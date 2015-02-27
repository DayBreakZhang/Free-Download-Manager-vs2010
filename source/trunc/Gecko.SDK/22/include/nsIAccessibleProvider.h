/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/accessible/public/nsIAccessibleProvider.idl
 */

#ifndef __gen_nsIAccessibleProvider_h__
#define __gen_nsIAccessibleProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleProvider */
#define NS_IACCESSIBLEPROVIDER_IID_STR "f7e531b6-bc29-4d3d-8c91-60fc2b71eb40"

#define NS_IACCESSIBLEPROVIDER_IID \
  {0xf7e531b6, 0xbc29, 0x4d3d, \
    { 0x8c, 0x91, 0x60, 0xfc, 0x2b, 0x71, 0xeb, 0x40 }}

class NS_NO_VTABLE nsIAccessibleProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEPROVIDER_IID)

  enum {
    NoAccessible = 0,
    OuterDoc = 1,
    XULAlert = 4097,
    XULButton = 4098,
    XULCheckbox = 4099,
    XULColorPicker = 4100,
    XULColorPickerTile = 4101,
    XULCombobox = 4102,
    XULDropmarker = 4103,
    XULGroupbox = 4104,
    XULImage = 4105,
    XULLink = 4106,
    XULListbox = 4107,
    XULListCell = 4134,
    XULListHead = 4132,
    XULListHeader = 4133,
    XULListitem = 4108,
    XULMenubar = 4109,
    XULMenuitem = 4110,
    XULMenupopup = 4111,
    XULMenuSeparator = 4112,
    XULPane = 4113,
    XULProgressMeter = 4114,
    XULScale = 4115,
    XULStatusBar = 4116,
    XULRadioButton = 4117,
    XULRadioGroup = 4118,
    XULTab = 4119,
    XULTabs = 4120,
    XULTabpanels = 4121,
    XULText = 4122,
    XULTextBox = 4123,
    XULThumb = 4124,
    XULTree = 4125,
    XULTreeColumns = 4126,
    XULTreeColumnItem = 4127,
    XULToolbar = 4128,
    XULToolbarSeparator = 4129,
    XULTooltip = 4130,
    XULToolbarButton = 4131
  };

  /* readonly attribute long accessibleType; */
  NS_IMETHOD GetAccessibleType(int32_t *aAccessibleType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleProvider, NS_IACCESSIBLEPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEPROVIDER \
  NS_IMETHOD GetAccessibleType(int32_t *aAccessibleType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEPROVIDER(_to) \
  NS_IMETHOD GetAccessibleType(int32_t *aAccessibleType) { return _to GetAccessibleType(aAccessibleType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEPROVIDER(_to) \
  NS_IMETHOD GetAccessibleType(int32_t *aAccessibleType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleType(aAccessibleType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleProvider : public nsIAccessibleProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEPROVIDER

  nsAccessibleProvider();

private:
  ~nsAccessibleProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleProvider, nsIAccessibleProvider)

nsAccessibleProvider::nsAccessibleProvider()
{
  /* member initializers and constructor code */
}

nsAccessibleProvider::~nsAccessibleProvider()
{
  /* destructor code */
}

/* readonly attribute long accessibleType; */
NS_IMETHODIMP nsAccessibleProvider::GetAccessibleType(int32_t *aAccessibleType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleProvider_h__ */
