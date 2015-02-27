/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/intl/locale/idl/nsIScriptableDateFormat.idl
 */

#ifndef __gen_nsIScriptableDateFormat_h__
#define __gen_nsIScriptableDateFormat_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef PRInt32  nsDateFormatSelector;

enum
{
    kDateFormatNone = 0,            // do not include the date  in the format string
    kDateFormatLong,                // provides the long date format for the given locale
    kDateFormatShort,               // provides the short date format for the given locale
    kDateFormatYearMonth,           // formats using only the year and month 
    kDateFormatWeekday              // week day (e.g. Mon, Tue)
};
typedef PRInt32  nsTimeFormatSelector;

enum
{
    kTimeFormatNone = 0,            // don't include the time in the format string
    kTimeFormatSeconds,             // provides the time format with seconds in the  given locale 
    kTimeFormatNoSeconds,           // provides the time format without seconds in the given locale 
    kTimeFormatSecondsForce24Hour,  // forces the time format to use the 24 clock, regardless of the locale conventions
    kTimeFormatNoSecondsForce24Hour // forces the time format to use the 24 clock, regardless of the locale conventions
};
// Define Contractid and CID
// {2EA2E7D0-4095-11d3-9144-006008A6EDF6}
#define NS_SCRIPTABLEDATEFORMAT_CID \
{ 0x2ea2e7d0, 0x4095, 0x11d3, { 0x91, 0x44, 0x0, 0x60, 0x8, 0xa6, 0xed, 0xf6 } }
#define NS_SCRIPTABLEDATEFORMAT_CONTRACTID "@mozilla.org/intl/scriptabledateformat;1"
extern nsresult
NS_NewScriptableDateFormat(nsISupports* aOuter, REFNSIID aIID, void** aResult);

/* starting interface:    nsIScriptableDateFormat */
#define NS_ISCRIPTABLEDATEFORMAT_IID_STR "0c89efb0-1aae-11d3-9141-006008a6edf6"

#define NS_ISCRIPTABLEDATEFORMAT_IID \
  {0x0c89efb0, 0x1aae, 0x11d3, \
    { 0x91, 0x41, 0x00, 0x60, 0x08, 0xa6, 0xed, 0xf6 }}

