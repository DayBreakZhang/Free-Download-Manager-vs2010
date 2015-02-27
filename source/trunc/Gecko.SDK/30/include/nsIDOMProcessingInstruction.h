/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMProcessingInstruction.idl
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
#define NS_IDOMPROCESSINGINSTRUCTION_IID_STR "91f2e856-5596-44d6-b396-0a02d8ec28c6"

#define NS_IDOMPROCESSINGINSTRUCTION_IID \
  {0x91f2e856, 0x5596, 0x44d6, \
    { 0xb3, 0x96, 0x0a, 0x02, 0xd8, 0xec, 0x28, 0xc6 }}

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
