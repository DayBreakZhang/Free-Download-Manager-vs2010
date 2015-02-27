/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessibleHyperLink.idl
 */

#ifndef __gen_nsIAccessibleHyperLink_h__
#define __gen_nsIAccessibleHyperLink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIAccessible; /* forward declaration */


/* starting interface:    nsIAccessibleHyperLink */
#define NS_IACCESSIBLEHYPERLINK_IID_STR "38c60bfa-6040-4bfe-93f2-acd6a909bb60"

#define NS_IACCESSIBLEHYPERLINK_IID \
  {0x38c60bfa, 0x6040, 0x4bfe, \
    { 0x93, 0xf2, 0xac, 0xd6, 0xa9, 0x09, 0xbb, 0x60 }}

class NS_NO_VTABLE nsIAccessibleHyperLink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEHYPERLINK_IID)

  /* readonly attribute long startIndex; */
  NS_IMETHOD GetStartIndex(int32_t *aStartIndex) = 0;

  /* readonly attribute long endIndex; */
  NS_IMETHOD GetEndIndex(int32_t *aEndIndex) = 0;

  /* readonly attribute boolean valid; */
  NS_IMETHOD GetValid(bool *aValid) = 0;

  /* readonly attribute boolean selected; */
  NS_IMETHOD GetSelected(bool *aSelected) = 0;

  /* readonly attribute long anchorCount; */
  NS_IMETHOD GetAnchorCount(int32_t *aAnchorCount) = 0;

  /* nsIURI getURI (in long index); */
  NS_IMETHOD GetURI(int32_t index, nsIURI * *_retval) = 0;

  /* nsIAccessible getAnchor (in long index); */
  NS_IMETHOD GetAnchor(int32_t index, nsIAccessible * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleHyperLink, NS_IACCESSIBLEHYPERLINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEHYPERLINK \
  NS_IMETHOD GetStartIndex(int32_t *aStartIndex); \
  NS_IMETHOD GetEndIndex(int32_t *aEndIndex); \
  NS_IMETHOD GetValid(bool *aValid); \
  NS_IMETHOD GetSelected(bool *aSelected); \
  NS_IMETHOD GetAnchorCount(int32_t *aAnchorCount); \
  NS_IMETHOD GetURI(int32_t index, nsIURI * *_retval); \
  NS_IMETHOD GetAnchor(int32_t index, nsIAccessible * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEHYPERLINK(_to) \
  NS_IMETHOD GetStartIndex(int32_t *aStartIndex) { return _to GetStartIndex(aStartIndex); } \
  NS_IMETHOD GetEndIndex(int32_t *aEndIndex) { return _to GetEndIndex(aEndIndex); } \
  NS_IMETHOD GetValid(bool *aValid) { return _to GetValid(aValid); } \
  NS_IMETHOD GetSelected(bool *aSelected) { return _to GetSelected(aSelected); } \
  NS_IMETHOD GetAnchorCount(int32_t *aAnchorCount) { return _to GetAnchorCount(aAnchorCount); } \
  NS_IMETHOD GetURI(int32_t index, nsIURI * *_retval) { return _to GetURI(index, _retval); } \
  NS_IMETHOD GetAnchor(int32_t index, nsIAccessible * *_retval) { return _to GetAnchor(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEHYPERLINK(_to) \
  NS_IMETHOD GetStartIndex(int32_t *aStartIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartIndex(aStartIndex); } \
  NS_IMETHOD GetEndIndex(int32_t *aEndIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndIndex(aEndIndex); } \
  NS_IMETHOD GetValid(bool *aValid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValid(aValid); } \
  NS_IMETHOD GetSelected(bool *aSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelected(aSelected); } \
  NS_IMETHOD GetAnchorCount(int32_t *aAnchorCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnchorCount(aAnchorCount); } \
  NS_IMETHOD GetURI(int32_t index, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(index, _retval); } \
  NS_IMETHOD GetAnchor(int32_t index, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnchor(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleHyperLink : public nsIAccessibleHyperLink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEHYPERLINK

  nsAccessibleHyperLink();

private:
  ~nsAccessibleHyperLink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleHyperLink, nsIAccessibleHyperLink)

nsAccessibleHyperLink::nsAccessibleHyperLink()
{
  /* member initializers and constructor code */
}

nsAccessibleHyperLink::~nsAccessibleHyperLink()
{
  /* destructor code */
}

/* readonly attribute long startIndex; */
NS_IMETHODIMP nsAccessibleHyperLink::GetStartIndex(int32_t *aStartIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long endIndex; */
NS_IMETHODIMP nsAccessibleHyperLink::GetEndIndex(int32_t *aEndIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean valid; */
NS_IMETHODIMP nsAccessibleHyperLink::GetValid(bool *aValid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean selected; */
NS_IMETHODIMP nsAccessibleHyperLink::GetSelected(bool *aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long anchorCount; */
NS_IMETHODIMP nsAccessibleHyperLink::GetAnchorCount(int32_t *aAnchorCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getURI (in long index); */
NS_IMETHODIMP nsAccessibleHyperLink::GetURI(int32_t index, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAnchor (in long index); */
NS_IMETHODIMP nsAccessibleHyperLink::GetAnchor(int32_t index, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleHyperLink_h__ */
