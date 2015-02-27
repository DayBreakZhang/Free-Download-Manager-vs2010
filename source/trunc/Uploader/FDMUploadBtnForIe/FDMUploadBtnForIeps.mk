
FDMUploadBtnForIeps.dll: dlldata.obj FDMUploadBtnForIe_p.obj FDMUploadBtnForIe_i.obj
	link /dll /out:FDMUploadBtnForIeps.dll /def:FDMUploadBtnForIeps.def /entry:DllMain dlldata.obj FDMUploadBtnForIe_p.obj FDMUploadBtnForIe_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del FDMUploadBtnForIeps.dll
	@del FDMUploadBtnForIeps.lib
	@del FDMUploadBtnForIeps.exp
	@del dlldata.obj
	@del FDMUploadBtnForIe_p.obj
	@del FDMUploadBtnForIe_i.obj
