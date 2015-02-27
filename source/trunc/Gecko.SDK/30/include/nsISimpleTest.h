/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISimpleTest.idl
 */

#ifndef __gen_nsISimpleTest_h__
#define __gen_nsISimpleTest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISimpleTest */
#define NS_ISIMPLETEST_IID_STR "f2f71d91-0451-47ec-aaa0-166663a7711a"

#define NS_ISIMPLETEST_IID \
  {0xf2f71d91, 0x0451, 0x47ec, \
    { 0xaa, 0xa0, 0x16, 0x66, 0x63, 0xa7, 0x71, 0x1a }}

class NS_NO_VTABLE nsISimpleTest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIMPLETEST_IID)

  /* long add (in long a, in long b); */
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISimpleTest, NS_ISIMPLETEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIMPLETEST \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIMPLETEST(_to) \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) { return _to Add(a, b, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIMPLETEST(_to) \
  NS_IMETHOD Add(int32_t a, int32_t b, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(a, b, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSimpleTest : public nsISimpleTest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIMPLETEST

  nsSimpleTest();

private:
  ~nsSimpleTest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSimpleTest, nsISimpleTest)

nsSimpleTest::nsSimpleTest()
{
  /* member initializers and constructor code */
}

nsSimpleTest::~nsSimpleTest()
{
  /* destructor code */
}

/* long add (in long a, in long b); */
NS_IMETHODIMP nsSimpleTest::Add(int32_t a, int32_t b, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISimpleTest_h__ */
