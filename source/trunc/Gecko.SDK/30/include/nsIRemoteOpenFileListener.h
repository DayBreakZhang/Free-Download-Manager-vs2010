/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRemoteOpenFileListener.idl
 */

#ifndef __gen_nsIRemoteOpenFileListener_h__
#define __gen_nsIRemoteOpenFileListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRemoteOpenFileListener */
#define NS_IREMOTEOPENFILELISTENER_IID_STR "5c89208c-fe2b-4e04-9783-93bcf5c3b783"

#define NS_IREMOTEOPENFILELISTENER_IID \
  {0x5c89208c, 0xfe2b, 0x4e04, \
    { 0x97, 0x83, 0x93, 0xbc, 0xf5, 0xc3, 0xb7, 0x83 }}

class NS_NO_VTABLE nsIRemoteOpenFileListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREMOTEOPENFILELISTENER_IID)

  /* void onRemoteFileOpenComplete (in nsresult aOpenStatus); */
  NS_IMETHOD OnRemoteFileOpenComplete(nsresult aOpenStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRemoteOpenFileListener, NS_IREMOTEOPENFILELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREMOTEOPENFILELISTENER \
  NS_IMETHOD OnRemoteFileOpenComplete(nsresult aOpenStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREMOTEOPENFILELISTENER(_to) \
  NS_IMETHOD OnRemoteFileOpenComplete(nsresult aOpenStatus) { return _to OnRemoteFileOpenComplete(aOpenStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREMOTEOPENFILELISTENER(_to) \
  NS_IMETHOD OnRemoteFileOpenComplete(nsresult aOpenStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRemoteFileOpenComplete(aOpenStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRemoteOpenFileListener : public nsIRemoteOpenFileListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREMOTEOPENFILELISTENER

  nsRemoteOpenFileListener();

private:
  ~nsRemoteOpenFileListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRemoteOpenFileListener, nsIRemoteOpenFileListener)

nsRemoteOpenFileListener::nsRemoteOpenFileListener()
{
  /* member initializers and constructor code */
}

nsRemoteOpenFileListener::~nsRemoteOpenFileListener()
{
  /* destructor code */
}

/* void onRemoteFileOpenComplete (in nsresult aOpenStatus); */
NS_IMETHODIMP nsRemoteOpenFileListener::OnRemoteFileOpenComplete(nsresult aOpenStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRemoteOpenFileListener_h__ */
