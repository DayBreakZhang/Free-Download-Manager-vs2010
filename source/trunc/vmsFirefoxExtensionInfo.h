/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include <iterator>
#include <fstream>

#include "sqlite/sqlite3.h"
#include "picojson.h"

class vmsFirefoxExtensionInfo
{
public:

	vmsFirefoxExtensionInfo(void) : 
	  m_iSoftDisabled (0), m_iAppDisabled (0), m_iUserDisabled (0)
	{
	}

	virtual ~vmsFirefoxExtensionInfo(void)
	{
	}

	virtual bool Read (LPCTSTR ptszDbFile, LPCTSTR ptszExtensionId)
	{
		USES_CONVERSION;
		sqlite3 *db = NULL;
		if (SQLITE_OK != sqlite3_open16 (T2CW (ptszDbFile), &db))
			return false;

		tstring tstrQ = _T ("SELECT * FROM addon WHERE id==\"");
		tstrQ += ptszExtensionId;
		tstrQ += "\";";

		bool bOK = SQLITE_OK == sqlite3_exec (db, _t2utf8 (tstrQ.c_str ()).c_str (), _onAddonRecordEnum, this, NULL);

		sqlite3_close (db);

		return bOK;
	}

public:
	int m_iSoftDisabled, m_iAppDisabled, m_iUserDisabled;

protected:
	static int _onAddonRecordEnum (void *param, int coln, char **rows, char **colnm)
	{
		vmsFirefoxExtensionInfo *pthis = (vmsFirefoxExtensionInfo*) param;

		for (int i = 0; i < coln; i++)
		{
			if (!stricmp (colnm [i], "softDisabled"))
				pthis->m_iSoftDisabled = atoi (rows [i]);

			else if (!stricmp (colnm [i], "appDisabled"))
				pthis->m_iAppDisabled = atoi (rows [i]);

			else if (!stricmp (colnm [i], "userDisabled"))
				pthis->m_iUserDisabled = atoi (rows [i]);
		}

		return 0;
	}
};

class vmsFirefox26ExtensionInfo : public vmsFirefoxExtensionInfo
{
public:
	vmsFirefox26ExtensionInfo(void)
	{
	}

	virtual bool Read (LPCTSTR ptszDbFile, LPCTSTR ptszExtensionId)
	{
		std::ifstream file(ptszDbFile);
		if(!file)
			return false;

		std::istream_iterator<char> input(file);
		picojson::value v;
		std::string err;
		picojson::parse(v, input, std::istream_iterator<char>(), &err);
		if (!err.empty())
			return false;
		if(!v.is<picojson::object>())
			return false;
		picojson::array addons = v.get<picojson::object>()["addons"].get<picojson::array>();
		for(auto addon = addons.begin(); addon != addons.end(); ++addon)
		{
			picojson::object obj = (*addon).get<picojson::object>();
			if(obj["id"].to_str() == std::string(ptszExtensionId))
			{
				if(obj.count("softDisabled") && obj.count("appDisabled") && obj.count("userDisabled"))
				{
					m_iSoftDisabled = obj["softDisabled"].get<bool>();
					m_iAppDisabled  = obj["appDisabled" ].get<bool>();
					m_iUserDisabled = obj["userDisabled"].get<bool>();
				}
				break;
			}
		}
		return true;
	}
};
