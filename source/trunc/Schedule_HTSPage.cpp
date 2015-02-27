/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Schedule_HTSPage.h"
#include "fsScheduleMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CSchedule_HTSPage, CPropertyPage)

CSchedule_HTSPage::CSchedule_HTSPage() : CPropertyPage(CSchedule_HTSPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_HTS);
}

CSchedule_HTSPage::~CSchedule_HTSPage()
{
}

void CSchedule_HTSPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSchedule_HTSPage)
	DDX_Control(pDX, IDC_DATE, m_wndDate);
	DDX_Control(pDX, IDC_EVENT, m_wndEvent);
	DDX_Control(pDX, IDC_EVERYDIM, m_wndEveryDim);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_TIME, m_wndTime);
}

BEGIN_MESSAGE_MAP(CSchedule_HTSPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSchedule_HTSPage)
	ON_BN_CLICKED(IDC_ONCE, OnOnce)
	ON_BN_CLICKED(IDC_DAILY, OnDaily)
	ON_BN_CLICKED(IDC_ONEVERY, OnOnevery)
	ON_BN_CLICKED(IDC_ONEVENT, OnOnevent)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TIME, OnDatetimechangeTime)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE, OnDatetimechangeDate)
	ON_BN_CLICKED(IDC_SUN, OnSun)
	ON_BN_CLICKED(IDC_WED, OnWed)
	ON_BN_CLICKED(IDC_SAT, OnSat)
	ON_BN_CLICKED(IDC_MON, OnMon)
	ON_BN_CLICKED(IDC_THU, OnThu)
	ON_BN_CLICKED(IDC_TUE, OnTue)
	ON_BN_CLICKED(IDC_FRI, OnFri)
	ON_EN_CHANGE(IDC_EVERY, OnChangeEvery)
	ON_CBN_SELCHANGE(IDC_EVERYDIM, OnSelchangeEverydim)
	ON_CBN_SELCHANGE(IDC_EVENT, OnSelchangeEvent)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSchedule_HTSPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	UINT nChecked = IDC_ONEVENT;

	switch (m_task->hts.enType)
	{
		case HTS_ONCE:
			nChecked = IDC_ONCE;
			break;

		case HTS_DAILY:
			nChecked = IDC_DAILY;
			break;

		case HTS_CONTINUOUSLY:
			nChecked = IDC_ONEVERY;
			break;
	}

	CheckRadioButton (IDC_ONCE, IDC_ONEVENT, nChecked);

	m_wndTime.SetFormat ("HH:mm");

	m_wndEveryDim.AddString (LS (L_B_MINUTES));
	m_wndEveryDim.AddString (LS (L_B_HOURS));
	m_wndEveryDim.AddString (LS (L_B_DAYS));
	m_wndEveryDim.SetCurSel (0);

	m_wndEvent.AddString (LS (L_ATSTARTUP));
	m_wndEvent.AddString (LS (L_AFTERDIALOK));
	m_wndEvent.AddString (LS (L_DIALWASFAILED));
	m_wndEvent.AddString (LS (L_WHENNOACTIVEDLDS));
	m_wndEvent.AddString (LS (L_WHENSPEEDSMALL));
	m_wndEvent.AddString (LS (L_WHENALLDLDSINERRSTATE));
	m_wndEvent.AddString (LS (L_WHENDONE_2));
	m_wndEvent.SetCurSel (0);

	((CSpinButtonCtrl*) GetDlgItem (IDC_EVERYSPIN))->SetRange (1, UD_MAXVAL);
	((CSpinButtonCtrl*) GetDlgItem (IDC_DURINGSPIN))->SetRange (1, UD_MAXVAL);

	SetDlgItemInt (IDC_DURING, 10);
	SetDlgItemInt (IDC_LOWSPEED, 100);
	SetDlgItemInt (IDC_EVERY, 1);

	DataToDialog ();

	UpdateEnabled ();

	GetDlgItem (IDC_ONCE)->SetFocus ();

	m_bNeedRecalcStartTime = FALSE;

	ApplyLanguage ();

	return FALSE;
}

