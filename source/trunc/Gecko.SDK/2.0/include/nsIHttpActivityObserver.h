/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/protocol/http/nsIHttpActivityObserver.idl
 */

#ifndef __gen_nsIHttpActivityObserver_h__
#define __gen_nsIHttpActivityObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHttpActivityObserver */
#define NS_IHTTPACTIVITYOBSERVER_IID_STR "412880c8-6c36-48d8-bf8f-84f91f892503"

#define NS_IHTTPACTIVITYOBSERVER_IID \
  {0x412880c8, 0x6c36, 0x48d8, \
    { 0xbf, 0x8f, 0x84, 0xf9, 0x1f, 0x89, 0x25, 0x03 }}

/**
 * nsIHttpActivityObserver
 *
 * This interface provides a way for http activities to be reported
 * to observers.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHttpActivityObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPACTIVITYOBSERVER_IID)

  /**
     * observe activity from the http transport
     *
     * @param aHttpChannel
     *        nsISupports interface for the the http channel that
     *        generated this activity
     * @param aActivityType
     *        The value of this aActivityType will be one of
     *          ACTIVITY_TYPE_SOCKET_TRANSPORT or
     *          ACTIVITY_TYPE_HTTP_TRANSACTION
     * @param aActivitySubtype
     *        The value of this aActivitySubtype, will be depend
     *        on the value of aActivityType. When aActivityType
     *        is ACTIVITY_TYPE_SOCKET_TRANSPORT
     *          aActivitySubtype will be one of the
     *          nsISocketTransport::STATUS_???? values defined in
     *          nsISocketTransport.idl
     *        OR when aActivityType
     *        is ACTIVITY_TYPE_HTTP_TRANSACTION
     *          aActivitySubtype will be one of the
     *          nsIHttpActivityObserver::ACTIVITY_SUBTYPE_???? values
     *          defined below
     * @param aTimestamp
     *        microseconds past the epoch of Jan 1, 1970
     * @param aExtraSizeData
     *        Any extra size data optionally available with
     *        this activity
     * @param aExtraStringData
     *        Any extra string data optionally available with
     *        this activity
     */
  /* void observeActivity (in nsISupports aHttpChannel, in PRUint32 aActivityType, in PRUint32 aActivitySubtype, in PRTime aTimestamp, in PRUint64 aExtraSizeData, in ACString aExtraStringData); */
  NS_SCRIPTABLE NS_IMETHOD ObserveActivity(nsISupports *aHttpChannel, PRUint32 aActivityType, PRUint32 aActivitySubtype, PRTime aTimestamp, PRUint64 aExtraSizeData, const nsACString & aExtraStringData) = 0;

  /**
     * This attribute is true when this interface is active and should
     * observe http activities. When false, observeActivity() should not
     * be called. It is present for compatibility reasons and should be
     * implemented only by nsHttpActivityDistributor.
     */
  /* readonly attribute boolean isActive; */
  NS_SCRIPTABLE NS_IMETHOD GetIsActive(PRBool *aIsActive) = 0;

  enum { ACTIVITY_TYPE_SOCKET_TRANSPORT = 1U };

  enum { ACTIVITY_TYPE_HTTP_TRANSACTION = 2U };

  enum { ACTIVITY_SUBTYPE_REQUEST_HEADER = 20481U };

  enum { ACTIVITY_SUBTYPE_REQUEST_BODY_SENT = 20482U };

  enum { ACTIVITY_SUBTYPE_RESPONSE_START = 20483U };

  enum { ACTIVITY_SUBTYPE_RESPONSE_HEADER = 20484U };

  enum { ACTIVITY_SUBTYPE_RESPONSE_COMPLETE = 20485U };

  enum { ACTIVITY_SUBTYPE_TRANSACTION_CLOSE = 20486U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpActivityObserver, NS_IHTTPACTIVITYOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPACTIVITYOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD ObserveActivity(nsISupports *aHttpChannel, PRUint32 aActivityType, PRUint32 aActivitySubtype, PRTime aTimestamp, PRUint64 aExtraSizeData, const nsACString & aExtraStringData); \
  NS_SCRIPTABLE NS_IMETHOD GetIsActive(PRBool *aIsActive); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPACTIVITYOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ObserveActivity(nsISupports *aHttpChannel, PRUint32 aActivityType, PRUint32 aActivitySubtype, PRTime aTimestamp, PRUint64 aExtraSizeData, const nsACString & aExtraStringData) { return _to ObserveActivity(aHttpChannel, aActivityType, aActivitySubtype, aTimestamp, aExtraSizeData, aExtraStringData); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsActive(PRBool *aIsActive) { return _to GetIsActive(aIsActive); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPACTIVITYOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ObserveActivity(nsISupports *aHttpChannel, PRUint32 aActivityType, PRUint32 aActivitySubtype, PRTime aTimestamp, PRUint64 aExtraSizeData, const nsACString & aExtraStringData) { return !_to ? NS_ERROR_NULL_POINTER : _to->ObserveActivity(aHttpChannel, aActivityType, aActivitySubtype, aTimestamp, aExtraSizeData, aExtraStringData); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsActive(PRBool *aIsActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsActive(aIsActive); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpActivityObserver : public nsIHttpActivityObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPACTIVITYOBSERVER

  nsHttpActivityObserver();

private:
  ~nsHttpActivityObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpActivityObserver, nsIHttpActivityObserver)

nsHttpActivityObserver::nsHttpActivityObserver()
{
  /* member initializers and constructor code */
}

nsHttpActivityObserver::~nsHttpActivityObserver()
{
  /* destructor code */
}

/* void observeActivity (in nsISupports aHttpChannel, in PRUint32 aActivityType, in PRUint32 aActivitySubtype, in PRTime aTimestamp, in PRUint64 aExtraSizeData, in ACString aExtraStringData); */
NS_IMETHODIMP nsHttpActivityObserver::ObserveActivity(nsISupports *aHttpChannel, PRUint32 aActivityType, PRUint32 aActivitySubtype, PRTime aTimestamp, PRUint64 aExtraSizeData, const nsACString & aExtraStringData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isActive; */
NS_IMETHODIMP nsHttpActivityObserver::GetIsActive(PRBool *aIsActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_HTTP_ACTIVITY_TYPE_SOCKET_TRANSPORT    \
            nsIHttpActivityObserver::ACTIVITY_TYPE_SOCKET_TRANSPORT
#define NS_HTTP_ACTIVITY_TYPE_HTTP_TRANSACTION    \
            nsIHttpActivityObserver::ACTIVITY_TYPE_HTTP_TRANSACTION
#define NS_HTTP_ACTIVITY_SUBTYPE_REQUEST_HEADER    \
            nsIHttpActivityObserver::ACTIVITY_SUBTYPE_REQUEST_HEADER
#define NS_HTTP_ACTIVITY_SUBTYPE_REQUEST_BODY_SENT \
            nsIHttpActivityObserver::ACTIVITY_SUBTYPE_REQUEST_BODY_SENT
#define NS_HTTP_ACTIVITY_SUBTYPE_RESPONSE_START    \
            nsIHttpActivityObserver::ACTIVITY_SUBTYPE_RESPONSE_START
#define NS_HTTP_ACTIVITY_SUBTYPE_RESPONSE_HEADER   \
            nsIHttpActivityObserver::ACTIVITY_SUBTYPE_RESPONSE_HEADER
#define NS_HTTP_ACTIVITY_SUBTYPE_RESPONSE_COMPLETE \
            nsIHttpActivityObserver::ACTIVITY_SUBTYPE_RESPONSE_COMPLETE
#define NS_HTTP_ACTIVITY_SUBTYPE_TRANSACTION_CLOSE \
            nsIHttpActivityObserver::ACTIVITY_SUBTYPE_TRANSACTION_CLOSE

/* starting interface:    nsIHttpActivityDistributor */
#define NS_IHTTPACTIVITYDISTRIBUTOR_IID_STR "7c512cb8-582a-4625-b5b6-8639755271b5"

#define NS_IHTTPACTIVITYDISTRIBUTOR_IID \
  {0x7c512cb8, 0x582a, 0x4625, \
    { 0xb5, 0xb6, 0x86, 0x39, 0x75, 0x52, 0x71, 0xb5 }}

/**
     *  When aActivityType is ACTIVITY_TYPE_SOCKET_TRANSPORT
     *  and aActivitySubtype is STATUS_SENDING_TO
     *  aExtraSizeData will contain the count of bytes sent 
     *  There may be more than one of these activities reported
     *  for a single http transaction, each aExtraSizeData 
     *  represents only that portion of the total bytes sent
     *
     *  When aActivityType is ACTIVITY_TYPE_HTTP_TRANSACTION
     *  and aActivitySubtype is ACTIVITY_SUBTYPE_REQUEST_HEADER
     *  aExtraStringData will contain the text of the header
     *
     *  When aActivityType is ACTIVITY_TYPE_HTTP_TRANSACTION
     *  and aActivitySubtype is ACTIVITY_SUBTYPE_RESPONSE_HEADER
     *  aExtraStringData will contain the text of the header
     *
     *  When aActivityType is ACTIVITY_TYPE_HTTP_TRANSACTION
     *  and aActivitySubtype is ACTIVITY_SUBTYPE_RESPONSE_COMPLETE
     *  aExtraSizeData will contain the count of total bytes received
     */
/**
 * nsIHttpActivityDistributor
 *
 * This interface provides a way to register and unregister observers to the
 * http activities.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHttpActivityDistributor : public nsIHttpActivityObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPACTIVITYDISTRIBUTOR_IID)

  /* void addObserver (in nsIHttpActivityObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIHttpActivityObserver *aObserver) = 0;

  /* void removeObserver (in nsIHttpActivityObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIHttpActivityObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpActivityDistributor, NS_IHTTPACTIVITYDISTRIBUTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPACTIVITYDISTRIBUTOR \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIHttpActivityObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIHttpActivityObserver *aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPACTIVITYDISTRIBUTOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIHttpActivityObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIHttpActivityObserver *aObserver) { return _to RemoveObserver(aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPACTIVITYDISTRIBUTOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIHttpActivityObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIHttpActivityObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpActivityDistributor : public nsIHttpActivityDistributor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPACTIVITYDISTRIBUTOR

  nsHttpActivityDistributor();

private:
  ~nsHttpActivityDistributor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpActivityDistributor, nsIHttpActivityDistributor)

nsHttpActivityDistributor::nsHttpActivityDistributor()
{
  /* member initializers and constructor code */
}

nsHttpActivityDistributor::~nsHttpActivityDistributor()
{
  /* destructor code */
}

/* void addObserver (in nsIHttpActivityObserver aObserver); */
NS_IMETHODIMP nsHttpActivityDistributor::AddObserver(nsIHttpActivityObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIHttpActivityObserver aObserver); */
NS_IMETHODIMP nsHttpActivityDistributor::RemoveObserver(nsIHttpActivityObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpActivityObserver_h__ */
