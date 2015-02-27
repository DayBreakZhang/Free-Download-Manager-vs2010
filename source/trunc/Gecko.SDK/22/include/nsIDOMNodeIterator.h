/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/traversal/nsIDOMNodeIterator.idl
 */

#ifndef __gen_nsIDOMNodeIterator_h__
#define __gen_nsIDOMNodeIterator_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNodeIterator; /* forward declaration */

class nsIDOMNodeFilter; /* forward declaration */


/* starting interface:    nsIDOMNodeIterator */
#define NS_IDOMNODEITERATOR_IID_STR "a86bdac9-ff89-4c94-8160-4fe86733bab8"

#define NS_IDOMNODEITERATOR_IID \
  {0xa86bdac9, 0xff89, 0x4c94, \
    { 0x81, 0x60, 0x4f, 0xe8, 0x67, 0x33, 0xba, 0xb8 }}

class NS_NO_VTABLE nsIDOMNodeIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNODEITERATOR_IID)

  /* readonly attribute nsIDOMNode root; */
  NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) = 0;

  /* readonly attribute unsigned long whatToShow; */
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) = 0;

  /* readonly attribute nsIDOMNodeFilter filter; */
  NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) = 0;

  /* nsIDOMNode nextNode () raises (DOMException); */
  NS_IMETHOD NextNode(nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode previousNode () raises (DOMException); */
  NS_IMETHOD PreviousNode(nsIDOMNode * *_retval) = 0;

  /* void detach (); */
  NS_IMETHOD Detach(void) = 0;

  /* readonly attribute nsIDOMNode referenceNode; */
  NS_IMETHOD GetReferenceNode(nsIDOMNode * *aReferenceNode) = 0;

  /* readonly attribute boolean pointerBeforeReferenceNode; */
  NS_IMETHOD GetPointerBeforeReferenceNode(bool *aPointerBeforeReferenceNode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNodeIterator, NS_IDOMNODEITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNODEITERATOR \
  NS_IMETHOD GetRoot(nsIDOMNode * *aRoot); \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow); \
  NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter); \
  NS_IMETHOD NextNode(nsIDOMNode * *_retval); \
  NS_IMETHOD PreviousNode(nsIDOMNode * *_retval); \
  NS_IMETHOD Detach(void); \
  NS_IMETHOD GetReferenceNode(nsIDOMNode * *aReferenceNode); \
  NS_IMETHOD GetPointerBeforeReferenceNode(bool *aPointerBeforeReferenceNode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNODEITERATOR(_to) \
  NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) { return _to GetRoot(aRoot); } \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) { return _to GetWhatToShow(aWhatToShow); } \
  NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) { return _to GetFilter(aFilter); } \
  NS_IMETHOD NextNode(nsIDOMNode * *_retval) { return _to NextNode(_retval); } \
  NS_IMETHOD PreviousNode(nsIDOMNode * *_retval) { return _to PreviousNode(_retval); } \
  NS_IMETHOD Detach(void) { return _to Detach(); } \
  NS_IMETHOD GetReferenceNode(nsIDOMNode * *aReferenceNode) { return _to GetReferenceNode(aReferenceNode); } \
  NS_IMETHOD GetPointerBeforeReferenceNode(bool *aPointerBeforeReferenceNode) { return _to GetPointerBeforeReferenceNode(aPointerBeforeReferenceNode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNODEITERATOR(_to) \
  NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhatToShow(aWhatToShow); } \
  NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilter(aFilter); } \
  NS_IMETHOD NextNode(nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NextNode(_retval); } \
  NS_IMETHOD PreviousNode(nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreviousNode(_retval); } \
  NS_IMETHOD Detach(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Detach(); } \
  NS_IMETHOD GetReferenceNode(nsIDOMNode * *aReferenceNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferenceNode(aReferenceNode); } \
  NS_IMETHOD GetPointerBeforeReferenceNode(bool *aPointerBeforeReferenceNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPointerBeforeReferenceNode(aPointerBeforeReferenceNode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNodeIterator : public nsIDOMNodeIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNODEITERATOR

  nsDOMNodeIterator();

private:
  ~nsDOMNodeIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNodeIterator, nsIDOMNodeIterator)

nsDOMNodeIterator::nsDOMNodeIterator()
{
  /* member initializers and constructor code */
}

nsDOMNodeIterator::~nsDOMNodeIterator()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode root; */
NS_IMETHODIMP nsDOMNodeIterator::GetRoot(nsIDOMNode * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long whatToShow; */
NS_IMETHODIMP nsDOMNodeIterator::GetWhatToShow(uint32_t *aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNodeFilter filter; */
NS_IMETHODIMP nsDOMNodeIterator::GetFilter(nsIDOMNodeFilter * *aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode nextNode () raises (DOMException); */
NS_IMETHODIMP nsDOMNodeIterator::NextNode(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode previousNode () raises (DOMException); */
NS_IMETHODIMP nsDOMNodeIterator::PreviousNode(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void detach (); */
NS_IMETHODIMP nsDOMNodeIterator::Detach()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode referenceNode; */
NS_IMETHODIMP nsDOMNodeIterator::GetReferenceNode(nsIDOMNode * *aReferenceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean pointerBeforeReferenceNode; */
NS_IMETHODIMP nsDOMNodeIterator::GetPointerBeforeReferenceNode(bool *aPointerBeforeReferenceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNodeIterator_h__ */
