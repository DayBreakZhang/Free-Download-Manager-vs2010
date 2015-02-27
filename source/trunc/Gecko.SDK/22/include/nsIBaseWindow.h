/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIBaseWindow.idl
 */

#ifndef __gen_nsIBaseWindow_h__
#define __gen_nsIBaseWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIWidget;
typedef void * nativeWindow;


/* starting interface:    nsIBaseWindow */
#define NS_IBASEWINDOW_IID_STR "9da319f3-eee6-4504-81a5-6a19cf6215bf"

#define NS_IBASEWINDOW_IID \
  {0x9da319f3, 0xeee6, 0x4504, \
    { 0x81, 0xa5, 0x6a, 0x19, 0xcf, 0x62, 0x15, 0xbf }}

class NS_NO_VTABLE nsIBaseWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBASEWINDOW_IID)

  /* [noscript] void initWindow (in nativeWindow parentNativeWindow, in nsIWidget parentWidget, in long x, in long y, in long cx, in long cy); */
  NS_IMETHOD InitWindow(nativeWindow parentNativeWindow, nsIWidget *parentWidget, int32_t x, int32_t y, int32_t cx, int32_t cy) = 0;

  /* void create (); */
  NS_IMETHOD Create(void) = 0;

  /* void destroy (); */
  NS_IMETHOD Destroy(void) = 0;

  /* void setPosition (in long x, in long y); */
  NS_IMETHOD SetPosition(int32_t x, int32_t y) = 0;

  /* void getPosition (out long x, out long y); */
  NS_IMETHOD GetPosition(int32_t *x, int32_t *y) = 0;

  /* void setSize (in long cx, in long cy, in boolean fRepaint); */
  NS_IMETHOD SetSize(int32_t cx, int32_t cy, bool fRepaint) = 0;

  /* void getSize (out long cx, out long cy); */
  NS_IMETHOD GetSize(int32_t *cx, int32_t *cy) = 0;

  /* void setPositionAndSize (in long x, in long y, in long cx, in long cy, in boolean fRepaint); */
  NS_IMETHOD SetPositionAndSize(int32_t x, int32_t y, int32_t cx, int32_t cy, bool fRepaint) = 0;

  /* void getPositionAndSize (out long x, out long y, out long cx, out long cy); */
  NS_IMETHOD GetPositionAndSize(int32_t *x, int32_t *y, int32_t *cx, int32_t *cy) = 0;

  /* void repaint (in boolean force); */
  NS_IMETHOD Repaint(bool force) = 0;

  /* [noscript] attribute nsIWidget parentWidget; */
  NS_IMETHOD GetParentWidget(nsIWidget **aParentWidget) = 0;
  NS_IMETHOD SetParentWidget(nsIWidget *aParentWidget) = 0;

  /* attribute nativeWindow parentNativeWindow; */
  NS_IMETHOD GetParentNativeWindow(nativeWindow *aParentNativeWindow) = 0;
  NS_IMETHOD SetParentNativeWindow(nativeWindow aParentNativeWindow) = 0;

  /* readonly attribute DOMString nativeHandle; */
  NS_IMETHOD GetNativeHandle(nsAString & aNativeHandle) = 0;

  /* attribute boolean visibility; */
  NS_IMETHOD GetVisibility(bool *aVisibility) = 0;
  NS_IMETHOD SetVisibility(bool aVisibility) = 0;

  /* attribute boolean enabled; */
  NS_IMETHOD GetEnabled(bool *aEnabled) = 0;
  NS_IMETHOD SetEnabled(bool aEnabled) = 0;

  /* [noscript] readonly attribute nsIWidget mainWidget; */
  NS_IMETHOD GetMainWidget(nsIWidget **aMainWidget) = 0;

  /* readonly attribute double unscaledDevicePixelsPerCSSPixel; */
  NS_IMETHOD GetUnscaledDevicePixelsPerCSSPixel(double *aUnscaledDevicePixelsPerCSSPixel) = 0;

  /* void setFocus (); */
  NS_IMETHOD SetFocus(void) = 0;

  /* attribute wstring title; */
  NS_IMETHOD GetTitle(PRUnichar * *aTitle) = 0;
  NS_IMETHOD SetTitle(const PRUnichar * aTitle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBaseWindow, NS_IBASEWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBASEWINDOW \
  NS_IMETHOD InitWindow(nativeWindow parentNativeWindow, nsIWidget *parentWidget, int32_t x, int32_t y, int32_t cx, int32_t cy); \
  NS_IMETHOD Create(void); \
  NS_IMETHOD Destroy(void); \
  NS_IMETHOD SetPosition(int32_t x, int32_t y); \
  NS_IMETHOD GetPosition(int32_t *x, int32_t *y); \
  NS_IMETHOD SetSize(int32_t cx, int32_t cy, bool fRepaint); \
  NS_IMETHOD GetSize(int32_t *cx, int32_t *cy); \
  NS_IMETHOD SetPositionAndSize(int32_t x, int32_t y, int32_t cx, int32_t cy, bool fRepaint); \
  NS_IMETHOD GetPositionAndSize(int32_t *x, int32_t *y, int32_t *cx, int32_t *cy); \
  NS_IMETHOD Repaint(bool force); \
  NS_IMETHOD GetParentWidget(nsIWidget **aParentWidget); \
  NS_IMETHOD SetParentWidget(nsIWidget *aParentWidget); \
  NS_IMETHOD GetParentNativeWindow(nativeWindow *aParentNativeWindow); \
  NS_IMETHOD SetParentNativeWindow(nativeWindow aParentNativeWindow); \
  NS_IMETHOD GetNativeHandle(nsAString & aNativeHandle); \
  NS_IMETHOD GetVisibility(bool *aVisibility); \
  NS_IMETHOD SetVisibility(bool aVisibility); \
  NS_IMETHOD GetEnabled(bool *aEnabled); \
  NS_IMETHOD SetEnabled(bool aEnabled); \
  NS_IMETHOD GetMainWidget(nsIWidget **aMainWidget); \
  NS_IMETHOD GetUnscaledDevicePixelsPerCSSPixel(double *aUnscaledDevicePixelsPerCSSPixel); \
  NS_IMETHOD SetFocus(void); \
  NS_IMETHOD GetTitle(PRUnichar * *aTitle); \
  NS_IMETHOD SetTitle(const PRUnichar * aTitle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBASEWINDOW(_to) \
  NS_IMETHOD InitWindow(nativeWindow parentNativeWindow, nsIWidget *parentWidget, int32_t x, int32_t y, int32_t cx, int32_t cy) { return _to InitWindow(parentNativeWindow, parentWidget, x, y, cx, cy); } \
  NS_IMETHOD Create(void) { return _to Create(); } \
  NS_IMETHOD Destroy(void) { return _to Destroy(); } \
  NS_IMETHOD SetPosition(int32_t x, int32_t y) { return _to SetPosition(x, y); } \
  NS_IMETHOD GetPosition(int32_t *x, int32_t *y) { return _to GetPosition(x, y); } \
  NS_IMETHOD SetSize(int32_t cx, int32_t cy, bool fRepaint) { return _to SetSize(cx, cy, fRepaint); } \
  NS_IMETHOD GetSize(int32_t *cx, int32_t *cy) { return _to GetSize(cx, cy); } \
  NS_IMETHOD SetPositionAndSize(int32_t x, int32_t y, int32_t cx, int32_t cy, bool fRepaint) { return _to SetPositionAndSize(x, y, cx, cy, fRepaint); } \
  NS_IMETHOD GetPositionAndSize(int32_t *x, int32_t *y, int32_t *cx, int32_t *cy) { return _to GetPositionAndSize(x, y, cx, cy); } \
  NS_IMETHOD Repaint(bool force) { return _to Repaint(force); } \
  NS_IMETHOD GetParentWidget(nsIWidget **aParentWidget) { return _to GetParentWidget(aParentWidget); } \
  NS_IMETHOD SetParentWidget(nsIWidget *aParentWidget) { return _to SetParentWidget(aParentWidget); } \
  NS_IMETHOD GetParentNativeWindow(nativeWindow *aParentNativeWindow) { return _to GetParentNativeWindow(aParentNativeWindow); } \
  NS_IMETHOD SetParentNativeWindow(nativeWindow aParentNativeWindow) { return _to SetParentNativeWindow(aParentNativeWindow); } \
  NS_IMETHOD GetNativeHandle(nsAString & aNativeHandle) { return _to GetNativeHandle(aNativeHandle); } \
  NS_IMETHOD GetVisibility(bool *aVisibility) { return _to GetVisibility(aVisibility); } \
  NS_IMETHOD SetVisibility(bool aVisibility) { return _to SetVisibility(aVisibility); } \
  NS_IMETHOD GetEnabled(bool *aEnabled) { return _to GetEnabled(aEnabled); } \
  NS_IMETHOD SetEnabled(bool aEnabled) { return _to SetEnabled(aEnabled); } \
  NS_IMETHOD GetMainWidget(nsIWidget **aMainWidget) { return _to GetMainWidget(aMainWidget); } \
  NS_IMETHOD GetUnscaledDevicePixelsPerCSSPixel(double *aUnscaledDevicePixelsPerCSSPixel) { return _to GetUnscaledDevicePixelsPerCSSPixel(aUnscaledDevicePixelsPerCSSPixel); } \
  NS_IMETHOD SetFocus(void) { return _to SetFocus(); } \
  NS_IMETHOD GetTitle(PRUnichar * *aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const PRUnichar * aTitle) { return _to SetTitle(aTitle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBASEWINDOW(_to) \
  NS_IMETHOD InitWindow(nativeWindow parentNativeWindow, nsIWidget *parentWidget, int32_t x, int32_t y, int32_t cx, int32_t cy) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWindow(parentNativeWindow, parentWidget, x, y, cx, cy); } \
  NS_IMETHOD Create(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Create(); } \
  NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_IMETHOD SetPosition(int32_t x, int32_t y) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPosition(x, y); } \
  NS_IMETHOD GetPosition(int32_t *x, int32_t *y) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(x, y); } \
  NS_IMETHOD SetSize(int32_t cx, int32_t cy, bool fRepaint) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSize(cx, cy, fRepaint); } \
  NS_IMETHOD GetSize(int32_t *cx, int32_t *cy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(cx, cy); } \
  NS_IMETHOD SetPositionAndSize(int32_t x, int32_t y, int32_t cx, int32_t cy, bool fRepaint) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPositionAndSize(x, y, cx, cy, fRepaint); } \
  NS_IMETHOD GetPositionAndSize(int32_t *x, int32_t *y, int32_t *cx, int32_t *cy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPositionAndSize(x, y, cx, cy); } \
  NS_IMETHOD Repaint(bool force) { return !_to ? NS_ERROR_NULL_POINTER : _to->Repaint(force); } \
  NS_IMETHOD GetParentWidget(nsIWidget **aParentWidget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentWidget(aParentWidget); } \
  NS_IMETHOD SetParentWidget(nsIWidget *aParentWidget) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentWidget(aParentWidget); } \
  NS_IMETHOD GetParentNativeWindow(nativeWindow *aParentNativeWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentNativeWindow(aParentNativeWindow); } \
  NS_IMETHOD SetParentNativeWindow(nativeWindow aParentNativeWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentNativeWindow(aParentNativeWindow); } \
  NS_IMETHOD GetNativeHandle(nsAString & aNativeHandle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeHandle(aNativeHandle); } \
  NS_IMETHOD GetVisibility(bool *aVisibility) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisibility(aVisibility); } \
  NS_IMETHOD SetVisibility(bool aVisibility) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisibility(aVisibility); } \
  NS_IMETHOD GetEnabled(bool *aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnabled(aEnabled); } \
  NS_IMETHOD SetEnabled(bool aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnabled(aEnabled); } \
  NS_IMETHOD GetMainWidget(nsIWidget **aMainWidget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMainWidget(aMainWidget); } \
  NS_IMETHOD GetUnscaledDevicePixelsPerCSSPixel(double *aUnscaledDevicePixelsPerCSSPixel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnscaledDevicePixelsPerCSSPixel(aUnscaledDevicePixelsPerCSSPixel); } \
  NS_IMETHOD SetFocus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocus(); } \
  NS_IMETHOD GetTitle(PRUnichar * *aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const PRUnichar * aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBaseWindow : public nsIBaseWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBASEWINDOW

  nsBaseWindow();

private:
  ~nsBaseWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBaseWindow, nsIBaseWindow)

