/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/xpcom/base/nsIDebug2.idl
 */

#ifndef __gen_nsIDebug2_h__
#define __gen_nsIDebug2_h__


#ifndef __gen_nsIDebug_h__
#include "nsIDebug.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDebug2 */
#define NS_IDEBUG2_IID_STR "9c9307ed-480a-4f2a-8f29-21378c03bcbc"

#define NS_IDEBUG2_IID \
  {0x9c9307ed, 0x480a, 0x4f2a, \
    { 0x8f, 0x29, 0x21, 0x37, 0x8c, 0x03, 0xbc, 0xbc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDebug2 : public nsIDebug {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDEBUG2_IID)

  /**
     * Whether XPCOM was compiled with DEBUG defined.  This often
     * correlates to whether other code (e.g., Firefox, XULRunner) was
     * compiled with DEBUG defined.
     */
  /* readonly attribute boolean isDebugBuild; */
  NS_SCRIPTABLE NS_IMETHOD GetIsDebugBuild(PRBool *aIsDebugBuild) = 0;

  /**
     * The number of assertions since process start.
     */
  /* readonly attribute long assertionCount; */
  NS_SCRIPTABLE NS_IMETHOD GetAssertionCount(PRInt32 *aAssertionCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDebug2, NS_IDEBUG2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDEBUG2 \
  NS_SCRIPTABLE NS_IMETHOD GetIsDebugBuild(PRBool *aIsDebugBuild); \
  NS_SCRIPTABLE NS_IMETHOD GetAssertionCount(PRInt32 *aAssertionCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDEBUG2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsDebugBuild(PRBool *aIsDebugBuild) { return _to GetIsDebugBuild(aIsDebugBuild); } \
  NS_SCRIPTABLE NS_IMETHOD GetAssertionCount(PRInt32 *aAssertionCount) { return _to GetAssertionCount(aAssertionCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDEBUG2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsDebugBuild(PRBool *aIsDebugBuild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDebugBuild(aIsDebugBuild); } \
  NS_SCRIPTABLE NS_IMETHOD GetAssertionCount(PRInt32 *aAssertionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAssertionCount(aAssertionCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDebug2 : public nsIDebug2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDEBUG2

  nsDebug2();

private:
  ~nsDebug2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDebug2, nsIDebug2)

nsDebug2::nsDebug2()
{
  /* member initializers and constructor code */
}

nsDebug2::~nsDebug2()
{
  /* destructor code */
}

/* readonly attribute boolean isDebugBuild; */
NS_IMETHODIMP nsDebug2::GetIsDebugBuild(PRBool *aIsDebugBuild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long assertionCount; */
NS_IMETHODIMP nsDebug2::GetAssertionCount(PRInt32 *aAssertionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDebug2_h__ */
