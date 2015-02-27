/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBlocklistService.idl
 */

#ifndef __gen_nsIBlocklistService_h__
#define __gen_nsIBlocklistService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPluginTag; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIBlocklistService */
#define NS_IBLOCKLISTSERVICE_IID_STR "d463dfbb-89c4-4553-97af-b4fd8854e161"

#define NS_IBLOCKLISTSERVICE_IID \
  {0xd463dfbb, 0x89c4, 0x4553, \
    { 0x97, 0xaf, 0xb4, 0xfd, 0x88, 0x54, 0xe1, 0x61 }}

class NS_NO_VTABLE nsIBlocklistService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBLOCKLISTSERVICE_IID)

  enum {
    STATE_NOT_BLOCKED = 0U,
    STATE_SOFTBLOCKED = 1U,
    STATE_BLOCKED = 2U,
    STATE_OUTDATED = 3U,
    STATE_VULNERABLE_UPDATE_AVAILABLE = 4U,
    STATE_VULNERABLE_NO_UPDATE = 5U
  };

  /* boolean isAddonBlocklisted (in jsval addon, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_IMETHOD IsAddonBlocklisted(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval) = 0;

  /* unsigned long getAddonBlocklistState (in jsval addon, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_IMETHOD GetAddonBlocklistState(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) = 0;

  /* unsigned long getPluginBlocklistState (in nsIPluginTag plugin, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) = 0;

  /* AString getAddonBlocklistURL (in jsval addon, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_IMETHOD GetAddonBlocklistURL(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval) = 0;

  /* AString getPluginBlocklistURL (in nsIPluginTag plugin); */
  NS_IMETHOD GetPluginBlocklistURL(nsIPluginTag *plugin, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBlocklistService, NS_IBLOCKLISTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBLOCKLISTSERVICE \
  NS_IMETHOD IsAddonBlocklisted(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval); \
  NS_IMETHOD GetAddonBlocklistState(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval); \
  NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval); \
  NS_IMETHOD GetAddonBlocklistURL(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval); \
  NS_IMETHOD GetPluginBlocklistURL(nsIPluginTag *plugin, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBLOCKLISTSERVICE(_to) \
  NS_IMETHOD IsAddonBlocklisted(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval) { return _to IsAddonBlocklisted(addon, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetAddonBlocklistState(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) { return _to GetAddonBlocklistState(addon, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) { return _to GetPluginBlocklistState(plugin, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetAddonBlocklistURL(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval) { return _to GetAddonBlocklistURL(addon, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetPluginBlocklistURL(nsIPluginTag *plugin, nsAString & _retval) { return _to GetPluginBlocklistURL(plugin, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBLOCKLISTSERVICE(_to) \
  NS_IMETHOD IsAddonBlocklisted(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAddonBlocklisted(addon, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetAddonBlocklistState(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonBlocklistState(addon, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginBlocklistState(plugin, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetAddonBlocklistURL(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonBlocklistURL(addon, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetPluginBlocklistURL(nsIPluginTag *plugin, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginBlocklistURL(plugin, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBlocklistService : public nsIBlocklistService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBLOCKLISTSERVICE

  nsBlocklistService();

private:
  ~nsBlocklistService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBlocklistService, nsIBlocklistService)

nsBlocklistService::nsBlocklistService()
{
  /* member initializers and constructor code */
}

nsBlocklistService::~nsBlocklistService()
{
  /* destructor code */
}

/* boolean isAddonBlocklisted (in jsval addon, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::IsAddonBlocklisted(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getAddonBlocklistState (in jsval addon, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::GetAddonBlocklistState(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getPluginBlocklistState (in nsIPluginTag plugin, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getAddonBlocklistURL (in jsval addon, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::GetAddonBlocklistURL(JS::HandleValue addon, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getPluginBlocklistURL (in nsIPluginTag plugin); */
NS_IMETHODIMP nsBlocklistService::GetPluginBlocklistURL(nsIPluginTag *plugin, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBlocklistPrompt */
#define NS_IBLOCKLISTPROMPT_IID_STR "ba915921-b9c0-400d-8e4f-ca1b80c5699a"

#define NS_IBLOCKLISTPROMPT_IID \
  {0xba915921, 0xb9c0, 0x400d, \
    { 0x8e, 0x4f, 0xca, 0x1b, 0x80, 0xc5, 0x69, 0x9a }}

class NS_NO_VTABLE nsIBlocklistPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBLOCKLISTPROMPT_IID)

  /* void prompt ([array, size_is (aCount)] in nsIVariant aAddons, [optional] in uint32_t aCount); */
  NS_IMETHOD Prompt(nsIVariant **aAddons, uint32_t aCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBlocklistPrompt, NS_IBLOCKLISTPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBLOCKLISTPROMPT \
  NS_IMETHOD Prompt(nsIVariant **aAddons, uint32_t aCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBLOCKLISTPROMPT(_to) \
  NS_IMETHOD Prompt(nsIVariant **aAddons, uint32_t aCount) { return _to Prompt(aAddons, aCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBLOCKLISTPROMPT(_to) \
  NS_IMETHOD Prompt(nsIVariant **aAddons, uint32_t aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(aAddons, aCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBlocklistPrompt : public nsIBlocklistPrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBLOCKLISTPROMPT

  nsBlocklistPrompt();

private:
  ~nsBlocklistPrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBlocklistPrompt, nsIBlocklistPrompt)

nsBlocklistPrompt::nsBlocklistPrompt()
{
  /* member initializers and constructor code */
}

nsBlocklistPrompt::~nsBlocklistPrompt()
{
  /* destructor code */
}

/* void prompt ([array, size_is (aCount)] in nsIVariant aAddons, [optional] in uint32_t aCount); */
NS_IMETHODIMP nsBlocklistPrompt::Prompt(nsIVariant **aAddons, uint32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBlocklistService_h__ */
