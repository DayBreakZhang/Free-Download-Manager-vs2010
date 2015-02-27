@echo off
::bat删除当前目录及其所有子目录中的除EXE文件外的所有VC临时文件

echo 删除vc编译产生的临时文件

echo 删除开始...

::for /r . %%c in (.) do @if exist "%%c\Debug" rd /s /q "%%c\Debug"

::for /r . %%c in (.) do @if exist "%%c\Release" rd /s /q "%%c\Release"

for /r . %%c in (*.obj *.pch *.htm *.dep *.idb *.pdb *.manifest *.ilk *.res *.sbr *tlh *tli *.bsc *.aps *.clw *.ncb *.plg *.positions *.ww *.user) do del "%%c"

::递归删除当前目录下的所有空目录
for /f "delims=" %%a in ('dir . /b /ad /s ^|sort /r' ) do rd /q "%%a" 2>nul

for /r . %%c in ("*va_c__documents and settings_administrator_local settings_application data_visualassist_vc6_history_") do del "%%c"

echo 删除完毕...

pause

