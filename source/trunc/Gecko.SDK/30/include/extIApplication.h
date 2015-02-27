/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\extIApplication.idl
 */

#ifndef __gen_extIApplication_h__
#define __gen_extIApplication_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class extIPreference; /* forward declaration */

class extISessionStorage; /* forward declaration */


/* starting interface:    extIConsole */
#define EXTICONSOLE_IID_STR "ae8482e0-aa5a-11db-abbd-0800200c9a66"

#define EXTICONSOLE_IID \
  {0xae8482e0, 0xaa5a, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE extIConsole : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTICONSOLE_IID)

  /* void log (in AString aMsg); */
  NS_IMETHOD Log(const nsAString & aMsg) = 0;

  /* void open (); */
  NS_IMETHOD Open(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIConsole, EXTICONSOLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTICONSOLE \
  NS_IMETHOD Log(const nsAString & aMsg); \
  NS_IMETHOD Open(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTICONSOLE(_to) \
  NS_IMETHOD Log(const nsAString & aMsg) { return _to Log(aMsg); } \
  NS_IMETHOD Open(void) { return _to Open(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTICONSOLE(_to) \
  NS_IMETHOD Log(const nsAString & aMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->Log(aMsg); } \
  NS_IMETHOD Open(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIConsole
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTICONSOLE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIConsole)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void log (in AString aMsg); */
NS_IMETHODIMP _MYCLASS_::Log(const nsAString & aMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (); */
NS_IMETHODIMP _MYCLASS_::Open()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIEventItem */
#define EXTIEVENTITEM_IID_STR "05281820-ab62-11db-abbd-0800200c9a66"

#define EXTIEVENTITEM_IID \
  {0x05281820, 0xab62, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE extIEventItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEVENTITEM_IID)

  /* readonly attribute AString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute nsIVariant data; */
  NS_IMETHOD GetData(nsIVariant * *aData) = 0;

  /* void preventDefault (); */
  NS_IMETHOD PreventDefault(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIEventItem, EXTIEVENTITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEVENTITEM \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetData(nsIVariant * *aData); \
  NS_IMETHOD PreventDefault(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEVENTITEM(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetData(nsIVariant * *aData) { return _to GetData(aData); } \
  NS_IMETHOD PreventDefault(void) { return _to PreventDefault(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEVENTITEM(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetData(nsIVariant * *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD PreventDefault(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreventDefault(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIEventItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEVENTITEM

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIEventItem)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString type; */
NS_IMETHODIMP _MYCLASS_::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant data; */
NS_IMETHODIMP _MYCLASS_::GetData(nsIVariant * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preventDefault (); */
NS_IMETHODIMP _MYCLASS_::PreventDefault()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIEventListener */
#define EXTIEVENTLISTENER_IID_STR "2dfe3a50-ab2f-11db-abbd-0800200c9a66"

#define EXTIEVENTLISTENER_IID \
  {0x2dfe3a50, 0xab2f, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE extIEventListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEVENTLISTENER_IID)

  /* void handleEvent (in extIEventItem aEvent); */
  NS_IMETHOD HandleEvent(extIEventItem *aEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIEventListener, EXTIEVENTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEVENTLISTENER \
  NS_IMETHOD HandleEvent(extIEventItem *aEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEVENTLISTENER(_to) \
  NS_IMETHOD HandleEvent(extIEventItem *aEvent) { return _to HandleEvent(aEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEVENTLISTENER(_to) \
  NS_IMETHOD HandleEvent(extIEventItem *aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(aEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIEventListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEVENTLISTENER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIEventListener)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void handleEvent (in extIEventItem aEvent); */
NS_IMETHODIMP _MYCLASS_::HandleEvent(extIEventItem *aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIEvents */
#define EXTIEVENTS_IID_STR "3a8ec9d0-ab19-11db-abbd-0800200c9a66"

#define EXTIEVENTS_IID \
  {0x3a8ec9d0, 0xab19, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE extIEvents : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEVENTS_IID)

  /* void addListener (in AString aEvent, in extIEventListener aListener); */
  NS_IMETHOD AddListener(const nsAString & aEvent, extIEventListener *aListener) = 0;

  /* void removeListener (in AString aEvent, in extIEventListener aListener); */
  NS_IMETHOD RemoveListener(const nsAString & aEvent, extIEventListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIEvents, EXTIEVENTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEVENTS \
  NS_IMETHOD AddListener(const nsAString & aEvent, extIEventListener *aListener); \
  NS_IMETHOD RemoveListener(const nsAString & aEvent, extIEventListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEVENTS(_to) \
  NS_IMETHOD AddListener(const nsAString & aEvent, extIEventListener *aListener) { return _to AddListener(aEvent, aListener); } \
  NS_IMETHOD RemoveListener(const nsAString & aEvent, extIEventListener *aListener) { return _to RemoveListener(aEvent, aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEVENTS(_to) \
  NS_IMETHOD AddListener(const nsAString & aEvent, extIEventListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aEvent, aListener); } \
  NS_IMETHOD RemoveListener(const nsAString & aEvent, extIEventListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aEvent, aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIEvents
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEVENTS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIEvents)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void addListener (in AString aEvent, in extIEventListener aListener); */
NS_IMETHODIMP _MYCLASS_::AddListener(const nsAString & aEvent, extIEventListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in AString aEvent, in extIEventListener aListener); */
NS_IMETHODIMP _MYCLASS_::RemoveListener(const nsAString & aEvent, extIEventListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIPreferenceBranch */
#define EXTIPREFERENCEBRANCH_IID_STR "ce697d40-aa5a-11db-abbd-0800200c9a66"

#define EXTIPREFERENCEBRANCH_IID \
  {0xce697d40, 0xaa5a, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE extIPreferenceBranch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIPREFERENCEBRANCH_IID)

  /* readonly attribute AString root; */
  NS_IMETHOD GetRoot(nsAString & aRoot) = 0;

  /* readonly attribute nsIVariant all; */
  NS_IMETHOD GetAll(nsIVariant * *aAll) = 0;

  /* readonly attribute extIEvents events; */
  NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /* boolean has (in AString aName); */
  NS_IMETHOD Has(const nsAString & aName, bool *_retval) = 0;

  /* extIPreference get (in AString aName); */
  NS_IMETHOD Get(const nsAString & aName, extIPreference * *_retval) = 0;

  /* nsIVariant getValue (in AString aName, in nsIVariant aDefaultValue); */
  NS_IMETHOD GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval) = 0;

  /* void setValue (in AString aName, in nsIVariant aValue); */
  NS_IMETHOD SetValue(const nsAString & aName, nsIVariant *aValue) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIPreferenceBranch, EXTIPREFERENCEBRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIPREFERENCEBRANCH \
  NS_IMETHOD GetRoot(nsAString & aRoot); \
  NS_IMETHOD GetAll(nsIVariant * *aAll); \
  NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_IMETHOD Has(const nsAString & aName, bool *_retval); \
  NS_IMETHOD Get(const nsAString & aName, extIPreference * *_retval); \
  NS_IMETHOD GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval); \
  NS_IMETHOD SetValue(const nsAString & aName, nsIVariant *aValue); \
  NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIPREFERENCEBRANCH(_to) \
  NS_IMETHOD GetRoot(nsAString & aRoot) { return _to GetRoot(aRoot); } \
  NS_IMETHOD GetAll(nsIVariant * *aAll) { return _to GetAll(aAll); } \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_IMETHOD Has(const nsAString & aName, bool *_retval) { return _to Has(aName, _retval); } \
  NS_IMETHOD Get(const nsAString & aName, extIPreference * *_retval) { return _to Get(aName, _retval); } \
  NS_IMETHOD GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval) { return _to GetValue(aName, aDefaultValue, _retval); } \
  NS_IMETHOD SetValue(const nsAString & aName, nsIVariant *aValue) { return _to SetValue(aName, aValue); } \
  NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIPREFERENCEBRANCH(_to) \
  NS_IMETHOD GetRoot(nsAString & aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_IMETHOD GetAll(nsIVariant * *aAll) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(aAll); } \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_IMETHOD Has(const nsAString & aName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Has(aName, _retval); } \
  NS_IMETHOD Get(const nsAString & aName, extIPreference * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, _retval); } \
  NS_IMETHOD GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aName, aDefaultValue, _retval); } \
  NS_IMETHOD SetValue(const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aName, aValue); } \
  NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIPreferenceBranch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIPREFERENCEBRANCH

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIPreferenceBranch)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString root; */
NS_IMETHODIMP _MYCLASS_::GetRoot(nsAString & aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant all; */
NS_IMETHODIMP _MYCLASS_::GetAll(nsIVariant * *aAll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean has (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Has(const nsAString & aName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* extIPreference get (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Get(const nsAString & aName, extIPreference * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getValue (in AString aName, in nsIVariant aDefaultValue); */
NS_IMETHODIMP _MYCLASS_::GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setValue (in AString aName, in nsIVariant aValue); */
NS_IMETHODIMP _MYCLASS_::SetValue(const nsAString & aName, nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP _MYCLASS_::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIPreference */
#define EXTIPREFERENCE_IID_STR "2c7462e2-72c2-4473-9007-0e6ae71e23ca"

#define EXTIPREFERENCE_IID \
  {0x2c7462e2, 0x72c2, 0x4473, \
    { 0x90, 0x07, 0x0e, 0x6a, 0xe7, 0x1e, 0x23, 0xca }}

class NS_NO_VTABLE extIPreference : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIPREFERENCE_IID)

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute AString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* attribute nsIVariant value; */
  NS_IMETHOD GetValue(nsIVariant * *aValue) = 0;
  NS_IMETHOD SetValue(nsIVariant *aValue) = 0;

  /* attribute boolean locked; */
  NS_IMETHOD GetLocked(bool *aLocked) = 0;
  NS_IMETHOD SetLocked(bool aLocked) = 0;

  /* readonly attribute boolean modified; */
  NS_IMETHOD GetModified(bool *aModified) = 0;

  /* readonly attribute extIPreferenceBranch branch; */
  NS_IMETHOD GetBranch(extIPreferenceBranch * *aBranch) = 0;

  /* readonly attribute extIEvents events; */
  NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIPreference, EXTIPREFERENCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIPREFERENCE \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetValue(nsIVariant * *aValue); \
  NS_IMETHOD SetValue(nsIVariant *aValue); \
  NS_IMETHOD GetLocked(bool *aLocked); \
  NS_IMETHOD SetLocked(bool aLocked); \
  NS_IMETHOD GetModified(bool *aModified); \
  NS_IMETHOD GetBranch(extIPreferenceBranch * *aBranch); \
  NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIPREFERENCE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetValue(nsIVariant * *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(nsIVariant *aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetLocked(bool *aLocked) { return _to GetLocked(aLocked); } \
  NS_IMETHOD SetLocked(bool aLocked) { return _to SetLocked(aLocked); } \
  NS_IMETHOD GetModified(bool *aModified) { return _to GetModified(aModified); } \
  NS_IMETHOD GetBranch(extIPreferenceBranch * *aBranch) { return _to GetBranch(aBranch); } \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIPREFERENCE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetValue(nsIVariant * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetLocked(bool *aLocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocked(aLocked); } \
  NS_IMETHOD SetLocked(bool aLocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocked(aLocked); } \
  NS_IMETHOD GetModified(bool *aModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModified(aModified); } \
  NS_IMETHOD GetBranch(extIPreferenceBranch * *aBranch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBranch(aBranch); } \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIPreference
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIPREFERENCE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIPreference)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString name; */
NS_IMETHODIMP _MYCLASS_::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString type; */
NS_IMETHODIMP _MYCLASS_::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant value; */
NS_IMETHODIMP _MYCLASS_::GetValue(nsIVariant * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetValue(nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean locked; */
NS_IMETHODIMP _MYCLASS_::GetLocked(bool *aLocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetLocked(bool aLocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean modified; */
NS_IMETHODIMP _MYCLASS_::GetModified(bool *aModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIPreferenceBranch branch; */
NS_IMETHODIMP _MYCLASS_::GetBranch(extIPreferenceBranch * *aBranch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP _MYCLASS_::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIExtension */
#define EXTIEXTENSION_IID_STR "10cee02c-f6e0-4d61-ab27-c16572b18c46"

#define EXTIEXTENSION_IID \
  {0x10cee02c, 0xf6e0, 0x4d61, \
    { 0xab, 0x27, 0xc1, 0x65, 0x72, 0xb1, 0x8c, 0x46 }}

class NS_NO_VTABLE extIExtension : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEXTENSION_IID)

  /* readonly attribute AString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute boolean enabled; */
  NS_IMETHOD GetEnabled(bool *aEnabled) = 0;

  /* readonly attribute AString version; */
  NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /* readonly attribute boolean firstRun; */
  NS_IMETHOD GetFirstRun(bool *aFirstRun) = 0;

  /* readonly attribute extIPreferenceBranch prefs; */
  NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) = 0;

  /* readonly attribute extISessionStorage storage; */
  NS_IMETHOD GetStorage(extISessionStorage * *aStorage) = 0;

  /* readonly attribute extIEvents events; */
  NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIExtension, EXTIEXTENSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEXTENSION \
  NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetEnabled(bool *aEnabled); \
  NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_IMETHOD GetFirstRun(bool *aFirstRun); \
  NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs); \
  NS_IMETHOD GetStorage(extISessionStorage * *aStorage); \
  NS_IMETHOD GetEvents(extIEvents * *aEvents); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEXTENSION(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetEnabled(bool *aEnabled) { return _to GetEnabled(aEnabled); } \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD GetFirstRun(bool *aFirstRun) { return _to GetFirstRun(aFirstRun); } \
  NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) { return _to GetPrefs(aPrefs); } \
  NS_IMETHOD GetStorage(extISessionStorage * *aStorage) { return _to GetStorage(aStorage); } \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEXTENSION(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetEnabled(bool *aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnabled(aEnabled); } \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD GetFirstRun(bool *aFirstRun) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstRun(aFirstRun); } \
  NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefs(aPrefs); } \
  NS_IMETHOD GetStorage(extISessionStorage * *aStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorage(aStorage); } \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIExtension
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEXTENSION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIExtension)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString id; */
NS_IMETHODIMP _MYCLASS_::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP _MYCLASS_::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean enabled; */
NS_IMETHODIMP _MYCLASS_::GetEnabled(bool *aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString version; */
NS_IMETHODIMP _MYCLASS_::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean firstRun; */
NS_IMETHODIMP _MYCLASS_::GetFirstRun(bool *aFirstRun)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIPreferenceBranch prefs; */
NS_IMETHODIMP _MYCLASS_::GetPrefs(extIPreferenceBranch * *aPrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extISessionStorage storage; */
NS_IMETHODIMP _MYCLASS_::GetStorage(extISessionStorage * *aStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIExtensions */
#define EXTIEXTENSIONS_IID_STR "de281930-aa5a-11db-abbd-0800200c9a66"

#define EXTIEXTENSIONS_IID \
  {0xde281930, 0xaa5a, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE extIExtensions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEXTENSIONS_IID)

  /* readonly attribute nsIVariant all; */
  NS_IMETHOD GetAll(nsIVariant * *aAll) = 0;

  /* boolean has (in AString aId); */
  NS_IMETHOD Has(const nsAString & aId, bool *_retval) = 0;

  /* extIExtension get (in AString aId); */
  NS_IMETHOD Get(const nsAString & aId, extIExtension * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIExtensions, EXTIEXTENSIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEXTENSIONS \
  NS_IMETHOD GetAll(nsIVariant * *aAll); \
  NS_IMETHOD Has(const nsAString & aId, bool *_retval); \
  NS_IMETHOD Get(const nsAString & aId, extIExtension * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEXTENSIONS(_to) \
  NS_IMETHOD GetAll(nsIVariant * *aAll) { return _to GetAll(aAll); } \
  NS_IMETHOD Has(const nsAString & aId, bool *_retval) { return _to Has(aId, _retval); } \
  NS_IMETHOD Get(const nsAString & aId, extIExtension * *_retval) { return _to Get(aId, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEXTENSIONS(_to) \
  NS_IMETHOD GetAll(nsIVariant * *aAll) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(aAll); } \
  NS_IMETHOD Has(const nsAString & aId, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Has(aId, _retval); } \
  NS_IMETHOD Get(const nsAString & aId, extIExtension * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aId, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIExtensions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEXTENSIONS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIExtensions)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute nsIVariant all; */
NS_IMETHODIMP _MYCLASS_::GetAll(nsIVariant * *aAll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean has (in AString aId); */
NS_IMETHODIMP _MYCLASS_::Has(const nsAString & aId, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* extIExtension get (in AString aId); */
NS_IMETHODIMP _MYCLASS_::Get(const nsAString & aId, extIExtension * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIExtensionsCallback */
#define EXTIEXTENSIONSCALLBACK_IID_STR "2571cbb5-550d-4400-8038-75df9b553f98"

#define EXTIEXTENSIONSCALLBACK_IID \
  {0x2571cbb5, 0x550d, 0x4400, \
    { 0x80, 0x38, 0x75, 0xdf, 0x9b, 0x55, 0x3f, 0x98 }}

class NS_NO_VTABLE extIExtensionsCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEXTENSIONSCALLBACK_IID)

  /* void callback (in nsIVariant extensions); */
  NS_IMETHOD Callback(nsIVariant *extensions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIExtensionsCallback, EXTIEXTENSIONSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEXTENSIONSCALLBACK \
  NS_IMETHOD Callback(nsIVariant *extensions); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEXTENSIONSCALLBACK(_to) \
  NS_IMETHOD Callback(nsIVariant *extensions) { return _to Callback(extensions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEXTENSIONSCALLBACK(_to) \
  NS_IMETHOD Callback(nsIVariant *extensions) { return !_to ? NS_ERROR_NULL_POINTER : _to->Callback(extensions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIExtensionsCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEXTENSIONSCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIExtensionsCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void callback (in nsIVariant extensions); */
NS_IMETHODIMP _MYCLASS_::Callback(nsIVariant *extensions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extISessionStorage */
#define EXTISESSIONSTORAGE_IID_STR "0787ac44-29b9-4889-b97f-13573aec6971"

#define EXTISESSIONSTORAGE_IID \
  {0x0787ac44, 0x29b9, 0x4889, \
    { 0xb9, 0x7f, 0x13, 0x57, 0x3a, 0xec, 0x69, 0x71 }}

class NS_NO_VTABLE extISessionStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTISESSIONSTORAGE_IID)

  /* readonly attribute extIEvents events; */
  NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /* boolean has (in AString aName); */
  NS_IMETHOD Has(const nsAString & aName, bool *_retval) = 0;

  /* void set (in AString aName, in nsIVariant aValue); */
  NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue) = 0;

  /* nsIVariant get (in AString aName, in nsIVariant aDefaultValue); */
  NS_IMETHOD Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extISessionStorage, EXTISESSIONSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTISESSIONSTORAGE \
  NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_IMETHOD Has(const nsAString & aName, bool *_retval); \
  NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue); \
  NS_IMETHOD Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTISESSIONSTORAGE(_to) \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_IMETHOD Has(const nsAString & aName, bool *_retval) { return _to Has(aName, _retval); } \
  NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue) { return _to Set(aName, aValue); } \
  NS_IMETHOD Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval) { return _to Get(aName, aDefaultValue, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTISESSIONSTORAGE(_to) \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_IMETHOD Has(const nsAString & aName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Has(aName, _retval); } \
  NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(aName, aValue); } \
  NS_IMETHOD Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, aDefaultValue, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extISessionStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTISESSIONSTORAGE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extISessionStorage)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean has (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Has(const nsAString & aName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void set (in AString aName, in nsIVariant aValue); */
NS_IMETHODIMP _MYCLASS_::Set(const nsAString & aName, nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant get (in AString aName, in nsIVariant aDefaultValue); */
NS_IMETHODIMP _MYCLASS_::Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIApplication */
#define EXTIAPPLICATION_IID_STR "2be87909-0817-4292-acfa-fc39be53be3f"

#define EXTIAPPLICATION_IID \
  {0x2be87909, 0x0817, 0x4292, \
    { 0xac, 0xfa, 0xfc, 0x39, 0xbe, 0x53, 0xbe, 0x3f }}

class NS_NO_VTABLE extIApplication : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIAPPLICATION_IID)

  /* readonly attribute AString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute AString version; */
  NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /* readonly attribute extIConsole console; */
  NS_IMETHOD GetConsole(extIConsole * *aConsole) = 0;

  /* void getExtensions (in extIExtensionsCallback aCallback); */
  NS_IMETHOD GetExtensions(extIExtensionsCallback *aCallback) = 0;

  /* readonly attribute extIPreferenceBranch prefs; */
  NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) = 0;

  /* readonly attribute extISessionStorage storage; */
  NS_IMETHOD GetStorage(extISessionStorage * *aStorage) = 0;

  /* readonly attribute extIEvents events; */
  NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /* boolean quit (); */
  NS_IMETHOD Quit(bool *_retval) = 0;

  /* boolean restart (); */
  NS_IMETHOD Restart(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIApplication, EXTIAPPLICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIAPPLICATION \
  NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_IMETHOD GetConsole(extIConsole * *aConsole); \
  NS_IMETHOD GetExtensions(extIExtensionsCallback *aCallback); \
  NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs); \
  NS_IMETHOD GetStorage(extISessionStorage * *aStorage); \
  NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_IMETHOD Quit(bool *_retval); \
  NS_IMETHOD Restart(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIAPPLICATION(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD GetConsole(extIConsole * *aConsole) { return _to GetConsole(aConsole); } \
  NS_IMETHOD GetExtensions(extIExtensionsCallback *aCallback) { return _to GetExtensions(aCallback); } \
  NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) { return _to GetPrefs(aPrefs); } \
  NS_IMETHOD GetStorage(extISessionStorage * *aStorage) { return _to GetStorage(aStorage); } \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_IMETHOD Quit(bool *_retval) { return _to Quit(_retval); } \
  NS_IMETHOD Restart(bool *_retval) { return _to Restart(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIAPPLICATION(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD GetConsole(extIConsole * *aConsole) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConsole(aConsole); } \
  NS_IMETHOD GetExtensions(extIExtensionsCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtensions(aCallback); } \
  NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefs(aPrefs); } \
  NS_IMETHOD GetStorage(extISessionStorage * *aStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorage(aStorage); } \
  NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_IMETHOD Quit(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Quit(_retval); } \
  NS_IMETHOD Restart(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Restart(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIApplication
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIAPPLICATION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIApplication)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString id; */
NS_IMETHODIMP _MYCLASS_::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP _MYCLASS_::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString version; */
NS_IMETHODIMP _MYCLASS_::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIConsole console; */
NS_IMETHODIMP _MYCLASS_::GetConsole(extIConsole * *aConsole)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getExtensions (in extIExtensionsCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::GetExtensions(extIExtensionsCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIPreferenceBranch prefs; */
NS_IMETHODIMP _MYCLASS_::GetPrefs(extIPreferenceBranch * *aPrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extISessionStorage storage; */
NS_IMETHODIMP _MYCLASS_::GetStorage(extISessionStorage * *aStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean quit (); */
NS_IMETHODIMP _MYCLASS_::Quit(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean restart (); */
NS_IMETHODIMP _MYCLASS_::Restart(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_extIApplication_h__ */
