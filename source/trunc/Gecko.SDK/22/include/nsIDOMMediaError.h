/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMMediaError.idl
 */

#ifndef __gen_nsIDOMMediaError_h__
#define __gen_nsIDOMMediaError_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMediaError */
#define NS_IDOMMEDIAERROR_IID_STR "7bd8c29f-8a76-453f-9373-79f820f2dc01"

#define NS_IDOMMEDIAERROR_IID \
  {0x7bd8c29f, 0x8a76, 0x453f, \
    { 0x93, 0x73, 0x79, 0xf8, 0x20, 0xf2, 0xdc, 0x01 }}

class NS_NO_VTABLE nsIDOMMediaError : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMEDIAERROR_IID)

  enum {
    MEDIA_ERR_ABORTED = 1U,
    MEDIA_ERR_NETWORK = 2U,
    MEDIA_ERR_DECODE = 3U,
    MEDIA_ERR_SRC_NOT_SUPPORTED = 4U
  };

  /* readonly attribute unsigned short code; */
  NS_IMETHOD GetCode(uint16_t *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMediaError, NS_IDOMMEDIAERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMEDIAERROR \
  NS_IMETHOD GetCode(uint16_t *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMEDIAERROR(_to) \
  NS_IMETHOD GetCode(uint16_t *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMEDIAERROR(_to) \
  NS_IMETHOD GetCode(uint16_t *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMediaError : public nsIDOMMediaError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMEDIAERROR

  nsDOMMediaError();

private:
  ~nsDOMMediaError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMediaError, nsIDOMMediaError)

nsDOMMediaError::nsDOMMediaError()
{
  /* member initializers and constructor code */
}

nsDOMMediaError::~nsDOMMediaError()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMMediaError::GetCode(uint16_t *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMediaError_h__ */
