/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/layout/base/nsIStyleSheetService.idl
 */

#ifndef __gen_nsIStyleSheetService_h__
#define __gen_nsIStyleSheetService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIStyleSheetService */
#define NS_ISTYLESHEETSERVICE_IID_STR "1f42a6a2-ab0a-45d4-8a96-396f58ea6c6d"

#define NS_ISTYLESHEETSERVICE_IID \
  {0x1f42a6a2, 0xab0a, 0x45d4, \
    { 0x8a, 0x96, 0x39, 0x6f, 0x58, 0xea, 0x6c, 0x6d }}

class NS_NO_VTABLE nsIStyleSheetService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTYLESHEETSERVICE_IID)

  enum {
    AGENT_SHEET = 0U,
    USER_SHEET = 1U,
    AUTHOR_SHEET = 2U
  };

  /* void loadAndRegisterSheet (in nsIURI sheetURI, in unsigned long type); */
  NS_IMETHOD LoadAndRegisterSheet(nsIURI *sheetURI, uint32_t type) = 0;

  /* boolean sheetRegistered (in nsIURI sheetURI, in unsigned long type); */
  NS_IMETHOD SheetRegistered(nsIURI *sheetURI, uint32_t type, bool *_retval) = 0;

  /* void unregisterSheet (in nsIURI sheetURI, in unsigned long type); */
  NS_IMETHOD UnregisterSheet(nsIURI *sheetURI, uint32_t type) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStyleSheetService, NS_ISTYLESHEETSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTYLESHEETSERVICE \
  NS_IMETHOD LoadAndRegisterSheet(nsIURI *sheetURI, uint32_t type); \
  NS_IMETHOD SheetRegistered(nsIURI *sheetURI, uint32_t type, bool *_retval); \
  NS_IMETHOD UnregisterSheet(nsIURI *sheetURI, uint32_t type); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTYLESHEETSERVICE(_to) \
  NS_IMETHOD LoadAndRegisterSheet(nsIURI *sheetURI, uint32_t type) { return _to LoadAndRegisterSheet(sheetURI, type); } \
  NS_IMETHOD SheetRegistered(nsIURI *sheetURI, uint32_t type, bool *_retval) { return _to SheetRegistered(sheetURI, type, _retval); } \
  NS_IMETHOD UnregisterSheet(nsIURI *sheetURI, uint32_t type) { return _to UnregisterSheet(sheetURI, type); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTYLESHEETSERVICE(_to) \
  NS_IMETHOD LoadAndRegisterSheet(nsIURI *sheetURI, uint32_t type) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadAndRegisterSheet(sheetURI, type); } \
  NS_IMETHOD SheetRegistered(nsIURI *sheetURI, uint32_t type, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SheetRegistered(sheetURI, type, _retval); } \
  NS_IMETHOD UnregisterSheet(nsIURI *sheetURI, uint32_t type) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterSheet(sheetURI, type); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStyleSheetService : public nsIStyleSheetService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTYLESHEETSERVICE

  nsStyleSheetService();

private:
  ~nsStyleSheetService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStyleSheetService, nsIStyleSheetService)

nsStyleSheetService::nsStyleSheetService()
{
  /* member initializers and constructor code */
}

nsStyleSheetService::~nsStyleSheetService()
{
  /* destructor code */
}

/* void loadAndRegisterSheet (in nsIURI sheetURI, in unsigned long type); */
NS_IMETHODIMP nsStyleSheetService::LoadAndRegisterSheet(nsIURI *sheetURI, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sheetRegistered (in nsIURI sheetURI, in unsigned long type); */
NS_IMETHODIMP nsStyleSheetService::SheetRegistered(nsIURI *sheetURI, uint32_t type, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterSheet (in nsIURI sheetURI, in unsigned long type); */
NS_IMETHODIMP nsStyleSheetService::UnregisterSheet(nsIURI *sheetURI, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStyleSheetService_h__ */
