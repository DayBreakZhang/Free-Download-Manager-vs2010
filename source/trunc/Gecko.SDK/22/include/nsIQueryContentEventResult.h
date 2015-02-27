/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIQueryContentEventResult.idl
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

class NS_NO_VTABLE nsIQueryContentEventResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IQUERYCONTENTEVENTRESULT_IID)

  /* readonly attribute unsigned long offset; */
  NS_IMETHOD GetOffset(uint32_t *aOffset) = 0;

  /* readonly attribute boolean reversed; */
  NS_IMETHOD GetReversed(bool *aReversed) = 0;

  /* readonly attribute long left; */
  NS_IMETHOD GetLeft(int32_t *aLeft) = 0;

  /* readonly attribute long top; */
  NS_IMETHOD GetTop(int32_t *aTop) = 0;

  /* readonly attribute long width; */
  NS_IMETHOD GetWidth(int32_t *aWidth) = 0;

  /* readonly attribute long height; */
  NS_IMETHOD GetHeight(int32_t *aHeight) = 0;

  /* readonly attribute AString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;

  /* readonly attribute boolean succeeded; */
  NS_IMETHOD GetSucceeded(bool *aSucceeded) = 0;

  /* readonly attribute boolean notFound; */
  NS_IMETHOD GetNotFound(bool *aNotFound) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIQueryContentEventResult, NS_IQUERYCONTENTEVENTRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIQUERYCONTENTEVENTRESULT \
  NS_IMETHOD GetOffset(uint32_t *aOffset); \
  NS_IMETHOD GetReversed(bool *aReversed); \
  NS_IMETHOD GetLeft(int32_t *aLeft); \
  NS_IMETHOD GetTop(int32_t *aTop); \
  NS_IMETHOD GetWidth(int32_t *aWidth); \
  NS_IMETHOD GetHeight(int32_t *aHeight); \
  NS_IMETHOD GetText(nsAString & aText); \
  NS_IMETHOD GetSucceeded(bool *aSucceeded); \
  NS_IMETHOD GetNotFound(bool *aNotFound); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIQUERYCONTENTEVENTRESULT(_to) \
  NS_IMETHOD GetOffset(uint32_t *aOffset) { return _to GetOffset(aOffset); } \
  NS_IMETHOD GetReversed(bool *aReversed) { return _to GetReversed(aReversed); } \
  NS_IMETHOD GetLeft(int32_t *aLeft) { return _to GetLeft(aLeft); } \
  NS_IMETHOD GetTop(int32_t *aTop) { return _to GetTop(aTop); } \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_IMETHOD GetSucceeded(bool *aSucceeded) { return _to GetSucceeded(aSucceeded); } \
  NS_IMETHOD GetNotFound(bool *aNotFound) { return _to GetNotFound(aNotFound); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIQUERYCONTENTEVENTRESULT(_to) \
  NS_IMETHOD GetOffset(uint32_t *aOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffset(aOffset); } \
  NS_IMETHOD GetReversed(bool *aReversed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReversed(aReversed); } \
  NS_IMETHOD GetLeft(int32_t *aLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLeft(aLeft); } \
  NS_IMETHOD GetTop(int32_t *aTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTop(aTop); } \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD GetSucceeded(bool *aSucceeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSucceeded(aSucceeded); } \
  NS_IMETHOD GetNotFound(bool *aNotFound) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotFound(aNotFound); } 

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
NS_IMETHODIMP nsQueryContentEventResult::GetOffset(uint32_t *aOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean reversed; */
NS_IMETHODIMP nsQueryContentEventResult::GetReversed(bool *aReversed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long left; */
NS_IMETHODIMP nsQueryContentEventResult::GetLeft(int32_t *aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long top; */
NS_IMETHODIMP nsQueryContentEventResult::GetTop(int32_t *aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsQueryContentEventResult::GetWidth(int32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsQueryContentEventResult::GetHeight(int32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString text; */
NS_IMETHODIMP nsQueryContentEventResult::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean succeeded; */
NS_IMETHODIMP nsQueryContentEventResult::GetSucceeded(bool *aSucceeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean notFound; */
NS_IMETHODIMP nsQueryContentEventResult::GetNotFound(bool *aNotFound)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIQueryContentEventResult_h__ */
