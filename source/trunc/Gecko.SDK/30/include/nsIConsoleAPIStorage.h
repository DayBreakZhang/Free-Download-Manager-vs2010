/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIConsoleAPIStorage.idl
 */

#ifndef __gen_nsIConsoleAPIStorage_h__
#define __gen_nsIConsoleAPIStorage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIConsoleAPIStorage */
#define NS_ICONSOLEAPISTORAGE_IID_STR "6701600a-17ca-417e-98f9-4ceb175dd15d"

#define NS_ICONSOLEAPISTORAGE_IID \
  {0x6701600a, 0x17ca, 0x417e, \
    { 0x98, 0xf9, 0x4c, 0xeb, 0x17, 0x5d, 0xd1, 0x5d }}

class NS_NO_VTABLE nsIConsoleAPIStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONSOLEAPISTORAGE_IID)

  /* jsval getEvents ([optional] in DOMString aId); */
  NS_IMETHOD GetEvents(const nsAString & aId, JS::MutableHandleValue _retval) = 0;

  /* void recordEvent (in DOMString aId, in jsval aEvent); */
  NS_IMETHOD RecordEvent(const nsAString & aId, JS::HandleValue aEvent) = 0;

  /* void clearEvents ([optional] in DOMString aId); */
  NS_IMETHOD ClearEvents(const nsAString & aId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConsoleAPIStorage, NS_ICONSOLEAPISTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONSOLEAPISTORAGE \
  NS_IMETHOD GetEvents(const nsAString & aId, JS::MutableHandleValue _retval); \
  NS_IMETHOD RecordEvent(const nsAString & aId, JS::HandleValue aEvent); \
  NS_IMETHOD ClearEvents(const nsAString & aId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONSOLEAPISTORAGE(_to) \
  NS_IMETHOD GetEvents(const nsAString & aId, JS::MutableHandleValue _retval) { return _to GetEvents(aId, _retval); } \
  NS_IMETHOD RecordEvent(const nsAString & aId, JS::HandleValue aEvent) { return _to RecordEvent(aId, aEvent); } \
  NS_IMETHOD ClearEvents(const nsAString & aId) { return _to ClearEvents(aId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONSOLEAPISTORAGE(_to) \
  NS_IMETHOD GetEvents(const nsAString & aId, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aId, _retval); } \
  NS_IMETHOD RecordEvent(const nsAString & aId, JS::HandleValue aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->RecordEvent(aId, aEvent); } \
  NS_IMETHOD ClearEvents(const nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearEvents(aId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConsoleAPIStorage : public nsIConsoleAPIStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONSOLEAPISTORAGE

  nsConsoleAPIStorage();

private:
  ~nsConsoleAPIStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConsoleAPIStorage, nsIConsoleAPIStorage)

nsConsoleAPIStorage::nsConsoleAPIStorage()
{
  /* member initializers and constructor code */
}

nsConsoleAPIStorage::~nsConsoleAPIStorage()
{
  /* destructor code */
}

/* jsval getEvents ([optional] in DOMString aId); */
NS_IMETHODIMP nsConsoleAPIStorage::GetEvents(const nsAString & aId, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void recordEvent (in DOMString aId, in jsval aEvent); */
NS_IMETHODIMP nsConsoleAPIStorage::RecordEvent(const nsAString & aId, JS::HandleValue aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearEvents ([optional] in DOMString aId); */
NS_IMETHODIMP nsConsoleAPIStorage::ClearEvents(const nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIConsoleAPIStorage_h__ */
