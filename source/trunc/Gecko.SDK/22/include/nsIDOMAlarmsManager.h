/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/alarm/nsIDOMAlarmsManager.idl
 */

#ifndef __gen_nsIDOMAlarmsManager_h__
#define __gen_nsIDOMAlarmsManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */


/* starting interface:    nsIDOMMozAlarmsManager */
#define NS_IDOMMOZALARMSMANAGER_IID_STR "fea1e884-9b05-11e1-9b64-87a7016c3860"

#define NS_IDOMMOZALARMSMANAGER_IID \
  {0xfea1e884, 0x9b05, 0x11e1, \
    { 0x9b, 0x64, 0x87, 0xa7, 0x01, 0x6c, 0x38, 0x60 }}

class NS_NO_VTABLE nsIDOMMozAlarmsManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZALARMSMANAGER_IID)

  /* nsIDOMDOMRequest getAll (); */
  NS_IMETHOD GetAll(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest add (in jsval date, in DOMString respectTimezone, [optional] in jsval data); */
  NS_IMETHOD Add(const JS::Value & date, const nsAString & respectTimezone, const JS::Value & data, nsIDOMDOMRequest * *_retval) = 0;

  /* void remove (in unsigned long id); */
  NS_IMETHOD Remove(uint32_t id) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozAlarmsManager, NS_IDOMMOZALARMSMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZALARMSMANAGER \
  NS_IMETHOD GetAll(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Add(const JS::Value & date, const nsAString & respectTimezone, const JS::Value & data, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Remove(uint32_t id); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZALARMSMANAGER(_to) \
  NS_IMETHOD GetAll(nsIDOMDOMRequest * *_retval) { return _to GetAll(_retval); } \
  NS_IMETHOD Add(const JS::Value & date, const nsAString & respectTimezone, const JS::Value & data, nsIDOMDOMRequest * *_retval) { return _to Add(date, respectTimezone, data, _retval); } \
  NS_IMETHOD Remove(uint32_t id) { return _to Remove(id); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZALARMSMANAGER(_to) \
  NS_IMETHOD GetAll(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(_retval); } \
  NS_IMETHOD Add(const JS::Value & date, const nsAString & respectTimezone, const JS::Value & data, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(date, respectTimezone, data, _retval); } \
  NS_IMETHOD Remove(uint32_t id) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(id); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozAlarmsManager : public nsIDOMMozAlarmsManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZALARMSMANAGER

  nsDOMMozAlarmsManager();

private:
  ~nsDOMMozAlarmsManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozAlarmsManager, nsIDOMMozAlarmsManager)

nsDOMMozAlarmsManager::nsDOMMozAlarmsManager()
{
  /* member initializers and constructor code */
}

nsDOMMozAlarmsManager::~nsDOMMozAlarmsManager()
{
  /* destructor code */
}

/* nsIDOMDOMRequest getAll (); */
NS_IMETHODIMP nsDOMMozAlarmsManager::GetAll(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest add (in jsval date, in DOMString respectTimezone, [optional] in jsval data); */
NS_IMETHODIMP nsDOMMozAlarmsManager::Add(const JS::Value & date, const nsAString & respectTimezone, const JS::Value & data, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in unsigned long id); */
NS_IMETHODIMP nsDOMMozAlarmsManager::Remove(uint32_t id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMAlarmsManager_h__ */
