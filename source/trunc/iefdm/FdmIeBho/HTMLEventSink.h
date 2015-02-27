/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef DHTML_EVENT_H
#define DHTML_EVENT_H

template <class T> class CHtmlEventSink : public IDispatch  
{
typedef void (T::*EVENTFUNCTIONCALLBACK)(IUnknown *pUnkParam, DISPID idEvent,  VARIANT* pVarResult);

public:
	CHtmlEventSink()  { m_cRef = 0; m_dwCookie = 0;}
   ~CHtmlEventSink()  { ;}

   HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject)
   {
      *ppvObject = NULL;

      if (IsEqualGUID(riid, IID_IUnknown))
         *ppvObject = reinterpret_cast<void**>(this);

      if (IsEqualGUID(riid, IID_IDispatch))
         *ppvObject = reinterpret_cast<void**>(this);

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
      if (InterlockedDecrement(&m_cRef) == 0)
      {
         delete this;
         return 0;
      }	  
      return m_cRef;
   }
	   
	STDMETHOD(GetTypeInfoCount)(unsigned int FAR* pctinfo)
   { return E_NOTIMPL; }

   STDMETHOD(GetTypeInfo)(unsigned int iTInfo, LCID  lcid, ITypeInfo FAR* FAR*  ppTInfo)
   { return E_NOTIMPL; }

   STDMETHOD(GetIDsOfNames)(REFIID riid, OLECHAR FAR* FAR* rgszNames, unsigned int cNames, LCID lcid, DISPID FAR* rgDispId)
   { return S_OK; }

   STDMETHOD(Invoke)(DISPID dispIdMember, REFIID riid, LCID lcid,
      WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult,
      EXCEPINFO * pExcepInfo, UINT * puArgErr)
   {
	  if (m_pT)
		  (m_pT->*m_pFunc)(m_spUnkParam, dispIdMember, pVarResult);
	
      return S_OK;
   }

public:
   static CHtmlEventSink* CreateHandler(T* pT, EVENTFUNCTIONCALLBACK pFunc, LPUNKNOWN pUnkParam)
   {
      CHtmlEventSink<T>* pFO = new CHtmlEventSink<T>;
      pFO->m_pT = pT;
      pFO->m_pFunc = pFunc;
      if (pUnkParam)
		  pFO->m_spUnkParam = pUnkParam;
      pFO->AddRef ();	
      return pFO;
   }
public:
  IUnknown* getUnkParam () const {return m_spUnkParam;}
  DWORD m_dwCookie;

protected:	
	EVENTFUNCTIONCALLBACK m_pFunc;
	IUnknownPtr m_spUnkParam;

	T* m_pT;
	long m_cRef;
};

#endif DHTML_EVENT_H