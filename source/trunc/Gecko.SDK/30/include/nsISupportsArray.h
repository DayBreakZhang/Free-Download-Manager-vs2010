/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISupportsArray.idl
 */

#ifndef __gen_nsISupportsArray_h__
#define __gen_nsISupportsArray_h__


#ifndef __gen_nsICollection_h__
#include "nsICollection.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

class nsIBidirectionalEnumerator;
class nsISupportsArray;
 
#define NS_SUPPORTSARRAY_CID                         \
{ /* bda17d50-0d6b-11d3-9331-00104ba0fd40 */         \
    0xbda17d50,                                      \
    0x0d6b,                                          \
    0x11d3,                                          \
    {0x93, 0x31, 0x00, 0x10, 0x4b, 0xa0, 0xfd, 0x40} \
}
#define NS_SUPPORTSARRAY_CONTRACTID "@mozilla.org/supports-array;1"
 

/* starting interface:    nsISupportsArray */
#define NS_ISUPPORTSARRAY_IID_STR "241addc8-3608-4e73-8083-2fd6fa09eba2"

#define NS_ISUPPORTSARRAY_IID \
  {0x241addc8, 0x3608, 0x4e73, \
    { 0x80, 0x83, 0x2f, 0xd6, 0xfa, 0x09, 0xeb, 0xa2 }}

