/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/js/xpconnect/idl/nsIScriptError.idl
 */

#ifndef __gen_nsIScriptError_h__
#define __gen_nsIScriptError_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIConsoleMessage_h__
#include "nsIConsoleMessage.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptError */
#define NS_ISCRIPTERROR_IID_STR "ec640482-be5f-49a0-a9cb-c87eacce9291"

#define NS_ISCRIPTERROR_IID \
  {0xec640482, 0xbe5f, 0x49a0, \
    { 0xa9, 0xcb, 0xc8, 0x7e, 0xac, 0xce, 0x92, 0x91 }}

class NS_NO_VTABLE nsIScriptError : public nsIConsoleMessage {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTERROR_IID)

  enum {
    errorFlag = 0U,
    warningFlag = 1U,
    exceptionFlag = 2U,
    strictFlag = 4U
  };

  /* readonly attribute AString errorMessage; */
  NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) = 0;

  /* readonly attribute AString sourceName; */
  NS_IMETHOD GetSourceName(nsAString & aSourceName) = 0;

  /* readonly attribute AString sourceLine; */
  NS_IMETHOD GetSourceLine(nsAString & aSourceLine) = 0;

  /* readonly attribute uint32_t lineNumber; */
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) = 0;

  /* readonly attribute uint32_t columnNumber; */
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) = 0;

  /* readonly attribute uint32_t flags; */
  NS_IMETHOD GetFlags(uint32_t *aFlags) = 0;

  /* readonly attribute string category; */
  NS_IMETHOD GetCategory(char * *aCategory) = 0;

  /* readonly attribute long long timeStamp; */
  NS_IMETHOD GetTimeStamp(int64_t *aTimeStamp) = 0;

  /* readonly attribute unsigned long long outerWindowID; */
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) = 0;

  /* readonly attribute unsigned long long innerWindowID; */
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) = 0;

  /* readonly attribute boolean isFromPrivateWindow; */
  NS_IMETHOD GetIsFromPrivateWindow(bool *aIsFromPrivateWindow) = 0;

  /* void init (in AString message, in AString sourceName, in AString sourceLine, in uint32_t lineNumber, in uint32_t columnNumber, in uint32_t flags, in string category); */
  NS_IMETHOD Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category) = 0;

  /* void initWithWindowID (in AString message, in AString sourceName, in AString sourceLine, in uint32_t lineNumber, in uint32_t columnNumber, in uint32_t flags, in string category, in unsigned long long innerWindowID); */
  NS_IMETHOD InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category, uint64_t innerWindowID) = 0;

  /* AUTF8String toString (); */
  NS_IMETHOD ToString(nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptError, NS_ISCRIPTERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTERROR \
  NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage); \
  NS_IMETHOD GetSourceName(nsAString & aSourceName); \
  NS_IMETHOD GetSourceLine(nsAString & aSourceLine); \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber); \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber); \
  NS_IMETHOD GetFlags(uint32_t *aFlags); \
  NS_IMETHOD GetCategory(char * *aCategory); \
  NS_IMETHOD GetTimeStamp(int64_t *aTimeStamp); \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID); \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID); \
  NS_IMETHOD GetIsFromPrivateWindow(bool *aIsFromPrivateWindow); \
  NS_IMETHOD Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category); \
  NS_IMETHOD InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category, uint64_t innerWindowID); \
  NS_IMETHOD ToString(nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTERROR(_to) \
  NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) { return _to GetErrorMessage(aErrorMessage); } \
  NS_IMETHOD GetSourceName(nsAString & aSourceName) { return _to GetSourceName(aSourceName); } \
  NS_IMETHOD GetSourceLine(nsAString & aSourceLine) { return _to GetSourceLine(aSourceLine); } \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) { return _to GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) { return _to GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) { return _to GetFlags(aFlags); } \
  NS_IMETHOD GetCategory(char * *aCategory) { return _to GetCategory(aCategory); } \
  NS_IMETHOD GetTimeStamp(int64_t *aTimeStamp) { return _to GetTimeStamp(aTimeStamp); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) { return _to GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) { return _to GetInnerWindowID(aInnerWindowID); } \
  NS_IMETHOD GetIsFromPrivateWindow(bool *aIsFromPrivateWindow) { return _to GetIsFromPrivateWindow(aIsFromPrivateWindow); } \
  NS_IMETHOD Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category) { return _to Init(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category); } \
  NS_IMETHOD InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category, uint64_t innerWindowID) { return _to InitWithWindowID(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category, innerWindowID); } \
  NS_IMETHOD ToString(nsACString & _retval) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTERROR(_to) \
  NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorMessage(aErrorMessage); } \
  NS_IMETHOD GetSourceName(nsAString & aSourceName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceName(aSourceName); } \
  NS_IMETHOD GetSourceLine(nsAString & aSourceLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceLine(aSourceLine); } \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_IMETHOD GetCategory(char * *aCategory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCategory(aCategory); } \
  NS_IMETHOD GetTimeStamp(int64_t *aTimeStamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeStamp(aTimeStamp); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerWindowID(aInnerWindowID); } \
  NS_IMETHOD GetIsFromPrivateWindow(bool *aIsFromPrivateWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFromPrivateWindow(aIsFromPrivateWindow); } \
  NS_IMETHOD Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category); } \
  NS_IMETHOD InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category, uint64_t innerWindowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithWindowID(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category, innerWindowID); } \
  NS_IMETHOD ToString(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptError : public nsIScriptError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTERROR

  nsScriptError();

private:
  ~nsScriptError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptError, nsIScriptError)

