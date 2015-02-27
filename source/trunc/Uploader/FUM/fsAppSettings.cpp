/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsAppSettings.h"
#include "MainFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsAppSettings::fsAppSettings()
{
	m_dwWriteCacheSize = DWORD (-1);
}

fsAppSettings::~fsAppSettings()
{

}

fsInternetAccessTypeEx fsAppSettings::InternetAccessType()
{
	return (fsInternetAccessTypeEx) m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("InternetAccessType"), IATE_PRECONFIGPROXY);
}

void fsAppSettings::InternetAccessType(fsInternetAccessTypeEx enType)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("InternetAccessType"), enType);
}

CString fsAppSettings::UserName()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("UserName"), _T (""));
}

void fsAppSettings::UserName(LPCTSTR pszStr)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("UserName"), pszStr);
}

CString fsAppSettings::UserPassword()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("UserPassword"), _T (""));
}

void fsAppSettings::UserPassword(LPCTSTR pszStr)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("UserPassword"), pszStr);
}

CString fsAppSettings::Referer()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("Referer"), _T (""));
}

void fsAppSettings::Referer(LPCTSTR pszStr)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("Referer"), pszStr);
}

BOOL fsAppSettings::UseHttp11()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("UseHttp1.1"), TRUE);
}

void fsAppSettings::UseHttp11(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("UseHttp1.1"), b);
}

DWORD fsAppSettings::FtpFlags()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("FtpFlags"), 0);
}

void fsAppSettings::FtpFlags(DWORD dw)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("FtpFlags"), dw);
}

fsFtpTransferType fsAppSettings::FtpTransferType()
{
	return (fsFtpTransferType) m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("TransferType"), FTT_UNKNOWN);
}

void fsAppSettings::FtpTransferType(fsFtpTransferType enType)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("TransferType"), enType);
}

CString fsAppSettings::ASCIIExts()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("ASCIIExts"), _T ("txt htm html shtml"));
}

void fsAppSettings::ASCIIExts(LPCTSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("ASCIIExts"), psz);
}

UINT fsAppSettings::RetriesTime()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("RetriesTime"), 5000);
}

void fsAppSettings::RetriesTime(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("RetriesTime"), u);
}

UINT fsAppSettings::SectionMinSize()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("SectionMinSize"), 300*1024);
}

void fsAppSettings::SectionMinSize(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("SectionMinSize"), u);
}

UINT fsAppSettings::MaxSections()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("MaxSections"), 10);
}

void fsAppSettings::MaxSections(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("MaxSections"), u);
}

UINT fsAppSettings::TrafficRestriction()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("TrafficRestriction"), UINT_MAX);
}

void fsAppSettings::TrafficRestriction(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("TrafficRestriction"), u);
}

UINT fsAppSettings::MaxAttempts()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("MaxAttempts"), 20);
}

void fsAppSettings::MaxAttempts(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("MaxAttempts"), u);
}

BOOL fsAppSettings::IgnoreRestrictions()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("IgnoreRestrictions"), FALSE);
}

void fsAppSettings::IgnoreRestrictions(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("IgnoreRestrictions"), b);
}

BOOL fsAppSettings::RestartSpeedLow()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("RestartSpeedLow"), FALSE);
}

void fsAppSettings::RestartSpeedLow(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("RestartSpeedLow"), b);
}

CString fsAppSettings::Agent()
{
	CString str = m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("Agent"), "");
	if (str == "")
		str = PRG_AGENT_NAME;
	if (str == "FDM 1.x") 
		str = PRG_AGENT_NAME;
	return str;
}

void fsAppSettings::Agent(LPCSTR psz)
{
	if (lstrcmpi (psz, PRG_AGENT_NAME) == 0)
		psz = "";
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("Agent"), psz);
}

BOOL fsAppSettings::ReserveDiskSpace ()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("ReserveDiskSpace"), TRUE);
}

void fsAppSettings::ReserveDiskSpace(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("ReserveDiskSpace"), b);
}

UINT fsAppSettings::Timeout()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("Timeout"), 120000);
}

void fsAppSettings::Timeout(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("Timeout"), u);
}

CString fsAppSettings::HttpProxy_Name()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("HttpProxy_Name"), "");
}

void fsAppSettings::HttpProxy_Name(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("HttpProxy_Name"), psz);
}

CString fsAppSettings::HttpProxy_UserName()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("HttpProxy_UserName"), "");
}

void fsAppSettings::HttpProxy_UserName(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("HttpProxy_UserName"), psz);
}

CString fsAppSettings::HttpProxy_Password()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("HttpProxy_Password"), "");
}

void fsAppSettings::HttpProxy_Password(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("HttpProxy_Password"), psz);
}

CString fsAppSettings::HttpsProxy_Name()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("HttpsProxy_Name"), "");
}

void fsAppSettings::HttpsProxy_Name(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("HttpsProxy_Name"), psz);
}

CString fsAppSettings::HttpsProxy_UserName()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("HttpsProxy_UserName"), "");
}

void fsAppSettings::HttpsProxy_UserName(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("HttpsProxy_UserName"), psz);
}

CString fsAppSettings::HttpsProxy_Password()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("HttpsProxy_Password"), "");
}

void fsAppSettings::HttpsProxy_Password(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("HttpsProxy_Password"), psz);
}

CString fsAppSettings::FtpProxy_Name()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("FtpProxy_Name"), "");
}

void fsAppSettings::FtpProxy_Name(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("FtpProxy_Name"), psz);
}

CString fsAppSettings::FtpProxy_UserName()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("FtpProxy_UserName"), "");
}

void fsAppSettings::FtpProxy_UserName(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("FtpProxy_UserName"), psz);
}

CString fsAppSettings::FtpProxy_Password()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("FtpProxy_Password"), "");
}

void fsAppSettings::FtpProxy_Password(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("FtpProxy_Password"), psz);
}

CString fsAppSettings::SocksProxy_Name()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("SocksProxy_Name"), "");
}

void fsAppSettings::SocksProxy_Name(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("SocksProxy_Name"), psz);
}

CString fsAppSettings::SocksProxy_UserName()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("SocksProxy_UserName"), "");
}

void fsAppSettings::SocksProxy_UserName(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("SocksProxy_UserName"), psz);
}

CString fsAppSettings::SocksProxy_Password()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("SocksProxy_Password"), "");
}

void fsAppSettings::SocksProxy_Password(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("SocksProxy_Password"), psz);
}

BOOL fsAppSettings::UseCookie()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("UseCookie"), TRUE);
}

void fsAppSettings::UseCookie(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("UseCookie"), b);
}

BOOL fsAppSettings::UseSocksProxy()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("UseSocksProxy"), FALSE);
}

void fsAppSettings::UseSocksProxy(BOOL bUse)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("UseSocksProxy"), bUse);
}

CString fsAppSettings::AdditionalExtension()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"), _T ("AddExt"), "");
}

void fsAppSettings::AdditionalExtension(LPCSTR pszExt)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"), _T ("AddExt"), pszExt);
}

void fsAppSettings::AutoDelCompleted(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("AutoDelCompleted"), b);
}

BOOL fsAppSettings::AutoDelCompleted()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("AutoDelCompleted"), FALSE);
}

UINT fsAppSettings::AutosaveInterval()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("Autosave"), 3*60*1000);
}

void fsAppSettings::AutosaveInterval(UINT nVal)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("Autosave"), nVal);
}

int fsAppSettings::NOW()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("NOW"), 0);
}

void fsAppSettings::NOW(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("NOW"), i);
}

int fsAppSettings::ActivePlugin()
{
	return m_stgs.GetProfileInt (_T ("Settings"), _T ("ActivePlugin"), 0);
}

void fsAppSettings::ActivePlugin(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings"), _T ("ActivePlugin"), i);
}

UINT fsAppSettings::CreateDld_IdOfLastGrpSelected()
{
	return m_stgs.GetProfileInt (_T ("Settings"), _T ("LastGrpId"), 0);
}

void fsAppSettings::CreateDld_IdOfLastGrpSelected(UINT n)
{
	m_stgs.WriteProfileInt (_T ("Settings"), _T ("LastGrpId"), n);
}

BOOL fsAppSettings::RetreiveInfoWhileGettingList()
{
	return m_stgs.GetProfileInt (_T ("Settings\\WebExplorer"), _T ("RetreiveInfoWhileGettingList"), FALSE);
}

void fsAppSettings::RetreiveInfoWhileGettingList(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\WebExplorer"), _T ("RetreiveInfoWhileGettingList"), b);
}

