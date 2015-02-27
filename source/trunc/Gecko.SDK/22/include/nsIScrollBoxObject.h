/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/layout/xul/base/public/nsIScrollBoxObject.idl
 */

#ifndef __gen_nsIScrollBoxObject_h__
#define __gen_nsIScrollBoxObject_h__


#ifndef __gen_nsIBoxObject_h__
#include "nsIBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIScrollBoxObject */
#define NS_ISCROLLBOXOBJECT_IID_STR "56e2ada8-4631-11d4-ba11-001083023c1e"

#define NS_ISCROLLBOXOBJECT_IID \
  {0x56e2ada8, 0x4631, 0x11d4, \
    { 0xba, 0x11, 0x00, 0x10, 0x83, 0x02, 0x3c, 0x1e }}

class NS_NO_VTABLE nsIScrollBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCROLLBOXOBJECT_IID)

  /* void scrollTo (in long x, in long y); */
  NS_IMETHOD ScrollTo(int32_t x, int32_t y) = 0;

  /* void scrollBy (in long dx, in long dy); */
  NS_IMETHOD ScrollBy(int32_t dx, int32_t dy) = 0;

  /* void scrollByLine (in long dlines); */
  NS_IMETHOD ScrollByLine(int32_t dlines) = 0;

  /* void scrollByIndex (in long dindexes); */
  NS_IMETHOD ScrollByIndex(int32_t dindexes) = 0;

  /* void scrollToLine (in long line); */
  NS_IMETHOD ScrollToLine(int32_t line) = 0;

  /* void scrollToElement (in nsIDOMElement child); */
  NS_IMETHOD ScrollToElement(nsIDOMElement *child) = 0;

  /* void scrollToIndex (in long index); */
  NS_IMETHOD ScrollToIndex(int32_t index) = 0;

  /* void getPosition (out long x, out long y); */
  NS_IMETHOD GetPosition(int32_t *x, int32_t *y) = 0;

  /* void getScrolledSize (out long width, out long height); */
  NS_IMETHOD GetScrolledSize(int32_t *width, int32_t *height) = 0;

  /* void ensureElementIsVisible (in nsIDOMElement child); */
  NS_IMETHOD EnsureElementIsVisible(nsIDOMElement *child) = 0;

  /* void ensureIndexIsVisible (in long index); */
  NS_IMETHOD EnsureIndexIsVisible(int32_t index) = 0;

  /* void ensureLineIsVisible (in long line); */
  NS_IMETHOD EnsureLineIsVisible(int32_t line) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScrollBoxObject, NS_ISCROLLBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCROLLBOXOBJECT \
  NS_IMETHOD ScrollTo(int32_t x, int32_t y); \
  NS_IMETHOD ScrollBy(int32_t dx, int32_t dy); \
  NS_IMETHOD ScrollByLine(int32_t dlines); \
  NS_IMETHOD ScrollByIndex(int32_t dindexes); \
  NS_IMETHOD ScrollToLine(int32_t line); \
  NS_IMETHOD ScrollToElement(nsIDOMElement *child); \
  NS_IMETHOD ScrollToIndex(int32_t index); \
  NS_IMETHOD GetPosition(int32_t *x, int32_t *y); \
  NS_IMETHOD GetScrolledSize(int32_t *width, int32_t *height); \
  NS_IMETHOD EnsureElementIsVisible(nsIDOMElement *child); \
  NS_IMETHOD EnsureIndexIsVisible(int32_t index); \
  NS_IMETHOD EnsureLineIsVisible(int32_t line); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCROLLBOXOBJECT(_to) \
  NS_IMETHOD ScrollTo(int32_t x, int32_t y) { return _to ScrollTo(x, y); } \
  NS_IMETHOD ScrollBy(int32_t dx, int32_t dy) { return _to ScrollBy(dx, dy); } \
  NS_IMETHOD ScrollByLine(int32_t dlines) { return _to ScrollByLine(dlines); } \
  NS_IMETHOD ScrollByIndex(int32_t dindexes) { return _to ScrollByIndex(dindexes); } \
  NS_IMETHOD ScrollToLine(int32_t line) { return _to ScrollToLine(line); } \
  NS_IMETHOD ScrollToElement(nsIDOMElement *child) { return _to ScrollToElement(child); } \
  NS_IMETHOD ScrollToIndex(int32_t index) { return _to ScrollToIndex(index); } \
  NS_IMETHOD GetPosition(int32_t *x, int32_t *y) { return _to GetPosition(x, y); } \
  NS_IMETHOD GetScrolledSize(int32_t *width, int32_t *height) { return _to GetScrolledSize(width, height); } \
  NS_IMETHOD EnsureElementIsVisible(nsIDOMElement *child) { return _to EnsureElementIsVisible(child); } \
  NS_IMETHOD EnsureIndexIsVisible(int32_t index) { return _to EnsureIndexIsVisible(index); } \
  NS_IMETHOD EnsureLineIsVisible(int32_t line) { return _to EnsureLineIsVisible(line); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCROLLBOXOBJECT(_to) \
  NS_IMETHOD ScrollTo(int32_t x, int32_t y) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollTo(x, y); } \
  NS_IMETHOD ScrollBy(int32_t dx, int32_t dy) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollBy(dx, dy); } \
  NS_IMETHOD ScrollByLine(int32_t dlines) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLine(dlines); } \
  NS_IMETHOD ScrollByIndex(int32_t dindexes) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByIndex(dindexes); } \
  NS_IMETHOD ScrollToLine(int32_t line) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToLine(line); } \
  NS_IMETHOD ScrollToElement(nsIDOMElement *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToElement(child); } \
  NS_IMETHOD ScrollToIndex(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToIndex(index); } \
  NS_IMETHOD GetPosition(int32_t *x, int32_t *y) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(x, y); } \
  NS_IMETHOD GetScrolledSize(int32_t *width, int32_t *height) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrolledSize(width, height); } \
  NS_IMETHOD EnsureElementIsVisible(nsIDOMElement *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureElementIsVisible(child); } \
  NS_IMETHOD EnsureIndexIsVisible(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureIndexIsVisible(index); } \
  NS_IMETHOD EnsureLineIsVisible(int32_t line) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureLineIsVisible(line); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScrollBoxObject : public nsIScrollBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCROLLBOXOBJECT

  nsScrollBoxObject();

