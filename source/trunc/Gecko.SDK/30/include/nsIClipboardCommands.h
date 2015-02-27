/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIClipboardCommands.idl
 */

#ifndef __gen_nsIClipboardCommands_h__
#define __gen_nsIClipboardCommands_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIClipboardCommands */
#define NS_ICLIPBOARDCOMMANDS_IID_STR "b8100c90-73be-11d2-92a5-00105a1b0d64"

#define NS_ICLIPBOARDCOMMANDS_IID \
  {0xb8100c90, 0x73be, 0x11d2, \
    { 0x92, 0xa5, 0x00, 0x10, 0x5a, 0x1b, 0x0d, 0x64 }}

class NS_NO_VTABLE nsIClipboardCommands : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIPBOARDCOMMANDS_IID)

  /* boolean canCutSelection (); */
  NS_IMETHOD CanCutSelection(bool *_retval) = 0;

  /* boolean canCopySelection (); */
  NS_IMETHOD CanCopySelection(bool *_retval) = 0;

  /* boolean canCopyLinkLocation (); */
  NS_IMETHOD CanCopyLinkLocation(bool *_retval) = 0;

  /* boolean canCopyImageLocation (); */
  NS_IMETHOD CanCopyImageLocation(bool *_retval) = 0;

  /* boolean canCopyImageContents (); */
  NS_IMETHOD CanCopyImageContents(bool *_retval) = 0;

  /* boolean canPaste (); */
  NS_IMETHOD CanPaste(bool *_retval) = 0;

  /* void cutSelection (); */
  NS_IMETHOD CutSelection(void) = 0;

  /* void copySelection (); */
  NS_IMETHOD CopySelection(void) = 0;

  /* void copyLinkLocation (); */
  NS_IMETHOD CopyLinkLocation(void) = 0;

  /* void copyImageLocation (); */
  NS_IMETHOD CopyImageLocation(void) = 0;

  /* void copyImageContents (); */
  NS_IMETHOD CopyImageContents(void) = 0;

  /* void paste (); */
  NS_IMETHOD Paste(void) = 0;

  /* void selectAll (); */
  NS_IMETHOD SelectAll(void) = 0;

  /* void selectNone (); */
  NS_IMETHOD SelectNone(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClipboardCommands, NS_ICLIPBOARDCOMMANDS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIPBOARDCOMMANDS \
  NS_IMETHOD CanCutSelection(bool *_retval); \
  NS_IMETHOD CanCopySelection(bool *_retval); \
  NS_IMETHOD CanCopyLinkLocation(bool *_retval); \
  NS_IMETHOD CanCopyImageLocation(bool *_retval); \
  NS_IMETHOD CanCopyImageContents(bool *_retval); \
  NS_IMETHOD CanPaste(bool *_retval); \
  NS_IMETHOD CutSelection(void); \
  NS_IMETHOD CopySelection(void); \
  NS_IMETHOD CopyLinkLocation(void); \
  NS_IMETHOD CopyImageLocation(void); \
  NS_IMETHOD CopyImageContents(void); \
  NS_IMETHOD Paste(void); \
  NS_IMETHOD SelectAll(void); \
  NS_IMETHOD SelectNone(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIPBOARDCOMMANDS(_to) \
  NS_IMETHOD CanCutSelection(bool *_retval) { return _to CanCutSelection(_retval); } \
  NS_IMETHOD CanCopySelection(bool *_retval) { return _to CanCopySelection(_retval); } \
  NS_IMETHOD CanCopyLinkLocation(bool *_retval) { return _to CanCopyLinkLocation(_retval); } \
  NS_IMETHOD CanCopyImageLocation(bool *_retval) { return _to CanCopyImageLocation(_retval); } \
  NS_IMETHOD CanCopyImageContents(bool *_retval) { return _to CanCopyImageContents(_retval); } \
  NS_IMETHOD CanPaste(bool *_retval) { return _to CanPaste(_retval); } \
  NS_IMETHOD CutSelection(void) { return _to CutSelection(); } \
  NS_IMETHOD CopySelection(void) { return _to CopySelection(); } \
  NS_IMETHOD CopyLinkLocation(void) { return _to CopyLinkLocation(); } \
  NS_IMETHOD CopyImageLocation(void) { return _to CopyImageLocation(); } \
  NS_IMETHOD CopyImageContents(void) { return _to CopyImageContents(); } \
  NS_IMETHOD Paste(void) { return _to Paste(); } \
  NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_IMETHOD SelectNone(void) { return _to SelectNone(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIPBOARDCOMMANDS(_to) \
  NS_IMETHOD CanCutSelection(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCutSelection(_retval); } \
  NS_IMETHOD CanCopySelection(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCopySelection(_retval); } \
  NS_IMETHOD CanCopyLinkLocation(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCopyLinkLocation(_retval); } \
  NS_IMETHOD CanCopyImageLocation(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCopyImageLocation(_retval); } \
  NS_IMETHOD CanCopyImageContents(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCopyImageContents(_retval); } \
  NS_IMETHOD CanPaste(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPaste(_retval); } \
  NS_IMETHOD CutSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CutSelection(); } \
  NS_IMETHOD CopySelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopySelection(); } \
  NS_IMETHOD CopyLinkLocation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyLinkLocation(); } \
  NS_IMETHOD CopyImageLocation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyImageLocation(); } \
  NS_IMETHOD CopyImageContents(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyImageContents(); } \
  NS_IMETHOD Paste(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Paste(); } \
  NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_IMETHOD SelectNone(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectNone(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClipboardCommands : public nsIClipboardCommands
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIPBOARDCOMMANDS

  nsClipboardCommands();

private:
  ~nsClipboardCommands();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClipboardCommands, nsIClipboardCommands)

nsClipboardCommands::nsClipboardCommands()
{
  /* member initializers and constructor code */
}

nsClipboardCommands::~nsClipboardCommands()
{
  /* destructor code */
}

/* boolean canCutSelection (); */
NS_IMETHODIMP nsClipboardCommands::CanCutSelection(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCopySelection (); */
NS_IMETHODIMP nsClipboardCommands::CanCopySelection(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCopyLinkLocation (); */
NS_IMETHODIMP nsClipboardCommands::CanCopyLinkLocation(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCopyImageLocation (); */
NS_IMETHODIMP nsClipboardCommands::CanCopyImageLocation(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCopyImageContents (); */
NS_IMETHODIMP nsClipboardCommands::CanCopyImageContents(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canPaste (); */
NS_IMETHODIMP nsClipboardCommands::CanPaste(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cutSelection (); */
NS_IMETHODIMP nsClipboardCommands::CutSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copySelection (); */
NS_IMETHODIMP nsClipboardCommands::CopySelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyLinkLocation (); */
NS_IMETHODIMP nsClipboardCommands::CopyLinkLocation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyImageLocation (); */
NS_IMETHODIMP nsClipboardCommands::CopyImageLocation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyImageContents (); */
NS_IMETHODIMP nsClipboardCommands::CopyImageContents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void paste (); */
NS_IMETHODIMP nsClipboardCommands::Paste()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsClipboardCommands::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectNone (); */
NS_IMETHODIMP nsClipboardCommands::SelectNone()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClipboardCommands_h__ */
