/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsBtSupport.h"
#include "mfchelp.h"
#include "vmsTrafficUsageModeMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsBtSupport::vmsBtSupport()
{
	m_pbDHTstate = NULL;
	m_hBtDll = NULL;
	m_bWasShutdown = false;
}

vmsBtSupport::~vmsBtSupport()
{
}

BOOL vmsBtSupport::Initialize()
{
	if (false == LoadBtDll ())
		return FALSE;
	return LoadState ();
}

vmsBtSession* vmsBtSupport::get_Session()
{
	if (m_bWasShutdown)
		return NULL;

	static vmsBtSession* _pSession = NULL;
	if (_pSession)
		return _pSession;

	vmsAUTOLOCKSECTION (m_cs1);

	if (_pSession)
		return _pSession;

	if (!m_hBtDll)
		Initialize ();

	typedef vmsBtSession* (WINAPI *FNS)();
	FNS pfnSession = (FNS) GetProcAddress (m_hBtDll, "vmsBt_getSession");;
	
	if (pfnSession)
	{
		_pSession = pfnSession ();

		if (_pSession)
		{
			_pSession->SetUserAgent (vmsFdmAppMgr::getAppBtAgentName ());
			_pSession->DisableOsCash();
			ApplyListenPortSettings ();
			ApplyDHTSettings ();
			ApplyAdditionalTorrentSettings();
			_pSession->SetDownloadLimit (-1);
			_pSession->SetUploadLimit (-1);
			ApplyProxySettings ();
			_DldsMgr.AttachToBtSession ();
			_DldsMgr.setNeedApplyTrafficLimit ();
		}
	}
	
	return _pSession;
}

BOOL vmsBtSupport::is_Initialized()
{
	return m_hBtDll != NULL;
}

void vmsBtSupport::ApplyListenPortSettings()
{
	if (is_Initialized ())
	{
		vmsBtSession *pBtSession = get_Session ();

		int portFrom = _App.Bittorrent_ListenPort_From (),
			portTo = _App.Bittorrent_ListenPort_To ();

		if (pBtSession->IsListening () == FALSE ||
				pBtSession->get_ListenPort () > portTo ||
				pBtSession->get_ListenPort () < portFrom)
			pBtSession->ListenOn (portFrom, portTo);
	}
}

void vmsBtSupport::ApplyDHTSettings()
{
	if (is_Initialized () == FALSE)
		return;

	vmsBtSession *pBtSession = get_Session ();

	if (_App.Bittorrent_EnableDHT ())
	{
		if (pBtSession->DHT_isStarted () == FALSE){
			pBtSession->DHT_start (m_pbDHTstate, m_dwDHTstateSize);
		}
	}
	else
	{
		if (pBtSession->DHT_isStarted ())
			pBtSession->DHT_stop ();
	}
}

void vmsBtSupport::ApplyAdditionalTorrentSettings(){
	if (is_Initialized () == FALSE)
		return;

	vmsBtSession *pBtSession = get_Session ();

	if (_App.Bittorrent_EnableLocalPeerDiscovery())
	{
		pBtSession->LocalPeers_start ();
	}
	else
	{
		pBtSession->LocalPeers_stop ();
	}

	if (_App.Bittorrent_EnableUPnP())
	{
		pBtSession->UPNP_start ();
	}
	else
	{
		pBtSession->UPNP_stop ();
	}

	if (_App.Bittorrent_EnableNATPMP())
	{
		pBtSession->NATPMP_start ();
	}
	else
	{
		pBtSession->NATPMP_stop ();
	}
}

