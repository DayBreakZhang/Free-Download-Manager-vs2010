/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/browser-element/nsIOpenWindowEventDetail.idl
 */

#ifndef __gen_nsIOpenWindowEventDetail_h__
#define __gen_nsIOpenWindowEventDetail_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    nsIOpenWindowEventDetail */
#define NS_IOPENWINDOWEVENTDETAIL_IID_STR "94377af6-956a-4adf-908b-363f7023ae1a"

#define NS_IOPENWINDOWEVENTDETAIL_IID \
  {0x94377af6, 0x956a, 0x4adf, \
    { 0x90, 0x8b, 0x36, 0x3f, 0x70, 0x23, 0xae, 0x1a }}

class NS_NO_VTABLE nsIOpenWindowEventDetail : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOPENWINDOWEVENTDETAIL_IID)

  /* readonly attribute AString url; */
  NS_IMETHOD GetUrl(nsAString & aUrl) = 0;

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute AString features; */
  NS_IMETHOD GetFeatures(nsAString & aFeatures) = 0;

  /* readonly attribute nsIDOMNode frameElement; */
  NS_IMETHOD GetFrameElement(nsIDOMNode * *aFrameElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOpenWindowEventDetail, NS_IOPENWINDOWEVENTDETAIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOPENWINDOWEVENTDETAIL \
  NS_IMETHOD GetUrl(nsAString & aUrl); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetFeatures(nsAString & aFeatures); \
  NS_IMETHOD GetFrameElement(nsIDOMNode * *aFrameElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOPENWINDOWEVENTDETAIL(_to) \
  NS_IMETHOD GetUrl(nsAString & aUrl) { return _to GetUrl(aUrl); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetFeatures(nsAString & aFeatures) { return _to GetFeatures(aFeatures); } \
  NS_IMETHOD GetFrameElement(nsIDOMNode * *aFrameElement) { return _to GetFrameElement(aFrameElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOPENWINDOWEVENTDETAIL(_to) \
  NS_IMETHOD GetUrl(nsAString & aUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetFeatures(nsAString & aFeatures) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeatures(aFeatures); } \
  NS_IMETHOD GetFrameElement(nsIDOMNode * *aFrameElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameElement(aFrameElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOpenWindowEventDetail : public nsIOpenWindowEventDetail
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOPENWINDOWEVENTDETAIL

  nsOpenWindowEventDetail();

private:
  ~nsOpenWindowEventDetail();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOpenWindowEventDetail, nsIOpenWindowEventDetail)

nsOpenWindowEventDetail::nsOpenWindowEventDetail()
{
  /* member initializers and constructor code */
}

nsOpenWindowEventDetail::~nsOpenWindowEventDetail()
{
  /* destructor code */
}

/* readonly attribute AString url; */
NS_IMETHODIMP nsOpenWindowEventDetail::GetUrl(nsAString & aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsOpenWindowEventDetail::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString features; */
NS_IMETHODIMP nsOpenWindowEventDetail::GetFeatures(nsAString & aFeatures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode frameElement; */
NS_IMETHODIMP nsOpenWindowEventDetail::GetFrameElement(nsIDOMNode * *aFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIOpenWindowEventDetail_h__ */
