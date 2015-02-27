/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/rdf/base/idl/nsIRDFContainerUtils.idl
 */

#ifndef __gen_nsIRDFContainerUtils_h__
#define __gen_nsIRDFContainerUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFContainer_h__
#include "nsIRDFContainer.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFContainerUtils */
#define NS_IRDFCONTAINERUTILS_IID_STR "d4214e91-fb94-11d2-bdd8-00104bde6048"

#define NS_IRDFCONTAINERUTILS_IID \
  {0xd4214e91, 0xfb94, 0x11d2, \
    { 0xbd, 0xd8, 0x00, 0x10, 0x4b, 0xde, 0x60, 0x48 }}

class NS_NO_VTABLE nsIRDFContainerUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFCONTAINERUTILS_IID)

  /* boolean IsOrdinalProperty (in nsIRDFResource aProperty); */
  NS_IMETHOD IsOrdinalProperty(nsIRDFResource *aProperty, bool *_retval) = 0;

  /* nsIRDFResource IndexToOrdinalResource (in long aIndex); */
  NS_IMETHOD IndexToOrdinalResource(int32_t aIndex, nsIRDFResource * *_retval) = 0;

  /* long OrdinalResourceToIndex (in nsIRDFResource aOrdinal); */
  NS_IMETHOD OrdinalResourceToIndex(nsIRDFResource *aOrdinal, int32_t *_retval) = 0;

  /* boolean IsContainer (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_IMETHOD IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) = 0;

  /* boolean IsEmpty (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_IMETHOD IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) = 0;

  /* boolean IsBag (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_IMETHOD IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) = 0;

  /* boolean IsSeq (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_IMETHOD IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) = 0;

  /* boolean IsAlt (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_IMETHOD IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) = 0;

  /* nsIRDFContainer MakeBag (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_IMETHOD MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) = 0;

  /* nsIRDFContainer MakeSeq (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_IMETHOD MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) = 0;

  /* nsIRDFContainer MakeAlt (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_IMETHOD MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) = 0;

  /* long indexOf (in nsIRDFDataSource aDataSource, in nsIRDFResource aContainer, in nsIRDFNode aElement); */
  NS_IMETHOD IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFContainerUtils, NS_IRDFCONTAINERUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFCONTAINERUTILS \
  NS_IMETHOD IsOrdinalProperty(nsIRDFResource *aProperty, bool *_retval); \
  NS_IMETHOD IndexToOrdinalResource(int32_t aIndex, nsIRDFResource * *_retval); \
  NS_IMETHOD OrdinalResourceToIndex(nsIRDFResource *aOrdinal, int32_t *_retval); \
  NS_IMETHOD IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval); \
  NS_IMETHOD IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval); \
  NS_IMETHOD IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval); \
  NS_IMETHOD IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval); \
  NS_IMETHOD IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval); \
  NS_IMETHOD MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval); \
  NS_IMETHOD MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval); \
  NS_IMETHOD MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval); \
  NS_IMETHOD IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFCONTAINERUTILS(_to) \
  NS_IMETHOD IsOrdinalProperty(nsIRDFResource *aProperty, bool *_retval) { return _to IsOrdinalProperty(aProperty, _retval); } \
  NS_IMETHOD IndexToOrdinalResource(int32_t aIndex, nsIRDFResource * *_retval) { return _to IndexToOrdinalResource(aIndex, _retval); } \
  NS_IMETHOD OrdinalResourceToIndex(nsIRDFResource *aOrdinal, int32_t *_retval) { return _to OrdinalResourceToIndex(aOrdinal, _retval); } \
  NS_IMETHOD IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return _to IsContainer(aDataSource, aResource, _retval); } \
  NS_IMETHOD IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return _to IsEmpty(aDataSource, aResource, _retval); } \
  NS_IMETHOD IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return _to IsBag(aDataSource, aResource, _retval); } \
  NS_IMETHOD IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return _to IsSeq(aDataSource, aResource, _retval); } \
  NS_IMETHOD IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return _to IsAlt(aDataSource, aResource, _retval); } \
  NS_IMETHOD MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) { return _to MakeBag(aDataSource, aResource, _retval); } \
  NS_IMETHOD MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) { return _to MakeSeq(aDataSource, aResource, _retval); } \
  NS_IMETHOD MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) { return _to MakeAlt(aDataSource, aResource, _retval); } \
  NS_IMETHOD IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, int32_t *_retval) { return _to IndexOf(aDataSource, aContainer, aElement, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFCONTAINERUTILS(_to) \
  NS_IMETHOD IsOrdinalProperty(nsIRDFResource *aProperty, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsOrdinalProperty(aProperty, _retval); } \
  NS_IMETHOD IndexToOrdinalResource(int32_t aIndex, nsIRDFResource * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexToOrdinalResource(aIndex, _retval); } \
  NS_IMETHOD OrdinalResourceToIndex(nsIRDFResource *aOrdinal, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OrdinalResourceToIndex(aOrdinal, _retval); } \
  NS_IMETHOD IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsContainer(aDataSource, aResource, _retval); } \
  NS_IMETHOD IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEmpty(aDataSource, aResource, _retval); } \
  NS_IMETHOD IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBag(aDataSource, aResource, _retval); } \
  NS_IMETHOD IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSeq(aDataSource, aResource, _retval); } \
  NS_IMETHOD IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAlt(aDataSource, aResource, _retval); } \
  NS_IMETHOD MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeBag(aDataSource, aResource, _retval); } \
  NS_IMETHOD MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeSeq(aDataSource, aResource, _retval); } \
  NS_IMETHOD MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeAlt(aDataSource, aResource, _retval); } \
  NS_IMETHOD IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexOf(aDataSource, aContainer, aElement, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFContainerUtils : public nsIRDFContainerUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFCONTAINERUTILS

  nsRDFContainerUtils();

private:
  ~nsRDFContainerUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFContainerUtils, nsIRDFContainerUtils)

nsRDFContainerUtils::nsRDFContainerUtils()
{
  /* member initializers and constructor code */
}

nsRDFContainerUtils::~nsRDFContainerUtils()
{
  /* destructor code */
}

/* boolean IsOrdinalProperty (in nsIRDFResource aProperty); */
NS_IMETHODIMP nsRDFContainerUtils::IsOrdinalProperty(nsIRDFResource *aProperty, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFResource IndexToOrdinalResource (in long aIndex); */
NS_IMETHODIMP nsRDFContainerUtils::IndexToOrdinalResource(int32_t aIndex, nsIRDFResource * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long OrdinalResourceToIndex (in nsIRDFResource aOrdinal); */
NS_IMETHODIMP nsRDFContainerUtils::OrdinalResourceToIndex(nsIRDFResource *aOrdinal, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsContainer (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsEmpty (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsBag (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsSeq (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsAlt (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFContainer MakeBag (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFContainer MakeSeq (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFContainer MakeAlt (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long indexOf (in nsIRDFDataSource aDataSource, in nsIRDFResource aContainer, in nsIRDFNode aElement); */
NS_IMETHODIMP nsRDFContainerUtils::IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

extern nsresult
NS_NewRDFContainerUtils(nsIRDFContainerUtils** aResult);

#endif /* __gen_nsIRDFContainerUtils_h__ */
