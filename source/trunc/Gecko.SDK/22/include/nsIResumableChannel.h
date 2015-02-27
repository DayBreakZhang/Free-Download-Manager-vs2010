/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIResumableChannel.idl
 */

#ifndef __gen_nsIResumableChannel_h__
#define __gen_nsIResumableChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIStreamListener; /* forward declaration */


/* starting interface:    nsIResumableChannel */
#define NS_IRESUMABLECHANNEL_IID_STR "4ad136fa-83af-4a22-a76e-503642c0f4a8"

#define NS_IRESUMABLECHANNEL_IID \
  {0x4ad136fa, 0x83af, 0x4a22, \
    { 0xa7, 0x6e, 0x50, 0x36, 0x42, 0xc0, 0xf4, 0xa8 }}

class NS_NO_VTABLE nsIResumableChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRESUMABLECHANNEL_IID)

  /* void resumeAt (in unsigned long long startPos, in ACString entityID); */
  NS_IMETHOD ResumeAt(uint64_t startPos, const nsACString & entityID) = 0;

  /* readonly attribute ACString entityID; */
  NS_IMETHOD GetEntityID(nsACString & aEntityID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIResumableChannel, NS_IRESUMABLECHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRESUMABLECHANNEL \
  NS_IMETHOD ResumeAt(uint64_t startPos, const nsACString & entityID); \
  NS_IMETHOD GetEntityID(nsACString & aEntityID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRESUMABLECHANNEL(_to) \
  NS_IMETHOD ResumeAt(uint64_t startPos, const nsACString & entityID) { return _to ResumeAt(startPos, entityID); } \
  NS_IMETHOD GetEntityID(nsACString & aEntityID) { return _to GetEntityID(aEntityID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRESUMABLECHANNEL(_to) \
  NS_IMETHOD ResumeAt(uint64_t startPos, const nsACString & entityID) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeAt(startPos, entityID); } \
  NS_IMETHOD GetEntityID(nsACString & aEntityID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntityID(aEntityID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsResumableChannel : public nsIResumableChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRESUMABLECHANNEL

  nsResumableChannel();

private:
  ~nsResumableChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsResumableChannel, nsIResumableChannel)

nsResumableChannel::nsResumableChannel()
{
  /* member initializers and constructor code */
}

nsResumableChannel::~nsResumableChannel()
{
  /* destructor code */
}

/* void resumeAt (in unsigned long long startPos, in ACString entityID); */
NS_IMETHODIMP nsResumableChannel::ResumeAt(uint64_t startPos, const nsACString & entityID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString entityID; */
NS_IMETHODIMP nsResumableChannel::GetEntityID(nsACString & aEntityID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIResumableChannel_h__ */
