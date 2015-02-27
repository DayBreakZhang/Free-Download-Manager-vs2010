/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/traversal/nsIDOMNodeFilter.idl
 */

#ifndef __gen_nsIDOMNodeFilter_h__
#define __gen_nsIDOMNodeFilter_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNodeFilter */
#define NS_IDOMNODEFILTER_IID_STR "e4723748-1dd1-11b2-8ee6-866a532a6237"

#define NS_IDOMNODEFILTER_IID \
  {0xe4723748, 0x1dd1, 0x11b2, \
    { 0x8e, 0xe6, 0x86, 0x6a, 0x53, 0x2a, 0x62, 0x37 }}

class NS_NO_VTABLE nsIDOMNodeFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNODEFILTER_IID)

  enum {
    FILTER_ACCEPT = 1,
    FILTER_REJECT = 2,
    FILTER_SKIP = 3,
    SHOW_ALL = 4294967295U,
    SHOW_ELEMENT = 1U,
    SHOW_ATTRIBUTE = 2U,
    SHOW_TEXT = 4U,
    SHOW_CDATA_SECTION = 8U,
    SHOW_ENTITY_REFERENCE = 16U,
    SHOW_ENTITY = 32U,
    SHOW_PROCESSING_INSTRUCTION = 64U,
    SHOW_COMMENT = 128U,
    SHOW_DOCUMENT = 256U,
    SHOW_DOCUMENT_TYPE = 512U,
    SHOW_DOCUMENT_FRAGMENT = 1024U,
    SHOW_NOTATION = 2048U
  };

  /* short acceptNode (in nsIDOMNode n); */
  NS_IMETHOD AcceptNode(nsIDOMNode *n, int16_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNodeFilter, NS_IDOMNODEFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNODEFILTER \
  NS_IMETHOD AcceptNode(nsIDOMNode *n, int16_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNODEFILTER(_to) \
  NS_IMETHOD AcceptNode(nsIDOMNode *n, int16_t *_retval) { return _to AcceptNode(n, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNODEFILTER(_to) \
  NS_IMETHOD AcceptNode(nsIDOMNode *n, int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AcceptNode(n, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNodeFilter : public nsIDOMNodeFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNODEFILTER

  nsDOMNodeFilter();

private:
  ~nsDOMNodeFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNodeFilter, nsIDOMNodeFilter)

nsDOMNodeFilter::nsDOMNodeFilter()
{
  /* member initializers and constructor code */
}

nsDOMNodeFilter::~nsDOMNodeFilter()
{
  /* destructor code */
}

/* short acceptNode (in nsIDOMNode n); */
NS_IMETHODIMP nsDOMNodeFilter::AcceptNode(nsIDOMNode *n, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNodeFilter_h__ */
