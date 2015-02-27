/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLAudioElement.idl
 */

#ifndef __gen_nsIDOMHTMLAudioElement_h__
#define __gen_nsIDOMHTMLAudioElement_h__


#ifndef __gen_nsIDOMHTMLMediaElement_h__
#include "nsIDOMHTMLMediaElement.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jsapi.h"

/* starting interface:    nsIDOMHTMLAudioElement */
#define NS_IDOMHTMLAUDIOELEMENT_IID_STR "8e3fb6a1-490d-4772-90fd-3e3763958b74"

#define NS_IDOMHTMLAUDIOELEMENT_IID \
  {0x8e3fb6a1, 0x490d, 0x4772, \
    { 0x90, 0xfd, 0x3e, 0x37, 0x63, 0x95, 0x8b, 0x74 }}

class NS_NO_VTABLE nsIDOMHTMLAudioElement : public nsIDOMHTMLMediaElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLAUDIOELEMENT_IID)

  /* void mozSetup (in uint32_t channels, in uint32_t rate); */
  NS_IMETHOD MozSetup(uint32_t channels, uint32_t rate) = 0;

  /* [implicit_jscontext] unsigned long mozWriteAudio (in jsval data); */
  NS_IMETHOD MozWriteAudio(const JS::Value & data, JSContext* cx, uint32_t *_retval) = 0;

  /* unsigned long long mozCurrentSampleOffset (); */
  NS_IMETHOD MozCurrentSampleOffset(uint64_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLAudioElement, NS_IDOMHTMLAUDIOELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLAUDIOELEMENT \
  NS_IMETHOD MozSetup(uint32_t channels, uint32_t rate); \
  NS_IMETHOD MozWriteAudio(const JS::Value & data, JSContext* cx, uint32_t *_retval); \
  NS_IMETHOD MozCurrentSampleOffset(uint64_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLAUDIOELEMENT(_to) \
  NS_IMETHOD MozSetup(uint32_t channels, uint32_t rate) { return _to MozSetup(channels, rate); } \
  NS_IMETHOD MozWriteAudio(const JS::Value & data, JSContext* cx, uint32_t *_retval) { return _to MozWriteAudio(data, cx, _retval); } \
  NS_IMETHOD MozCurrentSampleOffset(uint64_t *_retval) { return _to MozCurrentSampleOffset(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLAUDIOELEMENT(_to) \
  NS_IMETHOD MozSetup(uint32_t channels, uint32_t rate) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetup(channels, rate); } \
  NS_IMETHOD MozWriteAudio(const JS::Value & data, JSContext* cx, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozWriteAudio(data, cx, _retval); } \
  NS_IMETHOD MozCurrentSampleOffset(uint64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCurrentSampleOffset(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLAudioElement : public nsIDOMHTMLAudioElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLAUDIOELEMENT

  nsDOMHTMLAudioElement();

private:
  ~nsDOMHTMLAudioElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLAudioElement, nsIDOMHTMLAudioElement)

nsDOMHTMLAudioElement::nsDOMHTMLAudioElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLAudioElement::~nsDOMHTMLAudioElement()
{
  /* destructor code */
}

/* void mozSetup (in uint32_t channels, in uint32_t rate); */
NS_IMETHODIMP nsDOMHTMLAudioElement::MozSetup(uint32_t channels, uint32_t rate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] unsigned long mozWriteAudio (in jsval data); */
NS_IMETHODIMP nsDOMHTMLAudioElement::MozWriteAudio(const JS::Value & data, JSContext* cx, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long mozCurrentSampleOffset (); */
NS_IMETHODIMP nsDOMHTMLAudioElement::MozCurrentSampleOffset(uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLAudioElement_h__ */
