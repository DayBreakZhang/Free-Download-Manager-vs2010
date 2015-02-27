/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIClipboard.idl
 */

#ifndef __gen_nsIClipboard_h__
#define __gen_nsIClipboard_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsITransferable_h__
#include "nsITransferable.h"
#endif

#ifndef __gen_nsIClipboardOwner_h__
#include "nsIClipboardOwner.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */


/* starting interface:    nsIClipboard */
#define NS_ICLIPBOARD_IID_STR "ceaa0047-647f-4b8e-ad1c-aff9fa62aa51"

#define NS_ICLIPBOARD_IID \
  {0xceaa0047, 0x647f, 0x4b8e, \
    { 0xad, 0x1c, 0xaf, 0xf9, 0xfa, 0x62, 0xaa, 0x51 }}

class NS_NO_VTABLE nsIClipboard : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIPBOARD_IID)

  enum {
    kSelectionClipboard = 0,
    kGlobalClipboard = 1,
    kFindClipboard = 2
  };

  /* void setData (in nsITransferable aTransferable, in nsIClipboardOwner anOwner, in long aWhichClipboard); */
  NS_IMETHOD SetData(nsITransferable *aTransferable, nsIClipboardOwner *anOwner, int32_t aWhichClipboard) = 0;

  /* void getData (in nsITransferable aTransferable, in long aWhichClipboard); */
  NS_IMETHOD GetData(nsITransferable *aTransferable, int32_t aWhichClipboard) = 0;

  /* void emptyClipboard (in long aWhichClipboard); */
  NS_IMETHOD EmptyClipboard(int32_t aWhichClipboard) = 0;

  /* boolean hasDataMatchingFlavors ([array, size_is (aLength)] in string aFlavorList, in unsigned long aLength, in long aWhichClipboard); */
  NS_IMETHOD HasDataMatchingFlavors(const char * *aFlavorList, uint32_t aLength, int32_t aWhichClipboard, bool *_retval) = 0;

  /* boolean supportsSelectionClipboard (); */
  NS_IMETHOD SupportsSelectionClipboard(bool *_retval) = 0;

  /* boolean supportsFindClipboard (); */
  NS_IMETHOD SupportsFindClipboard(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClipboard, NS_ICLIPBOARD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIPBOARD \
  NS_IMETHOD SetData(nsITransferable *aTransferable, nsIClipboardOwner *anOwner, int32_t aWhichClipboard); \
  NS_IMETHOD GetData(nsITransferable *aTransferable, int32_t aWhichClipboard); \
  NS_IMETHOD EmptyClipboard(int32_t aWhichClipboard); \
  NS_IMETHOD HasDataMatchingFlavors(const char * *aFlavorList, uint32_t aLength, int32_t aWhichClipboard, bool *_retval); \
  NS_IMETHOD SupportsSelectionClipboard(bool *_retval); \
  NS_IMETHOD SupportsFindClipboard(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIPBOARD(_to) \
  NS_IMETHOD SetData(nsITransferable *aTransferable, nsIClipboardOwner *anOwner, int32_t aWhichClipboard) { return _to SetData(aTransferable, anOwner, aWhichClipboard); } \
  NS_IMETHOD GetData(nsITransferable *aTransferable, int32_t aWhichClipboard) { return _to GetData(aTransferable, aWhichClipboard); } \
  NS_IMETHOD EmptyClipboard(int32_t aWhichClipboard) { return _to EmptyClipboard(aWhichClipboard); } \
  NS_IMETHOD HasDataMatchingFlavors(const char * *aFlavorList, uint32_t aLength, int32_t aWhichClipboard, bool *_retval) { return _to HasDataMatchingFlavors(aFlavorList, aLength, aWhichClipboard, _retval); } \
  NS_IMETHOD SupportsSelectionClipboard(bool *_retval) { return _to SupportsSelectionClipboard(_retval); } \
  NS_IMETHOD SupportsFindClipboard(bool *_retval) { return _to SupportsFindClipboard(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIPBOARD(_to) \
  NS_IMETHOD SetData(nsITransferable *aTransferable, nsIClipboardOwner *anOwner, int32_t aWhichClipboard) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(aTransferable, anOwner, aWhichClipboard); } \
  NS_IMETHOD GetData(nsITransferable *aTransferable, int32_t aWhichClipboard) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aTransferable, aWhichClipboard); } \
  NS_IMETHOD EmptyClipboard(int32_t aWhichClipboard) { return !_to ? NS_ERROR_NULL_POINTER : _to->EmptyClipboard(aWhichClipboard); } \
  NS_IMETHOD HasDataMatchingFlavors(const char * *aFlavorList, uint32_t aLength, int32_t aWhichClipboard, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasDataMatchingFlavors(aFlavorList, aLength, aWhichClipboard, _retval); } \
  NS_IMETHOD SupportsSelectionClipboard(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SupportsSelectionClipboard(_retval); } \
  NS_IMETHOD SupportsFindClipboard(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SupportsFindClipboard(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClipboard : public nsIClipboard
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIPBOARD

  nsClipboard();

private:
  ~nsClipboard();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClipboard, nsIClipboard)

nsClipboard::nsClipboard()
{
  /* member initializers and constructor code */
}

nsClipboard::~nsClipboard()
{
  /* destructor code */
}

/* void setData (in nsITransferable aTransferable, in nsIClipboardOwner anOwner, in long aWhichClipboard); */
NS_IMETHODIMP nsClipboard::SetData(nsITransferable *aTransferable, nsIClipboardOwner *anOwner, int32_t aWhichClipboard)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getData (in nsITransferable aTransferable, in long aWhichClipboard); */
NS_IMETHODIMP nsClipboard::GetData(nsITransferable *aTransferable, int32_t aWhichClipboard)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void emptyClipboard (in long aWhichClipboard); */
NS_IMETHODIMP nsClipboard::EmptyClipboard(int32_t aWhichClipboard)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasDataMatchingFlavors ([array, size_is (aLength)] in string aFlavorList, in unsigned long aLength, in long aWhichClipboard); */
NS_IMETHODIMP nsClipboard::HasDataMatchingFlavors(const char * *aFlavorList, uint32_t aLength, int32_t aWhichClipboard, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean supportsSelectionClipboard (); */
NS_IMETHODIMP nsClipboard::SupportsSelectionClipboard(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean supportsFindClipboard (); */
NS_IMETHODIMP nsClipboard::SupportsFindClipboard(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif



#endif /* __gen_nsIClipboard_h__ */
