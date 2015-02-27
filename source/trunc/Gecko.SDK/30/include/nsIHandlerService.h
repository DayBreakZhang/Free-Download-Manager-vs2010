/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHandlerService.idl
 */

#ifndef __gen_nsIHandlerService_h__
#define __gen_nsIHandlerService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHandlerInfo; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIHandlerService */
#define NS_IHANDLERSERVICE_IID_STR "53f0ad17-ec62-46a1-adbc-efccc06babcd"

#define NS_IHANDLERSERVICE_IID \
  {0x53f0ad17, 0xec62, 0x46a1, \
    { 0xad, 0xbc, 0xef, 0xcc, 0xc0, 0x6b, 0xab, 0xcd }}

class NS_NO_VTABLE nsIHandlerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHANDLERSERVICE_IID)

  /* nsISimpleEnumerator enumerate (); */
  NS_IMETHOD Enumerate(nsISimpleEnumerator * *_retval) = 0;

  /* void fillHandlerInfo (in nsIHandlerInfo aHandlerInfo, in ACString aOverrideType); */
  NS_IMETHOD FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType) = 0;

  /* void store (in nsIHandlerInfo aHandlerInfo); */
  NS_IMETHOD Store(nsIHandlerInfo *aHandlerInfo) = 0;

  /* boolean exists (in nsIHandlerInfo aHandlerInfo); */
  NS_IMETHOD Exists(nsIHandlerInfo *aHandlerInfo, bool *_retval) = 0;

  /* void remove (in nsIHandlerInfo aHandlerInfo); */
  NS_IMETHOD Remove(nsIHandlerInfo *aHandlerInfo) = 0;

  /* ACString getTypeFromExtension (in ACString aFileExtension); */
  NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHandlerService, NS_IHANDLERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHANDLERSERVICE \
  NS_IMETHOD Enumerate(nsISimpleEnumerator * *_retval); \
  NS_IMETHOD FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType); \
  NS_IMETHOD Store(nsIHandlerInfo *aHandlerInfo); \
  NS_IMETHOD Exists(nsIHandlerInfo *aHandlerInfo, bool *_retval); \
  NS_IMETHOD Remove(nsIHandlerInfo *aHandlerInfo); \
  NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHANDLERSERVICE(_to) \
  NS_IMETHOD Enumerate(nsISimpleEnumerator * *_retval) { return _to Enumerate(_retval); } \
  NS_IMETHOD FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType) { return _to FillHandlerInfo(aHandlerInfo, aOverrideType); } \
  NS_IMETHOD Store(nsIHandlerInfo *aHandlerInfo) { return _to Store(aHandlerInfo); } \
  NS_IMETHOD Exists(nsIHandlerInfo *aHandlerInfo, bool *_retval) { return _to Exists(aHandlerInfo, _retval); } \
  NS_IMETHOD Remove(nsIHandlerInfo *aHandlerInfo) { return _to Remove(aHandlerInfo); } \
  NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval) { return _to GetTypeFromExtension(aFileExtension, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHANDLERSERVICE(_to) \
  NS_IMETHOD Enumerate(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Enumerate(_retval); } \
  NS_IMETHOD FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType) { return !_to ? NS_ERROR_NULL_POINTER : _to->FillHandlerInfo(aHandlerInfo, aOverrideType); } \
  NS_IMETHOD Store(nsIHandlerInfo *aHandlerInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->Store(aHandlerInfo); } \
  NS_IMETHOD Exists(nsIHandlerInfo *aHandlerInfo, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Exists(aHandlerInfo, _retval); } \
  NS_IMETHOD Remove(nsIHandlerInfo *aHandlerInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(aHandlerInfo); } \
  NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromExtension(aFileExtension, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHandlerService : public nsIHandlerService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHANDLERSERVICE

  nsHandlerService();

private:
  ~nsHandlerService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHandlerService, nsIHandlerService)

nsHandlerService::nsHandlerService()
{
  /* member initializers and constructor code */
}

nsHandlerService::~nsHandlerService()
{
  /* destructor code */
}

/* nsISimpleEnumerator enumerate (); */
NS_IMETHODIMP nsHandlerService::Enumerate(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fillHandlerInfo (in nsIHandlerInfo aHandlerInfo, in ACString aOverrideType); */
NS_IMETHODIMP nsHandlerService::FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void store (in nsIHandlerInfo aHandlerInfo); */
NS_IMETHODIMP nsHandlerService::Store(nsIHandlerInfo *aHandlerInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean exists (in nsIHandlerInfo aHandlerInfo); */
NS_IMETHODIMP nsHandlerService::Exists(nsIHandlerInfo *aHandlerInfo, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in nsIHandlerInfo aHandlerInfo); */
NS_IMETHODIMP nsHandlerService::Remove(nsIHandlerInfo *aHandlerInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getTypeFromExtension (in ACString aFileExtension); */
NS_IMETHODIMP nsHandlerService::GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHandlerService_h__ */
