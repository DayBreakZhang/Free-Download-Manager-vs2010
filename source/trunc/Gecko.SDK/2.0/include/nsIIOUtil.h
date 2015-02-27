/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/xpcom/io/nsIIOUtil.idl
 */

#ifndef __gen_nsIIOUtil_h__
#define __gen_nsIIOUtil_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIIOUtil */
#define NS_IIOUTIL_IID_STR "e8152f7f-4209-4c63-ad23-c3d2aa0c5a49"

#define NS_IIOUTIL_IID \
  {0xe8152f7f, 0x4209, 0x4c63, \
    { 0xad, 0x23, 0xc3, 0xd2, 0xaa, 0x0c, 0x5a, 0x49 }}

/**
 * nsIIOUtil provdes various xpcom/io-related utility methods.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIOUtil : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIOUTIL_IID)

  /**
   * Test whether an input stream is buffered.  See nsStreamUtils.h
   * documentation for NS_InputStreamIsBuffered for the definition of
   * "buffered" used here and for edge-case behavior.
   *
   * @throws NS_ERROR_INVALID_POINTER if null is passed in.
   */
  /* boolean inputStreamIsBuffered (in nsIInputStream aStream); */
  NS_SCRIPTABLE NS_IMETHOD InputStreamIsBuffered(nsIInputStream *aStream, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Test whether an output stream is buffered.  See nsStreamUtils.h
   * documentation for NS_OutputStreamIsBuffered for the definition of
   * "buffered" used here and for edge-case behavior.
   *
   * @throws NS_ERROR_INVALID_POINTER if null is passed in.
   */
  /* boolean outputStreamIsBuffered (in nsIOutputStream aStream); */
  NS_SCRIPTABLE NS_IMETHOD OutputStreamIsBuffered(nsIOutputStream *aStream, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIOUtil, NS_IIOUTIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIOUTIL \
  NS_SCRIPTABLE NS_IMETHOD InputStreamIsBuffered(nsIInputStream *aStream, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OutputStreamIsBuffered(nsIOutputStream *aStream, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIOUTIL(_to) \
  NS_SCRIPTABLE NS_IMETHOD InputStreamIsBuffered(nsIInputStream *aStream, PRBool *_retval NS_OUTPARAM) { return _to InputStreamIsBuffered(aStream, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OutputStreamIsBuffered(nsIOutputStream *aStream, PRBool *_retval NS_OUTPARAM) { return _to OutputStreamIsBuffered(aStream, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIOUTIL(_to) \
  NS_SCRIPTABLE NS_IMETHOD InputStreamIsBuffered(nsIInputStream *aStream, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InputStreamIsBuffered(aStream, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OutputStreamIsBuffered(nsIOutputStream *aStream, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OutputStreamIsBuffered(aStream, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIOUtil : public nsIIOUtil
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIOUTIL

  nsIOUtil();

private:
  ~nsIOUtil();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIOUtil, nsIIOUtil)

nsIOUtil::nsIOUtil()
{
  /* member initializers and constructor code */
}

nsIOUtil::~nsIOUtil()
{
  /* destructor code */
}

/* boolean inputStreamIsBuffered (in nsIInputStream aStream); */
NS_IMETHODIMP nsIOUtil::InputStreamIsBuffered(nsIInputStream *aStream, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean outputStreamIsBuffered (in nsIOutputStream aStream); */
NS_IMETHODIMP nsIOUtil::OutputStreamIsBuffered(nsIOutputStream *aStream, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIOUtil_h__ */
