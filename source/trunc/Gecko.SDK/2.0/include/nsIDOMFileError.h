/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/base/public/nsIDOMFileError.idl
 */

#ifndef __gen_nsIDOMFileError_h__
#define __gen_nsIDOMFileError_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMFileError */
#define NS_IDOMFILEERROR_IID_STR "4bdafb64-15e2-49c1-a090-4315a7884a56"

#define NS_IDOMFILEERROR_IID \
  {0x4bdafb64, 0x15e2, 0x49c1, \
    { 0xa0, 0x90, 0x43, 0x15, 0xa7, 0x88, 0x4a, 0x56 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMFileError : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILEERROR_IID)

  enum { NOT_FOUND_ERR = 1U };

  enum { SECURITY_ERR = 2U };

  enum { ABORT_ERR = 3U };

  enum { NOT_READABLE_ERR = 4U };

  enum { ENCODING_ERR = 5U };

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFileError, NS_IDOMFILEERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILEERROR \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILEERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILEERROR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFileError : public nsIDOMFileError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILEERROR

  nsDOMFileError();

private:
  ~nsDOMFileError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFileError, nsIDOMFileError)

nsDOMFileError::nsDOMFileError()
{
  /* member initializers and constructor code */
}

nsDOMFileError::~nsDOMFileError()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMFileError::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFileError_h__ */
