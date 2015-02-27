/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDocumentEncoder.idl
 */

#ifndef __gen_nsIDocumentEncoder_h__
#define __gen_nsIDocumentEncoder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIDOMRange; /* forward declaration */

class nsISelection; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsINode;
class nsIDocument;

/* starting interface:    nsIDocumentEncoderNodeFixup */
#define NS_IDOCUMENTENCODERNODEFIXUP_IID_STR "3d9371d8-a2ad-403e-8b0e-8885ad3562e3"

#define NS_IDOCUMENTENCODERNODEFIXUP_IID \
  {0x3d9371d8, 0xa2ad, 0x403e, \
    { 0x8b, 0x0e, 0x88, 0x85, 0xad, 0x35, 0x62, 0xe3 }}

class NS_NO_VTABLE nsIDocumentEncoderNodeFixup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTENCODERNODEFIXUP_IID)

  /* nsIDOMNode fixupNode (in nsIDOMNode aNode, out boolean aSerializeCloneKids); */
  NS_IMETHOD FixupNode(nsIDOMNode *aNode, bool *aSerializeCloneKids, nsIDOMNode * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentEncoderNodeFixup, NS_IDOCUMENTENCODERNODEFIXUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTENCODERNODEFIXUP \
  NS_IMETHOD FixupNode(nsIDOMNode *aNode, bool *aSerializeCloneKids, nsIDOMNode * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTENCODERNODEFIXUP(_to) \
  NS_IMETHOD FixupNode(nsIDOMNode *aNode, bool *aSerializeCloneKids, nsIDOMNode * *_retval) { return _to FixupNode(aNode, aSerializeCloneKids, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTENCODERNODEFIXUP(_to) \
  NS_IMETHOD FixupNode(nsIDOMNode *aNode, bool *aSerializeCloneKids, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FixupNode(aNode, aSerializeCloneKids, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentEncoderNodeFixup : public nsIDocumentEncoderNodeFixup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTENCODERNODEFIXUP

  nsDocumentEncoderNodeFixup();

private:
  ~nsDocumentEncoderNodeFixup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentEncoderNodeFixup, nsIDocumentEncoderNodeFixup)

nsDocumentEncoderNodeFixup::nsDocumentEncoderNodeFixup()
{
  /* member initializers and constructor code */
}

nsDocumentEncoderNodeFixup::~nsDocumentEncoderNodeFixup()
{
  /* destructor code */
}

/* nsIDOMNode fixupNode (in nsIDOMNode aNode, out boolean aSerializeCloneKids); */
NS_IMETHODIMP nsDocumentEncoderNodeFixup::FixupNode(nsIDOMNode *aNode, bool *aSerializeCloneKids, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDocumentEncoder */
#define NS_IDOCUMENTENCODER_IID_STR "7222bdf1-c2b9-41f1-a40a-a3d65283a95b"

#define NS_IDOCUMENTENCODER_IID \
  {0x7222bdf1, 0xc2b9, 0x41f1, \
    { 0xa4, 0x0a, 0xa3, 0xd6, 0x52, 0x83, 0xa9, 0x5b }}

class NS_NO_VTABLE nsIDocumentEncoder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTENCODER_IID)

  enum {
    OutputSelectionOnly = 1U,
    OutputFormatted = 2U,
    OutputRaw = 4U,
    OutputBodyOnly = 8U,
    OutputPreformatted = 16U,
    OutputWrap = 32U,
    OutputFormatFlowed = 64U,
    OutputAbsoluteLinks = 128U,
    OutputEncodeW3CEntities = 256U,
    OutputCRLineBreak = 512U,
    OutputLFLineBreak = 1024U,
    OutputNoScriptContent = 2048U,
    OutputNoFramesContent = 4096U,
    OutputNoFormattingInPre = 8192U,
    OutputEncodeBasicEntities = 16384U,
    OutputEncodeLatin1Entities = 32768U,
    OutputEncodeHTMLEntities = 65536U,
    OutputPersistNBSP = 131072U,
    OutputDontRewriteEncodingDeclaration = 262144U,
    SkipInvisibleContent = 524288U,
    OutputFormatDelSp = 1048576U,
    OutputDropInvisibleBreak = 2097152U,
    OutputIgnoreMozDirty = 4194304U,
    OutputNonTextContentAsPlaceholder = 8388608U,
    OutputDontRemoveLineEndingSpaces = 16777216U
  };

  /* void init (in nsIDOMDocument aDocument, in AString aMimeType, in unsigned long aFlags); */
  NS_IMETHOD Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags) = 0;

  /* [noscript] void nativeInit (in nsIDocumentPtr aDocument, in AString aMimeType, in unsigned long aFlags); */
  NS_IMETHOD NativeInit(nsIDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags) = 0;

  /* void setSelection (in nsISelection aSelection); */
  NS_IMETHOD SetSelection(nsISelection *aSelection) = 0;

  /* void setRange (in nsIDOMRange aRange); */
  NS_IMETHOD SetRange(nsIDOMRange *aRange) = 0;

  /* void setNode (in nsIDOMNode aNode); */
  NS_IMETHOD SetNode(nsIDOMNode *aNode) = 0;

  /* [noscript] void setNativeNode (in nsINodePtr aNode); */
  NS_IMETHOD SetNativeNode(nsINode *aNode) = 0;

  /* void setContainerNode (in nsIDOMNode aContainer); */
  NS_IMETHOD SetContainerNode(nsIDOMNode *aContainer) = 0;

  /* [noscript] void setNativeContainerNode (in nsINodePtr aContainer); */
  NS_IMETHOD SetNativeContainerNode(nsINode *aContainer) = 0;

  /* void setCharset (in ACString aCharset); */
  NS_IMETHOD SetCharset(const nsACString & aCharset) = 0;

  /* void setWrapColumn (in unsigned long aWrapColumn); */
  NS_IMETHOD SetWrapColumn(uint32_t aWrapColumn) = 0;

  /* readonly attribute AString mimeType; */
  NS_IMETHOD GetMimeType(nsAString & aMimeType) = 0;

  /* void encodeToStream (in nsIOutputStream aStream); */
  NS_IMETHOD EncodeToStream(nsIOutputStream *aStream) = 0;

  /* AString encodeToString (); */
  NS_IMETHOD EncodeToString(nsAString & _retval) = 0;

  /* AString encodeToStringWithContext (out AString aContextString, out AString aInfoString); */
  NS_IMETHOD EncodeToStringWithContext(nsAString & aContextString, nsAString & aInfoString, nsAString & _retval) = 0;

  /* void setNodeFixup (in nsIDocumentEncoderNodeFixup aFixup); */
  NS_IMETHOD SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentEncoder, NS_IDOCUMENTENCODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTENCODER \
  NS_IMETHOD Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags); \
  NS_IMETHOD NativeInit(nsIDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags); \
  NS_IMETHOD SetSelection(nsISelection *aSelection); \
  NS_IMETHOD SetRange(nsIDOMRange *aRange); \
  NS_IMETHOD SetNode(nsIDOMNode *aNode); \
  NS_IMETHOD SetNativeNode(nsINode *aNode); \
  NS_IMETHOD SetContainerNode(nsIDOMNode *aContainer); \
  NS_IMETHOD SetNativeContainerNode(nsINode *aContainer); \
  NS_IMETHOD SetCharset(const nsACString & aCharset); \
  NS_IMETHOD SetWrapColumn(uint32_t aWrapColumn); \
  NS_IMETHOD GetMimeType(nsAString & aMimeType); \
  NS_IMETHOD EncodeToStream(nsIOutputStream *aStream); \
  NS_IMETHOD EncodeToString(nsAString & _retval); \
  NS_IMETHOD EncodeToStringWithContext(nsAString & aContextString, nsAString & aInfoString, nsAString & _retval); \
  NS_IMETHOD SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTENCODER(_to) \
  NS_IMETHOD Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags) { return _to Init(aDocument, aMimeType, aFlags); } \
  NS_IMETHOD NativeInit(nsIDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags) { return _to NativeInit(aDocument, aMimeType, aFlags); } \
  NS_IMETHOD SetSelection(nsISelection *aSelection) { return _to SetSelection(aSelection); } \
  NS_IMETHOD SetRange(nsIDOMRange *aRange) { return _to SetRange(aRange); } \
  NS_IMETHOD SetNode(nsIDOMNode *aNode) { return _to SetNode(aNode); } \
  NS_IMETHOD SetNativeNode(nsINode *aNode) { return _to SetNativeNode(aNode); } \
  NS_IMETHOD SetContainerNode(nsIDOMNode *aContainer) { return _to SetContainerNode(aContainer); } \
  NS_IMETHOD SetNativeContainerNode(nsINode *aContainer) { return _to SetNativeContainerNode(aContainer); } \
  NS_IMETHOD SetCharset(const nsACString & aCharset) { return _to SetCharset(aCharset); } \
  NS_IMETHOD SetWrapColumn(uint32_t aWrapColumn) { return _to SetWrapColumn(aWrapColumn); } \
  NS_IMETHOD GetMimeType(nsAString & aMimeType) { return _to GetMimeType(aMimeType); } \
  NS_IMETHOD EncodeToStream(nsIOutputStream *aStream) { return _to EncodeToStream(aStream); } \
  NS_IMETHOD EncodeToString(nsAString & _retval) { return _to EncodeToString(_retval); } \
  NS_IMETHOD EncodeToStringWithContext(nsAString & aContextString, nsAString & aInfoString, nsAString & _retval) { return _to EncodeToStringWithContext(aContextString, aInfoString, _retval); } \
  NS_IMETHOD SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup) { return _to SetNodeFixup(aFixup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTENCODER(_to) \
  NS_IMETHOD Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDocument, aMimeType, aFlags); } \
  NS_IMETHOD NativeInit(nsIDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->NativeInit(aDocument, aMimeType, aFlags); } \
  NS_IMETHOD SetSelection(nsISelection *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelection(aSelection); } \
  NS_IMETHOD SetRange(nsIDOMRange *aRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRange(aRange); } \
  NS_IMETHOD SetNode(nsIDOMNode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNode(aNode); } \
  NS_IMETHOD SetNativeNode(nsINode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNativeNode(aNode); } \
  NS_IMETHOD SetContainerNode(nsIDOMNode *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainerNode(aContainer); } \
  NS_IMETHOD SetNativeContainerNode(nsINode *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNativeContainerNode(aContainer); } \
  NS_IMETHOD SetCharset(const nsACString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } \
  NS_IMETHOD SetWrapColumn(uint32_t aWrapColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrapColumn(aWrapColumn); } \
  NS_IMETHOD GetMimeType(nsAString & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_IMETHOD EncodeToStream(nsIOutputStream *aStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToStream(aStream); } \
  NS_IMETHOD EncodeToString(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToString(_retval); } \
  NS_IMETHOD EncodeToStringWithContext(nsAString & aContextString, nsAString & aInfoString, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToStringWithContext(aContextString, aInfoString, _retval); } \
  NS_IMETHOD SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNodeFixup(aFixup); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentEncoder : public nsIDocumentEncoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTENCODER

  nsDocumentEncoder();

private:
  ~nsDocumentEncoder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentEncoder, nsIDocumentEncoder)

nsDocumentEncoder::nsDocumentEncoder()
{
  /* member initializers and constructor code */
}

nsDocumentEncoder::~nsDocumentEncoder()
{
  /* destructor code */
}

/* void init (in nsIDOMDocument aDocument, in AString aMimeType, in unsigned long aFlags); */
NS_IMETHODIMP nsDocumentEncoder::Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void nativeInit (in nsIDocumentPtr aDocument, in AString aMimeType, in unsigned long aFlags); */
NS_IMETHODIMP nsDocumentEncoder::NativeInit(nsIDocument *aDocument, const nsAString & aMimeType, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelection (in nsISelection aSelection); */
NS_IMETHODIMP nsDocumentEncoder::SetSelection(nsISelection *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRange (in nsIDOMRange aRange); */
NS_IMETHODIMP nsDocumentEncoder::SetRange(nsIDOMRange *aRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setNode (in nsIDOMNode aNode); */
NS_IMETHODIMP nsDocumentEncoder::SetNode(nsIDOMNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setNativeNode (in nsINodePtr aNode); */
NS_IMETHODIMP nsDocumentEncoder::SetNativeNode(nsINode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setContainerNode (in nsIDOMNode aContainer); */
NS_IMETHODIMP nsDocumentEncoder::SetContainerNode(nsIDOMNode *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setNativeContainerNode (in nsINodePtr aContainer); */
NS_IMETHODIMP nsDocumentEncoder::SetNativeContainerNode(nsINode *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCharset (in ACString aCharset); */
NS_IMETHODIMP nsDocumentEncoder::SetCharset(const nsACString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWrapColumn (in unsigned long aWrapColumn); */
NS_IMETHODIMP nsDocumentEncoder::SetWrapColumn(uint32_t aWrapColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString mimeType; */
NS_IMETHODIMP nsDocumentEncoder::GetMimeType(nsAString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void encodeToStream (in nsIOutputStream aStream); */
NS_IMETHODIMP nsDocumentEncoder::EncodeToStream(nsIOutputStream *aStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString encodeToString (); */
NS_IMETHODIMP nsDocumentEncoder::EncodeToString(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString encodeToStringWithContext (out AString aContextString, out AString aInfoString); */
NS_IMETHODIMP nsDocumentEncoder::EncodeToStringWithContext(nsAString & aContextString, nsAString & aInfoString, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setNodeFixup (in nsIDocumentEncoderNodeFixup aFixup); */
NS_IMETHODIMP nsDocumentEncoder::SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocumentEncoder_h__ */
