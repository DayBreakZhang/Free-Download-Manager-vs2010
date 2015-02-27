/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIDOMProcessingInstruction.idl
 */

#ifndef __gen_nsIDOMProcessingInstruction_h__
#define __gen_nsIDOMProcessingInstruction_h__


#ifndef __gen_nsIDOMCharacterData_h__
#include "nsIDOMCharacterData.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMProcessingInstruction */
#define NS_IDOMPROCESSINGINSTRUCTION_IID_STR "9ee8b1c3-2b0d-49e2-b2d6-f6bb8bf21b9e"

#define NS_IDOMPROCESSINGINSTRUCTION_IID \
  {0x9ee8b1c3, 0x2b0d, 0x49e2, \
    { 0xb2, 0xd6, 0xf6, 0xbb, 0x8b, 0xf2, 0x1b, 0x9e }}

class NS_NO_VTABLE nsIDOMProcessingInstruction : public nsIDOMCharacterData {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPROCESSINGINSTRUCTION_IID)

  /* readonly attribute DOMString target; */
  NS_IMETHOD GetTarget(nsAString & aTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMProcessingInstruction, NS_IDOMPROCESSINGINSTRUCTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPROCESSINGINSTRUCTION \
  NS_IMETHOD GetTarget(nsAString & aTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPROCESSINGINSTRUCTION(_to) \
  NS_IMETHOD GetTarget(nsAString & aTarget) { return _to GetTarget(aTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPROCESSINGINSTRUCTION(_to) \
  NS_IMETHOD GetTarget(nsAString & aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMProcessingInstruction : public nsIDOMProcessingInstruction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPROCESSINGINSTRUCTION

  nsDOMProcessingInstruction();

private:
  ~nsDOMProcessingInstruction();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMProcessingInstruction, nsIDOMProcessingInstruction)

nsDOMProcessingInstruction::nsDOMProcessingInstruction()
{
  /* member initializers and constructor code */
}

nsDOMProcessingInstruction::~nsDOMProcessingInstruction()
{
  /* destructor code */
}

/* readonly attribute DOMString target; */
NS_IMETHODIMP nsDOMProcessingInstruction::GetTarget(nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMProcessingInstruction_h__ */
