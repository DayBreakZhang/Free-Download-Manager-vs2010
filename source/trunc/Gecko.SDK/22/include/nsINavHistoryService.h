/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/places/nsINavHistoryService.idl
 */

#ifndef __gen_nsINavHistoryService_h__
#define __gen_nsINavHistoryService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIFile; /* forward declaration */

class nsINavHistoryContainerResultNode; /* forward declaration */

class nsINavHistoryQueryResultNode; /* forward declaration */

class nsINavHistoryQuery; /* forward declaration */

class nsINavHistoryQueryOptions; /* forward declaration */

class nsINavHistoryResult; /* forward declaration */

class nsINavHistoryBatchCallback; /* forward declaration */


/* starting interface:    nsINavHistoryResultNode */
#define NS_INAVHISTORYRESULTNODE_IID_STR "081452e5-be5c-4038-a5ea-f1f34cb6fd81"

#define NS_INAVHISTORYRESULTNODE_IID \
  {0x081452e5, 0xbe5c, 0x4038, \
    { 0xa5, 0xea, 0xf1, 0xf3, 0x4c, 0xb6, 0xfd, 0x81 }}

class NS_NO_VTABLE nsINavHistoryResultNode : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTNODE_IID)

  /* readonly attribute nsINavHistoryContainerResultNode parent; */
  NS_IMETHOD GetParent(nsINavHistoryContainerResultNode * *aParent) = 0;

  /* readonly attribute nsINavHistoryResult parentResult; */
  NS_IMETHOD GetParentResult(nsINavHistoryResult * *aParentResult) = 0;

  /* readonly attribute AUTF8String uri; */
  NS_IMETHOD GetUri(nsACString & aUri) = 0;

  enum {
    RESULT_TYPE_URI = 0U,
    RESULT_TYPE_QUERY = 5U,
    RESULT_TYPE_FOLDER = 6U,
    RESULT_TYPE_SEPARATOR = 7U,
    RESULT_TYPE_FOLDER_SHORTCUT = 9U
  };

  /* readonly attribute unsigned long type; */
  NS_IMETHOD GetType(uint32_t *aType) = 0;

  /* readonly attribute AUTF8String title; */
  NS_IMETHOD GetTitle(nsACString & aTitle) = 0;

  /* readonly attribute unsigned long accessCount; */
  NS_IMETHOD GetAccessCount(uint32_t *aAccessCount) = 0;

  /* readonly attribute PRTime time; */
  NS_IMETHOD GetTime(PRTime *aTime) = 0;

  /* readonly attribute AUTF8String icon; */
  NS_IMETHOD GetIcon(nsACString & aIcon) = 0;

  /* readonly attribute long indentLevel; */
  NS_IMETHOD GetIndentLevel(int32_t *aIndentLevel) = 0;

  /* readonly attribute long bookmarkIndex; */
  NS_IMETHOD GetBookmarkIndex(int32_t *aBookmarkIndex) = 0;

  /* readonly attribute long long itemId; */
  NS_IMETHOD GetItemId(int64_t *aItemId) = 0;

  /* readonly attribute PRTime dateAdded; */
  NS_IMETHOD GetDateAdded(PRTime *aDateAdded) = 0;

  /* readonly attribute PRTime lastModified; */
  NS_IMETHOD GetLastModified(PRTime *aLastModified) = 0;

  /* readonly attribute AString tags; */
  NS_IMETHOD GetTags(nsAString & aTags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultNode, NS_INAVHISTORYRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTNODE \
  NS_IMETHOD GetParent(nsINavHistoryContainerResultNode * *aParent); \
  NS_IMETHOD GetParentResult(nsINavHistoryResult * *aParentResult); \
  NS_IMETHOD GetUri(nsACString & aUri); \
  NS_IMETHOD GetType(uint32_t *aType); \
  NS_IMETHOD GetTitle(nsACString & aTitle); \
  NS_IMETHOD GetAccessCount(uint32_t *aAccessCount); \
  NS_IMETHOD GetTime(PRTime *aTime); \
  NS_IMETHOD GetIcon(nsACString & aIcon); \
  NS_IMETHOD GetIndentLevel(int32_t *aIndentLevel); \
  NS_IMETHOD GetBookmarkIndex(int32_t *aBookmarkIndex); \
  NS_IMETHOD GetItemId(int64_t *aItemId); \
  NS_IMETHOD GetDateAdded(PRTime *aDateAdded); \
  NS_IMETHOD GetLastModified(PRTime *aLastModified); \
  NS_IMETHOD GetTags(nsAString & aTags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTNODE(_to) \
  NS_IMETHOD GetParent(nsINavHistoryContainerResultNode * *aParent) { return _to GetParent(aParent); } \
  NS_IMETHOD GetParentResult(nsINavHistoryResult * *aParentResult) { return _to GetParentResult(aParentResult); } \
  NS_IMETHOD GetUri(nsACString & aUri) { return _to GetUri(aUri); } \
  NS_IMETHOD GetType(uint32_t *aType) { return _to GetType(aType); } \
  NS_IMETHOD GetTitle(nsACString & aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD GetAccessCount(uint32_t *aAccessCount) { return _to GetAccessCount(aAccessCount); } \
  NS_IMETHOD GetTime(PRTime *aTime) { return _to GetTime(aTime); } \
  NS_IMETHOD GetIcon(nsACString & aIcon) { return _to GetIcon(aIcon); } \
  NS_IMETHOD GetIndentLevel(int32_t *aIndentLevel) { return _to GetIndentLevel(aIndentLevel); } \
  NS_IMETHOD GetBookmarkIndex(int32_t *aBookmarkIndex) { return _to GetBookmarkIndex(aBookmarkIndex); } \
  NS_IMETHOD GetItemId(int64_t *aItemId) { return _to GetItemId(aItemId); } \
  NS_IMETHOD GetDateAdded(PRTime *aDateAdded) { return _to GetDateAdded(aDateAdded); } \
  NS_IMETHOD GetLastModified(PRTime *aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_IMETHOD GetTags(nsAString & aTags) { return _to GetTags(aTags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTNODE(_to) \
  NS_IMETHOD GetParent(nsINavHistoryContainerResultNode * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD GetParentResult(nsINavHistoryResult * *aParentResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentResult(aParentResult); } \
  NS_IMETHOD GetUri(nsACString & aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD GetType(uint32_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetTitle(nsACString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD GetAccessCount(uint32_t *aAccessCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessCount(aAccessCount); } \
  NS_IMETHOD GetTime(PRTime *aTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTime(aTime); } \
  NS_IMETHOD GetIcon(nsACString & aIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIcon(aIcon); } \
  NS_IMETHOD GetIndentLevel(int32_t *aIndentLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndentLevel(aIndentLevel); } \
  NS_IMETHOD GetBookmarkIndex(int32_t *aBookmarkIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkIndex(aBookmarkIndex); } \
  NS_IMETHOD GetItemId(int64_t *aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemId(aItemId); } \
  NS_IMETHOD GetDateAdded(PRTime *aDateAdded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDateAdded(aDateAdded); } \
  NS_IMETHOD GetLastModified(PRTime *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_IMETHOD GetTags(nsAString & aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTags(aTags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultNode : public nsINavHistoryResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTNODE

  nsNavHistoryResultNode();

private:
  ~nsNavHistoryResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryResultNode, nsINavHistoryResultNode)

nsNavHistoryResultNode::nsNavHistoryResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultNode::~nsNavHistoryResultNode()
{
  /* destructor code */
}

/* readonly attribute nsINavHistoryContainerResultNode parent; */
NS_IMETHODIMP nsNavHistoryResultNode::GetParent(nsINavHistoryContainerResultNode * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryResult parentResult; */
NS_IMETHODIMP nsNavHistoryResultNode::GetParentResult(nsINavHistoryResult * *aParentResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String uri; */
NS_IMETHODIMP nsNavHistoryResultNode::GetUri(nsACString & aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long type; */
NS_IMETHODIMP nsNavHistoryResultNode::GetType(uint32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String title; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTitle(nsACString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long accessCount; */
NS_IMETHODIMP nsNavHistoryResultNode::GetAccessCount(uint32_t *aAccessCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime time; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTime(PRTime *aTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String icon; */
NS_IMETHODIMP nsNavHistoryResultNode::GetIcon(nsACString & aIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long indentLevel; */
NS_IMETHODIMP nsNavHistoryResultNode::GetIndentLevel(int32_t *aIndentLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long bookmarkIndex; */
NS_IMETHODIMP nsNavHistoryResultNode::GetBookmarkIndex(int32_t *aBookmarkIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long itemId; */
NS_IMETHODIMP nsNavHistoryResultNode::GetItemId(int64_t *aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime dateAdded; */
NS_IMETHODIMP nsNavHistoryResultNode::GetDateAdded(PRTime *aDateAdded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModified; */
NS_IMETHODIMP nsNavHistoryResultNode::GetLastModified(PRTime *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString tags; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTags(nsAString & aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryContainerResultNode */
#define NS_INAVHISTORYCONTAINERRESULTNODE_IID_STR "62534d3c-1b3f-401e-b3ba-b911f57f8a29"

#define NS_INAVHISTORYCONTAINERRESULTNODE_IID \
  {0x62534d3c, 0x1b3f, 0x401e, \
    { 0xb3, 0xba, 0xb9, 0x11, 0xf5, 0x7f, 0x8a, 0x29 }}

class NS_NO_VTABLE nsINavHistoryContainerResultNode : public nsINavHistoryResultNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYCONTAINERRESULTNODE_IID)

  /* attribute boolean containerOpen; */
  NS_IMETHOD GetContainerOpen(bool *aContainerOpen) = 0;
  NS_IMETHOD SetContainerOpen(bool aContainerOpen) = 0;

  /* readonly attribute unsigned short state; */
  NS_IMETHOD GetState(uint16_t *aState) = 0;

  enum {
    STATE_CLOSED = 0U,
    STATE_LOADING = 1U,
    STATE_OPENED = 2U
  };

  /* readonly attribute boolean hasChildren; */
  NS_IMETHOD GetHasChildren(bool *aHasChildren) = 0;

  /* readonly attribute unsigned long childCount; */
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) = 0;

  /* nsINavHistoryResultNode getChild (in unsigned long aIndex); */
  NS_IMETHOD GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval) = 0;

  /* unsigned long getChildIndex (in nsINavHistoryResultNode aNode); */
  NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval) = 0;

  /* nsINavHistoryResultNode findNodeByDetails (in AUTF8String aURIString, in PRTime aTime, in long long aItemId, in boolean aRecursive); */
  NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval) = 0;

  /* readonly attribute boolean childrenReadOnly; */
  NS_IMETHOD GetChildrenReadOnly(bool *aChildrenReadOnly) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryContainerResultNode, NS_INAVHISTORYCONTAINERRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYCONTAINERRESULTNODE \
  NS_IMETHOD GetContainerOpen(bool *aContainerOpen); \
  NS_IMETHOD SetContainerOpen(bool aContainerOpen); \
  NS_IMETHOD GetState(uint16_t *aState); \
  NS_IMETHOD GetHasChildren(bool *aHasChildren); \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount); \
  NS_IMETHOD GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval); \
  NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval); \
  NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval); \
  NS_IMETHOD GetChildrenReadOnly(bool *aChildrenReadOnly); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYCONTAINERRESULTNODE(_to) \
  NS_IMETHOD GetContainerOpen(bool *aContainerOpen) { return _to GetContainerOpen(aContainerOpen); } \
  NS_IMETHOD SetContainerOpen(bool aContainerOpen) { return _to SetContainerOpen(aContainerOpen); } \
  NS_IMETHOD GetState(uint16_t *aState) { return _to GetState(aState); } \
  NS_IMETHOD GetHasChildren(bool *aHasChildren) { return _to GetHasChildren(aHasChildren); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_IMETHOD GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval) { return _to GetChild(aIndex, _retval); } \
  NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval) { return _to GetChildIndex(aNode, _retval); } \
  NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval) { return _to FindNodeByDetails(aURIString, aTime, aItemId, aRecursive, _retval); } \
  NS_IMETHOD GetChildrenReadOnly(bool *aChildrenReadOnly) { return _to GetChildrenReadOnly(aChildrenReadOnly); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYCONTAINERRESULTNODE(_to) \
  NS_IMETHOD GetContainerOpen(bool *aContainerOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainerOpen(aContainerOpen); } \
  NS_IMETHOD SetContainerOpen(bool aContainerOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainerOpen(aContainerOpen); } \
  NS_IMETHOD GetState(uint16_t *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD GetHasChildren(bool *aHasChildren) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasChildren(aHasChildren); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_IMETHOD GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChild(aIndex, _retval); } \
  NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildIndex(aNode, _retval); } \
  NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindNodeByDetails(aURIString, aTime, aItemId, aRecursive, _retval); } \
  NS_IMETHOD GetChildrenReadOnly(bool *aChildrenReadOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildrenReadOnly(aChildrenReadOnly); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryContainerResultNode : public nsINavHistoryContainerResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYCONTAINERRESULTNODE

  nsNavHistoryContainerResultNode();

private:
  ~nsNavHistoryContainerResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryContainerResultNode, nsINavHistoryContainerResultNode)

nsNavHistoryContainerResultNode::nsNavHistoryContainerResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryContainerResultNode::~nsNavHistoryContainerResultNode()
{
  /* destructor code */
}

/* attribute boolean containerOpen; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetContainerOpen(bool *aContainerOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryContainerResultNode::SetContainerOpen(bool aContainerOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short state; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetState(uint16_t *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasChildren; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetHasChildren(bool *aHasChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childCount; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChildCount(uint32_t *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResultNode getChild (in unsigned long aIndex); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getChildIndex (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResultNode findNodeByDetails (in AUTF8String aURIString, in PRTime aTime, in long long aItemId, in boolean aRecursive); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean childrenReadOnly; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChildrenReadOnly(bool *aChildrenReadOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQueryResultNode */
#define NS_INAVHISTORYQUERYRESULTNODE_IID_STR "ea17745a-1852-4155-a98f-d1dd1763b3df"

#define NS_INAVHISTORYQUERYRESULTNODE_IID \
  {0xea17745a, 0x1852, 0x4155, \
    { 0xa9, 0x8f, 0xd1, 0xdd, 0x17, 0x63, 0xb3, 0xdf }}

class NS_NO_VTABLE nsINavHistoryQueryResultNode : public nsINavHistoryContainerResultNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERYRESULTNODE_IID)

  /* void getQueries ([optional] out unsigned long queryCount, [array, size_is (queryCount), retval] out nsINavHistoryQuery queries); */
  NS_IMETHOD GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries) = 0;

  /* readonly attribute nsINavHistoryQueryOptions queryOptions; */
  NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions) = 0;

  /* readonly attribute long long folderItemId; */
  NS_IMETHOD GetFolderItemId(int64_t *aFolderItemId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQueryResultNode, NS_INAVHISTORYQUERYRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERYRESULTNODE \
  NS_IMETHOD GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries); \
  NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions); \
  NS_IMETHOD GetFolderItemId(int64_t *aFolderItemId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERYRESULTNODE(_to) \
  NS_IMETHOD GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries) { return _to GetQueries(queryCount, queries); } \
  NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions) { return _to GetQueryOptions(aQueryOptions); } \
  NS_IMETHOD GetFolderItemId(int64_t *aFolderItemId) { return _to GetFolderItemId(aFolderItemId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERYRESULTNODE(_to) \
  NS_IMETHOD GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueries(queryCount, queries); } \
  NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryOptions(aQueryOptions); } \
  NS_IMETHOD GetFolderItemId(int64_t *aFolderItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderItemId(aFolderItemId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQueryResultNode : public nsINavHistoryQueryResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERYRESULTNODE

  nsNavHistoryQueryResultNode();

private:
  ~nsNavHistoryQueryResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryQueryResultNode, nsINavHistoryQueryResultNode)

nsNavHistoryQueryResultNode::nsNavHistoryQueryResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryQueryResultNode::~nsNavHistoryQueryResultNode()
{
  /* destructor code */
}

/* void getQueries ([optional] out unsigned long queryCount, [array, size_is (queryCount), retval] out nsINavHistoryQuery queries); */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryQueryOptions queryOptions; */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long folderItemId; */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetFolderItemId(int64_t *aFolderItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResultObserver */
#define NS_INAVHISTORYRESULTOBSERVER_IID_STR "f62d8b6b-3c4e-4a9f-a897-db605d0b7a0f"

#define NS_INAVHISTORYRESULTOBSERVER_IID \
  {0xf62d8b6b, 0x3c4e, 0x4a9f, \
    { 0xa8, 0x97, 0xdb, 0x60, 0x5d, 0x0b, 0x7a, 0x0f }}

class NS_NO_VTABLE nsINavHistoryResultObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTOBSERVER_IID)

  /* void nodeInserted (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aNode, in unsigned long aNewIndex); */
  NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex) = 0;

  /* void nodeRemoved (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aItem, in unsigned long aOldIndex); */
  NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex) = 0;

  /* void nodeMoved (in nsINavHistoryResultNode aNode, in nsINavHistoryContainerResultNode aOldParent, in unsigned long aOldIndex, in nsINavHistoryContainerResultNode aNewParent, in unsigned long aNewIndex); */
  NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex) = 0;

  /* void nodeTitleChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewTitle); */
  NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) = 0;

  /* void nodeURIChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewURI); */
  NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) = 0;

  /* void nodeIconChanged (in nsINavHistoryResultNode aNode); */
  NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) = 0;

  /* void nodeHistoryDetailsChanged (in nsINavHistoryResultNode aNode, in PRTime aNewVisitDate, in unsigned long aNewAccessCount); */
  NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount) = 0;

  /* void nodeTagsChanged (in nsINavHistoryResultNode aNode); */
  NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) = 0;

  /* void nodeKeywordChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewKeyword); */
  NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) = 0;

  /* void nodeAnnotationChanged (in nsINavHistoryResultNode aNode, in AUTF8String aAnnoName); */
  NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) = 0;

  /* void nodeDateAddedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
  NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) = 0;

  /* void nodeLastModifiedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
  NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) = 0;

  /* void containerStateChanged (in nsINavHistoryContainerResultNode aContainerNode, in unsigned long aOldState, in unsigned long aNewState); */
  NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState) = 0;

  /* void invalidateContainer (in nsINavHistoryContainerResultNode aContainerNode); */
  NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) = 0;

  /* void sortingChanged (in unsigned short sortingMode); */
  NS_IMETHOD SortingChanged(uint16_t sortingMode) = 0;

  /* void batching (in boolean aToggleMode); */
  NS_IMETHOD Batching(bool aToggleMode) = 0;

  /* attribute nsINavHistoryResult result; */
  NS_IMETHOD GetResult(nsINavHistoryResult * *aResult) = 0;
  NS_IMETHOD SetResult(nsINavHistoryResult *aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultObserver, NS_INAVHISTORYRESULTOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTOBSERVER \
  NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex); \
  NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex); \
  NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex); \
  NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle); \
  NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI); \
  NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode); \
  NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount); \
  NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode); \
  NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword); \
  NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName); \
  NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue); \
  NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue); \
  NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState); \
  NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode); \
  NS_IMETHOD SortingChanged(uint16_t sortingMode); \
  NS_IMETHOD Batching(bool aToggleMode); \
  NS_IMETHOD GetResult(nsINavHistoryResult * *aResult); \
  NS_IMETHOD SetResult(nsINavHistoryResult *aResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTOBSERVER(_to) \
  NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex) { return _to NodeInserted(aParent, aNode, aNewIndex); } \
  NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex) { return _to NodeRemoved(aParent, aItem, aOldIndex); } \
  NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex) { return _to NodeMoved(aNode, aOldParent, aOldIndex, aNewParent, aNewIndex); } \
  NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) { return _to NodeTitleChanged(aNode, aNewTitle); } \
  NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) { return _to NodeURIChanged(aNode, aNewURI); } \
  NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) { return _to NodeIconChanged(aNode); } \
  NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount) { return _to NodeHistoryDetailsChanged(aNode, aNewVisitDate, aNewAccessCount); } \
  NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) { return _to NodeTagsChanged(aNode); } \
  NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) { return _to NodeKeywordChanged(aNode, aNewKeyword); } \
  NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) { return _to NodeAnnotationChanged(aNode, aAnnoName); } \
  NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) { return _to NodeDateAddedChanged(aNode, aNewValue); } \
  NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) { return _to NodeLastModifiedChanged(aNode, aNewValue); } \
  NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState) { return _to ContainerStateChanged(aContainerNode, aOldState, aNewState); } \
  NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) { return _to InvalidateContainer(aContainerNode); } \
  NS_IMETHOD SortingChanged(uint16_t sortingMode) { return _to SortingChanged(sortingMode); } \
  NS_IMETHOD Batching(bool aToggleMode) { return _to Batching(aToggleMode); } \
  NS_IMETHOD GetResult(nsINavHistoryResult * *aResult) { return _to GetResult(aResult); } \
  NS_IMETHOD SetResult(nsINavHistoryResult *aResult) { return _to SetResult(aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTOBSERVER(_to) \
  NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeInserted(aParent, aNode, aNewIndex); } \
  NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeRemoved(aParent, aItem, aOldIndex); } \
  NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeMoved(aNode, aOldParent, aOldIndex, aNewParent, aNewIndex); } \
  NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeTitleChanged(aNode, aNewTitle); } \
  NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeURIChanged(aNode, aNewURI); } \
  NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeIconChanged(aNode); } \
  NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeHistoryDetailsChanged(aNode, aNewVisitDate, aNewAccessCount); } \
  NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeTagsChanged(aNode); } \
  NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeKeywordChanged(aNode, aNewKeyword); } \
  NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeAnnotationChanged(aNode, aAnnoName); } \
  NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeDateAddedChanged(aNode, aNewValue); } \
  NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeLastModifiedChanged(aNode, aNewValue); } \
  NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainerStateChanged(aContainerNode, aOldState, aNewState); } \
  NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateContainer(aContainerNode); } \
  NS_IMETHOD SortingChanged(uint16_t sortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SortingChanged(sortingMode); } \
  NS_IMETHOD Batching(bool aToggleMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Batching(aToggleMode); } \
  NS_IMETHOD GetResult(nsINavHistoryResult * *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD SetResult(nsINavHistoryResult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResult(aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultObserver : public nsINavHistoryResultObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTOBSERVER

  nsNavHistoryResultObserver();

private:
  ~nsNavHistoryResultObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryResultObserver, nsINavHistoryResultObserver)

nsNavHistoryResultObserver::nsNavHistoryResultObserver()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultObserver::~nsNavHistoryResultObserver()
{
  /* destructor code */
}

/* void nodeInserted (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aNode, in unsigned long aNewIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeRemoved (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aItem, in unsigned long aOldIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeMoved (in nsINavHistoryResultNode aNode, in nsINavHistoryContainerResultNode aOldParent, in unsigned long aOldIndex, in nsINavHistoryContainerResultNode aNewParent, in unsigned long aNewIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeTitleChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewTitle); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeURIChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewURI); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeIconChanged (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeIconChanged(nsINavHistoryResultNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeHistoryDetailsChanged (in nsINavHistoryResultNode aNode, in PRTime aNewVisitDate, in unsigned long aNewAccessCount); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeTagsChanged (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeTagsChanged(nsINavHistoryResultNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeKeywordChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewKeyword); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeAnnotationChanged (in nsINavHistoryResultNode aNode, in AUTF8String aAnnoName); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeDateAddedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeLastModifiedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void containerStateChanged (in nsINavHistoryContainerResultNode aContainerNode, in unsigned long aOldState, in unsigned long aNewState); */
NS_IMETHODIMP nsNavHistoryResultObserver::ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateContainer (in nsINavHistoryContainerResultNode aContainerNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sortingChanged (in unsigned short sortingMode); */
NS_IMETHODIMP nsNavHistoryResultObserver::SortingChanged(uint16_t sortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void batching (in boolean aToggleMode); */
NS_IMETHODIMP nsNavHistoryResultObserver::Batching(bool aToggleMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsINavHistoryResult result; */
NS_IMETHODIMP nsNavHistoryResultObserver::GetResult(nsINavHistoryResult * *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResultObserver::SetResult(nsINavHistoryResult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResultTreeViewer */
#define NS_INAVHISTORYRESULTTREEVIEWER_IID_STR "f8b518c0-1faf-11df-8a39-0800200c9a66"

#define NS_INAVHISTORYRESULTTREEVIEWER_IID \
  {0xf8b518c0, 0x1faf, 0x11df, \
    { 0x8a, 0x39, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsINavHistoryResultTreeViewer : public nsINavHistoryResultObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTTREEVIEWER_IID)

  /* nsINavHistoryResultNode nodeForTreeIndex (in unsigned long aIndex); */
  NS_IMETHOD NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval) = 0;

  enum {
    INDEX_INVISIBLE = 4294967295U
  };

  /* unsigned long treeIndexForNode (in nsINavHistoryResultNode aNode); */
  NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultTreeViewer, NS_INAVHISTORYRESULTTREEVIEWER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTTREEVIEWER \
  NS_IMETHOD NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval); \
  NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTTREEVIEWER(_to) \
  NS_IMETHOD NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval) { return _to NodeForTreeIndex(aIndex, _retval); } \
  NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval) { return _to TreeIndexForNode(aNode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTTREEVIEWER(_to) \
  NS_IMETHOD NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeForTreeIndex(aIndex, _retval); } \
  NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TreeIndexForNode(aNode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultTreeViewer : public nsINavHistoryResultTreeViewer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTTREEVIEWER

  nsNavHistoryResultTreeViewer();

private:
  ~nsNavHistoryResultTreeViewer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryResultTreeViewer, nsINavHistoryResultTreeViewer)

nsNavHistoryResultTreeViewer::nsNavHistoryResultTreeViewer()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultTreeViewer::~nsNavHistoryResultTreeViewer()
{
  /* destructor code */
}

/* nsINavHistoryResultNode nodeForTreeIndex (in unsigned long aIndex); */
NS_IMETHODIMP nsNavHistoryResultTreeViewer::NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long treeIndexForNode (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultTreeViewer::TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResult */
#define NS_INAVHISTORYRESULT_IID_STR "c2229ce3-2159-4001-859c-7013c52f7619"

#define NS_INAVHISTORYRESULT_IID \
  {0xc2229ce3, 0x2159, 0x4001, \
    { 0x85, 0x9c, 0x70, 0x13, 0xc5, 0x2f, 0x76, 0x19 }}

class NS_NO_VTABLE nsINavHistoryResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULT_IID)

  /* attribute unsigned short sortingMode; */
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) = 0;
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) = 0;

  /* attribute AUTF8String sortingAnnotation; */
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) = 0;
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) = 0;

  /* attribute boolean suppressNotifications; */
  NS_IMETHOD GetSuppressNotifications(bool *aSuppressNotifications) = 0;
  NS_IMETHOD SetSuppressNotifications(bool aSuppressNotifications) = 0;

  /* void addObserver (in nsINavHistoryResultObserver aObserver, in boolean aOwnsWeak); */
  NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak) = 0;

  /* void removeObserver (in nsINavHistoryResultObserver aObserver); */
  NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) = 0;

  /* readonly attribute nsINavHistoryContainerResultNode root; */
  NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode * *aRoot) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResult, NS_INAVHISTORYRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULT \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode); \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode); \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation); \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation); \
  NS_IMETHOD GetSuppressNotifications(bool *aSuppressNotifications); \
  NS_IMETHOD SetSuppressNotifications(bool aSuppressNotifications); \
  NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak); \
  NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver); \
  NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode * *aRoot); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULT(_to) \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) { return _to GetSortingMode(aSortingMode); } \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) { return _to SetSortingMode(aSortingMode); } \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) { return _to GetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) { return _to SetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD GetSuppressNotifications(bool *aSuppressNotifications) { return _to GetSuppressNotifications(aSuppressNotifications); } \
  NS_IMETHOD SetSuppressNotifications(bool aSuppressNotifications) { return _to SetSuppressNotifications(aSuppressNotifications); } \
  NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak) { return _to AddObserver(aObserver, aOwnsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode * *aRoot) { return _to GetRoot(aRoot); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULT(_to) \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingMode(aSortingMode); } \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingMode(aSortingMode); } \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD GetSuppressNotifications(bool *aSuppressNotifications) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuppressNotifications(aSuppressNotifications); } \
  NS_IMETHOD SetSuppressNotifications(bool aSuppressNotifications) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSuppressNotifications(aSuppressNotifications); } \
  NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver, aOwnsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode * *aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResult : public nsINavHistoryResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULT

  nsNavHistoryResult();