nsScriptError::nsScriptError()
{
  /* member initializers and constructor code */
}

nsScriptError::~nsScriptError()
{
  /* destructor code */
}

/* readonly attribute AString errorMessage; */
NS_IMETHODIMP nsScriptError::GetErrorMessage(nsAString & aErrorMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sourceName; */
NS_IMETHODIMP nsScriptError::GetSourceName(nsAString & aSourceName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sourceLine; */
NS_IMETHODIMP nsScriptError::GetSourceLine(nsAString & aSourceLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lineNumber; */
NS_IMETHODIMP nsScriptError::GetLineNumber(uint32_t *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t columnNumber; */
NS_IMETHODIMP nsScriptError::GetColumnNumber(uint32_t *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t flags; */
NS_IMETHODIMP nsScriptError::GetFlags(uint32_t *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string category; */
NS_IMETHODIMP nsScriptError::GetCategory(char * *aCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long timeStamp; */
NS_IMETHODIMP nsScriptError::GetTimeStamp(int64_t *aTimeStamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long outerWindowID; */
NS_IMETHODIMP nsScriptError::GetOuterWindowID(uint64_t *aOuterWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long innerWindowID; */
NS_IMETHODIMP nsScriptError::GetInnerWindowID(uint64_t *aInnerWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isFromPrivateWindow; */
NS_IMETHODIMP nsScriptError::GetIsFromPrivateWindow(bool *aIsFromPrivateWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in AString message, in AString sourceName, in AString sourceLine, in uint32_t lineNumber, in uint32_t columnNumber, in uint32_t flags, in string category); */
NS_IMETHODIMP nsScriptError::Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithWindowID (in AString message, in AString sourceName, in AString sourceLine, in uint32_t lineNumber, in uint32_t columnNumber, in uint32_t flags, in string category, in unsigned long long innerWindowID); */
NS_IMETHODIMP nsScriptError::InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category, uint64_t innerWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toString (); */
NS_IMETHODIMP nsScriptError::ToString(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SCRIPTERROR_CID \
{ 0xe38e53b9, 0x5bb0, 0x456a, { 0xb5, 0x53, 0x57, 0x93, 0x70, 0xcb, 0x15, 0x67 }}
#define NS_SCRIPTERROR_CONTRACTID "@mozilla.org/scripterror;1"

#endif /* __gen_nsIScriptError_h__ */
