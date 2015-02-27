/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/ds/nsIWindowsRegKey.idl
 */

#ifndef __gen_nsIWindowsRegKey_h__
#define __gen_nsIWindowsRegKey_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWindowsRegKey */
#define NS_IWINDOWSREGKEY_IID_STR "2555b930-d64f-437e-9be7-0a2cb252c1f4"

#define NS_IWINDOWSREGKEY_IID \
  {0x2555b930, 0xd64f, 0x437e, \
    { 0x9b, 0xe7, 0x0a, 0x2c, 0xb2, 0x52, 0xc1, 0xf4 }}

class NS_NO_VTABLE nsIWindowsRegKey : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWSREGKEY_IID)

  enum {
    ROOT_KEY_CLASSES_ROOT = 2147483648U,
    ROOT_KEY_CURRENT_USER = 2147483649U,
    ROOT_KEY_LOCAL_MACHINE = 2147483650U,
    ACCESS_BASIC = 131072U,
    ACCESS_QUERY_VALUE = 1U,
    ACCESS_SET_VALUE = 2U,
    ACCESS_CREATE_SUB_KEY = 4U,
    ACCESS_ENUMERATE_SUB_KEYS = 8U,
    ACCESS_NOTIFY = 16U,
    ACCESS_READ = 131097U,
    ACCESS_WRITE = 131078U,
    ACCESS_ALL = 131103U,
    WOW64_32 = 512U,
    WOW64_64 = 256U,
    TYPE_NONE = 0U,
    TYPE_STRING = 1U,
    TYPE_BINARY = 3U,
    TYPE_INT = 4U,
    TYPE_INT64 = 11U
  };

  /* [noscript] attribute HKEY key; */
  NS_IMETHOD GetKey(HKEY *aKey) = 0;
  NS_IMETHOD SetKey(HKEY aKey) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void open (in unsigned long rootKey, in AString relPath, in unsigned long mode); */
  NS_IMETHOD Open(uint32_t rootKey, const nsAString & relPath, uint32_t mode) = 0;

  /* void create (in unsigned long rootKey, in AString relPath, in unsigned long mode); */
  NS_IMETHOD Create(uint32_t rootKey, const nsAString & relPath, uint32_t mode) = 0;

  /* nsIWindowsRegKey openChild (in AString relPath, in unsigned long mode); */
  NS_IMETHOD OpenChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval) = 0;

  /* nsIWindowsRegKey createChild (in AString relPath, in unsigned long mode); */
  NS_IMETHOD CreateChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval) = 0;

  /* readonly attribute unsigned long childCount; */
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) = 0;

  /* AString getChildName (in unsigned long index); */
  NS_IMETHOD GetChildName(uint32_t index, nsAString & _retval) = 0;

  /* boolean hasChild (in AString name); */
  NS_IMETHOD HasChild(const nsAString & name, bool *_retval) = 0;

  /* readonly attribute unsigned long valueCount; */
  NS_IMETHOD GetValueCount(uint32_t *aValueCount) = 0;

  /* AString getValueName (in unsigned long index); */
  NS_IMETHOD GetValueName(uint32_t index, nsAString & _retval) = 0;

  /* boolean hasValue (in AString name); */
  NS_IMETHOD HasValue(const nsAString & name, bool *_retval) = 0;

  /* void removeChild (in AString relPath); */
  NS_IMETHOD RemoveChild(const nsAString & relPath) = 0;

  /* void removeValue (in AString name); */
  NS_IMETHOD RemoveValue(const nsAString & name) = 0;

  /* unsigned long getValueType (in AString name); */
  NS_IMETHOD GetValueType(const nsAString & name, uint32_t *_retval) = 0;

  /* AString readStringValue (in AString name); */
  NS_IMETHOD ReadStringValue(const nsAString & name, nsAString & _retval) = 0;

  /* unsigned long readIntValue (in AString name); */
  NS_IMETHOD ReadIntValue(const nsAString & name, uint32_t *_retval) = 0;

  /* unsigned long long readInt64Value (in AString name); */
  NS_IMETHOD ReadInt64Value(const nsAString & name, uint64_t *_retval) = 0;

  /* ACString readBinaryValue (in AString name); */
  NS_IMETHOD ReadBinaryValue(const nsAString & name, nsACString & _retval) = 0;

  /* void writeStringValue (in AString name, in AString data); */
  NS_IMETHOD WriteStringValue(const nsAString & name, const nsAString & data) = 0;

  /* void writeIntValue (in AString name, in unsigned long data); */
  NS_IMETHOD WriteIntValue(const nsAString & name, uint32_t data) = 0;

  /* void writeInt64Value (in AString name, in unsigned long long data); */
  NS_IMETHOD WriteInt64Value(const nsAString & name, uint64_t data) = 0;

  /* void writeBinaryValue (in AString name, in ACString data); */
  NS_IMETHOD WriteBinaryValue(const nsAString & name, const nsACString & data) = 0;

  /* void startWatching (in boolean recurse); */
  NS_IMETHOD StartWatching(bool recurse) = 0;

  /* void stopWatching (); */
  NS_IMETHOD StopWatching(void) = 0;

  /* boolean isWatching (); */
  NS_IMETHOD IsWatching(bool *_retval) = 0;

  /* boolean hasChanged (); */
  NS_IMETHOD HasChanged(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowsRegKey, NS_IWINDOWSREGKEY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWSREGKEY \
  NS_IMETHOD GetKey(HKEY *aKey); \
  NS_IMETHOD SetKey(HKEY aKey); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD Open(uint32_t rootKey, const nsAString & relPath, uint32_t mode); \
  NS_IMETHOD Create(uint32_t rootKey, const nsAString & relPath, uint32_t mode); \
  NS_IMETHOD OpenChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval); \
  NS_IMETHOD CreateChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval); \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount); \
  NS_IMETHOD GetChildName(uint32_t index, nsAString & _retval); \
  NS_IMETHOD HasChild(const nsAString & name, bool *_retval); \
  NS_IMETHOD GetValueCount(uint32_t *aValueCount); \
  NS_IMETHOD GetValueName(uint32_t index, nsAString & _retval); \
  NS_IMETHOD HasValue(const nsAString & name, bool *_retval); \
  NS_IMETHOD RemoveChild(const nsAString & relPath); \
  NS_IMETHOD RemoveValue(const nsAString & name); \
  NS_IMETHOD GetValueType(const nsAString & name, uint32_t *_retval); \
  NS_IMETHOD ReadStringValue(const nsAString & name, nsAString & _retval); \
  NS_IMETHOD ReadIntValue(const nsAString & name, uint32_t *_retval); \
  NS_IMETHOD ReadInt64Value(const nsAString & name, uint64_t *_retval); \
  NS_IMETHOD ReadBinaryValue(const nsAString & name, nsACString & _retval); \
  NS_IMETHOD WriteStringValue(const nsAString & name, const nsAString & data); \
  NS_IMETHOD WriteIntValue(const nsAString & name, uint32_t data); \
  NS_IMETHOD WriteInt64Value(const nsAString & name, uint64_t data); \
  NS_IMETHOD WriteBinaryValue(const nsAString & name, const nsACString & data); \
  NS_IMETHOD StartWatching(bool recurse); \
  NS_IMETHOD StopWatching(void); \
  NS_IMETHOD IsWatching(bool *_retval); \
  NS_IMETHOD HasChanged(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWSREGKEY(_to) \
  NS_IMETHOD GetKey(HKEY *aKey) { return _to GetKey(aKey); } \
  NS_IMETHOD SetKey(HKEY aKey) { return _to SetKey(aKey); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD Open(uint32_t rootKey, const nsAString & relPath, uint32_t mode) { return _to Open(rootKey, relPath, mode); } \
  NS_IMETHOD Create(uint32_t rootKey, const nsAString & relPath, uint32_t mode) { return _to Create(rootKey, relPath, mode); } \
  NS_IMETHOD OpenChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval) { return _to OpenChild(relPath, mode, _retval); } \
  NS_IMETHOD CreateChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval) { return _to CreateChild(relPath, mode, _retval); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_IMETHOD GetChildName(uint32_t index, nsAString & _retval) { return _to GetChildName(index, _retval); } \
  NS_IMETHOD HasChild(const nsAString & name, bool *_retval) { return _to HasChild(name, _retval); } \
  NS_IMETHOD GetValueCount(uint32_t *aValueCount) { return _to GetValueCount(aValueCount); } \
  NS_IMETHOD GetValueName(uint32_t index, nsAString & _retval) { return _to GetValueName(index, _retval); } \
  NS_IMETHOD HasValue(const nsAString & name, bool *_retval) { return _to HasValue(name, _retval); } \
  NS_IMETHOD RemoveChild(const nsAString & relPath) { return _to RemoveChild(relPath); } \
  NS_IMETHOD RemoveValue(const nsAString & name) { return _to RemoveValue(name); } \
  NS_IMETHOD GetValueType(const nsAString & name, uint32_t *_retval) { return _to GetValueType(name, _retval); } \
  NS_IMETHOD ReadStringValue(const nsAString & name, nsAString & _retval) { return _to ReadStringValue(name, _retval); } \
  NS_IMETHOD ReadIntValue(const nsAString & name, uint32_t *_retval) { return _to ReadIntValue(name, _retval); } \
  NS_IMETHOD ReadInt64Value(const nsAString & name, uint64_t *_retval) { return _to ReadInt64Value(name, _retval); } \
  NS_IMETHOD ReadBinaryValue(const nsAString & name, nsACString & _retval) { return _to ReadBinaryValue(name, _retval); } \
  NS_IMETHOD WriteStringValue(const nsAString & name, const nsAString & data) { return _to WriteStringValue(name, data); } \
  NS_IMETHOD WriteIntValue(const nsAString & name, uint32_t data) { return _to WriteIntValue(name, data); } \
  NS_IMETHOD WriteInt64Value(const nsAString & name, uint64_t data) { return _to WriteInt64Value(name, data); } \
  NS_IMETHOD WriteBinaryValue(const nsAString & name, const nsACString & data) { return _to WriteBinaryValue(name, data); } \
  NS_IMETHOD StartWatching(bool recurse) { return _to StartWatching(recurse); } \
  NS_IMETHOD StopWatching(void) { return _to StopWatching(); } \
  NS_IMETHOD IsWatching(bool *_retval) { return _to IsWatching(_retval); } \
  NS_IMETHOD HasChanged(bool *_retval) { return _to HasChanged(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWSREGKEY(_to) \
  NS_IMETHOD GetKey(HKEY *aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_IMETHOD SetKey(HKEY aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKey(aKey); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Open(uint32_t rootKey, const nsAString & relPath, uint32_t mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(rootKey, relPath, mode); } \
  NS_IMETHOD Create(uint32_t rootKey, const nsAString & relPath, uint32_t mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Create(rootKey, relPath, mode); } \
  NS_IMETHOD OpenChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenChild(relPath, mode, _retval); } \
  NS_IMETHOD CreateChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateChild(relPath, mode, _retval); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_IMETHOD GetChildName(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildName(index, _retval); } \
  NS_IMETHOD HasChild(const nsAString & name, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasChild(name, _retval); } \
  NS_IMETHOD GetValueCount(uint32_t *aValueCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueCount(aValueCount); } \
  NS_IMETHOD GetValueName(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueName(index, _retval); } \
  NS_IMETHOD HasValue(const nsAString & name, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasValue(name, _retval); } \
  NS_IMETHOD RemoveChild(const nsAString & relPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChild(relPath); } \
  NS_IMETHOD RemoveValue(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveValue(name); } \
  NS_IMETHOD GetValueType(const nsAString & name, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueType(name, _retval); } \
  NS_IMETHOD ReadStringValue(const nsAString & name, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadStringValue(name, _retval); } \
  NS_IMETHOD ReadIntValue(const nsAString & name, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadIntValue(name, _retval); } \
  NS_IMETHOD ReadInt64Value(const nsAString & name, uint64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadInt64Value(name, _retval); } \
  NS_IMETHOD ReadBinaryValue(const nsAString & name, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadBinaryValue(name, _retval); } \
  NS_IMETHOD WriteStringValue(const nsAString & name, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteStringValue(name, data); } \
  NS_IMETHOD WriteIntValue(const nsAString & name, uint32_t data) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteIntValue(name, data); } \
  NS_IMETHOD WriteInt64Value(const nsAString & name, uint64_t data) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteInt64Value(name, data); } \
  NS_IMETHOD WriteBinaryValue(const nsAString & name, const nsACString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteBinaryValue(name, data); } \
  NS_IMETHOD StartWatching(bool recurse) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartWatching(recurse); } \
  NS_IMETHOD StopWatching(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopWatching(); } \
  NS_IMETHOD IsWatching(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsWatching(_retval); } \
  NS_IMETHOD HasChanged(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasChanged(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowsRegKey : public nsIWindowsRegKey
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWSREGKEY

  nsWindowsRegKey();

private:
  ~nsWindowsRegKey();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowsRegKey, nsIWindowsRegKey)

nsWindowsRegKey::nsWindowsRegKey()
{
  /* member initializers and constructor code */
}

nsWindowsRegKey::~nsWindowsRegKey()
{
  /* destructor code */
}

/* [noscript] attribute HKEY key; */
NS_IMETHODIMP nsWindowsRegKey::GetKey(HKEY *aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWindowsRegKey::SetKey(HKEY aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsWindowsRegKey::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (in unsigned long rootKey, in AString relPath, in unsigned long mode); */
NS_IMETHODIMP nsWindowsRegKey::Open(uint32_t rootKey, const nsAString & relPath, uint32_t mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void create (in unsigned long rootKey, in AString relPath, in unsigned long mode); */
NS_IMETHODIMP nsWindowsRegKey::Create(uint32_t rootKey, const nsAString & relPath, uint32_t mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWindowsRegKey openChild (in AString relPath, in unsigned long mode); */
NS_IMETHODIMP nsWindowsRegKey::OpenChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWindowsRegKey createChild (in AString relPath, in unsigned long mode); */
NS_IMETHODIMP nsWindowsRegKey::CreateChild(const nsAString & relPath, uint32_t mode, nsIWindowsRegKey * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childCount; */
NS_IMETHODIMP nsWindowsRegKey::GetChildCount(uint32_t *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getChildName (in unsigned long index); */
NS_IMETHODIMP nsWindowsRegKey::GetChildName(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasChild (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::HasChild(const nsAString & name, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long valueCount; */
NS_IMETHODIMP nsWindowsRegKey::GetValueCount(uint32_t *aValueCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValueName (in unsigned long index); */
NS_IMETHODIMP nsWindowsRegKey::GetValueName(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::HasValue(const nsAString & name, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeChild (in AString relPath); */
NS_IMETHODIMP nsWindowsRegKey::RemoveChild(const nsAString & relPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::RemoveValue(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getValueType (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::GetValueType(const nsAString & name, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString readStringValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::ReadStringValue(const nsAString & name, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long readIntValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::ReadIntValue(const nsAString & name, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long readInt64Value (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::ReadInt64Value(const nsAString & name, uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString readBinaryValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::ReadBinaryValue(const nsAString & name, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeStringValue (in AString name, in AString data); */
NS_IMETHODIMP nsWindowsRegKey::WriteStringValue(const nsAString & name, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeIntValue (in AString name, in unsigned long data); */
NS_IMETHODIMP nsWindowsRegKey::WriteIntValue(const nsAString & name, uint32_t data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeInt64Value (in AString name, in unsigned long long data); */
NS_IMETHODIMP nsWindowsRegKey::WriteInt64Value(const nsAString & name, uint64_t data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeBinaryValue (in AString name, in ACString data); */
NS_IMETHODIMP nsWindowsRegKey::WriteBinaryValue(const nsAString & name, const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startWatching (in boolean recurse); */
NS_IMETHODIMP nsWindowsRegKey::StartWatching(bool recurse)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopWatching (); */
NS_IMETHODIMP nsWindowsRegKey::StopWatching()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isWatching (); */
NS_IMETHODIMP nsWindowsRegKey::IsWatching(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasChanged (); */
NS_IMETHODIMP nsWindowsRegKey::HasChanged(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowsRegKey_h__ */
