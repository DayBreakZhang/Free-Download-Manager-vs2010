/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITaskbarProgress.idl
 */

#ifndef __gen_nsITaskbarProgress_h__
#define __gen_nsITaskbarProgress_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIBaseWindow_h__
#include "nsIBaseWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef int32_t  nsTaskbarProgressState;


/* starting interface:    nsITaskbarProgress */
#define NS_ITASKBARPROGRESS_IID_STR "23ac257d-ef3c-4033-b424-be7fef91a86c"

#define NS_ITASKBARPROGRESS_IID \
  {0x23ac257d, 0xef3c, 0x4033, \
    { 0xb4, 0x24, 0xbe, 0x7f, 0xef, 0x91, 0xa8, 0x6c }}

class NS_NO_VTABLE nsITaskbarProgress : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBARPROGRESS_IID)

  enum {
    STATE_NO_PROGRESS = 0,
    STATE_INDETERMINATE = 1,
    STATE_NORMAL = 2,
    STATE_ERROR = 3,
    STATE_PAUSED = 4
  };

  /* void setProgressState (in nsTaskbarProgressState state, [optional] in unsigned long long currentValue, [optional] in unsigned long long maxValue); */
  NS_IMETHOD SetProgressState(nsTaskbarProgressState state, uint64_t currentValue, uint64_t maxValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarProgress, NS_ITASKBARPROGRESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBARPROGRESS \
  NS_IMETHOD SetProgressState(nsTaskbarProgressState state, uint64_t currentValue, uint64_t maxValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBARPROGRESS(_to) \
  NS_IMETHOD SetProgressState(nsTaskbarProgressState state, uint64_t currentValue, uint64_t maxValue) { return _to SetProgressState(state, currentValue, maxValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBARPROGRESS(_to) \
  NS_IMETHOD SetProgressState(nsTaskbarProgressState state, uint64_t currentValue, uint64_t maxValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProgressState(state, currentValue, maxValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaskbarProgress : public nsITaskbarProgress
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITASKBARPROGRESS

  nsTaskbarProgress();

private:
  ~nsTaskbarProgress();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaskbarProgress, nsITaskbarProgress)

nsTaskbarProgress::nsTaskbarProgress()
{
  /* member initializers and constructor code */
}

nsTaskbarProgress::~nsTaskbarProgress()
{
  /* destructor code */
}

/* void setProgressState (in nsTaskbarProgressState state, [optional] in unsigned long long currentValue, [optional] in unsigned long long maxValue); */
NS_IMETHODIMP nsTaskbarProgress::SetProgressState(nsTaskbarProgressState state, uint64_t currentValue, uint64_t maxValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarProgress_h__ */
