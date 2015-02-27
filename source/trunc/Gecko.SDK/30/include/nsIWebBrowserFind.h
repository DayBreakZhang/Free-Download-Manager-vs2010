/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebBrowserFind.idl
 */

#ifndef __gen_nsIWebBrowserFind_h__
#define __gen_nsIWebBrowserFind_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebBrowserFind */
#define NS_IWEBBROWSERFIND_IID_STR "2f977d44-5485-11d4-87e2-0010a4e75ef2"

#define NS_IWEBBROWSERFIND_IID \
  {0x2f977d44, 0x5485, 0x11d4, \
    { 0x87, 0xe2, 0x00, 0x10, 0xa4, 0xe7, 0x5e, 0xf2 }}

class NS_NO_VTABLE nsIWebBrowserFind : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERFIND_IID)

  /* boolean findNext (); */
  NS_IMETHOD FindNext(bool *_retval) = 0;

  /* attribute wstring searchString; */
  NS_IMETHOD GetSearchString(char16_t * *aSearchString) = 0;
  NS_IMETHOD SetSearchString(const char16_t * aSearchString) = 0;

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

  /* attribute boolean searchFrames; */
  NS_IMETHOD GetSearchFrames(bool *aSearchFrames) = 0;
  NS_IMETHOD SetSearchFrames(bool aSearchFrames) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserFind, NS_IWEBBROWSERFIND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERFIND \
  NS_IMETHOD FindNext(bool *_retval); \
  NS_IMETHOD GetSearchString(char16_t * *aSearchString); \
  NS_IMETHOD SetSearchString(const char16_t * aSearchString); \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards); \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards); \
  NS_IMETHOD GetWrapFind(bool *aWrapFind); \
  NS_IMETHOD SetWrapFind(bool aWrapFind); \
  NS_IMETHOD GetEntireWord(bool *aEntireWord); \
  NS_IMETHOD SetEntireWord(bool aEntireWord); \
  NS_IMETHOD GetMatchCase(bool *aMatchCase); \
  NS_IMETHOD SetMatchCase(bool aMatchCase); \
  NS_IMETHOD GetSearchFrames(bool *aSearchFrames); \
  NS_IMETHOD SetSearchFrames(bool aSearchFrames); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERFIND(_to) \
  NS_IMETHOD FindNext(bool *_retval) { return _to FindNext(_retval); } \
  NS_IMETHOD GetSearchString(char16_t * *aSearchString) { return _to GetSearchString(aSearchString); } \
  NS_IMETHOD SetSearchString(const char16_t * aSearchString) { return _to SetSearchString(aSearchString); } \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards) { return _to GetFindBackwards(aFindBackwards); } \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards) { return _to SetFindBackwards(aFindBackwards); } \
  NS_IMETHOD GetWrapFind(bool *aWrapFind) { return _to GetWrapFind(aWrapFind); } \
  NS_IMETHOD SetWrapFind(bool aWrapFind) { return _to SetWrapFind(aWrapFind); } \
  NS_IMETHOD GetEntireWord(bool *aEntireWord) { return _to GetEntireWord(aEntireWord); } \
  NS_IMETHOD SetEntireWord(bool aEntireWord) { return _to SetEntireWord(aEntireWord); } \
  NS_IMETHOD GetMatchCase(bool *aMatchCase) { return _to GetMatchCase(aMatchCase); } \
  NS_IMETHOD SetMatchCase(bool aMatchCase) { return _to SetMatchCase(aMatchCase); } \
  NS_IMETHOD GetSearchFrames(bool *aSearchFrames) { return _to GetSearchFrames(aSearchFrames); } \
  NS_IMETHOD SetSearchFrames(bool aSearchFrames) { return _to SetSearchFrames(aSearchFrames); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERFIND(_to) \
  NS_IMETHOD FindNext(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindNext(_retval); } \
  NS_IMETHOD GetSearchString(char16_t * *aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchString(aSearchString); } \
  NS_IMETHOD SetSearchString(const char16_t * aSearchString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchString(aSearchString); } \
  NS_IMETHOD GetFindBackwards(bool *aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFindBackwards(aFindBackwards); } \
  NS_IMETHOD SetFindBackwards(bool aFindBackwards) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFindBackwards(aFindBackwards); } \
  NS_IMETHOD GetWrapFind(bool *aWrapFind) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrapFind(aWrapFind); } \
  NS_IMETHOD SetWrapFind(bool aWrapFind) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrapFind(aWrapFind); } \
  NS_IMETHOD GetEntireWord(bool *aEntireWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntireWord(aEntireWord); } \
  NS_IMETHOD SetEntireWord(bool aEntireWord) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEntireWord(aEntireWord); } \
  NS_IMETHOD GetMatchCase(bool *aMatchCase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatchCase(aMatchCase); } \
  NS_IMETHOD SetMatchCase(bool aMatchCase) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMatchCase(aMatchCase); } \
  NS_IMETHOD GetSearchFrames(bool *aSearchFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchFrames(aSearchFrames); } \
  NS_IMETHOD SetSearchFrames(bool aSearchFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchFrames(aSearchFrames); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserFind : public nsIWebBrowserFind
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERFIND

  nsWebBrowserFind();

private:
  ~nsWebBrowserFind();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserFind, nsIWebBrowserFind)