BOOL fsAppSettings::HFE_FtpPassiveMode()
{
	return m_stgs.GetProfileInt (_T ("Settings\\WebExplorer"), _T ("HFE_FPM"), FALSE);
}

void fsAppSettings::HFE_FtpPassiveMode(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\WebExplorer"), _T ("HFE_FPM"), b);
}

CString fsAppSettings::Monitor_SkipExts()
{
	return m_stgs.GetProfileString (_T ("Settings\\Monitor"), _T ("SkipExtensions"), 
		"pls m3u");
}

void fsAppSettings::Monitor_SkipExts(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Monitor"), _T ("SkipExtensions"), psz);
}

BOOL fsAppSettings::Monitor_IE1()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("IE"), FALSE);
}

void fsAppSettings::Monitor_IE1(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("IE"), b);
}

BOOL fsAppSettings::Monitor_IE2()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("IE2"), TRUE);
}

void fsAppSettings::Monitor_IE2(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("IE2"), b);
}

BOOL fsAppSettings::Monitor_Clipboard()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("Clipboard"), FALSE);
}

void fsAppSettings::Monitor_Clipboard(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("Clipboard"), b);
}

BOOL fsAppSettings::Monitor_ALTShouldPressed()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("ALTShouldPressed"), FALSE);
}

void fsAppSettings::Monitor_ALTShouldPressed(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("ALTShouldPressed"), b);
}

BOOL fsAppSettings::Prg_StartMinimized()
{
	return m_stgs.GetProfileInt (_T ("Settings\\General"), _T ("StartMinimized"), FALSE);
}

void fsAppSettings::Prg_StartMinimized(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\General"), _T ("StartMinimized"), b);
}

BOOL fsAppSettings::Prg_CloseAsMinimize()
{
	return m_stgs.GetProfileInt (_T ("Settings\\General"), _T ("CloseAsMinimize"), TRUE);
}

void fsAppSettings::Prg_CloseAsMinimize(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\General"), _T ("CloseAsMinimize"), b);
}

BOOL fsAppSettings::Prg_MinToTray()
{
	return m_stgs.GetProfileInt (_T ("Settings\\General"), _T ("MinToTray"), TRUE);
}

void fsAppSettings::Prg_MinToTray(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\General"), _T ("MinToTray"), b);
}

CString fsAppSettings::Update_URL()
{
	CString str = m_stgs.GetProfileString (_T ("Settings\\Update"), _T ("URL"), 
		_T ("http://www.freedownloadmanager.org/update/"));
	return str;
}

void fsAppSettings::Update_URL(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Update"), _T ("URL"), psz);
}

BOOL fsAppSettings::Update_LastCheck(SYSTEMTIME *time)
{
	BYTE *pb;
	UINT sz;

	if (m_stgs.GetProfileBinary (_T ("Settings\\Update"), _T ("LastCheck"), &pb, &sz))
	{
		if (sz == sizeof (SYSTEMTIME))
		{
			CopyMemory (time, pb, sz);
			delete [] pb;
			return TRUE;
		}

		delete [] pb;
	}
	
	return FALSE;
}

void fsAppSettings::Update_LastCheck(SYSTEMTIME time)
{
	m_stgs.WriteProfileBinary (_T ("Settings\\Update"), _T ("LastCheck"), (LPBYTE) &time, sizeof (time));
}

BOOL fsAppSettings::View_SWBar()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("SWBar"), TRUE);
}

void fsAppSettings::View_SWBar(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("SWBar"), b);
}

BOOL fsAppSettings::View_AllGroups()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("AllGroups"), TRUE);
}

void fsAppSettings::View_AllGroups(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("AllGroups"), b);
}

BOOL fsAppSettings::View_DLInfo()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DLInfo"), TRUE);
}

void fsAppSettings::View_DLInfo(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DLInfo"), b);
}

BOOL fsAppSettings::View_SchedulerLog()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("SchedulerLog"), TRUE);
}

void fsAppSettings::View_SchedulerLog(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("SchedulerLog"), b);
}

BOOL fsAppSettings::View_HFELog()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("HFELog"), TRUE);
}

void fsAppSettings::View_HFELog(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("HFELog"), b);
}

BOOL fsAppSettings::View_Toolbar()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("Toolbar"), TRUE);
}

void fsAppSettings::View_Toolbar(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("Toolbar"), b);
}

BOOL fsAppSettings::View_Statusbar()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("StatusBar"), TRUE);
}

void fsAppSettings::View_Statusbar(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("StatusBar"), b);
}

void fsAppSettings::View_SaveWndSize(CWnd *pWnd, LPCSTR pszName)
{
	CRect rc;
	pWnd->GetWindowRect (&rc);
	CString strx = pszName, stry = pszName;
	strx += 'x'; stry += 'y';
	m_stgs.WriteProfileInt (_T ("Settings\\View\\Windows"), strx, rc.right-rc.left);
	m_stgs.WriteProfileInt (_T ("Settings\\View\\Windows"), stry, rc.bottom-rc.top);
}

void fsAppSettings::View_ReadWndSize(CWnd *pWnd, LPCSTR pszName)
{
	

	CString strx = pszName, stry = pszName;
	strx += 'x'; stry += 'y';
	int cx, cy;
	cx = m_stgs.GetProfileInt (_T ("Settings\\View\\Windows"), strx, 0);
	cy = m_stgs.GetProfileInt (_T ("Settings\\View\\Windows"), stry, 0);

	if (cx > GetSystemMetrics (SM_CXSCREEN))
		cx = 0;
	if (cy > GetSystemMetrics (SM_CYSCREEN))
		cy = 0;

	if (cx && cy)
		pWnd->MoveWindow (0, 0, cx, cy);
}

void fsAppSettings::View_SaveWndPlacement(CWnd *pWnd, LPCSTR pszName)
{
	WINDOWPLACEMENT wp;
	wp.length = sizeof (wp);
	pWnd->GetWindowPlacement (&wp);
	m_stgs.WriteProfileBinary (_T ("Settings\\View\\Windows"), pszName, (LPBYTE)&wp, sizeof (wp));
}

void fsAppSettings::View_ReadWndPlacement(CWnd *pWnd, LPCSTR pszName, BOOL bInitiallyHidden)
{
	WINDOWPLACEMENT *wp;
	LPBYTE lp;
	UINT uSize;

	if (m_stgs.GetProfileBinary (_T ("Settings\\View\\Windows"), pszName, &lp, &uSize))
	{
		wp = (WINDOWPLACEMENT*) lp;
		int cx = GetSystemMetrics (SM_CXSCREEN);
		int cy = GetSystemMetrics (SM_CYSCREEN);
		if (wp->rcNormalPosition.left >= cx || wp->rcNormalPosition.right <= 0)
		{
			wp->rcNormalPosition.left = cx / 2;
			wp->rcNormalPosition.right = cx / 2 + 40;

			
		}
		if (wp->rcNormalPosition.top >= cy || wp->rcNormalPosition.bottom <= 0)
		{
			wp->rcNormalPosition.top = cy / 2;
			wp->rcNormalPosition.bottom = cy / 2 + 40;

			
		}

		if (bInitiallyHidden)
			wp->showCmd = SW_HIDE;

		pWnd->SetWindowPlacement (wp);
		delete [] lp;
	}
	else
		pWnd->ShowWindow (bInitiallyHidden ? SW_HIDE : SW_SHOW);
}

void fsAppSettings::View_SplitterRatio(LPCSTR pszName, float fRatio)
{
	m_stgs.WriteProfileBinary (_T ("Settings\\View\\Splitters"), pszName, (LPBYTE)&fRatio, sizeof (fRatio));
}

float fsAppSettings::View_SplitterRatio(LPCSTR pszName)
{
	LPBYTE pf;
	UINT nSize;
	float f = 0.5f;

	if (m_stgs.GetProfileBinary (_T ("Settings\\View\\Splitters"), pszName, &pf, &nSize))
	{
		if (pf [0] == 0 && pf [1] == 0 && pf [2] == 192 && pf [3] == 255)
			f = 0.1f;
		else
			CopyMemory (&f, pf, sizeof (f));
		
		delete [] pf;

		if (f < 0 || f > 1)
			f = 0.5;
	}

	return f;
}

void fsAppSettings::View_Language(LPCSTR pszLang)
{
	m_stgs.WriteProfileString (_T ("Settings\\View"), _T ("Language"), pszLang);	
}

