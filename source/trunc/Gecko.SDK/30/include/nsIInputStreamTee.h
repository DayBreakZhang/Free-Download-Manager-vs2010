/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInputStreamTee.idl
 */

#ifndef __gen_nsIInputStreamTee_h__
#define __gen_nsIInputStreamTee_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIInputStreamTee */
#define NS_IINPUTSTREAMTEE_IID_STR "90a9d790-3bca-421e-a73b-98f68e13c917"

#define NS_IINPUTSTREAMTEE_IID \
  {0x90a9d790, 0x3bca, 0x421e, \
    { 0xa7, 0x3b, 0x98, 0xf6, 0x8e, 0x13, 0xc9, 0x17 }}

class NS_NO_VTABLE nsIInputStreamTee : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTSTREAMTEE_IID)

  /* attribute nsIInputStream source; */
  NS_IMETHOD GetSource(nsIInputStream * *aSource) = 0;
  NS_IMETHOD SetSource(nsIInputStream *aSource) = 0;

  /* attribute nsIOutputStream sink; */
  NS_IMETHOD GetSink(nsIOutputStream * *aSink) = 0;
  NS_IMETHOD SetSink(nsIOutputStream *aSink) = 0;

  /* attribute nsIEventTarget eventTarget; */
  NS_IMETHOD GetEventTarget(nsIEventTarget * *aEventTarget) = 0;
  NS_IMETHOD SetEventTarget(nsIEventTarget *aEventTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputStreamTee, NS_IINPUTSTREAMTEE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTSTREAMTEE \
  NS_IMETHOD GetSource(nsIInputStream * *aSource); \
  NS_IMETHOD SetSource(nsIInputStream *aSource); \
  NS_IMETHOD GetSink(nsIOutputStream * *aSink); \
  NS_IMETHOD SetSink(nsIOutputStream *aSink); \
  NS_IMETHOD GetEventTarget(nsIEventTarget * *aEventTarget); \
  NS_IMETHOD SetEventTarget(nsIEventTarget *aEventTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTSTREAMTEE(_to) \
  NS_IMETHOD GetSource(nsIInputStream * *aSource) { return _to GetSource(aSource); } \
  NS_IMETHOD SetSource(nsIInputStream *aSource) { return _to SetSource(aSource); } \
  NS_IMETHOD GetSink(nsIOutputStream * *aSink) { return _to GetSink(aSink); } \
  NS_IMETHOD SetSink(nsIOutputStream *aSink) { return _to SetSink(aSink); } \
  NS_IMETHOD GetEventTarget(nsIEventTarget * *aEventTarget) { return _to GetEventTarget(aEventTarget); } \
  NS_IMETHOD SetEventTarget(nsIEventTarget *aEventTarget) { return _to SetEventTarget(aEventTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTSTREAMTEE(_to) \
  NS_IMETHOD GetSource(nsIInputStream * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_IMETHOD SetSource(nsIInputStream *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSource(aSource); } \
  NS_IMETHOD GetSink(nsIOutputStream * *aSink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSink(aSink); } \
  NS_IMETHOD SetSink(nsIOutputStream *aSink) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSink(aSink); } \
  NS_IMETHOD GetEventTarget(nsIEventTarget * *aEventTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventTarget(aEventTarget); } \
  NS_IMETHOD SetEventTarget(nsIEventTarget *aEventTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEventTarget(aEventTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputStreamTee : public nsIInputStreamTee
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTSTREAMTEE

  nsInputStreamTee();

private:
  ~nsInputStreamTee();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputStreamTee, nsIInputStreamTee)

nsInputStreamTee::nsInputStreamTee()
{
  /* member initializers and constructor code */
}

nsInputStreamTee::~nsInputStreamTee()
{
  /* destructor code */
}

/* attribute nsIInputStream source; */
NS_IMETHODIMP nsInputStreamTee::GetSource(nsIInputStream * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputStreamTee::SetSource(nsIInputStream *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIOutputStream sink; */
NS_IMETHODIMP nsInputStreamTee::GetSink(nsIOutputStream * *aSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputStreamTee::SetSink(nsIOutputStream *aSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIEventTarget eventTarget; */
NS_IMETHODIMP nsInputStreamTee::GetEventTarget(nsIEventTarget * *aEventTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputStreamTee::SetEventTarget(nsIEventTarget *aEventTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// factory methods
extern nsresult
NS_NewInputStreamTee(nsIInputStream **tee, // read from this input stream
                     nsIInputStream *source,
                     nsIOutputStream *sink);
                     
extern nsresult
NS_NewInputStreamTeeAsync(nsIInputStream **tee, // read from this input stream
                     nsIInputStream *source,
                     nsIOutputStream *sink,
                     nsIEventTarget *eventTarget);

#endif /* __gen_nsIInputStreamTee_h__ */
