/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISerializationHelper.idl
 */

#ifndef __gen_nsISerializationHelper_h__
#define __gen_nsISerializationHelper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISerializable; /* forward declaration */


/* starting interface:    nsISerializationHelper */
#define NS_ISERIALIZATIONHELPER_IID_STR "31654c0f-35f3-44c6-b31e-37a11516e6bc"

#define NS_ISERIALIZATIONHELPER_IID \
  {0x31654c0f, 0x35f3, 0x44c6, \
    { 0xb3, 0x1e, 0x37, 0xa1, 0x15, 0x16, 0xe6, 0xbc }}

class NS_NO_VTABLE nsISerializationHelper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERIALIZATIONHELPER_IID)

  /* ACString serializeToString (in nsISerializable serializable); */
  NS_IMETHOD SerializeToString(nsISerializable *serializable, nsACString & _retval) = 0;

  /* nsISupports deserializeObject (in ACString input); */
  NS_IMETHOD DeserializeObject(const nsACString & input, nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISerializationHelper, NS_ISERIALIZATIONHELPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERIALIZATIONHELPER \
  NS_IMETHOD SerializeToString(nsISerializable *serializable, nsACString & _retval); \
  NS_IMETHOD DeserializeObject(const nsACString & input, nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERIALIZATIONHELPER(_to) \
  NS_IMETHOD SerializeToString(nsISerializable *serializable, nsACString & _retval) { return _to SerializeToString(serializable, _retval); } \
  NS_IMETHOD DeserializeObject(const nsACString & input, nsISupports * *_retval) { return _to DeserializeObject(input, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERIALIZATIONHELPER(_to) \
  NS_IMETHOD SerializeToString(nsISerializable *serializable, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SerializeToString(serializable, _retval); } \
  NS_IMETHOD DeserializeObject(const nsACString & input, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeserializeObject(input, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSerializationHelper : public nsISerializationHelper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERIALIZATIONHELPER

  nsSerializationHelper();

private:
  ~nsSerializationHelper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSerializationHelper, nsISerializationHelper)

nsSerializationHelper::nsSerializationHelper()
{
  /* member initializers and constructor code */
}

nsSerializationHelper::~nsSerializationHelper()
{
  /* destructor code */
}

/* ACString serializeToString (in nsISerializable serializable); */
NS_IMETHODIMP nsSerializationHelper::SerializeToString(nsISerializable *serializable, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports deserializeObject (in ACString input); */
NS_IMETHODIMP nsSerializationHelper::DeserializeObject(const nsACString & input, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISerializationHelper_h__ */