private:
  ~nsNavHistoryResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryResult, nsINavHistoryResult)

nsNavHistoryResult::nsNavHistoryResult()
{
  /* member initializers and constructor code */
}

nsNavHistoryResult::~nsNavHistoryResult()
{
  /* destructor code */
}

/* attribute unsigned short sortingMode; */
NS_IMETHODIMP nsNavHistoryResult::GetSortingMode(uint16_t *aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSortingMode(uint16_t aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String sortingAnnotation; */
NS_IMETHODIMP nsNavHistoryResult::GetSortingAnnotation(nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSortingAnnotation(const nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean suppressNotifications; */
NS_IMETHODIMP nsNavHistoryResult::GetSuppressNotifications(bool *aSuppressNotifications)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSuppressNotifications(bool aSuppressNotifications)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsINavHistoryResultObserver aObserver, in boolean aOwnsWeak); */
NS_IMETHODIMP nsNavHistoryResult::AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsINavHistoryResultObserver aObserver); */
NS_IMETHODIMP nsNavHistoryResult::RemoveObserver(nsINavHistoryResultObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryContainerResultNode root; */
NS_IMETHODIMP nsNavHistoryResult::GetRoot(nsINavHistoryContainerResultNode * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryObserver */
#define NS_INAVHISTORYOBSERVER_IID_STR "45e2970b-9b00-4473-9938-39d6beaf4248"

#define NS_INAVHISTORYOBSERVER_IID \
  {0x45e2970b, 0x9b00, 0x4473, \
    { 0x99, 0x38, 0x39, 0xd6, 0xbe, 0xaf, 0x42, 0x48 }}

class NS_NO_VTABLE nsINavHistoryObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYOBSERVER_IID)

  /* void onBeginUpdateBatch (); */
  NS_IMETHOD OnBeginUpdateBatch(void) = 0;

  /* void onEndUpdateBatch (); */
  NS_IMETHOD OnEndUpdateBatch(void) = 0;

  /* void onVisit (in nsIURI aURI, in long long aVisitID, in PRTime aTime, in long long aSessionID, in long long aReferringID, in unsigned long aTransitionType, in ACString aGUID, in boolean aHidden); */
  NS_IMETHOD OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden) = 0;

  /* void onTitleChanged (in nsIURI aURI, in AString aPageTitle, in ACString aGUID); */
  NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID) = 0;

  enum {
    REASON_DELETED = 0U,
    REASON_EXPIRED = 1U
  };

  /* void onDeleteURI (in nsIURI aURI, in ACString aGUID, in unsigned short aReason); */
  NS_IMETHOD OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason) = 0;

  /* void onClearHistory (); */
  NS_IMETHOD OnClearHistory(void) = 0;

  enum {
    ATTRIBUTE_FAVICON = 3U
  };

  /* void onPageChanged (in nsIURI aURI, in unsigned long aChangedAttribute, in AString aNewValue, in ACString aGUID); */
  NS_IMETHOD OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID) = 0;

  /* void onDeleteVisits (in nsIURI aURI, in PRTime aVisitTime, in ACString aGUID, in unsigned short aReason, in unsigned long aTransitionType); */
  NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryObserver, NS_INAVHISTORYOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYOBSERVER \
  NS_IMETHOD OnBeginUpdateBatch(void); \
  NS_IMETHOD OnEndUpdateBatch(void); \
  NS_IMETHOD OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden); \
  NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID); \
  NS_IMETHOD OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason); \
  NS_IMETHOD OnClearHistory(void); \
  NS_IMETHOD OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID); \
  NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYOBSERVER(_to) \
  NS_IMETHOD OnBeginUpdateBatch(void) { return _to OnBeginUpdateBatch(); } \
  NS_IMETHOD OnEndUpdateBatch(void) { return _to OnEndUpdateBatch(); } \
  NS_IMETHOD OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden) { return _to OnVisit(aURI, aVisitID, aTime, aSessionID, aReferringID, aTransitionType, aGUID, aHidden); } \
  NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID) { return _to OnTitleChanged(aURI, aPageTitle, aGUID); } \
  NS_IMETHOD OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason) { return _to OnDeleteURI(aURI, aGUID, aReason); } \
  NS_IMETHOD OnClearHistory(void) { return _to OnClearHistory(); } \
  NS_IMETHOD OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID) { return _to OnPageChanged(aURI, aChangedAttribute, aNewValue, aGUID); } \
  NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) { return _to OnDeleteVisits(aURI, aVisitTime, aGUID, aReason, aTransitionType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYOBSERVER(_to) \
  NS_IMETHOD OnBeginUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeginUpdateBatch(); } \
  NS_IMETHOD OnEndUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndUpdateBatch(); } \
  NS_IMETHOD OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnVisit(aURI, aVisitID, aTime, aSessionID, aReferringID, aTransitionType, aGUID, aHidden); } \
  NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTitleChanged(aURI, aPageTitle, aGUID); } \
  NS_IMETHOD OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDeleteURI(aURI, aGUID, aReason); } \
  NS_IMETHOD OnClearHistory(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClearHistory(); } \
  NS_IMETHOD OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPageChanged(aURI, aChangedAttribute, aNewValue, aGUID); } \
  NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDeleteVisits(aURI, aVisitTime, aGUID, aReason, aTransitionType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryObserver : public nsINavHistoryObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYOBSERVER

  nsNavHistoryObserver();

private:
  ~nsNavHistoryObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryObserver, nsINavHistoryObserver)

