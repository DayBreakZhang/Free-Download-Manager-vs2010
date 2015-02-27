/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIObjectOutputStream.idl
 */

#ifndef __gen_nsIObjectOutputStream_h__
#define __gen_nsIObjectOutputStream_h__


#ifndef __gen_nsIBinaryOutputStream_h__
#include "nsIBinaryOutputStream.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIObjectOutputStream */
#define NS_IOBJECTOUTPUTSTREAM_IID_STR "92c898ac-5fde-4b99-87b3-5d486422094b"

#define NS_IOBJECTOUTPUTSTREAM_IID \
  {0x92c898ac, 0x5fde, 0x4b99, \
    { 0x87, 0xb3, 0x5d, 0x48, 0x64, 0x22, 0x09, 0x4b }}

class NS_NO_VTABLE nsIObjectOutputStream : public nsIBinaryOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOBJECTOUTPUTSTREAM_IID)

  /* void writeObject (in nsISupports aObject, in boolean aIsStrongRef); */
  NS_IMETHOD WriteObject(nsISupports *aObject, bool aIsStrongRef) = 0;

  /* void writeSingleRefObject (in nsISupports aObject); */
  NS_IMETHOD WriteSingleRefObject(nsISupports *aObject) = 0;

  /* void writeCompoundObject (in nsISupports aObject, in nsIIDRef aIID, in boolean aIsStrongRef); */
  NS_IMETHOD WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, bool aIsStrongRef) = 0;

  /* void writeID (in nsIDRef aID); */
  NS_IMETHOD WriteID(const nsID & aID) = 0;

  /* [notxpcom] charPtr getBuffer (in uint32_t aLength, in uint32_t aAlignMask); */
  NS_IMETHOD_(char *) GetBuffer(uint32_t aLength, uint32_t aAlignMask) = 0;

  /* [notxpcom] void putBuffer (in charPtr aBuffer, in uint32_t aLength); */
  NS_IMETHOD_(void) PutBuffer(char *aBuffer, uint32_t aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIObjectOutputStream, NS_IOBJECTOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOBJECTOUTPUTSTREAM \
  NS_IMETHOD WriteObject(nsISupports *aObject, bool aIsStrongRef); \
  NS_IMETHOD WriteSingleRefObject(nsISupports *aObject); \
  NS_IMETHOD WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, bool aIsStrongRef); \
  NS_IMETHOD WriteID(const nsID & aID); \
  NS_IMETHOD_(char *) GetBuffer(uint32_t aLength, uint32_t aAlignMask); \
  NS_IMETHOD_(void) PutBuffer(char *aBuffer, uint32_t aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOBJECTOUTPUTSTREAM(_to) \
  NS_IMETHOD WriteObject(nsISupports *aObject, bool aIsStrongRef) { return _to WriteObject(aObject, aIsStrongRef); } \
  NS_IMETHOD WriteSingleRefObject(nsISupports *aObject) { return _to WriteSingleRefObject(aObject); } \
  NS_IMETHOD WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, bool aIsStrongRef) { return _to WriteCompoundObject(aObject, aIID, aIsStrongRef); } \
  NS_IMETHOD WriteID(const nsID & aID) { return _to WriteID(aID); } \
  NS_IMETHOD_(char *) GetBuffer(uint32_t aLength, uint32_t aAlignMask) { return _to GetBuffer(aLength, aAlignMask); } \
  NS_IMETHOD_(void) PutBuffer(char *aBuffer, uint32_t aLength) { return _to PutBuffer(aBuffer, aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOBJECTOUTPUTSTREAM(_to) \
  NS_IMETHOD WriteObject(nsISupports *aObject, bool aIsStrongRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteObject(aObject, aIsStrongRef); } \
  NS_IMETHOD WriteSingleRefObject(nsISupports *aObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteSingleRefObject(aObject); } \
  NS_IMETHOD WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, bool aIsStrongRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteCompoundObject(aObject, aIID, aIsStrongRef); } \
  NS_IMETHOD WriteID(const nsID & aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteID(aID); } \
  NS_IMETHOD_(char *) GetBuffer(uint32_t aLength, uint32_t aAlignMask); \
  NS_IMETHOD_(void) PutBuffer(char *aBuffer, uint32_t aLength); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsObjectOutputStream : public nsIObjectOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOBJECTOUTPUTSTREAM

  nsObjectOutputStream();

private:
  ~nsObjectOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsObjectOutputStream, nsIObjectOutputStream)

nsObjectOutputStream::nsObjectOutputStream()
{
  /* member initializers and constructor code */
}

nsObjectOutputStream::~nsObjectOutputStream()
{
  /* destructor code */
}

/* void writeObject (in nsISupports aObject, in boolean aIsStrongRef); */
NS_IMETHODIMP nsObjectOutputStream::WriteObject(nsISupports *aObject, bool aIsStrongRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeSingleRefObject (in nsISupports aObject); */
NS_IMETHODIMP nsObjectOutputStream::WriteSingleRefObject(nsISupports *aObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeCompoundObject (in nsISupports aObject, in nsIIDRef aIID, in boolean aIsStrongRef); */
NS_IMETHODIMP nsObjectOutputStream::WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, bool aIsStrongRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeID (in nsIDRef aID); */
NS_IMETHODIMP nsObjectOutputStream::WriteID(const nsID & aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] charPtr getBuffer (in uint32_t aLength, in uint32_t aAlignMask); */
NS_IMETHODIMP_(char *) nsObjectOutputStream::GetBuffer(uint32_t aLength, uint32_t aAlignMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void putBuffer (in charPtr aBuffer, in uint32_t aLength); */
NS_IMETHODIMP_(void) nsObjectOutputStream::PutBuffer(char *aBuffer, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


inline nsresult
NS_WriteOptionalObject(nsIObjectOutputStream* aStream, nsISupports* aObject,
                       bool aIsStrongRef)
{
    bool nonnull = (aObject != nullptr);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteObject(aObject, aIsStrongRef);
    return rv;
}
inline nsresult
NS_WriteOptionalSingleRefObject(nsIObjectOutputStream* aStream,
                                nsISupports* aObject)
{
    bool nonnull = (aObject != nullptr);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteSingleRefObject(aObject);
    return rv;
}
inline nsresult
NS_WriteOptionalCompoundObject(nsIObjectOutputStream* aStream,
                               nsISupports* aObject,
                               const nsIID& aIID,
                               bool aIsStrongRef)
{
    bool nonnull = (aObject != nullptr);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteCompoundObject(aObject, aIID, aIsStrongRef);
    return rv;
}

#endif /* __gen_nsIObjectOutputStream_h__ */
