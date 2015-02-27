/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "fsUploadMgr.h"
#include "zip.h"
#include <sys/stat.h>
#include <time.h>
#include "vmsInternetSession.h"
#include "misc.h"
#include "vmsCrc32.h"

extern void vmsMakeWinInetProxy (LPCSTR pszProxy, fsNetworkProtocol npConnection, fsNetworkProtocol npProxy, LPSTR pszWProxy);

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsUploadMgr::fsUploadMgr()
{
	m_pfnEventHandler = NULL;
	m_upldr.SetEventFunc (_UploaderEvents, this);
	m_cThreads = 0;

	m_bNeedStop = false;
	m_bRunning = false;

	m_nFileId = -1;
	m_dwUploadFileCrc32 = 0;

	m_bDetailsWasSent = FALSE;
	m_bCaptchaValidated = FALSE;

	m_bZipFileCreated = FALSE;

	m_bRequestUploadUrlOnly = FALSE;

	m_strDownloadUrl = "";

	m_bUploadFileCrc32IsValid = FALSE;
}

fsUploadMgr::~fsUploadMgr()
{
	while (m_cThreads)
		Sleep (10);
}

void fsUploadMgr::Create(vmsUploadPackageImpl *pkg)
{
	if (m_pkg.m_vPathes.size () != 0)
		return;

	m_pkg = *pkg;

	if (pkg->is_shouldBeCompressed () == false)
		m_strUploadFile = pkg->m_vPathes [0];
}

DWORD fsUploadMgr::_UploaderEvents(fsInternetUploader*, fsInternetUploaderEvent ev, LPVOID pData, LPVOID lpThis)
{
	fsUploadMgr* pthis = (fsUploadMgr*) lpThis;

	switch (ev)
	{
	case IUE_UPLOADSTOPPEDORDONE:
		if (pthis->m_upldr.IsDone ())
			pthis->DeleteZipFile ();
		if (pthis->IsRunning ())
			return pthis->Event (UMGRE_UPLOADER_STOPPED_OR_DONE);
		return pthis->Event (UMGRE_STOPPED_OR_DONE);
	}

	return pthis->Event (UMGRE_UPLOADER_EVENT, ev, pData);
}

BOOL fsUploadMgr::IsRunning()
{
	return m_bRunning || m_upldr.IsRunning ();
}

void fsUploadMgr::StartUploading(BOOL bRequestUploadUrlOnly)
{
	if (IsRunning ())
	{
		if (bRequestUploadUrlOnly == FALSE)
			m_bRequestUploadUrlOnly = FALSE;
		return;
	}

	m_bNeedStop = false;

	InterlockedIncrement (&m_cThreads);
	m_bRunning = true;
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadUploadMgr, this, 0, &dw));
}

void fsUploadMgr::StopUploading(BOOL bWaitStop)
{
	m_bNeedStop = true;
	m_memDldr.Abort ();
	m_networkOpFile.Close ();	

	if (m_upldr.IsRunning ())
		m_upldr.StopUploading (bWaitStop);

	if (bWaitStop)
	{
		while (m_cThreads)
			Sleep (10);
	}
}

double fsUploadMgr::GetProgress()
{
	return ((double)(__int64)GetUploadedByteCount ()) / (__int64)GetTotalSize () * 100.0;
}

void fsUploadMgr::SetEventFunc(fntUploadMgrEventFunc pfn, LPVOID lpParam)
{
	m_pfnEventHandler = pfn;
	m_lpEventParam = lpParam;
}

BOOL fsUploadMgr::IsDone()
{
	return m_bDetailsWasSent && m_bCaptchaValidated && GetProgress () == 100;
}

UINT64 fsUploadMgr::GetTotalSize()
{
	return m_upldr.GetFileSize ();
}

UINT64 fsUploadMgr::GetUploadedByteCount()
{
	return m_upldr.GetCurrentPosition ();
}

DWORD fsUploadMgr::GetSpeed()
{
	return m_upldr.GetSpeed ();
}

LPCSTR fsUploadMgr::get_PackageName()
{
	return m_pkg.m_strName;
}

LPCSTR fsUploadMgr::get_PackageUrl()
{
	return m_strDownloadUrl;
}

