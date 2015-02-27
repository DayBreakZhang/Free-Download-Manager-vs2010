@echo off

rmdir /S /Q Debug
rmdir /S /Q Release

rmdir /S /Q DownloaderLib\Debug
rmdir /S /Q DownloaderLib\Release

rmdir /S /Q EncodeForStat\Debug
rmdir /S /Q EncodeForStat\Release

rmdir /S /Q FDMActiveXInstaller\Debug
rmdir /S /Q FDMActiveXInstaller\Release

rmdir /S /Q FDMCustomized\Debug
rmdir /S /Q FDMCustomized\Release

rmdir /S /Q FDMCustomized\FDMCustGenerator\Debug
rmdir /S /Q FDMCustomized\FDMCustGenerator\Release

rmdir /S /Q FDMCustomized\FDMCustIEBtn\Debug
rmdir /S /Q FDMCustomized\FDMCustIEBtn\Release

rmdir /S /Q FDMCustomized\FDMCustomized_lib\Debug
rmdir /S /Q FDMCustomized\FDMCustomized_lib\Release

rmdir /S /Q FDMCustomized\FDMCustomized_PreExe\Debug
rmdir /S /Q FDMCustomized\FDMCustomized_PreExe\Release

rmdir /S /Q FDMSetupInstaller\Debug
rmdir /S /Q FDMSetupInstaller\Release

del /Q FDMSetupInstaller\BUILD_SCRIPT\result.exe
del /Q FDMSetupInstaller\BUILD_SCRIPT\fdminst.exe
del /Q FDMSetupInstaller\BUILD_SCRIPT\fdm-fdc-pk.rar

rmdir /S /Q iefdm\Debug
rmdir /S /Q iefdm\Release

rmdir /S /Q iefdm\iefdmdm\Debug
rmdir /S /Q iefdm\iefdmdm\Release

rmdir /S /Q iefdm\iecooks\Debug
rmdir /S /Q iefdm\iecooks\Release

rmdir /S /Q iefdm\UrlMonSpy\Debug
rmdir /S /Q iefdm\UrlMonSpy\Release

rmdir /S /Q InnoSetup\fdminno\Debug
rmdir /S /Q InnoSetup\fdminno\Release

rmdir /S /Q msdl\Debug
rmdir /S /Q msdl\Release

rmdir /S /Q InetFile\Debug
rmdir /S /Q InetFile\Release

rmdir /S /Q InetFile\cURL_lib\Debug
rmdir /S /Q InetFile\cURL_lib\Release
rmdir /S /Q InetFile\cURL_lib\Release_nossl

rmdir /S /Q OpNetCatcher\Debug
rmdir /S /Q OpNetCatcher\Release

rmdir /S /Q PartMediaPreview\Debug
rmdir /S /Q PartMediaPreview\Release

rmdir /S /Q Hash\Debug
rmdir /S /Q Hash\Release

rmdir /S /Q Updater\Debug
rmdir /S /Q Updater\Release

rmdir /S /Q Updater\WrapperForInstaller\Debug
rmdir /S /Q Updater\WrapperForInstaller\Release
del /Q Updater\WrapperForInstaller\BUILD_SCRIPT\fdminst.exe
del /Q Updater\WrapperForInstaller\BUILD_SCRIPT\result.exe


del /Q mshtml.tli mshtml.tlh
del /Q /S *.ncb *.opt *.plg

rmdir /S /Q "Firefox\XPCOM Component\Debug"
rmdir /S /Q "Firefox\XPCOM Component\Release"

rmdir /S /Q "Web Interface\Debug"
rmdir /S /Q "Web Interface\Release"

rmdir /S /Q Uploader\CoreDll\Debug
rmdir /S /Q Uploader\CoreDll\Release

rmdir /S /Q Uploader\FUM\Debug
rmdir /S /Q Uploader\FUM\Release

rmdir /S /Q Uploader\UploadContextMenu\UploadShellExt\Debug
rmdir /S /Q Uploader\UploadContextMenu\UploadShellExt\Release

rmdir /S /Q Uploader\UploadContextMenu\UploadOeMenu\InjApp\Debug
rmdir /S /Q Uploader\UploadContextMenu\UploadOeMenu\InjApp\Release

rmdir /S /Q Uploader\UploadContextMenu\UploadOeMenu\InjDll\Debug
rmdir /S /Q Uploader\UploadContextMenu\UploadOeMenu\InjDll\Release

rmdir /S /Q Uploader\FDMUploadBtnForIe\Debug
rmdir /S /Q Uploader\FDMUploadBtnForIe\Release

rmdir /S /Q Bittorrent\fdmbtsupp\Debug
rmdir /S /Q Bittorrent\fdmbtsupp\Release

rmdir /S /Q Bittorrent\libtorrent\Debug
rmdir /S /Q Bittorrent\libtorrent\Release

rmdir /S /Q MediaConverter\Debug
rmdir /S /Q MediaConverter\Release

rmdir /S /Q VistaFx\Debug
rmdir /S /Q VistaFx\Release

rmdir /S /Q AppWinSockSniffDll\Debug
rmdir /S /Q AppWinSockSniffDll\Release

rmdir /S /Q etasks\Debug
rmdir /S /Q etasks\Release

rmdir /S /Q iefdm\FdmIeBho\Debug
rmdir /S /Q iefdm\FdmIeBho\Release

