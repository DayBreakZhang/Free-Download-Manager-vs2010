/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/range/nsIDOMNSRange.idl
 */

#ifndef __gen_nsIDOMNSRange_h__
#define __gen_nsIDOMNSRange_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSRange */
#define NS_IDOMNSRANGE_IID_STR "fed93d11-f24d-41d8-ae55-4197927999bb"

#define NS_IDOMNSRANGE_IID \
  {0xfed93d11, 0xf24d, 0x41d8, \
    { 0xae, 0x55, 0x41, 0x97, 0x92, 0x79, 0x99, 0xbb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSRange : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSRANGE_IID)

  /* nsIDOMDocumentFragment createContextualFragment (in DOMString fragment); */
  NS_SCRIPTABLE NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM) = 0;

  /* boolean isPointInRange (in nsIDOMNode parent, in long offset); */
  NS_SCRIPTABLE NS_IMETHOD IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM) = 0;

  /* short comparePoint (in nsIDOMNode parent, in long offset); */
  NS_SCRIPTABLE NS_IMETHOD ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM) = 0;

  /* nsIDOMClientRectList getClientRects (); */
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList **_retval NS_OUTPARAM) = 0;

  /* nsIDOMClientRect getBoundingClientRect (); */
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSRange, NS_IDOMNSRANGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSRANGE \
  NS_SCRIPTABLE NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSRANGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return _to CreateContextualFragment(fragment, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM) { return _to IsPointInRange(parent, offset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM) { return _to ComparePoint(parent, offset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList **_retval NS_OUTPARAM) { return _to GetClientRects(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect **_retval NS_OUTPARAM) { return _to GetBoundingClientRect(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSRANGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateContextualFragment(fragment, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPointInRange(parent, offset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ComparePoint(parent, offset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClientRects(nsIDOMClientRectList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientRects(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingClientRect(nsIDOMClientRect **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundingClientRect(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSRange : public nsIDOMNSRange
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSRANGE

  nsDOMNSRange();

private:
  ~nsDOMNSRange();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSRange, nsIDOMNSRange)

nsDOMNSRange::nsDOMNSRange()
{
  /* member initializers and constructor code */
}

nsDOMNSRange::~nsDOMNSRange()
{
  /* destructor code */
}

/* nsIDOMDocumentFragment createContextualFragment (in DOMString fragment); */
NS_IMETHODIMP nsDOMNSRange::CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isPointInRange (in nsIDOMNode parent, in long offset); */
NS_IMETHODIMP nsDOMNSRange::IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short comparePoint (in nsIDOMNode parent, in long offset); */
NS_IMETHODIMP nsDOMNSRange::ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRectList getClientRects (); */
NS_IMETHODIMP nsDOMNSRange::GetClientRects(nsIDOMClientRectList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect getBoundingClientRect (); */
NS_IMETHODIMP nsDOMNSRange::GetBoundingClientRect(nsIDOMClientRect **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSRange_h__ */
