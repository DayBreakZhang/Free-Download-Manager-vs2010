/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/base/public/nsISelection3.idl
 */

#ifndef __gen_nsISelection3_h__
#define __gen_nsISelection3_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISelection3 */
#define NS_ISELECTION3_IID_STR "94ac0cb4-95b4-11df-8e13-0026b9792740"

#define NS_ISELECTION3_IID \
  {0x94ac0cb4, 0x95b4, 0x11df, \
    { 0x8e, 0x13, 0x00, 0x26, 0xb9, 0x79, 0x27, 0x40 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISelection3 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTION3_IID)

  /**
   * Modifies the selection.  Note that the parameters are case-insensitive.
   *
   * @param alter can be one of { "move", "extend" }
   *   - "move" collapses the selection to the end of the selection and
   *      applies the movement direction/granularity to the collapsed
   *      selection.
   *   - "extend" leaves the start of the selection unchanged, and applies
   *      movement direction/granularity to the end of the selection.
   * @param direction can be one of { "forward", "backward", "left", "right" }
   * @param granularity can be one of { "character", "word",
   *                                    "line", "lineboundary" }
   *
   * @returns NS_ERROR_NOT_IMPLEMENTED if the granularity is "sentence",
   * "sentenceboundary", "paragraph", "paragraphboundary", or
   * "documentboundary".  Returns NS_ERROR_INVALID_ARG if alter, direction,
   * or granularity has an unrecognized value.
   */
  /* void modify (in DOMString alter, in DOMString direction, in DOMString granularity); */
  NS_SCRIPTABLE NS_IMETHOD Modify(const nsAString & alter, const nsAString & direction, const nsAString & granularity) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelection3, NS_ISELECTION3_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTION3 \
  NS_SCRIPTABLE NS_IMETHOD Modify(const nsAString & alter, const nsAString & direction, const nsAString & granularity); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTION3(_to) \
  NS_SCRIPTABLE NS_IMETHOD Modify(const nsAString & alter, const nsAString & direction, const nsAString & granularity) { return _to Modify(alter, direction, granularity); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTION3(_to) \
  NS_SCRIPTABLE NS_IMETHOD Modify(const nsAString & alter, const nsAString & direction, const nsAString & granularity) { return !_to ? NS_ERROR_NULL_POINTER : _to->Modify(alter, direction, granularity); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelection3 : public nsISelection3
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTION3

  nsSelection3();

private:
  ~nsSelection3();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSelection3, nsISelection3)

nsSelection3::nsSelection3()
{
  /* member initializers and constructor code */
}

nsSelection3::~nsSelection3()
{
  /* destructor code */
}

/* void modify (in DOMString alter, in DOMString direction, in DOMString granularity); */
NS_IMETHODIMP nsSelection3::Modify(const nsAString & alter, const nsAString & direction, const nsAString & granularity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISelection3_h__ */
