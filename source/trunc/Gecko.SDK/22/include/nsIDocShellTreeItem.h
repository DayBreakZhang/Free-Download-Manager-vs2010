/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsIDocShellTreeItem.idl
 */

#ifndef __gen_nsIDocShellTreeItem_h__
#define __gen_nsIDocShellTreeItem_h__


#ifndef __gen_nsIDocShellTreeNode_h__
#include "nsIDocShellTreeNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShellTreeOwner; /* forward declaration */


/* starting interface:    nsIDocShellTreeItem */
#define NS_IDOCSHELLTREEITEM_IID_STR "e35bbb39-985b-4d62-81da-73c330222e5f"

#define NS_IDOCSHELLTREEITEM_IID \
  {0xe35bbb39, 0x985b, 0x4d62, \
    { 0x81, 0xda, 0x73, 0xc3, 0x30, 0x22, 0x2e, 0x5f }}

class NS_NO_VTABLE nsIDocShellTreeItem : public nsIDocShellTreeNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLTREEITEM_IID)

  /* attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* boolean nameEquals (in wstring name); */
  NS_IMETHOD NameEquals(const PRUnichar * name, bool *_retval) = 0;

  enum {
    typeChrome = 0,
    typeContent = 1,
    typeContentWrapper = 2,
    typeChromeWrapper = 3,
    typeAll = 2147483647
  };

  /* attribute long itemType; */
  NS_IMETHOD GetItemType(int32_t *aItemType) = 0;
  NS_IMETHOD SetItemType(int32_t aItemType) = 0;

  /* readonly attribute nsIDocShellTreeItem parent; */
  NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) = 0;

  /* readonly attribute nsIDocShellTreeItem sameTypeParent; */
  NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) = 0;

  /* readonly attribute nsIDocShellTreeItem rootTreeItem; */
  NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) = 0;

  /* readonly attribute nsIDocShellTreeItem sameTypeRootTreeItem; */
  NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) = 0;

  /* nsIDocShellTreeItem findItemWithName (in wstring name, in nsISupports aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_IMETHOD FindItemWithName(const PRUnichar * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) = 0;

  /* readonly attribute nsIDocShellTreeOwner treeOwner; */
  NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) = 0;

  /* [noscript] void setTreeOwner (in nsIDocShellTreeOwner treeOwner); */
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellTreeItem, NS_IDOCSHELLTREEITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLTREEITEM \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD NameEquals(const PRUnichar * name, bool *_retval); \
  NS_IMETHOD GetItemType(int32_t *aItemType); \
  NS_IMETHOD SetItemType(int32_t aItemType); \
  NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent); \
  NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent); \
  NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem); \
  NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem); \
  NS_IMETHOD FindItemWithName(const PRUnichar * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval); \
  NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner); \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLTREEITEM(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD NameEquals(const PRUnichar * name, bool *_retval) { return _to NameEquals(name, _retval); } \
  NS_IMETHOD GetItemType(int32_t *aItemType) { return _to GetItemType(aItemType); } \
  NS_IMETHOD SetItemType(int32_t aItemType) { return _to SetItemType(aItemType); } \
  NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) { return _to GetParent(aParent); } \
  NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) { return _to GetSameTypeParent(aSameTypeParent); } \
  NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) { return _to GetRootTreeItem(aRootTreeItem); } \
  NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) { return _to GetSameTypeRootTreeItem(aSameTypeRootTreeItem); } \
  NS_IMETHOD FindItemWithName(const PRUnichar * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) { return _to FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) { return _to GetTreeOwner(aTreeOwner); } \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) { return _to SetTreeOwner(treeOwner); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLTREEITEM(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD NameEquals(const PRUnichar * name, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NameEquals(name, _retval); } \
  NS_IMETHOD GetItemType(int32_t *aItemType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemType); } \
  NS_IMETHOD SetItemType(int32_t aItemType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemType(aItemType); } \
  NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSameTypeParent(aSameTypeParent); } \
  NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootTreeItem(aRootTreeItem); } \
  NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSameTypeRootTreeItem(aSameTypeRootTreeItem); } \
  NS_IMETHOD FindItemWithName(const PRUnichar * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTreeOwner(aTreeOwner); } \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTreeOwner(treeOwner); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellTreeItem : public nsIDocShellTreeItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLTREEITEM

  nsDocShellTreeItem();

private:
  ~nsDocShellTreeItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShellTreeItem, nsIDocShellTreeItem)

nsDocShellTreeItem::nsDocShellTreeItem()
{
  /* member initializers and constructor code */
}

nsDocShellTreeItem::~nsDocShellTreeItem()
{
  /* destructor code */
}

/* attribute AString name; */
NS_IMETHODIMP nsDocShellTreeItem::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellTreeItem::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean nameEquals (in wstring name); */
NS_IMETHODIMP nsDocShellTreeItem::NameEquals(const PRUnichar * name, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long itemType; */
NS_IMETHODIMP nsDocShellTreeItem::GetItemType(int32_t *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellTreeItem::SetItemType(int32_t aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem parent; */
NS_IMETHODIMP nsDocShellTreeItem::GetParent(nsIDocShellTreeItem * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem sameTypeParent; */
NS_IMETHODIMP nsDocShellTreeItem::GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem rootTreeItem; */
NS_IMETHODIMP nsDocShellTreeItem::GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem sameTypeRootTreeItem; */
NS_IMETHODIMP nsDocShellTreeItem::GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem findItemWithName (in wstring name, in nsISupports aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP nsDocShellTreeItem::FindItemWithName(const PRUnichar * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeOwner treeOwner; */
NS_IMETHODIMP nsDocShellTreeItem::GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setTreeOwner (in nsIDocShellTreeOwner treeOwner); */
NS_IMETHODIMP nsDocShellTreeItem::SetTreeOwner(nsIDocShellTreeOwner *treeOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellTreeItem_h__ */
