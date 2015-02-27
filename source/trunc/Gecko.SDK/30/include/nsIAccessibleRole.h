/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleRole.idl
 */

#ifndef __gen_nsIAccessibleRole_h__
#define __gen_nsIAccessibleRole_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleRole */
#define NS_IACCESSIBLEROLE_IID_STR "50db5e86-9a45-4637-a5c3-4ff148c33270"

#define NS_IACCESSIBLEROLE_IID \
  {0x50db5e86, 0x9a45, 0x4637, \
    { 0xa5, 0xc3, 0x4f, 0xf1, 0x48, 0xc3, 0x32, 0x70 }}

class NS_NO_VTABLE nsIAccessibleRole : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEROLE_IID)

  enum {
    ROLE_NOTHING = 0U,
    ROLE_TITLEBAR = 1U,
    ROLE_MENUBAR = 2U,
    ROLE_SCROLLBAR = 3U,
    ROLE_GRIP = 4U,
    ROLE_SOUND = 5U,
    ROLE_CURSOR = 6U,
    ROLE_CARET = 7U,
    ROLE_ALERT = 8U,
    ROLE_WINDOW = 9U,
    ROLE_INTERNAL_FRAME = 10U,
    ROLE_MENUPOPUP = 11U,
    ROLE_MENUITEM = 12U,
    ROLE_TOOLTIP = 13U,
    ROLE_APPLICATION = 14U,
    ROLE_DOCUMENT = 15U,
    ROLE_PANE = 16U,
    ROLE_CHART = 17U,
    ROLE_DIALOG = 18U,
    ROLE_BORDER = 19U,
    ROLE_GROUPING = 20U,
    ROLE_SEPARATOR = 21U,
    ROLE_TOOLBAR = 22U,
    ROLE_STATUSBAR = 23U,
    ROLE_TABLE = 24U,
    ROLE_COLUMNHEADER = 25U,
    ROLE_ROWHEADER = 26U,
    ROLE_COLUMN = 27U,
    ROLE_ROW = 28U,
    ROLE_CELL = 29U,
    ROLE_LINK = 30U,
    ROLE_HELPBALLOON = 31U,
    ROLE_CHARACTER = 32U,
    ROLE_LIST = 33U,
    ROLE_LISTITEM = 34U,
    ROLE_OUTLINE = 35U,
    ROLE_OUTLINEITEM = 36U,
    ROLE_PAGETAB = 37U,
    ROLE_PROPERTYPAGE = 38U,
    ROLE_INDICATOR = 39U,
    ROLE_GRAPHIC = 40U,
    ROLE_STATICTEXT = 41U,
    ROLE_TEXT_LEAF = 42U,
    ROLE_PUSHBUTTON = 43U,
    ROLE_CHECKBUTTON = 44U,
    ROLE_RADIOBUTTON = 45U,
    ROLE_COMBOBOX = 46U,
    ROLE_DROPLIST = 47U,
    ROLE_PROGRESSBAR = 48U,
    ROLE_DIAL = 49U,
    ROLE_HOTKEYFIELD = 50U,
    ROLE_SLIDER = 51U,
    ROLE_SPINBUTTON = 52U,
    ROLE_DIAGRAM = 53U,
    ROLE_ANIMATION = 54U,
    ROLE_EQUATION = 55U,
    ROLE_BUTTONDROPDOWN = 56U,
    ROLE_BUTTONMENU = 57U,
    ROLE_BUTTONDROPDOWNGRID = 58U,
    ROLE_WHITESPACE = 59U,
    ROLE_PAGETABLIST = 60U,
    ROLE_CLOCK = 61U,
    ROLE_SPLITBUTTON = 62U,
    ROLE_IPADDRESS = 63U,
    ROLE_ACCEL_LABEL = 64U,
    ROLE_ARROW = 65U,
    ROLE_CANVAS = 66U,
    ROLE_CHECK_MENU_ITEM = 67U,
    ROLE_COLOR_CHOOSER = 68U,
    ROLE_DATE_EDITOR = 69U,
    ROLE_DESKTOP_ICON = 70U,
    ROLE_DESKTOP_FRAME = 71U,
    ROLE_DIRECTORY_PANE = 72U,
    ROLE_FILE_CHOOSER = 73U,
    ROLE_FONT_CHOOSER = 74U,
    ROLE_CHROME_WINDOW = 75U,
    ROLE_GLASS_PANE = 76U,
    ROLE_HTML_CONTAINER = 77U,
    ROLE_ICON = 78U,
    ROLE_LABEL = 79U,
    ROLE_LAYERED_PANE = 80U,
    ROLE_OPTION_PANE = 81U,
    ROLE_PASSWORD_TEXT = 82U,
    ROLE_POPUP_MENU = 83U,
    ROLE_RADIO_MENU_ITEM = 84U,
    ROLE_ROOT_PANE = 85U,
    ROLE_SCROLL_PANE = 86U,
    ROLE_SPLIT_PANE = 87U,
    ROLE_TABLE_COLUMN_HEADER = 88U,
    ROLE_TABLE_ROW_HEADER = 89U,
    ROLE_TEAR_OFF_MENU_ITEM = 90U,
    ROLE_TERMINAL = 91U,
    ROLE_TEXT_CONTAINER = 92U,
    ROLE_TOGGLE_BUTTON = 93U,
    ROLE_TREE_TABLE = 94U,
    ROLE_VIEWPORT = 95U,
    ROLE_HEADER = 96U,
    ROLE_FOOTER = 97U,
    ROLE_PARAGRAPH = 98U,
    ROLE_RULER = 99U,
    ROLE_AUTOCOMPLETE = 100U,
    ROLE_EDITBAR = 101U,
    ROLE_ENTRY = 102U,
    ROLE_CAPTION = 103U,
    ROLE_DOCUMENT_FRAME = 104U,
    ROLE_HEADING = 105U,
    ROLE_PAGE = 106U,
    ROLE_SECTION = 107U,
    ROLE_REDUNDANT_OBJECT = 108U,
    ROLE_FORM = 109U,
    ROLE_IME = 110U,
    ROLE_APP_ROOT = 111U,
    ROLE_PARENT_MENUITEM = 112U,
    ROLE_CALENDAR = 113U,
    ROLE_COMBOBOX_LIST = 114U,
    ROLE_COMBOBOX_OPTION = 115U,
    ROLE_IMAGE_MAP = 116U,
    ROLE_OPTION = 117U,
    ROLE_RICH_OPTION = 118U,
    ROLE_LISTBOX = 119U,
    ROLE_FLAT_EQUATION = 120U,
    ROLE_GRID_CELL = 121U,
    ROLE_EMBEDDED_OBJECT = 122U,
    ROLE_NOTE = 123U,
    ROLE_FIGURE = 124U,
    ROLE_CHECK_RICH_OPTION = 125U,
    ROLE_DEFINITION_LIST = 126U,
    ROLE_TERM = 127U,
    ROLE_DEFINITION = 128U,
    ROLE_KEY = 129U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleRole, NS_IACCESSIBLEROLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEROLE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEROLE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEROLE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleRole : public nsIAccessibleRole
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEROLE

  nsAccessibleRole();

private:
  ~nsAccessibleRole();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleRole, nsIAccessibleRole)

nsAccessibleRole::nsAccessibleRole()
{
  /* member initializers and constructor code */
}

nsAccessibleRole::~nsAccessibleRole()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleRole_h__ */
