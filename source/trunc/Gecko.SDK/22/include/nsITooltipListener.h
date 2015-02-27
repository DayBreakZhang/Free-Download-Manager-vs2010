/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/browser/webBrowser/nsITooltipListener.idl
 */

#ifndef __gen_nsITooltipListener_h__
#define __gen_nsITooltipListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITooltipListener */
#define NS_ITOOLTIPLISTENER_IID_STR "44b78386-1dd2-11b2-9ad2-e4eee2ca1916"

#define NS_ITOOLTIPLISTENER_IID \
  {0x44b78386, 0x1dd2, 0x11b2, \
    { 0x9a, 0xd2, 0xe4, 0xee, 0xe2, 0xca, 0x19, 0x16 }}

class NS_NO_VTABLE nsITooltipListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLTIPLISTENER_IID)

  /* void onShowTooltip (in long aXCoords, in long aYCoords, in wstring aTipText); */
  NS_IMETHOD OnShowTooltip(int32_t aXCoords, int32_t aYCoords, const PRUnichar * aTipText) = 0;

  /* void onHideTooltip (); */
  NS_IMETHOD OnHideTooltip(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITooltipListener, NS_ITOOLTIPLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLTIPLISTENER \
  NS_IMETHOD OnShowTooltip(int32_t aXCoords, int32_t aYCoords, const PRUnichar * aTipText); \
  NS_IMETHOD OnHideTooltip(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLTIPLISTENER(_to) \
  NS_IMETHOD OnShowTooltip(int32_t aXCoords, int32_t aYCoords, const PRUnichar * aTipText) { return _to OnShowTooltip(aXCoords, aYCoords, aTipText); } \
  NS_IMETHOD OnHideTooltip(void) { return _to OnHideTooltip(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLTIPLISTENER(_to) \
  NS_IMETHOD OnShowTooltip(int32_t aXCoords, int32_t aYCoords, const PRUnichar * aTipText) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnShowTooltip(aXCoords, aYCoords, aTipText); } \
  NS_IMETHOD OnHideTooltip(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHideTooltip(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTooltipListener : public nsITooltipListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLTIPLISTENER

  nsTooltipListener();

private:
  ~nsTooltipListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTooltipListener, nsITooltipListener)

nsTooltipListener::nsTooltipListener()
{
  /* member initializers and constructor code */
}

nsTooltipListener::~nsTooltipListener()
{
  /* destructor code */
}

/* void onShowTooltip (in long aXCoords, in long aYCoords, in wstring aTipText); */
NS_IMETHODIMP nsTooltipListener::OnShowTooltip(int32_t aXCoords, int32_t aYCoords, const PRUnichar * aTipText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onHideTooltip (); */
NS_IMETHODIMP nsTooltipListener::OnHideTooltip()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITooltipListener_h__ */
