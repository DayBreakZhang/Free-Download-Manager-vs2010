/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/editor/idl/nsIHTMLEditor_MOZILLA_2_0_BRANCH.idl
 */

#ifndef __gen_nsIHTMLEditor_MOZILLA_2_0_BRANCH_h__
#define __gen_nsIHTMLEditor_MOZILLA_2_0_BRANCH_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    nsIHTMLEditor_MOZILLA_2_0_BRANCH */
#define NS_IHTMLEDITOR_MOZILLA_2_0_BRANCH_IID_STR "278714d1-2072-440a-bb0f-6522d98d280a"

#define NS_IHTMLEDITOR_MOZILLA_2_0_BRANCH_IID \
  {0x278714d1, 0x2072, 0x440a, \
    { 0xbb, 0x0f, 0x65, 0x22, 0xd9, 0x8d, 0x28, 0x0a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIHTMLEditor_MOZILLA_2_0_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLEDITOR_MOZILLA_2_0_BRANCH_IID)

  /**
   * Checks whether a BR node is visible to the user.
   */
  /* boolean breakIsVisible (in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD BreakIsVisible(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLEditor_MOZILLA_2_0_BRANCH, NS_IHTMLEDITOR_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLEDITOR_MOZILLA_2_0_BRANCH \
  NS_SCRIPTABLE NS_IMETHOD BreakIsVisible(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLEDITOR_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD BreakIsVisible(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM) { return _to BreakIsVisible(aNode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLEDITOR_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD BreakIsVisible(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->BreakIsVisible(aNode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLEditor_MOZILLA_2_0_BRANCH : public nsIHTMLEditor_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLEDITOR_MOZILLA_2_0_BRANCH

  nsHTMLEditor_MOZILLA_2_0_BRANCH();

private:
  ~nsHTMLEditor_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTMLEditor_MOZILLA_2_0_BRANCH, nsIHTMLEditor_MOZILLA_2_0_BRANCH)

nsHTMLEditor_MOZILLA_2_0_BRANCH::nsHTMLEditor_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsHTMLEditor_MOZILLA_2_0_BRANCH::~nsHTMLEditor_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* boolean breakIsVisible (in nsIDOMNode aNode); */
NS_IMETHODIMP nsHTMLEditor_MOZILLA_2_0_BRANCH::BreakIsVisible(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLEditor_MOZILLA_2_0_BRANCH_h__ */
