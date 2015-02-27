/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/uriloader/base/nsITransfer.idl
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

class nsILocalFile; /* forward declaration */


/* starting interface:    nsITransfer */
#define NS_ITRANSFER_IID_STR "3a982955-dc44-422e-8734-8462bf8d2121"

#define NS_ITRANSFER_IID \
  {0x3a982955, 0xdc44, 0x422e, \
    { 0x87, 0x34, 0x84, 0x62, 0xbf, 0x8d, 0x21, 0x21 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITransfer : public nsIWebProgressListener2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSFER_IID)

  /**
     * Initializes the transfer with certain properties.  This function must
     * be called prior to accessing any properties on this interface.
     *
     * @param aSource The source URI of the transfer. Must not be null.
     *
     * @param aTarget The target URI of the transfer. Must not be null.
     *
     * @param aDisplayName The user-readable description of the transfer.
     *                     Can be empty.
     *
     * @param aMIMEInfo The MIME info associated with the target,
     *                  including MIME type and helper app when appropriate.
     *                  This parameter is optional.
     *
     * @param startTime Time when the download started (ie, when the first
     *                  response from the server was received)
     *                  XXX presumably wbp and exthandler do this differently
     *
     * @param aTempFile The location of a temporary file; i.e. a file in which
     *                  the received data will be stored, but which is not
     *                  equal to the target file. (will be moved to the real
     *                  target by the caller, when the download is finished)
     *                  May be null.
     *
     * @param aCancelable An object that can be used to abort the download.
     *                    Must not be null.
     *                    Implementations are expected to hold a strong
     *                    reference to this object until the download is
     *                    finished, at which point they should release the
     *                    reference.
     */
  /* void init (in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime startTime, in nsILocalFile aTempFile, in nsICancelable aCancelable); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsILocalFile *aTempFile, nsICancelable *aCancelable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransfer, NS_ITRANSFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSFER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsILocalFile *aTempFile, nsICancelable *aCancelable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSFER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsILocalFile *aTempFile, nsICancelable *aCancelable) { return _to Init(aSource, aTarget, aDisplayName, aMIMEInfo, startTime, aTempFile, aCancelable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSFER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsILocalFile *aTempFile, nsICancelable *aCancelable) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aSource, aTarget, aDisplayName, aMIMEInfo, startTime, aTempFile, aCancelable); } 

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

/* void init (in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime startTime, in nsILocalFile aTempFile, in nsICancelable aCancelable); */
NS_IMETHODIMP nsTransfer::Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsILocalFile *aTempFile, nsICancelable *aCancelable)
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
