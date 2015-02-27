/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/storage/nsIDOMStorageList.idl
 */

#ifndef __gen_nsIDOMStorageList_h__
#define __gen_nsIDOMStorageList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMStorageObsolete; /* forward declaration */


/* starting interface:    nsIDOMStorageList */
#define NS_IDOMSTORAGELIST_IID_STR "a4e9b257-5ccf-4b17-8721-23ac45c83128"

#define NS_IDOMSTORAGELIST_IID \
  {0xa4e9b257, 0x5ccf, 0x4b17, \
    { 0x87, 0x21, 0x23, 0xac, 0x45, 0xc8, 0x31, 0x28 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorageList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGELIST_IID)

  /**
   * Returns a storage object for a particular domain.
   *
   * @param domain domain to retrieve
   * @returns a storage area for the given domain
   */
  /* nsIDOMStorageObsolete namedItem (in DOMString domain); */
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & domain, nsIDOMStorageObsolete **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageList, NS_IDOMSTORAGELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGELIST \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & domain, nsIDOMStorageObsolete **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & domain, nsIDOMStorageObsolete **_retval NS_OUTPARAM) { return _to NamedItem(domain, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & domain, nsIDOMStorageObsolete **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(domain, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageList : public nsIDOMStorageList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGELIST

  nsDOMStorageList();

private:
  ~nsDOMStorageList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageList, nsIDOMStorageList)

nsDOMStorageList::nsDOMStorageList()
{
  /* member initializers and constructor code */
}

nsDOMStorageList::~nsDOMStorageList()
{
  /* destructor code */
}

/* nsIDOMStorageObsolete namedItem (in DOMString domain); */
NS_IMETHODIMP nsDOMStorageList::NamedItem(const nsAString & domain, nsIDOMStorageObsolete **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageList_h__ */
