/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/places/public/nsIMicrosummaryService.idl
 */

#ifndef __gen_nsIMicrosummaryService_h__
#define __gen_nsIMicrosummaryService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIURI; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIMicrosummary; /* forward declaration */


/* starting interface:    nsIMicrosummaryObserver */
#define NS_IMICROSUMMARYOBSERVER_IID_STR "560b0980-be95-47e9-81cc-4428c073127c"

#define NS_IMICROSUMMARYOBSERVER_IID \
  {0x560b0980, 0xbe95, 0x47e9, \
    { 0x81, 0xcc, 0x44, 0x28, 0xc0, 0x73, 0x12, 0x7c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMicrosummaryObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMICROSUMMARYOBSERVER_IID)

  /**
     * Called when an observed microsummary updates its content.
     * Since an observer might watch multiple microsummaries at the same time,
     * the microsummary whose content has been updated gets passed
     * to this handler.
     * XXX Should this be onContentUpdated?
     *
     * @param microsummary
     *        the microsummary whose content has just been updated
     *
     */
  /* void onContentLoaded (in nsIMicrosummary microsummary); */
  NS_SCRIPTABLE NS_IMETHOD OnContentLoaded(nsIMicrosummary *microsummary) = 0;

  /**
     * Called when an observed microsummary encounters an error during an update.
     * 
     * @param microsummary
     *        the microsummary which could not be updated
     *
     */
  /* void onError (in nsIMicrosummary microsummary); */
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIMicrosummary *microsummary) = 0;

  /**
     * Called when an element is appended to a microsummary set.
     * XXX Should this be in a separate nsICollectionObserver interface?
     *
     * @param microsummary
     *        the microsummary that has just been appended to the set
     *
     */
  /* void onElementAppended (in nsIMicrosummary microsummary); */
  NS_SCRIPTABLE NS_IMETHOD OnElementAppended(nsIMicrosummary *microsummary) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMicrosummaryObserver, NS_IMICROSUMMARYOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMICROSUMMARYOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnContentLoaded(nsIMicrosummary *microsummary); \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIMicrosummary *microsummary); \
  NS_SCRIPTABLE NS_IMETHOD OnElementAppended(nsIMicrosummary *microsummary); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMICROSUMMARYOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnContentLoaded(nsIMicrosummary *microsummary) { return _to OnContentLoaded(microsummary); } \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIMicrosummary *microsummary) { return _to OnError(microsummary); } \
  NS_SCRIPTABLE NS_IMETHOD OnElementAppended(nsIMicrosummary *microsummary) { return _to OnElementAppended(microsummary); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMICROSUMMARYOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnContentLoaded(nsIMicrosummary *microsummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContentLoaded(microsummary); } \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIMicrosummary *microsummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(microsummary); } \
  NS_SCRIPTABLE NS_IMETHOD OnElementAppended(nsIMicrosummary *microsummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnElementAppended(microsummary); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMicrosummaryObserver : public nsIMicrosummaryObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMICROSUMMARYOBSERVER

  nsMicrosummaryObserver();

private:
  ~nsMicrosummaryObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMicrosummaryObserver, nsIMicrosummaryObserver)

nsMicrosummaryObserver::nsMicrosummaryObserver()
{
  /* member initializers and constructor code */
}

nsMicrosummaryObserver::~nsMicrosummaryObserver()
{
  /* destructor code */
}

