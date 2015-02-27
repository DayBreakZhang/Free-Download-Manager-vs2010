/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/parser/xml/public/nsISAXXMLFilter.idl
 */

#ifndef __gen_nsISAXXMLFilter_h__
#define __gen_nsISAXXMLFilter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISAXXMLReader_h__
#include "nsISAXXMLReader.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXXMLFilter */
#define NS_ISAXXMLFILTER_IID_STR "77a22cf0-6cdf-11da-be43-001422106990"

#define NS_ISAXXMLFILTER_IID \
  {0x77a22cf0, 0x6cdf, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

class NS_NO_VTABLE nsISAXXMLFilter : public nsISAXXMLReader {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXXMLFILTER_IID)

  /* attribute nsISAXXMLReader parent; */
  NS_IMETHOD GetParent(nsISAXXMLReader * *aParent) = 0;
  NS_IMETHOD SetParent(nsISAXXMLReader *aParent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXXMLFilter, NS_ISAXXMLFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXXMLFILTER \
  NS_IMETHOD GetParent(nsISAXXMLReader * *aParent); \
  NS_IMETHOD SetParent(nsISAXXMLReader *aParent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXXMLFILTER(_to) \
  NS_IMETHOD GetParent(nsISAXXMLReader * *aParent) { return _to GetParent(aParent); } \
  NS_IMETHOD SetParent(nsISAXXMLReader *aParent) { return _to SetParent(aParent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXXMLFILTER(_to) \
  NS_IMETHOD GetParent(nsISAXXMLReader * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD SetParent(nsISAXXMLReader *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParent(aParent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXXMLFilter : public nsISAXXMLFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXXMLFILTER

  nsSAXXMLFilter();

private:
  ~nsSAXXMLFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXXMLFilter, nsISAXXMLFilter)

nsSAXXMLFilter::nsSAXXMLFilter()
{
  /* member initializers and constructor code */
}

nsSAXXMLFilter::~nsSAXXMLFilter()
{
  /* destructor code */
}

/* attribute nsISAXXMLReader parent; */
NS_IMETHODIMP nsSAXXMLFilter::GetParent(nsISAXXMLReader * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSAXXMLFilter::SetParent(nsISAXXMLReader *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXXMLFilter_h__ */
