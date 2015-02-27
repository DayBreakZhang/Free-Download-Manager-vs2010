
iecooksps.dll: dlldata.obj iecooks_p.obj iecooks_i.obj
	link /dll /out:iecooksps.dll /def:iecooksps.def /entry:DllMain dlldata.obj iecooks_p.obj iecooks_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del iecooksps.dll
	@del iecooksps.lib
	@del iecooksps.exp
	@del dlldata.obj
	@del iecooks_p.obj
	@del iecooks_i.obj