/**
 * Format date and time in a human readable format.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptableDateFormat : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEDATEFORMAT_IID)

  /**
     * Do not include the date in the format string.
     */
  enum { dateFormatNone = 0 };

  /**
     * Provide the long date format.
     *
     * NOTE:
     * The original definitions of dateFormatLong and dateFormatShort are from
     * the Windows platform. 
     * In US English dateFormatLong output will be like:
     *     Wednesday, January 29, 2003 4:02:14 PM
     * In US English dateFormatShort output will be like:
     *     1/29/03 4:02:14 PM
     * On platforms like Linux and OS2, it is rather difficult to achieve exact
     * same output, and since we are aiming at human readers, it does not make
     * sense to achieve exact same result. We will do just enough as the
     * platform allow us to do. 
     */
  enum { dateFormatLong = 1 };

  /**
     * Provide the short date format. See also dateFormatLong.
     */
  enum { dateFormatShort = 2 };

  /**
     * Format using only the year and month.
     */
  enum { dateFormatYearMonth = 3 };

  /**
     * Provide the Week day (e.g. Mo, Mon, Monday or similar).
     */
  enum { dateFormatWeekday = 4 };

  /**
     * Don't include the time in the format string.
     */
  enum { timeFormatNone = 0 };

  /**
     * Provide the time format with seconds.
     */
  enum { timeFormatSeconds = 1 };

  /**
     * Provide the time format without seconds.
     */
  enum { timeFormatNoSeconds = 2 };

  /**
     * Provide the time format with seconds, and force the time format to use
     * 24-hour clock, regardless of the locale conventions.
     */
  enum { timeFormatSecondsForce24Hour = 3 };

  /**
     * Provide the time format without seconds, and force the time format to use
     * 24-hour clock, regardless of the locale conventions.
     */
  enum { timeFormatNoSecondsForce24Hour = 4 };

  /**
     * Format the given date and time in a human readable format.
     *
     * The underlying operating system is used to format the date and time.
     *
     * Pass an empty string as the locale parameter to use the OS settings with
     * the preferred date and time formatting given by the user.
     *
     * Pass a locale code as described in nsILocale as the locale parameter
     * (e.g. en-US) to use a specific locale. If the given locale is not
     * available, a fallback will be used.
     *
     * NOTE: The output of this method depends on the operating system and user
     * settings. Even if you pass a locale code as the first parameter, there
     * are no guarantees about which locale and exact format the returned value
     * uses. Even if you know the locale, the format might be customized by the
     * user. Therefore you should not use the returned values in contexts where
     * you depend on any specific format or language.
     *
     * @param locale
     *        Locale code of locale used to format the date or an empty string
     *        to follow user preference.
     * @param dateFormatSelector
     *        Indicate which format should preferably be used for the date.
     *        Use one of the dateFormat* constants.
     * @param timeFormatSelector
     *        Indicate which format should preferably be used for the time.
     *        Use one of the timeFormat* constants.
     * @param year, month, day, hour, minute and second
     *        The date and time to be formatted, given in the computer's local
     *        time zone.
     * @return The date and time formatted as human readable text according to
     *         user preferences or the given locale.
     */
  /* wstring FormatDateTime (in wstring locale, in long dateFormatSelector, in long timeFormatSelector, in long year, in long month, in long day, in long hour, in long minute, in long second); */
  NS_SCRIPTABLE NS_IMETHOD FormatDateTime(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 timeFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM) = 0;

  /**
     * Format the given date in a human readable format.
     *
     * See FormatDateTime for details.
     */
  /* wstring FormatDate (in wstring locale, in long dateFormatSelector, in long year, in long month, in long day); */
  NS_SCRIPTABLE NS_IMETHOD FormatDate(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRUnichar **_retval NS_OUTPARAM) = 0;

  /**
     * Format the given time in a human readable format.
     *
     * See FormatDateTime for details.
     */
  /* wstring FormatTime (in wstring locale, in long timeFormatSelector, in long hour, in long minute, in long second); */
  NS_SCRIPTABLE NS_IMETHOD FormatTime(const PRUnichar *locale, PRInt32 timeFormatSelector, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableDateFormat, NS_ISCRIPTABLEDATEFORMAT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEDATEFORMAT \
  NS_SCRIPTABLE NS_IMETHOD FormatDateTime(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 timeFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FormatDate(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FormatTime(const PRUnichar *locale, PRInt32 timeFormatSelector, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEDATEFORMAT(_to) \
  NS_SCRIPTABLE NS_IMETHOD FormatDateTime(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 timeFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM) { return _to FormatDateTime(locale, dateFormatSelector, timeFormatSelector, year, month, day, hour, minute, second, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatDate(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRUnichar **_retval NS_OUTPARAM) { return _to FormatDate(locale, dateFormatSelector, year, month, day, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatTime(const PRUnichar *locale, PRInt32 timeFormatSelector, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM) { return _to FormatTime(locale, timeFormatSelector, hour, minute, second, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEDATEFORMAT(_to) \
  NS_SCRIPTABLE NS_IMETHOD FormatDateTime(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 timeFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatDateTime(locale, dateFormatSelector, timeFormatSelector, year, month, day, hour, minute, second, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatDate(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatDate(locale, dateFormatSelector, year, month, day, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FormatTime(const PRUnichar *locale, PRInt32 timeFormatSelector, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FormatTime(locale, timeFormatSelector, hour, minute, second, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableDateFormat : public nsIScriptableDateFormat
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEDATEFORMAT

  nsScriptableDateFormat();

private:
  ~nsScriptableDateFormat();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableDateFormat, nsIScriptableDateFormat)

nsScriptableDateFormat::nsScriptableDateFormat()
{
  /* member initializers and constructor code */
}

nsScriptableDateFormat::~nsScriptableDateFormat()
{
  /* destructor code */
}

/* wstring FormatDateTime (in wstring locale, in long dateFormatSelector, in long timeFormatSelector, in long year, in long month, in long day, in long hour, in long minute, in long second); */
NS_IMETHODIMP nsScriptableDateFormat::FormatDateTime(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 timeFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring FormatDate (in wstring locale, in long dateFormatSelector, in long year, in long month, in long day); */
NS_IMETHODIMP nsScriptableDateFormat::FormatDate(const PRUnichar *locale, PRInt32 dateFormatSelector, PRInt32 year, PRInt32 month, PRInt32 day, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring FormatTime (in wstring locale, in long timeFormatSelector, in long hour, in long minute, in long second); */
NS_IMETHODIMP nsScriptableDateFormat::FormatTime(const PRUnichar *locale, PRInt32 timeFormatSelector, PRInt32 hour, PRInt32 minute, PRInt32 second, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableDateFormat_h__ */
