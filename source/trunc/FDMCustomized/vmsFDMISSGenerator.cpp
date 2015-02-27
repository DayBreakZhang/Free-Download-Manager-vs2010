/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustomized.h"
#include "vmsFDMISSGenerator.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFDMISSGenerator::vmsFDMISSGenerator()
{
	m_strInputFolder = "E:\\Release\\Free Download Manager\\";
	m_strVersion = "1.5";
	m_strOutputFolder = "E:\\Release\\#Output";
	m_strOutputFile = "fdminst-customized";

	m_bAddSiteLinkToStartMenu = TRUE;
	m_bAddSiteLinkToFavorites = TRUE;
	m_bModifyHomepage = TRUE;
	m_bAddDownloadsFile = FALSE;
	
	m_strSiteLink = "http://fdmcs.com/";
	m_strSiteIcoFile = "D:\\WINDOWS\\system32\\divx.ico";
}

vmsFDMISSGenerator::~vmsFDMISSGenerator()
{

}

void vmsFDMISSGenerator::Generate(LPCSTR pszOutputFile)
{
	CStdioFile file (pszOutputFile, CFile::modeWrite | CFile::modeCreate);	

#define WRITE(s) file.WriteString (s); file.WriteString ("\n");

	WRITE ("[Setup]");
	WRITE ("AppName=Free Download Manager");

	CString str = "AppVerName=Free Download Manager ";
	str += m_strVersion; str += " "; str += m_strInstallationName;
	WRITE (str);
	WRITE ("AppPublisher=FreeDownloadManager.ORG");
	WRITE ("AppPublisherURL=http://www.freedownloadmanager.org/");
	WRITE ("AppSupportURL=http://www.freedownloadmanager.org/");
	WRITE ("AppUpdatesURL=http://www.freedownloadmanager.org/");
	WRITE ("DefaultDirName={pf}\\Free Download Manager");
	WRITE ("UsePreviousAppDir=yes");
	WRITE ("UsePreviousGroup=yes");
	WRITE ("UsePreviousTasks=yes");
	WRITE ("DefaultGroupName=Free Download Manager");

	str = "LicenseFile="; str += m_strInputFolder; str += "license.txt";
	WRITE (str);

	WRITE ("Compression=lzma");
	WRITE ("SolidCompression=yes");
	
	str = "OutputDir="; str += m_strOutputFolder;
	WRITE (str);

	str = "OutputBaseFilename="; str += m_strOutputFile;
	WRITE (str);

	WRITE ("");

	WRITE ("[Tasks]");
	WRITE ("Name: \"desktopicon\"; Description: \"{cm:CreateDesktopIcon}\"; GroupDescription: \"{cm:AdditionalIcons}\";");
	WRITE ("Name: \"quicklaunchicon\"; Description: \"{cm:CreateQuickLaunchIcon}\"; GroupDescription: \"{cm:AdditionalIcons}\"; Flags: unchecked");
	WRITE ("Name: \"autorun\"; Description: \"Launch FDM automatically at Windows startup\"; GroupDescription: \"Additional options\";");
	WRITE ("");
	WRITE ("[Files]");

	str = "Source: \""; str += m_strInputFolder; str += "*.exe\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "*.htm\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "*.tlb\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "Help\\*\"; DestDir: \"{app}\\Help\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "Language\\*\"; DestDir: \"{app}\\Language\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "dbghelp.dll\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "iefdm.dll\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "iefdmdm.dll\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "npfdm.dll\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	str = "Source: \""; str += m_strInputFolder; str += "*.txt\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
	WRITE (str);

	
	if (m_bAddSiteLinkToStartMenu || m_bAddSiteLinkToFavorites)
	{
		str = "Source: \""; str += m_strSiteIcoFile; 
		str += "\"; DestDir: \"{app}\"; DestName: \"fdmcs.ico\"; Flags: ignoreversion restartreplace";
		WRITE (str);
	}

	
	if (m_bAddDownloadsFile)
	{
		str = "Source: \""; str += m_strInputFolder; str += m_strDownloadsFile; 
		str += "\"; DestDir: \"{app}\"; Flags: ignoreversion restartreplace";
		WRITE (str);
	}
	
	WRITE ("");

	WRITE ("[INI]");
	WRITE ("Filename: \"{app}\\fdm.url\"; Section: \"InternetShortcut\"; Key: \"URL\"; String: \"http://www.freedownloadmanager.org/\"");

	if (m_bAddSiteLinkToStartMenu)
	{
		

		
		str = "Filename: \"{app}\\fdmcs.url\"; Section: \"InternetShortcut\"; Key: \"URL\"; String: \""; str += m_strSiteLink; str += "\"";
		WRITE (str);

		
		str = "Filename: \"{app}\\fdmcs.url\"; Section: \"InternetShortcut\"; Key: \"IconIndex\"; String: \"0\"";
		WRITE (str);
		str = "Filename: \"{app}\\fdmcs.url\"; Section: \"InternetShortcut\"; Key: \"IconFile\"; String: \""; str += "fdmcs.ico"; str += "\"";
		WRITE (str);
	}

	WRITE ("");
	WRITE ("[Icons]");
	WRITE ("Name: \"{group}\\Free Download Manager\"; Filename: \"{app}\\fdm.exe\"");
	WRITE ("Name: \"{group}\\Documentation\"; Filename: \"{app}\\Help\\Free Download Manager.chm\"");
	WRITE ("Name: \"{group}\\{cm:ProgramOnTheWeb,Free Download Manager}\"; Filename: \"{app}\\fdm.url\"");
	WRITE ("Name: \"{userdesktop}\\Free Download Manager\"; Filename: \"{app}\\fdm.exe\"; Tasks: desktopicon");
	WRITE ("Name: \"{userappdata}\\Microsoft\\Internet Explorer\\Quick Launch\\Free Download Manager\"; Filename: \"{app}\\fdm.exe\"; Tasks: quicklaunchicon");
	WRITE ("Name: \"{group}\\{cm:UninstallProgram,Free Download Manager}\"; Filename: \"{uninstallexe}\"");
	if (m_bAddSiteLinkToStartMenu)
	{
		str = "Name: \"{commonstartmenu}\\";
		str +=  "FDM Customization Site";
		str += "\"; Filename: \"{app}\\fdmcs.url\"; IconFilename: \"{app}\\fdmcs.ico\"; IconIndex: 0";
		WRITE (str);
	}
	if (m_bAddSiteLinkToFavorites)
	{
		str = "Name: \"{userfavorites}\\";
		str +=  "FDM Customization Site";
		str += "\"; Filename: \"{app}\\fdmcs.url\"; IconFilename: \"{app}\\fdmcs.ico\"; IconIndex: 0; MinVersion: 4.1,4.0";
		WRITE (str);
	}
	
	WRITE ("");
	WRITE ("[Registry]");
	WRITE ("Root: HKCU; Subkey: \"Software\\FreeDownloadManager.ORG\\Free Download Manager\"; Flags: uninsdeletekey");
	WRITE ("Root: HKCU; Subkey: \"Software\\FreeDownloadManager.ORG\\Free Download Manager\"; Valuetype: string; Valuename: \"Path\"; Valuedata: \"{app}\"");
	WRITE ("Root: HKCU; Subkey: \"Software\\Microsoft\\Windows\\CurrentVersion\\Run\"; Valuetype: string; Valuename: \"Free Download Manager\"; Valuedata: \"{app}\\fdm.exe -autorun\"; tasks: autorun");
	if (m_bModifyHomepage)
	{
		str = "Root: HKCU; Subkey: \"Software\\Microsoft\\Internet Explorer\\Main\"; Valuetype: string; Valuename: \"Start Page\"; Valuedata: \"";
		str += m_strSiteLink; str +="\";";
		WRITE (str);
	}
	
	WRITE ("");
	WRITE ("[Code]");
	WRITE ("function InitializeSetup(): Boolean;");
	WRITE ("begin");
	WRITE ("while CheckForMutexes ('Free Download Manager') do");
	WRITE ("begin");
	WRITE ("  if IDCANCEL = MsgBox ('Setup has detected that Free Download Manager is currently running.'#13#13'Please close all instances of it now, then click OK to continue, or Cancel to exit', mbError, MB_OKCANCEL) then");
	WRITE ("  begin");
	WRITE ("      Result := False;");
	WRITE ("      exit;");
	WRITE ("  end;");
	WRITE ("end;");
	WRITE ("");
	WRITE ("Result := True;");
	WRITE ("end;");
	WRITE ("");
	WRITE ("procedure UpdateOperaPlugin();");
	WRITE ("var");
	WRITE ("OperaPath : String;");
	WRITE ("AppDir : String;");
	WRITE ("begin");
	WRITE ("if not RegQueryStringValue (HKEY_CURRENT_USER, 'Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor',");
	WRITE ("          'OPDI', OperaPath) then exit;");
	WRITE ("");
	WRITE ("if OperaPath = '' then exit;");
	WRITE ("");
	WRITE ("OperaPath := AddBackslash (OperaPath);");
	WRITE ("AppDir := AddBackslash (WizardDirValue);");
	WRITE ("");
	WRITE ("while not FileCopy (AppDir + 'npfdm.dll', OperaPath + 'npfdm.dll', false) do");
	WRITE ("  begin");
	WRITE ("    if IDCANCEL = MsgBox ('Failed to update Opera monitoring plugin. Please close Opera', mbError, MB_RETRYCANCEL) then");
	WRITE ("      exit;");
	WRITE ("  end;");
	WRITE ("end;");
	WRITE ("");
	WRITE ("[Run]");
	WRITE ("Filename: \"{app}\\fdm.exe\"; Parameters: \"-regserver\"; StatusMsg: \"Registering...\"");
	WRITE ("Filename: \"{app}\\fdm.exe\"; Description: \"{cm:LaunchProgram,Free Download Manager}\"; Flags: nowait postinstall skipifsilent");
	WRITE ("");
	WRITE ("[UninstallRun]");
	WRITE ("Filename: \"{app}\\fdm.exe\"; Parameters: \"-unregserver\"");
	WRITE ("");
	WRITE ("[UninstallDelete]");
	WRITE ("Type: files; Name: \"{app}\\fdm.url\"");
	WRITE ("Type: files; Name: \"{app}\\fdmcs.url\"");
	WRITE ("");
}