LPCSTR fsUploadMgr::GetUploadingFile()
{
	return m_strUploadFile;
}

fsInternetUploader* fsUploadMgr::GetUploader()
{
	return &m_upldr;
}

vmsUploadPackageImpl* fsUploadMgr::get_Package()
{
	return &m_pkg;
}

BOOL fsUploadMgr::ZipFiles ()
{
	if (m_bZipFileCreated)
		return TRUE;

	Event (UMGRE_ZIP_FILES_START);

	char szTmpFile [MAX_PATH];
	char szTmpPath [MAX_PATH];
	GetTempPath (MAX_PATH, szTmpPath);
	GetTempFileName (szTmpPath, "tmp", 0, szTmpFile);
	m_strUploadFile = szTmpFile;
	
	zipFile zip = zipOpen (m_strUploadFile, 0);
	BOOL bOk = TRUE;

	m_strZipContentsDescHtml = "<ul>";

	for (size_t i = 0; i < m_pkg.m_vPathes.size () && bOk && m_bNeedStop == false; i++)
	{
		LPCSTR psz = m_pkg.m_vPathes [i];

		char szName [1000] = "";
		fsGetFileName (psz, szName);

		if (GetFileAttributes (psz) & FILE_ATTRIBUTE_DIRECTORY)
		{
			AddItemToZipContentsDescHtml (szName, _UI64_MAX);
			m_strZipContentsDescHtml += "<ul>";
			bOk = bOk && Zip_AddFolder (zip, psz, NULL, 1);
			m_strZipContentsDescHtml += "</ul>";
		}
		else
		{
			bOk = bOk && Zip_AddFile (zip, psz, NULL);
			if (bOk)
			{
				WIN32_FILE_ATTRIBUTE_DATA wfad;
				GetFileAttributesEx (psz, GetFileExInfoStandard, &wfad);
				AddItemToZipContentsDescHtml (szName, ((UINT64)wfad.nFileSizeHigh << 32) + wfad.nFileSizeLow);
			}
		}
	}

	m_strZipContentsDescHtml += "</ul>";

	zipClose (zip, NULL);

	if (m_bNeedStop || bOk == FALSE)
		DeleteFile (m_strUploadFile);
	else
		m_bZipFileCreated = TRUE;

	if (m_bNeedStop == false)
		Event (bOk ? UMGRE_ZIP_FILES_DONE : UMGRE_ZIP_FILES_FAILED);

	return m_bZipFileCreated;
}

BOOL fsUploadMgr::Zip_AddFile(void *z, LPCSTR pszFile, LPCSTR pszNameInZip)
{
	zipFile zip = (zipFile) z;
	bool result = false;

	if (pszNameInZip == NULL)
	{
		pszNameInZip = strrchr (pszFile, '\\');
		if (pszNameInZip)
			pszNameInZip++;
		if (pszNameInZip == NULL)
			pszNameInZip = pszFile;
	}
	
	zip_fileinfo zfileinfo = {0};
    struct _stat file_stat = {0};

	FILE* file = fopen (pszFile, "rb");

	_fstat (_fileno (file), &file_stat);
	struct tm* file_time = localtime (&file_stat.st_mtime);
	tm_zip* zip_time = &zfileinfo.tmz_date;
	memcpy (zip_time, file_time, sizeof (tm_zip));

	const int READ_BUFFER_SIZE = 65535;
	char read_buf[READ_BUFFER_SIZE];

	wchar_t wsz [30000];
	MultiByteToWideChar (CP_ACP, 0, pszNameInZip, -1, wsz, 30000);
	char szNameInZip [30000];
	WideCharToMultiByte (CP_OEMCP, 0, wsz, -1, szNameInZip, 30000, NULL, NULL);
	
	if (ZIP_OK == zipOpenNewFileInZip (zip, szNameInZip, &zfileinfo, NULL, 0, NULL, 0, NULL, Z_DEFLATED, m_pkg.m_iZipCompressMethod))
    {
		while (!feof (file))
        {
			result = false;
			size_t count = fread (read_buf, sizeof(char), READ_BUFFER_SIZE, file);
            if (!ferror (file))
			{
				if (ZIP_OK == zipWriteInFileInZip (zip, read_buf, count))
                {
					result = true;
                    continue;
                }
                else 
					break;
            }
			else 
				break; 
		}

		result = result && (Z_OK == zipCloseFileInZip(zip));        
	}
        
	result = result && (0 == fclose (file));

	return result;
}

