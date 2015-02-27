/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsIDocCharset.idl
 */

#ifndef __gen_nsIDocCharset_h__
#define __gen_nsIDocCharset_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDocCharset */
#define NS_IDOCCHARSET_IID_STR "c3faaf6e-40f0-11e1-95fc-6c626d69675c"

#define NS_IDOCCHARSET_IID \
  {0xc3faaf6e, 0x40f0, 0x11e1, \
    { 0x95, 0xfc, 0x6c, 0x62, 0x6d, 0x69, 0x67, 0x5c }}

class NS_NO_VTABLE nsIDocCharset : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCCHARSET_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocCharset, NS_IDOCCHARSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCCHARSET \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCCHARSET(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCCHARSET(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocCharset : public nsIDocCharset
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCCHARSET

  nsDocCharset();

private:
  ~nsDocCharset();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocCharset, nsIDocCharset)

nsDocCharset::nsDocCharset()
{
  /* member initializers and constructor code */
}

nsDocCharset::~nsDocCharset()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocCharset_h__ */
