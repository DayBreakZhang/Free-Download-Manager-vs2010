/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsISound.idl
 */

#ifndef __gen_nsISound_h__
#define __gen_nsISound_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURL; /* forward declaration */


/* starting interface:    nsISound */
#define NS_ISOUND_IID_STR "c3c28d92-a17f-43df-976d-4eeae6f995fc"

#define NS_ISOUND_IID \
  {0xc3c28d92, 0xa17f, 0x43df, \
    { 0x97, 0x6d, 0x4e, 0xea, 0xe6, 0xf9, 0x95, 0xfc }}

class NS_NO_VTABLE nsISound : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOUND_IID)

  /* void play (in nsIURL aURL); */
  NS_IMETHOD Play(nsIURL *aURL) = 0;

  /* void playSystemSound (in AString soundAlias); */
  NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) = 0;

  /* void beep (); */
  NS_IMETHOD Beep(void) = 0;

  /* void init (); */
  NS_IMETHOD Init(void) = 0;

  enum {
    EVENT_NEW_MAIL_RECEIVED = 0U,
    EVENT_ALERT_DIALOG_OPEN = 1U,
    EVENT_CONFIRM_DIALOG_OPEN = 2U,
    EVENT_PROMPT_DIALOG_OPEN = 3U,
    EVENT_SELECT_DIALOG_OPEN = 4U,
    EVENT_MENU_EXECUTE = 5U,
    EVENT_MENU_POPUP = 6U,
    EVENT_EDITOR_MAX_LEN = 7U
  };

  /* void playEventSound (in unsigned long aEventId); */
  NS_IMETHOD PlayEventSound(uint32_t aEventId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISound, NS_ISOUND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOUND \
  NS_IMETHOD Play(nsIURL *aURL); \
  NS_IMETHOD PlaySystemSound(const nsAString & soundAlias); \
  NS_IMETHOD Beep(void); \
  NS_IMETHOD Init(void); \
  NS_IMETHOD PlayEventSound(uint32_t aEventId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOUND(_to) \
  NS_IMETHOD Play(nsIURL *aURL) { return _to Play(aURL); } \
  NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) { return _to PlaySystemSound(soundAlias); } \
  NS_IMETHOD Beep(void) { return _to Beep(); } \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD PlayEventSound(uint32_t aEventId) { return _to PlayEventSound(aEventId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOUND(_to) \
  NS_IMETHOD Play(nsIURL *aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->Play(aURL); } \
  NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) { return !_to ? NS_ERROR_NULL_POINTER : _to->PlaySystemSound(soundAlias); } \
  NS_IMETHOD Beep(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Beep(); } \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD PlayEventSound(uint32_t aEventId) { return !_to ? NS_ERROR_NULL_POINTER : _to->PlayEventSound(aEventId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSound : public nsISound
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOUND

  nsSound();

private:
  ~nsSound();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSound, nsISound)

nsSound::nsSound()
{
  /* member initializers and constructor code */
}

nsSound::~nsSound()
{
  /* destructor code */
}

/* void play (in nsIURL aURL); */
NS_IMETHODIMP nsSound::Play(nsIURL *aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void playSystemSound (in AString soundAlias); */
NS_IMETHODIMP nsSound::PlaySystemSound(const nsAString & soundAlias)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beep (); */
NS_IMETHODIMP nsSound::Beep()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (); */
NS_IMETHODIMP nsSound::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void playEventSound (in unsigned long aEventId); */
NS_IMETHODIMP nsSound::PlayEventSound(uint32_t aEventId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/**
 * NS_SYSSOUND_* can be used for playSystemSound but they are obsolete.
 * Use nsISound::playEventSound instead.
 */
#define NS_SYSSOUND_PREFIX          NS_LITERAL_STRING("_moz_")
#define NS_SYSSOUND_MAIL_BEEP       NS_LITERAL_STRING("_moz_mailbeep")
#define NS_SYSSOUND_ALERT_DIALOG    NS_LITERAL_STRING("_moz_alertdialog")
#define NS_SYSSOUND_CONFIRM_DIALOG  NS_LITERAL_STRING("_moz_confirmdialog")
#define NS_SYSSOUND_PROMPT_DIALOG   NS_LITERAL_STRING("_moz_promptdialog")
#define NS_SYSSOUND_SELECT_DIALOG   NS_LITERAL_STRING("_moz_selectdialog")
#define NS_SYSSOUND_MENU_EXECUTE    NS_LITERAL_STRING("_moz_menucommand")
#define NS_SYSSOUND_MENU_POPUP      NS_LITERAL_STRING("_moz_menupopup")
#define NS_IsMozAliasSound(aSoundAlias) \
          StringBeginsWith(aSoundAlias, NS_SYSSOUND_PREFIX)

#endif /* __gen_nsISound_h__ */