/* void onContentLoaded (in nsIMicrosummary microsummary); */
NS_IMETHODIMP nsMicrosummaryObserver::OnContentLoaded(nsIMicrosummary *microsummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onError (in nsIMicrosummary microsummary); */
NS_IMETHODIMP nsMicrosummaryObserver::OnError(nsIMicrosummary *microsummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onElementAppended (in nsIMicrosummary microsummary); */
NS_IMETHODIMP nsMicrosummaryObserver::OnElementAppended(nsIMicrosummary *microsummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMicrosummaryGenerator */
#define NS_IMICROSUMMARYGENERATOR_IID_STR "05b48344-d0a7-427e-934e-9a6e0d5ecced"

#define NS_IMICROSUMMARYGENERATOR_IID \
  {0x05b48344, 0xd0a7, 0x427e, \
    { 0x93, 0x4e, 0x9a, 0x6e, 0x0d, 0x5e, 0xcc, 0xed }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMicrosummaryGenerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMICROSUMMARYGENERATOR_IID)

  /* readonly attribute boolean loaded; */
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRBool *aLoaded) = 0;

  /* readonly attribute AUTF8String name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) = 0;

  /**
     * microsummary-generator equivalence test
     * generators equal if their canonical locations equal, see uri attribute.
     */
  /* boolean equals (in nsIMicrosummaryGenerator aOther); */
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMicrosummaryGenerator *aOther, PRBool *_retval NS_OUTPARAM) = 0;

  /* readonly attribute nsIURI localURI; */
  NS_SCRIPTABLE NS_IMETHOD GetLocalURI(nsIURI **aLocalURI) = 0;

  /* readonly attribute boolean needsPageContent; */
  NS_SCRIPTABLE NS_IMETHOD GetNeedsPageContent(PRBool *aNeedsPageContent) = 0;

  /**
     * Generate a microsummary by processing the generator template
     * against the page content.  If a generator doesn't need content,
     * pass null as the parameter to this method.
     *
     * XXX In the future, this should support returning rich text content,
     * so perhaps we should make it return a DOM node now and have the caller
     * convert that to text if it doesn't support rich content.
     *
     * @param   pageContent
     *          the content of the page being summarized
     * @returns the text result of processing the template
     *
     */
  /* AString generateMicrosummary (in nsIDOMNode aPageContent); */
  NS_SCRIPTABLE NS_IMETHOD GenerateMicrosummary(nsIDOMNode *aPageContent, nsAString & _retval NS_OUTPARAM) = 0;

  /**
     * Calculate the interval until the microsummary should be updated for
     * the next time, depending on the page content. If the generator doesn't
     * specify an interval, null is returned.
     *
     * @param   pageContent
     *          the content of the page being summarized
     * @returns the interval in milliseconds until the next update request
     *
     */
  /* long calculateUpdateInterval (in nsIDOMNode aPageContent); */
  NS_SCRIPTABLE NS_IMETHOD CalculateUpdateInterval(nsIDOMNode *aPageContent, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMicrosummaryGenerator, NS_IMICROSUMMARYGENERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMICROSUMMARYGENERATOR \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRBool *aLoaded); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri); \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMicrosummaryGenerator *aOther, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalURI(nsIURI **aLocalURI); \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsPageContent(PRBool *aNeedsPageContent); \
  NS_SCRIPTABLE NS_IMETHOD GenerateMicrosummary(nsIDOMNode *aPageContent, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CalculateUpdateInterval(nsIDOMNode *aPageContent, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMICROSUMMARYGENERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRBool *aLoaded) { return _to GetLoaded(aLoaded); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMicrosummaryGenerator *aOther, PRBool *_retval NS_OUTPARAM) { return _to Equals(aOther, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalURI(nsIURI **aLocalURI) { return _to GetLocalURI(aLocalURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsPageContent(PRBool *aNeedsPageContent) { return _to GetNeedsPageContent(aNeedsPageContent); } \
  NS_SCRIPTABLE NS_IMETHOD GenerateMicrosummary(nsIDOMNode *aPageContent, nsAString & _retval NS_OUTPARAM) { return _to GenerateMicrosummary(aPageContent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CalculateUpdateInterval(nsIDOMNode *aPageContent, PRInt32 *_retval NS_OUTPARAM) { return _to CalculateUpdateInterval(aPageContent, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMICROSUMMARYGENERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLoaded(PRBool *aLoaded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoaded(aLoaded); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMicrosummaryGenerator *aOther, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(aOther, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalURI(nsIURI **aLocalURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalURI(aLocalURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsPageContent(PRBool *aNeedsPageContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeedsPageContent(aNeedsPageContent); } \
  NS_SCRIPTABLE NS_IMETHOD GenerateMicrosummary(nsIDOMNode *aPageContent, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateMicrosummary(aPageContent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CalculateUpdateInterval(nsIDOMNode *aPageContent, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CalculateUpdateInterval(aPageContent, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMicrosummaryGenerator : public nsIMicrosummaryGenerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMICROSUMMARYGENERATOR

  nsMicrosummaryGenerator();

private:
  ~nsMicrosummaryGenerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMicrosummaryGenerator, nsIMicrosummaryGenerator)

nsMicrosummaryGenerator::nsMicrosummaryGenerator()
{
  /* member initializers and constructor code */
}

nsMicrosummaryGenerator::~nsMicrosummaryGenerator()
{
  /* destructor code */
}

/* readonly attribute boolean loaded; */
NS_IMETHODIMP nsMicrosummaryGenerator::GetLoaded(PRBool *aLoaded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsMicrosummaryGenerator::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI uri; */
NS_IMETHODIMP nsMicrosummaryGenerator::GetUri(nsIURI **aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIMicrosummaryGenerator aOther); */
NS_IMETHODIMP nsMicrosummaryGenerator::Equals(nsIMicrosummaryGenerator *aOther, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI localURI; */
NS_IMETHODIMP nsMicrosummaryGenerator::GetLocalURI(nsIURI **aLocalURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean needsPageContent; */
NS_IMETHODIMP nsMicrosummaryGenerator::GetNeedsPageContent(PRBool *aNeedsPageContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString generateMicrosummary (in nsIDOMNode aPageContent); */
NS_IMETHODIMP nsMicrosummaryGenerator::GenerateMicrosummary(nsIDOMNode *aPageContent, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long calculateUpdateInterval (in nsIDOMNode aPageContent); */
NS_IMETHODIMP nsMicrosummaryGenerator::CalculateUpdateInterval(nsIDOMNode *aPageContent, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMicrosummary */
#define NS_IMICROSUMMARY_IID_STR "6867dc21-077f-4462-937d-cd8b7c680e0c"

#define NS_IMICROSUMMARY_IID \
  {0x6867dc21, 0x077f, 0x4462, \
    { 0x93, 0x7d, 0xcd, 0x8b, 0x7c, 0x68, 0x0e, 0x0c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMicrosummary : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMICROSUMMARY_IID)

  /* readonly attribute nsIURI pageURI; */
  NS_SCRIPTABLE NS_IMETHOD GetPageURI(nsIURI **aPageURI) = 0;

  /* attribute nsIMicrosummaryGenerator generator; */
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIMicrosummaryGenerator **aGenerator) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGenerator(nsIMicrosummaryGenerator *aGenerator) = 0;

  /* readonly attribute AString content; */
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsAString & aContent) = 0;

  /* readonly attribute long updateInterval; */
  NS_SCRIPTABLE NS_IMETHOD GetUpdateInterval(PRInt32 *aUpdateInterval) = 0;

  /* readonly attribute boolean needsRemoval; */
  NS_SCRIPTABLE NS_IMETHOD GetNeedsRemoval(PRBool *aNeedsRemoval) = 0;

  /**
     * Add a microsummary observer to this microsummary.
     *
     * @param observer
     *        the microsummary observer to add
     *
     */
  /* void addObserver (in nsIMicrosummaryObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIMicrosummaryObserver *observer) = 0;

  /**
     * Remove a microsummary observer from this microsummary.
     *
     * @param observer
     *        the microsummary observer to remove
     *
     */
  /* void removeObserver (in nsIMicrosummaryObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIMicrosummaryObserver *observer) = 0;

  /**
     * Microsummary equivalence test
     * Microsummaries equal if they summarize the same page with the same
     * microsummary-generator (see also nsIMicrosummaryGenerator::equals).
     *
     * Note: this method returns false if either objects don't have a generator
     */
  /* boolean equals (in nsIMicrosummary aOther); */
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMicrosummary *aOther, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Update the microsummary, first loading its generator and page content
     * as necessary.  If you want know when a microsummary finishes updating,
     * add an observer before calling this method.
     *
     */
  /* void update (); */
  NS_SCRIPTABLE NS_IMETHOD Update(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMicrosummary, NS_IMICROSUMMARY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMICROSUMMARY \
  NS_SCRIPTABLE NS_IMETHOD GetPageURI(nsIURI **aPageURI); \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIMicrosummaryGenerator **aGenerator); \
  NS_SCRIPTABLE NS_IMETHOD SetGenerator(nsIMicrosummaryGenerator *aGenerator); \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsAString & aContent); \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateInterval(PRInt32 *aUpdateInterval); \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsRemoval(PRBool *aNeedsRemoval); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIMicrosummaryObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIMicrosummaryObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMicrosummary *aOther, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Update(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMICROSUMMARY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPageURI(nsIURI **aPageURI) { return _to GetPageURI(aPageURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIMicrosummaryGenerator **aGenerator) { return _to GetGenerator(aGenerator); } \
  NS_SCRIPTABLE NS_IMETHOD SetGenerator(nsIMicrosummaryGenerator *aGenerator) { return _to SetGenerator(aGenerator); } \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsAString & aContent) { return _to GetContent(aContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateInterval(PRInt32 *aUpdateInterval) { return _to GetUpdateInterval(aUpdateInterval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsRemoval(PRBool *aNeedsRemoval) { return _to GetNeedsRemoval(aNeedsRemoval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIMicrosummaryObserver *observer) { return _to AddObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIMicrosummaryObserver *observer) { return _to RemoveObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMicrosummary *aOther, PRBool *_retval NS_OUTPARAM) { return _to Equals(aOther, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Update(void) { return _to Update(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMICROSUMMARY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPageURI(nsIURI **aPageURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageURI(aPageURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIMicrosummaryGenerator **aGenerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGenerator(aGenerator); } \
  NS_SCRIPTABLE NS_IMETHOD SetGenerator(nsIMicrosummaryGenerator *aGenerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGenerator(aGenerator); } \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsAString & aContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContent(aContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateInterval(PRInt32 *aUpdateInterval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateInterval(aUpdateInterval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsRemoval(PRBool *aNeedsRemoval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeedsRemoval(aNeedsRemoval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIMicrosummaryObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIMicrosummaryObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIMicrosummary *aOther, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(aOther, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Update(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMicrosummary : public nsIMicrosummary
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMICROSUMMARY

  nsMicrosummary();

private:
  ~nsMicrosummary();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMicrosummary, nsIMicrosummary)

nsMicrosummary::nsMicrosummary()
{
  /* member initializers and constructor code */
}

nsMicrosummary::~nsMicrosummary()
{
  /* destructor code */
}

/* readonly attribute nsIURI pageURI; */
NS_IMETHODIMP nsMicrosummary::GetPageURI(nsIURI **aPageURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIMicrosummaryGenerator generator; */
NS_IMETHODIMP nsMicrosummary::GetGenerator(nsIMicrosummaryGenerator **aGenerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMicrosummary::SetGenerator(nsIMicrosummaryGenerator *aGenerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString content; */
NS_IMETHODIMP nsMicrosummary::GetContent(nsAString & aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long updateInterval; */
NS_IMETHODIMP nsMicrosummary::GetUpdateInterval(PRInt32 *aUpdateInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean needsRemoval; */
NS_IMETHODIMP nsMicrosummary::GetNeedsRemoval(PRBool *aNeedsRemoval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsIMicrosummaryObserver observer); */
NS_IMETHODIMP nsMicrosummary::AddObserver(nsIMicrosummaryObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIMicrosummaryObserver observer); */
NS_IMETHODIMP nsMicrosummary::RemoveObserver(nsIMicrosummaryObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIMicrosummary aOther); */
NS_IMETHODIMP nsMicrosummary::Equals(nsIMicrosummary *aOther, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update (); */
NS_IMETHODIMP nsMicrosummary::Update()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMicrosummarySet */
#define NS_IMICROSUMMARYSET_IID_STR "7111e88d-fecd-4b17-b7a9-1fa74e23153f"

#define NS_IMICROSUMMARYSET_IID \
  {0x7111e88d, 0xfecd, 0x4b17, \
    { 0xb7, 0xa9, 0x1f, 0xa7, 0x4e, 0x23, 0x15, 0x3f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMicrosummarySet : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMICROSUMMARYSET_IID)

  /**
     * Add a microsummary observer to this microsummary set.  Adding an observer
     * to a set is the equivalent of adding it to each constituent microsummary.
     *
     * @param observer
     *        the microsummary observer to add
     *
     */
  /* void addObserver (in nsIMicrosummaryObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIMicrosummaryObserver *observer) = 0;

  /**
     * Remove a microsummary observer from this microsummary.
     *
     * @param observer
     *        the microsummary observer to remove
     *
     */
  /* void removeObserver (in nsIMicrosummaryObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIMicrosummaryObserver *observer) = 0;

  /**
     * Retrieve a enumerator of microsummaries in the set.
     *
     * @returns an enumerator of nsIMicrosummary objects
     *
     */
  /* nsISimpleEnumerator Enumerate (); */
  NS_SCRIPTABLE NS_IMETHOD Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMicrosummarySet, NS_IMICROSUMMARYSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMICROSUMMARYSET \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIMicrosummaryObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIMicrosummaryObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMICROSUMMARYSET(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIMicrosummaryObserver *observer) { return _to AddObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIMicrosummaryObserver *observer) { return _to RemoveObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to Enumerate(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMICROSUMMARYSET(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIMicrosummaryObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIMicrosummaryObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Enumerate(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMicrosummarySet : public nsIMicrosummarySet
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMICROSUMMARYSET

  nsMicrosummarySet();

private:
  ~nsMicrosummarySet();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMicrosummarySet, nsIMicrosummarySet)

nsMicrosummarySet::nsMicrosummarySet()
{
  /* member initializers and constructor code */
}

nsMicrosummarySet::~nsMicrosummarySet()
{
  /* destructor code */
}

/* void addObserver (in nsIMicrosummaryObserver observer); */
NS_IMETHODIMP nsMicrosummarySet::AddObserver(nsIMicrosummaryObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIMicrosummaryObserver observer); */
NS_IMETHODIMP nsMicrosummarySet::RemoveObserver(nsIMicrosummaryObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator Enumerate (); */
NS_IMETHODIMP nsMicrosummarySet::Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMicrosummaryService */
#define NS_IMICROSUMMARYSERVICE_IID_STR "d58143a2-74fa-4b13-94ed-113af8936d80"

#define NS_IMICROSUMMARYSERVICE_IID \
  {0xd58143a2, 0x74fa, 0x4b13, \
    { 0x94, 0xed, 0x11, 0x3a, 0xf8, 0x93, 0x6d, 0x80 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMicrosummaryService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMICROSUMMARYSERVICE_IID)

  /**
     * Return a microsummary generator for the given URI.
     *
     * @param   generatorURI
     *          the URI of the generator
     *
     * @returns an nsIMicrosummaryGenerator for the given URI.
     *
     */
  /* nsIMicrosummaryGenerator getGenerator (in nsIURI generatorURI); */
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIURI *generatorURI, nsIMicrosummaryGenerator **_retval NS_OUTPARAM) = 0;

  /**
     * Install the microsummary generator from the resource at the supplied URI.
     * Callable by content via the addMicrosummaryGenerator() sidebar method.
     *
     * @param   generatorURI
     *          the URI of the resource providing the generator
     *
     */
  /* void addGenerator (in nsIURI generatorURI); */
  NS_SCRIPTABLE NS_IMETHOD AddGenerator(nsIURI *generatorURI) = 0;

  /**
     * Install the microsummary generator in the given XML definition.
     *
     * @param   xmlDefinition
     *          an nsIDOMDocument XML document defining the generator
     *
     * @returns the newly-installed nsIMicrosummaryGenerator object
     *
     */
  /* nsIMicrosummaryGenerator installGenerator (in nsIDOMDocument xmlDefinition); */
  NS_SCRIPTABLE NS_IMETHOD InstallGenerator(nsIDOMDocument *xmlDefinition, nsIMicrosummaryGenerator **_retval NS_OUTPARAM) = 0;

  /**
     * Get the set of bookmarks with microsummaries.
     *
     * In the old RDF-based bookmarks datastore, bookmark IDs are nsIRDFResource
     * objects.  In the new Places-based datastore, they are nsIURI objects.
     *
     * @returns an nsISimpleEnumerator enumeration of bookmark IDs
     *
     */
  /* nsISimpleEnumerator getBookmarks (); */
  NS_SCRIPTABLE NS_IMETHOD GetBookmarks(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Get the set of microsummaries available for a given page.  The set
     * might change after this method returns, since this method will trigger
     * an asynchronous load of the page in question (if it isn't already loaded)
     * to see if it references any page-specific microsummaries.
     *
     * If the caller passes a bookmark ID, and one of the microsummaries
     * is the current one for the bookmark, this method will retrieve content
     * from the datastore for that microsummary, which is useful when callers
     * want to display a list of microsummaries for a page that isn't loaded,
     * and they want to display the actual content of the selected microsummary
     * immediately (rather than after the content is asynchronously loaded).
     *
     * @param   pageURI
     *          the URI of the page for which to retrieve available microsummaries
     *
     * @param   bookmarkID (optional)
     *          the ID of the bookmark for which this method is being called
     *
     * @returns an nsIMicrosummarySet of nsIMicrosummaries for the given page
     *
     */
  /* nsIMicrosummarySet getMicrosummaries (in nsIURI pageURI, in long long bookmarkID); */
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummaries(nsIURI *pageURI, PRInt64 bookmarkID, nsIMicrosummarySet **_retval NS_OUTPARAM) = 0;

  /**
     * Get the current microsummary for the given bookmark.
     *
     * @param   bookmarkID
     *          the bookmark for which to get the current microsummary
     *
     * @returns the current microsummary for the bookmark, or null
     *          if the bookmark does not have a current microsummary
     *
     */
  /* nsIMicrosummary getMicrosummary (in long long bookmarkID); */
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM) = 0;

  /**
     * Create a microsummary for a given page URI and generator URI.
     *
     * @param   pageURI
     *          the URI of the page to be summarized
     *
     * @param   generatorURI
     *          the URI of the microsummary generator
     *
     * @returns an nsIMicrosummary for the given page and generator URIs.
     *
     */
  /* nsIMicrosummary createMicrosummary (in nsIURI pageURI, in nsIURI generatorURI); */
  NS_SCRIPTABLE NS_IMETHOD CreateMicrosummary(nsIURI *pageURI, nsIURI *generatorURI, nsIMicrosummary **_retval NS_OUTPARAM) = 0;

  /**
     * Set the current microsummary for the given bookmark.
     *
     * @param   bookmarkID
     *          the bookmark for which to set the current microsummary
     *
     * @param   microsummary
     *          the microsummary to set as the current one
     *
     */
  /* void setMicrosummary (in long long bookmarkID, in nsIMicrosummary microsummary); */
  NS_SCRIPTABLE NS_IMETHOD SetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary) = 0;

  /**
     * Remove the current microsummary for the given bookmark.
     *
     * @param   bookmarkID
     *          the bookmark for which to remove the current microsummary
     *
     */
  /* void removeMicrosummary (in long long bookmarkID); */
  NS_SCRIPTABLE NS_IMETHOD RemoveMicrosummary(PRInt64 bookmarkID) = 0;

  /**
     * Whether or not the given bookmark has a current microsummary.
     *
     * @param   bookmarkID
     *          the bookmark for which to set the current microsummary
     *
     * @returns a boolean representing whether or not the given bookmark
     *          has a current microsummary
     *
     */
  /* boolean hasMicrosummary (in long long bookmarkID); */
  NS_SCRIPTABLE NS_IMETHOD HasMicrosummary(PRInt64 bookmarkID, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Whether or not the given microsummary is the current microsummary
     * for the given bookmark.
     *
     * @param   bookmarkID
     *          the bookmark to check
     *
     * @param   microsummary
     *          the microsummary to check
     *
     * @returns whether or not the microsummary is the current one
     *          for the bookmark
     *
     */
  /* boolean isMicrosummary (in long long bookmarkID, in nsIMicrosummary microsummary); */
  NS_SCRIPTABLE NS_IMETHOD IsMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Refresh a microsummary, updating its value in the datastore and UI.
     * If this method can refresh the microsummary instantly, it will.
     * Otherwise, it'll asynchronously download the necessary information
     * (the generator and/or page) before refreshing the microsummary.
     *
     * Callers should check the "content" property of the returned microsummary
     * object to distinguish between sync and async refreshes.  If its value
     * is "null", then it's an async refresh, and the caller should register
     * itself as an nsIMicrosummaryObserver via nsIMicrosummary.addObserver()
     * to find out when the refresh completes.
     *
     * @param   bookmarkID
     *          the bookmark whose microsummary is being refreshed
     *
     * @returns the microsummary being refreshed
     *
     */
  /* nsIMicrosummary refreshMicrosummary (in long long bookmarkID); */
  NS_SCRIPTABLE NS_IMETHOD RefreshMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMicrosummaryService, NS_IMICROSUMMARYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMICROSUMMARYSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIURI *generatorURI, nsIMicrosummaryGenerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddGenerator(nsIURI *generatorURI); \
  NS_SCRIPTABLE NS_IMETHOD InstallGenerator(nsIDOMDocument *xmlDefinition, nsIMicrosummaryGenerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarks(nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummaries(nsIURI *pageURI, PRInt64 bookmarkID, nsIMicrosummarySet **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateMicrosummary(nsIURI *pageURI, nsIURI *generatorURI, nsIMicrosummary **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary); \
  NS_SCRIPTABLE NS_IMETHOD RemoveMicrosummary(PRInt64 bookmarkID); \
  NS_SCRIPTABLE NS_IMETHOD HasMicrosummary(PRInt64 bookmarkID, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RefreshMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMICROSUMMARYSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIURI *generatorURI, nsIMicrosummaryGenerator **_retval NS_OUTPARAM) { return _to GetGenerator(generatorURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddGenerator(nsIURI *generatorURI) { return _to AddGenerator(generatorURI); } \
  NS_SCRIPTABLE NS_IMETHOD InstallGenerator(nsIDOMDocument *xmlDefinition, nsIMicrosummaryGenerator **_retval NS_OUTPARAM) { return _to InstallGenerator(xmlDefinition, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarks(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetBookmarks(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummaries(nsIURI *pageURI, PRInt64 bookmarkID, nsIMicrosummarySet **_retval NS_OUTPARAM) { return _to GetMicrosummaries(pageURI, bookmarkID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM) { return _to GetMicrosummary(bookmarkID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateMicrosummary(nsIURI *pageURI, nsIURI *generatorURI, nsIMicrosummary **_retval NS_OUTPARAM) { return _to CreateMicrosummary(pageURI, generatorURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary) { return _to SetMicrosummary(bookmarkID, microsummary); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveMicrosummary(PRInt64 bookmarkID) { return _to RemoveMicrosummary(bookmarkID); } \
  NS_SCRIPTABLE NS_IMETHOD HasMicrosummary(PRInt64 bookmarkID, PRBool *_retval NS_OUTPARAM) { return _to HasMicrosummary(bookmarkID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary, PRBool *_retval NS_OUTPARAM) { return _to IsMicrosummary(bookmarkID, microsummary, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RefreshMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM) { return _to RefreshMicrosummary(bookmarkID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMICROSUMMARYSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIURI *generatorURI, nsIMicrosummaryGenerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGenerator(generatorURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddGenerator(nsIURI *generatorURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddGenerator(generatorURI); } \
  NS_SCRIPTABLE NS_IMETHOD InstallGenerator(nsIDOMDocument *xmlDefinition, nsIMicrosummaryGenerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallGenerator(xmlDefinition, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarks(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarks(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummaries(nsIURI *pageURI, PRInt64 bookmarkID, nsIMicrosummarySet **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMicrosummaries(pageURI, bookmarkID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMicrosummary(bookmarkID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateMicrosummary(nsIURI *pageURI, nsIURI *generatorURI, nsIMicrosummary **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateMicrosummary(pageURI, generatorURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMicrosummary(bookmarkID, microsummary); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveMicrosummary(PRInt64 bookmarkID) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveMicrosummary(bookmarkID); } \
  NS_SCRIPTABLE NS_IMETHOD HasMicrosummary(PRInt64 bookmarkID, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasMicrosummary(bookmarkID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsMicrosummary(bookmarkID, microsummary, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RefreshMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshMicrosummary(bookmarkID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMicrosummaryService : public nsIMicrosummaryService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMICROSUMMARYSERVICE

  nsMicrosummaryService();

private:
  ~nsMicrosummaryService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMicrosummaryService, nsIMicrosummaryService)

nsMicrosummaryService::nsMicrosummaryService()
{
  /* member initializers and constructor code */
}

nsMicrosummaryService::~nsMicrosummaryService()
{
  /* destructor code */
}

/* nsIMicrosummaryGenerator getGenerator (in nsIURI generatorURI); */
NS_IMETHODIMP nsMicrosummaryService::GetGenerator(nsIURI *generatorURI, nsIMicrosummaryGenerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addGenerator (in nsIURI generatorURI); */
NS_IMETHODIMP nsMicrosummaryService::AddGenerator(nsIURI *generatorURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMicrosummaryGenerator installGenerator (in nsIDOMDocument xmlDefinition); */
NS_IMETHODIMP nsMicrosummaryService::InstallGenerator(nsIDOMDocument *xmlDefinition, nsIMicrosummaryGenerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getBookmarks (); */
NS_IMETHODIMP nsMicrosummaryService::GetBookmarks(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMicrosummarySet getMicrosummaries (in nsIURI pageURI, in long long bookmarkID); */
NS_IMETHODIMP nsMicrosummaryService::GetMicrosummaries(nsIURI *pageURI, PRInt64 bookmarkID, nsIMicrosummarySet **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMicrosummary getMicrosummary (in long long bookmarkID); */
NS_IMETHODIMP nsMicrosummaryService::GetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMicrosummary createMicrosummary (in nsIURI pageURI, in nsIURI generatorURI); */
NS_IMETHODIMP nsMicrosummaryService::CreateMicrosummary(nsIURI *pageURI, nsIURI *generatorURI, nsIMicrosummary **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setMicrosummary (in long long bookmarkID, in nsIMicrosummary microsummary); */
NS_IMETHODIMP nsMicrosummaryService::SetMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeMicrosummary (in long long bookmarkID); */
NS_IMETHODIMP nsMicrosummaryService::RemoveMicrosummary(PRInt64 bookmarkID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasMicrosummary (in long long bookmarkID); */
NS_IMETHODIMP nsMicrosummaryService::HasMicrosummary(PRInt64 bookmarkID, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isMicrosummary (in long long bookmarkID, in nsIMicrosummary microsummary); */
NS_IMETHODIMP nsMicrosummaryService::IsMicrosummary(PRInt64 bookmarkID, nsIMicrosummary *microsummary, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMicrosummary refreshMicrosummary (in long long bookmarkID); */
NS_IMETHODIMP nsMicrosummaryService::RefreshMicrosummary(PRInt64 bookmarkID, nsIMicrosummary **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsILiveTitleNotificationSubject */
#define NS_ILIVETITLENOTIFICATIONSUBJECT_IID_STR "f9e577a8-19d9-4ca0-a140-b9e43f014470"

#define NS_ILIVETITLENOTIFICATIONSUBJECT_IID \
  {0xf9e577a8, 0x19d9, 0x4ca0, \
    { 0xa1, 0x40, 0xb9, 0xe4, 0x3f, 0x01, 0x44, 0x70 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILiveTitleNotificationSubject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILIVETITLENOTIFICATIONSUBJECT_IID)

  /* readonly attribute long long bookmarkID; */
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkID(PRInt64 *aBookmarkID) = 0;

  /* readonly attribute nsIMicrosummary microsummary; */
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummary(nsIMicrosummary **aMicrosummary) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILiveTitleNotificationSubject, NS_ILIVETITLENOTIFICATIONSUBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILIVETITLENOTIFICATIONSUBJECT \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkID(PRInt64 *aBookmarkID); \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummary(nsIMicrosummary **aMicrosummary); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILIVETITLENOTIFICATIONSUBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkID(PRInt64 *aBookmarkID) { return _to GetBookmarkID(aBookmarkID); } \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummary(nsIMicrosummary **aMicrosummary) { return _to GetMicrosummary(aMicrosummary); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILIVETITLENOTIFICATIONSUBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkID(PRInt64 *aBookmarkID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkID(aBookmarkID); } \
  NS_SCRIPTABLE NS_IMETHOD GetMicrosummary(nsIMicrosummary **aMicrosummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMicrosummary(aMicrosummary); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLiveTitleNotificationSubject : public nsILiveTitleNotificationSubject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILIVETITLENOTIFICATIONSUBJECT

  nsLiveTitleNotificationSubject();

private:
  ~nsLiveTitleNotificationSubject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLiveTitleNotificationSubject, nsILiveTitleNotificationSubject)

nsLiveTitleNotificationSubject::nsLiveTitleNotificationSubject()
{
  /* member initializers and constructor code */
}

nsLiveTitleNotificationSubject::~nsLiveTitleNotificationSubject()
{
  /* destructor code */
}

/* readonly attribute long long bookmarkID; */
NS_IMETHODIMP nsLiveTitleNotificationSubject::GetBookmarkID(PRInt64 *aBookmarkID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMicrosummary microsummary; */
NS_IMETHODIMP nsLiveTitleNotificationSubject::GetMicrosummary(nsIMicrosummary **aMicrosummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMicrosummaryService_h__ */
