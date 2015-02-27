/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsKnownBrowsers
{
public:
	enum Browser 
	{
		Unknown					= 0,
		InternetExplorer		= 1,
		Opera					= 1 << 1, 
		Netscape				= 1 << 2, 
		MozillaSuite			= 1 << 3, 
		Chrome					= 1 << 4, 
		Safari					= 1 << 5, 
		Firefox					= 1 << 6
	};

public:

	static bool isBrowserRunning (Browser enBrowser)
	{
		static std::pair <Browser, tstring> _aWndClasses [] = {
			std::make_pair (InternetExplorer, _T ("IEFrame")),
			std::make_pair (Firefox, _T ("MozillaUIWindowClass")),
			std::make_pair (Chrome, _T ("Chrome_WidgetWin_0")),
			std::make_pair (Opera, _T ("OperaWindowClass")),
			std::make_pair (Opera, _T ("OpWindow")),
		};

		for (size_t i = 0; i < _countof (_aWndClasses); i++)
		{
			if (_aWndClasses [i].first != enBrowser)
				continue;

			if (FindWindowEx (NULL, NULL, _aWndClasses [i].second.c_str (), NULL))
				return true;
		}

		return false;
	}

	static LPCTSTR getBrowserUiName (Browser enBrowser)
	{
		switch (enBrowser)
		{
		case InternetExplorer: return _T ("Internet Explorer");
		case Opera: return _T ("Opera");
		case Netscape: return _T ("Netscape");
		case MozillaSuite: return _T ("Mozilla Suite");
		case Chrome: return _T ("Google Chrome");
		case Safari: return _T ("Safari");
		case Firefox: return _T ("Firefox");
		default: assert (false); return NULL;
		}
	}

	vmsKnownBrowsers(void)
	{
	}

	~vmsKnownBrowsers(void)
	{
	}
};

