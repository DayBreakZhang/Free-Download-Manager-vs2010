/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentViewer.idl
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
class nsIDocShell; /* forward declaration */

class nsIDocument; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsISHEntry; /* forward declaration */

class nsIPrintSettings; /* forward declaration */

class nsIWidget;
struct nsIntRect;
class nsIPresShell;
class nsPresContext;
class nsView;
class nsDOMNavigationTiming;

/* starting interface:    nsIContentViewer */
#define NS_ICONTENTVIEWER_IID_STR "4fc2512b-87c7-4a37-9fac-cee0f116bfdf"

#define NS_ICONTENTVIEWER_IID \
  {0x4fc2512b, 0x87c7, 0x4a37, \
    { 0x9f, 0xac, 0xce, 0xe0, 0xf1, 0x16, 0xbf, 0xdf }}

class NS_NO_VTABLE nsIContentViewer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWER_IID)

  /* [noscript] void init (in nsIWidgetPtr aParentWidget, [const] in nsIntRectRef aBounds); */
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) = 0;

  /* attribute nsIDocShell container; */
  NS_IMETHOD GetContainer(nsIDocShell * *aContainer) = 0;
  NS_IMETHOD SetContainer(nsIDocShell *aContainer) = 0;

  /* [noscript,nostdcall,notxpcom] void loadStart (in nsIDocument aDoc); */
  virtual void LoadStart(nsIDocument *aDoc) = 0;

  /* void loadComplete (in nsresult aStatus); */
  NS_IMETHOD LoadComplete(nsresult aStatus) = 0;

  /* boolean permitUnload ([optional] in boolean aCallerClosesWindow); */
  NS_IMETHOD PermitUnload(bool aCallerClosesWindow, bool *_retval) = 0;

  /* [noscript,nostdcall] boolean permitUnloadInternal (in boolean aCallerClosesWindow, inout boolean aShouldPrompt); */
  virtual nsresult PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval) = 0;

  /* readonly attribute boolean beforeUnloadFiring; */
  NS_IMETHOD GetBeforeUnloadFiring(bool *aBeforeUnloadFiring) = 0;

  /* void resetCloseWindow (); */
  NS_IMETHOD ResetCloseWindow(void) = 0;

  /* void pageHide (in boolean isUnload); */
  NS_IMETHOD PageHide(bool isUnload) = 0;

  /* void close (in nsISHEntry historyEntry); */
  NS_IMETHOD Close(nsISHEntry *historyEntry) = 0;

  /* void destroy (); */
  NS_IMETHOD Destroy(void) = 0;

  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /* attribute nsIDOMDocument DOMDocument; */
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) = 0;
  NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) = 0;

  /* [noscript,notxpcom] nsIDocument getDocument (); */
  NS_IMETHOD_(nsIDocument *) GetDocument(void) = 0;

  /* [noscript] void getBounds (in nsIntRectRef aBounds); */
  NS_IMETHOD GetBounds(nsIntRect & aBounds) = 0;

  /* [noscript] void setBounds ([const] in nsIntRectRef aBounds); */
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) = 0;

  /* [noscript] attribute nsIContentViewer previousViewer; */
  NS_IMETHOD GetPreviousViewer(nsIContentViewer * *aPreviousViewer) = 0;
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) = 0;

  /* void move (in long aX, in long aY); */
  NS_IMETHOD Move(int32_t aX, int32_t aY) = 0;

  /* void show (); */
  NS_IMETHOD Show(void) = 0;

  /* void hide (); */
  NS_IMETHOD Hide(void) = 0;

  /* attribute boolean sticky; */
  NS_IMETHOD GetSticky(bool *aSticky) = 0;
  NS_IMETHOD SetSticky(bool aSticky) = 0;

  /* boolean requestWindowClose (); */
  NS_IMETHOD RequestWindowClose(bool *_retval) = 0;

  /* void open (in nsISupports aState, in nsISHEntry aSHEntry); */
  NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) = 0;

  /* void clearHistoryEntry (); */
  NS_IMETHOD ClearHistoryEntry(void) = 0;

  /* void setPageMode (in boolean aPageMode, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings) = 0;

  /* readonly attribute nsISHEntry historyEntry; */
  NS_IMETHOD GetHistoryEntry(nsISHEntry * *aHistoryEntry) = 0;

  /* readonly attribute boolean isTabModalPromptAllowed; */
  NS_IMETHOD GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed) = 0;

  /* readonly attribute boolean isHidden; */
  NS_IMETHOD GetIsHidden(bool *aIsHidden) = 0;

  /* [noscript] readonly attribute nsIPresShellPtr presShell; */
  NS_IMETHOD GetPresShell(nsIPresShell **aPresShell) = 0;

  /* [noscript] readonly attribute nsPresContextPtr presContext; */
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) = 0;

  /* [noscript] void setDocumentInternal (in nsIDocument aDocument, in boolean aForceReuseInnerWindow); */
  NS_IMETHOD SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow) = 0;

  /* [noscript,nostdcall,notxpcom] nsViewPtr findContainerView (); */
  virtual nsView * FindContainerView(void) = 0;

  /* [noscript,nostdcall,notxpcom] void setNavigationTiming (in nsDOMNavigationTimingPtr aTiming); */
  virtual void SetNavigationTiming(nsDOMNavigationTiming *aTiming) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewer, NS_ICONTENTVIEWER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWER \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds); \
  NS_IMETHOD GetContainer(nsIDocShell * *aContainer); \
  NS_IMETHOD SetContainer(nsIDocShell *aContainer); \
  virtual void LoadStart(nsIDocument *aDoc); \
  NS_IMETHOD LoadComplete(nsresult aStatus); \
  NS_IMETHOD PermitUnload(bool aCallerClosesWindow, bool *_retval); \
  virtual nsresult PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval); \
  NS_IMETHOD GetBeforeUnloadFiring(bool *aBeforeUnloadFiring); \
  NS_IMETHOD ResetCloseWindow(void); \
  NS_IMETHOD PageHide(bool isUnload); \
  NS_IMETHOD Close(nsISHEntry *historyEntry); \
  NS_IMETHOD Destroy(void); \
  NS_IMETHOD Stop(void); \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument); \
  NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument); \
  NS_IMETHOD_(nsIDocument *) GetDocument(void); \
  NS_IMETHOD GetBounds(nsIntRect & aBounds); \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds); \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer * *aPreviousViewer); \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer); \
  NS_IMETHOD Move(int32_t aX, int32_t aY); \
  NS_IMETHOD Show(void); \
  NS_IMETHOD Hide(void); \
  NS_IMETHOD GetSticky(bool *aSticky); \
  NS_IMETHOD SetSticky(bool aSticky); \
  NS_IMETHOD RequestWindowClose(bool *_retval); \
  NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry); \
  NS_IMETHOD ClearHistoryEntry(void); \
  NS_IMETHOD SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings); \
  NS_IMETHOD GetHistoryEntry(nsISHEntry * *aHistoryEntry); \
  NS_IMETHOD GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed); \
  NS_IMETHOD GetIsHidden(bool *aIsHidden); \
  NS_IMETHOD GetPresShell(nsIPresShell **aPresShell); \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext); \
  NS_IMETHOD SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow); \
  virtual nsView * FindContainerView(void); \
  virtual void SetNavigationTiming(nsDOMNavigationTiming *aTiming); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWER(_to) \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) { return _to Init(aParentWidget, aBounds); } \
  NS_IMETHOD GetContainer(nsIDocShell * *aContainer) { return _to GetContainer(aContainer); } \
  NS_IMETHOD SetContainer(nsIDocShell *aContainer) { return _to SetContainer(aContainer); } \
  virtual void LoadStart(nsIDocument *aDoc) { return _to LoadStart(aDoc); } \
  NS_IMETHOD LoadComplete(nsresult aStatus) { return _to LoadComplete(aStatus); } \
  NS_IMETHOD PermitUnload(bool aCallerClosesWindow, bool *_retval) { return _to PermitUnload(aCallerClosesWindow, _retval); } \
  virtual nsresult PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval) { return _to PermitUnloadInternal(aCallerClosesWindow, aShouldPrompt, _retval); } \
  NS_IMETHOD GetBeforeUnloadFiring(bool *aBeforeUnloadFiring) { return _to GetBeforeUnloadFiring(aBeforeUnloadFiring); } \
  NS_IMETHOD ResetCloseWindow(void) { return _to ResetCloseWindow(); } \
  NS_IMETHOD PageHide(bool isUnload) { return _to PageHide(isUnload); } \
  NS_IMETHOD Close(nsISHEntry *historyEntry) { return _to Close(historyEntry); } \
  NS_IMETHOD Destroy(void) { return _to Destroy(); } \
  NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) { return _to GetDOMDocument(aDOMDocument); } \
  NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) { return _to SetDOMDocument(aDOMDocument); } \
  NS_IMETHOD_(nsIDocument *) GetDocument(void) { return _to GetDocument(); } \
  NS_IMETHOD GetBounds(nsIntRect & aBounds) { return _to GetBounds(aBounds); } \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) { return _to SetBounds(aBounds); } \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer * *aPreviousViewer) { return _to GetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) { return _to SetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD Move(int32_t aX, int32_t aY) { return _to Move(aX, aY); } \
  NS_IMETHOD Show(void) { return _to Show(); } \
  NS_IMETHOD Hide(void) { return _to Hide(); } \
  NS_IMETHOD GetSticky(bool *aSticky) { return _to GetSticky(aSticky); } \
  NS_IMETHOD SetSticky(bool aSticky) { return _to SetSticky(aSticky); } \
  NS_IMETHOD RequestWindowClose(bool *_retval) { return _to RequestWindowClose(_retval); } \
  NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) { return _to Open(aState, aSHEntry); } \
  NS_IMETHOD ClearHistoryEntry(void) { return _to ClearHistoryEntry(); } \
  NS_IMETHOD SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings) { return _to SetPageMode(aPageMode, aPrintSettings); } \
  NS_IMETHOD GetHistoryEntry(nsISHEntry * *aHistoryEntry) { return _to GetHistoryEntry(aHistoryEntry); } \
  NS_IMETHOD GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed) { return _to GetIsTabModalPromptAllowed(aIsTabModalPromptAllowed); } \
  NS_IMETHOD GetIsHidden(bool *aIsHidden) { return _to GetIsHidden(aIsHidden); } \
  NS_IMETHOD GetPresShell(nsIPresShell **aPresShell) { return _to GetPresShell(aPresShell); } \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) { return _to GetPresContext(aPresContext); } \
  NS_IMETHOD SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow) { return _to SetDocumentInternal(aDocument, aForceReuseInnerWindow); } \
  virtual nsView * FindContainerView(void) { return _to FindContainerView(); } \
  virtual void SetNavigationTiming(nsDOMNavigationTiming *aTiming) { return _to SetNavigationTiming(aTiming); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWER(_to) \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aParentWidget, aBounds); } \
  NS_IMETHOD GetContainer(nsIDocShell * *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainer(aContainer); } \
  NS_IMETHOD SetContainer(nsIDocShell *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainer(aContainer); } \
  virtual void LoadStart(nsIDocument *aDoc); \
  NS_IMETHOD LoadComplete(nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadComplete(aStatus); } \
  NS_IMETHOD PermitUnload(bool aCallerClosesWindow, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PermitUnload(aCallerClosesWindow, _retval); } \
  virtual nsresult PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PermitUnloadInternal(aCallerClosesWindow, aShouldPrompt, _retval); } \
  NS_IMETHOD GetBeforeUnloadFiring(bool *aBeforeUnloadFiring) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeforeUnloadFiring(aBeforeUnloadFiring); } \
  NS_IMETHOD ResetCloseWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetCloseWindow(); } \
  NS_IMETHOD PageHide(bool isUnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->PageHide(isUnload); } \
  NS_IMETHOD Close(nsISHEntry *historyEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(historyEntry); } \
  NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMDocument(aDOMDocument); } \
  NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDOMDocument(aDOMDocument); } \
  NS_IMETHOD_(nsIDocument *) GetDocument(void); \
  NS_IMETHOD GetBounds(nsIntRect & aBounds) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBounds(aBounds); } \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBounds(aBounds); } \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer * *aPreviousViewer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD Move(int32_t aX, int32_t aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->Move(aX, aY); } \
  NS_IMETHOD Show(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(); } \
  NS_IMETHOD Hide(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Hide(); } \
  NS_IMETHOD GetSticky(bool *aSticky) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSticky(aSticky); } \
  NS_IMETHOD SetSticky(bool aSticky) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSticky(aSticky); } \
  NS_IMETHOD RequestWindowClose(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestWindowClose(_retval); } \
  NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aState, aSHEntry); } \
  NS_IMETHOD ClearHistoryEntry(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearHistoryEntry(); } \
  NS_IMETHOD SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageMode(aPageMode, aPrintSettings); } \
  NS_IMETHOD GetHistoryEntry(nsISHEntry * *aHistoryEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistoryEntry(aHistoryEntry); } \
  NS_IMETHOD GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTabModalPromptAllowed(aIsTabModalPromptAllowed); } \
  NS_IMETHOD GetIsHidden(bool *aIsHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsHidden(aIsHidden); } \
  NS_IMETHOD GetPresShell(nsIPresShell **aPresShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresShell(aPresShell); } \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresContext(aPresContext); } \
  NS_IMETHOD SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentInternal(aDocument, aForceReuseInnerWindow); } \
  virtual nsView * FindContainerView(void); \
  virtual void SetNavigationTiming(nsDOMNavigationTiming *aTiming); 

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

