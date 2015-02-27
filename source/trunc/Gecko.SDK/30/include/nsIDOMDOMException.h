/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDOMException.idl
 */

#ifndef __gen_nsIDOMDOMException_h__
#define __gen_nsIDOMDOMException_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDOMException */
#define NS_IDOMDOMEXCEPTION_IID_STR "5bd766d3-57a9-4833-995d-dbe21da29595"

#define NS_IDOMDOMEXCEPTION_IID \
  {0x5bd766d3, 0x57a9, 0x4833, \
    { 0x99, 0x5d, 0xdb, 0xe2, 0x1d, 0xa2, 0x95, 0x95 }}

class NS_NO_VTABLE nsIDOMDOMException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMEXCEPTION_IID)

  enum {
    INDEX_SIZE_ERR = 1U,
    DOMSTRING_SIZE_ERR = 2U,
    HIERARCHY_REQUEST_ERR = 3U,
    WRONG_DOCUMENT_ERR = 4U,
    INVALID_CHARACTER_ERR = 5U,
    NO_DATA_ALLOWED_ERR = 6U,
    NO_MODIFICATION_ALLOWED_ERR = 7U,
    NOT_FOUND_ERR = 8U,
    NOT_SUPPORTED_ERR = 9U,
    INUSE_ATTRIBUTE_ERR = 10U,
    INVALID_STATE_ERR = 11U,
    SYNTAX_ERR = 12U,
    INVALID_MODIFICATION_ERR = 13U,
    NAMESPACE_ERR = 14U,
    INVALID_ACCESS_ERR = 15U,
    VALIDATION_ERR = 16U,
    TYPE_MISMATCH_ERR = 17U,
    SECURITY_ERR = 18U,
    NETWORK_ERR = 19U,
    ABORT_ERR = 20U,
    URL_MISMATCH_ERR = 21U,
    QUOTA_EXCEEDED_ERR = 22U,
    TIMEOUT_ERR = 23U,
    INVALID_NODE_TYPE_ERR = 24U,
    DATA_CLONE_ERR = 25U
  };

  /* readonly attribute unsigned short code; */
  NS_IMETHOD GetCode(uint16_t *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMException, NS_IDOMDOMEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMEXCEPTION \
  NS_IMETHOD GetCode(uint16_t *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMEXCEPTION(_to) \
  NS_IMETHOD GetCode(uint16_t *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMEXCEPTION(_to) \
  NS_IMETHOD GetCode(uint16_t *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMException : public nsIDOMDOMException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMEXCEPTION

  nsDOMDOMException();

private:
  ~nsDOMDOMException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMException, nsIDOMDOMException)

nsDOMDOMException::nsDOMDOMException()
{
  /* member initializers and constructor code */
}

nsDOMDOMException::~nsDOMDOMException()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMDOMException::GetCode(uint16_t *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMException_h__ */
