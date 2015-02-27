/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIGamepadServiceTest.idl
 */

#ifndef __gen_nsIGamepadServiceTest_h__
#define __gen_nsIGamepadServiceTest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIGamepadServiceTest */
#define NS_IGAMEPADSERVICETEST_IID_STR "b6ed093c-6ea0-4141-a8eb-f99645162651"

#define NS_IGAMEPADSERVICETEST_IID \
  {0xb6ed093c, 0x6ea0, 0x4141, \
    { 0xa8, 0xeb, 0xf9, 0x96, 0x45, 0x16, 0x26, 0x51 }}

class NS_NO_VTABLE nsIGamepadServiceTest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGAMEPADSERVICETEST_IID)

  enum {
    NO_MAPPING = 0U,
    STANDARD_MAPPING = 1U
  };

  /* unsigned long addGamepad (in string id, in unsigned long mapping, in unsigned long numButtons, in unsigned long numAxes); */
  NS_IMETHOD AddGamepad(const char * id, uint32_t mapping, uint32_t numButtons, uint32_t numAxes, uint32_t *_retval) = 0;

  /* void removeGamepad (in unsigned long index); */
  NS_IMETHOD RemoveGamepad(uint32_t index) = 0;

  /* void newButtonEvent (in unsigned long index, in unsigned long button, in boolean pressed); */
  NS_IMETHOD NewButtonEvent(uint32_t index, uint32_t button, bool pressed) = 0;

  /* void newAxisMoveEvent (in unsigned long index, in unsigned long axis, in double value); */
  NS_IMETHOD NewAxisMoveEvent(uint32_t index, uint32_t axis, double value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGamepadServiceTest, NS_IGAMEPADSERVICETEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGAMEPADSERVICETEST \
  NS_IMETHOD AddGamepad(const char * id, uint32_t mapping, uint32_t numButtons, uint32_t numAxes, uint32_t *_retval); \
  NS_IMETHOD RemoveGamepad(uint32_t index); \
  NS_IMETHOD NewButtonEvent(uint32_t index, uint32_t button, bool pressed); \
  NS_IMETHOD NewAxisMoveEvent(uint32_t index, uint32_t axis, double value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGAMEPADSERVICETEST(_to) \
  NS_IMETHOD AddGamepad(const char * id, uint32_t mapping, uint32_t numButtons, uint32_t numAxes, uint32_t *_retval) { return _to AddGamepad(id, mapping, numButtons, numAxes, _retval); } \
  NS_IMETHOD RemoveGamepad(uint32_t index) { return _to RemoveGamepad(index); } \
  NS_IMETHOD NewButtonEvent(uint32_t index, uint32_t button, bool pressed) { return _to NewButtonEvent(index, button, pressed); } \
  NS_IMETHOD NewAxisMoveEvent(uint32_t index, uint32_t axis, double value) { return _to NewAxisMoveEvent(index, axis, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGAMEPADSERVICETEST(_to) \
  NS_IMETHOD AddGamepad(const char * id, uint32_t mapping, uint32_t numButtons, uint32_t numAxes, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddGamepad(id, mapping, numButtons, numAxes, _retval); } \
  NS_IMETHOD RemoveGamepad(uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveGamepad(index); } \
  NS_IMETHOD NewButtonEvent(uint32_t index, uint32_t button, bool pressed) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewButtonEvent(index, button, pressed); } \
  NS_IMETHOD NewAxisMoveEvent(uint32_t index, uint32_t axis, double value) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewAxisMoveEvent(index, axis, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGamepadServiceTest : public nsIGamepadServiceTest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGAMEPADSERVICETEST

  nsGamepadServiceTest();

private:
  ~nsGamepadServiceTest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGamepadServiceTest, nsIGamepadServiceTest)

nsGamepadServiceTest::nsGamepadServiceTest()
{
  /* member initializers and constructor code */
}

nsGamepadServiceTest::~nsGamepadServiceTest()
{
  /* destructor code */
}

/* unsigned long addGamepad (in string id, in unsigned long mapping, in unsigned long numButtons, in unsigned long numAxes); */
NS_IMETHODIMP nsGamepadServiceTest::AddGamepad(const char * id, uint32_t mapping, uint32_t numButtons, uint32_t numAxes, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeGamepad (in unsigned long index); */
NS_IMETHODIMP nsGamepadServiceTest::RemoveGamepad(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newButtonEvent (in unsigned long index, in unsigned long button, in boolean pressed); */
NS_IMETHODIMP nsGamepadServiceTest::NewButtonEvent(uint32_t index, uint32_t button, bool pressed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newAxisMoveEvent (in unsigned long index, in unsigned long axis, in double value); */
NS_IMETHODIMP nsGamepadServiceTest::NewAxisMoveEvent(uint32_t index, uint32_t axis, double value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGamepadServiceTest_h__ */
