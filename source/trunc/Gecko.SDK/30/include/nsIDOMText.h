/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMText.idl
 */

#ifndef __gen_nsIDOMText_h__
#define __gen_nsIDOMText_h__


#ifndef __gen_nsIDOMCharacterData_h__
#include "nsIDOMCharacterData.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMText */
#define NS_IDOMTEXT_IID_STR "d14d13b4-21d5-49e2-8d59-76a24156db54"

#define NS_IDOMTEXT_IID \
  {0xd14d13b4, 0x21d5, 0x49e2, \
    { 0x8d, 0x59, 0x76, 0xa2, 0x41, 0x56, 0xdb, 0x54 }}

class NS_NO_VTABLE nsIDOMText : public nsIDOMCharacterData {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTEXT_IID)

  /* nsIDOMText splitText (in unsigned long offset) raises (DOMException); */
  NS_IMETHOD SplitText(uint32_t offset, nsIDOMText * *_retval) = 0;

  /* readonly attribute DOMString wholeText; */
  NS_IMETHOD GetWholeText(nsAString & aWholeText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMText, NS_IDOMTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTEXT \
  NS_IMETHOD SplitText(uint32_t offset, nsIDOMText * *_retval); \
  NS_IMETHOD GetWholeText(nsAString & aWholeText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTEXT(_to) \
  NS_IMETHOD SplitText(uint32_t offset, nsIDOMText * *_retval) { return _to SplitText(offset, _retval); } \
  NS_IMETHOD GetWholeText(nsAString & aWholeText) { return _to GetWholeText(aWholeText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTEXT(_to) \
  NS_IMETHOD SplitText(uint32_t offset, nsIDOMText * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SplitText(offset, _retval); } \
  NS_IMETHOD GetWholeText(nsAString & aWholeText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWholeText(aWholeText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMText : public nsIDOMText
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTEXT

  nsDOMText();

private:
  ~nsDOMText();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMText, nsIDOMText)

nsDOMText::nsDOMText()
{
  /* member initializers and constructor code */
}

nsDOMText::~nsDOMText()
{
  /* destructor code */
}

/* nsIDOMText splitText (in unsigned long offset) raises (DOMException); */
NS_IMETHODIMP nsDOMText::SplitText(uint32_t offset, nsIDOMText * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString wholeText; */
NS_IMETHODIMP nsDOMText::GetWholeText(nsAString & aWholeText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMText_h__ */
