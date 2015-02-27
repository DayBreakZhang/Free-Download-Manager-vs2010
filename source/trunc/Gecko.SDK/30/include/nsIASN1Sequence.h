/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIASN1Sequence.idl
 */

#ifndef __gen_nsIASN1Sequence_h__
#define __gen_nsIASN1Sequence_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIASN1Object_h__
#include "nsIASN1Object.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMutableArray; /* forward declaration */


/* starting interface:    nsIASN1Sequence */
#define NS_IASN1SEQUENCE_IID_STR "b6b957e6-1dd1-11b2-89d7-e30624f50b00"

#define NS_IASN1SEQUENCE_IID \
  {0xb6b957e6, 0x1dd1, 0x11b2, \
    { 0x89, 0xd7, 0xe3, 0x06, 0x24, 0xf5, 0x0b, 0x00 }}

class NS_NO_VTABLE nsIASN1Sequence : public nsIASN1Object {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASN1SEQUENCE_IID)

  /* attribute nsIMutableArray ASN1Objects; */
  NS_IMETHOD GetASN1Objects(nsIMutableArray * *aASN1Objects) = 0;
  NS_IMETHOD SetASN1Objects(nsIMutableArray *aASN1Objects) = 0;

  /* attribute boolean isValidContainer; */
  NS_IMETHOD GetIsValidContainer(bool *aIsValidContainer) = 0;
  NS_IMETHOD SetIsValidContainer(bool aIsValidContainer) = 0;

  /* attribute boolean isExpanded; */
  NS_IMETHOD GetIsExpanded(bool *aIsExpanded) = 0;
  NS_IMETHOD SetIsExpanded(bool aIsExpanded) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIASN1Sequence, NS_IASN1SEQUENCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASN1SEQUENCE \
  NS_IMETHOD GetASN1Objects(nsIMutableArray * *aASN1Objects); \
  NS_IMETHOD SetASN1Objects(nsIMutableArray *aASN1Objects); \
  NS_IMETHOD GetIsValidContainer(bool *aIsValidContainer); \
  NS_IMETHOD SetIsValidContainer(bool aIsValidContainer); \
  NS_IMETHOD GetIsExpanded(bool *aIsExpanded); \
  NS_IMETHOD SetIsExpanded(bool aIsExpanded); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASN1SEQUENCE(_to) \
  NS_IMETHOD GetASN1Objects(nsIMutableArray * *aASN1Objects) { return _to GetASN1Objects(aASN1Objects); } \
  NS_IMETHOD SetASN1Objects(nsIMutableArray *aASN1Objects) { return _to SetASN1Objects(aASN1Objects); } \
  NS_IMETHOD GetIsValidContainer(bool *aIsValidContainer) { return _to GetIsValidContainer(aIsValidContainer); } \
  NS_IMETHOD SetIsValidContainer(bool aIsValidContainer) { return _to SetIsValidContainer(aIsValidContainer); } \
  NS_IMETHOD GetIsExpanded(bool *aIsExpanded) { return _to GetIsExpanded(aIsExpanded); } \
  NS_IMETHOD SetIsExpanded(bool aIsExpanded) { return _to SetIsExpanded(aIsExpanded); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASN1SEQUENCE(_to) \
  NS_IMETHOD GetASN1Objects(nsIMutableArray * *aASN1Objects) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetASN1Objects(aASN1Objects); } \
  NS_IMETHOD SetASN1Objects(nsIMutableArray *aASN1Objects) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetASN1Objects(aASN1Objects); } \
  NS_IMETHOD GetIsValidContainer(bool *aIsValidContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsValidContainer(aIsValidContainer); } \
  NS_IMETHOD SetIsValidContainer(bool aIsValidContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsValidContainer(aIsValidContainer); } \
  NS_IMETHOD GetIsExpanded(bool *aIsExpanded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExpanded(aIsExpanded); } \
  NS_IMETHOD SetIsExpanded(bool aIsExpanded) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsExpanded(aIsExpanded); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsASN1Sequence : public nsIASN1Sequence
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASN1SEQUENCE

  nsASN1Sequence();

private:
  ~nsASN1Sequence();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsASN1Sequence, nsIASN1Sequence)

nsASN1Sequence::nsASN1Sequence()
{
  /* member initializers and constructor code */
}

nsASN1Sequence::~nsASN1Sequence()
{
  /* destructor code */
}

/* attribute nsIMutableArray ASN1Objects; */
NS_IMETHODIMP nsASN1Sequence::GetASN1Objects(nsIMutableArray * *aASN1Objects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsASN1Sequence::SetASN1Objects(nsIMutableArray *aASN1Objects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isValidContainer; */
NS_IMETHODIMP nsASN1Sequence::GetIsValidContainer(bool *aIsValidContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsASN1Sequence::SetIsValidContainer(bool aIsValidContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isExpanded; */
NS_IMETHODIMP nsASN1Sequence::GetIsExpanded(bool *aIsExpanded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsASN1Sequence::SetIsExpanded(bool aIsExpanded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIASN1Sequence_h__ */
