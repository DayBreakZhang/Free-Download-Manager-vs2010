/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsISound.idl
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
#define NS_ISOUND_IID_STR "86b75b05-db60-4c3e-97a7-82b363a41a01"

#define NS_ISOUND_IID \
  {0x86b75b05, 0xdb60, 0x4c3e, \
    { 0x97, 0xa7, 0x82, 0xb3, 0x63, 0xa4, 0x1a, 0x01 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISound : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOUND_IID)

  /* void play (in nsIURL aURL); */
  NS_SCRIPTABLE NS_IMETHOD Play(nsIURL *aURL) = 0;

  /**
   * for playing system sounds
   *
   * NS_SYSSOUND_* params are obsolete. The new events will not be supported by
   * this method.  You should use playEventSound method instaed.
   */
  /* void playSystemSound (in AString soundAlias); */
  NS_SCRIPTABLE NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) = 0;

  /* void beep (); */
  NS_SCRIPTABLE NS_IMETHOD Beep(void) = 0;

  /**
    * Not strictly necessary, but avoids delay before first sound.
    * The various methods on nsISound call Init() if they need to.
	*/
  /* void init (); */
  NS_SCRIPTABLE NS_IMETHOD Init(void) = 0;

  /**
   * In some situations, playEventSound will be called.  Then, each
   * implementations will play a system sound for the event if it's necessary.
   *
   * NOTE: Don't change these values because they are used in
   * nsPIPromptService.idl. So, if they are changed, that makes big impact for
   * the embedders.
   */
  enum { EVENT_NEW_MAIL_RECEIVED = 0U };

  enum { EVENT_ALERT_DIALOG_OPEN = 1U };

  enum { EVENT_CONFIRM_DIALOG_OPEN = 2U };

  enum { EVENT_PROMPT_DIALOG_OPEN = 3U };

  enum { EVENT_SELECT_DIALOG_OPEN = 4U };

  enum { EVENT_MENU_EXECUTE = 5U };

  enum { EVENT_MENU_POPUP = 6U };

  /* void playEventSound (in unsigned long aEventId); */
  NS_SCRIPTABLE NS_IMETHOD PlayEventSound(PRUint32 aEventId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISound, NS_ISOUND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOUND \
  NS_SCRIPTABLE NS_IMETHOD Play(nsIURL *aURL); \
  NS_SCRIPTABLE NS_IMETHOD PlaySystemSound(const nsAString & soundAlias); \
  NS_SCRIPTABLE NS_IMETHOD Beep(void); \
  NS_SCRIPTABLE NS_IMETHOD Init(void); \
  NS_SCRIPTABLE NS_IMETHOD PlayEventSound(PRUint32 aEventId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOUND(_to) \
  NS_SCRIPTABLE NS_IMETHOD Play(nsIURL *aURL) { return _to Play(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) { return _to PlaySystemSound(soundAlias); } \
  NS_SCRIPTABLE NS_IMETHOD Beep(void) { return _to Beep(); } \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return _to Init(); } \
  NS_SCRIPTABLE NS_IMETHOD PlayEventSound(PRUint32 aEventId) { return _to PlayEventSound(aEventId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOUND(_to) \
  NS_SCRIPTABLE NS_IMETHOD Play(nsIURL *aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->Play(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) { return !_to ? NS_ERROR_NULL_POINTER : _to->PlaySystemSound(soundAlias); } \
  NS_SCRIPTABLE NS_IMETHOD Beep(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Beep(); } \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_SCRIPTABLE NS_IMETHOD PlayEventSound(PRUint32 aEventId) { return !_to ? NS_ERROR_NULL_POINTER : _to->PlayEventSound(aEventId); } 

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
NS_IMETHODIMP nsSound::PlayEventSound(PRUint32 aEventId)
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
