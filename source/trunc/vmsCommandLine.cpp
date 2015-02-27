/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsCommandLine.h"
#include "vmsFileUtil.h"
#include <Tlhelp32.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsCommandLine::vmsCommandLine()
{

}

vmsCommandLine::~vmsCommandLine()
{

}

bool SearchPath(LPCTSTR ptszFile, LPCTSTR ptszExt, tstring *ptstrResult)
{
	TCHAR tsz [MAX_PATH] = _T ("");
	if (::SearchPath (NULL, ptszFile, ptszExt, MAX_PATH, tsz, NULL))
	{
		*ptstrResult = tsz;
		return true;
	}
	return false;
}

tstring getLongPathName(LPCTSTR ptsz)
{
	TCHAR tsz [MAX_PATH] = _T ("");
	if (_tcslen (ptsz) > 2 && ptsz [1] != ':')
	{
		tstring tstr;
		if (SearchPath (ptsz, _T ("exe"), &tstr))
			_tcscpy (tsz, tstr.c_str ());
	}
	if (0 == GetLongPathName (ptsz, tsz, MAX_PATH))
		return ptsz;
	return tsz;
}

void vmsCommandLine::fromString(LPCTSTR ptsz, bool bConvertToLongPath)
{
	Clear ();

	if (ptsz == NULL || *ptsz == 0)
		return;

	TCHAR tszTmp [MAX_PATH] = _T ("");
	if (_tcschr (ptsz, '%'))
	{
		ExpandEnvironmentStrings (ptsz, tszTmp, MAX_PATH);
		ptsz = tszTmp;
	}

	if (*ptsz == '"')
	{
		ptsz++;
		while (*ptsz && *ptsz != '"')
			m_tstrExe += *ptsz++;
		if (*ptsz == 0)
		{
			m_tstrExe = _T ("");
			return;
		}

		ptsz++;
	}
	else
	{
		

		while (*ptsz == ' ')
			ptsz++;

		do 
		{
			while (*ptsz && *ptsz != ' ')
				m_tstrExe += *ptsz++;

			if (m_tstrExe.length () > 1 && m_tstrExe [1] != ':')
			{
				if (SearchPath (m_tstrExe.c_str (), _T (".exe"), &m_tstrExe))
				{
					bConvertToLongPath = false; 
					break;
				}
			}

			if (*ptsz)
			{
				DWORD dw = GetFileAttributes (m_tstrExe.c_str ());
				if (dw != DWORD (-1) && (dw & FILE_ATTRIBUTE_DIRECTORY) == 0)
					break;

				tstring tstr = m_tstrExe; 

				tstr += _T (".exe");
				dw = GetFileAttributes (tstr.c_str ());
				if (dw != DWORD (-1) && (dw & FILE_ATTRIBUTE_DIRECTORY) == 0)
					break;

				if (m_tstrExe.length () > 4 && 
						_tcsicmp (m_tstrExe.c_str ()+m_tstrExe.length ()-4, _T (".exe")) == 0)
					break; 

				while (*ptsz == ' ')
					m_tstrExe += *ptsz++;
			}

		} while (*ptsz);
	}

	if (bConvertToLongPath)
		m_tstrExe = getLongPathName (m_tstrExe.c_str ());

	while (*ptsz == ' ')
		ptsz++;
	
	m_tstrArgs = ptsz ? ptsz : _T ("");

	RemoveTrailingSpaces ();
}

tstring vmsCommandLine::toString() const
{
	if (m_tstrArgs.empty ())
		return m_tstrExe;

	if (m_tstrExe.empty ())
		return _T ("");

	TCHAR tsz [32*1024] = _T ("");
	_sntprintf (tsz, 32*1024, _T ("\"%s\" %s"), m_tstrExe.c_str (), m_tstrArgs.c_str ());
	return tsz;
}

bool vmsCommandLine::isEmpty() const
{
	return m_tstrExe.empty ();
}

LPCTSTR vmsCommandLine::getExe() const
{
	return m_tstrExe.c_str ();
}

LPCTSTR vmsCommandLine::getArgs() const
{
	return m_tstrArgs.c_str ();
}

void vmsCommandLine::Clear()
{
	m_tstrExe = m_tstrArgs = _T ("");
}

void vmsCommandLine::setExe(LPCTSTR ptsz)
{
	m_tstrExe = ptsz;
}

void vmsCommandLine::setArgs(LPCTSTR ptsz)
{
	while (*ptsz == ' ')
		ptsz++;
	m_tstrArgs = ptsz;
	RemoveTrailingSpaces ();
}

bool vmsCommandLine::is_EXE_CmdLine() const
{
	if (m_tstrExe.empty ())
		return false;
	if (m_tstrExe.length () < 5)
		return false;

	return _tcsicmp (m_tstrExe.c_str () + m_tstrExe.length () - 4, _T (".exe")) == 0;
}

