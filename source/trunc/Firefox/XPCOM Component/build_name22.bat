@REM PYTHON 2.7 must be installed (3.x version of PYTHON is not supported)
@REM https://developer.mozilla.org/en-US/docs/XPIDL/pyxpidl
@echo off
@cls
del %1.h > nul
del %1.xpt > nul
copy /Y %1.idl "..\..\Gecko.SDK\22\idl\" > nul
cd "..\..\Gecko.SDK\22\idl\"
del %1.h > nul
del %1.xpt > nul
..\sdk\bin\header.py --cachedir=%TMP% -o "%1.h" "%1.idl"
..\sdk\bin\typelib.py --cachedir=%TMP% -o "%1.xpt" "%1.idl"
cd "..\..\..\Firefox\XPCOM Component"
copy /Y "..\..\Gecko.SDK\22\idl\%1.h" .\ > nul
copy /Y "..\..\Gecko.SDK\22\idl\%1.xpt" .\ > nul
@rem make a copy for bin\Release folder...
copy /Y "..\..\Gecko.SDK\22\idl\%1.xpt" ..\extension\Components\ > nul