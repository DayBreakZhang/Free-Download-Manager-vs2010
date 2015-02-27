/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/core/nsIDOMCharacterData.idl
 */

#ifndef __gen_nsIDOMCharacterData_h__
#define __gen_nsIDOMCharacterData_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCharacterData */
#define NS_IDOMCHARACTERDATA_IID_STR "05c29ae6-5533-42b6-9085-257f60445d5a"

#define NS_IDOMCHARACTERDATA_IID \
  {0x05c29ae6, 0x5533, 0x42b6, \
    { 0x90, 0x85, 0x25, 0x7f, 0x60, 0x44, 0x5d, 0x5a }}

class NS_NO_VTABLE nsIDOMCharacterData : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCHARACTERDATA_IID)

  /* attribute DOMString data; */
  NS_IMETHOD GetData(nsAString & aData) = 0;
  NS_IMETHOD SetData(const nsAString & aData) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* DOMString substringData (in unsigned long offset, in unsigned long count) raises (DOMException); */
  NS_IMETHOD SubstringData(uint32_t offset, uint32_t count, nsAString & _retval) = 0;

  /* void appendData (in DOMString arg) raises (DOMException); */
  NS_IMETHOD AppendData(const nsAString & arg) = 0;

  /* void insertData (in unsigned long offset, in DOMString arg) raises (DOMException); */
  NS_IMETHOD InsertData(uint32_t offset, const nsAString & arg) = 0;

  /* void deleteData (in unsigned long offset, in unsigned long count) raises (DOMException); */
  NS_IMETHOD DeleteData(uint32_t offset, uint32_t count) = 0;

  /* void replaceData (in unsigned long offset, in unsigned long count, in DOMString arg) raises (DOMException); */
  NS_IMETHOD ReplaceData(uint32_t offset, uint32_t count, const nsAString & arg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCharacterData, NS_IDOMCHARACTERDATA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCHARACTERDATA \
  NS_IMETHOD GetData(nsAString & aData); \
  NS_IMETHOD SetData(const nsAString & aData); \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD SubstringData(uint32_t offset, uint32_t count, nsAString & _retval); \
  NS_IMETHOD AppendData(const nsAString & arg); \
  NS_IMETHOD InsertData(uint32_t offset, const nsAString & arg); \
  NS_IMETHOD DeleteData(uint32_t offset, uint32_t count); \
  NS_IMETHOD ReplaceData(uint32_t offset, uint32_t count, const nsAString & arg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCHARACTERDATA(_to) \
  NS_IMETHOD GetData(nsAString & aData) { return _to GetData(aData); } \
  NS_IMETHOD SetData(const nsAString & aData) { return _to SetData(aData); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD SubstringData(uint32_t offset, uint32_t count, nsAString & _retval) { return _to SubstringData(offset, count, _retval); } \
  NS_IMETHOD AppendData(const nsAString & arg) { return _to AppendData(arg); } \
  NS_IMETHOD InsertData(uint32_t offset, const nsAString & arg) { return _to InsertData(offset, arg); } \
  NS_IMETHOD DeleteData(uint32_t offset, uint32_t count) { return _to DeleteData(offset, count); } \
  NS_IMETHOD ReplaceData(uint32_t offset, uint32_t count, const nsAString & arg) { return _to ReplaceData(offset, count, arg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCHARACTERDATA(_to) \
  NS_IMETHOD GetData(nsAString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD SetData(const nsAString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(aData); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD SubstringData(uint32_t offset, uint32_t count, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubstringData(offset, count, _retval); } \
  NS_IMETHOD AppendData(const nsAString & arg) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendData(arg); } \
  NS_IMETHOD InsertData(uint32_t offset, const nsAString & arg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertData(offset, arg); } \
  NS_IMETHOD DeleteData(uint32_t offset, uint32_t count) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteData(offset, count); } \
  NS_IMETHOD ReplaceData(uint32_t offset, uint32_t count, const nsAString & arg) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceData(offset, count, arg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCharacterData : public nsIDOMCharacterData
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCHARACTERDATA

  nsDOMCharacterData();

private:
  ~nsDOMCharacterData();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCharacterData, nsIDOMCharacterData)

nsDOMCharacterData::nsDOMCharacterData()
{
  /* member initializers and constructor code */
}

nsDOMCharacterData::~nsDOMCharacterData()
{
  /* destructor code */
}

/* attribute DOMString data; */
NS_IMETHODIMP nsDOMCharacterData::GetData(nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCharacterData::SetData(const nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMCharacterData::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString substringData (in unsigned long offset, in unsigned long count) raises (DOMException); */
NS_IMETHODIMP nsDOMCharacterData::SubstringData(uint32_t offset, uint32_t count, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendData (in DOMString arg) raises (DOMException); */
NS_IMETHODIMP nsDOMCharacterData::AppendData(const nsAString & arg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertData (in unsigned long offset, in DOMString arg) raises (DOMException); */
NS_IMETHODIMP nsDOMCharacterData::InsertData(uint32_t offset, const nsAString & arg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteData (in unsigned long offset, in unsigned long count) raises (DOMException); */
NS_IMETHODIMP nsDOMCharacterData::DeleteData(uint32_t offset, uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceData (in unsigned long offset, in unsigned long count, in DOMString arg) raises (DOMException); */
NS_IMETHODIMP nsDOMCharacterData::ReplaceData(uint32_t offset, uint32_t count, const nsAString & arg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCharacterData_h__ */
