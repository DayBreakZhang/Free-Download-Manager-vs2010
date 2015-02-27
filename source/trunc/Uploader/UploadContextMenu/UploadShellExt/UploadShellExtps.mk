
UploadShellExtps.dll: dlldata.obj UploadShellExt_p.obj UploadShellExt_i.obj
	link /dll /out:UploadShellExtps.dll /def:UploadShellExtps.def /entry:DllMain dlldata.obj UploadShellExt_p.obj UploadShellExt_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del UploadShellExtps.dll
	@del UploadShellExtps.lib
	@del UploadShellExtps.exp
	@del dlldata.obj
	@del UploadShellExt_p.obj
	@del UploadShellExt_i.obj
