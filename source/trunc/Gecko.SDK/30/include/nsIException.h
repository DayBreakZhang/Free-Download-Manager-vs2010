/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIException.idl
 */

#ifndef __gen_nsIException_h__
#define __gen_nsIException_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStackFrame */
#define NS_ISTACKFRAME_IID_STR "60abee59-717e-477d-8bbb-a1c3e7067126"

#define NS_ISTACKFRAME_IID \
  {0x60abee59, 0x717e, 0x477d, \
    { 0x8b, 0xbb, 0xa1, 0xc3, 0xe7, 0x06, 0x71, 0x26 }}

class NS_NO_VTABLE nsIStackFrame : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTACKFRAME_IID)

  /* readonly attribute uint32_t language; */
  NS_IMETHOD GetLanguage(uint32_t *aLanguage) = 0;

  /* readonly attribute AUTF8String languageName; */
  NS_IMETHOD GetLanguageName(nsACString & aLanguageName) = 0;

  /* readonly attribute AUTF8String filename; */
  NS_IMETHOD GetFilename(nsACString & aFilename) = 0;

  /* readonly attribute AUTF8String name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute int32_t lineNumber; */
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) = 0;

  /* readonly attribute AUTF8String sourceLine; */
  NS_IMETHOD GetSourceLine(nsACString & aSourceLine) = 0;

  /* readonly attribute nsIStackFrame caller; */
  NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) = 0;

  /* AUTF8String toString (); */
  NS_IMETHOD ToString(nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStackFrame, NS_ISTACKFRAME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTACKFRAME \
  NS_IMETHOD GetLanguage(uint32_t *aLanguage); \
  NS_IMETHOD GetLanguageName(nsACString & aLanguageName); \
  NS_IMETHOD GetFilename(nsACString & aFilename); \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber); \
  NS_IMETHOD GetSourceLine(nsACString & aSourceLine); \
  NS_IMETHOD GetCaller(nsIStackFrame * *aCaller); \
  NS_IMETHOD ToString(nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTACKFRAME(_to) \
  NS_IMETHOD GetLanguage(uint32_t *aLanguage) { return _to GetLanguage(aLanguage); } \
  NS_IMETHOD GetLanguageName(nsACString & aLanguageName) { return _to GetLanguageName(aLanguageName); } \
  NS_IMETHOD GetFilename(nsACString & aFilename) { return _to GetFilename(aFilename); } \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) { return _to GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetSourceLine(nsACString & aSourceLine) { return _to GetSourceLine(aSourceLine); } \
  NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) { return _to GetCaller(aCaller); } \
  NS_IMETHOD ToString(nsACString & _retval) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTACKFRAME(_to) \
  NS_IMETHOD GetLanguage(uint32_t *aLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_IMETHOD GetLanguageName(nsACString & aLanguageName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguageName(aLanguageName); } \
  NS_IMETHOD GetFilename(nsACString & aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetSourceLine(nsACString & aSourceLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceLine(aSourceLine); } \
  NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaller(aCaller); } \
  NS_IMETHOD ToString(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStackFrame : public nsIStackFrame
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTACKFRAME

  nsStackFrame();

private:
  ~nsStackFrame();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStackFrame, nsIStackFrame)

nsStackFrame::nsStackFrame()
{
  /* member initializers and constructor code */
}

nsStackFrame::~nsStackFrame()
{
  /* destructor code */
}

/* readonly attribute uint32_t language; */
NS_IMETHODIMP nsStackFrame::GetLanguage(uint32_t *aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String languageName; */
NS_IMETHODIMP nsStackFrame::GetLanguageName(nsACString & aLanguageName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String filename; */
NS_IMETHODIMP nsStackFrame::GetFilename(nsACString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsStackFrame::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t lineNumber; */
NS_IMETHODIMP nsStackFrame::GetLineNumber(int32_t *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String sourceLine; */
NS_IMETHODIMP nsStackFrame::GetSourceLine(nsACString & aSourceLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame caller; */
NS_IMETHODIMP nsStackFrame::GetCaller(nsIStackFrame * *aCaller)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toString (); */
NS_IMETHODIMP nsStackFrame::ToString(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIException */
#define NS_IEXCEPTION_IID_STR "6738090a-ba6f-4f3f-8aa0-b9f6311262a5"

#define NS_IEXCEPTION_IID \
  {0x6738090a, 0xba6f, 0x4f3f, \
    { 0x8a, 0xa0, 0xb9, 0xf6, 0x31, 0x12, 0x62, 0xa5 }}

class NS_NO_VTABLE nsIException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXCEPTION_IID)

  /* [binaryname(MessageMoz)] readonly attribute AUTF8String message; */
  NS_IMETHOD GetMessageMoz(nsACString & aMessage) = 0;

  /* readonly attribute nsresult result; */
  NS_IMETHOD GetResult(nsresult *aResult) = 0;

  /* readonly attribute AUTF8String name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute AUTF8String filename; */
  NS_IMETHOD GetFilename(nsACString & aFilename) = 0;

  /* readonly attribute uint32_t lineNumber; */
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) = 0;

  /* readonly attribute uint32_t columnNumber; */
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) = 0;

  /* readonly attribute nsIStackFrame location; */
  NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) = 0;

  /* readonly attribute nsIException inner; */
  NS_IMETHOD GetInner(nsIException * *aInner) = 0;

  /* readonly attribute nsISupports data; */
  NS_IMETHOD GetData(nsISupports * *aData) = 0;

  /* AUTF8String toString (); */
  NS_IMETHOD ToString(nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIException, NS_IEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXCEPTION \
  NS_IMETHOD GetMessageMoz(nsACString & aMessage); \
  NS_IMETHOD GetResult(nsresult *aResult); \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD GetFilename(nsACString & aFilename); \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber); \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber); \
  NS_IMETHOD GetLocation(nsIStackFrame * *aLocation); \
  NS_IMETHOD GetInner(nsIException * *aInner); \
  NS_IMETHOD GetData(nsISupports * *aData); \
  NS_IMETHOD ToString(nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXCEPTION(_to) \
  NS_IMETHOD GetMessageMoz(nsACString & aMessage) { return _to GetMessageMoz(aMessage); } \
  NS_IMETHOD GetResult(nsresult *aResult) { return _to GetResult(aResult); } \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetFilename(nsACString & aFilename) { return _to GetFilename(aFilename); } \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) { return _to GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) { return _to GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) { return _to GetLocation(aLocation); } \
  NS_IMETHOD GetInner(nsIException * *aInner) { return _to GetInner(aInner); } \
  NS_IMETHOD GetData(nsISupports * *aData) { return _to GetData(aData); } \
  NS_IMETHOD ToString(nsACString & _retval) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXCEPTION(_to) \
  NS_IMETHOD GetMessageMoz(nsACString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(aMessage); } \
  NS_IMETHOD GetResult(nsresult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetFilename(nsACString & aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_IMETHOD GetInner(nsIException * *aInner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInner(aInner); } \
  NS_IMETHOD GetData(nsISupports * *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD ToString(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsException : public nsIException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXCEPTION

  nsException();

private:
  ~nsException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsException, nsIException)

nsException::nsException()
{
  /* member initializers and constructor code */
}

nsException::~nsException()
{
  /* destructor code */
}

/* [binaryname(MessageMoz)] readonly attribute AUTF8String message; */
NS_IMETHODIMP nsException::GetMessageMoz(nsACString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsresult result; */
NS_IMETHODIMP nsException::GetResult(nsresult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsException::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String filename; */
NS_IMETHODIMP nsException::GetFilename(nsACString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lineNumber; */
NS_IMETHODIMP nsException::GetLineNumber(uint32_t *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t columnNumber; */
NS_IMETHODIMP nsException::GetColumnNumber(uint32_t *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame location; */
NS_IMETHODIMP nsException::GetLocation(nsIStackFrame * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIException inner; */
NS_IMETHODIMP nsException::GetInner(nsIException * *aInner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports data; */
NS_IMETHODIMP nsException::GetData(nsISupports * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toString (); */
NS_IMETHODIMP nsException::ToString(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIException_h__ */
