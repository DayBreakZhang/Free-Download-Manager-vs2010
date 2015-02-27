/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Utils.h"
#include "FdmApp.h"
#include "fsScheduleMgr.h"
#include "DownloadsWnd.h"
#include "fsPluginMgr.h"
#include "DialDlg.h"
#include "fsRASMgr.h"
#include "ShedulerWnd.h"
#include "WaitForConfirmationDlg.h"
#include "SpiderWnd.h"
#include "MainFrm.h"

extern CSpiderWnd *_pwndSpider;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

extern CDownloadsWnd *_pwndDownloads;
extern fsPluginMgr _PluginMgr;
extern CShedulerWnd* _pwndScheduler;

void vmsPersistableScheduleWrapper::putListToBuffer(fs::list<UINT>* pvIds, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSize, DWORD* pdwSizeRequired)
{
	if (pvIds == 0)
		return;

	pvIds->lock();
	int nCount = pvIds->size();
	putVarToBuffer(nCount, pbtCurrentPos, 0, 0, pdwSizeRequired);

	int i = 0;
	for (i = 0; i < pvIds->size(); i++) {
		putVarToBuffer(pvIds->at(i), pbtCurrentPos, 0, 0, pdwSizeRequired);
	}

	if (pbtBuffer == NULL) {
		pvIds->unlock();
		return;
	}

	putVarToBuffer(nCount, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);

	for (i = 0; i < pvIds->size(); i++) {
		putVarToBuffer(pvIds->at(i), pbtCurrentPos, pbtBuffer, dwBufferSize, 0);
	}

	pvIds->unlock();
}

bool vmsPersistableScheduleWrapper::getListFromBuffer(fs::list<UINT>* pvIds, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSize)
{
	if (pvIds == 0)
		return false;

	pvIds->lock();
	int nCount = 0;
	if (!getVarFromBuffer(nCount, pbtCurrentPos, pbtBuffer, dwBufferSize)) {
		pvIds->unlock();
		return false;
	}

	if (nCount < 0) {
		pvIds->unlock();
		return false;
	}

	int i = 0;
	for (i = 0; i < nCount; i++) {
		UINT uiId = 0;
		if (!getVarFromBuffer(uiId, pbtCurrentPos, pbtBuffer, dwBufferSize)) {
			pvIds->unlock();
			return false;
		}
		pvIds->add(uiId);
	}

	pvIds->unlock();
	return true;
}

