/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFormHistory.idl
 */

#ifndef __gen_nsIFormHistory_h__
#define __gen_nsIFormHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class mozIStorageConnection; /* forward declaration */


/* starting interface:    nsIFormHistory2 */
#define NS_IFORMHISTORY2_IID_STR "5d7d84d1-9798-4016-bf61-a32acf09b29d"

#define NS_IFORMHISTORY2_IID \
  {0x5d7d84d1, 0x9798, 0x4016, \
    { 0xbf, 0x61, 0xa3, 0x2a, 0xcf, 0x09, 0xb2, 0x9d }}

class NS_NO_VTABLE nsIFormHistory2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMHISTORY2_IID)

  /* readonly attribute boolean hasEntries; */
  NS_IMETHOD GetHasEntries(bool *aHasEntries) = 0;

  /* void addEntry (in AString name, in AString value); */
  NS_IMETHOD AddEntry(const nsAString & name, const nsAString & value) = 0;

  /* void removeEntry (in AString name, in AString value); */
  NS_IMETHOD RemoveEntry(const nsAString & name, const nsAString & value) = 0;

  /* void removeEntriesForName (in AString name); */
  NS_IMETHOD RemoveEntriesForName(const nsAString & name) = 0;

  /* void removeAllEntries (); */
  NS_IMETHOD RemoveAllEntries(void) = 0;

  /* boolean nameExists (in AString name); */
  NS_IMETHOD NameExists(const nsAString & name, bool *_retval) = 0;

  /* boolean entryExists (in AString name, in AString value); */
  NS_IMETHOD EntryExists(const nsAString & name, const nsAString & value, bool *_retval) = 0;

  /* void removeEntriesByTimeframe (in long long aBeginTime, in long long aEndTime); */
  NS_IMETHOD RemoveEntriesByTimeframe(int64_t aBeginTime, int64_t aEndTime) = 0;

  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormHistory2, NS_IFORMHISTORY2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMHISTORY2 \
  NS_IMETHOD GetHasEntries(bool *aHasEntries); \
  NS_IMETHOD AddEntry(const nsAString & name, const nsAString & value); \
  NS_IMETHOD RemoveEntry(const nsAString & name, const nsAString & value); \
  NS_IMETHOD RemoveEntriesForName(const nsAString & name); \
  NS_IMETHOD RemoveAllEntries(void); \
  NS_IMETHOD NameExists(const nsAString & name, bool *_retval); \
  NS_IMETHOD EntryExists(const nsAString & name, const nsAString & value, bool *_retval); \
  NS_IMETHOD RemoveEntriesByTimeframe(int64_t aBeginTime, int64_t aEndTime); \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMHISTORY2(_to) \
  NS_IMETHOD GetHasEntries(bool *aHasEntries) { return _to GetHasEntries(aHasEntries); } \
  NS_IMETHOD AddEntry(const nsAString & name, const nsAString & value) { return _to AddEntry(name, value); } \
  NS_IMETHOD RemoveEntry(const nsAString & name, const nsAString & value) { return _to RemoveEntry(name, value); } \
  NS_IMETHOD RemoveEntriesForName(const nsAString & name) { return _to RemoveEntriesForName(name); } \
  NS_IMETHOD RemoveAllEntries(void) { return _to RemoveAllEntries(); } \
  NS_IMETHOD NameExists(const nsAString & name, bool *_retval) { return _to NameExists(name, _retval); } \
  NS_IMETHOD EntryExists(const nsAString & name, const nsAString & value, bool *_retval) { return _to EntryExists(name, value, _retval); } \
  NS_IMETHOD RemoveEntriesByTimeframe(int64_t aBeginTime, int64_t aEndTime) { return _to RemoveEntriesByTimeframe(aBeginTime, aEndTime); } \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return _to GetDBConnection(aDBConnection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMHISTORY2(_to) \
  NS_IMETHOD GetHasEntries(bool *aHasEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasEntries(aHasEntries); } \
  NS_IMETHOD AddEntry(const nsAString & name, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntry(name, value); } \
  NS_IMETHOD RemoveEntry(const nsAString & name, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntry(name, value); } \
  NS_IMETHOD RemoveEntriesForName(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntriesForName(name); } \
  NS_IMETHOD RemoveAllEntries(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllEntries(); } \
  NS_IMETHOD NameExists(const nsAString & name, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NameExists(name, _retval); } \
  NS_IMETHOD EntryExists(const nsAString & name, const nsAString & value, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EntryExists(name, value, _retval); } \
  NS_IMETHOD RemoveEntriesByTimeframe(int64_t aBeginTime, int64_t aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntriesByTimeframe(aBeginTime, aEndTime); } \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormHistory2 : public nsIFormHistory2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMHISTORY2

  nsFormHistory2();

private:
  ~nsFormHistory2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFormHistory2, nsIFormHistory2)

nsFormHistory2::nsFormHistory2()
{
  /* member initializers and constructor code */
}

nsFormHistory2::~nsFormHistory2()
{
  /* destructor code */
}

/* readonly attribute boolean hasEntries; */
NS_IMETHODIMP nsFormHistory2::GetHasEntries(bool *aHasEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEntry (in AString name, in AString value); */
NS_IMETHODIMP nsFormHistory2::AddEntry(const nsAString & name, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntry (in AString name, in AString value); */
NS_IMETHODIMP nsFormHistory2::RemoveEntry(const nsAString & name, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntriesForName (in AString name); */
NS_IMETHODIMP nsFormHistory2::RemoveEntriesForName(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllEntries (); */
NS_IMETHODIMP nsFormHistory2::RemoveAllEntries()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean nameExists (in AString name); */
NS_IMETHODIMP nsFormHistory2::NameExists(const nsAString & name, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean entryExists (in AString name, in AString value); */
NS_IMETHODIMP nsFormHistory2::EntryExists(const nsAString & name, const nsAString & value, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntriesByTimeframe (in long long aBeginTime, in long long aEndTime); */
NS_IMETHODIMP nsFormHistory2::RemoveEntriesByTimeframe(int64_t aBeginTime, int64_t aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP nsFormHistory2::GetDBConnection(mozIStorageConnection * *aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFormHistory_h__ */
