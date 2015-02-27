REM do these steps:
REM make sure Perl (ActivePerl) installed
cd openssl-0.9.8g
perl Configure VC-WIN32
ms\do_ms.bat
VCVARS32.BAT
REM by default nt.mak has /MD option (/MT - static runtime)
nmake -f ms\nt.mak