LPCTSTR vmsCommandLine::getExeName() const
{
	LPCTSTR ptsz = _tcsrchr (getExe (), '\\');
	if (!ptsz)
		ptsz = _tcsrchr (getExe (), '/');
	if (ptsz)
		ptsz++;
	return ptsz;
}

int vmsCommandLine::CompareEXEs(const vmsCommandLine &cl) const
{
	LPCTSTR ptsz1 = getExe ();
	LPCTSTR ptsz2 = cl.getExe ();

	if (ptsz1 && ptsz2)
		return _tcsicmp (ptsz1, ptsz2);

	if (ptsz1 == NULL && ptsz2 == NULL)
		return 0;

	if (!ptsz1)
		return -1;

	return 1;
}

void vmsCommandLine::RemoveTrailingSpaces()
{
	while (m_tstrArgs.empty () == false && m_tstrArgs [m_tstrArgs.length () - 1] == ' ')
		m_tstrArgs.erase (m_tstrArgs.begin () + m_tstrArgs.length () - 1);
}

bool vmsCommandLine::haveArgs() const
{
	return !m_tstrArgs.empty ();
}

bool vmsCommandLine::Execute(DWORD dwFlags, LPDWORD pdwProcessExitCode) const
{
	if (isEmpty ())
		return false;

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory (&si, sizeof (si));
	si.cb = sizeof (si);
	ZeroMemory (&pi, sizeof (pi));

	tstring tstrExe = m_tstrExe;

	BOOL bOK = CreateProcess (NULL, (LPTSTR)toString ().c_str (),
		NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &si, &pi);

	if (!bOK)
	{
		DWORD dwError = GetLastError ();
		if (dwError == ERROR_NOT_FOUND || dwError == ERROR_PATH_NOT_FOUND)
		{
			if (dwFlags & SearchPathIfRequired)
			{
				LPTSTR ptszTmp;
				TCHAR tszExe [MAX_PATH] = _T ("");
				SearchPath (NULL, m_tstrExe.c_str (), _T (".exe"), MAX_PATH, tszExe, &ptszTmp);
				tstrExe = tszExe;
				tstring tstrCmdLine = _T ("\"");
				tstrCmdLine += tszExe;
				tstrCmdLine += _T ("\" ");
				tstrCmdLine += m_tstrArgs;

				bOK = CreateProcess (NULL, (LPTSTR)tstrCmdLine.c_str (),
					NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &si, &pi);
			}
			else
			{
				return false;
			}
		}		
	}

	if (!bOK)
	{
		if (GetLastError () == ERROR_ELEVATION_REQUIRED)
		{
			if (dwFlags & RunElevatedIfRequired)
			{
				SHELLEXECUTEINFO sei = {0};
				sei.cbSize = sizeof (sei);
				sei.fMask = SEE_MASK_FLAG_NO_UI | SEE_MASK_NOCLOSEPROCESS;
				sei.lpVerb = _T ("runas");
				sei.lpFile = tstrExe.c_str ();
				sei.lpParameters = m_tstrArgs.c_str ();
				sei.nShow = SW_SHOWNORMAL;
				bOK = ShellExecuteEx (&sei);
				if (bOK)
				{
					pi.hProcess = sei.hProcess;
					pi.dwProcessId = GetProcessId (pi.hProcess);
				}
			}
			else
			{
				return false;
			}
		}
	}

	if (!bOK)
		return false;

	if ((dwFlags & WaitForCompletion) || pdwProcessExitCode)
	{
		WaitForSingleObject (pi.hProcess, INFINITE);

		HANDLE hSnapshot = CreateToolhelp32Snapshot (TH32CS_SNAPALL, NULL);
		if (hSnapshot != INVALID_HANDLE_VALUE) 
		{
			PROCESSENTRY32 pe = {sizeof (PROCESSENTRY32)}; 
			BOOL bDoSearch = Process32First (hSnapshot, &pe);
			while (bDoSearch)
			{
				bDoSearch = Process32Next (hSnapshot, &pe);

				if (pe.th32ParentProcessID == pi.dwProcessId)
				{
					HANDLE h = OpenProcess (SYNCHRONIZE, FALSE, pe.th32ProcessID);
					if (h)
					{
						WaitForSingleObject (h, INFINITE);					
						CloseHandle (h);
					}
					bDoSearch = FALSE; 
				}
			}
			CloseHandle (hSnapshot);
		}

		if (pdwProcessExitCode)
		{
			*pdwProcessExitCode = 0;
			if (FALSE == GetExitCodeProcess (pi.hProcess, pdwProcessExitCode))
			{
				CloseHandle (pi.hProcess);
				return false;
			}
		}
	}

	CloseHandle (pi.hProcess);

	return true;
}
