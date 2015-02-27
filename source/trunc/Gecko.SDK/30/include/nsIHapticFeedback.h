/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHapticFeedback.idl
 */

#ifndef __gen_nsIHapticFeedback_h__
#define __gen_nsIHapticFeedback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHapticFeedback */
#define NS_IHAPTICFEEDBACK_IID_STR "91917c98-a8f3-4c98-8f10-4afb872f54c7"

#define NS_IHAPTICFEEDBACK_IID \
  {0x91917c98, 0xa8f3, 0x4c98, \
    { 0x8f, 0x10, 0x4a, 0xfb, 0x87, 0x2f, 0x54, 0xc7 }}

class NS_NO_VTABLE nsIHapticFeedback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHAPTICFEEDBACK_IID)

  enum {
    ShortPress = 0,
    LongPress = 1
  };

  /* void performSimpleAction (in long isLongPress); */
  NS_IMETHOD PerformSimpleAction(int32_t isLongPress) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHapticFeedback, NS_IHAPTICFEEDBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHAPTICFEEDBACK \
  NS_IMETHOD PerformSimpleAction(int32_t isLongPress); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHAPTICFEEDBACK(_to) \
  NS_IMETHOD PerformSimpleAction(int32_t isLongPress) { return _to PerformSimpleAction(isLongPress); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHAPTICFEEDBACK(_to) \
  NS_IMETHOD PerformSimpleAction(int32_t isLongPress) { return !_to ? NS_ERROR_NULL_POINTER : _to->PerformSimpleAction(isLongPress); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHapticFeedback : public nsIHapticFeedback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHAPTICFEEDBACK

  nsHapticFeedback();

private:
  ~nsHapticFeedback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHapticFeedback, nsIHapticFeedback)

nsHapticFeedback::nsHapticFeedback()
{
  /* member initializers and constructor code */
}

nsHapticFeedback::~nsHapticFeedback()
{
  /* destructor code */
}

/* void performSimpleAction (in long isLongPress); */
NS_IMETHODIMP nsHapticFeedback::PerformSimpleAction(int32_t isLongPress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHapticFeedback_h__ */
