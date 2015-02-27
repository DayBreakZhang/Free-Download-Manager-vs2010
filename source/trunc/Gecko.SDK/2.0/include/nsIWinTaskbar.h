/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsIWinTaskbar.idl
 */

#ifndef __gen_nsIWinTaskbar_h__
#define __gen_nsIWinTaskbar_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIBaseWindow_h__
#include "nsIBaseWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsITaskbarTabPreview; /* forward declaration */

class nsITaskbarWindowPreview; /* forward declaration */

class nsITaskbarPreviewController; /* forward declaration */

class nsITaskbarProgress; /* forward declaration */

class nsIJumpListBuilder; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIWinTaskbar */
#define NS_IWINTASKBAR_IID_STR "a25ad3ed-1ded-4473-bb6e-bf8b89d88949"

#define NS_IWINTASKBAR_IID \
  {0xa25ad3ed, 0x1ded, 0x4473, \
    { 0xbb, 0x6e, 0xbf, 0x8b, 0x89, 0xd8, 0x89, 0x49 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWinTaskbar : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINTASKBAR_IID)

  /**
   * Returns true if the operating system supports Win7+ taskbar features.
   * This property acts as a replacement for in-place os version checking.
   */
  /* readonly attribute boolean available; */
  NS_SCRIPTABLE NS_IMETHOD GetAvailable(PRBool *aAvailable) = 0;

  /**
   * Returns the default application user model identity the application
   * registers with the system. This id is used by the taskbar in grouping
   * windows and in associating pinned shortcuts with running instances and
   * jump lists.
   */
  /* readonly attribute AString defaultGroupId; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultGroupId(nsAString & aDefaultGroupId) = 0;

  /**
   * Taskbar window and tab preview management
   */
/**
   * Creates a taskbar preview. The docshell should be a toplevel docshell and
   * is used to find the toplevel window. See the documentation for
   * nsITaskbarTabPreview for more information.
   */
  /* nsITaskbarTabPreview createTaskbarTabPreview (in nsIDocShell shell, in nsITaskbarPreviewController controller); */
  NS_SCRIPTABLE NS_IMETHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview **_retval NS_OUTPARAM) = 0;

  /**
   * Gets the taskbar preview for a window. The docshell is used to find the
   * toplevel window. See the documentation for nsITaskbarTabPreview for more
   * information.
   *
   * Note: to implement custom drawing or buttons, a controller is required.
   */
  /* nsITaskbarWindowPreview getTaskbarWindowPreview (in nsIDocShell shell); */
  NS_SCRIPTABLE NS_IMETHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview **_retval NS_OUTPARAM) = 0;

  /**
   * Taskbar icon progress indicator
   */
/**
   * Gets the taskbar progress for a window. The docshell is used to find the
   * toplevel window. See the documentation for nsITaskbarProgress for more
   * information.
   */
  /* nsITaskbarProgress getTaskbarProgress (in nsIDocShell shell); */
  NS_SCRIPTABLE NS_IMETHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress **_retval NS_OUTPARAM) = 0;

  /**
   * Taskbar and start menu jump list management
   */
/**
   * Retrieve a taskbar jump list builder
   *
   * Fails if a jump list build operation has already been initiated, developers
   * should make use of a single instance of nsIJumpListBuilder for building lists
   * within an application.
   *
   * @thow NS_ERROR_ALREADY_INITIALIZED if an nsIJumpListBuilder instance is
   * currently building a list.
   */
  /* nsIJumpListBuilder createJumpListBuilder (); */
  NS_SCRIPTABLE NS_IMETHOD CreateJumpListBuilder(nsIJumpListBuilder **_retval NS_OUTPARAM) = 0;

  /**
   * Application window taskbar group settings
   */
