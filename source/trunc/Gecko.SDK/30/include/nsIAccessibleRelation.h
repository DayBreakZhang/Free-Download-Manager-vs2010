/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleRelation.idl
 */

#ifndef __gen_nsIAccessibleRelation_h__
#define __gen_nsIAccessibleRelation_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIArray_h__
#include "nsIArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */


/* starting interface:    nsIAccessibleRelation */
#define NS_IACCESSIBLERELATION_IID_STR "55b308c4-2ae4-46bc-b4cd-4d4370e0a660"

#define NS_IACCESSIBLERELATION_IID \
  {0x55b308c4, 0x2ae4, 0x46bc, \
    { 0xb4, 0xcd, 0x4d, 0x43, 0x70, 0xe0, 0xa6, 0x60 }}

class NS_NO_VTABLE nsIAccessibleRelation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLERELATION_IID)

  enum {
    RELATION_LABELLED_BY = 0U,
    RELATION_LABEL_FOR = 1U,
    RELATION_DESCRIBED_BY = 2U,
    RELATION_DESCRIPTION_FOR = 3U,
    RELATION_NODE_CHILD_OF = 4U,
    RELATION_NODE_PARENT_OF = 5U,
    RELATION_CONTROLLED_BY = 6U,
    RELATION_CONTROLLER_FOR = 7U,
    RELATION_FLOWS_TO = 8U,
    RELATION_FLOWS_FROM = 9U,
    RELATION_MEMBER_OF = 10U,
    RELATION_SUBWINDOW_OF = 11U,
    RELATION_EMBEDS = 12U,
    RELATION_EMBEDDED_BY = 13U,
    RELATION_POPUP_FOR = 14U,
    RELATION_PARENT_WINDOW_OF = 15U,
    RELATION_DEFAULT_BUTTON = 16U,
    RELATION_CONTAINING_DOCUMENT = 17U,
    RELATION_CONTAINING_TAB_PANE = 18U,
    RELATION_CONTAINING_APPLICATION = 20U
  };

  /* readonly attribute unsigned long relationType; */
  NS_IMETHOD GetRelationType(uint32_t *aRelationType) = 0;

  /* readonly attribute unsigned long targetsCount; */
  NS_IMETHOD GetTargetsCount(uint32_t *aTargetsCount) = 0;

  /* nsIAccessible getTarget (in unsigned long index); */
  NS_IMETHOD GetTarget(uint32_t index, nsIAccessible * *_retval) = 0;

  /* nsIArray getTargets (); */
  NS_IMETHOD GetTargets(nsIArray * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleRelation, NS_IACCESSIBLERELATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLERELATION \
  NS_IMETHOD GetRelationType(uint32_t *aRelationType); \
  NS_IMETHOD GetTargetsCount(uint32_t *aTargetsCount); \
  NS_IMETHOD GetTarget(uint32_t index, nsIAccessible * *_retval); \
  NS_IMETHOD GetTargets(nsIArray * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLERELATION(_to) \
  NS_IMETHOD GetRelationType(uint32_t *aRelationType) { return _to GetRelationType(aRelationType); } \
  NS_IMETHOD GetTargetsCount(uint32_t *aTargetsCount) { return _to GetTargetsCount(aTargetsCount); } \
  NS_IMETHOD GetTarget(uint32_t index, nsIAccessible * *_retval) { return _to GetTarget(index, _retval); } \
  NS_IMETHOD GetTargets(nsIArray * *_retval) { return _to GetTargets(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLERELATION(_to) \
  NS_IMETHOD GetRelationType(uint32_t *aRelationType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelationType(aRelationType); } \
  NS_IMETHOD GetTargetsCount(uint32_t *aTargetsCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetsCount(aTargetsCount); } \
  NS_IMETHOD GetTarget(uint32_t index, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(index, _retval); } \
  NS_IMETHOD GetTargets(nsIArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargets(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleRelation : public nsIAccessibleRelation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLERELATION

  nsAccessibleRelation();

private:
  ~nsAccessibleRelation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleRelation, nsIAccessibleRelation)

nsAccessibleRelation::nsAccessibleRelation()
{
  /* member initializers and constructor code */
}

nsAccessibleRelation::~nsAccessibleRelation()
{
  /* destructor code */
}

/* readonly attribute unsigned long relationType; */
NS_IMETHODIMP nsAccessibleRelation::GetRelationType(uint32_t *aRelationType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long targetsCount; */
NS_IMETHODIMP nsAccessibleRelation::GetTargetsCount(uint32_t *aTargetsCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getTarget (in unsigned long index); */
NS_IMETHODIMP nsAccessibleRelation::GetTarget(uint32_t index, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getTargets (); */
NS_IMETHODIMP nsAccessibleRelation::GetTargets(nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleRelation_h__ */
