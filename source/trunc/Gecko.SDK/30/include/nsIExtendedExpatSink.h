/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIExtendedExpatSink.idl
 */

#ifndef __gen_nsIExtendedExpatSink_h__
#define __gen_nsIExtendedExpatSink_h__


#ifndef __gen_nsIExpatSink_h__
#include "nsIExpatSink.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIExtendedExpatSink */
#define NS_IEXTENDEDEXPATSINK_IID_STR "146e194b-333d-4283-8cf6-4bc3ee9b5dff"

#define NS_IEXTENDEDEXPATSINK_IID \
  {0x146e194b, 0x333d, 0x4283, \
    { 0x8c, 0xf6, 0x4b, 0xc3, 0xee, 0x9b, 0x5d, 0xff }}

class NS_NO_VTABLE nsIExtendedExpatSink : public nsIExpatSink {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTENDEDEXPATSINK_IID)

  /* void handleStartDTD (in wstring aDoctypeName, in wstring aSysid, in wstring aPubid); */
  NS_IMETHOD HandleStartDTD(const char16_t * aDoctypeName, const char16_t * aSysid, const char16_t * aPubid) = 0;

  /* void handleStartNamespaceDecl (in wstring aPrefix, in wstring aUri); */
  NS_IMETHOD HandleStartNamespaceDecl(const char16_t * aPrefix, const char16_t * aUri) = 0;

  /* void handleEndNamespaceDecl (in wstring aPrefix); */
  NS_IMETHOD HandleEndNamespaceDecl(const char16_t * aPrefix) = 0;

  /* void handleNotationDecl (in wstring aNotationName, in wstring aSysid, in wstring aPubid); */
  NS_IMETHOD HandleNotationDecl(const char16_t * aNotationName, const char16_t * aSysid, const char16_t * aPubid) = 0;

  /* void handleUnparsedEntityDecl (in wstring aName, in wstring aSysid, in wstring aPubid, in wstring aNotationName); */
  NS_IMETHOD HandleUnparsedEntityDecl(const char16_t * aName, const char16_t * aSysid, const char16_t * aPubid, const char16_t * aNotationName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExtendedExpatSink, NS_IEXTENDEDEXPATSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTENDEDEXPATSINK \
  NS_IMETHOD HandleStartDTD(const char16_t * aDoctypeName, const char16_t * aSysid, const char16_t * aPubid); \
  NS_IMETHOD HandleStartNamespaceDecl(const char16_t * aPrefix, const char16_t * aUri); \
  NS_IMETHOD HandleEndNamespaceDecl(const char16_t * aPrefix); \
  NS_IMETHOD HandleNotationDecl(const char16_t * aNotationName, const char16_t * aSysid, const char16_t * aPubid); \
  NS_IMETHOD HandleUnparsedEntityDecl(const char16_t * aName, const char16_t * aSysid, const char16_t * aPubid, const char16_t * aNotationName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTENDEDEXPATSINK(_to) \
  NS_IMETHOD HandleStartDTD(const char16_t * aDoctypeName, const char16_t * aSysid, const char16_t * aPubid) { return _to HandleStartDTD(aDoctypeName, aSysid, aPubid); } \
  NS_IMETHOD HandleStartNamespaceDecl(const char16_t * aPrefix, const char16_t * aUri) { return _to HandleStartNamespaceDecl(aPrefix, aUri); } \
  NS_IMETHOD HandleEndNamespaceDecl(const char16_t * aPrefix) { return _to HandleEndNamespaceDecl(aPrefix); } \
  NS_IMETHOD HandleNotationDecl(const char16_t * aNotationName, const char16_t * aSysid, const char16_t * aPubid) { return _to HandleNotationDecl(aNotationName, aSysid, aPubid); } \
  NS_IMETHOD HandleUnparsedEntityDecl(const char16_t * aName, const char16_t * aSysid, const char16_t * aPubid, const char16_t * aNotationName) { return _to HandleUnparsedEntityDecl(aName, aSysid, aPubid, aNotationName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTENDEDEXPATSINK(_to) \
  NS_IMETHOD HandleStartDTD(const char16_t * aDoctypeName, const char16_t * aSysid, const char16_t * aPubid) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStartDTD(aDoctypeName, aSysid, aPubid); } \
  NS_IMETHOD HandleStartNamespaceDecl(const char16_t * aPrefix, const char16_t * aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStartNamespaceDecl(aPrefix, aUri); } \
  NS_IMETHOD HandleEndNamespaceDecl(const char16_t * aPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEndNamespaceDecl(aPrefix); } \
  NS_IMETHOD HandleNotationDecl(const char16_t * aNotationName, const char16_t * aSysid, const char16_t * aPubid) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleNotationDecl(aNotationName, aSysid, aPubid); } \
  NS_IMETHOD HandleUnparsedEntityDecl(const char16_t * aName, const char16_t * aSysid, const char16_t * aPubid, const char16_t * aNotationName) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleUnparsedEntityDecl(aName, aSysid, aPubid, aNotationName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExtendedExpatSink : public nsIExtendedExpatSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTENDEDEXPATSINK

  nsExtendedExpatSink();

private:
  ~nsExtendedExpatSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExtendedExpatSink, nsIExtendedExpatSink)

nsExtendedExpatSink::nsExtendedExpatSink()
{
  /* member initializers and constructor code */
}

nsExtendedExpatSink::~nsExtendedExpatSink()
{
  /* destructor code */
}

/* void handleStartDTD (in wstring aDoctypeName, in wstring aSysid, in wstring aPubid); */
NS_IMETHODIMP nsExtendedExpatSink::HandleStartDTD(const char16_t * aDoctypeName, const char16_t * aSysid, const char16_t * aPubid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleStartNamespaceDecl (in wstring aPrefix, in wstring aUri); */
NS_IMETHODIMP nsExtendedExpatSink::HandleStartNamespaceDecl(const char16_t * aPrefix, const char16_t * aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleEndNamespaceDecl (in wstring aPrefix); */
NS_IMETHODIMP nsExtendedExpatSink::HandleEndNamespaceDecl(const char16_t * aPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleNotationDecl (in wstring aNotationName, in wstring aSysid, in wstring aPubid); */
NS_IMETHODIMP nsExtendedExpatSink::HandleNotationDecl(const char16_t * aNotationName, const char16_t * aSysid, const char16_t * aPubid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleUnparsedEntityDecl (in wstring aName, in wstring aSysid, in wstring aPubid, in wstring aNotationName); */
NS_IMETHODIMP nsExtendedExpatSink::HandleUnparsedEntityDecl(const char16_t * aName, const char16_t * aSysid, const char16_t * aPubid, const char16_t * aNotationName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExtendedExpatSink_h__ */
