/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/xpcom/io/nsILocalFileWin.idl
 */

#ifndef __gen_nsILocalFileWin_h__
#define __gen_nsILocalFileWin_h__


#ifndef __gen_nsILocalFile_h__
#include "nsILocalFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILocalFileWin */
#define NS_ILOCALFILEWIN_IID_STR "def24611-88a1-2cac-74fd-4b0b12bcaed5"

#define NS_ILOCALFILEWIN_IID \
  {0xdef24611, 0x88a1, 0x2cac, \
    { 0x74, 0xfd, 0x4b, 0x0b, 0x12, 0xbc, 0xae, 0xd5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILocalFileWin : public nsILocalFile {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALFILEWIN_IID)

  /**
    * getVersionInfoValue
    *
    * Retrieve a metadata field from the file's VERSIONINFO block.
    * Throws NS_ERROR_FAILURE if no value is found, or the value is empty.
    *
    * @param   aField         The field to look up.
    *
    */
  /* AString getVersionInfoField (in string aField); */
  NS_SCRIPTABLE NS_IMETHOD GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM) = 0;

  /**
     * The canonical path of the file, which avoids short/long
     * pathname inconsistencies. The nsILocalFile persistent
     * descriptor is not guaranteed to be canonicalized (it may
     * persist either the long or the short path name). The format of
     * the canonical path will vary with the underlying file system:
     * it will typically be the short pathname on filesystems that
     * support both short and long path forms.
     */
  /* readonly attribute AString canonicalPath; */
  NS_SCRIPTABLE NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) = 0;

  /* [noscript] readonly attribute ACString nativeCanonicalPath; */
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) = 0;

  /**
     * Windows specific file attributes.
     *
     * WFA_SEARCH_INDEXED: Generally the default on files in Windows except
     * those created in temp locations. Valid on XP and up. When set the
     * file or directory is marked to be indexed by desktop search services.
     */
  enum { WFA_SEARCH_INDEXED = 1U };

  /**
     * fileAttributesWin
     *
     * Set or get windows specific file attributes.
     * 
     * Throws NS_ERROR_FILE_INVALID_PATH for an invalid file.
     * Throws NS_ERROR_FAILURE if the set or get fails.
     */
  /* attribute unsigned long fileAttributesWin; */
  NS_SCRIPTABLE NS_IMETHOD GetFileAttributesWin(PRUint32 *aFileAttributesWin) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFileAttributesWin(PRUint32 aFileAttributesWin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalFileWin, NS_ILOCALFILEWIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALFILEWIN \
  NS_SCRIPTABLE NS_IMETHOD GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath); \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath); \
  NS_SCRIPTABLE NS_IMETHOD GetFileAttributesWin(PRUint32 *aFileAttributesWin); \
  NS_SCRIPTABLE NS_IMETHOD SetFileAttributesWin(PRUint32 aFileAttributesWin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALFILEWIN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM) { return _to GetVersionInfoField(aField, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) { return _to GetCanonicalPath(aCanonicalPath); } \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) { return _to GetNativeCanonicalPath(aNativeCanonicalPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileAttributesWin(PRUint32 *aFileAttributesWin) { return _to GetFileAttributesWin(aFileAttributesWin); } \
  NS_SCRIPTABLE NS_IMETHOD SetFileAttributesWin(PRUint32 aFileAttributesWin) { return _to SetFileAttributesWin(aFileAttributesWin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALFILEWIN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersionInfoField(aField, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanonicalPath(aCanonicalPath); } \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeCanonicalPath(aNativeCanonicalPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileAttributesWin(PRUint32 *aFileAttributesWin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileAttributesWin(aFileAttributesWin); } \
  NS_SCRIPTABLE NS_IMETHOD SetFileAttributesWin(PRUint32 aFileAttributesWin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFileAttributesWin(aFileAttributesWin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalFileWin : public nsILocalFileWin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALFILEWIN

  nsLocalFileWin();

private:
  ~nsLocalFileWin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLocalFileWin, nsILocalFileWin)

nsLocalFileWin::nsLocalFileWin()
{
  /* member initializers and constructor code */
}

nsLocalFileWin::~nsLocalFileWin()
{
  /* destructor code */
}

/* AString getVersionInfoField (in string aField); */
NS_IMETHODIMP nsLocalFileWin::GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString canonicalPath; */
NS_IMETHODIMP nsLocalFileWin::GetCanonicalPath(nsAString & aCanonicalPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute ACString nativeCanonicalPath; */
NS_IMETHODIMP nsLocalFileWin::GetNativeCanonicalPath(nsACString & aNativeCanonicalPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long fileAttributesWin; */
NS_IMETHODIMP nsLocalFileWin::GetFileAttributesWin(PRUint32 *aFileAttributesWin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLocalFileWin::SetFileAttributesWin(PRUint32 aFileAttributesWin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILocalFileWin_h__ */
