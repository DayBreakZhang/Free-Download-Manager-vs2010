/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/places/mozIColorAnalyzer.idl
 */

#ifndef __gen_mozIColorAnalyzer_h__
#define __gen_mozIColorAnalyzer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    mozIRepresentativeColorCallback */
#define MOZIREPRESENTATIVECOLORCALLBACK_IID_STR "e4089e21-71b6-40af-b546-33c21b90e874"

#define MOZIREPRESENTATIVECOLORCALLBACK_IID \
  {0xe4089e21, 0x71b6, 0x40af, \
    { 0xb5, 0x46, 0x33, 0xc2, 0x1b, 0x90, 0xe8, 0x74 }}

class NS_NO_VTABLE mozIRepresentativeColorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIREPRESENTATIVECOLORCALLBACK_IID)

  /* void onComplete (in boolean success, [optional] in unsigned long color); */
  NS_IMETHOD OnComplete(bool success, uint32_t color) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIRepresentativeColorCallback, MOZIREPRESENTATIVECOLORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIREPRESENTATIVECOLORCALLBACK \
  NS_IMETHOD OnComplete(bool success, uint32_t color); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIREPRESENTATIVECOLORCALLBACK(_to) \
  NS_IMETHOD OnComplete(bool success, uint32_t color) { return _to OnComplete(success, color); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIREPRESENTATIVECOLORCALLBACK(_to) \
  NS_IMETHOD OnComplete(bool success, uint32_t color) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnComplete(success, color); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIRepresentativeColorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIREPRESENTATIVECOLORCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIRepresentativeColorCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onComplete (in boolean success, [optional] in unsigned long color); */
NS_IMETHODIMP _MYCLASS_::OnComplete(bool success, uint32_t color)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIColorAnalyzer */
#define MOZICOLORANALYZER_IID_STR "d056186c-28a0-494e-aacc-9e433772b143"

#define MOZICOLORANALYZER_IID \
  {0xd056186c, 0x28a0, 0x494e, \
    { 0xaa, 0xcc, 0x9e, 0x43, 0x37, 0x72, 0xb1, 0x43 }}

class NS_NO_VTABLE mozIColorAnalyzer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZICOLORANALYZER_IID)

  /* void findRepresentativeColor (in nsIURI imageURI, in mozIRepresentativeColorCallback callback); */
  NS_IMETHOD FindRepresentativeColor(nsIURI *imageURI, mozIRepresentativeColorCallback *callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIColorAnalyzer, MOZICOLORANALYZER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZICOLORANALYZER \
  NS_IMETHOD FindRepresentativeColor(nsIURI *imageURI, mozIRepresentativeColorCallback *callback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZICOLORANALYZER(_to) \
  NS_IMETHOD FindRepresentativeColor(nsIURI *imageURI, mozIRepresentativeColorCallback *callback) { return _to FindRepresentativeColor(imageURI, callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZICOLORANALYZER(_to) \
  NS_IMETHOD FindRepresentativeColor(nsIURI *imageURI, mozIRepresentativeColorCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindRepresentativeColor(imageURI, callback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIColorAnalyzer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZICOLORANALYZER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIColorAnalyzer)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void findRepresentativeColor (in nsIURI imageURI, in mozIRepresentativeColorCallback callback); */
NS_IMETHODIMP _MYCLASS_::FindRepresentativeColor(nsIURI *imageURI, mozIRepresentativeColorCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIColorAnalyzer_h__ */
