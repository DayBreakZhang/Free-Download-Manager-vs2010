/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISynthVoiceRegistry.idl
 */

#ifndef __gen_nsISynthVoiceRegistry_h__
#define __gen_nsISynthVoiceRegistry_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISpeechService; /* forward declaration */


/* starting interface:    nsISynthVoiceRegistry */
#define NS_ISYNTHVOICEREGISTRY_IID_STR "53dcc868-4193-4c3c-a1d9-fe5a0a6af2fb"

#define NS_ISYNTHVOICEREGISTRY_IID \
  {0x53dcc868, 0x4193, 0x4c3c, \
    { 0xa1, 0xd9, 0xfe, 0x5a, 0x0a, 0x6a, 0xf2, 0xfb }}

class NS_NO_VTABLE nsISynthVoiceRegistry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYNTHVOICEREGISTRY_IID)

  /* void addVoice (in nsISpeechService aService, in DOMString aUri, in DOMString aName, in DOMString aLang, in boolean aLocalService); */
  NS_IMETHOD AddVoice(nsISpeechService *aService, const nsAString & aUri, const nsAString & aName, const nsAString & aLang, bool aLocalService) = 0;

  /* void removeVoice (in nsISpeechService aService, in DOMString aUri); */
  NS_IMETHOD RemoveVoice(nsISpeechService *aService, const nsAString & aUri) = 0;

  /* void setDefaultVoice (in DOMString aUri, in boolean aIsDefault); */
  NS_IMETHOD SetDefaultVoice(const nsAString & aUri, bool aIsDefault) = 0;

  /* readonly attribute uint32_t voiceCount; */
  NS_IMETHOD GetVoiceCount(uint32_t *aVoiceCount) = 0;

  /* AString getVoice (in uint32_t aIndex); */
  NS_IMETHOD GetVoice(uint32_t aIndex, nsAString & _retval) = 0;

  /* bool isDefaultVoice (in DOMString aUri); */
  NS_IMETHOD IsDefaultVoice(const nsAString & aUri, bool *_retval) = 0;

  /* bool isLocalVoice (in DOMString aUri); */
  NS_IMETHOD IsLocalVoice(const nsAString & aUri, bool *_retval) = 0;

  /* AString getVoiceLang (in DOMString aUri); */
  NS_IMETHOD GetVoiceLang(const nsAString & aUri, nsAString & _retval) = 0;

  /* AString getVoiceName (in DOMString aUri); */
  NS_IMETHOD GetVoiceName(const nsAString & aUri, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISynthVoiceRegistry, NS_ISYNTHVOICEREGISTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYNTHVOICEREGISTRY \
  NS_IMETHOD AddVoice(nsISpeechService *aService, const nsAString & aUri, const nsAString & aName, const nsAString & aLang, bool aLocalService); \
  NS_IMETHOD RemoveVoice(nsISpeechService *aService, const nsAString & aUri); \
  NS_IMETHOD SetDefaultVoice(const nsAString & aUri, bool aIsDefault); \
  NS_IMETHOD GetVoiceCount(uint32_t *aVoiceCount); \
  NS_IMETHOD GetVoice(uint32_t aIndex, nsAString & _retval); \
  NS_IMETHOD IsDefaultVoice(const nsAString & aUri, bool *_retval); \
  NS_IMETHOD IsLocalVoice(const nsAString & aUri, bool *_retval); \
  NS_IMETHOD GetVoiceLang(const nsAString & aUri, nsAString & _retval); \
  NS_IMETHOD GetVoiceName(const nsAString & aUri, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYNTHVOICEREGISTRY(_to) \
  NS_IMETHOD AddVoice(nsISpeechService *aService, const nsAString & aUri, const nsAString & aName, const nsAString & aLang, bool aLocalService) { return _to AddVoice(aService, aUri, aName, aLang, aLocalService); } \
  NS_IMETHOD RemoveVoice(nsISpeechService *aService, const nsAString & aUri) { return _to RemoveVoice(aService, aUri); } \
  NS_IMETHOD SetDefaultVoice(const nsAString & aUri, bool aIsDefault) { return _to SetDefaultVoice(aUri, aIsDefault); } \
  NS_IMETHOD GetVoiceCount(uint32_t *aVoiceCount) { return _to GetVoiceCount(aVoiceCount); } \
  NS_IMETHOD GetVoice(uint32_t aIndex, nsAString & _retval) { return _to GetVoice(aIndex, _retval); } \
  NS_IMETHOD IsDefaultVoice(const nsAString & aUri, bool *_retval) { return _to IsDefaultVoice(aUri, _retval); } \
  NS_IMETHOD IsLocalVoice(const nsAString & aUri, bool *_retval) { return _to IsLocalVoice(aUri, _retval); } \
  NS_IMETHOD GetVoiceLang(const nsAString & aUri, nsAString & _retval) { return _to GetVoiceLang(aUri, _retval); } \
  NS_IMETHOD GetVoiceName(const nsAString & aUri, nsAString & _retval) { return _to GetVoiceName(aUri, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYNTHVOICEREGISTRY(_to) \
  NS_IMETHOD AddVoice(nsISpeechService *aService, const nsAString & aUri, const nsAString & aName, const nsAString & aLang, bool aLocalService) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddVoice(aService, aUri, aName, aLang, aLocalService); } \
  NS_IMETHOD RemoveVoice(nsISpeechService *aService, const nsAString & aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveVoice(aService, aUri); } \
  NS_IMETHOD SetDefaultVoice(const nsAString & aUri, bool aIsDefault) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultVoice(aUri, aIsDefault); } \
  NS_IMETHOD GetVoiceCount(uint32_t *aVoiceCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVoiceCount(aVoiceCount); } \
  NS_IMETHOD GetVoice(uint32_t aIndex, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVoice(aIndex, _retval); } \
  NS_IMETHOD IsDefaultVoice(const nsAString & aUri, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDefaultVoice(aUri, _retval); } \
  NS_IMETHOD IsLocalVoice(const nsAString & aUri, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLocalVoice(aUri, _retval); } \
  NS_IMETHOD GetVoiceLang(const nsAString & aUri, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVoiceLang(aUri, _retval); } \
  NS_IMETHOD GetVoiceName(const nsAString & aUri, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVoiceName(aUri, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSynthVoiceRegistry : public nsISynthVoiceRegistry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYNTHVOICEREGISTRY

  nsSynthVoiceRegistry();

private:
  ~nsSynthVoiceRegistry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSynthVoiceRegistry, nsISynthVoiceRegistry)

nsSynthVoiceRegistry::nsSynthVoiceRegistry()
{
  /* member initializers and constructor code */
}

nsSynthVoiceRegistry::~nsSynthVoiceRegistry()
{
  /* destructor code */
}

/* void addVoice (in nsISpeechService aService, in DOMString aUri, in DOMString aName, in DOMString aLang, in boolean aLocalService); */
NS_IMETHODIMP nsSynthVoiceRegistry::AddVoice(nsISpeechService *aService, const nsAString & aUri, const nsAString & aName, const nsAString & aLang, bool aLocalService)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeVoice (in nsISpeechService aService, in DOMString aUri); */
NS_IMETHODIMP nsSynthVoiceRegistry::RemoveVoice(nsISpeechService *aService, const nsAString & aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDefaultVoice (in DOMString aUri, in boolean aIsDefault); */
NS_IMETHODIMP nsSynthVoiceRegistry::SetDefaultVoice(const nsAString & aUri, bool aIsDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t voiceCount; */
NS_IMETHODIMP nsSynthVoiceRegistry::GetVoiceCount(uint32_t *aVoiceCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getVoice (in uint32_t aIndex); */
NS_IMETHODIMP nsSynthVoiceRegistry::GetVoice(uint32_t aIndex, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isDefaultVoice (in DOMString aUri); */
NS_IMETHODIMP nsSynthVoiceRegistry::IsDefaultVoice(const nsAString & aUri, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isLocalVoice (in DOMString aUri); */
NS_IMETHODIMP nsSynthVoiceRegistry::IsLocalVoice(const nsAString & aUri, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getVoiceLang (in DOMString aUri); */
NS_IMETHODIMP nsSynthVoiceRegistry::GetVoiceLang(const nsAString & aUri, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getVoiceName (in DOMString aUri); */
NS_IMETHODIMP nsSynthVoiceRegistry::GetVoiceName(const nsAString & aUri, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SYNTHVOICEREGISTRY_CID                   \
  { /* {7090524d-5574-4492-a77f-d8d558ced59d} */       \
    0x7090524d,                                        \
    0x5574,                                            \
    0x4492,                                            \
    { 0xa7, 0x7f, 0xd8, 0xd5, 0x58, 0xce, 0xd5, 0x9d } \
  }
#define NS_SYNTHVOICEREGISTRY_CONTRACTID \
    "@mozilla.org/synth-voice-registry;1"
#define NS_SYNTHVOICEREGISTRY_CLASSNAME \
    "Speech Synthesis Voice Registry"

#endif /* __gen_nsISynthVoiceRegistry_h__ */
