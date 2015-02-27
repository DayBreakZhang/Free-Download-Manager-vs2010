/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFrameLoader.idl
 */

#ifndef __gen_nsIFrameLoader_h__
#define __gen_nsIFrameLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsFrameLoader; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIFrame; /* forward declaration */

class nsSubDocumentFrame; /* forward declaration */

class nsIMessageSender; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsITabParent; /* forward declaration */

class nsILoadContext; /* forward declaration */

typedef uint64_t  nsContentViewId;


/* starting interface:    nsIContentView */
#define NS_ICONTENTVIEW_IID_STR "c04c5c40-fa2a-4e9c-94f5-b362a10a86cb"

#define NS_ICONTENTVIEW_IID \
  {0xc04c5c40, 0xfa2a, 0x4e9c, \
    { 0x94, 0xf5, 0xb3, 0x62, 0xa1, 0x0a, 0x86, 0xcb }}

class NS_NO_VTABLE nsIContentView : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEW_IID)

  /* void scrollTo (in float xPx, in float yPx); */
  NS_IMETHOD ScrollTo(float xPx, float yPx) = 0;

  /* void scrollBy (in float dxPx, in float dyPx); */
  NS_IMETHOD ScrollBy(float dxPx, float dyPx) = 0;

  /* void setScale (in float xScale, in float yScale); */
  NS_IMETHOD SetScale(float xScale, float yScale) = 0;

  /* readonly attribute float scrollX; */
  NS_IMETHOD GetScrollX(float *aScrollX) = 0;

  /* readonly attribute float scrollY; */
  NS_IMETHOD GetScrollY(float *aScrollY) = 0;

  /* readonly attribute float viewportWidth; */
  NS_IMETHOD GetViewportWidth(float *aViewportWidth) = 0;

  /* readonly attribute float viewportHeight; */
  NS_IMETHOD GetViewportHeight(float *aViewportHeight) = 0;

  /* readonly attribute float contentWidth; */
  NS_IMETHOD GetContentWidth(float *aContentWidth) = 0;

  /* readonly attribute float contentHeight; */
  NS_IMETHOD GetContentHeight(float *aContentHeight) = 0;

  /* readonly attribute nsContentViewId id; */
  NS_IMETHOD GetId(nsContentViewId *aId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentView, NS_ICONTENTVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEW \
  NS_IMETHOD ScrollTo(float xPx, float yPx); \
  NS_IMETHOD ScrollBy(float dxPx, float dyPx); \
  NS_IMETHOD SetScale(float xScale, float yScale); \
  NS_IMETHOD GetScrollX(float *aScrollX); \
  NS_IMETHOD GetScrollY(float *aScrollY); \
  NS_IMETHOD GetViewportWidth(float *aViewportWidth); \
  NS_IMETHOD GetViewportHeight(float *aViewportHeight); \
  NS_IMETHOD GetContentWidth(float *aContentWidth); \
  NS_IMETHOD GetContentHeight(float *aContentHeight); \
  NS_IMETHOD GetId(nsContentViewId *aId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEW(_to) \
  NS_IMETHOD ScrollTo(float xPx, float yPx) { return _to ScrollTo(xPx, yPx); } \
  NS_IMETHOD ScrollBy(float dxPx, float dyPx) { return _to ScrollBy(dxPx, dyPx); } \
  NS_IMETHOD SetScale(float xScale, float yScale) { return _to SetScale(xScale, yScale); } \
  NS_IMETHOD GetScrollX(float *aScrollX) { return _to GetScrollX(aScrollX); } \
  NS_IMETHOD GetScrollY(float *aScrollY) { return _to GetScrollY(aScrollY); } \
  NS_IMETHOD GetViewportWidth(float *aViewportWidth) { return _to GetViewportWidth(aViewportWidth); } \
  NS_IMETHOD GetViewportHeight(float *aViewportHeight) { return _to GetViewportHeight(aViewportHeight); } \
  NS_IMETHOD GetContentWidth(float *aContentWidth) { return _to GetContentWidth(aContentWidth); } \
  NS_IMETHOD GetContentHeight(float *aContentHeight) { return _to GetContentHeight(aContentHeight); } \
  NS_IMETHOD GetId(nsContentViewId *aId) { return _to GetId(aId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEW(_to) \
  NS_IMETHOD ScrollTo(float xPx, float yPx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollTo(xPx, yPx); } \
  NS_IMETHOD ScrollBy(float dxPx, float dyPx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollBy(dxPx, dyPx); } \
  NS_IMETHOD SetScale(float xScale, float yScale) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScale(xScale, yScale); } \
  NS_IMETHOD GetScrollX(float *aScrollX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollX(aScrollX); } \
  NS_IMETHOD GetScrollY(float *aScrollY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollY(aScrollY); } \
  NS_IMETHOD GetViewportWidth(float *aViewportWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewportWidth(aViewportWidth); } \
  NS_IMETHOD GetViewportHeight(float *aViewportHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewportHeight(aViewportHeight); } \
  NS_IMETHOD GetContentWidth(float *aContentWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentWidth(aContentWidth); } \
  NS_IMETHOD GetContentHeight(float *aContentHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentHeight(aContentHeight); } \
  NS_IMETHOD GetId(nsContentViewId *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentView : public nsIContentView
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEW

  nsContentView();

private:
  ~nsContentView();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentView, nsIContentView)

nsContentView::nsContentView()
{
  /* member initializers and constructor code */
}

nsContentView::~nsContentView()
{
  /* destructor code */
}

/* void scrollTo (in float xPx, in float yPx); */
NS_IMETHODIMP nsContentView::ScrollTo(float xPx, float yPx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollBy (in float dxPx, in float dyPx); */
NS_IMETHODIMP nsContentView::ScrollBy(float dxPx, float dyPx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScale (in float xScale, in float yScale); */
NS_IMETHODIMP nsContentView::SetScale(float xScale, float yScale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float scrollX; */
NS_IMETHODIMP nsContentView::GetScrollX(float *aScrollX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float scrollY; */
NS_IMETHODIMP nsContentView::GetScrollY(float *aScrollY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float viewportWidth; */
NS_IMETHODIMP nsContentView::GetViewportWidth(float *aViewportWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float viewportHeight; */
NS_IMETHODIMP nsContentView::GetViewportHeight(float *aViewportHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float contentWidth; */
NS_IMETHODIMP nsContentView::GetContentWidth(float *aContentWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float contentHeight; */
NS_IMETHODIMP nsContentView::GetContentHeight(float *aContentHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsContentViewId id; */
NS_IMETHODIMP nsContentView::GetId(nsContentViewId *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentViewManager */
#define NS_ICONTENTVIEWMANAGER_IID_STR "ba5af90d-ece5-40b2-9a1d-a0154128db1c"

#define NS_ICONTENTVIEWMANAGER_IID \
  {0xba5af90d, 0xece5, 0x40b2, \
    { 0x9a, 0x1d, 0xa0, 0x15, 0x41, 0x28, 0xdb, 0x1c }}

class NS_NO_VTABLE nsIContentViewManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWMANAGER_IID)

  /* void getContentViewsIn (in float aXPx, in float aYPx, in float aTopSize, in float aRightSize, in float aBottomSize, in float aLeftSize, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out nsIContentView aResult); */
  NS_IMETHOD GetContentViewsIn(float aXPx, float aYPx, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, uint32_t *aLength, nsIContentView * **aResult) = 0;

  /* readonly attribute nsIContentView rootContentView; */
  NS_IMETHOD GetRootContentView(nsIContentView * *aRootContentView) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewManager, NS_ICONTENTVIEWMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWMANAGER \
  NS_IMETHOD GetContentViewsIn(float aXPx, float aYPx, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, uint32_t *aLength, nsIContentView * **aResult); \
  NS_IMETHOD GetRootContentView(nsIContentView * *aRootContentView); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWMANAGER(_to) \
  NS_IMETHOD GetContentViewsIn(float aXPx, float aYPx, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, uint32_t *aLength, nsIContentView * **aResult) { return _to GetContentViewsIn(aXPx, aYPx, aTopSize, aRightSize, aBottomSize, aLeftSize, aLength, aResult); } \
  NS_IMETHOD GetRootContentView(nsIContentView * *aRootContentView) { return _to GetRootContentView(aRootContentView); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWMANAGER(_to) \
  NS_IMETHOD GetContentViewsIn(float aXPx, float aYPx, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, uint32_t *aLength, nsIContentView * **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentViewsIn(aXPx, aYPx, aTopSize, aRightSize, aBottomSize, aLeftSize, aLength, aResult); } \
  NS_IMETHOD GetRootContentView(nsIContentView * *aRootContentView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootContentView(aRootContentView); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentViewManager : public nsIContentViewManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEWMANAGER

  nsContentViewManager();

private:
  ~nsContentViewManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentViewManager, nsIContentViewManager)

nsContentViewManager::nsContentViewManager()
{
  /* member initializers and constructor code */
}

nsContentViewManager::~nsContentViewManager()
{
  /* destructor code */
}

/* void getContentViewsIn (in float aXPx, in float aYPx, in float aTopSize, in float aRightSize, in float aBottomSize, in float aLeftSize, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out nsIContentView aResult); */
NS_IMETHODIMP nsContentViewManager::GetContentViewsIn(float aXPx, float aYPx, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, uint32_t *aLength, nsIContentView * **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIContentView rootContentView; */
NS_IMETHODIMP nsContentViewManager::GetRootContentView(nsIContentView * *aRootContentView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFrameLoader */
#define NS_IFRAMELOADER_IID_STR "a5cefcc8-551b-4901-83f3-7436b09ecaba"

#define NS_IFRAMELOADER_IID \
  {0xa5cefcc8, 0x551b, 0x4901, \
    { 0x83, 0xf3, 0x74, 0x36, 0xb0, 0x9e, 0xca, 0xba }}

class NS_NO_VTABLE nsIFrameLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMELOADER_IID)

  /* readonly attribute nsIDocShell docShell; */
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

  /* readonly attribute nsITabParent tabParent; */
  NS_IMETHOD GetTabParent(nsITabParent * *aTabParent) = 0;

  /* readonly attribute nsILoadContext loadContext; */
  NS_IMETHOD GetLoadContext(nsILoadContext * *aLoadContext) = 0;

  /* void loadFrame (); */
  NS_IMETHOD LoadFrame(void) = 0;

  /* void loadURI (in nsIURI aURI); */
  NS_IMETHOD LoadURI(nsIURI *aURI) = 0;

  /* void destroy (); */
  NS_IMETHOD Destroy(void) = 0;

  /* readonly attribute boolean depthTooGreat; */
  NS_IMETHOD GetDepthTooGreat(bool *aDepthTooGreat) = 0;

  /* [noscript] void updatePositionAndSize (in nsSubDocumentFrame aIFrame); */
  NS_IMETHOD UpdatePositionAndSize(nsSubDocumentFrame *aIFrame) = 0;

  /* void activateRemoteFrame (); */
  NS_IMETHOD ActivateRemoteFrame(void) = 0;

  /* void deactivateRemoteFrame (); */
  NS_IMETHOD DeactivateRemoteFrame(void) = 0;

  /* void sendCrossProcessMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_IMETHOD SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame) = 0;

  /* void activateFrameEvent (in AString aType, in boolean capture); */
  NS_IMETHOD ActivateFrameEvent(const nsAString & aType, bool capture) = 0;

  /* readonly attribute nsIMessageSender messageManager; */
  NS_IMETHOD GetMessageManager(nsIMessageSender * *aMessageManager) = 0;

  /* void sendCrossProcessKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in boolean aPreventDefault); */
  NS_IMETHOD SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault) = 0;

  enum {
    RENDER_MODE_DEFAULT = 0U,
    RENDER_MODE_ASYNC_SCROLL = 1U
  };

  /* attribute unsigned long renderMode; */
  NS_IMETHOD GetRenderMode(uint32_t *aRenderMode) = 0;
  NS_IMETHOD SetRenderMode(uint32_t aRenderMode) = 0;

  enum {
    EVENT_MODE_NORMAL_DISPATCH = 0U,
    EVENT_MODE_DONT_FORWARD_TO_CHILD = 1U
  };

  /* attribute unsigned long eventMode; */
  NS_IMETHOD GetEventMode(uint32_t *aEventMode) = 0;
  NS_IMETHOD SetEventMode(uint32_t aEventMode) = 0;

  /* attribute boolean clipSubdocument; */
  NS_IMETHOD GetClipSubdocument(bool *aClipSubdocument) = 0;
  NS_IMETHOD SetClipSubdocument(bool aClipSubdocument) = 0;

  /* attribute boolean clampScrollPosition; */
  NS_IMETHOD GetClampScrollPosition(bool *aClampScrollPosition) = 0;
  NS_IMETHOD SetClampScrollPosition(bool aClampScrollPosition) = 0;

  /* readonly attribute nsIDOMElement ownerElement; */
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) = 0;

  /* readonly attribute unsigned long long childID; */
  NS_IMETHOD GetChildID(uint64_t *aChildID) = 0;

  /* [infallible] attribute boolean visible; */
  NS_IMETHOD GetVisible(bool *aVisible) = 0;
  inline bool GetVisible()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetVisible(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetVisible(bool aVisible) = 0;

  /* readonly attribute boolean ownerIsBrowserOrAppFrame; */
  NS_IMETHOD GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameLoader, NS_IFRAMELOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMELOADER \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell); \
  NS_IMETHOD GetTabParent(nsITabParent * *aTabParent); \
  NS_IMETHOD GetLoadContext(nsILoadContext * *aLoadContext); \
  NS_IMETHOD LoadFrame(void); \
  NS_IMETHOD LoadURI(nsIURI *aURI); \
  NS_IMETHOD Destroy(void); \
  NS_IMETHOD GetDepthTooGreat(bool *aDepthTooGreat); \
  NS_IMETHOD UpdatePositionAndSize(nsSubDocumentFrame *aIFrame); \
  NS_IMETHOD ActivateRemoteFrame(void); \
  NS_IMETHOD DeactivateRemoteFrame(void); \
  NS_IMETHOD SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame); \
  NS_IMETHOD ActivateFrameEvent(const nsAString & aType, bool capture); \
  NS_IMETHOD GetMessageManager(nsIMessageSender * *aMessageManager); \
  NS_IMETHOD SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault); \
  NS_IMETHOD GetRenderMode(uint32_t *aRenderMode); \
  NS_IMETHOD SetRenderMode(uint32_t aRenderMode); \
  NS_IMETHOD GetEventMode(uint32_t *aEventMode); \
  NS_IMETHOD SetEventMode(uint32_t aEventMode); \
  NS_IMETHOD GetClipSubdocument(bool *aClipSubdocument); \
  NS_IMETHOD SetClipSubdocument(bool aClipSubdocument); \
  NS_IMETHOD GetClampScrollPosition(bool *aClampScrollPosition); \
  NS_IMETHOD SetClampScrollPosition(bool aClampScrollPosition); \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement); \
  NS_IMETHOD GetChildID(uint64_t *aChildID); \
  NS_IMETHOD GetVisible(bool *aVisible); \
  NS_IMETHOD SetVisible(bool aVisible); \
  NS_IMETHOD GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMELOADER(_to) \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return _to GetDocShell(aDocShell); } \
  NS_IMETHOD GetTabParent(nsITabParent * *aTabParent) { return _to GetTabParent(aTabParent); } \
  NS_IMETHOD GetLoadContext(nsILoadContext * *aLoadContext) { return _to GetLoadContext(aLoadContext); } \
  NS_IMETHOD LoadFrame(void) { return _to LoadFrame(); } \
  NS_IMETHOD LoadURI(nsIURI *aURI) { return _to LoadURI(aURI); } \
  NS_IMETHOD Destroy(void) { return _to Destroy(); } \
  NS_IMETHOD GetDepthTooGreat(bool *aDepthTooGreat) { return _to GetDepthTooGreat(aDepthTooGreat); } \
  NS_IMETHOD UpdatePositionAndSize(nsSubDocumentFrame *aIFrame) { return _to UpdatePositionAndSize(aIFrame); } \
  NS_IMETHOD ActivateRemoteFrame(void) { return _to ActivateRemoteFrame(); } \
  NS_IMETHOD DeactivateRemoteFrame(void) { return _to DeactivateRemoteFrame(); } \
  NS_IMETHOD SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame) { return _to SendCrossProcessMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_IMETHOD ActivateFrameEvent(const nsAString & aType, bool capture) { return _to ActivateFrameEvent(aType, capture); } \
  NS_IMETHOD GetMessageManager(nsIMessageSender * *aMessageManager) { return _to GetMessageManager(aMessageManager); } \
  NS_IMETHOD SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault) { return _to SendCrossProcessKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aPreventDefault); } \
  NS_IMETHOD GetRenderMode(uint32_t *aRenderMode) { return _to GetRenderMode(aRenderMode); } \
  NS_IMETHOD SetRenderMode(uint32_t aRenderMode) { return _to SetRenderMode(aRenderMode); } \
  NS_IMETHOD GetEventMode(uint32_t *aEventMode) { return _to GetEventMode(aEventMode); } \
  NS_IMETHOD SetEventMode(uint32_t aEventMode) { return _to SetEventMode(aEventMode); } \
  NS_IMETHOD GetClipSubdocument(bool *aClipSubdocument) { return _to GetClipSubdocument(aClipSubdocument); } \
  NS_IMETHOD SetClipSubdocument(bool aClipSubdocument) { return _to SetClipSubdocument(aClipSubdocument); } \
  NS_IMETHOD GetClampScrollPosition(bool *aClampScrollPosition) { return _to GetClampScrollPosition(aClampScrollPosition); } \
  NS_IMETHOD SetClampScrollPosition(bool aClampScrollPosition) { return _to SetClampScrollPosition(aClampScrollPosition); } \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) { return _to GetOwnerElement(aOwnerElement); } \
  NS_IMETHOD GetChildID(uint64_t *aChildID) { return _to GetChildID(aChildID); } \
  NS_IMETHOD GetVisible(bool *aVisible) { return _to GetVisible(aVisible); } \
  NS_IMETHOD SetVisible(bool aVisible) { return _to SetVisible(aVisible); } \
  NS_IMETHOD GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame) { return _to GetOwnerIsBrowserOrAppFrame(aOwnerIsBrowserOrAppFrame); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMELOADER(_to) \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } \
  NS_IMETHOD GetTabParent(nsITabParent * *aTabParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabParent(aTabParent); } \
  NS_IMETHOD GetLoadContext(nsILoadContext * *aLoadContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadContext(aLoadContext); } \
  NS_IMETHOD LoadFrame(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadFrame(); } \
  NS_IMETHOD LoadURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(aURI); } \
  NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_IMETHOD GetDepthTooGreat(bool *aDepthTooGreat) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDepthTooGreat(aDepthTooGreat); } \
  NS_IMETHOD UpdatePositionAndSize(nsSubDocumentFrame *aIFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdatePositionAndSize(aIFrame); } \
  NS_IMETHOD ActivateRemoteFrame(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateRemoteFrame(); } \
  NS_IMETHOD DeactivateRemoteFrame(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeactivateRemoteFrame(); } \
  NS_IMETHOD SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCrossProcessMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_IMETHOD ActivateFrameEvent(const nsAString & aType, bool capture) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateFrameEvent(aType, capture); } \
  NS_IMETHOD GetMessageManager(nsIMessageSender * *aMessageManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageManager(aMessageManager); } \
  NS_IMETHOD SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCrossProcessKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aPreventDefault); } \
  NS_IMETHOD GetRenderMode(uint32_t *aRenderMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRenderMode(aRenderMode); } \
  NS_IMETHOD SetRenderMode(uint32_t aRenderMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRenderMode(aRenderMode); } \
  NS_IMETHOD GetEventMode(uint32_t *aEventMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventMode(aEventMode); } \
  NS_IMETHOD SetEventMode(uint32_t aEventMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEventMode(aEventMode); } \
  NS_IMETHOD GetClipSubdocument(bool *aClipSubdocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClipSubdocument(aClipSubdocument); } \
  NS_IMETHOD SetClipSubdocument(bool aClipSubdocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClipSubdocument(aClipSubdocument); } \
  NS_IMETHOD GetClampScrollPosition(bool *aClampScrollPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClampScrollPosition(aClampScrollPosition); } \
  NS_IMETHOD SetClampScrollPosition(bool aClampScrollPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClampScrollPosition(aClampScrollPosition); } \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerElement(aOwnerElement); } \
  NS_IMETHOD GetChildID(uint64_t *aChildID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildID(aChildID); } \
  NS_IMETHOD GetVisible(bool *aVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisible(aVisible); } \
  NS_IMETHOD SetVisible(bool aVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisible(aVisible); } \
  NS_IMETHOD GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerIsBrowserOrAppFrame(aOwnerIsBrowserOrAppFrame); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameLoader : public nsIFrameLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMELOADER

  nsFrameLoader();