class NS_NO_VTABLE nsISupportsArray : public nsICollection {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISUPPORTSARRAY_IID)

  /* [notxpcom] boolean Equals ([const] in nsISupportsArray other); */
  NS_IMETHOD_(bool) Equals(const nsISupportsArray *other) = 0;

  /* [notxpcom] long IndexOf ([const] in nsISupports aPossibleElement); */
  NS_IMETHOD_(int32_t) IndexOf(const nsISupports *aPossibleElement) = 0;

  /* [notxpcom] long IndexOfStartingAt ([const] in nsISupports aPossibleElement, in unsigned long aStartIndex); */
  NS_IMETHOD_(int32_t) IndexOfStartingAt(const nsISupports *aPossibleElement, uint32_t aStartIndex) = 0;

  /* [notxpcom] long LastIndexOf ([const] in nsISupports aPossibleElement); */
  NS_IMETHOD_(int32_t) LastIndexOf(const nsISupports *aPossibleElement) = 0;

  /* long GetIndexOf (in nsISupports aPossibleElement); */
  NS_IMETHOD GetIndexOf(nsISupports *aPossibleElement, int32_t *_retval) = 0;

  /* long GetIndexOfStartingAt (in nsISupports aPossibleElement, in unsigned long aStartIndex); */
  NS_IMETHOD GetIndexOfStartingAt(nsISupports *aPossibleElement, uint32_t aStartIndex, int32_t *_retval) = 0;

  /* long GetLastIndexOf (in nsISupports aPossibleElement); */
  NS_IMETHOD GetLastIndexOf(nsISupports *aPossibleElement, int32_t *_retval) = 0;

  /* [notxpcom] boolean InsertElementAt (in nsISupports aElement, in unsigned long aIndex); */
  NS_IMETHOD_(bool) InsertElementAt(nsISupports *aElement, uint32_t aIndex) = 0;

  /* [notxpcom] boolean ReplaceElementAt (in nsISupports aElement, in unsigned long aIndex); */
  NS_IMETHOD_(bool) ReplaceElementAt(nsISupports *aElement, uint32_t aIndex) = 0;

  /* [notxpcom] boolean RemoveElementAt (in unsigned long aIndex); */
  NS_IMETHOD_(bool) RemoveElementAt(uint32_t aIndex) = 0;

  /* [notxpcom] boolean RemoveLastElement ([const] in nsISupports aElement); */
  NS_IMETHOD_(bool) RemoveLastElement(const nsISupports *aElement) = 0;

  /* void DeleteLastElement (in nsISupports aElement); */
  NS_IMETHOD DeleteLastElement(nsISupports *aElement) = 0;

  /* void DeleteElementAt (in unsigned long aIndex); */
  NS_IMETHOD DeleteElementAt(uint32_t aIndex) = 0;

  /* [notxpcom] boolean AppendElements (in nsISupportsArray aElements); */
  NS_IMETHOD_(bool) AppendElements(nsISupportsArray *aElements) = 0;

  /* void Compact (); */
  NS_IMETHOD Compact(void) = 0;

  /* nsISupportsArray clone (); */
  NS_IMETHOD Clone(nsISupportsArray * *_retval) = 0;

  /* [notxpcom] boolean MoveElement (in long aFrom, in long aTo); */
  NS_IMETHOD_(bool) MoveElement(int32_t aFrom, int32_t aTo) = 0;

  /* [notxpcom] boolean InsertElementsAt (in nsISupportsArray aOther, in unsigned long aIndex); */
  NS_IMETHOD_(bool) InsertElementsAt(nsISupportsArray *aOther, uint32_t aIndex) = 0;

  /* [notxpcom] boolean RemoveElementsAt (in unsigned long aIndex, in unsigned long aCount); */
  NS_IMETHOD_(bool) RemoveElementsAt(uint32_t aIndex, uint32_t aCount) = 0;

  /* [notxpcom] boolean SizeTo (in long aSize); */
  NS_IMETHOD_(bool) SizeTo(int32_t aSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISupportsArray, NS_ISUPPORTSARRAY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISUPPORTSARRAY \
  NS_IMETHOD_(bool) Equals(const nsISupportsArray *other); \
  NS_IMETHOD_(int32_t) IndexOf(const nsISupports *aPossibleElement); \
  NS_IMETHOD_(int32_t) IndexOfStartingAt(const nsISupports *aPossibleElement, uint32_t aStartIndex); \
  NS_IMETHOD_(int32_t) LastIndexOf(const nsISupports *aPossibleElement); \
  NS_IMETHOD GetIndexOf(nsISupports *aPossibleElement, int32_t *_retval); \
  NS_IMETHOD GetIndexOfStartingAt(nsISupports *aPossibleElement, uint32_t aStartIndex, int32_t *_retval); \
  NS_IMETHOD GetLastIndexOf(nsISupports *aPossibleElement, int32_t *_retval); \
  NS_IMETHOD_(bool) InsertElementAt(nsISupports *aElement, uint32_t aIndex); \
  NS_IMETHOD_(bool) ReplaceElementAt(nsISupports *aElement, uint32_t aIndex); \
  NS_IMETHOD_(bool) RemoveElementAt(uint32_t aIndex); \
  NS_IMETHOD_(bool) RemoveLastElement(const nsISupports *aElement); \
  NS_IMETHOD DeleteLastElement(nsISupports *aElement); \
  NS_IMETHOD DeleteElementAt(uint32_t aIndex); \
  NS_IMETHOD_(bool) AppendElements(nsISupportsArray *aElements); \
  NS_IMETHOD Compact(void); \
  NS_IMETHOD Clone(nsISupportsArray * *_retval); \
  NS_IMETHOD_(bool) MoveElement(int32_t aFrom, int32_t aTo); \
  NS_IMETHOD_(bool) InsertElementsAt(nsISupportsArray *aOther, uint32_t aIndex); \
  NS_IMETHOD_(bool) RemoveElementsAt(uint32_t aIndex, uint32_t aCount); \
  NS_IMETHOD_(bool) SizeTo(int32_t aSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISUPPORTSARRAY(_to) \
  NS_IMETHOD_(bool) Equals(const nsISupportsArray *other) { return _to Equals(other); } \
  NS_IMETHOD_(int32_t) IndexOf(const nsISupports *aPossibleElement) { return _to IndexOf(aPossibleElement); } \
  NS_IMETHOD_(int32_t) IndexOfStartingAt(const nsISupports *aPossibleElement, uint32_t aStartIndex) { return _to IndexOfStartingAt(aPossibleElement, aStartIndex); } \
  NS_IMETHOD_(int32_t) LastIndexOf(const nsISupports *aPossibleElement) { return _to LastIndexOf(aPossibleElement); } \
  NS_IMETHOD GetIndexOf(nsISupports *aPossibleElement, int32_t *_retval) { return _to GetIndexOf(aPossibleElement, _retval); } \
  NS_IMETHOD GetIndexOfStartingAt(nsISupports *aPossibleElement, uint32_t aStartIndex, int32_t *_retval) { return _to GetIndexOfStartingAt(aPossibleElement, aStartIndex, _retval); } \
  NS_IMETHOD GetLastIndexOf(nsISupports *aPossibleElement, int32_t *_retval) { return _to GetLastIndexOf(aPossibleElement, _retval); } \
  NS_IMETHOD_(bool) InsertElementAt(nsISupports *aElement, uint32_t aIndex) { return _to InsertElementAt(aElement, aIndex); } \
  NS_IMETHOD_(bool) ReplaceElementAt(nsISupports *aElement, uint32_t aIndex) { return _to ReplaceElementAt(aElement, aIndex); } \
  NS_IMETHOD_(bool) RemoveElementAt(uint32_t aIndex) { return _to RemoveElementAt(aIndex); } \
  NS_IMETHOD_(bool) RemoveLastElement(const nsISupports *aElement) { return _to RemoveLastElement(aElement); } \
  NS_IMETHOD DeleteLastElement(nsISupports *aElement) { return _to DeleteLastElement(aElement); } \
  NS_IMETHOD DeleteElementAt(uint32_t aIndex) { return _to DeleteElementAt(aIndex); } \
  NS_IMETHOD_(bool) AppendElements(nsISupportsArray *aElements) { return _to AppendElements(aElements); } \
  NS_IMETHOD Compact(void) { return _to Compact(); } \
  NS_IMETHOD Clone(nsISupportsArray * *_retval) { return _to Clone(_retval); } \
  NS_IMETHOD_(bool) MoveElement(int32_t aFrom, int32_t aTo) { return _to MoveElement(aFrom, aTo); } \
  NS_IMETHOD_(bool) InsertElementsAt(nsISupportsArray *aOther, uint32_t aIndex) { return _to InsertElementsAt(aOther, aIndex); } \
  NS_IMETHOD_(bool) RemoveElementsAt(uint32_t aIndex, uint32_t aCount) { return _to RemoveElementsAt(aIndex, aCount); } \
  NS_IMETHOD_(bool) SizeTo(int32_t aSize) { return _to SizeTo(aSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISUPPORTSARRAY(_to) \
  NS_IMETHOD_(bool) Equals(const nsISupportsArray *other); \
  NS_IMETHOD_(int32_t) IndexOf(const nsISupports *aPossibleElement); \
  NS_IMETHOD_(int32_t) IndexOfStartingAt(const nsISupports *aPossibleElement, uint32_t aStartIndex); \
  NS_IMETHOD_(int32_t) LastIndexOf(const nsISupports *aPossibleElement); \
  NS_IMETHOD GetIndexOf(nsISupports *aPossibleElement, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOf(aPossibleElement, _retval); } \
  NS_IMETHOD GetIndexOfStartingAt(nsISupports *aPossibleElement, uint32_t aStartIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfStartingAt(aPossibleElement, aStartIndex, _retval); } \
  NS_IMETHOD GetLastIndexOf(nsISupports *aPossibleElement, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastIndexOf(aPossibleElement, _retval); } \
  NS_IMETHOD_(bool) InsertElementAt(nsISupports *aElement, uint32_t aIndex); \
  NS_IMETHOD_(bool) ReplaceElementAt(nsISupports *aElement, uint32_t aIndex); \
  NS_IMETHOD_(bool) RemoveElementAt(uint32_t aIndex); \
  NS_IMETHOD_(bool) RemoveLastElement(const nsISupports *aElement); \
  NS_IMETHOD DeleteLastElement(nsISupports *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteLastElement(aElement); } \
  NS_IMETHOD DeleteElementAt(uint32_t aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteElementAt(aIndex); } \
  NS_IMETHOD_(bool) AppendElements(nsISupportsArray *aElements); \
  NS_IMETHOD Compact(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Compact(); } \
  NS_IMETHOD Clone(nsISupportsArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_IMETHOD_(bool) MoveElement(int32_t aFrom, int32_t aTo); \
  NS_IMETHOD_(bool) InsertElementsAt(nsISupportsArray *aOther, uint32_t aIndex); \
  NS_IMETHOD_(bool) RemoveElementsAt(uint32_t aIndex, uint32_t aCount); \
  NS_IMETHOD_(bool) SizeTo(int32_t aSize); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSupportsArray : public nsISupportsArray
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISUPPORTSARRAY

  nsSupportsArray();

private:
  ~nsSupportsArray();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSupportsArray, nsISupportsArray)

nsSupportsArray::nsSupportsArray()
{
  /* member initializers and constructor code */
}

nsSupportsArray::~nsSupportsArray()
{
  /* destructor code */
}

/* [notxpcom] boolean Equals ([const] in nsISupportsArray other); */
NS_IMETHODIMP_(bool) nsSupportsArray::Equals(const nsISupportsArray *other)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] long IndexOf ([const] in nsISupports aPossibleElement); */
NS_IMETHODIMP_(int32_t) nsSupportsArray::IndexOf(const nsISupports *aPossibleElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] long IndexOfStartingAt ([const] in nsISupports aPossibleElement, in unsigned long aStartIndex); */
NS_IMETHODIMP_(int32_t) nsSupportsArray::IndexOfStartingAt(const nsISupports *aPossibleElement, uint32_t aStartIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] long LastIndexOf ([const] in nsISupports aPossibleElement); */
NS_IMETHODIMP_(int32_t) nsSupportsArray::LastIndexOf(const nsISupports *aPossibleElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetIndexOf (in nsISupports aPossibleElement); */
NS_IMETHODIMP nsSupportsArray::GetIndexOf(nsISupports *aPossibleElement, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetIndexOfStartingAt (in nsISupports aPossibleElement, in unsigned long aStartIndex); */
NS_IMETHODIMP nsSupportsArray::GetIndexOfStartingAt(nsISupports *aPossibleElement, uint32_t aStartIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetLastIndexOf (in nsISupports aPossibleElement); */
NS_IMETHODIMP nsSupportsArray::GetLastIndexOf(nsISupports *aPossibleElement, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean InsertElementAt (in nsISupports aElement, in unsigned long aIndex); */
NS_IMETHODIMP_(bool) nsSupportsArray::InsertElementAt(nsISupports *aElement, uint32_t aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean ReplaceElementAt (in nsISupports aElement, in unsigned long aIndex); */
NS_IMETHODIMP_(bool) nsSupportsArray::ReplaceElementAt(nsISupports *aElement, uint32_t aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean RemoveElementAt (in unsigned long aIndex); */
NS_IMETHODIMP_(bool) nsSupportsArray::RemoveElementAt(uint32_t aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean RemoveLastElement ([const] in nsISupports aElement); */
NS_IMETHODIMP_(bool) nsSupportsArray::RemoveLastElement(const nsISupports *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DeleteLastElement (in nsISupports aElement); */
NS_IMETHODIMP nsSupportsArray::DeleteLastElement(nsISupports *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DeleteElementAt (in unsigned long aIndex); */
NS_IMETHODIMP nsSupportsArray::DeleteElementAt(uint32_t aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean AppendElements (in nsISupportsArray aElements); */
NS_IMETHODIMP_(bool) nsSupportsArray::AppendElements(nsISupportsArray *aElements)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Compact (); */
NS_IMETHODIMP nsSupportsArray::Compact()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupportsArray clone (); */
NS_IMETHODIMP nsSupportsArray::Clone(nsISupportsArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean MoveElement (in long aFrom, in long aTo); */
NS_IMETHODIMP_(bool) nsSupportsArray::MoveElement(int32_t aFrom, int32_t aTo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean InsertElementsAt (in nsISupportsArray aOther, in unsigned long aIndex); */
NS_IMETHODIMP_(bool) nsSupportsArray::InsertElementsAt(nsISupportsArray *aOther, uint32_t aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean RemoveElementsAt (in unsigned long aIndex, in unsigned long aCount); */
NS_IMETHODIMP_(bool) nsSupportsArray::RemoveElementsAt(uint32_t aIndex, uint32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean SizeTo (in long aSize); */
NS_IMETHODIMP_(bool) nsSupportsArray::SizeTo(int32_t aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


// Construct and return a default implementation of nsISupportsArray:
extern nsresult
NS_NewISupportsArray(nsISupportsArray** aInstancePtrResult);

#endif /* __gen_nsISupportsArray_h__ */
