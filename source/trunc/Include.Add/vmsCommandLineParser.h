/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "tstring.h"

class vmsCommandLineParser
{
public:
	
	
	
	typedef std::pair <tstring, tstring> Argument;
public:
	bool Parse (LPCTSTR ptszCmdLine = GetCommandLine ())
	{
		m_vArgs.clear ();

		if (*ptszCmdLine == '"')
		{
			ptszCmdLine = _tcschr (ptszCmdLine+1, '"');
			if (ptszCmdLine)
				ptszCmdLine++;
			else
				return false;
		}
		else
		{
			while (*ptszCmdLine && *ptszCmdLine != ' ')
				ptszCmdLine++;
		}

		tstring tstrParam, tstrValue;
		tstrParam.reserve (MAX_PATH);
		tstrValue.reserve (MAX_PATH);

		while (*ptszCmdLine)
		{
			tstrParam = _T ("");
			tstrValue = _T ("");
			
			bool bHasValue = true;

			
			while (*ptszCmdLine && (*ptszCmdLine == ' ' || *ptszCmdLine == '\r' || *ptszCmdLine == '\n'))
				ptszCmdLine++;

			if (*ptszCmdLine == '/' || *ptszCmdLine == '-')
			{
				while (*++ptszCmdLine && *ptszCmdLine != ' ' && *ptszCmdLine != '=')
					tstrParam += *ptszCmdLine;

				while (*ptszCmdLine == ' ')
					ptszCmdLine++;

				
				if (*ptszCmdLine == '=')
				{
					ptszCmdLine++;
					while (*ptszCmdLine == ' ')
						ptszCmdLine++;
				}
				else
					bHasValue = false;
			}

			if (bHasValue)
			{
				TCHAR cSp = ' ';	
				TCHAR cSp1 = '\n', cSp2 = '\r';
				
				if (*ptszCmdLine == '"' || *ptszCmdLine == '\'')
				{
					cSp = *ptszCmdLine++;
					cSp1 = cSp2 = 0;
				}

				
				if (*ptszCmdLine != '/' && *ptszCmdLine != '-')
				{
					while (*ptszCmdLine && *ptszCmdLine != cSp && *ptszCmdLine != cSp1 && *ptszCmdLine != cSp2)
						tstrValue += *ptszCmdLine++;

					while (*ptszCmdLine && (*ptszCmdLine == cSp || *ptszCmdLine == cSp1 || *ptszCmdLine == cSp2))
						ptszCmdLine++;
				}
			}

			if (!tstrParam.empty () || !tstrValue.empty ())
				m_vArgs.push_back (Argument (tstrParam, tstrValue));
		}

		return true;
	}

	size_t getArgumentCount () const {return m_vArgs.size ();}
	const Argument& getArgument (size_t nIndex) const {return m_vArgs [nIndex];}

public:
	vmsCommandLineParser (LPCTSTR ptszCmdLine = GetCommandLine ()) {Parse (ptszCmdLine);}
	const Argument* findArgument (LPCTSTR ptszName) const
	{
		for (size_t i = 0; i < m_vArgs.size (); i++)
		{
			if (m_vArgs [i].first == ptszName)
				return &m_vArgs [i];
		}
		return NULL;
	}

protected:
	std::vector <Argument> m_vArgs;
};