void CSchedule_HTSPage::UpdateEnabled()
{
	BOOL b;

	GetDlgItem (IDC_DATE)->EnableWindow (IsDlgButtonChecked (IDC_ONCE) == BST_CHECKED);

	b = IsDlgButtonChecked (IDC_DAILY) == BST_CHECKED;
	UINT nIDs [] = {IDC_SUN, IDC_MON, IDC_TUE, IDC_WED, IDC_THU, IDC_FRI, IDC_SAT};
	for (int i = 0; i < sizeof (nIDs) / sizeof (UINT); i++)
		GetDlgItem (nIDs [i])->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_ONEVERY) == BST_CHECKED;
	GetDlgItem (IDC_EVERY)->EnableWindow (b);
	GetDlgItem (IDC_EVERYSPIN)->EnableWindow (b);
	GetDlgItem (IDC_EVERYDIM)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_ONEVENT) == BST_CHECKED;
	GetDlgItem (IDC_EVENT)->EnableWindow (b);
	GetDlgItem (IDC_TIME)->EnableWindow (!b);
	GetDlgItem (IDC_STARTTIME)->EnableWindow (!b);
	
	b = b && m_wndEvent.GetCurSel () > 3;
	GetDlgItem (IDC_DURING)->EnableWindow (b);
	GetDlgItem (IDC_DURINGSPIN)->EnableWindow (b);
	GetDlgItem (IDC__DURING)->EnableWindow (b);
	GetDlgItem (IDC__MINUTES)->EnableWindow (b);

	b = b && m_wndEvent.GetCurSel () == 4;
	GetDlgItem (IDC__LOWSPEED)->EnableWindow (b);
	GetDlgItem (IDC_LOWSPEED)->EnableWindow (b);
	GetDlgItem (IDC__BPS)->EnableWindow (b);
}

void CSchedule_HTSPage::OnOnce() 
{
	m_bNeedRecalcStartTime = TRUE;
	UpdateEnabled ();
	SetModified ();
}

void CSchedule_HTSPage::OnDaily() 
{
	m_bNeedRecalcStartTime = TRUE;
	UpdateEnabled ();	
	SetModified ();
}

void CSchedule_HTSPage::OnOnevery() 
{
	m_bNeedRecalcStartTime = TRUE;
	UpdateEnabled ();
	SetModified ();
}

void CSchedule_HTSPage::OnOnevent() 
{
	m_bNeedRecalcStartTime = TRUE;
	UpdateEnabled ();
	SetModified ();
}

void CSchedule_HTSPage::DataToDialog()
{
	UINT nIDs [] = {IDC_SUN, IDC_MON, IDC_TUE, IDC_WED, IDC_THU, IDC_FRI, IDC_SAT};

	SYSTEMTIME time;
	FileTimeToSystemTime (&m_task->hts.next, &time);

	switch (m_task->hts.enType)
	{
		case HTS_ONCE:
   			m_wndDate.SetTime (&time);
			m_wndTime.SetTime (&time);
		break;

		case HTS_DAILY:
			int i;
			for (i = 0; i < 7; i++)
				CheckDlgButton (nIDs [i], m_task->hts.aWeeklyDays [i] ? BST_CHECKED : BST_UNCHECKED);
			m_wndTime.SetTime (&time);
		break;

		case HTS_CONTINUOUSLY:
		{
			UINT nInterval = m_task->hts.interval;
			
			if (nInterval % (24*60) == 0)
			{
				SetDlgItemInt (IDC_EVERY, nInterval / 24 / 60);
				m_wndEveryDim.SetCurSel (2);
			} 
			else if (nInterval % 60 == 0)
			{
				SetDlgItemInt (IDC_EVERY, nInterval / 60);
				m_wndEveryDim.SetCurSel (1);
			}
			else
			{
				SetDlgItemInt (IDC_EVERY, nInterval);
				m_wndEveryDim.SetCurSel (0); 
			}

			m_wndTime.SetTime (&time);
		}
		break;

		default:
			m_wndEvent.SetCurSel (m_task->hts.enType - HTS_WHENISTART);
			if (m_task->hts.enType == HTS_WHENSPEEDLOW)
			{
				SetDlgItemInt (IDC_DURING, m_task->hts.speedLow.uTimeInterval);
				SetDlgItemInt (IDC_LOWSPEED, m_task->hts.speedLow.uLowSpeed);
			}
			else if (m_task->hts.enType == HTS_NOTHINGRECEIVED || m_task->hts.enType == HTS_WHENDONE)
			{
				SetDlgItemInt (IDC_DURING, m_task->hts.uTimeNothingReceived);
			}

			break;	
	}
}