CString fsAppSettings::View_Language()
{
	CString strLang = m_stgs.GetProfileString (_T ("Settings\\View"), _T ("Language"), _T (""));

	if (strLang == "")
	{
		

		strLang = "English";
	}

	return strLang;
}

CString fsAppSettings::Dial_LastEntry()
{
	return m_stgs.GetProfileString (_T ("Settings\\Dial"), _T ("LastEntry"), "");
}

void fsAppSettings::Dial_LastEntry(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Dial"), _T ("LastEntry"), psz);
}

BOOL fsAppSettings::Dial_Auto()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Dial"), _T ("Auto"), FALSE);
}

void fsAppSettings::Dial_Auto(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Dial"), _T ("Auto"), b);
}

BOOL fsAppSettings::View_SpiderTree()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("SpiderTree"), TRUE);
}

void fsAppSettings::View_SpiderTree(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("SpiderTree"), b);
}

CString fsAppSettings::Spider_HTMLExts()
{
	return m_stgs.GetProfileString (_T ("Settings\\Spider"), _T ("HTMLExts"), "html htm shtm shtml phml dhtml php hta htc cgi asp");
}

void fsAppSettings::Spider_HTMLExts(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Spider"), _T ("HTMLExts"), psz);
}

BOOL fsAppSettings::Spider_NotAllPages()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Spider"), _T ("NotAllPages"), TRUE);
}

void fsAppSettings::Spider_NotAllPages(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Spider"), _T ("NotAllPages"), b);
}

BOOL fsAppSettings::Spider_NotAllFiles()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Spider"), _T ("NotAllFiles"), TRUE);
}

void fsAppSettings::Spider_NotAllFiles(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Spider"), _T ("NotAllFiles"), b);
}

BOOL fsAppSettings::Spider_NotAllImages()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Spider"), _T ("NotAllImages"), TRUE);
}

void fsAppSettings::Spider_NotAllImages(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Spider"), _T ("NotAllImages"), b);
}

BOOL fsAppSettings::Spider_DownloadImages()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Spider"), _T ("DownloadImages"), TRUE);
}

void fsAppSettings::Spider_DownloadImages(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Spider"), _T ("DownloadImages"), b);
}

BOOL fsAppSettings::Spider_DownloadFiles()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Spider"), _T ("DownloadFiles"), FALSE);
}

void fsAppSettings::Spider_DownloadFiles(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Spider"), _T ("DownloadFiles"), b);
}

int fsAppSettings::Spider_Depth()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Spider"), _T ("Depth"), 4);
}

void fsAppSettings::Spider_Depth(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Spider"), _T ("Depth"), i);
}

CString fsAppSettings::Spider_Exts()
{
	return m_stgs.GetProfileString (_T ("Settings\\Spider"), _T ("Exts"), "");
}

void fsAppSettings::Spider_Exts(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Spider"), _T ("Exts"), psz);
}

BOOL fsAppSettings::Spider_DownloadStyles()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Spider"), _T ("DownloadStyles"), TRUE);
}

void fsAppSettings::Spider_DownloadStyles(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Spider"), _T ("DownloadStyles"), b);
}

CString fsAppSettings::Spider_ImgExts()
{
	return m_stgs.GetProfileString (_T ("Settings\\Spider"), _T ("ImgExts"), "");
}

void fsAppSettings::Spider_ImgExts(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Spider"), _T ("ImgExts"), psz);
}

int fsAppSettings::Last_Autostart()
{
	return m_stgs.GetProfileInt (_T ("Settings"), _T ("LastAutoStart"), 0);
}

void fsAppSettings::Last_Autostart(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings"), _T ("LastAutoStart"), i);
}

int fsAppSettings::View_DldInfoCurTab()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DldInfoCurTab"), 0);
}

void fsAppSettings::View_DldInfoCurTab(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DldInfoCurTab"), i);
}

BYTE fsAppSettings::DropBoxWndBlend()
{
	return (BYTE) m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DropBoxWndBlend"), 150);
}

void fsAppSettings::DropBoxWndBlend(BYTE b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DropBoxWndBlend"), b);
}

BYTE fsAppSettings::DownloadsInfoWndBlend()
{
	return (BYTE) m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DownloadsInfoWndBlend"), 150);
}

void fsAppSettings::DownloadsInfoWndBlend(BYTE b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DownloadsInfoWndBlend"), b);
}

BOOL fsAppSettings::View_FloatingWindow()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("ShowFW"), TRUE);
}

void fsAppSettings::View_FloatingWindow(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("ShowFW"), b);
}

BOOL fsAppSettings::DetLog()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("DetLog"), FALSE);
}

void fsAppSettings::DetLog(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("DetLog"), b);
}

CString fsAppSettings::Monitor_OperaPDInstalledTo()
{
	return m_stgs.GetProfileString (_T ("Settings\\Monitor"), _T ("OPDI"), "");
}

void fsAppSettings::Monitor_OperaPDInstalledTo(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Monitor"), _T ("OPDI"), psz);
}

CString fsAppSettings::Monitor_NetscapePDInstalledTo()
{
	return m_stgs.GetProfileString (_T ("Settings\\Monitor"), _T ("NPDI"), "");
}

void fsAppSettings::Monitor_NetscapePDInstalledTo(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Monitor"), _T ("NPDI"), psz);
}

CString fsAppSettings::Monitor_FirefoxPDInstalledTo()
{
	return m_stgs.GetProfileString (_T ("Settings\\Monitor"), _T ("FPDI"), "");
}

void fsAppSettings::Monitor_FirefoxPDInstalledTo(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Monitor"), _T ("FPDI"), psz);
}

BOOL fsAppSettings::Monitor_AllowDownload()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("AllowDownload"), TRUE);
}

void fsAppSettings::Monitor_AllowDownload(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("AllowDownload"), b);
}

CString fsAppSettings::Download_CreateExt()
{
	return m_stgs.GetProfileString (_T ("Settings\\Network"),"CreateExt", "");
}

void fsAppSettings::Download_CreateExt(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Network"),"CreateExt", psz);
}

BOOL fsAppSettings::View_SizesInBytes()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("SizesInBytes"), FALSE);
}

void fsAppSettings::View_SizesInBytes(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("SizesInBytes"), b);
}

BOOL fsAppSettings::Avir_Perform()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Avir"), _T ("Perform"), FALSE);
}

void fsAppSettings::Avir_Perform(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Avir"), _T ("Perform"), b);
}

CString fsAppSettings::Avir_Name()
{
	return m_stgs.GetProfileString (_T ("Settings\\Avir"), _T ("Name"), "");
}

void fsAppSettings::Avir_Name(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Avir"), _T ("Name"), psz);
}

CString fsAppSettings::Avir_Args()
{
	return m_stgs.GetProfileString (_T ("Settings\\Avir"), _T ("Args"), "%file%");
}

void fsAppSettings::Avir_Args(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Avir"), _T ("Args"), psz);
}

CString fsAppSettings::Avir_Exts()
{
	return m_stgs.GetProfileString (_T ("Settings\\Avir"), _T ("Exts"), 
		"exe com msi zip rar arj tar t?z bin cab doc");
}

void fsAppSettings::Avir_Exts(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Avir"), _T ("Exts"), psz);
}

BOOL fsAppSettings::Spider_SavePagesUnderHTM()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Spider"), _T ("SavePagesUnderHTM"), TRUE);
}

void fsAppSettings::Spider_SavePagesUnderHTM(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Spider"), _T ("SavePagesUnderHTM"), b);
}

BOOL fsAppSettings::NewVerExists()
{
	return m_stgs.GetProfileInt (_T ("Update"), _T ("NewVerExists"), FALSE);
}

void fsAppSettings::NewVerExists(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Update"), _T ("NewVerExists"), b);
}

BOOL fsAppSettings::Network_Br_SettingsSaved()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("BrUA_Saved"), FALSE);
}

void fsAppSettings::Network_Br_SettingsSaved(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("BrUA_Saved"), b);
}

BOOL fsAppSettings::Notif_UseBalloon()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Notifications"), _T ("UseBalloons"), TRUE);
}

void fsAppSettings::Notif_UseBalloon(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Notifications"), _T ("UseBalloons"), b);
}

DWORD fsAppSettings::Notif_BalloonTimeout()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Notifications"), _T ("BalloonTimeout"), 3);
}

#pragma warning (disable : 4100)

void fsAppSettings::Notif_BalloonTimeout(DWORD dw)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Notifications"), _T ("BalloonTimeout"), dw);
}

BOOL fsAppSettings::Mirr_AutoSearch()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("AutoSearch"), FALSE);
}

