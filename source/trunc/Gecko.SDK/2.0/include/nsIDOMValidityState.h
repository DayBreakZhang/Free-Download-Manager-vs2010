/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMValidityState.idl
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

/**
 * The nsIDOMValidityState interface is the interface to a ValidityState
 * object which represents the validity states of an element.
 *
 * For more information on this interface please see
 * http://www.whatwg.org/specs/web-apps/current-work/#validitystate
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMValidityState : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMVALIDITYSTATE_IID)

  /* readonly attribute boolean valueMissing; */
  NS_SCRIPTABLE NS_IMETHOD GetValueMissing(PRBool *aValueMissing) = 0;

  /* readonly attribute boolean typeMismatch; */
  NS_SCRIPTABLE NS_IMETHOD GetTypeMismatch(PRBool *aTypeMismatch) = 0;

  /* readonly attribute boolean patternMismatch; */
  NS_SCRIPTABLE NS_IMETHOD GetPatternMismatch(PRBool *aPatternMismatch) = 0;

  /* readonly attribute boolean tooLong; */
  NS_SCRIPTABLE NS_IMETHOD GetTooLong(PRBool *aTooLong) = 0;

  /* readonly attribute boolean rangeUnderflow; */
  NS_SCRIPTABLE NS_IMETHOD GetRangeUnderflow(PRBool *aRangeUnderflow) = 0;

  /* readonly attribute boolean rangeOverflow; */
  NS_SCRIPTABLE NS_IMETHOD GetRangeOverflow(PRBool *aRangeOverflow) = 0;

  /* readonly attribute boolean stepMismatch; */
  NS_SCRIPTABLE NS_IMETHOD GetStepMismatch(PRBool *aStepMismatch) = 0;

  /* readonly attribute boolean customError; */
  NS_SCRIPTABLE NS_IMETHOD GetCustomError(PRBool *aCustomError) = 0;

  /* readonly attribute boolean valid; */
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMValidityState, NS_IDOMVALIDITYSTATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMVALIDITYSTATE \
  NS_SCRIPTABLE NS_IMETHOD GetValueMissing(PRBool *aValueMissing); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeMismatch(PRBool *aTypeMismatch); \
  NS_SCRIPTABLE NS_IMETHOD GetPatternMismatch(PRBool *aPatternMismatch); \
  NS_SCRIPTABLE NS_IMETHOD GetTooLong(PRBool *aTooLong); \
  NS_SCRIPTABLE NS_IMETHOD GetRangeUnderflow(PRBool *aRangeUnderflow); \
  NS_SCRIPTABLE NS_IMETHOD GetRangeOverflow(PRBool *aRangeOverflow); \
  NS_SCRIPTABLE NS_IMETHOD GetStepMismatch(PRBool *aStepMismatch); \
  NS_SCRIPTABLE NS_IMETHOD GetCustomError(PRBool *aCustomError); \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMVALIDITYSTATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValueMissing(PRBool *aValueMissing) { return _to GetValueMissing(aValueMissing); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeMismatch(PRBool *aTypeMismatch) { return _to GetTypeMismatch(aTypeMismatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatternMismatch(PRBool *aPatternMismatch) { return _to GetPatternMismatch(aPatternMismatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetTooLong(PRBool *aTooLong) { return _to GetTooLong(aTooLong); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeUnderflow(PRBool *aRangeUnderflow) { return _to GetRangeUnderflow(aRangeUnderflow); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeOverflow(PRBool *aRangeOverflow) { return _to GetRangeOverflow(aRangeOverflow); } \
  NS_SCRIPTABLE NS_IMETHOD GetStepMismatch(PRBool *aStepMismatch) { return _to GetStepMismatch(aStepMismatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetCustomError(PRBool *aCustomError) { return _to GetCustomError(aCustomError); } \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) { return _to GetValid(aValid); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMVALIDITYSTATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValueMissing(PRBool *aValueMissing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueMissing(aValueMissing); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeMismatch(PRBool *aTypeMismatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeMismatch(aTypeMismatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetPatternMismatch(PRBool *aPatternMismatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatternMismatch(aPatternMismatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetTooLong(PRBool *aTooLong) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooLong(aTooLong); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeUnderflow(PRBool *aRangeUnderflow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeUnderflow(aRangeUnderflow); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeOverflow(PRBool *aRangeOverflow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeOverflow(aRangeOverflow); } \
  NS_SCRIPTABLE NS_IMETHOD GetStepMismatch(PRBool *aStepMismatch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStepMismatch(aStepMismatch); } \
  NS_SCRIPTABLE NS_IMETHOD GetCustomError(PRBool *aCustomError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCustomError(aCustomError); } \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValid(aValid); } 

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
NS_IMETHODIMP nsDOMValidityState::GetValueMissing(PRBool *aValueMissing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean typeMismatch; */
NS_IMETHODIMP nsDOMValidityState::GetTypeMismatch(PRBool *aTypeMismatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean patternMismatch; */
NS_IMETHODIMP nsDOMValidityState::GetPatternMismatch(PRBool *aPatternMismatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean tooLong; */
NS_IMETHODIMP nsDOMValidityState::GetTooLong(PRBool *aTooLong)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean rangeUnderflow; */
NS_IMETHODIMP nsDOMValidityState::GetRangeUnderflow(PRBool *aRangeUnderflow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean rangeOverflow; */
NS_IMETHODIMP nsDOMValidityState::GetRangeOverflow(PRBool *aRangeOverflow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean stepMismatch; */
NS_IMETHODIMP nsDOMValidityState::GetStepMismatch(PRBool *aStepMismatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean customError; */
NS_IMETHODIMP nsDOMValidityState::GetCustomError(PRBool *aCustomError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean valid; */
NS_IMETHODIMP nsDOMValidityState::GetValid(PRBool *aValid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMValidityState_h__ */
