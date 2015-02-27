/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsIQueryContentEventResult.idl
 */

#ifndef __gen_nsIQueryContentEventResult_h__
#define __gen_nsIQueryContentEventResult_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIQueryContentEventResult */
#define NS_IQUERYCONTENTEVENTRESULT_IID_STR "4b4ba266-b51e-4f0f-8d0e-9f13cb2a0056"

#define NS_IQUERYCONTENTEVENTRESULT_IID \
  {0x4b4ba266, 0xb51e, 0x4f0f, \
    { 0x8d, 0x0e, 0x9f, 0x13, 0xcb, 0x2a, 0x00, 0x56 }}

/**
 * The result of query content events.  succeeded propery can be used always.
 * Whether other properties can be used or not depends on the event.
 * See nsIDOMWindowUtils.idl, which properites can be used was documented.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIQueryContentEventResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IQUERYCONTENTEVENTRESULT_IID)

  /* readonly attribute unsigned long offset; */
  NS_SCRIPTABLE NS_IMETHOD GetOffset(PRUint32 *aOffset) = 0;

  /* readonly attribute boolean reversed; */
  NS_SCRIPTABLE NS_IMETHOD GetReversed(PRBool *aReversed) = 0;

  /* readonly attribute long left; */
  NS_SCRIPTABLE NS_IMETHOD GetLeft(PRInt32 *aLeft) = 0;

  /* readonly attribute long top; */
  NS_SCRIPTABLE NS_IMETHOD GetTop(PRInt32 *aTop) = 0;

  /* readonly attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /* readonly attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;

  /* readonly attribute AString text; */
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) = 0;

  /* readonly attribute boolean succeeded; */
  NS_SCRIPTABLE NS_IMETHOD GetSucceeded(PRBool *aSucceeded) = 0;

  /* readonly attribute boolean notFound; */
  NS_SCRIPTABLE NS_IMETHOD GetNotFound(PRBool *aNotFound) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIQueryContentEventResult, NS_IQUERYCONTENTEVENTRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIQUERYCONTENTEVENTRESULT \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(PRUint32 *aOffset); \
  NS_SCRIPTABLE NS_IMETHOD GetReversed(PRBool *aReversed); \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(PRInt32 *aLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetTop(PRInt32 *aTop); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText); \
  NS_SCRIPTABLE NS_IMETHOD GetSucceeded(PRBool *aSucceeded); \
  NS_SCRIPTABLE NS_IMETHOD GetNotFound(PRBool *aNotFound); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIQUERYCONTENTEVENTRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(PRUint32 *aOffset) { return _to GetOffset(aOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetReversed(PRBool *aReversed) { return _to GetReversed(aReversed); } \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(PRInt32 *aLeft) { return _to GetLeft(aLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetTop(PRInt32 *aTop) { return _to GetTop(aTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD GetSucceeded(PRBool *aSucceeded) { return _to GetSucceeded(aSucceeded); } \
  NS_SCRIPTABLE NS_IMETHOD GetNotFound(PRBool *aNotFound) { return _to GetNotFound(aNotFound); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIQUERYCONTENTEVENTRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(PRUint32 *aOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffset(aOffset); } \
  NS_SCRIPTABLE NS_IMETHOD GetReversed(PRBool *aReversed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReversed(aReversed); } \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(PRInt32 *aLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLeft(aLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetTop(PRInt32 *aTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTop(aTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD GetSucceeded(PRBool *aSucceeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSucceeded(aSucceeded); } \
  NS_SCRIPTABLE NS_IMETHOD GetNotFound(PRBool *aNotFound) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotFound(aNotFound); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsQueryContentEventResult : public nsIQueryContentEventResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIQUERYCONTENTEVENTRESULT

  nsQueryContentEventResult();

private:
  ~nsQueryContentEventResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsQueryContentEventResult, nsIQueryContentEventResult)

nsQueryContentEventResult::nsQueryContentEventResult()
{
  /* member initializers and constructor code */
}

nsQueryContentEventResult::~nsQueryContentEventResult()
{
  /* destructor code */
}

/* readonly attribute unsigned long offset; */
NS_IMETHODIMP nsQueryContentEventResult::GetOffset(PRUint32 *aOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean reversed; */
NS_IMETHODIMP nsQueryContentEventResult::GetReversed(PRBool *aReversed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long left; */
NS_IMETHODIMP nsQueryContentEventResult::GetLeft(PRInt32 *aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long top; */
NS_IMETHODIMP nsQueryContentEventResult::GetTop(PRInt32 *aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsQueryContentEventResult::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsQueryContentEventResult::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString text; */
NS_IMETHODIMP nsQueryContentEventResult::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean succeeded; */
NS_IMETHODIMP nsQueryContentEventResult::GetSucceeded(PRBool *aSucceeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean notFound; */
NS_IMETHODIMP nsQueryContentEventResult::GetNotFound(PRBool *aNotFound)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIQueryContentEventResult_h__ */