BOOL vmsBtSupport::SaveState()
{
	if (is_Initialized () == FALSE)
		return TRUE;

	vmsBtSession *pBtSession = get_Session ();
	vmsBtPersistObject *pBtPO = NULL;
	pBtSession->getPersistObject (&pBtPO);
	assert (pBtPO != NULL);
	if (!pBtPO)
		return FALSE;

	if (!pBtPO->isDirty())
		return TRUE;

	if (pBtSession->DHT_isStarted ())
	{
		SAFE_DELETE_ARRAY (m_pbDHTstate);
	
		pBtPO->getStateBuffer(0, &m_dwDHTstateSize, false);

		m_pbDHTstate = new BYTE [m_dwDHTstateSize];

		pBtPO->getStateBuffer(m_pbDHTstate, &m_dwDHTstateSize, true);
	}

	if (m_pbDHTstate == NULL)
		return TRUE;

	HANDLE hFile = CreateFile (fsGetDataFilePath ("btdht.sav"), GENERIC_WRITE,
		0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dw;
	WriteFile (hFile, m_pbDHTstate, m_dwDHTstateSize, &dw, NULL);

	CloseHandle (hFile);

	return TRUE;
}

BOOL vmsBtSupport::LoadState()
{
	if (GetFileAttributes (fsGetDataFilePath ("btdht.sav")) == DWORD (-1))
		return TRUE;

	HANDLE hFile = CreateFile (fsGetDataFilePath ("btdht.sav"), GENERIC_READ,
		0, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	SAFE_DELETE_ARRAY (m_pbDHTstate);
	m_dwDHTstateSize = GetFileSize (hFile, NULL);
	m_pbDHTstate = new BYTE [m_dwDHTstateSize];

	DWORD dw;
	ReadFile (hFile, m_pbDHTstate, m_dwDHTstateSize, &dw, NULL);

	CloseHandle (hFile);

	return TRUE;
}

void vmsBtSupport::Shutdown()
{
	if (is_Initialized () == FALSE)
		return;

	m_bWasShutdown = true;

	typedef void (WINAPI *FNS)();
	FNS pfn = (FNS) GetProcAddress (m_hBtDll, "vmsBt_Shutdown");
	if (pfn)
		pfn ();
}

void vmsBtSupport::ApplyProxySettings()
{
	if (is_Initialized () == FALSE)
		return;

	fsString strIp, strUser, strPwd;
	int nPort = 0;

	switch (_App.InternetAccessType ())
	{
	case IATE_PRECONFIGPROXY:
		GetIeProxySettings (strIp, strUser, strPwd, nPort);
		break;

	case IATE_NOPROXY:
		break;

	case IATE_MANUALPROXY:
		strIp = _App.HttpProxy_Name ();
		strUser = _App.HttpProxy_UserName ();
		strPwd = _App.HttpProxy_UserName ();
		if (strIp.IsEmpty () == FALSE)
		{
			char sz [1000];
			strcpy (sz, strIp);
			LPSTR pszPort = strrchr (sz, ':');
			if (pszPort)
			{
				*pszPort++ = 0;
				nPort = atoi (pszPort);
				strIp = sz;
			}
		}
		break;

	case IATE_FIREFOXPROXY:
		GetFirefoxProxySettings (strIp, strUser, strPwd, nPort);
		break;
	}

	get_Session ()->SetProxySettings (strIp, nPort, strUser, strPwd);
}

void vmsBtSupport::GetIeProxySettings(fsString &strIp, fsString &strUser, fsString &strPwd, int &nPort)
{
	strIp = strUser = strPwd = ""; 
	nPort = 0;

	CRegKey key;
	if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, 
			"Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings", 
			KEY_READ))
		return;

	DWORD dw;
	if (ERROR_SUCCESS != key.QueryValue (dw, "ProxyEnable"))
		return;
	if (dw == FALSE)
		return;

	char szProxy [1000];
	dw = sizeof (szProxy);
	if (ERROR_SUCCESS != key.QueryValue (szProxy, "ProxyServer", &dw))
		return;

	LPSTR pszPort = strrchr (szProxy, ':');
	if (pszPort)
	{
		*pszPort = 0;
		pszPort++;
		nPort = atoi (pszPort);
	}

	strIp = szProxy;
}

void vmsBtSupport::GetFirefoxProxySettings(fsString &strIp, fsString &strUser, fsString &strPwd, int &nPort)
{
	strIp = strUser = strPwd = ""; 
	nPort = 0;

	if (1 != _App.FirefoxSettings_Proxy_Type ())
		return;

	strIp = _App.FirefoxSettings_Proxy_Addr ("http");
	nPort = _App.FirefoxSettings_Proxy_Port ("http");
}

vmsBtFile* vmsBtSupport::CreateTorrentFileObject()
{
	if (m_hBtDll == NULL && false == LoadBtDll ())
		return NULL;
	
	typedef vmsBtFile* (WINAPI *FNBTF)();
	static FNBTF _pfnCreateTorrentFileObject = NULL;
	
	if (_pfnCreateTorrentFileObject == NULL)
	{
		_pfnCreateTorrentFileObject = (FNBTF) GetProcAddress (m_hBtDll, "vmsBt_CreateTorrentFileObject");
		if (_pfnCreateTorrentFileObject == NULL)
			return NULL;
	}

	return _pfnCreateTorrentFileObject ();
}

