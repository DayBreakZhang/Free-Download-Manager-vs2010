/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIScrollable.idl
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
#define NS_ISCROLLABLE_IID_STR "3507fc93-313e-4a4c-8ca8-4d0ea0f97315"

#define NS_ISCROLLABLE_IID \
  {0x3507fc93, 0x313e, 0x4a4c, \
    { 0x8c, 0xa8, 0x4d, 0x0e, 0xa0, 0xf9, 0x73, 0x15 }}

class NS_NO_VTABLE nsIScrollable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCROLLABLE_IID)

  enum {
    ScrollOrientation_X = 1,
    ScrollOrientation_Y = 2,
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
  NS_IMETHOD GetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t *_retval); \
  NS_IMETHOD SetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t scrollbarPref); \
  NS_IMETHOD GetScrollbarVisibility(bool *verticalVisible, bool *horizontalVisible); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCROLLABLE(_to) \
  NS_IMETHOD GetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t *_retval) { return _to GetDefaultScrollbarPreferences(scrollOrientation, _retval); } \
  NS_IMETHOD SetDefaultScrollbarPreferences(int32_t scrollOrientation, int32_t scrollbarPref) { return _to SetDefaultScrollbarPreferences(scrollOrientation, scrollbarPref); } \
  NS_IMETHOD GetScrollbarVisibility(bool *verticalVisible, bool *horizontalVisible) { return _to GetScrollbarVisibility(verticalVisible, horizontalVisible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCROLLABLE(_to) \
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
