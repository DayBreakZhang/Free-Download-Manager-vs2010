/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/uriloader/base/nsITransfer.idl
 */

#ifndef __gen_nsITransfer_h__
#define __gen_nsITransfer_h__


#ifndef __gen_nsIWebProgressListener2_h__
#include "nsIWebProgressListener2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIMIMEInfo; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsITransfer */
#define NS_ITRANSFER_IID_STR "08b0b78c-6d7d-4d97-86c9-be5a695813c9"

#define NS_ITRANSFER_IID \
  {0x08b0b78c, 0x6d7d, 0x4d97, \
    { 0x86, 0xc9, 0xbe, 0x5a, 0x69, 0x58, 0x13, 0xc9 }}

class NS_NO_VTABLE nsITransfer : public nsIWebProgressListener2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSFER_IID)

  /* void init (in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime startTime, in nsIFile aTempFile, in nsICancelable aCancelable, in boolean aIsPrivate); */
  NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransfer, NS_ITRANSFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSFER \
  NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSFER(_to) \
  NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate) { return _to Init(aSource, aTarget, aDisplayName, aMIMEInfo, startTime, aTempFile, aCancelable, aIsPrivate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSFER(_to) \
  NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aSource, aTarget, aDisplayName, aMIMEInfo, startTime, aTempFile, aCancelable, aIsPrivate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransfer : public nsITransfer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSFER

  nsTransfer();

private:
  ~nsTransfer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransfer, nsITransfer)

nsTransfer::nsTransfer()
{
  /* member initializers and constructor code */
}

nsTransfer::~nsTransfer()
{
  /* destructor code */
}

/* void init (in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime startTime, in nsIFile aTempFile, in nsICancelable aCancelable, in boolean aIsPrivate); */
NS_IMETHODIMP nsTransfer::Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * A component with this contract ID will be created each time a download is
 * started, and nsITransfer::Init will be called on it and an observer will be set.
 *
 * Notifications of the download progress will happen via
 * nsIWebProgressListener/nsIWebProgressListener2.
 *
 * INTERFACES THAT MUST BE IMPLEMENTED:
 *   nsITransfer
 *   nsIWebProgressListener
 *   nsIWebProgressListener2
 *
 * XXX move this to nsEmbedCID.h once the interfaces (and the contract ID) are
 * frozen.
 */
#define NS_TRANSFER_CONTRACTID "@mozilla.org/transfer;1"

#endif /* __gen_nsITransfer_h__ */
