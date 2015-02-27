/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIBackgroundFileSaver.idl
 */

#ifndef __gen_nsIBackgroundFileSaver_h__
#define __gen_nsIBackgroundFileSaver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBackgroundFileSaverObserver; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIBackgroundFileSaver */
#define NS_IBACKGROUNDFILESAVER_IID_STR "17a2ff32-918f-11e2-8fc9-f9626188709b"

#define NS_IBACKGROUNDFILESAVER_IID \
  {0x17a2ff32, 0x918f, 0x11e2, \
    { 0x8f, 0xc9, 0xf9, 0x62, 0x61, 0x88, 0x70, 0x9b }}

class NS_NO_VTABLE nsIBackgroundFileSaver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBACKGROUNDFILESAVER_IID)

  /* attribute nsIBackgroundFileSaverObserver observer; */
  NS_IMETHOD GetObserver(nsIBackgroundFileSaverObserver * *aObserver) = 0;
  NS_IMETHOD SetObserver(nsIBackgroundFileSaverObserver *aObserver) = 0;

  /* readonly attribute ACString sha256Hash; */
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) = 0;

  /* void enableSha256 (); */
  NS_IMETHOD EnableSha256(void) = 0;

  /* void setTarget (in nsIFile aTarget, in bool aKeepPartial); */
  NS_IMETHOD SetTarget(nsIFile *aTarget, bool aKeepPartial) = 0;

  /* void finish (in nsresult aStatus); */
  NS_IMETHOD Finish(nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBackgroundFileSaver, NS_IBACKGROUNDFILESAVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBACKGROUNDFILESAVER \
  NS_IMETHOD GetObserver(nsIBackgroundFileSaverObserver * *aObserver); \
  NS_IMETHOD SetObserver(nsIBackgroundFileSaverObserver *aObserver); \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash); \
  NS_IMETHOD EnableSha256(void); \
  NS_IMETHOD SetTarget(nsIFile *aTarget, bool aKeepPartial); \
  NS_IMETHOD Finish(nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBACKGROUNDFILESAVER(_to) \
  NS_IMETHOD GetObserver(nsIBackgroundFileSaverObserver * *aObserver) { return _to GetObserver(aObserver); } \
  NS_IMETHOD SetObserver(nsIBackgroundFileSaverObserver *aObserver) { return _to SetObserver(aObserver); } \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) { return _to GetSha256Hash(aSha256Hash); } \
  NS_IMETHOD EnableSha256(void) { return _to EnableSha256(); } \
  NS_IMETHOD SetTarget(nsIFile *aTarget, bool aKeepPartial) { return _to SetTarget(aTarget, aKeepPartial); } \
  NS_IMETHOD Finish(nsresult aStatus) { return _to Finish(aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBACKGROUNDFILESAVER(_to) \
  NS_IMETHOD GetObserver(nsIBackgroundFileSaverObserver * *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObserver(aObserver); } \
  NS_IMETHOD SetObserver(nsIBackgroundFileSaverObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObserver(aObserver); } \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSha256Hash(aSha256Hash); } \
  NS_IMETHOD EnableSha256(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableSha256(); } \
  NS_IMETHOD SetTarget(nsIFile *aTarget, bool aKeepPartial) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget, aKeepPartial); } \
  NS_IMETHOD Finish(nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBackgroundFileSaver : public nsIBackgroundFileSaver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBACKGROUNDFILESAVER

  nsBackgroundFileSaver();

private:
  ~nsBackgroundFileSaver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBackgroundFileSaver, nsIBackgroundFileSaver)

nsBackgroundFileSaver::nsBackgroundFileSaver()
{
  /* member initializers and constructor code */
}

nsBackgroundFileSaver::~nsBackgroundFileSaver()
{
  /* destructor code */
}

