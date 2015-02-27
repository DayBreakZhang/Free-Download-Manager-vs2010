/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMValidityState.idl
 */

#ifndef __gen_nsIDOMValidityState_h__
#define __gen_nsIDOMValidityState_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMValidityState */
#define NS_IDOMVALIDITYSTATE_IID_STR "5e62197a-9b74-4812-b5a2-ca102e886f7a"

#define NS_IDOMVALIDITYSTATE_IID \
  {0x5e62197a, 0x9b74, 0x4812, \
    { 0xb5, 0xa2, 0xca, 0x10, 0x2e, 0x88, 0x6f, 0x7a }}

class NS_NO_VTABLE nsIDOMValidityState : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMVALIDITYSTATE_IID)

  /* readonly attribute boolean valueMissing; */
  NS_IMETHOD GetValueMissing(bool *aValueMissing) = 0;

  /* readonly attribute boolean typeMismatch; */
  NS_IMETHOD GetTypeMismatch(bool *aTypeMismatch) = 0;

  /* readonly attribute boolean patternMismatch; */
  NS_IMETHOD GetPatternMismatch(bool *aPatternMismatch) = 0;

  /* readonly attribute boolean tooLong; */
  NS_IMETHOD GetTooLong(bool *aTooLong) = 0;

  /* readonly attribute boolean rangeUnderflow; */
  NS_IMETHOD GetRangeUnderflow(bool *aRangeUnderflow) = 0;

  /* readonly attribute boolean rangeOverflow; */
  NS_IMETHOD GetRangeOverflow(bool *aRangeOverflow) = 0;

  /* readonly attribute boolean stepMismatch; */
  NS_IMETHOD GetStepMismatch(bool *aStepMismatch) = 0;

  /* readonly attribute boolean customError; */
  NS_IMETHOD GetCustomError(bool *aCustomError) = 0;

  /* readonly attribute boolean valid; */
  NS_IMETHOD GetValid(bool *aValid) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMValidityState, NS_IDOMVALIDITYSTATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMVALIDITYSTATE \
  NS_IMETHOD GetValueMissing(bool *aValueMissing); \
  NS_IMETHOD GetTypeMismatch(bool *aTypeMismatch); \
  NS_IMETHOD GetPatternMismatch(bool *aPatternMismatch); \
  NS_IMETHOD GetTooLong(bool *aTooLong); \
  NS_IMETHOD GetRangeUnderflow(bool *aRangeUnderflow); \
  NS_IMETHOD GetRangeOverflow(bool *aRangeOverflow); \
  NS_IMETHOD GetStepMismatch(bool *aStepMismatch); \
  NS_IMETHOD GetCustomError(bool *aCustomError); \
  NS_IMETHOD GetValid(bool *aValid); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMVALIDITYSTATE(_to) \
  NS_IMETHOD GetValueMissing(bool *aValueMissing) { return _to GetValueMissing(aValueMissing); } \
  NS_IMETHOD GetTypeMismatch(bool *aTypeMismatch) { return _to GetTypeMismatch(aTypeMismatch); } \
  NS_IMETHOD GetPatternMismatch(bool *aPatternMismatch) { return _to GetPatternMismatch(aPatternMismatch); } \
  NS_IMETHOD GetTooLong(bool *aTooLong) { return _to GetTooLong(aTooLong); } \
  NS_IMETHOD GetRangeUnderflow(bool *aRangeUnderflow) { return _to GetRangeUnderflow(aRangeUnderflow); } \
  NS_IMETHOD GetRangeOverflow(bool *aRangeOverflow) { return _to GetRangeOverflow(aRangeOverflow); } \
  NS_IMETHOD GetStepMismatch(bool *aStepMismatch) { return _to GetStepMismatch(aStepMismatch); } \
  NS_IMETHOD GetCustomError(bool *aCustomError) { return _to GetCustomError(aCustomError); } \
  NS_IMETHOD GetValid(bool *aValid) { return _to GetValid(aValid); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMVALIDITYSTATE(_to) \
  NS_IMETHOD GetValueMissing(bool *aValueMissing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueMissing(aValueMissing); } \
  NS_IMETHOD GetTypeMismatch(bool *aTypeMismatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeMismatch(aTypeMismatch); } \
  NS_IMETHOD GetPatternMismatch(bool *aPatternMismatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatternMismatch(aPatternMismatch); } \
  NS_IMETHOD GetTooLong(bool *aTooLong) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooLong(aTooLong); } \
  NS_IMETHOD GetRangeUnderflow(bool *aRangeUnderflow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeUnderflow(aRangeUnderflow); } \
  NS_IMETHOD GetRangeOverflow(bool *aRangeOverflow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeOverflow(aRangeOverflow); } \
  NS_IMETHOD GetStepMismatch(bool *aStepMismatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStepMismatch(aStepMismatch); } \
  NS_IMETHOD GetCustomError(bool *aCustomError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCustomError(aCustomError); } \
  NS_IMETHOD GetValid(bool *aValid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValid(aValid); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMValidityState : public nsIDOMValidityState
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMVALIDITYSTATE

  nsDOMValidityState();

private:
  ~nsDOMValidityState();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMValidityState, nsIDOMValidityState)

nsDOMValidityState::nsDOMValidityState()
{
  /* member initializers and constructor code */
}

nsDOMValidityState::~nsDOMValidityState()
{
  /* destructor code */
}

/* readonly attribute boolean valueMissing; */
NS_IMETHODIMP nsDOMValidityState::GetValueMissing(bool *aValueMissing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean typeMismatch; */
NS_IMETHODIMP nsDOMValidityState::GetTypeMismatch(bool *aTypeMismatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean patternMismatch; */
NS_IMETHODIMP nsDOMValidityState::GetPatternMismatch(bool *aPatternMismatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean tooLong; */
NS_IMETHODIMP nsDOMValidityState::GetTooLong(bool *aTooLong)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean rangeUnderflow; */
NS_IMETHODIMP nsDOMValidityState::GetRangeUnderflow(bool *aRangeUnderflow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean rangeOverflow; */
NS_IMETHODIMP nsDOMValidityState::GetRangeOverflow(bool *aRangeOverflow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean stepMismatch; */
NS_IMETHODIMP nsDOMValidityState::GetStepMismatch(bool *aStepMismatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean customError; */
NS_IMETHODIMP nsDOMValidityState::GetCustomError(bool *aCustomError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean valid; */
NS_IMETHODIMP nsDOMValidityState::GetValid(bool *aValid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMValidityState_h__ */
