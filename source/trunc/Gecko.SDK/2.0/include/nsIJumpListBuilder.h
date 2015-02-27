/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsIJumpListBuilder.idl
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

class NS_NO_VTABLE NS_SCRIPTABLE nsIJumpListBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJUMPLISTBUILDER_IID)

  /**
   * JumpLists
   *
   * Jump lists are built and then applied. Modifying an applied jump list is not
   * permitted. Callers should begin the creation of a new jump list using
   * initListBuild, add sub lists using addListBuild, then commit the jump list
   * using commitListBuild. Lists are built in real-time during the sequence of
   * build calls, make sure to check for errors on each individual step.
   *
   * The default number of allowed items in a jump list is ten. Users can change
   * the number through system preferences. User may also pin items to jump lists,
   * which take up additional slots. Applications do not have control over the
   * number of items allowed in jump lists; excess items added are dropped by the
   * system. Item insertion priority is defined as first to last added. 
   *
   * Users may remove items from jump lists after they are commited. The system
   * tracks removed items between commits. A list of these items is returned by
   * a call to initListBuild. nsIJumpListBuilder does not filter entries added that
   * have been removed since the last commit. To prevent repeatedly adding entires
   * users have removed, applications are encoraged to track removed items 
   * internally.
   *
   * Each list is made up of an array of nsIWinJumpListItems representing items
   * such as shortcuts, links, and separators. See nsIJumpListItem for information
   * on adding additional jump list types.
   */
/**
   * List Types
   */
/**
   * Task List
   * 
   * Tasks are common actions performed by users within the application. A task
   * can be represented by an application shortcut and associated command line
   * parameters or a URI. Task lists should generally be static lists that do not
   * change often, if at all - similar to an application menu.
   *
   * Tasks are given the highest priority of all lists when space is limited.
   */
  enum { JUMPLIST_CATEGORY_TASKS = 0 };

  /**
   * Recent or Frequent list
   * 
   * Recent and frequent lists are based on Window's recent document lists. The
   * lists are generated automatically by Windows. Applications that use recent
   * or frequent lists should keep document use tracking up to date by calling
   * the SHAddToRecentDocs shell api.
   */
  enum { JUMPLIST_CATEGORY_RECENT = 1 };

  enum { JUMPLIST_CATEGORY_FREQUENT = 2 };

  /**
   * Custom Lists
   *
   * Custom lists can be made up of tasks, links, and separators. The title of
   * of the list is passed through the optional string parameter of addBuildList.
   */
  enum { JUMPLIST_CATEGORY_CUSTOMLIST = 3 };

  /**
   * Indicates whether jump list taskbar features are supported by the current
   * host.
   */
  /* readonly attribute short available; */
  NS_SCRIPTABLE NS_IMETHOD GetAvailable(PRInt16 *aAvailable) = 0;

  /**
   * JumpList management
   *
   * @throw NS_ERROR_NOT_AVAILABLE on all calls if taskbar functionality
   * is not supported by the operating system.
   */
