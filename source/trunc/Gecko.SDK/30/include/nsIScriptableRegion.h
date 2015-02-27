/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIScriptableRegion.idl
 */

#ifndef __gen_nsIScriptableRegion_h__
#define __gen_nsIScriptableRegion_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIntRegion;

/* starting interface:    nsIScriptableRegion */
#define NS_ISCRIPTABLEREGION_IID_STR "a5f44cc7-2820-489b-b817-ae8a08506ff6"

#define NS_ISCRIPTABLEREGION_IID \
  {0xa5f44cc7, 0x2820, 0x489b, \
    { 0xb8, 0x17, 0xae, 0x8a, 0x08, 0x50, 0x6f, 0xf6 }}

class NS_NO_VTABLE nsIScriptableRegion : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEREGION_IID)

  /* void init (); */
  NS_IMETHOD Init(void) = 0;

  /* void setToRegion (in nsIScriptableRegion aRegion); */
  NS_IMETHOD SetToRegion(nsIScriptableRegion *aRegion) = 0;

  /* void setToRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_IMETHOD SetToRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) = 0;

  /* void intersectRegion (in nsIScriptableRegion aRegion); */
  NS_IMETHOD IntersectRegion(nsIScriptableRegion *aRegion) = 0;

  /* void intersectRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_IMETHOD IntersectRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) = 0;

  /* void unionRegion (in nsIScriptableRegion aRegion); */
  NS_IMETHOD UnionRegion(nsIScriptableRegion *aRegion) = 0;

  /* void unionRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_IMETHOD UnionRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) = 0;

  /* void subtractRegion (in nsIScriptableRegion aRegion); */
  NS_IMETHOD SubtractRegion(nsIScriptableRegion *aRegion) = 0;

  /* void subtractRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_IMETHOD SubtractRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) = 0;

  /* boolean isEmpty (); */
  NS_IMETHOD IsEmpty(bool *_retval) = 0;

  /* boolean isEqualRegion (in nsIScriptableRegion aRegion); */
  NS_IMETHOD IsEqualRegion(nsIScriptableRegion *aRegion, bool *_retval) = 0;

  /* void getBoundingBox (out long aX, out long aY, out long aWidth, out long aHeight); */
  NS_IMETHOD GetBoundingBox(int32_t *aX, int32_t *aY, int32_t *aWidth, int32_t *aHeight) = 0;

  /* void offset (in long aXOffset, in long aYOffset); */
  NS_IMETHOD Offset(int32_t aXOffset, int32_t aYOffset) = 0;

  /* [implicit_jscontext] jsval getRects (); */
  NS_IMETHOD GetRects(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* boolean containsRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_IMETHOD ContainsRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, bool *_retval) = 0;

  /* [noscript] readonly attribute nsIntRegion region; */
  NS_IMETHOD GetRegion(nsIntRegion *aRegion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableRegion, NS_ISCRIPTABLEREGION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEREGION \
  NS_IMETHOD Init(void); \
  NS_IMETHOD SetToRegion(nsIScriptableRegion *aRegion); \
  NS_IMETHOD SetToRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight); \
  NS_IMETHOD IntersectRegion(nsIScriptableRegion *aRegion); \
  NS_IMETHOD IntersectRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight); \
  NS_IMETHOD UnionRegion(nsIScriptableRegion *aRegion); \
  NS_IMETHOD UnionRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight); \
  NS_IMETHOD SubtractRegion(nsIScriptableRegion *aRegion); \
  NS_IMETHOD SubtractRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight); \
  NS_IMETHOD IsEmpty(bool *_retval); \
  NS_IMETHOD IsEqualRegion(nsIScriptableRegion *aRegion, bool *_retval); \
  NS_IMETHOD GetBoundingBox(int32_t *aX, int32_t *aY, int32_t *aWidth, int32_t *aHeight); \
  NS_IMETHOD Offset(int32_t aXOffset, int32_t aYOffset); \
  NS_IMETHOD GetRects(JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD ContainsRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, bool *_retval); \
  NS_IMETHOD GetRegion(nsIntRegion *aRegion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEREGION(_to) \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD SetToRegion(nsIScriptableRegion *aRegion) { return _to SetToRegion(aRegion); } \
  NS_IMETHOD SetToRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) { return _to SetToRect(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD IntersectRegion(nsIScriptableRegion *aRegion) { return _to IntersectRegion(aRegion); } \
  NS_IMETHOD IntersectRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) { return _to IntersectRect(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD UnionRegion(nsIScriptableRegion *aRegion) { return _to UnionRegion(aRegion); } \
  NS_IMETHOD UnionRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) { return _to UnionRect(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD SubtractRegion(nsIScriptableRegion *aRegion) { return _to SubtractRegion(aRegion); } \
  NS_IMETHOD SubtractRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) { return _to SubtractRect(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD IsEmpty(bool *_retval) { return _to IsEmpty(_retval); } \
  NS_IMETHOD IsEqualRegion(nsIScriptableRegion *aRegion, bool *_retval) { return _to IsEqualRegion(aRegion, _retval); } \
  NS_IMETHOD GetBoundingBox(int32_t *aX, int32_t *aY, int32_t *aWidth, int32_t *aHeight) { return _to GetBoundingBox(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD Offset(int32_t aXOffset, int32_t aYOffset) { return _to Offset(aXOffset, aYOffset); } \
  NS_IMETHOD GetRects(JSContext* cx, JS::MutableHandleValue _retval) { return _to GetRects(cx, _retval); } \
  NS_IMETHOD ContainsRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, bool *_retval) { return _to ContainsRect(aX, aY, aWidth, aHeight, _retval); } \
  NS_IMETHOD GetRegion(nsIntRegion *aRegion) { return _to GetRegion(aRegion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEREGION(_to) \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD SetToRegion(nsIScriptableRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetToRegion(aRegion); } \
  NS_IMETHOD SetToRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetToRect(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD IntersectRegion(nsIScriptableRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->IntersectRegion(aRegion); } \
  NS_IMETHOD IntersectRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->IntersectRect(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD UnionRegion(nsIScriptableRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnionRegion(aRegion); } \
  NS_IMETHOD UnionRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnionRect(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD SubtractRegion(nsIScriptableRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubtractRegion(aRegion); } \
  NS_IMETHOD SubtractRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubtractRect(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD IsEmpty(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEmpty(_retval); } \
  NS_IMETHOD IsEqualRegion(nsIScriptableRegion *aRegion, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualRegion(aRegion, _retval); } \
  NS_IMETHOD GetBoundingBox(int32_t *aX, int32_t *aY, int32_t *aWidth, int32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundingBox(aX, aY, aWidth, aHeight); } \
  NS_IMETHOD Offset(int32_t aXOffset, int32_t aYOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->Offset(aXOffset, aYOffset); } \
  NS_IMETHOD GetRects(JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRects(cx, _retval); } \
  NS_IMETHOD ContainsRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainsRect(aX, aY, aWidth, aHeight, _retval); } \
  NS_IMETHOD GetRegion(nsIntRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegion(aRegion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableRegion : public nsIScriptableRegion
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEREGION

  nsScriptableRegion();

private:
  ~nsScriptableRegion();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableRegion, nsIScriptableRegion)

nsScriptableRegion::nsScriptableRegion()
{
  /* member initializers and constructor code */
}

nsScriptableRegion::~nsScriptableRegion()
{
  /* destructor code */
}

/* void init (); */
NS_IMETHODIMP nsScriptableRegion::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setToRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::SetToRegion(nsIScriptableRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setToRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::SetToRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void intersectRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::IntersectRegion(nsIScriptableRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void intersectRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::IntersectRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unionRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::UnionRegion(nsIScriptableRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unionRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::UnionRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void subtractRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::SubtractRegion(nsIScriptableRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void subtractRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::SubtractRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEmpty (); */
NS_IMETHODIMP nsScriptableRegion::IsEmpty(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::IsEqualRegion(nsIScriptableRegion *aRegion, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBoundingBox (out long aX, out long aY, out long aWidth, out long aHeight); */
NS_IMETHODIMP nsScriptableRegion::GetBoundingBox(int32_t *aX, int32_t *aY, int32_t *aWidth, int32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void offset (in long aXOffset, in long aYOffset); */
NS_IMETHODIMP nsScriptableRegion::Offset(int32_t aXOffset, int32_t aYOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getRects (); */
NS_IMETHODIMP nsScriptableRegion::GetRects(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean containsRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::ContainsRect(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIntRegion region; */
NS_IMETHODIMP nsScriptableRegion::GetRegion(nsIntRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableRegion_h__ */
