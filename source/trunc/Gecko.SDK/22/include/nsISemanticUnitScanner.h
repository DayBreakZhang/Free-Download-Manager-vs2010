/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/intl/lwbrk/idl/nsISemanticUnitScanner.idl
 */

#ifndef __gen_nsISemanticUnitScanner_h__
#define __gen_nsISemanticUnitScanner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// {ADF42751-1CEF-4ad2-AA8E-BCB849D8D31F}
#define NS_SEMANTICUNITSCANNER_CID { 0xadf42751, 0x1cef, 0x4ad2, { 0xaa, 0x8e, 0xbc, 0xb8, 0x49, 0xd8, 0xd3, 0x1f}}
#define NS_SEMANTICUNITSCANNER_CONTRACTID "@mozilla.org/intl/semanticunitscanner;1"

/* starting interface:    nsISemanticUnitScanner */
#define NS_ISEMANTICUNITSCANNER_IID_STR "9f620be4-e535-11d6-b254-00039310a47a"

#define NS_ISEMANTICUNITSCANNER_IID \
  {0x9f620be4, 0xe535, 0x11d6, \
    { 0xb2, 0x54, 0x00, 0x03, 0x93, 0x10, 0xa4, 0x7a }}

class NS_NO_VTABLE nsISemanticUnitScanner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEMANTICUNITSCANNER_IID)

  /* void start (in string characterSet); */
  NS_IMETHOD Start(const char * characterSet) = 0;

  /* boolean next (in wstring text, in long length, in long pos, in boolean isLastBuffer, out long begin, out long end); */
  NS_IMETHOD Next(const PRUnichar * text, int32_t length, int32_t pos, bool isLastBuffer, int32_t *begin, int32_t *end, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISemanticUnitScanner, NS_ISEMANTICUNITSCANNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEMANTICUNITSCANNER \
  NS_IMETHOD Start(const char * characterSet); \
  NS_IMETHOD Next(const PRUnichar * text, int32_t length, int32_t pos, bool isLastBuffer, int32_t *begin, int32_t *end, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEMANTICUNITSCANNER(_to) \
  NS_IMETHOD Start(const char * characterSet) { return _to Start(characterSet); } \
  NS_IMETHOD Next(const PRUnichar * text, int32_t length, int32_t pos, bool isLastBuffer, int32_t *begin, int32_t *end, bool *_retval) { return _to Next(text, length, pos, isLastBuffer, begin, end, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEMANTICUNITSCANNER(_to) \
  NS_IMETHOD Start(const char * characterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(characterSet); } \
  NS_IMETHOD Next(const PRUnichar * text, int32_t length, int32_t pos, bool isLastBuffer, int32_t *begin, int32_t *end, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Next(text, length, pos, isLastBuffer, begin, end, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSemanticUnitScanner : public nsISemanticUnitScanner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEMANTICUNITSCANNER

  nsSemanticUnitScanner();

private:
  ~nsSemanticUnitScanner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSemanticUnitScanner, nsISemanticUnitScanner)

nsSemanticUnitScanner::nsSemanticUnitScanner()
{
  /* member initializers and constructor code */
}

nsSemanticUnitScanner::~nsSemanticUnitScanner()
{
  /* destructor code */
}

/* void start (in string characterSet); */
NS_IMETHODIMP nsSemanticUnitScanner::Start(const char * characterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean next (in wstring text, in long length, in long pos, in boolean isLastBuffer, out long begin, out long end); */
NS_IMETHODIMP nsSemanticUnitScanner::Next(const PRUnichar * text, int32_t length, int32_t pos, bool isLastBuffer, int32_t *begin, int32_t *end, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISemanticUnitScanner_h__ */
