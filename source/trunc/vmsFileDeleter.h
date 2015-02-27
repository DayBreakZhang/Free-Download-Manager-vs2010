/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsFileDeleter
{
public:
	enum ErrorType { NoError, FileIsInUse, NotEnoughRights, Unknown };
	
	typedef bool (*FNOnDeleteError)(vmsFileDeleter* pDeleter);
public:

	vmsFileDeleter(LPCTSTR ptszFile, DWORD dwDeleteFileError = 0) : m_dwLastError (dwDeleteFileError),
		m_pfnOnDeleteError (NULL)
	{
		if (ptszFile)
			m_tstrFile = ptszFile;
	}

	~vmsFileDeleter(void)
	{
	}

	bool DeleteFile ()
	{
		BOOL b = ::DeleteFile (m_tstrFile.c_str ());
		
		
		if (!b && GetLastError () == ERROR_ACCESS_DENIED)
		{
			HANDLE h = CreateFile (m_tstrFile.c_str (), GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
			if (h == INVALID_HANDLE_VALUE)
			{
				if (GetLastError () == ERROR_SHARING_VIOLATION)
					m_dwLastError = ERROR_SHARING_VIOLATION; 
			}
			else
			{
				CloseHandle (h);
				b = ::DeleteFile (m_tstrFile.c_str ());
			}
		}
		m_dwLastError = b ? 0 : GetLastError ();
		return b != FALSE;
	}

	ErrorType getErrorType () const 
	{
		switch (m_dwLastError)
		{
		case 0:
			return NoError;
		case ERROR_BUSY: 
		case ERROR_SHARING_VIOLATION:
			return FileIsInUse;
		case ERROR_ACCESS_DENIED: 
			return NotEnoughRights;
		default: 
			return Unknown;
		}
	}

	const tstring& getFilePath () const {return m_tstrFile;}

	bool DeleteFileEx ()
	{
		while (!DeleteFile () && m_pfnOnDeleteError && m_pfnOnDeleteError (this))
			;
		if (getErrorType () == FileIsInUse)
			return ScheduleFileDeleteAtReboot ();
		return m_dwLastError == 0;
	}

	bool ScheduleFileDeleteAtReboot ()
	{
		if (MoveFileEx (m_tstrFile.c_str (), NULL, MOVEFILE_DELAY_UNTIL_REBOOT))
			m_dwLastError = 0;
		else
			m_dwLastError = GetLastError ();
		return m_dwLastError == 0;
	}

	void setOnDeleteErrorHandler (FNOnDeleteError pfn) {m_pfnOnDeleteError = pfn;}

protected:
	FNOnDeleteError m_pfnOnDeleteError;
	tstring m_tstrFile;
	DWORD m_dwLastError;
};