nsBaseWindow::nsBaseWindow()
{
  /* member initializers and constructor code */
}

nsBaseWindow::~nsBaseWindow()
{
  /* destructor code */
}

/* [noscript] void initWindow (in nativeWindow parentNativeWindow, in nsIWidget parentWidget, in long x, in long y, in long cx, in long cy); */
NS_IMETHODIMP nsBaseWindow::InitWindow(nativeWindow parentNativeWindow, nsIWidget *parentWidget, int32_t x, int32_t y, int32_t cx, int32_t cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void create (); */
NS_IMETHODIMP nsBaseWindow::Create()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroy (); */
NS_IMETHODIMP nsBaseWindow::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPosition (in long x, in long y); */
NS_IMETHODIMP nsBaseWindow::SetPosition(int32_t x, int32_t y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPosition (out long x, out long y); */
NS_IMETHODIMP nsBaseWindow::GetPosition(int32_t *x, int32_t *y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSize (in long cx, in long cy, in boolean fRepaint); */
NS_IMETHODIMP nsBaseWindow::SetSize(int32_t cx, int32_t cy, bool fRepaint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSize (out long cx, out long cy); */
NS_IMETHODIMP nsBaseWindow::GetSize(int32_t *cx, int32_t *cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPositionAndSize (in long x, in long y, in long cx, in long cy, in boolean fRepaint); */
NS_IMETHODIMP nsBaseWindow::SetPositionAndSize(int32_t x, int32_t y, int32_t cx, int32_t cy, bool fRepaint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPositionAndSize (out long x, out long y, out long cx, out long cy); */
NS_IMETHODIMP nsBaseWindow::GetPositionAndSize(int32_t *x, int32_t *y, int32_t *cx, int32_t *cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void repaint (in boolean force); */
NS_IMETHODIMP nsBaseWindow::Repaint(bool force)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIWidget parentWidget; */
NS_IMETHODIMP nsBaseWindow::GetParentWidget(nsIWidget **aParentWidget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBaseWindow::SetParentWidget(nsIWidget *aParentWidget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nativeWindow parentNativeWindow; */
NS_IMETHODIMP nsBaseWindow::GetParentNativeWindow(nativeWindow *aParentNativeWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBaseWindow::SetParentNativeWindow(nativeWindow aParentNativeWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString nativeHandle; */
NS_IMETHODIMP nsBaseWindow::GetNativeHandle(nsAString & aNativeHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean visibility; */
NS_IMETHODIMP nsBaseWindow::GetVisibility(bool *aVisibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBaseWindow::SetVisibility(bool aVisibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean enabled; */
NS_IMETHODIMP nsBaseWindow::GetEnabled(bool *aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBaseWindow::SetEnabled(bool aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIWidget mainWidget; */
NS_IMETHODIMP nsBaseWindow::GetMainWidget(nsIWidget **aMainWidget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double unscaledDevicePixelsPerCSSPixel; */
NS_IMETHODIMP nsBaseWindow::GetUnscaledDevicePixelsPerCSSPixel(double *aUnscaledDevicePixelsPerCSSPixel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFocus (); */
NS_IMETHODIMP nsBaseWindow::SetFocus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring title; */
NS_IMETHODIMP nsBaseWindow::GetTitle(PRUnichar * *aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBaseWindow::SetTitle(const PRUnichar * aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBaseWindow_h__ */
