/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/find/nsIFindService.idl
 */

#ifndef __gen_nsIFindService_h__
#define __gen_nsIFindService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFindService */
#define NS_IFINDSERVICE_IID_STR "5060b801-340e-11d5-be5b-b3e063ec6a3c"

#define NS_IFINDSERVICE_IID \
  {0x5060b801, 0x340e, 0x11d5, \
    { 0xbe, 0x5b, 0xb3, 0xe0, 0x63, 0xec, 0x6a, 0x3c }}

class NS_NO_VTABLE nsIFindService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFINDSERVICE_IID)

  /* attribute AString searchString; */
  NS_IMETHOD GetSearchString(nsAString & aSearchString) = 0;
  NS_IMETHOD SetSearchString(const nsAString & aSearchString) = 0;

  /* attribute AString replaceString; */
  NS_IMETHOD GetReplaceString(nsAString & aReplaceString) = 0;
  NS_IMETHOD SetReplaceString(const nsAString & aReplaceString) = 0;

  /* attribute boolean findBackwards; */
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards) = 0;
  NS_IMETHOD SetFindBackwards(bool aFindBackwards) = 0;

  /* attribute boolean wrapFind; */
  NS_IMETHOD GetWrapFind(bool *aWrapFind) = 0;
  NS_IMETHOD SetWrapFind(bool aWrapFind) = 0;

  /* attribute boolean entireWord; */
  NS_IMETHOD GetEntireWord(bool *aEntireWord) = 0;
  NS_IMETHOD SetEntireWord(bool aEntireWord) = 0;

  /* attribute boolean matchCase; */
  NS_IMETHOD GetMatchCase(bool *aMatchCase) = 0;
  NS_IMETHOD SetMatchCase(bool aMatchCase) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFindService, NS_IFINDSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFINDSERVICE \
  NS_IMETHOD GetSearchString(nsAString & aSearchString); \
  NS_IMETHOD SetSearchString(const nsAString & aSearchString); \
  NS_IMETHOD GetReplaceString(nsAString & aReplaceString); \
  NS_IMETHOD SetReplaceString(const nsAString & aReplaceString); \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards); \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards); \
  NS_IMETHOD GetWrapFind(bool *aWrapFind); \
  NS_IMETHOD SetWrapFind(bool aWrapFind); \
  NS_IMETHOD GetEntireWord(bool *aEntireWord); \
  NS_IMETHOD SetEntireWord(bool aEntireWord); \
  NS_IMETHOD GetMatchCase(bool *aMatchCase); \
  NS_IMETHOD SetMatchCase(bool aMatchCase); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFINDSERVICE(_to) \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) { return _to GetSearchString(aSearchString); } \
  NS_IMETHOD SetSearchString(const nsAString & aSearchString) { return _to SetSearchString(aSearchString); } \
  NS_IMETHOD GetReplaceString(nsAString & aReplaceString) { return _to GetReplaceString(aReplaceString); } \
  NS_IMETHOD SetReplaceString(const nsAString & aReplaceString) { return _to SetReplaceString(aReplaceString); } \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards) { return _to GetFindBackwards(aFindBackwards); } \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards) { return _to SetFindBackwards(aFindBackwards); } \
  NS_IMETHOD GetWrapFind(bool *aWrapFind) { return _to GetWrapFind(aWrapFind); } \
  NS_IMETHOD SetWrapFind(bool aWrapFind) { return _to SetWrapFind(aWrapFind); } \
  NS_IMETHOD GetEntireWord(bool *aEntireWord) { return _to GetEntireWord(aEntireWord); } \
  NS_IMETHOD SetEntireWord(bool aEntireWord) { return _to SetEntireWord(aEntireWord); } \
  NS_IMETHOD GetMatchCase(bool *aMatchCase) { return _to GetMatchCase(aMatchCase); } \
  NS_IMETHOD SetMatchCase(bool aMatchCase) { return _to SetMatchCase(aMatchCase); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFINDSERVICE(_to) \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchString(aSearchString); } \
  NS_IMETHOD SetSearchString(const nsAString & aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchString(aSearchString); } \
  NS_IMETHOD GetReplaceString(nsAString & aReplaceString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReplaceString(aReplaceString); } \
  NS_IMETHOD SetReplaceString(const nsAString & aReplaceString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReplaceString(aReplaceString); } \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFindBackwards(aFindBackwards); } \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFindBackwards(aFindBackwards); } \
  NS_IMETHOD GetWrapFind(bool *aWrapFind) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrapFind(aWrapFind); } \
  NS_IMETHOD SetWrapFind(bool aWrapFind) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrapFind(aWrapFind); } \
  NS_IMETHOD GetEntireWord(bool *aEntireWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntireWord(aEntireWord); } \
  NS_IMETHOD SetEntireWord(bool aEntireWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEntireWord(aEntireWord); } \
  NS_IMETHOD GetMatchCase(bool *aMatchCase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatchCase(aMatchCase); } \
  NS_IMETHOD SetMatchCase(bool aMatchCase) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMatchCase(aMatchCase); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFindService : public nsIFindService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFINDSERVICE

  nsFindService();

private:
  ~nsFindService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFindService, nsIFindService)

nsFindService::nsFindService()
{
  /* member initializers and constructor code */
}

nsFindService::~nsFindService()
{
  /* destructor code */
}

/* attribute AString searchString; */
NS_IMETHODIMP nsFindService::GetSearchString(nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetSearchString(const nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString replaceString; */
NS_IMETHODIMP nsFindService::GetReplaceString(nsAString & aReplaceString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetReplaceString(const nsAString & aReplaceString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean findBackwards; */
NS_IMETHODIMP nsFindService::GetFindBackwards(bool *aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetFindBackwards(bool aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean wrapFind; */
NS_IMETHODIMP nsFindService::GetWrapFind(bool *aWrapFind)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetWrapFind(bool aWrapFind)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean entireWord; */
NS_IMETHODIMP nsFindService::GetEntireWord(bool *aEntireWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetEntireWord(bool aEntireWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean matchCase; */
NS_IMETHODIMP nsFindService::GetMatchCase(bool *aMatchCase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFindService::SetMatchCase(bool aMatchCase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFindService_h__ */
