/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include <string>
#include <vector>

#ifdef SCL_ENABLE

#define SCL_INITOBJECT(moduleName,logSizePerThread) vmsSourceCodeLogger _SourceCodeLoggerObject(moduleName,logSizePerThread)
extern class vmsSourceCodeLogger _SourceCodeLoggerObject;

#define LOG	_SourceCodeLoggerObject.logf
#define LOGs(s) _SourceCodeLoggerObject.log (s)
#define LOGsnl(s) _SourceCodeLoggerObject.log (s, true)
#define LOGFN(a) vmsSourceCodeLogger_Function _sclgr_fn (a)
#define LOGERR(e) _SourceCodeLoggerObject.logSysError (e)
#define LOGRESULT(desc,res) _SourceCodeLoggerObject.logResult (desc, res)
#define LOG_TIME_BEGIN(name) LARGE_INTEGER liQpCounts##name; QueryPerformanceCounter (&liQpCounts##name)
#define LOG_TIME_ELAPSED(name, pszDesc) {LARGE_INTEGER liTmp; QueryPerformanceCounter (&liTmp);\
	liTmp.QuadPart -= liQpCounts##name.QuadPart; \
	LOG ("%s (%s) taken: %d ms (%d counts)", #name, pszDesc, \
		_SourceCodeLoggerObject.QpCountsToMilliseconds (liTmp), (int)liTmp.QuadPart); \
	LOG_TIME_RESET(name);}
#define LOG_TIME_RESET(name) QueryPerformanceCounter (&liQpCounts##name)
#define SCL_FLUSH_ALL _SourceCodeLoggerObject.FlushBuffers ()
#define SCL_DISABLE_LOG_IF(b) vmsSourceCodeLogger_DisableLogIf _sclgr_dlif (b)

#else 

#define SCL_INITOBJECT(a,b)
#define LOG(a)
#define LOGs(s)
#define LOGsnl(s)
#define LOGFN(a)
#define LOGERR(e)
#define LOGRESULT(desc,res)
#define LOG_TIME_BEGIN(name)
#define LOG_TIME_ELAPSED(name, pszDesc)
#define LOG_TIME_RESET(name)
#define SCL_FLUSH_ALL
#define SCL_DISABLE_LOG_IF(b)
#pragma warning (disable: 4002)

#endif 

#ifdef SCL_ENABLE

class vmsSourceCodeLogger  
{
public:
	vmsSourceCodeLogger (LPCTSTR ptszThisModuleName = _T ("unknown"), int bufSizePerThread = 64*1024)
	{
		QueryPerformanceFrequency (&m_liQpFrequency);
		m_vThreadsLogs.reserve (300);
		m_nBufSizePerThread = bufSizePerThread;
		m_tstrThisModuleName = ptszThisModuleName;
		InitializeLogsFolder ();
	}
	virtual ~vmsSourceCodeLogger()
	{
		for (size_t i = 0; i < m_vThreadsLogs.size (); i++)
		{
			threadCtx *thr = &m_vThreadsLogs [i];
			FlushThreadLogBuffer (thr);
			CloseHandle (thr->hLogFile);
		}
	}

	int QpCountsToMilliseconds (LARGE_INTEGER liCounts)
	{
		return liCounts.QuadPart * 1000 / m_liQpFrequency.QuadPart;
	}

