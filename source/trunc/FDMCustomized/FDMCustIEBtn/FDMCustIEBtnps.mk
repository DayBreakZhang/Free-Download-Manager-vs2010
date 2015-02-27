
FDMCustIEBtnps.dll: dlldata.obj FDMCustIEBtn_p.obj FDMCustIEBtn_i.obj
	link /dll /out:FDMCustIEBtnps.dll /def:FDMCustIEBtnps.def /entry:DllMain dlldata.obj FDMCustIEBtn_p.obj FDMCustIEBtn_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del FDMCustIEBtnps.dll
	@del FDMCustIEBtnps.lib
	@del FDMCustIEBtnps.exp
	@del dlldata.obj
	@del FDMCustIEBtn_p.obj
	@del FDMCustIEBtn_i.obj
