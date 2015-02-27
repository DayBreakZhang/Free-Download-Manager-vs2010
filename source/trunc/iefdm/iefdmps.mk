
iefdmps.dll: dlldata.obj iefdm_p.obj iefdm_i.obj
	link /dll /out:iefdmps.dll /def:iefdmps.def /entry:DllMain dlldata.obj iefdm_p.obj iefdm_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del iefdmps.dll
	@del iefdmps.lib
	@del iefdmps.exp
	@del dlldata.obj
	@del iefdm_p.obj
	@del iefdm_i.obj
