/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleEditableText.idl
 */

#ifndef __gen_nsIAccessibleEditableText_h__
#define __gen_nsIAccessibleEditableText_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleEditableText */
#define NS_IACCESSIBLEEDITABLETEXT_IID_STR "93d0ba57-0d20-49d1-aede-8fde6699855d"

#define NS_IACCESSIBLEEDITABLETEXT_IID \
  {0x93d0ba57, 0x0d20, 0x49d1, \
    { 0xae, 0xde, 0x8f, 0xde, 0x66, 0x99, 0x85, 0x5d }}

class NS_NO_VTABLE nsIAccessibleEditableText : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEEDITABLETEXT_IID)

  /* void setTextContents (in AString text); */
  NS_IMETHOD SetTextContents(const nsAString & text) = 0;

  /* [binaryname(ScriptableInsertText)] void insertText (in AString text, in long position); */
  NS_IMETHOD ScriptableInsertText(const nsAString & text, int32_t position) = 0;

  /* [binaryname(ScriptableCopyText)] void copyText (in long startPos, in long endPos); */
  NS_IMETHOD ScriptableCopyText(int32_t startPos, int32_t endPos) = 0;

  /* [binaryname(ScriptableCutText)] void cutText (in long startPos, in long endPos); */
  NS_IMETHOD ScriptableCutText(int32_t startPos, int32_t endPos) = 0;

  /* [binaryname(ScriptableDeleteText)] void deleteText (in long startPos, in long endPos); */
  NS_IMETHOD ScriptableDeleteText(int32_t startPos, int32_t endPos) = 0;

  /* [binaryname(ScriptablePasteText)] void pasteText (in long position); */
  NS_IMETHOD ScriptablePasteText(int32_t position) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleEditableText, NS_IACCESSIBLEEDITABLETEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEEDITABLETEXT \
  NS_IMETHOD SetTextContents(const nsAString & text); \
  NS_IMETHOD ScriptableInsertText(const nsAString & text, int32_t position); \
  NS_IMETHOD ScriptableCopyText(int32_t startPos, int32_t endPos); \
  NS_IMETHOD ScriptableCutText(int32_t startPos, int32_t endPos); \
  NS_IMETHOD ScriptableDeleteText(int32_t startPos, int32_t endPos); \
  NS_IMETHOD ScriptablePasteText(int32_t position); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEEDITABLETEXT(_to) \
  NS_IMETHOD SetTextContents(const nsAString & text) { return _to SetTextContents(text); } \
  NS_IMETHOD ScriptableInsertText(const nsAString & text, int32_t position) { return _to ScriptableInsertText(text, position); } \
  NS_IMETHOD ScriptableCopyText(int32_t startPos, int32_t endPos) { return _to ScriptableCopyText(startPos, endPos); } \
  NS_IMETHOD ScriptableCutText(int32_t startPos, int32_t endPos) { return _to ScriptableCutText(startPos, endPos); } \
  NS_IMETHOD ScriptableDeleteText(int32_t startPos, int32_t endPos) { return _to ScriptableDeleteText(startPos, endPos); } \
  NS_IMETHOD ScriptablePasteText(int32_t position) { return _to ScriptablePasteText(position); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEEDITABLETEXT(_to) \
  NS_IMETHOD SetTextContents(const nsAString & text) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextContents(text); } \
  NS_IMETHOD ScriptableInsertText(const nsAString & text, int32_t position) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableInsertText(text, position); } \
  NS_IMETHOD ScriptableCopyText(int32_t startPos, int32_t endPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableCopyText(startPos, endPos); } \
  NS_IMETHOD ScriptableCutText(int32_t startPos, int32_t endPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableCutText(startPos, endPos); } \
  NS_IMETHOD ScriptableDeleteText(int32_t startPos, int32_t endPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableDeleteText(startPos, endPos); } \
  NS_IMETHOD ScriptablePasteText(int32_t position) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptablePasteText(position); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleEditableText : public nsIAccessibleEditableText
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEEDITABLETEXT

  nsAccessibleEditableText();

private:
  ~nsAccessibleEditableText();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleEditableText, nsIAccessibleEditableText)

nsAccessibleEditableText::nsAccessibleEditableText()
{
  /* member initializers and constructor code */
}

nsAccessibleEditableText::~nsAccessibleEditableText()
{
  /* destructor code */
}

/* void setTextContents (in AString text); */
NS_IMETHODIMP nsAccessibleEditableText::SetTextContents(const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableInsertText)] void insertText (in AString text, in long position); */
NS_IMETHODIMP nsAccessibleEditableText::ScriptableInsertText(const nsAString & text, int32_t position)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableCopyText)] void copyText (in long startPos, in long endPos); */
NS_IMETHODIMP nsAccessibleEditableText::ScriptableCopyText(int32_t startPos, int32_t endPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableCutText)] void cutText (in long startPos, in long endPos); */
NS_IMETHODIMP nsAccessibleEditableText::ScriptableCutText(int32_t startPos, int32_t endPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableDeleteText)] void deleteText (in long startPos, in long endPos); */
NS_IMETHODIMP nsAccessibleEditableText::ScriptableDeleteText(int32_t startPos, int32_t endPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptablePasteText)] void pasteText (in long position); */
NS_IMETHODIMP nsAccessibleEditableText::ScriptablePasteText(int32_t position)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleEditableText_h__ */
