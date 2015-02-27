/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleDocument.idl
 */

#ifndef __gen_nsIAccessibleDocument_h__
#define __gen_nsIAccessibleDocument_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */

class nsIAccessiblePivot; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIAccessibleDocument */
#define NS_IACCESSIBLEDOCUMENT_IID_STR "fe5b3886-2b6a-491a-80cd-a3e6342c451d"

#define NS_IACCESSIBLEDOCUMENT_IID \
  {0xfe5b3886, 0x2b6a, 0x491a, \
    { 0x80, 0xcd, 0xa3, 0xe6, 0x34, 0x2c, 0x45, 0x1d }}

class NS_NO_VTABLE nsIAccessibleDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEDOCUMENT_IID)

  /* readonly attribute AString URL; */
  NS_IMETHOD GetURL(nsAString & aURL) = 0;

  /* readonly attribute AString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;

  /* readonly attribute AString mimeType; */
  NS_IMETHOD GetMimeType(nsAString & aMimeType) = 0;

  /* readonly attribute AString docType; */
  NS_IMETHOD GetDocType(nsAString & aDocType) = 0;

  /* readonly attribute nsIDOMDocument DOMDocument; */
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) = 0;

  /* readonly attribute nsIDOMWindow window; */
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) = 0;

  /* AString getNameSpaceURIForID (in short nameSpaceID); */
  NS_IMETHOD GetNameSpaceURIForID(int16_t nameSpaceID, nsAString & _retval) = 0;

  /* [noscript] readonly attribute voidPtr windowHandle; */
  NS_IMETHOD GetWindowHandle(void **aWindowHandle) = 0;

  /* readonly attribute nsIAccessibleDocument parentDocument; */
  NS_IMETHOD GetParentDocument(nsIAccessibleDocument * *aParentDocument) = 0;

  /* readonly attribute unsigned long childDocumentCount; */
  NS_IMETHOD GetChildDocumentCount(uint32_t *aChildDocumentCount) = 0;

  /* readonly attribute nsIAccessiblePivot virtualCursor; */
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) = 0;

  /* nsIAccessibleDocument getChildDocumentAt (in unsigned long index); */
  NS_IMETHOD GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleDocument, NS_IACCESSIBLEDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEDOCUMENT \
  NS_IMETHOD GetURL(nsAString & aURL); \
  NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_IMETHOD GetMimeType(nsAString & aMimeType); \
  NS_IMETHOD GetDocType(nsAString & aDocType); \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument); \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow); \
  NS_IMETHOD GetNameSpaceURIForID(int16_t nameSpaceID, nsAString & _retval); \
  NS_IMETHOD GetWindowHandle(void **aWindowHandle); \
  NS_IMETHOD GetParentDocument(nsIAccessibleDocument * *aParentDocument); \
  NS_IMETHOD GetChildDocumentCount(uint32_t *aChildDocumentCount); \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor); \
  NS_IMETHOD GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEDOCUMENT(_to) \
  NS_IMETHOD GetURL(nsAString & aURL) { return _to GetURL(aURL); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD GetMimeType(nsAString & aMimeType) { return _to GetMimeType(aMimeType); } \
  NS_IMETHOD GetDocType(nsAString & aDocType) { return _to GetDocType(aDocType); } \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) { return _to GetDOMDocument(aDOMDocument); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetNameSpaceURIForID(int16_t nameSpaceID, nsAString & _retval) { return _to GetNameSpaceURIForID(nameSpaceID, _retval); } \
  NS_IMETHOD GetWindowHandle(void **aWindowHandle) { return _to GetWindowHandle(aWindowHandle); } \
  NS_IMETHOD GetParentDocument(nsIAccessibleDocument * *aParentDocument) { return _to GetParentDocument(aParentDocument); } \
  NS_IMETHOD GetChildDocumentCount(uint32_t *aChildDocumentCount) { return _to GetChildDocumentCount(aChildDocumentCount); } \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) { return _to GetVirtualCursor(aVirtualCursor); } \
  NS_IMETHOD GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval) { return _to GetChildDocumentAt(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEDOCUMENT(_to) \
  NS_IMETHOD GetURL(nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD GetMimeType(nsAString & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_IMETHOD GetDocType(nsAString & aDocType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocType(aDocType); } \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMDocument(aDOMDocument); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetNameSpaceURIForID(int16_t nameSpaceID, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNameSpaceURIForID(nameSpaceID, _retval); } \
  NS_IMETHOD GetWindowHandle(void **aWindowHandle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowHandle(aWindowHandle); } \
  NS_IMETHOD GetParentDocument(nsIAccessibleDocument * *aParentDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentDocument(aParentDocument); } \
  NS_IMETHOD GetChildDocumentCount(uint32_t *aChildDocumentCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildDocumentCount(aChildDocumentCount); } \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVirtualCursor(aVirtualCursor); } \
  NS_IMETHOD GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildDocumentAt(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleDocument : public nsIAccessibleDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEDOCUMENT

  nsAccessibleDocument();

private:
  ~nsAccessibleDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleDocument, nsIAccessibleDocument)

nsAccessibleDocument::nsAccessibleDocument()
{
  /* member initializers and constructor code */
}

nsAccessibleDocument::~nsAccessibleDocument()
{
  /* destructor code */
}

/* readonly attribute AString URL; */
NS_IMETHODIMP nsAccessibleDocument::GetURL(nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString title; */
NS_IMETHODIMP nsAccessibleDocument::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString mimeType; */
NS_IMETHODIMP nsAccessibleDocument::GetMimeType(nsAString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString docType; */
NS_IMETHODIMP nsAccessibleDocument::GetDocType(nsAString & aDocType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument DOMDocument; */
NS_IMETHODIMP nsAccessibleDocument::GetDOMDocument(nsIDOMDocument * *aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsAccessibleDocument::GetWindow(nsIDOMWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getNameSpaceURIForID (in short nameSpaceID); */
NS_IMETHODIMP nsAccessibleDocument::GetNameSpaceURIForID(int16_t nameSpaceID, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute voidPtr windowHandle; */
NS_IMETHODIMP nsAccessibleDocument::GetWindowHandle(void **aWindowHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleDocument parentDocument; */
NS_IMETHODIMP nsAccessibleDocument::GetParentDocument(nsIAccessibleDocument * *aParentDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childDocumentCount; */
NS_IMETHODIMP nsAccessibleDocument::GetChildDocumentCount(uint32_t *aChildDocumentCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessiblePivot virtualCursor; */
NS_IMETHODIMP nsAccessibleDocument::GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleDocument getChildDocumentAt (in unsigned long index); */
NS_IMETHODIMP nsAccessibleDocument::GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleDocument_h__ */
