/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILocalFile.idl
 */

#ifndef __gen_nsILocalFile_h__
#define __gen_nsILocalFile_h__


#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILocalFile */
#define NS_ILOCALFILE_IID_STR "ce4ef184-7660-445e-9e59-6731bdc65505"

#define NS_ILOCALFILE_IID \
  {0xce4ef184, 0x7660, 0x445e, \
    { 0x9e, 0x59, 0x67, 0x31, 0xbd, 0xc6, 0x55, 0x05 }}

class NS_NO_VTABLE nsILocalFile : public nsIFile {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALFILE_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalFile, NS_ILOCALFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALFILE \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALFILE(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALFILE(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalFile : public nsILocalFile
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALFILE

  nsLocalFile();

private:
  ~nsLocalFile();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLocalFile, nsILocalFile)

nsLocalFile::nsLocalFile()
{
  /* member initializers and constructor code */
}

nsLocalFile::~nsLocalFile()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILocalFile_h__ */