void CSchedule_HTSPage::OnDatetimechangeTime(NMHDR* , LRESULT* pResult) 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();
	*pResult = 0;
}

BOOL CSchedule_HTSPage::OnApply() 
{
	SYSTEMTIME time;
	m_wndTime.GetTime (&time);

	if (IsDlgButtonChecked (IDC_ONCE) == BST_CHECKED)
	{
		SYSTEMTIME date;
		m_wndDate.GetTime (&date);

		date.wHour   = time.wHour;
		date.wMinute = time.wMinute;
		date.wSecond = time.wSecond;

		SystemTimeToFileTime (&date, &m_task->hts.next);
		m_task->hts.enType = HTS_ONCE;
	}
	else if (IsDlgButtonChecked (IDC_DAILY) == BST_CHECKED)
	{
		UINT nIDs [] = {IDC_SUN, IDC_MON, IDC_TUE, IDC_WED, IDC_THU, IDC_FRI, IDC_SAT};
		BOOL bOk = FALSE;
		for (int i = 0; i < 7; i++)
		{
			m_task->hts.aWeeklyDays [i] = IsDlgButtonChecked (nIDs [i]) == BST_CHECKED;
			bOk = bOk || m_task->hts.aWeeklyDays [i];
		}
		if (bOk == FALSE)
		{
			
			MessageBox (LS (L_ENTERDAYS), LS (L_INPERR), MB_ICONEXCLAMATION);
			return FALSE;
		}
		m_task->hts.enType = HTS_DAILY;
		SystemTimeToFileTime (&time, &m_task->hts.next);
		
	}
	else if (IsDlgButtonChecked (IDC_ONEVERY) == BST_CHECKED)
	{
		UINT u = GetDlgItemInt (IDC_EVERY);
		if (u == 0)
		{
			CString str; str.Format (LS (L_ENTERGREATER), 0);
			MessageBox (str, LS (L_ERR), MB_ICONEXCLAMATION);
			return FALSE;
		}

		int i = m_wndEveryDim.GetCurSel ();
		int mul [] = {1, 60, 60*24};	
		u *= mul [i];
		m_task->hts.interval = u;
		m_task->hts.enType = HTS_CONTINUOUSLY;
		SystemTimeToFileTime (&time, &m_task->hts.next);
	}
	else
	{
		m_task->hts.enType = (fsWhenToStartType) (HTS_WHENISTART + m_wndEvent.GetCurSel ());
		if (m_task->hts.enType == HTS_WHENSPEEDLOW)
		{
			m_task->hts.speedLow.uTimeInterval = GetDlgItemInt (IDC_DURING);
			m_task->hts.speedLow.uLowSpeed = GetDlgItemInt (IDC_LOWSPEED);
		}
		else if (m_task->hts.enType == HTS_NOTHINGRECEIVED || m_task->hts.enType == HTS_WHENDONE)
		{
			m_task->hts.uTimeNothingReceived = GetDlgItemInt (IDC_DURING);
		}
	}

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)m_task;
	if (pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();
	
	return CPropertyPage::OnApply();
}

void CSchedule_HTSPage::OnDatetimechangeDate(NMHDR* , LRESULT* pResult) 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();
	*pResult = 0;
}

void CSchedule_HTSPage::OnSun() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();
}

void CSchedule_HTSPage::OnWed() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();	
}

void CSchedule_HTSPage::OnSat() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();	
}

void CSchedule_HTSPage::OnMon() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();	
}

void CSchedule_HTSPage::OnThu() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();	
}

void CSchedule_HTSPage::OnTue() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();	
}

