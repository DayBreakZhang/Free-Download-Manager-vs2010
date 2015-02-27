/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/parser/htmlparser/public/nsIExpatSink.idl
 */

#ifndef __gen_nsIExpatSink_h__
#define __gen_nsIExpatSink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIScriptError; /* forward declaration */


/* starting interface:    nsIExpatSink */
#define NS_IEXPATSINK_IID_STR "f61c56b5-ea5b-42b4-ad3c-17416e72e238"

#define NS_IEXPATSINK_IID \
  {0xf61c56b5, 0xea5b, 0x42b4, \
    { 0xad, 0x3c, 0x17, 0x41, 0x6e, 0x72, 0xe2, 0x38 }}

class NS_NO_VTABLE nsIExpatSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXPATSINK_IID)

  /* void HandleStartElement (in wstring aName, [array, size_is (aAttsCount)] in wstring aAtts, in unsigned long aAttsCount, in long aIndex, in unsigned long aLineNumber); */
  NS_IMETHOD HandleStartElement(const PRUnichar * aName, const PRUnichar * *aAtts, uint32_t aAttsCount, int32_t aIndex, uint32_t aLineNumber) = 0;

  /* void HandleEndElement (in wstring aName); */
  NS_IMETHOD HandleEndElement(const PRUnichar * aName) = 0;

  /* void HandleComment (in wstring aCommentText); */
  NS_IMETHOD HandleComment(const PRUnichar * aCommentText) = 0;

  /* void HandleCDataSection ([size_is (aLength)] in wstring aData, in unsigned long aLength); */
  NS_IMETHOD HandleCDataSection(const PRUnichar * aData, uint32_t aLength) = 0;

  /* void HandleDoctypeDecl (in AString aSubset, in AString aName, in AString aSystemId, in AString aPublicId, in nsISupports aCatalogData); */
  NS_IMETHOD HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData) = 0;

  /* void HandleCharacterData ([size_is (aLength)] in wstring aData, in unsigned long aLength); */
  NS_IMETHOD HandleCharacterData(const PRUnichar * aData, uint32_t aLength) = 0;

  /* void HandleProcessingInstruction (in wstring aTarget, in wstring aData); */
  NS_IMETHOD HandleProcessingInstruction(const PRUnichar * aTarget, const PRUnichar * aData) = 0;

  /* void HandleXMLDeclaration (in wstring aVersion, in wstring aEncoding, in long aStandalone); */
  NS_IMETHOD HandleXMLDeclaration(const PRUnichar * aVersion, const PRUnichar * aEncoding, int32_t aStandalone) = 0;

  /* boolean ReportError (in wstring aErrorText, in wstring aSourceText, in nsIScriptError aError); */
  NS_IMETHOD ReportError(const PRUnichar * aErrorText, const PRUnichar * aSourceText, nsIScriptError *aError, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExpatSink, NS_IEXPATSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXPATSINK \
  NS_IMETHOD HandleStartElement(const PRUnichar * aName, const PRUnichar * *aAtts, uint32_t aAttsCount, int32_t aIndex, uint32_t aLineNumber); \
  NS_IMETHOD HandleEndElement(const PRUnichar * aName); \
  NS_IMETHOD HandleComment(const PRUnichar * aCommentText); \
  NS_IMETHOD HandleCDataSection(const PRUnichar * aData, uint32_t aLength); \
  NS_IMETHOD HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData); \
  NS_IMETHOD HandleCharacterData(const PRUnichar * aData, uint32_t aLength); \
  NS_IMETHOD HandleProcessingInstruction(const PRUnichar * aTarget, const PRUnichar * aData); \
  NS_IMETHOD HandleXMLDeclaration(const PRUnichar * aVersion, const PRUnichar * aEncoding, int32_t aStandalone); \
  NS_IMETHOD ReportError(const PRUnichar * aErrorText, const PRUnichar * aSourceText, nsIScriptError *aError, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXPATSINK(_to) \
  NS_IMETHOD HandleStartElement(const PRUnichar * aName, const PRUnichar * *aAtts, uint32_t aAttsCount, int32_t aIndex, uint32_t aLineNumber) { return _to HandleStartElement(aName, aAtts, aAttsCount, aIndex, aLineNumber); } \
  NS_IMETHOD HandleEndElement(const PRUnichar * aName) { return _to HandleEndElement(aName); } \
  NS_IMETHOD HandleComment(const PRUnichar * aCommentText) { return _to HandleComment(aCommentText); } \
  NS_IMETHOD HandleCDataSection(const PRUnichar * aData, uint32_t aLength) { return _to HandleCDataSection(aData, aLength); } \
  NS_IMETHOD HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData) { return _to HandleDoctypeDecl(aSubset, aName, aSystemId, aPublicId, aCatalogData); } \
  NS_IMETHOD HandleCharacterData(const PRUnichar * aData, uint32_t aLength) { return _to HandleCharacterData(aData, aLength); } \
  NS_IMETHOD HandleProcessingInstruction(const PRUnichar * aTarget, const PRUnichar * aData) { return _to HandleProcessingInstruction(aTarget, aData); } \
  NS_IMETHOD HandleXMLDeclaration(const PRUnichar * aVersion, const PRUnichar * aEncoding, int32_t aStandalone) { return _to HandleXMLDeclaration(aVersion, aEncoding, aStandalone); } \
  NS_IMETHOD ReportError(const PRUnichar * aErrorText, const PRUnichar * aSourceText, nsIScriptError *aError, bool *_retval) { return _to ReportError(aErrorText, aSourceText, aError, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXPATSINK(_to) \
  NS_IMETHOD HandleStartElement(const PRUnichar * aName, const PRUnichar * *aAtts, uint32_t aAttsCount, int32_t aIndex, uint32_t aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStartElement(aName, aAtts, aAttsCount, aIndex, aLineNumber); } \
  NS_IMETHOD HandleEndElement(const PRUnichar * aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEndElement(aName); } \
  NS_IMETHOD HandleComment(const PRUnichar * aCommentText) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleComment(aCommentText); } \
  NS_IMETHOD HandleCDataSection(const PRUnichar * aData, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCDataSection(aData, aLength); } \
  NS_IMETHOD HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleDoctypeDecl(aSubset, aName, aSystemId, aPublicId, aCatalogData); } \
  NS_IMETHOD HandleCharacterData(const PRUnichar * aData, uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCharacterData(aData, aLength); } \
  NS_IMETHOD HandleProcessingInstruction(const PRUnichar * aTarget, const PRUnichar * aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleProcessingInstruction(aTarget, aData); } \
  NS_IMETHOD HandleXMLDeclaration(const PRUnichar * aVersion, const PRUnichar * aEncoding, int32_t aStandalone) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleXMLDeclaration(aVersion, aEncoding, aStandalone); } \
  NS_IMETHOD ReportError(const PRUnichar * aErrorText, const PRUnichar * aSourceText, nsIScriptError *aError, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReportError(aErrorText, aSourceText, aError, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExpatSink : public nsIExpatSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXPATSINK

  nsExpatSink();

private:
  ~nsExpatSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExpatSink, nsIExpatSink)

nsExpatSink::nsExpatSink()
{
  /* member initializers and constructor code */
}

nsExpatSink::~nsExpatSink()
{
  /* destructor code */
}

/* void HandleStartElement (in wstring aName, [array, size_is (aAttsCount)] in wstring aAtts, in unsigned long aAttsCount, in long aIndex, in unsigned long aLineNumber); */
NS_IMETHODIMP nsExpatSink::HandleStartElement(const PRUnichar * aName, const PRUnichar * *aAtts, uint32_t aAttsCount, int32_t aIndex, uint32_t aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleEndElement (in wstring aName); */
NS_IMETHODIMP nsExpatSink::HandleEndElement(const PRUnichar * aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleComment (in wstring aCommentText); */
NS_IMETHODIMP nsExpatSink::HandleComment(const PRUnichar * aCommentText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleCDataSection ([size_is (aLength)] in wstring aData, in unsigned long aLength); */
NS_IMETHODIMP nsExpatSink::HandleCDataSection(const PRUnichar * aData, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleDoctypeDecl (in AString aSubset, in AString aName, in AString aSystemId, in AString aPublicId, in nsISupports aCatalogData); */
NS_IMETHODIMP nsExpatSink::HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleCharacterData ([size_is (aLength)] in wstring aData, in unsigned long aLength); */
NS_IMETHODIMP nsExpatSink::HandleCharacterData(const PRUnichar * aData, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleProcessingInstruction (in wstring aTarget, in wstring aData); */
NS_IMETHODIMP nsExpatSink::HandleProcessingInstruction(const PRUnichar * aTarget, const PRUnichar * aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleXMLDeclaration (in wstring aVersion, in wstring aEncoding, in long aStandalone); */
NS_IMETHODIMP nsExpatSink::HandleXMLDeclaration(const PRUnichar * aVersion, const PRUnichar * aEncoding, int32_t aStandalone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean ReportError (in wstring aErrorText, in wstring aSourceText, in nsIScriptError aError); */
NS_IMETHODIMP nsExpatSink::ReportError(const PRUnichar * aErrorText, const PRUnichar * aSourceText, nsIScriptError *aError, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExpatSink_h__ */