void fsAppSettings::Mirr_AutoSearch(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("AutoSearch"), b);
}

UINT fsAppSettings::Mirr_MaxCount()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("MaxCount"), UINT_MAX);
}

void fsAppSettings::Mirr_MaxCount(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("MaxCount"), u);
}

BOOL fsAppSettings::Mirr_CalcSpeed()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("CalcSpeed"), FALSE);
}

void fsAppSettings::Mirr_CalcSpeed(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("CalcSpeed"), b);
}

UINT fsAppSettings::Mirr_RecalcSpeedTime()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("RST"), 0);
}

void fsAppSettings::Mirr_RecalcSpeedTime(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("RST"), u);
}

UINT fsAppSettings::Mirr_FileMinSize()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("MinSize"), 1000*1024);
}

void fsAppSettings::Mirr_FileMinSize(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("MinSize"), u);
}

BOOL fsAppSettings::Mirr_DontSearchIfSizeUnk()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("DontIfSizeUnk"), TRUE);
}

void fsAppSettings::Mirr_DontSearchIfSizeUnk(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("DontIfSizeUnk"), b);
}

BOOL fsAppSettings::View_FloatingInfoWindow()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("ShowFIW"), TRUE);
}

void fsAppSettings::View_FloatingInfoWindow(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("ShowFIW"), b);
}

void fsAppSettings::NewDL_GroupId(UINT n)
{
	m_stgs.WriteProfileInt (_T ("Settings\\New Download"), _T ("GroupId"), n);
}

UINT fsAppSettings::NewDL_GroupId()
{
	return m_stgs.GetProfileInt (_T ("Settings\\New Download"), _T ("GroupId"), -1);
}

void fsAppSettings::NewDL_Group_old(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\New Download"), _T ("Group"), psz);
}

CString fsAppSettings::NewDL_Group_old()
{
	return m_stgs.GetProfileString (_T ("Settings\\New Download"), _T ("Group"), "");
}

BOOL fsAppSettings::Monitor_Silent()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("Silent"), FALSE);
}

void fsAppSettings::Monitor_Silent(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("Silent"), b);
}

BOOL fsAppSettings::Monitor_IEMenu_DLThis()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("DLThis"), TRUE);
}

void fsAppSettings::Monitor_IEMenu_DLThis(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("DLThis"), b);
}

void fsAppSettings::Monitor_IEMenu_DLPage(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("DLPage"), b);
}

BOOL fsAppSettings::Monitor_IEMenu_DLPage()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("DLPage"), FALSE);
}

void fsAppSettings::Monitor_IEMenu_DLAll(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("DLAll"), b);
}

BOOL fsAppSettings::Monitor_IEMenu_DLAll()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("DLAll"), TRUE);
}

void fsAppSettings::Monitor_IEMenu_DLSelected(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("DLSelected"), b);
}

BOOL fsAppSettings::Monitor_IEMenu_DLSelected()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("DLSelected"), TRUE);
}

CString fsAppSettings::Snd_DownloadComplete()
{
	return m_stgs.GetProfileString (_T ("Settings\\Sounds"), _T ("DownloadComplete"), "");
}

void fsAppSettings::Snd_DownloadComplete(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Sounds"), _T ("DownloadComplete"), psz);
}

CString fsAppSettings::Snd_DownloadAdded()
{
	return m_stgs.GetProfileString (_T ("Settings\\Sounds"), _T ("DownloadAdded"), "");
}

void fsAppSettings::Snd_DownloadAdded(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Sounds"), _T ("DownloadAdded"), psz);
}

CString fsAppSettings::Snd_NoActiveDownloads()
{
	return m_stgs.GetProfileString (_T ("Settings\\Sounds"), _T ("NoActiveDownloads"), "");
}

void fsAppSettings::Snd_NoActiveDownloads(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Sounds"), _T ("NoActiveDownloads"), psz);
}

CString fsAppSettings::Snd_DialingOK()
{
	return m_stgs.GetProfileString (_T ("Settings\\Sounds"), _T ("DialingOK"), "");
}

void fsAppSettings::Snd_DialingOK(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Sounds"), _T ("DialingOK"), psz);
}

CString fsAppSettings::Snd_DialingFailed()
{
	return m_stgs.GetProfileString (_T ("Settings\\Sounds"), _T ("DialingFailed"), "");
}

void fsAppSettings::Snd_DialingFailed(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Sounds"), _T ("DialingFailed"), psz);
}

CString fsAppSettings::Snd_DownloadFailed()
{
	return m_stgs.GetProfileString (_T ("Settings\\Sounds"), _T ("DownloadFailed"), "");
}

void fsAppSettings::Snd_DownloadFailed(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Sounds"), _T ("DownloadFailed"), psz);
}

BOOL fsAppSettings::Snd_Use()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Sounds"), _T ("Use"), FALSE);
}

void fsAppSettings::Snd_Use(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Sounds"), _T ("Use"), b);
}

void fsAppSettings::History_Use(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\History"), _T ("Use"), b);
}

BOOL fsAppSettings::History_Use()
{
	return m_stgs.GetProfileInt (_T ("Settings\\History"), _T ("Use"), TRUE);
}

int fsAppSettings::History_KeepDays()
{
	return m_stgs.GetProfileInt (_T ("Settings\\History"), _T ("KeepDays"), 15);
}

void fsAppSettings::History_KeepDays(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\History"), _T ("KeepDays"), i);
}

void fsAppSettings::History_MaxRecords(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\History"), _T ("MaxRecords"), i);
}

int fsAppSettings::History_MaxRecords()
{
	return m_stgs.GetProfileInt (_T ("Settings\\History"), _T ("MaxRecords"), 30);
}

BOOL fsAppSettings::History_FoldersOnly()
{
	return m_stgs.GetProfileInt (_T ("Settings\\History"), _T ("FoldersOnly"), FALSE);
}

void fsAppSettings::History_FoldersOnly(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\History"), _T ("FoldersOnly"), b);
}

int fsAppSettings::Export_WhichDlds()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Export"), _T ("WhichDlds"), 0);
}

void fsAppSettings::Export_WhichDlds(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Export"), _T ("WhichDlds"), i);
}

BOOL fsAppSettings::Export_DontExpCompleted()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Export"), _T ("DontComp"), TRUE);
}

void fsAppSettings::Export_DontExpCompleted(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Export"), _T ("DontComp"), b);
}

BOOL fsAppSettings::Export_Append()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Export"), _T ("Append"), TRUE);
}

void fsAppSettings::Export_Append(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Export"), _T ("Append"), b);
}

BOOL fsAppSettings::Deleted_Bypass()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Deleted"), _T ("Bypass"), FALSE);
}

void fsAppSettings::Deleted_Bypass(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Deleted"), _T ("Bypass"), b);
}

UINT fsAppSettings::Deleted_MaxCount()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Deleted"), _T ("MaxCount"), 500);
}

void fsAppSettings::Deleted_MaxCount(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Deleted"), _T ("MaxCount"), u);
}

BOOL fsAppSettings::Deleted_ConfirmDeletion()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Deleted"), _T ("ConfirmDeletion"), TRUE);
}

void fsAppSettings::Deleted_ConfirmDeletion(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Deleted"), _T ("ConfirmDeletion"), b);
}

BOOL fsAppSettings::Deleted_BypassCompleted()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Deleted"), _T ("BypassCompleted"), TRUE);
}

void fsAppSettings::Deleted_BypassCompleted(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Deleted"), _T ("BypassCompleted"), b);
}

BOOL fsAppSettings::History_Downloads_Use()
{
	return m_stgs.GetProfileInt (_T ("Settings\\History\\Downloads"), _T ("Use"), TRUE);
}

void fsAppSettings::History_Downloads_Use(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\History\\Downloads"), _T ("Use"), b);
}

UINT fsAppSettings::History_Downloads_KeepDays()
{
	return m_stgs.GetProfileInt (_T ("Settings\\History\\Downloads"), _T ("KeepDays"), UINT_MAX);
}

void fsAppSettings::History_Downloads_KeepDays(UINT u)
{
	m_stgs.WriteProfileInt (_T ("Settings\\History\\Downloads"), _T ("KeepDays"), u);
}

BOOL fsAppSettings::History_Downloads_CompletedOnly()
{
	return m_stgs.GetProfileInt (_T ("Settings\\History\\Downloads"), _T ("CompOnly"), TRUE);
}

void fsAppSettings::History_Downloads_CompletedOnly(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\History\\Downloads"), _T ("CompOnly"), b);
}

