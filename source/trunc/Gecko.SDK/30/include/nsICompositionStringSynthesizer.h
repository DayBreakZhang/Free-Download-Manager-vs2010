/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICompositionStringSynthesizer.idl
 */

#ifndef __gen_nsICompositionStringSynthesizer_h__
#define __gen_nsICompositionStringSynthesizer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICompositionStringSynthesizer */
#define NS_ICOMPOSITIONSTRINGSYNTHESIZER_IID_STR "9a7d7851-8c0a-4061-9edc-60d6693f86c9"

#define NS_ICOMPOSITIONSTRINGSYNTHESIZER_IID \
  {0x9a7d7851, 0x8c0a, 0x4061, \
    { 0x9e, 0xdc, 0x60, 0xd6, 0x69, 0x3f, 0x86, 0xc9 }}

class NS_NO_VTABLE nsICompositionStringSynthesizer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMPOSITIONSTRINGSYNTHESIZER_IID)

  /* void setString (in AString aString); */
  NS_IMETHOD SetString(const nsAString & aString) = 0;

  enum {
    ATTR_RAWINPUT = 2U,
    ATTR_SELECTEDRAWTEXT = 3U,
    ATTR_CONVERTEDTEXT = 4U,
    ATTR_SELECTEDCONVERTEDTEXT = 5U
  };

  /* void appendClause (in unsigned long aLength, in unsigned long aAttribute); */
  NS_IMETHOD AppendClause(uint32_t aLength, uint32_t aAttribute) = 0;

  /* void setCaret (in unsigned long aOffset, in unsigned long aLength); */
  NS_IMETHOD SetCaret(uint32_t aOffset, uint32_t aLength) = 0;

  /* bool dispatchEvent (); */
  NS_IMETHOD DispatchEvent(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICompositionStringSynthesizer, NS_ICOMPOSITIONSTRINGSYNTHESIZER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMPOSITIONSTRINGSYNTHESIZER \
  NS_IMETHOD SetString(const nsAString & aString); \
  NS_IMETHOD AppendClause(uint32_t aLength, uint32_t aAttribute); \
  NS_IMETHOD SetCaret(uint32_t aOffset, uint32_t aLength); \
  NS_IMETHOD DispatchEvent(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMPOSITIONSTRINGSYNTHESIZER(_to) \
  NS_IMETHOD SetString(const nsAString & aString) { return _to SetString(aString); } \
  NS_IMETHOD AppendClause(uint32_t aLength, uint32_t aAttribute) { return _to AppendClause(aLength, aAttribute); } \
  NS_IMETHOD SetCaret(uint32_t aOffset, uint32_t aLength) { return _to SetCaret(aOffset, aLength); } \
  NS_IMETHOD DispatchEvent(bool *_retval) { return _to DispatchEvent(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMPOSITIONSTRINGSYNTHESIZER(_to) \
  NS_IMETHOD SetString(const nsAString & aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetString(aString); } \
  NS_IMETHOD AppendClause(uint32_t aLength, uint32_t aAttribute) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendClause(aLength, aAttribute); } \
  NS_IMETHOD SetCaret(uint32_t aOffset, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaret(aOffset, aLength); } \
  NS_IMETHOD DispatchEvent(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchEvent(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCompositionStringSynthesizer : public nsICompositionStringSynthesizer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMPOSITIONSTRINGSYNTHESIZER

  nsCompositionStringSynthesizer();

private:
  ~nsCompositionStringSynthesizer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCompositionStringSynthesizer, nsICompositionStringSynthesizer)

nsCompositionStringSynthesizer::nsCompositionStringSynthesizer()
{
  /* member initializers and constructor code */
}

nsCompositionStringSynthesizer::~nsCompositionStringSynthesizer()
{
  /* destructor code */
}

/* void setString (in AString aString); */
NS_IMETHODIMP nsCompositionStringSynthesizer::SetString(const nsAString & aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendClause (in unsigned long aLength, in unsigned long aAttribute); */
NS_IMETHODIMP nsCompositionStringSynthesizer::AppendClause(uint32_t aLength, uint32_t aAttribute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaret (in unsigned long aOffset, in unsigned long aLength); */
NS_IMETHODIMP nsCompositionStringSynthesizer::SetCaret(uint32_t aOffset, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool dispatchEvent (); */
NS_IMETHODIMP nsCompositionStringSynthesizer::DispatchEvent(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICompositionStringSynthesizer_h__ */
