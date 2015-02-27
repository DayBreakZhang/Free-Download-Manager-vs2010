/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/accessible/public/nsIAccessibleDocument.idl
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

class nsIAccessNode; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIAccessibleDocument */
#define NS_IACCESSIBLEDOCUMENT_IID_STR "451242bd-8a0c-4198-ae88-c053609a4e5d"

#define NS_IACCESSIBLEDOCUMENT_IID \
  {0x451242bd, 0x8a0c, 0x4198, \
    { 0xae, 0x88, 0xc0, 0x53, 0x60, 0x9a, 0x4e, 0x5d }}

/**
 * An interface for in-process accessibility clients
 * that wish to retrieve information about a document.
 * When accessibility is turned on in Gecko,
 * there is an nsIAccessibleDocument for each document
 * whether it is XUL, HTML or whatever.
 * You can QueryInterface to nsIAccessibleDocument from
 * the nsIAccessible or nsIAccessNode for the root node
 * of a document. You can also get one from 
 * nsIAccessNode::GetAccessibleDocument() or 
 * nsIAccessibleEvent::GetAccessibleDocument()
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEDOCUMENT_IID)

  /**
   * The URL of the document
   */
  /* readonly attribute AString URL; */
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) = 0;

  /**
   * The title of the document, as specified in the document.
   */
  /* readonly attribute AString title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) = 0;

  /**
   * The mime type of the document
   */
  /* readonly attribute AString mimeType; */
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(nsAString & aMimeType) = 0;

  /**
   * The doc type of the document, as specified in the document.
   */
  /* readonly attribute AString docType; */
  NS_SCRIPTABLE NS_IMETHOD GetDocType(nsAString & aDocType) = 0;

  /**
   * The nsIDOMDocument interface associated with this document.
   */
  /* readonly attribute nsIDOMDocument DOMDocument; */
  NS_SCRIPTABLE NS_IMETHOD GetDOMDocument(nsIDOMDocument **aDOMDocument) = 0;

  /**
   * The nsIDOMWindow that the document resides in.
   */
  /* readonly attribute nsIDOMWindow window; */
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow **aWindow) = 0;

  /**
   * The namespace for each ID that is handed back.
   */
  /* AString getNameSpaceURIForID (in short nameSpaceID); */
  NS_SCRIPTABLE NS_IMETHOD GetNameSpaceURIForID(PRInt16 nameSpaceID, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * The window handle for the OS window the document is being displayed in.
   * For example, in Windows you can static cast it to an HWND.
   */
  /* [noscript] readonly attribute voidPtr windowHandle; */
  NS_IMETHOD GetWindowHandle(void **aWindowHandle) = 0;

  /**
   * Return the parent document accessible.
   */
  /* readonly attribute nsIAccessibleDocument parentDocument; */
  NS_SCRIPTABLE NS_IMETHOD GetParentDocument(nsIAccessibleDocument **aParentDocument) = 0;

  /**
   * Return the count of child document accessibles.
   */
  /* readonly attribute unsigned long childDocumentCount; */
  NS_SCRIPTABLE NS_IMETHOD GetChildDocumentCount(PRUint32 *aChildDocumentCount) = 0;

  /**
   * Return the child document accessible at the given index.
   */
  /* nsIAccessibleDocument getChildDocumentAt (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetChildDocumentAt(PRUint32 index, nsIAccessibleDocument **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleDocument, NS_IACCESSIBLEDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(nsAString & aMimeType); \
  NS_SCRIPTABLE NS_IMETHOD GetDocType(nsAString & aDocType); \
  NS_SCRIPTABLE NS_IMETHOD GetDOMDocument(nsIDOMDocument **aDOMDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow **aWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetNameSpaceURIForID(PRInt16 nameSpaceID, nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetWindowHandle(void **aWindowHandle); \
  NS_SCRIPTABLE NS_IMETHOD GetParentDocument(nsIAccessibleDocument **aParentDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetChildDocumentCount(PRUint32 *aChildDocumentCount); \
  NS_SCRIPTABLE NS_IMETHOD GetChildDocumentAt(PRUint32 index, nsIAccessibleDocument **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) { return _to GetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(nsAString & aMimeType) { return _to GetMimeType(aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocType(nsAString & aDocType) { return _to GetDocType(aDocType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDOMDocument(nsIDOMDocument **aDOMDocument) { return _to GetDOMDocument(aDOMDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow **aWindow) { return _to GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetNameSpaceURIForID(PRInt16 nameSpaceID, nsAString & _retval NS_OUTPARAM) { return _to GetNameSpaceURIForID(nameSpaceID, _retval); } \
  NS_IMETHOD GetWindowHandle(void **aWindowHandle) { return _to GetWindowHandle(aWindowHandle); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentDocument(nsIAccessibleDocument **aParentDocument) { return _to GetParentDocument(aParentDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildDocumentCount(PRUint32 *aChildDocumentCount) { return _to GetChildDocumentCount(aChildDocumentCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildDocumentAt(PRUint32 index, nsIAccessibleDocument **_retval NS_OUTPARAM) { return _to GetChildDocumentAt(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(nsAString & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocType(nsAString & aDocType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocType(aDocType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDOMDocument(nsIDOMDocument **aDOMDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMDocument(aDOMDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow **aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetNameSpaceURIForID(PRInt16 nameSpaceID, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNameSpaceURIForID(nameSpaceID, _retval); } \
  NS_IMETHOD GetWindowHandle(void **aWindowHandle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowHandle(aWindowHandle); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentDocument(nsIAccessibleDocument **aParentDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentDocument(aParentDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildDocumentCount(PRUint32 *aChildDocumentCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildDocumentCount(aChildDocumentCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildDocumentAt(PRUint32 index, nsIAccessibleDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildDocumentAt(index, _retval); } 

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
NS_IMETHODIMP nsAccessibleDocument::GetDOMDocument(nsIDOMDocument **aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsAccessibleDocument::GetWindow(nsIDOMWindow **aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getNameSpaceURIForID (in short nameSpaceID); */
NS_IMETHODIMP nsAccessibleDocument::GetNameSpaceURIForID(PRInt16 nameSpaceID, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute voidPtr windowHandle; */
NS_IMETHODIMP nsAccessibleDocument::GetWindowHandle(void **aWindowHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleDocument parentDocument; */
NS_IMETHODIMP nsAccessibleDocument::GetParentDocument(nsIAccessibleDocument **aParentDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childDocumentCount; */
NS_IMETHODIMP nsAccessibleDocument::GetChildDocumentCount(PRUint32 *aChildDocumentCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleDocument getChildDocumentAt (in unsigned long index); */
NS_IMETHODIMP nsAccessibleDocument::GetChildDocumentAt(PRUint32 index, nsIAccessibleDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleDocument_h__ */