void fsAppSettings::Find_What(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Find"), _T ("What"), psz);
}

CString fsAppSettings::Find_What()
{
	return m_stgs.GetProfileString (_T ("Settings\\Find"), _T ("What"), "");
}

UINT fsAppSettings::Find_GroupId()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Find"), _T ("GroupId"), -1);
}

void fsAppSettings::Find_GroupId(UINT n)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Find"), _T ("GroupId"), n);
}

void fsAppSettings::Find_TimeFrom(FILETIME &t)
{
	m_stgs.WriteProfileBinary (_T ("Settings\\Find"), _T ("t1"),
		(LPBYTE) &t, sizeof (t));
}

FILETIME fsAppSettings::Find_TimeFrom()
{
	BYTE *pb;
	UINT sz;
	FILETIME t;
	ZeroMemory (&t, sizeof (t));

	if (m_stgs.GetProfileBinary (_T ("Settings\\Find"), _T ("t1"), &pb, &sz))
	{
		if (sz == sizeof (t))
		{
			CopyMemory (&t, pb, sizeof (t));
			delete [] pb;
		}
	}
	
	return t;
}

void fsAppSettings::Find_TimeTo(FILETIME &t)
{
	m_stgs.WriteProfileBinary (_T ("Settings\\Find"), _T ("t2"),
		(LPBYTE) &t, sizeof (t));
}

FILETIME fsAppSettings::Find_TimeTo()
{
	BYTE *pb;
	UINT sz;
	FILETIME t;
	ZeroMemory (&t, sizeof (t));

	if (m_stgs.GetProfileBinary (_T ("Settings\\Find"), _T ("t2"), &pb, &sz))
	{
		if (sz == sizeof (t))
		{
			CopyMemory (&t, pb, sizeof (t));
			delete [] pb;
		}
	}
	
	return t;
}

UINT64 fsAppSettings::Find_FileSizeFrom()
{
	BYTE *pb;
	UINT sz;
	UINT64 u = 0;

	if (m_stgs.GetProfileBinary (_T ("Settings\\Find"), _T ("s1"), &pb, &sz))
	{
		if (sz == sizeof (u))
		{
			CopyMemory (&u, pb, sizeof (u));
			delete [] pb;
		}
	}
	
	return u;
}

void fsAppSettings::Find_FileSizeFrom(UINT64 u)
{
	m_stgs.WriteProfileBinary (_T ("Settings\\Find"), _T ("s1"),
		(LPBYTE) &u, sizeof (u));
}

void fsAppSettings::Find_FileSizeTo(UINT64 u)
{
	m_stgs.WriteProfileBinary (_T ("Settings\\Find"), _T ("s2"),
		(LPBYTE) &u, sizeof (u));
}

UINT64 fsAppSettings::Find_FileSizeTo()
{
	BYTE *pb;
	UINT sz;
	UINT64 u = 0;

	if (m_stgs.GetProfileBinary (_T ("Settings\\Find"), _T ("s2"), &pb, &sz))
	{
		if (sz == sizeof (u))
		{
			CopyMemory (&u, pb, sizeof (u));
			delete [] pb;
		}
	}
	
	return u;
}

BOOL fsAppSettings::UseZipPreview()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("UseZipPreview"), FALSE);
}

void fsAppSettings::UseZipPreview(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("UseZipPreview"), b);
}

BOOL fsAppSettings::MP_Mute()
{
	return m_stgs.GetProfileInt (_T ("Settings\\MP"), _T ("Mute"), FALSE);
}

void fsAppSettings::MP_Mute(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\MP"), _T ("Mute"), b);
}

int fsAppSettings::MP_Volume()
{
	return m_stgs.GetProfileInt (_T ("Settings\\MP"), _T ("Volume"), 50);
}

void fsAppSettings::MP_Volume(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\MP"), _T ("Volume"), i);
}

BOOL fsAppSettings::NewDL_AutoStart()
{
	return m_stgs.GetProfileInt (_T ("Settings\\New Download"), _T ("AutoStart"), TRUE);
}

void fsAppSettings::NewDL_AutoStart(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\New Download"), _T ("AutoStart"), b);
}

BOOL fsAppSettings::NewDL_UseZIPPreview()
{
	return m_stgs.GetProfileInt (_T ("Settings\\New Download"), _T ("UseZIPPreview"), TRUE);
}

void fsAppSettings::NewDL_UseZIPPreview(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\New Download"), _T ("UseZIPPreview"), b);
}

WORD fsAppSettings::RollBackSize()
{
	return (WORD)m_stgs.GetProfileInt (_T ("Settings\\Network"), _T ("RollBackSize"), 3000);
}

void fsAppSettings::RollBackSize(WORD w)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network"), _T ("RollBackSize"), w);
}

int fsAppSettings::Monitor_SkipSmaller()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("SkipSmaller"), 0);
}

void fsAppSettings::Monitor_SkipSmaller(int iSize)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("SkipSmaller"), iSize);
}

BOOL fsAppSettings::CheckRecycleBinSize()
{
	return m_stgs.GetProfileInt (_T ("Settings"), _T ("CheckRBSize"), TRUE);
}

void fsAppSettings::CheckRecycleBinSize(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings"), _T ("CheckRBSize"), b);
}

BOOL fsAppSettings::CheckHistorySize()
{
	return m_stgs.GetProfileInt (_T ("Settings"), _T ("CheckHistSize"), TRUE);
}

void fsAppSettings::CheckHistorySize(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings"), _T ("CheckHistSize"), b);
}

CString fsAppSettings::Skin_Current()
{
	return m_stgs.GetProfileString (_T ("Settings\\Skins"), _T ("Current"), "");
}

void fsAppSettings::Skin_Current(CString str)
{
	m_stgs.WriteProfileString (_T ("Settings\\Skins"), _T ("Current"), str);
}

DWORD fsAppSettings::Skin_Flags()
{
	
	return m_stgs.GetProfileInt ("Settings\\Skins", "Flags", 3);
}

void fsAppSettings::Skin_Flags(DWORD dw)
{
	m_stgs.WriteProfileInt ("Settings\\Skins", "Flags", dw);
}

BOOL fsAppSettings::SM_KeepPasswords()
{
	return m_stgs.GetProfileInt (_T ("Settings\\SiteManager"), _T ("KeepPasswords"), TRUE);
}

void fsAppSettings::SM_KeepPasswords(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\SiteManager"), _T ("KeepPasswords"), b);
}

BOOL fsAppSettings::SM_PwdsManualAddition()
{
	return m_stgs.GetProfileInt (_T ("Settings\\SiteManager"), _T ("pma"), FALSE);
}

void fsAppSettings::SM_PwdsManualAddition(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\SiteManager"), _T ("pma"), b);
}

BOOL fsAppSettings::SM_DontSavePwdsToDisk()
{
	return m_stgs.GetProfileInt (_T ("Settings\\SiteManager"), _T ("DontSavePwdsToDisk"), FALSE);
}

void fsAppSettings::SM_DontSavePwdsToDisk(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\SiteManager"), _T ("DontSavePwdsToDisk"), b);
}

BOOL fsAppSettings::FloatingWndsHideInFSMode()
{
	return m_stgs.GetProfileInt (_T ("Settings\\General"), _T ("FltWndsHideInFSMode"), TRUE);
}

void fsAppSettings::FloatingWndsHideInFSMode(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\General"), _T ("FltWndsHideInFSMode"), b);
}

int fsAppSettings::Mirr_Server()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("Server"), 0);
}

void fsAppSettings::Mirr_Server(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Network\\Mirrors"), _T ("Server"), i);
}

BOOL fsAppSettings::NewDL_GenerateNameAutomatically()
{
	return m_stgs.GetProfileInt (_T ("Settings\\New Download"), _T ("GenerateNameAutomatically"), TRUE);
}

void fsAppSettings::NewDL_GenerateNameAutomatically(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\New Download"), _T ("GenerateNameAutomatically"), b);
}

void fsAppSettings::SaveStringList(LPCSTR pszSubKey, LPCSTR pszValue, CStringList &v)
{
	int lt = 0;
	int i = 0;
	for (i = 0; i < v.GetCount (); i++)
		lt += v.GetAt (v.FindIndex (i)).GetLength ();
	lt += v.GetCount ()+1;

	LPBYTE pb = new BYTE [lt];
	LPSTR pbp = (LPSTR)pb;

	for (i = 0; i < v.GetCount (); i++)
	{
		CString& str = v.GetAt (v.FindIndex (i));
		lstrcpy (pbp, str);
		pbp += str.GetLength ()+1;
	}

	*pbp = 0;
	m_stgs.WriteProfileBinary (pszSubKey, pszValue, pb, lt);
}

