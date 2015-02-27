/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICommandLine.idl
 */

#ifndef __gen_nsICommandLine_h__
#define __gen_nsICommandLine_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsICommandLine */
#define NS_ICOMMANDLINE_IID_STR "bc3173bd-aa46-46a0-9d25-d9867a9659b6"

#define NS_ICOMMANDLINE_IID \
  {0xbc3173bd, 0xaa46, 0x46a0, \
    { 0x9d, 0x25, 0xd9, 0x86, 0x7a, 0x96, 0x59, 0xb6 }}

class NS_NO_VTABLE nsICommandLine : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDLINE_IID)

  /* readonly attribute long length; */
  NS_IMETHOD GetLength(int32_t *aLength) = 0;

  /* AString getArgument (in long aIndex); */
  NS_IMETHOD GetArgument(int32_t aIndex, nsAString & _retval) = 0;

  /* long findFlag (in AString aFlag, in boolean aCaseSensitive); */
  NS_IMETHOD FindFlag(const nsAString & aFlag, bool aCaseSensitive, int32_t *_retval) = 0;

  /* void removeArguments (in long aStart, in long aEnd); */
  NS_IMETHOD RemoveArguments(int32_t aStart, int32_t aEnd) = 0;

  /* boolean handleFlag (in AString aFlag, in boolean aCaseSensitive); */
  NS_IMETHOD HandleFlag(const nsAString & aFlag, bool aCaseSensitive, bool *_retval) = 0;

  /* AString handleFlagWithParam (in AString aFlag, in boolean aCaseSensitive); */
  NS_IMETHOD HandleFlagWithParam(const nsAString & aFlag, bool aCaseSensitive, nsAString & _retval) = 0;

  /* readonly attribute unsigned long state; */
  NS_IMETHOD GetState(uint32_t *aState) = 0;

  enum {
    STATE_INITIAL_LAUNCH = 0U,
    STATE_REMOTE_AUTO = 1U,
    STATE_REMOTE_EXPLICIT = 2U
  };

  /* attribute boolean preventDefault; */
  NS_IMETHOD GetPreventDefault(bool *aPreventDefault) = 0;
  NS_IMETHOD SetPreventDefault(bool aPreventDefault) = 0;

  /* readonly attribute nsIFile workingDirectory; */
  NS_IMETHOD GetWorkingDirectory(nsIFile * *aWorkingDirectory) = 0;

  /* readonly attribute nsIDOMWindow windowContext; */
  NS_IMETHOD GetWindowContext(nsIDOMWindow * *aWindowContext) = 0;

  /* nsIFile resolveFile (in AString aArgument); */
  NS_IMETHOD ResolveFile(const nsAString & aArgument, nsIFile * *_retval) = 0;

  /* nsIURI resolveURI (in AString aArgument); */
  NS_IMETHOD ResolveURI(const nsAString & aArgument, nsIURI * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandLine, NS_ICOMMANDLINE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDLINE \
  NS_IMETHOD GetLength(int32_t *aLength); \
  NS_IMETHOD GetArgument(int32_t aIndex, nsAString & _retval); \
  NS_IMETHOD FindFlag(const nsAString & aFlag, bool aCaseSensitive, int32_t *_retval); \
  NS_IMETHOD RemoveArguments(int32_t aStart, int32_t aEnd); \
  NS_IMETHOD HandleFlag(const nsAString & aFlag, bool aCaseSensitive, bool *_retval); \
  NS_IMETHOD HandleFlagWithParam(const nsAString & aFlag, bool aCaseSensitive, nsAString & _retval); \
  NS_IMETHOD GetState(uint32_t *aState); \
  NS_IMETHOD GetPreventDefault(bool *aPreventDefault); \
  NS_IMETHOD SetPreventDefault(bool aPreventDefault); \
  NS_IMETHOD GetWorkingDirectory(nsIFile * *aWorkingDirectory); \
  NS_IMETHOD GetWindowContext(nsIDOMWindow * *aWindowContext); \
  NS_IMETHOD ResolveFile(const nsAString & aArgument, nsIFile * *_retval); \
  NS_IMETHOD ResolveURI(const nsAString & aArgument, nsIURI * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDLINE(_to) \
  NS_IMETHOD GetLength(int32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD GetArgument(int32_t aIndex, nsAString & _retval) { return _to GetArgument(aIndex, _retval); } \
  NS_IMETHOD FindFlag(const nsAString & aFlag, bool aCaseSensitive, int32_t *_retval) { return _to FindFlag(aFlag, aCaseSensitive, _retval); } \
  NS_IMETHOD RemoveArguments(int32_t aStart, int32_t aEnd) { return _to RemoveArguments(aStart, aEnd); } \
  NS_IMETHOD HandleFlag(const nsAString & aFlag, bool aCaseSensitive, bool *_retval) { return _to HandleFlag(aFlag, aCaseSensitive, _retval); } \
  NS_IMETHOD HandleFlagWithParam(const nsAString & aFlag, bool aCaseSensitive, nsAString & _retval) { return _to HandleFlagWithParam(aFlag, aCaseSensitive, _retval); } \
  NS_IMETHOD GetState(uint32_t *aState) { return _to GetState(aState); } \
  NS_IMETHOD GetPreventDefault(bool *aPreventDefault) { return _to GetPreventDefault(aPreventDefault); } \
  NS_IMETHOD SetPreventDefault(bool aPreventDefault) { return _to SetPreventDefault(aPreventDefault); } \
  NS_IMETHOD GetWorkingDirectory(nsIFile * *aWorkingDirectory) { return _to GetWorkingDirectory(aWorkingDirectory); } \
  NS_IMETHOD GetWindowContext(nsIDOMWindow * *aWindowContext) { return _to GetWindowContext(aWindowContext); } \
  NS_IMETHOD ResolveFile(const nsAString & aArgument, nsIFile * *_retval) { return _to ResolveFile(aArgument, _retval); } \
  NS_IMETHOD ResolveURI(const nsAString & aArgument, nsIURI * *_retval) { return _to ResolveURI(aArgument, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDLINE(_to) \
  NS_IMETHOD GetLength(int32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetArgument(int32_t aIndex, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetArgument(aIndex, _retval); } \
  NS_IMETHOD FindFlag(const nsAString & aFlag, bool aCaseSensitive, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindFlag(aFlag, aCaseSensitive, _retval); } \
  NS_IMETHOD RemoveArguments(int32_t aStart, int32_t aEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveArguments(aStart, aEnd); } \
  NS_IMETHOD HandleFlag(const nsAString & aFlag, bool aCaseSensitive, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleFlag(aFlag, aCaseSensitive, _retval); } \
  NS_IMETHOD HandleFlagWithParam(const nsAString & aFlag, bool aCaseSensitive, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleFlagWithParam(aFlag, aCaseSensitive, _retval); } \
  NS_IMETHOD GetState(uint32_t *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD GetPreventDefault(bool *aPreventDefault) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreventDefault(aPreventDefault); } \
  NS_IMETHOD SetPreventDefault(bool aPreventDefault) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreventDefault(aPreventDefault); } \
  NS_IMETHOD GetWorkingDirectory(nsIFile * *aWorkingDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWorkingDirectory(aWorkingDirectory); } \
  NS_IMETHOD GetWindowContext(nsIDOMWindow * *aWindowContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowContext(aWindowContext); } \
  NS_IMETHOD ResolveFile(const nsAString & aArgument, nsIFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResolveFile(aArgument, _retval); } \
  NS_IMETHOD ResolveURI(const nsAString & aArgument, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResolveURI(aArgument, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandLine : public nsICommandLine
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDLINE

  nsCommandLine();

private:
  ~nsCommandLine();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandLine, nsICommandLine)

nsCommandLine::nsCommandLine()
{
  /* member initializers and constructor code */
}

nsCommandLine::~nsCommandLine()
{
  /* destructor code */
}

/* readonly attribute long length; */
NS_IMETHODIMP nsCommandLine::GetLength(int32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getArgument (in long aIndex); */
NS_IMETHODIMP nsCommandLine::GetArgument(int32_t aIndex, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long findFlag (in AString aFlag, in boolean aCaseSensitive); */
NS_IMETHODIMP nsCommandLine::FindFlag(const nsAString & aFlag, bool aCaseSensitive, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeArguments (in long aStart, in long aEnd); */
NS_IMETHODIMP nsCommandLine::RemoveArguments(int32_t aStart, int32_t aEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleFlag (in AString aFlag, in boolean aCaseSensitive); */
NS_IMETHODIMP nsCommandLine::HandleFlag(const nsAString & aFlag, bool aCaseSensitive, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString handleFlagWithParam (in AString aFlag, in boolean aCaseSensitive); */
NS_IMETHODIMP nsCommandLine::HandleFlagWithParam(const nsAString & aFlag, bool aCaseSensitive, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long state; */
NS_IMETHODIMP nsCommandLine::GetState(uint32_t *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean preventDefault; */
NS_IMETHODIMP nsCommandLine::GetPreventDefault(bool *aPreventDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCommandLine::SetPreventDefault(bool aPreventDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile workingDirectory; */
NS_IMETHODIMP nsCommandLine::GetWorkingDirectory(nsIFile * *aWorkingDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow windowContext; */
NS_IMETHODIMP nsCommandLine::GetWindowContext(nsIDOMWindow * *aWindowContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile resolveFile (in AString aArgument); */
NS_IMETHODIMP nsCommandLine::ResolveFile(const nsAString & aArgument, nsIFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI resolveURI (in AString aArgument); */
NS_IMETHODIMP nsCommandLine::ResolveURI(const nsAString & aArgument, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICommandLine_h__ */
