/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/components/find/public/nsIFind.idl
 */

#ifndef __gen_nsIFind_h__
#define __gen_nsIFind_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMRange; /* forward declaration */

class nsIWordBreaker; /* forward declaration */


/* starting interface:    nsIFind */
#define NS_IFIND_IID_STR "75125d55-37ee-4575-b9b5-f33bfa68c2a1"

#define NS_IFIND_IID \
  {0x75125d55, 0x37ee, 0x4575, \
    { 0xb9, 0xb5, 0xf3, 0x3b, 0xfa, 0x68, 0xc2, 0xa1 }}

class NS_NO_VTABLE nsIFind : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFIND_IID)

  /* attribute boolean findBackwards; */
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards) = 0;
  NS_IMETHOD SetFindBackwards(bool aFindBackwards) = 0;

  /* attribute boolean caseSensitive; */
  NS_IMETHOD GetCaseSensitive(bool *aCaseSensitive) = 0;
  NS_IMETHOD SetCaseSensitive(bool aCaseSensitive) = 0;

  /* [noscript] attribute nsIWordBreaker wordBreaker; */
  NS_IMETHOD GetWordBreaker(nsIWordBreaker * *aWordBreaker) = 0;
  NS_IMETHOD SetWordBreaker(nsIWordBreaker *aWordBreaker) = 0;

  /* nsIDOMRange Find (in wstring aPatText, in nsIDOMRange aSearchRange, in nsIDOMRange aStartPoint, in nsIDOMRange aEndPoint); */
  NS_IMETHOD Find(const PRUnichar * aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFind, NS_IFIND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFIND \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards); \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards); \
  NS_IMETHOD GetCaseSensitive(bool *aCaseSensitive); \
  NS_IMETHOD SetCaseSensitive(bool aCaseSensitive); \
  NS_IMETHOD GetWordBreaker(nsIWordBreaker * *aWordBreaker); \
  NS_IMETHOD SetWordBreaker(nsIWordBreaker *aWordBreaker); \
  NS_IMETHOD Find(const PRUnichar * aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFIND(_to) \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards) { return _to GetFindBackwards(aFindBackwards); } \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards) { return _to SetFindBackwards(aFindBackwards); } \
  NS_IMETHOD GetCaseSensitive(bool *aCaseSensitive) { return _to GetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD SetCaseSensitive(bool aCaseSensitive) { return _to SetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD GetWordBreaker(nsIWordBreaker * *aWordBreaker) { return _to GetWordBreaker(aWordBreaker); } \
  NS_IMETHOD SetWordBreaker(nsIWordBreaker *aWordBreaker) { return _to SetWordBreaker(aWordBreaker); } \
  NS_IMETHOD Find(const PRUnichar * aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange * *_retval) { return _to Find(aPatText, aSearchRange, aStartPoint, aEndPoint, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFIND(_to) \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFindBackwards(aFindBackwards); } \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFindBackwards(aFindBackwards); } \
  NS_IMETHOD GetCaseSensitive(bool *aCaseSensitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD SetCaseSensitive(bool aCaseSensitive) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD GetWordBreaker(nsIWordBreaker * *aWordBreaker) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWordBreaker(aWordBreaker); } \
  NS_IMETHOD SetWordBreaker(nsIWordBreaker *aWordBreaker) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWordBreaker(aWordBreaker); } \
  NS_IMETHOD Find(const PRUnichar * aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(aPatText, aSearchRange, aStartPoint, aEndPoint, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFind : public nsIFind
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFIND

  nsFind();

private:
  ~nsFind();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFind, nsIFind)

nsFind::nsFind()
{
  /* member initializers and constructor code */
}

nsFind::~nsFind()
{
  /* destructor code */
}

/* attribute boolean findBackwards; */
NS_IMETHODIMP nsFind::GetFindBackwards(bool *aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFind::SetFindBackwards(bool aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean caseSensitive; */
NS_IMETHODIMP nsFind::GetCaseSensitive(bool *aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFind::SetCaseSensitive(bool aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIWordBreaker wordBreaker; */
NS_IMETHODIMP nsFind::GetWordBreaker(nsIWordBreaker * *aWordBreaker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFind::SetWordBreaker(nsIWordBreaker *aWordBreaker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMRange Find (in wstring aPatText, in nsIDOMRange aSearchRange, in nsIDOMRange aStartPoint, in nsIDOMRange aEndPoint); */
NS_IMETHODIMP nsFind::Find(const PRUnichar * aPatText, nsIDOMRange *aSearchRange, nsIDOMRange *aStartPoint, nsIDOMRange *aEndPoint, nsIDOMRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFind_h__ */
