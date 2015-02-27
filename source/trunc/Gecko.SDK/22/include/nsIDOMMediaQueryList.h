/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIDOMMediaQueryList.idl
 */

#ifndef __gen_nsIDOMMediaQueryList_h__
#define __gen_nsIDOMMediaQueryList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMediaQueryListListener; /* forward declaration */


/* starting interface:    nsIDOMMediaQueryList */
#define NS_IDOMMEDIAQUERYLIST_IID_STR "e0e49c52-915b-40f9-9cba-6026305cdf3e"

#define NS_IDOMMEDIAQUERYLIST_IID \
  {0xe0e49c52, 0x915b, 0x40f9, \
    { 0x9c, 0xba, 0x60, 0x26, 0x30, 0x5c, 0xdf, 0x3e }}

class NS_NO_VTABLE nsIDOMMediaQueryList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMEDIAQUERYLIST_IID)

  /* readonly attribute DOMString media; */
  NS_IMETHOD GetMedia(nsAString & aMedia) = 0;

  /* readonly attribute boolean matches; */
  NS_IMETHOD GetMatches(bool *aMatches) = 0;

  /* void addListener (in nsIDOMMediaQueryListListener listener); */
  NS_IMETHOD AddListener(nsIDOMMediaQueryListListener *listener) = 0;

  /* void removeListener (in nsIDOMMediaQueryListListener listener); */
  NS_IMETHOD RemoveListener(nsIDOMMediaQueryListListener *listener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMediaQueryList, NS_IDOMMEDIAQUERYLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMEDIAQUERYLIST \
  NS_IMETHOD GetMedia(nsAString & aMedia); \
  NS_IMETHOD GetMatches(bool *aMatches); \
  NS_IMETHOD AddListener(nsIDOMMediaQueryListListener *listener); \
  NS_IMETHOD RemoveListener(nsIDOMMediaQueryListListener *listener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMEDIAQUERYLIST(_to) \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return _to GetMedia(aMedia); } \
  NS_IMETHOD GetMatches(bool *aMatches) { return _to GetMatches(aMatches); } \
  NS_IMETHOD AddListener(nsIDOMMediaQueryListListener *listener) { return _to AddListener(listener); } \
  NS_IMETHOD RemoveListener(nsIDOMMediaQueryListListener *listener) { return _to RemoveListener(listener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMEDIAQUERYLIST(_to) \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_IMETHOD GetMatches(bool *aMatches) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatches(aMatches); } \
  NS_IMETHOD AddListener(nsIDOMMediaQueryListListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(listener); } \
  NS_IMETHOD RemoveListener(nsIDOMMediaQueryListListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(listener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMediaQueryList : public nsIDOMMediaQueryList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMEDIAQUERYLIST

  nsDOMMediaQueryList();

private:
  ~nsDOMMediaQueryList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMediaQueryList, nsIDOMMediaQueryList)

nsDOMMediaQueryList::nsDOMMediaQueryList()
{
  /* member initializers and constructor code */
}

nsDOMMediaQueryList::~nsDOMMediaQueryList()
{
  /* destructor code */
}

/* readonly attribute DOMString media; */
NS_IMETHODIMP nsDOMMediaQueryList::GetMedia(nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean matches; */
NS_IMETHODIMP nsDOMMediaQueryList::GetMatches(bool *aMatches)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListener (in nsIDOMMediaQueryListListener listener); */
NS_IMETHODIMP nsDOMMediaQueryList::AddListener(nsIDOMMediaQueryListListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIDOMMediaQueryListListener listener); */
NS_IMETHODIMP nsDOMMediaQueryList::RemoveListener(nsIDOMMediaQueryListListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMMediaQueryListListener */
#define NS_IDOMMEDIAQUERYLISTLISTENER_IID_STR "279a5cbd-5c15-475d-847b-e0de1624eb77"

#define NS_IDOMMEDIAQUERYLISTLISTENER_IID \
  {0x279a5cbd, 0x5c15, 0x475d, \
    { 0x84, 0x7b, 0xe0, 0xde, 0x16, 0x24, 0xeb, 0x77 }}

class NS_NO_VTABLE nsIDOMMediaQueryListListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMEDIAQUERYLISTLISTENER_IID)

  /* void handleChange (in nsIDOMMediaQueryList mql); */
  NS_IMETHOD HandleChange(nsIDOMMediaQueryList *mql) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMediaQueryListListener, NS_IDOMMEDIAQUERYLISTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMEDIAQUERYLISTLISTENER \
  NS_IMETHOD HandleChange(nsIDOMMediaQueryList *mql); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMEDIAQUERYLISTLISTENER(_to) \
  NS_IMETHOD HandleChange(nsIDOMMediaQueryList *mql) { return _to HandleChange(mql); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMEDIAQUERYLISTLISTENER(_to) \
  NS_IMETHOD HandleChange(nsIDOMMediaQueryList *mql) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleChange(mql); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMediaQueryListListener : public nsIDOMMediaQueryListListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMEDIAQUERYLISTLISTENER

  nsDOMMediaQueryListListener();

private:
  ~nsDOMMediaQueryListListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMediaQueryListListener, nsIDOMMediaQueryListListener)

nsDOMMediaQueryListListener::nsDOMMediaQueryListListener()
{
  /* member initializers and constructor code */
}

nsDOMMediaQueryListListener::~nsDOMMediaQueryListListener()
{
  /* destructor code */
}

/* void handleChange (in nsIDOMMediaQueryList mql); */
NS_IMETHODIMP nsDOMMediaQueryListListener::HandleChange(nsIDOMMediaQueryList *mql)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMediaQueryList_h__ */
