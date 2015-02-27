/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFTPChannel.idl
 */

#ifndef __gen_nsIFTPChannel_h__
#define __gen_nsIFTPChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFTPChannel */
#define NS_IFTPCHANNEL_IID_STR "07f0d5cd-1fd5-4aa3-b6fc-665bdc5dbf9f"

#define NS_IFTPCHANNEL_IID \
  {0x07f0d5cd, 0x1fd5, 0x4aa3, \
    { 0xb6, 0xfc, 0x66, 0x5b, 0xdc, 0x5d, 0xbf, 0x9f }}

class NS_NO_VTABLE nsIFTPChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFTPCHANNEL_IID)

  /* attribute PRTime lastModifiedTime; */
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) = 0;
  NS_IMETHOD SetLastModifiedTime(PRTime aLastModifiedTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFTPChannel, NS_IFTPCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFTPCHANNEL \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime); \
  NS_IMETHOD SetLastModifiedTime(PRTime aLastModifiedTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFTPCHANNEL(_to) \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return _to GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD SetLastModifiedTime(PRTime aLastModifiedTime) { return _to SetLastModifiedTime(aLastModifiedTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFTPCHANNEL(_to) \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD SetLastModifiedTime(PRTime aLastModifiedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLastModifiedTime(aLastModifiedTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFTPChannel : public nsIFTPChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFTPCHANNEL

  nsFTPChannel();

private:
  ~nsFTPChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFTPChannel, nsIFTPChannel)

nsFTPChannel::nsFTPChannel()
{
  /* member initializers and constructor code */
}

nsFTPChannel::~nsFTPChannel()
{
  /* destructor code */
}

/* attribute PRTime lastModifiedTime; */
NS_IMETHODIMP nsFTPChannel::GetLastModifiedTime(PRTime *aLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFTPChannel::SetLastModifiedTime(PRTime aLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFTPEventSink */
#define NS_IFTPEVENTSINK_IID_STR "455d4234-0330-43d2-bbfb-99afbecbfeb0"

#define NS_IFTPEVENTSINK_IID \
  {0x455d4234, 0x0330, 0x43d2, \
    { 0xbb, 0xfb, 0x99, 0xaf, 0xbe, 0xcb, 0xfe, 0xb0 }}

class NS_NO_VTABLE nsIFTPEventSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFTPEVENTSINK_IID)

  /* void OnFTPControlLog (in boolean server, in string msg); */
  NS_IMETHOD OnFTPControlLog(bool server, const char * msg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFTPEventSink, NS_IFTPEVENTSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFTPEVENTSINK \
  NS_IMETHOD OnFTPControlLog(bool server, const char * msg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFTPEVENTSINK(_to) \
  NS_IMETHOD OnFTPControlLog(bool server, const char * msg) { return _to OnFTPControlLog(server, msg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFTPEVENTSINK(_to) \
  NS_IMETHOD OnFTPControlLog(bool server, const char * msg) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnFTPControlLog(server, msg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFTPEventSink : public nsIFTPEventSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFTPEVENTSINK

  nsFTPEventSink();

private:
  ~nsFTPEventSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFTPEventSink, nsIFTPEventSink)

nsFTPEventSink::nsFTPEventSink()
{
  /* member initializers and constructor code */
}

nsFTPEventSink::~nsFTPEventSink()
{
  /* destructor code */
}

/* void OnFTPControlLog (in boolean server, in string msg); */
NS_IMETHODIMP nsFTPEventSink::OnFTPControlLog(bool server, const char * msg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFTPChannel_h__ */
