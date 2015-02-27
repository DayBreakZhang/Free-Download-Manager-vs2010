/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/docshell/shistory/public/nsISHEntry.idl
 */

#ifndef __gen_nsISHEntry_h__
#define __gen_nsISHEntry_h__


#ifndef __gen_nsIHistoryEntry_h__
#include "nsIHistoryEntry.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILayoutHistoryState; /* forward declaration */

class nsIContentViewer; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIDocShellTreeItem; /* forward declaration */

class nsISupportsArray; /* forward declaration */

struct nsIntRect;
class nsDocShellEditorData;

/* starting interface:    nsISHEntry */
#define NS_ISHENTRY_IID_STR "39b73c3a-48eb-4189-8069-247279c3c42d"

#define NS_ISHENTRY_IID \
  {0x39b73c3a, 0x48eb, 0x4189, \
    { 0x80, 0x69, 0x24, 0x72, 0x79, 0xc3, 0xc4, 0x2d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISHEntry : public nsIHistoryEntry {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHENTRY_IID)

  /** URI for the document */
  /* void setURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD SetURI(nsIURI *aURI) = 0;

  /** Referrer URI */
  /* attribute nsIURI referrerURI; */
  NS_SCRIPTABLE NS_IMETHOD GetReferrerURI(nsIURI **aReferrerURI) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReferrerURI(nsIURI *aReferrerURI) = 0;

  /** Content viewer, for fast restoration of presentation */
  /* attribute nsIContentViewer contentViewer; */
  NS_SCRIPTABLE NS_IMETHOD GetContentViewer(nsIContentViewer **aContentViewer) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentViewer(nsIContentViewer *aContentViewer) = 0;

  /** Whether the content viewer is marked "sticky" */
  /* attribute boolean sticky; */
  NS_SCRIPTABLE NS_IMETHOD GetSticky(PRBool *aSticky) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSticky(PRBool aSticky) = 0;

  /** Saved state of the global window object */
  /* attribute nsISupports windowState; */
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(nsISupports **aWindowState) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWindowState(nsISupports *aWindowState) = 0;

  /**
     * Saved position and dimensions of the content viewer; we must adjust the
     * root view's widget accordingly if this has changed when the presentation
     * is restored.
     */
  /* [noscript] void getViewerBounds (in nsIntRect bounds); */
  NS_IMETHOD GetViewerBounds(nsIntRect & bounds) = 0;

  /* [noscript] void setViewerBounds ([const] in nsIntRect bounds); */
  NS_IMETHOD SetViewerBounds(const nsIntRect & bounds) = 0;

  /**
     * Saved child docshells corresponding to contentViewer.  The child shells
     * are restored as children of the parent docshell, in this order, when the
     * parent docshell restores a saved presentation.
     */
/** Append a child shell to the end of our list. */
  /* void addChildShell (in nsIDocShellTreeItem shell); */
  NS_SCRIPTABLE NS_IMETHOD AddChildShell(nsIDocShellTreeItem *shell) = 0;

  /**
     * Get the child shell at |index|; returns null if |index| is out of bounds.
     */
  /* nsIDocShellTreeItem childShellAt (in long index); */
  NS_SCRIPTABLE NS_IMETHOD ChildShellAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM) = 0;

  /**
     * Clear the child shell list.
     */
  /* void clearChildShells (); */
  NS_SCRIPTABLE NS_IMETHOD ClearChildShells(void) = 0;

  /** Saved refresh URI list for the content viewer */
  /* attribute nsISupportsArray refreshURIList; */
  NS_SCRIPTABLE NS_IMETHOD GetRefreshURIList(nsISupportsArray **aRefreshURIList) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetRefreshURIList(nsISupportsArray *aRefreshURIList) = 0;

  /**
     * Ensure that the cached presentation members are self-consistent.
     * If either |contentViewer| or |windowState| are null, then all of the
     * following members are cleared/reset:
     *  contentViewer, sticky, windowState, viewerBounds, childShells,
     *  refreshURIList.
     */
  /* void syncPresentationState (); */
  NS_SCRIPTABLE NS_IMETHOD SyncPresentationState(void) = 0;

  /** Title for the document */
  /* void setTitle (in AString aTitle); */
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /** Post Data for the document */
  /* attribute nsIInputStream postData; */
  NS_SCRIPTABLE NS_IMETHOD GetPostData(nsIInputStream **aPostData) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPostData(nsIInputStream *aPostData) = 0;

  /** LayoutHistoryState for scroll position and form values */
  /* attribute nsILayoutHistoryState layoutHistoryState; */
  NS_SCRIPTABLE NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState **aLayoutHistoryState) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState) = 0;

  /** parent of this entry */
  /* attribute nsISHEntry parent; */
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsISHEntry **aParent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetParent(nsISHEntry *aParent) = 0;

  /**
     * The loadType for this entry. This is typically loadHistory except
     * when reload is pressed, it has the appropriate reload flag
     */
  /* attribute unsigned long loadType; */
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(PRUint32 *aLoadType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(PRUint32 aLoadType) = 0;

  /**
     * An ID to help identify this entry from others during
     * subframe navigation
     */
  /* attribute unsigned long ID; */
  NS_SCRIPTABLE NS_IMETHOD GetID(PRUint32 *aID) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetID(PRUint32 aID) = 0;

  /**
     * pageIdentifier is an integer that should be the same for two entries
     * attached to the same docshell only if the two entries are entries for
     * the same page in the sense that one could go from the state represented
     * by one to the state represented by the other simply by scrolling (so the
     * entries are separated by an anchor traversal or a subframe navigation in
     * some other frame).
     */
  /* attribute unsigned long pageIdentifier; */
  NS_SCRIPTABLE NS_IMETHOD GetPageIdentifier(PRUint32 *aPageIdentifier) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPageIdentifier(PRUint32 aPageIdentifier) = 0;

  /**
     * docIdentifier is an integer that should be the same for two entries
     * attached to the same docshell if and only if the two entries are entries
     * for the same document.  In practice, two entries A and B will have the
     * same docIdentifier if they have the same pageIdentifier or if B was
     * created by A calling history.pushState().
     */
  /* attribute unsigned long long docIdentifier; */
  NS_SCRIPTABLE NS_IMETHOD GetDocIdentifier(PRUint64 *aDocIdentifier) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocIdentifier(PRUint64 aDocIdentifier) = 0;

  /**
     * Changes this entry's doc identifier to a new value which is unique
     * among those of all other entries.
     */
  /* void setUniqueDocIdentifier (); */
  NS_SCRIPTABLE NS_IMETHOD SetUniqueDocIdentifier(void) = 0;

  /** attribute to set and get the cache key for the entry */
  /* attribute nsISupports cacheKey; */
  NS_SCRIPTABLE NS_IMETHOD GetCacheKey(nsISupports **aCacheKey) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCacheKey(nsISupports *aCacheKey) = 0;

  /** attribute to indicate whether layoutHistoryState should be saved */
  /* attribute boolean saveLayoutStateFlag; */
  NS_SCRIPTABLE NS_IMETHOD GetSaveLayoutStateFlag(PRBool *aSaveLayoutStateFlag) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSaveLayoutStateFlag(PRBool aSaveLayoutStateFlag) = 0;

  /** attribute to indicate whether the page is already expired in cache */
  /* attribute boolean expirationStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetExpirationStatus(PRBool *aExpirationStatus) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExpirationStatus(PRBool aExpirationStatus) = 0;

  /**
     * attribute to indicate the content-type of the document that this
     * is a session history entry for
     */
  /* attribute ACString contentType; */
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsACString & aContentType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const nsACString & aContentType) = 0;

  /** Set/Get scrollers' positon in anchored pages */
  /* void setScrollPosition (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD SetScrollPosition(PRInt32 x, PRInt32 y) = 0;

  /* void getScrollPosition (out long x, out long y); */
  NS_SCRIPTABLE NS_IMETHOD GetScrollPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) = 0;

  /** Additional ways to create an entry */
  /* [noscript] void create (in nsIURI URI, in AString title, in nsIInputStream inputStream, in nsILayoutHistoryState layoutHistoryState, in nsISupports cacheKey, in ACString contentType, in nsISupports owner, in unsigned long long docshellID, in boolean dynamicCreation); */
  NS_IMETHOD Create(nsIURI *URI, const nsAString & title, nsIInputStream *inputStream, nsILayoutHistoryState *layoutHistoryState, nsISupports *cacheKey, const nsACString & contentType, nsISupports *owner, PRUint64 docshellID, PRBool dynamicCreation) = 0;

  /* nsISHEntry clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISHEntry **_retval NS_OUTPARAM) = 0;

  /** Attribute that indicates if this entry is for a subframe navigation */
  /* void setIsSubFrame (in boolean aFlag); */
  NS_SCRIPTABLE NS_IMETHOD SetIsSubFrame(PRBool aFlag) = 0;

  /** Return any content viewer present in or below this node in the
        nsSHEntry tree.  This will differ from contentViewer in the case
        where a child nsSHEntry has the content viewer for this tree. */
  /* nsIContentViewer getAnyContentViewer (out nsISHEntry ownerEntry); */
  NS_SCRIPTABLE NS_IMETHOD GetAnyContentViewer(nsISHEntry **ownerEntry NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM) = 0;

  /**
     * Get the owner, if any, that was associated with the channel
     * that the document that was loaded to create this history entry
     * came from.
     */
  /* attribute nsISupports owner; */
  NS_SCRIPTABLE NS_IMETHOD GetOwner(nsISupports **aOwner) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOwner(nsISupports *aOwner) = 0;

  /**
     * Get/set data associated with this history state via a pushState() call,
     * encoded as JSON.
     **/
  /* attribute AString stateData; */
  NS_SCRIPTABLE NS_IMETHOD GetStateData(nsAString & aStateData) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStateData(const nsAString & aStateData) = 0;

  /**
     * Gets the owning pointer to the editor data assosicated with
     * this shistory entry. This forgets its pointer, so free it when
     * you're done.
     */
  /* [noscript, notxpcom] nsDocShellEditorDataPtr forgetEditorData (); */
  NS_IMETHOD_(nsDocShellEditorData *) ForgetEditorData(void) = 0;

  /**
     * Sets the owning pointer to the editor data assosicated with
     * this shistory entry. Unless forgetEditorData() is called, this
     * shentry will destroy the editor data when it's destroyed.
     */
  /* [noscript, notxpcom] void setEditorData (in nsDocShellEditorDataPtr aData); */
  NS_IMETHOD_(void) SetEditorData(nsDocShellEditorData *aData) = 0;

  /** Returns true if this shistory entry is storing a detached editor. */
  /* [noscript, notxpcom] boolean hasDetachedEditor (); */
  NS_IMETHOD_(PRBool ) HasDetachedEditor(void) = 0;

  /**
     * Returns true if the related docshell was added because of
     * dynamic addition of an iframe/frame.
     */
  /* boolean isDynamicallyAdded (); */
  NS_SCRIPTABLE NS_IMETHOD IsDynamicallyAdded(PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Returns true if any of the child entries returns true
     * when isDynamicallyAdded is called on it.
     */
  /* boolean hasDynamicallyAddedChild (); */
  NS_SCRIPTABLE NS_IMETHOD HasDynamicallyAddedChild(PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * The history ID of the docshell.
     */
  /* attribute unsigned long long docshellID; */
  NS_SCRIPTABLE NS_IMETHOD GetDocshellID(PRUint64 *aDocshellID) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocshellID(PRUint64 aDocshellID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHEntry, NS_ISHENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHENTRY \
  NS_SCRIPTABLE NS_IMETHOD SetURI(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD GetReferrerURI(nsIURI **aReferrerURI); \
  NS_SCRIPTABLE NS_IMETHOD SetReferrerURI(nsIURI *aReferrerURI); \
  NS_SCRIPTABLE NS_IMETHOD GetContentViewer(nsIContentViewer **aContentViewer); \
  NS_SCRIPTABLE NS_IMETHOD SetContentViewer(nsIContentViewer *aContentViewer); \
  NS_SCRIPTABLE NS_IMETHOD GetSticky(PRBool *aSticky); \
  NS_SCRIPTABLE NS_IMETHOD SetSticky(PRBool aSticky); \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(nsISupports **aWindowState); \
  NS_SCRIPTABLE NS_IMETHOD SetWindowState(nsISupports *aWindowState); \
  NS_IMETHOD GetViewerBounds(nsIntRect & bounds); \
  NS_IMETHOD SetViewerBounds(const nsIntRect & bounds); \
  NS_SCRIPTABLE NS_IMETHOD AddChildShell(nsIDocShellTreeItem *shell); \
  NS_SCRIPTABLE NS_IMETHOD ChildShellAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ClearChildShells(void); \
  NS_SCRIPTABLE NS_IMETHOD GetRefreshURIList(nsISupportsArray **aRefreshURIList); \
  NS_SCRIPTABLE NS_IMETHOD SetRefreshURIList(nsISupportsArray *aRefreshURIList); \
  NS_SCRIPTABLE NS_IMETHOD SyncPresentationState(void); \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(nsIInputStream **aPostData); \
  NS_SCRIPTABLE NS_IMETHOD SetPostData(nsIInputStream *aPostData); \
  NS_SCRIPTABLE NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState **aLayoutHistoryState); \
  NS_SCRIPTABLE NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState); \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsISHEntry **aParent); \
  NS_SCRIPTABLE NS_IMETHOD SetParent(nsISHEntry *aParent); \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(PRUint32 *aLoadType); \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(PRUint32 aLoadType); \
  NS_SCRIPTABLE NS_IMETHOD GetID(PRUint32 *aID); \
  NS_SCRIPTABLE NS_IMETHOD SetID(PRUint32 aID); \
  NS_SCRIPTABLE NS_IMETHOD GetPageIdentifier(PRUint32 *aPageIdentifier); \
  NS_SCRIPTABLE NS_IMETHOD SetPageIdentifier(PRUint32 aPageIdentifier); \
  NS_SCRIPTABLE NS_IMETHOD GetDocIdentifier(PRUint64 *aDocIdentifier); \
  NS_SCRIPTABLE NS_IMETHOD SetDocIdentifier(PRUint64 aDocIdentifier); \
  NS_SCRIPTABLE NS_IMETHOD SetUniqueDocIdentifier(void); \
  NS_SCRIPTABLE NS_IMETHOD GetCacheKey(nsISupports **aCacheKey); \
  NS_SCRIPTABLE NS_IMETHOD SetCacheKey(nsISupports *aCacheKey); \
  NS_SCRIPTABLE NS_IMETHOD GetSaveLayoutStateFlag(PRBool *aSaveLayoutStateFlag); \
  NS_SCRIPTABLE NS_IMETHOD SetSaveLayoutStateFlag(PRBool aSaveLayoutStateFlag); \
  NS_SCRIPTABLE NS_IMETHOD GetExpirationStatus(PRBool *aExpirationStatus); \
  NS_SCRIPTABLE NS_IMETHOD SetExpirationStatus(PRBool aExpirationStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsACString & aContentType); \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const nsACString & aContentType); \
  NS_SCRIPTABLE NS_IMETHOD SetScrollPosition(PRInt32 x, PRInt32 y); \
  NS_SCRIPTABLE NS_IMETHOD GetScrollPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM); \
  NS_IMETHOD Create(nsIURI *URI, const nsAString & title, nsIInputStream *inputStream, nsILayoutHistoryState *layoutHistoryState, nsISupports *cacheKey, const nsACString & contentType, nsISupports *owner, PRUint64 docshellID, PRBool dynamicCreation); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISHEntry **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetIsSubFrame(PRBool aFlag); \
  NS_SCRIPTABLE NS_IMETHOD GetAnyContentViewer(nsISHEntry **ownerEntry NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetOwner(nsISupports **aOwner); \
  NS_SCRIPTABLE NS_IMETHOD SetOwner(nsISupports *aOwner); \
  NS_SCRIPTABLE NS_IMETHOD GetStateData(nsAString & aStateData); \
  NS_SCRIPTABLE NS_IMETHOD SetStateData(const nsAString & aStateData); \
  NS_IMETHOD_(nsDocShellEditorData *) ForgetEditorData(void); \
  NS_IMETHOD_(void) SetEditorData(nsDocShellEditorData *aData); \
  NS_IMETHOD_(PRBool ) HasDetachedEditor(void); \
  NS_SCRIPTABLE NS_IMETHOD IsDynamicallyAdded(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasDynamicallyAddedChild(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDocshellID(PRUint64 *aDocshellID); \
  NS_SCRIPTABLE NS_IMETHOD SetDocshellID(PRUint64 aDocshellID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHENTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetURI(nsIURI *aURI) { return _to SetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrerURI(nsIURI **aReferrerURI) { return _to GetReferrerURI(aReferrerURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetReferrerURI(nsIURI *aReferrerURI) { return _to SetReferrerURI(aReferrerURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentViewer(nsIContentViewer **aContentViewer) { return _to GetContentViewer(aContentViewer); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentViewer(nsIContentViewer *aContentViewer) { return _to SetContentViewer(aContentViewer); } \
  NS_SCRIPTABLE NS_IMETHOD GetSticky(PRBool *aSticky) { return _to GetSticky(aSticky); } \
  NS_SCRIPTABLE NS_IMETHOD SetSticky(PRBool aSticky) { return _to SetSticky(aSticky); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(nsISupports **aWindowState) { return _to GetWindowState(aWindowState); } \
  NS_SCRIPTABLE NS_IMETHOD SetWindowState(nsISupports *aWindowState) { return _to SetWindowState(aWindowState); } \
  NS_IMETHOD GetViewerBounds(nsIntRect & bounds) { return _to GetViewerBounds(bounds); } \
  NS_IMETHOD SetViewerBounds(const nsIntRect & bounds) { return _to SetViewerBounds(bounds); } \
  NS_SCRIPTABLE NS_IMETHOD AddChildShell(nsIDocShellTreeItem *shell) { return _to AddChildShell(shell); } \
  NS_SCRIPTABLE NS_IMETHOD ChildShellAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return _to ChildShellAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearChildShells(void) { return _to ClearChildShells(); } \
  NS_SCRIPTABLE NS_IMETHOD GetRefreshURIList(nsISupportsArray **aRefreshURIList) { return _to GetRefreshURIList(aRefreshURIList); } \
  NS_SCRIPTABLE NS_IMETHOD SetRefreshURIList(nsISupportsArray *aRefreshURIList) { return _to SetRefreshURIList(aRefreshURIList); } \
  NS_SCRIPTABLE NS_IMETHOD SyncPresentationState(void) { return _to SyncPresentationState(); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(nsIInputStream **aPostData) { return _to GetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD SetPostData(nsIInputStream *aPostData) { return _to SetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState **aLayoutHistoryState) { return _to GetLayoutHistoryState(aLayoutHistoryState); } \
  NS_SCRIPTABLE NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState) { return _to SetLayoutHistoryState(aLayoutHistoryState); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsISHEntry **aParent) { return _to GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD SetParent(nsISHEntry *aParent) { return _to SetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(PRUint32 *aLoadType) { return _to GetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(PRUint32 aLoadType) { return _to SetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD GetID(PRUint32 *aID) { return _to GetID(aID); } \
  NS_SCRIPTABLE NS_IMETHOD SetID(PRUint32 aID) { return _to SetID(aID); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageIdentifier(PRUint32 *aPageIdentifier) { return _to GetPageIdentifier(aPageIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD SetPageIdentifier(PRUint32 aPageIdentifier) { return _to SetPageIdentifier(aPageIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocIdentifier(PRUint64 *aDocIdentifier) { return _to GetDocIdentifier(aDocIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocIdentifier(PRUint64 aDocIdentifier) { return _to SetDocIdentifier(aDocIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD SetUniqueDocIdentifier(void) { return _to SetUniqueDocIdentifier(); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheKey(nsISupports **aCacheKey) { return _to GetCacheKey(aCacheKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheKey(nsISupports *aCacheKey) { return _to SetCacheKey(aCacheKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetSaveLayoutStateFlag(PRBool *aSaveLayoutStateFlag) { return _to GetSaveLayoutStateFlag(aSaveLayoutStateFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetSaveLayoutStateFlag(PRBool aSaveLayoutStateFlag) { return _to SetSaveLayoutStateFlag(aSaveLayoutStateFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpirationStatus(PRBool *aExpirationStatus) { return _to GetExpirationStatus(aExpirationStatus); } \
  NS_SCRIPTABLE NS_IMETHOD SetExpirationStatus(PRBool aExpirationStatus) { return _to SetExpirationStatus(aExpirationStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsACString & aContentType) { return _to GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const nsACString & aContentType) { return _to SetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD SetScrollPosition(PRInt32 x, PRInt32 y) { return _to SetScrollPosition(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) { return _to GetScrollPosition(x, y); } \
  NS_IMETHOD Create(nsIURI *URI, const nsAString & title, nsIInputStream *inputStream, nsILayoutHistoryState *layoutHistoryState, nsISupports *cacheKey, const nsACString & contentType, nsISupports *owner, PRUint64 docshellID, PRBool dynamicCreation) { return _to Create(URI, title, inputStream, layoutHistoryState, cacheKey, contentType, owner, docshellID, dynamicCreation); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISHEntry **_retval NS_OUTPARAM) { return _to Clone(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsSubFrame(PRBool aFlag) { return _to SetIsSubFrame(aFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnyContentViewer(nsISHEntry **ownerEntry NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM) { return _to GetAnyContentViewer(ownerEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetOwner(nsISupports **aOwner) { return _to GetOwner(aOwner); } \
  NS_SCRIPTABLE NS_IMETHOD SetOwner(nsISupports *aOwner) { return _to SetOwner(aOwner); } \
  NS_SCRIPTABLE NS_IMETHOD GetStateData(nsAString & aStateData) { return _to GetStateData(aStateData); } \
  NS_SCRIPTABLE NS_IMETHOD SetStateData(const nsAString & aStateData) { return _to SetStateData(aStateData); } \
  NS_IMETHOD_(nsDocShellEditorData *) ForgetEditorData(void) { return _to ForgetEditorData(); } \
  NS_IMETHOD_(void) SetEditorData(nsDocShellEditorData *aData) { return _to SetEditorData(aData); } \
  NS_IMETHOD_(PRBool ) HasDetachedEditor(void) { return _to HasDetachedEditor(); } \
  NS_SCRIPTABLE NS_IMETHOD IsDynamicallyAdded(PRBool *_retval NS_OUTPARAM) { return _to IsDynamicallyAdded(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasDynamicallyAddedChild(PRBool *_retval NS_OUTPARAM) { return _to HasDynamicallyAddedChild(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocshellID(PRUint64 *aDocshellID) { return _to GetDocshellID(aDocshellID); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocshellID(PRUint64 aDocshellID) { return _to SetDocshellID(aDocshellID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHENTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrerURI(nsIURI **aReferrerURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrerURI(aReferrerURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetReferrerURI(nsIURI *aReferrerURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReferrerURI(aReferrerURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentViewer(nsIContentViewer **aContentViewer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentViewer(aContentViewer); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentViewer(nsIContentViewer *aContentViewer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentViewer(aContentViewer); } \
  NS_SCRIPTABLE NS_IMETHOD GetSticky(PRBool *aSticky) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSticky(aSticky); } \
  NS_SCRIPTABLE NS_IMETHOD SetSticky(PRBool aSticky) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSticky(aSticky); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(nsISupports **aWindowState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowState(aWindowState); } \
  NS_SCRIPTABLE NS_IMETHOD SetWindowState(nsISupports *aWindowState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindowState(aWindowState); } \
  NS_IMETHOD GetViewerBounds(nsIntRect & bounds) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewerBounds(bounds); } \
  NS_IMETHOD SetViewerBounds(const nsIntRect & bounds) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetViewerBounds(bounds); } \
  NS_SCRIPTABLE NS_IMETHOD AddChildShell(nsIDocShellTreeItem *shell) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChildShell(shell); } \
  NS_SCRIPTABLE NS_IMETHOD ChildShellAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChildShellAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearChildShells(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearChildShells(); } \
  NS_SCRIPTABLE NS_IMETHOD GetRefreshURIList(nsISupportsArray **aRefreshURIList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRefreshURIList(aRefreshURIList); } \
  NS_SCRIPTABLE NS_IMETHOD SetRefreshURIList(nsISupportsArray *aRefreshURIList) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRefreshURIList(aRefreshURIList); } \
  NS_SCRIPTABLE NS_IMETHOD SyncPresentationState(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SyncPresentationState(); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetPostData(nsIInputStream **aPostData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD SetPostData(nsIInputStream *aPostData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPostData(aPostData); } \
  NS_SCRIPTABLE NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState **aLayoutHistoryState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayoutHistoryState(aLayoutHistoryState); } \
  NS_SCRIPTABLE NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLayoutHistoryState(aLayoutHistoryState); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsISHEntry **aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD SetParent(nsISHEntry *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(PRUint32 *aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(PRUint32 aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD GetID(PRUint32 *aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetID(aID); } \
  NS_SCRIPTABLE NS_IMETHOD SetID(PRUint32 aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetID(aID); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageIdentifier(PRUint32 *aPageIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageIdentifier(aPageIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD SetPageIdentifier(PRUint32 aPageIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageIdentifier(aPageIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocIdentifier(PRUint64 *aDocIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocIdentifier(aDocIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocIdentifier(PRUint64 aDocIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocIdentifier(aDocIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD SetUniqueDocIdentifier(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUniqueDocIdentifier(); } \
  NS_SCRIPTABLE NS_IMETHOD GetCacheKey(nsISupports **aCacheKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheKey(aCacheKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetCacheKey(nsISupports *aCacheKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheKey(aCacheKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetSaveLayoutStateFlag(PRBool *aSaveLayoutStateFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSaveLayoutStateFlag(aSaveLayoutStateFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetSaveLayoutStateFlag(PRBool aSaveLayoutStateFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSaveLayoutStateFlag(aSaveLayoutStateFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpirationStatus(PRBool *aExpirationStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpirationStatus(aExpirationStatus); } \
  NS_SCRIPTABLE NS_IMETHOD SetExpirationStatus(PRBool aExpirationStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExpirationStatus(aExpirationStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD SetScrollPosition(PRInt32 x, PRInt32 y) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollPosition(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollPosition(x, y); } \
  NS_IMETHOD Create(nsIURI *URI, const nsAString & title, nsIInputStream *inputStream, nsILayoutHistoryState *layoutHistoryState, nsISupports *cacheKey, const nsACString & contentType, nsISupports *owner, PRUint64 docshellID, PRBool dynamicCreation) { return !_to ? NS_ERROR_NULL_POINTER : _to->Create(URI, title, inputStream, layoutHistoryState, cacheKey, contentType, owner, docshellID, dynamicCreation); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISHEntry **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsSubFrame(PRBool aFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsSubFrame(aFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnyContentViewer(nsISHEntry **ownerEntry NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnyContentViewer(ownerEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetOwner(nsISupports **aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwner(aOwner); } \
  NS_SCRIPTABLE NS_IMETHOD SetOwner(nsISupports *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwner(aOwner); } \
  NS_SCRIPTABLE NS_IMETHOD GetStateData(nsAString & aStateData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStateData(aStateData); } \
  NS_SCRIPTABLE NS_IMETHOD SetStateData(const nsAString & aStateData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStateData(aStateData); } \
  NS_IMETHOD_(nsDocShellEditorData *) ForgetEditorData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForgetEditorData(); } \
  NS_IMETHOD_(void) SetEditorData(nsDocShellEditorData *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEditorData(aData); } \
  NS_IMETHOD_(PRBool ) HasDetachedEditor(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasDetachedEditor(); } \
  NS_SCRIPTABLE NS_IMETHOD IsDynamicallyAdded(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDynamicallyAdded(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasDynamicallyAddedChild(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasDynamicallyAddedChild(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocshellID(PRUint64 *aDocshellID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocshellID(aDocshellID); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocshellID(PRUint64 aDocshellID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocshellID(aDocshellID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHEntry : public nsISHEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHENTRY

  nsSHEntry();

private:
  ~nsSHEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSHEntry, nsISHEntry)

nsSHEntry::nsSHEntry()
{
  /* member initializers and constructor code */
}

nsSHEntry::~nsSHEntry()
{
  /* destructor code */
}

/* void setURI (in nsIURI aURI); */
NS_IMETHODIMP nsSHEntry::SetURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI referrerURI; */
NS_IMETHODIMP nsSHEntry::GetReferrerURI(nsIURI **aReferrerURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetReferrerURI(nsIURI *aReferrerURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIContentViewer contentViewer; */
NS_IMETHODIMP nsSHEntry::GetContentViewer(nsIContentViewer **aContentViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetContentViewer(nsIContentViewer *aContentViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean sticky; */
NS_IMETHODIMP nsSHEntry::GetSticky(PRBool *aSticky)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetSticky(PRBool aSticky)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports windowState; */
NS_IMETHODIMP nsSHEntry::GetWindowState(nsISupports **aWindowState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetWindowState(nsISupports *aWindowState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getViewerBounds (in nsIntRect bounds); */
NS_IMETHODIMP nsSHEntry::GetViewerBounds(nsIntRect & bounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setViewerBounds ([const] in nsIntRect bounds); */
NS_IMETHODIMP nsSHEntry::SetViewerBounds(const nsIntRect & bounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addChildShell (in nsIDocShellTreeItem shell); */
NS_IMETHODIMP nsSHEntry::AddChildShell(nsIDocShellTreeItem *shell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem childShellAt (in long index); */
NS_IMETHODIMP nsSHEntry::ChildShellAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearChildShells (); */
NS_IMETHODIMP nsSHEntry::ClearChildShells()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupportsArray refreshURIList; */
NS_IMETHODIMP nsSHEntry::GetRefreshURIList(nsISupportsArray **aRefreshURIList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetRefreshURIList(nsISupportsArray *aRefreshURIList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void syncPresentationState (); */
NS_IMETHODIMP nsSHEntry::SyncPresentationState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTitle (in AString aTitle); */
NS_IMETHODIMP nsSHEntry::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream postData; */
NS_IMETHODIMP nsSHEntry::GetPostData(nsIInputStream **aPostData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetPostData(nsIInputStream *aPostData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsILayoutHistoryState layoutHistoryState; */
NS_IMETHODIMP nsSHEntry::GetLayoutHistoryState(nsILayoutHistoryState **aLayoutHistoryState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISHEntry parent; */
NS_IMETHODIMP nsSHEntry::GetParent(nsISHEntry **aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetParent(nsISHEntry *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long loadType; */
NS_IMETHODIMP nsSHEntry::GetLoadType(PRUint32 *aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetLoadType(PRUint32 aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long ID; */
NS_IMETHODIMP nsSHEntry::GetID(PRUint32 *aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetID(PRUint32 aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long pageIdentifier; */
NS_IMETHODIMP nsSHEntry::GetPageIdentifier(PRUint32 *aPageIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetPageIdentifier(PRUint32 aPageIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long docIdentifier; */
NS_IMETHODIMP nsSHEntry::GetDocIdentifier(PRUint64 *aDocIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetDocIdentifier(PRUint64 aDocIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setUniqueDocIdentifier (); */
NS_IMETHODIMP nsSHEntry::SetUniqueDocIdentifier()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports cacheKey; */
NS_IMETHODIMP nsSHEntry::GetCacheKey(nsISupports **aCacheKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetCacheKey(nsISupports *aCacheKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean saveLayoutStateFlag; */
NS_IMETHODIMP nsSHEntry::GetSaveLayoutStateFlag(PRBool *aSaveLayoutStateFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetSaveLayoutStateFlag(PRBool aSaveLayoutStateFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean expirationStatus; */
NS_IMETHODIMP nsSHEntry::GetExpirationStatus(PRBool *aExpirationStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetExpirationStatus(PRBool aExpirationStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString contentType; */
NS_IMETHODIMP nsSHEntry::GetContentType(nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetContentType(const nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScrollPosition (in long x, in long y); */
NS_IMETHODIMP nsSHEntry::SetScrollPosition(PRInt32 x, PRInt32 y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollPosition (out long x, out long y); */
NS_IMETHODIMP nsSHEntry::GetScrollPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void create (in nsIURI URI, in AString title, in nsIInputStream inputStream, in nsILayoutHistoryState layoutHistoryState, in nsISupports cacheKey, in ACString contentType, in nsISupports owner, in unsigned long long docshellID, in boolean dynamicCreation); */
NS_IMETHODIMP nsSHEntry::Create(nsIURI *URI, const nsAString & title, nsIInputStream *inputStream, nsILayoutHistoryState *layoutHistoryState, nsISupports *cacheKey, const nsACString & contentType, nsISupports *owner, PRUint64 docshellID, PRBool dynamicCreation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISHEntry clone (); */
NS_IMETHODIMP nsSHEntry::Clone(nsISHEntry **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIsSubFrame (in boolean aFlag); */
NS_IMETHODIMP nsSHEntry::SetIsSubFrame(PRBool aFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIContentViewer getAnyContentViewer (out nsISHEntry ownerEntry); */
NS_IMETHODIMP nsSHEntry::GetAnyContentViewer(nsISHEntry **ownerEntry NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports owner; */
NS_IMETHODIMP nsSHEntry::GetOwner(nsISupports **aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetOwner(nsISupports *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString stateData; */
NS_IMETHODIMP nsSHEntry::GetStateData(nsAString & aStateData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetStateData(const nsAString & aStateData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] nsDocShellEditorDataPtr forgetEditorData (); */
NS_IMETHODIMP_(nsDocShellEditorData *) nsSHEntry::ForgetEditorData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] void setEditorData (in nsDocShellEditorDataPtr aData); */
NS_IMETHODIMP_(void) nsSHEntry::SetEditorData(nsDocShellEditorData *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] boolean hasDetachedEditor (); */
NS_IMETHODIMP_(PRBool ) nsSHEntry::HasDetachedEditor()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isDynamicallyAdded (); */
NS_IMETHODIMP nsSHEntry::IsDynamicallyAdded(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasDynamicallyAddedChild (); */
NS_IMETHODIMP nsSHEntry::HasDynamicallyAddedChild(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long docshellID; */
NS_IMETHODIMP nsSHEntry::GetDocshellID(PRUint64 *aDocshellID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntry::SetDocshellID(PRUint64 aDocshellID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISHEntryInternal */
#define NS_ISHENTRYINTERNAL_IID_STR "bb66ac35-253b-471f-a317-3ece940f04c5"

#define NS_ISHENTRYINTERNAL_IID \
  {0xbb66ac35, 0x253b, 0x471f, \
    { 0xa3, 0x17, 0x3e, 0xce, 0x94, 0x0f, 0x04, 0xc5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISHEntryInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHENTRYINTERNAL_IID)

  /* [notxpcom] void RemoveFromBFCacheAsync (); */
  NS_IMETHOD_(void) RemoveFromBFCacheAsync(void) = 0;

  /* [notxpcom] void RemoveFromBFCacheSync (); */
  NS_IMETHOD_(void) RemoveFromBFCacheSync(void) = 0;

  /**
     * A number that is assigned by the sHistory when the entry is activated
     */
  /* attribute unsigned long lastTouched; */
  NS_SCRIPTABLE NS_IMETHOD GetLastTouched(PRUint32 *aLastTouched) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLastTouched(PRUint32 aLastTouched) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHEntryInternal, NS_ISHENTRYINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHENTRYINTERNAL \
  NS_IMETHOD_(void) RemoveFromBFCacheAsync(void); \
  NS_IMETHOD_(void) RemoveFromBFCacheSync(void); \
  NS_SCRIPTABLE NS_IMETHOD GetLastTouched(PRUint32 *aLastTouched); \
  NS_SCRIPTABLE NS_IMETHOD SetLastTouched(PRUint32 aLastTouched); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHENTRYINTERNAL(_to) \
  NS_IMETHOD_(void) RemoveFromBFCacheAsync(void) { return _to RemoveFromBFCacheAsync(); } \
  NS_IMETHOD_(void) RemoveFromBFCacheSync(void) { return _to RemoveFromBFCacheSync(); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastTouched(PRUint32 *aLastTouched) { return _to GetLastTouched(aLastTouched); } \
  NS_SCRIPTABLE NS_IMETHOD SetLastTouched(PRUint32 aLastTouched) { return _to SetLastTouched(aLastTouched); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHENTRYINTERNAL(_to) \
  NS_IMETHOD_(void) RemoveFromBFCacheAsync(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFromBFCacheAsync(); } \
  NS_IMETHOD_(void) RemoveFromBFCacheSync(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFromBFCacheSync(); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastTouched(PRUint32 *aLastTouched) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastTouched(aLastTouched); } \
  NS_SCRIPTABLE NS_IMETHOD SetLastTouched(PRUint32 aLastTouched) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLastTouched(aLastTouched); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHEntryInternal : public nsISHEntryInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHENTRYINTERNAL

  nsSHEntryInternal();

private:
  ~nsSHEntryInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSHEntryInternal, nsISHEntryInternal)

nsSHEntryInternal::nsSHEntryInternal()
{
  /* member initializers and constructor code */
}

nsSHEntryInternal::~nsSHEntryInternal()
{
  /* destructor code */
}

/* [notxpcom] void RemoveFromBFCacheAsync (); */
NS_IMETHODIMP_(void) nsSHEntryInternal::RemoveFromBFCacheAsync()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void RemoveFromBFCacheSync (); */
NS_IMETHODIMP_(void) nsSHEntryInternal::RemoveFromBFCacheSync()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long lastTouched; */
NS_IMETHODIMP nsSHEntryInternal::GetLastTouched(PRUint32 *aLastTouched)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHEntryInternal::SetLastTouched(PRUint32 aLastTouched)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {BFD1A791-AD9F-11d3-BDC7-0050040A9B44}
#define NS_SHENTRY_CID \
{0xbfd1a791, 0xad9f, 0x11d3, {0xbd, 0xc7, 0x0, 0x50, 0x4, 0xa, 0x9b, 0x44}}
#define NS_SHENTRY_CONTRACTID \
    "@mozilla.org/browser/session-history-entry;1"

#endif /* __gen_nsISHEntry_h__ */
