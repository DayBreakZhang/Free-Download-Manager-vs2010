/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleTextRange.idl
 */

#ifndef __gen_nsIAccessibleTextRange_h__
#define __gen_nsIAccessibleTextRange_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */


/* starting interface:    nsIAccessibleTextRange */
#define NS_IACCESSIBLETEXTRANGE_IID_STR "6fe17c33-6709-4d7a-9ba0-3d448c4b3ef4"

#define NS_IACCESSIBLETEXTRANGE_IID \
  {0x6fe17c33, 0x6709, 0x4d7a, \
    { 0x9b, 0xa0, 0x3d, 0x44, 0x8c, 0x4b, 0x3e, 0xf4 }}

class NS_NO_VTABLE nsIAccessibleTextRange : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETEXTRANGE_IID)

  /* readonly attribute nsIAccessible startContainer; */
  NS_IMETHOD GetStartContainer(nsIAccessible * *aStartContainer) = 0;

  /* readonly attribute long startOffset; */
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) = 0;

  /* readonly attribute nsIAccessible endContainer; */
  NS_IMETHOD GetEndContainer(nsIAccessible * *aEndContainer) = 0;

  /* readonly attribute long endOffset; */
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) = 0;

  /* readonly attribute AString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTextRange, NS_IACCESSIBLETEXTRANGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETEXTRANGE \
  NS_IMETHOD GetStartContainer(nsIAccessible * *aStartContainer); \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset); \
  NS_IMETHOD GetEndContainer(nsIAccessible * *aEndContainer); \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset); \
  NS_IMETHOD GetText(nsAString & aText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETEXTRANGE(_to) \
  NS_IMETHOD GetStartContainer(nsIAccessible * *aStartContainer) { return _to GetStartContainer(aStartContainer); } \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) { return _to GetStartOffset(aStartOffset); } \
  NS_IMETHOD GetEndContainer(nsIAccessible * *aEndContainer) { return _to GetEndContainer(aEndContainer); } \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) { return _to GetEndOffset(aEndOffset); } \
  NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETEXTRANGE(_to) \
  NS_IMETHOD GetStartContainer(nsIAccessible * *aStartContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartContainer(aStartContainer); } \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartOffset(aStartOffset); } \
  NS_IMETHOD GetEndContainer(nsIAccessible * *aEndContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndContainer(aEndContainer); } \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndOffset(aEndOffset); } \
  NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTextRange : public nsIAccessibleTextRange
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETEXTRANGE

  nsAccessibleTextRange();

private:
  ~nsAccessibleTextRange();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleTextRange, nsIAccessibleTextRange)

nsAccessibleTextRange::nsAccessibleTextRange()
{
  /* member initializers and constructor code */
}

nsAccessibleTextRange::~nsAccessibleTextRange()
{
  /* destructor code */
}

/* readonly attribute nsIAccessible startContainer; */
NS_IMETHODIMP nsAccessibleTextRange::GetStartContainer(nsIAccessible * *aStartContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long startOffset; */
NS_IMETHODIMP nsAccessibleTextRange::GetStartOffset(int32_t *aStartOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible endContainer; */
NS_IMETHODIMP nsAccessibleTextRange::GetEndContainer(nsIAccessible * *aEndContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long endOffset; */
NS_IMETHODIMP nsAccessibleTextRange::GetEndOffset(int32_t *aEndOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString text; */
NS_IMETHODIMP nsAccessibleTextRange::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTextRange_h__ */
