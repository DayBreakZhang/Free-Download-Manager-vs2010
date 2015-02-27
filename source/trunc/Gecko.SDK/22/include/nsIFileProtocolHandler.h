/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/protocol/file/nsIFileProtocolHandler.idl
 */

#ifndef __gen_nsIFileProtocolHandler_h__
#define __gen_nsIFileProtocolHandler_h__


#ifndef __gen_nsIProtocolHandler_h__
#include "nsIProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIFileProtocolHandler */
#define NS_IFILEPROTOCOLHANDLER_IID_STR "1fb25bd5-4354-4dcd-8d97-621b7b3ed2e4"

#define NS_IFILEPROTOCOLHANDLER_IID \
  {0x1fb25bd5, 0x4354, 0x4dcd, \
    { 0x8d, 0x97, 0x62, 0x1b, 0x7b, 0x3e, 0xd2, 0xe4 }}

class NS_NO_VTABLE nsIFileProtocolHandler : public nsIProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILEPROTOCOLHANDLER_IID)

  /* nsIURI newFileURI (in nsIFile aFile); */
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) = 0;

  /* AUTF8String getURLSpecFromFile (in nsIFile file); */
  NS_IMETHOD GetURLSpecFromFile(nsIFile *file, nsACString & _retval) = 0;

  /* AUTF8String getURLSpecFromActualFile (in nsIFile file); */
  NS_IMETHOD GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval) = 0;

  /* AUTF8String getURLSpecFromDir (in nsIFile file); */
  NS_IMETHOD GetURLSpecFromDir(nsIFile *file, nsACString & _retval) = 0;

  /* nsIFile getFileFromURLSpec (in AUTF8String url); */
  NS_IMETHOD GetFileFromURLSpec(const nsACString & url, nsIFile * *_retval) = 0;

  /* nsIURI readURLFile (in nsIFile file); */
  NS_IMETHOD ReadURLFile(nsIFile *file, nsIURI * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileProtocolHandler, NS_IFILEPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILEPROTOCOLHANDLER \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval); \
  NS_IMETHOD GetURLSpecFromFile(nsIFile *file, nsACString & _retval); \
  NS_IMETHOD GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval); \
  NS_IMETHOD GetURLSpecFromDir(nsIFile *file, nsACString & _retval); \
  NS_IMETHOD GetFileFromURLSpec(const nsACString & url, nsIFile * *_retval); \
  NS_IMETHOD ReadURLFile(nsIFile *file, nsIURI * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILEPROTOCOLHANDLER(_to) \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) { return _to NewFileURI(aFile, _retval); } \
  NS_IMETHOD GetURLSpecFromFile(nsIFile *file, nsACString & _retval) { return _to GetURLSpecFromFile(file, _retval); } \
  NS_IMETHOD GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval) { return _to GetURLSpecFromActualFile(file, _retval); } \
  NS_IMETHOD GetURLSpecFromDir(nsIFile *file, nsACString & _retval) { return _to GetURLSpecFromDir(file, _retval); } \
  NS_IMETHOD GetFileFromURLSpec(const nsACString & url, nsIFile * *_retval) { return _to GetFileFromURLSpec(url, _retval); } \
  NS_IMETHOD ReadURLFile(nsIFile *file, nsIURI * *_retval) { return _to ReadURLFile(file, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILEPROTOCOLHANDLER(_to) \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewFileURI(aFile, _retval); } \
  NS_IMETHOD GetURLSpecFromFile(nsIFile *file, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURLSpecFromFile(file, _retval); } \
  NS_IMETHOD GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURLSpecFromActualFile(file, _retval); } \
  NS_IMETHOD GetURLSpecFromDir(nsIFile *file, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURLSpecFromDir(file, _retval); } \
  NS_IMETHOD GetFileFromURLSpec(const nsACString & url, nsIFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileFromURLSpec(url, _retval); } \
  NS_IMETHOD ReadURLFile(nsIFile *file, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadURLFile(file, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileProtocolHandler : public nsIFileProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEPROTOCOLHANDLER

  nsFileProtocolHandler();

private:
  ~nsFileProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileProtocolHandler, nsIFileProtocolHandler)

nsFileProtocolHandler::nsFileProtocolHandler()
{
  /* member initializers and constructor code */
}

nsFileProtocolHandler::~nsFileProtocolHandler()
{
  /* destructor code */
}

/* nsIURI newFileURI (in nsIFile aFile); */
NS_IMETHODIMP nsFileProtocolHandler::NewFileURI(nsIFile *aFile, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getURLSpecFromFile (in nsIFile file); */
NS_IMETHODIMP nsFileProtocolHandler::GetURLSpecFromFile(nsIFile *file, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getURLSpecFromActualFile (in nsIFile file); */
NS_IMETHODIMP nsFileProtocolHandler::GetURLSpecFromActualFile(nsIFile *file, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getURLSpecFromDir (in nsIFile file); */
NS_IMETHODIMP nsFileProtocolHandler::GetURLSpecFromDir(nsIFile *file, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile getFileFromURLSpec (in AUTF8String url); */
NS_IMETHODIMP nsFileProtocolHandler::GetFileFromURLSpec(const nsACString & url, nsIFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI readURLFile (in nsIFile file); */
NS_IMETHODIMP nsFileProtocolHandler::ReadURLFile(nsIFile *file, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFileProtocolHandler_h__ */
