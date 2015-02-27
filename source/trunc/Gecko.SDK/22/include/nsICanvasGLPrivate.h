/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/canvas/public/nsICanvasGLPrivate.idl
 */

#ifndef __gen_nsICanvasGLPrivate_h__
#define __gen_nsICanvasGLPrivate_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICanvasGLBuffer */
#define NS_ICANVASGLBUFFER_IID_STR "eba2aa03-ae19-46e2-bad7-6b966037e22c"

#define NS_ICANVASGLBUFFER_IID \
  {0xeba2aa03, 0xae19, 0x46e2, \
    { 0xba, 0xd7, 0x6b, 0x96, 0x60, 0x37, 0xe2, 0x2c }}

class NS_NO_VTABLE nsICanvasGLBuffer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICANVASGLBUFFER_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICanvasGLBuffer, NS_ICANVASGLBUFFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICANVASGLBUFFER \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICANVASGLBUFFER(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICANVASGLBUFFER(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCanvasGLBuffer : public nsICanvasGLBuffer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICANVASGLBUFFER

  nsCanvasGLBuffer();

private:
  ~nsCanvasGLBuffer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCanvasGLBuffer, nsICanvasGLBuffer)

nsCanvasGLBuffer::nsCanvasGLBuffer()
{
  /* member initializers and constructor code */
}

nsCanvasGLBuffer::~nsCanvasGLBuffer()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICanvasGLTexture */
#define NS_ICANVASGLTEXTURE_IID_STR "27310aab-1988-43e8-882e-6293c8c9df60"

#define NS_ICANVASGLTEXTURE_IID \
  {0x27310aab, 0x1988, 0x43e8, \
    { 0x88, 0x2e, 0x62, 0x93, 0xc8, 0xc9, 0xdf, 0x60 }}

class NS_NO_VTABLE nsICanvasGLTexture : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICANVASGLTEXTURE_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICanvasGLTexture, NS_ICANVASGLTEXTURE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICANVASGLTEXTURE \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICANVASGLTEXTURE(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICANVASGLTEXTURE(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCanvasGLTexture : public nsICanvasGLTexture
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICANVASGLTEXTURE

  nsCanvasGLTexture();

private:
  ~nsCanvasGLTexture();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCanvasGLTexture, nsICanvasGLTexture)

nsCanvasGLTexture::nsCanvasGLTexture()
{
  /* member initializers and constructor code */
}

nsCanvasGLTexture::~nsCanvasGLTexture()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICanvasGLPrivate_h__ */
