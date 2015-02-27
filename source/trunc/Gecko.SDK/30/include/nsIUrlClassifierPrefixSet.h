/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUrlClassifierPrefixSet.idl
 */

#ifndef __gen_nsIUrlClassifierPrefixSet_h__
#define __gen_nsIUrlClassifierPrefixSet_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUrlClassifierPrefixSet */
#define NS_IURLCLASSIFIERPREFIXSET_IID_STR "3d8579f0-75fa-4e00-ba41-38661d5b5d17"

#define NS_IURLCLASSIFIERPREFIXSET_IID \
  {0x3d8579f0, 0x75fa, 0x4e00, \
    { 0xba, 0x41, 0x38, 0x66, 0x1d, 0x5b, 0x5d, 0x17 }}

class NS_NO_VTABLE nsIUrlClassifierPrefixSet : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERPREFIXSET_IID)

  /* void init (in ACString aName); */
  NS_IMETHOD Init(const nsACString & aName) = 0;

  /* void setPrefixes ([array, size_is (aLength), const] in unsigned long aPrefixes, in unsigned long aLength); */
  NS_IMETHOD SetPrefixes(const uint32_t *aPrefixes, uint32_t aLength) = 0;

  /* void getPrefixes (out unsigned long aCount, [array, size_is (aCount), retval] out unsigned long aPrefixes); */
  NS_IMETHOD GetPrefixes(uint32_t *aCount, uint32_t **aPrefixes) = 0;

  /* boolean contains (in unsigned long aPrefix); */
  NS_IMETHOD Contains(uint32_t aPrefix, bool *_retval) = 0;

  /* boolean isEmpty (); */
  NS_IMETHOD IsEmpty(bool *_retval) = 0;

  /* void loadFromFile (in nsIFile aFile); */
  NS_IMETHOD LoadFromFile(nsIFile *aFile) = 0;

  /* void storeToFile (in nsIFile aFile); */
  NS_IMETHOD StoreToFile(nsIFile *aFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierPrefixSet, NS_IURLCLASSIFIERPREFIXSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERPREFIXSET \
  NS_IMETHOD Init(const nsACString & aName); \
  NS_IMETHOD SetPrefixes(const uint32_t *aPrefixes, uint32_t aLength); \
  NS_IMETHOD GetPrefixes(uint32_t *aCount, uint32_t **aPrefixes); \
  NS_IMETHOD Contains(uint32_t aPrefix, bool *_retval); \
  NS_IMETHOD IsEmpty(bool *_retval); \
  NS_IMETHOD LoadFromFile(nsIFile *aFile); \
  NS_IMETHOD StoreToFile(nsIFile *aFile); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERPREFIXSET(_to) \
  NS_IMETHOD Init(const nsACString & aName) { return _to Init(aName); } \
  NS_IMETHOD SetPrefixes(const uint32_t *aPrefixes, uint32_t aLength) { return _to SetPrefixes(aPrefixes, aLength); } \
  NS_IMETHOD GetPrefixes(uint32_t *aCount, uint32_t **aPrefixes) { return _to GetPrefixes(aCount, aPrefixes); } \
  NS_IMETHOD Contains(uint32_t aPrefix, bool *_retval) { return _to Contains(aPrefix, _retval); } \
  NS_IMETHOD IsEmpty(bool *_retval) { return _to IsEmpty(_retval); } \
  NS_IMETHOD LoadFromFile(nsIFile *aFile) { return _to LoadFromFile(aFile); } \
  NS_IMETHOD StoreToFile(nsIFile *aFile) { return _to StoreToFile(aFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERPREFIXSET(_to) \
  NS_IMETHOD Init(const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aName); } \
  NS_IMETHOD SetPrefixes(const uint32_t *aPrefixes, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrefixes(aPrefixes, aLength); } \
  NS_IMETHOD GetPrefixes(uint32_t *aCount, uint32_t **aPrefixes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefixes(aCount, aPrefixes); } \
  NS_IMETHOD Contains(uint32_t aPrefix, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Contains(aPrefix, _retval); } \
  NS_IMETHOD IsEmpty(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEmpty(_retval); } \
  NS_IMETHOD LoadFromFile(nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadFromFile(aFile); } \
  NS_IMETHOD StoreToFile(nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->StoreToFile(aFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierPrefixSet : public nsIUrlClassifierPrefixSet
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERPREFIXSET

  nsUrlClassifierPrefixSet();

private:
  ~nsUrlClassifierPrefixSet();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierPrefixSet, nsIUrlClassifierPrefixSet)

nsUrlClassifierPrefixSet::nsUrlClassifierPrefixSet()
{
  /* member initializers and constructor code */
}

nsUrlClassifierPrefixSet::~nsUrlClassifierPrefixSet()
{
  /* destructor code */
}

/* void init (in ACString aName); */
NS_IMETHODIMP nsUrlClassifierPrefixSet::Init(const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPrefixes ([array, size_is (aLength), const] in unsigned long aPrefixes, in unsigned long aLength); */
NS_IMETHODIMP nsUrlClassifierPrefixSet::SetPrefixes(const uint32_t *aPrefixes, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPrefixes (out unsigned long aCount, [array, size_is (aCount), retval] out unsigned long aPrefixes); */
NS_IMETHODIMP nsUrlClassifierPrefixSet::GetPrefixes(uint32_t *aCount, uint32_t **aPrefixes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean contains (in unsigned long aPrefix); */
NS_IMETHODIMP nsUrlClassifierPrefixSet::Contains(uint32_t aPrefix, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEmpty (); */
NS_IMETHODIMP nsUrlClassifierPrefixSet::IsEmpty(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadFromFile (in nsIFile aFile); */
NS_IMETHODIMP nsUrlClassifierPrefixSet::LoadFromFile(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void storeToFile (in nsIFile aFile); */
NS_IMETHODIMP nsUrlClassifierPrefixSet::StoreToFile(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlClassifierPrefixSet_h__ */
