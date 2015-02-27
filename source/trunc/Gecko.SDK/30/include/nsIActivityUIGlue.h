/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIActivityUIGlue.idl
 */

#ifndef __gen_nsIActivityUIGlue_h__
#define __gen_nsIActivityUIGlue_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIActivityUIGlueCallback */
#define NS_IACTIVITYUIGLUECALLBACK_IID_STR "7a16feb4-5a78-4589-9174-b728f26942e2"

#define NS_IACTIVITYUIGLUECALLBACK_IID \
  {0x7a16feb4, 0x5a78, 0x4589, \
    { 0x91, 0x74, 0xb7, 0x28, 0xf2, 0x69, 0x42, 0xe2 }}

class NS_NO_VTABLE nsIActivityUIGlueCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACTIVITYUIGLUECALLBACK_IID)

  /* void handleEvent (in long choice); */
  NS_IMETHOD HandleEvent(int32_t choice) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIActivityUIGlueCallback, NS_IACTIVITYUIGLUECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACTIVITYUIGLUECALLBACK \
  NS_IMETHOD HandleEvent(int32_t choice); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACTIVITYUIGLUECALLBACK(_to) \
  NS_IMETHOD HandleEvent(int32_t choice) { return _to HandleEvent(choice); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACTIVITYUIGLUECALLBACK(_to) \
  NS_IMETHOD HandleEvent(int32_t choice) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(choice); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsActivityUIGlueCallback : public nsIActivityUIGlueCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACTIVITYUIGLUECALLBACK

  nsActivityUIGlueCallback();

private:
  ~nsActivityUIGlueCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsActivityUIGlueCallback, nsIActivityUIGlueCallback)

nsActivityUIGlueCallback::nsActivityUIGlueCallback()
{
  /* member initializers and constructor code */
}

nsActivityUIGlueCallback::~nsActivityUIGlueCallback()
{
  /* destructor code */
}

/* void handleEvent (in long choice); */
NS_IMETHODIMP nsActivityUIGlueCallback::HandleEvent(int32_t choice)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIActivityUIGlue */
#define NS_IACTIVITYUIGLUE_IID_STR "8624ad73-937a-400f-9d93-39ab5449b867"

#define NS_IACTIVITYUIGLUE_IID \
  {0x8624ad73, 0x937a, 0x400f, \
    { 0x9d, 0x93, 0x39, 0xab, 0x54, 0x49, 0xb8, 0x67 }}

class NS_NO_VTABLE nsIActivityUIGlue : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACTIVITYUIGLUE_IID)

  /* void chooseActivity (in DOMString title, in jsval activities, in nsIActivityUIGlueCallback onresult); */
  NS_IMETHOD ChooseActivity(const nsAString & title, JS::HandleValue activities, nsIActivityUIGlueCallback *onresult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIActivityUIGlue, NS_IACTIVITYUIGLUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACTIVITYUIGLUE \
  NS_IMETHOD ChooseActivity(const nsAString & title, JS::HandleValue activities, nsIActivityUIGlueCallback *onresult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACTIVITYUIGLUE(_to) \
  NS_IMETHOD ChooseActivity(const nsAString & title, JS::HandleValue activities, nsIActivityUIGlueCallback *onresult) { return _to ChooseActivity(title, activities, onresult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACTIVITYUIGLUE(_to) \
  NS_IMETHOD ChooseActivity(const nsAString & title, JS::HandleValue activities, nsIActivityUIGlueCallback *onresult) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChooseActivity(title, activities, onresult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsActivityUIGlue : public nsIActivityUIGlue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACTIVITYUIGLUE

  nsActivityUIGlue();

private:
  ~nsActivityUIGlue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsActivityUIGlue, nsIActivityUIGlue)

nsActivityUIGlue::nsActivityUIGlue()
{
  /* member initializers and constructor code */
}

nsActivityUIGlue::~nsActivityUIGlue()
{
  /* destructor code */
}

/* void chooseActivity (in DOMString title, in jsval activities, in nsIActivityUIGlueCallback onresult); */
NS_IMETHODIMP nsActivityUIGlue::ChooseActivity(const nsAString & title, JS::HandleValue activities, nsIActivityUIGlueCallback *onresult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIActivityUIGlue_h__ */
