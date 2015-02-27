/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsIContentViewerEdit.idl
 */

#ifndef __gen_nsIContentViewerEdit_h__
#define __gen_nsIContentViewerEdit_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIContentViewerEdit */
#define NS_ICONTENTVIEWEREDIT_IID_STR "af13ea3a-d488-4308-b843-526e055ab943"

#define NS_ICONTENTVIEWEREDIT_IID \
  {0xaf13ea3a, 0xd488, 0x4308, \
    { 0xb8, 0x43, 0x52, 0x6e, 0x05, 0x5a, 0xb9, 0x43 }}

class NS_NO_VTABLE nsIContentViewerEdit : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWEREDIT_IID)

  /* void clearSelection (); */
  NS_IMETHOD ClearSelection(void) = 0;

  /* void selectAll (); */
  NS_IMETHOD SelectAll(void) = 0;

  /* void copySelection (); */
  NS_IMETHOD CopySelection(void) = 0;

  /* readonly attribute boolean copyable; */
  NS_IMETHOD GetCopyable(bool *aCopyable) = 0;

  /* void copyLinkLocation (); */
  NS_IMETHOD CopyLinkLocation(void) = 0;

  /* readonly attribute boolean inLink; */
  NS_IMETHOD GetInLink(bool *aInLink) = 0;

  enum {
    COPY_IMAGE_TEXT = 1,
    COPY_IMAGE_HTML = 2,
    COPY_IMAGE_DATA = 4,
    COPY_IMAGE_ALL = -1
  };

  /* void copyImage (in long aCopyFlags); */
  NS_IMETHOD CopyImage(int32_t aCopyFlags) = 0;

  /* readonly attribute boolean inImage; */
  NS_IMETHOD GetInImage(bool *aInImage) = 0;

  /* AString getContents (in string aMimeType, in boolean aSelectionOnly); */
  NS_IMETHOD GetContents(const char * aMimeType, bool aSelectionOnly, nsAString & _retval) = 0;

  /* readonly attribute boolean canGetContents; */
  NS_IMETHOD GetCanGetContents(bool *aCanGetContents) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewerEdit, NS_ICONTENTVIEWEREDIT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWEREDIT \
  NS_IMETHOD ClearSelection(void); \
  NS_IMETHOD SelectAll(void); \
  NS_IMETHOD CopySelection(void); \
  NS_IMETHOD GetCopyable(bool *aCopyable); \
  NS_IMETHOD CopyLinkLocation(void); \
  NS_IMETHOD GetInLink(bool *aInLink); \
  NS_IMETHOD CopyImage(int32_t aCopyFlags); \
  NS_IMETHOD GetInImage(bool *aInImage); \
  NS_IMETHOD GetContents(const char * aMimeType, bool aSelectionOnly, nsAString & _retval); \
  NS_IMETHOD GetCanGetContents(bool *aCanGetContents); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWEREDIT(_to) \
  NS_IMETHOD ClearSelection(void) { return _to ClearSelection(); } \
  NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_IMETHOD CopySelection(void) { return _to CopySelection(); } \
  NS_IMETHOD GetCopyable(bool *aCopyable) { return _to GetCopyable(aCopyable); } \
  NS_IMETHOD CopyLinkLocation(void) { return _to CopyLinkLocation(); } \
  NS_IMETHOD GetInLink(bool *aInLink) { return _to GetInLink(aInLink); } \
  NS_IMETHOD CopyImage(int32_t aCopyFlags) { return _to CopyImage(aCopyFlags); } \
  NS_IMETHOD GetInImage(bool *aInImage) { return _to GetInImage(aInImage); } \
  NS_IMETHOD GetContents(const char * aMimeType, bool aSelectionOnly, nsAString & _retval) { return _to GetContents(aMimeType, aSelectionOnly, _retval); } \
  NS_IMETHOD GetCanGetContents(bool *aCanGetContents) { return _to GetCanGetContents(aCanGetContents); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWEREDIT(_to) \
  NS_IMETHOD ClearSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearSelection(); } \
  NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_IMETHOD CopySelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopySelection(); } \
  NS_IMETHOD GetCopyable(bool *aCopyable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCopyable(aCopyable); } \
  NS_IMETHOD CopyLinkLocation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyLinkLocation(); } \
  NS_IMETHOD GetInLink(bool *aInLink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInLink(aInLink); } \
  NS_IMETHOD CopyImage(int32_t aCopyFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyImage(aCopyFlags); } \
  NS_IMETHOD GetInImage(bool *aInImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInImage(aInImage); } \
  NS_IMETHOD GetContents(const char * aMimeType, bool aSelectionOnly, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContents(aMimeType, aSelectionOnly, _retval); } \
  NS_IMETHOD GetCanGetContents(bool *aCanGetContents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanGetContents(aCanGetContents); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentViewerEdit : public nsIContentViewerEdit
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEWEREDIT

  nsContentViewerEdit();

private:
  ~nsContentViewerEdit();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentViewerEdit, nsIContentViewerEdit)

nsContentViewerEdit::nsContentViewerEdit()
{
  /* member initializers and constructor code */
}

nsContentViewerEdit::~nsContentViewerEdit()
{
  /* destructor code */
}

/* void clearSelection (); */
NS_IMETHODIMP nsContentViewerEdit::ClearSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsContentViewerEdit::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copySelection (); */
NS_IMETHODIMP nsContentViewerEdit::CopySelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean copyable; */
NS_IMETHODIMP nsContentViewerEdit::GetCopyable(bool *aCopyable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyLinkLocation (); */
NS_IMETHODIMP nsContentViewerEdit::CopyLinkLocation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inLink; */
NS_IMETHODIMP nsContentViewerEdit::GetInLink(bool *aInLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyImage (in long aCopyFlags); */
NS_IMETHODIMP nsContentViewerEdit::CopyImage(int32_t aCopyFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inImage; */
NS_IMETHODIMP nsContentViewerEdit::GetInImage(bool *aInImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getContents (in string aMimeType, in boolean aSelectionOnly); */
NS_IMETHODIMP nsContentViewerEdit::GetContents(const char * aMimeType, bool aSelectionOnly, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canGetContents; */
NS_IMETHODIMP nsContentViewerEdit::GetCanGetContents(bool *aCanGetContents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentViewerEdit_h__ */