	void logResult (LPCSTR pszDescription, DWORD dwResultCode)
	{
		if (dwResultCode == 0)
		{
			std::string str = pszDescription;
			str += ": ok";
			log (str.c_str (), true);
		}
		else
		{
			logf ("%s: 0x%x - %s", pszDescription, dwResultCode, StringFromError (dwResultCode).c_str ());
		}
	}
	void logSysError (DWORD dw)
	{
		if (!dw)
			return;
		logf ("(0x%x - %s)", dw, StringFromError (dw).c_str ());
	}
	bool isLogForCurrentThreadDisabled()
	{
		threadCtx *thr = getCurrentThreadContext ();
		if (thr == NULL)
			return false;
		return thr->bDisableLog;
	}
	void DisableLogForCurrentThread(bool bDisable = true)
	{
		threadCtx *thr = getCurrentThreadContext ();
		if (thr == NULL)
			return;
		thr->bDisableLog = bDisable;
	}
	void setLogCurrentTimeForCurrentThread(bool bLog = true)
	{
		threadCtx *thr = getCurrentThreadContext ();
		if (thr == NULL)
			return;
		thr->bLogCurrentTime = bLog;
	}
	void FlushBuffers()
	{
		
		for (size_t i = 0; i < m_vThreadsLogs.size (); i++)
			FlushThreadLogBuffer (&m_vThreadsLogs [i]);
	}
	void log (LPCSTR psz, bool bAddNextLine = false)
	{
		threadCtx *thr = getCurrentThreadContext ();
		if (thr == NULL)
			return;
		if (thr->bDisableLog)
			return;

		thr->strLog += psz;
		if (bAddNextLine)
			thr->strLog += "\r\n";

		if (thr->bLogCurrentTime && 
			(thr->strLog [thr->strLog.length ()-1] == '\n' || thr->strLog [thr->strLog.length ()-1] == '\r'))
		{
			SYSTEMTIME time;
			GetLocalTime (&time);

			if (time.wSecond != thr->stLastTimeLogged.wSecond ||
				time.wMinute != thr->stLastTimeLogged.wMinute ||
				time.wHour != thr->stLastTimeLogged.wHour)
			{
				char sz [40];
				sprintf (sz, "(time was: %02d:%02d:%02d)\r\n", (int)time.wHour, (int)time.wMinute, (int)time.wSecond);
				thr->strLog += sz;
				thr->stLastTimeLogged = time;
			}
		}

		if (thr->strLog.length () > m_nBufSizePerThread)
			FlushThreadLogBuffer (thr);
	}
	void logf (LPCSTR pszFormat ...)
	{
		threadCtx *thr = getCurrentThreadContext ();
		if (thr == NULL)
			return;
		if (thr->bDisableLog)
			return;

		va_list ap;
		char sz [50000];

		va_start (ap, pszFormat);
		vsprintf (sz, pszFormat, ap);
		strcat (sz, "\r\n");
		va_end (ap);

		log (sz);
	}

protected:
	void InitializeLogsFolder ()
	{
		TCHAR tsz [MAX_PATH] = _T ("");
		GetModuleFileName (NULL, tsz, MAX_PATH);
		LPCTSTR ptszExeName = _tcsrchr (tsz, '\\');
		if (!ptszExeName++)
			return;
		TCHAR tsz2 [MAX_PATH] = _T ("");
		GetTempPath (MAX_PATH, tsz2);
		if (tsz2 [_tcslen (tsz2) - 1] != '\\')
			_tcscat (tsz2, _T ("\\"));
		_tcscat (tsz2, _T ("SourceCodeLogger"));
		CreateDirectory (tsz2, NULL);
		_tcscat (tsz2, _T ("\\"));
		_tcscat (tsz2, ptszExeName);
		CreateDirectory (tsz2, NULL);
		_tcscat (tsz2, _T ("\\"));
		m_tstrLogsFolder = tsz2;
		DeleteAllLogFiles ();
	}
	void DeleteAllLogFiles ()
	{
		tstring tstr = m_tstrLogsFolder;
		tstr += m_tstrThisModuleName;
		tstr += _T (".*.sclgr");

		WIN32_FIND_DATA wfd;
		HANDLE hFind = FindFirstFile (tstr.c_str (), &wfd);
		if (hFind != INVALID_HANDLE_VALUE)
		{
			do 
			{
				tstring tstr2 = m_tstrLogsFolder + wfd.cFileName;
				DeleteFile (tstr2.c_str ());
			}
			while (FindNextFile (hFind, &wfd));

			FindClose (hFind);
		}
	}
	std::string StringFromError (DWORD dw)
	{
		LPSTR psz = NULL;

		FormatMessageA (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, 
			NULL, dw, 0, (LPSTR)&psz, 0, NULL);

		if (psz)
		{
			while (*psz != 0 && (psz [strlen (psz)-1] == '\n' || psz [strlen (psz)-1] == '\r'))
				psz [strlen (psz)-1] = 0;
			if (*psz && psz [strlen (psz)-1] == '.')
				psz [strlen (psz)-1] = 0;
			std::string str = psz;
			LocalFree (psz);
			return str;
		}
		else
		{
			return "unknown error";
		}
	}
	struct threadCtx
	{
		DWORD dwThreadId;
		std::string strLog;
		HANDLE hLogFile;
		bool bLogCurrentTime;
		SYSTEMTIME stLastTimeLogged;
		bool bDisableLog;

