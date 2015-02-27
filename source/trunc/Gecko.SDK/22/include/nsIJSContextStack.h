/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/js/xpconnect/idl/nsIJSContextStack.idl
 */

#ifndef __gen_nsIJSContextStack_h__
#define __gen_nsIJSContextStack_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJSContextStack */
#define NS_IJSCONTEXTSTACK_IID_STR "c67d8270-3189-11d3-9885-006008962422"

#define NS_IJSCONTEXTSTACK_IID \
  {0xc67d8270, 0x3189, 0x11d3, \
    { 0x98, 0x85, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

class NS_NO_VTABLE nsIJSContextStack : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSCONTEXTSTACK_IID)

  /* readonly attribute int32_t count; */
  NS_IMETHOD GetCount(int32_t *aCount) = 0;

  /* JSContext peek (); */
  NS_IMETHOD Peek(JSContext **_retval) = 0;

  /* JSContext pop (); */
  NS_IMETHOD Pop(JSContext **_retval) = 0;

  /* void push (in JSContext cx); */
  NS_IMETHOD Push(JSContext *cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSContextStack, NS_IJSCONTEXTSTACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSCONTEXTSTACK \
  NS_IMETHOD GetCount(int32_t *aCount); \
  NS_IMETHOD Peek(JSContext **_retval); \
  NS_IMETHOD Pop(JSContext **_retval); \
  NS_IMETHOD Push(JSContext *cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSCONTEXTSTACK(_to) \
  NS_IMETHOD GetCount(int32_t *aCount) { return _to GetCount(aCount); } \
  NS_IMETHOD Peek(JSContext **_retval) { return _to Peek(_retval); } \
  NS_IMETHOD Pop(JSContext **_retval) { return _to Pop(_retval); } \
  NS_IMETHOD Push(JSContext *cx) { return _to Push(cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSCONTEXTSTACK(_to) \
  NS_IMETHOD GetCount(int32_t *aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(aCount); } \
  NS_IMETHOD Peek(JSContext **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Peek(_retval); } \
  NS_IMETHOD Pop(JSContext **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Pop(_retval); } \
  NS_IMETHOD Push(JSContext *cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Push(cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSContextStack : public nsIJSContextStack
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSCONTEXTSTACK

  nsJSContextStack();

private:
  ~nsJSContextStack();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSContextStack, nsIJSContextStack)

nsJSContextStack::nsJSContextStack()
{
  /* member initializers and constructor code */
}

nsJSContextStack::~nsJSContextStack()
{
  /* destructor code */
}

/* readonly attribute int32_t count; */
NS_IMETHODIMP nsJSContextStack::GetCount(int32_t *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* JSContext peek (); */
NS_IMETHODIMP nsJSContextStack::Peek(JSContext **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* JSContext pop (); */
NS_IMETHODIMP nsJSContextStack::Pop(JSContext **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void push (in JSContext cx); */
NS_IMETHODIMP nsJSContextStack::Push(JSContext *cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJSContextStackIterator */
#define NS_IJSCONTEXTSTACKITERATOR_IID_STR "c7e6b7aa-fc12-4ca7-b140-98c38b698961"

#define NS_IJSCONTEXTSTACKITERATOR_IID \
  {0xc7e6b7aa, 0xfc12, 0x4ca7, \
    { 0xb1, 0x40, 0x98, 0xc3, 0x8b, 0x69, 0x89, 0x61 }}

class NS_NO_VTABLE nsIJSContextStackIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSCONTEXTSTACKITERATOR_IID)

  /* void reset (in nsIJSContextStack stack); */
  NS_IMETHOD Reset(nsIJSContextStack *stack) = 0;

  /* boolean done (); */
  NS_IMETHOD Done(bool *_retval) = 0;

  /* JSContext prev (); */
  NS_IMETHOD Prev(JSContext **_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSContextStackIterator, NS_IJSCONTEXTSTACKITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSCONTEXTSTACKITERATOR \
  NS_IMETHOD Reset(nsIJSContextStack *stack); \
  NS_IMETHOD Done(bool *_retval); \
  NS_IMETHOD Prev(JSContext **_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSCONTEXTSTACKITERATOR(_to) \
  NS_IMETHOD Reset(nsIJSContextStack *stack) { return _to Reset(stack); } \
  NS_IMETHOD Done(bool *_retval) { return _to Done(_retval); } \
  NS_IMETHOD Prev(JSContext **_retval) { return _to Prev(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSCONTEXTSTACKITERATOR(_to) \
  NS_IMETHOD Reset(nsIJSContextStack *stack) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(stack); } \
  NS_IMETHOD Done(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(_retval); } \
  NS_IMETHOD Prev(JSContext **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Prev(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSContextStackIterator : public nsIJSContextStackIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSCONTEXTSTACKITERATOR

  nsJSContextStackIterator();

private:
  ~nsJSContextStackIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSContextStackIterator, nsIJSContextStackIterator)

nsJSContextStackIterator::nsJSContextStackIterator()
{
  /* member initializers and constructor code */
}

nsJSContextStackIterator::~nsJSContextStackIterator()
{
  /* destructor code */
}

/* void reset (in nsIJSContextStack stack); */
NS_IMETHODIMP nsJSContextStackIterator::Reset(nsIJSContextStack *stack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean done (); */
NS_IMETHODIMP nsJSContextStackIterator::Done(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* JSContext prev (); */
NS_IMETHODIMP nsJSContextStackIterator::Prev(JSContext **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIThreadJSContextStack */
#define NS_ITHREADJSCONTEXTSTACK_IID_STR "59ad3ff1-a2d3-4c11-b825-098bff3c3e15"

#define NS_ITHREADJSCONTEXTSTACK_IID \
  {0x59ad3ff1, 0xa2d3, 0x4c11, \
    { 0xb8, 0x25, 0x09, 0x8b, 0xff, 0x3c, 0x3e, 0x15 }}

class NS_NO_VTABLE nsIThreadJSContextStack : public nsIJSContextStack {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADJSCONTEXTSTACK_IID)

  /* [nostdcall,notxpcom] JSContext getSafeJSContext (); */
  virtual JSContext * GetSafeJSContext(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadJSContextStack, NS_ITHREADJSCONTEXTSTACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADJSCONTEXTSTACK \
  virtual JSContext * GetSafeJSContext(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADJSCONTEXTSTACK(_to) \
  virtual JSContext * GetSafeJSContext(void) { return _to GetSafeJSContext(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADJSCONTEXTSTACK(_to) \
  virtual JSContext * GetSafeJSContext(void); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadJSContextStack : public nsIThreadJSContextStack
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADJSCONTEXTSTACK

  nsThreadJSContextStack();

private:
  ~nsThreadJSContextStack();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadJSContextStack, nsIThreadJSContextStack)

nsThreadJSContextStack::nsThreadJSContextStack()
{
  /* member initializers and constructor code */
}

nsThreadJSContextStack::~nsThreadJSContextStack()
{
  /* destructor code */
}

/* [nostdcall,notxpcom] JSContext getSafeJSContext (); */
JSContext * nsThreadJSContextStack::GetSafeJSContext()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJSContextStack_h__ */
