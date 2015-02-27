/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/mozapps/extensions/amIWebInstallListener.idl
 */

#ifndef __gen_amIWebInstallListener_h__
#define __gen_amIWebInstallListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    amIWebInstallInfo */
#define AMIWEBINSTALLINFO_IID_STR "8710e692-3989-4dc7-b607-40d57610ae75"

#define AMIWEBINSTALLINFO_IID \
  {0x8710e692, 0x3989, 0x4dc7, \
    { 0xb6, 0x07, 0x40, 0xd5, 0x76, 0x10, 0xae, 0x75 }}

class NS_NO_VTABLE amIWebInstallInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLINFO_IID)

  /* readonly attribute nsIDOMWindow originatingWindow; */
  NS_IMETHOD GetOriginatingWindow(nsIDOMWindow * *aOriginatingWindow) = 0;

  /* readonly attribute nsIURI originatingURI; */
  NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) = 0;

  /* readonly attribute nsIVariant installs; */
  NS_IMETHOD GetInstalls(nsIVariant * *aInstalls) = 0;

  /* void install (); */
  NS_IMETHOD Install(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallInfo, AMIWEBINSTALLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLINFO \
  NS_IMETHOD GetOriginatingWindow(nsIDOMWindow * *aOriginatingWindow); \
  NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI); \
  NS_IMETHOD GetInstalls(nsIVariant * *aInstalls); \
  NS_IMETHOD Install(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLINFO(_to) \
  NS_IMETHOD GetOriginatingWindow(nsIDOMWindow * *aOriginatingWindow) { return _to GetOriginatingWindow(aOriginatingWindow); } \
  NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) { return _to GetOriginatingURI(aOriginatingURI); } \
  NS_IMETHOD GetInstalls(nsIVariant * *aInstalls) { return _to GetInstalls(aInstalls); } \
  NS_IMETHOD Install(void) { return _to Install(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLINFO(_to) \
  NS_IMETHOD GetOriginatingWindow(nsIDOMWindow * *aOriginatingWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginatingWindow(aOriginatingWindow); } \
  NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginatingURI(aOriginatingURI); } \
  NS_IMETHOD GetInstalls(nsIVariant * *aInstalls) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstalls(aInstalls); } \
  NS_IMETHOD Install(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Install(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstallInfo : public amIWebInstallInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLINFO

  amWebInstallInfo();

private:
  ~amWebInstallInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(amWebInstallInfo, amIWebInstallInfo)

amWebInstallInfo::amWebInstallInfo()
{
  /* member initializers and constructor code */
}

amWebInstallInfo::~amWebInstallInfo()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow originatingWindow; */
NS_IMETHODIMP amWebInstallInfo::GetOriginatingWindow(nsIDOMWindow * *aOriginatingWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI originatingURI; */
NS_IMETHODIMP amWebInstallInfo::GetOriginatingURI(nsIURI * *aOriginatingURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant installs; */
NS_IMETHODIMP amWebInstallInfo::GetInstalls(nsIVariant * *aInstalls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void install (); */
NS_IMETHODIMP amWebInstallInfo::Install()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    amIWebInstallListener */
#define AMIWEBINSTALLLISTENER_IID_STR "a5503979-89c8-441e-9e4a-321df379c172"

#define AMIWEBINSTALLLISTENER_IID \
  {0xa5503979, 0x89c8, 0x441e, \
    { 0x9e, 0x4a, 0x32, 0x1d, 0xf3, 0x79, 0xc1, 0x72 }}

class NS_NO_VTABLE amIWebInstallListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLLISTENER_IID)

  /* void onWebInstallDisabled (in nsIDOMWindow aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD OnWebInstallDisabled(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) = 0;

  /* boolean onWebInstallBlocked (in nsIDOMWindow aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD OnWebInstallBlocked(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) = 0;

  /* boolean onWebInstallRequested (in nsIDOMWindow aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD OnWebInstallRequested(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallListener, AMIWEBINSTALLLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLLISTENER \
  NS_IMETHOD OnWebInstallDisabled(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount); \
  NS_IMETHOD OnWebInstallBlocked(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval); \
  NS_IMETHOD OnWebInstallRequested(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLLISTENER(_to) \
  NS_IMETHOD OnWebInstallDisabled(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) { return _to OnWebInstallDisabled(aWindow, aUri, aInstalls, aCount); } \
  NS_IMETHOD OnWebInstallBlocked(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) { return _to OnWebInstallBlocked(aWindow, aUri, aInstalls, aCount, _retval); } \
  NS_IMETHOD OnWebInstallRequested(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) { return _to OnWebInstallRequested(aWindow, aUri, aInstalls, aCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLLISTENER(_to) \
  NS_IMETHOD OnWebInstallDisabled(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallDisabled(aWindow, aUri, aInstalls, aCount); } \
  NS_IMETHOD OnWebInstallBlocked(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallBlocked(aWindow, aUri, aInstalls, aCount, _retval); } \
  NS_IMETHOD OnWebInstallRequested(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallRequested(aWindow, aUri, aInstalls, aCount, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstallListener : public amIWebInstallListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLLISTENER

  amWebInstallListener();

private:
  ~amWebInstallListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(amWebInstallListener, amIWebInstallListener)

amWebInstallListener::amWebInstallListener()
{
  /* member initializers and constructor code */
}

amWebInstallListener::~amWebInstallListener()
{
  /* destructor code */
}

/* void onWebInstallDisabled (in nsIDOMWindow aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallDisabled(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onWebInstallBlocked (in nsIDOMWindow aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallBlocked(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onWebInstallRequested (in nsIDOMWindow aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallRequested(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    amIWebInstallPrompt */
#define AMIWEBINSTALLPROMPT_IID_STR "c5529918-4291-4b56-bd46-e9268900f2a3"

#define AMIWEBINSTALLPROMPT_IID \
  {0xc5529918, 0x4291, 0x4b56, \
    { 0xbd, 0x46, 0xe9, 0x26, 0x89, 0x00, 0xf2, 0xa3 }}

class NS_NO_VTABLE amIWebInstallPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLPROMPT_IID)

  /* void confirm (in nsIDOMWindow aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD Confirm(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallPrompt, AMIWEBINSTALLPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLPROMPT \
  NS_IMETHOD Confirm(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLPROMPT(_to) \
  NS_IMETHOD Confirm(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) { return _to Confirm(aWindow, aUri, aInstalls, aCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLPROMPT(_to) \
  NS_IMETHOD Confirm(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->Confirm(aWindow, aUri, aInstalls, aCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstallPrompt : public amIWebInstallPrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLPROMPT

  amWebInstallPrompt();

private:
  ~amWebInstallPrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(amWebInstallPrompt, amIWebInstallPrompt)

amWebInstallPrompt::amWebInstallPrompt()
{
  /* member initializers and constructor code */
}

amWebInstallPrompt::~amWebInstallPrompt()
{
  /* destructor code */
}

/* void confirm (in nsIDOMWindow aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallPrompt::Confirm(nsIDOMWindow *aWindow, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_amIWebInstallListener_h__ */
