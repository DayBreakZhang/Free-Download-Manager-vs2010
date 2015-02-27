/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/editor/idl/nsIHTMLInlineTableEditor.idl
 */

#ifndef __gen_nsIHTMLInlineTableEditor_h__
#define __gen_nsIHTMLInlineTableEditor_h__


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

/* starting interface:    nsIHTMLInlineTableEditor */
#define NS_IHTMLINLINETABLEEDITOR_IID_STR "eda2e65c-a758-451f-9b05-77cb8de74ed2"

#define NS_IHTMLINLINETABLEEDITOR_IID \
  {0xeda2e65c, 0xa758, 0x451f, \
    { 0x9b, 0x05, 0x77, 0xcb, 0x8d, 0xe7, 0x4e, 0xd2 }}

class NS_NO_VTABLE nsIHTMLInlineTableEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLINLINETABLEEDITOR_IID)

  /* attribute boolean inlineTableEditingEnabled; */
  NS_IMETHOD GetInlineTableEditingEnabled(bool *aInlineTableEditingEnabled) = 0;
  NS_IMETHOD SetInlineTableEditingEnabled(bool aInlineTableEditingEnabled) = 0;

  /* void showInlineTableEditingUI (in nsIDOMElement aCell); */
  NS_IMETHOD ShowInlineTableEditingUI(nsIDOMElement *aCell) = 0;

  /* void hideInlineTableEditingUI (); */
  NS_IMETHOD HideInlineTableEditingUI(void) = 0;

  /* void doInlineTableEditingAction (in nsIDOMElement aUIAnonymousElement); */
  NS_IMETHOD DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement) = 0;

  /* void refreshInlineTableEditingUI (); */
  NS_IMETHOD RefreshInlineTableEditingUI(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLInlineTableEditor, NS_IHTMLINLINETABLEEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLINLINETABLEEDITOR \
  NS_IMETHOD GetInlineTableEditingEnabled(bool *aInlineTableEditingEnabled); \
  NS_IMETHOD SetInlineTableEditingEnabled(bool aInlineTableEditingEnabled); \
  NS_IMETHOD ShowInlineTableEditingUI(nsIDOMElement *aCell); \
  NS_IMETHOD HideInlineTableEditingUI(void); \
  NS_IMETHOD DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement); \
  NS_IMETHOD RefreshInlineTableEditingUI(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLINLINETABLEEDITOR(_to) \
  NS_IMETHOD GetInlineTableEditingEnabled(bool *aInlineTableEditingEnabled) { return _to GetInlineTableEditingEnabled(aInlineTableEditingEnabled); } \
  NS_IMETHOD SetInlineTableEditingEnabled(bool aInlineTableEditingEnabled) { return _to SetInlineTableEditingEnabled(aInlineTableEditingEnabled); } \
  NS_IMETHOD ShowInlineTableEditingUI(nsIDOMElement *aCell) { return _to ShowInlineTableEditingUI(aCell); } \
  NS_IMETHOD HideInlineTableEditingUI(void) { return _to HideInlineTableEditingUI(); } \
  NS_IMETHOD DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement) { return _to DoInlineTableEditingAction(aUIAnonymousElement); } \
  NS_IMETHOD RefreshInlineTableEditingUI(void) { return _to RefreshInlineTableEditingUI(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLINLINETABLEEDITOR(_to) \
  NS_IMETHOD GetInlineTableEditingEnabled(bool *aInlineTableEditingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInlineTableEditingEnabled(aInlineTableEditingEnabled); } \
  NS_IMETHOD SetInlineTableEditingEnabled(bool aInlineTableEditingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInlineTableEditingEnabled(aInlineTableEditingEnabled); } \
  NS_IMETHOD ShowInlineTableEditingUI(nsIDOMElement *aCell) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowInlineTableEditingUI(aCell); } \
  NS_IMETHOD HideInlineTableEditingUI(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HideInlineTableEditingUI(); } \
  NS_IMETHOD DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoInlineTableEditingAction(aUIAnonymousElement); } \
  NS_IMETHOD RefreshInlineTableEditingUI(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshInlineTableEditingUI(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLInlineTableEditor : public nsIHTMLInlineTableEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLINLINETABLEEDITOR

  nsHTMLInlineTableEditor();

private:
  ~nsHTMLInlineTableEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTMLInlineTableEditor, nsIHTMLInlineTableEditor)

nsHTMLInlineTableEditor::nsHTMLInlineTableEditor()
{
  /* member initializers and constructor code */
}

nsHTMLInlineTableEditor::~nsHTMLInlineTableEditor()
{
  /* destructor code */
}

/* attribute boolean inlineTableEditingEnabled; */
NS_IMETHODIMP nsHTMLInlineTableEditor::GetInlineTableEditingEnabled(bool *aInlineTableEditingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLInlineTableEditor::SetInlineTableEditingEnabled(bool aInlineTableEditingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showInlineTableEditingUI (in nsIDOMElement aCell); */
NS_IMETHODIMP nsHTMLInlineTableEditor::ShowInlineTableEditingUI(nsIDOMElement *aCell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hideInlineTableEditingUI (); */
NS_IMETHODIMP nsHTMLInlineTableEditor::HideInlineTableEditingUI()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doInlineTableEditingAction (in nsIDOMElement aUIAnonymousElement); */
NS_IMETHODIMP nsHTMLInlineTableEditor::DoInlineTableEditingAction(nsIDOMElement *aUIAnonymousElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshInlineTableEditingUI (); */
NS_IMETHODIMP nsHTMLInlineTableEditor::RefreshInlineTableEditingUI()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLInlineTableEditor_h__ */