vmsUTorrentDownloadsDb* vmsBtSupport::CreateUTorrentDownloadsDbObject()
{
	if (m_hBtDll == NULL && false == LoadBtDll ())
		return NULL;
	
	typedef vmsUTorrentDownloadsDb* (WINAPI *FNUTD)();
	static FNUTD _pfnCreateUTorrentDownloadsDbObject = NULL;
	
	if (_pfnCreateUTorrentDownloadsDbObject == NULL)
	{
		_pfnCreateUTorrentDownloadsDbObject = (FNUTD) GetProcAddress (m_hBtDll, "vms_CreateUTorrentDownloadsDbObject");
		if (_pfnCreateUTorrentDownloadsDbObject == NULL)
			return NULL;
	}

	return _pfnCreateUTorrentDownloadsDbObject ();
}

bool vmsBtSupport::LoadBtDll()
{
	if (m_hBtDll)
		return true;
	if (!isBtDllValid ())
		return false;
	return NULL != (m_hBtDll = LoadLibrary (getBtDllFileName ().c_str ()));
}

int vmsBtSupport::getBtDllVersion()
{
	static int ver = -1;
	if (ver != -1)
		return ver;

	CString str = getBtDllFileName ().c_str ();

	if (GetFileAttributes (str) == DWORD (-1))
		return ver = INT_MAX;
	
	DWORD dw;
	DWORD dwSize = GetFileVersionInfoSize (str, &dw);
	if (dwSize == 0)
		return ver = 0;
	LPVOID pvVer = _alloca (dwSize);
	ZeroMemory (pvVer, dwSize);
	if (FALSE == GetFileVersionInfo (str, 0, dwSize, pvVer))
		return ver = 0;
	
	VS_FIXEDFILEINFO *pFileInfo = NULL;
	UINT u;
	if (FALSE == VerQueryValue (pvVer, _T ("\\"), (LPVOID*)&pFileInfo, &u))
		return ver = 0;
	
	return ver = pFileInfo->dwFileVersionLS >> 16;
}

int vmsBtSupport::getBtDllMinimumFdmBuildRequired()
{
	static int _val = -1;
	if (_val != -1)
		return _val;

	CString str = getBtDllFileName ().c_str ();

	if (GetFileAttributes (str) == DWORD (-1))
		return _val = 0;

	vmsDLL dll; 
	if (!dll.Load (str))
		return _val = 0;

	typedef int (WINAPI *FNgetMinimumFdmBuildRequired)();
	FNgetMinimumFdmBuildRequired pfn = (FNgetMinimumFdmBuildRequired)dll.GetProcAddress ("vmsBt_getMinimumFdmBuildRequired");
	if (!pfn)
		return _val = 0;

	return _val = pfn ();
}

std::string vmsBtSupport::getBtDllFileName(void)
{
	tstring tstrDll;

	TCHAR tsz [MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, MAX_PATH);
	LPTSTR ptsz = _tcsrchr (tsz, '\\');
	if (ptsz)
	{
		_tcscpy (ptsz + 1, _T ("fdmbtsupp.dll"));
		tstrDll = tsz;
	}

	if (GetFileAttributes (tstrDll.c_str ()) != DWORD (-1))
		return tstrDll;

	
	tstrDll = ((CFdmApp*)AfxGetApp ())->m_strAppPath;
	if (tstrDll [tstrDll.length () - 1] != '\\')
		tstrDll += '\\';
	tstrDll += _T ("fdmbtsupp.dll");
	return tstrDll;
}

bool vmsBtSupport::isBtDllValid(void)
{
	static int _iResult = -1;
	
	if (_iResult != -1)
		return _iResult != 0;

	if (GetFileAttributes (getBtDllFileName ().c_str ()) == DWORD (-1))
	{
		_iResult = 1;
		return true;
	}

	_iResult = getBtDllVersion () >= BTSUPP_DLL_MINVERREQ &&
		getBtDllMinimumFdmBuildRequired () <= vmsFdmAppMgr::getBuildNumber ();

	return _iResult != 0;
}