BOOL fsAppSettings::LoadStringList(LPCSTR pszSubKey, LPCSTR pszValue, CStringList *v)
{
	LPBYTE pb = NULL;
	UINT lt = 0;
	
	v->RemoveAll ();
	
	if (FALSE == m_stgs.GetProfileBinary (pszSubKey, pszValue, &pb, &lt))
		return FALSE;
	if (pb == NULL || lt == 0)
		return FALSE;

	LPCSTR pbp = (LPCSTR)pb;

	while ((int)lt > 1)
	{
		v->AddTail (pbp);
		lt -= lstrlen (pbp)+1;
		pbp += lstrlen (pbp)+1;

	}

	delete [] pb;
	return TRUE;
}

BOOL fsAppSettings::FilesToDelete(CStringList &v)
{
	return LoadStringList ("FilesToDelete", "", &v);
}

void fsAppSettings::FilesToDelete_save(CStringList &v)
{
	SaveStringList ("FilesToDelete", "", v);
}

vmsSpreadHelpRemind fsAppSettings::View_SpreadHelpDialog()
{
	return (vmsSpreadHelpRemind)
		m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("SpreadHelpDialog"), SHR_WAIT1STTIME);
}

void fsAppSettings::View_SpreadHelpDialog(vmsSpreadHelpRemind b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("SpreadHelpDialog"), b);
}

BOOL fsAppSettings::View_SpreadHelpDialog_LastTimeShown(FILETIME &time)
{
	BYTE *pb;
	UINT sz;

	if (m_stgs.GetProfileBinary (_T ("Settings\\View"), _T ("SpreadHelpDialog_lts"), &pb, &sz))
	{
		if (sz == sizeof (time))
		{
			CopyMemory (&time, pb, sz);
			delete [] pb;
			return TRUE;
		}
	}
	
	return FALSE;
}

void fsAppSettings::View_SpreadHelpDialog_LastTimeShown_save(FILETIME &time)
{
	m_stgs.WriteProfileBinary (_T ("Settings\\View"), _T ("SpreadHelpDialog_lts"), (LPBYTE)&time, sizeof (time));
}

BOOL fsAppSettings::View_GCVButton()
{
	return m_stgs.GetProfileInt ("Settings\\View", "GCVButton", TRUE);
}

void fsAppSettings::View_GCVButton(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\View", "GCVButton", b);
}

BOOL fsAppSettings::View_TUMChanged()
{
	return m_stgs.GetProfileInt ("Settings\\View", "TUMChanged", TRUE);
}

void fsAppSettings::View_TUMChanged(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\View", "TUMChanged", b);
}

CString fsAppSettings::DldListDlg_Filter_LastExts()
{
	return m_stgs.GetProfileString (_T ("Settings\\Last\\DldListDlg"), _T ("Exts"), "");
}

void fsAppSettings::DldListDlg_Filter_LastExts(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Last\\DldListDlg"), _T ("Exts"), psz);
}

BOOL fsAppSettings::DldListDlg_Filter_LastExtsRemove()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Last\\DldListDlg"), _T ("ler"), FALSE);
}

void fsAppSettings::DldListDlg_Filter_LastExtsRemove(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Last\\DldListDlg"), _T ("ler"), b);
}

DWORD fsAppSettings::CreateBD_LastAtoZ()
{
	return (DWORD) m_stgs.GetProfileInt (_T ("Settings\\Last\\CBD"), _T ("AtoZ"), MAKELPARAM (0, 'Z' - 'A' - 1));
}

void fsAppSettings::CreateBD_LastAtoZ(DWORD dw)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Last\\CBD"), _T ("AtoZ"), dw);
}

BOOL fsAppSettings::DontSaveLogs()
{
	return m_stgs.GetProfileInt (_T ("Settings\\General"), _T ("DontSaveLogs"), TRUE);
}

void fsAppSettings::DontSaveLogs(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\General"), _T ("DontSaveLogs"), b);
}

int fsAppSettings::Export_WhichHist()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Export"), _T ("WhichHist"), 0);
}

void fsAppSettings::Export_WhichHist(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Export"), _T ("WhichHist"), i);
}

BOOL fsAppSettings::Export_Hist_CompletedOnly()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Export"), _T ("Hist_CompletedOnly"), TRUE);
}

void fsAppSettings::Export_Hist_CompletedOnly(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Export"), _T ("Hist_CompletedOnly"), b);
}

BOOL fsAppSettings::Export_Hist_Append()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Export"), _T ("Hist_Append"), TRUE);
}

void fsAppSettings::Export_Hist_Append(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Export"), _T ("Hist_Append"), b);
}

BOOL fsAppSettings::DownloadDialog_AutoClose()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DldDlg_AutoClose"), TRUE);
}

void fsAppSettings::DownloadDialog_AutoClose(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DldDlg_AutoClose"), b);
}

BOOL fsAppSettings::DownloadDialog_Use()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DldDlg_Use"), TRUE);
}

void fsAppSettings::DownloadDialog_Use(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DldDlg_Use"), b);
}

BOOL fsAppSettings::DownloadDialog_DontAskOnHide()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DldDlg_DontAskOnHide"), FALSE);
}

void fsAppSettings::DownloadDialog_DontAskOnHide(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DldDlg_DontAskOnHide"), b);
}

int fsAppSettings::NumberOfDlCreatesByUser()
{
	return m_stgs.GetProfileInt (_T ("Settings\\General"), _T ("NumberOfDlCBU"), 0);
}

void fsAppSettings::NumberOfDlCreatesByUser(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\General"), _T ("NumberOfDlCBU"), i);
}

UINT fsAppSettings::ConfTimeout_Hangup()
{
	return m_stgs.GetProfileInt ("Settings\\Scheduler\\ConfTimeouts", "Hangup", 30);
}

void fsAppSettings::ConfTimeout_Hangup(UINT u)
{
	m_stgs.WriteProfileInt ("Settings\\Scheduler\\ConfTimeouts", "Hangup", u);
}

UINT fsAppSettings::ConfTimeout_Exit()
{
	return m_stgs.GetProfileInt ("Settings\\Scheduler\\ConfTimeouts", "Exit", 30);
}

void fsAppSettings::ConfTimeout_Exit(UINT u)
{
	m_stgs.WriteProfileInt ("Settings\\Scheduler\\ConfTimeouts", "Exit", u);
}

UINT fsAppSettings::ConfTimeout_Shutdown()
{
	return m_stgs.GetProfileInt ("Settings\\Scheduler\\ConfTimeouts", "Shutdown", 30);
}

void fsAppSettings::ConfTimeout_Shutdown(UINT u)
{
	m_stgs.WriteProfileInt ("Settings\\Scheduler\\ConfTimeouts", "Shutdown", u);
}

UINT fsAppSettings::ConfTimeout_LaunchDld()
{
	return m_stgs.GetProfileInt ("Settings\\Scheduler\\ConfTimeouts", "LaunchDld", 30);
}

void fsAppSettings::ConfTimeout_LaunchDld(UINT u)
{
	m_stgs.WriteProfileInt ("Settings\\Scheduler\\ConfTimeouts", "LaunchDld", u);
}

CString fsAppSettings::CreateBD_LastNumbers()
{
	return m_stgs.GetProfileString (_T ("Settings\\Last\\CBD"), _T ("Numbers"), "1-100");
}

void fsAppSettings::CreateBD_LastNumbers(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Last\\CBD"), _T ("Numbers"), psz);
}

UINT64 fsAppSettings::TotalTraffic()
{
	BYTE *pb;
	UINT sz;
	UINT64 u = 0;

	if (m_stgs.GetProfileBinary (_T ("Stat"), _T ("TotalTraffic"), &pb, &sz))
	{
		if (sz == sizeof (u))
		{
			CopyMemory (&u, pb, sizeof (u));
			delete [] pb;
		}
	}
	
	return u;
}

void fsAppSettings::TotalTraffic(UINT64 u)
{
	m_stgs.WriteProfileBinary (_T ("Stat"), _T ("TotalTraffic"),
		(LPBYTE) &u, sizeof (u));
}

