/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/docshell/base/nsIContentViewer.idl
 */

#ifndef __gen_nsIContentViewer_h__
#define __gen_nsIContentViewer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsISHEntry; /* forward declaration */

class nsIPrintSettings; /* forward declaration */

class nsIWidget;
class nsIDocument;
struct nsIntRect;

/* starting interface:    nsIContentViewer */
#define NS_ICONTENTVIEWER_IID_STR "e2e5dd7d-8140-4fc5-b2c3-3a3b4f946fc7"

#define NS_ICONTENTVIEWER_IID \
  {0xe2e5dd7d, 0x8140, 0x4fc5, \
    { 0xb2, 0xc3, 0x3a, 0x3b, 0x4f, 0x94, 0x6f, 0xc7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentViewer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWER_IID)

  /* [noscript] void init (in nsIWidgetPtr aParentWidget, [const] in nsIntRectRef aBounds); */
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) = 0;

  /* attribute nsISupports container; */
  NS_SCRIPTABLE NS_IMETHOD GetContainer(nsISupports **aContainer) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContainer(nsISupports *aContainer) = 0;

  /* void loadStart (in nsISupports aDoc); */
  NS_SCRIPTABLE NS_IMETHOD LoadStart(nsISupports *aDoc) = 0;

  /**
   * On success, returns NS_SUCCESS_LOAD_STOPPED if the load was stopped by the
   * end of the method, and NS_OK otherwise.
   */
  /* void loadComplete (in unsigned long aStatus); */
  NS_SCRIPTABLE NS_IMETHOD LoadComplete(PRUint32 aStatus) = 0;

  /**
   * Checks if the document wants to prevent unloading by firing beforeunload on
   * the document, and if it does, prompts the user. The result is returned.
   *
   * @param aCallerClosesWindow indicates that the current caller will close the
   *        window. If the method returns true, all subsequent calls will be
   *        ignored.
   */
  /* boolean permitUnload ([optional] in boolean aCallerClosesWindow); */
  NS_SCRIPTABLE NS_IMETHOD PermitUnload(PRBool aCallerClosesWindow, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Works in tandem with permitUnload, if the caller decides not to close the
   * window it indicated it will, it is the caller's responsibility to reset
   * that with this method.
   *
   * @Note this method is only meant to be called on documents for which the
   *  caller has indicated that it will close the window. If that is not the case
   *  the behavior of this method is undefined.
   */
  /* void resetCloseWindow (); */
  NS_SCRIPTABLE NS_IMETHOD ResetCloseWindow(void) = 0;

  /* void pageHide (in boolean isUnload); */
  NS_SCRIPTABLE NS_IMETHOD PageHide(PRBool isUnload) = 0;

  /**
   * All users of a content viewer are responsible for calling both
   * close() and destroy(), in that order. 
   *
   * close() should be called when the load of a new page for the next
   * content viewer begins, and destroy() should be called when the next
   * content viewer replaces this one.
   *
   * |historyEntry| sets the session history entry for the content viewer.  If
   * this is null, then Destroy() will be called on the document by close().
   * If it is non-null, the document will not be destroyed, and the following
   * actions will happen when destroy() is called (*):
   *  - Sanitize() will be called on the viewer's document
   *  - The content viewer will set the contentViewer property on the
   *    history entry, and release its reference (ownership reversal).
   *  - hide() will be called, and no further destruction will happen.
   *
   *  (*) unless the document is currently being printed, in which case
   *      it will never be saved in session history.
   *
   */
  /* void close (in nsISHEntry historyEntry); */
  NS_SCRIPTABLE NS_IMETHOD Close(nsISHEntry *historyEntry) = 0;

  /* void destroy (); */
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) = 0;

  /* void stop (); */
  NS_SCRIPTABLE NS_IMETHOD Stop(void) = 0;

  /* attribute nsIDOMDocument DOMDocument; */
  NS_SCRIPTABLE NS_IMETHOD GetDOMDocument(nsIDOMDocument **aDOMDocument) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) = 0;

  /**
   * Returns DOMDocument as nsIDocument and without addrefing.
   */
  /* [noscript, notxpcom] nsIDocumentPtr getDocument (); */
  NS_IMETHOD_(nsIDocument *) GetDocument(void) = 0;

  /* [noscript] void getBounds (in nsIntRectRef aBounds); */
  NS_IMETHOD GetBounds(nsIntRect & aBounds) = 0;

  /* [noscript] void setBounds ([const] in nsIntRectRef aBounds); */
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) = 0;

  /**
   * The previous content viewer, which has been |close|d but not
   * |destroy|ed.
   */
  /* [noscript] attribute nsIContentViewer previousViewer; */
  NS_IMETHOD GetPreviousViewer(nsIContentViewer **aPreviousViewer) = 0;
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) = 0;

  /* void move (in long aX, in long aY); */
  NS_SCRIPTABLE NS_IMETHOD Move(PRInt32 aX, PRInt32 aY) = 0;

  /* void show (); */
  NS_SCRIPTABLE NS_IMETHOD Show(void) = 0;

  /* void hide (); */
  NS_SCRIPTABLE NS_IMETHOD Hide(void) = 0;

  /* attribute boolean sticky; */
  NS_SCRIPTABLE NS_IMETHOD GetSticky(PRBool *aSticky) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSticky(PRBool aSticky) = 0;

  /* boolean requestWindowClose (); */
  NS_SCRIPTABLE NS_IMETHOD RequestWindowClose(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Attach the content viewer to its DOM window and docshell.
   * @param aState A state object that might be useful in attaching the DOM
   *               window.
   * @param aSHEntry The history entry that the content viewer was stored in.
   *                 The entry must have the docshells for all of the child
   *                 documents stored in its child shell list.
   */
  /* void open (in nsISupports aState, in nsISHEntry aSHEntry); */
  NS_SCRIPTABLE NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) = 0;

  /**
   * Clears the current history entry.  This is used if we need to clear out
   * the saved presentation state.
   */
  /* void clearHistoryEntry (); */
  NS_SCRIPTABLE NS_IMETHOD ClearHistoryEntry(void) = 0;

  /* void setPageMode (in PRBool aPageMode, in nsIPrintSettings aPrintSettings); */
  NS_SCRIPTABLE NS_IMETHOD SetPageMode(PRBool aPageMode, nsIPrintSettings *aPrintSettings) = 0;

  /**
   * Get the history entry that this viewer will save itself into when
   * destroyed.  Can return null
   */
  /* readonly attribute nsISHEntry historyEntry; */
  NS_SCRIPTABLE NS_IMETHOD GetHistoryEntry(nsISHEntry **aHistoryEntry) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewer, NS_ICONTENTVIEWER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWER \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds); \
  NS_SCRIPTABLE NS_IMETHOD GetContainer(nsISupports **aContainer); \
  NS_SCRIPTABLE NS_IMETHOD SetContainer(nsISupports *aContainer); \
  NS_SCRIPTABLE NS_IMETHOD LoadStart(nsISupports *aDoc); \
  NS_SCRIPTABLE NS_IMETHOD LoadComplete(PRUint32 aStatus); \
  NS_SCRIPTABLE NS_IMETHOD PermitUnload(PRBool aCallerClosesWindow, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ResetCloseWindow(void); \
  NS_SCRIPTABLE NS_IMETHOD PageHide(PRBool isUnload); \
  NS_SCRIPTABLE NS_IMETHOD Close(nsISHEntry *historyEntry); \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void); \
  NS_SCRIPTABLE NS_IMETHOD Stop(void); \
  NS_SCRIPTABLE NS_IMETHOD GetDOMDocument(nsIDOMDocument **aDOMDocument); \
  NS_SCRIPTABLE NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument); \
  NS_IMETHOD_(nsIDocument *) GetDocument(void); \
  NS_IMETHOD GetBounds(nsIntRect & aBounds); \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds); \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer **aPreviousViewer); \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer); \
  NS_SCRIPTABLE NS_IMETHOD Move(PRInt32 aX, PRInt32 aY); \
  NS_SCRIPTABLE NS_IMETHOD Show(void); \
  NS_SCRIPTABLE NS_IMETHOD Hide(void); \
  NS_SCRIPTABLE NS_IMETHOD GetSticky(PRBool *aSticky); \
  NS_SCRIPTABLE NS_IMETHOD SetSticky(PRBool aSticky); \
  NS_SCRIPTABLE NS_IMETHOD RequestWindowClose(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry); \
  NS_SCRIPTABLE NS_IMETHOD ClearHistoryEntry(void); \
  NS_SCRIPTABLE NS_IMETHOD SetPageMode(PRBool aPageMode, nsIPrintSettings *aPrintSettings); \
  NS_SCRIPTABLE NS_IMETHOD GetHistoryEntry(nsISHEntry **aHistoryEntry); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWER(_to) \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) { return _to Init(aParentWidget, aBounds); } \
  NS_SCRIPTABLE NS_IMETHOD GetContainer(nsISupports **aContainer) { return _to GetContainer(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD SetContainer(nsISupports *aContainer) { return _to SetContainer(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD LoadStart(nsISupports *aDoc) { return _to LoadStart(aDoc); } \
  NS_SCRIPTABLE NS_IMETHOD LoadComplete(PRUint32 aStatus) { return _to LoadComplete(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD PermitUnload(PRBool aCallerClosesWindow, PRBool *_retval NS_OUTPARAM) { return _to PermitUnload(aCallerClosesWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ResetCloseWindow(void) { return _to ResetCloseWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD PageHide(PRBool isUnload) { return _to PageHide(isUnload); } \
  NS_SCRIPTABLE NS_IMETHOD Close(nsISHEntry *historyEntry) { return _to Close(historyEntry); } \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) { return _to Destroy(); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_SCRIPTABLE NS_IMETHOD GetDOMDocument(nsIDOMDocument **aDOMDocument) { return _to GetDOMDocument(aDOMDocument); } \
  NS_SCRIPTABLE NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) { return _to SetDOMDocument(aDOMDocument); } \
  NS_IMETHOD_(nsIDocument *) GetDocument(void) { return _to GetDocument(); } \
  NS_IMETHOD GetBounds(nsIntRect & aBounds) { return _to GetBounds(aBounds); } \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) { return _to SetBounds(aBounds); } \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer **aPreviousViewer) { return _to GetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) { return _to SetPreviousViewer(aPreviousViewer); } \
  NS_SCRIPTABLE NS_IMETHOD Move(PRInt32 aX, PRInt32 aY) { return _to Move(aX, aY); } \
  NS_SCRIPTABLE NS_IMETHOD Show(void) { return _to Show(); } \
  NS_SCRIPTABLE NS_IMETHOD Hide(void) { return _to Hide(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSticky(PRBool *aSticky) { return _to GetSticky(aSticky); } \
  NS_SCRIPTABLE NS_IMETHOD SetSticky(PRBool aSticky) { return _to SetSticky(aSticky); } \
  NS_SCRIPTABLE NS_IMETHOD RequestWindowClose(PRBool *_retval NS_OUTPARAM) { return _to RequestWindowClose(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) { return _to Open(aState, aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD ClearHistoryEntry(void) { return _to ClearHistoryEntry(); } \
  NS_SCRIPTABLE NS_IMETHOD SetPageMode(PRBool aPageMode, nsIPrintSettings *aPrintSettings) { return _to SetPageMode(aPageMode, aPrintSettings); } \
  NS_SCRIPTABLE NS_IMETHOD GetHistoryEntry(nsISHEntry **aHistoryEntry) { return _to GetHistoryEntry(aHistoryEntry); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWER(_to) \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aParentWidget, aBounds); } \
  NS_SCRIPTABLE NS_IMETHOD GetContainer(nsISupports **aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainer(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD SetContainer(nsISupports *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainer(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD LoadStart(nsISupports *aDoc) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadStart(aDoc); } \
  NS_SCRIPTABLE NS_IMETHOD LoadComplete(PRUint32 aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadComplete(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD PermitUnload(PRBool aCallerClosesWindow, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PermitUnload(aCallerClosesWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ResetCloseWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetCloseWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD PageHide(PRBool isUnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->PageHide(isUnload); } \
  NS_SCRIPTABLE NS_IMETHOD Close(nsISHEntry *historyEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(historyEntry); } \
  NS_SCRIPTABLE NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_SCRIPTABLE NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_SCRIPTABLE NS_IMETHOD GetDOMDocument(nsIDOMDocument **aDOMDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMDocument(aDOMDocument); } \
  NS_SCRIPTABLE NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDOMDocument(aDOMDocument); } \
  NS_IMETHOD_(nsIDocument *) GetDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(); } \
  NS_IMETHOD GetBounds(nsIntRect & aBounds) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBounds(aBounds); } \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBounds(aBounds); } \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer **aPreviousViewer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreviousViewer(aPreviousViewer); } \
  NS_SCRIPTABLE NS_IMETHOD Move(PRInt32 aX, PRInt32 aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->Move(aX, aY); } \
  NS_SCRIPTABLE NS_IMETHOD Show(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(); } \
  NS_SCRIPTABLE NS_IMETHOD Hide(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Hide(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSticky(PRBool *aSticky) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSticky(aSticky); } \
  NS_SCRIPTABLE NS_IMETHOD SetSticky(PRBool aSticky) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSticky(aSticky); } \
  NS_SCRIPTABLE NS_IMETHOD RequestWindowClose(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestWindowClose(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aState, aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD ClearHistoryEntry(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearHistoryEntry(); } \
  NS_SCRIPTABLE NS_IMETHOD SetPageMode(PRBool aPageMode, nsIPrintSettings *aPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageMode(aPageMode, aPrintSettings); } \
  NS_SCRIPTABLE NS_IMETHOD GetHistoryEntry(nsISHEntry **aHistoryEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistoryEntry(aHistoryEntry); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentViewer : public nsIContentViewer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEWER

  nsContentViewer();

private:
  ~nsContentViewer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentViewer, nsIContentViewer)

nsContentViewer::nsContentViewer()
{
  /* member initializers and constructor code */
}

nsContentViewer::~nsContentViewer()
{
  /* destructor code */
}

/* [noscript] void init (in nsIWidgetPtr aParentWidget, [const] in nsIntRectRef aBounds); */
NS_IMETHODIMP nsContentViewer::Init(nsIWidget *aParentWidget, const nsIntRect & aBounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports container; */
NS_IMETHODIMP nsContentViewer::GetContainer(nsISupports **aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetContainer(nsISupports *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadStart (in nsISupports aDoc); */
NS_IMETHODIMP nsContentViewer::LoadStart(nsISupports *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadComplete (in unsigned long aStatus); */
NS_IMETHODIMP nsContentViewer::LoadComplete(PRUint32 aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean permitUnload ([optional] in boolean aCallerClosesWindow); */
NS_IMETHODIMP nsContentViewer::PermitUnload(PRBool aCallerClosesWindow, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetCloseWindow (); */
NS_IMETHODIMP nsContentViewer::ResetCloseWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pageHide (in boolean isUnload); */
NS_IMETHODIMP nsContentViewer::PageHide(PRBool isUnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (in nsISHEntry historyEntry); */
NS_IMETHODIMP nsContentViewer::Close(nsISHEntry *historyEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroy (); */
NS_IMETHODIMP nsContentViewer::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsContentViewer::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMDocument DOMDocument; */
NS_IMETHODIMP nsContentViewer::GetDOMDocument(nsIDOMDocument **aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetDOMDocument(nsIDOMDocument *aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] nsIDocumentPtr getDocument (); */
NS_IMETHODIMP_(nsIDocument *) nsContentViewer::GetDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getBounds (in nsIntRectRef aBounds); */
NS_IMETHODIMP nsContentViewer::GetBounds(nsIntRect & aBounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setBounds ([const] in nsIntRectRef aBounds); */
NS_IMETHODIMP nsContentViewer::SetBounds(const nsIntRect & aBounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIContentViewer previousViewer; */
NS_IMETHODIMP nsContentViewer::GetPreviousViewer(nsIContentViewer **aPreviousViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetPreviousViewer(nsIContentViewer *aPreviousViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void move (in long aX, in long aY); */
NS_IMETHODIMP nsContentViewer::Move(PRInt32 aX, PRInt32 aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void show (); */
NS_IMETHODIMP nsContentViewer::Show()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hide (); */
NS_IMETHODIMP nsContentViewer::Hide()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean sticky; */
NS_IMETHODIMP nsContentViewer::GetSticky(PRBool *aSticky)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetSticky(PRBool aSticky)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean requestWindowClose (); */
NS_IMETHODIMP nsContentViewer::RequestWindowClose(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (in nsISupports aState, in nsISHEntry aSHEntry); */
NS_IMETHODIMP nsContentViewer::Open(nsISupports *aState, nsISHEntry *aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearHistoryEntry (); */
NS_IMETHODIMP nsContentViewer::ClearHistoryEntry()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPageMode (in PRBool aPageMode, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsContentViewer::SetPageMode(PRBool aPageMode, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISHEntry historyEntry; */
NS_IMETHODIMP nsContentViewer::GetHistoryEntry(nsISHEntry **aHistoryEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentViewer_MOZILLA_2_0_BRANCH */
#define NS_ICONTENTVIEWER_MOZILLA_2_0_BRANCH_IID_STR "4710ef6e-6de3-47fe-88f4-e49b48c87fc9"

#define NS_ICONTENTVIEWER_MOZILLA_2_0_BRANCH_IID \
  {0x4710ef6e, 0x6de3, 0x47fe, \
    { 0x88, 0xf4, 0xe4, 0x9b, 0x48, 0xc8, 0x7f, 0xc9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentViewer_MOZILLA_2_0_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWER_MOZILLA_2_0_BRANCH_IID)

  /* readonly attribute boolean isTabModalPromptAllowed; */
  NS_SCRIPTABLE NS_IMETHOD GetIsTabModalPromptAllowed(PRBool *aIsTabModalPromptAllowed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewer_MOZILLA_2_0_BRANCH, NS_ICONTENTVIEWER_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWER_MOZILLA_2_0_BRANCH \
  NS_SCRIPTABLE NS_IMETHOD GetIsTabModalPromptAllowed(PRBool *aIsTabModalPromptAllowed); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWER_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsTabModalPromptAllowed(PRBool *aIsTabModalPromptAllowed) { return _to GetIsTabModalPromptAllowed(aIsTabModalPromptAllowed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWER_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsTabModalPromptAllowed(PRBool *aIsTabModalPromptAllowed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTabModalPromptAllowed(aIsTabModalPromptAllowed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentViewer_MOZILLA_2_0_BRANCH : public nsIContentViewer_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEWER_MOZILLA_2_0_BRANCH

  nsContentViewer_MOZILLA_2_0_BRANCH();

private:
  ~nsContentViewer_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentViewer_MOZILLA_2_0_BRANCH, nsIContentViewer_MOZILLA_2_0_BRANCH)

nsContentViewer_MOZILLA_2_0_BRANCH::nsContentViewer_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsContentViewer_MOZILLA_2_0_BRANCH::~nsContentViewer_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* readonly attribute boolean isTabModalPromptAllowed; */
NS_IMETHODIMP nsContentViewer_MOZILLA_2_0_BRANCH::GetIsTabModalPromptAllowed(PRBool *aIsTabModalPromptAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentViewer_h__ */
