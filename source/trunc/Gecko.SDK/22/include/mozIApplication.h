/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/apps/mozIApplication.idl
 */

#ifndef __gen_mozIApplication_h__
#define __gen_mozIApplication_h__


#ifndef __gen_nsIDOMApplicationRegistry_h__
#include "nsIDOMApplicationRegistry.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIApplication */
#define MOZIAPPLICATION_IID_STR "cfa75628-4d31-481f-b51e-fe0ce18fa98f"

#define MOZIAPPLICATION_IID \
  {0xcfa75628, 0x4d31, 0x481f, \
    { 0xb5, 0x1e, 0xfe, 0x0c, 0xe1, 0x8f, 0xa9, 0x8f }}

class NS_NO_VTABLE mozIApplication : public mozIDOMApplication {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIAPPLICATION_IID)

  /* boolean hasPermission (in string permission); */
  NS_IMETHOD HasPermission(const char * permission, bool *_retval) = 0;

  /* readonly attribute unsigned short appStatus; */
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) = 0;

  /* readonly attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;

  /* readonly attribute unsigned long localId; */
  NS_IMETHOD GetLocalId(uint32_t *aLocalId) = 0;

  /* readonly attribute DOMString basePath; */
  NS_IMETHOD GetBasePath(nsAString & aBasePath) = 0;

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString csp; */
  NS_IMETHOD GetCsp(nsAString & aCsp) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIApplication, MOZIAPPLICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIAPPLICATION \
  NS_IMETHOD HasPermission(const char * permission, bool *_retval); \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus); \
  NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD GetLocalId(uint32_t *aLocalId); \
  NS_IMETHOD GetBasePath(nsAString & aBasePath); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetCsp(nsAString & aCsp); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIAPPLICATION(_to) \
  NS_IMETHOD HasPermission(const char * permission, bool *_retval) { return _to HasPermission(permission, _retval); } \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) { return _to GetAppStatus(aAppStatus); } \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD GetLocalId(uint32_t *aLocalId) { return _to GetLocalId(aLocalId); } \
  NS_IMETHOD GetBasePath(nsAString & aBasePath) { return _to GetBasePath(aBasePath); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetCsp(nsAString & aCsp) { return _to GetCsp(aCsp); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIAPPLICATION(_to) \
  NS_IMETHOD HasPermission(const char * permission, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPermission(permission, _retval); } \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppStatus(aAppStatus); } \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetLocalId(uint32_t *aLocalId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalId(aLocalId); } \
  NS_IMETHOD GetBasePath(nsAString & aBasePath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBasePath(aBasePath); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetCsp(nsAString & aCsp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCsp(aCsp); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIApplication
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIAPPLICATION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIApplication)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean hasPermission (in string permission); */
NS_IMETHODIMP _MYCLASS_::HasPermission(const char * permission, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short appStatus; */
NS_IMETHODIMP _MYCLASS_::GetAppStatus(uint16_t *aAppStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString id; */
NS_IMETHODIMP _MYCLASS_::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long localId; */
NS_IMETHODIMP _MYCLASS_::GetLocalId(uint32_t *aLocalId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString basePath; */
NS_IMETHODIMP _MYCLASS_::GetBasePath(nsAString & aBasePath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP _MYCLASS_::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString csp; */
NS_IMETHODIMP _MYCLASS_::GetCsp(nsAString & aCsp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIApplication_h__ */
