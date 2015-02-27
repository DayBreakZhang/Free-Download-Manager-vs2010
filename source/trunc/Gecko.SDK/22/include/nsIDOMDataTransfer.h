/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMDataTransfer.idl
 */

#ifndef __gen_nsIDOMDataTransfer_h__
#define __gen_nsIDOMDataTransfer_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIDOMFileList; /* forward declaration */


/* starting interface:    nsIDOMDataTransfer */
#define NS_IDOMDATATRANSFER_IID_STR "7d73cfbf-ec30-4f8e-b6a4-bb31eb943580"

#define NS_IDOMDATATRANSFER_IID \
  {0x7d73cfbf, 0xec30, 0x4f8e, \
    { 0xb6, 0xa4, 0xbb, 0x31, 0xeb, 0x94, 0x35, 0x80 }}

class NS_NO_VTABLE nsIDOMDataTransfer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDATATRANSFER_IID)

  /* attribute DOMString dropEffect; */
  NS_IMETHOD GetDropEffect(nsAString & aDropEffect) = 0;
  NS_IMETHOD SetDropEffect(const nsAString & aDropEffect) = 0;

  /* attribute DOMString effectAllowed; */
  NS_IMETHOD GetEffectAllowed(nsAString & aEffectAllowed) = 0;
  NS_IMETHOD SetEffectAllowed(const nsAString & aEffectAllowed) = 0;

  /* readonly attribute nsIDOMFileList files; */
  NS_IMETHOD GetFiles(nsIDOMFileList * *aFiles) = 0;

  /* readonly attribute nsIDOMDOMStringList types; */
  NS_IMETHOD GetTypes(nsIDOMDOMStringList * *aTypes) = 0;

  /* void clearData ([optional] in DOMString format); */
  NS_IMETHOD ClearData(const nsAString & format) = 0;

  /* void setData (in DOMString format, in DOMString data); */
  NS_IMETHOD SetData(const nsAString & format, const nsAString & data) = 0;

  /* DOMString getData (in DOMString format); */
  NS_IMETHOD GetData(const nsAString & format, nsAString & _retval) = 0;

  /* void setDragImage (in nsIDOMElement image, in long x, in long y); */
  NS_IMETHOD SetDragImage(nsIDOMElement *image, int32_t x, int32_t y) = 0;

  /* void addElement (in nsIDOMElement element); */
  NS_IMETHOD AddElement(nsIDOMElement *element) = 0;

  /* readonly attribute unsigned long mozItemCount; */
  NS_IMETHOD GetMozItemCount(uint32_t *aMozItemCount) = 0;

  /* attribute DOMString mozCursor; */
  NS_IMETHOD GetMozCursor(nsAString & aMozCursor) = 0;
  NS_IMETHOD SetMozCursor(const nsAString & aMozCursor) = 0;

  /* nsIDOMDOMStringList mozTypesAt (in unsigned long index); */
  NS_IMETHOD MozTypesAt(uint32_t index, nsIDOMDOMStringList * *_retval) = 0;

  /* void mozClearDataAt (in DOMString format, in unsigned long index); */
  NS_IMETHOD MozClearDataAt(const nsAString & format, uint32_t index) = 0;

  /* void mozSetDataAt (in DOMString format, in nsIVariant data, in unsigned long index); */
  NS_IMETHOD MozSetDataAt(const nsAString & format, nsIVariant *data, uint32_t index) = 0;

  /* nsIVariant mozGetDataAt (in DOMString format, in unsigned long index); */
  NS_IMETHOD MozGetDataAt(const nsAString & format, uint32_t index, nsIVariant * *_retval) = 0;

  /* readonly attribute boolean mozUserCancelled; */
  NS_IMETHOD GetMozUserCancelled(bool *aMozUserCancelled) = 0;

  /* readonly attribute nsIDOMNode mozSourceNode; */
  NS_IMETHOD GetMozSourceNode(nsIDOMNode * *aMozSourceNode) = 0;

  /* [noscript] attribute unsigned long dropEffectInt; */
  NS_IMETHOD GetDropEffectInt(uint32_t *aDropEffectInt) = 0;
  NS_IMETHOD SetDropEffectInt(uint32_t aDropEffectInt) = 0;

  /* [noscript] attribute unsigned long effectAllowedInt; */
  NS_IMETHOD GetEffectAllowedInt(uint32_t *aEffectAllowedInt) = 0;
  NS_IMETHOD SetEffectAllowedInt(uint32_t aEffectAllowedInt) = 0;

  /* [noscript] nsIDOMDataTransfer clone (in uint32_t aEventType, in boolean aUserCancelled, in boolean isCrossDomainSubFrameDrop); */
  NS_IMETHOD Clone(uint32_t aEventType, bool aUserCancelled, bool isCrossDomainSubFrameDrop, nsIDOMDataTransfer * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDataTransfer, NS_IDOMDATATRANSFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDATATRANSFER \
  NS_IMETHOD GetDropEffect(nsAString & aDropEffect); \
  NS_IMETHOD SetDropEffect(const nsAString & aDropEffect); \
  NS_IMETHOD GetEffectAllowed(nsAString & aEffectAllowed); \
  NS_IMETHOD SetEffectAllowed(const nsAString & aEffectAllowed); \
  NS_IMETHOD GetFiles(nsIDOMFileList * *aFiles); \
  NS_IMETHOD GetTypes(nsIDOMDOMStringList * *aTypes); \
  NS_IMETHOD ClearData(const nsAString & format); \
  NS_IMETHOD SetData(const nsAString & format, const nsAString & data); \
  NS_IMETHOD GetData(const nsAString & format, nsAString & _retval); \
  NS_IMETHOD SetDragImage(nsIDOMElement *image, int32_t x, int32_t y); \
  NS_IMETHOD AddElement(nsIDOMElement *element); \
  NS_IMETHOD GetMozItemCount(uint32_t *aMozItemCount); \
  NS_IMETHOD GetMozCursor(nsAString & aMozCursor); \
  NS_IMETHOD SetMozCursor(const nsAString & aMozCursor); \
  NS_IMETHOD MozTypesAt(uint32_t index, nsIDOMDOMStringList * *_retval); \
  NS_IMETHOD MozClearDataAt(const nsAString & format, uint32_t index); \
  NS_IMETHOD MozSetDataAt(const nsAString & format, nsIVariant *data, uint32_t index); \
  NS_IMETHOD MozGetDataAt(const nsAString & format, uint32_t index, nsIVariant * *_retval); \
  NS_IMETHOD GetMozUserCancelled(bool *aMozUserCancelled); \
  NS_IMETHOD GetMozSourceNode(nsIDOMNode * *aMozSourceNode); \
  NS_IMETHOD GetDropEffectInt(uint32_t *aDropEffectInt); \
  NS_IMETHOD SetDropEffectInt(uint32_t aDropEffectInt); \
  NS_IMETHOD GetEffectAllowedInt(uint32_t *aEffectAllowedInt); \
  NS_IMETHOD SetEffectAllowedInt(uint32_t aEffectAllowedInt); \
  NS_IMETHOD Clone(uint32_t aEventType, bool aUserCancelled, bool isCrossDomainSubFrameDrop, nsIDOMDataTransfer * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDATATRANSFER(_to) \
  NS_IMETHOD GetDropEffect(nsAString & aDropEffect) { return _to GetDropEffect(aDropEffect); } \
  NS_IMETHOD SetDropEffect(const nsAString & aDropEffect) { return _to SetDropEffect(aDropEffect); } \
  NS_IMETHOD GetEffectAllowed(nsAString & aEffectAllowed) { return _to GetEffectAllowed(aEffectAllowed); } \
  NS_IMETHOD SetEffectAllowed(const nsAString & aEffectAllowed) { return _to SetEffectAllowed(aEffectAllowed); } \
  NS_IMETHOD GetFiles(nsIDOMFileList * *aFiles) { return _to GetFiles(aFiles); } \
  NS_IMETHOD GetTypes(nsIDOMDOMStringList * *aTypes) { return _to GetTypes(aTypes); } \
  NS_IMETHOD ClearData(const nsAString & format) { return _to ClearData(format); } \
  NS_IMETHOD SetData(const nsAString & format, const nsAString & data) { return _to SetData(format, data); } \
  NS_IMETHOD GetData(const nsAString & format, nsAString & _retval) { return _to GetData(format, _retval); } \
  NS_IMETHOD SetDragImage(nsIDOMElement *image, int32_t x, int32_t y) { return _to SetDragImage(image, x, y); } \
  NS_IMETHOD AddElement(nsIDOMElement *element) { return _to AddElement(element); } \
  NS_IMETHOD GetMozItemCount(uint32_t *aMozItemCount) { return _to GetMozItemCount(aMozItemCount); } \
  NS_IMETHOD GetMozCursor(nsAString & aMozCursor) { return _to GetMozCursor(aMozCursor); } \
  NS_IMETHOD SetMozCursor(const nsAString & aMozCursor) { return _to SetMozCursor(aMozCursor); } \
  NS_IMETHOD MozTypesAt(uint32_t index, nsIDOMDOMStringList * *_retval) { return _to MozTypesAt(index, _retval); } \
  NS_IMETHOD MozClearDataAt(const nsAString & format, uint32_t index) { return _to MozClearDataAt(format, index); } \
  NS_IMETHOD MozSetDataAt(const nsAString & format, nsIVariant *data, uint32_t index) { return _to MozSetDataAt(format, data, index); } \
  NS_IMETHOD MozGetDataAt(const nsAString & format, uint32_t index, nsIVariant * *_retval) { return _to MozGetDataAt(format, index, _retval); } \
  NS_IMETHOD GetMozUserCancelled(bool *aMozUserCancelled) { return _to GetMozUserCancelled(aMozUserCancelled); } \
  NS_IMETHOD GetMozSourceNode(nsIDOMNode * *aMozSourceNode) { return _to GetMozSourceNode(aMozSourceNode); } \
  NS_IMETHOD GetDropEffectInt(uint32_t *aDropEffectInt) { return _to GetDropEffectInt(aDropEffectInt); } \
  NS_IMETHOD SetDropEffectInt(uint32_t aDropEffectInt) { return _to SetDropEffectInt(aDropEffectInt); } \
  NS_IMETHOD GetEffectAllowedInt(uint32_t *aEffectAllowedInt) { return _to GetEffectAllowedInt(aEffectAllowedInt); } \
  NS_IMETHOD SetEffectAllowedInt(uint32_t aEffectAllowedInt) { return _to SetEffectAllowedInt(aEffectAllowedInt); } \
  NS_IMETHOD Clone(uint32_t aEventType, bool aUserCancelled, bool isCrossDomainSubFrameDrop, nsIDOMDataTransfer * *_retval) { return _to Clone(aEventType, aUserCancelled, isCrossDomainSubFrameDrop, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDATATRANSFER(_to) \
  NS_IMETHOD GetDropEffect(nsAString & aDropEffect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDropEffect(aDropEffect); } \
  NS_IMETHOD SetDropEffect(const nsAString & aDropEffect) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDropEffect(aDropEffect); } \
  NS_IMETHOD GetEffectAllowed(nsAString & aEffectAllowed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffectAllowed(aEffectAllowed); } \
  NS_IMETHOD SetEffectAllowed(const nsAString & aEffectAllowed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEffectAllowed(aEffectAllowed); } \
  NS_IMETHOD GetFiles(nsIDOMFileList * *aFiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFiles(aFiles); } \
  NS_IMETHOD GetTypes(nsIDOMDOMStringList * *aTypes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypes(aTypes); } \
  NS_IMETHOD ClearData(const nsAString & format) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearData(format); } \
  NS_IMETHOD SetData(const nsAString & format, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(format, data); } \
  NS_IMETHOD GetData(const nsAString & format, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(format, _retval); } \
  NS_IMETHOD SetDragImage(nsIDOMElement *image, int32_t x, int32_t y) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDragImage(image, x, y); } \
  NS_IMETHOD AddElement(nsIDOMElement *element) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddElement(element); } \
  NS_IMETHOD GetMozItemCount(uint32_t *aMozItemCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozItemCount(aMozItemCount); } \
  NS_IMETHOD GetMozCursor(nsAString & aMozCursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozCursor(aMozCursor); } \
  NS_IMETHOD SetMozCursor(const nsAString & aMozCursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozCursor(aMozCursor); } \
  NS_IMETHOD MozTypesAt(uint32_t index, nsIDOMDOMStringList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozTypesAt(index, _retval); } \
  NS_IMETHOD MozClearDataAt(const nsAString & format, uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozClearDataAt(format, index); } \
  NS_IMETHOD MozSetDataAt(const nsAString & format, nsIVariant *data, uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetDataAt(format, data, index); } \
  NS_IMETHOD MozGetDataAt(const nsAString & format, uint32_t index, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetDataAt(format, index, _retval); } \
  NS_IMETHOD GetMozUserCancelled(bool *aMozUserCancelled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozUserCancelled(aMozUserCancelled); } \
  NS_IMETHOD GetMozSourceNode(nsIDOMNode * *aMozSourceNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozSourceNode(aMozSourceNode); } \
  NS_IMETHOD GetDropEffectInt(uint32_t *aDropEffectInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDropEffectInt(aDropEffectInt); } \
  NS_IMETHOD SetDropEffectInt(uint32_t aDropEffectInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDropEffectInt(aDropEffectInt); } \
  NS_IMETHOD GetEffectAllowedInt(uint32_t *aEffectAllowedInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffectAllowedInt(aEffectAllowedInt); } \
  NS_IMETHOD SetEffectAllowedInt(uint32_t aEffectAllowedInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEffectAllowedInt(aEffectAllowedInt); } \
  NS_IMETHOD Clone(uint32_t aEventType, bool aUserCancelled, bool isCrossDomainSubFrameDrop, nsIDOMDataTransfer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(aEventType, aUserCancelled, isCrossDomainSubFrameDrop, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDataTransfer : public nsIDOMDataTransfer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDATATRANSFER

  nsDOMDataTransfer();

private:
  ~nsDOMDataTransfer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDataTransfer, nsIDOMDataTransfer)

nsDOMDataTransfer::nsDOMDataTransfer()
{
  /* member initializers and constructor code */
}

nsDOMDataTransfer::~nsDOMDataTransfer()
{
  /* destructor code */
}

/* attribute DOMString dropEffect; */
NS_IMETHODIMP nsDOMDataTransfer::GetDropEffect(nsAString & aDropEffect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataTransfer::SetDropEffect(const nsAString & aDropEffect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString effectAllowed; */
NS_IMETHODIMP nsDOMDataTransfer::GetEffectAllowed(nsAString & aEffectAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataTransfer::SetEffectAllowed(const nsAString & aEffectAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMFileList files; */
NS_IMETHODIMP nsDOMDataTransfer::GetFiles(nsIDOMFileList * *aFiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList types; */
NS_IMETHODIMP nsDOMDataTransfer::GetTypes(nsIDOMDOMStringList * *aTypes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearData ([optional] in DOMString format); */
NS_IMETHODIMP nsDOMDataTransfer::ClearData(const nsAString & format)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setData (in DOMString format, in DOMString data); */
NS_IMETHODIMP nsDOMDataTransfer::SetData(const nsAString & format, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getData (in DOMString format); */
NS_IMETHODIMP nsDOMDataTransfer::GetData(const nsAString & format, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDragImage (in nsIDOMElement image, in long x, in long y); */
NS_IMETHODIMP nsDOMDataTransfer::SetDragImage(nsIDOMElement *image, int32_t x, int32_t y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addElement (in nsIDOMElement element); */
NS_IMETHODIMP nsDOMDataTransfer::AddElement(nsIDOMElement *element)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozItemCount; */
NS_IMETHODIMP nsDOMDataTransfer::GetMozItemCount(uint32_t *aMozItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString mozCursor; */
NS_IMETHODIMP nsDOMDataTransfer::GetMozCursor(nsAString & aMozCursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataTransfer::SetMozCursor(const nsAString & aMozCursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMStringList mozTypesAt (in unsigned long index); */
NS_IMETHODIMP nsDOMDataTransfer::MozTypesAt(uint32_t index, nsIDOMDOMStringList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozClearDataAt (in DOMString format, in unsigned long index); */
NS_IMETHODIMP nsDOMDataTransfer::MozClearDataAt(const nsAString & format, uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozSetDataAt (in DOMString format, in nsIVariant data, in unsigned long index); */
NS_IMETHODIMP nsDOMDataTransfer::MozSetDataAt(const nsAString & format, nsIVariant *data, uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant mozGetDataAt (in DOMString format, in unsigned long index); */
NS_IMETHODIMP nsDOMDataTransfer::MozGetDataAt(const nsAString & format, uint32_t index, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozUserCancelled; */
NS_IMETHODIMP nsDOMDataTransfer::GetMozUserCancelled(bool *aMozUserCancelled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode mozSourceNode; */
NS_IMETHODIMP nsDOMDataTransfer::GetMozSourceNode(nsIDOMNode * *aMozSourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute unsigned long dropEffectInt; */
NS_IMETHODIMP nsDOMDataTransfer::GetDropEffectInt(uint32_t *aDropEffectInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataTransfer::SetDropEffectInt(uint32_t aDropEffectInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute unsigned long effectAllowedInt; */
NS_IMETHODIMP nsDOMDataTransfer::GetEffectAllowedInt(uint32_t *aEffectAllowedInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataTransfer::SetEffectAllowedInt(uint32_t aEffectAllowedInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMDataTransfer clone (in uint32_t aEventType, in boolean aUserCancelled, in boolean isCrossDomainSubFrameDrop); */
NS_IMETHODIMP nsDOMDataTransfer::Clone(uint32_t aEventType, bool aUserCancelled, bool isCrossDomainSubFrameDrop, nsIDOMDataTransfer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDataTransfer_h__ */
