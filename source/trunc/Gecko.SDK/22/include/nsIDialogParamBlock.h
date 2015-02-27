/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/components/windowwatcher/public/nsIDialogParamBlock.idl
 */

#ifndef __gen_nsIDialogParamBlock_h__
#define __gen_nsIDialogParamBlock_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMutableArray; /* forward declaration */


/* starting interface:    nsIDialogParamBlock */
#define NS_IDIALOGPARAMBLOCK_IID_STR "f76c0901-437a-11d3-b7a0-e35db351b4bc"

#define NS_IDIALOGPARAMBLOCK_IID \
  {0xf76c0901, 0x437a, 0x11d3, \
    { 0xb7, 0xa0, 0xe3, 0x5d, 0xb3, 0x51, 0xb4, 0xbc }}

class NS_NO_VTABLE nsIDialogParamBlock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIALOGPARAMBLOCK_IID)

  /* int32_t GetInt (in int32_t inIndex); */
  NS_IMETHOD GetInt(int32_t inIndex, int32_t *_retval) = 0;

  /* void SetInt (in int32_t inIndex, in int32_t inInt); */
  NS_IMETHOD SetInt(int32_t inIndex, int32_t inInt) = 0;

  /* void SetNumberStrings (in int32_t inNumStrings); */
  NS_IMETHOD SetNumberStrings(int32_t inNumStrings) = 0;

  /* wstring GetString (in int32_t inIndex); */
  NS_IMETHOD GetString(int32_t inIndex, PRUnichar * *_retval) = 0;

  /* void SetString (in int32_t inIndex, in wstring inString); */
  NS_IMETHOD SetString(int32_t inIndex, const PRUnichar * inString) = 0;

  /* attribute nsIMutableArray objects; */
  NS_IMETHOD GetObjects(nsIMutableArray * *aObjects) = 0;
  NS_IMETHOD SetObjects(nsIMutableArray *aObjects) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDialogParamBlock, NS_IDIALOGPARAMBLOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIALOGPARAMBLOCK \
  NS_IMETHOD GetInt(int32_t inIndex, int32_t *_retval); \
  NS_IMETHOD SetInt(int32_t inIndex, int32_t inInt); \
  NS_IMETHOD SetNumberStrings(int32_t inNumStrings); \
  NS_IMETHOD GetString(int32_t inIndex, PRUnichar * *_retval); \
  NS_IMETHOD SetString(int32_t inIndex, const PRUnichar * inString); \
  NS_IMETHOD GetObjects(nsIMutableArray * *aObjects); \
  NS_IMETHOD SetObjects(nsIMutableArray *aObjects); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIALOGPARAMBLOCK(_to) \
  NS_IMETHOD GetInt(int32_t inIndex, int32_t *_retval) { return _to GetInt(inIndex, _retval); } \
  NS_IMETHOD SetInt(int32_t inIndex, int32_t inInt) { return _to SetInt(inIndex, inInt); } \
  NS_IMETHOD SetNumberStrings(int32_t inNumStrings) { return _to SetNumberStrings(inNumStrings); } \
  NS_IMETHOD GetString(int32_t inIndex, PRUnichar * *_retval) { return _to GetString(inIndex, _retval); } \
  NS_IMETHOD SetString(int32_t inIndex, const PRUnichar * inString) { return _to SetString(inIndex, inString); } \
  NS_IMETHOD GetObjects(nsIMutableArray * *aObjects) { return _to GetObjects(aObjects); } \
  NS_IMETHOD SetObjects(nsIMutableArray *aObjects) { return _to SetObjects(aObjects); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIALOGPARAMBLOCK(_to) \
  NS_IMETHOD GetInt(int32_t inIndex, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt(inIndex, _retval); } \
  NS_IMETHOD SetInt(int32_t inIndex, int32_t inInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInt(inIndex, inInt); } \
  NS_IMETHOD SetNumberStrings(int32_t inNumStrings) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNumberStrings(inNumStrings); } \
  NS_IMETHOD GetString(int32_t inIndex, PRUnichar * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(inIndex, _retval); } \
  NS_IMETHOD SetString(int32_t inIndex, const PRUnichar * inString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetString(inIndex, inString); } \
  NS_IMETHOD GetObjects(nsIMutableArray * *aObjects) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjects(aObjects); } \
  NS_IMETHOD SetObjects(nsIMutableArray *aObjects) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObjects(aObjects); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDialogParamBlock : public nsIDialogParamBlock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIALOGPARAMBLOCK

  nsDialogParamBlock();

private:
  ~nsDialogParamBlock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDialogParamBlock, nsIDialogParamBlock)

nsDialogParamBlock::nsDialogParamBlock()
{
  /* member initializers and constructor code */
}

nsDialogParamBlock::~nsDialogParamBlock()
{
  /* destructor code */
}

/* int32_t GetInt (in int32_t inIndex); */
NS_IMETHODIMP nsDialogParamBlock::GetInt(int32_t inIndex, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetInt (in int32_t inIndex, in int32_t inInt); */
NS_IMETHODIMP nsDialogParamBlock::SetInt(int32_t inIndex, int32_t inInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetNumberStrings (in int32_t inNumStrings); */
NS_IMETHODIMP nsDialogParamBlock::SetNumberStrings(int32_t inNumStrings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetString (in int32_t inIndex); */
NS_IMETHODIMP nsDialogParamBlock::GetString(int32_t inIndex, PRUnichar * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetString (in int32_t inIndex, in wstring inString); */
NS_IMETHODIMP nsDialogParamBlock::SetString(int32_t inIndex, const PRUnichar * inString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIMutableArray objects; */
NS_IMETHODIMP nsDialogParamBlock::GetObjects(nsIMutableArray * *aObjects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDialogParamBlock::SetObjects(nsIMutableArray *aObjects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_DIALOGPARAMBLOCK_CONTRACTID "@mozilla.org/embedcomp/dialogparam;1"

#endif /* __gen_nsIDialogParamBlock_h__ */
