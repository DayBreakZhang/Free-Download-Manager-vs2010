/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/libpr0n/public/imgIContainerDebug.idl
 */

#ifndef __gen_imgIContainerDebug_h__
#define __gen_imgIContainerDebug_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    imgIContainerDebug */
#define IMGICONTAINERDEBUG_IID_STR "52cbb839-6e63-4a70-b21a-1db4ca706c49"

#define IMGICONTAINERDEBUG_IID \
  {0x52cbb839, 0x6e63, 0x4a70, \
    { 0xb2, 0x1a, 0x1d, 0xb4, 0xca, 0x70, 0x6c, 0x49 }}

/**
 * This interface is used in debug builds (and only there) in
 * order to let automatic tests running JavaScript access
 * internal state of imgContainers. This lets us test
 * things like animation.
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgIContainerDebug : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGICONTAINERDEBUG_IID)

  /**
   * The # of frames this imgContainer has been notified about.
   * That is equal to the # of times the animation timer has
   * fired, and is usually equal to the # of frames actually
   * drawn (but actual drawing might be disabled).
   */
  /* readonly attribute PRUint32 framesNotified; */
  NS_SCRIPTABLE NS_IMETHOD GetFramesNotified(PRUint32 *aFramesNotified) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIContainerDebug, IMGICONTAINERDEBUG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGICONTAINERDEBUG \
  NS_SCRIPTABLE NS_IMETHOD GetFramesNotified(PRUint32 *aFramesNotified); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGICONTAINERDEBUG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFramesNotified(PRUint32 *aFramesNotified) { return _to GetFramesNotified(aFramesNotified); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGICONTAINERDEBUG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFramesNotified(PRUint32 *aFramesNotified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFramesNotified(aFramesNotified); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIContainerDebug
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGICONTAINERDEBUG

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIContainerDebug)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute PRUint32 framesNotified; */
NS_IMETHODIMP _MYCLASS_::GetFramesNotified(PRUint32 *aFramesNotified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIContainerDebug_h__ */
