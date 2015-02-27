/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIURIClassifier.idl
 */

#ifndef __gen_nsIURIClassifier_h__
#define __gen_nsIURIClassifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    nsIURIClassifierCallback */
#define NS_IURICLASSIFIERCALLBACK_IID_STR "8face46e-0c96-470f-af40-0037dcd797bd"

#define NS_IURICLASSIFIERCALLBACK_IID \
  {0x8face46e, 0x0c96, 0x470f, \
    { 0xaf, 0x40, 0x00, 0x37, 0xdc, 0xd7, 0x97, 0xbd }}

class NS_NO_VTABLE nsIURIClassifierCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURICLASSIFIERCALLBACK_IID)

  /* void onClassifyComplete (in nsresult aErrorCode); */
  NS_IMETHOD OnClassifyComplete(nsresult aErrorCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIClassifierCallback, NS_IURICLASSIFIERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURICLASSIFIERCALLBACK \
  NS_IMETHOD OnClassifyComplete(nsresult aErrorCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURICLASSIFIERCALLBACK(_to) \
  NS_IMETHOD OnClassifyComplete(nsresult aErrorCode) { return _to OnClassifyComplete(aErrorCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURICLASSIFIERCALLBACK(_to) \
  NS_IMETHOD OnClassifyComplete(nsresult aErrorCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClassifyComplete(aErrorCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIClassifierCallback : public nsIURIClassifierCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURICLASSIFIERCALLBACK

  nsURIClassifierCallback();

private:
  ~nsURIClassifierCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIClassifierCallback, nsIURIClassifierCallback)

nsURIClassifierCallback::nsURIClassifierCallback()
{
  /* member initializers and constructor code */
}

nsURIClassifierCallback::~nsURIClassifierCallback()
{
  /* destructor code */
}

/* void onClassifyComplete (in nsresult aErrorCode); */
NS_IMETHODIMP nsURIClassifierCallback::OnClassifyComplete(nsresult aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIURIClassifier */
#define NS_IURICLASSIFIER_IID_STR "617f1002-ec55-42c4-a7b0-ebb221ba9fa2"

#define NS_IURICLASSIFIER_IID \
  {0x617f1002, 0xec55, 0x42c4, \
    { 0xa7, 0xb0, 0xeb, 0xb2, 0x21, 0xba, 0x9f, 0xa2 }}

class NS_NO_VTABLE nsIURIClassifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURICLASSIFIER_IID)

  /* boolean classify (in nsIPrincipal aPrincipal, in nsIURIClassifierCallback aCallback); */
  NS_IMETHOD Classify(nsIPrincipal *aPrincipal, nsIURIClassifierCallback *aCallback, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIClassifier, NS_IURICLASSIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURICLASSIFIER \
  NS_IMETHOD Classify(nsIPrincipal *aPrincipal, nsIURIClassifierCallback *aCallback, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURICLASSIFIER(_to) \
  NS_IMETHOD Classify(nsIPrincipal *aPrincipal, nsIURIClassifierCallback *aCallback, bool *_retval) { return _to Classify(aPrincipal, aCallback, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURICLASSIFIER(_to) \
  NS_IMETHOD Classify(nsIPrincipal *aPrincipal, nsIURIClassifierCallback *aCallback, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Classify(aPrincipal, aCallback, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIClassifier : public nsIURIClassifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURICLASSIFIER

  nsURIClassifier();

private:
  ~nsURIClassifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIClassifier, nsIURIClassifier)

nsURIClassifier::nsURIClassifier()
{
  /* member initializers and constructor code */
}

nsURIClassifier::~nsURIClassifier()
{
  /* destructor code */
}

/* boolean classify (in nsIPrincipal aPrincipal, in nsIURIClassifierCallback aCallback); */
NS_IMETHODIMP nsURIClassifier::Classify(nsIPrincipal *aPrincipal, nsIURIClassifierCallback *aCallback, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIClassifier_h__ */
