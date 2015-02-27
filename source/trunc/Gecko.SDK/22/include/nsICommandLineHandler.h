/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/commandlines/nsICommandLineHandler.idl
 */

#ifndef __gen_nsICommandLineHandler_h__
#define __gen_nsICommandLineHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICommandLine; /* forward declaration */


/* starting interface:    nsICommandLineHandler */
#define NS_ICOMMANDLINEHANDLER_IID_STR "d4b123df-51ee-48b1-a663-002180e60d3b"

#define NS_ICOMMANDLINEHANDLER_IID \
  {0xd4b123df, 0x51ee, 0x48b1, \
    { 0xa6, 0x63, 0x00, 0x21, 0x80, 0xe6, 0x0d, 0x3b }}

class NS_NO_VTABLE nsICommandLineHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDLINEHANDLER_IID)

  /* void handle (in nsICommandLine aCommandLine); */
  NS_IMETHOD Handle(nsICommandLine *aCommandLine) = 0;

  /* readonly attribute AUTF8String helpInfo; */
  NS_IMETHOD GetHelpInfo(nsACString & aHelpInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandLineHandler, NS_ICOMMANDLINEHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDLINEHANDLER \
  NS_IMETHOD Handle(nsICommandLine *aCommandLine); \
  NS_IMETHOD GetHelpInfo(nsACString & aHelpInfo); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDLINEHANDLER(_to) \
  NS_IMETHOD Handle(nsICommandLine *aCommandLine) { return _to Handle(aCommandLine); } \
  NS_IMETHOD GetHelpInfo(nsACString & aHelpInfo) { return _to GetHelpInfo(aHelpInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDLINEHANDLER(_to) \
  NS_IMETHOD Handle(nsICommandLine *aCommandLine) { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(aCommandLine); } \
  NS_IMETHOD GetHelpInfo(nsACString & aHelpInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHelpInfo(aHelpInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandLineHandler : public nsICommandLineHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDLINEHANDLER

  nsCommandLineHandler();

private:
  ~nsCommandLineHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandLineHandler, nsICommandLineHandler)

nsCommandLineHandler::nsCommandLineHandler()
{
  /* member initializers and constructor code */
}

nsCommandLineHandler::~nsCommandLineHandler()
{
  /* destructor code */
}

/* void handle (in nsICommandLine aCommandLine); */
NS_IMETHODIMP nsCommandLineHandler::Handle(nsICommandLine *aCommandLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String helpInfo; */
NS_IMETHODIMP nsCommandLineHandler::GetHelpInfo(nsACString & aHelpInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICommandLineHandler_h__ */
