/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/components/windowwatcher/public/nsIPromptService.idl
 */

#ifndef __gen_nsIPromptService_h__
#define __gen_nsIPromptService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIPromptService */
#define NS_IPROMPTSERVICE_IID_STR "1630c61a-325e-49ca-8759-a31b16c47aa5"

#define NS_IPROMPTSERVICE_IID \
  {0x1630c61a, 0x325e, 0x49ca, \
    { 0x87, 0x59, 0xa3, 0x1b, 0x16, 0xc4, 0x7a, 0xa5 }}

class NS_NO_VTABLE nsIPromptService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROMPTSERVICE_IID)

  /* void alert (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText); */
  NS_IMETHOD Alert(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText) = 0;

  /* void alertCheck (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, in wstring aCheckMsg, inout boolean aCheckState); */
  NS_IMETHOD AlertCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState) = 0;

  /* boolean confirm (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText); */
  NS_IMETHOD Confirm(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, bool *_retval) = 0;

  /* boolean confirmCheck (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, in wstring aCheckMsg, inout boolean aCheckState); */
  NS_IMETHOD ConfirmCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) = 0;

  enum {
    BUTTON_POS_0 = 1U,
    BUTTON_POS_1 = 256U,
    BUTTON_POS_2 = 65536U,
    BUTTON_TITLE_OK = 1U,
    BUTTON_TITLE_CANCEL = 2U,
    BUTTON_TITLE_YES = 3U,
    BUTTON_TITLE_NO = 4U,
    BUTTON_TITLE_SAVE = 5U,
    BUTTON_TITLE_DONT_SAVE = 6U,
    BUTTON_TITLE_REVERT = 7U,
    BUTTON_TITLE_IS_STRING = 127U,
    BUTTON_POS_0_DEFAULT = 0U,
    BUTTON_POS_1_DEFAULT = 16777216U,
    BUTTON_POS_2_DEFAULT = 33554432U,
    BUTTON_DELAY_ENABLE = 67108864U,
    STD_OK_CANCEL_BUTTONS = 513U,
    STD_YES_NO_BUTTONS = 1027U
  };

  /* int32_t confirmEx (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, in unsigned long aButtonFlags, in wstring aButton0Title, in wstring aButton1Title, in wstring aButton2Title, in wstring aCheckMsg, inout boolean aCheckState); */
  NS_IMETHOD ConfirmEx(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aButtonFlags, const PRUnichar * aButton0Title, const PRUnichar * aButton1Title, const PRUnichar * aButton2Title, const PRUnichar * aCheckMsg, bool *aCheckState, int32_t *_retval) = 0;

  /* boolean prompt (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, inout wstring aValue, in wstring aCheckMsg, inout boolean aCheckState); */
  NS_IMETHOD Prompt(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aValue, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) = 0;

  /* boolean promptUsernameAndPassword (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, inout wstring aUsername, inout wstring aPassword, in wstring aCheckMsg, inout boolean aCheckState); */
  NS_IMETHOD PromptUsernameAndPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aUsername, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) = 0;

  /* boolean promptPassword (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, inout wstring aPassword, in wstring aCheckMsg, inout boolean aCheckState); */
  NS_IMETHOD PromptPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) = 0;

  /* boolean select (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, in uint32_t aCount, [array, size_is (aCount)] in wstring aSelectList, out long aOutSelection); */
  NS_IMETHOD Select(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aCount, const PRUnichar * *aSelectList, int32_t *aOutSelection, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPromptService, NS_IPROMPTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROMPTSERVICE \
  NS_IMETHOD Alert(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText); \
  NS_IMETHOD AlertCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState); \
  NS_IMETHOD Confirm(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, bool *_retval); \
  NS_IMETHOD ConfirmCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval); \
  NS_IMETHOD ConfirmEx(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aButtonFlags, const PRUnichar * aButton0Title, const PRUnichar * aButton1Title, const PRUnichar * aButton2Title, const PRUnichar * aCheckMsg, bool *aCheckState, int32_t *_retval); \
  NS_IMETHOD Prompt(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aValue, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval); \
  NS_IMETHOD PromptUsernameAndPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aUsername, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval); \
  NS_IMETHOD PromptPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval); \
  NS_IMETHOD Select(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aCount, const PRUnichar * *aSelectList, int32_t *aOutSelection, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROMPTSERVICE(_to) \
  NS_IMETHOD Alert(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText) { return _to Alert(aParent, aDialogTitle, aText); } \
  NS_IMETHOD AlertCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState) { return _to AlertCheck(aParent, aDialogTitle, aText, aCheckMsg, aCheckState); } \
  NS_IMETHOD Confirm(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, bool *_retval) { return _to Confirm(aParent, aDialogTitle, aText, _retval); } \
  NS_IMETHOD ConfirmCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) { return _to ConfirmCheck(aParent, aDialogTitle, aText, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD ConfirmEx(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aButtonFlags, const PRUnichar * aButton0Title, const PRUnichar * aButton1Title, const PRUnichar * aButton2Title, const PRUnichar * aCheckMsg, bool *aCheckState, int32_t *_retval) { return _to ConfirmEx(aParent, aDialogTitle, aText, aButtonFlags, aButton0Title, aButton1Title, aButton2Title, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD Prompt(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aValue, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) { return _to Prompt(aParent, aDialogTitle, aText, aValue, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD PromptUsernameAndPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aUsername, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) { return _to PromptUsernameAndPassword(aParent, aDialogTitle, aText, aUsername, aPassword, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD PromptPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) { return _to PromptPassword(aParent, aDialogTitle, aText, aPassword, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD Select(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aCount, const PRUnichar * *aSelectList, int32_t *aOutSelection, bool *_retval) { return _to Select(aParent, aDialogTitle, aText, aCount, aSelectList, aOutSelection, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROMPTSERVICE(_to) \
  NS_IMETHOD Alert(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->Alert(aParent, aDialogTitle, aText); } \
  NS_IMETHOD AlertCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->AlertCheck(aParent, aDialogTitle, aText, aCheckMsg, aCheckState); } \
  NS_IMETHOD Confirm(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Confirm(aParent, aDialogTitle, aText, _retval); } \
  NS_IMETHOD ConfirmCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmCheck(aParent, aDialogTitle, aText, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD ConfirmEx(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aButtonFlags, const PRUnichar * aButton0Title, const PRUnichar * aButton1Title, const PRUnichar * aButton2Title, const PRUnichar * aCheckMsg, bool *aCheckState, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmEx(aParent, aDialogTitle, aText, aButtonFlags, aButton0Title, aButton1Title, aButton2Title, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD Prompt(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aValue, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(aParent, aDialogTitle, aText, aValue, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD PromptUsernameAndPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aUsername, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptUsernameAndPassword(aParent, aDialogTitle, aText, aUsername, aPassword, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD PromptPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptPassword(aParent, aDialogTitle, aText, aPassword, aCheckMsg, aCheckState, _retval); } \
  NS_IMETHOD Select(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aCount, const PRUnichar * *aSelectList, int32_t *aOutSelection, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Select(aParent, aDialogTitle, aText, aCount, aSelectList, aOutSelection, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPromptService : public nsIPromptService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROMPTSERVICE

  nsPromptService();

private:
  ~nsPromptService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPromptService, nsIPromptService)

nsPromptService::nsPromptService()
{
  /* member initializers and constructor code */
}

nsPromptService::~nsPromptService()
{
  /* destructor code */
}

/* void alert (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText); */
NS_IMETHODIMP nsPromptService::Alert(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void alertCheck (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, in wstring aCheckMsg, inout boolean aCheckState); */
NS_IMETHODIMP nsPromptService::AlertCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean confirm (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText); */
NS_IMETHODIMP nsPromptService::Confirm(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean confirmCheck (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, in wstring aCheckMsg, inout boolean aCheckState); */
NS_IMETHODIMP nsPromptService::ConfirmCheck(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t confirmEx (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, in unsigned long aButtonFlags, in wstring aButton0Title, in wstring aButton1Title, in wstring aButton2Title, in wstring aCheckMsg, inout boolean aCheckState); */
NS_IMETHODIMP nsPromptService::ConfirmEx(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aButtonFlags, const PRUnichar * aButton0Title, const PRUnichar * aButton1Title, const PRUnichar * aButton2Title, const PRUnichar * aCheckMsg, bool *aCheckState, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean prompt (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, inout wstring aValue, in wstring aCheckMsg, inout boolean aCheckState); */
NS_IMETHODIMP nsPromptService::Prompt(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aValue, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean promptUsernameAndPassword (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, inout wstring aUsername, inout wstring aPassword, in wstring aCheckMsg, inout boolean aCheckState); */
NS_IMETHODIMP nsPromptService::PromptUsernameAndPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aUsername, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean promptPassword (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, inout wstring aPassword, in wstring aCheckMsg, inout boolean aCheckState); */
NS_IMETHODIMP nsPromptService::PromptPassword(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, PRUnichar * *aPassword, const PRUnichar * aCheckMsg, bool *aCheckState, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean select (in nsIDOMWindow aParent, in wstring aDialogTitle, in wstring aText, in uint32_t aCount, [array, size_is (aCount)] in wstring aSelectList, out long aOutSelection); */
NS_IMETHODIMP nsPromptService::Select(nsIDOMWindow *aParent, const PRUnichar * aDialogTitle, const PRUnichar * aText, uint32_t aCount, const PRUnichar * *aSelectList, int32_t *aOutSelection, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPromptService_h__ */
