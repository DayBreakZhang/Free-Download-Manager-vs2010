/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMutableArray.idl
 */

#ifndef __gen_nsIMutableArray_h__
#define __gen_nsIMutableArray_h__


#ifndef __gen_nsIArray_h__
#include "nsIArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMutableArray */
#define NS_IMUTABLEARRAY_IID_STR "af059da0-c85b-40ec-af07-ae4bfdc192cc"

#define NS_IMUTABLEARRAY_IID \
  {0xaf059da0, 0xc85b, 0x40ec, \
    { 0xaf, 0x07, 0xae, 0x4b, 0xfd, 0xc1, 0x92, 0xcc }}

class NS_NO_VTABLE nsIMutableArray : public nsIArray {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMUTABLEARRAY_IID)

  /* void appendElement (in nsISupports element, in boolean weak); */
  NS_IMETHOD AppendElement(nsISupports *element, bool weak) = 0;

  /* void removeElementAt (in unsigned long index); */
  NS_IMETHOD RemoveElementAt(uint32_t index) = 0;

  /* void insertElementAt (in nsISupports element, in unsigned long index, in boolean weak); */
  NS_IMETHOD InsertElementAt(nsISupports *element, uint32_t index, bool weak) = 0;

  /* void replaceElementAt (in nsISupports element, in unsigned long index, in boolean weak); */
  NS_IMETHOD ReplaceElementAt(nsISupports *element, uint32_t index, bool weak) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMutableArray, NS_IMUTABLEARRAY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMUTABLEARRAY \
  NS_IMETHOD AppendElement(nsISupports *element, bool weak); \
  NS_IMETHOD RemoveElementAt(uint32_t index); \
  NS_IMETHOD InsertElementAt(nsISupports *element, uint32_t index, bool weak); \
  NS_IMETHOD ReplaceElementAt(nsISupports *element, uint32_t index, bool weak); \
  NS_IMETHOD Clear(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMUTABLEARRAY(_to) \
  NS_IMETHOD AppendElement(nsISupports *element, bool weak) { return _to AppendElement(element, weak); } \
  NS_IMETHOD RemoveElementAt(uint32_t index) { return _to RemoveElementAt(index); } \
  NS_IMETHOD InsertElementAt(nsISupports *element, uint32_t index, bool weak) { return _to InsertElementAt(element, index, weak); } \
  NS_IMETHOD ReplaceElementAt(nsISupports *element, uint32_t index, bool weak) { return _to ReplaceElementAt(element, index, weak); } \
  NS_IMETHOD Clear(void) { return _to Clear(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMUTABLEARRAY(_to) \
  NS_IMETHOD AppendElement(nsISupports *element, bool weak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendElement(element, weak); } \
  NS_IMETHOD RemoveElementAt(uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveElementAt(index); } \
  NS_IMETHOD InsertElementAt(nsISupports *element, uint32_t index, bool weak) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertElementAt(element, index, weak); } \
  NS_IMETHOD ReplaceElementAt(nsISupports *element, uint32_t index, bool weak) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceElementAt(element, index, weak); } \
  NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMutableArray : public nsIMutableArray
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMUTABLEARRAY

  nsMutableArray();

private:
  ~nsMutableArray();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMutableArray, nsIMutableArray)

nsMutableArray::nsMutableArray()
{
  /* member initializers and constructor code */
}

nsMutableArray::~nsMutableArray()
{
  /* destructor code */
}

/* void appendElement (in nsISupports element, in boolean weak); */
NS_IMETHODIMP nsMutableArray::AppendElement(nsISupports *element, bool weak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeElementAt (in unsigned long index); */
NS_IMETHODIMP nsMutableArray::RemoveElementAt(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertElementAt (in nsISupports element, in unsigned long index, in boolean weak); */
NS_IMETHODIMP nsMutableArray::InsertElementAt(nsISupports *element, uint32_t index, bool weak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceElementAt (in nsISupports element, in unsigned long index, in boolean weak); */
NS_IMETHODIMP nsMutableArray::ReplaceElementAt(nsISupports *element, uint32_t index, bool weak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsMutableArray::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMutableArray_h__ */