		threadCtx () {
			ZeroMemory (&stLastTimeLogged, sizeof (stLastTimeLogged));
			hLogFile = INVALID_HANDLE_VALUE;
			bDisableLog = false;
			bLogCurrentTime = false;
		}
	};

	threadCtx* getCurrentThreadContext()
	{
		int n = findCurrentThreadIndex ();
		if (n != -1)
			return &m_vThreadsLogs [n];
		return CreateCurrentThreadContext ();
	}
	threadCtx* CreateCurrentThreadContext ()
	{
		threadCtx t;
		t.dwThreadId = GetCurrentThreadId ();
		t.bLogCurrentTime = false;
		tstring tstr = m_tstrLogsFolder;
		tstr += m_tstrThisModuleName;
		tstr += '.';
		TCHAR tsz2 [20] = _T ("");
		_itot (t.dwThreadId, tsz2, 16);
		tstr += tsz2;
		tstr += _T (".sclgr");
		t.hLogFile = CreateFile (tstr.c_str (), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		assert (t.hLogFile != INVALID_HANDLE_VALUE);
		if (t.hLogFile == INVALID_HANDLE_VALUE)
			return NULL;
		m_vThreadsLogs.push_back (t);
		threadCtx *thr = &m_vThreadsLogs [findCurrentThreadIndex ()];
		thr->strLog.reserve (m_nBufSizePerThread + 3000);
		return thr;
	}
	void FlushThreadLogBuffer (threadCtx* thr)
	{
		DWORD dw;
		if (FALSE == WriteFile (thr->hLogFile, thr->strLog.c_str (), thr->strLog.length (), &dw, NULL))
			return;
		thr->strLog = "";
	}
	int findCurrentThreadIndex () const
	{
		DWORD dwId = GetCurrentThreadId ();

		for (size_t i = 0; i < m_vThreadsLogs.size (); i++)
		{
			if (m_vThreadsLogs [i].dwThreadId == dwId)
				return i;
		}

		return -1;
	}
	size_t m_nBufSizePerThread;
	std::vector <threadCtx> m_vThreadsLogs;
	tstring m_tstrThisModuleName;
	tstring m_tstrLogsFolder;
	LARGE_INTEGER m_liQpFrequency; 
};

class vmsSourceCodeLogger_Function
{
public:
	vmsSourceCodeLogger_Function (LPCSTR pszDesc)
	{
		LOG ("%s started.", pszDesc);
		m_strDesc = pszDesc;
		QueryPerformanceCounter (&m_liQpCountsStart);
	}

	~vmsSourceCodeLogger_Function ()
	{
		LARGE_INTEGER liTmp; QueryPerformanceCounter (&liTmp);
		liTmp.QuadPart -= m_liQpCountsStart.QuadPart;
		LOG ("%s has finished (run time: %d ms (%d counts)).", m_strDesc.c_str (), _SourceCodeLoggerObject.QpCountsToMilliseconds (liTmp), (int)liTmp.QuadPart);
	}

protected:
	std::string m_strDesc;
	LARGE_INTEGER m_liQpCountsStart;
};

class vmsSourceCodeLogger_DisableLogIf 
{
public:
	vmsSourceCodeLogger_DisableLogIf (bool b)
	{
		m_bLogWasDisabledAlready = _SourceCodeLoggerObject.isLogForCurrentThreadDisabled ();
		if (m_bLogWasDisabledAlready == false && b)
			_SourceCodeLoggerObject.DisableLogForCurrentThread (true);
	}

	~vmsSourceCodeLogger_DisableLogIf ()
	{
		if (m_bLogWasDisabledAlready == false)
			_SourceCodeLoggerObject.DisableLogForCurrentThread (false);
	}

protected:
	bool m_bLogWasDisabledAlready;
};

#endif 

