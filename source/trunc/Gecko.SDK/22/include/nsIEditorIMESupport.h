/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/idl/nsIEditorIMESupport.idl
 */

#ifndef __gen_nsIEditorIMESupport_h__
#define __gen_nsIEditorIMESupport_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
namespace widget {
struct IMEState;
} // namespace widget
} // namespace mozilla

/* starting interface:    nsIEditorIMESupport */
#define NS_IEDITORIMESUPPORT_IID_STR "0ba7f490-afb8-46dd-87fc-bc6137fbc899"

#define NS_IEDITORIMESUPPORT_IID \
  {0x0ba7f490, 0xafb8, 0x46dd, \
    { 0x87, 0xfc, 0xbc, 0x61, 0x37, 0xfb, 0xc8, 0x99 }}

class NS_NO_VTABLE nsIEditorIMESupport : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORIMESUPPORT_IID)

  /* void forceCompositionEnd (); */
  NS_IMETHOD ForceCompositionEnd(void) = 0;

  /* [noscript] IMEState getPreferredIMEState (); */
  NS_IMETHOD GetPreferredIMEState(mozilla::widget::IMEState *_retval) = 0;

  /* readonly attribute boolean composing; */
  NS_IMETHOD GetComposing(bool *aComposing) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorIMESupport, NS_IEDITORIMESUPPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORIMESUPPORT \
  NS_IMETHOD ForceCompositionEnd(void); \
  NS_IMETHOD GetPreferredIMEState(mozilla::widget::IMEState *_retval); \
  NS_IMETHOD GetComposing(bool *aComposing); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORIMESUPPORT(_to) \
  NS_IMETHOD ForceCompositionEnd(void) { return _to ForceCompositionEnd(); } \
  NS_IMETHOD GetPreferredIMEState(mozilla::widget::IMEState *_retval) { return _to GetPreferredIMEState(_retval); } \
  NS_IMETHOD GetComposing(bool *aComposing) { return _to GetComposing(aComposing); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORIMESUPPORT(_to) \
  NS_IMETHOD ForceCompositionEnd(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceCompositionEnd(); } \
  NS_IMETHOD GetPreferredIMEState(mozilla::widget::IMEState *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredIMEState(_retval); } \
  NS_IMETHOD GetComposing(bool *aComposing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComposing(aComposing); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorIMESupport : public nsIEditorIMESupport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITORIMESUPPORT

  nsEditorIMESupport();

private:
  ~nsEditorIMESupport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorIMESupport, nsIEditorIMESupport)

nsEditorIMESupport::nsEditorIMESupport()
{
  /* member initializers and constructor code */
}

nsEditorIMESupport::~nsEditorIMESupport()
{
  /* destructor code */
}

/* void forceCompositionEnd (); */
NS_IMETHODIMP nsEditorIMESupport::ForceCompositionEnd()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] IMEState getPreferredIMEState (); */
NS_IMETHODIMP nsEditorIMESupport::GetPreferredIMEState(mozilla::widget::IMEState *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean composing; */
NS_IMETHODIMP nsEditorIMESupport::GetComposing(bool *aComposing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorIMESupport_h__ */
