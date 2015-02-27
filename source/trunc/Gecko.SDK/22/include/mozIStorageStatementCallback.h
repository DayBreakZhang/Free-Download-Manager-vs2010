/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageStatementCallback.idl
 */

#ifndef __gen_mozIStorageStatementCallback_h__
#define __gen_mozIStorageStatementCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageResultSet; /* forward declaration */

class mozIStorageError; /* forward declaration */


/* starting interface:    mozIStorageStatementCallback */
#define MOZISTORAGESTATEMENTCALLBACK_IID_STR "29383d00-d8c4-4ddd-9f8b-c2feb0f2fcfa"

#define MOZISTORAGESTATEMENTCALLBACK_IID \
  {0x29383d00, 0xd8c4, 0x4ddd, \
    { 0x9f, 0x8b, 0xc2, 0xfe, 0xb0, 0xf2, 0xfc, 0xfa }}

class NS_NO_VTABLE mozIStorageStatementCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENTCALLBACK_IID)

  /* void handleResult (in mozIStorageResultSet aResultSet); */
  NS_IMETHOD HandleResult(mozIStorageResultSet *aResultSet) = 0;

  /* void handleError (in mozIStorageError aError); */
  NS_IMETHOD HandleError(mozIStorageError *aError) = 0;

  enum {
    REASON_FINISHED = 0U,
    REASON_CANCELED = 1U,
    REASON_ERROR = 2U
  };

  /* void handleCompletion (in unsigned short aReason); */
  NS_IMETHOD HandleCompletion(uint16_t aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatementCallback, MOZISTORAGESTATEMENTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENTCALLBACK \
  NS_IMETHOD HandleResult(mozIStorageResultSet *aResultSet); \
  NS_IMETHOD HandleError(mozIStorageError *aError); \
  NS_IMETHOD HandleCompletion(uint16_t aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENTCALLBACK(_to) \
  NS_IMETHOD HandleResult(mozIStorageResultSet *aResultSet) { return _to HandleResult(aResultSet); } \
  NS_IMETHOD HandleError(mozIStorageError *aError) { return _to HandleError(aError); } \
  NS_IMETHOD HandleCompletion(uint16_t aReason) { return _to HandleCompletion(aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENTCALLBACK(_to) \
  NS_IMETHOD HandleResult(mozIStorageResultSet *aResultSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleResult(aResultSet); } \
  NS_IMETHOD HandleError(mozIStorageError *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleError(aError); } \
  NS_IMETHOD HandleCompletion(uint16_t aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCompletion(aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatementCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENTCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatementCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void handleResult (in mozIStorageResultSet aResultSet); */
NS_IMETHODIMP _MYCLASS_::HandleResult(mozIStorageResultSet *aResultSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleError (in mozIStorageError aError); */
NS_IMETHODIMP _MYCLASS_::HandleError(mozIStorageError *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleCompletion (in unsigned short aReason); */
NS_IMETHODIMP _MYCLASS_::HandleCompletion(uint16_t aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageStatementCallback_h__ */
