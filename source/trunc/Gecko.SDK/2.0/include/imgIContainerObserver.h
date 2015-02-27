/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/libpr0n/public/imgIContainerObserver.idl
 */

#ifndef __gen_imgIContainerObserver_h__
#define __gen_imgIContainerObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_gfxidltypes_h__
#include "gfxidltypes.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsRect.h"
class imgIContainer; /* forward declaration */


/* starting interface:    imgIContainerObserver */
#define IMGICONTAINEROBSERVER_IID_STR "aa2068c1-6b91-4f52-8603-487b14ac5f04"

#define IMGICONTAINEROBSERVER_IID \
  {0xaa2068c1, 0x6b91, 0x4f52, \
    { 0x86, 0x03, 0x48, 0x7b, 0x14, 0xac, 0x5f, 0x04 }}

/**
 * imgIContainerObserver interface
 *
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.1
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgIContainerObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGICONTAINEROBSERVER_IID)

  /* [noscript] void frameChanged (in imgIContainer aContainer, [const] in nsIntRect aDirtyRect); */
  NS_IMETHOD FrameChanged(imgIContainer *aContainer, const nsIntRect *aDirtyRect) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIContainerObserver, IMGICONTAINEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGICONTAINEROBSERVER \
  NS_IMETHOD FrameChanged(imgIContainer *aContainer, const nsIntRect *aDirtyRect); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGICONTAINEROBSERVER(_to) \
  NS_IMETHOD FrameChanged(imgIContainer *aContainer, const nsIntRect *aDirtyRect) { return _to FrameChanged(aContainer, aDirtyRect); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGICONTAINEROBSERVER(_to) \
  NS_IMETHOD FrameChanged(imgIContainer *aContainer, const nsIntRect *aDirtyRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->FrameChanged(aContainer, aDirtyRect); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIContainerObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGICONTAINEROBSERVER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIContainerObserver)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] void frameChanged (in imgIContainer aContainer, [const] in nsIntRect aDirtyRect); */
NS_IMETHODIMP _MYCLASS_::FrameChanged(imgIContainer *aContainer, const nsIntRect *aDirtyRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIContainerObserver_h__ */
