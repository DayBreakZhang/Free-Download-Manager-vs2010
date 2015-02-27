/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRDFCompositeDataSource.idl
 */

#ifndef __gen_nsIRDFCompositeDataSource_h__
#define __gen_nsIRDFCompositeDataSource_h__


#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIRDFCompositeDataSource */
#define NS_IRDFCOMPOSITEDATASOURCE_IID_STR "96343820-307c-11d2-bc15-00805f912fe7"

#define NS_IRDFCOMPOSITEDATASOURCE_IID \
  {0x96343820, 0x307c, 0x11d2, \
    { 0xbc, 0x15, 0x00, 0x80, 0x5f, 0x91, 0x2f, 0xe7 }}

class NS_NO_VTABLE nsIRDFCompositeDataSource : public nsIRDFDataSource {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFCOMPOSITEDATASOURCE_IID)

  /* attribute boolean allowNegativeAssertions; */
  NS_IMETHOD GetAllowNegativeAssertions(bool *aAllowNegativeAssertions) = 0;
  NS_IMETHOD SetAllowNegativeAssertions(bool aAllowNegativeAssertions) = 0;

  /* attribute boolean coalesceDuplicateArcs; */
  NS_IMETHOD GetCoalesceDuplicateArcs(bool *aCoalesceDuplicateArcs) = 0;
  NS_IMETHOD SetCoalesceDuplicateArcs(bool aCoalesceDuplicateArcs) = 0;

  /* void AddDataSource (in nsIRDFDataSource aDataSource); */
  NS_IMETHOD AddDataSource(nsIRDFDataSource *aDataSource) = 0;

  /* void RemoveDataSource (in nsIRDFDataSource aDataSource); */
  NS_IMETHOD RemoveDataSource(nsIRDFDataSource *aDataSource) = 0;

  /* nsISimpleEnumerator GetDataSources (); */
  NS_IMETHOD GetDataSources(nsISimpleEnumerator * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFCompositeDataSource, NS_IRDFCOMPOSITEDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFCOMPOSITEDATASOURCE \
  NS_IMETHOD GetAllowNegativeAssertions(bool *aAllowNegativeAssertions); \
  NS_IMETHOD SetAllowNegativeAssertions(bool aAllowNegativeAssertions); \
  NS_IMETHOD GetCoalesceDuplicateArcs(bool *aCoalesceDuplicateArcs); \
  NS_IMETHOD SetCoalesceDuplicateArcs(bool aCoalesceDuplicateArcs); \
  NS_IMETHOD AddDataSource(nsIRDFDataSource *aDataSource); \
  NS_IMETHOD RemoveDataSource(nsIRDFDataSource *aDataSource); \
  NS_IMETHOD GetDataSources(nsISimpleEnumerator * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFCOMPOSITEDATASOURCE(_to) \
  NS_IMETHOD GetAllowNegativeAssertions(bool *aAllowNegativeAssertions) { return _to GetAllowNegativeAssertions(aAllowNegativeAssertions); } \
  NS_IMETHOD SetAllowNegativeAssertions(bool aAllowNegativeAssertions) { return _to SetAllowNegativeAssertions(aAllowNegativeAssertions); } \
  NS_IMETHOD GetCoalesceDuplicateArcs(bool *aCoalesceDuplicateArcs) { return _to GetCoalesceDuplicateArcs(aCoalesceDuplicateArcs); } \
  NS_IMETHOD SetCoalesceDuplicateArcs(bool aCoalesceDuplicateArcs) { return _to SetCoalesceDuplicateArcs(aCoalesceDuplicateArcs); } \
  NS_IMETHOD AddDataSource(nsIRDFDataSource *aDataSource) { return _to AddDataSource(aDataSource); } \
  NS_IMETHOD RemoveDataSource(nsIRDFDataSource *aDataSource) { return _to RemoveDataSource(aDataSource); } \
  NS_IMETHOD GetDataSources(nsISimpleEnumerator * *_retval) { return _to GetDataSources(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFCOMPOSITEDATASOURCE(_to) \
  NS_IMETHOD GetAllowNegativeAssertions(bool *aAllowNegativeAssertions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowNegativeAssertions(aAllowNegativeAssertions); } \
  NS_IMETHOD SetAllowNegativeAssertions(bool aAllowNegativeAssertions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowNegativeAssertions(aAllowNegativeAssertions); } \
  NS_IMETHOD GetCoalesceDuplicateArcs(bool *aCoalesceDuplicateArcs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoalesceDuplicateArcs(aCoalesceDuplicateArcs); } \
  NS_IMETHOD SetCoalesceDuplicateArcs(bool aCoalesceDuplicateArcs) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCoalesceDuplicateArcs(aCoalesceDuplicateArcs); } \
  NS_IMETHOD AddDataSource(nsIRDFDataSource *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDataSource(aDataSource); } \
  NS_IMETHOD RemoveDataSource(nsIRDFDataSource *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDataSource(aDataSource); } \
  NS_IMETHOD GetDataSources(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSources(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFCompositeDataSource : public nsIRDFCompositeDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFCOMPOSITEDATASOURCE

  nsRDFCompositeDataSource();

private:
  ~nsRDFCompositeDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFCompositeDataSource, nsIRDFCompositeDataSource)

nsRDFCompositeDataSource::nsRDFCompositeDataSource()
{
  /* member initializers and constructor code */
}

nsRDFCompositeDataSource::~nsRDFCompositeDataSource()
{
  /* destructor code */
}

/* attribute boolean allowNegativeAssertions; */
NS_IMETHODIMP nsRDFCompositeDataSource::GetAllowNegativeAssertions(bool *aAllowNegativeAssertions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRDFCompositeDataSource::SetAllowNegativeAssertions(bool aAllowNegativeAssertions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean coalesceDuplicateArcs; */
NS_IMETHODIMP nsRDFCompositeDataSource::GetCoalesceDuplicateArcs(bool *aCoalesceDuplicateArcs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRDFCompositeDataSource::SetCoalesceDuplicateArcs(bool aCoalesceDuplicateArcs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddDataSource (in nsIRDFDataSource aDataSource); */
NS_IMETHODIMP nsRDFCompositeDataSource::AddDataSource(nsIRDFDataSource *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveDataSource (in nsIRDFDataSource aDataSource); */
NS_IMETHODIMP nsRDFCompositeDataSource::RemoveDataSource(nsIRDFDataSource *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetDataSources (); */
NS_IMETHODIMP nsRDFCompositeDataSource::GetDataSources(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

extern nsresult
NS_NewRDFCompositeDataSource(nsIRDFCompositeDataSource** result);

#endif /* __gen_nsIRDFCompositeDataSource_h__ */