BOOL fsUploadMgr::Zip_AddFolder(void *zip, LPCSTR pszFolder, LPCSTR pszFolderNameInZip, int nDepth)
{
	fsString strDir = pszFolder;
	if (strDir [strDir.GetLength () - 1] != '\\')
		strDir += '\\';
	fsString strMask = strDir; strMask += "*.*";
	fsString strFolderNameInZip;
	if (pszFolderNameInZip == NULL)
	{
		LPCSTR psz = strrchr (pszFolder, '\\');
		if (psz)
		{
			if (psz [1] == 0)
				while (*(--psz) != '\\');
			psz++;
		}
		if (psz == NULL)
			psz = pszFolder;
		strFolderNameInZip = psz;
	}
	else
		strFolderNameInZip = pszFolderNameInZip;
	if (strFolderNameInZip.IsEmpty () == FALSE && 
			strFolderNameInZip [strFolderNameInZip.GetLength () - 1] != '\\')
		strFolderNameInZip += '\\';
	pszFolderNameInZip = strFolderNameInZip;

	WIN32_FIND_DATA wfd;
	HANDLE hFind = FindFirstFile (strMask, &wfd);
	if (hFind == NULL)
		return TRUE;

	do
	{
		if (strcmp (wfd.cFileName, ".") == 0 || strcmp (wfd.cFileName, "..") == 0)
			continue;

		fsString str = strDir;
		str += wfd.cFileName;

		fsString strNameInZip = pszFolderNameInZip;
		strNameInZip += wfd.cFileName;

		if (GetFileAttributes (str) & FILE_ATTRIBUTE_DIRECTORY)
		{
			AddItemToZipContentsDescHtml (wfd.cFileName, _UI64_MAX);
			strNameInZip += '\\';
			m_strZipContentsDescHtml += "<ul>";
			if (FALSE == Zip_AddFolder (zip, str, strNameInZip, nDepth+1))
				return FALSE;
			m_strZipContentsDescHtml += "</ul>";
		}
		else
		{
			if (FALSE == Zip_AddFile (zip, str, strNameInZip))
				return FALSE;
			AddItemToZipContentsDescHtml (wfd.cFileName, ((UINT64)wfd.nFileSizeHigh << 32) + wfd.nFileSizeLow);
		}
	}
	while (FindNextFile (hFind, &wfd));

	FindClose (hFind);

	return TRUE;
}

DWORD fsUploadMgr::Event(fsUploadMgrEvent ev, DWORD dwData, LPVOID pData)
{
	if (m_pfnEventHandler)
		return m_pfnEventHandler (this, ev, dwData, pData, m_lpEventParam);
	return 0;
}

fsInternetResult fsUploadMgr::RequestUploadInfo()
{
	Event (UMGRE_REQ_UPLOAD_INIT);

	fsUpload_Properties up;
	ZeroMemory (&up, sizeof (up));
	CString strUrl;
	
	
	
	
	
	strUrl = "http://www.wikifortio.com/dispatch-upload.action?getUplAddrAndFileId&fileName=";
	strUrl += fsHtmlUnicodeEncode (get_UploadName ());
	
	fsInternetResult ir = fsUP_GetByUrl (&up, strUrl);
	if (ir != IR_SUCCESS)
		goto _lErr;

	vmsInternetSession* pSession; pSession = new vmsInternetSession;
	char szProxy [10000];
	vmsMakeWinInetProxy (up.pszProxyName, up.enProtocol, up.enProtocol, szProxy);
	ir  = pSession->Create (up.pszAgent, up.enAccType, szProxy, up.enProtocol);
	if (ir != IR_SUCCESS)
	{
		delete pSession;
		goto _lErr;
	}
	
	pSession->SetProxyAuth (up.pszProxyUserName, up.pszProxyPassword);
	pSession->SetTimeout (up.uTimeout);

	m_memDldr.Initialize (pSession);

	m_memDldr.Get_File ()->UseHttp11 (up.bUseHttp11);
	m_memDldr.Get_File ()->UseCookie (up.bUseCookie);

	ir = m_memDldr.Download (strUrl);
	m_memDldr.Get_File ()->CloseHandle ();

	delete pSession;

	if (ir != IR_SUCCESS)
		goto _lErr;

	LPCSTR pszInfo; pszInfo = (LPCSTR) m_memDldr.Get_FileBuffer ();

	fsUP_GetByUrl_Free (&up);

	if (FALSE == RequestUploadInfo_parse (pszInfo))
	{
		ir = IR_ERROR;
		goto _lErr;
	}

	Event (UMGRE_REQ_UPLOAD_INIT_DONE);

	return IR_SUCCESS;

_lErr:
	Event (UMGRE_REQ_UPLOAD_INIT_FAILED, ir);
	return ir;
}

