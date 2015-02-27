/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMNode.idl
 */

#ifndef __gen_nsIDOMNode_h__
#define __gen_nsIDOMNode_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIDOMUserDataHandler; /* forward declaration */


/* starting interface:    nsIDOMNode */
#define NS_IDOMNODE_IID_STR "56545150-a001-484e-9ed4-cb319eebd7b3"

#define NS_IDOMNODE_IID \
  {0x56545150, 0xa001, 0x484e, \
    { 0x9e, 0xd4, 0xcb, 0x31, 0x9e, 0xeb, 0xd7, 0xb3 }}

class NS_NO_VTABLE nsIDOMNode : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNODE_IID)

  enum {
    ELEMENT_NODE = 1U,
    ATTRIBUTE_NODE = 2U,
    TEXT_NODE = 3U,
    CDATA_SECTION_NODE = 4U,
    ENTITY_REFERENCE_NODE = 5U,
    ENTITY_NODE = 6U,
    PROCESSING_INSTRUCTION_NODE = 7U,
    COMMENT_NODE = 8U,
    DOCUMENT_NODE = 9U,
    DOCUMENT_TYPE_NODE = 10U,
    DOCUMENT_FRAGMENT_NODE = 11U,
    NOTATION_NODE = 12U
  };

  /* readonly attribute DOMString nodeName; */
  NS_IMETHOD GetNodeName(nsAString & aNodeName) = 0;

  /* attribute DOMString nodeValue; */
  NS_IMETHOD GetNodeValue(nsAString & aNodeValue) = 0;
  NS_IMETHOD SetNodeValue(const nsAString & aNodeValue) = 0;

  /* readonly attribute unsigned short nodeType; */
  NS_IMETHOD GetNodeType(uint16_t *aNodeType) = 0;

  /* readonly attribute nsIDOMNode parentNode; */
  NS_IMETHOD GetParentNode(nsIDOMNode * *aParentNode) = 0;

  /* readonly attribute nsIDOMElement parentElement; */
  NS_IMETHOD GetParentElement(nsIDOMElement * *aParentElement) = 0;

  /* readonly attribute nsIDOMNodeList childNodes; */
  NS_IMETHOD GetChildNodes(nsIDOMNodeList * *aChildNodes) = 0;

  /* readonly attribute nsIDOMNode firstChild; */
  NS_IMETHOD GetFirstChild(nsIDOMNode * *aFirstChild) = 0;

  /* readonly attribute nsIDOMNode lastChild; */
  NS_IMETHOD GetLastChild(nsIDOMNode * *aLastChild) = 0;

  /* readonly attribute nsIDOMNode previousSibling; */
  NS_IMETHOD GetPreviousSibling(nsIDOMNode * *aPreviousSibling) = 0;

  /* readonly attribute nsIDOMNode nextSibling; */
  NS_IMETHOD GetNextSibling(nsIDOMNode * *aNextSibling) = 0;

  /* readonly attribute nsIDOMDocument ownerDocument; */
  NS_IMETHOD GetOwnerDocument(nsIDOMDocument * *aOwnerDocument) = 0;

  /* nsIDOMNode insertBefore (in nsIDOMNode newChild, in nsIDOMNode refChild) raises (DOMException); */
  NS_IMETHOD InsertBefore(nsIDOMNode *newChild, nsIDOMNode *refChild, nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode replaceChild (in nsIDOMNode newChild, in nsIDOMNode oldChild) raises (DOMException); */
  NS_IMETHOD ReplaceChild(nsIDOMNode *newChild, nsIDOMNode *oldChild, nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode removeChild (in nsIDOMNode oldChild) raises (DOMException); */
  NS_IMETHOD RemoveChild(nsIDOMNode *oldChild, nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode appendChild (in nsIDOMNode newChild) raises (DOMException); */
  NS_IMETHOD AppendChild(nsIDOMNode *newChild, nsIDOMNode * *_retval) = 0;

  /* boolean hasChildNodes (); */
  NS_IMETHOD HasChildNodes(bool *_retval) = 0;

  /* [optional_argc] nsIDOMNode cloneNode ([optional] in boolean deep); */
  NS_IMETHOD CloneNode(bool deep, uint8_t _argc, nsIDOMNode * *_retval) = 0;

  /* void normalize (); */
  NS_IMETHOD Normalize(void) = 0;

  /* readonly attribute DOMString namespaceURI; */
  NS_IMETHOD GetNamespaceURI(nsAString & aNamespaceURI) = 0;

  /* readonly attribute DOMString prefix; */
  NS_IMETHOD GetPrefix(nsAString & aPrefix) = 0;

  /* readonly attribute DOMString localName; */
  NS_IMETHOD GetLocalName(nsAString & aLocalName) = 0;

  /* boolean hasAttributes (); */
  NS_IMETHOD HasAttributes(bool *_retval) = 0;

  /* [binaryname(DOMBaseURI)] readonly attribute DOMString baseURI; */
  NS_IMETHOD GetDOMBaseURI(nsAString & aBaseURI) = 0;

  enum {
    DOCUMENT_POSITION_DISCONNECTED = 1U,
    DOCUMENT_POSITION_PRECEDING = 2U,
    DOCUMENT_POSITION_FOLLOWING = 4U,
    DOCUMENT_POSITION_CONTAINS = 8U,
    DOCUMENT_POSITION_CONTAINED_BY = 16U,
    DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 32U
  };

  /* unsigned short compareDocumentPosition (in nsIDOMNode other) raises (DOMException); */
  NS_IMETHOD CompareDocumentPosition(nsIDOMNode *other, uint16_t *_retval) = 0;

  /* attribute DOMString textContent; */
  NS_IMETHOD GetTextContent(nsAString & aTextContent) = 0;
  NS_IMETHOD SetTextContent(const nsAString & aTextContent) = 0;

  /* DOMString lookupPrefix (in DOMString namespaceURI); */
  NS_IMETHOD LookupPrefix(const nsAString & namespaceURI, nsAString & _retval) = 0;

  /* boolean isDefaultNamespace (in DOMString namespaceURI); */
  NS_IMETHOD IsDefaultNamespace(const nsAString & namespaceURI, bool *_retval) = 0;

  /* DOMString lookupNamespaceURI (in DOMString prefix); */
  NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval) = 0;

  /* boolean isEqualNode (in nsIDOMNode arg); */
  NS_IMETHOD IsEqualNode(nsIDOMNode *arg, bool *_retval) = 0;

  /* nsIVariant setUserData (in DOMString key, in nsIVariant data, in nsIDOMUserDataHandler handler); */
  NS_IMETHOD SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant * *_retval) = 0;

  /* nsIVariant getUserData (in DOMString key); */
  NS_IMETHOD GetUserData(const nsAString & key, nsIVariant * *_retval) = 0;

  /* boolean contains (in nsIDOMNode aOther); */
  NS_IMETHOD Contains(nsIDOMNode *aOther, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNode, NS_IDOMNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNODE \
  NS_IMETHOD GetNodeName(nsAString & aNodeName); \
  NS_IMETHOD GetNodeValue(nsAString & aNodeValue); \
  NS_IMETHOD SetNodeValue(const nsAString & aNodeValue); \
  NS_IMETHOD GetNodeType(uint16_t *aNodeType); \
  NS_IMETHOD GetParentNode(nsIDOMNode * *aParentNode); \
  NS_IMETHOD GetParentElement(nsIDOMElement * *aParentElement); \
  NS_IMETHOD GetChildNodes(nsIDOMNodeList * *aChildNodes); \
  NS_IMETHOD GetFirstChild(nsIDOMNode * *aFirstChild); \
  NS_IMETHOD GetLastChild(nsIDOMNode * *aLastChild); \
  NS_IMETHOD GetPreviousSibling(nsIDOMNode * *aPreviousSibling); \
  NS_IMETHOD GetNextSibling(nsIDOMNode * *aNextSibling); \
  NS_IMETHOD GetOwnerDocument(nsIDOMDocument * *aOwnerDocument); \
  NS_IMETHOD InsertBefore(nsIDOMNode *newChild, nsIDOMNode *refChild, nsIDOMNode * *_retval); \
  NS_IMETHOD ReplaceChild(nsIDOMNode *newChild, nsIDOMNode *oldChild, nsIDOMNode * *_retval); \
  NS_IMETHOD RemoveChild(nsIDOMNode *oldChild, nsIDOMNode * *_retval); \
  NS_IMETHOD AppendChild(nsIDOMNode *newChild, nsIDOMNode * *_retval); \
  NS_IMETHOD HasChildNodes(bool *_retval); \
  NS_IMETHOD CloneNode(bool deep, uint8_t _argc, nsIDOMNode * *_retval); \
  NS_IMETHOD Normalize(void); \
  NS_IMETHOD GetNamespaceURI(nsAString & aNamespaceURI); \
  NS_IMETHOD GetPrefix(nsAString & aPrefix); \
  NS_IMETHOD GetLocalName(nsAString & aLocalName); \
  NS_IMETHOD HasAttributes(bool *_retval); \
  NS_IMETHOD GetDOMBaseURI(nsAString & aBaseURI); \
  NS_IMETHOD CompareDocumentPosition(nsIDOMNode *other, uint16_t *_retval); \
  NS_IMETHOD GetTextContent(nsAString & aTextContent); \
  NS_IMETHOD SetTextContent(const nsAString & aTextContent); \
  NS_IMETHOD LookupPrefix(const nsAString & namespaceURI, nsAString & _retval); \
  NS_IMETHOD IsDefaultNamespace(const nsAString & namespaceURI, bool *_retval); \
  NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval); \
  NS_IMETHOD IsEqualNode(nsIDOMNode *arg, bool *_retval); \
  NS_IMETHOD SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant * *_retval); \
  NS_IMETHOD GetUserData(const nsAString & key, nsIVariant * *_retval); \
  NS_IMETHOD Contains(nsIDOMNode *aOther, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNODE(_to) \
  NS_IMETHOD GetNodeName(nsAString & aNodeName) { return _to GetNodeName(aNodeName); } \
  NS_IMETHOD GetNodeValue(nsAString & aNodeValue) { return _to GetNodeValue(aNodeValue); } \
  NS_IMETHOD SetNodeValue(const nsAString & aNodeValue) { return _to SetNodeValue(aNodeValue); } \
  NS_IMETHOD GetNodeType(uint16_t *aNodeType) { return _to GetNodeType(aNodeType); } \
  NS_IMETHOD GetParentNode(nsIDOMNode * *aParentNode) { return _to GetParentNode(aParentNode); } \
  NS_IMETHOD GetParentElement(nsIDOMElement * *aParentElement) { return _to GetParentElement(aParentElement); } \
  NS_IMETHOD GetChildNodes(nsIDOMNodeList * *aChildNodes) { return _to GetChildNodes(aChildNodes); } \
  NS_IMETHOD GetFirstChild(nsIDOMNode * *aFirstChild) { return _to GetFirstChild(aFirstChild); } \
  NS_IMETHOD GetLastChild(nsIDOMNode * *aLastChild) { return _to GetLastChild(aLastChild); } \
  NS_IMETHOD GetPreviousSibling(nsIDOMNode * *aPreviousSibling) { return _to GetPreviousSibling(aPreviousSibling); } \
  NS_IMETHOD GetNextSibling(nsIDOMNode * *aNextSibling) { return _to GetNextSibling(aNextSibling); } \
  NS_IMETHOD GetOwnerDocument(nsIDOMDocument * *aOwnerDocument) { return _to GetOwnerDocument(aOwnerDocument); } \
  NS_IMETHOD InsertBefore(nsIDOMNode *newChild, nsIDOMNode *refChild, nsIDOMNode * *_retval) { return _to InsertBefore(newChild, refChild, _retval); } \
  NS_IMETHOD ReplaceChild(nsIDOMNode *newChild, nsIDOMNode *oldChild, nsIDOMNode * *_retval) { return _to ReplaceChild(newChild, oldChild, _retval); } \
  NS_IMETHOD RemoveChild(nsIDOMNode *oldChild, nsIDOMNode * *_retval) { return _to RemoveChild(oldChild, _retval); } \
  NS_IMETHOD AppendChild(nsIDOMNode *newChild, nsIDOMNode * *_retval) { return _to AppendChild(newChild, _retval); } \
  NS_IMETHOD HasChildNodes(bool *_retval) { return _to HasChildNodes(_retval); } \
  NS_IMETHOD CloneNode(bool deep, uint8_t _argc, nsIDOMNode * *_retval) { return _to CloneNode(deep, _argc, _retval); } \
  NS_IMETHOD Normalize(void) { return _to Normalize(); } \
  NS_IMETHOD GetNamespaceURI(nsAString & aNamespaceURI) { return _to GetNamespaceURI(aNamespaceURI); } \
  NS_IMETHOD GetPrefix(nsAString & aPrefix) { return _to GetPrefix(aPrefix); } \
  NS_IMETHOD GetLocalName(nsAString & aLocalName) { return _to GetLocalName(aLocalName); } \
  NS_IMETHOD HasAttributes(bool *_retval) { return _to HasAttributes(_retval); } \
  NS_IMETHOD GetDOMBaseURI(nsAString & aBaseURI) { return _to GetDOMBaseURI(aBaseURI); } \
  NS_IMETHOD CompareDocumentPosition(nsIDOMNode *other, uint16_t *_retval) { return _to CompareDocumentPosition(other, _retval); } \
  NS_IMETHOD GetTextContent(nsAString & aTextContent) { return _to GetTextContent(aTextContent); } \
  NS_IMETHOD SetTextContent(const nsAString & aTextContent) { return _to SetTextContent(aTextContent); } \
  NS_IMETHOD LookupPrefix(const nsAString & namespaceURI, nsAString & _retval) { return _to LookupPrefix(namespaceURI, _retval); } \
  NS_IMETHOD IsDefaultNamespace(const nsAString & namespaceURI, bool *_retval) { return _to IsDefaultNamespace(namespaceURI, _retval); } \
  NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval) { return _to LookupNamespaceURI(prefix, _retval); } \
  NS_IMETHOD IsEqualNode(nsIDOMNode *arg, bool *_retval) { return _to IsEqualNode(arg, _retval); } \
  NS_IMETHOD SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant * *_retval) { return _to SetUserData(key, data, handler, _retval); } \
  NS_IMETHOD GetUserData(const nsAString & key, nsIVariant * *_retval) { return _to GetUserData(key, _retval); } \
  NS_IMETHOD Contains(nsIDOMNode *aOther, bool *_retval) { return _to Contains(aOther, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNODE(_to) \
  NS_IMETHOD GetNodeName(nsAString & aNodeName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeName(aNodeName); } \
  NS_IMETHOD GetNodeValue(nsAString & aNodeValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeValue(aNodeValue); } \
  NS_IMETHOD SetNodeValue(const nsAString & aNodeValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNodeValue(aNodeValue); } \
  NS_IMETHOD GetNodeType(uint16_t *aNodeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeType(aNodeType); } \
  NS_IMETHOD GetParentNode(nsIDOMNode * *aParentNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentNode(aParentNode); } \
  NS_IMETHOD GetParentElement(nsIDOMElement * *aParentElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentElement(aParentElement); } \
  NS_IMETHOD GetChildNodes(nsIDOMNodeList * *aChildNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildNodes(aChildNodes); } \
  NS_IMETHOD GetFirstChild(nsIDOMNode * *aFirstChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstChild(aFirstChild); } \
  NS_IMETHOD GetLastChild(nsIDOMNode * *aLastChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastChild(aLastChild); } \
  NS_IMETHOD GetPreviousSibling(nsIDOMNode * *aPreviousSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousSibling(aPreviousSibling); } \
  NS_IMETHOD GetNextSibling(nsIDOMNode * *aNextSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSibling(aNextSibling); } \
  NS_IMETHOD GetOwnerDocument(nsIDOMDocument * *aOwnerDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerDocument(aOwnerDocument); } \
  NS_IMETHOD InsertBefore(nsIDOMNode *newChild, nsIDOMNode *refChild, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertBefore(newChild, refChild, _retval); } \
  NS_IMETHOD ReplaceChild(nsIDOMNode *newChild, nsIDOMNode *oldChild, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceChild(newChild, oldChild, _retval); } \
  NS_IMETHOD RemoveChild(nsIDOMNode *oldChild, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChild(oldChild, _retval); } \
  NS_IMETHOD AppendChild(nsIDOMNode *newChild, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendChild(newChild, _retval); } \
  NS_IMETHOD HasChildNodes(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasChildNodes(_retval); } \
  NS_IMETHOD CloneNode(bool deep, uint8_t _argc, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneNode(deep, _argc, _retval); } \
  NS_IMETHOD Normalize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Normalize(); } \
  NS_IMETHOD GetNamespaceURI(nsAString & aNamespaceURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamespaceURI(aNamespaceURI); } \
  NS_IMETHOD GetPrefix(nsAString & aPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefix(aPrefix); } \
  NS_IMETHOD GetLocalName(nsAString & aLocalName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalName(aLocalName); } \
  NS_IMETHOD HasAttributes(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAttributes(_retval); } \
  NS_IMETHOD GetDOMBaseURI(nsAString & aBaseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMBaseURI(aBaseURI); } \
  NS_IMETHOD CompareDocumentPosition(nsIDOMNode *other, uint16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareDocumentPosition(other, _retval); } \
  NS_IMETHOD GetTextContent(nsAString & aTextContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextContent(aTextContent); } \
  NS_IMETHOD SetTextContent(const nsAString & aTextContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextContent(aTextContent); } \
  NS_IMETHOD LookupPrefix(const nsAString & namespaceURI, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LookupPrefix(namespaceURI, _retval); } \
  NS_IMETHOD IsDefaultNamespace(const nsAString & namespaceURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDefaultNamespace(namespaceURI, _retval); } \
  NS_IMETHOD LookupNamespaceURI(const nsAString & prefix, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LookupNamespaceURI(prefix, _retval); } \
  NS_IMETHOD IsEqualNode(nsIDOMNode *arg, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualNode(arg, _retval); } \
  NS_IMETHOD SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUserData(key, data, handler, _retval); } \
  NS_IMETHOD GetUserData(const nsAString & key, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserData(key, _retval); } \
  NS_IMETHOD Contains(nsIDOMNode *aOther, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Contains(aOther, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNode : public nsIDOMNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNODE

  nsDOMNode();

private:
  ~nsDOMNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNode, nsIDOMNode)

nsDOMNode::nsDOMNode()
{
  /* member initializers and constructor code */
}

nsDOMNode::~nsDOMNode()
{
  /* destructor code */
}

/* readonly attribute DOMString nodeName; */
NS_IMETHODIMP nsDOMNode::GetNodeName(nsAString & aNodeName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString nodeValue; */
NS_IMETHODIMP nsDOMNode::GetNodeValue(nsAString & aNodeValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNode::SetNodeValue(const nsAString & aNodeValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short nodeType; */
NS_IMETHODIMP nsDOMNode::GetNodeType(uint16_t *aNodeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode parentNode; */
NS_IMETHODIMP nsDOMNode::GetParentNode(nsIDOMNode * *aParentNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement parentElement; */
NS_IMETHODIMP nsDOMNode::GetParentElement(nsIDOMElement * *aParentElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNodeList childNodes; */
NS_IMETHODIMP nsDOMNode::GetChildNodes(nsIDOMNodeList * *aChildNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode firstChild; */
NS_IMETHODIMP nsDOMNode::GetFirstChild(nsIDOMNode * *aFirstChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode lastChild; */
NS_IMETHODIMP nsDOMNode::GetLastChild(nsIDOMNode * *aLastChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode previousSibling; */
NS_IMETHODIMP nsDOMNode::GetPreviousSibling(nsIDOMNode * *aPreviousSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode nextSibling; */
NS_IMETHODIMP nsDOMNode::GetNextSibling(nsIDOMNode * *aNextSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument ownerDocument; */
NS_IMETHODIMP nsDOMNode::GetOwnerDocument(nsIDOMDocument * *aOwnerDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode insertBefore (in nsIDOMNode newChild, in nsIDOMNode refChild) raises (DOMException); */
NS_IMETHODIMP nsDOMNode::InsertBefore(nsIDOMNode *newChild, nsIDOMNode *refChild, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode replaceChild (in nsIDOMNode newChild, in nsIDOMNode oldChild) raises (DOMException); */
NS_IMETHODIMP nsDOMNode::ReplaceChild(nsIDOMNode *newChild, nsIDOMNode *oldChild, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode removeChild (in nsIDOMNode oldChild) raises (DOMException); */
NS_IMETHODIMP nsDOMNode::RemoveChild(nsIDOMNode *oldChild, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode appendChild (in nsIDOMNode newChild) raises (DOMException); */
NS_IMETHODIMP nsDOMNode::AppendChild(nsIDOMNode *newChild, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasChildNodes (); */
NS_IMETHODIMP nsDOMNode::HasChildNodes(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMNode cloneNode ([optional] in boolean deep); */
NS_IMETHODIMP nsDOMNode::CloneNode(bool deep, uint8_t _argc, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void normalize (); */
NS_IMETHODIMP nsDOMNode::Normalize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString namespaceURI; */
NS_IMETHODIMP nsDOMNode::GetNamespaceURI(nsAString & aNamespaceURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString prefix; */
NS_IMETHODIMP nsDOMNode::GetPrefix(nsAString & aPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString localName; */
NS_IMETHODIMP nsDOMNode::GetLocalName(nsAString & aLocalName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasAttributes (); */
NS_IMETHODIMP nsDOMNode::HasAttributes(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMBaseURI)] readonly attribute DOMString baseURI; */
NS_IMETHODIMP nsDOMNode::GetDOMBaseURI(nsAString & aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short compareDocumentPosition (in nsIDOMNode other) raises (DOMException); */
NS_IMETHODIMP nsDOMNode::CompareDocumentPosition(nsIDOMNode *other, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString textContent; */
NS_IMETHODIMP nsDOMNode::GetTextContent(nsAString & aTextContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNode::SetTextContent(const nsAString & aTextContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString lookupPrefix (in DOMString namespaceURI); */
NS_IMETHODIMP nsDOMNode::LookupPrefix(const nsAString & namespaceURI, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isDefaultNamespace (in DOMString namespaceURI); */
NS_IMETHODIMP nsDOMNode::IsDefaultNamespace(const nsAString & namespaceURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString lookupNamespaceURI (in DOMString prefix); */
NS_IMETHODIMP nsDOMNode::LookupNamespaceURI(const nsAString & prefix, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualNode (in nsIDOMNode arg); */
NS_IMETHODIMP nsDOMNode::IsEqualNode(nsIDOMNode *arg, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant setUserData (in DOMString key, in nsIVariant data, in nsIDOMUserDataHandler handler); */
NS_IMETHODIMP nsDOMNode::SetUserData(const nsAString & key, nsIVariant *data, nsIDOMUserDataHandler *handler, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getUserData (in DOMString key); */
NS_IMETHODIMP nsDOMNode::GetUserData(const nsAString & key, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean contains (in nsIDOMNode aOther); */
NS_IMETHODIMP nsDOMNode::Contains(nsIDOMNode *aOther, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNode_h__ */
