/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFeedTextConstruct.idl
 */

#ifndef __gen_nsIFeedTextConstruct_h__
#define __gen_nsIFeedTextConstruct_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMDocumentFragment; /* forward declaration */


/* starting interface:    nsIFeedTextConstruct */
#define NS_IFEEDTEXTCONSTRUCT_IID_STR "fc97a2a9-d649-4494-931e-db81a156c873"

#define NS_IFEEDTEXTCONSTRUCT_IID \
  {0xfc97a2a9, 0xd649, 0x4494, \
    { 0x93, 0x1e, 0xdb, 0x81, 0xa1, 0x56, 0xc8, 0x73 }}

class NS_NO_VTABLE nsIFeedTextConstruct : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDTEXTCONSTRUCT_IID)

  /* attribute nsIURI base; */
  NS_IMETHOD GetBase(nsIURI * *aBase) = 0;
  NS_IMETHOD SetBase(nsIURI *aBase) = 0;

  /* attribute AString lang; */
  NS_IMETHOD GetLang(nsAString & aLang) = 0;
  NS_IMETHOD SetLang(const nsAString & aLang) = 0;

  /* attribute AString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute AString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;
  NS_IMETHOD SetText(const nsAString & aText) = 0;

  /* AString plainText (); */
  NS_IMETHOD PlainText(nsAString & _retval) = 0;

  /* nsIDOMDocumentFragment createDocumentFragment (in nsIDOMElement element); */
  NS_IMETHOD CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedTextConstruct, NS_IFEEDTEXTCONSTRUCT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDTEXTCONSTRUCT \
  NS_IMETHOD GetBase(nsIURI * *aBase); \
  NS_IMETHOD SetBase(nsIURI *aBase); \
  NS_IMETHOD GetLang(nsAString & aLang); \
  NS_IMETHOD SetLang(const nsAString & aLang); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetText(nsAString & aText); \
  NS_IMETHOD SetText(const nsAString & aText); \
  NS_IMETHOD PlainText(nsAString & _retval); \
  NS_IMETHOD CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDTEXTCONSTRUCT(_to) \
  NS_IMETHOD GetBase(nsIURI * *aBase) { return _to GetBase(aBase); } \
  NS_IMETHOD SetBase(nsIURI *aBase) { return _to SetBase(aBase); } \
  NS_IMETHOD GetLang(nsAString & aLang) { return _to GetLang(aLang); } \
  NS_IMETHOD SetLang(const nsAString & aLang) { return _to SetLang(aLang); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) { return _to SetText(aText); } \
  NS_IMETHOD PlainText(nsAString & _retval) { return _to PlainText(_retval); } \
  NS_IMETHOD CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment * *_retval) { return _to CreateDocumentFragment(element, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDTEXTCONSTRUCT(_to) \
  NS_IMETHOD GetBase(nsIURI * *aBase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBase(aBase); } \
  NS_IMETHOD SetBase(nsIURI *aBase) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBase(aBase); } \
  NS_IMETHOD GetLang(nsAString & aLang) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLang(aLang); } \
  NS_IMETHOD SetLang(const nsAString & aLang) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLang(aLang); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetText(aText); } \
  NS_IMETHOD PlainText(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PlainText(_retval); } \
  NS_IMETHOD CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDocumentFragment(element, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedTextConstruct : public nsIFeedTextConstruct
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDTEXTCONSTRUCT

  nsFeedTextConstruct();

private:
  ~nsFeedTextConstruct();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedTextConstruct, nsIFeedTextConstruct)

nsFeedTextConstruct::nsFeedTextConstruct()
{
  /* member initializers and constructor code */
}

nsFeedTextConstruct::~nsFeedTextConstruct()
{
  /* destructor code */
}

/* attribute nsIURI base; */
NS_IMETHODIMP nsFeedTextConstruct::GetBase(nsIURI * *aBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedTextConstruct::SetBase(nsIURI *aBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString lang; */
NS_IMETHODIMP nsFeedTextConstruct::GetLang(nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedTextConstruct::SetLang(const nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString type; */
NS_IMETHODIMP nsFeedTextConstruct::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedTextConstruct::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString text; */
NS_IMETHODIMP nsFeedTextConstruct::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedTextConstruct::SetText(const nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString plainText (); */
NS_IMETHODIMP nsFeedTextConstruct::PlainText(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment createDocumentFragment (in nsIDOMElement element); */
NS_IMETHODIMP nsFeedTextConstruct::CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedTextConstruct_h__ */
