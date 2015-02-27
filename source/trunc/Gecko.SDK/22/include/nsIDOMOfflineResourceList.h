/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/offline/nsIDOMOfflineResourceList.idl
 */

#ifndef __gen_nsIDOMOfflineResourceList_h__
#define __gen_nsIDOMOfflineResourceList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMStringList; /* forward declaration */


/* starting interface:    nsIDOMOfflineResourceList */
#define NS_IDOMOFFLINERESOURCELIST_IID_STR "c105fe6f-5603-40b2-b3d0-84cb51fab9f4"

#define NS_IDOMOFFLINERESOURCELIST_IID \
  {0xc105fe6f, 0x5603, 0x40b2, \
    { 0xb3, 0xd0, 0x84, 0xcb, 0x51, 0xfa, 0xb9, 0xf4 }}

class NS_NO_VTABLE nsIDOMOfflineResourceList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMOFFLINERESOURCELIST_IID)

  /* readonly attribute nsIDOMDOMStringList mozItems; */
  NS_IMETHOD GetMozItems(nsIDOMDOMStringList * *aMozItems) = 0;

  /* boolean mozHasItem (in DOMString uri); */
  NS_IMETHOD MozHasItem(const nsAString & uri, bool *_retval) = 0;

  /* readonly attribute unsigned long mozLength; */
  NS_IMETHOD GetMozLength(uint32_t *aMozLength) = 0;

  /* DOMString mozItem (in unsigned long index); */
  NS_IMETHOD MozItem(uint32_t index, nsAString & _retval) = 0;

  /* void mozAdd (in DOMString uri); */
  NS_IMETHOD MozAdd(const nsAString & uri) = 0;

  /* void mozRemove (in DOMString uri); */
  NS_IMETHOD MozRemove(const nsAString & uri) = 0;

  enum {
    UNCACHED = 0U,
    IDLE = 1U,
    CHECKING = 2U,
    DOWNLOADING = 3U,
    UPDATEREADY = 4U,
    OBSOLETE = 5U
  };

  /* readonly attribute unsigned short status; */
  NS_IMETHOD GetStatus(uint16_t *aStatus) = 0;

  /* void update (); */
  NS_IMETHOD Update(void) = 0;

  /* void swapCache (); */
  NS_IMETHOD SwapCache(void) = 0;

  /* [implicit_jscontext] attribute jsval onchecking; */
  NS_IMETHOD GetOnchecking(JSContext* cx, JS::Value *aOnchecking) = 0;
  NS_IMETHOD SetOnchecking(JSContext* cx, const JS::Value & aOnchecking) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

  /* [implicit_jscontext] attribute jsval onnoupdate; */
  NS_IMETHOD GetOnnoupdate(JSContext* cx, JS::Value *aOnnoupdate) = 0;
  NS_IMETHOD SetOnnoupdate(JSContext* cx, const JS::Value & aOnnoupdate) = 0;

  /* [implicit_jscontext] attribute jsval ondownloading; */
  NS_IMETHOD GetOndownloading(JSContext* cx, JS::Value *aOndownloading) = 0;
  NS_IMETHOD SetOndownloading(JSContext* cx, const JS::Value & aOndownloading) = 0;

  /* [implicit_jscontext] attribute jsval onprogress; */
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) = 0;
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) = 0;

  /* [implicit_jscontext] attribute jsval onupdateready; */
  NS_IMETHOD GetOnupdateready(JSContext* cx, JS::Value *aOnupdateready) = 0;
  NS_IMETHOD SetOnupdateready(JSContext* cx, const JS::Value & aOnupdateready) = 0;

  /* [implicit_jscontext] attribute jsval oncached; */
  NS_IMETHOD GetOncached(JSContext* cx, JS::Value *aOncached) = 0;
  NS_IMETHOD SetOncached(JSContext* cx, const JS::Value & aOncached) = 0;

  /* [implicit_jscontext] attribute jsval onobsolete; */
  NS_IMETHOD GetOnobsolete(JSContext* cx, JS::Value *aOnobsolete) = 0;
  NS_IMETHOD SetOnobsolete(JSContext* cx, const JS::Value & aOnobsolete) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMOfflineResourceList, NS_IDOMOFFLINERESOURCELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMOFFLINERESOURCELIST \
  NS_IMETHOD GetMozItems(nsIDOMDOMStringList * *aMozItems); \
  NS_IMETHOD MozHasItem(const nsAString & uri, bool *_retval); \
  NS_IMETHOD GetMozLength(uint32_t *aMozLength); \
  NS_IMETHOD MozItem(uint32_t index, nsAString & _retval); \
  NS_IMETHOD MozAdd(const nsAString & uri); \
  NS_IMETHOD MozRemove(const nsAString & uri); \
  NS_IMETHOD GetStatus(uint16_t *aStatus); \
  NS_IMETHOD Update(void); \
  NS_IMETHOD SwapCache(void); \
  NS_IMETHOD GetOnchecking(JSContext* cx, JS::Value *aOnchecking); \
  NS_IMETHOD SetOnchecking(JSContext* cx, const JS::Value & aOnchecking); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); \
  NS_IMETHOD GetOnnoupdate(JSContext* cx, JS::Value *aOnnoupdate); \
  NS_IMETHOD SetOnnoupdate(JSContext* cx, const JS::Value & aOnnoupdate); \
  NS_IMETHOD GetOndownloading(JSContext* cx, JS::Value *aOndownloading); \
  NS_IMETHOD SetOndownloading(JSContext* cx, const JS::Value & aOndownloading); \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress); \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress); \
  NS_IMETHOD GetOnupdateready(JSContext* cx, JS::Value *aOnupdateready); \
  NS_IMETHOD SetOnupdateready(JSContext* cx, const JS::Value & aOnupdateready); \
  NS_IMETHOD GetOncached(JSContext* cx, JS::Value *aOncached); \
  NS_IMETHOD SetOncached(JSContext* cx, const JS::Value & aOncached); \
  NS_IMETHOD GetOnobsolete(JSContext* cx, JS::Value *aOnobsolete); \
  NS_IMETHOD SetOnobsolete(JSContext* cx, const JS::Value & aOnobsolete); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMOFFLINERESOURCELIST(_to) \
  NS_IMETHOD GetMozItems(nsIDOMDOMStringList * *aMozItems) { return _to GetMozItems(aMozItems); } \
  NS_IMETHOD MozHasItem(const nsAString & uri, bool *_retval) { return _to MozHasItem(uri, _retval); } \
  NS_IMETHOD GetMozLength(uint32_t *aMozLength) { return _to GetMozLength(aMozLength); } \
  NS_IMETHOD MozItem(uint32_t index, nsAString & _retval) { return _to MozItem(index, _retval); } \
  NS_IMETHOD MozAdd(const nsAString & uri) { return _to MozAdd(uri); } \
  NS_IMETHOD MozRemove(const nsAString & uri) { return _to MozRemove(uri); } \
  NS_IMETHOD GetStatus(uint16_t *aStatus) { return _to GetStatus(aStatus); } \
  NS_IMETHOD Update(void) { return _to Update(); } \
  NS_IMETHOD SwapCache(void) { return _to SwapCache(); } \
  NS_IMETHOD GetOnchecking(JSContext* cx, JS::Value *aOnchecking) { return _to GetOnchecking(cx, aOnchecking); } \
  NS_IMETHOD SetOnchecking(JSContext* cx, const JS::Value & aOnchecking) { return _to SetOnchecking(cx, aOnchecking); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnnoupdate(JSContext* cx, JS::Value *aOnnoupdate) { return _to GetOnnoupdate(cx, aOnnoupdate); } \
  NS_IMETHOD SetOnnoupdate(JSContext* cx, const JS::Value & aOnnoupdate) { return _to SetOnnoupdate(cx, aOnnoupdate); } \
  NS_IMETHOD GetOndownloading(JSContext* cx, JS::Value *aOndownloading) { return _to GetOndownloading(cx, aOndownloading); } \
  NS_IMETHOD SetOndownloading(JSContext* cx, const JS::Value & aOndownloading) { return _to SetOndownloading(cx, aOndownloading); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) { return _to GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) { return _to SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnupdateready(JSContext* cx, JS::Value *aOnupdateready) { return _to GetOnupdateready(cx, aOnupdateready); } \
  NS_IMETHOD SetOnupdateready(JSContext* cx, const JS::Value & aOnupdateready) { return _to SetOnupdateready(cx, aOnupdateready); } \
  NS_IMETHOD GetOncached(JSContext* cx, JS::Value *aOncached) { return _to GetOncached(cx, aOncached); } \
  NS_IMETHOD SetOncached(JSContext* cx, const JS::Value & aOncached) { return _to SetOncached(cx, aOncached); } \
  NS_IMETHOD GetOnobsolete(JSContext* cx, JS::Value *aOnobsolete) { return _to GetOnobsolete(cx, aOnobsolete); } \
  NS_IMETHOD SetOnobsolete(JSContext* cx, const JS::Value & aOnobsolete) { return _to SetOnobsolete(cx, aOnobsolete); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMOFFLINERESOURCELIST(_to) \
  NS_IMETHOD GetMozItems(nsIDOMDOMStringList * *aMozItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozItems(aMozItems); } \
  NS_IMETHOD MozHasItem(const nsAString & uri, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozHasItem(uri, _retval); } \
  NS_IMETHOD GetMozLength(uint32_t *aMozLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozLength(aMozLength); } \
  NS_IMETHOD MozItem(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozItem(index, _retval); } \
  NS_IMETHOD MozAdd(const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozAdd(uri); } \
  NS_IMETHOD MozRemove(const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRemove(uri); } \
  NS_IMETHOD GetStatus(uint16_t *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD Update(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(); } \
  NS_IMETHOD SwapCache(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwapCache(); } \
  NS_IMETHOD GetOnchecking(JSContext* cx, JS::Value *aOnchecking) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchecking(cx, aOnchecking); } \
  NS_IMETHOD SetOnchecking(JSContext* cx, const JS::Value & aOnchecking) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchecking(cx, aOnchecking); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnnoupdate(JSContext* cx, JS::Value *aOnnoupdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnnoupdate(cx, aOnnoupdate); } \
  NS_IMETHOD SetOnnoupdate(JSContext* cx, const JS::Value & aOnnoupdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnnoupdate(cx, aOnnoupdate); } \
  NS_IMETHOD GetOndownloading(JSContext* cx, JS::Value *aOndownloading) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndownloading(cx, aOndownloading); } \
  NS_IMETHOD SetOndownloading(JSContext* cx, const JS::Value & aOndownloading) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndownloading(cx, aOndownloading); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::Value *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, const JS::Value & aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnupdateready(JSContext* cx, JS::Value *aOnupdateready) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnupdateready(cx, aOnupdateready); } \
  NS_IMETHOD SetOnupdateready(JSContext* cx, const JS::Value & aOnupdateready) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnupdateready(cx, aOnupdateready); } \
  NS_IMETHOD GetOncached(JSContext* cx, JS::Value *aOncached) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncached(cx, aOncached); } \
  NS_IMETHOD SetOncached(JSContext* cx, const JS::Value & aOncached) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncached(cx, aOncached); } \
  NS_IMETHOD GetOnobsolete(JSContext* cx, JS::Value *aOnobsolete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnobsolete(cx, aOnobsolete); } \
  NS_IMETHOD SetOnobsolete(JSContext* cx, const JS::Value & aOnobsolete) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnobsolete(cx, aOnobsolete); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMOfflineResourceList : public nsIDOMOfflineResourceList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMOFFLINERESOURCELIST

  nsDOMOfflineResourceList();

