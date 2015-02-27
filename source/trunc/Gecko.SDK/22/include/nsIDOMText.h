/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIDOMText.idl
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
#define NS_IDOMTEXT_IID_STR "3de88cc9-1462-4bb8-a2fc-845b132547ac"

#define NS_IDOMTEXT_IID \
  {0x3de88cc9, 0x1462, 0x4bb8, \
    { 0xa2, 0xfc, 0x84, 0x5b, 0x13, 0x25, 0x47, 0xac }}

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
