/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Prg_SkinsPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CPrg_SkinsPage, CPropertyPage)

CPrg_SkinsPage::CPrg_SkinsPage() : CPropertyPage(CPrg_SkinsPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_SKINS);
}

CPrg_SkinsPage::~CPrg_SkinsPage()
{
}

void CPrg_SkinsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrg_SkinsPage)
	DDX_Control(pDX, IDC_SKIN, m_wndSkins);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrg_SkinsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPrg_SkinsPage)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPrg_SkinsPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_wndSkins.AddString (LS (L_NEWSTYLE));
	for (int i = 0; i < _SkinMgr.get_Count (); i++)
	{
		CString str = _SkinMgr.get_Skin (i)->strName;
		if (str.CompareNoCase ("Old Style") == 0)
			str = LS (L_OLDSTYLE);
		m_wndSkins.AddString (str);
	}
	m_wndSkins.SetCurSel (_SkinMgr.get_Current ()+1);

	DWORD dw = _App.Skin_Flags ();
	CheckDlgButton (IDC_ALLOWICONS, dw & SM_ALLOWICONS ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_ALLOWBITMAPS, dw & SM_ALLOWBITMAPS ? BST_CHECKED : BST_UNCHECKED);

	ApplyLanguage ();
	
	return TRUE;
}

void CPrg_SkinsPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__SKIN, L_SKIN),
		fsDlgLngInfo (IDC_ALLOWBITMAPS, L_SKIN_ALLOWBITMAPS),
		fsDlgLngInfo (IDC_ALLOWICONS, L_SKIN_ALLOWICONS),
		fsDlgLngInfo (IDC__AFTERRESTART, L_AFTERRESTART),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo));
}

BOOL CPrg_SkinsPage::OnApply() 
{
	CString str;
	m_wndSkins.GetLBText (m_wndSkins.GetCurSel (), str);

	if (str == LS (L_OLDSTYLE))
		str = "Old Style";
	else if (str == LS (L_NEWSTYLE))
		str = "";

	_App.Skin_Current (str);

	DWORD dw = 0;
	if (IsDlgButtonChecked (IDC_ALLOWICONS) == BST_CHECKED)
		dw |= SM_ALLOWICONS;
	if (IsDlgButtonChecked (IDC_ALLOWBITMAPS) == BST_CHECKED)
		dw |= SM_ALLOWBITMAPS;
	_App.Skin_Flags (dw);
	
	return CPropertyPage::OnApply();
}

BOOL CPrg_SkinsPage::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	return FALSE; 
}
