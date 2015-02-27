/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIJARURI.idl
 */

#ifndef __gen_nsIJARURI_h__
#define __gen_nsIJARURI_h__


#ifndef __gen_nsIURL_h__
#include "nsIURL.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJARURI */
#define NS_IJARURI_IID_STR "1ee60719-c056-43b3-8f54-6a6e7ba0ca6c"

#define NS_IJARURI_IID \
  {0x1ee60719, 0xc056, 0x43b3, \
    { 0x8f, 0x54, 0x6a, 0x6e, 0x7b, 0xa0, 0xca, 0x6c }}

class NS_NO_VTABLE nsIJARURI : public nsIURL {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJARURI_IID)

  /* readonly attribute nsIURI JARFile; */
  NS_IMETHOD GetJARFile(nsIURI * *aJARFile) = 0;

  /* attribute AUTF8String JAREntry; */
  NS_IMETHOD GetJAREntry(nsACString & aJAREntry) = 0;
  NS_IMETHOD SetJAREntry(const nsACString & aJAREntry) = 0;

  /* nsIJARURI cloneWithJARFile (in nsIURI jarFile); */
  NS_IMETHOD CloneWithJARFile(nsIURI *jarFile, nsIJARURI * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJARURI, NS_IJARURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJARURI \
  NS_IMETHOD GetJARFile(nsIURI * *aJARFile); \
  NS_IMETHOD GetJAREntry(nsACString & aJAREntry); \
  NS_IMETHOD SetJAREntry(const nsACString & aJAREntry); \
  NS_IMETHOD CloneWithJARFile(nsIURI *jarFile, nsIJARURI * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJARURI(_to) \
  NS_IMETHOD GetJARFile(nsIURI * *aJARFile) { return _to GetJARFile(aJARFile); } \
  NS_IMETHOD GetJAREntry(nsACString & aJAREntry) { return _to GetJAREntry(aJAREntry); } \
  NS_IMETHOD SetJAREntry(const nsACString & aJAREntry) { return _to SetJAREntry(aJAREntry); } \
  NS_IMETHOD CloneWithJARFile(nsIURI *jarFile, nsIJARURI * *_retval) { return _to CloneWithJARFile(jarFile, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJARURI(_to) \
  NS_IMETHOD GetJARFile(nsIURI * *aJARFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJARFile(aJARFile); } \
  NS_IMETHOD GetJAREntry(nsACString & aJAREntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJAREntry(aJAREntry); } \
  NS_IMETHOD SetJAREntry(const nsACString & aJAREntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetJAREntry(aJAREntry); } \
  NS_IMETHOD CloneWithJARFile(nsIURI *jarFile, nsIJARURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneWithJARFile(jarFile, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJARURI : public nsIJARURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJARURI

  nsJARURI();

private:
  ~nsJARURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJARURI, nsIJARURI)

nsJARURI::nsJARURI()
{
  /* member initializers and constructor code */
}

nsJARURI::~nsJARURI()
{
  /* destructor code */
}

/* readonly attribute nsIURI JARFile; */
NS_IMETHODIMP nsJARURI::GetJARFile(nsIURI * *aJARFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String JAREntry; */
NS_IMETHODIMP nsJARURI::GetJAREntry(nsACString & aJAREntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsJARURI::SetJAREntry(const nsACString & aJAREntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIJARURI cloneWithJARFile (in nsIURI jarFile); */
NS_IMETHODIMP nsJARURI::CloneWithJARFile(nsIURI *jarFile, nsIJARURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJARURI_h__ */