nsWebBrowserFind::nsWebBrowserFind()
{
  /* member initializers and constructor code */
}

nsWebBrowserFind::~nsWebBrowserFind()
{
  /* destructor code */
}

/* boolean findNext (); */
NS_IMETHODIMP nsWebBrowserFind::FindNext(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring searchString; */
NS_IMETHODIMP nsWebBrowserFind::GetSearchString(char16_t * *aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFind::SetSearchString(const char16_t * aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean findBackwards; */
NS_IMETHODIMP nsWebBrowserFind::GetFindBackwards(bool *aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFind::SetFindBackwards(bool aFindBackwards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean wrapFind; */
NS_IMETHODIMP nsWebBrowserFind::GetWrapFind(bool *aWrapFind)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFind::SetWrapFind(bool aWrapFind)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean entireWord; */
NS_IMETHODIMP nsWebBrowserFind::GetEntireWord(bool *aEntireWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFind::SetEntireWord(bool aEntireWord)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean matchCase; */
NS_IMETHODIMP nsWebBrowserFind::GetMatchCase(bool *aMatchCase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFind::SetMatchCase(bool aMatchCase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean searchFrames; */
NS_IMETHODIMP nsWebBrowserFind::GetSearchFrames(bool *aSearchFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFind::SetSearchFrames(bool aSearchFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebBrowserFindInFrames */
#define NS_IWEBBROWSERFINDINFRAMES_IID_STR "e0f5d182-34bc-11d5-be5b-b760676c6ebc"

#define NS_IWEBBROWSERFINDINFRAMES_IID \
  {0xe0f5d182, 0x34bc, 0x11d5, \
    { 0xbe, 0x5b, 0xb7, 0x60, 0x67, 0x6c, 0x6e, 0xbc }}

class NS_NO_VTABLE nsIWebBrowserFindInFrames : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERFINDINFRAMES_IID)

  /* attribute nsIDOMWindow currentSearchFrame; */
  NS_IMETHOD GetCurrentSearchFrame(nsIDOMWindow * *aCurrentSearchFrame) = 0;
  NS_IMETHOD SetCurrentSearchFrame(nsIDOMWindow *aCurrentSearchFrame) = 0;

  /* attribute nsIDOMWindow rootSearchFrame; */
  NS_IMETHOD GetRootSearchFrame(nsIDOMWindow * *aRootSearchFrame) = 0;
  NS_IMETHOD SetRootSearchFrame(nsIDOMWindow *aRootSearchFrame) = 0;

  /* attribute boolean searchSubframes; */
  NS_IMETHOD GetSearchSubframes(bool *aSearchSubframes) = 0;
  NS_IMETHOD SetSearchSubframes(bool aSearchSubframes) = 0;

  /* attribute boolean searchParentFrames; */
  NS_IMETHOD GetSearchParentFrames(bool *aSearchParentFrames) = 0;
  NS_IMETHOD SetSearchParentFrames(bool aSearchParentFrames) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserFindInFrames, NS_IWEBBROWSERFINDINFRAMES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERFINDINFRAMES \
  NS_IMETHOD GetCurrentSearchFrame(nsIDOMWindow * *aCurrentSearchFrame); \
  NS_IMETHOD SetCurrentSearchFrame(nsIDOMWindow *aCurrentSearchFrame); \
  NS_IMETHOD GetRootSearchFrame(nsIDOMWindow * *aRootSearchFrame); \
  NS_IMETHOD SetRootSearchFrame(nsIDOMWindow *aRootSearchFrame); \
  NS_IMETHOD GetSearchSubframes(bool *aSearchSubframes); \
  NS_IMETHOD SetSearchSubframes(bool aSearchSubframes); \
  NS_IMETHOD GetSearchParentFrames(bool *aSearchParentFrames); \
  NS_IMETHOD SetSearchParentFrames(bool aSearchParentFrames); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERFINDINFRAMES(_to) \
  NS_IMETHOD GetCurrentSearchFrame(nsIDOMWindow * *aCurrentSearchFrame) { return _to GetCurrentSearchFrame(aCurrentSearchFrame); } \
  NS_IMETHOD SetCurrentSearchFrame(nsIDOMWindow *aCurrentSearchFrame) { return _to SetCurrentSearchFrame(aCurrentSearchFrame); } \
  NS_IMETHOD GetRootSearchFrame(nsIDOMWindow * *aRootSearchFrame) { return _to GetRootSearchFrame(aRootSearchFrame); } \
  NS_IMETHOD SetRootSearchFrame(nsIDOMWindow *aRootSearchFrame) { return _to SetRootSearchFrame(aRootSearchFrame); } \
  NS_IMETHOD GetSearchSubframes(bool *aSearchSubframes) { return _to GetSearchSubframes(aSearchSubframes); } \
  NS_IMETHOD SetSearchSubframes(bool aSearchSubframes) { return _to SetSearchSubframes(aSearchSubframes); } \
  NS_IMETHOD GetSearchParentFrames(bool *aSearchParentFrames) { return _to GetSearchParentFrames(aSearchParentFrames); } \
  NS_IMETHOD SetSearchParentFrames(bool aSearchParentFrames) { return _to SetSearchParentFrames(aSearchParentFrames); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERFINDINFRAMES(_to) \
  NS_IMETHOD GetCurrentSearchFrame(nsIDOMWindow * *aCurrentSearchFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentSearchFrame(aCurrentSearchFrame); } \
  NS_IMETHOD SetCurrentSearchFrame(nsIDOMWindow *aCurrentSearchFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentSearchFrame(aCurrentSearchFrame); } \
  NS_IMETHOD GetRootSearchFrame(nsIDOMWindow * *aRootSearchFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootSearchFrame(aRootSearchFrame); } \
  NS_IMETHOD SetRootSearchFrame(nsIDOMWindow *aRootSearchFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRootSearchFrame(aRootSearchFrame); } \
  NS_IMETHOD GetSearchSubframes(bool *aSearchSubframes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchSubframes(aSearchSubframes); } \
  NS_IMETHOD SetSearchSubframes(bool aSearchSubframes) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchSubframes(aSearchSubframes); } \
  NS_IMETHOD GetSearchParentFrames(bool *aSearchParentFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchParentFrames(aSearchParentFrames); } \
  NS_IMETHOD SetSearchParentFrames(bool aSearchParentFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchParentFrames(aSearchParentFrames); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserFindInFrames : public nsIWebBrowserFindInFrames
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERFINDINFRAMES

  nsWebBrowserFindInFrames();

private:
  ~nsWebBrowserFindInFrames();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserFindInFrames, nsIWebBrowserFindInFrames)

nsWebBrowserFindInFrames::nsWebBrowserFindInFrames()
{
  /* member initializers and constructor code */
}

nsWebBrowserFindInFrames::~nsWebBrowserFindInFrames()
{
  /* destructor code */
}

/* attribute nsIDOMWindow currentSearchFrame; */
NS_IMETHODIMP nsWebBrowserFindInFrames::GetCurrentSearchFrame(nsIDOMWindow * *aCurrentSearchFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFindInFrames::SetCurrentSearchFrame(nsIDOMWindow *aCurrentSearchFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindow rootSearchFrame; */
NS_IMETHODIMP nsWebBrowserFindInFrames::GetRootSearchFrame(nsIDOMWindow * *aRootSearchFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFindInFrames::SetRootSearchFrame(nsIDOMWindow *aRootSearchFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean searchSubframes; */
NS_IMETHODIMP nsWebBrowserFindInFrames::GetSearchSubframes(bool *aSearchSubframes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFindInFrames::SetSearchSubframes(bool aSearchSubframes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean searchParentFrames; */
NS_IMETHODIMP nsWebBrowserFindInFrames::GetSearchParentFrames(bool *aSearchParentFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserFindInFrames::SetSearchParentFrames(bool aSearchParentFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserFind_h__ */
