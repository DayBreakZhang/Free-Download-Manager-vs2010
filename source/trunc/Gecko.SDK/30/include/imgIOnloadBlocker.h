/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\imgIOnloadBlocker.idl
 */

#ifndef __gen_imgIOnloadBlocker_h__
#define __gen_imgIOnloadBlocker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIRequest; /* forward declaration */


/* starting interface:    imgIOnloadBlocker */
#define IMGIONLOADBLOCKER_IID_STR "dc126d90-0ee0-4683-b942-2fa66e443abc"

#define IMGIONLOADBLOCKER_IID \
  {0xdc126d90, 0x0ee0, 0x4683, \
    { 0xb9, 0x42, 0x2f, 0xa6, 0x6e, 0x44, 0x3a, 0xbc }}

class NS_NO_VTABLE imgIOnloadBlocker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGIONLOADBLOCKER_IID)

  /* void blockOnload (in imgIRequest aRequest); */
  NS_IMETHOD BlockOnload(imgIRequest *aRequest) = 0;

  /* void unblockOnload (in imgIRequest aRequest); */
  NS_IMETHOD UnblockOnload(imgIRequest *aRequest) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIOnloadBlocker, IMGIONLOADBLOCKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGIONLOADBLOCKER \
  NS_IMETHOD BlockOnload(imgIRequest *aRequest); \
  NS_IMETHOD UnblockOnload(imgIRequest *aRequest); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGIONLOADBLOCKER(_to) \
  NS_IMETHOD BlockOnload(imgIRequest *aRequest) { return _to BlockOnload(aRequest); } \
  NS_IMETHOD UnblockOnload(imgIRequest *aRequest) { return _to UnblockOnload(aRequest); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGIONLOADBLOCKER(_to) \
  NS_IMETHOD BlockOnload(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->BlockOnload(aRequest); } \
  NS_IMETHOD UnblockOnload(imgIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnblockOnload(aRequest); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIOnloadBlocker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGIONLOADBLOCKER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIOnloadBlocker)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void blockOnload (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::BlockOnload(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unblockOnload (in imgIRequest aRequest); */
NS_IMETHODIMP _MYCLASS_::UnblockOnload(imgIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIOnloadBlocker_h__ */
