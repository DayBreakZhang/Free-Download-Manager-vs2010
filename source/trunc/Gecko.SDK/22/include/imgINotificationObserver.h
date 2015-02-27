/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/image/public/imgINotificationObserver.idl
 */

#ifndef __gen_imgINotificationObserver_h__
#define __gen_imgINotificationObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIRequest; /* forward declaration */

#include "nsRect.h"

/* starting interface:    imgINotificationObserver */
#define IMGINOTIFICATIONOBSERVER_IID_STR "ac65c702-7771-4f6d-b18b-1c7d806ce3c1"

#define IMGINOTIFICATIONOBSERVER_IID \
  {0xac65c702, 0x7771, 0x4f6d, \
    { 0xb1, 0x8b, 0x1c, 0x7d, 0x80, 0x6c, 0xe3, 0xc1 }}

class NS_NO_VTABLE imgINotificationObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGINOTIFICATIONOBSERVER_IID)

  enum {
    SIZE_AVAILABLE = 1,
    FRAME_UPDATE = 2,
    FRAME_COMPLETE = 3,
    LOAD_COMPLETE = 4,
    DECODE_COMPLETE = 5,
    DISCARD = 6,
    UNLOCKED_DRAW = 7,
    IS_ANIMATED = 8
  };

  /* [noscript] void notify (in imgIRequest aProxy, in long aType, [const] in nsIntRect aRect); */
  NS_IMETHOD Notify(imgIRequest *aProxy, int32_t aType, const nsIntRect *aRect) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgINotificationObserver, IMGINOTIFICATIONOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGINOTIFICATIONOBSERVER \
  NS_IMETHOD Notify(imgIRequest *aProxy, int32_t aType, const nsIntRect *aRect); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGINOTIFICATIONOBSERVER(_to) \
  NS_IMETHOD Notify(imgIRequest *aProxy, int32_t aType, const nsIntRect *aRect) { return _to Notify(aProxy, aType, aRect); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGINOTIFICATIONOBSERVER(_to) \
  NS_IMETHOD Notify(imgIRequest *aProxy, int32_t aType, const nsIntRect *aRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->Notify(aProxy, aType, aRect); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgINotificationObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGINOTIFICATIONOBSERVER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgINotificationObserver)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] void notify (in imgIRequest aProxy, in long aType, [const] in nsIntRect aRect); */
NS_IMETHODIMP _MYCLASS_::Notify(imgIRequest *aProxy, int32_t aType, const nsIntRect *aRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgINotificationObserver_h__ */
