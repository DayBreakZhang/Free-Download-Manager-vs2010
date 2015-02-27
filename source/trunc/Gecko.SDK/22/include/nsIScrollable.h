/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsIScrollable.idl
 */

#ifndef __gen_nsIScrollable_h__
#define __gen_nsIScrollable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScrollable */
#define NS_ISCROLLABLE_IID_STR "919e792a-6490-40b8-bba5-f9e9ad5640c8"

#define NS_ISCROLLABLE_IID \
  {0x919e792a, 0x6490, 0x40b8, \
    { 0xbb, 0xa5, 0xf9, 0xe9, 0xad, 0x56, 0x40, 0xc8 }}

class NS_NO_VTABLE nsIScrollable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCROLLABLE_IID)

  enum {
    ScrollOrientation_X = 1,
    ScrollOrientation_Y = 2
  };

  /* long getCurScrollPos (in long scrollOrientation); */
  NS_IMETHOD GetCurScrollPos(int32_t scrollOrientation, int32_t *_retval) = 0;

  /* void setCurScrollPos (in long scrollOrientation, in long curPos); */
  NS_IMETHOD SetCurScrollPos(int32_t scrollOrientation, int32_t curPos) = 0;

  /* void setCurScrollPosEx (in long curHorizontalPos, in long curVerticalPos); */
  NS_IMETHOD SetCurScrollPosEx(int32_t curHorizontalPos, int32_t curVerticalPos) = 0;

  /* void getScrollRange (in long scrollOrientation, out long minPos, out long maxPos); */
  NS_IMETHOD GetScrollRange(int32_t scrollOrientation, int32_t *minPos, int32_t *maxPos) = 0;

  /* void setScrollRange (in long scrollOrientation, in long minPos, in long maxPos); */
  NS_IMETHOD SetScrollRange(int32_t scrollOrientation, int32_t minPos, int32_t maxPos) = 0;

  /* void setScrollRangeEx (in long minHorizontalPos, in long maxHorizontalPos, in long minVerticalPos, in long maxVerticalPos); */
  NS_IMETHOD SetScrollRangeEx(int32_t minHorizontalPos, int32_t maxHorizontalPos, int32_t minVerticalPos, int32_t maxVerticalPos) = 0;

  enum {
    Scrollbar_Auto = 1,
    Scrollbar_Never = 2,
    Scrollbar_Always = 3
  };

  /* long getDefaultScrollbarPreferences (in long scrollOrientation); */
  NS_IMETHOD GetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t *_retval) = 0;

  /* void setDefaultScrollbarPreferences (in long scrollOrientation, in long scrollbarPref); */
  NS_IMETHOD SetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t scrollbarPref) = 0;

  /* void getScrollbarVisibility (out boolean verticalVisible, out boolean horizontalVisible); */
  NS_IMETHOD GetScrollbarVisibility(bool *verticalVisible, bool *horizontalVisible) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScrollable, NS_ISCROLLABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCROLLABLE \
  NS_IMETHOD GetCurScrollPos(int32_t scrollOrientation, int32_t *_retval); \
  NS_IMETHOD SetCurScrollPos(int32_t scrollOrientation, int32_t curPos); \
  NS_IMETHOD SetCurScrollPosEx(int32_t curHorizontalPos, int32_t curVerticalPos); \
  NS_IMETHOD GetScrollRange(int32_t scrollOrientation, int32_t *minPos, int32_t *maxPos); \
  NS_IMETHOD SetScrollRange(int32_t scrollOrientation, int32_t minPos, int32_t maxPos); \
  NS_IMETHOD SetScrollRangeEx(int32_t minHorizontalPos, int32_t maxHorizontalPos, int32_t minVerticalPos, int32_t maxVerticalPos); \
  NS_IMETHOD GetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t *_retval); \
  NS_IMETHOD SetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t scrollbarPref); \
  NS_IMETHOD GetScrollbarVisibility(bool *verticalVisible, bool *horizontalVisible); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCROLLABLE(_to) \
  NS_IMETHOD GetCurScrollPos(int32_t scrollOrientation, int32_t *_retval) { return _to GetCurScrollPos(scrollOrientation, _retval); } \
  NS_IMETHOD SetCurScrollPos(int32_t scrollOrientation, int32_t curPos) { return _to SetCurScrollPos(scrollOrientation, curPos); } \
  NS_IMETHOD SetCurScrollPosEx(int32_t curHorizontalPos, int32_t curVerticalPos) { return _to SetCurScrollPosEx(curHorizontalPos, curVerticalPos); } \
  NS_IMETHOD GetScrollRange(int32_t scrollOrientation, int32_t *minPos, int32_t *maxPos) { return _to GetScrollRange(scrollOrientation, minPos, maxPos); } \
  NS_IMETHOD SetScrollRange(int32_t scrollOrientation, int32_t minPos, int32_t maxPos) { return _to SetScrollRange(scrollOrientation, minPos, maxPos); } \
  NS_IMETHOD SetScrollRangeEx(int32_t minHorizontalPos, int32_t maxHorizontalPos, int32_t minVerticalPos, int32_t maxVerticalPos) { return _to SetScrollRangeEx(minHorizontalPos, maxHorizontalPos, minVerticalPos, maxVerticalPos); } \
  NS_IMETHOD GetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t *_retval) { return _to GetDefaultScrollbarPreferences(scrollOrientation, _retval); } \
  NS_IMETHOD SetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t scrollbarPref) { return _to SetDefaultScrollbarPreferences(scrollOrientation, scrollbarPref); } \
  NS_IMETHOD GetScrollbarVisibility(bool *verticalVisible, bool *horizontalVisible) { return _to GetScrollbarVisibility(verticalVisible, horizontalVisible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCROLLABLE(_to) \
  NS_IMETHOD GetCurScrollPos(int32_t scrollOrientation, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurScrollPos(scrollOrientation, _retval); } \
  NS_IMETHOD SetCurScrollPos(int32_t scrollOrientation, int32_t curPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurScrollPos(scrollOrientation, curPos); } \
  NS_IMETHOD SetCurScrollPosEx(int32_t curHorizontalPos, int32_t curVerticalPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurScrollPosEx(curHorizontalPos, curVerticalPos); } \
  NS_IMETHOD GetScrollRange(int32_t scrollOrientation, int32_t *minPos, int32_t *maxPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollRange(scrollOrientation, minPos, maxPos); } \
  NS_IMETHOD SetScrollRange(int32_t scrollOrientation, int32_t minPos, int32_t maxPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollRange(scrollOrientation, minPos, maxPos); } \
  NS_IMETHOD SetScrollRangeEx(int32_t minHorizontalPos, int32_t maxHorizontalPos, int32_t minVerticalPos, int32_t maxVerticalPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollRangeEx(minHorizontalPos, maxHorizontalPos, minVerticalPos, maxVerticalPos); } \
  NS_IMETHOD GetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultScrollbarPreferences(scrollOrientation, _retval); } \
  NS_IMETHOD SetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t scrollbarPref) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultScrollbarPreferences(scrollOrientation, scrollbarPref); } \
  NS_IMETHOD GetScrollbarVisibility(bool *verticalVisible, bool *horizontalVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollbarVisibility(verticalVisible, horizontalVisible); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScrollable : public nsIScrollable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCROLLABLE

  nsScrollable();

private:
  ~nsScrollable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScrollable, nsIScrollable)

