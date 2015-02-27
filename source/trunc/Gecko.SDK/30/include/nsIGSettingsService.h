/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIGSettingsService.idl
 */

#ifndef __gen_nsIGSettingsService_h__
#define __gen_nsIGSettingsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */


/* starting interface:    nsIGSettingsCollection */
#define NS_IGSETTINGSCOLLECTION_IID_STR "16d5b0ed-e756-4f1b-a8ce-9132e869acd8"

#define NS_IGSETTINGSCOLLECTION_IID \
  {0x16d5b0ed, 0xe756, 0x4f1b, \
    { 0xa8, 0xce, 0x91, 0x32, 0xe8, 0x69, 0xac, 0xd8 }}

class NS_NO_VTABLE nsIGSettingsCollection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGSETTINGSCOLLECTION_IID)

  /* void setString (in AUTF8String key, in AUTF8String value); */
  NS_IMETHOD SetString(const nsACString & key, const nsACString & value) = 0;

  /* void setBoolean (in AUTF8String key, in boolean value); */
  NS_IMETHOD SetBoolean(const nsACString & key, bool value) = 0;

  /* void setInt (in AUTF8String key, in long value); */
  NS_IMETHOD SetInt(const nsACString & key, int32_t value) = 0;

  /* AUTF8String getString (in AUTF8String key); */
  NS_IMETHOD GetString(const nsACString & key, nsACString & _retval) = 0;

  /* boolean getBoolean (in AUTF8String key); */
  NS_IMETHOD GetBoolean(const nsACString & key, bool *_retval) = 0;

  /* long getInt (in AUTF8String key); */
  NS_IMETHOD GetInt(const nsACString & key, int32_t *_retval) = 0;

  /* nsIArray getStringList (in AUTF8String key); */
  NS_IMETHOD GetStringList(const nsACString & key, nsIArray * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGSettingsCollection, NS_IGSETTINGSCOLLECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGSETTINGSCOLLECTION \
  NS_IMETHOD SetString(const nsACString & key, const nsACString & value); \
  NS_IMETHOD SetBoolean(const nsACString & key, bool value); \
  NS_IMETHOD SetInt(const nsACString & key, int32_t value); \
  NS_IMETHOD GetString(const nsACString & key, nsACString & _retval); \
  NS_IMETHOD GetBoolean(const nsACString & key, bool *_retval); \
  NS_IMETHOD GetInt(const nsACString & key, int32_t *_retval); \
  NS_IMETHOD GetStringList(const nsACString & key, nsIArray * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGSETTINGSCOLLECTION(_to) \
  NS_IMETHOD SetString(const nsACString & key, const nsACString & value) { return _to SetString(key, value); } \
  NS_IMETHOD SetBoolean(const nsACString & key, bool value) { return _to SetBoolean(key, value); } \
  NS_IMETHOD SetInt(const nsACString & key, int32_t value) { return _to SetInt(key, value); } \
  NS_IMETHOD GetString(const nsACString & key, nsACString & _retval) { return _to GetString(key, _retval); } \
  NS_IMETHOD GetBoolean(const nsACString & key, bool *_retval) { return _to GetBoolean(key, _retval); } \
  NS_IMETHOD GetInt(const nsACString & key, int32_t *_retval) { return _to GetInt(key, _retval); } \
  NS_IMETHOD GetStringList(const nsACString & key, nsIArray * *_retval) { return _to GetStringList(key, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGSETTINGSCOLLECTION(_to) \
  NS_IMETHOD SetString(const nsACString & key, const nsACString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetString(key, value); } \
  NS_IMETHOD SetBoolean(const nsACString & key, bool value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBoolean(key, value); } \
  NS_IMETHOD SetInt(const nsACString & key, int32_t value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInt(key, value); } \
  NS_IMETHOD GetString(const nsACString & key, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(key, _retval); } \
  NS_IMETHOD GetBoolean(const nsACString & key, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoolean(key, _retval); } \
  NS_IMETHOD GetInt(const nsACString & key, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt(key, _retval); } \
  NS_IMETHOD GetStringList(const nsACString & key, nsIArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringList(key, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGSettingsCollection : public nsIGSettingsCollection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGSETTINGSCOLLECTION

  nsGSettingsCollection();

private:
  ~nsGSettingsCollection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGSettingsCollection, nsIGSettingsCollection)

nsGSettingsCollection::nsGSettingsCollection()
{
  /* member initializers and constructor code */
}

nsGSettingsCollection::~nsGSettingsCollection()
{
  /* destructor code */
}

/* void setString (in AUTF8String key, in AUTF8String value); */
NS_IMETHODIMP nsGSettingsCollection::SetString(const nsACString & key, const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBoolean (in AUTF8String key, in boolean value); */
NS_IMETHODIMP nsGSettingsCollection::SetBoolean(const nsACString & key, bool value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setInt (in AUTF8String key, in long value); */
NS_IMETHODIMP nsGSettingsCollection::SetInt(const nsACString & key, int32_t value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getString (in AUTF8String key); */
NS_IMETHODIMP nsGSettingsCollection::GetString(const nsACString & key, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getBoolean (in AUTF8String key); */
NS_IMETHODIMP nsGSettingsCollection::GetBoolean(const nsACString & key, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getInt (in AUTF8String key); */
NS_IMETHODIMP nsGSettingsCollection::GetInt(const nsACString & key, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getStringList (in AUTF8String key); */
NS_IMETHODIMP nsGSettingsCollection::GetStringList(const nsACString & key, nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGSettingsService */
#define NS_IGSETTINGSSERVICE_IID_STR "849c088b-57d1-4f24-b7b2-3dc4acb04c0a"

#define NS_IGSETTINGSSERVICE_IID \
  {0x849c088b, 0x57d1, 0x4f24, \
    { 0xb7, 0xb2, 0x3d, 0xc4, 0xac, 0xb0, 0x4c, 0x0a }}

class NS_NO_VTABLE nsIGSettingsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGSETTINGSSERVICE_IID)

  /* nsIGSettingsCollection getCollectionForSchema (in AUTF8String schema); */
  NS_IMETHOD GetCollectionForSchema(const nsACString & schema, nsIGSettingsCollection * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGSettingsService, NS_IGSETTINGSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGSETTINGSSERVICE \
  NS_IMETHOD GetCollectionForSchema(const nsACString & schema, nsIGSettingsCollection * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGSETTINGSSERVICE(_to) \
  NS_IMETHOD GetCollectionForSchema(const nsACString & schema, nsIGSettingsCollection * *_retval) { return _to GetCollectionForSchema(schema, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGSETTINGSSERVICE(_to) \
  NS_IMETHOD GetCollectionForSchema(const nsACString & schema, nsIGSettingsCollection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCollectionForSchema(schema, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGSettingsService : public nsIGSettingsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGSETTINGSSERVICE

  nsGSettingsService();

private:
  ~nsGSettingsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGSettingsService, nsIGSettingsService)

nsGSettingsService::nsGSettingsService()
{
  /* member initializers and constructor code */
}

nsGSettingsService::~nsGSettingsService()
{
  /* destructor code */
}

/* nsIGSettingsCollection getCollectionForSchema (in AUTF8String schema); */
NS_IMETHODIMP nsGSettingsService::GetCollectionForSchema(const nsACString & schema, nsIGSettingsCollection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_GSETTINGSSERVICE_CONTRACTID "@mozilla.org/gsettings-service;1"

#endif /* __gen_nsIGSettingsService_h__ */