UINT64 fsAppSettings::TotalTraffic_PrevMonth()
{
	BYTE *pb;
	UINT sz;
	UINT64 u = 0;

	if (m_stgs.GetProfileBinary (_T ("Stat"), _T ("TotalTraffic_PrevMonth"), &pb, &sz))
	{
		if (sz == sizeof (u))
		{
			CopyMemory (&u, pb, sizeof (u));
			delete [] pb;
		}
	}
	
	return u;
}

void fsAppSettings::TotalTraffic_PrevMonth(UINT64 u)
{
	m_stgs.WriteProfileBinary (_T ("Stat"), _T ("TotalTraffic_PrevMonth"),
		(LPBYTE) &u, sizeof (u));
}

int fsAppSettings::TotalTraffic_CurrMonth()
{
	return m_stgs.GetProfileInt ("Stat", "TotalTraffic_CurrMonth", -1);
}

void fsAppSettings::TotalTraffic_CurrMonth(int i)
{
	m_stgs.WriteProfileInt ("Stat", "TotalTraffic_CurrMonth", i);
}

BOOL fsAppSettings::WD_DisableAfterExec()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Last"), _T ("WD_DisableAfterExec"), TRUE);
}

void fsAppSettings::WD_DisableAfterExec(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Last"), _T ("WD_DisableAfterExec"), b);
}

BOOL fsAppSettings::IsArchivePackInstalled()
{
	return m_stgs.GetProfileInt ("", "apinstalled", FALSE);
}

BOOL fsAppSettings::DontShowInstallAP()
{
	return m_stgs.GetProfileInt ("Settings\\View", "DontShowInstallAP", FALSE);
}

void fsAppSettings::DontShowInstallAP(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\View", "DontShowInstallAP", b);
}

CString fsAppSettings::Hash_LastAlgorithm()
{
	return m_stgs.GetProfileString ("Settings\\Hash", "LastAlgorithm", "MD5");
}

void fsAppSettings::Hash_LastAlgorithm(LPCSTR psz)
{
	m_stgs.WriteProfileString ("Settings\\Hash", "LastAlgorithm", psz);
}

BOOL fsAppSettings::View_DontShowHashCheckResultIfOK()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DontShowHashCheckResultIfOK"), FALSE);
}

void fsAppSettings::View_DontShowHashCheckResultIfOK(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DontShowHashCheckResultIfOK"), b);
}

CString fsAppSettings::CreateBD_SaveAs_Template()
{
	return m_stgs.GetProfileString (_T ("Settings\\Last\\CBD"), _T ("SaveAsTemplate"), "");
}

void fsAppSettings::CreateBD_SaveAs_Template(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Last\\CBD"), _T ("SaveAsTemplate"), psz);
}

BOOL fsAppSettings::App_2_0_SchedulerFixPerformed()
{
	return m_stgs.GetProfileInt ("", "sfp_2.0", FALSE);
}

void fsAppSettings::App_2_0_SchedulerFixPerformed(BOOL b)
{
	m_stgs.WriteProfileInt ("", "sfp_2.0", b);
}

CString fsAppSettings::Monitor_MozillaSuitePDInstalledTo()
{
	return m_stgs.GetProfileString (_T ("Settings\\Monitor"), _T ("MozSPDI"), "");
}

void fsAppSettings::Monitor_MozillaSuitePDInstalledTo(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Monitor"), _T ("MozSPDI"), psz);
}

CString fsAppSettings::View_SpreadHelpDialog_LinkToUsText()
{
	return m_stgs.GetProfileString (_T ("Settings\\View"), _T ("SpreadHelpDialog_ltut"), "");
}

void fsAppSettings::View_SpreadHelpDialog_LinkToUsText(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\View"), _T ("SpreadHelpDialog_ltut"), psz);
}

CString fsAppSettings::View_SpreadHelpDialog_RadioButton1Text()
{
	return m_stgs.GetProfileString (_T ("Settings\\View"), _T ("SpreadHelpDialog_rb1t"), "");
}

void fsAppSettings::View_SpreadHelpDialog_RadioButton1Text(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\View"), _T ("SpreadHelpDialog_rb1t"), psz);
}

CString fsAppSettings::View_SpreadHelpDialog_RadioButton2Text()
{
	return m_stgs.GetProfileString (_T ("Settings\\View"), _T ("SpreadHelpDialog_rb2t"), "");
}

void fsAppSettings::View_SpreadHelpDialog_RadioButton2Text(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\View"), _T ("SpreadHelpDialog_rb2t"), psz);
}

BOOL fsAppSettings::Community_SwitchToOpinions()
{
	return m_stgs.GetProfileInt ("Settings\\Community", "SwitchToOpinions", TRUE);
}

void fsAppSettings::Community_SwitchToOpinions(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\Community", "SwitchToOpinions", b);
}

BOOL fsAppSettings::ModifyIEUserAgent()
{
	return m_stgs.GetProfileInt (_T ("Settings\\General"), _T ("ModifyIEUserAgent"), TRUE);
}

void fsAppSettings::ModifyIEUserAgent(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\General"), _T ("ModifyIEUserAgent"), b);
}

BOOL fsAppSettings::View_DontShowMalOpinionOKReport()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DontShowMalOpinionOKReport"), FALSE);
}

void fsAppSettings::View_DontShowMalOpinionOKReport(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DontShowMalOpinionOKReport"), b);
}

BOOL fsAppSettings::Community_CheckIfMalBeforeDlding()
{
	return m_stgs.GetProfileInt ("Settings\\Community", "CheckIfMalBeforeDlding", TRUE);
}

void fsAppSettings::Community_CheckIfMalBeforeDlding(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\Community", "CheckIfMalBeforeDlding", b);
}

BOOL fsAppSettings::Community_DisplayOpinionsAtDlding()
{
	return m_stgs.GetProfileInt ("Settings\\Community", "DisplayOpinionsAtDlding", TRUE);
}

void fsAppSettings::Community_DisplayOpinionsAtDlding(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\Community", "DisplayOpinionsAtDlding", b);
}

DWORD fsAppSettings::FileWriteCacheSize()
{
	if (m_dwWriteCacheSize == DWORD (-1))
		m_dwWriteCacheSize = m_stgs.GetProfileInt (_T ("Settings\\General"), _T ("FileWriteCacheSize"), 0);
	return m_dwWriteCacheSize;
}

void fsAppSettings::FileWriteCacheSize(DWORD dw)
{
	m_dwWriteCacheSize = dw;
	m_stgs.WriteProfileInt (_T ("Settings\\General"), _T ("FileWriteCacheSize"), dw);
}

BOOL fsAppSettings::Monitor_Firefox()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("Firefox"), TRUE);
}

void fsAppSettings::Monitor_Firefox(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("Firefox"), b);
}

CString fsAppSettings::View_LastDldMoveToFolder()
{
	return m_stgs.GetProfileString (_T ("Settings\\View"), _T ("LastDldMoveToFolder"), "");
}

void fsAppSettings::View_LastDldMoveToFolder(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\View"), _T ("LastDldMoveToFolder"), psz);
}

BOOL fsAppSettings::Monitor_IEMenu_Enable()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("Enable"), TRUE);
}

void fsAppSettings::Monitor_IEMenu_Enable(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor\\IEMenu"), _T ("Enable"), b);
}

DWORD fsAppSettings::DNPFlags()
{
	return m_stgs.GetProfileInt ("Settings\\Network", "DNPFlags", 0);
}

void fsAppSettings::DNPFlags(DWORD dw)
{
	m_stgs.WriteProfileInt ("Settings\\Network", "DNPFlags", dw);
}

WORD fsAppSettings::LowSpeed_Duration()
{
	return (WORD)m_stgs.GetProfileInt ("Settings\\Network", "LowSpeed_Duration", 3);
}

void fsAppSettings::LowSpeed_Duration(WORD w)
{
	m_stgs.WriteProfileInt ("Settings\\Network", "LowSpeed_Duration", w);
}

WORD fsAppSettings::LowSpeed_Factor()
{
	return (WORD)m_stgs.GetProfileInt ("Settings\\Network", "LowSpeed_Factor", 3);
}

void fsAppSettings::LowSpeed_Factor(WORD w)
{
	m_stgs.WriteProfileInt ("Settings\\Network", "LowSpeed_Factor", w);
}

DWORD fsAppSettings::Monitor_UserSwitchedOn()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Monitor"), _T ("UserSwitchedOn"), 
		MONITOR_USERSWITCHEDON_IE | MONITOR_USERSWITCHEDON_FIREFOX);
}

void fsAppSettings::Monitor_UserSwitchedOn(DWORD dw)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Monitor"), _T ("UserSwitchedOn"), dw);
}

