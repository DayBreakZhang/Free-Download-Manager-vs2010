/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __IHTMLScreen3_INTERFACE_DEFINED__
#define __IHTMLScreen3_INTERFACE_DEFINED__

 

EXTERN_C const IID IID_IHTMLScreen3;

MIDL_INTERFACE("305104a1-98b5-11cf-bb82-00aa00bdce0b")
IHTMLScreen3 : public IDispatch
{
public:
	virtual  HRESULT STDMETHODCALLTYPE get_systemXDPI( 
		 __RPC__out long *p) = 0;

	virtual  HRESULT STDMETHODCALLTYPE get_systemYDPI( 
		 __RPC__out long *p) = 0;

};

#endif 	