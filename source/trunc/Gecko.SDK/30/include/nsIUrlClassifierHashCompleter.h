/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUrlClassifierHashCompleter.idl
 */

#ifndef __gen_nsIUrlClassifierHashCompleter_h__
#define __gen_nsIUrlClassifierHashCompleter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUrlClassifierHashCompleterCallback */
#define NS_IURLCLASSIFIERHASHCOMPLETERCALLBACK_IID_STR "da16de40-df26-414d-bde7-c4faf4504868"

#define NS_IURLCLASSIFIERHASHCOMPLETERCALLBACK_IID \
  {0xda16de40, 0xdf26, 0x414d, \
    { 0xbd, 0xe7, 0xc4, 0xfa, 0xf4, 0x50, 0x48, 0x68 }}

class NS_NO_VTABLE nsIUrlClassifierHashCompleterCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERHASHCOMPLETERCALLBACK_IID)

  /* void completion (in ACString hash, in ACString table, in uint32_t chunkId); */
  NS_IMETHOD Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId) = 0;

  /* void completionFinished (in nsresult status); */
  NS_IMETHOD CompletionFinished(nsresult status) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierHashCompleterCallback, NS_IURLCLASSIFIERHASHCOMPLETERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERHASHCOMPLETERCALLBACK \
  NS_IMETHOD Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId); \
  NS_IMETHOD CompletionFinished(nsresult status); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERHASHCOMPLETERCALLBACK(_to) \
  NS_IMETHOD Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId) { return _to Completion(hash, table, chunkId); } \
  NS_IMETHOD CompletionFinished(nsresult status) { return _to CompletionFinished(status); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERHASHCOMPLETERCALLBACK(_to) \
  NS_IMETHOD Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId) { return !_to ? NS_ERROR_NULL_POINTER : _to->Completion(hash, table, chunkId); } \
  NS_IMETHOD CompletionFinished(nsresult status) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompletionFinished(status); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierHashCompleterCallback : public nsIUrlClassifierHashCompleterCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERHASHCOMPLETERCALLBACK

  nsUrlClassifierHashCompleterCallback();

private:
  ~nsUrlClassifierHashCompleterCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierHashCompleterCallback, nsIUrlClassifierHashCompleterCallback)

nsUrlClassifierHashCompleterCallback::nsUrlClassifierHashCompleterCallback()
{
  /* member initializers and constructor code */
}

nsUrlClassifierHashCompleterCallback::~nsUrlClassifierHashCompleterCallback()
{
  /* destructor code */
}

/* void completion (in ACString hash, in ACString table, in uint32_t chunkId); */
NS_IMETHODIMP nsUrlClassifierHashCompleterCallback::Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completionFinished (in nsresult status); */
NS_IMETHODIMP nsUrlClassifierHashCompleterCallback::CompletionFinished(nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUrlClassifierHashCompleter */
#define NS_IURLCLASSIFIERHASHCOMPLETER_IID_STR "ade9b72b-3562-44f5-aba6-e63246be53ae"

#define NS_IURLCLASSIFIERHASHCOMPLETER_IID \
  {0xade9b72b, 0x3562, 0x44f5, \
    { 0xab, 0xa6, 0xe6, 0x32, 0x46, 0xbe, 0x53, 0xae }}

class NS_NO_VTABLE nsIUrlClassifierHashCompleter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERHASHCOMPLETER_IID)

  /* void complete (in ACString partialHash, in nsIUrlClassifierHashCompleterCallback callback); */
  NS_IMETHOD Complete(const nsACString & partialHash, nsIUrlClassifierHashCompleterCallback *callback) = 0;

  /* attribute ACString gethashUrl; */
  NS_IMETHOD GetGethashUrl(nsACString & aGethashUrl) = 0;
  NS_IMETHOD SetGethashUrl(const nsACString & aGethashUrl) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierHashCompleter, NS_IURLCLASSIFIERHASHCOMPLETER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERHASHCOMPLETER \
  NS_IMETHOD Complete(const nsACString & partialHash, nsIUrlClassifierHashCompleterCallback *callback); \
  NS_IMETHOD GetGethashUrl(nsACString & aGethashUrl); \
  NS_IMETHOD SetGethashUrl(const nsACString & aGethashUrl); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERHASHCOMPLETER(_to) \
  NS_IMETHOD Complete(const nsACString & partialHash, nsIUrlClassifierHashCompleterCallback *callback) { return _to Complete(partialHash, callback); } \
  NS_IMETHOD GetGethashUrl(nsACString & aGethashUrl) { return _to GetGethashUrl(aGethashUrl); } \
  NS_IMETHOD SetGethashUrl(const nsACString & aGethashUrl) { return _to SetGethashUrl(aGethashUrl); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERHASHCOMPLETER(_to) \
  NS_IMETHOD Complete(const nsACString & partialHash, nsIUrlClassifierHashCompleterCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(partialHash, callback); } \
  NS_IMETHOD GetGethashUrl(nsACString & aGethashUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGethashUrl(aGethashUrl); } \
  NS_IMETHOD SetGethashUrl(const nsACString & aGethashUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGethashUrl(aGethashUrl); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierHashCompleter : public nsIUrlClassifierHashCompleter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERHASHCOMPLETER

  nsUrlClassifierHashCompleter();

private:
  ~nsUrlClassifierHashCompleter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierHashCompleter, nsIUrlClassifierHashCompleter)

nsUrlClassifierHashCompleter::nsUrlClassifierHashCompleter()
{
  /* member initializers and constructor code */
}

nsUrlClassifierHashCompleter::~nsUrlClassifierHashCompleter()
{
  /* destructor code */
}

/* void complete (in ACString partialHash, in nsIUrlClassifierHashCompleterCallback callback); */
NS_IMETHODIMP nsUrlClassifierHashCompleter::Complete(const nsACString & partialHash, nsIUrlClassifierHashCompleterCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString gethashUrl; */
NS_IMETHODIMP nsUrlClassifierHashCompleter::GetGethashUrl(nsACString & aGethashUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUrlClassifierHashCompleter::SetGethashUrl(const nsACString & aGethashUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlClassifierHashCompleter_h__ */
