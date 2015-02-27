/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIScriptChannel.idl
 */

#ifndef __gen_nsIScriptChannel_h__
#define __gen_nsIScriptChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptChannel */
#define NS_ISCRIPTCHANNEL_IID_STR "33234b99-9588-4c7d-9da6-86b8b7cba565"

#define NS_ISCRIPTCHANNEL_IID \
  {0x33234b99, 0x9588, 0x4c7d, \
    { 0x9d, 0xa6, 0x86, 0xb8, 0xb7, 0xcb, 0xa5, 0x65 }}

class NS_NO_VTABLE nsIScriptChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTCHANNEL_IID)

  enum {
    NO_EXECUTION = 0U,
    EXECUTE_IN_SANDBOX = 1U,
    EXECUTE_NORMAL = 2U
  };

  /* attribute unsigned long executionPolicy; */
  NS_IMETHOD GetExecutionPolicy(uint32_t *aExecutionPolicy) = 0;
  NS_IMETHOD SetExecutionPolicy(uint32_t aExecutionPolicy) = 0;

  /* attribute boolean executeAsync; */
  NS_IMETHOD GetExecuteAsync(bool *aExecuteAsync) = 0;
  NS_IMETHOD SetExecuteAsync(bool aExecuteAsync) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptChannel, NS_ISCRIPTCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTCHANNEL \
  NS_IMETHOD GetExecutionPolicy(uint32_t *aExecutionPolicy); \
  NS_IMETHOD SetExecutionPolicy(uint32_t aExecutionPolicy); \
  NS_IMETHOD GetExecuteAsync(bool *aExecuteAsync); \
  NS_IMETHOD SetExecuteAsync(bool aExecuteAsync); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTCHANNEL(_to) \
  NS_IMETHOD GetExecutionPolicy(uint32_t *aExecutionPolicy) { return _to GetExecutionPolicy(aExecutionPolicy); } \
  NS_IMETHOD SetExecutionPolicy(uint32_t aExecutionPolicy) { return _to SetExecutionPolicy(aExecutionPolicy); } \
  NS_IMETHOD GetExecuteAsync(bool *aExecuteAsync) { return _to GetExecuteAsync(aExecuteAsync); } \
  NS_IMETHOD SetExecuteAsync(bool aExecuteAsync) { return _to SetExecuteAsync(aExecuteAsync); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTCHANNEL(_to) \
  NS_IMETHOD GetExecutionPolicy(uint32_t *aExecutionPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExecutionPolicy(aExecutionPolicy); } \
  NS_IMETHOD SetExecutionPolicy(uint32_t aExecutionPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExecutionPolicy(aExecutionPolicy); } \
  NS_IMETHOD GetExecuteAsync(bool *aExecuteAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExecuteAsync(aExecuteAsync); } \
  NS_IMETHOD SetExecuteAsync(bool aExecuteAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExecuteAsync(aExecuteAsync); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptChannel : public nsIScriptChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTCHANNEL

  nsScriptChannel();

private:
  ~nsScriptChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptChannel, nsIScriptChannel)

nsScriptChannel::nsScriptChannel()
{
  /* member initializers and constructor code */
}

nsScriptChannel::~nsScriptChannel()
{
  /* destructor code */
}

/* attribute unsigned long executionPolicy; */
NS_IMETHODIMP nsScriptChannel::GetExecutionPolicy(uint32_t *aExecutionPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsScriptChannel::SetExecutionPolicy(uint32_t aExecutionPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean executeAsync; */
NS_IMETHODIMP nsScriptChannel::GetExecuteAsync(bool *aExecuteAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsScriptChannel::SetExecuteAsync(bool aExecuteAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptChannel_h__ */
