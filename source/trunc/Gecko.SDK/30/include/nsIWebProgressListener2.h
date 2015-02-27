/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebProgressListener2.idl
 */

#ifndef __gen_nsIWebProgressListener2_h__
#define __gen_nsIWebProgressListener2_h__


#ifndef __gen_nsIWebProgressListener_h__
#include "nsIWebProgressListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebProgressListener2 */
#define NS_IWEBPROGRESSLISTENER2_IID_STR "dde39de0-e4e0-11da-8ad9-0800200c9a66"

#define NS_IWEBPROGRESSLISTENER2_IID \
  {0xdde39de0, 0xe4e0, 0x11da, \
    { 0x8a, 0xd9, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIWebProgressListener2 : public nsIWebProgressListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBPROGRESSLISTENER2_IID)

  /* void onProgressChange64 (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in long long aCurSelfProgress, in long long aMaxSelfProgress, in long long aCurTotalProgress, in long long aMaxTotalProgress); */
  NS_IMETHOD OnProgressChange64(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress) = 0;

  /* boolean onRefreshAttempted (in nsIWebProgress aWebProgress, in nsIURI aRefreshURI, in long aMillis, in boolean aSameURI); */
  NS_IMETHOD OnRefreshAttempted(nsIWebProgress *aWebProgress, nsIURI *aRefreshURI, int32_t aMillis, bool aSameURI, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebProgressListener2, NS_IWEBPROGRESSLISTENER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBPROGRESSLISTENER2 \
  NS_IMETHOD OnProgressChange64(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress); \
  NS_IMETHOD OnRefreshAttempted(nsIWebProgress *aWebProgress, nsIURI *aRefreshURI, int32_t aMillis, bool aSameURI, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBPROGRESSLISTENER2(_to) \
  NS_IMETHOD OnProgressChange64(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress) { return _to OnProgressChange64(aWebProgress, aRequest, aCurSelfProgress, aMaxSelfProgress, aCurTotalProgress, aMaxTotalProgress); } \
  NS_IMETHOD OnRefreshAttempted(nsIWebProgress *aWebProgress, nsIURI *aRefreshURI, int32_t aMillis, bool aSameURI, bool *_retval) { return _to OnRefreshAttempted(aWebProgress, aRefreshURI, aMillis, aSameURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBPROGRESSLISTENER2(_to) \
  NS_IMETHOD OnProgressChange64(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProgressChange64(aWebProgress, aRequest, aCurSelfProgress, aMaxSelfProgress, aCurTotalProgress, aMaxTotalProgress); } \
  NS_IMETHOD OnRefreshAttempted(nsIWebProgress *aWebProgress, nsIURI *aRefreshURI, int32_t aMillis, bool aSameURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRefreshAttempted(aWebProgress, aRefreshURI, aMillis, aSameURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebProgressListener2 : public nsIWebProgressListener2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBPROGRESSLISTENER2

  nsWebProgressListener2();

private:
  ~nsWebProgressListener2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebProgressListener2, nsIWebProgressListener2)

nsWebProgressListener2::nsWebProgressListener2()
{
  /* member initializers and constructor code */
}

nsWebProgressListener2::~nsWebProgressListener2()
{
  /* destructor code */
}

/* void onProgressChange64 (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in long long aCurSelfProgress, in long long aMaxSelfProgress, in long long aCurTotalProgress, in long long aMaxTotalProgress); */
NS_IMETHODIMP nsWebProgressListener2::OnProgressChange64(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onRefreshAttempted (in nsIWebProgress aWebProgress, in nsIURI aRefreshURI, in long aMillis, in boolean aSameURI); */
NS_IMETHODIMP nsWebProgressListener2::OnRefreshAttempted(nsIWebProgress *aWebProgress, nsIURI *aRefreshURI, int32_t aMillis, bool aSameURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebProgressListener2_h__ */
