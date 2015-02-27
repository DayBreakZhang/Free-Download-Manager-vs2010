/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/base/public/nsIDOMFormData.idl
 */

#ifndef __gen_nsIDOMFormData_h__
#define __gen_nsIDOMFormData_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMFormData */
#define NS_IDOMFORMDATA_IID_STR "256c9139-5a29-41e1-8698-f9f9aae7d6cf"

#define NS_IDOMFORMDATA_IID \
  {0x256c9139, 0x5a29, 0x41e1, \
    { 0x86, 0x98, 0xf9, 0xf9, 0xaa, 0xe7, 0xd6, 0xcf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMFormData : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFORMDATA_IID)

  /* void append (in DOMString name, in nsIVariant value); */
  NS_SCRIPTABLE NS_IMETHOD Append(const nsAString & name, nsIVariant *value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFormData, NS_IDOMFORMDATA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFORMDATA \
  NS_SCRIPTABLE NS_IMETHOD Append(const nsAString & name, nsIVariant *value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFORMDATA(_to) \
  NS_SCRIPTABLE NS_IMETHOD Append(const nsAString & name, nsIVariant *value) { return _to Append(name, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFORMDATA(_to) \
  NS_SCRIPTABLE NS_IMETHOD Append(const nsAString & name, nsIVariant *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->Append(name, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFormData : public nsIDOMFormData
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFORMDATA

  nsDOMFormData();

private:
  ~nsDOMFormData();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFormData, nsIDOMFormData)

nsDOMFormData::nsDOMFormData()
{
  /* member initializers and constructor code */
}

nsDOMFormData::~nsDOMFormData()
{
  /* destructor code */
}

/* void append (in DOMString name, in nsIVariant value); */
NS_IMETHODIMP nsDOMFormData::Append(const nsAString & name, nsIVariant *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_FORMDATA_CID \
{ 0x6b192618, 0x26f2, 0x426e, \
  { 0xa7, 0xac, 0x1e, 0x13, 0xa6, 0xa4, 0x52, 0x2b } }
#define NS_FORMDATA_CONTRACTID "@mozilla.org/files/formdata;1"

#endif /* __gen_nsIDOMFormData_h__ */
