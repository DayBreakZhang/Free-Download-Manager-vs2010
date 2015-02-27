/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/media/nsIDOMMediaStream.idl
 */

#ifndef __gen_nsIDOMMediaStream_h__
#define __gen_nsIDOMMediaStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

/* starting interface:    nsIDOMMediaStream */
#define NS_IDOMMEDIASTREAM_IID_STR "3ef760bb-ff19-4dbb-b552-af27ab84b9b8"

#define NS_IDOMMEDIASTREAM_IID \
  {0x3ef760bb, 0xff19, 0x4dbb, \
    { 0xb5, 0x52, 0xaf, 0x27, 0xab, 0x84, 0xb9, 0xb8 }}

class NS_NO_VTABLE nsIDOMMediaStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMEDIASTREAM_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMediaStream, NS_IDOMMEDIASTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMEDIASTREAM \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMEDIASTREAM(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMEDIASTREAM(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMediaStream : public nsIDOMMediaStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMEDIASTREAM

  nsDOMMediaStream();

private:
  ~nsDOMMediaStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMediaStream, nsIDOMMediaStream)

nsDOMMediaStream::nsDOMMediaStream()
{
  /* member initializers and constructor code */
}

nsDOMMediaStream::~nsDOMMediaStream()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMLocalMediaStream */
#define NS_IDOMLOCALMEDIASTREAM_IID_STR "dd37150a-9823-4605-ac4c-3516629a8aaf"

#define NS_IDOMLOCALMEDIASTREAM_IID \
  {0xdd37150a, 0x9823, 0x4605, \
    { 0xac, 0x4c, 0x35, 0x16, 0x62, 0x9a, 0x8a, 0xaf }}

class NS_NO_VTABLE nsIDOMLocalMediaStream : public nsIDOMMediaStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLOCALMEDIASTREAM_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLocalMediaStream, NS_IDOMLOCALMEDIASTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLOCALMEDIASTREAM \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLOCALMEDIASTREAM(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLOCALMEDIASTREAM(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLocalMediaStream : public nsIDOMLocalMediaStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLOCALMEDIASTREAM

  nsDOMLocalMediaStream();

private:
  ~nsDOMLocalMediaStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLocalMediaStream, nsIDOMLocalMediaStream)

nsDOMLocalMediaStream::nsDOMLocalMediaStream()
{
  /* member initializers and constructor code */
}

nsDOMLocalMediaStream::~nsDOMLocalMediaStream()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMediaStream_h__ */
