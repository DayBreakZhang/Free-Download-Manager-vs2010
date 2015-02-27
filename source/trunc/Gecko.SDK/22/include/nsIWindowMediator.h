/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpfe/appshell/public/nsIWindowMediator.idl
 */

#ifndef __gen_nsIWindowMediator_h__
#define __gen_nsIWindowMediator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_WINDOWMEDIATOR_CID \
{ 0x292e17c8, 0xccc1, 0x42e1, \
  { 0xac, 0x8b, 0xaf, 0x61, 0x7d, 0x54, 0x13, 0xb1 } }
#define NS_WINDOWMEDIATOR_CONTRACTID \
  "@mozilla.org/appshell/window-mediator;1"
class nsIXULWindow; /* forward declaration */

class nsIWidget; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIWindowMediatorListener; /* forward declaration */


/* starting interface:    nsIWindowMediator */
#define NS_IWINDOWMEDIATOR_IID_STR "292e17c8-ccc1-42e1-ac8b-af617d5413b1"

#define NS_IWINDOWMEDIATOR_IID \
  {0x292e17c8, 0xccc1, 0x42e1, \
    { 0xac, 0x8b, 0xaf, 0x61, 0x7d, 0x54, 0x13, 0xb1 }}

class NS_NO_VTABLE nsIWindowMediator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWMEDIATOR_IID)

  /* nsISimpleEnumerator getEnumerator (in wstring aWindowType); */
  NS_IMETHOD GetEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval) = 0;

  /* nsISimpleEnumerator getXULWindowEnumerator (in wstring aWindowType); */
  NS_IMETHOD GetXULWindowEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval) = 0;

  /* nsISimpleEnumerator getZOrderDOMWindowEnumerator (in wstring aWindowType, in boolean aFrontToBack); */
  NS_IMETHOD GetZOrderDOMWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval) = 0;

  /* nsISimpleEnumerator getZOrderXULWindowEnumerator (in wstring aWindowType, in boolean aFrontToBack); */
  NS_IMETHOD GetZOrderXULWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval) = 0;

  /* nsIDOMWindow getMostRecentWindow (in wstring aWindowType); */
  NS_IMETHOD GetMostRecentWindow(const PRUnichar * aWindowType, nsIDOMWindow * *_retval) = 0;

  /* [noscript] void registerWindow (in nsIXULWindow aWindow); */
  NS_IMETHOD RegisterWindow(nsIXULWindow *aWindow) = 0;

  /* [noscript] void unregisterWindow (in nsIXULWindow aWindow); */
  NS_IMETHOD UnregisterWindow(nsIXULWindow *aWindow) = 0;

  /* [noscript] void updateWindowTimeStamp (in nsIXULWindow aWindow); */
  NS_IMETHOD UpdateWindowTimeStamp(nsIXULWindow *aWindow) = 0;

  /* [noscript] void updateWindowTitle (in nsIXULWindow aWindow, in wstring inTitle); */
  NS_IMETHOD UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar * inTitle) = 0;

  enum {
    zLevelTop = 1U,
    zLevelBottom = 2U,
    zLevelBelow = 3U
  };

  /* [noscript] boolean calculateZPosition (in nsIXULWindow inWindow, in unsigned long inPosition, in nsIWidget inBelow, out unsigned long outPosition, out nsIWidget outBelow); */
  NS_IMETHOD CalculateZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIWidget *inBelow, uint32_t *outPosition, nsIWidget * *outBelow, bool *_retval) = 0;

  /* [noscript] void setZPosition (in nsIXULWindow inWindow, in unsigned long inPosition, in nsIXULWindow inBelow); */
  NS_IMETHOD SetZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIXULWindow *inBelow) = 0;

  /* [noscript] uint32_t getZLevel (in nsIXULWindow aWindow); */
  NS_IMETHOD GetZLevel(nsIXULWindow *aWindow, uint32_t *_retval) = 0;

  /* [noscript] void setZLevel (in nsIXULWindow aWindow, in uint32_t aZLevel); */
  NS_IMETHOD SetZLevel(nsIXULWindow *aWindow, uint32_t aZLevel) = 0;

  /* void addListener (in nsIWindowMediatorListener aListener); */
  NS_IMETHOD AddListener(nsIWindowMediatorListener *aListener) = 0;

  /* void removeListener (in nsIWindowMediatorListener aListener); */
  NS_IMETHOD RemoveListener(nsIWindowMediatorListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowMediator, NS_IWINDOWMEDIATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWMEDIATOR \
  NS_IMETHOD GetEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD GetXULWindowEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD GetZOrderDOMWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD GetZOrderXULWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD GetMostRecentWindow(const PRUnichar * aWindowType, nsIDOMWindow * *_retval); \
  NS_IMETHOD RegisterWindow(nsIXULWindow *aWindow); \
  NS_IMETHOD UnregisterWindow(nsIXULWindow *aWindow); \
  NS_IMETHOD UpdateWindowTimeStamp(nsIXULWindow *aWindow); \
  NS_IMETHOD UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar * inTitle); \
  NS_IMETHOD CalculateZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIWidget *inBelow, uint32_t *outPosition, nsIWidget * *outBelow, bool *_retval); \
  NS_IMETHOD SetZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIXULWindow *inBelow); \
  NS_IMETHOD GetZLevel(nsIXULWindow *aWindow, uint32_t *_retval); \
  NS_IMETHOD SetZLevel(nsIXULWindow *aWindow, uint32_t aZLevel); \
  NS_IMETHOD AddListener(nsIWindowMediatorListener *aListener); \
  NS_IMETHOD RemoveListener(nsIWindowMediatorListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWMEDIATOR(_to) \
  NS_IMETHOD GetEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval) { return _to GetEnumerator(aWindowType, _retval); } \
  NS_IMETHOD GetXULWindowEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval) { return _to GetXULWindowEnumerator(aWindowType, _retval); } \
  NS_IMETHOD GetZOrderDOMWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval) { return _to GetZOrderDOMWindowEnumerator(aWindowType, aFrontToBack, _retval); } \
  NS_IMETHOD GetZOrderXULWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval) { return _to GetZOrderXULWindowEnumerator(aWindowType, aFrontToBack, _retval); } \
  NS_IMETHOD GetMostRecentWindow(const PRUnichar * aWindowType, nsIDOMWindow * *_retval) { return _to GetMostRecentWindow(aWindowType, _retval); } \
  NS_IMETHOD RegisterWindow(nsIXULWindow *aWindow) { return _to RegisterWindow(aWindow); } \
  NS_IMETHOD UnregisterWindow(nsIXULWindow *aWindow) { return _to UnregisterWindow(aWindow); } \
  NS_IMETHOD UpdateWindowTimeStamp(nsIXULWindow *aWindow) { return _to UpdateWindowTimeStamp(aWindow); } \
  NS_IMETHOD UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar * inTitle) { return _to UpdateWindowTitle(aWindow, inTitle); } \
  NS_IMETHOD CalculateZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIWidget *inBelow, uint32_t *outPosition, nsIWidget * *outBelow, bool *_retval) { return _to CalculateZPosition(inWindow, inPosition, inBelow, outPosition, outBelow, _retval); } \
  NS_IMETHOD SetZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIXULWindow *inBelow) { return _to SetZPosition(inWindow, inPosition, inBelow); } \
  NS_IMETHOD GetZLevel(nsIXULWindow *aWindow, uint32_t *_retval) { return _to GetZLevel(aWindow, _retval); } \
  NS_IMETHOD SetZLevel(nsIXULWindow *aWindow, uint32_t aZLevel) { return _to SetZLevel(aWindow, aZLevel); } \
  NS_IMETHOD AddListener(nsIWindowMediatorListener *aListener) { return _to AddListener(aListener); } \
  NS_IMETHOD RemoveListener(nsIWindowMediatorListener *aListener) { return _to RemoveListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWMEDIATOR(_to) \
  NS_IMETHOD GetEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(aWindowType, _retval); } \
  NS_IMETHOD GetXULWindowEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXULWindowEnumerator(aWindowType, _retval); } \
  NS_IMETHOD GetZOrderDOMWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZOrderDOMWindowEnumerator(aWindowType, aFrontToBack, _retval); } \
  NS_IMETHOD GetZOrderXULWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZOrderXULWindowEnumerator(aWindowType, aFrontToBack, _retval); } \
  NS_IMETHOD GetMostRecentWindow(const PRUnichar * aWindowType, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMostRecentWindow(aWindowType, _retval); } \
  NS_IMETHOD RegisterWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterWindow(aWindow); } \
  NS_IMETHOD UnregisterWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterWindow(aWindow); } \
  NS_IMETHOD UpdateWindowTimeStamp(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateWindowTimeStamp(aWindow); } \
  NS_IMETHOD UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar * inTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateWindowTitle(aWindow, inTitle); } \
  NS_IMETHOD CalculateZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIWidget *inBelow, uint32_t *outPosition, nsIWidget * *outBelow, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CalculateZPosition(inWindow, inPosition, inBelow, outPosition, outBelow, _retval); } \
  NS_IMETHOD SetZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIXULWindow *inBelow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZPosition(inWindow, inPosition, inBelow); } \
  NS_IMETHOD GetZLevel(nsIXULWindow *aWindow, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZLevel(aWindow, _retval); } \
  NS_IMETHOD SetZLevel(nsIXULWindow *aWindow, uint32_t aZLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZLevel(aWindow, aZLevel); } \
  NS_IMETHOD AddListener(nsIWindowMediatorListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_IMETHOD RemoveListener(nsIWindowMediatorListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowMediator : public nsIWindowMediator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWMEDIATOR

  nsWindowMediator();

private:
  ~nsWindowMediator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowMediator, nsIWindowMediator)

nsWindowMediator::nsWindowMediator()
{
  /* member initializers and constructor code */
}

nsWindowMediator::~nsWindowMediator()
{
  /* destructor code */
}

/* nsISimpleEnumerator getEnumerator (in wstring aWindowType); */
NS_IMETHODIMP nsWindowMediator::GetEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getXULWindowEnumerator (in wstring aWindowType); */
NS_IMETHODIMP nsWindowMediator::GetXULWindowEnumerator(const PRUnichar * aWindowType, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getZOrderDOMWindowEnumerator (in wstring aWindowType, in boolean aFrontToBack); */
NS_IMETHODIMP nsWindowMediator::GetZOrderDOMWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getZOrderXULWindowEnumerator (in wstring aWindowType, in boolean aFrontToBack); */
NS_IMETHODIMP nsWindowMediator::GetZOrderXULWindowEnumerator(const PRUnichar * aWindowType, bool aFrontToBack, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow getMostRecentWindow (in wstring aWindowType); */
NS_IMETHODIMP nsWindowMediator::GetMostRecentWindow(const PRUnichar * aWindowType, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void registerWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsWindowMediator::RegisterWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void unregisterWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsWindowMediator::UnregisterWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void updateWindowTimeStamp (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsWindowMediator::UpdateWindowTimeStamp(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void updateWindowTitle (in nsIXULWindow aWindow, in wstring inTitle); */
NS_IMETHODIMP nsWindowMediator::UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar * inTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean calculateZPosition (in nsIXULWindow inWindow, in unsigned long inPosition, in nsIWidget inBelow, out unsigned long outPosition, out nsIWidget outBelow); */
NS_IMETHODIMP nsWindowMediator::CalculateZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIWidget *inBelow, uint32_t *outPosition, nsIWidget * *outBelow, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setZPosition (in nsIXULWindow inWindow, in unsigned long inPosition, in nsIXULWindow inBelow); */
NS_IMETHODIMP nsWindowMediator::SetZPosition(nsIXULWindow *inWindow, uint32_t inPosition, nsIXULWindow *inBelow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] uint32_t getZLevel (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsWindowMediator::GetZLevel(nsIXULWindow *aWindow, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setZLevel (in nsIXULWindow aWindow, in uint32_t aZLevel); */
NS_IMETHODIMP nsWindowMediator::SetZLevel(nsIXULWindow *aWindow, uint32_t aZLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListener (in nsIWindowMediatorListener aListener); */
NS_IMETHODIMP nsWindowMediator::AddListener(nsIWindowMediatorListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIWindowMediatorListener aListener); */
NS_IMETHODIMP nsWindowMediator::RemoveListener(nsIWindowMediatorListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowMediator_h__ */