/**
   * Indicates if a commit has already occurred in this session.
   */
  /* readonly attribute boolean isListCommitted; */
  NS_SCRIPTABLE NS_IMETHOD GetIsListCommitted(PRBool *aIsListCommitted) = 0;

  /**
   * The maximum number of jump list items the current desktop can support.
   */
  /* readonly attribute short maxListItems; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxListItems(PRInt16 *aMaxListItems) = 0;

  /**
   * Initializes a jump list build and returns a list of items the user removed
   * since the last time a jump list was committed. Removed items can become state
   * after initListBuild is called, lists should be built in single-shot fasion.
   *
   * @param removedItems
   *        A list of items that were removed by the user since the last commit.
   *
   * @returns true if the operation completed successfully.
   */
  /* boolean initListBuild (in nsIMutableArray removedItems); */
  NS_SCRIPTABLE NS_IMETHOD InitListBuild(nsIMutableArray *removedItems, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Adds a list and if required, a set of items for the list.
   *
   * @param aCatType
   *        The type of list to add.
   * @param items
   *        An array of nsIJumpListItem items to add to the list.
   * @param catName
   *        For custom lists, the title of the list.
   *
   * @returns true if the operation completed successfully.
   *
   * @throw NS_ERROR_INVALID_ARG if incorrect parameters are passed for
   * a particular category or item type.
   * @throw NS_ERROR_ILLEGAL_VALUE if an item is added that was removed
   * since the last commit.
   * @throw NS_ERROR_UNEXPECTED on internal errors.
   */
  /* boolean addListToBuild (in short aCatType, [optional] in nsIArray items, [optional] in AString catName); */
  NS_SCRIPTABLE NS_IMETHOD AddListToBuild(PRInt16 aCatType, nsIArray *items, const nsAString & catName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Aborts and clears the current jump list build.
   */
  /* void abortListBuild (); */
  NS_SCRIPTABLE NS_IMETHOD AbortListBuild(void) = 0;

  /**
   * Commits the current jump list build to the Taskbar.
   *
   * @returns true if the operation completed successfully.
   */
  /* boolean commitListBuild (); */
  NS_SCRIPTABLE NS_IMETHOD CommitListBuild(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Deletes any currently applied taskbar jump list for this application.
   * Common uses would be the enabling of a privacy mode and uninstallation.
   *
   * @returns true if the operation completed successfully.
   *
   * @throw NS_ERROR_UNEXPECTED on internal errors.
   */
  /* boolean deleteActiveList (); */
  NS_SCRIPTABLE NS_IMETHOD DeleteActiveList(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJumpListBuilder, NS_IJUMPLISTBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJUMPLISTBUILDER \
  NS_SCRIPTABLE NS_IMETHOD GetAvailable(PRInt16 *aAvailable); \
  NS_SCRIPTABLE NS_IMETHOD GetIsListCommitted(PRBool *aIsListCommitted); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxListItems(PRInt16 *aMaxListItems); \
  NS_SCRIPTABLE NS_IMETHOD InitListBuild(nsIMutableArray *removedItems, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddListToBuild(PRInt16 aCatType, nsIArray *items, const nsAString & catName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AbortListBuild(void); \
  NS_SCRIPTABLE NS_IMETHOD CommitListBuild(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DeleteActiveList(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJUMPLISTBUILDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAvailable(PRInt16 *aAvailable) { return _to GetAvailable(aAvailable); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsListCommitted(PRBool *aIsListCommitted) { return _to GetIsListCommitted(aIsListCommitted); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxListItems(PRInt16 *aMaxListItems) { return _to GetMaxListItems(aMaxListItems); } \
  NS_SCRIPTABLE NS_IMETHOD InitListBuild(nsIMutableArray *removedItems, PRBool *_retval NS_OUTPARAM) { return _to InitListBuild(removedItems, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddListToBuild(PRInt16 aCatType, nsIArray *items, const nsAString & catName, PRBool *_retval NS_OUTPARAM) { return _to AddListToBuild(aCatType, items, catName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AbortListBuild(void) { return _to AbortListBuild(); } \
  NS_SCRIPTABLE NS_IMETHOD CommitListBuild(PRBool *_retval NS_OUTPARAM) { return _to CommitListBuild(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteActiveList(PRBool *_retval NS_OUTPARAM) { return _to DeleteActiveList(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJUMPLISTBUILDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAvailable(PRInt16 *aAvailable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailable(aAvailable); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsListCommitted(PRBool *aIsListCommitted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsListCommitted(aIsListCommitted); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxListItems(PRInt16 *aMaxListItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxListItems(aMaxListItems); } \
  NS_SCRIPTABLE NS_IMETHOD InitListBuild(nsIMutableArray *removedItems, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitListBuild(removedItems, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddListToBuild(PRInt16 aCatType, nsIArray *items, const nsAString & catName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListToBuild(aCatType, items, catName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AbortListBuild(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AbortListBuild(); } \
  NS_SCRIPTABLE NS_IMETHOD CommitListBuild(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CommitListBuild(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteActiveList(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteActiveList(_retval); } 

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
NS_IMETHODIMP nsJumpListBuilder::GetAvailable(PRInt16 *aAvailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isListCommitted; */
NS_IMETHODIMP nsJumpListBuilder::GetIsListCommitted(PRBool *aIsListCommitted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short maxListItems; */
NS_IMETHODIMP nsJumpListBuilder::GetMaxListItems(PRInt16 *aMaxListItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean initListBuild (in nsIMutableArray removedItems); */
NS_IMETHODIMP nsJumpListBuilder::InitListBuild(nsIMutableArray *removedItems, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean addListToBuild (in short aCatType, [optional] in nsIArray items, [optional] in AString catName); */
NS_IMETHODIMP nsJumpListBuilder::AddListToBuild(PRInt16 aCatType, nsIArray *items, const nsAString & catName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abortListBuild (); */
NS_IMETHODIMP nsJumpListBuilder::AbortListBuild()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean commitListBuild (); */
NS_IMETHODIMP nsJumpListBuilder::CommitListBuild(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean deleteActiveList (); */
NS_IMETHODIMP nsJumpListBuilder::DeleteActiveList(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJumpListBuilder_h__ */
