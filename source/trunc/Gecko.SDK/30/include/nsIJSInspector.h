/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIJSInspector.idl
 */

#ifndef __gen_nsIJSInspector_h__
#define __gen_nsIJSInspector_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJSInspector */
#define NS_IJSINSPECTOR_IID_STR "6758d0d7-e96a-4c5c-bca8-3bcbe5a15943"

#define NS_IJSINSPECTOR_IID \
  {0x6758d0d7, 0xe96a, 0x4c5c, \
    { 0xbc, 0xa8, 0x3b, 0xcb, 0xe5, 0xa1, 0x59, 0x43 }}

class NS_NO_VTABLE nsIJSInspector : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSINSPECTOR_IID)

  /* unsigned long enterNestedEventLoop (in jsval requestor); */
  NS_IMETHOD EnterNestedEventLoop(JS::HandleValue requestor, uint32_t *_retval) = 0;

  /* unsigned long exitNestedEventLoop (); */
  NS_IMETHOD ExitNestedEventLoop(uint32_t *_retval) = 0;

  /* readonly attribute unsigned long eventLoopNestLevel; */
  NS_IMETHOD GetEventLoopNestLevel(uint32_t *aEventLoopNestLevel) = 0;

  /* readonly attribute jsval lastNestRequestor; */
  NS_IMETHOD GetLastNestRequestor(JS::MutableHandleValue aLastNestRequestor) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSInspector, NS_IJSINSPECTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSINSPECTOR \
  NS_IMETHOD EnterNestedEventLoop(JS::HandleValue requestor, uint32_t *_retval); \
  NS_IMETHOD ExitNestedEventLoop(uint32_t *_retval); \
  NS_IMETHOD GetEventLoopNestLevel(uint32_t *aEventLoopNestLevel); \
  NS_IMETHOD GetLastNestRequestor(JS::MutableHandleValue aLastNestRequestor); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSINSPECTOR(_to) \
  NS_IMETHOD EnterNestedEventLoop(JS::HandleValue requestor, uint32_t *_retval) { return _to EnterNestedEventLoop(requestor, _retval); } \
  NS_IMETHOD ExitNestedEventLoop(uint32_t *_retval) { return _to ExitNestedEventLoop(_retval); } \
  NS_IMETHOD GetEventLoopNestLevel(uint32_t *aEventLoopNestLevel) { return _to GetEventLoopNestLevel(aEventLoopNestLevel); } \
  NS_IMETHOD GetLastNestRequestor(JS::MutableHandleValue aLastNestRequestor) { return _to GetLastNestRequestor(aLastNestRequestor); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSINSPECTOR(_to) \
  NS_IMETHOD EnterNestedEventLoop(JS::HandleValue requestor, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterNestedEventLoop(requestor, _retval); } \
  NS_IMETHOD ExitNestedEventLoop(uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitNestedEventLoop(_retval); } \
  NS_IMETHOD GetEventLoopNestLevel(uint32_t *aEventLoopNestLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventLoopNestLevel(aEventLoopNestLevel); } \
  NS_IMETHOD GetLastNestRequestor(JS::MutableHandleValue aLastNestRequestor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastNestRequestor(aLastNestRequestor); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSInspector : public nsIJSInspector
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSINSPECTOR

  nsJSInspector();

private:
  ~nsJSInspector();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSInspector, nsIJSInspector)

nsJSInspector::nsJSInspector()
{
  /* member initializers and constructor code */
}

nsJSInspector::~nsJSInspector()
{
  /* destructor code */
}

/* unsigned long enterNestedEventLoop (in jsval requestor); */
NS_IMETHODIMP nsJSInspector::EnterNestedEventLoop(JS::HandleValue requestor, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long exitNestedEventLoop (); */
NS_IMETHODIMP nsJSInspector::ExitNestedEventLoop(uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long eventLoopNestLevel; */
NS_IMETHODIMP nsJSInspector::GetEventLoopNestLevel(uint32_t *aEventLoopNestLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval lastNestRequestor; */
NS_IMETHODIMP nsJSInspector::GetLastNestRequestor(JS::MutableHandleValue aLastNestRequestor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJSInspector_h__ */
