/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIColorPicker.idl
 */

#ifndef __gen_nsIColorPicker_h__
#define __gen_nsIColorPicker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIColorPickerShownCallback */
#define NS_ICOLORPICKERSHOWNCALLBACK_IID_STR "d2ce78d1-40b5-49d1-b66d-5801fcb9a385"

#define NS_ICOLORPICKERSHOWNCALLBACK_IID \
  {0xd2ce78d1, 0x40b5, 0x49d1, \
    { 0xb6, 0x6d, 0x58, 0x01, 0xfc, 0xb9, 0xa3, 0x85 }}

class NS_NO_VTABLE nsIColorPickerShownCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOLORPICKERSHOWNCALLBACK_IID)

  /* void update (in AString color); */
  NS_IMETHOD Update(const nsAString & color) = 0;

  /* void done (in AString color); */
  NS_IMETHOD Done(const nsAString & color) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIColorPickerShownCallback, NS_ICOLORPICKERSHOWNCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOLORPICKERSHOWNCALLBACK \
  NS_IMETHOD Update(const nsAString & color); \
  NS_IMETHOD Done(const nsAString & color); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOLORPICKERSHOWNCALLBACK(_to) \
  NS_IMETHOD Update(const nsAString & color) { return _to Update(color); } \
  NS_IMETHOD Done(const nsAString & color) { return _to Done(color); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOLORPICKERSHOWNCALLBACK(_to) \
  NS_IMETHOD Update(const nsAString & color) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(color); } \
  NS_IMETHOD Done(const nsAString & color) { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(color); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsColorPickerShownCallback : public nsIColorPickerShownCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOLORPICKERSHOWNCALLBACK

  nsColorPickerShownCallback();

private:
  ~nsColorPickerShownCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsColorPickerShownCallback, nsIColorPickerShownCallback)

nsColorPickerShownCallback::nsColorPickerShownCallback()
{
  /* member initializers and constructor code */
}

nsColorPickerShownCallback::~nsColorPickerShownCallback()
{
  /* destructor code */
}

/* void update (in AString color); */
NS_IMETHODIMP nsColorPickerShownCallback::Update(const nsAString & color)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void done (in AString color); */
NS_IMETHODIMP nsColorPickerShownCallback::Done(const nsAString & color)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIColorPicker */
#define NS_ICOLORPICKER_IID_STR "3c3bdcce-54b1-4ae2-8647-1a8d4712ef2e"

#define NS_ICOLORPICKER_IID \
  {0x3c3bdcce, 0x54b1, 0x4ae2, \
    { 0x86, 0x47, 0x1a, 0x8d, 0x47, 0x12, 0xef, 0x2e }}

class NS_NO_VTABLE nsIColorPicker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOLORPICKER_IID)

  /* void init (in nsIDOMWindow parent, in AString title, in AString initialColor); */
  NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, const nsAString & initialColor) = 0;

  /* void open (in nsIColorPickerShownCallback aColorPickerShownCallback); */
  NS_IMETHOD Open(nsIColorPickerShownCallback *aColorPickerShownCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIColorPicker, NS_ICOLORPICKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOLORPICKER \
  NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, const nsAString & initialColor); \
  NS_IMETHOD Open(nsIColorPickerShownCallback *aColorPickerShownCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOLORPICKER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, const nsAString & initialColor) { return _to Init(parent, title, initialColor); } \
  NS_IMETHOD Open(nsIColorPickerShownCallback *aColorPickerShownCallback) { return _to Open(aColorPickerShownCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOLORPICKER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, const nsAString & initialColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(parent, title, initialColor); } \
  NS_IMETHOD Open(nsIColorPickerShownCallback *aColorPickerShownCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aColorPickerShownCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsColorPicker : public nsIColorPicker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOLORPICKER

  nsColorPicker();

private:
  ~nsColorPicker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsColorPicker, nsIColorPicker)

nsColorPicker::nsColorPicker()
{
  /* member initializers and constructor code */
}

nsColorPicker::~nsColorPicker()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow parent, in AString title, in AString initialColor); */
NS_IMETHODIMP nsColorPicker::Init(nsIDOMWindow *parent, const nsAString & title, const nsAString & initialColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (in nsIColorPickerShownCallback aColorPickerShownCallback); */
NS_IMETHODIMP nsColorPicker::Open(nsIColorPickerShownCallback *aColorPickerShownCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIColorPicker_h__ */
