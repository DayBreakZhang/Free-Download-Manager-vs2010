/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebBrowserPersist.idl
 */

#ifndef __gen_nsIWebBrowserPersist_h__
#define __gen_nsIWebBrowserPersist_h__


#ifndef __gen_nsICancelable_h__
#include "nsICancelable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIWebProgressListener; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsILoadContext; /* forward declaration */


/* starting interface:    nsIWebBrowserPersist */
#define NS_IWEBBROWSERPERSIST_IID_STR "35c1f231-582b-4315-a26c-a1227e3539b4"

#define NS_IWEBBROWSERPERSIST_IID \
  {0x35c1f231, 0x582b, 0x4315, \
    { 0xa2, 0x6c, 0xa1, 0x22, 0x7e, 0x35, 0x39, 0xb4 }}

class NS_NO_VTABLE nsIWebBrowserPersist : public nsICancelable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERPERSIST_IID)

  enum {
    PERSIST_FLAGS_NONE = 0U,
    PERSIST_FLAGS_FROM_CACHE = 1U,
    PERSIST_FLAGS_BYPASS_CACHE = 2U,
    PERSIST_FLAGS_IGNORE_REDIRECTED_DATA = 4U,
    PERSIST_FLAGS_IGNORE_IFRAMES = 8U,
    PERSIST_FLAGS_NO_CONVERSION = 16U,
    PERSIST_FLAGS_REPLACE_EXISTING_FILES = 32U,
    PERSIST_FLAGS_NO_BASE_TAG_MODIFICATIONS = 64U,
    PERSIST_FLAGS_FIXUP_ORIGINAL_DOM = 128U,
    PERSIST_FLAGS_FIXUP_LINKS_TO_DESTINATION = 256U,
    PERSIST_FLAGS_DONT_FIXUP_LINKS = 512U,
    PERSIST_FLAGS_SERIALIZE_OUTPUT = 1024U,
    PERSIST_FLAGS_DONT_CHANGE_FILENAMES = 2048U,
    PERSIST_FLAGS_FAIL_ON_BROKEN_LINKS = 4096U,
    PERSIST_FLAGS_CLEANUP_ON_FAILURE = 8192U,
    PERSIST_FLAGS_AUTODETECT_APPLY_CONVERSION = 16384U,
    PERSIST_FLAGS_APPEND_TO_FILE = 32768U,
    PERSIST_FLAGS_FORCE_ALLOW_COOKIES = 65536U
  };

  /* attribute unsigned long persistFlags; */
  NS_IMETHOD GetPersistFlags(uint32_t *aPersistFlags) = 0;
  NS_IMETHOD SetPersistFlags(uint32_t aPersistFlags) = 0;

  enum {
    PERSIST_STATE_READY = 1U,
    PERSIST_STATE_SAVING = 2U,
    PERSIST_STATE_FINISHED = 3U
  };

  /* readonly attribute unsigned long currentState; */
  NS_IMETHOD GetCurrentState(uint32_t *aCurrentState) = 0;

  /* readonly attribute nsresult result; */
  NS_IMETHOD GetResult(nsresult *aResult) = 0;

  /* attribute nsIWebProgressListener progressListener; */
  NS_IMETHOD GetProgressListener(nsIWebProgressListener * *aProgressListener) = 0;
  NS_IMETHOD SetProgressListener(nsIWebProgressListener *aProgressListener) = 0;

  /* void saveURI (in nsIURI aURI, in nsISupports aCacheKey, in nsIURI aReferrer, in nsIInputStream aPostData, in string aExtraHeaders, in nsISupports aFile, in nsILoadContext aPrivacyContext); */
  NS_IMETHOD SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, nsILoadContext *aPrivacyContext) = 0;

  /* void savePrivacyAwareURI (in nsIURI aURI, in nsISupports aCacheKey, in nsIURI aReferrer, in nsIInputStream aPostData, in string aExtraHeaders, in nsISupports aFile, in boolean aIsPrivate); */
  NS_IMETHOD SavePrivacyAwareURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, bool aIsPrivate) = 0;

  /* void saveChannel (in nsIChannel aChannel, in nsISupports aFile); */
  NS_IMETHOD SaveChannel(nsIChannel *aChannel, nsISupports *aFile) = 0;

  enum {
    ENCODE_FLAGS_SELECTION_ONLY = 1U,
    ENCODE_FLAGS_FORMATTED = 2U,
    ENCODE_FLAGS_RAW = 4U,
    ENCODE_FLAGS_BODY_ONLY = 8U,
    ENCODE_FLAGS_PREFORMATTED = 16U,
    ENCODE_FLAGS_WRAP = 32U,
    ENCODE_FLAGS_FORMAT_FLOWED = 64U,
    ENCODE_FLAGS_ABSOLUTE_LINKS = 128U,
    ENCODE_FLAGS_ENCODE_W3C_ENTITIES = 256U,
    ENCODE_FLAGS_CR_LINEBREAKS = 512U,
    ENCODE_FLAGS_LF_LINEBREAKS = 1024U,
    ENCODE_FLAGS_NOSCRIPT_CONTENT = 2048U,
    ENCODE_FLAGS_NOFRAMES_CONTENT = 4096U,
    ENCODE_FLAGS_ENCODE_BASIC_ENTITIES = 8192U,
    ENCODE_FLAGS_ENCODE_LATIN1_ENTITIES = 16384U,
    ENCODE_FLAGS_ENCODE_HTML_ENTITIES = 32768U
  };

  /* void saveDocument (in nsIDOMDocument aDocument, in nsISupports aFile, in nsISupports aDataPath, in string aOutputContentType, in unsigned long aEncodingFlags, in unsigned long aWrapColumn); */
  NS_IMETHOD SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char * aOutputContentType, uint32_t aEncodingFlags, uint32_t aWrapColumn) = 0;

  /* void cancelSave (); */
  NS_IMETHOD CancelSave(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserPersist, NS_IWEBBROWSERPERSIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERPERSIST \
  NS_IMETHOD GetPersistFlags(uint32_t *aPersistFlags); \
  NS_IMETHOD SetPersistFlags(uint32_t aPersistFlags); \
  NS_IMETHOD GetCurrentState(uint32_t *aCurrentState); \
  NS_IMETHOD GetResult(nsresult *aResult); \
  NS_IMETHOD GetProgressListener(nsIWebProgressListener * *aProgressListener); \
  NS_IMETHOD SetProgressListener(nsIWebProgressListener *aProgressListener); \
  NS_IMETHOD SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, nsILoadContext *aPrivacyContext); \
  NS_IMETHOD SavePrivacyAwareURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, bool aIsPrivate); \
  NS_IMETHOD SaveChannel(nsIChannel *aChannel, nsISupports *aFile); \
  NS_IMETHOD SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char * aOutputContentType, uint32_t aEncodingFlags, uint32_t aWrapColumn); \
  NS_IMETHOD CancelSave(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERPERSIST(_to) \
  NS_IMETHOD GetPersistFlags(uint32_t *aPersistFlags) { return _to GetPersistFlags(aPersistFlags); } \
  NS_IMETHOD SetPersistFlags(uint32_t aPersistFlags) { return _to SetPersistFlags(aPersistFlags); } \
  NS_IMETHOD GetCurrentState(uint32_t *aCurrentState) { return _to GetCurrentState(aCurrentState); } \
  NS_IMETHOD GetResult(nsresult *aResult) { return _to GetResult(aResult); } \
  NS_IMETHOD GetProgressListener(nsIWebProgressListener * *aProgressListener) { return _to GetProgressListener(aProgressListener); } \
  NS_IMETHOD SetProgressListener(nsIWebProgressListener *aProgressListener) { return _to SetProgressListener(aProgressListener); } \
  NS_IMETHOD SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, nsILoadContext *aPrivacyContext) { return _to SaveURI(aURI, aCacheKey, aReferrer, aPostData, aExtraHeaders, aFile, aPrivacyContext); } \
  NS_IMETHOD SavePrivacyAwareURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, bool aIsPrivate) { return _to SavePrivacyAwareURI(aURI, aCacheKey, aReferrer, aPostData, aExtraHeaders, aFile, aIsPrivate); } \
  NS_IMETHOD SaveChannel(nsIChannel *aChannel, nsISupports *aFile) { return _to SaveChannel(aChannel, aFile); } \
  NS_IMETHOD SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char * aOutputContentType, uint32_t aEncodingFlags, uint32_t aWrapColumn) { return _to SaveDocument(aDocument, aFile, aDataPath, aOutputContentType, aEncodingFlags, aWrapColumn); } \
  NS_IMETHOD CancelSave(void) { return _to CancelSave(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERPERSIST(_to) \
  NS_IMETHOD GetPersistFlags(uint32_t *aPersistFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersistFlags(aPersistFlags); } \
  NS_IMETHOD SetPersistFlags(uint32_t aPersistFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersistFlags(aPersistFlags); } \
  NS_IMETHOD GetCurrentState(uint32_t *aCurrentState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentState(aCurrentState); } \
  NS_IMETHOD GetResult(nsresult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD GetProgressListener(nsIWebProgressListener * *aProgressListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProgressListener(aProgressListener); } \
  NS_IMETHOD SetProgressListener(nsIWebProgressListener *aProgressListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProgressListener(aProgressListener); } \
  NS_IMETHOD SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, nsILoadContext *aPrivacyContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveURI(aURI, aCacheKey, aReferrer, aPostData, aExtraHeaders, aFile, aPrivacyContext); } \
  NS_IMETHOD SavePrivacyAwareURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, bool aIsPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SavePrivacyAwareURI(aURI, aCacheKey, aReferrer, aPostData, aExtraHeaders, aFile, aIsPrivate); } \
  NS_IMETHOD SaveChannel(nsIChannel *aChannel, nsISupports *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveChannel(aChannel, aFile); } \
  NS_IMETHOD SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char * aOutputContentType, uint32_t aEncodingFlags, uint32_t aWrapColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveDocument(aDocument, aFile, aDataPath, aOutputContentType, aEncodingFlags, aWrapColumn); } \
  NS_IMETHOD CancelSave(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelSave(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserPersist : public nsIWebBrowserPersist
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERPERSIST

  nsWebBrowserPersist();

private:
  ~nsWebBrowserPersist();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserPersist, nsIWebBrowserPersist)

nsWebBrowserPersist::nsWebBrowserPersist()
{
  /* member initializers and constructor code */
}

nsWebBrowserPersist::~nsWebBrowserPersist()
{
  /* destructor code */
}

/* attribute unsigned long persistFlags; */
NS_IMETHODIMP nsWebBrowserPersist::GetPersistFlags(uint32_t *aPersistFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserPersist::SetPersistFlags(uint32_t aPersistFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long currentState; */
NS_IMETHODIMP nsWebBrowserPersist::GetCurrentState(uint32_t *aCurrentState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsresult result; */
NS_IMETHODIMP nsWebBrowserPersist::GetResult(nsresult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWebProgressListener progressListener; */
NS_IMETHODIMP nsWebBrowserPersist::GetProgressListener(nsIWebProgressListener * *aProgressListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserPersist::SetProgressListener(nsIWebProgressListener *aProgressListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveURI (in nsIURI aURI, in nsISupports aCacheKey, in nsIURI aReferrer, in nsIInputStream aPostData, in string aExtraHeaders, in nsISupports aFile, in nsILoadContext aPrivacyContext); */
NS_IMETHODIMP nsWebBrowserPersist::SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, nsILoadContext *aPrivacyContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void savePrivacyAwareURI (in nsIURI aURI, in nsISupports aCacheKey, in nsIURI aReferrer, in nsIInputStream aPostData, in string aExtraHeaders, in nsISupports aFile, in boolean aIsPrivate); */
NS_IMETHODIMP nsWebBrowserPersist::SavePrivacyAwareURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char * aExtraHeaders, nsISupports *aFile, bool aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveChannel (in nsIChannel aChannel, in nsISupports aFile); */
NS_IMETHODIMP nsWebBrowserPersist::SaveChannel(nsIChannel *aChannel, nsISupports *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveDocument (in nsIDOMDocument aDocument, in nsISupports aFile, in nsISupports aDataPath, in string aOutputContentType, in unsigned long aEncodingFlags, in unsigned long aWrapColumn); */
NS_IMETHODIMP nsWebBrowserPersist::SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char * aOutputContentType, uint32_t aEncodingFlags, uint32_t aWrapColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelSave (); */
NS_IMETHODIMP nsWebBrowserPersist::CancelSave()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserPersist_h__ */