private:
  ~nsFrameLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFrameLoader, nsIFrameLoader)

nsFrameLoader::nsFrameLoader()
{
  /* member initializers and constructor code */
}

nsFrameLoader::~nsFrameLoader()
{
  /* destructor code */
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsFrameLoader::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsITabParent tabParent; */
NS_IMETHODIMP nsFrameLoader::GetTabParent(nsITabParent * *aTabParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILoadContext loadContext; */
NS_IMETHODIMP nsFrameLoader::GetLoadContext(nsILoadContext * *aLoadContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadFrame (); */
NS_IMETHODIMP nsFrameLoader::LoadFrame()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadURI (in nsIURI aURI); */
NS_IMETHODIMP nsFrameLoader::LoadURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroy (); */
NS_IMETHODIMP nsFrameLoader::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean depthTooGreat; */
NS_IMETHODIMP nsFrameLoader::GetDepthTooGreat(bool *aDepthTooGreat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void updatePositionAndSize (in nsSubDocumentFrame aIFrame); */
NS_IMETHODIMP nsFrameLoader::UpdatePositionAndSize(nsSubDocumentFrame *aIFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateRemoteFrame (); */
NS_IMETHODIMP nsFrameLoader::ActivateRemoteFrame()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deactivateRemoteFrame (); */
NS_IMETHODIMP nsFrameLoader::DeactivateRemoteFrame()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendCrossProcessMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsFrameLoader::SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateFrameEvent (in AString aType, in boolean capture); */
NS_IMETHODIMP nsFrameLoader::ActivateFrameEvent(const nsAString & aType, bool capture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMessageSender messageManager; */
NS_IMETHODIMP nsFrameLoader::GetMessageManager(nsIMessageSender * *aMessageManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendCrossProcessKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in boolean aPreventDefault); */
NS_IMETHODIMP nsFrameLoader::SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long renderMode; */
NS_IMETHODIMP nsFrameLoader::GetRenderMode(uint32_t *aRenderMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetRenderMode(uint32_t aRenderMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long eventMode; */
NS_IMETHODIMP nsFrameLoader::GetEventMode(uint32_t *aEventMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetEventMode(uint32_t aEventMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean clipSubdocument; */
NS_IMETHODIMP nsFrameLoader::GetClipSubdocument(bool *aClipSubdocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetClipSubdocument(bool aClipSubdocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean clampScrollPosition; */
NS_IMETHODIMP nsFrameLoader::GetClampScrollPosition(bool *aClampScrollPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetClampScrollPosition(bool aClampScrollPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement ownerElement; */
NS_IMETHODIMP nsFrameLoader::GetOwnerElement(nsIDOMElement * *aOwnerElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long childID; */
NS_IMETHODIMP nsFrameLoader::GetChildID(uint64_t *aChildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] attribute boolean visible; */
NS_IMETHODIMP nsFrameLoader::GetVisible(bool *aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetVisible(bool aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ownerIsBrowserOrAppFrame; */
NS_IMETHODIMP nsFrameLoader::GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsFrameLoader;

/* starting interface:    nsIFrameLoaderOwner */
#define NS_IFRAMELOADEROWNER_IID_STR "5879040e-83e9-40e3-b2bb-5ddf43b76e47"

#define NS_IFRAMELOADEROWNER_IID \
  {0x5879040e, 0x83e9, 0x40e3, \
    { 0xb2, 0xbb, 0x5d, 0xdf, 0x43, 0xb7, 0x6e, 0x47 }}

class NS_NO_VTABLE nsIFrameLoaderOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMELOADEROWNER_IID)

  /* readonly attribute nsIFrameLoader frameLoader; */
  NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) = 0;

  /* [noscript,notxpcom] alreadyAddRefed_nsFrameLoader GetFrameLoader (); */
  NS_IMETHOD_(already_AddRefed<nsFrameLoader>) GetFrameLoader(void) = 0;

  /* void swapFrameLoaders (in nsIFrameLoaderOwner aOtherOwner); */
  NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameLoaderOwner, NS_IFRAMELOADEROWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMELOADEROWNER \
  NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader); \
  NS_IMETHOD_(already_AddRefed<nsFrameLoader>) GetFrameLoader(void); \
  NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMELOADEROWNER(_to) \
  NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) { return _to GetFrameLoader(aFrameLoader); } \
  NS_IMETHOD_(already_AddRefed<nsFrameLoader>) GetFrameLoader(void) { return _to GetFrameLoader(); } \
  NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) { return _to SwapFrameLoaders(aOtherOwner); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMELOADEROWNER(_to) \
  NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameLoader(aFrameLoader); } \
  NS_IMETHOD_(already_AddRefed<nsFrameLoader>) GetFrameLoader(void); \
  NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwapFrameLoaders(aOtherOwner); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameLoaderOwner : public nsIFrameLoaderOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMELOADEROWNER

  nsFrameLoaderOwner();

private:
  ~nsFrameLoaderOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFrameLoaderOwner, nsIFrameLoaderOwner)

nsFrameLoaderOwner::nsFrameLoaderOwner()
{
  /* member initializers and constructor code */
}

nsFrameLoaderOwner::~nsFrameLoaderOwner()
{
  /* destructor code */
}

/* readonly attribute nsIFrameLoader frameLoader; */
NS_IMETHODIMP nsFrameLoaderOwner::GetFrameLoader(nsIFrameLoader * *aFrameLoader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] alreadyAddRefed_nsFrameLoader GetFrameLoader (); */
NS_IMETHODIMP_(already_AddRefed<nsFrameLoader>) nsFrameLoaderOwner::GetFrameLoader()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void swapFrameLoaders (in nsIFrameLoaderOwner aOtherOwner); */
NS_IMETHODIMP nsFrameLoaderOwner::SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFrameLoader_h__ */
