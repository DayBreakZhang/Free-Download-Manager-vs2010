/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCanvasRenderingContext2D.idl
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