BOOL fsUploadMgr::RequestUploadInfo_parse(LPCSTR psz)
{
	char sz [10000];

	for (int i = 0; *psz; i++)
	{
		
		LPSTR psz2 = sz;
		while (*psz && *psz != ';' && psz2 - sz < sizeof (sz) - 1)
			*psz2++ = *psz++;
		*psz2 = 0;
		if (*psz == ';')
			psz++;

		switch (i)
		{
		case 0:
			m_nFileId = atoi (sz);
			break;

		case 1:
		case 2:
		case 3:
			break;

		case 4:
			m_strCaptchaUrl = sz;
			break;

		case 5:
			m_strCaptchaValidateUrl = sz;
			break;

		case 6:
			m_strUploadUrl = sz;
			if (m_strUploadUrl.IsEmpty () == FALSE && 
					m_strUploadUrl [m_strUploadUrl.GetLength () - 1] != '/')
				m_strUploadUrl += '/';
			m_strUploadUrl += get_UploadName ();
			break;

		case 7:
			m_strDownloadUrl = sz;
			break;

		case 8:
			m_strDetailsScriptUrl = sz;
			break;
		}

		if (i == 8)
			break;
	}

	if (m_strCaptchaUrl.IsEmpty () || m_strCaptchaValidateUrl.IsEmpty ())
		m_bCaptchaValidated = TRUE;

	return TRUE;
}

DWORD WINAPI fsUploadMgr::_threadUploadMgr(LPVOID lp)
{
	fsUploadMgr *pthis = (fsUploadMgr*) lp;

	if (FALSE == pthis->Event (UMGRE_BEFORE_UPLOAD, 0, &pthis->m_bNeedStop))
		goto _lExit;

	if (pthis->m_strUploadUrl.IsEmpty ())
	{
		if (IR_SUCCESS != pthis->RequestUploadInfo ())
			goto _lExit;

		if (pthis->m_bRequestUploadUrlOnly)
			goto _lExit;
	}

	if (pthis->m_bNeedStop)
		goto _lExit;

	if (pthis->m_bZipFileCreated == FALSE && 
			pthis->m_pkg.is_shouldBeCompressed ())
	{
		if (FALSE == pthis->ZipFiles ())
			goto _lExit;
	}

	if (pthis->m_bNeedStop)
		goto _lExit;

	if (pthis->m_bUploadFileCrc32IsValid == FALSE)
	{
		if (FALSE == pthis->CalculateUploadFileCrc32 ())
			goto _lExit;
	}

	if (pthis->m_bNeedStop)
		goto _lExit;

	if (pthis->m_upldr.IsDone () == FALSE && 
			(pthis->m_upldr.get_UploadFileName () == NULL || *pthis->m_upldr.get_UploadFileName () == 0))
	{
		if (pthis->m_upldr.get_UploadFileName () == NULL || 
				*pthis->m_upldr.get_UploadFileName () == 0)
			pthis->m_upldr.CreateForFile (pthis->m_strUploadFile, pthis->m_strUploadUrl);
	}

	if (pthis->m_upldr.IsDone () == FALSE)
	{
		pthis->Event (UMGRE_STARTING_UPLOAD_FILE);
		pthis->m_upldr.StartUploading ();
	}

	if (pthis->m_bDetailsWasSent == FALSE)
	{
		while (pthis->m_bNeedStop == false && 
				pthis->m_upldr.GetSpeed () == 0 && pthis->m_upldr.IsDone () == FALSE)
			Sleep (33);

		if (pthis->m_bNeedStop)
			goto _lExit;

		pthis->SendUploadDetails ();
	}

	if (pthis->m_bNeedStop)
		goto _lExit;

	if (pthis->m_bCaptchaValidated == FALSE)
		pthis->ValidateCaptcha ();

_lExit:
	pthis->m_bRunning = false;

	if (pthis->IsRunning () == FALSE)
		pthis->Event (UMGRE_STOPPED_OR_DONE);

	InterlockedDecrement (&pthis->m_cThreads);
	return 0;
}

