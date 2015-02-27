/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIUnicharOutputStream.idl
 */

#ifndef __gen_nsIUnicharOutputStream_h__
#define __gen_nsIUnicharOutputStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUnicharOutputStream */
#define NS_IUNICHAROUTPUTSTREAM_IID_STR "2d00b1bb-8b21-4a63-bcc6-7213f513ac2e"

#define NS_IUNICHAROUTPUTSTREAM_IID \
  {0x2d00b1bb, 0x8b21, 0x4a63, \
    { 0xbc, 0xc6, 0x72, 0x13, 0xf5, 0x13, 0xac, 0x2e }}

class NS_NO_VTABLE nsIUnicharOutputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNICHAROUTPUTSTREAM_IID)

  /* boolean write (in unsigned long aCount, [array, size_is (aCount), const] in PRUnichar c); */
  NS_IMETHOD Write(uint32_t aCount, const PRUnichar *c, bool *_retval) = 0;

  /* boolean writeString (in AString str); */
  NS_IMETHOD WriteString(const nsAString & str, bool *_retval) = 0;

  /* void flush (); */
  NS_IMETHOD Flush(void) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUnicharOutputStream, NS_IUNICHAROUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNICHAROUTPUTSTREAM \
  NS_IMETHOD Write(uint32_t aCount, const PRUnichar *c, bool *_retval); \
  NS_IMETHOD WriteString(const nsAString & str, bool *_retval); \
  NS_IMETHOD Flush(void); \
  NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNICHAROUTPUTSTREAM(_to) \
  NS_IMETHOD Write(uint32_t aCount, const PRUnichar *c, bool *_retval) { return _to Write(aCount, c, _retval); } \
  NS_IMETHOD WriteString(const nsAString & str, bool *_retval) { return _to WriteString(str, _retval); } \
  NS_IMETHOD Flush(void) { return _to Flush(); } \
  NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNICHAROUTPUTSTREAM(_to) \
  NS_IMETHOD Write(uint32_t aCount, const PRUnichar *c, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(aCount, c, _retval); } \
  NS_IMETHOD WriteString(const nsAString & str, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteString(str, _retval); } \
  NS_IMETHOD Flush(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUnicharOutputStream : public nsIUnicharOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNICHAROUTPUTSTREAM

  nsUnicharOutputStream();

private:
  ~nsUnicharOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUnicharOutputStream, nsIUnicharOutputStream)

nsUnicharOutputStream::nsUnicharOutputStream()
{
  /* member initializers and constructor code */
}

nsUnicharOutputStream::~nsUnicharOutputStream()
{
  /* destructor code */
}

/* boolean write (in unsigned long aCount, [array, size_is (aCount), const] in PRUnichar c); */
NS_IMETHODIMP nsUnicharOutputStream::Write(uint32_t aCount, const PRUnichar *c, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean writeString (in AString str); */
NS_IMETHODIMP nsUnicharOutputStream::WriteString(const nsAString & str, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flush (); */
NS_IMETHODIMP nsUnicharOutputStream::Flush()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUnicharOutputStream::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUnicharOutputStream_h__ */
