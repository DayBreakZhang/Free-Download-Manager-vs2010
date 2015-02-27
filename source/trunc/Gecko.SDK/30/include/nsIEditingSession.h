/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEditingSession.idl
 */

#ifndef __gen_nsIEditingSession_h__
#define __gen_nsIEditingSession_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIEditor; /* forward declaration */


/* starting interface:    nsIEditingSession */
#define NS_IEDITINGSESSION_IID_STR "24f3f4da-18a4-448d-876d-7360fefac029"

#define NS_IEDITINGSESSION_IID \
  {0x24f3f4da, 0x18a4, 0x448d, \
    { 0x87, 0x6d, 0x73, 0x60, 0xfe, 0xfa, 0xc0, 0x29 }}

class NS_NO_VTABLE nsIEditingSession : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITINGSESSION_IID)

  enum {
    eEditorOK = 0,
    eEditorCreationInProgress = 1,
    eEditorErrorCantEditMimeType = 2,
    eEditorErrorFileNotFound = 3,
    eEditorErrorCantEditFramesets = 8,
    eEditorErrorUnknown = 9
  };

  /* readonly attribute unsigned long editorStatus; */
  NS_IMETHOD GetEditorStatus(uint32_t *aEditorStatus) = 0;

  /* void makeWindowEditable (in nsIDOMWindow window, in string aEditorType, in boolean doAfterUriLoad, in boolean aMakeWholeDocumentEditable, in boolean aInteractive); */
  NS_IMETHOD MakeWindowEditable(nsIDOMWindow *window, const char * aEditorType, bool doAfterUriLoad, bool aMakeWholeDocumentEditable, bool aInteractive) = 0;

  /* boolean windowIsEditable (in nsIDOMWindow window); */
  NS_IMETHOD WindowIsEditable(nsIDOMWindow *window, bool *_retval) = 0;

  /* nsIEditor getEditorForWindow (in nsIDOMWindow window); */
  NS_IMETHOD GetEditorForWindow(nsIDOMWindow *window, nsIEditor * *_retval) = 0;

  /* void setupEditorOnWindow (in nsIDOMWindow window); */
  NS_IMETHOD SetupEditorOnWindow(nsIDOMWindow *window) = 0;

  /* void tearDownEditorOnWindow (in nsIDOMWindow window); */
  NS_IMETHOD TearDownEditorOnWindow(nsIDOMWindow *window) = 0;

  /* void setEditorOnControllers (in nsIDOMWindow aWindow, in nsIEditor aEditor); */
  NS_IMETHOD SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor) = 0;

  /* void disableJSAndPlugins (in nsIDOMWindow aWindow); */
  NS_IMETHOD DisableJSAndPlugins(nsIDOMWindow *aWindow) = 0;

  /* void restoreJSAndPlugins (in nsIDOMWindow aWindow); */
  NS_IMETHOD RestoreJSAndPlugins(nsIDOMWindow *aWindow) = 0;

  /* void detachFromWindow (in nsIDOMWindow aWindow); */
  NS_IMETHOD DetachFromWindow(nsIDOMWindow *aWindow) = 0;

  /* void reattachToWindow (in nsIDOMWindow aWindow); */
  NS_IMETHOD ReattachToWindow(nsIDOMWindow *aWindow) = 0;

  /* readonly attribute boolean jsAndPluginsDisabled; */
  NS_IMETHOD GetJsAndPluginsDisabled(bool *aJsAndPluginsDisabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditingSession, NS_IEDITINGSESSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITINGSESSION \
  NS_IMETHOD GetEditorStatus(uint32_t *aEditorStatus); \
  NS_IMETHOD MakeWindowEditable(nsIDOMWindow *window, const char * aEditorType, bool doAfterUriLoad, bool aMakeWholeDocumentEditable, bool aInteractive); \
  NS_IMETHOD WindowIsEditable(nsIDOMWindow *window, bool *_retval); \
  NS_IMETHOD GetEditorForWindow(nsIDOMWindow *window, nsIEditor * *_retval); \
  NS_IMETHOD SetupEditorOnWindow(nsIDOMWindow *window); \
  NS_IMETHOD TearDownEditorOnWindow(nsIDOMWindow *window); \
  NS_IMETHOD SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor); \
  NS_IMETHOD DisableJSAndPlugins(nsIDOMWindow *aWindow); \
  NS_IMETHOD RestoreJSAndPlugins(nsIDOMWindow *aWindow); \
  NS_IMETHOD DetachFromWindow(nsIDOMWindow *aWindow); \
  NS_IMETHOD ReattachToWindow(nsIDOMWindow *aWindow); \
  NS_IMETHOD GetJsAndPluginsDisabled(bool *aJsAndPluginsDisabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITINGSESSION(_to) \
  NS_IMETHOD GetEditorStatus(uint32_t *aEditorStatus) { return _to GetEditorStatus(aEditorStatus); } \
  NS_IMETHOD MakeWindowEditable(nsIDOMWindow *window, const char * aEditorType, bool doAfterUriLoad, bool aMakeWholeDocumentEditable, bool aInteractive) { return _to MakeWindowEditable(window, aEditorType, doAfterUriLoad, aMakeWholeDocumentEditable, aInteractive); } \
  NS_IMETHOD WindowIsEditable(nsIDOMWindow *window, bool *_retval) { return _to WindowIsEditable(window, _retval); } \
  NS_IMETHOD GetEditorForWindow(nsIDOMWindow *window, nsIEditor * *_retval) { return _to GetEditorForWindow(window, _retval); } \
  NS_IMETHOD SetupEditorOnWindow(nsIDOMWindow *window) { return _to SetupEditorOnWindow(window); } \
  NS_IMETHOD TearDownEditorOnWindow(nsIDOMWindow *window) { return _to TearDownEditorOnWindow(window); } \
  NS_IMETHOD SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor) { return _to SetEditorOnControllers(aWindow, aEditor); } \
  NS_IMETHOD DisableJSAndPlugins(nsIDOMWindow *aWindow) { return _to DisableJSAndPlugins(aWindow); } \
  NS_IMETHOD RestoreJSAndPlugins(nsIDOMWindow *aWindow) { return _to RestoreJSAndPlugins(aWindow); } \
  NS_IMETHOD DetachFromWindow(nsIDOMWindow *aWindow) { return _to DetachFromWindow(aWindow); } \
  NS_IMETHOD ReattachToWindow(nsIDOMWindow *aWindow) { return _to ReattachToWindow(aWindow); } \
  NS_IMETHOD GetJsAndPluginsDisabled(bool *aJsAndPluginsDisabled) { return _to GetJsAndPluginsDisabled(aJsAndPluginsDisabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITINGSESSION(_to) \
  NS_IMETHOD GetEditorStatus(uint32_t *aEditorStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditorStatus(aEditorStatus); } \
  NS_IMETHOD MakeWindowEditable(nsIDOMWindow *window, const char * aEditorType, bool doAfterUriLoad, bool aMakeWholeDocumentEditable, bool aInteractive) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeWindowEditable(window, aEditorType, doAfterUriLoad, aMakeWholeDocumentEditable, aInteractive); } \
  NS_IMETHOD WindowIsEditable(nsIDOMWindow *window, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowIsEditable(window, _retval); } \
  NS_IMETHOD GetEditorForWindow(nsIDOMWindow *window, nsIEditor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditorForWindow(window, _retval); } \
  NS_IMETHOD SetupEditorOnWindow(nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupEditorOnWindow(window); } \
  NS_IMETHOD TearDownEditorOnWindow(nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->TearDownEditorOnWindow(window); } \
  NS_IMETHOD SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEditorOnControllers(aWindow, aEditor); } \
  NS_IMETHOD DisableJSAndPlugins(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableJSAndPlugins(aWindow); } \
  NS_IMETHOD RestoreJSAndPlugins(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreJSAndPlugins(aWindow); } \
  NS_IMETHOD DetachFromWindow(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->DetachFromWindow(aWindow); } \
  NS_IMETHOD ReattachToWindow(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReattachToWindow(aWindow); } \
  NS_IMETHOD GetJsAndPluginsDisabled(bool *aJsAndPluginsDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJsAndPluginsDisabled(aJsAndPluginsDisabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditingSession : public nsIEditingSession
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITINGSESSION

  nsEditingSession();

private:
  ~nsEditingSession();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditingSession, nsIEditingSession)

nsEditingSession::nsEditingSession()
{
  /* member initializers and constructor code */
}

nsEditingSession::~nsEditingSession()
{
  /* destructor code */
}

/* readonly attribute unsigned long editorStatus; */
NS_IMETHODIMP nsEditingSession::GetEditorStatus(uint32_t *aEditorStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void makeWindowEditable (in nsIDOMWindow window, in string aEditorType, in boolean doAfterUriLoad, in boolean aMakeWholeDocumentEditable, in boolean aInteractive); */
NS_IMETHODIMP nsEditingSession::MakeWindowEditable(nsIDOMWindow *window, const char * aEditorType, bool doAfterUriLoad, bool aMakeWholeDocumentEditable, bool aInteractive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean windowIsEditable (in nsIDOMWindow window); */
NS_IMETHODIMP nsEditingSession::WindowIsEditable(nsIDOMWindow *window, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEditor getEditorForWindow (in nsIDOMWindow window); */
NS_IMETHODIMP nsEditingSession::GetEditorForWindow(nsIDOMWindow *window, nsIEditor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setupEditorOnWindow (in nsIDOMWindow window); */
NS_IMETHODIMP nsEditingSession::SetupEditorOnWindow(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void tearDownEditorOnWindow (in nsIDOMWindow window); */
NS_IMETHODIMP nsEditingSession::TearDownEditorOnWindow(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEditorOnControllers (in nsIDOMWindow aWindow, in nsIEditor aEditor); */
NS_IMETHODIMP nsEditingSession::SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableJSAndPlugins (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsEditingSession::DisableJSAndPlugins(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreJSAndPlugins (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsEditingSession::RestoreJSAndPlugins(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void detachFromWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsEditingSession::DetachFromWindow(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reattachToWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsEditingSession::ReattachToWindow(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean jsAndPluginsDisabled; */
NS_IMETHODIMP nsEditingSession::GetJsAndPluginsDisabled(bool *aJsAndPluginsDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditingSession_h__ */
