/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/js/jetpack/nsIJetpack.idl
 */

#ifndef __gen_nsIJetpack_h__
#define __gen_nsIJetpack_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIJetpack */
#define NS_IJETPACK_IID_STR "61a5be65-faf2-4fd1-96df-b13a7ad7d88d"

#define NS_IJETPACK_IID \
  {0x61a5be65, 0xfaf2, 0x4fd1, \
    { 0x96, 0xdf, 0xb1, 0x3a, 0x7a, 0xd7, 0xd8, 0x8d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIJetpack : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJETPACK_IID)

  /* void sendMessage (in AString aMessageName); */
  NS_SCRIPTABLE NS_IMETHOD SendMessage(const nsAString & aMessageName) = 0;

  /* void registerReceiver (in AString aMessageName, in jsval aReceiver); */
  NS_SCRIPTABLE NS_IMETHOD RegisterReceiver(const nsAString & aMessageName, const jsval & aReceiver) = 0;

  /* void unregisterReceiver (in AString aMessageName, in jsval aReceiver); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterReceiver(const nsAString & aMessageName, const jsval & aReceiver) = 0;

  /* void unregisterReceivers (in AString aMessageName); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterReceivers(const nsAString & aMessageName) = 0;

  /* void evalScript (in AString aScript); */
  NS_SCRIPTABLE NS_IMETHOD EvalScript(const nsAString & aScript) = 0;

  /* nsIVariant createHandle (); */
  NS_SCRIPTABLE NS_IMETHOD CreateHandle(nsIVariant **_retval NS_OUTPARAM) = 0;

  /* void destroy (); */
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJetpack, NS_IJETPACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJETPACK \
  NS_SCRIPTABLE NS_IMETHOD SendMessage(const nsAString & aMessageName); \
  NS_SCRIPTABLE NS_IMETHOD RegisterReceiver(const nsAString & aMessageName, const jsval & aReceiver); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReceiver(const nsAString & aMessageName, const jsval & aReceiver); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReceivers(const nsAString & aMessageName); \
  NS_SCRIPTABLE NS_IMETHOD EvalScript(const nsAString & aScript); \
  NS_SCRIPTABLE NS_IMETHOD CreateHandle(nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJETPACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD SendMessage(const nsAString & aMessageName) { return _to SendMessage(aMessageName); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterReceiver(const nsAString & aMessageName, const jsval & aReceiver) { return _to RegisterReceiver(aMessageName, aReceiver); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReceiver(const nsAString & aMessageName, const jsval & aReceiver) { return _to UnregisterReceiver(aMessageName, aReceiver); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReceivers(const nsAString & aMessageName) { return _to UnregisterReceivers(aMessageName); } \
  NS_SCRIPTABLE NS_IMETHOD EvalScript(const nsAString & aScript) { return _to EvalScript(aScript); } \
  NS_SCRIPTABLE NS_IMETHOD CreateHandle(nsIVariant **_retval NS_OUTPARAM) { return _to CreateHandle(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) { return _to Destroy(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJETPACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD SendMessage(const nsAString & aMessageName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMessage(aMessageName); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterReceiver(const nsAString & aMessageName, const jsval & aReceiver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterReceiver(aMessageName, aReceiver); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReceiver(const nsAString & aMessageName, const jsval & aReceiver) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterReceiver(aMessageName, aReceiver); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReceivers(const nsAString & aMessageName) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterReceivers(aMessageName); } \
  NS_SCRIPTABLE NS_IMETHOD EvalScript(const nsAString & aScript) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvalScript(aScript); } \
  NS_SCRIPTABLE NS_IMETHOD CreateHandle(nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateHandle(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJetpack : public nsIJetpack
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJETPACK

  nsJetpack();

private:
  ~nsJetpack();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJetpack, nsIJetpack)

nsJetpack::nsJetpack()
{
  /* member initializers and constructor code */
}

nsJetpack::~nsJetpack()
{
  /* destructor code */
}

/* void sendMessage (in AString aMessageName); */
NS_IMETHODIMP nsJetpack::SendMessage(const nsAString & aMessageName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerReceiver (in AString aMessageName, in jsval aReceiver); */
NS_IMETHODIMP nsJetpack::RegisterReceiver(const nsAString & aMessageName, const jsval & aReceiver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterReceiver (in AString aMessageName, in jsval aReceiver); */
NS_IMETHODIMP nsJetpack::UnregisterReceiver(const nsAString & aMessageName, const jsval & aReceiver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterReceivers (in AString aMessageName); */
NS_IMETHODIMP nsJetpack::UnregisterReceivers(const nsAString & aMessageName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evalScript (in AString aScript); */
NS_IMETHODIMP nsJetpack::EvalScript(const nsAString & aScript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant createHandle (); */
NS_IMETHODIMP nsJetpack::CreateHandle(nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroy (); */
NS_IMETHODIMP nsJetpack::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJetpack_h__ */
