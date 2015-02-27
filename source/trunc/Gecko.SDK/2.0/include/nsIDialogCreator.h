/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/embedding/base/nsIDialogCreator.idl
 */

#ifndef __gen_nsIDialogCreator_h__
#define __gen_nsIDialogCreator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIDialogParamBlock; /* forward declaration */


/* starting interface:    nsIDialogCreator */
#define NS_IDIALOGCREATOR_IID_STR "17c9e659-2a9a-4a58-8a1c-d76bb58339c0"

#define NS_IDIALOGCREATOR_IID \
  {0x17c9e659, 0x2a9a, 0x4a58, \
    { 0x8a, 0x1c, 0xd7, 0x6b, 0xb5, 0x83, 0x39, 0xc0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDialogCreator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIALOGCREATOR_IID)

  enum { UNKNOWN_DIALOG = 0U };

  enum { GENERIC_DIALOG = 1U };

  enum { SELECT_DIALOG = 2U };

  /* void openDialog (in unsigned long aType, in ACString aName, in ACString aFeatures, in nsIDialogParamBlock aArguments, [optional] in nsIDOMElement aFrameElement); */
  NS_SCRIPTABLE NS_IMETHOD OpenDialog(PRUint32 aType, const nsACString & aName, const nsACString & aFeatures, nsIDialogParamBlock *aArguments, nsIDOMElement *aFrameElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDialogCreator, NS_IDIALOGCREATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIALOGCREATOR \
  NS_SCRIPTABLE NS_IMETHOD OpenDialog(PRUint32 aType, const nsACString & aName, const nsACString & aFeatures, nsIDialogParamBlock *aArguments, nsIDOMElement *aFrameElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIALOGCREATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD OpenDialog(PRUint32 aType, const nsACString & aName, const nsACString & aFeatures, nsIDialogParamBlock *aArguments, nsIDOMElement *aFrameElement) { return _to OpenDialog(aType, aName, aFeatures, aArguments, aFrameElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIALOGCREATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD OpenDialog(PRUint32 aType, const nsACString & aName, const nsACString & aFeatures, nsIDialogParamBlock *aArguments, nsIDOMElement *aFrameElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDialog(aType, aName, aFeatures, aArguments, aFrameElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDialogCreator : public nsIDialogCreator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIALOGCREATOR

  nsDialogCreator();

private:
  ~nsDialogCreator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDialogCreator, nsIDialogCreator)

nsDialogCreator::nsDialogCreator()
{
  /* member initializers and constructor code */
}

nsDialogCreator::~nsDialogCreator()
{
  /* destructor code */
}

/* void openDialog (in unsigned long aType, in ACString aName, in ACString aFeatures, in nsIDialogParamBlock aArguments, [optional] in nsIDOMElement aFrameElement); */
NS_IMETHODIMP nsDialogCreator::OpenDialog(PRUint32 aType, const nsACString & aName, const nsACString & aFeatures, nsIDialogParamBlock *aArguments, nsIDOMElement *aFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDialogCreator_h__ */