nsNavHistoryObserver::nsNavHistoryObserver()
{
  /* member initializers and constructor code */
}

nsNavHistoryObserver::~nsNavHistoryObserver()
{
  /* destructor code */
}

/* void onBeginUpdateBatch (); */
NS_IMETHODIMP nsNavHistoryObserver::OnBeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndUpdateBatch (); */
NS_IMETHODIMP nsNavHistoryObserver::OnEndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onVisit (in nsIURI aURI, in long long aVisitID, in PRTime aTime, in long long aSessionID, in long long aReferringID, in unsigned long aTransitionType, in ACString aGUID, in boolean aHidden); */
NS_IMETHODIMP nsNavHistoryObserver::OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onTitleChanged (in nsIURI aURI, in AString aPageTitle, in ACString aGUID); */
NS_IMETHODIMP nsNavHistoryObserver::OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDeleteURI (in nsIURI aURI, in ACString aGUID, in unsigned short aReason); */
NS_IMETHODIMP nsNavHistoryObserver::OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onClearHistory (); */
NS_IMETHODIMP nsNavHistoryObserver::OnClearHistory()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPageChanged (in nsIURI aURI, in unsigned long aChangedAttribute, in AString aNewValue, in ACString aGUID); */
NS_IMETHODIMP nsNavHistoryObserver::OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDeleteVisits (in nsIURI aURI, in PRTime aVisitTime, in ACString aGUID, in unsigned short aReason, in unsigned long aTransitionType); */
NS_IMETHODIMP nsNavHistoryObserver::OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQuery */
#define NS_INAVHISTORYQUERY_IID_STR "dc87ae79-22f1-4dcf-975b-852b01d210cb"