fsInternetResult fsUploadMgr::SendUploadDetails()
{
	if (m_bDetailsWasSent)
		return IR_S_FALSE;

	Event (UMGRE_SENDING_UPLOAD_DETAILS);

	CString str;
	fsString strDet;

	strDet = "saveDetails=&";

	strDet += "fid=";
	char sz [100]; 
	strDet += itoa (m_nFileId, sz, 10);

	strDet += "&crc=";
	str.Format ("%u", m_dwUploadFileCrc32);
	strDet += str;
	
	strDet += "&storagePeriodDays=";
	strDet += itoa (m_pkg.m_nNumberOfDaysToKeepThisUpload, sz, 10);

	strDet += "&email="; 
	strDet += fsUtf8HttpUrlEncode (m_pkg.m_strRecipientEmail);

	strDet += "&description=";
	strDet += fsUtf8HttpUrlEncode (m_pkg.m_strDescription);

	strDet += "&password=";
	strDet += fsUtf8HttpUrlEncode (m_pkg.m_strPassword);
	strDet += "&confirmPassword=";
	strDet += fsUtf8HttpUrlEncode (m_pkg.m_strPassword);

	if (m_pkg.is_shouldBeCompressed ())
	{
		strDet += "&packageName=";
		strDet += fsUtf8HttpUrlEncode (m_pkg.m_strName);

		strDet += "&packageDescription=";
		strDet += fsUtf8HttpUrlEncode (m_strZipContentsDescHtml);
	}

	strDet += "&userName=";
	strDet += fsUtf8HttpUrlEncode (m_pkg.m_strOwnerName);

	strDet += "&userEmail=";
	strDet += fsUtf8HttpUrlEncode (m_pkg.m_strOwnerEmail);

	strDet += "&tagString=";
	strDet += fsUtf8HttpUrlEncode (m_pkg.m_strTags);

	strDet += "&plannedDownloadCount=";
	strDet += itoa (m_pkg.m_nSupposedNumberOfDlds, sz, 10);

	strDet += "&addToDirectory=";
	strDet += m_pkg.m_bAddLinkToUploadInCatalogue ? "1" : "0";

	strDet += "&FUM=1";

	fsUpload_Properties up;
	ZeroMemory (&up, sizeof (up));

	fsInternetResult ir = fsUP_GetByUrl (&up, m_strDetailsScriptUrl);
	if (ir != IR_SUCCESS)
		goto _lErr;

	vmsInternetSession* pSession; pSession = new vmsInternetSession;
	char szProxy [10000];
	vmsMakeWinInetProxy (up.pszProxyName, up.enProtocol, up.enProtocol, szProxy);
	ir = pSession->Create (up.pszAgent, up.enAccType, szProxy, up.enProtocol);
	if (ir != IR_SUCCESS)
	{
		delete pSession;
		goto _lErr;
	}
	
	pSession->SetProxyAuth (up.pszProxyUserName, up.pszProxyPassword);
	pSession->SetTimeout (up.uTimeout);

	m_networkOpFile.Initialize (pSession);

	m_networkOpFile.UseHttp11 (up.bUseHttp11);
	m_networkOpFile.UseCookie (up.bUseCookie);
	m_networkOpFile.set_Charset ("UTF-8");

	

	m_networkOpFile.set_UseMultipart (FALSE);
	m_networkOpFile.set_EnableAutoRedirect (TRUE);

	ir = m_networkOpFile.OpenEx (fsNPToScheme (up.enProtocol), up.pszServerName,
			up.pszUserName, up.pszPassword, up.uServerPort, 
			up.pszPathName, 0, FALSE, strDet.GetLength (), strDet.GetLength ());

	if (ir != IR_SUCCESS)
		goto _lErr;

	DWORD dw;
	ir = m_networkOpFile.Write ((LPBYTE)(LPCSTR)strDet, strDet.GetLength (), &dw);

	delete pSession;

	if (ir != IR_SUCCESS)
		goto _lErr;

	m_bDetailsWasSent = TRUE;

	fsUP_GetByUrl_Free (&up);

	Event (UMGRE_SENDING_UPLOAD_DETAILS_DONE);

	return IR_SUCCESS;

_lErr:
	Event (UMGRE_SENDING_UPLOAD_DETAILS_FAILED, ir);
	return ir;
}

