/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/idl/nsIEditActionListener.idl
 */

#ifndef __gen_nsIEditActionListener_h__
#define __gen_nsIEditActionListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISelection; /* forward declaration */


/* starting interface:    nsIEditActionListener */
#define NS_IEDITACTIONLISTENER_IID_STR "b22907b1-ee93-11d2-8d50-000064657374"

#define NS_IEDITACTIONLISTENER_IID \
  {0xb22907b1, 0xee93, 0x11d2, \
    { 0x8d, 0x50, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

class NS_NO_VTABLE nsIEditActionListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITACTIONLISTENER_IID)

  /* void WillCreateNode (in DOMString aTag, in nsIDOMNode aParent, in long aPosition); */
  NS_IMETHOD WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, int32_t aPosition) = 0;

  /* void DidCreateNode (in DOMString aTag, in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition, in nsresult aResult); */
  NS_IMETHOD DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult) = 0;

  /* void WillInsertNode (in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition); */
  NS_IMETHOD WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition) = 0;

  /* void DidInsertNode (in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition, in nsresult aResult); */
  NS_IMETHOD DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult) = 0;

  /* void WillDeleteNode (in nsIDOMNode aChild); */
  NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild) = 0;

  /* void DidDeleteNode (in nsIDOMNode aChild, in nsresult aResult); */
  NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult) = 0;

  /* void WillSplitNode (in nsIDOMNode aExistingRightNode, in long aOffset); */
  NS_IMETHOD WillSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset) = 0;

  /* void DidSplitNode (in nsIDOMNode aExistingRightNode, in long aOffset, in nsIDOMNode aNewLeftNode, in nsresult aResult); */
  NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult) = 0;

  /* void WillJoinNodes (in nsIDOMNode aLeftNode, in nsIDOMNode aRightNode, in nsIDOMNode aParent); */
  NS_IMETHOD WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent) = 0;

  /* void DidJoinNodes (in nsIDOMNode aLeftNode, in nsIDOMNode aRightNode, in nsIDOMNode aParent, in nsresult aResult); */
  NS_IMETHOD DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult) = 0;

  /* void WillInsertText (in nsIDOMCharacterData aTextNode, in long aOffset, in DOMString aString); */
  NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString) = 0;

  /* void DidInsertText (in nsIDOMCharacterData aTextNode, in long aOffset, in DOMString aString, in nsresult aResult); */
  NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString, nsresult aResult) = 0;

  /* void WillDeleteText (in nsIDOMCharacterData aTextNode, in long aOffset, in long aLength); */
  NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength) = 0;

  /* void DidDeleteText (in nsIDOMCharacterData aTextNode, in long aOffset, in long aLength, in nsresult aResult); */
  NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength, nsresult aResult) = 0;

  /* void WillDeleteSelection (in nsISelection aSelection); */
  NS_IMETHOD WillDeleteSelection(nsISelection *aSelection) = 0;

  /* void DidDeleteSelection (in nsISelection aSelection); */
  NS_IMETHOD DidDeleteSelection(nsISelection *aSelection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditActionListener, NS_IEDITACTIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITACTIONLISTENER \
  NS_IMETHOD WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, int32_t aPosition); \
  NS_IMETHOD DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult); \
  NS_IMETHOD WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition); \
  NS_IMETHOD DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult); \
  NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild); \
  NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult); \
  NS_IMETHOD WillSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset); \
  NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult); \
  NS_IMETHOD WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent); \
  NS_IMETHOD DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult); \
  NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString); \
  NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString, nsresult aResult); \
  NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength); \
  NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength, nsresult aResult); \
  NS_IMETHOD WillDeleteSelection(nsISelection *aSelection); \
  NS_IMETHOD DidDeleteSelection(nsISelection *aSelection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITACTIONLISTENER(_to) \
  NS_IMETHOD WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, int32_t aPosition) { return _to WillCreateNode(aTag, aParent, aPosition); } \
  NS_IMETHOD DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult) { return _to DidCreateNode(aTag, aNode, aParent, aPosition, aResult); } \
  NS_IMETHOD WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition) { return _to WillInsertNode(aNode, aParent, aPosition); } \
  NS_IMETHOD DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult) { return _to DidInsertNode(aNode, aParent, aPosition, aResult); } \
  NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild) { return _to WillDeleteNode(aChild); } \
  NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult) { return _to DidDeleteNode(aChild, aResult); } \
  NS_IMETHOD WillSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset) { return _to WillSplitNode(aExistingRightNode, aOffset); } \
  NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult) { return _to DidSplitNode(aExistingRightNode, aOffset, aNewLeftNode, aResult); } \
  NS_IMETHOD WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent) { return _to WillJoinNodes(aLeftNode, aRightNode, aParent); } \
  NS_IMETHOD DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult) { return _to DidJoinNodes(aLeftNode, aRightNode, aParent, aResult); } \
  NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString) { return _to WillInsertText(aTextNode, aOffset, aString); } \
  NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString, nsresult aResult) { return _to DidInsertText(aTextNode, aOffset, aString, aResult); } \
  NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength) { return _to WillDeleteText(aTextNode, aOffset, aLength); } \
  NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength, nsresult aResult) { return _to DidDeleteText(aTextNode, aOffset, aLength, aResult); } \
  NS_IMETHOD WillDeleteSelection(nsISelection *aSelection) { return _to WillDeleteSelection(aSelection); } \
  NS_IMETHOD DidDeleteSelection(nsISelection *aSelection) { return _to DidDeleteSelection(aSelection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITACTIONLISTENER(_to) \
  NS_IMETHOD WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, int32_t aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillCreateNode(aTag, aParent, aPosition); } \
  NS_IMETHOD DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidCreateNode(aTag, aNode, aParent, aPosition, aResult); } \
  NS_IMETHOD WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillInsertNode(aNode, aParent, aPosition); } \
  NS_IMETHOD DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidInsertNode(aNode, aParent, aPosition, aResult); } \
  NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillDeleteNode(aChild); } \
  NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidDeleteNode(aChild, aResult); } \
  NS_IMETHOD WillSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillSplitNode(aExistingRightNode, aOffset); } \
  NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidSplitNode(aExistingRightNode, aOffset, aNewLeftNode, aResult); } \
  NS_IMETHOD WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillJoinNodes(aLeftNode, aRightNode, aParent); } \
  NS_IMETHOD DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidJoinNodes(aLeftNode, aRightNode, aParent, aResult); } \
  NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillInsertText(aTextNode, aOffset, aString); } \
  NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidInsertText(aTextNode, aOffset, aString, aResult); } \
  NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillDeleteText(aTextNode, aOffset, aLength); } \
  NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidDeleteText(aTextNode, aOffset, aLength, aResult); } \
  NS_IMETHOD WillDeleteSelection(nsISelection *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillDeleteSelection(aSelection); } \
  NS_IMETHOD DidDeleteSelection(nsISelection *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidDeleteSelection(aSelection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditActionListener : public nsIEditActionListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITACTIONLISTENER

  nsEditActionListener();

private:
  ~nsEditActionListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditActionListener, nsIEditActionListener)

nsEditActionListener::nsEditActionListener()
{
  /* member initializers and constructor code */
}

nsEditActionListener::~nsEditActionListener()
{
  /* destructor code */
}

/* void WillCreateNode (in DOMString aTag, in nsIDOMNode aParent, in long aPosition); */
NS_IMETHODIMP nsEditActionListener::WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, int32_t aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidCreateNode (in DOMString aTag, in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillInsertNode (in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition); */
NS_IMETHODIMP nsEditActionListener::WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidInsertNode (in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, int32_t aPosition, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillDeleteNode (in nsIDOMNode aChild); */
NS_IMETHODIMP nsEditActionListener::WillDeleteNode(nsIDOMNode *aChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidDeleteNode (in nsIDOMNode aChild, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidDeleteNode(nsIDOMNode *aChild, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillSplitNode (in nsIDOMNode aExistingRightNode, in long aOffset); */
NS_IMETHODIMP nsEditActionListener::WillSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidSplitNode (in nsIDOMNode aExistingRightNode, in long aOffset, in nsIDOMNode aNewLeftNode, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidSplitNode(nsIDOMNode *aExistingRightNode, int32_t aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillJoinNodes (in nsIDOMNode aLeftNode, in nsIDOMNode aRightNode, in nsIDOMNode aParent); */
NS_IMETHODIMP nsEditActionListener::WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidJoinNodes (in nsIDOMNode aLeftNode, in nsIDOMNode aRightNode, in nsIDOMNode aParent, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillInsertText (in nsIDOMCharacterData aTextNode, in long aOffset, in DOMString aString); */
NS_IMETHODIMP nsEditActionListener::WillInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidInsertText (in nsIDOMCharacterData aTextNode, in long aOffset, in DOMString aString, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidInsertText(nsIDOMCharacterData *aTextNode, int32_t aOffset, const nsAString & aString, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillDeleteText (in nsIDOMCharacterData aTextNode, in long aOffset, in long aLength); */
NS_IMETHODIMP nsEditActionListener::WillDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidDeleteText (in nsIDOMCharacterData aTextNode, in long aOffset, in long aLength, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidDeleteText(nsIDOMCharacterData *aTextNode, int32_t aOffset, int32_t aLength, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillDeleteSelection (in nsISelection aSelection); */
NS_IMETHODIMP nsEditActionListener::WillDeleteSelection(nsISelection *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidDeleteSelection (in nsISelection aSelection); */
NS_IMETHODIMP nsEditActionListener::DidDeleteSelection(nsISelection *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditActionListener_h__ */
