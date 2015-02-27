
iefdmdmps.dll: dlldata.obj iefdmdm_p.obj iefdmdm_i.obj
	link /dll /out:iefdmdmps.dll /def:iefdmdmps.def /entry:DllMain dlldata.obj iefdmdm_p.obj iefdmdm_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del iefdmdmps.dll
	@del iefdmdmps.lib
	@del iefdmdmps.exp
	@del dlldata.obj
	@del iefdmdm_p.obj
	@del iefdmdm_i.obj