fsInternetResult fsUploadMgr::ValidateCaptcha()
{
	if (m_bCaptchaValidated)
		return IR_S_FALSE;

	Event (UMGRE_VALIDATING_UPLOAD);

	fsString strCookie;
	CString strPngFile, strCaptchaValidateUrl, strCaptchaVal;
	fsUpload_Properties up;
	ZeroMemory (&up, sizeof (up));
	vmsInternetSession* pSession = NULL;

	

	fsInternetResult ir = fsUP_GetByUrl (&up, m_strCaptchaUrl);
	if (ir != IR_SUCCESS)
		goto _lErr;

	pSession = new vmsInternetSession;
	char szProxy [10000];
	vmsMakeWinInetProxy (up.pszProxyName, up.enProtocol, up.enProtocol, szProxy);
	ir  = pSession->Create (up.pszAgent, up.enAccType, szProxy, up.enProtocol);
	if (ir != IR_SUCCESS)
		goto _lErr;
	
	pSession->SetProxyAuth (up.pszProxyUserName, up.pszProxyPassword);
	pSession->SetTimeout (up.uTimeout);

	m_memDldr.Initialize (pSession);

	m_memDldr.Get_File ()->UseHttp11 (TRUE);
	m_memDldr.Get_File ()->UseCookie (TRUE);

	ir = m_memDldr.Download (m_strCaptchaUrl);

	if (ir != IR_SUCCESS)
		goto _lErr;

	if (m_bNeedStop)
	{
		ir = IR_S_FALSE;
		goto _lErr;
	}

	strCookie = m_memDldr.Get_File ()->GetCookiesFromResponse ();

	m_memDldr.Get_File ()->CloseHandle ();
	fsUP_GetByUrl_Free (&up);

	char szTmpPath [MAX_PATH];
	GetTempPath (MAX_PATH, szTmpPath);
	if (szTmpPath [lstrlen (szTmpPath) - 1] != '\\')
		lstrcat (szTmpPath, "\\");

	int i; i = 0;
	do {
		strPngFile.Format ("%s%u%d.png", szTmpPath, m_nFileId, i++);
	}
	while (GetFileAttributes (strPngFile) != DWORD (-1));

	HANDLE hFile; hFile = CreateFile (strPngFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_HIDDEN, NULL);
	DWORD dw;
	WriteFile (hFile, m_memDldr.Get_FileBuffer (), m_memDldr.Get_FileSize (), &dw, NULL);
	CloseHandle (hFile);

	

_lAskCaptchaValue:

	LPSTR pszCV; pszCV = strCaptchaVal.GetBuffer (100);
	*pszCV = 0;
	Event (UMGRE_NEED_ASK_CAPTCHA_VALUE, (DWORD)(LPCSTR)strPngFile, pszCV);
	strCaptchaVal.ReleaseBuffer ();

	if (strCaptchaVal.IsEmpty ())
	{
		DeleteFile (strPngFile);
		ir = IR_S_FALSE;
		goto _lErr;
	}

	

	strCaptchaVal = fsHttpUrlEncode (strCaptchaVal);

	strCaptchaValidateUrl = m_strCaptchaValidateUrl;
	strCaptchaValidateUrl.Replace ("jcaptchaCode", strCaptchaVal);
	ir = fsUP_GetByUrl (&up, strCaptchaValidateUrl);
	if (ir != IR_SUCCESS)
	{
		DeleteFile (strPngFile);
		goto _lErr;
	}

	m_networkOpFile.Initialize (pSession, FALSE);

	m_networkOpFile.SetCookies (strCookie);

	m_networkOpFile.set_EnableAutoRedirect (TRUE);

	m_networkOpFile.set_Charset ("");

	ir = m_networkOpFile.OpenEx (fsNPToScheme (up.enProtocol), up.pszServerName,
		up.pszUserName, up.pszPassword, up.uServerPort, 
		up.pszPathName, 0, FALSE, _UI64_MAX, _UI64_MAX);

	if (ir == IR_FILENOTFOUND)
		goto _lAskCaptchaValue;

	DeleteFile (strPngFile);
	
	if (ir != IR_SUCCESS)
		goto _lErr;

	m_bCaptchaValidated = TRUE;

	m_networkOpFile.CloseHandle ();

	delete pSession;

	Event (UMGRE_VALIDATING_UPLOAD_DONE);

	return IR_SUCCESS;

_lErr:
	if (pSession)
		delete pSession;
	Event (UMGRE_VALIDATING_UPLOAD_FAILED, ir);
	return ir;
}

