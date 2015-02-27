/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/editor/idl/nsIEditorIMESupport.idl
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

/* starting interface:    nsIEditorIMESupport */
#define NS_IEDITORIMESUPPORT_IID_STR "a64744c5-d3ff-46ba-b9b1-57f79ff7d97d"

#define NS_IEDITORIMESUPPORT_IID \
  {0xa64744c5, 0xd3ff, 0x46ba, \
    { 0xb9, 0xb1, 0x57, 0xf7, 0x9f, 0xf7, 0xd9, 0x7d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIEditorIMESupport : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORIMESUPPORT_IID)

  /**
   * forceCompositionEnd() force the composition end
   */
  /* void forceCompositionEnd (); */
  NS_SCRIPTABLE NS_IMETHOD ForceCompositionEnd(void) = 0;

  /**
   * Get preferred IME status of current widget.
   */
  /* [noscript] void getPreferredIMEState (out unsigned long aState); */
  NS_IMETHOD GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM) = 0;

  /**
   * whether this editor has active IME transaction
   */
  /* readonly attribute boolean composing; */
  NS_SCRIPTABLE NS_IMETHOD GetComposing(PRBool *aComposing) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorIMESupport, NS_IEDITORIMESUPPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORIMESUPPORT \
  NS_SCRIPTABLE NS_IMETHOD ForceCompositionEnd(void); \
  NS_IMETHOD GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetComposing(PRBool *aComposing); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORIMESUPPORT(_to) \
  NS_SCRIPTABLE NS_IMETHOD ForceCompositionEnd(void) { return _to ForceCompositionEnd(); } \
  NS_IMETHOD GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM) { return _to GetPreferredIMEState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetComposing(PRBool *aComposing) { return _to GetComposing(aComposing); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORIMESUPPORT(_to) \
  NS_SCRIPTABLE NS_IMETHOD ForceCompositionEnd(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceCompositionEnd(); } \
  NS_IMETHOD GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredIMEState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetComposing(PRBool *aComposing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComposing(aComposing); } 

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

/* [noscript] void getPreferredIMEState (out unsigned long aState); */
NS_IMETHODIMP nsEditorIMESupport::GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean composing; */
NS_IMETHODIMP nsEditorIMESupport::GetComposing(PRBool *aComposing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorIMESupport_h__ */
