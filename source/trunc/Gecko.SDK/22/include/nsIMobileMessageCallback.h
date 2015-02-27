/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIMobileMessageCallback.idl
 */

#ifndef __gen_nsIMobileMessageCallback_h__
#define __gen_nsIMobileMessageCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMobileMessageCallback */
#define NS_IMOBILEMESSAGECALLBACK_IID_STR "edb1de12-8d58-11e2-b382-7bf132b20cb2"

#define NS_IMOBILEMESSAGECALLBACK_IID \
  {0xedb1de12, 0x8d58, 0x11e2, \
    { 0xb3, 0x82, 0x7b, 0xf1, 0x32, 0xb2, 0x0c, 0xb2 }}

class NS_NO_VTABLE nsIMobileMessageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGECALLBACK_IID)

  enum {
    SUCCESS_NO_ERROR = 0U,
    NO_SIGNAL_ERROR = 1U,
    NOT_FOUND_ERROR = 2U,
    UNKNOWN_ERROR = 3U,
    INTERNAL_ERROR = 4U
  };

  /* void notifyMessageSent (in nsISupports message); */
  NS_IMETHOD NotifyMessageSent(nsISupports *message) = 0;

  /* void notifySendMessageFailed (in long error); */
  NS_IMETHOD NotifySendMessageFailed(int32_t error) = 0;

  /* void notifyMessageGot (in nsISupports message); */
  NS_IMETHOD NotifyMessageGot(nsISupports *message) = 0;

  /* void notifyGetMessageFailed (in long error); */
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) = 0;

  /* void notifyMessageDeleted (in boolean deleted); */
  NS_IMETHOD NotifyMessageDeleted(bool deleted) = 0;

  /* void notifyDeleteMessageFailed (in long error); */
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) = 0;

  /* void notifyMessageListCreated (in long listId, in nsISupports message); */
  NS_IMETHOD NotifyMessageListCreated(int32_t listId, nsISupports *message) = 0;

  /* void notifyReadMessageListFailed (in long error); */
  NS_IMETHOD NotifyReadMessageListFailed(int32_t error) = 0;

  /* void notifyNextMessageInListGot (in nsISupports message); */
  NS_IMETHOD NotifyNextMessageInListGot(nsISupports *message) = 0;

  /* void notifyNoMessageInList (); */
  NS_IMETHOD NotifyNoMessageInList(void) = 0;

  /* void notifyMessageMarkedRead (in boolean read); */
  NS_IMETHOD NotifyMessageMarkedRead(bool read) = 0;

  /* void notifyMarkMessageReadFailed (in long error); */
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) = 0;

  /* [implicit_jscontext] void notifyThreadList (in jsval threadList); */
  NS_IMETHOD NotifyThreadList(const JS::Value & threadList, JSContext* cx) = 0;

  /* void notifyThreadListFailed (in long error); */
  NS_IMETHOD NotifyThreadListFailed(int32_t error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageCallback, NS_IMOBILEMESSAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGECALLBACK \
  NS_IMETHOD NotifyMessageSent(nsISupports *message); \
  NS_IMETHOD NotifySendMessageFailed(int32_t error); \
  NS_IMETHOD NotifyMessageGot(nsISupports *message); \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error); \
  NS_IMETHOD NotifyMessageDeleted(bool deleted); \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error); \
  NS_IMETHOD NotifyMessageListCreated(int32_t listId, nsISupports *message); \
  NS_IMETHOD NotifyReadMessageListFailed(int32_t error); \
  NS_IMETHOD NotifyNextMessageInListGot(nsISupports *message); \
  NS_IMETHOD NotifyNoMessageInList(void); \
  NS_IMETHOD NotifyMessageMarkedRead(bool read); \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error); \
  NS_IMETHOD NotifyThreadList(const JS::Value & threadList, JSContext* cx); \
  NS_IMETHOD NotifyThreadListFailed(int32_t error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGECALLBACK(_to) \
  NS_IMETHOD NotifyMessageSent(nsISupports *message) { return _to NotifyMessageSent(message); } \
  NS_IMETHOD NotifySendMessageFailed(int32_t error) { return _to NotifySendMessageFailed(error); } \
  NS_IMETHOD NotifyMessageGot(nsISupports *message) { return _to NotifyMessageGot(message); } \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) { return _to NotifyGetMessageFailed(error); } \
  NS_IMETHOD NotifyMessageDeleted(bool deleted) { return _to NotifyMessageDeleted(deleted); } \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) { return _to NotifyDeleteMessageFailed(error); } \
  NS_IMETHOD NotifyMessageListCreated(int32_t listId, nsISupports *message) { return _to NotifyMessageListCreated(listId, message); } \
  NS_IMETHOD NotifyReadMessageListFailed(int32_t error) { return _to NotifyReadMessageListFailed(error); } \
  NS_IMETHOD NotifyNextMessageInListGot(nsISupports *message) { return _to NotifyNextMessageInListGot(message); } \
  NS_IMETHOD NotifyNoMessageInList(void) { return _to NotifyNoMessageInList(); } \
  NS_IMETHOD NotifyMessageMarkedRead(bool read) { return _to NotifyMessageMarkedRead(read); } \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) { return _to NotifyMarkMessageReadFailed(error); } \
  NS_IMETHOD NotifyThreadList(const JS::Value & threadList, JSContext* cx) { return _to NotifyThreadList(threadList, cx); } \
  NS_IMETHOD NotifyThreadListFailed(int32_t error) { return _to NotifyThreadListFailed(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGECALLBACK(_to) \
  NS_IMETHOD NotifyMessageSent(nsISupports *message) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageSent(message); } \
  NS_IMETHOD NotifySendMessageFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySendMessageFailed(error); } \
  NS_IMETHOD NotifyMessageGot(nsISupports *message) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageGot(message); } \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetMessageFailed(error); } \
  NS_IMETHOD NotifyMessageDeleted(bool deleted) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageDeleted(deleted); } \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDeleteMessageFailed(error); } \
  NS_IMETHOD NotifyMessageListCreated(int32_t listId, nsISupports *message) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageListCreated(listId, message); } \
  NS_IMETHOD NotifyReadMessageListFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyReadMessageListFailed(error); } \
  NS_IMETHOD NotifyNextMessageInListGot(nsISupports *message) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyNextMessageInListGot(message); } \
  NS_IMETHOD NotifyNoMessageInList(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyNoMessageInList(); } \
  NS_IMETHOD NotifyMessageMarkedRead(bool read) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageMarkedRead(read); } \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMarkMessageReadFailed(error); } \
  NS_IMETHOD NotifyThreadList(const JS::Value & threadList, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyThreadList(threadList, cx); } \
  NS_IMETHOD NotifyThreadListFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyThreadListFailed(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageCallback : public nsIMobileMessageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGECALLBACK

  nsMobileMessageCallback();

private:
  ~nsMobileMessageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMobileMessageCallback, nsIMobileMessageCallback)

nsMobileMessageCallback::nsMobileMessageCallback()
{
  /* member initializers and constructor code */
}

nsMobileMessageCallback::~nsMobileMessageCallback()
{
  /* destructor code */
}

/* void notifyMessageSent (in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageSent(nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifySendMessageFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifySendMessageFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageGot (in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageGot(nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetMessageFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyGetMessageFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageDeleted (in boolean deleted); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageDeleted(bool deleted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDeleteMessageFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyDeleteMessageFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageListCreated (in long listId, in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageListCreated(int32_t listId, nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyReadMessageListFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyReadMessageListFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyNextMessageInListGot (in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyNextMessageInListGot(nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyNoMessageInList (); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyNoMessageInList()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageMarkedRead (in boolean read); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageMarkedRead(bool read)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMarkMessageReadFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMarkMessageReadFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void notifyThreadList (in jsval threadList); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyThreadList(const JS::Value & threadList, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyThreadListFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyThreadListFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileMessageCallback_h__ */
