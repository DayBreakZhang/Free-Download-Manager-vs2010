/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPluginTag.idl
 */

#ifndef __gen_nsIPluginTag_h__
#define __gen_nsIPluginTag_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPluginTag */
#define NS_IPLUGINTAG_IID_STR "0e56f04d-cda4-4a55-ab83-e5e29ddd370e"

#define NS_IPLUGINTAG_IID \
  {0x0e56f04d, 0xcda4, 0x4a55, \
    { 0xab, 0x83, 0xe5, 0xe2, 0x9d, 0xdd, 0x37, 0x0e }}

class NS_NO_VTABLE nsIPluginTag : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINTAG_IID)

  enum {
    STATE_DISABLED = 0U,
    STATE_CLICKTOPLAY = 1U,
    STATE_ENABLED = 2U
  };

  /* readonly attribute AUTF8String description; */
  NS_IMETHOD GetDescription(nsACString & aDescription) = 0;

  /* readonly attribute AUTF8String filename; */
  NS_IMETHOD GetFilename(nsACString & aFilename) = 0;

  /* readonly attribute AUTF8String fullpath; */
  NS_IMETHOD GetFullpath(nsACString & aFullpath) = 0;

  /* readonly attribute AUTF8String version; */
  NS_IMETHOD GetVersion(nsACString & aVersion) = 0;

  /* readonly attribute AUTF8String name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute boolean blocklisted; */
  NS_IMETHOD GetBlocklisted(bool *aBlocklisted) = 0;

  /* readonly attribute boolean disabled; */
  NS_IMETHOD GetDisabled(bool *aDisabled) = 0;

  /* readonly attribute boolean clicktoplay; */
  NS_IMETHOD GetClicktoplay(bool *aClicktoplay) = 0;

  /* attribute unsigned long enabledState; */
  NS_IMETHOD GetEnabledState(uint32_t *aEnabledState) = 0;
  NS_IMETHOD SetEnabledState(uint32_t aEnabledState) = 0;

  /* readonly attribute PRTime lastModifiedTime; */
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) = 0;

  /* void getMimeTypes ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out wstring aResults); */
  NS_IMETHOD GetMimeTypes(uint32_t *aCount, char16_t * **aResults) = 0;

  /* void getMimeDescriptions ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out wstring aResults); */
  NS_IMETHOD GetMimeDescriptions(uint32_t *aCount, char16_t * **aResults) = 0;

  /* void getExtensions ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out wstring aResults); */
  NS_IMETHOD GetExtensions(uint32_t *aCount, char16_t * **aResults) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginTag, NS_IPLUGINTAG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINTAG \
  NS_IMETHOD GetDescription(nsACString & aDescription); \
  NS_IMETHOD GetFilename(nsACString & aFilename); \
  NS_IMETHOD GetFullpath(nsACString & aFullpath); \
  NS_IMETHOD GetVersion(nsACString & aVersion); \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD GetBlocklisted(bool *aBlocklisted); \
  NS_IMETHOD GetDisabled(bool *aDisabled); \
  NS_IMETHOD GetClicktoplay(bool *aClicktoplay); \
  NS_IMETHOD GetEnabledState(uint32_t *aEnabledState); \
  NS_IMETHOD SetEnabledState(uint32_t aEnabledState); \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime); \
  NS_IMETHOD GetMimeTypes(uint32_t *aCount, char16_t * **aResults); \
  NS_IMETHOD GetMimeDescriptions(uint32_t *aCount, char16_t * **aResults); \
  NS_IMETHOD GetExtensions(uint32_t *aCount, char16_t * **aResults); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINTAG(_to) \
  NS_IMETHOD GetDescription(nsACString & aDescription) { return _to GetDescription(aDescription); } \
  NS_IMETHOD GetFilename(nsACString & aFilename) { return _to GetFilename(aFilename); } \
  NS_IMETHOD GetFullpath(nsACString & aFullpath) { return _to GetFullpath(aFullpath); } \
  NS_IMETHOD GetVersion(nsACString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetBlocklisted(bool *aBlocklisted) { return _to GetBlocklisted(aBlocklisted); } \
  NS_IMETHOD GetDisabled(bool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_IMETHOD GetClicktoplay(bool *aClicktoplay) { return _to GetClicktoplay(aClicktoplay); } \
  NS_IMETHOD GetEnabledState(uint32_t *aEnabledState) { return _to GetEnabledState(aEnabledState); } \
  NS_IMETHOD SetEnabledState(uint32_t aEnabledState) { return _to SetEnabledState(aEnabledState); } \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return _to GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD GetMimeTypes(uint32_t *aCount, char16_t * **aResults) { return _to GetMimeTypes(aCount, aResults); } \
  NS_IMETHOD GetMimeDescriptions(uint32_t *aCount, char16_t * **aResults) { return _to GetMimeDescriptions(aCount, aResults); } \
  NS_IMETHOD GetExtensions(uint32_t *aCount, char16_t * **aResults) { return _to GetExtensions(aCount, aResults); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINTAG(_to) \
  NS_IMETHOD GetDescription(nsACString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_IMETHOD GetFilename(nsACString & aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_IMETHOD GetFullpath(nsACString & aFullpath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullpath(aFullpath); } \
  NS_IMETHOD GetVersion(nsACString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetBlocklisted(bool *aBlocklisted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlocklisted(aBlocklisted); } \
  NS_IMETHOD GetDisabled(bool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_IMETHOD GetClicktoplay(bool *aClicktoplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClicktoplay(aClicktoplay); } \
  NS_IMETHOD GetEnabledState(uint32_t *aEnabledState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnabledState(aEnabledState); } \
  NS_IMETHOD SetEnabledState(uint32_t aEnabledState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnabledState(aEnabledState); } \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD GetMimeTypes(uint32_t *aCount, char16_t * **aResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeTypes(aCount, aResults); } \
  NS_IMETHOD GetMimeDescriptions(uint32_t *aCount, char16_t * **aResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeDescriptions(aCount, aResults); } \
  NS_IMETHOD GetExtensions(uint32_t *aCount, char16_t * **aResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtensions(aCount, aResults); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginTag : public nsIPluginTag
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINTAG

  nsPluginTag();

private:
  ~nsPluginTag();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginTag, nsIPluginTag)

nsPluginTag::nsPluginTag()
{
  /* member initializers and constructor code */
}

nsPluginTag::~nsPluginTag()
{
  /* destructor code */
}

/* readonly attribute AUTF8String description; */
NS_IMETHODIMP nsPluginTag::GetDescription(nsACString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String filename; */
NS_IMETHODIMP nsPluginTag::GetFilename(nsACString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String fullpath; */
NS_IMETHODIMP nsPluginTag::GetFullpath(nsACString & aFullpath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String version; */
NS_IMETHODIMP nsPluginTag::GetVersion(nsACString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsPluginTag::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean blocklisted; */
NS_IMETHODIMP nsPluginTag::GetBlocklisted(bool *aBlocklisted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean disabled; */
NS_IMETHODIMP nsPluginTag::GetDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean clicktoplay; */
NS_IMETHODIMP nsPluginTag::GetClicktoplay(bool *aClicktoplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long enabledState; */
NS_IMETHODIMP nsPluginTag::GetEnabledState(uint32_t *aEnabledState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPluginTag::SetEnabledState(uint32_t aEnabledState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModifiedTime; */
NS_IMETHODIMP nsPluginTag::GetLastModifiedTime(PRTime *aLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMimeTypes ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out wstring aResults); */
NS_IMETHODIMP nsPluginTag::GetMimeTypes(uint32_t *aCount, char16_t * **aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMimeDescriptions ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out wstring aResults); */
NS_IMETHODIMP nsPluginTag::GetMimeDescriptions(uint32_t *aCount, char16_t * **aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getExtensions ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out wstring aResults); */
NS_IMETHODIMP nsPluginTag::GetExtensions(uint32_t *aCount, char16_t * **aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginTag_h__ */
