/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDOCHOSTUIHANDLER_H__F6586962_B0E8_4009_AD67_83DF5459BE7C__INCLUDED_)
#define AFX_VMSDOCHOSTUIHANDLER_H__F6586962_B0E8_4009_AD67_83DF5459BE7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <mshtmhst.h>
#include <mshtml.h>
#include <comdef.h>
_COM_SMARTPTR_TYPEDEF(IHTMLInputTextElement, __uuidof(IHTMLInputTextElement));
_COM_SMARTPTR_TYPEDEF(IHTMLTextAreaElement, __uuidof(IHTMLTextAreaElement));

class vmsDocHostUIHandler : public IDocHostUIHandler  
{
public:
	STDMETHOD(GetHostInfo)(DOCHOSTUIINFO *pInfo);
	vmsDocHostUIHandler();
	virtual ~vmsDocHostUIHandler();

	HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject)
	{
		*ppvObject = NULL;

		if (IsEqualGUID(riid, IID_IUnknown))
			*ppvObject = static_cast<IDocHostUIHandler*>(this);

		if (IsEqualGUID(riid, IID_IDocHostUIHandler))
			*ppvObject = static_cast<IDocHostUIHandler*>(this);

		if (*ppvObject)
		{
			((IUnknown*)*ppvObject)->AddRef();
			return S_OK;
		}
		else return E_NOINTERFACE;
	}

	DWORD __stdcall AddRef()
	{
		return InterlockedIncrement(&m_cRef);
	}

	DWORD __stdcall Release()
	{
		InterlockedDecrement(&m_cRef);
		return m_cRef;
	}

	
		
	STDMETHOD( ShowContextMenu )(  
		 DWORD dwID,
		 POINT *ppt,
		 IUnknown *pcmdtReserved,
		 IDispatch *pdispReserved)
	{ 
		

		IHTMLInputTextElementPtr spTextInp (pdispReserved);
		if (spTextInp != NULL)
			return S_FALSE;
		IHTMLTextAreaElementPtr spTextArea (pdispReserved);
		if (spTextArea != NULL)
			return S_FALSE;

		return S_OK;
	}

	STDMETHOD( ShowUI )( 
		 DWORD dwID,
		 IOleInPlaceActiveObject *pActiveObject,
		 IOleCommandTarget *pCommandTarget,
		 IOleInPlaceFrame *pFrame,
		 IOleInPlaceUIWindow *pDoc)
	{ return E_NOTIMPL; }

	STDMETHOD( HideUI )( )
	{ return E_NOTIMPL; }

	STDMETHOD( UpdateUI )( )
	{ return E_NOTIMPL; }

	STDMETHOD( EnableModeless )( 
		 BOOL fEnable)
	{ return E_NOTIMPL; }

	STDMETHOD( OnDocWindowActivate )(
		 BOOL fActivate)
	{ return E_NOTIMPL; }

	STDMETHOD( OnFrameWindowActivate )( 
		 BOOL fActivate)
	{ return E_NOTIMPL; }

	STDMETHOD( ResizeBorder )( 
		 LPCRECT prcBorder,
		 IOleInPlaceUIWindow *pUIWindow,
		 BOOL fRameWindow)
	{ return E_NOTIMPL; }

	STDMETHOD( TranslateAccelerator )( 
		 LPMSG lpMsg,
		 const GUID *pguidCmdGroup,
		 DWORD nCmdID)
	{ return E_NOTIMPL; }

	STDMETHOD( GetOptionKeyPath )( 
		 LPOLESTR *pchKey,
		 DWORD dw)
	{ return E_NOTIMPL; }

	STDMETHOD( GetDropTarget )( 
		 IDropTarget *pDropTarget,
		 IDropTarget **ppDropTarget)
	{ return E_NOTIMPL; }

	STDMETHOD( GetExternal )( 
		 IDispatch **ppDispatch)
	{ return E_NOTIMPL; }

	STDMETHOD( TranslateUrl )( 
		 DWORD dwTranslate,
		 OLECHAR *pchURLIn,
		 OLECHAR **ppchURLOut)
	{ return E_NOTIMPL; }

	STDMETHOD( FilterDataObject )( 
		 IDataObject *pDO,
		 IDataObject **ppDORet)
	{ return E_NOTIMPL; }

protected:
	long m_cRef;
};

#endif 
