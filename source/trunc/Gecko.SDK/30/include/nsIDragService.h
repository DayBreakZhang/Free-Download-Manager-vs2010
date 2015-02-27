/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDragService.idl
 */

#ifndef __gen_nsIDragService_h__
#define __gen_nsIDragService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISupportsArray_h__
#include "nsISupportsArray.h"
#endif

#ifndef __gen_nsIDragSession_h__
#include "nsIDragSession.h"
#endif

#ifndef __gen_nsIScriptableRegion_h__
#include "nsIScriptableRegion.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIDOMDragEvent; /* forward declaration */

class nsIDOMDataTransfer; /* forward declaration */

class nsISelection; /* forward declaration */


/* starting interface:    nsIDragService */
#define NS_IDRAGSERVICE_IID_STR "82b58ada-f490-4c3d-b737-1057c4f1d052"

#define NS_IDRAGSERVICE_IID \
  {0x82b58ada, 0xf490, 0x4c3d, \
    { 0xb7, 0x37, 0x10, 0x57, 0xc4, 0xf1, 0xd0, 0x52 }}

class NS_NO_VTABLE nsIDragService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDRAGSERVICE_IID)

  enum {
    DRAGDROP_ACTION_NONE = 0,
    DRAGDROP_ACTION_COPY = 1,
    DRAGDROP_ACTION_MOVE = 2,
    DRAGDROP_ACTION_LINK = 4,
    DRAGDROP_ACTION_UNINITIALIZED = 64
  };

  /* void invokeDragSession (in nsIDOMNode aDOMNode, in nsISupportsArray aTransferables, in nsIScriptableRegion aRegion, in unsigned long aActionType); */
  NS_IMETHOD InvokeDragSession(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferables, nsIScriptableRegion *aRegion, uint32_t aActionType) = 0;

  /* void invokeDragSessionWithImage (in nsIDOMNode aDOMNode, in nsISupportsArray aTransferableArray, in nsIScriptableRegion aRegion, in unsigned long aActionType, in nsIDOMNode aImage, in long aImageX, in long aImageY, in nsIDOMDragEvent aDragEvent, in nsIDOMDataTransfer aDataTransfer); */
  NS_IMETHOD InvokeDragSessionWithImage(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferableArray, nsIScriptableRegion *aRegion, uint32_t aActionType, nsIDOMNode *aImage, int32_t aImageX, int32_t aImageY, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer) = 0;

  /* void invokeDragSessionWithSelection (in nsISelection aSelection, in nsISupportsArray aTransferableArray, in unsigned long aActionType, in nsIDOMDragEvent aDragEvent, in nsIDOMDataTransfer aDataTransfer); */
  NS_IMETHOD InvokeDragSessionWithSelection(nsISelection *aSelection, nsISupportsArray *aTransferableArray, uint32_t aActionType, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer) = 0;

  /* nsIDragSession getCurrentSession (); */
  NS_IMETHOD GetCurrentSession(nsIDragSession * *_retval) = 0;

  /* void startDragSession (); */
  NS_IMETHOD StartDragSession(void) = 0;

  /* void endDragSession (in boolean aDoneDrag); */
  NS_IMETHOD EndDragSession(bool aDoneDrag) = 0;

  /* void fireDragEventAtSource (in unsigned long aMsg); */
  NS_IMETHOD FireDragEventAtSource(uint32_t aMsg) = 0;

  /* void suppress (); */
  NS_IMETHOD Suppress(void) = 0;

  /* void unsuppress (); */
  NS_IMETHOD Unsuppress(void) = 0;

  /* [noscript] void dragMoved (in long aX, in long aY); */
  NS_IMETHOD DragMoved(int32_t aX, int32_t aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDragService, NS_IDRAGSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDRAGSERVICE \
  NS_IMETHOD InvokeDragSession(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferables, nsIScriptableRegion *aRegion, uint32_t aActionType); \
  NS_IMETHOD InvokeDragSessionWithImage(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferableArray, nsIScriptableRegion *aRegion, uint32_t aActionType, nsIDOMNode *aImage, int32_t aImageX, int32_t aImageY, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer); \
  NS_IMETHOD InvokeDragSessionWithSelection(nsISelection *aSelection, nsISupportsArray *aTransferableArray, uint32_t aActionType, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer); \
  NS_IMETHOD GetCurrentSession(nsIDragSession * *_retval); \
  NS_IMETHOD StartDragSession(void); \
  NS_IMETHOD EndDragSession(bool aDoneDrag); \
  NS_IMETHOD FireDragEventAtSource(uint32_t aMsg); \
  NS_IMETHOD Suppress(void); \
  NS_IMETHOD Unsuppress(void); \
  NS_IMETHOD DragMoved(int32_t aX, int32_t aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDRAGSERVICE(_to) \
  NS_IMETHOD InvokeDragSession(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferables, nsIScriptableRegion *aRegion, uint32_t aActionType) { return _to InvokeDragSession(aDOMNode, aTransferables, aRegion, aActionType); } \
  NS_IMETHOD InvokeDragSessionWithImage(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferableArray, nsIScriptableRegion *aRegion, uint32_t aActionType, nsIDOMNode *aImage, int32_t aImageX, int32_t aImageY, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer) { return _to InvokeDragSessionWithImage(aDOMNode, aTransferableArray, aRegion, aActionType, aImage, aImageX, aImageY, aDragEvent, aDataTransfer); } \
  NS_IMETHOD InvokeDragSessionWithSelection(nsISelection *aSelection, nsISupportsArray *aTransferableArray, uint32_t aActionType, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer) { return _to InvokeDragSessionWithSelection(aSelection, aTransferableArray, aActionType, aDragEvent, aDataTransfer); } \
  NS_IMETHOD GetCurrentSession(nsIDragSession * *_retval) { return _to GetCurrentSession(_retval); } \
  NS_IMETHOD StartDragSession(void) { return _to StartDragSession(); } \
  NS_IMETHOD EndDragSession(bool aDoneDrag) { return _to EndDragSession(aDoneDrag); } \
  NS_IMETHOD FireDragEventAtSource(uint32_t aMsg) { return _to FireDragEventAtSource(aMsg); } \
  NS_IMETHOD Suppress(void) { return _to Suppress(); } \
  NS_IMETHOD Unsuppress(void) { return _to Unsuppress(); } \
  NS_IMETHOD DragMoved(int32_t aX, int32_t aY) { return _to DragMoved(aX, aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDRAGSERVICE(_to) \
  NS_IMETHOD InvokeDragSession(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferables, nsIScriptableRegion *aRegion, uint32_t aActionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvokeDragSession(aDOMNode, aTransferables, aRegion, aActionType); } \
  NS_IMETHOD InvokeDragSessionWithImage(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferableArray, nsIScriptableRegion *aRegion, uint32_t aActionType, nsIDOMNode *aImage, int32_t aImageX, int32_t aImageY, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvokeDragSessionWithImage(aDOMNode, aTransferableArray, aRegion, aActionType, aImage, aImageX, aImageY, aDragEvent, aDataTransfer); } \
  NS_IMETHOD InvokeDragSessionWithSelection(nsISelection *aSelection, nsISupportsArray *aTransferableArray, uint32_t aActionType, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvokeDragSessionWithSelection(aSelection, aTransferableArray, aActionType, aDragEvent, aDataTransfer); } \
  NS_IMETHOD GetCurrentSession(nsIDragSession * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentSession(_retval); } \
  NS_IMETHOD StartDragSession(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDragSession(); } \
  NS_IMETHOD EndDragSession(bool aDoneDrag) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndDragSession(aDoneDrag); } \
  NS_IMETHOD FireDragEventAtSource(uint32_t aMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireDragEventAtSource(aMsg); } \
  NS_IMETHOD Suppress(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Suppress(); } \
  NS_IMETHOD Unsuppress(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unsuppress(); } \
  NS_IMETHOD DragMoved(int32_t aX, int32_t aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->DragMoved(aX, aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDragService : public nsIDragService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDRAGSERVICE

  nsDragService();

private:
  ~nsDragService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDragService, nsIDragService)

nsDragService::nsDragService()
{
  /* member initializers and constructor code */
}

nsDragService::~nsDragService()
{
  /* destructor code */
}

/* void invokeDragSession (in nsIDOMNode aDOMNode, in nsISupportsArray aTransferables, in nsIScriptableRegion aRegion, in unsigned long aActionType); */
NS_IMETHODIMP nsDragService::InvokeDragSession(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferables, nsIScriptableRegion *aRegion, uint32_t aActionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invokeDragSessionWithImage (in nsIDOMNode aDOMNode, in nsISupportsArray aTransferableArray, in nsIScriptableRegion aRegion, in unsigned long aActionType, in nsIDOMNode aImage, in long aImageX, in long aImageY, in nsIDOMDragEvent aDragEvent, in nsIDOMDataTransfer aDataTransfer); */
NS_IMETHODIMP nsDragService::InvokeDragSessionWithImage(nsIDOMNode *aDOMNode, nsISupportsArray *aTransferableArray, nsIScriptableRegion *aRegion, uint32_t aActionType, nsIDOMNode *aImage, int32_t aImageX, int32_t aImageY, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invokeDragSessionWithSelection (in nsISelection aSelection, in nsISupportsArray aTransferableArray, in unsigned long aActionType, in nsIDOMDragEvent aDragEvent, in nsIDOMDataTransfer aDataTransfer); */
NS_IMETHODIMP nsDragService::InvokeDragSessionWithSelection(nsISelection *aSelection, nsISupportsArray *aTransferableArray, uint32_t aActionType, nsIDOMDragEvent *aDragEvent, nsIDOMDataTransfer *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDragSession getCurrentSession (); */
NS_IMETHODIMP nsDragService::GetCurrentSession(nsIDragSession * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startDragSession (); */
NS_IMETHODIMP nsDragService::StartDragSession()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endDragSession (in boolean aDoneDrag); */
NS_IMETHODIMP nsDragService::EndDragSession(bool aDoneDrag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireDragEventAtSource (in unsigned long aMsg); */
NS_IMETHODIMP nsDragService::FireDragEventAtSource(uint32_t aMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suppress (); */
NS_IMETHODIMP nsDragService::Suppress()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unsuppress (); */
NS_IMETHODIMP nsDragService::Unsuppress()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void dragMoved (in long aX, in long aY); */
NS_IMETHODIMP nsDragService::DragMoved(int32_t aX, int32_t aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif



#endif /* __gen_nsIDragService_h__ */
