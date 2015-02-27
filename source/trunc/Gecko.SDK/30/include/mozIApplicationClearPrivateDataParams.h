/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIApplicationClearPrivateDataParams.idl
 */

#ifndef __gen_mozIApplicationClearPrivateDataParams_h__
#define __gen_mozIApplicationClearPrivateDataParams_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIApplicationClearPrivateDataParams */
#define MOZIAPPLICATIONCLEARPRIVATEDATAPARAMS_IID_STR "ba0e6c8e-8c03-4b9b-8f9b-4fb14216f56e"

#define MOZIAPPLICATIONCLEARPRIVATEDATAPARAMS_IID \
  {0xba0e6c8e, 0x8c03, 0x4b9b, \
    { 0x8f, 0x9b, 0x4f, 0xb1, 0x42, 0x16, 0xf5, 0x6e }}

class NS_NO_VTABLE mozIApplicationClearPrivateDataParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIAPPLICATIONCLEARPRIVATEDATAPARAMS_IID)

  /* readonly attribute unsigned long appId; */
  NS_IMETHOD GetAppId(uint32_t *aAppId) = 0;

  /* readonly attribute boolean browserOnly; */
  NS_IMETHOD GetBrowserOnly(bool *aBrowserOnly) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIApplicationClearPrivateDataParams, MOZIAPPLICATIONCLEARPRIVATEDATAPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIAPPLICATIONCLEARPRIVATEDATAPARAMS \
  NS_IMETHOD GetAppId(uint32_t *aAppId); \
  NS_IMETHOD GetBrowserOnly(bool *aBrowserOnly); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIAPPLICATIONCLEARPRIVATEDATAPARAMS(_to) \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return _to GetAppId(aAppId); } \
  NS_IMETHOD GetBrowserOnly(bool *aBrowserOnly) { return _to GetBrowserOnly(aBrowserOnly); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIAPPLICATIONCLEARPRIVATEDATAPARAMS(_to) \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppId(aAppId); } \
  NS_IMETHOD GetBrowserOnly(bool *aBrowserOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBrowserOnly(aBrowserOnly); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIApplicationClearPrivateDataParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIAPPLICATIONCLEARPRIVATEDATAPARAMS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIApplicationClearPrivateDataParams)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute unsigned long appId; */
NS_IMETHODIMP _MYCLASS_::GetAppId(uint32_t *aAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean browserOnly; */
NS_IMETHODIMP _MYCLASS_::GetBrowserOnly(bool *aBrowserOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define TOPIC_WEB_APP_CLEAR_DATA "webapps-clear-data"

#endif /* __gen_mozIApplicationClearPrivateDataParams_h__ */