void fsUploadMgr::DeleteZipFile()
{
	if (m_bZipFileCreated)
		DeleteFile (m_strUploadFile);
}

BOOL fsUploadMgr::CalculateUploadFileCrc32()
{
	if (m_bUploadFileCrc32IsValid)
		return TRUE;

	Event (UMGRE_CRC_UPLOAD_FILE);

	vmsCRC32 crc;

	HANDLE hFile = CreateFile (m_strUploadFile, GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		goto _lErr;

	BYTE ab [10000];
	DWORD dwRead;

	do
	{
		if (FALSE == ReadFile (hFile, ab, sizeof (ab), &dwRead, NULL))
			goto _lErr;
		if (dwRead)
			crc.Calculate (ab, dwRead);
		if (m_bNeedStop)
			return FALSE;
	}
	while (dwRead == sizeof (ab));

        CloseHandle (hFile);

	m_dwUploadFileCrc32 = crc.get_Result ();
	m_bUploadFileCrc32IsValid = TRUE;

	Event (UMGRE_CRC_UPLOAD_FILE_DONE);

	return TRUE;

_lErr:
	Event (UMGRE_CRC_UPLOAD_FILE_FAILED, GetLastError ());
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);
	return FALSE;
}

void fsUploadMgr::AddItemToZipContentsDescHtml(LPCSTR pszName, UINT64 uSize)
{
	m_strZipContentsDescHtml += "<li>";
	m_strZipContentsDescHtml += pszName;

	if (uSize != _UI64_MAX)
	{
		m_strZipContentsDescHtml += " (";
		m_strZipContentsDescHtml += fsBytesToStr (uSize, FALSE);
		m_strZipContentsDescHtml += " bytes";
		m_strZipContentsDescHtml += ")";
	}

	m_strZipContentsDescHtml += "</li>";
}

BOOL fsUploadMgr::Save(HANDLE hFile)
{
	if (FALSE == Save_Package (hFile))
		return FALSE;

	DWORD dw;

	if (FALSE == WriteFile (hFile, &m_bCaptchaValidated, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_bDetailsWasSent, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_bUploadFileCrc32IsValid, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_bZipFileCreated, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_dwUploadFileCrc32, sizeof (DWORD), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_nFileId, sizeof (int), &dw, NULL))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_strCaptchaUrl, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_strCaptchaValidateUrl, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_strDetailsScriptUrl, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_strDownloadUrl, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_strUploadUrl, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_strUploadFile, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_strUploadUrl, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_strZipContentsDescHtml, hFile))
		return FALSE;

	if (FALSE == m_upldr.Save (hFile))
		return FALSE;

	return TRUE;
}