private:
  ~nsScrollBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScrollBoxObject, nsIScrollBoxObject)

nsScrollBoxObject::nsScrollBoxObject()
{
  /* member initializers and constructor code */
}

nsScrollBoxObject::~nsScrollBoxObject()
{
  /* destructor code */
}

/* void scrollTo (in long x, in long y); */
NS_IMETHODIMP nsScrollBoxObject::ScrollTo(int32_t x, int32_t y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollBy (in long dx, in long dy); */
NS_IMETHODIMP nsScrollBoxObject::ScrollBy(int32_t dx, int32_t dy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByLine (in long dlines); */
NS_IMETHODIMP nsScrollBoxObject::ScrollByLine(int32_t dlines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByIndex (in long dindexes); */
NS_IMETHODIMP nsScrollBoxObject::ScrollByIndex(int32_t dindexes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToLine (in long line); */
NS_IMETHODIMP nsScrollBoxObject::ScrollToLine(int32_t line)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToElement (in nsIDOMElement child); */
NS_IMETHODIMP nsScrollBoxObject::ScrollToElement(nsIDOMElement *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToIndex (in long index); */
NS_IMETHODIMP nsScrollBoxObject::ScrollToIndex(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPosition (out long x, out long y); */
NS_IMETHODIMP nsScrollBoxObject::GetPosition(int32_t *x, int32_t *y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrolledSize (out long width, out long height); */
NS_IMETHODIMP nsScrollBoxObject::GetScrolledSize(int32_t *width, int32_t *height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureElementIsVisible (in nsIDOMElement child); */
NS_IMETHODIMP nsScrollBoxObject::EnsureElementIsVisible(nsIDOMElement *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureIndexIsVisible (in long index); */
NS_IMETHODIMP nsScrollBoxObject::EnsureIndexIsVisible(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureLineIsVisible (in long line); */
NS_IMETHODIMP nsScrollBoxObject::EnsureLineIsVisible(int32_t line)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewScrollBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIScrollBoxObject_h__ */