void vmsPersistableScheduleWrapper::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;

	putVarToBuffer(schScheduleParam.schTask, pbtCurrentPos, 0, 0, &dwRequiredSize);

	
	switch (schScheduleParam.schTask.wts.enType)
	{
		case WTS_PROGRAM:
			putStrToBuffer(schScheduleParam.schTask.wts.prog.pszName, pbtCurrentPos, 0, 0, &dwRequiredSize);
			putStrToBuffer(schScheduleParam.schTask.wts.prog.pszArgs, pbtCurrentPos, 0, 0, &dwRequiredSize);
		break;

		case WTS_STARTDOWNLOAD:
		case WTS_STOPDOWNLOAD:
			putListToBuffer(schScheduleParam.schTask.wts.dlds.pvIDs, pbtCurrentPos, 0, 0, &dwRequiredSize);
		break;

		case WTS_DIAL:
			putStrToBuffer(schScheduleParam.schTask.wts.dial.pszConnection, pbtCurrentPos, 0, 0, &dwRequiredSize);
		break;

		case WTS_HANGUP:
			putStrToBuffer(schScheduleParam.schTask.wts.pszHangupConnection, pbtCurrentPos, 0, 0, &dwRequiredSize);
		break;
	}

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	putVarToBuffer(schScheduleParam.schTask, pbtCurrentPos, pbtBuffer, *pdwSize, 0);

	
	switch (schScheduleParam.schTask.wts.enType)
	{
		case WTS_PROGRAM:
			putStrToBuffer(schScheduleParam.schTask.wts.prog.pszName, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
			putStrToBuffer(schScheduleParam.schTask.wts.prog.pszArgs, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		break;

		case WTS_STARTDOWNLOAD:
		case WTS_STOPDOWNLOAD:
			putListToBuffer(schScheduleParam.schTask.wts.dlds.pvIDs, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		break;

		case WTS_DIAL:
			putStrToBuffer(schScheduleParam.schTask.wts.dial.pszConnection, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		break;

		case WTS_HANGUP:
			putStrToBuffer(schScheduleParam.schTask.wts.pszHangupConnection, pbtCurrentPos, pbtBuffer, *pdwSize, 0);
		break;
	}

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

bool vmsPersistableScheduleWrapper::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	LPBYTE pbtCurrentPos = pbtBuffer;

	if (!getVarFromBuffer(schScheduleParam.schTask, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	switch (schScheduleParam.schTask.wts.enType)
	{
		case WTS_PROGRAM:

			if (!getStrFromBuffer(&schScheduleParam.schTask.wts.prog.pszName, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;

			if (!getStrFromBuffer(&schScheduleParam.schTask.wts.prog.pszArgs, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;

		break;

		case WTS_STARTDOWNLOAD:
		case WTS_STOPDOWNLOAD:
			fsnew1 (schScheduleParam.schTask.wts.dlds.pvIDs, fs::list <UINT>);
			if (!getListFromBuffer(schScheduleParam.schTask.wts.dlds.pvIDs, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;
		break;

		case WTS_DIAL:
			if (!getStrFromBuffer(&schScheduleParam.schTask.wts.dial.pszConnection, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;
		break;

		case WTS_HANGUP:
			if (!getStrFromBuffer(&schScheduleParam.schTask.wts.pszHangupConnection, pbtCurrentPos, pbtBuffer, *pdwSize))
				return false;
		break;
	}

	if (slehEventHandler)
		slehEventHandler(&schScheduleParam.schTask, pvData);

	
	*pdwSize = pbtCurrentPos - pbtBuffer;

	return true;
}

vmsPersistableScheduleWrapper& vmsPersistableScheduleWrapper::operator = (const vmsPersistableScheduleWrapper& src)
{
	schScheduleParam.schTask = src.schScheduleParam.schTask;
	return *this;
}

fsScheduleMgr::fsScheduleMgr()
{
	m_bNeedExit = FALSE;

	m_pfnEvents = NULL;
	m_pfnEventDesc = NULL;

	m_uID = 0;
}

fsScheduleMgr::~fsScheduleMgr()
{
	FreeTasks ();
}

DWORD WINAPI fsScheduleMgr::_threadScheduleMgr(LPVOID lp)
{
	fsScheduleMgr *pThis = (fsScheduleMgr*) lp;

	while (pThis->m_bNeedExit == FALSE)
	{
		pThis->ManageNotEvents ();
		pThis->ManageHalfEvents ();
		
		int iSleep = 1000;
		while (iSleep && pThis->m_bNeedExit == FALSE)
		{
			iSleep -= 200;
			Sleep (200);
		}
	}

	pThis->m_bNeedExit = FALSE;

	return 0;
}

void fsScheduleMgr::ManageNotEvents()
{
	UpdateCurrentTime ();

	
	fs::list <fsSchedule*> vTasks; 

	int i;
	for (i = m_vTasks.size () - 1; i >= 0; i--)
	{
		fsSchedule *task = &m_vTasks [i]->schScheduleParam.schTask;

		if ((task->dwFlags & SCHEDULE_ENABLED) == 0)
			continue;

		if (IsTimeBased (task))
		{
			if (IsNeedToStart (task))
			{
				
				

				if (task->wts.enType == WTS_SHUTDOWN)
					vTasks.insert (0, task);  
				else if (task->wts.enType == WTS_EXIT)
					vTasks.add (task);		
				else
					StartTask (task);
			}
		}
	}

	
	for (i = 0; i < vTasks.size (); i++)
		StartTask (vTasks [i]);
}

BOOL fsScheduleMgr::IsNeedToStart(fsSchedule *task)
{
	SYSTEMTIME time1, time2;

	FileTimeToSystemTime (&m_curTime, &time1);
	FileTimeToSystemTime (&task->hts.next, &time2);

	
	if (time1.wYear == time2.wYear && time1.wMonth == time2.wMonth &&
		time1.wDay  == time2.wDay  && time1.wHour  == time2.wHour  &&
		time1.wMinute == time2.wMinute)
	{
		
		
		if (CompareFileTime (&task->hts.last, &task->hts.next))
			return TRUE;	
	}

	return FALSE;	
}

void fsScheduleMgr::StartTask(fsSchedule *task)
{
	if ((task->dwFlags & SCHEDULE_ENABLED) == 0)
		return;

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)task;

	if (IsTimeBased (task))
	{
		task->hts.last = task->hts.next;
		
		GetNextTime (task);
	}
	else
		task->hts.last = m_curTime;

	if (pschScheduleParam && pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();

	if (task->wts.enType == WTS_HANGUP)
	{
		fsRASMgr mgr;

		if (FALSE == mgr.EnumConnections ())
			return;

		if (mgr.GetConnectionCount () == 0)
			return; 
	}

	
	OnTaskUpdated (task);

	if (task->uWaitForConfirmation)
	{
		

		CWaitForConfirmationDlg dlg;
		CString strMsg;
		CString strTask;

		strTask = WTSToStr (task);
		strMsg.Format (LS (L_STARTIT), strTask);
		dlg.Init (strMsg, task->uWaitForConfirmation);

  		if (_DlgMgr.DoModal (&dlg) != IDOK)
			return;
	}

	
	Event (task, SME_TASK_STARTED);

	switch (task->wts.enType)
	{
		case WTS_PROGRAM:
			LaunchProgram (task);
		break;

		case WTS_STARTDOWNLOAD:
			StartDownloads (task);
		break;

		case WTS_STOPDOWNLOAD:
			StopDownloads (task);
		break;

		case WTS_STARTALLDOWNLOADS:
			Event (LS (L_STARTALLDLDS));
			_DldsMgr.StartAllDownloads (TRUE);
		break;

		case WTS_STOPALLDOWNLOADS:
			Event (LS (L_STOPALLDLDS));
			_DldsMgr.StopAllDownloads (TRUE);
		break;

		case WTS_DIAL:
			Dial (task);
		break;

		case WTS_HANGUP:
			Hangup (task);
		break;
	
		case WTS_CHANGE_TUM:
		{
			LPCSTR ppszTUM [] = {LS (L_LIGHT), LS (L_MEDIUM), LS (L_HEAVY)};
			CString str;
			str.Format (LS (L_CHANGINGTUM), ppszTUM [task->wts.enTUM]);
			Event (str);
			_TumMgr.SetTUM (task->wts.enTUM);
		}
		break;

		case WTS_RESTRAINALLDLDS:
		{
			Event (WTSToStr (task));
			bool bEn = _TumMgr.getRestrainAll ();
			bool bShould;
			if (task->wts.enRAD == RAD_ENABLE)
				bShould = true;
			else if (task->wts.enRAD == RAD_DISABLE)
				bShould = false;
			else
				bShould = !bEn;
			if (!bEn != !bShould)
				_TumMgr.setRestrainAll (bShould);
		}
		break;

		case WTS_EXIT:
			_DlgMgr.EndAllDialogs ();
			Event (LS (L_EXIT));
			AfxGetApp ()->m_pMainWnd->PostMessage (WM_COMMAND, ID_NEED_EXIT);
		break;

		case WTS_SHUTDOWN:
			_DlgMgr.EndAllDialogs ();
			Shutdown (task);
		break;
	}

	if (task->dwFlags & SCHEDULE_AUTODEL)
		DeleteTask (task);
	else if (task->dwFlags & SCHEDULE_AUTODIS)
	{
		task->dwFlags &= ~ SCHEDULE_ENABLED;
		if (pschScheduleParam && pschScheduleParam->m_ppoTaskWrapper)
			pschScheduleParam->m_ppoTaskWrapper->setDirty();
		OnTaskUpdated (task);
	}
}

BOOL fsScheduleMgr::IsTimeUnknown(FILETIME &time)
{
	return time.dwHighDateTime == UINT_MAX && time.dwLowDateTime == UINT_MAX;
}

void fsScheduleMgr::RepairNextTime(fsSchedule *task)
{
	SYSTEMTIME time;
	SYSTEMTIME time2;

	if (IsTimeBased (task) == FALSE || task->hts.enType == HTS_ONCE)
		return;

	
	if (CompareFileTime (&m_curTime, &task->hts.next) != 1)
		return; 

	
	
	
	if (CompareFileTime (&task->hts.next, &task->hts.last) == 0)
		return;	
	
	

	FileTimeToSystemTime (&m_curTime, &time);
	FileTimeToSystemTime (&task->hts.next, &time2);

	
	
	if (task->hts.enType == HTS_DAILY || 
		(task->hts.enType == HTS_CONTINUOUSLY && task->hts.interval >= 24*60) )
	{
		
		
		time.wHour = time2.wHour;
		time.wMinute = time2.wMinute;
		time.wSecond = time2.wSecond;
	}

	
	SystemTimeToFileTime (&time, &task->hts.next);

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)task;
	if (pschScheduleParam && pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();

	
	
	GetNextTime (task);
}

void fsScheduleMgr::GetNextTime(fsSchedule *task)
{
	if (IsTimeBased (task) == FALSE)
		return;
	
	
	ULARGE_INTEGER next;

	next.LowPart  = task->hts.next.dwLowDateTime;
	next.HighPart = task->hts.next.dwHighDateTime;

	
	switch (task->hts.enType)
	{
		case HTS_DAILY:
		{
			SYSTEMTIME time;
			FileTimeToSystemTime (&m_curTime, &time);

			

			for (int i = time.wDayOfWeek+1; TRUE; i++)
			{
				next.QuadPart += (ULONGLONG) 24 * 60 * 60 * 10000000;

				if (i == 7)
					i = 0;

				if (task->hts.aWeeklyDays [i])	
					break;
			}
		}
		break;

		case HTS_CONTINUOUSLY:	
			
			next.QuadPart += (ULONGLONG) task->hts.interval * 60 * 10000000;
			break;
	}

	

	task->hts.next.dwLowDateTime = next.LowPart;
	task->hts.next.dwHighDateTime = next.HighPart;

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)task;
	if (pschScheduleParam && pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();
}

BOOL fsScheduleMgr::IsTimeBased(fsSchedule *task)
{
	
	return task->hts.enType == HTS_ONCE || task->hts.enType == HTS_DAILY || task->hts.enType == HTS_CONTINUOUSLY;
}

void fsScheduleMgr::CalculateStartTime(fsSchedule *task)
{
	if (!IsTimeBased (task) || task->hts.enType == HTS_ONCE)
		return;

	SYSTEMTIME timeNow, timeStart, time;
	GetLocalTime (&timeNow);

	timeStart = timeNow;

	FileTimeToSystemTime (&task->hts.next, &time);

	
	timeStart.wHour   = time.wHour;
	timeStart.wMinute = time.wMinute;
	timeStart.wSecond = time.wSecond;

	
	SystemTimeToFileTime (&timeStart, &task->hts.next);

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)task;
	if (pschScheduleParam && pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();

	

	switch (task->hts.enType)
	{
		case HTS_DAILY:
			int iStart, i;

			
			if (CompareFileTime (&m_curTime, &task->hts.next) == -1)
				iStart = timeStart.wDayOfWeek;	
			else
			{
				
				
				iStart = timeStart.wDayOfWeek+1;
				((ULARGE_INTEGER*) &task->hts.next)->QuadPart += (ULONGLONG) 24 * 60 * 60 * 10000000;
			}

			
			for (i = iStart; TRUE; i++)
			{
				if (i == 7)
					i = 0;

				if (task->hts.aWeeklyDays [i])	
					break;

				((ULARGE_INTEGER*) &task->hts.next)->QuadPart += (ULONGLONG) 24 * 60 * 60 * 10000000;
			}
		break;

		case HTS_CONTINUOUSLY:
			
			if (CompareFileTime (&m_curTime, &task->hts.next) != -1)
				
				((ULARGE_INTEGER*) &task->hts.next)->QuadPart += (ULONGLONG) 24 * 60 * 60 * 10000000;
		break;
	}

	OnTaskUpdated (task);
}

int fsScheduleMgr::AddTask(fsSchedule *task)
{
	task->hts.last.dwHighDateTime =  task->hts.last.dwLowDateTime = UINT (-1);
	
	
	
	
	vmsPersistableScheduleWrapperSmartPtr pTaskPtr;
	pTaskPtr.CreateInstance();
	fsSchedule* t = &pTaskPtr->schScheduleParam.schTask;
	*t = *task;
	m_vTasks.add (pTaskPtr);
	setDirty();
	m_vTasks[m_vTasks.size()-1]->setDirty();
	getPersistObjectChildren ()->addPersistObject ((vmsPersistableScheduleWrapper*)pTaskPtr);
	pTaskPtr->schScheduleParam.m_ppoTaskWrapper = (vmsPersistObject*)(vmsPersistableScheduleWrapper*)pTaskPtr;

	if (task->wts.enType == WTS_STARTDOWNLOAD)
	{
		UpdateTaskDownloads (task);
		_pwndSpider->UpdateTasksIcons ();
	}

	return m_vTasks.size () - 1;
}

CString fsScheduleMgr::WTSToStr(fsSchedule *task)
{
	CString str;

	switch (task->wts.enType)
	{
		case WTS_PROGRAM:
			str = LS (L_START); str += ' ';
			str += task->wts.prog.pszName;
		break;
	
		case WTS_STARTDOWNLOAD:
			str = LS (L_STARTDLDS);
		break;

		case WTS_STOPDOWNLOAD:
			str = LS (L_STOPDLDS);
		break;

		case WTS_STARTALLDOWNLOADS:
			str = LS (L_STARTALLDLDS);
		break;

		case WTS_STOPALLDOWNLOADS:
			str = LS (L_STOPALLDLDS);
		break;

		case WTS_DIAL:
			str = LS (L_DIAL); str += ' ';
			str += task->wts.dial.pszConnection;
		break;

		case WTS_HANGUP:
			str += LS (L_HANGUP); str += ' ';
			if (task->wts.pszHangupConnection)
			{
				str += '"';
				str += task->wts.pszHangupConnection;
				str += '"';
			}
			else
				str += LS (L_ALLCONNS);
		break;

		case WTS_CHANGE_TUM:
		{
			LPCSTR pszTum [] = {LS (L_LIGHT), LS (L_MEDIUM), LS (L_HEAVY)};
			str = LS (L_CHANGETUMTO); str += ' '; str += pszTum [task->wts.enTUM];
		}
		break;

		case WTS_EXIT:
			str = LS (L_EXIT);
		break;

		case WTS_SHUTDOWN:
		{
			LPCSTR pszSh [] = {LS (L_SHUTDOWN), LS (L_RESTARTCOMP), LS (L_LOGOFF), LS (L_HIBERNATE), LS (L_STANDBY)};
			str = pszSh [task->wts.shutdown.enShutdown];
		}
		break;

		case WTS_RESTRAINALLDLDS:
		{
			LPCSTR psz [] = {LS (L_ENABLE), LS (L_DISABLE), LS (L_SWITCH)};
			str = LS (L_PAUSEALLDOWNLOADS);
			str += " ("; str += psz [task->wts.enRAD]; str += ')';
		}
		break;

		default:
			ASSERT (FALSE);
	}

	return str;
}

fsSchedule* fsScheduleMgr::GetTask(int i)
{
	return (fsSchedule*)&m_vTasks [i]->schScheduleParam;
}

void fsScheduleMgr::setDirtyFlagForTask(int i)
{
	return m_vTasks [i]->setDirty();
}

CString fsScheduleMgr::HTSToStr(fsSchedule *task)
{
	CString str;

	switch (task->hts.enType)
	{
		case HTS_ONCE:
			str = LS (L_ONCE);
		break;

		case HTS_DAILY:
		{
			LPCSTR pszDays [] = {LS (L_SUN), LS (L_MON), LS (L_TUE), LS (L_WED), LS (L_THU), LS (L_FRI), LS (L_SAT)};
			str = LS (L_ONDAYS); str += ' ';
			for (int i = 0; i < 7; i++)
			{
				if (task->hts.aWeeklyDays [i])
				{
					str += '"';
					str += pszDays [i];
					str += '"';
					str += ' ';
				}
			}
		}
		break;

		case HTS_CONTINUOUSLY:
			str = LS (L_EVERY); str += ' ';
			if (task->hts.interval % (24*60) == 0)
			{
				CString s;
				s.Format ("%d %s", task->hts.interval / 24 / 60, LS (L_DAYS));
				str += s;
			}
			else if (task->hts.interval % 60 == 0)
			{
				CString s;
				s.Format ("%d %s", task->hts.interval / 60, LS (L_HOURS));
				str += s;
			}
			else
			{
				CString s;
				s.Format ("%d %s", task->hts.interval, LS (L_MIN_SMALL));
				str += s;
			}
		break;

		case HTS_WHENISTART:
			str = LS (L_ATSTARTUP);
		break;

		case HTS_WHENDIALINGSUCCESS:
			str = LS (L_AFTERDIALOK);
		break;

		case HTS_WHENDIALINGFAILED:
			str = LS (L_DIALWASFAILED);
		break;

		case HTS_WHENNODOWNLOADS:
			str = LS (L_WHENNOACTIVEDLDS);
		break;

		case HTS_WHENSPEEDLOW:
		{
			CString str1;
			str1.Format (LS (L_WHENSPEEDLESS), task->hts.speedLow.uLowSpeed, task->hts.speedLow.uTimeInterval);
			str.Format ("%s %s", str1, LS (L_MIN_SMALL));
		}
		break;

		case HTS_NOTHINGRECEIVED:
			str.Format ("%s %d %s", LS (L_WHENALLDLDSINERR), task->hts.uTimeNothingReceived, LS (L_MIN_SMALL));
		break;

		case HTS_WHENDONE:
			str = LS (L_WHENDONE);
		break;
	}

	return str;
}

CString fsScheduleMgr::NextTimeToStr(fsSchedule *task)
{
	CString str;

	switch (task->hts.enType)
	{
		case HTS_ONCE:
			SYSTEMTIME time;
			FILETIME tm;
			GetLocalTime (&time);
			SystemTimeToFileTime (&time, &tm);
			if (CompareFileTime (&tm, &task->hts.next) >= 0)
			{
				str = LS (L_NEVER);
				break;
			}

		case HTS_DAILY:
		case HTS_CONTINUOUSLY:
		{
			SYSTEMTIME time;
			CHAR strTime [1000], strDate [1000];

			FileTimeToSystemTime (&task->hts.next, &time);

			SystemTimeToStr (&time, strDate, strTime, FALSE);

			str += strTime;
			str += " ";
			str += strDate;
		}
		break;

		default:
			str = "";	
	}

	return str;
}

CString fsScheduleMgr::LastTimeToStr(fsSchedule *task)
{
	if (IsTimeUnknown (task->hts.last))
		return LS (L_NEVER);

	SYSTEMTIME time;
	CHAR strTime [1000], strDate [1000];
	CString str;

	FileTimeToSystemTime (&task->hts.last, &time);

	SystemTimeToStr (&time, strDate, strTime, FALSE);

	str += strTime;
	str += " ";
	str += strDate;

	return str;
}

void fsScheduleMgr::SetEventFunc(fntScheduleMgrEvents pfn, LPVOID lp)
{
	m_pfnEvents = pfn;
	m_lpEvents  = lp;
}

void fsScheduleMgr::Event(fsSchedule* task, fsScheduleMgrEvent ev)
{
	if (m_pfnEvents)
		m_pfnEvents (task, ev, m_lpEvents);
}

BOOL fsScheduleMgr::SaveStateToFile(HANDLE hFile)
{
	int cTasks = m_vTasks.size ();

	DWORD dw;

	if (!WriteFile (hFile, &cTasks, sizeof (cTasks), &dw, NULL))
		return FALSE;
	
	for (int i = 0; i < cTasks; i++)
	{
		fsSchedule *task = &m_vTasks [i]->schScheduleParam.schTask;

		if (!WriteFile (hFile, task, sizeof (fsSchedule), &dw, NULL))
			return FALSE;

		
		switch (task->wts.enType)
		{
			case WTS_PROGRAM:
				if (!fsSaveStrToFile (task->wts.prog.pszName, hFile))
					return FALSE;

				if (!fsSaveStrToFile (task->wts.prog.pszArgs, hFile))
					return FALSE;
			break;

			case WTS_STARTDOWNLOAD:
			case WTS_STOPDOWNLOAD:
				if (!task->wts.dlds.pvIDs->save (hFile))
					return FALSE;
			break;

			case WTS_DIAL:
				if (!fsSaveStrToFile (task->wts.dial.pszConnection, hFile))
					return FALSE;
			break;

			case WTS_HANGUP:
				if (!fsSaveStrToFile (task->wts.pszHangupConnection, hFile))
					return FALSE;
			break;
		}
	}

	return TRUE;
}

BOOL fsScheduleMgr::LoadStateFromFile(HANDLE hFile)
{
	FreeTasks ();
	m_uID = 0;

	int cTasks;

	DWORD dw;

	if (!ReadFile (hFile, &cTasks, sizeof (cTasks), &dw, NULL) || dw != sizeof (cTasks))
		return FALSE;

	UpdateCurrentTime ();

	while (cTasks--)
	{
		
		
		vmsPersistableScheduleWrapperSmartPtr pTaskPtr;
		pTaskPtr.CreateInstance();
		fsSchedule* task = &pTaskPtr->schScheduleParam.schTask;

		if (!ReadFile (hFile, task, sizeof (fsSchedule), &dw, NULL) || dw != sizeof (fsSchedule))
			return FALSE;

		switch (task->wts.enType)
		{
			case WTS_PROGRAM:
				if (!fsReadStrFromFile (&task->wts.prog.pszName, hFile))
					return FALSE;

				if (!fsReadStrFromFile (&task->wts.prog.pszArgs, hFile))
					return FALSE;
			break;

			case WTS_STARTDOWNLOAD:
			case WTS_STOPDOWNLOAD:
				fsnew1 (task->wts.dlds.pvIDs, fs::list <UINT>);
				if (!task->wts.dlds.pvIDs->load (hFile))
					return FALSE;
			break;

			case WTS_DIAL:
				if (!fsReadStrFromFile (&task->wts.dial.pszConnection, hFile))
					return FALSE;
			break;

			case WTS_HANGUP:
				if (!fsReadStrFromFile (&task->wts.pszHangupConnection, hFile))
					return FALSE;
			break;
		}

		RepairNextTime (task);
		m_vTasks.add (pTaskPtr);
		getPersistObjectChildren ()->addPersistObject ((vmsPersistableScheduleWrapper*)pTaskPtr);
		pTaskPtr->schScheduleParam.m_ppoTaskWrapper = (vmsPersistObject*)(vmsPersistableScheduleWrapper*)pTaskPtr;
	}

	return TRUE;
}

void fsScheduleMgr::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;
	int cTasks = m_vTasks.size ();

	putVarToBuffer(cTasks, pbtCurrentPos, 0, 0, &dwRequiredSize);

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	putVarToBuffer(cTasks, pbtCurrentPos, pbtBuffer, *pdwSize, 0);

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

bool fsScheduleMgr::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	LPBYTE pbtCurrentPos = pbtBuffer;
	FreeTasks ();
	m_uID = 0;

	int cTasks = 0;
	if (!getVarFromBuffer(cTasks, pbtCurrentPos, pbtBuffer, *pdwSize))
		return false;

	int i = 0;
	for (i = 0; i < cTasks; i++) {
		vmsPersistableScheduleWrapperSmartPtr pTaskPtr;
		pTaskPtr.CreateInstance();
		m_vTasks.add(pTaskPtr);
		getPersistObjectChildren ()->addPersistObject ((vmsPersistableScheduleWrapper*)pTaskPtr);
		pTaskPtr->pvData = this;
		pTaskPtr->slehEventHandler = FdmScheduleLoadEventHandler;
		pTaskPtr->schScheduleParam.m_ppoTaskWrapper = (vmsPersistObject*)(vmsPersistableScheduleWrapper*)pTaskPtr;
	}

	UpdateCurrentTime ();

	*pdwSize = pbtCurrentPos - pbtBuffer;

	return true;
}

void fsScheduleMgr::FreeTask(fsSchedule *task)
{
	switch (task->wts.enType)
	{
		case WTS_PROGRAM:
			SAFE_DELETE_ARRAY (task->wts.prog.pszName);
			SAFE_DELETE_ARRAY (task->wts.prog.pszArgs);
		break;

		case WTS_STARTDOWNLOAD:
		case WTS_STOPDOWNLOAD:
			SAFE_DELETE (task->wts.dlds.pvIDs);
		break;

		case WTS_DIAL:
			SAFE_DELETE_ARRAY (task->wts.dial.pszConnection);
		break;

		case WTS_HANGUP:
			SAFE_DELETE_ARRAY (task->wts.pszHangupConnection);
		break;
	}
}

void fsScheduleMgr::FreeTasks()
{
	for (int i = m_vTasks.size () - 1; i >= 0; i--)
	{
		FreeTask (&m_vTasks [i]->schScheduleParam.schTask);
		
		
		getPersistObjectChildren ()->removePersistObject (i);
		m_vTasks [i] = 0;
	}

	m_vTasks.clear ();
}

int fsScheduleMgr::GetTaskCount()
{
	return m_vTasks.size ();
}

void fsScheduleMgr::DeleteTask(fsSchedule *task)
{
	int index = FindTask (task);

	if (index == -1)
		return;

	Event (task, SME_TASK_WILLBEDELETED);
	m_vTasks.del (index);
	getPersistObjectChildren ()->removePersistObject (index);
	setDirty();

	if (task->wts.enType == WTS_STARTDOWNLOAD)
		UpdateTaskDownloads (task);
}

int fsScheduleMgr::FindTask(fsSchedule *task)
{
	for (int i = m_vTasks.size () - 1; i >= 0; i--)
		if (task == &m_vTasks [i]->schScheduleParam.schTask)
			return i;

	return -1;
}

void fsScheduleMgr::StartDownloads(fsSchedule *task)
{
	DLDS_LIST vDldsToStart;

	for (int i = task->wts.dlds.pvIDs->size () - 1; i >= 0; i--)
	{
		vmsDownloadSmartPtr dld = _DldsMgr.GetDownloadByID (task->wts.dlds.pvIDs->at (i));

		if (dld != NULL && dld->pMgr->IsRunning () == FALSE)
		{
			BOOL bDone = dld->pMgr->IsDone ();
			BOOL bStart = TRUE;

			if (bDone)
			{
				if (task->wts.dlds.dwFlags & SDI_RESTART_COMPLETED_DOWNLOADS)
					dld->pMgr->SetToRestartState ();
				else
					bStart = FALSE;
			}

			if (bStart)
			{	
				CString str;

				str.Format ("%s \"%s\"", bDone ? LS (L_RESTART) : LS (L_START), dld->pMgr->get_URL ());
				
				Event (str);

				vDldsToStart.push_back (dld);
			}
		}
		else if (dld == NULL)
		{
			task->wts.dlds.pvIDs->del (i);
		}
	}

	_DldsMgr.StartDownloads (vDldsToStart);
}

void fsScheduleMgr::StopDownloads(fsSchedule *task)
{
	DLDS_LIST vDlds;

	for (int i = task->wts.dlds.pvIDs->size () - 1; i >= 0; i--)
	{
		vmsDownloadSmartPtr dld = _DldsMgr.GetDownloadByID (task->wts.dlds.pvIDs->at (i));

		if (dld != NULL && dld->pMgr->IsRunning ())
		{		
			CString str;
			str.Format ("%s \"%s\"", LS (L_STOP), dld->pMgr->get_URL ());
			Event (str);

			vDlds.push_back (dld);
		}
		else if (dld == NULL)
		{
			task->wts.dlds.pvIDs->del (i);
		}
	}

	_DldsMgr.StopDownloads (vDlds, TRUE);
}

void fsScheduleMgr::Dial(fsSchedule *task)
{
	DWORD dw;
	CloseHandle (CreateThread (NULL, 0, _threadDial, task, 0, &dw));
}

void fsScheduleMgr::Hangup(fsSchedule *task)
{
	fsRASMgr mgr;

	if (FALSE == mgr.EnumConnections ())
		return;

	for (int i = mgr.GetConnectionCount () - 1; i >= 0; i--)
	{
		LPRASCONN conn = mgr.GetConnection (i);
		char szEv [1000];
		sprintf (szEv, "%s \"%s\"", LS (L_HANGUP), conn->szEntryName);

		if (task->wts.pszHangupConnection)
		{
			if (stricmp (task->wts.pszHangupConnection, conn->szEntryName) == 0)
			{
				Event (szEv);
				fsRasHangUp (conn->hrasconn);
				break;
			}
		}
		else
		{
			Event (szEv);
			fsRasHangUp (conn->hrasconn);
		}
	}
}

void fsScheduleMgr::Shutdown(fsSchedule *task)
{
	HANDLE hProc = GetCurrentProcess ();
	HANDLE hToken;
	TOKEN_PRIVILEGES tp;
	LUID luid;

	
	OpenProcessToken (hProc, TOKEN_ADJUST_PRIVILEGES, &hToken);

	LookupPrivilegeValue (NULL, SE_SHUTDOWN_NAME, &luid);
	tp.PrivilegeCount = 1;
	tp.Privileges [0].Luid = luid;
	tp.Privileges [0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges (hToken, FALSE, &tp, 0, NULL, 0);
	

	UINT uFlags = 0;
	switch (task->wts.shutdown.enShutdown)
	{
		case ST_SHUTDOWN:
			uFlags = EWX_POWEROFF;
		break;

		case ST_RESTART:
			uFlags = EWX_REBOOT;
		break;

		case ST_LOGOFF:
			uFlags = EWX_LOGOFF;
		break;

		case ST_HIBERNATE:
			uFlags = 1 << 16;
		break;

		case ST_STANDBY:
			uFlags = 1 << 17;
		break;
	}

	if (task->wts.shutdown.bForce || IsWorkStationLocked())
		uFlags |= EWX_FORCE;

	LPCSTR szEv [] = { LS (L_SHUTDOWN), LS (L_RESTARTCOMP), LS (L_LOGOFF), 
		LS (L_HIBERNATE), LS (L_STANDBY) };
	Event (szEv [task->wts.shutdown.enShutdown]);

	DWORD dw;
	CloseHandle (CreateThread (NULL, 0, _threadShutdown, (LPVOID) uFlags, 0, &dw));
}

DWORD WINAPI fsScheduleMgr::_threadDial(LPVOID lp)
{
	fsSchedule *task = (fsSchedule*) lp;

	fsDialInfo dial = task->wts.dial;

	fsnew (dial.pszConnection, char, strlen (task->wts.dial.pszConnection) + 1);
	strcpy (dial.pszConnection, task->wts.dial.pszConnection);

	CDialDlg dlg (NULL);

	dlg.Init (&dial);

	fsScheduleMgr *pThis = _pwndScheduler->GetMgr ();

	CString str = LS (L_DIAL); str += " \"";
	str += dial.pszConnection;
	str += '"';

	pThis->Event (str, SMET_INPROGRESS);

    _DlgMgr.OnDoModal (&dlg);

	if (IDOK == dlg.DoModal ())
	{
		
		str.Format (LS (L_SUCCCONNECTED), dial.pszConnection);
		pThis->Event (str, SMET_S);
	}
	else
	{
		str.Format (LS (L_FAILEDCONNECTTO), dial.pszConnection);
		pThis->Event (str, SMET_E);
	}

    _DlgMgr.OnEndDialog (&dlg);

	delete [] dial.pszConnection;

	return 0;
}

void fsScheduleMgr::SetEventDescFunc(fntScheduleMgrEventDesc pfn, LPVOID lp)
{
	m_pfnEventDesc = pfn;
	m_lpEventDesc = lp;
}

void fsScheduleMgr::Event(LPCSTR pszEvent, fsScheduleMgrEventType enType)
{
	if (m_pfnEventDesc)
		m_pfnEventDesc (pszEvent, enType, m_lpEventDesc);
}

void fsScheduleMgr::LaunchProgram(fsSchedule *task)
{
	DWORD dwRet = (DWORD) ShellExecute (NULL, "open", task->wts.prog.pszName, task->wts.prog.pszArgs, 
										NULL, SW_SHOW);
	if (dwRet > 32)
	{
		

		CString str = '"';
		str += task->wts.prog.pszName;
		str += "\" ";
		str += LS (L_LAUNCHEDSUCC);
		Event (str);
	}
	else
	{
		

		CString str;
		char szErr [200];
		SetLastError (dwRet);
		if (dwRet)
			fsErrorToStr (szErr, sizeof (szErr));
		else
			strcpy (szErr, LS (L_OUTOFMEMORY));
		str.Format ("%s %s [%s]", LS (L_CANTLAUNCH), task->wts.prog.pszName, szErr); 
		Event (str, SMET_E);
	}
}

void fsScheduleMgr::ExciteEvent(fsExternalEvent ev)
{
	
	fsWhenToStartType hts = ExternalEventToHTS (ev);

	if (ev == EV_STARTUP)
	{
		DWORD dw;
		CloseHandle (
			CreateThread (NULL, 0, _threadScheduleMgr, this, 0, &dw));
	}
	
	
	fs::list <fsSchedule*> vTasks; 

	int i = 0;
	for (i = 0; i < m_vTasks.size (); i++)
	{
		fsSchedule *task = &m_vTasks [i]->schScheduleParam.schTask;

		if ((task->dwFlags & SCHEDULE_ENABLED) == 0)
			continue;

		fsWhenToStartType htsTask = task->hts.enType;
		if (htsTask == HTS_WHENDONE)
			htsTask = HTS_WHENNODOWNLOADS;

		if (hts == htsTask)
		{
			

			if (ev == EV_STARTUP &&
				(task->wts.enType == WTS_SHUTDOWN || task->wts.enType == WTS_EXIT))
			{
				MessageBox (0, LS (L_SCHEDULERESTOEXIT), LS (L_SCHEDULER), MB_ICONEXCLAMATION);
				task->dwFlags &= ~ SCHEDULE_ENABLED;
				m_vTasks [i]->setDirty();
				continue;
			}

			if (task->wts.enType == WTS_SHUTDOWN)
				vTasks.insert (0, task);  
			else if (task->wts.enType == WTS_EXIT)
				vTasks.add (task);		
			else
				StartTask (task);
		}
	}

	for (i = 0; i < vTasks.size (); i++)
		StartTask (vTasks [i]);
}

fsWhenToStartType fsScheduleMgr::ExternalEventToHTS(fsExternalEvent ev)
{
	switch (ev)
	{
		case EV_STARTUP:
			return HTS_WHENISTART;

		case EV_DIALINGSUCCESS:
			return HTS_WHENDIALINGSUCCESS;

		case EV_DIALINGFAILED:
			return HTS_WHENDIALINGFAILED;

		case EV_NODOWNLOADS:
			return HTS_WHENNODOWNLOADS;

		default:
			ASSERT (FALSE);
			return HTS_ONCE;
	}
}

void fsScheduleMgr::ManageHalfEvents()
{
	fs::list <fsSchedule*> vTasks;

	
	
	if (_DldsMgr.IsRunning () == FALSE)
		return;

	int i;
	for (i = m_vTasks.size () - 1; i >= 0; i--)
	{
		fsSchedule *task = &m_vTasks [i]->schScheduleParam.schTask;

		if ((task->dwFlags & SCHEDULE_ENABLED) == 0)
			continue;

		UINT uSpeed = task->hts.speedLow.uLowSpeed;
		UINT uInterval = task->hts.speedLow.uTimeInterval;

		switch (task->hts.enType)
		{
			case HTS_NOTHINGRECEIVED:
			case HTS_WHENDONE:
				uSpeed = 1;	
				uInterval = task->hts.uTimeNothingReceived;
			case HTS_WHENSPEEDLOW:
				
				
				if (IsTimeUnknown (task->hts.last) || 
					 fsGetTimeDelta (&m_curTime, &task->hts.last) >= uInterval*60)
				{
					
					if (_DldsMgr.IsSummarySpeedWasLessThan (uSpeed+1, uInterval*60))
					{
						

						switch (task->wts.enType)
						{
							case WTS_EXIT:
								vTasks.add (task);
								break;

							case WTS_SHUTDOWN:
								vTasks.insert (0, task);
								break;

							default:
								StartTask (task);
						}
					}
				}
		}
	}

	for (i = 0; i < vTasks.size (); i++)
		StartTask (vTasks [i]);
}

void fsScheduleMgr::Stop()
{
	m_bNeedExit = TRUE;
	while (m_bNeedExit)
		Sleep (5);
}

DWORD WINAPI fsScheduleMgr::_threadShutdown(LPVOID lp)
{
	UINT uFlags = (UINT)lp;

	Sleep (1000);

	if (uFlags & ((1 << 16) | (1 << 17)))
	{
		BOOL bHibernate = (uFlags & (1 << 16)) != 0;
		vmsSetSuspendState (bHibernate, (uFlags & EWX_FORCE) != 0, FALSE);
		return 0;
	}

	if (uFlags & EWX_FORCE)
		((CMainFrame*) AfxGetApp ()->m_pMainWnd)->onExit (false);

	

	ExitWindowsEx (uFlags, 0);

	

	return 0;
}

BOOL fsScheduleMgr::IsDownloadScheduled(vmsDownloadSmartPtr dld)
{
	for (int i = m_vTasks.size () - 1; i >= 0; i--)
	{
		fsSchedule *task = &m_vTasks [i]->schScheduleParam.schTask;
		
		if (task->wts.enType == WTS_STARTDOWNLOAD && (task->dwFlags & SCHEDULE_ENABLED))
		{
			
			for (int j = task->wts.dlds.pvIDs->size () - 1; j >= 0; j--)
			{
				if (task->wts.dlds.pvIDs->at (j) == dld->nID)
				{
					

					if (task->hts.enType == HTS_ONCE)
					{
						
						if (IsTimeUnknown (task->hts.next) == FALSE && CompareFileTime (&task->hts.next, &m_curTime) == 1)
							return TRUE;	
					}
					else
						return TRUE;	
				}
			}
		}
	}

	return FALSE;
}

fsSchedule* fsScheduleMgr::GetScheduleDLTask(DLDS_LIST &vDlds, BOOL bStartDL)
{
	fsWhatToStartType enWTS = bStartDL ? WTS_STARTDOWNLOAD : WTS_STOPDOWNLOAD;

	int cDlds = vDlds.size ();
	ASSERT (cDlds);

	for (int i = m_vTasks.size () - 1; i >= 0; i--)
	{
		fsSchedule *task = &m_vTasks [i]->schScheduleParam.schTask;
		if (task->wts.enType == enWTS)
		{
			if (task->wts.dlds.pvIDs->size () == cDlds)
			{
				int j = 0;
				for (j = 0; j < cDlds; j++)  
				{
					int k = 0;
					for (k = 0; k < cDlds; k++)   
						if (vDlds [j]->nID == task->wts.dlds.pvIDs->at (k))
							break;

					if (k == cDlds) 
						break;
				}

				if (j == cDlds) 
					return task;
			}
		}
	}

	return NULL;
}

void fsScheduleMgr::UpdateCurrentTime()
{
	SYSTEMTIME time;
	GetLocalTime (&time);
	SystemTimeToFileTime (&time, &m_curTime);
}

int fsScheduleMgr::FindTask(fsWhatToStartType enType, int iStartPos)
{
	for (int i = iStartPos+1; i < m_vTasks.size (); i++)
	{
		if (m_vTasks [i]->schScheduleParam.schTask.wts.enType == enType)
			return i;
	}

	return -1;
}

void fsScheduleMgr::UpdateTaskDownloads(fsSchedule *task)
{
	DLDS_LIST vDlds;

	for (int j = 0; j < task->wts.dlds.pvIDs->size ();  j++)
	{
		vmsDownloadSmartPtr dld = _DldsMgr.GetDownloadByID (task->wts.dlds.pvIDs->at (j));
		if (dld)
			_pwndDownloads->UpdateDownload (dld);
	}
}

void fsScheduleMgr::OnTaskUpdated(fsSchedule *task)
{
	if (task->wts.enType == WTS_STARTDOWNLOAD)
	{
		UpdateTaskDownloads (task);
		_pwndSpider->UpdateTasksIcons ();
	}

	Event (task, SME_TASK_UPDATED);
}

void fsScheduleMgr::RepairTasksNextTimes()
{
	for (int i = 0; i < m_vTasks.size (); i++)
		RepairNextTime (&m_vTasks [i]->schScheduleParam.schTask);
}

BOOL fsScheduleMgr::IsWorkStationLocked()
{
    HDESK hDesk = OpenInputDesktop(0, FALSE, DESKTOP_READOBJECTS);
    if (hDesk == NULL)
    return TRUE;

    TCHAR szName[80];
    DWORD cbName;
    BOOL bLocked;
    
    bLocked = !GetUserObjectInformation(hDesk, UOI_NAME, szName, 80, &cbName)
          || lstrcmpi(szName, _T("default")) != 0;

    CloseDesktop(hDesk);
    return bLocked;
}

bool FdmScheduleLoadEventHandler(fsSchedule* pschTask, void* pvData)
{
	fsScheduleMgr* pschmMgr = (fsScheduleMgr*)pvData;
	if (pschmMgr == 0)
		return false;

	if (pschTask == 0)
		return false;

	pschmMgr->RepairNextTime(pschTask);

	return true;
}