CString fsAppSettings::Scheduler_LastTask_ProgName()
{
	return m_stgs.GetProfileString (_T ("Settings\\Scheduler"), _T ("LastTask_ProgName"), "");
}

void fsAppSettings::Scheduler_LastTask_ProgName(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Scheduler"), _T ("LastTask_ProgName"), psz);
}

CString fsAppSettings::Scheduler_LastTask_ProgArgs()
{
	return m_stgs.GetProfileString (_T ("Settings\\Scheduler"), _T ("LastTask_ProgArgs"), "");
}

void fsAppSettings::Scheduler_LastTask_ProgArgs(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Scheduler"), _T ("LastTask_ProgArgs"), psz);
}

vmsAutoUpdateType fsAppSettings::Update_AutoUpdateType()
{
	return (vmsAutoUpdateType)
		m_stgs.GetProfileInt (_T ("Settings\\Update"), _T ("AutoUpdateType"), AUT_DLANDINST);
}

void fsAppSettings::Update_AutoUpdateType(vmsAutoUpdateType en)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Update"), _T ("AutoUpdateType"), en);
}

vmsAppSettingsStore* fsAppSettings::get_SettingsStore()
{
	return &m_stgs;
}

BOOL fsAppSettings::View_DropBoxIntro()
{
	return m_stgs.GetProfileInt ("Settings\\View", "DropBoxIntro", TRUE);
}

void fsAppSettings::View_DropBoxIntro(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\View", "DropBoxIntro", b);
}

BOOL fsAppSettings::Notif_DisableForBatchDownloads()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Notifications"), _T ("DisableForBatchDownloads"), FALSE);
}

void fsAppSettings::Notif_DisableForBatchDownloads(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Notifications"), _T ("DisableForBatchDownloads"), b);
}

CString fsAppSettings::Monitor_SkipServers()
{
	return m_stgs.GetProfileString (_T ("Settings\\Monitor"), _T ("SkipServers"), "");
}

void fsAppSettings::Monitor_SkipServers(LPCSTR psz)
{
	m_stgs.WriteProfileString (_T ("Settings\\Monitor"), _T ("SkipServers"), psz);
}

BOOL fsAppSettings::Download_CheckIntegrityWhenDone()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Integrity"),"CheckWhenDone", TRUE);
}

void fsAppSettings::Download_CheckIntegrityWhenDone(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Integrity"),"CheckWhenDone", b);
}

int fsAppSettings::Download_IntegrityCheckFailedReaction()
{
	return m_stgs.GetProfileInt (_T ("Settings\\Integrity"),"ICFR", 0);
}

void fsAppSettings::Download_IntegrityCheckFailedReaction(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\Integrity"),"ICFR", i);
}

int fsAppSettings::FirefoxSettings_Proxy_Type()
{
	
	return AfxGetApp ()->GetProfileInt ("FirefoxSettings\\Proxy", "ProxyType", 0);
}

CString fsAppSettings::FirefoxSettings_Proxy_Addr(LPCSTR pszProtocol)
{
	CString str = pszProtocol; str += "_addr";
	
	return AfxGetApp ()->GetProfileString ("FirefoxSettings\\Proxy", str, "");
}

int fsAppSettings::FirefoxSettings_Proxy_Port(LPCSTR pszProtocol)
{
	CString str = pszProtocol; str += "_port";
	
	return AfxGetApp ()->GetProfileInt ("FirefoxSettings\\Proxy", str, 80);
}

BOOL fsAppSettings::View_SetOutputFolderAsDefForAllGrpsChecked()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("SetOutputFolderAsDefForAllGrpsChecked"), TRUE);
}

void fsAppSettings::View_SetOutputFolderAsDefForAllGrpsChecked(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("SetOutputFolderAsDefForAllGrpsChecked"), b);
}

int fsAppSettings::View_DownloadsGroups_SelectedFilterId()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("DownloadsGroups_SelectedFilterId"), -2);
}

void fsAppSettings::View_DownloadsGroups_SelectedFilterId(int i)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("DownloadsGroups_SelectedFilterId"), i);
}

BOOL fsAppSettings::View_UploadsLog()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("UploadsLog"), TRUE);
}

void fsAppSettings::View_UploadsLog(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("UploadsLog"), b);
}

BOOL fsAppSettings::Bittorrent_Enable()
{
	return m_stgs.GetProfileInt ("Settings\\Network\\Bittorrent", "Enable", FALSE);
}

void fsAppSettings::Bittorrent_Enable(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\Network\\Bittorrent", "Enable", b);
}

int fsAppSettings::Bittorrent_UploadTrafficLimit(int mode)
{
	ASSERT (mode >= 0 && mode <= 2); 
	CString str; str.Format ("UploadTrafficLimit%d", mode);
	return m_stgs.GetProfileInt ("Settings\\Network\\Bittorrent", str, -1);
}

void fsAppSettings::Bittorrent_UploadTrafficLimit(int mode, int limit)
{
	ASSERT (mode >= 0 && mode <= 2); 
	CString str; str.Format ("UploadTrafficLimit%d", mode);
	m_stgs.WriteProfileInt ("Settings\\Network\\Bittorrent", str, limit);
}

int fsAppSettings::Bittorrent_UploadConnectionLimit(int mode)
{
	ASSERT (mode >= 0 && mode <= 2); 
	CString str; str.Format ("UploadConnectionLimit%d", mode);
	return m_stgs.GetProfileInt ("Settings\\Network\\Bittorrent", str, -1);
}

void fsAppSettings::Bittorrent_UploadConnectionLimit(int mode, int limit)
{
	ASSERT (mode >= 0 && mode <= 2); 
	CString str; str.Format ("UploadConnectionLimit%d", mode);
	m_stgs.WriteProfileInt ("Settings\\Network\\Bittorrent", str, limit);
}

int fsAppSettings::Bittorrent_ListenPort_From()
{
	return m_stgs.GetProfileInt ("Settings\\Network\\Bittorrent", "ListenPortFrom", 6881);
}

void fsAppSettings::Bittorrent_ListenPort_From(int i)
{
	m_stgs.WriteProfileInt ("Settings\\Network\\Bittorrent", "ListenPortFrom", i);
}

int fsAppSettings::Bittorrent_ListenPort_To()
{
	return m_stgs.GetProfileInt ("Settings\\Network\\Bittorrent", "ListenPortTo", 6889);
}

void fsAppSettings::Bittorrent_ListenPort_To(int i)
{
	m_stgs.WriteProfileInt ("Settings\\Network\\Bittorrent", "ListenPortTo", i);
}

BOOL fsAppSettings::Bittorrent_EnableDHT()
{
	return m_stgs.GetProfileInt ("Settings\\Network\\Bittorrent", "EnableDHT", FALSE);
}

void fsAppSettings::Bittorrent_EnableDHT(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\Network\\Bittorrent", "EnableDHT", b);
}

CString fsAppSettings::Bittorrent_OldTorrentAssociation()
{
	return m_stgs.GetProfileString ("Settings\\Network\\Bittorrent", "OldTorrentAssocString", "");
}

void fsAppSettings::Bittorrent_OldTorrentAssociation(LPCSTR psz)
{
	m_stgs.WriteProfileString ("Settings\\Network\\Bittorrent", "OldTorrentAssocString", psz);
}

BOOL fsAppSettings::View_AskRemoveFromAutostartAtAppExit()
{
	return m_stgs.GetProfileInt (_T ("Settings\\View"), _T ("AskRemoveFromAutostartAtAppExit"), TRUE);
}

void fsAppSettings::View_AskRemoveFromAutostartAtAppExit(BOOL b)
{
	m_stgs.WriteProfileInt (_T ("Settings\\View"), _T ("AskRemoveFromAutostartAtAppExit"), b);
}

CString fsAppSettings::DataFolder()
{
	CString str = m_stgs.GetProfileString ("Settings", "DataFolder", "");
	if (str.IsEmpty ())
		str = m_stgs.GetProfileString ("", "force_data_folder", "");
	return str;
}

void fsAppSettings::DataFolder(LPCSTR psz)
{
	m_stgs.WriteProfileString ("Settings", "DataFolder", psz);
}

BOOL fsAppSettings::View_DontAskEnableBittorrent()
{
	return m_stgs.GetProfileInt ("Settings\\View", "DontAskEnableBt", FALSE);
}

void fsAppSettings::View_DontAskEnableBittorrent(BOOL b)
{
	m_stgs.WriteProfileInt ("Settings\\View", "DontAskEnableBt", b);
}
