/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/mozapps/extensions/amIWebInstallListener.idl
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
class nsIDOMWindowInternal; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    amIWebInstallInfo */
#define AMIWEBINSTALLINFO_IID_STR "8710e692-3989-4dc7-b607-40d57610ae75"

#define AMIWEBINSTALLINFO_IID \
  {0x8710e692, 0x3989, 0x4dc7, \
    { 0xb6, 0x07, 0x40, 0xd5, 0x76, 0x10, 0xae, 0x75 }}

/**
 * amIWebInstallInfo is used by the default implementation of
 * amIWebInstallListener to communicate with the running application and allow
 * it to warn the user about blocked installs and start the installs running.
 */
class NS_NO_VTABLE NS_SCRIPTABLE amIWebInstallInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLINFO_IID)

  /* readonly attribute nsIDOMWindowInternal originatingWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingWindow(nsIDOMWindowInternal **aOriginatingWindow) = 0;

  /* readonly attribute nsIURI originatingURI; */
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIURI **aOriginatingURI) = 0;

  /* readonly attribute nsIVariant installs; */
  NS_SCRIPTABLE NS_IMETHOD GetInstalls(nsIVariant **aInstalls) = 0;

  /**
   * Starts all installs.
   */
  /* void install (); */
  NS_SCRIPTABLE NS_IMETHOD Install(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallInfo, AMIWEBINSTALLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLINFO \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingWindow(nsIDOMWindowInternal **aOriginatingWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIURI **aOriginatingURI); \
  NS_SCRIPTABLE NS_IMETHOD GetInstalls(nsIVariant **aInstalls); \
  NS_SCRIPTABLE NS_IMETHOD Install(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingWindow(nsIDOMWindowInternal **aOriginatingWindow) { return _to GetOriginatingWindow(aOriginatingWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIURI **aOriginatingURI) { return _to GetOriginatingURI(aOriginatingURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstalls(nsIVariant **aInstalls) { return _to GetInstalls(aInstalls); } \
  NS_SCRIPTABLE NS_IMETHOD Install(void) { return _to Install(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingWindow(nsIDOMWindowInternal **aOriginatingWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginatingWindow(aOriginatingWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetOriginatingURI(nsIURI **aOriginatingURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginatingURI(aOriginatingURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstalls(nsIVariant **aInstalls) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstalls(aInstalls); } \
  NS_SCRIPTABLE NS_IMETHOD Install(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Install(); } 

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

/* readonly attribute nsIDOMWindowInternal originatingWindow; */
NS_IMETHODIMP amWebInstallInfo::GetOriginatingWindow(nsIDOMWindowInternal **aOriginatingWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI originatingURI; */
NS_IMETHODIMP amWebInstallInfo::GetOriginatingURI(nsIURI **aOriginatingURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant installs; */
NS_IMETHODIMP amWebInstallInfo::GetInstalls(nsIVariant **aInstalls)
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

/**
 * The registered amIWebInstallListener is used to notify about new installs
 * triggered by websites. The default implementation displays a confirmation
 * dialog when add-ons are ready to install and uses the observer service to
 * notify when installations are blocked.
 */
class NS_NO_VTABLE NS_SCRIPTABLE amIWebInstallListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLLISTENER_IID)

  /**
   * Called when installation by websites is currently disabled.
   *
   * @param  aWindow
   *         The window that triggered the installs
   * @param  aUri
   *         The URI of the site that triggered the installs
   * @param  aInstalls
   *         The AddonInstalls that were blocked
   * @param  aCount
   *         The number of AddonInstalls
   */
  /* void onWebInstallDisabled (in nsIDOMWindowInternal aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in PRUint32 aCount); */
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallDisabled(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount) = 0;

  /**
   * Called when the website is not allowed to directly prompt the user to
   * install add-ons.
   *
   * @param  aWindow
   *         The window that triggered the installs
   * @param  aUri
   *         The URI of the site that triggered the installs
   * @param  aInstalls
   *         The AddonInstalls that were blocked
   * @param  aCount
   *         The number of AddonInstalls
   * @return true if the caller should start the installs
   */
  /* boolean onWebInstallBlocked (in nsIDOMWindowInternal aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in PRUint32 aCount); */
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallBlocked(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Called when a website wants to ask the user to install add-ons.
   *
   * @param  aWindow
   *         The window that triggered the installs
   * @param  aUri
   *         The URI of the site that triggered the installs
   * @param  aInstalls
   *         The AddonInstalls that were requested
   * @param  aCount
   *         The number of AddonInstalls
   * @return true if the caller should start the installs
   */
  /* boolean onWebInstallRequested (in nsIDOMWindowInternal aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in PRUint32 aCount); */
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallRequested(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallListener, AMIWEBINSTALLLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallDisabled(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount); \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallBlocked(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallRequested(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallDisabled(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount) { return _to OnWebInstallDisabled(aWindow, aUri, aInstalls, aCount); } \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallBlocked(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM) { return _to OnWebInstallBlocked(aWindow, aUri, aInstalls, aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallRequested(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM) { return _to OnWebInstallRequested(aWindow, aUri, aInstalls, aCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallDisabled(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallDisabled(aWindow, aUri, aInstalls, aCount); } \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallBlocked(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallBlocked(aWindow, aUri, aInstalls, aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OnWebInstallRequested(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallRequested(aWindow, aUri, aInstalls, aCount, _retval); } 

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

/* void onWebInstallDisabled (in nsIDOMWindowInternal aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in PRUint32 aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallDisabled(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onWebInstallBlocked (in nsIDOMWindowInternal aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in PRUint32 aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallBlocked(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onWebInstallRequested (in nsIDOMWindowInternal aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in PRUint32 aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallRequested(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount, PRBool *_retval NS_OUTPARAM)
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

/**
 * amIWebInstallPrompt is used, if available, by the default implementation of 
 * amIWebInstallInfo to display a confirmation UI to the user before running
 * installs.
 */
class NS_NO_VTABLE NS_SCRIPTABLE amIWebInstallPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLPROMPT_IID)

  /**
   * Get a confirmation that the user wants to start the installs.
   *
   * @param  aWindow
   *         The window that triggered the installs
   * @param  aUri
   *         The URI of the site that triggered the installs
   * @param  aInstalls
   *         The AddonInstalls that were requested
   * @param  aCount
   *         The number of AddonInstalls
   */
  /* void confirm (in nsIDOMWindowInternal aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in PRUint32 aCount); */
  NS_SCRIPTABLE NS_IMETHOD Confirm(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallPrompt, AMIWEBINSTALLPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLPROMPT \
  NS_SCRIPTABLE NS_IMETHOD Confirm(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Confirm(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount) { return _to Confirm(aWindow, aUri, aInstalls, aCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Confirm(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->Confirm(aWindow, aUri, aInstalls, aCount); } 

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

/* void confirm (in nsIDOMWindowInternal aWindow, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in PRUint32 aCount); */
NS_IMETHODIMP amWebInstallPrompt::Confirm(nsIDOMWindowInternal *aWindow, nsIURI *aUri, nsIVariant **aInstalls, PRUint32 aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_amIWebInstallListener_h__ */
