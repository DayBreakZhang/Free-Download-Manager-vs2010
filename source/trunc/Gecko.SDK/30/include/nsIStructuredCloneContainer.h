/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStructuredCloneContainer.idl
 */

#ifndef __gen_nsIStructuredCloneContainer_h__
#define __gen_nsIStructuredCloneContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIDocument; /* forward declaration */

#include "js/TypeDecls.h"

/* starting interface:    nsIStructuredCloneContainer */
#define NS_ISTRUCTUREDCLONECONTAINER_IID_STR "c8852f01-4c05-47c3-acca-253a958f39f6"

#define NS_ISTRUCTUREDCLONECONTAINER_IID \
  {0xc8852f01, 0x4c05, 0x47c3, \
    { 0xac, 0xca, 0x25, 0x3a, 0x95, 0x8f, 0x39, 0xf6 }}

class NS_NO_VTABLE nsIStructuredCloneContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTRUCTUREDCLONECONTAINER_IID)

  /* [implicit_jscontext,noscript] void initFromJSVal (in jsval aData); */
  NS_IMETHOD InitFromJSVal(JS::HandleValue aData, JSContext* cx) = 0;

  /* [implicit_jscontext] void initFromBase64 (in AString aData, in unsigned long aFormatVersion); */
  NS_IMETHOD InitFromBase64(const nsAString & aData, uint32_t aFormatVersion, JSContext* cx) = 0;

  /* [implicit_jscontext] nsIVariant deserializeToVariant (); */
  NS_IMETHOD DeserializeToVariant(JSContext* cx, nsIVariant * *_retval) = 0;

  /* AString getDataAsBase64 (); */
  NS_IMETHOD GetDataAsBase64(nsAString & _retval) = 0;

  /* readonly attribute unsigned long long serializedNBytes; */
  NS_IMETHOD GetSerializedNBytes(uint64_t *aSerializedNBytes) = 0;

  /* readonly attribute unsigned long formatVersion; */
  NS_IMETHOD GetFormatVersion(uint32_t *aFormatVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStructuredCloneContainer, NS_ISTRUCTUREDCLONECONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTRUCTUREDCLONECONTAINER \
  NS_IMETHOD InitFromJSVal(JS::HandleValue aData, JSContext* cx); \
  NS_IMETHOD InitFromBase64(const nsAString & aData, uint32_t aFormatVersion, JSContext* cx); \
  NS_IMETHOD DeserializeToVariant(JSContext* cx, nsIVariant * *_retval); \
  NS_IMETHOD GetDataAsBase64(nsAString & _retval); \
  NS_IMETHOD GetSerializedNBytes(uint64_t *aSerializedNBytes); \
  NS_IMETHOD GetFormatVersion(uint32_t *aFormatVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTRUCTUREDCLONECONTAINER(_to) \
  NS_IMETHOD InitFromJSVal(JS::HandleValue aData, JSContext* cx) { return _to InitFromJSVal(aData, cx); } \
  NS_IMETHOD InitFromBase64(const nsAString & aData, uint32_t aFormatVersion, JSContext* cx) { return _to InitFromBase64(aData, aFormatVersion, cx); } \
  NS_IMETHOD DeserializeToVariant(JSContext* cx, nsIVariant * *_retval) { return _to DeserializeToVariant(cx, _retval); } \
  NS_IMETHOD GetDataAsBase64(nsAString & _retval) { return _to GetDataAsBase64(_retval); } \
  NS_IMETHOD GetSerializedNBytes(uint64_t *aSerializedNBytes) { return _to GetSerializedNBytes(aSerializedNBytes); } \
  NS_IMETHOD GetFormatVersion(uint32_t *aFormatVersion) { return _to GetFormatVersion(aFormatVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTRUCTUREDCLONECONTAINER(_to) \
  NS_IMETHOD InitFromJSVal(JS::HandleValue aData, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitFromJSVal(aData, cx); } \
  NS_IMETHOD InitFromBase64(const nsAString & aData, uint32_t aFormatVersion, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitFromBase64(aData, aFormatVersion, cx); } \
  NS_IMETHOD DeserializeToVariant(JSContext* cx, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeserializeToVariant(cx, _retval); } \
  NS_IMETHOD GetDataAsBase64(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataAsBase64(_retval); } \
  NS_IMETHOD GetSerializedNBytes(uint64_t *aSerializedNBytes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSerializedNBytes(aSerializedNBytes); } \
  NS_IMETHOD GetFormatVersion(uint32_t *aFormatVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormatVersion(aFormatVersion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStructuredCloneContainer : public nsIStructuredCloneContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTRUCTUREDCLONECONTAINER

  nsStructuredCloneContainer();

private:
  ~nsStructuredCloneContainer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStructuredCloneContainer, nsIStructuredCloneContainer)

nsStructuredCloneContainer::nsStructuredCloneContainer()
{
  /* member initializers and constructor code */
}

nsStructuredCloneContainer::~nsStructuredCloneContainer()
{
  /* destructor code */
}

/* [implicit_jscontext,noscript] void initFromJSVal (in jsval aData); */
NS_IMETHODIMP nsStructuredCloneContainer::InitFromJSVal(JS::HandleValue aData, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void initFromBase64 (in AString aData, in unsigned long aFormatVersion); */
NS_IMETHODIMP nsStructuredCloneContainer::InitFromBase64(const nsAString & aData, uint32_t aFormatVersion, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIVariant deserializeToVariant (); */
NS_IMETHODIMP nsStructuredCloneContainer::DeserializeToVariant(JSContext* cx, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getDataAsBase64 (); */
NS_IMETHODIMP nsStructuredCloneContainer::GetDataAsBase64(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long serializedNBytes; */
NS_IMETHODIMP nsStructuredCloneContainer::GetSerializedNBytes(uint64_t *aSerializedNBytes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long formatVersion; */
NS_IMETHODIMP nsStructuredCloneContainer::GetFormatVersion(uint32_t *aFormatVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStructuredCloneContainer_h__ */
