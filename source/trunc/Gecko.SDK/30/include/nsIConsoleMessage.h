/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIConsoleMessage.idl
 */

#ifndef __gen_nsIConsoleMessage_h__
#define __gen_nsIConsoleMessage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIConsoleMessage */
#define NS_ICONSOLEMESSAGE_IID_STR "c14c151b-5ea4-47ed-8e85-d392cdd3e154"

#define NS_ICONSOLEMESSAGE_IID \
  {0xc14c151b, 0x5ea4, 0x47ed, \
    { 0x8e, 0x85, 0xd3, 0x92, 0xcd, 0xd3, 0xe1, 0x54 }}

class NS_NO_VTABLE nsIConsoleMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONSOLEMESSAGE_IID)

  /* readonly attribute long long timeStamp; */
  NS_IMETHOD GetTimeStamp(int64_t *aTimeStamp) = 0;

  /* [binaryname(MessageMoz)] readonly attribute wstring message; */
  NS_IMETHOD GetMessageMoz(char16_t * *aMessage) = 0;

  /* AUTF8String toString (); */
  NS_IMETHOD ToString(nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConsoleMessage, NS_ICONSOLEMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONSOLEMESSAGE \
  NS_IMETHOD GetTimeStamp(int64_t *aTimeStamp); \
  NS_IMETHOD GetMessageMoz(char16_t * *aMessage); \
  NS_IMETHOD ToString(nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONSOLEMESSAGE(_to) \
  NS_IMETHOD GetTimeStamp(int64_t *aTimeStamp) { return _to GetTimeStamp(aTimeStamp); } \
  NS_IMETHOD GetMessageMoz(char16_t * *aMessage) { return _to GetMessageMoz(aMessage); } \
  NS_IMETHOD ToString(nsACString & _retval) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONSOLEMESSAGE(_to) \
  NS_IMETHOD GetTimeStamp(int64_t *aTimeStamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeStamp(aTimeStamp); } \
  NS_IMETHOD GetMessageMoz(char16_t * *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(aMessage); } \
  NS_IMETHOD ToString(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConsoleMessage : public nsIConsoleMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONSOLEMESSAGE

  nsConsoleMessage();

private:
  ~nsConsoleMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConsoleMessage, nsIConsoleMessage)

nsConsoleMessage::nsConsoleMessage()
{
  /* member initializers and constructor code */
}

nsConsoleMessage::~nsConsoleMessage()
{
  /* destructor code */
}

/* readonly attribute long long timeStamp; */
NS_IMETHODIMP nsConsoleMessage::GetTimeStamp(int64_t *aTimeStamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(MessageMoz)] readonly attribute wstring message; */
NS_IMETHODIMP nsConsoleMessage::GetMessageMoz(char16_t * *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toString (); */
NS_IMETHODIMP nsConsoleMessage::ToString(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CONSOLEMESSAGE_CID \
{ 0x024efc9e, 0x54dc, 0x4844, { 0x80, 0x4b, 0x41, 0xd3, 0xf3, 0x69, 0x90, 0x73 }}

#endif /* __gen_nsIConsoleMessage_h__ */
