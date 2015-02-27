/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsPILoadGroupInternal.idl
 */

#ifndef __gen_nsPILoadGroupInternal_h__
#define __gen_nsPILoadGroupInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */


/* starting interface:    nsPILoadGroupInternal */
#define NS_PILOADGROUPINTERNAL_IID_STR "6ef2f8ac-9584-48f3-957a-0c94fff0c8c7"

#define NS_PILOADGROUPINTERNAL_IID \
  {0x6ef2f8ac, 0x9584, 0x48f3, \
    { 0x95, 0x7a, 0x0c, 0x94, 0xff, 0xf0, 0xc8, 0xc7 }}

class NS_NO_VTABLE nsPILoadGroupInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PILOADGROUPINTERNAL_IID)

  /* void OnEndPageLoad (in nsIChannel aDefaultChannel); */
  NS_IMETHOD OnEndPageLoad(nsIChannel *aDefaultChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPILoadGroupInternal, NS_PILOADGROUPINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPILOADGROUPINTERNAL \
  NS_IMETHOD OnEndPageLoad(nsIChannel *aDefaultChannel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPILOADGROUPINTERNAL(_to) \
  NS_IMETHOD OnEndPageLoad(nsIChannel *aDefaultChannel) { return _to OnEndPageLoad(aDefaultChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPILOADGROUPINTERNAL(_to) \
  NS_IMETHOD OnEndPageLoad(nsIChannel *aDefaultChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndPageLoad(aDefaultChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPILoadGroupInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPILOADGROUPINTERNAL

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPILoadGroupInternal)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void OnEndPageLoad (in nsIChannel aDefaultChannel); */
NS_IMETHODIMP _MYCLASS_::OnEndPageLoad(nsIChannel *aDefaultChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPILoadGroupInternal_h__ */
