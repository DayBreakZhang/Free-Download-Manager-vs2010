/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsITextScroll.idl
 */

#ifndef __gen_nsITextScroll_h__
#define __gen_nsITextScroll_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITextScroll */
#define NS_ITEXTSCROLL_IID_STR "067b28a0-877f-11d3-af7e-00a024ffc08c"

#define NS_ITEXTSCROLL_IID \
  {0x067b28a0, 0x877f, 0x11d3, \
    { 0xaf, 0x7e, 0x00, 0xa0, 0x24, 0xff, 0xc0, 0x8c }}

class NS_NO_VTABLE nsITextScroll : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITEXTSCROLL_IID)

  /* void scrollByLines (in long numLines); */
  NS_IMETHOD ScrollByLines(int32_t numLines) = 0;

  /* void scrollByPages (in long numPages); */
  NS_IMETHOD ScrollByPages(int32_t numPages) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITextScroll, NS_ITEXTSCROLL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITEXTSCROLL \
  NS_IMETHOD ScrollByLines(int32_t numLines); \
  NS_IMETHOD ScrollByPages(int32_t numPages); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITEXTSCROLL(_to) \
  NS_IMETHOD ScrollByLines(int32_t numLines) { return _to ScrollByLines(numLines); } \
  NS_IMETHOD ScrollByPages(int32_t numPages) { return _to ScrollByPages(numPages); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITEXTSCROLL(_to) \
  NS_IMETHOD ScrollByLines(int32_t numLines) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLines(numLines); } \
  NS_IMETHOD ScrollByPages(int32_t numPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByPages(numPages); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTextScroll : public nsITextScroll
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITEXTSCROLL

  nsTextScroll();

private:
  ~nsTextScroll();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTextScroll, nsITextScroll)

nsTextScroll::nsTextScroll()
{
  /* member initializers and constructor code */
}

nsTextScroll::~nsTextScroll()
{
  /* destructor code */
}

/* void scrollByLines (in long numLines); */
NS_IMETHODIMP nsTextScroll::ScrollByLines(int32_t numLines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByPages (in long numPages); */
NS_IMETHODIMP nsTextScroll::ScrollByPages(int32_t numPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITextScroll_h__ */