nsScrollable::nsScrollable()
{
  /* member initializers and constructor code */
}

nsScrollable::~nsScrollable()
{
  /* destructor code */
}

/* long getCurScrollPos (in long scrollOrientation); */
NS_IMETHODIMP nsScrollable::GetCurScrollPos(int32_t scrollOrientation, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCurScrollPos (in long scrollOrientation, in long curPos); */
NS_IMETHODIMP nsScrollable::SetCurScrollPos(int32_t scrollOrientation, int32_t curPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCurScrollPosEx (in long curHorizontalPos, in long curVerticalPos); */
NS_IMETHODIMP nsScrollable::SetCurScrollPosEx(int32_t curHorizontalPos, int32_t curVerticalPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollRange (in long scrollOrientation, out long minPos, out long maxPos); */
NS_IMETHODIMP nsScrollable::GetScrollRange(int32_t scrollOrientation, int32_t *minPos, int32_t *maxPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScrollRange (in long scrollOrientation, in long minPos, in long maxPos); */
NS_IMETHODIMP nsScrollable::SetScrollRange(int32_t scrollOrientation, int32_t minPos, int32_t maxPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScrollRangeEx (in long minHorizontalPos, in long maxHorizontalPos, in long minVerticalPos, in long maxVerticalPos); */
NS_IMETHODIMP nsScrollable::SetScrollRangeEx(int32_t minHorizontalPos, int32_t maxHorizontalPos, int32_t minVerticalPos, int32_t maxVerticalPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getDefaultScrollbarPreferences (in long scrollOrientation); */
NS_IMETHODIMP nsScrollable::GetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDefaultScrollbarPreferences (in long scrollOrientation, in long scrollbarPref); */
NS_IMETHODIMP nsScrollable::SetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t scrollbarPref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollbarVisibility (out boolean verticalVisible, out boolean horizontalVisible); */
NS_IMETHODIMP nsScrollable::GetScrollbarVisibility(bool *verticalVisible, bool *horizontalVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScrollable_h__ */