void CSchedule_HTSPage::OnFri() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();	
}

void CSchedule_HTSPage::OnChangeEvery() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();
}

void CSchedule_HTSPage::OnSelchangeEverydim() 
{
	m_bNeedRecalcStartTime = TRUE;
	SetModified ();
}

void CSchedule_HTSPage::OnSelchangeEvent() 
{
	SetModified ();	
	UpdateEnabled ();
}

void CSchedule_HTSPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CSchedule_HTSPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CSchedule_HTSPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_STARTTIME, L_TIME),
		fsDlgLngInfo (IDC_ONCE, L_ONCE),
		fsDlgLngInfo (IDC_DAILY, L_INCERTAINDAYS),
		fsDlgLngInfo (IDC_SUN, L_SUNDAY),
		fsDlgLngInfo (IDC_MON, L_MONDAY),
		fsDlgLngInfo (IDC_TUE, L_TUESDAY),
		fsDlgLngInfo (IDC_WED, L_WEDNESDAY),
		fsDlgLngInfo (IDC_THU, L_THURSDAY),
		fsDlgLngInfo (IDC_FRI, L_FRIDAY),
		fsDlgLngInfo (IDC_SAT, L_SATURDAY),
		fsDlgLngInfo (IDC_ONEVERY, L_EVERY),
		fsDlgLngInfo (IDC_ONEVENT, L_ONEVENT),
		fsDlgLngInfo (IDC__DURING, L_DURING),
		fsDlgLngInfo (IDC__MINUTES, L_MIN),
		fsDlgLngInfo (IDC__LOWSPEED, L_LOWSPEED),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CSchedule_HTSPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_STARTTIME, LS (L_STARTTIMEHERE)),
		fsCtrlContextHelp (IDC_TIME, LS (L_TIMEHERE)),
		fsCtrlContextHelp (IDC_ONCE, LS (L_ONCEHERE)),
		fsCtrlContextHelp (IDC_DATE, LS (L_DATEHERE)),
		fsCtrlContextHelp (IDC_DAILY, LS (L_DAILYHERE)),
		fsCtrlContextHelp (IDC_SUN, LS (L_SUNHERE)),
		fsCtrlContextHelp (IDC_MON,  LS (L_MONHERE)),
		fsCtrlContextHelp (IDC_TUE, LS (L_TUEHERE)),
		fsCtrlContextHelp (IDC_WED, LS (L_WEDHERE)),
		fsCtrlContextHelp (IDC_THU, LS (L_THUHERE)),
		fsCtrlContextHelp (IDC_FRI, LS (L_FRIHERE)),
		fsCtrlContextHelp (IDC_SAT, LS (L_SATHERE)),
		fsCtrlContextHelp (IDC_ONEVERY, LS (L_ONEVERYHERE)),
		fsCtrlContextHelp (IDC_EVERYDIM, LS (L_EVERYDIMHERE)),
		fsCtrlContextHelp (IDC_ONEVENT, LS (L_ONEVENTHERE)),
		fsCtrlContextHelp (IDC_EVENT, LS (L_EVENTHERE)),
		fsCtrlContextHelp (IDC__DURING, LS (L_DURINGHERE)),
		fsCtrlContextHelp (IDC_DURING, LS (L_DURINGHERE)),
		fsCtrlContextHelp (IDC__LOWSPEED, LS (L_LOWSPEEDHERE)),
		fsCtrlContextHelp (IDC_LOWSPEED, LS (L_LOWSPEEDHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CSchedule_HTSPage::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	RECT rc;
	CWnd *pItem = GetDlgItem (pHelpInfo->iCtrlId);
	if (pItem == NULL)
		return TRUE;
	pItem->GetWindowRect (&rc);
	if (PtInRect (&rc, pHelpInfo->MousePos) == FALSE)
	{
		pHelpInfo->MousePos.x = rc.left + (rc.right - rc.left) / 2;
		pHelpInfo->MousePos.y = rc.top + (rc.bottom - rc.top) / 2;
	}
	PrepareCHMgr (pHelpInfo->MousePos);
	_CHMgr.OnWT ();
	return TRUE;
}
