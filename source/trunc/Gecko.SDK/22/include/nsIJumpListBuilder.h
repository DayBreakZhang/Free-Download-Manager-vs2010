/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIJumpListBuilder.idl
 */

#ifndef __gen_nsIJumpListBuilder_h__
#define __gen_nsIJumpListBuilder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIMutableArray; /* forward declaration */


/* starting interface:    nsIJumpListBuilder */
#define NS_IJUMPLISTBUILDER_IID_STR "1fe6a9cd-2b18-4dd5-a176-c2b32fa4f683"

#define NS_IJUMPLISTBUILDER_IID \
  {0x1fe6a9cd, 0x2b18, 0x4dd5, \
    { 0xa1, 0x76, 0xc2, 0xb3, 0x2f, 0xa4, 0xf6, 0x83 }}

class NS_NO_VTABLE nsIJumpListBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTBUILDER_IID)

  enum {
    JUMPLIST_CATEGORY_TASKS = 0,
    JUMPLIST_CATEGORY_RECENT = 1,
    JUMPLIST_CATEGORY_FREQUENT = 2,
    JUMPLIST_CATEGORY_CUSTOMLIST = 3
  };

  /* readonly attribute short available; */
  NS_IMETHOD GetAvailable(int16_t *aAvailable) = 0;

  /* readonly attribute boolean isListCommitted; */
  NS_IMETHOD GetIsListCommitted(bool *aIsListCommitted) = 0;

  /* readonly attribute short maxListItems; */
  NS_IMETHOD GetMaxListItems(int16_t *aMaxListItems) = 0;

  /* boolean initListBuild (in nsIMutableArray removedItems); */
  NS_IMETHOD InitListBuild(nsIMutableArray *removedItems, bool *_retval) = 0;

  /* boolean addListToBuild (in short aCatType, [optional] in nsIArray items, [optional] in AString catName); */
  NS_IMETHOD AddListToBuild(int16_t aCatType, nsIArray *items, const nsAString & catName, bool *_retval) = 0;

  /* void abortListBuild (); */
  NS_IMETHOD AbortListBuild(void) = 0;

  /* boolean commitListBuild (); */
  NS_IMETHOD CommitListBuild(bool *_retval) = 0;

  /* boolean deleteActiveList (); */
  NS_IMETHOD DeleteActiveList(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListBuilder, NS_IJUMPLISTBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTBUILDER \
  NS_IMETHOD GetAvailable(int16_t *aAvailable); \
  NS_IMETHOD GetIsListCommitted(bool *aIsListCommitted); \
  NS_IMETHOD GetMaxListItems(int16_t *aMaxListItems); \
  NS_IMETHOD InitListBuild(nsIMutableArray *removedItems, bool *_retval); \
  NS_IMETHOD AddListToBuild(int16_t aCatType, nsIArray *items, const nsAString & catName, bool *_retval); \
  NS_IMETHOD AbortListBuild(void); \
  NS_IMETHOD CommitListBuild(bool *_retval); \
  NS_IMETHOD DeleteActiveList(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTBUILDER(_to) \
  NS_IMETHOD GetAvailable(int16_t *aAvailable) { return _to GetAvailable(aAvailable); } \
  NS_IMETHOD GetIsListCommitted(bool *aIsListCommitted) { return _to GetIsListCommitted(aIsListCommitted); } \
  NS_IMETHOD GetMaxListItems(int16_t *aMaxListItems) { return _to GetMaxListItems(aMaxListItems); } \
  NS_IMETHOD InitListBuild(nsIMutableArray *removedItems, bool *_retval) { return _to InitListBuild(removedItems, _retval); } \
  NS_IMETHOD AddListToBuild(int16_t aCatType, nsIArray *items, const nsAString & catName, bool *_retval) { return _to AddListToBuild(aCatType, items, catName, _retval); } \
  NS_IMETHOD AbortListBuild(void) { return _to AbortListBuild(); } \
  NS_IMETHOD CommitListBuild(bool *_retval) { return _to CommitListBuild(_retval); } \
  NS_IMETHOD DeleteActiveList(bool *_retval) { return _to DeleteActiveList(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTBUILDER(_to) \
  NS_IMETHOD GetAvailable(int16_t *aAvailable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailable(aAvailable); } \
  NS_IMETHOD GetIsListCommitted(bool *aIsListCommitted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsListCommitted(aIsListCommitted); } \
  NS_IMETHOD GetMaxListItems(int16_t *aMaxListItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxListItems(aMaxListItems); } \
  NS_IMETHOD InitListBuild(nsIMutableArray *removedItems, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitListBuild(removedItems, _retval); } \
  NS_IMETHOD AddListToBuild(int16_t aCatType, nsIArray *items, const nsAString & catName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListToBuild(aCatType, items, catName, _retval); } \
  NS_IMETHOD AbortListBuild(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AbortListBuild(); } \
  NS_IMETHOD CommitListBuild(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CommitListBuild(_retval); } \
  NS_IMETHOD DeleteActiveList(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteActiveList(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJumpListBuilder : public nsIJumpListBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJUMPLISTBUILDER

  nsJumpListBuilder();

private:
  ~nsJumpListBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJumpListBuilder, nsIJumpListBuilder)

nsJumpListBuilder::nsJumpListBuilder()
{
  /* member initializers and constructor code */
}

nsJumpListBuilder::~nsJumpListBuilder()
{
  /* destructor code */
}

/* readonly attribute short available; */
NS_IMETHODIMP nsJumpListBuilder::GetAvailable(int16_t *aAvailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isListCommitted; */
NS_IMETHODIMP nsJumpListBuilder::GetIsListCommitted(bool *aIsListCommitted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short maxListItems; */
NS_IMETHODIMP nsJumpListBuilder::GetMaxListItems(int16_t *aMaxListItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean initListBuild (in nsIMutableArray removedItems); */
NS_IMETHODIMP nsJumpListBuilder::InitListBuild(nsIMutableArray *removedItems, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean addListToBuild (in short aCatType, [optional] in nsIArray items, [optional] in AString catName); */
NS_IMETHODIMP nsJumpListBuilder::AddListToBuild(int16_t aCatType, nsIArray *items, const nsAString & catName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abortListBuild (); */
NS_IMETHODIMP nsJumpListBuilder::AbortListBuild()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean commitListBuild (); */
NS_IMETHODIMP nsJumpListBuilder::CommitListBuild(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean deleteActiveList (); */
NS_IMETHODIMP nsJumpListBuilder::DeleteActiveList(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJumpListBuilder_h__ */
