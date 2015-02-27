/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMozBrowserFrame.idl
 */

#ifndef __gen_nsIDOMMozBrowserFrame_h__
#define __gen_nsIDOMMozBrowserFrame_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozBrowserFrame */
#define NS_IDOMMOZBROWSERFRAME_IID_STR "4cafe116-581b-4194-b0de-7f02378fc51d"

#define NS_IDOMMOZBROWSERFRAME_IID \
  {0x4cafe116, 0x581b, 0x4194, \
    { 0xb0, 0xde, 0x7f, 0x02, 0x37, 0x8f, 0xc5, 0x1d }}

class NS_NO_VTABLE nsIDOMMozBrowserFrame : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZBROWSERFRAME_IID)

  /* attribute boolean mozbrowser; */
  NS_IMETHOD GetMozbrowser(bool *aMozbrowser) = 0;
  NS_IMETHOD SetMozbrowser(bool aMozbrowser) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozBrowserFrame, NS_IDOMMOZBROWSERFRAME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZBROWSERFRAME \
  NS_IMETHOD GetMozbrowser(bool *aMozbrowser); \
  NS_IMETHOD SetMozbrowser(bool aMozbrowser); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZBROWSERFRAME(_to) \
  NS_IMETHOD GetMozbrowser(bool *aMozbrowser) { return _to GetMozbrowser(aMozbrowser); } \
  NS_IMETHOD SetMozbrowser(bool aMozbrowser) { return _to SetMozbrowser(aMozbrowser); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZBROWSERFRAME(_to) \
  NS_IMETHOD GetMozbrowser(bool *aMozbrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozbrowser(aMozbrowser); } \
  NS_IMETHOD SetMozbrowser(bool aMozbrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozbrowser(aMozbrowser); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozBrowserFrame : public nsIDOMMozBrowserFrame
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZBROWSERFRAME

  nsDOMMozBrowserFrame();

private:
  ~nsDOMMozBrowserFrame();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozBrowserFrame, nsIDOMMozBrowserFrame)

nsDOMMozBrowserFrame::nsDOMMozBrowserFrame()
{
  /* member initializers and constructor code */
}

nsDOMMozBrowserFrame::~nsDOMMozBrowserFrame()
{
  /* destructor code */
}

/* attribute boolean mozbrowser; */
NS_IMETHODIMP nsDOMMozBrowserFrame::GetMozbrowser(bool *aMozbrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozBrowserFrame::SetMozbrowser(bool aMozbrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozBrowserFrame_h__ */
