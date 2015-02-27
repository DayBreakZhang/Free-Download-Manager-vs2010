/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProgrammingLanguage.idl
 */

#ifndef __gen_nsIProgrammingLanguage_h__
#define __gen_nsIProgrammingLanguage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIProgrammingLanguage */
#define NS_IPROGRAMMINGLANGUAGE_IID_STR "ea604e90-40ba-11d5-90bb-0010a4e73d9a"

#define NS_IPROGRAMMINGLANGUAGE_IID \
  {0xea604e90, 0x40ba, 0x11d5, \
    { 0x90, 0xbb, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIProgrammingLanguage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROGRAMMINGLANGUAGE_IID)

  enum {
    UNKNOWN = 0U,
    CPLUSPLUS = 1U,
    JAVASCRIPT = 2U,
    PYTHON = 3U,
    PERL = 4U,
    JAVA = 5U,
    ZX81_BASIC = 6U,
    JAVASCRIPT2 = 7U,
    RUBY = 8U,
    PHP = 9U,
    TCL = 10U,
    MAX = 10U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProgrammingLanguage, NS_IPROGRAMMINGLANGUAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROGRAMMINGLANGUAGE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROGRAMMINGLANGUAGE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROGRAMMINGLANGUAGE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProgrammingLanguage : public nsIProgrammingLanguage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROGRAMMINGLANGUAGE

  nsProgrammingLanguage();

private:
  ~nsProgrammingLanguage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProgrammingLanguage, nsIProgrammingLanguage)

nsProgrammingLanguage::nsProgrammingLanguage()
{
  /* member initializers and constructor code */
}

nsProgrammingLanguage::~nsProgrammingLanguage()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProgrammingLanguage_h__ */
