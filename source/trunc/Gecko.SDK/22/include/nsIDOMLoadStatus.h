/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/offline/nsIDOMLoadStatus.idl
 */

#ifndef __gen_nsIDOMLoadStatus_h__
#define __gen_nsIDOMLoadStatus_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMLoadStatus */
#define NS_IDOMLOADSTATUS_IID_STR "2cb53a8a-d2f4-4ddf-874f-3bc2d595c41a"

#define NS_IDOMLOADSTATUS_IID \
  {0x2cb53a8a, 0xd2f4, 0x4ddf, \
    { 0x87, 0x4f, 0x3b, 0xc2, 0xd5, 0x95, 0xc4, 0x1a }}

class NS_NO_VTABLE nsIDOMLoadStatus : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLOADSTATUS_IID)

  /* readonly attribute nsIDOMNode source; */
  NS_IMETHOD GetSource(nsIDOMNode * *aSource) = 0;

  /* readonly attribute DOMString uri; */
  NS_IMETHOD GetUri(nsAString & aUri) = 0;

  /* readonly attribute long totalSize; */
  NS_IMETHOD GetTotalSize(int32_t *aTotalSize) = 0;

  /* readonly attribute long loadedSize; */
  NS_IMETHOD GetLoadedSize(int32_t *aLoadedSize) = 0;

  /* readonly attribute unsigned short readyState; */
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) = 0;

  /* readonly attribute unsigned short status; */
  NS_IMETHOD GetStatus(uint16_t *aStatus) = 0;

  enum {
    UNINITIALIZED = 0U,
    REQUESTED = 1U,
    RECEIVING = 2U,
    LOADED = 3U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLoadStatus, NS_IDOMLOADSTATUS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLOADSTATUS \
  NS_IMETHOD GetSource(nsIDOMNode * *aSource); \
  NS_IMETHOD GetUri(nsAString & aUri); \
  NS_IMETHOD GetTotalSize(int32_t *aTotalSize); \
  NS_IMETHOD GetLoadedSize(int32_t *aLoadedSize); \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState); \
  NS_IMETHOD GetStatus(uint16_t *aStatus); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLOADSTATUS(_to) \
  NS_IMETHOD GetSource(nsIDOMNode * *aSource) { return _to GetSource(aSource); } \
  NS_IMETHOD GetUri(nsAString & aUri) { return _to GetUri(aUri); } \
  NS_IMETHOD GetTotalSize(int32_t *aTotalSize) { return _to GetTotalSize(aTotalSize); } \
  NS_IMETHOD GetLoadedSize(int32_t *aLoadedSize) { return _to GetLoadedSize(aLoadedSize); } \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetStatus(uint16_t *aStatus) { return _to GetStatus(aStatus); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLOADSTATUS(_to) \
  NS_IMETHOD GetSource(nsIDOMNode * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_IMETHOD GetUri(nsAString & aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD GetTotalSize(int32_t *aTotalSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalSize(aTotalSize); } \
  NS_IMETHOD GetLoadedSize(int32_t *aLoadedSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadedSize(aLoadedSize); } \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetStatus(uint16_t *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLoadStatus : public nsIDOMLoadStatus
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLOADSTATUS

  nsDOMLoadStatus();

private:
  ~nsDOMLoadStatus();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLoadStatus, nsIDOMLoadStatus)

nsDOMLoadStatus::nsDOMLoadStatus()
{
  /* member initializers and constructor code */
}

nsDOMLoadStatus::~nsDOMLoadStatus()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode source; */
NS_IMETHODIMP nsDOMLoadStatus::GetSource(nsIDOMNode * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString uri; */
NS_IMETHODIMP nsDOMLoadStatus::GetUri(nsAString & aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long totalSize; */
NS_IMETHODIMP nsDOMLoadStatus::GetTotalSize(int32_t *aTotalSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long loadedSize; */
NS_IMETHODIMP nsDOMLoadStatus::GetLoadedSize(int32_t *aLoadedSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short readyState; */
NS_IMETHODIMP nsDOMLoadStatus::GetReadyState(uint16_t *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short status; */
NS_IMETHODIMP nsDOMLoadStatus::GetStatus(uint16_t *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLoadStatus_h__ */
