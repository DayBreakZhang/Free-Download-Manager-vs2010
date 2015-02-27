/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsSingleLineTooltip.h"
#include "vmsUiStaticTextWindow.h"
#include "vmsUiLinkWindow.h"
#include "vmsUiFonts.h"
#include "vmsStringParser.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsSingleLineTooltip::vmsSingleLineTooltip()
{
	m_sRequired.cx = m_sRequired.cy = 0;
}

vmsSingleLineTooltip::~vmsSingleLineTooltip()
{

}

void vmsSingleLineTooltip::setText(LPCTSTR ptszHtml)
{
	vmsUiStaticTextWindow tmp;
	addChildWindow (&tmp);
	tmp.setText (_T (" "), vmsUiFonts::Tahoma_11 (), RGB (0,0,0));
	CSize sSpace = tmp.getRequiredSize ();
	RemoveAllChildWindows ();

	int x = 0;

	m_sRequired.cx = 0;
	m_sRequired.cy = 0;

	bool bBold = false;
	tstring tstrLinkUrl;

	while (*ptszHtml)
	{
		if (*ptszHtml == '<')
		{
			ptszHtml++;
			tstring tstrTag;
			vmsStringParser::SkipWhiteChars (ptszHtml);
			vmsStringParser::GetWordBeforeChar (ptszHtml, '>', tstrTag);
			if (tstrTag.empty ())
				return;
			if (_tcsicmp (tstrTag.c_str (), "B") == 0)
			{
				bBold = true;
			}
			else if (_tcsicmp (tstrTag.c_str (), "/B") == 0)
			{
				bBold = false;
			}
			else if (_tcsicmp (tstrTag.c_str (), "A") == 0)
			{
				vmsStringParser::SkipWhiteChars (ptszHtml);
				tstring tstrVN, tstrVV;
				do 
				{
					vmsStringParser::GetAlphaWord (ptszHtml, tstrVN);
					if (tstrVN.empty ())
						break;
					vmsStringParser::SkipWhiteChars (ptszHtml);
					if (*ptszHtml != '=')
						continue;
					ptszHtml++;
					vmsStringParser::SkipWhiteChars (ptszHtml);
					if (*ptszHtml == '"' || *ptszHtml == '\'')
					{
						TCHAR tch = *ptszHtml++;
						vmsStringParser::GetTextBeforeChar (ptszHtml, tch, tstrVV);
						if (*ptszHtml)
							ptszHtml++;
					}
					else
					{
						vmsStringParser::GetWordBeforeChar (ptszHtml, '>', tstrVV);
					}
					
					if (_tcsicmp (tstrVN.c_str (), "href") == 0)
						tstrLinkUrl = tstrVV;

					if (*ptszHtml != '>')
						vmsStringParser::SkipWhiteChars (ptszHtml);

					if (*ptszHtml == '>')
						break;
				} 
				while (*ptszHtml);
			}
			else if (_tcsicmp (tstrTag.c_str (), "/A") == 0)
			{
				tstrLinkUrl = _T ("");
			}

			if (*ptszHtml != '>')
				vmsStringParser::GetTextBeforeChar (ptszHtml, '>', tstrTag);
			if (*ptszHtml == '>')
				ptszHtml++;

			continue;
		}

		tstring tstrText;
		vmsStringParser::GetTextBeforeChar (ptszHtml, '<', tstrText);
		vmsStringParser::RemoveNonSpaceWhiteChars (tstrText);
		if (tstrText.empty ())
			continue;

		

		if (tstrLinkUrl.empty ())
		{
			vmsUiStaticTextWindow *pText = new vmsUiStaticTextWindow;
			addChildWindow (pText);
			pText->setText (tstrText.c_str (), 
				bBold ? vmsUiFonts::Tahoma_11bold () : vmsUiFonts::Tahoma_11 (), 
				RGB (0,0,0));
			CSize s = pText->getRequiredSize ();
			pText->setPos (x, 0, s.cx, s.cy);
			x += s.cx;
			m_sRequired.cy = max (m_sRequired.cy, s.cy);
		}
		else
		{
			vmsUiLinkWindow *pLink = new vmsUiLinkWindow;
			addChildWindow (pLink);
			pLink->setLink (tstrText.c_str (), tstrLinkUrl.c_str ());
			CSize s = pLink->getSize ();
			pLink->setPos (x, 0, s.cx, s.cy);
			x += s.cx;
			m_sRequired.cy = max (m_sRequired.cy, s.cy);
		}
	}

	m_sRequired.cx = x;
}

CSize vmsSingleLineTooltip::getRequiredSize() const
{
	return m_sRequired;
}
