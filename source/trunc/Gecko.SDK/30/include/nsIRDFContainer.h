/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRDFContainer.idl
 */

#ifndef __gen_nsIRDFContainer_h__
#define __gen_nsIRDFContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFContainer */
#define NS_IRDFCONTAINER_IID_STR "d4214e90-fb94-11d2-bdd8-00104bde6048"

#define NS_IRDFCONTAINER_IID \
  {0xd4214e90, 0xfb94, 0x11d2, \
    { 0xbd, 0xd8, 0x00, 0x10, 0x4b, 0xde, 0x60, 0x48 }}

class NS_NO_VTABLE nsIRDFContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFCONTAINER_IID)

  /* readonly attribute nsIRDFDataSource DataSource; */
  NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) = 0;

  /* readonly attribute nsIRDFResource Resource; */
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) = 0;

  /* void Init (in nsIRDFDataSource aDataSource, in nsIRDFResource aContainer); */
  NS_IMETHOD Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer) = 0;

  /* long GetCount (); */
  NS_IMETHOD GetCount(int32_t *_retval) = 0;

  /* nsISimpleEnumerator GetElements (); */
  NS_IMETHOD GetElements(nsISimpleEnumerator * *_retval) = 0;

  /* void AppendElement (in nsIRDFNode aElement); */
  NS_IMETHOD AppendElement(nsIRDFNode *aElement) = 0;

  /* void RemoveElement (in nsIRDFNode aElement, in boolean aRenumber); */
  NS_IMETHOD RemoveElement(nsIRDFNode *aElement, bool aRenumber) = 0;

  /* void InsertElementAt (in nsIRDFNode aElement, in long aIndex, in boolean aRenumber); */
  NS_IMETHOD InsertElementAt(nsIRDFNode *aElement, int32_t aIndex, bool aRenumber) = 0;

  /* nsIRDFNode RemoveElementAt (in long aIndex, in boolean aRenumber); */
  NS_IMETHOD RemoveElementAt(int32_t aIndex, bool aRenumber, nsIRDFNode * *_retval) = 0;

  /* long IndexOf (in nsIRDFNode aElement); */
  NS_IMETHOD IndexOf(nsIRDFNode *aElement, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFContainer, NS_IRDFCONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFCONTAINER \
  NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource); \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource); \
  NS_IMETHOD Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer); \
  NS_IMETHOD GetCount(int32_t *_retval); \
  NS_IMETHOD GetElements(nsISimpleEnumerator * *_retval); \
  NS_IMETHOD AppendElement(nsIRDFNode *aElement); \
  NS_IMETHOD RemoveElement(nsIRDFNode *aElement, bool aRenumber); \
  NS_IMETHOD InsertElementAt(nsIRDFNode *aElement, int32_t aIndex, bool aRenumber); \
  NS_IMETHOD RemoveElementAt(int32_t aIndex, bool aRenumber, nsIRDFNode * *_retval); \
  NS_IMETHOD IndexOf(nsIRDFNode *aElement, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFCONTAINER(_to) \
  NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) { return _to GetDataSource(aDataSource); } \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) { return _to GetResource(aResource); } \
  NS_IMETHOD Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer) { return _to Init(aDataSource, aContainer); } \
  NS_IMETHOD GetCount(int32_t *_retval) { return _to GetCount(_retval); } \
  NS_IMETHOD GetElements(nsISimpleEnumerator * *_retval) { return _to GetElements(_retval); } \
  NS_IMETHOD AppendElement(nsIRDFNode *aElement) { return _to AppendElement(aElement); } \
  NS_IMETHOD RemoveElement(nsIRDFNode *aElement, bool aRenumber) { return _to RemoveElement(aElement, aRenumber); } \
  NS_IMETHOD InsertElementAt(nsIRDFNode *aElement, int32_t aIndex, bool aRenumber) { return _to InsertElementAt(aElement, aIndex, aRenumber); } \
  NS_IMETHOD RemoveElementAt(int32_t aIndex, bool aRenumber, nsIRDFNode * *_retval) { return _to RemoveElementAt(aIndex, aRenumber, _retval); } \
  NS_IMETHOD IndexOf(nsIRDFNode *aElement, int32_t *_retval) { return _to IndexOf(aElement, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFCONTAINER(_to) \
  NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSource(aDataSource); } \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResource(aResource); } \
  NS_IMETHOD Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDataSource, aContainer); } \
  NS_IMETHOD GetCount(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(_retval); } \
  NS_IMETHOD GetElements(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElements(_retval); } \
  NS_IMETHOD AppendElement(nsIRDFNode *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendElement(aElement); } \
  NS_IMETHOD RemoveElement(nsIRDFNode *aElement, bool aRenumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveElement(aElement, aRenumber); } \
  NS_IMETHOD InsertElementAt(nsIRDFNode *aElement, int32_t aIndex, bool aRenumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertElementAt(aElement, aIndex, aRenumber); } \
  NS_IMETHOD RemoveElementAt(int32_t aIndex, bool aRenumber, nsIRDFNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveElementAt(aIndex, aRenumber, _retval); } \
  NS_IMETHOD IndexOf(nsIRDFNode *aElement, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexOf(aElement, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFContainer : public nsIRDFContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFCONTAINER

  nsRDFContainer();

private:
  ~nsRDFContainer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFContainer, nsIRDFContainer)

nsRDFContainer::nsRDFContainer()
{
  /* member initializers and constructor code */
}

nsRDFContainer::~nsRDFContainer()
{
  /* destructor code */
}

/* readonly attribute nsIRDFDataSource DataSource; */
NS_IMETHODIMP nsRDFContainer::GetDataSource(nsIRDFDataSource * *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFResource Resource; */
NS_IMETHODIMP nsRDFContainer::GetResource(nsIRDFResource * *aResource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Init (in nsIRDFDataSource aDataSource, in nsIRDFResource aContainer); */
NS_IMETHODIMP nsRDFContainer::Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetCount (); */
NS_IMETHODIMP nsRDFContainer::GetCount(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetElements (); */
NS_IMETHODIMP nsRDFContainer::GetElements(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AppendElement (in nsIRDFNode aElement); */
NS_IMETHODIMP nsRDFContainer::AppendElement(nsIRDFNode *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveElement (in nsIRDFNode aElement, in boolean aRenumber); */
NS_IMETHODIMP nsRDFContainer::RemoveElement(nsIRDFNode *aElement, bool aRenumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void InsertElementAt (in nsIRDFNode aElement, in long aIndex, in boolean aRenumber); */
NS_IMETHODIMP nsRDFContainer::InsertElementAt(nsIRDFNode *aElement, int32_t aIndex, bool aRenumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFNode RemoveElementAt (in long aIndex, in boolean aRenumber); */
NS_IMETHODIMP nsRDFContainer::RemoveElementAt(int32_t aIndex, bool aRenumber, nsIRDFNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long IndexOf (in nsIRDFNode aElement); */
NS_IMETHODIMP nsRDFContainer::IndexOf(nsIRDFNode *aElement, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewRDFContainer(nsIRDFContainer** aResult);
nsresult
NS_NewRDFContainer(nsIRDFDataSource* aDataSource,
                   nsIRDFResource* aResource,
                   nsIRDFContainer** aResult);
/**
 * Create a cursor on a container that enumerates its contents in
 * order
 */
nsresult
NS_NewContainerEnumerator(nsIRDFDataSource* aDataSource,
                          nsIRDFResource* aContainer,
                          nsISimpleEnumerator** aResult);

#endif /* __gen_nsIRDFContainer_h__ */
