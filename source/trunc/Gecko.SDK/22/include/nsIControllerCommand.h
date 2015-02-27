/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/components/commandhandler/public/nsIControllerCommand.idl
 */

#ifndef __gen_nsIControllerCommand_h__
#define __gen_nsIControllerCommand_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsICommandParams_h__
#include "nsICommandParams.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIControllerCommand */
#define NS_ICONTROLLERCOMMAND_IID_STR "0eae9a46-1dd2-11b2-aca0-9176f05fe9db"

#define NS_ICONTROLLERCOMMAND_IID \
  {0x0eae9a46, 0x1dd2, 0x11b2, \
    { 0xac, 0xa0, 0x91, 0x76, 0xf0, 0x5f, 0xe9, 0xdb }}

class NS_NO_VTABLE nsIControllerCommand : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTROLLERCOMMAND_IID)

  /* boolean isCommandEnabled (in string aCommandName, in nsISupports aCommandContext); */
  NS_IMETHOD IsCommandEnabled(const char * aCommandName, nsISupports *aCommandContext, bool *_retval) = 0;

  /* void getCommandStateParams (in string aCommandName, in nsICommandParams aParams, in nsISupports aCommandContext); */
  NS_IMETHOD GetCommandStateParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) = 0;

  /* void doCommand (in string aCommandName, in nsISupports aCommandContext); */
  NS_IMETHOD DoCommand(const char * aCommandName, nsISupports *aCommandContext) = 0;

  /* void doCommandParams (in string aCommandName, in nsICommandParams aParams, in nsISupports aCommandContext); */
  NS_IMETHOD DoCommandParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIControllerCommand, NS_ICONTROLLERCOMMAND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTROLLERCOMMAND \
  NS_IMETHOD IsCommandEnabled(const char * aCommandName, nsISupports *aCommandContext, bool *_retval); \
  NS_IMETHOD GetCommandStateParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext); \
  NS_IMETHOD DoCommand(const char * aCommandName, nsISupports *aCommandContext); \
  NS_IMETHOD DoCommandParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTROLLERCOMMAND(_to) \
  NS_IMETHOD IsCommandEnabled(const char * aCommandName, nsISupports *aCommandContext, bool *_retval) { return _to IsCommandEnabled(aCommandName, aCommandContext, _retval); } \
  NS_IMETHOD GetCommandStateParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) { return _to GetCommandStateParams(aCommandName, aParams, aCommandContext); } \
  NS_IMETHOD DoCommand(const char * aCommandName, nsISupports *aCommandContext) { return _to DoCommand(aCommandName, aCommandContext); } \
  NS_IMETHOD DoCommandParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) { return _to DoCommandParams(aCommandName, aParams, aCommandContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTROLLERCOMMAND(_to) \
  NS_IMETHOD IsCommandEnabled(const char * aCommandName, nsISupports *aCommandContext, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(aCommandName, aCommandContext, _retval); } \
  NS_IMETHOD GetCommandStateParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandStateParams(aCommandName, aParams, aCommandContext); } \
  NS_IMETHOD DoCommand(const char * aCommandName, nsISupports *aCommandContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(aCommandName, aCommandContext); } \
  NS_IMETHOD DoCommandParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommandParams(aCommandName, aParams, aCommandContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsControllerCommand : public nsIControllerCommand
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTROLLERCOMMAND

  nsControllerCommand();

private:
  ~nsControllerCommand();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsControllerCommand, nsIControllerCommand)

nsControllerCommand::nsControllerCommand()
{
  /* member initializers and constructor code */
}

nsControllerCommand::~nsControllerCommand()
{
  /* destructor code */
}

/* boolean isCommandEnabled (in string aCommandName, in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerCommand::IsCommandEnabled(const char * aCommandName, nsISupports *aCommandContext, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCommandStateParams (in string aCommandName, in nsICommandParams aParams, in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerCommand::GetCommandStateParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommand (in string aCommandName, in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerCommand::DoCommand(const char * aCommandName, nsISupports *aCommandContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommandParams (in string aCommandName, in nsICommandParams aParams, in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerCommand::DoCommandParams(const char * aCommandName, nsICommandParams *aParams, nsISupports *aCommandContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIControllerCommand_h__ */