private:
  ~nsDOMOfflineResourceList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMOfflineResourceList, nsIDOMOfflineResourceList)

nsDOMOfflineResourceList::nsDOMOfflineResourceList()
{
  /* member initializers and constructor code */
}

nsDOMOfflineResourceList::~nsDOMOfflineResourceList()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDOMStringList mozItems; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetMozItems(nsIDOMDOMStringList * *aMozItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean mozHasItem (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozHasItem(const nsAString & uri, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozLength; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetMozLength(uint32_t *aMozLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString mozItem (in unsigned long index); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozItem(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozAdd (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozAdd(const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozRemove (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozRemove(const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short status; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetStatus(uint16_t *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update (); */
NS_IMETHODIMP nsDOMOfflineResourceList::Update()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void swapCache (); */
NS_IMETHODIMP nsDOMOfflineResourceList::SwapCache()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onchecking; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnchecking(JSContext* cx, JS::Value *aOnchecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnchecking(JSContext* cx, const JS::Value & aOnchecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onnoupdate; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnnoupdate(JSContext* cx, JS::Value *aOnnoupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnnoupdate(JSContext* cx, const JS::Value & aOnnoupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondownloading; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOndownloading(JSContext* cx, JS::Value *aOndownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOndownloading(JSContext* cx, const JS::Value & aOndownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onprogress; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnprogress(JSContext* cx, JS::Value *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnprogress(JSContext* cx, const JS::Value & aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onupdateready; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnupdateready(JSContext* cx, JS::Value *aOnupdateready)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnupdateready(JSContext* cx, const JS::Value & aOnupdateready)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncached; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOncached(JSContext* cx, JS::Value *aOncached)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOncached(JSContext* cx, const JS::Value & aOncached)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onobsolete; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnobsolete(JSContext* cx, JS::Value *aOnobsolete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnobsolete(JSContext* cx, const JS::Value & aOnobsolete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMOfflineResourceList_h__ */