/**
   * Set the grouping id for a window.
   *
   * The runtime sets a default, global grouping id for all windows on startup.
   * setGroupIdForWindow allows individual windows to be grouped independently
   * on the taskbar. Ids should be unique to the app and window to insure
   * conflicts with other pinned applications do no arise.
   *
   * The default group id is based on application.ini vendor, application, and
   * version values, with a format of 'vendor.app.version'. The default can be
   * retrieved via defaultGroupId.
   *
   * Note, when a window changes taskbar window stacks, it is placed at the
   * bottom of the new stack.
   *
   * @thow NS_ERROR_INVALID_ARG if the window is not a valid top level window
   * associated with a widget.
   * @thow NS_ERROR_FAILURE if the property on the window could not be set.
   * @thow NS_ERROR_UNEXPECTED for general failures.
   */
  /* void setGroupIdForWindow (in nsIDOMWindow aParent, in AString aIdentifier); */
  NS_SCRIPTABLE NS_IMETHOD SetGroupIdForWindow(nsIDOMWindow *aParent, const nsAString & aIdentifier) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWinTaskbar, NS_IWINTASKBAR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINTASKBAR \
  NS_SCRIPTABLE NS_IMETHOD GetAvailable(PRBool *aAvailable); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultGroupId(nsAString & aDefaultGroupId); \
  NS_SCRIPTABLE NS_IMETHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateJumpListBuilder(nsIJumpListBuilder **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetGroupIdForWindow(nsIDOMWindow *aParent, const nsAString & aIdentifier); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINTASKBAR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAvailable(PRBool *aAvailable) { return _to GetAvailable(aAvailable); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultGroupId(nsAString & aDefaultGroupId) { return _to GetDefaultGroupId(aDefaultGroupId); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview **_retval NS_OUTPARAM) { return _to CreateTaskbarTabPreview(shell, controller, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview **_retval NS_OUTPARAM) { return _to GetTaskbarWindowPreview(shell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress **_retval NS_OUTPARAM) { return _to GetTaskbarProgress(shell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateJumpListBuilder(nsIJumpListBuilder **_retval NS_OUTPARAM) { return _to CreateJumpListBuilder(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetGroupIdForWindow(nsIDOMWindow *aParent, const nsAString & aIdentifier) { return _to SetGroupIdForWindow(aParent, aIdentifier); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINTASKBAR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAvailable(PRBool *aAvailable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailable(aAvailable); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultGroupId(nsAString & aDefaultGroupId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultGroupId(aDefaultGroupId); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTaskbarTabPreview(shell, controller, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTaskbarWindowPreview(shell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTaskbarProgress(shell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateJumpListBuilder(nsIJumpListBuilder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateJumpListBuilder(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetGroupIdForWindow(nsIDOMWindow *aParent, const nsAString & aIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGroupIdForWindow(aParent, aIdentifier); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWinTaskbar : public nsIWinTaskbar
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINTASKBAR

  nsWinTaskbar();

private:
  ~nsWinTaskbar();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWinTaskbar, nsIWinTaskbar)

nsWinTaskbar::nsWinTaskbar()
{
  /* member initializers and constructor code */
}

nsWinTaskbar::~nsWinTaskbar()
{
  /* destructor code */
}

/* readonly attribute boolean available; */
NS_IMETHODIMP nsWinTaskbar::GetAvailable(PRBool *aAvailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString defaultGroupId; */
NS_IMETHODIMP nsWinTaskbar::GetDefaultGroupId(nsAString & aDefaultGroupId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITaskbarTabPreview createTaskbarTabPreview (in nsIDocShell shell, in nsITaskbarPreviewController controller); */
NS_IMETHODIMP nsWinTaskbar::CreateTaskbarTabPreview(nsIDocShell *shell, nsITaskbarPreviewController *controller, nsITaskbarTabPreview **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITaskbarWindowPreview getTaskbarWindowPreview (in nsIDocShell shell); */
NS_IMETHODIMP nsWinTaskbar::GetTaskbarWindowPreview(nsIDocShell *shell, nsITaskbarWindowPreview **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITaskbarProgress getTaskbarProgress (in nsIDocShell shell); */
NS_IMETHODIMP nsWinTaskbar::GetTaskbarProgress(nsIDocShell *shell, nsITaskbarProgress **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIJumpListBuilder createJumpListBuilder (); */
NS_IMETHODIMP nsWinTaskbar::CreateJumpListBuilder(nsIJumpListBuilder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setGroupIdForWindow (in nsIDOMWindow aParent, in AString aIdentifier); */
NS_IMETHODIMP nsWinTaskbar::SetGroupIdForWindow(nsIDOMWindow *aParent, const nsAString & aIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWinTaskbar_h__ */