#define NS_INAVHISTORYQUERY_IID \
  {0xdc87ae79, 0x22f1, 0x4dcf, \
    { 0x97, 0x5b, 0x85, 0x2b, 0x01, 0xd2, 0x10, 0xcb }}

class NS_NO_VTABLE nsINavHistoryQuery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERY_IID)

  enum {
    TIME_RELATIVE_EPOCH = 0U,
    TIME_RELATIVE_TODAY = 1U,
    TIME_RELATIVE_NOW = 2U
  };

  /* attribute PRTime beginTime; */
  NS_IMETHOD GetBeginTime(PRTime *aBeginTime) = 0;
  NS_IMETHOD SetBeginTime(PRTime aBeginTime) = 0;

  /* attribute unsigned long beginTimeReference; */
  NS_IMETHOD GetBeginTimeReference(uint32_t *aBeginTimeReference) = 0;
  NS_IMETHOD SetBeginTimeReference(uint32_t aBeginTimeReference) = 0;

  /* readonly attribute boolean hasBeginTime; */
  NS_IMETHOD GetHasBeginTime(bool *aHasBeginTime) = 0;

  /* readonly attribute PRTime absoluteBeginTime; */
  NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) = 0;

  /* attribute PRTime endTime; */
  NS_IMETHOD GetEndTime(PRTime *aEndTime) = 0;
  NS_IMETHOD SetEndTime(PRTime aEndTime) = 0;

  /* attribute unsigned long endTimeReference; */
  NS_IMETHOD GetEndTimeReference(uint32_t *aEndTimeReference) = 0;
  NS_IMETHOD SetEndTimeReference(uint32_t aEndTimeReference) = 0;

  /* readonly attribute boolean hasEndTime; */
  NS_IMETHOD GetHasEndTime(bool *aHasEndTime) = 0;

  /* readonly attribute PRTime absoluteEndTime; */
  NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) = 0;

  /* attribute AString searchTerms; */
  NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) = 0;
  NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) = 0;

  /* readonly attribute boolean hasSearchTerms; */
  NS_IMETHOD GetHasSearchTerms(bool *aHasSearchTerms) = 0;

  /* attribute long minVisits; */
  NS_IMETHOD GetMinVisits(int32_t *aMinVisits) = 0;
  NS_IMETHOD SetMinVisits(int32_t aMinVisits) = 0;

  /* attribute long maxVisits; */
  NS_IMETHOD GetMaxVisits(int32_t *aMaxVisits) = 0;
  NS_IMETHOD SetMaxVisits(int32_t aMaxVisits) = 0;

  /* void setTransitions ([array, size_is (count), const] in unsigned long transitions, in unsigned long count); */
  NS_IMETHOD SetTransitions(const uint32_t *transitions, uint32_t count) = 0;

  /* void getTransitions ([optional] out unsigned long count, [array, size_is (count), retval] out unsigned long transitions); */
  NS_IMETHOD GetTransitions(uint32_t *count, uint32_t **transitions) = 0;

  /* readonly attribute unsigned long transitionCount; */
  NS_IMETHOD GetTransitionCount(uint32_t *aTransitionCount) = 0;

  /* attribute boolean onlyBookmarked; */
  NS_IMETHOD GetOnlyBookmarked(bool *aOnlyBookmarked) = 0;
  NS_IMETHOD SetOnlyBookmarked(bool aOnlyBookmarked) = 0;

  /* attribute boolean domainIsHost; */
  NS_IMETHOD GetDomainIsHost(bool *aDomainIsHost) = 0;
  NS_IMETHOD SetDomainIsHost(bool aDomainIsHost) = 0;

  /* attribute AUTF8String domain; */
  NS_IMETHOD GetDomain(nsACString & aDomain) = 0;
  NS_IMETHOD SetDomain(const nsACString & aDomain) = 0;

  /* readonly attribute boolean hasDomain; */
  NS_IMETHOD GetHasDomain(bool *aHasDomain) = 0;

  /* attribute boolean uriIsPrefix; */
  NS_IMETHOD GetUriIsPrefix(bool *aUriIsPrefix) = 0;
  NS_IMETHOD SetUriIsPrefix(bool aUriIsPrefix) = 0;

  /* attribute nsIURI uri; */
  NS_IMETHOD GetUri(nsIURI * *aUri) = 0;
  NS_IMETHOD SetUri(nsIURI *aUri) = 0;

  /* readonly attribute boolean hasUri; */
  NS_IMETHOD GetHasUri(bool *aHasUri) = 0;

  /* attribute boolean annotationIsNot; */
  NS_IMETHOD GetAnnotationIsNot(bool *aAnnotationIsNot) = 0;
  NS_IMETHOD SetAnnotationIsNot(bool aAnnotationIsNot) = 0;

  /* attribute AUTF8String annotation; */
  NS_IMETHOD GetAnnotation(nsACString & aAnnotation) = 0;
  NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) = 0;

  /* readonly attribute boolean hasAnnotation; */
  NS_IMETHOD GetHasAnnotation(bool *aHasAnnotation) = 0;

  /* attribute nsIVariant tags; */
  NS_IMETHOD GetTags(nsIVariant * *aTags) = 0;
  NS_IMETHOD SetTags(nsIVariant *aTags) = 0;

  /* attribute boolean tagsAreNot; */
  NS_IMETHOD GetTagsAreNot(bool *aTagsAreNot) = 0;
  NS_IMETHOD SetTagsAreNot(bool aTagsAreNot) = 0;

  /* void getFolders ([optional] out unsigned long count, [array, size_is (count), retval] out long long folders); */
  NS_IMETHOD GetFolders(uint32_t *count, int64_t **folders) = 0;

  /* readonly attribute unsigned long folderCount; */
  NS_IMETHOD GetFolderCount(uint32_t *aFolderCount) = 0;

  /* void setFolders ([array, size_is (folderCount), const] in long long folders, in unsigned long folderCount); */
  NS_IMETHOD SetFolders(const int64_t *folders, uint32_t folderCount) = 0;

  /* nsINavHistoryQuery clone (); */
  NS_IMETHOD Clone(nsINavHistoryQuery * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQuery, NS_INAVHISTORYQUERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERY \
  NS_IMETHOD GetBeginTime(PRTime *aBeginTime); \
  NS_IMETHOD SetBeginTime(PRTime aBeginTime); \
  NS_IMETHOD GetBeginTimeReference(uint32_t *aBeginTimeReference); \
  NS_IMETHOD SetBeginTimeReference(uint32_t aBeginTimeReference); \
  NS_IMETHOD GetHasBeginTime(bool *aHasBeginTime); \
  NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime); \
  NS_IMETHOD GetEndTime(PRTime *aEndTime); \
  NS_IMETHOD SetEndTime(PRTime aEndTime); \
  NS_IMETHOD GetEndTimeReference(uint32_t *aEndTimeReference); \
  NS_IMETHOD SetEndTimeReference(uint32_t aEndTimeReference); \
  NS_IMETHOD GetHasEndTime(bool *aHasEndTime); \
  NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime); \
  NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms); \
  NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms); \
  NS_IMETHOD GetHasSearchTerms(bool *aHasSearchTerms); \
  NS_IMETHOD GetMinVisits(int32_t *aMinVisits); \
  NS_IMETHOD SetMinVisits(int32_t aMinVisits); \
  NS_IMETHOD GetMaxVisits(int32_t *aMaxVisits); \
  NS_IMETHOD SetMaxVisits(int32_t aMaxVisits); \
  NS_IMETHOD SetTransitions(const uint32_t *transitions, uint32_t count); \
  NS_IMETHOD GetTransitions(uint32_t *count, uint32_t **transitions); \
  NS_IMETHOD GetTransitionCount(uint32_t *aTransitionCount); \
  NS_IMETHOD GetOnlyBookmarked(bool *aOnlyBookmarked); \
  NS_IMETHOD SetOnlyBookmarked(bool aOnlyBookmarked); \
  NS_IMETHOD GetDomainIsHost(bool *aDomainIsHost); \
  NS_IMETHOD SetDomainIsHost(bool aDomainIsHost); \
  NS_IMETHOD GetDomain(nsACString & aDomain); \
  NS_IMETHOD SetDomain(const nsACString & aDomain); \
  NS_IMETHOD GetHasDomain(bool *aHasDomain); \
  NS_IMETHOD GetUriIsPrefix(bool *aUriIsPrefix); \
  NS_IMETHOD SetUriIsPrefix(bool aUriIsPrefix); \
  NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_IMETHOD SetUri(nsIURI *aUri); \
  NS_IMETHOD GetHasUri(bool *aHasUri); \
  NS_IMETHOD GetAnnotationIsNot(bool *aAnnotationIsNot); \
  NS_IMETHOD SetAnnotationIsNot(bool aAnnotationIsNot); \
  NS_IMETHOD GetAnnotation(nsACString & aAnnotation); \
  NS_IMETHOD SetAnnotation(const nsACString & aAnnotation); \
  NS_IMETHOD GetHasAnnotation(bool *aHasAnnotation); \
  NS_IMETHOD GetTags(nsIVariant * *aTags); \
  NS_IMETHOD SetTags(nsIVariant *aTags); \
  NS_IMETHOD GetTagsAreNot(bool *aTagsAreNot); \
  NS_IMETHOD SetTagsAreNot(bool aTagsAreNot); \
  NS_IMETHOD GetFolders(uint32_t *count, int64_t **folders); \
  NS_IMETHOD GetFolderCount(uint32_t *aFolderCount); \
  NS_IMETHOD SetFolders(const int64_t *folders, uint32_t folderCount); \
  NS_IMETHOD Clone(nsINavHistoryQuery * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERY(_to) \
  NS_IMETHOD GetBeginTime(PRTime *aBeginTime) { return _to GetBeginTime(aBeginTime); } \
  NS_IMETHOD SetBeginTime(PRTime aBeginTime) { return _to SetBeginTime(aBeginTime); } \
  NS_IMETHOD GetBeginTimeReference(uint32_t *aBeginTimeReference) { return _to GetBeginTimeReference(aBeginTimeReference); } \
  NS_IMETHOD SetBeginTimeReference(uint32_t aBeginTimeReference) { return _to SetBeginTimeReference(aBeginTimeReference); } \
  NS_IMETHOD GetHasBeginTime(bool *aHasBeginTime) { return _to GetHasBeginTime(aHasBeginTime); } \
  NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) { return _to GetAbsoluteBeginTime(aAbsoluteBeginTime); } \
  NS_IMETHOD GetEndTime(PRTime *aEndTime) { return _to GetEndTime(aEndTime); } \
  NS_IMETHOD SetEndTime(PRTime aEndTime) { return _to SetEndTime(aEndTime); } \
  NS_IMETHOD GetEndTimeReference(uint32_t *aEndTimeReference) { return _to GetEndTimeReference(aEndTimeReference); } \
  NS_IMETHOD SetEndTimeReference(uint32_t aEndTimeReference) { return _to SetEndTimeReference(aEndTimeReference); } \
  NS_IMETHOD GetHasEndTime(bool *aHasEndTime) { return _to GetHasEndTime(aHasEndTime); } \
  NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) { return _to GetAbsoluteEndTime(aAbsoluteEndTime); } \
  NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) { return _to GetSearchTerms(aSearchTerms); } \
  NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) { return _to SetSearchTerms(aSearchTerms); } \
  NS_IMETHOD GetHasSearchTerms(bool *aHasSearchTerms) { return _to GetHasSearchTerms(aHasSearchTerms); } \
  NS_IMETHOD GetMinVisits(int32_t *aMinVisits) { return _to GetMinVisits(aMinVisits); } \
  NS_IMETHOD SetMinVisits(int32_t aMinVisits) { return _to SetMinVisits(aMinVisits); } \
  NS_IMETHOD GetMaxVisits(int32_t *aMaxVisits) { return _to GetMaxVisits(aMaxVisits); } \
  NS_IMETHOD SetMaxVisits(int32_t aMaxVisits) { return _to SetMaxVisits(aMaxVisits); } \
  NS_IMETHOD SetTransitions(const uint32_t *transitions, uint32_t count) { return _to SetTransitions(transitions, count); } \
  NS_IMETHOD GetTransitions(uint32_t *count, uint32_t **transitions) { return _to GetTransitions(count, transitions); } \
  NS_IMETHOD GetTransitionCount(uint32_t *aTransitionCount) { return _to GetTransitionCount(aTransitionCount); } \
  NS_IMETHOD GetOnlyBookmarked(bool *aOnlyBookmarked) { return _to GetOnlyBookmarked(aOnlyBookmarked); } \
  NS_IMETHOD SetOnlyBookmarked(bool aOnlyBookmarked) { return _to SetOnlyBookmarked(aOnlyBookmarked); } \
  NS_IMETHOD GetDomainIsHost(bool *aDomainIsHost) { return _to GetDomainIsHost(aDomainIsHost); } \
  NS_IMETHOD SetDomainIsHost(bool aDomainIsHost) { return _to SetDomainIsHost(aDomainIsHost); } \
  NS_IMETHOD GetDomain(nsACString & aDomain) { return _to GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsACString & aDomain) { return _to SetDomain(aDomain); } \
  NS_IMETHOD GetHasDomain(bool *aHasDomain) { return _to GetHasDomain(aHasDomain); } \
  NS_IMETHOD GetUriIsPrefix(bool *aUriIsPrefix) { return _to GetUriIsPrefix(aUriIsPrefix); } \
  NS_IMETHOD SetUriIsPrefix(bool aUriIsPrefix) { return _to SetUriIsPrefix(aUriIsPrefix); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) { return _to SetUri(aUri); } \
  NS_IMETHOD GetHasUri(bool *aHasUri) { return _to GetHasUri(aHasUri); } \
  NS_IMETHOD GetAnnotationIsNot(bool *aAnnotationIsNot) { return _to GetAnnotationIsNot(aAnnotationIsNot); } \
  NS_IMETHOD SetAnnotationIsNot(bool aAnnotationIsNot) { return _to SetAnnotationIsNot(aAnnotationIsNot); } \
  NS_IMETHOD GetAnnotation(nsACString & aAnnotation) { return _to GetAnnotation(aAnnotation); } \
  NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) { return _to SetAnnotation(aAnnotation); } \
  NS_IMETHOD GetHasAnnotation(bool *aHasAnnotation) { return _to GetHasAnnotation(aHasAnnotation); } \
  NS_IMETHOD GetTags(nsIVariant * *aTags) { return _to GetTags(aTags); } \
  NS_IMETHOD SetTags(nsIVariant *aTags) { return _to SetTags(aTags); } \
  NS_IMETHOD GetTagsAreNot(bool *aTagsAreNot) { return _to GetTagsAreNot(aTagsAreNot); } \
  NS_IMETHOD SetTagsAreNot(bool aTagsAreNot) { return _to SetTagsAreNot(aTagsAreNot); } \
  NS_IMETHOD GetFolders(uint32_t *count, int64_t **folders) { return _to GetFolders(count, folders); } \
  NS_IMETHOD GetFolderCount(uint32_t *aFolderCount) { return _to GetFolderCount(aFolderCount); } \
  NS_IMETHOD SetFolders(const int64_t *folders, uint32_t folderCount) { return _to SetFolders(folders, folderCount); } \
  NS_IMETHOD Clone(nsINavHistoryQuery * *_retval) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERY(_to) \
  NS_IMETHOD GetBeginTime(PRTime *aBeginTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeginTime(aBeginTime); } \
  NS_IMETHOD SetBeginTime(PRTime aBeginTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBeginTime(aBeginTime); } \
  NS_IMETHOD GetBeginTimeReference(uint32_t *aBeginTimeReference) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeginTimeReference(aBeginTimeReference); } \
  NS_IMETHOD SetBeginTimeReference(uint32_t aBeginTimeReference) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBeginTimeReference(aBeginTimeReference); } \
  NS_IMETHOD GetHasBeginTime(bool *aHasBeginTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasBeginTime(aHasBeginTime); } \
  NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsoluteBeginTime(aAbsoluteBeginTime); } \
  NS_IMETHOD GetEndTime(PRTime *aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndTime(aEndTime); } \
  NS_IMETHOD SetEndTime(PRTime aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndTime(aEndTime); } \
  NS_IMETHOD GetEndTimeReference(uint32_t *aEndTimeReference) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndTimeReference(aEndTimeReference); } \
  NS_IMETHOD SetEndTimeReference(uint32_t aEndTimeReference) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndTimeReference(aEndTimeReference); } \
  NS_IMETHOD GetHasEndTime(bool *aHasEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasEndTime(aHasEndTime); } \
  NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsoluteEndTime(aAbsoluteEndTime); } \
  NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchTerms(aSearchTerms); } \
  NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchTerms(aSearchTerms); } \
  NS_IMETHOD GetHasSearchTerms(bool *aHasSearchTerms) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasSearchTerms(aHasSearchTerms); } \
  NS_IMETHOD GetMinVisits(int32_t *aMinVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinVisits(aMinVisits); } \
  NS_IMETHOD SetMinVisits(int32_t aMinVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinVisits(aMinVisits); } \
  NS_IMETHOD GetMaxVisits(int32_t *aMaxVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxVisits(aMaxVisits); } \
  NS_IMETHOD SetMaxVisits(int32_t aMaxVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxVisits(aMaxVisits); } \
  NS_IMETHOD SetTransitions(const uint32_t *transitions, uint32_t count) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransitions(transitions, count); } \
  NS_IMETHOD GetTransitions(uint32_t *count, uint32_t **transitions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitions(count, transitions); } \
  NS_IMETHOD GetTransitionCount(uint32_t *aTransitionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitionCount(aTransitionCount); } \
  NS_IMETHOD GetOnlyBookmarked(bool *aOnlyBookmarked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnlyBookmarked(aOnlyBookmarked); } \
  NS_IMETHOD SetOnlyBookmarked(bool aOnlyBookmarked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnlyBookmarked(aOnlyBookmarked); } \
  NS_IMETHOD GetDomainIsHost(bool *aDomainIsHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainIsHost(aDomainIsHost); } \
  NS_IMETHOD SetDomainIsHost(bool aDomainIsHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomainIsHost(aDomainIsHost); } \
  NS_IMETHOD GetDomain(nsACString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsACString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } \
  NS_IMETHOD GetHasDomain(bool *aHasDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasDomain(aHasDomain); } \
  NS_IMETHOD GetUriIsPrefix(bool *aUriIsPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUriIsPrefix(aUriIsPrefix); } \
  NS_IMETHOD SetUriIsPrefix(bool aUriIsPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUriIsPrefix(aUriIsPrefix); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } \
  NS_IMETHOD GetHasUri(bool *aHasUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasUri(aHasUri); } \
  NS_IMETHOD GetAnnotationIsNot(bool *aAnnotationIsNot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotationIsNot(aAnnotationIsNot); } \
  NS_IMETHOD SetAnnotationIsNot(bool aAnnotationIsNot) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnnotationIsNot(aAnnotationIsNot); } \
  NS_IMETHOD GetAnnotation(nsACString & aAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotation(aAnnotation); } \
  NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnnotation(aAnnotation); } \
  NS_IMETHOD GetHasAnnotation(bool *aHasAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasAnnotation(aHasAnnotation); } \
  NS_IMETHOD GetTags(nsIVariant * *aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTags(aTags); } \
  NS_IMETHOD SetTags(nsIVariant *aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTags(aTags); } \
  NS_IMETHOD GetTagsAreNot(bool *aTagsAreNot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagsAreNot(aTagsAreNot); } \
  NS_IMETHOD SetTagsAreNot(bool aTagsAreNot) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTagsAreNot(aTagsAreNot); } \
  NS_IMETHOD GetFolders(uint32_t *count, int64_t **folders) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolders(count, folders); } \
  NS_IMETHOD GetFolderCount(uint32_t *aFolderCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderCount(aFolderCount); } \
  NS_IMETHOD SetFolders(const int64_t *folders, uint32_t folderCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFolders(folders, folderCount); } \
  NS_IMETHOD Clone(nsINavHistoryQuery * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQuery : public nsINavHistoryQuery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERY

  nsNavHistoryQuery();

private:
  ~nsNavHistoryQuery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryQuery, nsINavHistoryQuery)