BOOL fsUploadMgr::Save_Package(HANDLE hFile)
{
	DWORD dw;

	if (FALSE == WriteFile (hFile, &m_pkg.m_bAddLinkToUploadInCatalogue, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_pkg.m_iZipCompressMethod, sizeof (int), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_pkg.m_nNumberOfDaysToKeepThisUpload, sizeof (int), &dw, NULL))
		return FALSE;

	if (FALSE == WriteFile (hFile, &m_pkg.m_nSupposedNumberOfDlds, sizeof (int), &dw, NULL))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_pkg.m_strDescription, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_pkg.m_strName, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_pkg.m_strOwnerEmail, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_pkg.m_strOwnerName, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_pkg.m_strPassword, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_pkg.m_strRecipientEmail, hFile))
		return FALSE;

	if (FALSE == fsSaveStrToFile (m_pkg.m_strTags, hFile))
		return FALSE;

	size_t cItems = m_pkg.m_vPathes.size ();

	if (FALSE == WriteFile (hFile, &cItems, sizeof (size_t), &dw, NULL))
		return FALSE;

	for (size_t i = 0; i < cItems; i++)
	{
		if (FALSE == fsSaveStrToFile (m_pkg.m_vPathes [i], hFile))
			return FALSE;
	}

	return TRUE;
}

BOOL fsUploadMgr::Load(HANDLE hFile)
{
	if (FALSE == Load_Package (hFile))
		return FALSE;

	DWORD dw;

	if (FALSE == ReadFile (hFile, &m_bCaptchaValidated, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_bDetailsWasSent, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_bUploadFileCrc32IsValid, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_bZipFileCreated, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_dwUploadFileCrc32, sizeof (DWORD), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_nFileId, sizeof (int), &dw, NULL))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_strCaptchaUrl))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_strCaptchaValidateUrl))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_strDetailsScriptUrl))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_strDownloadUrl))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_strUploadUrl))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_strUploadFile))
		return FALSE;

	if (m_strUploadUrl.IsEmpty () == FALSE && m_strUploadFile.IsEmpty () == FALSE)
	{
		
		m_upldr.CreateForFile (m_strUploadFile, m_strUploadUrl);
	}

	if (FALSE == fsReadStringFromFile (hFile, m_strUploadUrl))
		return FALSE;

	fsString str;
	if (FALSE == fsReadStringFromFile (hFile, str))
		return FALSE;
	m_strZipContentsDescHtml = str;

	if (FALSE == m_upldr.Load (hFile))
		return FALSE;

	return TRUE;	
}

BOOL fsUploadMgr::Load_Package(HANDLE hFile)
{
	DWORD dw;

	if (FALSE == ReadFile (hFile, &m_pkg.m_bAddLinkToUploadInCatalogue, sizeof (BOOL), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_pkg.m_iZipCompressMethod, sizeof (int), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_pkg.m_nNumberOfDaysToKeepThisUpload, sizeof (int), &dw, NULL))
		return FALSE;

	if (FALSE == ReadFile (hFile, &m_pkg.m_nSupposedNumberOfDlds, sizeof (int), &dw, NULL))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_pkg.m_strDescription))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_pkg.m_strName))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_pkg.m_strOwnerEmail))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_pkg.m_strOwnerName))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_pkg.m_strPassword))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_pkg.m_strRecipientEmail))
		return FALSE;

	if (FALSE == fsReadStringFromFile (hFile, m_pkg.m_strTags))
		return FALSE;

	size_t cItems;

	if (FALSE == ReadFile (hFile, &cItems, sizeof (size_t), &dw, NULL))
		return FALSE;

	for (size_t i = 0; i < cItems; i++)
	{
		fsString str;
		if (FALSE == fsReadStringFromFile (hFile, str))
			return FALSE;
		m_pkg.m_vPathes.push_back (str);
	}

	return TRUE;
}

fsString fsUploadMgr::get_UploadName()
{
	if (m_pkg.is_shouldBeCompressed ())
	{
		fsString str;
		str = m_pkg.m_strName;
		str += ".zip";
		return str;
	}
	else
	{
		char sz [MAX_PATH];
		fsGetFileName (m_pkg.m_vPathes [0], sz);
		return sz;
	}
}

