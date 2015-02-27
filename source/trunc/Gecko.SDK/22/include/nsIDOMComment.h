/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIDOMComment.idl
 */

#ifndef __gen_nsIDOMComment_h__
#define __gen_nsIDOMComment_h__


#ifndef __gen_nsIDOMCharacterData_h__
#include "nsIDOMCharacterData.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMComment */
#define NS_IDOMCOMMENT_IID_STR "cf5493dc-ba25-423a-81e7-b417494f103a"

#define NS_IDOMCOMMENT_IID \
  {0xcf5493dc, 0xba25, 0x423a, \
    { 0x81, 0xe7, 0xb4, 0x17, 0x49, 0x4f, 0x10, 0x3a }}

class NS_NO_VTABLE nsIDOMComment : public nsIDOMCharacterData {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCOMMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMComment, NS_IDOMCOMMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCOMMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCOMMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCOMMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMComment : public nsIDOMComment
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCOMMENT

  nsDOMComment();

private:
  ~nsDOMComment();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMComment, nsIDOMComment)

nsDOMComment::nsDOMComment()
{
  /* member initializers and constructor code */
}

nsDOMComment::~nsDOMComment()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMComment_h__ */
