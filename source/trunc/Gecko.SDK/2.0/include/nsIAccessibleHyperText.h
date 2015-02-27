/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/accessible/public/nsIAccessibleHyperText.idl
 */

#ifndef __gen_nsIAccessibleHyperText_h__
#define __gen_nsIAccessibleHyperText_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAccessibleHyperLink_h__
#include "nsIAccessibleHyperLink.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleHyperText */
#define NS_IACCESSIBLEHYPERTEXT_IID_STR "b33684e2-090c-4e1d-a3d9-f4b46f4237b9"

#define NS_IACCESSIBLEHYPERTEXT_IID \
  {0xb33684e2, 0x090c, 0x4e1d, \
    { 0xa3, 0xd9, 0xf4, 0xb4, 0x6f, 0x42, 0x37, 0xb9 }}

/**
 * A cross-platform interface that deals with text which contains hyperlinks.
 * Each link is an embedded object representing exactly 1 character within
 * the hypertext.
 *
 * Current implementation assumes every embedded object is a link.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleHyperText : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEHYPERTEXT_IID)

  /**
   * Return the number of links contained within this hypertext object.
   */
  /* readonly attribute long linkCount; */
  NS_SCRIPTABLE NS_IMETHOD GetLinkCount(PRInt32 *aLinkCount) = 0;

  /**
   * Return link accessible at the given index.
   *
   * @param index  [in] 0-based index of the link that is to be retrieved
   *
   * @return       link accessible or null if there is no link at that index
   */
  /* nsIAccessibleHyperLink getLinkAt (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetLinkAt(PRInt32 index, nsIAccessibleHyperLink **_retval NS_OUTPARAM) = 0;

  /**
   * Return index of the given link.
   *
   * @param link  [in] link accessible the index is requested for
   *
   * @return      index of the given link or null if there's no link within
   *                hypertext accessible
   */
  /* long getLinkIndex (in nsIAccessibleHyperLink link); */
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndex(nsIAccessibleHyperLink *link, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long getLinkIndexAtOffset (in long offset); */
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndexAtOffset(PRInt32 offset, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleHyperText, NS_IACCESSIBLEHYPERTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEHYPERTEXT \
  NS_SCRIPTABLE NS_IMETHOD GetLinkCount(PRInt32 *aLinkCount); \
  NS_SCRIPTABLE NS_IMETHOD GetLinkAt(PRInt32 index, nsIAccessibleHyperLink **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndex(nsIAccessibleHyperLink *link, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndexAtOffset(PRInt32 offset, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEHYPERTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLinkCount(PRInt32 *aLinkCount) { return _to GetLinkCount(aLinkCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkAt(PRInt32 index, nsIAccessibleHyperLink **_retval NS_OUTPARAM) { return _to GetLinkAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndex(nsIAccessibleHyperLink *link, PRInt32 *_retval NS_OUTPARAM) { return _to GetLinkIndex(link, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndexAtOffset(PRInt32 offset, PRInt32 *_retval NS_OUTPARAM) { return _to GetLinkIndexAtOffset(offset, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEHYPERTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLinkCount(PRInt32 *aLinkCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkCount(aLinkCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkAt(PRInt32 index, nsIAccessibleHyperLink **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndex(nsIAccessibleHyperLink *link, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkIndex(link, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndexAtOffset(PRInt32 offset, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkIndexAtOffset(offset, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleHyperText : public nsIAccessibleHyperText
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEHYPERTEXT

  nsAccessibleHyperText();

private:
  ~nsAccessibleHyperText();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleHyperText, nsIAccessibleHyperText)

nsAccessibleHyperText::nsAccessibleHyperText()
{
  /* member initializers and constructor code */
}

nsAccessibleHyperText::~nsAccessibleHyperText()
{
  /* destructor code */
}

/* readonly attribute long linkCount; */
NS_IMETHODIMP nsAccessibleHyperText::GetLinkCount(PRInt32 *aLinkCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleHyperLink getLinkAt (in long index); */
NS_IMETHODIMP nsAccessibleHyperText::GetLinkAt(PRInt32 index, nsIAccessibleHyperLink **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getLinkIndex (in nsIAccessibleHyperLink link); */
NS_IMETHODIMP nsAccessibleHyperText::GetLinkIndex(nsIAccessibleHyperLink *link, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getLinkIndexAtOffset (in long offset); */
NS_IMETHODIMP nsAccessibleHyperText::GetLinkIndexAtOffset(PRInt32 offset, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleHyperText_h__ */
