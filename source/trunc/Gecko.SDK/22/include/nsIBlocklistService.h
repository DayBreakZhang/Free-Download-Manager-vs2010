/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/system/nsIBlocklistService.idl
 */

#ifndef __gen_nsIBlocklistService_h__
#define __gen_nsIBlocklistService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPluginTag; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIBlocklistService */
#define NS_IBLOCKLISTSERVICE_IID_STR "cbba15b8-316d-4ae6-8ed9-fe9cf8386730"

#define NS_IBLOCKLISTSERVICE_IID \
  {0xcbba15b8, 0x316d, 0x4ae6, \
    { 0x8e, 0xd9, 0xfe, 0x9c, 0xf8, 0x38, 0x67, 0x30 }}

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

  /* boolean isAddonBlocklisted (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_IMETHOD IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval) = 0;

  /* unsigned long getAddonBlocklistState (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_IMETHOD GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) = 0;

  /* unsigned long getPluginBlocklistState (in nsIPluginTag plugin, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) = 0;

  /* AString getAddonBlocklistURL (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_IMETHOD GetAddonBlocklistURL(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval) = 0;

  /* AString getPluginBlocklistURL (in nsIPluginTag plugin); */
  NS_IMETHOD GetPluginBlocklistURL(nsIPluginTag *plugin, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBlocklistService, NS_IBLOCKLISTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBLOCKLISTSERVICE \
  NS_IMETHOD IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval); \
  NS_IMETHOD GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval); \
  NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval); \
  NS_IMETHOD GetAddonBlocklistURL(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval); \
  NS_IMETHOD GetPluginBlocklistURL(nsIPluginTag *plugin, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBLOCKLISTSERVICE(_to) \
  NS_IMETHOD IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval) { return _to IsAddonBlocklisted(id, version, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) { return _to GetAddonBlocklistState(id, version, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) { return _to GetPluginBlocklistState(plugin, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetAddonBlocklistURL(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval) { return _to GetAddonBlocklistURL(id, version, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetPluginBlocklistURL(nsIPluginTag *plugin, nsAString & _retval) { return _to GetPluginBlocklistURL(plugin, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBLOCKLISTSERVICE(_to) \
  NS_IMETHOD IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAddonBlocklisted(id, version, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonBlocklistState(id, version, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginBlocklistState(plugin, appVersion, toolkitVersion, _retval); } \
  NS_IMETHOD GetAddonBlocklistURL(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonBlocklistURL(id, version, appVersion, toolkitVersion, _retval); } \
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

/* boolean isAddonBlocklisted (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getAddonBlocklistState (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getPluginBlocklistState (in nsIPluginTag plugin, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getAddonBlocklistURL (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::GetAddonBlocklistURL(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, nsAString & _retval)
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
#define NS_IBLOCKLISTPROMPT_IID_STR "36f97f40-b0c9-11df-94e2-0800200c9a66"

#define NS_IBLOCKLISTPROMPT_IID \
  {0x36f97f40, 0xb0c9, 0x11df, \
    { 0x94, 0xe2, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

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
