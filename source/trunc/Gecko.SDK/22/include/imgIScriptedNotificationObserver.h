/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/image/public/imgIScriptedNotificationObserver.idl
 */

#ifndef __gen_imgIScriptedNotificationObserver_h__
#define __gen_imgIScriptedNotificationObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIRequest; /* forward declaration */


/* starting interface:    imgIScriptedNotificationObserver */
#define IMGISCRIPTEDNOTIFICATIONOBSERVER_IID_STR "10be55b3-2029-41a7-a975-538efed250ed"

#define IMGISCRIPTEDNOTIFICATIONOBSERVER_IID \
  {0x10be55b3, 0x2029, 0x41a7, \
    { 0xa9, 0x75, 0x53, 0x8e, 0xfe, 0xd2, 0x50, 0xed }}

class NS_NO_VTABLE imgIScriptedNotificationObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGISCRIPTEDNOTIFICATIONOBSERVER_IID)

  /* void sizeAvailable (in imgIRequest aRequest); */
  NS_IMETHOD SizeAvailable(imgIRequest *aRequest) = 0;

  /* void frameUpdate (in imgIRequest aRequest); */
  NS_IMETHOD FrameUpdate(imgIRequest *aRequest) = 0;

  /* void frameComplete (in imgIRequest aRequest); */
  NS_IMETHOD FrameComplete(imgIRequest *aRequest) = 0;

  /* void loadComplete (in imgIRequest aRequest); */
  NS_IMETHOD LoadComplete(imgIRequest *aRequest) = 0;

  /* void decodeComplete (in imgIRequest aRequest); */
  NS_IMETHOD DecodeComplete(imgIRequest *aRequest) = 0;

  /* void discard (in imgIRequest aRequest); */
  NS_IMETHOD Discard(imgIRequest *aRequest) = 0;

  /* void isAnimated (in imgIRequest aRequest); */
  NS_IMETHOD IsAnimated(imgIRequest *aRequest) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIScriptedNotificationObserver, IMGISCRIPTEDNOTIFICATIONOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGISCRIPTEDNOTIFICATIONOBSERVER \
  NS_IMETHOD SizeAvailable(imgIRequest *aRequest); \
  NS_IMETHOD FrameUpdate(imgIRequest *aRequest); \
  NS_IMETHOD FrameComplete(imgIRequest *aRequest); \
  NS_IMETHOD LoadComplete(imgIRequest *aRequest); \
  NS_IMETHOD DecodeComplete(imgIRequest *aRequest); \
  NS_IMETHOD Discard(imgIRequest *aRequest); \
  NS_IMETHOD IsAnimated(imgIRequest *aRequest); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGISCRIPTEDNOTIFICATIONOBSERVER(_to) \
  NS_IMETHOD SizeAvailable(imgIRequest *aRequest) { return _to SizeAvailable(aRequest); } \
  NS_IMETHOD FrameUpdate(imgIRequest *aRequest) { return _to FrameUpdate(aRequest); } \
  NS_IMETHOD FrameComplete(imgIRequest *aRequest) { return _to FrameComplete(aRequest); } \
  NS_IMETHOD LoadComplete(imgIRequest *aRequest) { return _to LoadComplete(aRequest); } \
  NS_IMETHOD DecodeComplete(imgIRequest *aRequest) { return _to DecodeComplete(aRequest); } \
  NS_IMETHOD Discard(imgIRequest *aRequest) { return _to Discard(aRequest); } \
  NS_IMETHOD IsAnimated(imgIRequest *aRequest) { return _to IsAnimated(aRequest); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGISCRIPTEDNOTIFICATIONOBSERVER(_to) \
  NS_IMETHOD SizeAvailable(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeAvailable(aRequest); } \
  NS_IMETHOD FrameUpdate(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->FrameUpdate(aRequest); } \
  NS_IMETHOD FrameComplete(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->FrameComplete(aRequest); } \
  NS_IMETHOD LoadComplete(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadComplete(aRequest); } \
  NS_IMETHOD DecodeComplete(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeComplete(aRequest); } \
  NS_IMETHOD Discard(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->Discard(aRequest); } \
  NS_IMETHOD IsAnimated(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAnimated(aRequest); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIScriptedNotificationObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGISCRIPTEDNOTIFICATIONOBSERVER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIScriptedNotificationObserver)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void sizeAvailable (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::SizeAvailable(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void frameUpdate (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::FrameUpdate(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void frameComplete (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::FrameComplete(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadComplete (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::LoadComplete(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void decodeComplete (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::DecodeComplete(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void discard (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::Discard(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void isAnimated (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::IsAnimated(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIScriptedNotificationObserver_h__ */
