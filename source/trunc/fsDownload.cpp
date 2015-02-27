/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "system.h"
#include "fsDownload.h"
#include "vmsDownloadMgrEx.h"
#include "vmsTpDownloadMgr.h"
#include "vmsBtDownloadManager.h"
#include "fsDownloadMgr.h"

void fsDownload::getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
	{
		DWORD dwNeedSize = 0;

		

		dwNeedSize += sizeof (DWORD); 
		dwNeedSize += sizeof (BYTE); 
		dwNeedSize += sizeof (bAutoStart);
		
		int iReserved = 0;
		dwNeedSize += sizeof (iReserved);
		dwNeedSize += sizeof (nID);
		dwNeedSize += strComment.GetLength () + sizeof (DWORD);
		dwNeedSize += sizeof (UINT);	
		dwNeedSize += sizeof (dwFlags);
		dwNeedSize += sizeof (dwReserved);
		dwNeedSize += sizeof (dateAdded);
		dwNeedSize += sizeof (dateCompleted);

		DWORD cEvents = vEvents.size ();
		if (_App.DontSaveLogs ())
			cEvents = 0;
		dwNeedSize += sizeof (DWORD);  

		DWORD i = 0;
		for (i = 0; i < cEvents; i++)
			dwNeedSize += 2*sizeof (COLORREF) + sizeof (FILETIME) + sizeof (int) + vEvents [i].strEvent.GetLength () + sizeof (DWORD);

		if (pb == NULL) {
			*pdwSize = dwNeedSize;

			return;
		}

		if (*pdwSize < dwNeedSize) {
			*pdwSize = dwNeedSize;
			return;
		}

		LPBYTE pB = LPBYTE (pb);

		DWORD dwTmp = 0;
		CopyMemory (pB, &dwTmp, sizeof (dwTmp));
		pB += sizeof (dwTmp);

		BYTE btType = 0;
		if (pMgr->IsBittorrent()) {
			btType = 1;
		} else if (pMgr->IsTp()) {
			btType = 2;
		} else {
			btType = 0;
		}
		CopyMemory (pB, &btType, sizeof (btType));
		pB += sizeof (btType);

		CopyMemory (pB, &bAutoStart, sizeof (bAutoStart));
		pB += sizeof (bAutoStart);

		

		CopyMemory (pB, &iReserved, sizeof (iReserved));
		pB += sizeof (iReserved);

		CopyMemory (pB, &nID, sizeof (nID));
		pB += sizeof (nID);

		DWORD dw = strComment.GetLength ();
		CopyMemory (pB, &dw, sizeof (dw));
		pB += sizeof (dw);
		CopyMemory (pB, strComment, dw);
		pB += dw;

		CopyMemory (pB, &pGroup->nId, sizeof (UINT));
		pB += sizeof (UINT);

		CopyMemory (pB, &dwFlags, sizeof (dwFlags));
		pB += sizeof (dwFlags);

		CopyMemory (pB, &dwReserved, sizeof (dwReserved));
		pB += sizeof (dwReserved);

		CopyMemory (pB, &dateAdded, sizeof (dateAdded));
		pB += sizeof (dateAdded);

		CopyMemory (pB, &dateCompleted, sizeof (dateCompleted));
		pB += sizeof (dateCompleted);

		CopyMemory (pB, &cEvents, sizeof (DWORD));
		pB += sizeof (DWORD);

		

		for (i = 0; i < cEvents; i++)
		{
			fsDownloadEvents *ev = &vEvents [i];
		
			CopyMemory (pB, &ev->clrBg, sizeof (ev->clrBg));
			pB += sizeof (ev->clrBg);

			CopyMemory (pB, &ev->clrText, sizeof (ev->clrText));
			pB += sizeof (ev->clrText);

			CopyMemory (pB, &ev->timeEvent, sizeof (ev->timeEvent));
			pB += sizeof (ev->timeEvent);

			CopyMemory (pB, &ev->iImage, sizeof (ev->iImage));
			pB += sizeof (ev->iImage);

			dw = ev->strEvent.GetLength ();
			CopyMemory (pB, &dw, sizeof (dw));
			pB += sizeof (dw);
			CopyMemory (pB, vEvents [i].strEvent, dw);
			pB += dw;
		}

		*pdwSize = dwNeedSize;

	}

	bool fsDownload::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
	{
#define CHECK_BOUNDS(need) if (need < 0 || need > int(*pdwSize) - (pB - LPBYTE (pb))) return false;
	
	LPBYTE pB = LPBYTE (pb);
	DWORD dw = *pdwSize;
	LPSTR szStr;
	int iReserved;

	
	
	CHECK_BOUNDS (sizeof (DWORD));
	pB += sizeof (DWORD);

	if (pMgr == 0)
		return false;

	CHECK_BOUNDS (sizeof (BYTE));
	BYTE btType = *pB++;
	switch (btType) {
		case 0:
			{
				fsDownloadMgr* pdmMgr = new fsDownloadMgr();
				pMgr->Attach (pdmMgr);
			}
			break;
		case 1:
			{
				vmsBtDownloadManagerPtr spMgr; spMgr.CreateInstance ();
				pMgr->Attach (spMgr);
			}
			break;
		case 2:
			{
				vmsTpDownloadMgr* ptdmMgr = new vmsTpDownloadMgr();
				pMgr->Attach (ptdmMgr);
			}
			break;
		default:
			return false;
	}

	CHECK_BOUNDS (sizeof (bAutoStart));
	CopyMemory (&bAutoStart, pB, sizeof (bAutoStart));
	pB += sizeof (bAutoStart);

	CHECK_BOUNDS (sizeof (iReserved));

	CopyMemory (&iReserved, pB, sizeof (iReserved));
	pB += sizeof (iReserved);

	CHECK_BOUNDS (sizeof (nID));

	CopyMemory (&nID, pB, sizeof (nID));
	pB += sizeof (nID);

	CHECK_BOUNDS (sizeof (dw));

	CopyMemory (&dw, pB, sizeof (dw));
	CHECK_BOUNDS (int (dw));
	pB += sizeof (dw); fsnew (szStr, CHAR, dw+1);
	CopyMemory (szStr, pB, dw);
	szStr [dw] = 0; strComment = szStr; delete [] szStr;
	pB += dw;

	if (dwVer < 9)
	{
		CHECK_BOUNDS (sizeof (dw));

		CopyMemory (&dw, pB, sizeof (dw));
		CHECK_BOUNDS (int (dw));
		pB += sizeof (dw); fsnew (szStr, CHAR, dw+1);
		CopyMemory (szStr, pB, dw);
		szStr [dw] = 0; 
		pGroup = _DldsGrps.FindGroupByName (szStr);
		delete [] szStr;
		pB += dw;
	}
	else
	{
		UINT nGrpId;
		CHECK_BOUNDS (sizeof (UINT));
		CopyMemory (&nGrpId, pB, sizeof (UINT));
		pB += sizeof (UINT);
		pGroup = _DldsGrps.FindGroup (nGrpId);
	}

	if (pGroup == NULL)
		pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);

	CHECK_BOUNDS (sizeof (dwFlags));
	CopyMemory (&dwFlags, pB, sizeof (dwFlags));
	pB += sizeof (dwFlags);

	CHECK_BOUNDS (sizeof (dwReserved));
	CopyMemory (&dwReserved, pB, sizeof (dwReserved));
	pB += sizeof (dwReserved);

	CHECK_BOUNDS (sizeof (dateAdded));
	CopyMemory (&dateAdded, pB, sizeof (dateAdded));
	pB += sizeof (dateAdded);

	if (dwVer >= 15)
	{
		CHECK_BOUNDS (sizeof (dateCompleted));
		CopyMemory (&dateCompleted, pB, sizeof (dateCompleted));
		pB += sizeof (dateCompleted);
	}
	
	DWORD cEvents;
	CHECK_BOUNDS (sizeof (cEvents));
	CopyMemory (&cEvents, pB, sizeof (cEvents));
	pB += sizeof (cEvents);

	vEvents.clear ();

	while (cEvents--)
	{
		fsDownloadEvents ev;

		CHECK_BOUNDS (sizeof (ev.clrBg));
		
		CopyMemory (&ev.clrBg, pB, sizeof (ev.clrBg));
		pB += sizeof (ev.clrBg);

		CHECK_BOUNDS (sizeof (ev.clrText));

		CopyMemory (&ev.clrText, pB, sizeof (ev.clrText));
		pB += sizeof (ev.clrText);

		CHECK_BOUNDS (sizeof (ev.timeEvent));

		CopyMemory (&ev.timeEvent, pB, sizeof (ev.timeEvent));
		pB += sizeof (ev.timeEvent);

		CHECK_BOUNDS (sizeof (ev.iImage));

		CopyMemory (&ev.iImage, pB, sizeof (ev.iImage));
		pB += sizeof (ev.iImage);

		CHECK_BOUNDS (sizeof (dw));

		CopyMemory (&dw, pB, sizeof (dw));
		CHECK_BOUNDS (int (dw));
		pB += sizeof (dw); fsnew (szStr, CHAR, dw+1);
		CopyMemory (szStr, pB, dw);
		szStr [dw] = 0; ev.strEvent = szStr; delete [] szStr;
		pB += dw;

		vEvents.add (ev);
	}

	*pdwSize = pB - LPBYTE (pb);
	
	return true;
	}
