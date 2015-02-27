/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/browser-element/nsIAsyncScrollEventDetail.idl
 */

#ifndef __gen_nsIAsyncScrollEventDetail_h__
#define __gen_nsIAsyncScrollEventDetail_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAsyncScrollEventDetail */
#define NS_IASYNCSCROLLEVENTDETAIL_IID_STR "d0c13577-31e6-4701-b9b7-3535bbe19fe6"

#define NS_IASYNCSCROLLEVENTDETAIL_IID \
  {0xd0c13577, 0x31e6, 0x4701, \
    { 0xb9, 0xb7, 0x35, 0x35, 0xbb, 0xe1, 0x9f, 0xe6 }}

class NS_NO_VTABLE nsIAsyncScrollEventDetail : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCSCROLLEVENTDETAIL_IID)

  /* readonly attribute float top; */
  NS_IMETHOD GetTop(float *aTop) = 0;

  /* readonly attribute float left; */
  NS_IMETHOD GetLeft(float *aLeft) = 0;

  /* readonly attribute float width; */
  NS_IMETHOD GetWidth(float *aWidth) = 0;

  /* readonly attribute float height; */
  NS_IMETHOD GetHeight(float *aHeight) = 0;

  /* readonly attribute float scrollWidth; */
  NS_IMETHOD GetScrollWidth(float *aScrollWidth) = 0;

  /* readonly attribute float scrollHeight; */
  NS_IMETHOD GetScrollHeight(float *aScrollHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncScrollEventDetail, NS_IASYNCSCROLLEVENTDETAIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCSCROLLEVENTDETAIL \
  NS_IMETHOD GetTop(float *aTop); \
  NS_IMETHOD GetLeft(float *aLeft); \
  NS_IMETHOD GetWidth(float *aWidth); \
  NS_IMETHOD GetHeight(float *aHeight); \
  NS_IMETHOD GetScrollWidth(float *aScrollWidth); \
  NS_IMETHOD GetScrollHeight(float *aScrollHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCSCROLLEVENTDETAIL(_to) \
  NS_IMETHOD GetTop(float *aTop) { return _to GetTop(aTop); } \
  NS_IMETHOD GetLeft(float *aLeft) { return _to GetLeft(aLeft); } \
  NS_IMETHOD GetWidth(float *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(float *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetScrollWidth(float *aScrollWidth) { return _to GetScrollWidth(aScrollWidth); } \
  NS_IMETHOD GetScrollHeight(float *aScrollHeight) { return _to GetScrollHeight(aScrollHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCSCROLLEVENTDETAIL(_to) \
  NS_IMETHOD GetTop(float *aTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTop(aTop); } \
  NS_IMETHOD GetLeft(float *aLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLeft(aLeft); } \
  NS_IMETHOD GetWidth(float *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(float *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetScrollWidth(float *aScrollWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollWidth(aScrollWidth); } \
  NS_IMETHOD GetScrollHeight(float *aScrollHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollHeight(aScrollHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncScrollEventDetail : public nsIAsyncScrollEventDetail
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCSCROLLEVENTDETAIL

  nsAsyncScrollEventDetail();

private:
  ~nsAsyncScrollEventDetail();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAsyncScrollEventDetail, nsIAsyncScrollEventDetail)

nsAsyncScrollEventDetail::nsAsyncScrollEventDetail()
{
  /* member initializers and constructor code */
}

nsAsyncScrollEventDetail::~nsAsyncScrollEventDetail()
{
  /* destructor code */
}

/* readonly attribute float top; */
NS_IMETHODIMP nsAsyncScrollEventDetail::GetTop(float *aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float left; */
NS_IMETHODIMP nsAsyncScrollEventDetail::GetLeft(float *aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float width; */
NS_IMETHODIMP nsAsyncScrollEventDetail::GetWidth(float *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float height; */
NS_IMETHODIMP nsAsyncScrollEventDetail::GetHeight(float *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float scrollWidth; */
NS_IMETHODIMP nsAsyncScrollEventDetail::GetScrollWidth(float *aScrollWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float scrollHeight; */
NS_IMETHODIMP nsAsyncScrollEventDetail::GetScrollHeight(float *aScrollHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAsyncScrollEventDetail_h__ */
