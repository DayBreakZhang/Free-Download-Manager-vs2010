/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISidebar.idl
 */

#ifndef __gen_nsISidebar_h__
#define __gen_nsISidebar_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISidebar */
#define NS_ISIDEBAR_IID_STR "351887ca-56b2-4458-96fc-88baeb57b6e7"

#define NS_ISIDEBAR_IID \
  {0x351887ca, 0x56b2, 0x4458, \
    { 0x96, 0xfc, 0x88, 0xba, 0xeb, 0x57, 0xb6, 0xe7 }}

class NS_NO_VTABLE nsISidebar : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIDEBAR_IID)

  /* void addSearchEngine (in DOMString engineURL, in DOMString iconURL, in DOMString suggestedTitle, in DOMString suggestedCategory); */
  NS_IMETHOD AddSearchEngine(const nsAString & engineURL, const nsAString & iconURL, const nsAString & suggestedTitle, const nsAString & suggestedCategory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISidebar, NS_ISIDEBAR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIDEBAR \
  NS_IMETHOD AddSearchEngine(const nsAString & engineURL, const nsAString & iconURL, const nsAString & suggestedTitle, const nsAString & suggestedCategory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIDEBAR(_to) \
  NS_IMETHOD AddSearchEngine(const nsAString & engineURL, const nsAString & iconURL, const nsAString & suggestedTitle, const nsAString & suggestedCategory) { return _to AddSearchEngine(engineURL, iconURL, suggestedTitle, suggestedCategory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIDEBAR(_to) \
  NS_IMETHOD AddSearchEngine(const nsAString & engineURL, const nsAString & iconURL, const nsAString & suggestedTitle, const nsAString & suggestedCategory) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSearchEngine(engineURL, iconURL, suggestedTitle, suggestedCategory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSidebar : public nsISidebar
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIDEBAR

  nsSidebar();

private:
  ~nsSidebar();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSidebar, nsISidebar)

nsSidebar::nsSidebar()
{
  /* member initializers and constructor code */
}

nsSidebar::~nsSidebar()
{
  /* destructor code */
}

/* void addSearchEngine (in DOMString engineURL, in DOMString iconURL, in DOMString suggestedTitle, in DOMString suggestedCategory); */
NS_IMETHODIMP nsSidebar::AddSearchEngine(const nsAString & engineURL, const nsAString & iconURL, const nsAString & suggestedTitle, const nsAString & suggestedCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISidebarExternal */
#define NS_ISIDEBAREXTERNAL_IID_STR "5895076f-e28e-434a-9fdb-a69f94eb323f"

#define NS_ISIDEBAREXTERNAL_IID \
  {0x5895076f, 0xe28e, 0x434a, \
    { 0x9f, 0xdb, 0xa6, 0x9f, 0x94, 0xeb, 0x32, 0x3f }}

class NS_NO_VTABLE nsISidebarExternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIDEBAREXTERNAL_IID)

  /* void AddSearchProvider (in DOMString aDescriptionURL); */
  NS_IMETHOD AddSearchProvider(const nsAString & aDescriptionURL) = 0;

  /* unsigned long IsSearchProviderInstalled (in DOMString aSearchURL); */
  NS_IMETHOD IsSearchProviderInstalled(const nsAString & aSearchURL, uint32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISidebarExternal, NS_ISIDEBAREXTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIDEBAREXTERNAL \
  NS_IMETHOD AddSearchProvider(const nsAString & aDescriptionURL); \
  NS_IMETHOD IsSearchProviderInstalled(const nsAString & aSearchURL, uint32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIDEBAREXTERNAL(_to) \
  NS_IMETHOD AddSearchProvider(const nsAString & aDescriptionURL) { return _to AddSearchProvider(aDescriptionURL); } \
  NS_IMETHOD IsSearchProviderInstalled(const nsAString & aSearchURL, uint32_t *_retval) { return _to IsSearchProviderInstalled(aSearchURL, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIDEBAREXTERNAL(_to) \
  NS_IMETHOD AddSearchProvider(const nsAString & aDescriptionURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSearchProvider(aDescriptionURL); } \
  NS_IMETHOD IsSearchProviderInstalled(const nsAString & aSearchURL, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSearchProviderInstalled(aSearchURL, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSidebarExternal : public nsISidebarExternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIDEBAREXTERNAL

  nsSidebarExternal();

private:
  ~nsSidebarExternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSidebarExternal, nsISidebarExternal)

nsSidebarExternal::nsSidebarExternal()
{
  /* member initializers and constructor code */
}

nsSidebarExternal::~nsSidebarExternal()
{
  /* destructor code */
}

/* void AddSearchProvider (in DOMString aDescriptionURL); */
NS_IMETHODIMP nsSidebarExternal::AddSearchProvider(const nsAString & aDescriptionURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long IsSearchProviderInstalled (in DOMString aSearchURL); */
NS_IMETHODIMP nsSidebarExternal::IsSearchProviderInstalled(const nsAString & aSearchURL, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {577CB744-8CAF-11d3-AAEF-00805F8A4905} 
#define NS_SIDEBAR_CID \
{ 0x577cb744, 0x8caf, 0x11d3, { 0xaa, 0xef, 0x0, 0x80, 0x5f, 0x8a, 0x49, 0x5 } }
#define NS_SIDEBAR_CONTRACTID "@mozilla.org/sidebar;1"

#endif /* __gen_nsISidebar_h__ */