/* attribute nsIDocShell container; */
NS_IMETHODIMP nsContentViewer::GetContainer(nsIDocShell * *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetContainer(nsIDocShell *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void loadStart (in nsIDocument aDoc); */
void nsContentViewer::LoadStart(nsIDocument *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadComplete (in nsresult aStatus); */
NS_IMETHODIMP nsContentViewer::LoadComplete(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean permitUnload ([optional] in boolean aCallerClosesWindow); */
NS_IMETHODIMP nsContentViewer::PermitUnload(bool aCallerClosesWindow, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall] boolean permitUnloadInternal (in boolean aCallerClosesWindow, inout boolean aShouldPrompt); */
nsresult nsContentViewer::PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean beforeUnloadFiring; */
NS_IMETHODIMP nsContentViewer::GetBeforeUnloadFiring(bool *aBeforeUnloadFiring)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetCloseWindow (); */
NS_IMETHODIMP nsContentViewer::ResetCloseWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pageHide (in boolean isUnload); */
NS_IMETHODIMP nsContentViewer::PageHide(bool isUnload)
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
NS_IMETHODIMP nsContentViewer::GetDOMDocument(nsIDOMDocument * *aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetDOMDocument(nsIDOMDocument *aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsIDocument getDocument (); */
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
NS_IMETHODIMP nsContentViewer::GetPreviousViewer(nsIContentViewer * *aPreviousViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetPreviousViewer(nsIContentViewer *aPreviousViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void move (in long aX, in long aY); */
NS_IMETHODIMP nsContentViewer::Move(int32_t aX, int32_t aY)
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
NS_IMETHODIMP nsContentViewer::GetSticky(bool *aSticky)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetSticky(bool aSticky)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean requestWindowClose (); */
NS_IMETHODIMP nsContentViewer::RequestWindowClose(bool *_retval)
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

/* void setPageMode (in boolean aPageMode, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsContentViewer::SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISHEntry historyEntry; */
NS_IMETHODIMP nsContentViewer::GetHistoryEntry(nsISHEntry * *aHistoryEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isTabModalPromptAllowed; */
NS_IMETHODIMP nsContentViewer::GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isHidden; */
NS_IMETHODIMP nsContentViewer::GetIsHidden(bool *aIsHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPresShellPtr presShell; */
NS_IMETHODIMP nsContentViewer::GetPresShell(nsIPresShell **aPresShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsPresContextPtr presContext; */
NS_IMETHODIMP nsContentViewer::GetPresContext(nsPresContext **aPresContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setDocumentInternal (in nsIDocument aDocument, in boolean aForceReuseInnerWindow); */
NS_IMETHODIMP nsContentViewer::SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsViewPtr findContainerView (); */
nsView * nsContentViewer::FindContainerView()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void setNavigationTiming (in nsDOMNavigationTimingPtr aTiming); */
void nsContentViewer::SetNavigationTiming(nsDOMNavigationTiming *aTiming)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentViewer_h__ */
