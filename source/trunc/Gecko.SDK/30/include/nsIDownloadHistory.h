/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDownloadHistory.idl
 */

#ifndef __gen_nsIDownloadHistory_h__
#define __gen_nsIDownloadHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIDownloadHistory */
#define NS_IDOWNLOADHISTORY_IID_STR "4dcd6a12-a091-4f38-8360-022929635746"

#define NS_IDOWNLOADHISTORY_IID \
  {0x4dcd6a12, 0xa091, 0x4f38, \
    { 0x83, 0x60, 0x02, 0x29, 0x29, 0x63, 0x57, 0x46 }}

class NS_NO_VTABLE nsIDownloadHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADHISTORY_IID)

  /* void addDownload (in nsIURI aSource, [optional] in nsIURI aReferrer, [optional] in PRTime aStartTime, [optional] in nsIURI aDestination); */
  NS_IMETHOD AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime, nsIURI *aDestination) = 0;

  /* void removeAllDownloads (); */
  NS_IMETHOD RemoveAllDownloads(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadHistory, NS_IDOWNLOADHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADHISTORY \
  NS_IMETHOD AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime, nsIURI *aDestination); \
  NS_IMETHOD RemoveAllDownloads(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADHISTORY(_to) \
  NS_IMETHOD AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime, nsIURI *aDestination) { return _to AddDownload(aSource, aReferrer, aStartTime, aDestination); } \
  NS_IMETHOD RemoveAllDownloads(void) { return _to RemoveAllDownloads(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADHISTORY(_to) \
  NS_IMETHOD AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime, nsIURI *aDestination) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDownload(aSource, aReferrer, aStartTime, aDestination); } \
  NS_IMETHOD RemoveAllDownloads(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllDownloads(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadHistory : public nsIDownloadHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADHISTORY

  nsDownloadHistory();

private:
  ~nsDownloadHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloadHistory, nsIDownloadHistory)

nsDownloadHistory::nsDownloadHistory()
{
  /* member initializers and constructor code */
}

nsDownloadHistory::~nsDownloadHistory()
{
  /* destructor code */
}

/* void addDownload (in nsIURI aSource, [optional] in nsIURI aReferrer, [optional] in PRTime aStartTime, [optional] in nsIURI aDestination); */
NS_IMETHODIMP nsDownloadHistory::AddDownload(nsIURI *aSource, nsIURI *aReferrer, PRTime aStartTime, nsIURI *aDestination)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllDownloads (); */
NS_IMETHODIMP nsDownloadHistory::RemoveAllDownloads()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDownloadHistory_h__ */
