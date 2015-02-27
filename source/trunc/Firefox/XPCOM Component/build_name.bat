@echo off
@cls
del %1.h > nul
del %1.xpt > nul
copy /Y %1.idl "..\..\Gecko.SDK\2.0\idl\" > nul
cd "..\..\Gecko.SDK\2.0\idl\"
del %1.h > nul
del %1.xpt > nul
..\bin\xpidl -m header %1.idl
..\bin\xpidl -m typelib %1.idl
cd "..\..\..\Firefox\XPCOM Component"
copy /Y "..\..\Gecko.SDK\2.0\idl\%1.h" .\ > nul
copy /Y "..\..\Gecko.SDK\2.0\idl\%1.xpt" .\ > nul
@rem make a copy for bin\Release folder...
copy /Y "..\..\Gecko.SDK\2.0\idl\%1.xpt" ..\extension\Components\ > nul