/* attribute nsIBackgroundFileSaverObserver observer; */
NS_IMETHODIMP nsBackgroundFileSaver::GetObserver(nsIBackgroundFileSaverObserver * *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBackgroundFileSaver::SetObserver(nsIBackgroundFileSaverObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString sha256Hash; */
NS_IMETHODIMP nsBackgroundFileSaver::GetSha256Hash(nsACString & aSha256Hash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableSha256 (); */
NS_IMETHODIMP nsBackgroundFileSaver::EnableSha256()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTarget (in nsIFile aTarget, in bool aKeepPartial); */
NS_IMETHODIMP nsBackgroundFileSaver::SetTarget(nsIFile *aTarget, bool aKeepPartial)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finish (in nsresult aStatus); */
NS_IMETHODIMP nsBackgroundFileSaver::Finish(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBackgroundFileSaverObserver */
#define NS_IBACKGROUNDFILESAVEROBSERVER_IID_STR "ee7058c3-6e54-4411-b76b-3ce87b76fcb6"

#define NS_IBACKGROUNDFILESAVEROBSERVER_IID \
  {0xee7058c3, 0x6e54, 0x4411, \
    { 0xb7, 0x6b, 0x3c, 0xe8, 0x7b, 0x76, 0xfc, 0xb6 }}

class NS_NO_VTABLE nsIBackgroundFileSaverObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBACKGROUNDFILESAVEROBSERVER_IID)

  /* void onTargetChange (in nsIBackgroundFileSaver aSaver, in nsIFile aTarget); */
  NS_IMETHOD OnTargetChange(nsIBackgroundFileSaver *aSaver, nsIFile *aTarget) = 0;

  /* void onSaveComplete (in nsIBackgroundFileSaver aSaver, in nsresult aStatus); */
  NS_IMETHOD OnSaveComplete(nsIBackgroundFileSaver *aSaver, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBackgroundFileSaverObserver, NS_IBACKGROUNDFILESAVEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBACKGROUNDFILESAVEROBSERVER \
  NS_IMETHOD OnTargetChange(nsIBackgroundFileSaver *aSaver, nsIFile *aTarget); \
  NS_IMETHOD OnSaveComplete(nsIBackgroundFileSaver *aSaver, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBACKGROUNDFILESAVEROBSERVER(_to) \
  NS_IMETHOD OnTargetChange(nsIBackgroundFileSaver *aSaver, nsIFile *aTarget) { return _to OnTargetChange(aSaver, aTarget); } \
  NS_IMETHOD OnSaveComplete(nsIBackgroundFileSaver *aSaver, nsresult aStatus) { return _to OnSaveComplete(aSaver, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBACKGROUNDFILESAVEROBSERVER(_to) \
  NS_IMETHOD OnTargetChange(nsIBackgroundFileSaver *aSaver, nsIFile *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTargetChange(aSaver, aTarget); } \
  NS_IMETHOD OnSaveComplete(nsIBackgroundFileSaver *aSaver, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSaveComplete(aSaver, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBackgroundFileSaverObserver : public nsIBackgroundFileSaverObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBACKGROUNDFILESAVEROBSERVER

  nsBackgroundFileSaverObserver();

private:
  ~nsBackgroundFileSaverObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBackgroundFileSaverObserver, nsIBackgroundFileSaverObserver)

nsBackgroundFileSaverObserver::nsBackgroundFileSaverObserver()
{
  /* member initializers and constructor code */
}

nsBackgroundFileSaverObserver::~nsBackgroundFileSaverObserver()
{
  /* destructor code */
}

/* void onTargetChange (in nsIBackgroundFileSaver aSaver, in nsIFile aTarget); */
NS_IMETHODIMP nsBackgroundFileSaverObserver::OnTargetChange(nsIBackgroundFileSaver *aSaver, nsIFile *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSaveComplete (in nsIBackgroundFileSaver aSaver, in nsresult aStatus); */
NS_IMETHODIMP nsBackgroundFileSaverObserver::OnSaveComplete(nsIBackgroundFileSaver *aSaver, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBackgroundFileSaver_h__ */
