/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBidiKeyboard.idl
 */

#ifndef __gen_nsIBidiKeyboard_h__
#define __gen_nsIBidiKeyboard_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBidiKeyboard */
#define NS_IBIDIKEYBOARD_IID_STR "0d53579c-8f40-4bcf-9b87-61979c09f924"

#define NS_IBIDIKEYBOARD_IID \
  {0x0d53579c, 0x8f40, 0x4bcf, \
    { 0x9b, 0x87, 0x61, 0x97, 0x9c, 0x09, 0xf9, 0x24 }}

class NS_NO_VTABLE nsIBidiKeyboard : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBIDIKEYBOARD_IID)

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

  /* boolean isLangRTL (); */
  NS_IMETHOD IsLangRTL(bool *_retval) = 0;

  /* readonly attribute boolean haveBidiKeyboards; */
  NS_IMETHOD GetHaveBidiKeyboards(bool *aHaveBidiKeyboards) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBidiKeyboard, NS_IBIDIKEYBOARD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBIDIKEYBOARD \
  NS_IMETHOD Reset(void); \
  NS_IMETHOD IsLangRTL(bool *_retval); \
  NS_IMETHOD GetHaveBidiKeyboards(bool *aHaveBidiKeyboards); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBIDIKEYBOARD(_to) \
  NS_IMETHOD Reset(void) { return _to Reset(); } \
  NS_IMETHOD IsLangRTL(bool *_retval) { return _to IsLangRTL(_retval); } \
  NS_IMETHOD GetHaveBidiKeyboards(bool *aHaveBidiKeyboards) { return _to GetHaveBidiKeyboards(aHaveBidiKeyboards); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBIDIKEYBOARD(_to) \
  NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_IMETHOD IsLangRTL(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLangRTL(_retval); } \
  NS_IMETHOD GetHaveBidiKeyboards(bool *aHaveBidiKeyboards) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHaveBidiKeyboards(aHaveBidiKeyboards); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBidiKeyboard : public nsIBidiKeyboard
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBIDIKEYBOARD

  nsBidiKeyboard();

private:
  ~nsBidiKeyboard();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBidiKeyboard, nsIBidiKeyboard)

nsBidiKeyboard::nsBidiKeyboard()
{
  /* member initializers and constructor code */
}

nsBidiKeyboard::~nsBidiKeyboard()
{
  /* destructor code */
}

/* void reset (); */
NS_IMETHODIMP nsBidiKeyboard::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLangRTL (); */
NS_IMETHODIMP nsBidiKeyboard::IsLangRTL(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean haveBidiKeyboards; */
NS_IMETHODIMP nsBidiKeyboard::GetHaveBidiKeyboards(bool *aHaveBidiKeyboards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBidiKeyboard_h__ */
