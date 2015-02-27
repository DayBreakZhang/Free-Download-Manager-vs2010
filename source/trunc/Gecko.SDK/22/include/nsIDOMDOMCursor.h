/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/base/nsIDOMDOMCursor.idl
 */

#ifndef __gen_nsIDOMDOMCursor_h__
#define __gen_nsIDOMDOMCursor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICursorContinueCallback */
#define NS_ICURSORCONTINUECALLBACK_IID_STR "3a75d80a-9258-4ab8-95fd-ec0b5f634df1"

#define NS_ICURSORCONTINUECALLBACK_IID \
  {0x3a75d80a, 0x9258, 0x4ab8, \
    { 0x95, 0xfd, 0xec, 0x0b, 0x5f, 0x63, 0x4d, 0xf1 }}

class NS_NO_VTABLE nsICursorContinueCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICURSORCONTINUECALLBACK_IID)

  /* void handleContinue (); */
  NS_IMETHOD HandleContinue(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICursorContinueCallback, NS_ICURSORCONTINUECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICURSORCONTINUECALLBACK \
  NS_IMETHOD HandleContinue(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICURSORCONTINUECALLBACK(_to) \
  NS_IMETHOD HandleContinue(void) { return _to HandleContinue(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICURSORCONTINUECALLBACK(_to) \
  NS_IMETHOD HandleContinue(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleContinue(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCursorContinueCallback : public nsICursorContinueCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICURSORCONTINUECALLBACK

  nsCursorContinueCallback();

private:
  ~nsCursorContinueCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCursorContinueCallback, nsICursorContinueCallback)

nsCursorContinueCallback::nsCursorContinueCallback()
{
  /* member initializers and constructor code */
}

nsCursorContinueCallback::~nsCursorContinueCallback()
{
  /* destructor code */
}

/* void handleContinue (); */
NS_IMETHODIMP nsCursorContinueCallback::HandleContinue()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMDOMCursor */
#define NS_IDOMDOMCURSOR_IID_STR "062ea35a-5158-425a-b7bc-3ae9daa84398"

#define NS_IDOMDOMCURSOR_IID \
  {0x062ea35a, 0x5158, 0x425a, \
    { 0xb7, 0xbc, 0x3a, 0xe9, 0xda, 0xa8, 0x43, 0x98 }}

class NS_NO_VTABLE nsIDOMDOMCursor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMCURSOR_IID)

  /* readonly attribute boolean done; */
  NS_IMETHOD GetDone(bool *aDone) = 0;

  /* void continue (); */
  NS_IMETHOD Continue(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMCursor, NS_IDOMDOMCURSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMCURSOR \
  NS_IMETHOD GetDone(bool *aDone); \
  NS_IMETHOD Continue(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMCURSOR(_to) \
  NS_IMETHOD GetDone(bool *aDone) { return _to GetDone(aDone); } \
  NS_IMETHOD Continue(void) { return _to Continue(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMCURSOR(_to) \
  NS_IMETHOD GetDone(bool *aDone) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDone(aDone); } \
  NS_IMETHOD Continue(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Continue(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMCursor : public nsIDOMDOMCursor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMCURSOR

  nsDOMDOMCursor();

private:
  ~nsDOMDOMCursor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMCursor, nsIDOMDOMCursor)

nsDOMDOMCursor::nsDOMDOMCursor()
{
  /* member initializers and constructor code */
}

nsDOMDOMCursor::~nsDOMDOMCursor()
{
  /* destructor code */
}

/* readonly attribute boolean done; */
NS_IMETHODIMP nsDOMDOMCursor::GetDone(bool *aDone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void continue (); */
NS_IMETHODIMP nsDOMDOMCursor::Continue()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMCursor_h__ */
