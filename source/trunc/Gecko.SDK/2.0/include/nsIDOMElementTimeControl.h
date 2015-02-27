/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/smil/nsIDOMElementTimeControl.idl
 */

#ifndef __gen_nsIDOMElementTimeControl_h__
#define __gen_nsIDOMElementTimeControl_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMElementTimeControl */
#define NS_IDOMELEMENTTIMECONTROL_IID_STR "276a6678-7844-4d5e-8dfe-938c46089b84"

#define NS_IDOMELEMENTTIMECONTROL_IID \
  {0x276a6678, 0x7844, 0x4d5e, \
    { 0x8d, 0xfe, 0x93, 0x8c, 0x46, 0x08, 0x9b, 0x84 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMElementTimeControl : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMELEMENTTIMECONTROL_IID)

  /* void beginElement (); */
  NS_SCRIPTABLE NS_IMETHOD BeginElement(void) = 0;

  /* void beginElementAt (in float offset); */
  NS_SCRIPTABLE NS_IMETHOD BeginElementAt(float offset) = 0;

  /* void endElement (); */
  NS_SCRIPTABLE NS_IMETHOD EndElement(void) = 0;

  /* void endElementAt (in float offset); */
  NS_SCRIPTABLE NS_IMETHOD EndElementAt(float offset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMElementTimeControl, NS_IDOMELEMENTTIMECONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMELEMENTTIMECONTROL \
  NS_SCRIPTABLE NS_IMETHOD BeginElement(void); \
  NS_SCRIPTABLE NS_IMETHOD BeginElementAt(float offset); \
  NS_SCRIPTABLE NS_IMETHOD EndElement(void); \
  NS_SCRIPTABLE NS_IMETHOD EndElementAt(float offset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMELEMENTTIMECONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD BeginElement(void) { return _to BeginElement(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginElementAt(float offset) { return _to BeginElementAt(offset); } \
  NS_SCRIPTABLE NS_IMETHOD EndElement(void) { return _to EndElement(); } \
  NS_SCRIPTABLE NS_IMETHOD EndElementAt(float offset) { return _to EndElementAt(offset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMELEMENTTIMECONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD BeginElement(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginElement(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginElementAt(float offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginElementAt(offset); } \
  NS_SCRIPTABLE NS_IMETHOD EndElement(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndElement(); } \
  NS_SCRIPTABLE NS_IMETHOD EndElementAt(float offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndElementAt(offset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMElementTimeControl : public nsIDOMElementTimeControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMELEMENTTIMECONTROL

  nsDOMElementTimeControl();

private:
  ~nsDOMElementTimeControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMElementTimeControl, nsIDOMElementTimeControl)

nsDOMElementTimeControl::nsDOMElementTimeControl()
{
  /* member initializers and constructor code */
}

nsDOMElementTimeControl::~nsDOMElementTimeControl()
{
  /* destructor code */
}

/* void beginElement (); */
NS_IMETHODIMP nsDOMElementTimeControl::BeginElement()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginElementAt (in float offset); */
NS_IMETHODIMP nsDOMElementTimeControl::BeginElementAt(float offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endElement (); */
NS_IMETHODIMP nsDOMElementTimeControl::EndElement()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endElementAt (in float offset); */
NS_IMETHODIMP nsDOMElementTimeControl::EndElementAt(float offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMElementTimeControl_h__ */
