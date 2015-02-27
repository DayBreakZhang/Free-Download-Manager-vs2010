/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/canvas/nsIDOMCanvasRenderingContext2D.idl
 */

#ifndef __gen_nsIDOMCanvasRenderingContext2D_h__
#define __gen_nsIDOMCanvasRenderingContext2D_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCanvasGradient */
#define NS_IDOMCANVASGRADIENT_IID_STR "bbb20a59-524e-4662-981e-5e142814b20c"

#define NS_IDOMCANVASGRADIENT_IID \
  {0xbbb20a59, 0x524e, 0x4662, \
    { 0x98, 0x1e, 0x5e, 0x14, 0x28, 0x14, 0xb2, 0x0c }}

class NS_NO_VTABLE nsIDOMCanvasGradient : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCANVASGRADIENT_IID)

  /* void addColorStop (in float offset, in DOMString color); */
  NS_IMETHOD AddColorStop(float offset, const nsAString & color) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCanvasGradient, NS_IDOMCANVASGRADIENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCANVASGRADIENT \
  NS_IMETHOD AddColorStop(float offset, const nsAString & color); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCANVASGRADIENT(_to) \
  NS_IMETHOD AddColorStop(float offset, const nsAString & color) { return _to AddColorStop(offset, color); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCANVASGRADIENT(_to) \
  NS_IMETHOD AddColorStop(float offset, const nsAString & color) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddColorStop(offset, color); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCanvasGradient : public nsIDOMCanvasGradient
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCANVASGRADIENT

  nsDOMCanvasGradient();

private:
  ~nsDOMCanvasGradient();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCanvasGradient, nsIDOMCanvasGradient)

nsDOMCanvasGradient::nsDOMCanvasGradient()
{
  /* member initializers and constructor code */
}

nsDOMCanvasGradient::~nsDOMCanvasGradient()
{
  /* destructor code */
}

/* void addColorStop (in float offset, in DOMString color); */
NS_IMETHODIMP nsDOMCanvasGradient::AddColorStop(float offset, const nsAString & color)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMCanvasPattern */
#define NS_IDOMCANVASPATTERN_IID_STR "21dea65c-5c08-4eb1-ac82-81fe95be77b8"

#define NS_IDOMCANVASPATTERN_IID \
  {0x21dea65c, 0x5c08, 0x4eb1, \
    { 0xac, 0x82, 0x81, 0xfe, 0x95, 0xbe, 0x77, 0xb8 }}

class NS_NO_VTABLE nsIDOMCanvasPattern : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCANVASPATTERN_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCanvasPattern, NS_IDOMCANVASPATTERN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCANVASPATTERN \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCANVASPATTERN(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCANVASPATTERN(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCanvasPattern : public nsIDOMCanvasPattern
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCANVASPATTERN

  nsDOMCanvasPattern();

private:
  ~nsDOMCanvasPattern();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCanvasPattern, nsIDOMCanvasPattern)

nsDOMCanvasPattern::nsDOMCanvasPattern()
{
  /* member initializers and constructor code */
}

nsDOMCanvasPattern::~nsDOMCanvasPattern()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMTextMetrics */
#define NS_IDOMTEXTMETRICS_IID_STR "2d01715c-ec7d-424a-ab85-e0fd70c8665c"

#define NS_IDOMTEXTMETRICS_IID \
  {0x2d01715c, 0xec7d, 0x424a, \
    { 0xab, 0x85, 0xe0, 0xfd, 0x70, 0xc8, 0x66, 0x5c }}

class NS_NO_VTABLE nsIDOMTextMetrics : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTEXTMETRICS_IID)

  /* readonly attribute float width; */
  NS_IMETHOD GetWidth(float *aWidth) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTextMetrics, NS_IDOMTEXTMETRICS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTEXTMETRICS \
  NS_IMETHOD GetWidth(float *aWidth); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTEXTMETRICS(_to) \
  NS_IMETHOD GetWidth(float *aWidth) { return _to GetWidth(aWidth); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTEXTMETRICS(_to) \
  NS_IMETHOD GetWidth(float *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTextMetrics : public nsIDOMTextMetrics
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTEXTMETRICS

  nsDOMTextMetrics();

private:
  ~nsDOMTextMetrics();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTextMetrics, nsIDOMTextMetrics)

nsDOMTextMetrics::nsDOMTextMetrics()
{
  /* member initializers and constructor code */
}

nsDOMTextMetrics::~nsDOMTextMetrics()
{
  /* destructor code */
}

/* readonly attribute float width; */
NS_IMETHODIMP nsDOMTextMetrics::GetWidth(float *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMCanvasRenderingContext2D */
#define NS_IDOMCANVASRENDERINGCONTEXT2D_IID_STR "4417cab7-c7eb-4e0c-b00a-c43842f0cba8"

#define NS_IDOMCANVASRENDERINGCONTEXT2D_IID \
  {0x4417cab7, 0xc7eb, 0x4e0c, \
    { 0xb0, 0x0a, 0xc4, 0x38, 0x42, 0xf0, 0xcb, 0xa8 }}

class NS_NO_VTABLE nsIDOMCanvasRenderingContext2D : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCANVASRENDERINGCONTEXT2D_IID)

  enum {
    DRAWWINDOW_DRAW_CARET = 1U,
    DRAWWINDOW_DO_NOT_FLUSH = 2U,
    DRAWWINDOW_DRAW_VIEW = 4U,
    DRAWWINDOW_USE_WIDGET_LAYERS = 8U,
    DRAWWINDOW_ASYNC_DECODE_IMAGES = 16U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCanvasRenderingContext2D, NS_IDOMCANVASRENDERINGCONTEXT2D_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCANVASRENDERINGCONTEXT2D \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCANVASRENDERINGCONTEXT2D(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCANVASRENDERINGCONTEXT2D(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCanvasRenderingContext2D : public nsIDOMCanvasRenderingContext2D
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCANVASRENDERINGCONTEXT2D

  nsDOMCanvasRenderingContext2D();

private:
  ~nsDOMCanvasRenderingContext2D();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCanvasRenderingContext2D, nsIDOMCanvasRenderingContext2D)

nsDOMCanvasRenderingContext2D::nsDOMCanvasRenderingContext2D()
{
  /* member initializers and constructor code */
}

nsDOMCanvasRenderingContext2D::~nsDOMCanvasRenderingContext2D()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCanvasRenderingContext2D_h__ */
