/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISecurityConsoleMessage.idl
 */

#ifndef __gen_nsISecurityConsoleMessage_h__
#define __gen_nsISecurityConsoleMessage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISecurityConsoleMessage */
#define NS_ISECURITYCONSOLEMESSAGE_IID_STR "fe9fc9b6-dde2-11e2-a8f1-0a326188709b"

#define NS_ISECURITYCONSOLEMESSAGE_IID \
  {0xfe9fc9b6, 0xdde2, 0x11e2, \
    { 0xa8, 0xf1, 0x0a, 0x32, 0x61, 0x88, 0x70, 0x9b }}

class NS_NO_VTABLE nsISecurityConsoleMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECURITYCONSOLEMESSAGE_IID)

  /* attribute AString tag; */
  NS_IMETHOD GetTag(nsAString & aTag) = 0;
  NS_IMETHOD SetTag(const nsAString & aTag) = 0;

  /* attribute AString category; */
  NS_IMETHOD GetCategory(nsAString & aCategory) = 0;
  NS_IMETHOD SetCategory(const nsAString & aCategory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecurityConsoleMessage, NS_ISECURITYCONSOLEMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECURITYCONSOLEMESSAGE \
  NS_IMETHOD GetTag(nsAString & aTag); \
  NS_IMETHOD SetTag(const nsAString & aTag); \
  NS_IMETHOD GetCategory(nsAString & aCategory); \
  NS_IMETHOD SetCategory(const nsAString & aCategory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECURITYCONSOLEMESSAGE(_to) \
  NS_IMETHOD GetTag(nsAString & aTag) { return _to GetTag(aTag); } \
  NS_IMETHOD SetTag(const nsAString & aTag) { return _to SetTag(aTag); } \
  NS_IMETHOD GetCategory(nsAString & aCategory) { return _to GetCategory(aCategory); } \
  NS_IMETHOD SetCategory(const nsAString & aCategory) { return _to SetCategory(aCategory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECURITYCONSOLEMESSAGE(_to) \
  NS_IMETHOD GetTag(nsAString & aTag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTag(aTag); } \
  NS_IMETHOD SetTag(const nsAString & aTag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTag(aTag); } \
  NS_IMETHOD GetCategory(nsAString & aCategory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCategory(aCategory); } \
  NS_IMETHOD SetCategory(const nsAString & aCategory) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCategory(aCategory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecurityConsoleMessage : public nsISecurityConsoleMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECURITYCONSOLEMESSAGE

  nsSecurityConsoleMessage();

private:
  ~nsSecurityConsoleMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecurityConsoleMessage, nsISecurityConsoleMessage)

nsSecurityConsoleMessage::nsSecurityConsoleMessage()
{
  /* member initializers and constructor code */
}

nsSecurityConsoleMessage::~nsSecurityConsoleMessage()
{
  /* destructor code */
}

/* attribute AString tag; */
NS_IMETHODIMP nsSecurityConsoleMessage::GetTag(nsAString & aTag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSecurityConsoleMessage::SetTag(const nsAString & aTag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString category; */
NS_IMETHODIMP nsSecurityConsoleMessage::GetCategory(nsAString & aCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSecurityConsoleMessage::SetCategory(const nsAString & aCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SECURITY_CONSOLE_MESSAGE_CONTRACTID "@mozilla.org/securityconsole/message;1"

#endif /* __gen_nsISecurityConsoleMessage_h__ */
