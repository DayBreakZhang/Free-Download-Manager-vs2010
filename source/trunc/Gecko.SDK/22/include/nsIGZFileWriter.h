/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/base/nsIGZFileWriter.idl
 */

#ifndef __gen_nsIGZFileWriter_h__
#define __gen_nsIGZFileWriter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsDependentString.h"
class nsIFile; /* forward declaration */


/* starting interface:    nsIGZFileWriter */
#define NS_IGZFILEWRITER_IID_STR "a256f26a-c603-459e-b5a4-53b4877f2cd8"

#define NS_IGZFILEWRITER_IID \
  {0xa256f26a, 0xc603, 0x459e, \
    { 0xb5, 0xa4, 0x53, 0xb4, 0x87, 0x7f, 0x2c, 0xd8 }}

class nsIGZFileWriter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGZFILEWRITER_IID)

  /* void init (in nsIFile file); */
  NS_IMETHOD Init(nsIFile *file) = 0;

  /* void write (in AUTF8String str); */
  NS_IMETHOD Write(const nsACString & str) = 0;

   /**
   * Write the given char* to the file (not including the null-terminator).
   */
  nsresult Write(const char* str)
  {
    return Write(str, strlen(str));
  }
  /**
   * Write |length| bytes of |str| to the file.
   */
  nsresult Write(const char* str, uint32_t len)
  {
    return Write(nsDependentCString(str, len));
  }
    /* void finish (); */
  NS_IMETHOD Finish(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGZFileWriter, NS_IGZFILEWRITER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGZFILEWRITER \
  NS_IMETHOD Init(nsIFile *file); \
  NS_IMETHOD Write(const nsACString & str); \
  NS_IMETHOD Finish(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGZFILEWRITER(_to) \
  NS_IMETHOD Init(nsIFile *file) { return _to Init(file); } \
  NS_IMETHOD Write(const nsACString & str) { return _to Write(str); } \
  NS_IMETHOD Finish(void) { return _to Finish(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGZFILEWRITER(_to) \
  NS_IMETHOD Init(nsIFile *file) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(file); } \
  NS_IMETHOD Write(const nsACString & str) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(str); } \
  NS_IMETHOD Finish(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGZFileWriter : public nsIGZFileWriter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGZFILEWRITER

  nsGZFileWriter();

private:
  ~nsGZFileWriter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGZFileWriter, nsIGZFileWriter)

nsGZFileWriter::nsGZFileWriter()
{
  /* member initializers and constructor code */
}

nsGZFileWriter::~nsGZFileWriter()
{
  /* destructor code */
}

/* void init (in nsIFile file); */
NS_IMETHODIMP nsGZFileWriter::Init(nsIFile *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write (in AUTF8String str); */
NS_IMETHODIMP nsGZFileWriter::Write(const nsACString & str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finish (); */
NS_IMETHODIMP nsGZFileWriter::Finish()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGZFileWriter_h__ */
