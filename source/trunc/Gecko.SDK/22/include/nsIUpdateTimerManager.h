/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/mozapps/update/nsIUpdateTimerManager.idl
 */

#ifndef __gen_nsIUpdateTimerManager_h__
#define __gen_nsIUpdateTimerManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITimerCallback; /* forward declaration */


/* starting interface:    nsIUpdateTimerManager */
#define NS_IUPDATETIMERMANAGER_IID_STR "0765c92c-6145-4253-9db4-594d8023087e"

#define NS_IUPDATETIMERMANAGER_IID \
  {0x0765c92c, 0x6145, 0x4253, \
    { 0x9d, 0xb4, 0x59, 0x4d, 0x80, 0x23, 0x08, 0x7e }}

class NS_NO_VTABLE nsIUpdateTimerManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATETIMERMANAGER_IID)

  /* void registerTimer (in AString id, in nsITimerCallback callback, in unsigned long interval); */
  NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, uint32_t interval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateTimerManager, NS_IUPDATETIMERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATETIMERMANAGER \
  NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, uint32_t interval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATETIMERMANAGER(_to) \
  NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, uint32_t interval) { return _to RegisterTimer(id, callback, interval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATETIMERMANAGER(_to) \
  NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, uint32_t interval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterTimer(id, callback, interval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateTimerManager : public nsIUpdateTimerManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATETIMERMANAGER

  nsUpdateTimerManager();

private:
  ~nsUpdateTimerManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdateTimerManager, nsIUpdateTimerManager)

nsUpdateTimerManager::nsUpdateTimerManager()
{
  /* member initializers and constructor code */
}

nsUpdateTimerManager::~nsUpdateTimerManager()
{
  /* destructor code */
}

/* void registerTimer (in AString id, in nsITimerCallback callback, in unsigned long interval); */
NS_IMETHODIMP nsUpdateTimerManager::RegisterTimer(const nsAString & id, nsITimerCallback *callback, uint32_t interval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUpdateTimerManager_h__ */
