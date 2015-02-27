/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIUnicharLineInputStream.idl
 */

#ifndef __gen_nsIUnicharLineInputStream_h__
#define __gen_nsIUnicharLineInputStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUnicharLineInputStream */
#define NS_IUNICHARLINEINPUTSTREAM_IID_STR "67f42475-ba80-40f8-ac0b-649c89230184"

#define NS_IUNICHARLINEINPUTSTREAM_IID \
  {0x67f42475, 0xba80, 0x40f8, \
    { 0xac, 0x0b, 0x64, 0x9c, 0x89, 0x23, 0x01, 0x84 }}

class NS_NO_VTABLE nsIUnicharLineInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNICHARLINEINPUTSTREAM_IID)

  /* boolean readLine (out AString aLine); */
  NS_IMETHOD ReadLine(nsAString & aLine, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUnicharLineInputStream, NS_IUNICHARLINEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNICHARLINEINPUTSTREAM \
  NS_IMETHOD ReadLine(nsAString & aLine, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNICHARLINEINPUTSTREAM(_to) \
  NS_IMETHOD ReadLine(nsAString & aLine, bool *_retval) { return _to ReadLine(aLine, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNICHARLINEINPUTSTREAM(_to) \
  NS_IMETHOD ReadLine(nsAString & aLine, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadLine(aLine, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUnicharLineInputStream : public nsIUnicharLineInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNICHARLINEINPUTSTREAM

  nsUnicharLineInputStream();

private:
  ~nsUnicharLineInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUnicharLineInputStream, nsIUnicharLineInputStream)

nsUnicharLineInputStream::nsUnicharLineInputStream()
{
  /* member initializers and constructor code */
}

nsUnicharLineInputStream::~nsUnicharLineInputStream()
{
  /* destructor code */
}

/* boolean readLine (out AString aLine); */
NS_IMETHODIMP nsUnicharLineInputStream::ReadLine(nsAString & aLine, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUnicharLineInputStream_h__ */