nsNavHistoryQuery::nsNavHistoryQuery()
{
  /* member initializers and constructor code */
}

nsNavHistoryQuery::~nsNavHistoryQuery()
{
  /* destructor code */
}

/* attribute PRTime beginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetBeginTime(PRTime *aBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetBeginTime(PRTime aBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long beginTimeReference; */
NS_IMETHODIMP nsNavHistoryQuery::GetBeginTimeReference(uint32_t *aBeginTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetBeginTimeReference(uint32_t aBeginTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasBeginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasBeginTime(bool *aHasBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime absoluteBeginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRTime endTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetEndTime(PRTime *aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetEndTime(PRTime aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long endTimeReference; */
NS_IMETHODIMP nsNavHistoryQuery::GetEndTimeReference(uint32_t *aEndTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetEndTimeReference(uint32_t aEndTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasEndTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasEndTime(bool *aHasEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime absoluteEndTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetAbsoluteEndTime(PRTime *aAbsoluteEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString searchTerms; */
NS_IMETHODIMP nsNavHistoryQuery::GetSearchTerms(nsAString & aSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetSearchTerms(const nsAString & aSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasSearchTerms; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasSearchTerms(bool *aHasSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long minVisits; */
NS_IMETHODIMP nsNavHistoryQuery::GetMinVisits(int32_t *aMinVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetMinVisits(int32_t aMinVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxVisits; */
NS_IMETHODIMP nsNavHistoryQuery::GetMaxVisits(int32_t *aMaxVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetMaxVisits(int32_t aMaxVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTransitions ([array, size_is (count), const] in unsigned long transitions, in unsigned long count); */
NS_IMETHODIMP nsNavHistoryQuery::SetTransitions(const uint32_t *transitions, uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTransitions ([optional] out unsigned long count, [array, size_is (count), retval] out unsigned long transitions); */
NS_IMETHODIMP nsNavHistoryQuery::GetTransitions(uint32_t *count, uint32_t **transitions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long transitionCount; */
NS_IMETHODIMP nsNavHistoryQuery::GetTransitionCount(uint32_t *aTransitionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean onlyBookmarked; */
NS_IMETHODIMP nsNavHistoryQuery::GetOnlyBookmarked(bool *aOnlyBookmarked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetOnlyBookmarked(bool aOnlyBookmarked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean domainIsHost; */
NS_IMETHODIMP nsNavHistoryQuery::GetDomainIsHost(bool *aDomainIsHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetDomainIsHost(bool aDomainIsHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String domain; */
NS_IMETHODIMP nsNavHistoryQuery::GetDomain(nsACString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetDomain(const nsACString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasDomain; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasDomain(bool *aHasDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean uriIsPrefix; */
NS_IMETHODIMP nsNavHistoryQuery::GetUriIsPrefix(bool *aUriIsPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetUriIsPrefix(bool aUriIsPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI uri; */
NS_IMETHODIMP nsNavHistoryQuery::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetUri(nsIURI *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasUri; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasUri(bool *aHasUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean annotationIsNot; */
NS_IMETHODIMP nsNavHistoryQuery::GetAnnotationIsNot(bool *aAnnotationIsNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetAnnotationIsNot(bool aAnnotationIsNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String annotation; */
NS_IMETHODIMP nsNavHistoryQuery::GetAnnotation(nsACString & aAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetAnnotation(const nsACString & aAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasAnnotation; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasAnnotation(bool *aHasAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant tags; */
NS_IMETHODIMP nsNavHistoryQuery::GetTags(nsIVariant * *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetTags(nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean tagsAreNot; */
NS_IMETHODIMP nsNavHistoryQuery::GetTagsAreNot(bool *aTagsAreNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetTagsAreNot(bool aTagsAreNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getFolders ([optional] out unsigned long count, [array, size_is (count), retval] out long long folders); */
NS_IMETHODIMP nsNavHistoryQuery::GetFolders(uint32_t *count, int64_t **folders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long folderCount; */
NS_IMETHODIMP nsNavHistoryQuery::GetFolderCount(uint32_t *aFolderCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFolders ([array, size_is (folderCount), const] in long long folders, in unsigned long folderCount); */
NS_IMETHODIMP nsNavHistoryQuery::SetFolders(const int64_t *folders, uint32_t folderCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQuery clone (); */
NS_IMETHODIMP nsNavHistoryQuery::Clone(nsINavHistoryQuery * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQueryOptions */
#define NS_INAVHISTORYQUERYOPTIONS_IID_STR "8198dfa7-8061-4766-95cb-fa86b3c00a47"

#define NS_INAVHISTORYQUERYOPTIONS_IID \
  {0x8198dfa7, 0x8061, 0x4766, \
    { 0x95, 0xcb, 0xfa, 0x86, 0xb3, 0xc0, 0x0a, 0x47 }}

class NS_NO_VTABLE nsINavHistoryQueryOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERYOPTIONS_IID)

  enum {
    SORT_BY_NONE = 0U,
    SORT_BY_TITLE_ASCENDING = 1U,
    SORT_BY_TITLE_DESCENDING = 2U,
    SORT_BY_DATE_ASCENDING = 3U,
    SORT_BY_DATE_DESCENDING = 4U,
    SORT_BY_URI_ASCENDING = 5U,
    SORT_BY_URI_DESCENDING = 6U,
    SORT_BY_VISITCOUNT_ASCENDING = 7U,
    SORT_BY_VISITCOUNT_DESCENDING = 8U,
    SORT_BY_KEYWORD_ASCENDING = 9U,
    SORT_BY_KEYWORD_DESCENDING = 10U,
    SORT_BY_DATEADDED_ASCENDING = 11U,
    SORT_BY_DATEADDED_DESCENDING = 12U,
    SORT_BY_LASTMODIFIED_ASCENDING = 13U,
    SORT_BY_LASTMODIFIED_DESCENDING = 14U,
    SORT_BY_TAGS_ASCENDING = 17U,
    SORT_BY_TAGS_DESCENDING = 18U,
    SORT_BY_ANNOTATION_ASCENDING = 19U,
    SORT_BY_ANNOTATION_DESCENDING = 20U,
    SORT_BY_FRECENCY_ASCENDING = 21U,
    SORT_BY_FRECENCY_DESCENDING = 22U,
    RESULTS_AS_URI = 0U,
    RESULTS_AS_VISIT = 1U,
    RESULTS_AS_FULL_VISIT = 2U,
    RESULTS_AS_DATE_QUERY = 3U,
    RESULTS_AS_SITE_QUERY = 4U,
    RESULTS_AS_DATE_SITE_QUERY = 5U,
    RESULTS_AS_TAG_QUERY = 6U,
    RESULTS_AS_TAG_CONTENTS = 7U
  };

  /* attribute unsigned short sortingMode; */
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) = 0;
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) = 0;

  /* attribute AUTF8String sortingAnnotation; */
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) = 0;
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) = 0;

  /* attribute unsigned short resultType; */
  NS_IMETHOD GetResultType(uint16_t *aResultType) = 0;
  NS_IMETHOD SetResultType(uint16_t aResultType) = 0;

  /* attribute boolean excludeItems; */
  NS_IMETHOD GetExcludeItems(bool *aExcludeItems) = 0;
  NS_IMETHOD SetExcludeItems(bool aExcludeItems) = 0;

  /* attribute boolean excludeQueries; */
  NS_IMETHOD GetExcludeQueries(bool *aExcludeQueries) = 0;
  NS_IMETHOD SetExcludeQueries(bool aExcludeQueries) = 0;

  /* attribute boolean excludeReadOnlyFolders; */
  NS_IMETHOD GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders) = 0;
  NS_IMETHOD SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders) = 0;

  /* attribute boolean expandQueries; */
  NS_IMETHOD GetExpandQueries(bool *aExpandQueries) = 0;
  NS_IMETHOD SetExpandQueries(bool aExpandQueries) = 0;

  /* attribute boolean includeHidden; */
  NS_IMETHOD GetIncludeHidden(bool *aIncludeHidden) = 0;
  NS_IMETHOD SetIncludeHidden(bool aIncludeHidden) = 0;

  /* attribute unsigned long maxResults; */
  NS_IMETHOD GetMaxResults(uint32_t *aMaxResults) = 0;
  NS_IMETHOD SetMaxResults(uint32_t aMaxResults) = 0;

  enum {
    QUERY_TYPE_HISTORY = 0U,
    QUERY_TYPE_BOOKMARKS = 1U,
    QUERY_TYPE_UNIFIED = 2U
  };

  /* attribute unsigned short queryType; */
  NS_IMETHOD GetQueryType(uint16_t *aQueryType) = 0;
  NS_IMETHOD SetQueryType(uint16_t aQueryType) = 0;

  /* attribute boolean asyncEnabled; */
  NS_IMETHOD GetAsyncEnabled(bool *aAsyncEnabled) = 0;
  NS_IMETHOD SetAsyncEnabled(bool aAsyncEnabled) = 0;

  /* nsINavHistoryQueryOptions clone (); */
  NS_IMETHOD Clone(nsINavHistoryQueryOptions * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQueryOptions, NS_INAVHISTORYQUERYOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERYOPTIONS \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode); \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode); \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation); \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation); \
  NS_IMETHOD GetResultType(uint16_t *aResultType); \
  NS_IMETHOD SetResultType(uint16_t aResultType); \
  NS_IMETHOD GetExcludeItems(bool *aExcludeItems); \
  NS_IMETHOD SetExcludeItems(bool aExcludeItems); \
  NS_IMETHOD GetExcludeQueries(bool *aExcludeQueries); \
  NS_IMETHOD SetExcludeQueries(bool aExcludeQueries); \
  NS_IMETHOD GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders); \
  NS_IMETHOD SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders); \
  NS_IMETHOD GetExpandQueries(bool *aExpandQueries); \
  NS_IMETHOD SetExpandQueries(bool aExpandQueries); \
  NS_IMETHOD GetIncludeHidden(bool *aIncludeHidden); \
  NS_IMETHOD SetIncludeHidden(bool aIncludeHidden); \
  NS_IMETHOD GetMaxResults(uint32_t *aMaxResults); \
  NS_IMETHOD SetMaxResults(uint32_t aMaxResults); \
  NS_IMETHOD GetQueryType(uint16_t *aQueryType); \
  NS_IMETHOD SetQueryType(uint16_t aQueryType); \
  NS_IMETHOD GetAsyncEnabled(bool *aAsyncEnabled); \
  NS_IMETHOD SetAsyncEnabled(bool aAsyncEnabled); \
  NS_IMETHOD Clone(nsINavHistoryQueryOptions * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERYOPTIONS(_to) \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) { return _to GetSortingMode(aSortingMode); } \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) { return _to SetSortingMode(aSortingMode); } \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) { return _to GetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) { return _to SetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD GetResultType(uint16_t *aResultType) { return _to GetResultType(aResultType); } \
  NS_IMETHOD SetResultType(uint16_t aResultType) { return _to SetResultType(aResultType); } \
  NS_IMETHOD GetExcludeItems(bool *aExcludeItems) { return _to GetExcludeItems(aExcludeItems); } \
  NS_IMETHOD SetExcludeItems(bool aExcludeItems) { return _to SetExcludeItems(aExcludeItems); } \
  NS_IMETHOD GetExcludeQueries(bool *aExcludeQueries) { return _to GetExcludeQueries(aExcludeQueries); } \
  NS_IMETHOD SetExcludeQueries(bool aExcludeQueries) { return _to SetExcludeQueries(aExcludeQueries); } \
  NS_IMETHOD GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders) { return _to GetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_IMETHOD SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders) { return _to SetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_IMETHOD GetExpandQueries(bool *aExpandQueries) { return _to GetExpandQueries(aExpandQueries); } \
  NS_IMETHOD SetExpandQueries(bool aExpandQueries) { return _to SetExpandQueries(aExpandQueries); } \
  NS_IMETHOD GetIncludeHidden(bool *aIncludeHidden) { return _to GetIncludeHidden(aIncludeHidden); } \
  NS_IMETHOD SetIncludeHidden(bool aIncludeHidden) { return _to SetIncludeHidden(aIncludeHidden); } \
  NS_IMETHOD GetMaxResults(uint32_t *aMaxResults) { return _to GetMaxResults(aMaxResults); } \
  NS_IMETHOD SetMaxResults(uint32_t aMaxResults) { return _to SetMaxResults(aMaxResults); } \
  NS_IMETHOD GetQueryType(uint16_t *aQueryType) { return _to GetQueryType(aQueryType); } \
  NS_IMETHOD SetQueryType(uint16_t aQueryType) { return _to SetQueryType(aQueryType); } \
  NS_IMETHOD GetAsyncEnabled(bool *aAsyncEnabled) { return _to GetAsyncEnabled(aAsyncEnabled); } \
  NS_IMETHOD SetAsyncEnabled(bool aAsyncEnabled) { return _to SetAsyncEnabled(aAsyncEnabled); } \
  NS_IMETHOD Clone(nsINavHistoryQueryOptions * *_retval) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERYOPTIONS(_to) \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingMode(aSortingMode); } \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingMode(aSortingMode); } \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD GetResultType(uint16_t *aResultType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultType(aResultType); } \
  NS_IMETHOD SetResultType(uint16_t aResultType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResultType(aResultType); } \
  NS_IMETHOD GetExcludeItems(bool *aExcludeItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeItems(aExcludeItems); } \
  NS_IMETHOD SetExcludeItems(bool aExcludeItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeItems(aExcludeItems); } \
  NS_IMETHOD GetExcludeQueries(bool *aExcludeQueries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeQueries(aExcludeQueries); } \
  NS_IMETHOD SetExcludeQueries(bool aExcludeQueries) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeQueries(aExcludeQueries); } \
  NS_IMETHOD GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_IMETHOD SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_IMETHOD GetExpandQueries(bool *aExpandQueries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpandQueries(aExpandQueries); } \
  NS_IMETHOD SetExpandQueries(bool aExpandQueries) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExpandQueries(aExpandQueries); } \
  NS_IMETHOD GetIncludeHidden(bool *aIncludeHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIncludeHidden(aIncludeHidden); } \
  NS_IMETHOD SetIncludeHidden(bool aIncludeHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIncludeHidden(aIncludeHidden); } \
  NS_IMETHOD GetMaxResults(uint32_t *aMaxResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxResults(aMaxResults); } \
  NS_IMETHOD SetMaxResults(uint32_t aMaxResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxResults(aMaxResults); } \
  NS_IMETHOD GetQueryType(uint16_t *aQueryType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryType(aQueryType); } \
  NS_IMETHOD SetQueryType(uint16_t aQueryType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetQueryType(aQueryType); } \
  NS_IMETHOD GetAsyncEnabled(bool *aAsyncEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncEnabled(aAsyncEnabled); } \
  NS_IMETHOD SetAsyncEnabled(bool aAsyncEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsyncEnabled(aAsyncEnabled); } \
  NS_IMETHOD Clone(nsINavHistoryQueryOptions * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQueryOptions : public nsINavHistoryQueryOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERYOPTIONS

  nsNavHistoryQueryOptions();

private:
  ~nsNavHistoryQueryOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryQueryOptions, nsINavHistoryQueryOptions)

nsNavHistoryQueryOptions::nsNavHistoryQueryOptions()
{
  /* member initializers and constructor code */
}

nsNavHistoryQueryOptions::~nsNavHistoryQueryOptions()
{
  /* destructor code */
}

/* attribute unsigned short sortingMode; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetSortingMode(uint16_t *aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetSortingMode(uint16_t aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String sortingAnnotation; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetSortingAnnotation(nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetSortingAnnotation(const nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short resultType; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetResultType(uint16_t *aResultType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetResultType(uint16_t aResultType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeItems; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeItems(bool *aExcludeItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeItems(bool aExcludeItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeQueries; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeQueries(bool *aExcludeQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeQueries(bool aExcludeQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeReadOnlyFolders; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean expandQueries; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExpandQueries(bool *aExpandQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExpandQueries(bool aExpandQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean includeHidden; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetIncludeHidden(bool *aIncludeHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetIncludeHidden(bool aIncludeHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long maxResults; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetMaxResults(uint32_t *aMaxResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetMaxResults(uint32_t aMaxResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short queryType; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetQueryType(uint16_t *aQueryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetQueryType(uint16_t aQueryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean asyncEnabled; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetAsyncEnabled(bool *aAsyncEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetAsyncEnabled(bool aAsyncEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQueryOptions clone (); */
NS_IMETHODIMP nsNavHistoryQueryOptions::Clone(nsINavHistoryQueryOptions * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryService */
#define NS_INAVHISTORYSERVICE_IID_STR "baebc597-9daf-4103-a325-e41ef9e7608a"

#define NS_INAVHISTORYSERVICE_IID \
  {0xbaebc597, 0x9daf, 0x4103, \
    { 0xa3, 0x25, 0xe4, 0x1e, 0xf9, 0xe7, 0x60, 0x8a }}

class NS_NO_VTABLE nsINavHistoryService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYSERVICE_IID)

  enum {
    TRANSITION_LINK = 1U,
    TRANSITION_TYPED = 2U,
    TRANSITION_BOOKMARK = 3U,
    TRANSITION_EMBED = 4U,
    TRANSITION_REDIRECT_PERMANENT = 5U,
    TRANSITION_REDIRECT_TEMPORARY = 6U,
    TRANSITION_DOWNLOAD = 7U,
    TRANSITION_FRAMED_LINK = 8U,
    DATABASE_STATUS_OK = 0U,
    DATABASE_STATUS_CREATE = 1U,
    DATABASE_STATUS_CORRUPT = 2U,
    DATABASE_STATUS_UPGRADED = 3U
  };

  /* readonly attribute unsigned short databaseStatus; */
  NS_IMETHOD GetDatabaseStatus(uint16_t *aDatabaseStatus) = 0;

  /* readonly attribute boolean hasHistoryEntries; */
  NS_IMETHOD GetHasHistoryEntries(bool *aHasHistoryEntries) = 0;

  /* AString getPageTitle (in nsIURI aURI); */
  NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval) = 0;

  /* void markPageAsFollowedBookmark (in nsIURI aURI); */
  NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) = 0;

  /* void markPageAsTyped (in nsIURI aURI); */
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) = 0;

  /* void markPageAsFollowedLink (in nsIURI aURI); */
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) = 0;

  /* AString getCharsetForURI (in nsIURI aURI); */
  NS_IMETHOD GetCharsetForURI(nsIURI *aURI, nsAString & _retval) = 0;

  /* void setCharsetForURI (in nsIURI aURI, in AString aCharset); */
  NS_IMETHOD SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset) = 0;

  /* boolean canAddURI (in nsIURI aURI); */
  NS_IMETHOD CanAddURI(nsIURI *aURI, bool *_retval) = 0;

  /* nsINavHistoryQuery getNewQuery (); */
  NS_IMETHOD GetNewQuery(nsINavHistoryQuery * *_retval) = 0;

  /* nsINavHistoryQueryOptions getNewQueryOptions (); */
  NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval) = 0;

  /* nsINavHistoryResult executeQuery (in nsINavHistoryQuery aQuery, in nsINavHistoryQueryOptions options); */
  NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) = 0;

  /* nsINavHistoryResult executeQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
  NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) = 0;

  /* void queryStringToQueries (in AUTF8String aQueryString, [array, size_is (aResultCount)] out nsINavHistoryQuery aQueries, out unsigned long aResultCount, out nsINavHistoryQueryOptions options); */
  NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options) = 0;

  /* AUTF8String queriesToQueryString ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
  NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval) = 0;

  /* void addObserver (in nsINavHistoryObserver observer, in boolean ownsWeak); */
  NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, bool ownsWeak) = 0;

  /* void removeObserver (in nsINavHistoryObserver observer); */
  NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) = 0;

  /* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aClosure); */
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) = 0;

  /* readonly attribute boolean historyDisabled; */
  NS_IMETHOD GetHistoryDisabled(bool *aHistoryDisabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryService, NS_INAVHISTORYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYSERVICE \
  NS_IMETHOD GetDatabaseStatus(uint16_t *aDatabaseStatus); \
  NS_IMETHOD GetHasHistoryEntries(bool *aHasHistoryEntries); \
  NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval); \
  NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI); \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI); \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI); \
  NS_IMETHOD GetCharsetForURI(nsIURI *aURI, nsAString & _retval); \
  NS_IMETHOD SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset); \
  NS_IMETHOD CanAddURI(nsIURI *aURI, bool *_retval); \
  NS_IMETHOD GetNewQuery(nsINavHistoryQuery * *_retval); \
  NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval); \
  NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval); \
  NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval); \
  NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options); \
  NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval); \
  NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, bool ownsWeak); \
  NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer); \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure); \
  NS_IMETHOD GetHistoryDisabled(bool *aHistoryDisabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYSERVICE(_to) \
  NS_IMETHOD GetDatabaseStatus(uint16_t *aDatabaseStatus) { return _to GetDatabaseStatus(aDatabaseStatus); } \
  NS_IMETHOD GetHasHistoryEntries(bool *aHasHistoryEntries) { return _to GetHasHistoryEntries(aHasHistoryEntries); } \
  NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval) { return _to GetPageTitle(aURI, _retval); } \
  NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) { return _to MarkPageAsFollowedBookmark(aURI); } \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) { return _to MarkPageAsTyped(aURI); } \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) { return _to MarkPageAsFollowedLink(aURI); } \
  NS_IMETHOD GetCharsetForURI(nsIURI *aURI, nsAString & _retval) { return _to GetCharsetForURI(aURI, _retval); } \
  NS_IMETHOD SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset) { return _to SetCharsetForURI(aURI, aCharset); } \
  NS_IMETHOD CanAddURI(nsIURI *aURI, bool *_retval) { return _to CanAddURI(aURI, _retval); } \
  NS_IMETHOD GetNewQuery(nsINavHistoryQuery * *_retval) { return _to GetNewQuery(_retval); } \
  NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval) { return _to GetNewQueryOptions(_retval); } \
  NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) { return _to ExecuteQuery(aQuery, options, _retval); } \
  NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) { return _to ExecuteQueries(aQueries, aQueryCount, options, _retval); } \
  NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options) { return _to QueryStringToQueries(aQueryString, aQueries, aResultCount, options); } \
  NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval) { return _to QueriesToQueryString(aQueries, aQueryCount, options, _retval); } \
  NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, bool ownsWeak) { return _to AddObserver(observer, ownsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) { return _to RemoveObserver(observer); } \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) { return _to RunInBatchMode(aCallback, aClosure); } \
  NS_IMETHOD GetHistoryDisabled(bool *aHistoryDisabled) { return _to GetHistoryDisabled(aHistoryDisabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYSERVICE(_to) \
  NS_IMETHOD GetDatabaseStatus(uint16_t *aDatabaseStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabaseStatus(aDatabaseStatus); } \
  NS_IMETHOD GetHasHistoryEntries(bool *aHasHistoryEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasHistoryEntries(aHasHistoryEntries); } \
  NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageTitle(aURI, _retval); } \
  NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsFollowedBookmark(aURI); } \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsTyped(aURI); } \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsFollowedLink(aURI); } \
  NS_IMETHOD GetCharsetForURI(nsIURI *aURI, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetForURI(aURI, _retval); } \
  NS_IMETHOD SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharsetForURI(aURI, aCharset); } \
  NS_IMETHOD CanAddURI(nsIURI *aURI, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanAddURI(aURI, _retval); } \
  NS_IMETHOD GetNewQuery(nsINavHistoryQuery * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewQuery(_retval); } \
  NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewQueryOptions(_retval); } \
  NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteQuery(aQuery, options, _retval); } \
  NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteQueries(aQueries, aQueryCount, options, _retval); } \
  NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryStringToQueries(aQueryString, aQueries, aResultCount, options); } \
  NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueriesToQueryString(aQueries, aQueryCount, options, _retval); } \
  NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, bool ownsWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer, ownsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunInBatchMode(aCallback, aClosure); } \
  NS_IMETHOD GetHistoryDisabled(bool *aHistoryDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistoryDisabled(aHistoryDisabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryService : public nsINavHistoryService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYSERVICE

  nsNavHistoryService();

private:
  ~nsNavHistoryService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryService, nsINavHistoryService)

nsNavHistoryService::nsNavHistoryService()
{
  /* member initializers and constructor code */
}

nsNavHistoryService::~nsNavHistoryService()
{
  /* destructor code */
}

/* readonly attribute unsigned short databaseStatus; */
NS_IMETHODIMP nsNavHistoryService::GetDatabaseStatus(uint16_t *aDatabaseStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasHistoryEntries; */
NS_IMETHODIMP nsNavHistoryService::GetHasHistoryEntries(bool *aHasHistoryEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getPageTitle (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::GetPageTitle(nsIURI *aURI, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsFollowedBookmark (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::MarkPageAsFollowedBookmark(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsTyped (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::MarkPageAsTyped(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsFollowedLink (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::MarkPageAsFollowedLink(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCharsetForURI (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::GetCharsetForURI(nsIURI *aURI, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCharsetForURI (in nsIURI aURI, in AString aCharset); */
NS_IMETHODIMP nsNavHistoryService::SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canAddURI (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::CanAddURI(nsIURI *aURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQuery getNewQuery (); */
NS_IMETHODIMP nsNavHistoryService::GetNewQuery(nsINavHistoryQuery * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQueryOptions getNewQueryOptions (); */
NS_IMETHODIMP nsNavHistoryService::GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResult executeQuery (in nsINavHistoryQuery aQuery, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResult executeQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void queryStringToQueries (in AUTF8String aQueryString, [array, size_is (aResultCount)] out nsINavHistoryQuery aQueries, out unsigned long aResultCount, out nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String queriesToQueryString ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsINavHistoryObserver observer, in boolean ownsWeak); */
NS_IMETHODIMP nsNavHistoryService::AddObserver(nsINavHistoryObserver *observer, bool ownsWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsINavHistoryObserver observer); */
NS_IMETHODIMP nsNavHistoryService::RemoveObserver(nsINavHistoryObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aClosure); */
NS_IMETHODIMP nsNavHistoryService::RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean historyDisabled; */
NS_IMETHODIMP nsNavHistoryService::GetHistoryDisabled(bool *aHistoryDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryBatchCallback */
#define NS_INAVHISTORYBATCHCALLBACK_IID_STR "5143f2bb-be0a-4faf-9acb-b0ed3f82952c"

#define NS_INAVHISTORYBATCHCALLBACK_IID \
  {0x5143f2bb, 0xbe0a, 0x4faf, \
    { 0x9a, 0xcb, 0xb0, 0xed, 0x3f, 0x82, 0x95, 0x2c }}

class NS_NO_VTABLE nsINavHistoryBatchCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYBATCHCALLBACK_IID)

  /* void runBatched (in nsISupports aUserData); */
  NS_IMETHOD RunBatched(nsISupports *aUserData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryBatchCallback, NS_INAVHISTORYBATCHCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYBATCHCALLBACK \
  NS_IMETHOD RunBatched(nsISupports *aUserData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYBATCHCALLBACK(_to) \
  NS_IMETHOD RunBatched(nsISupports *aUserData) { return _to RunBatched(aUserData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYBATCHCALLBACK(_to) \
  NS_IMETHOD RunBatched(nsISupports *aUserData) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunBatched(aUserData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryBatchCallback : public nsINavHistoryBatchCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYBATCHCALLBACK

  nsNavHistoryBatchCallback();

private:
  ~nsNavHistoryBatchCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryBatchCallback, nsINavHistoryBatchCallback)

nsNavHistoryBatchCallback::nsNavHistoryBatchCallback()
{
  /* member initializers and constructor code */
}

nsNavHistoryBatchCallback::~nsNavHistoryBatchCallback()
{
  /* destructor code */
}

/* void runBatched (in nsISupports aUserData); */
NS_IMETHODIMP nsNavHistoryBatchCallback::RunBatched(nsISupports *aUserData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINavHistoryService_h__ */
