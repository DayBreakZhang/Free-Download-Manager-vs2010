/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITabParent.idl
 */

#ifndef __gen_nsITabParent_h__
#define __gen_nsITabParent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITabParent */
#define NS_ITABPARENT_IID_STR "33e8571d-5e5d-4000-81cf-e01f5f85d424"

#define NS_ITABPARENT_IID \
  {0x33e8571d, 0x5e5d, 0x4000, \
    { 0x81, 0xcf, 0xe0, 0x1f, 0x5f, 0x85, 0xd4, 0x24 }}

class NS_NO_VTABLE nsITabParent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABPARENT_IID)

  /* void injectTouchEvent (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers); */
  NS_IMETHOD InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers) = 0;

  /* readonly attribute boolean useAsyncPanZoom; */
  NS_IMETHOD GetUseAsyncPanZoom(bool *aUseAsyncPanZoom) = 0;

  /* void setIsDocShellActive (in bool aIsActive); */
  NS_IMETHOD SetIsDocShellActive(bool aIsActive) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabParent, NS_ITABPARENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABPARENT \
  NS_IMETHOD InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers); \
  NS_IMETHOD GetUseAsyncPanZoom(bool *aUseAsyncPanZoom); \
  NS_IMETHOD SetIsDocShellActive(bool aIsActive); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABPARENT(_to) \
  NS_IMETHOD InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers) { return _to InjectTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers); } \
  NS_IMETHOD GetUseAsyncPanZoom(bool *aUseAsyncPanZoom) { return _to GetUseAsyncPanZoom(aUseAsyncPanZoom); } \
  NS_IMETHOD SetIsDocShellActive(bool aIsActive) { return _to SetIsDocShellActive(aIsActive); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABPARENT(_to) \
  NS_IMETHOD InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers) { return !_to ? NS_ERROR_NULL_POINTER : _to->InjectTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers); } \
  NS_IMETHOD GetUseAsyncPanZoom(bool *aUseAsyncPanZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseAsyncPanZoom(aUseAsyncPanZoom); } \
  NS_IMETHOD SetIsDocShellActive(bool aIsActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsDocShellActive(aIsActive); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTabParent : public nsITabParent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABPARENT

  nsTabParent();

private:
  ~nsTabParent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTabParent, nsITabParent)

nsTabParent::nsTabParent()
{
  /* member initializers and constructor code */
}

nsTabParent::~nsTabParent()
{
  /* destructor code */
}

/* void injectTouchEvent (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers); */
NS_IMETHODIMP nsTabParent::InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean useAsyncPanZoom; */
NS_IMETHODIMP nsTabParent::GetUseAsyncPanZoom(bool *aUseAsyncPanZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIsDocShellActive (in bool aIsActive); */
NS_IMETHODIMP nsTabParent::SetIsDocShellActive(bool aIsActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITabParent_h__ */
