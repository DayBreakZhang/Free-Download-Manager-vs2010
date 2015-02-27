/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/canvas/nsIDOMWebGLRenderingContext.idl
 */

#ifndef __gen_nsIDOMWebGLRenderingContext_h__
#define __gen_nsIDOMWebGLRenderingContext_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIDOMHTMLCanvasElement; /* forward declaration */

class nsIPropertyBag; /* forward declaration */

typedef PRUint32  WebGLenum;

typedef PRBool  WebGLboolean;

typedef PRUint32  WebGLbitfield;

typedef PRInt32  WebGLint;

typedef PRInt32  WebGLsizei;

typedef PRInt32  WebGLsizeiptr;

typedef PRUint32  WebGLuint;

typedef float  WebGLfloat;

typedef float  WebGLclampf;

// for jsval
#include "jsapi.h"
namespace js {
struct ArrayBuffer;
struct TypedArray;
}
/* Avoid conflict with WinAPI */
#undef NO_ERROR

/* starting interface:    nsIWebGLTexture */
#define NS_IWEBGLTEXTURE_IID_STR "3b43762a-8305-11de-98ab-000c29206271"

#define NS_IWEBGLTEXTURE_IID \
  {0x3b43762a, 0x8305, 0x11de, \
    { 0x98, 0xab, 0x00, 0x0c, 0x29, 0x20, 0x62, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLTexture : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLTEXTURE_IID)

  /* [noscript] attribute WebGLuint name; */
  NS_IMETHOD GetName(WebGLuint *aName) = 0;
  NS_IMETHOD SetName(WebGLuint aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLTexture, NS_IWEBGLTEXTURE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLTEXTURE \
  NS_IMETHOD GetName(WebGLuint *aName); \
  NS_IMETHOD SetName(WebGLuint aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLTEXTURE(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return _to SetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLTEXTURE(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLTexture : public nsIWebGLTexture
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLTEXTURE

  nsWebGLTexture();

private:
  ~nsWebGLTexture();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLTexture, nsIWebGLTexture)

nsWebGLTexture::nsWebGLTexture()
{
  /* member initializers and constructor code */
}

nsWebGLTexture::~nsWebGLTexture()
{
  /* destructor code */
}

/* [noscript] attribute WebGLuint name; */
NS_IMETHODIMP nsWebGLTexture::GetName(WebGLuint *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebGLTexture::SetName(WebGLuint aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebGLBuffer */
#define NS_IWEBGLBUFFER_IID_STR "9eca9c32-8305-11de-b89b-000c29206271"

#define NS_IWEBGLBUFFER_IID \
  {0x9eca9c32, 0x8305, 0x11de, \
    { 0xb8, 0x9b, 0x00, 0x0c, 0x29, 0x20, 0x62, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLBuffer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLBUFFER_IID)

  /* [noscript] attribute WebGLuint name; */
  NS_IMETHOD GetName(WebGLuint *aName) = 0;
  NS_IMETHOD SetName(WebGLuint aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLBuffer, NS_IWEBGLBUFFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLBUFFER \
  NS_IMETHOD GetName(WebGLuint *aName); \
  NS_IMETHOD SetName(WebGLuint aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLBUFFER(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return _to SetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLBUFFER(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLBuffer : public nsIWebGLBuffer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLBUFFER

  nsWebGLBuffer();

private:
  ~nsWebGLBuffer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLBuffer, nsIWebGLBuffer)

nsWebGLBuffer::nsWebGLBuffer()
{
  /* member initializers and constructor code */
}

nsWebGLBuffer::~nsWebGLBuffer()
{
  /* destructor code */
}

/* [noscript] attribute WebGLuint name; */
NS_IMETHODIMP nsWebGLBuffer::GetName(WebGLuint *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebGLBuffer::SetName(WebGLuint aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebGLProgram */
#define NS_IWEBGLPROGRAM_IID_STR "a6a19e74-8305-11de-9ce9-000c29206271"

#define NS_IWEBGLPROGRAM_IID \
  {0xa6a19e74, 0x8305, 0x11de, \
    { 0x9c, 0xe9, 0x00, 0x0c, 0x29, 0x20, 0x62, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLProgram : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLPROGRAM_IID)

  /* [noscript] attribute WebGLuint name; */
  NS_IMETHOD GetName(WebGLuint *aName) = 0;
  NS_IMETHOD SetName(WebGLuint aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLProgram, NS_IWEBGLPROGRAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLPROGRAM \
  NS_IMETHOD GetName(WebGLuint *aName); \
  NS_IMETHOD SetName(WebGLuint aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLPROGRAM(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return _to SetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLPROGRAM(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLProgram : public nsIWebGLProgram
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLPROGRAM

  nsWebGLProgram();

private:
  ~nsWebGLProgram();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLProgram, nsIWebGLProgram)

nsWebGLProgram::nsWebGLProgram()
{
  /* member initializers and constructor code */
}

nsWebGLProgram::~nsWebGLProgram()
{
  /* destructor code */
}

/* [noscript] attribute WebGLuint name; */
NS_IMETHODIMP nsWebGLProgram::GetName(WebGLuint *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebGLProgram::SetName(WebGLuint aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebGLShader */
#define NS_IWEBGLSHADER_IID_STR "ac7440a4-8305-11de-807b-000c29206271"

#define NS_IWEBGLSHADER_IID \
  {0xac7440a4, 0x8305, 0x11de, \
    { 0x80, 0x7b, 0x00, 0x0c, 0x29, 0x20, 0x62, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLShader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLSHADER_IID)

  /* [noscript] attribute WebGLuint name; */
  NS_IMETHOD GetName(WebGLuint *aName) = 0;
  NS_IMETHOD SetName(WebGLuint aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLShader, NS_IWEBGLSHADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLSHADER \
  NS_IMETHOD GetName(WebGLuint *aName); \
  NS_IMETHOD SetName(WebGLuint aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLSHADER(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return _to SetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLSHADER(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLShader : public nsIWebGLShader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLSHADER

  nsWebGLShader();

private:
  ~nsWebGLShader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLShader, nsIWebGLShader)

nsWebGLShader::nsWebGLShader()
{
  /* member initializers and constructor code */
}

nsWebGLShader::~nsWebGLShader()
{
  /* destructor code */
}

/* [noscript] attribute WebGLuint name; */
NS_IMETHODIMP nsWebGLShader::GetName(WebGLuint *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebGLShader::SetName(WebGLuint aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebGLShaderArray */
#define NS_IWEBGLSHADERARRAY_IID_STR "beea4b38-3094-4e8d-b6e6-8b21d07e8994"

#define NS_IWEBGLSHADERARRAY_IID \
  {0xbeea4b38, 0x3094, 0x4e8d, \
    { 0xb6, 0xe6, 0x8b, 0x21, 0xd0, 0x7e, 0x89, 0x94 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLShaderArray : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLSHADERARRAY_IID)

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* nsIWebGLShader item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIWebGLShader **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLShaderArray, NS_IWEBGLSHADERARRAY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLSHADERARRAY \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIWebGLShader **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLSHADERARRAY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIWebGLShader **_retval NS_OUTPARAM) { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLSHADERARRAY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIWebGLShader **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLShaderArray : public nsIWebGLShaderArray
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLSHADERARRAY

  nsWebGLShaderArray();

private:
  ~nsWebGLShaderArray();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLShaderArray, nsIWebGLShaderArray)

nsWebGLShaderArray::nsWebGLShaderArray()
{
  /* member initializers and constructor code */
}

nsWebGLShaderArray::~nsWebGLShaderArray()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsWebGLShaderArray::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLShader item (in unsigned long index); */
NS_IMETHODIMP nsWebGLShaderArray::Item(PRUint32 index, nsIWebGLShader **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebGLFramebuffer */
#define NS_IWEBGLFRAMEBUFFER_IID_STR "bce8be60-8305-11de-9f3c-000c29206271"

#define NS_IWEBGLFRAMEBUFFER_IID \
  {0xbce8be60, 0x8305, 0x11de, \
    { 0x9f, 0x3c, 0x00, 0x0c, 0x29, 0x20, 0x62, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLFramebuffer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLFRAMEBUFFER_IID)

  /* [noscript] attribute WebGLuint name; */
  NS_IMETHOD GetName(WebGLuint *aName) = 0;
  NS_IMETHOD SetName(WebGLuint aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLFramebuffer, NS_IWEBGLFRAMEBUFFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLFRAMEBUFFER \
  NS_IMETHOD GetName(WebGLuint *aName); \
  NS_IMETHOD SetName(WebGLuint aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLFRAMEBUFFER(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return _to SetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLFRAMEBUFFER(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLFramebuffer : public nsIWebGLFramebuffer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLFRAMEBUFFER

  nsWebGLFramebuffer();

private:
  ~nsWebGLFramebuffer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLFramebuffer, nsIWebGLFramebuffer)

nsWebGLFramebuffer::nsWebGLFramebuffer()
{
  /* member initializers and constructor code */
}

nsWebGLFramebuffer::~nsWebGLFramebuffer()
{
  /* destructor code */
}

/* [noscript] attribute WebGLuint name; */
NS_IMETHODIMP nsWebGLFramebuffer::GetName(WebGLuint *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebGLFramebuffer::SetName(WebGLuint aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebGLRenderbuffer */
#define NS_IWEBGLRENDERBUFFER_IID_STR "c82eacd0-8305-11de-9de9-000c29206271"

#define NS_IWEBGLRENDERBUFFER_IID \
  {0xc82eacd0, 0x8305, 0x11de, \
    { 0x9d, 0xe9, 0x00, 0x0c, 0x29, 0x20, 0x62, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLRenderbuffer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLRENDERBUFFER_IID)

  /* [noscript] attribute WebGLuint name; */
  NS_IMETHOD GetName(WebGLuint *aName) = 0;
  NS_IMETHOD SetName(WebGLuint aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLRenderbuffer, NS_IWEBGLRENDERBUFFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLRENDERBUFFER \
  NS_IMETHOD GetName(WebGLuint *aName); \
  NS_IMETHOD SetName(WebGLuint aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLRENDERBUFFER(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return _to SetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLRENDERBUFFER(_to) \
  NS_IMETHOD GetName(WebGLuint *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(WebGLuint aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLRenderbuffer : public nsIWebGLRenderbuffer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLRENDERBUFFER

  nsWebGLRenderbuffer();

private:
  ~nsWebGLRenderbuffer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLRenderbuffer, nsIWebGLRenderbuffer)

nsWebGLRenderbuffer::nsWebGLRenderbuffer()
{
  /* member initializers and constructor code */
}

nsWebGLRenderbuffer::~nsWebGLRenderbuffer()
{
  /* destructor code */
}

/* [noscript] attribute WebGLuint name; */
NS_IMETHODIMP nsWebGLRenderbuffer::GetName(WebGLuint *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebGLRenderbuffer::SetName(WebGLuint aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebGLActiveInfo */
#define NS_IWEBGLACTIVEINFO_IID_STR "a85d4fd0-5b9f-4cb8-aeee-5a2c5c5bad76"

#define NS_IWEBGLACTIVEINFO_IID \
  {0xa85d4fd0, 0x5b9f, 0x4cb8, \
    { 0xae, 0xee, 0x5a, 0x2c, 0x5c, 0x5b, 0xad, 0x76 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLActiveInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLACTIVEINFO_IID)

  /* readonly attribute WebGLint size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(WebGLint *aSize) = 0;

  /* readonly attribute WebGLenum type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(WebGLenum *aType) = 0;

  /* readonly attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLActiveInfo, NS_IWEBGLACTIVEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLACTIVEINFO \
  NS_SCRIPTABLE NS_IMETHOD GetSize(WebGLint *aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetType(WebGLenum *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLACTIVEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSize(WebGLint *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(WebGLenum *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLACTIVEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSize(WebGLint *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(WebGLenum *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLActiveInfo : public nsIWebGLActiveInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLACTIVEINFO

  nsWebGLActiveInfo();

private:
  ~nsWebGLActiveInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLActiveInfo, nsIWebGLActiveInfo)

nsWebGLActiveInfo::nsWebGLActiveInfo()
{
  /* member initializers and constructor code */
}

nsWebGLActiveInfo::~nsWebGLActiveInfo()
{
  /* destructor code */
}

/* readonly attribute WebGLint size; */
NS_IMETHODIMP nsWebGLActiveInfo::GetSize(WebGLint *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute WebGLenum type; */
NS_IMETHODIMP nsWebGLActiveInfo::GetType(WebGLenum *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsWebGLActiveInfo::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebGLUniformLocation */
#define NS_IWEBGLUNIFORMLOCATION_IID_STR "d38b0467-623e-4c82-9140-5f14a3bd1bad"

#define NS_IWEBGLUNIFORMLOCATION_IID \
  {0xd38b0467, 0x623e, 0x4c82, \
    { 0x91, 0x40, 0x5f, 0x14, 0xa3, 0xbd, 0x1b, 0xad }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebGLUniformLocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBGLUNIFORMLOCATION_IID)

  /* [noscript] attribute WebGLint location; */
  NS_IMETHOD GetLocation(WebGLint *aLocation) = 0;
  NS_IMETHOD SetLocation(WebGLint aLocation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebGLUniformLocation, NS_IWEBGLUNIFORMLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBGLUNIFORMLOCATION \
  NS_IMETHOD GetLocation(WebGLint *aLocation); \
  NS_IMETHOD SetLocation(WebGLint aLocation); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBGLUNIFORMLOCATION(_to) \
  NS_IMETHOD GetLocation(WebGLint *aLocation) { return _to GetLocation(aLocation); } \
  NS_IMETHOD SetLocation(WebGLint aLocation) { return _to SetLocation(aLocation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBGLUNIFORMLOCATION(_to) \
  NS_IMETHOD GetLocation(WebGLint *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_IMETHOD SetLocation(WebGLint aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocation(aLocation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebGLUniformLocation : public nsIWebGLUniformLocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBGLUNIFORMLOCATION

  nsWebGLUniformLocation();

private:
  ~nsWebGLUniformLocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebGLUniformLocation, nsIWebGLUniformLocation)

nsWebGLUniformLocation::nsWebGLUniformLocation()
{
  /* member initializers and constructor code */
}

nsWebGLUniformLocation::~nsWebGLUniformLocation()
{
  /* destructor code */
}

/* [noscript] attribute WebGLint location; */
NS_IMETHODIMP nsWebGLUniformLocation::GetLocation(WebGLint *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebGLUniformLocation::SetLocation(WebGLint aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMWebGLRenderingContext */
#define NS_IDOMWEBGLRENDERINGCONTEXT_IID_STR "2f21ca21-9720-4eee-ad94-27eefe4f72dc"

#define NS_IDOMWEBGLRENDERINGCONTEXT_IID \
  {0x2f21ca21, 0x9720, 0x4eee, \
    { 0xad, 0x94, 0x27, 0xee, 0xfe, 0x4f, 0x72, 0xdc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMWebGLRenderingContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWEBGLRENDERINGCONTEXT_IID)

  enum { DEPTH_BUFFER_BIT = 256U };

  enum { STENCIL_BUFFER_BIT = 1024U };

  enum { COLOR_BUFFER_BIT = 16384U };

  enum { POINTS = 0U };

  enum { LINES = 1U };

  enum { LINE_LOOP = 2U };

  enum { LINE_STRIP = 3U };

  enum { TRIANGLES = 4U };

  enum { TRIANGLE_STRIP = 5U };

  enum { TRIANGLE_FAN = 6U };

  enum { ZERO = 0U };

  enum { ONE = 1U };

  enum { SRC_COLOR = 768U };

  enum { ONE_MINUS_SRC_COLOR = 769U };

  enum { SRC_ALPHA = 770U };

  enum { ONE_MINUS_SRC_ALPHA = 771U };

  enum { DST_ALPHA = 772U };

  enum { ONE_MINUS_DST_ALPHA = 773U };

  enum { DST_COLOR = 774U };

  enum { ONE_MINUS_DST_COLOR = 775U };

  enum { SRC_ALPHA_SATURATE = 776U };

  enum { FUNC_ADD = 32774U };

  enum { BLEND_EQUATION = 32777U };

  enum { BLEND_EQUATION_RGB = 32777U };

  enum { BLEND_EQUATION_ALPHA = 34877U };

  enum { FUNC_SUBTRACT = 32778U };

  enum { FUNC_REVERSE_SUBTRACT = 32779U };

  enum { BLEND_DST_RGB = 32968U };

  enum { BLEND_SRC_RGB = 32969U };

  enum { BLEND_DST_ALPHA = 32970U };

  enum { BLEND_SRC_ALPHA = 32971U };

  enum { CONSTANT_COLOR = 32769U };

  enum { ONE_MINUS_CONSTANT_COLOR = 32770U };

  enum { CONSTANT_ALPHA = 32771U };

  enum { ONE_MINUS_CONSTANT_ALPHA = 32772U };

  enum { BLEND_COLOR = 32773U };

  enum { ARRAY_BUFFER = 34962U };

  enum { ELEMENT_ARRAY_BUFFER = 34963U };

  enum { ARRAY_BUFFER_BINDING = 34964U };

  enum { ELEMENT_ARRAY_BUFFER_BINDING = 34965U };

  enum { STREAM_DRAW = 35040U };

  enum { STATIC_DRAW = 35044U };

  enum { DYNAMIC_DRAW = 35048U };

  enum { BUFFER_SIZE = 34660U };

  enum { BUFFER_USAGE = 34661U };

  enum { CURRENT_VERTEX_ATTRIB = 34342U };

  enum { FRONT = 1028U };

  enum { BACK = 1029U };

  enum { FRONT_AND_BACK = 1032U };

  enum { TEXTURE_2D = 3553U };

  enum { CULL_FACE = 2884U };

  enum { BLEND = 3042U };

  enum { DITHER = 3024U };

  enum { STENCIL_TEST = 2960U };

  enum { DEPTH_TEST = 2929U };

  enum { SCISSOR_TEST = 3089U };

  enum { POLYGON_OFFSET_FILL = 32823U };

  enum { SAMPLE_ALPHA_TO_COVERAGE = 32926U };

  enum { SAMPLE_COVERAGE = 32928U };

  enum { NO_ERROR = 0U };

  enum { INVALID_ENUM = 1280U };

  enum { INVALID_VALUE = 1281U };

  enum { INVALID_OPERATION = 1282U };

  enum { OUT_OF_MEMORY = 1285U };

  enum { CW = 2304U };

  enum { CCW = 2305U };

  enum { LINE_WIDTH = 2849U };

  enum { ALIASED_POINT_SIZE_RANGE = 33901U };

  enum { ALIASED_LINE_WIDTH_RANGE = 33902U };

  enum { CULL_FACE_MODE = 2885U };

  enum { FRONT_FACE = 2886U };

  enum { DEPTH_RANGE = 2928U };

  enum { DEPTH_WRITEMASK = 2930U };

  enum { DEPTH_CLEAR_VALUE = 2931U };

  enum { DEPTH_FUNC = 2932U };

  enum { STENCIL_CLEAR_VALUE = 2961U };

  enum { STENCIL_FUNC = 2962U };

  enum { STENCIL_FAIL = 2964U };

  enum { STENCIL_PASS_DEPTH_FAIL = 2965U };

  enum { STENCIL_PASS_DEPTH_PASS = 2966U };

  enum { STENCIL_REF = 2967U };

  enum { STENCIL_VALUE_MASK = 2963U };

  enum { STENCIL_WRITEMASK = 2968U };

  enum { STENCIL_BACK_FUNC = 34816U };

  enum { STENCIL_BACK_FAIL = 34817U };

  enum { STENCIL_BACK_PASS_DEPTH_FAIL = 34818U };

  enum { STENCIL_BACK_PASS_DEPTH_PASS = 34819U };

  enum { STENCIL_BACK_REF = 36003U };

  enum { STENCIL_BACK_VALUE_MASK = 36004U };

  enum { STENCIL_BACK_WRITEMASK = 36005U };

  enum { SCISSOR_BOX = 3088U };

  enum { COLOR_CLEAR_VALUE = 3106U };

  enum { COLOR_WRITEMASK = 3107U };

  enum { UNPACK_ALIGNMENT = 3317U };

  enum { PACK_ALIGNMENT = 3333U };

  enum { MAX_TEXTURE_SIZE = 3379U };

  enum { MAX_VIEWPORT_DIMS = 3386U };

  enum { SUBPIXEL_BITS = 3408U };

  enum { RED_BITS = 3410U };

  enum { GREEN_BITS = 3411U };

  enum { BLUE_BITS = 3412U };

  enum { ALPHA_BITS = 3413U };

  enum { DEPTH_BITS = 3414U };

  enum { STENCIL_BITS = 3415U };

  enum { POLYGON_OFFSET_UNITS = 10752U };

  enum { POLYGON_OFFSET_FACTOR = 32824U };

  enum { TEXTURE_BINDING_2D = 32873U };

  enum { SAMPLE_BUFFERS = 32936U };

  enum { SAMPLES = 32937U };

  enum { SAMPLE_COVERAGE_VALUE = 32938U };

  enum { SAMPLE_COVERAGE_INVERT = 32939U };

  enum { NUM_COMPRESSED_TEXTURE_FORMATS = 34466U };

  enum { COMPRESSED_TEXTURE_FORMATS = 34467U };

  enum { DONT_CARE = 4352U };

  enum { FASTEST = 4353U };

  enum { NICEST = 4354U };

  enum { GENERATE_MIPMAP_HINT = 33170U };

  enum { BYTE = 5120U };

  enum { UNSIGNED_BYTE = 5121U };

  enum { SHORT = 5122U };

  enum { UNSIGNED_SHORT = 5123U };

  enum { INT = 5124U };

  enum { UNSIGNED_INT = 5125U };

  enum { FLOAT = 5126U };

  enum { DEPTH_COMPONENT = 6402U };

  enum { ALPHA = 6406U };

  enum { RGB = 6407U };

  enum { RGBA = 6408U };

  enum { LUMINANCE = 6409U };

  enum { LUMINANCE_ALPHA = 6410U };

  enum { UNSIGNED_SHORT_4_4_4_4 = 32819U };

  enum { UNSIGNED_SHORT_5_5_5_1 = 32820U };

  enum { UNSIGNED_SHORT_5_6_5 = 33635U };

  enum { FRAGMENT_SHADER = 35632U };

  enum { VERTEX_SHADER = 35633U };

  enum { MAX_VERTEX_ATTRIBS = 34921U };

  enum { MAX_VERTEX_UNIFORM_VECTORS = 36347U };

  enum { MAX_VARYING_VECTORS = 36348U };

  enum { MAX_COMBINED_TEXTURE_IMAGE_UNITS = 35661U };

  enum { MAX_VERTEX_TEXTURE_IMAGE_UNITS = 35660U };

  enum { MAX_TEXTURE_IMAGE_UNITS = 34930U };

  enum { MAX_FRAGMENT_UNIFORM_VECTORS = 36349U };

  enum { SHADER_TYPE = 35663U };

  enum { DELETE_STATUS = 35712U };

  enum { LINK_STATUS = 35714U };

  enum { VALIDATE_STATUS = 35715U };

  enum { ATTACHED_SHADERS = 35717U };

  enum { ACTIVE_UNIFORMS = 35718U };

  enum { ACTIVE_UNIFORM_MAX_LENGTH = 35719U };

  enum { ACTIVE_ATTRIBUTES = 35721U };

  enum { ACTIVE_ATTRIBUTE_MAX_LENGTH = 35722U };

  enum { SHADING_LANGUAGE_VERSION = 35724U };

  enum { CURRENT_PROGRAM = 35725U };

  enum { NEVER = 512U };

  enum { LESS = 513U };

  enum { EQUAL = 514U };

  enum { LEQUAL = 515U };

  enum { GREATER = 516U };

  enum { NOTEQUAL = 517U };

  enum { GEQUAL = 518U };

  enum { ALWAYS = 519U };

  enum { KEEP = 7680U };

  enum { REPLACE = 7681U };

  enum { INCR = 7682U };

  enum { DECR = 7683U };

  enum { INVERT = 5386U };

  enum { INCR_WRAP = 34055U };

  enum { DECR_WRAP = 34056U };

  enum { VENDOR = 7936U };

  enum { RENDERER = 7937U };

  enum { VERSION = 7938U };

  enum { EXTENSIONS = 7939U };

  enum { NEAREST = 9728U };

  enum { LINEAR = 9729U };

  enum { NEAREST_MIPMAP_NEAREST = 9984U };

  enum { LINEAR_MIPMAP_NEAREST = 9985U };

  enum { NEAREST_MIPMAP_LINEAR = 9986U };

  enum { LINEAR_MIPMAP_LINEAR = 9987U };

  enum { TEXTURE_MAG_FILTER = 10240U };

  enum { TEXTURE_MIN_FILTER = 10241U };

  enum { TEXTURE_WRAP_S = 10242U };

  enum { TEXTURE_WRAP_T = 10243U };

  enum { TEXTURE = 5890U };

  enum { TEXTURE_CUBE_MAP = 34067U };

  enum { TEXTURE_BINDING_CUBE_MAP = 34068U };

  enum { TEXTURE_CUBE_MAP_POSITIVE_X = 34069U };

  enum { TEXTURE_CUBE_MAP_NEGATIVE_X = 34070U };

  enum { TEXTURE_CUBE_MAP_POSITIVE_Y = 34071U };

  enum { TEXTURE_CUBE_MAP_NEGATIVE_Y = 34072U };

  enum { TEXTURE_CUBE_MAP_POSITIVE_Z = 34073U };

  enum { TEXTURE_CUBE_MAP_NEGATIVE_Z = 34074U };

  enum { MAX_CUBE_MAP_TEXTURE_SIZE = 34076U };

  enum { TEXTURE0 = 33984U };

  enum { TEXTURE1 = 33985U };

  enum { TEXTURE2 = 33986U };

  enum { TEXTURE3 = 33987U };

  enum { TEXTURE4 = 33988U };

  enum { TEXTURE5 = 33989U };

  enum { TEXTURE6 = 33990U };

  enum { TEXTURE7 = 33991U };

  enum { TEXTURE8 = 33992U };

  enum { TEXTURE9 = 33993U };

  enum { TEXTURE10 = 33994U };

  enum { TEXTURE11 = 33995U };

  enum { TEXTURE12 = 33996U };

  enum { TEXTURE13 = 33997U };

  enum { TEXTURE14 = 33998U };

  enum { TEXTURE15 = 33999U };

  enum { TEXTURE16 = 34000U };

  enum { TEXTURE17 = 34001U };

  enum { TEXTURE18 = 34002U };

  enum { TEXTURE19 = 34003U };

  enum { TEXTURE20 = 34004U };

  enum { TEXTURE21 = 34005U };

  enum { TEXTURE22 = 34006U };

  enum { TEXTURE23 = 34007U };

  enum { TEXTURE24 = 34008U };

  enum { TEXTURE25 = 34009U };

  enum { TEXTURE26 = 34010U };

  enum { TEXTURE27 = 34011U };

  enum { TEXTURE28 = 34012U };

  enum { TEXTURE29 = 34013U };

  enum { TEXTURE30 = 34014U };

  enum { TEXTURE31 = 34015U };

  enum { ACTIVE_TEXTURE = 34016U };

  enum { REPEAT = 10497U };

  enum { CLAMP_TO_EDGE = 33071U };

  enum { MIRRORED_REPEAT = 33648U };

  enum { FLOAT_VEC2 = 35664U };

  enum { FLOAT_VEC3 = 35665U };

  enum { FLOAT_VEC4 = 35666U };

  enum { INT_VEC2 = 35667U };

  enum { INT_VEC3 = 35668U };

  enum { INT_VEC4 = 35669U };

  enum { BOOL = 35670U };

  enum { BOOL_VEC2 = 35671U };

  enum { BOOL_VEC3 = 35672U };

  enum { BOOL_VEC4 = 35673U };

  enum { FLOAT_MAT2 = 35674U };

  enum { FLOAT_MAT3 = 35675U };

  enum { FLOAT_MAT4 = 35676U };

  enum { SAMPLER_2D = 35678U };

  enum { SAMPLER_CUBE = 35680U };

  enum { VERTEX_ATTRIB_ARRAY_ENABLED = 34338U };

  enum { VERTEX_ATTRIB_ARRAY_SIZE = 34339U };

  enum { VERTEX_ATTRIB_ARRAY_STRIDE = 34340U };

  enum { VERTEX_ATTRIB_ARRAY_TYPE = 34341U };

  enum { VERTEX_ATTRIB_ARRAY_NORMALIZED = 34922U };

  enum { VERTEX_ATTRIB_ARRAY_POINTER = 34373U };

  enum { VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 34975U };

  enum { COMPILE_STATUS = 35713U };

  enum { INFO_LOG_LENGTH = 35716U };

  enum { SHADER_SOURCE_LENGTH = 35720U };

  enum { SHADER_COMPILER = 36346U };

  enum { LOW_FLOAT = 36336U };

  enum { MEDIUM_FLOAT = 36337U };

  enum { HIGH_FLOAT = 36338U };

  enum { LOW_INT = 36339U };

  enum { MEDIUM_INT = 36340U };

  enum { HIGH_INT = 36341U };

  enum { FRAMEBUFFER = 36160U };

  enum { RENDERBUFFER = 36161U };

  enum { RGBA4 = 32854U };

  enum { RGB5_A1 = 32855U };

  enum { RGB565 = 36194U };

  enum { DEPTH_COMPONENT16 = 33189U };

  enum { STENCIL_INDEX = 6401U };

  enum { STENCIL_INDEX8 = 36168U };

  enum { DEPTH_STENCIL = 34041U };

  enum { RENDERBUFFER_WIDTH = 36162U };

  enum { RENDERBUFFER_HEIGHT = 36163U };

  enum { RENDERBUFFER_INTERNAL_FORMAT = 36164U };

  enum { RENDERBUFFER_RED_SIZE = 36176U };

  enum { RENDERBUFFER_GREEN_SIZE = 36177U };

  enum { RENDERBUFFER_BLUE_SIZE = 36178U };

  enum { RENDERBUFFER_ALPHA_SIZE = 36179U };

  enum { RENDERBUFFER_DEPTH_SIZE = 36180U };

  enum { RENDERBUFFER_STENCIL_SIZE = 36181U };

  enum { FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 36048U };

  enum { FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 36049U };

  enum { FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 36050U };

  enum { FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 36051U };

  enum { COLOR_ATTACHMENT0 = 36064U };

  enum { DEPTH_ATTACHMENT = 36096U };

  enum { STENCIL_ATTACHMENT = 36128U };

  enum { DEPTH_STENCIL_ATTACHMENT = 33306U };

  enum { NONE = 0U };

  enum { FRAMEBUFFER_COMPLETE = 36053U };

  enum { FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 36054U };

  enum { FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 36055U };

  enum { FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 36057U };

  enum { FRAMEBUFFER_UNSUPPORTED = 36061U };

  enum { FRAMEBUFFER_BINDING = 36006U };

  enum { RENDERBUFFER_BINDING = 36007U };

  enum { MAX_RENDERBUFFER_SIZE = 34024U };

  enum { INVALID_FRAMEBUFFER_OPERATION = 1286U };

  enum { UNPACK_FLIP_Y_WEBGL = 37440U };

  enum { UNPACK_PREMULTIPLY_ALPHA_WEBGL = 37441U };

  enum { CONTEXT_LOST_WEBGL = 37442U };

  enum { UNPACK_COLORSPACE_CONVERSION_WEBGL = 37443U };

  enum { BROWSER_DEFAULT_WEBGL = 37444U };

  /* readonly attribute nsIDOMHTMLCanvasElement canvas; */
  NS_SCRIPTABLE NS_IMETHOD GetCanvas(nsIDOMHTMLCanvasElement **aCanvas) = 0;

  /* jsval getContextAttributes (); */
  NS_SCRIPTABLE NS_IMETHOD GetContextAttributes(jsval *_retval NS_OUTPARAM) = 0;

  /* void activeTexture (in WebGLenum texture); */
  NS_SCRIPTABLE NS_IMETHOD ActiveTexture(WebGLenum texture) = 0;

  /* void attachShader ([optional] in nsIWebGLProgram program, [optional] in nsIWebGLShader shader); */
  NS_SCRIPTABLE NS_IMETHOD AttachShader(nsIWebGLProgram *program, nsIWebGLShader *shader) = 0;

  /* void bindAttribLocation (in nsIWebGLProgram program, in WebGLuint index, in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD BindAttribLocation(nsIWebGLProgram *program, WebGLuint index, const nsAString & name) = 0;

  /* void bindBuffer (in WebGLenum target, in nsIWebGLBuffer buffer); */
  NS_SCRIPTABLE NS_IMETHOD BindBuffer(WebGLenum target, nsIWebGLBuffer *buffer) = 0;

  /* void bindFramebuffer (in WebGLenum target, in nsIWebGLFramebuffer framebuffer); */
  NS_SCRIPTABLE NS_IMETHOD BindFramebuffer(WebGLenum target, nsIWebGLFramebuffer *framebuffer) = 0;

  /* void bindRenderbuffer (in WebGLenum target, in nsIWebGLRenderbuffer renderbuffer); */
  NS_SCRIPTABLE NS_IMETHOD BindRenderbuffer(WebGLenum target, nsIWebGLRenderbuffer *renderbuffer) = 0;

  /* void bindTexture (in WebGLenum target, in nsIWebGLTexture texture); */
  NS_SCRIPTABLE NS_IMETHOD BindTexture(WebGLenum target, nsIWebGLTexture *texture) = 0;

  /* void blendColor (in WebGLclampf red, in WebGLclampf green, in WebGLclampf blue, in WebGLclampf alpha); */
  NS_SCRIPTABLE NS_IMETHOD BlendColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha) = 0;

  /* void blendEquation (in WebGLenum mode); */
  NS_SCRIPTABLE NS_IMETHOD BlendEquation(WebGLenum mode) = 0;

  /* void blendEquationSeparate (in WebGLenum modeRGB, in WebGLenum modeAlpha); */
  NS_SCRIPTABLE NS_IMETHOD BlendEquationSeparate(WebGLenum modeRGB, WebGLenum modeAlpha) = 0;

  /* void blendFunc (in WebGLenum sfactor, in WebGLenum dfactor); */
  NS_SCRIPTABLE NS_IMETHOD BlendFunc(WebGLenum sfactor, WebGLenum dfactor) = 0;

  /* void blendFuncSeparate (in WebGLenum srcRGB, in WebGLenum dstRGB, in WebGLenum srcAlpha, in WebGLenum dstAlpha); */
  NS_SCRIPTABLE NS_IMETHOD BlendFuncSeparate(WebGLenum srcRGB, WebGLenum dstRGB, WebGLenum srcAlpha, WebGLenum dstAlpha) = 0;

  /* void bufferData ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD BufferData(PRInt32 dummy) = 0;

  /* [noscript] void bufferData_size (in WebGLenum target, in WebGLsizei size, in WebGLenum usage); */
  NS_IMETHOD BufferData_size(WebGLenum target, WebGLsizei size, WebGLenum usage) = 0;

  /* [noscript] void bufferData_buf (in WebGLenum target, in WebGLArrayBufferPtr data, in WebGLenum usage); */
  NS_IMETHOD BufferData_buf(WebGLenum target, js::ArrayBuffer *data, WebGLenum usage) = 0;

  /* [noscript] void bufferData_array (in WebGLenum target, in WebGLArrayPtr data, in WebGLenum usage); */
  NS_IMETHOD BufferData_array(WebGLenum target, js::TypedArray *data, WebGLenum usage) = 0;

  /* [noscript] void bufferData_null (); */
  NS_IMETHOD BufferData_null(void) = 0;

  /* void bufferSubData ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD BufferSubData(PRInt32 dummy) = 0;

  /* [noscript] void bufferSubData_buf (in WebGLenum target, in long offset, in WebGLArrayBufferPtr data); */
  NS_IMETHOD BufferSubData_buf(WebGLenum target, PRInt32 offset, js::ArrayBuffer *data) = 0;

  /* [noscript] void bufferSubData_array (in WebGLenum target, in long offset, in WebGLArrayPtr data); */
  NS_IMETHOD BufferSubData_array(WebGLenum target, PRInt32 offset, js::TypedArray *data) = 0;

  /* [noscript] void bufferSubData_null (); */
  NS_IMETHOD BufferSubData_null(void) = 0;

  /* WebGLenum checkFramebufferStatus (in WebGLenum target); */
  NS_SCRIPTABLE NS_IMETHOD CheckFramebufferStatus(WebGLenum target, WebGLenum *_retval NS_OUTPARAM) = 0;

  /* void clear (in WebGLbitfield mask); */
  NS_SCRIPTABLE NS_IMETHOD Clear(WebGLbitfield mask) = 0;

  /* void clearColor (in WebGLclampf red, in WebGLclampf green, in WebGLclampf blue, in WebGLclampf alpha); */
  NS_SCRIPTABLE NS_IMETHOD ClearColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha) = 0;

  /* void clearDepth (in WebGLclampf depth); */
  NS_SCRIPTABLE NS_IMETHOD ClearDepth(WebGLclampf depth) = 0;

  /* void clearStencil (in WebGLint s); */
  NS_SCRIPTABLE NS_IMETHOD ClearStencil(WebGLint s) = 0;

  /* void colorMask (in WebGLboolean red, in WebGLboolean green, in WebGLboolean blue, in WebGLboolean alpha); */
  NS_SCRIPTABLE NS_IMETHOD ColorMask(WebGLboolean red, WebGLboolean green, WebGLboolean blue, WebGLboolean alpha) = 0;

  /* void compileShader ([optional] in nsIWebGLShader shader); */
  NS_SCRIPTABLE NS_IMETHOD CompileShader(nsIWebGLShader *shader) = 0;

  /* void copyTexImage2D (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height, in WebGLint border); */
  NS_SCRIPTABLE NS_IMETHOD CopyTexImage2D(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLint border) = 0;

  /* void copyTexSubImage2D (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height); */
  NS_SCRIPTABLE NS_IMETHOD CopyTexSubImage2D(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) = 0;

  /* nsIWebGLBuffer createBuffer (); */
  NS_SCRIPTABLE NS_IMETHOD CreateBuffer(nsIWebGLBuffer **_retval NS_OUTPARAM) = 0;

  /* nsIWebGLProgram createProgram (); */
  NS_SCRIPTABLE NS_IMETHOD CreateProgram(nsIWebGLProgram **_retval NS_OUTPARAM) = 0;

  /* nsIWebGLFramebuffer createFramebuffer (); */
  NS_SCRIPTABLE NS_IMETHOD CreateFramebuffer(nsIWebGLFramebuffer **_retval NS_OUTPARAM) = 0;

  /* nsIWebGLRenderbuffer createRenderbuffer (); */
  NS_SCRIPTABLE NS_IMETHOD CreateRenderbuffer(nsIWebGLRenderbuffer **_retval NS_OUTPARAM) = 0;

  /* nsIWebGLShader createShader (in WebGLenum type); */
  NS_SCRIPTABLE NS_IMETHOD CreateShader(WebGLenum type, nsIWebGLShader **_retval NS_OUTPARAM) = 0;

  /* nsIWebGLTexture createTexture (); */
  NS_SCRIPTABLE NS_IMETHOD CreateTexture(nsIWebGLTexture **_retval NS_OUTPARAM) = 0;

  /* void cullFace (in WebGLenum mode); */
  NS_SCRIPTABLE NS_IMETHOD CullFace(WebGLenum mode) = 0;

  /* void deleteBuffer (in nsIWebGLBuffer buffer); */
  NS_SCRIPTABLE NS_IMETHOD DeleteBuffer(nsIWebGLBuffer *buffer) = 0;

  /* void deleteProgram (in nsIWebGLProgram program); */
  NS_SCRIPTABLE NS_IMETHOD DeleteProgram(nsIWebGLProgram *program) = 0;

  /* void deleteFramebuffer (in nsIWebGLFramebuffer framebuffer); */
  NS_SCRIPTABLE NS_IMETHOD DeleteFramebuffer(nsIWebGLFramebuffer *framebuffer) = 0;

  /* void deleteRenderbuffer (in nsIWebGLRenderbuffer renderbuffer); */
  NS_SCRIPTABLE NS_IMETHOD DeleteRenderbuffer(nsIWebGLRenderbuffer *renderbuffer) = 0;

  /* void deleteShader (in nsIWebGLShader shader); */
  NS_SCRIPTABLE NS_IMETHOD DeleteShader(nsIWebGLShader *shader) = 0;

  /* void deleteTexture (in nsIWebGLTexture texture); */
  NS_SCRIPTABLE NS_IMETHOD DeleteTexture(nsIWebGLTexture *texture) = 0;

  /* void depthFunc (in WebGLenum func); */
  NS_SCRIPTABLE NS_IMETHOD DepthFunc(WebGLenum func) = 0;

  /* void depthMask (in WebGLboolean flag); */
  NS_SCRIPTABLE NS_IMETHOD DepthMask(WebGLboolean flag) = 0;

  /* void depthRange (in WebGLclampf zNear, in WebGLclampf zFar); */
  NS_SCRIPTABLE NS_IMETHOD DepthRange(WebGLclampf zNear, WebGLclampf zFar) = 0;

  /* void detachShader (in nsIWebGLProgram program, in nsIWebGLShader shader); */
  NS_SCRIPTABLE NS_IMETHOD DetachShader(nsIWebGLProgram *program, nsIWebGLShader *shader) = 0;

  /* void disable (in WebGLenum cap); */
  NS_SCRIPTABLE NS_IMETHOD Disable(WebGLenum cap) = 0;

  /* void disableVertexAttribArray (in WebGLuint index); */
  NS_SCRIPTABLE NS_IMETHOD DisableVertexAttribArray(WebGLuint index) = 0;

  /* void drawArrays (in WebGLenum mode, in WebGLint first, in WebGLsizei count); */
  NS_SCRIPTABLE NS_IMETHOD DrawArrays(WebGLenum mode, WebGLint first, WebGLsizei count) = 0;

  /* void drawElements (in WebGLenum mode, in WebGLsizei count, in WebGLenum type, in WebGLint offset); */
  NS_SCRIPTABLE NS_IMETHOD DrawElements(WebGLenum mode, WebGLsizei count, WebGLenum type, WebGLint offset) = 0;

  /* void enable (in WebGLenum cap); */
  NS_SCRIPTABLE NS_IMETHOD Enable(WebGLenum cap) = 0;

  /* void enableVertexAttribArray (in WebGLuint index); */
  NS_SCRIPTABLE NS_IMETHOD EnableVertexAttribArray(WebGLuint index) = 0;

  /* void finish (); */
  NS_SCRIPTABLE NS_IMETHOD Finish(void) = 0;

  /* void flush (); */
  NS_SCRIPTABLE NS_IMETHOD Flush(void) = 0;

  /* void framebufferRenderbuffer (in WebGLenum target, in WebGLenum attachment, in WebGLenum renderbuffertarget, in nsIWebGLRenderbuffer renderbuffer); */
  NS_SCRIPTABLE NS_IMETHOD FramebufferRenderbuffer(WebGLenum target, WebGLenum attachment, WebGLenum renderbuffertarget, nsIWebGLRenderbuffer *renderbuffer) = 0;

  /* void framebufferTexture2D (in WebGLenum target, in WebGLenum attachment, in WebGLenum textarget, in nsIWebGLTexture texture, in WebGLint level); */
  NS_SCRIPTABLE NS_IMETHOD FramebufferTexture2D(WebGLenum target, WebGLenum attachment, WebGLenum textarget, nsIWebGLTexture *texture, WebGLint level) = 0;

  /* void frontFace (in WebGLenum mode); */
  NS_SCRIPTABLE NS_IMETHOD FrontFace(WebGLenum mode) = 0;

  /* void generateMipmap (in WebGLenum target); */
  NS_SCRIPTABLE NS_IMETHOD GenerateMipmap(WebGLenum target) = 0;

  /* nsIWebGLActiveInfo getActiveAttrib (in nsIWebGLProgram program, in PRUint32 index); */
  NS_SCRIPTABLE NS_IMETHOD GetActiveAttrib(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM) = 0;

  /* nsIWebGLActiveInfo getActiveUniform (in nsIWebGLProgram program, in PRUint32 index); */
  NS_SCRIPTABLE NS_IMETHOD GetActiveUniform(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM) = 0;

  /* nsIVariant getAttachedShaders (in nsIWebGLProgram program); */
  NS_SCRIPTABLE NS_IMETHOD GetAttachedShaders(nsIWebGLProgram *program, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* WebGLint getAttribLocation (in nsIWebGLProgram program, in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD GetAttribLocation(nsIWebGLProgram *program, const nsAString & name, WebGLint *_retval NS_OUTPARAM) = 0;

  /* nsIVariant getParameter (in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetParameter(WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* nsIVariant getBufferParameter (in WebGLenum target, in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetBufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* WebGLenum getError (); */
  NS_SCRIPTABLE NS_IMETHOD GetError(WebGLenum *_retval NS_OUTPARAM) = 0;

  /* nsIVariant getFramebufferAttachmentParameter (in WebGLenum target, in WebGLenum attachment, in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetFramebufferAttachmentParameter(WebGLenum target, WebGLenum attachment, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* nsIVariant getProgramParameter (in nsIWebGLProgram program, in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetProgramParameter(nsIWebGLProgram *program, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* DOMString getProgramInfoLog (in nsIWebGLProgram program); */
  NS_SCRIPTABLE NS_IMETHOD GetProgramInfoLog(nsIWebGLProgram *program, nsAString & _retval NS_OUTPARAM) = 0;

  /* nsIVariant getRenderbufferParameter (in WebGLenum target, in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetRenderbufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* nsIVariant getShaderParameter (in nsIWebGLShader shader, in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetShaderParameter(nsIWebGLShader *shader, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* DOMString getShaderInfoLog (in nsIWebGLShader shader); */
  NS_SCRIPTABLE NS_IMETHOD GetShaderInfoLog(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString getShaderSource (in nsIWebGLShader shader); */
  NS_SCRIPTABLE NS_IMETHOD GetShaderSource(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM) = 0;

  /* nsIVariant getTexParameter (in WebGLenum target, in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetTexParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* nsIVariant getUniform (in nsIWebGLProgram program, in nsIWebGLUniformLocation location); */
  NS_SCRIPTABLE NS_IMETHOD GetUniform(nsIWebGLProgram *program, nsIWebGLUniformLocation *location, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* nsIWebGLUniformLocation getUniformLocation (in nsIWebGLProgram program, in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD GetUniformLocation(nsIWebGLProgram *program, const nsAString & name, nsIWebGLUniformLocation **_retval NS_OUTPARAM) = 0;

  /* nsIVariant getVertexAttrib (in WebGLuint index, in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetVertexAttrib(WebGLuint index, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* WebGLuint getVertexAttribOffset (in WebGLuint index, in WebGLenum pname); */
  NS_SCRIPTABLE NS_IMETHOD GetVertexAttribOffset(WebGLuint index, WebGLenum pname, WebGLuint *_retval NS_OUTPARAM) = 0;

  /* void hint (in WebGLenum target, in WebGLenum mode); */
  NS_SCRIPTABLE NS_IMETHOD Hint(WebGLenum target, WebGLenum mode) = 0;

  /* WebGLboolean isBuffer (in nsIWebGLBuffer buffer); */
  NS_SCRIPTABLE NS_IMETHOD IsBuffer(nsIWebGLBuffer *buffer, WebGLboolean *_retval NS_OUTPARAM) = 0;

  /* WebGLboolean isFramebuffer (in nsIWebGLFramebuffer framebuffer); */
  NS_SCRIPTABLE NS_IMETHOD IsFramebuffer(nsIWebGLFramebuffer *framebuffer, WebGLboolean *_retval NS_OUTPARAM) = 0;

  /* WebGLboolean isProgram (in nsIWebGLProgram program); */
  NS_SCRIPTABLE NS_IMETHOD IsProgram(nsIWebGLProgram *program, WebGLboolean *_retval NS_OUTPARAM) = 0;

  /* WebGLboolean isRenderbuffer (in nsIWebGLRenderbuffer renderbuffer); */
  NS_SCRIPTABLE NS_IMETHOD IsRenderbuffer(nsIWebGLRenderbuffer *renderbuffer, WebGLboolean *_retval NS_OUTPARAM) = 0;

  /* WebGLboolean isShader (in nsIWebGLShader shader); */
  NS_SCRIPTABLE NS_IMETHOD IsShader(nsIWebGLShader *shader, WebGLboolean *_retval NS_OUTPARAM) = 0;

  /* WebGLboolean isTexture (in nsIWebGLTexture texture); */
  NS_SCRIPTABLE NS_IMETHOD IsTexture(nsIWebGLTexture *texture, WebGLboolean *_retval NS_OUTPARAM) = 0;

  /* WebGLboolean isEnabled (in WebGLenum cap); */
  NS_SCRIPTABLE NS_IMETHOD IsEnabled(WebGLenum cap, WebGLboolean *_retval NS_OUTPARAM) = 0;

  /* void lineWidth (in WebGLfloat width); */
  NS_SCRIPTABLE NS_IMETHOD LineWidth(WebGLfloat width) = 0;

  /* void linkProgram ([optional] in nsIWebGLProgram program); */
  NS_SCRIPTABLE NS_IMETHOD LinkProgram(nsIWebGLProgram *program) = 0;

  /* void pixelStorei (in WebGLenum pname, in WebGLint param); */
  NS_SCRIPTABLE NS_IMETHOD PixelStorei(WebGLenum pname, WebGLint param) = 0;

  /* void polygonOffset (in WebGLfloat factor, in WebGLfloat units); */
  NS_SCRIPTABLE NS_IMETHOD PolygonOffset(WebGLfloat factor, WebGLfloat units) = 0;

  /* void readPixels ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD ReadPixels(PRInt32 dummy) = 0;

  /* [noscript] void readPixels_array (in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
  NS_IMETHOD ReadPixels_array(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) = 0;

  /* [noscript] void readPixels_buf (in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayBufferPtr pixels); */
  NS_IMETHOD ReadPixels_buf(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) = 0;

  /* void renderbufferStorage (in WebGLenum target, in WebGLenum internalformat, in WebGLsizei width, in WebGLsizei height); */
  NS_SCRIPTABLE NS_IMETHOD RenderbufferStorage(WebGLenum target, WebGLenum internalformat, WebGLsizei width, WebGLsizei height) = 0;

  /* void sampleCoverage (in WebGLclampf value, in WebGLboolean invert); */
  NS_SCRIPTABLE NS_IMETHOD SampleCoverage(WebGLclampf value, WebGLboolean invert) = 0;

  /* void scissor (in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height); */
  NS_SCRIPTABLE NS_IMETHOD Scissor(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) = 0;

  /* void shaderSource ([optional] in nsIWebGLShader shader, [optional] in DOMString source); */
  NS_SCRIPTABLE NS_IMETHOD ShaderSource(nsIWebGLShader *shader, const nsAString & source) = 0;

  /* void stencilFunc (in WebGLenum func, in WebGLint ref, in WebGLuint mask); */
  NS_SCRIPTABLE NS_IMETHOD StencilFunc(WebGLenum func, WebGLint ref, WebGLuint mask) = 0;

  /* void stencilFuncSeparate (in WebGLenum face, in WebGLenum func, in WebGLint ref, in WebGLuint mask); */
  NS_SCRIPTABLE NS_IMETHOD StencilFuncSeparate(WebGLenum face, WebGLenum func, WebGLint ref, WebGLuint mask) = 0;

  /* void stencilMask (in WebGLuint mask); */
  NS_SCRIPTABLE NS_IMETHOD StencilMask(WebGLuint mask) = 0;

  /* void stencilMaskSeparate (in WebGLenum face, in WebGLuint mask); */
  NS_SCRIPTABLE NS_IMETHOD StencilMaskSeparate(WebGLenum face, WebGLuint mask) = 0;

  /* void stencilOp (in WebGLenum fail, in WebGLenum zfail, in WebGLenum zpass); */
  NS_SCRIPTABLE NS_IMETHOD StencilOp(WebGLenum fail, WebGLenum zfail, WebGLenum zpass) = 0;

  /* void stencilOpSeparate (in WebGLenum face, in WebGLenum fail, in WebGLenum zfail, in WebGLenum zpass); */
  NS_SCRIPTABLE NS_IMETHOD StencilOpSeparate(WebGLenum face, WebGLenum fail, WebGLenum zfail, WebGLenum zpass) = 0;

  /* void texImage2D ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD TexImage2D(PRInt32 dummy) = 0;

  /* [noscript] void texImage2D_buf (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLsizei width, in WebGLsizei height, in WebGLint border, in WebGLenum format, in WebGLenum type, in WebGLArrayBufferPtr pixels); */
  NS_IMETHOD TexImage2D_buf(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) = 0;

  /* [noscript] void texImage2D_array (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLsizei width, in WebGLsizei height, in WebGLint border, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
  NS_IMETHOD TexImage2D_array(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels) = 0;

  /* [noscript] void texImage2D_imageData (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLsizei width, in WebGLsizei height, in WebGLint border, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
  NS_IMETHOD TexImage2D_imageData(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels) = 0;

  /* [noscript] void texImage2D_dom (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLenum format, in WebGLenum type, in nsIDOMElement element); */
  NS_IMETHOD TexImage2D_dom(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLenum format, WebGLenum type, nsIDOMElement *element) = 0;

  /* void texSubImage2D ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD TexSubImage2D(PRInt32 dummy) = 0;

  /* [noscript] void texSubImage2D_buf (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayBufferPtr pixels); */
  NS_IMETHOD TexSubImage2D_buf(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) = 0;

  /* [noscript] void texSubImage2D_array (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
  NS_IMETHOD TexSubImage2D_array(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) = 0;

  /* [noscript] void texSubImage2D_imageData (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
  NS_IMETHOD TexSubImage2D_imageData(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) = 0;

  /* [noscript] void texSubImage2D_dom (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLenum format, in WebGLenum type, in nsIDOMElement element); */
  NS_IMETHOD TexSubImage2D_dom(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLenum format, WebGLenum type, nsIDOMElement *element) = 0;

  /* void texParameterf (in WebGLenum target, in WebGLenum pname, in WebGLfloat param); */
  NS_SCRIPTABLE NS_IMETHOD TexParameterf(WebGLenum target, WebGLenum pname, WebGLfloat param) = 0;

  /* void texParameteri (in WebGLenum target, in WebGLenum pname, in WebGLint param); */
  NS_SCRIPTABLE NS_IMETHOD TexParameteri(WebGLenum target, WebGLenum pname, WebGLint param) = 0;

  /* void uniform1f (in nsIWebGLUniformLocation location, in WebGLfloat x); */
  NS_SCRIPTABLE NS_IMETHOD Uniform1f(nsIWebGLUniformLocation *location, WebGLfloat x) = 0;

  /* void uniform1i (in nsIWebGLUniformLocation location, in WebGLint x); */
  NS_SCRIPTABLE NS_IMETHOD Uniform1i(nsIWebGLUniformLocation *location, WebGLint x) = 0;

  /* void uniform2f (in nsIWebGLUniformLocation location, in WebGLfloat x, in WebGLfloat y); */
  NS_SCRIPTABLE NS_IMETHOD Uniform2f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y) = 0;

  /* void uniform2i (in nsIWebGLUniformLocation location, in WebGLint x, in WebGLint y); */
  NS_SCRIPTABLE NS_IMETHOD Uniform2i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y) = 0;

  /* void uniform3f (in nsIWebGLUniformLocation location, in WebGLfloat x, in WebGLfloat y, in WebGLfloat z); */
  NS_SCRIPTABLE NS_IMETHOD Uniform3f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z) = 0;

  /* void uniform3i (in nsIWebGLUniformLocation location, in WebGLint x, in WebGLint y, in WebGLint z); */
  NS_SCRIPTABLE NS_IMETHOD Uniform3i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z) = 0;

  /* void uniform4f (in nsIWebGLUniformLocation location, in WebGLfloat x, in WebGLfloat y, in WebGLfloat z, in WebGLfloat w); */
  NS_SCRIPTABLE NS_IMETHOD Uniform4f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w) = 0;

  /* void uniform4i (in nsIWebGLUniformLocation location, in WebGLint x, in WebGLint y, in WebGLint z, in WebGLint w); */
  NS_SCRIPTABLE NS_IMETHOD Uniform4i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z, WebGLint w) = 0;

  /* void uniform1fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD Uniform1fv(PRInt32 dummy) = 0;

  /* void uniform1iv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD Uniform1iv(PRInt32 dummy) = 0;

  /* void uniform2fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD Uniform2fv(PRInt32 dummy) = 0;

  /* void uniform2iv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD Uniform2iv(PRInt32 dummy) = 0;

  /* void uniform3fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD Uniform3fv(PRInt32 dummy) = 0;

  /* void uniform3iv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD Uniform3iv(PRInt32 dummy) = 0;

  /* void uniform4fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD Uniform4fv(PRInt32 dummy) = 0;

  /* void uniform4iv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD Uniform4iv(PRInt32 dummy) = 0;

  /* [noscript] void uniform1fv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
  NS_IMETHOD Uniform1fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) = 0;

  /* [noscript] void uniform1iv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
  NS_IMETHOD Uniform1iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) = 0;

  /* [noscript] void uniform2fv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
  NS_IMETHOD Uniform2fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) = 0;

  /* [noscript] void uniform2iv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
  NS_IMETHOD Uniform2iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) = 0;

  /* [noscript] void uniform3fv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
  NS_IMETHOD Uniform3fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) = 0;

  /* [noscript] void uniform3iv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
  NS_IMETHOD Uniform3iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) = 0;

  /* [noscript] void uniform4fv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
  NS_IMETHOD Uniform4fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) = 0;

  /* [noscript] void uniform4iv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
  NS_IMETHOD Uniform4iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) = 0;

  /* void uniformMatrix2fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix2fv(PRInt32 dummy) = 0;

  /* void uniformMatrix3fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix3fv(PRInt32 dummy) = 0;

  /* void uniformMatrix4fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix4fv(PRInt32 dummy) = 0;

  /* [noscript] void uniformMatrix2fv_array (in nsIWebGLUniformLocation location, in WebGLboolean transpose, in WebGLArrayPtr value); */
  NS_IMETHOD UniformMatrix2fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) = 0;

  /* [noscript] void uniformMatrix3fv_array (in nsIWebGLUniformLocation location, in WebGLboolean transpose, in WebGLArrayPtr value); */
  NS_IMETHOD UniformMatrix3fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) = 0;

  /* [noscript] void uniformMatrix4fv_array (in nsIWebGLUniformLocation location, in WebGLboolean transpose, in WebGLArrayPtr value); */
  NS_IMETHOD UniformMatrix4fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) = 0;

  /* void useProgram (in nsIWebGLProgram program); */
  NS_SCRIPTABLE NS_IMETHOD UseProgram(nsIWebGLProgram *program) = 0;

  /* void validateProgram (in nsIWebGLProgram program); */
  NS_SCRIPTABLE NS_IMETHOD ValidateProgram(nsIWebGLProgram *program) = 0;

  /* void vertexAttrib1f (in WebGLuint indx, in WebGLfloat x); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib1f(WebGLuint indx, WebGLfloat x) = 0;

  /* void vertexAttrib2f (in WebGLuint indx, in WebGLfloat x, in WebGLfloat y); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib2f(WebGLuint indx, WebGLfloat x, WebGLfloat y) = 0;

  /* void vertexAttrib3f (in WebGLuint indx, in WebGLfloat x, in WebGLfloat y, in WebGLfloat z); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib3f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z) = 0;

  /* void vertexAttrib4f (in WebGLuint indx, in WebGLfloat x, in WebGLfloat y, in WebGLfloat z, in WebGLfloat w); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib4f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w) = 0;

  /* void vertexAttrib1fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib1fv(PRInt32 dummy) = 0;

  /* void vertexAttrib2fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib2fv(PRInt32 dummy) = 0;

  /* void vertexAttrib3fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib3fv(PRInt32 dummy) = 0;

  /* void vertexAttrib4fv ([optional] in long dummy); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib4fv(PRInt32 dummy) = 0;

  /* [noscript] void vertexAttrib1fv_array (in WebGLuint indx, in WebGLArrayPtr values); */
  NS_IMETHOD VertexAttrib1fv_array(WebGLuint indx, js::TypedArray *values) = 0;

  /* [noscript] void vertexAttrib2fv_array (in WebGLuint indx, in WebGLArrayPtr values); */
  NS_IMETHOD VertexAttrib2fv_array(WebGLuint indx, js::TypedArray *values) = 0;

  /* [noscript] void vertexAttrib3fv_array (in WebGLuint indx, in WebGLArrayPtr values); */
  NS_IMETHOD VertexAttrib3fv_array(WebGLuint indx, js::TypedArray *values) = 0;

  /* [noscript] void vertexAttrib4fv_array (in WebGLuint indx, in WebGLArrayPtr values); */
  NS_IMETHOD VertexAttrib4fv_array(WebGLuint indx, js::TypedArray *values) = 0;

  /* void vertexAttribPointer (in WebGLuint idx, in WebGLint size, in WebGLenum type, in WebGLboolean normalized, in WebGLsizei stride, in WebGLsizeiptr offset); */
  NS_SCRIPTABLE NS_IMETHOD VertexAttribPointer(WebGLuint idx, WebGLint size, WebGLenum type, WebGLboolean normalized, WebGLsizei stride, WebGLsizeiptr offset) = 0;

  /* void viewport (in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height); */
  NS_SCRIPTABLE NS_IMETHOD Viewport(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) = 0;

  /* [noscript] DOMString mozGetUnderlyingParamString (in WebGLenum pname); */
  NS_IMETHOD MozGetUnderlyingParamString(WebGLenum pname, nsAString & _retval NS_OUTPARAM) = 0;

  /* nsISupports getExtension (in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD GetExtension(const nsAString & name, nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWebGLRenderingContext, NS_IDOMWEBGLRENDERINGCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWEBGLRENDERINGCONTEXT \
  NS_SCRIPTABLE NS_IMETHOD GetCanvas(nsIDOMHTMLCanvasElement **aCanvas); \
  NS_SCRIPTABLE NS_IMETHOD GetContextAttributes(jsval *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ActiveTexture(WebGLenum texture); \
  NS_SCRIPTABLE NS_IMETHOD AttachShader(nsIWebGLProgram *program, nsIWebGLShader *shader); \
  NS_SCRIPTABLE NS_IMETHOD BindAttribLocation(nsIWebGLProgram *program, WebGLuint index, const nsAString & name); \
  NS_SCRIPTABLE NS_IMETHOD BindBuffer(WebGLenum target, nsIWebGLBuffer *buffer); \
  NS_SCRIPTABLE NS_IMETHOD BindFramebuffer(WebGLenum target, nsIWebGLFramebuffer *framebuffer); \
  NS_SCRIPTABLE NS_IMETHOD BindRenderbuffer(WebGLenum target, nsIWebGLRenderbuffer *renderbuffer); \
  NS_SCRIPTABLE NS_IMETHOD BindTexture(WebGLenum target, nsIWebGLTexture *texture); \
  NS_SCRIPTABLE NS_IMETHOD BlendColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha); \
  NS_SCRIPTABLE NS_IMETHOD BlendEquation(WebGLenum mode); \
  NS_SCRIPTABLE NS_IMETHOD BlendEquationSeparate(WebGLenum modeRGB, WebGLenum modeAlpha); \
  NS_SCRIPTABLE NS_IMETHOD BlendFunc(WebGLenum sfactor, WebGLenum dfactor); \
  NS_SCRIPTABLE NS_IMETHOD BlendFuncSeparate(WebGLenum srcRGB, WebGLenum dstRGB, WebGLenum srcAlpha, WebGLenum dstAlpha); \
  NS_SCRIPTABLE NS_IMETHOD BufferData(PRInt32 dummy); \
  NS_IMETHOD BufferData_size(WebGLenum target, WebGLsizei size, WebGLenum usage); \
  NS_IMETHOD BufferData_buf(WebGLenum target, js::ArrayBuffer *data, WebGLenum usage); \
  NS_IMETHOD BufferData_array(WebGLenum target, js::TypedArray *data, WebGLenum usage); \
  NS_IMETHOD BufferData_null(void); \
  NS_SCRIPTABLE NS_IMETHOD BufferSubData(PRInt32 dummy); \
  NS_IMETHOD BufferSubData_buf(WebGLenum target, PRInt32 offset, js::ArrayBuffer *data); \
  NS_IMETHOD BufferSubData_array(WebGLenum target, PRInt32 offset, js::TypedArray *data); \
  NS_IMETHOD BufferSubData_null(void); \
  NS_SCRIPTABLE NS_IMETHOD CheckFramebufferStatus(WebGLenum target, WebGLenum *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clear(WebGLbitfield mask); \
  NS_SCRIPTABLE NS_IMETHOD ClearColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha); \
  NS_SCRIPTABLE NS_IMETHOD ClearDepth(WebGLclampf depth); \
  NS_SCRIPTABLE NS_IMETHOD ClearStencil(WebGLint s); \
  NS_SCRIPTABLE NS_IMETHOD ColorMask(WebGLboolean red, WebGLboolean green, WebGLboolean blue, WebGLboolean alpha); \
  NS_SCRIPTABLE NS_IMETHOD CompileShader(nsIWebGLShader *shader); \
  NS_SCRIPTABLE NS_IMETHOD CopyTexImage2D(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLint border); \
  NS_SCRIPTABLE NS_IMETHOD CopyTexSubImage2D(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height); \
  NS_SCRIPTABLE NS_IMETHOD CreateBuffer(nsIWebGLBuffer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateProgram(nsIWebGLProgram **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateFramebuffer(nsIWebGLFramebuffer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateRenderbuffer(nsIWebGLRenderbuffer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateShader(WebGLenum type, nsIWebGLShader **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateTexture(nsIWebGLTexture **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CullFace(WebGLenum mode); \
  NS_SCRIPTABLE NS_IMETHOD DeleteBuffer(nsIWebGLBuffer *buffer); \
  NS_SCRIPTABLE NS_IMETHOD DeleteProgram(nsIWebGLProgram *program); \
  NS_SCRIPTABLE NS_IMETHOD DeleteFramebuffer(nsIWebGLFramebuffer *framebuffer); \
  NS_SCRIPTABLE NS_IMETHOD DeleteRenderbuffer(nsIWebGLRenderbuffer *renderbuffer); \
  NS_SCRIPTABLE NS_IMETHOD DeleteShader(nsIWebGLShader *shader); \
  NS_SCRIPTABLE NS_IMETHOD DeleteTexture(nsIWebGLTexture *texture); \
  NS_SCRIPTABLE NS_IMETHOD DepthFunc(WebGLenum func); \
  NS_SCRIPTABLE NS_IMETHOD DepthMask(WebGLboolean flag); \
  NS_SCRIPTABLE NS_IMETHOD DepthRange(WebGLclampf zNear, WebGLclampf zFar); \
  NS_SCRIPTABLE NS_IMETHOD DetachShader(nsIWebGLProgram *program, nsIWebGLShader *shader); \
  NS_SCRIPTABLE NS_IMETHOD Disable(WebGLenum cap); \
  NS_SCRIPTABLE NS_IMETHOD DisableVertexAttribArray(WebGLuint index); \
  NS_SCRIPTABLE NS_IMETHOD DrawArrays(WebGLenum mode, WebGLint first, WebGLsizei count); \
  NS_SCRIPTABLE NS_IMETHOD DrawElements(WebGLenum mode, WebGLsizei count, WebGLenum type, WebGLint offset); \
  NS_SCRIPTABLE NS_IMETHOD Enable(WebGLenum cap); \
  NS_SCRIPTABLE NS_IMETHOD EnableVertexAttribArray(WebGLuint index); \
  NS_SCRIPTABLE NS_IMETHOD Finish(void); \
  NS_SCRIPTABLE NS_IMETHOD Flush(void); \
  NS_SCRIPTABLE NS_IMETHOD FramebufferRenderbuffer(WebGLenum target, WebGLenum attachment, WebGLenum renderbuffertarget, nsIWebGLRenderbuffer *renderbuffer); \
  NS_SCRIPTABLE NS_IMETHOD FramebufferTexture2D(WebGLenum target, WebGLenum attachment, WebGLenum textarget, nsIWebGLTexture *texture, WebGLint level); \
  NS_SCRIPTABLE NS_IMETHOD FrontFace(WebGLenum mode); \
  NS_SCRIPTABLE NS_IMETHOD GenerateMipmap(WebGLenum target); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveAttrib(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveUniform(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAttachedShaders(nsIWebGLProgram *program, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAttribLocation(nsIWebGLProgram *program, const nsAString & name, WebGLint *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(WebGLenum pname, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetError(WebGLenum *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFramebufferAttachmentParameter(WebGLenum target, WebGLenum attachment, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetProgramParameter(nsIWebGLProgram *program, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetProgramInfoLog(nsIWebGLProgram *program, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRenderbufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetShaderParameter(nsIWebGLShader *shader, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetShaderInfoLog(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetShaderSource(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTexParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUniform(nsIWebGLProgram *program, nsIWebGLUniformLocation *location, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUniformLocation(nsIWebGLProgram *program, const nsAString & name, nsIWebGLUniformLocation **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetVertexAttrib(WebGLuint index, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetVertexAttribOffset(WebGLuint index, WebGLenum pname, WebGLuint *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Hint(WebGLenum target, WebGLenum mode); \
  NS_SCRIPTABLE NS_IMETHOD IsBuffer(nsIWebGLBuffer *buffer, WebGLboolean *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsFramebuffer(nsIWebGLFramebuffer *framebuffer, WebGLboolean *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsProgram(nsIWebGLProgram *program, WebGLboolean *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsRenderbuffer(nsIWebGLRenderbuffer *renderbuffer, WebGLboolean *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsShader(nsIWebGLShader *shader, WebGLboolean *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsTexture(nsIWebGLTexture *texture, WebGLboolean *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsEnabled(WebGLenum cap, WebGLboolean *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LineWidth(WebGLfloat width); \
  NS_SCRIPTABLE NS_IMETHOD LinkProgram(nsIWebGLProgram *program); \
  NS_SCRIPTABLE NS_IMETHOD PixelStorei(WebGLenum pname, WebGLint param); \
  NS_SCRIPTABLE NS_IMETHOD PolygonOffset(WebGLfloat factor, WebGLfloat units); \
  NS_SCRIPTABLE NS_IMETHOD ReadPixels(PRInt32 dummy); \
  NS_IMETHOD ReadPixels_array(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels); \
  NS_IMETHOD ReadPixels_buf(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels); \
  NS_SCRIPTABLE NS_IMETHOD RenderbufferStorage(WebGLenum target, WebGLenum internalformat, WebGLsizei width, WebGLsizei height); \
  NS_SCRIPTABLE NS_IMETHOD SampleCoverage(WebGLclampf value, WebGLboolean invert); \
  NS_SCRIPTABLE NS_IMETHOD Scissor(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height); \
  NS_SCRIPTABLE NS_IMETHOD ShaderSource(nsIWebGLShader *shader, const nsAString & source); \
  NS_SCRIPTABLE NS_IMETHOD StencilFunc(WebGLenum func, WebGLint ref, WebGLuint mask); \
  NS_SCRIPTABLE NS_IMETHOD StencilFuncSeparate(WebGLenum face, WebGLenum func, WebGLint ref, WebGLuint mask); \
  NS_SCRIPTABLE NS_IMETHOD StencilMask(WebGLuint mask); \
  NS_SCRIPTABLE NS_IMETHOD StencilMaskSeparate(WebGLenum face, WebGLuint mask); \
  NS_SCRIPTABLE NS_IMETHOD StencilOp(WebGLenum fail, WebGLenum zfail, WebGLenum zpass); \
  NS_SCRIPTABLE NS_IMETHOD StencilOpSeparate(WebGLenum face, WebGLenum fail, WebGLenum zfail, WebGLenum zpass); \
  NS_SCRIPTABLE NS_IMETHOD TexImage2D(PRInt32 dummy); \
  NS_IMETHOD TexImage2D_buf(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels); \
  NS_IMETHOD TexImage2D_array(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels); \
  NS_IMETHOD TexImage2D_imageData(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels); \
  NS_IMETHOD TexImage2D_dom(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLenum format, WebGLenum type, nsIDOMElement *element); \
  NS_SCRIPTABLE NS_IMETHOD TexSubImage2D(PRInt32 dummy); \
  NS_IMETHOD TexSubImage2D_buf(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels); \
  NS_IMETHOD TexSubImage2D_array(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels); \
  NS_IMETHOD TexSubImage2D_imageData(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels); \
  NS_IMETHOD TexSubImage2D_dom(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLenum format, WebGLenum type, nsIDOMElement *element); \
  NS_SCRIPTABLE NS_IMETHOD TexParameterf(WebGLenum target, WebGLenum pname, WebGLfloat param); \
  NS_SCRIPTABLE NS_IMETHOD TexParameteri(WebGLenum target, WebGLenum pname, WebGLint param); \
  NS_SCRIPTABLE NS_IMETHOD Uniform1f(nsIWebGLUniformLocation *location, WebGLfloat x); \
  NS_SCRIPTABLE NS_IMETHOD Uniform1i(nsIWebGLUniformLocation *location, WebGLint x); \
  NS_SCRIPTABLE NS_IMETHOD Uniform2f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y); \
  NS_SCRIPTABLE NS_IMETHOD Uniform2i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y); \
  NS_SCRIPTABLE NS_IMETHOD Uniform3f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z); \
  NS_SCRIPTABLE NS_IMETHOD Uniform3i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z); \
  NS_SCRIPTABLE NS_IMETHOD Uniform4f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w); \
  NS_SCRIPTABLE NS_IMETHOD Uniform4i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z, WebGLint w); \
  NS_SCRIPTABLE NS_IMETHOD Uniform1fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD Uniform1iv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD Uniform2fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD Uniform2iv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD Uniform3fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD Uniform3iv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD Uniform4fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD Uniform4iv(PRInt32 dummy); \
  NS_IMETHOD Uniform1fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v); \
  NS_IMETHOD Uniform1iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v); \
  NS_IMETHOD Uniform2fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v); \
  NS_IMETHOD Uniform2iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v); \
  NS_IMETHOD Uniform3fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v); \
  NS_IMETHOD Uniform3iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v); \
  NS_IMETHOD Uniform4fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v); \
  NS_IMETHOD Uniform4iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v); \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix2fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix3fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix4fv(PRInt32 dummy); \
  NS_IMETHOD UniformMatrix2fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value); \
  NS_IMETHOD UniformMatrix3fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value); \
  NS_IMETHOD UniformMatrix4fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value); \
  NS_SCRIPTABLE NS_IMETHOD UseProgram(nsIWebGLProgram *program); \
  NS_SCRIPTABLE NS_IMETHOD ValidateProgram(nsIWebGLProgram *program); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib1f(WebGLuint indx, WebGLfloat x); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib2f(WebGLuint indx, WebGLfloat x, WebGLfloat y); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib3f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib4f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib1fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib2fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib3fv(PRInt32 dummy); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib4fv(PRInt32 dummy); \
  NS_IMETHOD VertexAttrib1fv_array(WebGLuint indx, js::TypedArray *values); \
  NS_IMETHOD VertexAttrib2fv_array(WebGLuint indx, js::TypedArray *values); \
  NS_IMETHOD VertexAttrib3fv_array(WebGLuint indx, js::TypedArray *values); \
  NS_IMETHOD VertexAttrib4fv_array(WebGLuint indx, js::TypedArray *values); \
  NS_SCRIPTABLE NS_IMETHOD VertexAttribPointer(WebGLuint idx, WebGLint size, WebGLenum type, WebGLboolean normalized, WebGLsizei stride, WebGLsizeiptr offset); \
  NS_SCRIPTABLE NS_IMETHOD Viewport(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height); \
  NS_IMETHOD MozGetUnderlyingParamString(WebGLenum pname, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetExtension(const nsAString & name, nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWEBGLRENDERINGCONTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCanvas(nsIDOMHTMLCanvasElement **aCanvas) { return _to GetCanvas(aCanvas); } \
  NS_SCRIPTABLE NS_IMETHOD GetContextAttributes(jsval *_retval NS_OUTPARAM) { return _to GetContextAttributes(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ActiveTexture(WebGLenum texture) { return _to ActiveTexture(texture); } \
  NS_SCRIPTABLE NS_IMETHOD AttachShader(nsIWebGLProgram *program, nsIWebGLShader *shader) { return _to AttachShader(program, shader); } \
  NS_SCRIPTABLE NS_IMETHOD BindAttribLocation(nsIWebGLProgram *program, WebGLuint index, const nsAString & name) { return _to BindAttribLocation(program, index, name); } \
  NS_SCRIPTABLE NS_IMETHOD BindBuffer(WebGLenum target, nsIWebGLBuffer *buffer) { return _to BindBuffer(target, buffer); } \
  NS_SCRIPTABLE NS_IMETHOD BindFramebuffer(WebGLenum target, nsIWebGLFramebuffer *framebuffer) { return _to BindFramebuffer(target, framebuffer); } \
  NS_SCRIPTABLE NS_IMETHOD BindRenderbuffer(WebGLenum target, nsIWebGLRenderbuffer *renderbuffer) { return _to BindRenderbuffer(target, renderbuffer); } \
  NS_SCRIPTABLE NS_IMETHOD BindTexture(WebGLenum target, nsIWebGLTexture *texture) { return _to BindTexture(target, texture); } \
  NS_SCRIPTABLE NS_IMETHOD BlendColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha) { return _to BlendColor(red, green, blue, alpha); } \
  NS_SCRIPTABLE NS_IMETHOD BlendEquation(WebGLenum mode) { return _to BlendEquation(mode); } \
  NS_SCRIPTABLE NS_IMETHOD BlendEquationSeparate(WebGLenum modeRGB, WebGLenum modeAlpha) { return _to BlendEquationSeparate(modeRGB, modeAlpha); } \
  NS_SCRIPTABLE NS_IMETHOD BlendFunc(WebGLenum sfactor, WebGLenum dfactor) { return _to BlendFunc(sfactor, dfactor); } \
  NS_SCRIPTABLE NS_IMETHOD BlendFuncSeparate(WebGLenum srcRGB, WebGLenum dstRGB, WebGLenum srcAlpha, WebGLenum dstAlpha) { return _to BlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha); } \
  NS_SCRIPTABLE NS_IMETHOD BufferData(PRInt32 dummy) { return _to BufferData(dummy); } \
  NS_IMETHOD BufferData_size(WebGLenum target, WebGLsizei size, WebGLenum usage) { return _to BufferData_size(target, size, usage); } \
  NS_IMETHOD BufferData_buf(WebGLenum target, js::ArrayBuffer *data, WebGLenum usage) { return _to BufferData_buf(target, data, usage); } \
  NS_IMETHOD BufferData_array(WebGLenum target, js::TypedArray *data, WebGLenum usage) { return _to BufferData_array(target, data, usage); } \
  NS_IMETHOD BufferData_null(void) { return _to BufferData_null(); } \
  NS_SCRIPTABLE NS_IMETHOD BufferSubData(PRInt32 dummy) { return _to BufferSubData(dummy); } \
  NS_IMETHOD BufferSubData_buf(WebGLenum target, PRInt32 offset, js::ArrayBuffer *data) { return _to BufferSubData_buf(target, offset, data); } \
  NS_IMETHOD BufferSubData_array(WebGLenum target, PRInt32 offset, js::TypedArray *data) { return _to BufferSubData_array(target, offset, data); } \
  NS_IMETHOD BufferSubData_null(void) { return _to BufferSubData_null(); } \
  NS_SCRIPTABLE NS_IMETHOD CheckFramebufferStatus(WebGLenum target, WebGLenum *_retval NS_OUTPARAM) { return _to CheckFramebufferStatus(target, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(WebGLbitfield mask) { return _to Clear(mask); } \
  NS_SCRIPTABLE NS_IMETHOD ClearColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha) { return _to ClearColor(red, green, blue, alpha); } \
  NS_SCRIPTABLE NS_IMETHOD ClearDepth(WebGLclampf depth) { return _to ClearDepth(depth); } \
  NS_SCRIPTABLE NS_IMETHOD ClearStencil(WebGLint s) { return _to ClearStencil(s); } \
  NS_SCRIPTABLE NS_IMETHOD ColorMask(WebGLboolean red, WebGLboolean green, WebGLboolean blue, WebGLboolean alpha) { return _to ColorMask(red, green, blue, alpha); } \
  NS_SCRIPTABLE NS_IMETHOD CompileShader(nsIWebGLShader *shader) { return _to CompileShader(shader); } \
  NS_SCRIPTABLE NS_IMETHOD CopyTexImage2D(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLint border) { return _to CopyTexImage2D(target, level, internalformat, x, y, width, height, border); } \
  NS_SCRIPTABLE NS_IMETHOD CopyTexSubImage2D(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) { return _to CopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD CreateBuffer(nsIWebGLBuffer **_retval NS_OUTPARAM) { return _to CreateBuffer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateProgram(nsIWebGLProgram **_retval NS_OUTPARAM) { return _to CreateProgram(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateFramebuffer(nsIWebGLFramebuffer **_retval NS_OUTPARAM) { return _to CreateFramebuffer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateRenderbuffer(nsIWebGLRenderbuffer **_retval NS_OUTPARAM) { return _to CreateRenderbuffer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateShader(WebGLenum type, nsIWebGLShader **_retval NS_OUTPARAM) { return _to CreateShader(type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTexture(nsIWebGLTexture **_retval NS_OUTPARAM) { return _to CreateTexture(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CullFace(WebGLenum mode) { return _to CullFace(mode); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteBuffer(nsIWebGLBuffer *buffer) { return _to DeleteBuffer(buffer); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteProgram(nsIWebGLProgram *program) { return _to DeleteProgram(program); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteFramebuffer(nsIWebGLFramebuffer *framebuffer) { return _to DeleteFramebuffer(framebuffer); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteRenderbuffer(nsIWebGLRenderbuffer *renderbuffer) { return _to DeleteRenderbuffer(renderbuffer); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteShader(nsIWebGLShader *shader) { return _to DeleteShader(shader); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTexture(nsIWebGLTexture *texture) { return _to DeleteTexture(texture); } \
  NS_SCRIPTABLE NS_IMETHOD DepthFunc(WebGLenum func) { return _to DepthFunc(func); } \
  NS_SCRIPTABLE NS_IMETHOD DepthMask(WebGLboolean flag) { return _to DepthMask(flag); } \
  NS_SCRIPTABLE NS_IMETHOD DepthRange(WebGLclampf zNear, WebGLclampf zFar) { return _to DepthRange(zNear, zFar); } \
  NS_SCRIPTABLE NS_IMETHOD DetachShader(nsIWebGLProgram *program, nsIWebGLShader *shader) { return _to DetachShader(program, shader); } \
  NS_SCRIPTABLE NS_IMETHOD Disable(WebGLenum cap) { return _to Disable(cap); } \
  NS_SCRIPTABLE NS_IMETHOD DisableVertexAttribArray(WebGLuint index) { return _to DisableVertexAttribArray(index); } \
  NS_SCRIPTABLE NS_IMETHOD DrawArrays(WebGLenum mode, WebGLint first, WebGLsizei count) { return _to DrawArrays(mode, first, count); } \
  NS_SCRIPTABLE NS_IMETHOD DrawElements(WebGLenum mode, WebGLsizei count, WebGLenum type, WebGLint offset) { return _to DrawElements(mode, count, type, offset); } \
  NS_SCRIPTABLE NS_IMETHOD Enable(WebGLenum cap) { return _to Enable(cap); } \
  NS_SCRIPTABLE NS_IMETHOD EnableVertexAttribArray(WebGLuint index) { return _to EnableVertexAttribArray(index); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(void) { return _to Finish(); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return _to Flush(); } \
  NS_SCRIPTABLE NS_IMETHOD FramebufferRenderbuffer(WebGLenum target, WebGLenum attachment, WebGLenum renderbuffertarget, nsIWebGLRenderbuffer *renderbuffer) { return _to FramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); } \
  NS_SCRIPTABLE NS_IMETHOD FramebufferTexture2D(WebGLenum target, WebGLenum attachment, WebGLenum textarget, nsIWebGLTexture *texture, WebGLint level) { return _to FramebufferTexture2D(target, attachment, textarget, texture, level); } \
  NS_SCRIPTABLE NS_IMETHOD FrontFace(WebGLenum mode) { return _to FrontFace(mode); } \
  NS_SCRIPTABLE NS_IMETHOD GenerateMipmap(WebGLenum target) { return _to GenerateMipmap(target); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveAttrib(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM) { return _to GetActiveAttrib(program, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveUniform(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM) { return _to GetActiveUniform(program, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttachedShaders(nsIWebGLProgram *program, nsIVariant **_retval NS_OUTPARAM) { return _to GetAttachedShaders(program, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttribLocation(nsIWebGLProgram *program, const nsAString & name, WebGLint *_retval NS_OUTPARAM) { return _to GetAttribLocation(program, name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return _to GetParameter(pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return _to GetBufferParameter(target, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetError(WebGLenum *_retval NS_OUTPARAM) { return _to GetError(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFramebufferAttachmentParameter(WebGLenum target, WebGLenum attachment, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return _to GetFramebufferAttachmentParameter(target, attachment, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProgramParameter(nsIWebGLProgram *program, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return _to GetProgramParameter(program, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProgramInfoLog(nsIWebGLProgram *program, nsAString & _retval NS_OUTPARAM) { return _to GetProgramInfoLog(program, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRenderbufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return _to GetRenderbufferParameter(target, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetShaderParameter(nsIWebGLShader *shader, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return _to GetShaderParameter(shader, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetShaderInfoLog(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM) { return _to GetShaderInfoLog(shader, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetShaderSource(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM) { return _to GetShaderSource(shader, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTexParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return _to GetTexParameter(target, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUniform(nsIWebGLProgram *program, nsIWebGLUniformLocation *location, nsIVariant **_retval NS_OUTPARAM) { return _to GetUniform(program, location, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUniformLocation(nsIWebGLProgram *program, const nsAString & name, nsIWebGLUniformLocation **_retval NS_OUTPARAM) { return _to GetUniformLocation(program, name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetVertexAttrib(WebGLuint index, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return _to GetVertexAttrib(index, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetVertexAttribOffset(WebGLuint index, WebGLenum pname, WebGLuint *_retval NS_OUTPARAM) { return _to GetVertexAttribOffset(index, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Hint(WebGLenum target, WebGLenum mode) { return _to Hint(target, mode); } \
  NS_SCRIPTABLE NS_IMETHOD IsBuffer(nsIWebGLBuffer *buffer, WebGLboolean *_retval NS_OUTPARAM) { return _to IsBuffer(buffer, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsFramebuffer(nsIWebGLFramebuffer *framebuffer, WebGLboolean *_retval NS_OUTPARAM) { return _to IsFramebuffer(framebuffer, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsProgram(nsIWebGLProgram *program, WebGLboolean *_retval NS_OUTPARAM) { return _to IsProgram(program, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsRenderbuffer(nsIWebGLRenderbuffer *renderbuffer, WebGLboolean *_retval NS_OUTPARAM) { return _to IsRenderbuffer(renderbuffer, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsShader(nsIWebGLShader *shader, WebGLboolean *_retval NS_OUTPARAM) { return _to IsShader(shader, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsTexture(nsIWebGLTexture *texture, WebGLboolean *_retval NS_OUTPARAM) { return _to IsTexture(texture, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEnabled(WebGLenum cap, WebGLboolean *_retval NS_OUTPARAM) { return _to IsEnabled(cap, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LineWidth(WebGLfloat width) { return _to LineWidth(width); } \
  NS_SCRIPTABLE NS_IMETHOD LinkProgram(nsIWebGLProgram *program) { return _to LinkProgram(program); } \
  NS_SCRIPTABLE NS_IMETHOD PixelStorei(WebGLenum pname, WebGLint param) { return _to PixelStorei(pname, param); } \
  NS_SCRIPTABLE NS_IMETHOD PolygonOffset(WebGLfloat factor, WebGLfloat units) { return _to PolygonOffset(factor, units); } \
  NS_SCRIPTABLE NS_IMETHOD ReadPixels(PRInt32 dummy) { return _to ReadPixels(dummy); } \
  NS_IMETHOD ReadPixels_array(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return _to ReadPixels_array(x, y, width, height, format, type, pixels); } \
  NS_IMETHOD ReadPixels_buf(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) { return _to ReadPixels_buf(x, y, width, height, format, type, pixels); } \
  NS_SCRIPTABLE NS_IMETHOD RenderbufferStorage(WebGLenum target, WebGLenum internalformat, WebGLsizei width, WebGLsizei height) { return _to RenderbufferStorage(target, internalformat, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD SampleCoverage(WebGLclampf value, WebGLboolean invert) { return _to SampleCoverage(value, invert); } \
  NS_SCRIPTABLE NS_IMETHOD Scissor(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) { return _to Scissor(x, y, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD ShaderSource(nsIWebGLShader *shader, const nsAString & source) { return _to ShaderSource(shader, source); } \
  NS_SCRIPTABLE NS_IMETHOD StencilFunc(WebGLenum func, WebGLint ref, WebGLuint mask) { return _to StencilFunc(func, ref, mask); } \
  NS_SCRIPTABLE NS_IMETHOD StencilFuncSeparate(WebGLenum face, WebGLenum func, WebGLint ref, WebGLuint mask) { return _to StencilFuncSeparate(face, func, ref, mask); } \
  NS_SCRIPTABLE NS_IMETHOD StencilMask(WebGLuint mask) { return _to StencilMask(mask); } \
  NS_SCRIPTABLE NS_IMETHOD StencilMaskSeparate(WebGLenum face, WebGLuint mask) { return _to StencilMaskSeparate(face, mask); } \
  NS_SCRIPTABLE NS_IMETHOD StencilOp(WebGLenum fail, WebGLenum zfail, WebGLenum zpass) { return _to StencilOp(fail, zfail, zpass); } \
  NS_SCRIPTABLE NS_IMETHOD StencilOpSeparate(WebGLenum face, WebGLenum fail, WebGLenum zfail, WebGLenum zpass) { return _to StencilOpSeparate(face, fail, zfail, zpass); } \
  NS_SCRIPTABLE NS_IMETHOD TexImage2D(PRInt32 dummy) { return _to TexImage2D(dummy); } \
  NS_IMETHOD TexImage2D_buf(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) { return _to TexImage2D_buf(target, level, internalformat, width, height, border, format, type, pixels); } \
  NS_IMETHOD TexImage2D_array(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return _to TexImage2D_array(target, level, internalformat, width, height, border, format, type, pixels); } \
  NS_IMETHOD TexImage2D_imageData(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return _to TexImage2D_imageData(target, level, internalformat, width, height, border, format, type, pixels); } \
  NS_IMETHOD TexImage2D_dom(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLenum format, WebGLenum type, nsIDOMElement *element) { return _to TexImage2D_dom(target, level, internalformat, format, type, element); } \
  NS_SCRIPTABLE NS_IMETHOD TexSubImage2D(PRInt32 dummy) { return _to TexSubImage2D(dummy); } \
  NS_IMETHOD TexSubImage2D_buf(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) { return _to TexSubImage2D_buf(target, level, xoffset, yoffset, width, height, format, type, pixels); } \
  NS_IMETHOD TexSubImage2D_array(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return _to TexSubImage2D_array(target, level, xoffset, yoffset, width, height, format, type, pixels); } \
  NS_IMETHOD TexSubImage2D_imageData(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return _to TexSubImage2D_imageData(target, level, xoffset, yoffset, width, height, format, type, pixels); } \
  NS_IMETHOD TexSubImage2D_dom(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLenum format, WebGLenum type, nsIDOMElement *element) { return _to TexSubImage2D_dom(target, level, xoffset, yoffset, format, type, element); } \
  NS_SCRIPTABLE NS_IMETHOD TexParameterf(WebGLenum target, WebGLenum pname, WebGLfloat param) { return _to TexParameterf(target, pname, param); } \
  NS_SCRIPTABLE NS_IMETHOD TexParameteri(WebGLenum target, WebGLenum pname, WebGLint param) { return _to TexParameteri(target, pname, param); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform1f(nsIWebGLUniformLocation *location, WebGLfloat x) { return _to Uniform1f(location, x); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform1i(nsIWebGLUniformLocation *location, WebGLint x) { return _to Uniform1i(location, x); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform2f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y) { return _to Uniform2f(location, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform2i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y) { return _to Uniform2i(location, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform3f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z) { return _to Uniform3f(location, x, y, z); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform3i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z) { return _to Uniform3i(location, x, y, z); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform4f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w) { return _to Uniform4f(location, x, y, z, w); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform4i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z, WebGLint w) { return _to Uniform4i(location, x, y, z, w); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform1fv(PRInt32 dummy) { return _to Uniform1fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform1iv(PRInt32 dummy) { return _to Uniform1iv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform2fv(PRInt32 dummy) { return _to Uniform2fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform2iv(PRInt32 dummy) { return _to Uniform2iv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform3fv(PRInt32 dummy) { return _to Uniform3fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform3iv(PRInt32 dummy) { return _to Uniform3iv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform4fv(PRInt32 dummy) { return _to Uniform4fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform4iv(PRInt32 dummy) { return _to Uniform4iv(dummy); } \
  NS_IMETHOD Uniform1fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return _to Uniform1fv_array(location, v); } \
  NS_IMETHOD Uniform1iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return _to Uniform1iv_array(location, v); } \
  NS_IMETHOD Uniform2fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return _to Uniform2fv_array(location, v); } \
  NS_IMETHOD Uniform2iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return _to Uniform2iv_array(location, v); } \
  NS_IMETHOD Uniform3fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return _to Uniform3fv_array(location, v); } \
  NS_IMETHOD Uniform3iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return _to Uniform3iv_array(location, v); } \
  NS_IMETHOD Uniform4fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return _to Uniform4fv_array(location, v); } \
  NS_IMETHOD Uniform4iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return _to Uniform4iv_array(location, v); } \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix2fv(PRInt32 dummy) { return _to UniformMatrix2fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix3fv(PRInt32 dummy) { return _to UniformMatrix3fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix4fv(PRInt32 dummy) { return _to UniformMatrix4fv(dummy); } \
  NS_IMETHOD UniformMatrix2fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) { return _to UniformMatrix2fv_array(location, transpose, value); } \
  NS_IMETHOD UniformMatrix3fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) { return _to UniformMatrix3fv_array(location, transpose, value); } \
  NS_IMETHOD UniformMatrix4fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) { return _to UniformMatrix4fv_array(location, transpose, value); } \
  NS_SCRIPTABLE NS_IMETHOD UseProgram(nsIWebGLProgram *program) { return _to UseProgram(program); } \
  NS_SCRIPTABLE NS_IMETHOD ValidateProgram(nsIWebGLProgram *program) { return _to ValidateProgram(program); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib1f(WebGLuint indx, WebGLfloat x) { return _to VertexAttrib1f(indx, x); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib2f(WebGLuint indx, WebGLfloat x, WebGLfloat y) { return _to VertexAttrib2f(indx, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib3f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z) { return _to VertexAttrib3f(indx, x, y, z); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib4f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w) { return _to VertexAttrib4f(indx, x, y, z, w); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib1fv(PRInt32 dummy) { return _to VertexAttrib1fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib2fv(PRInt32 dummy) { return _to VertexAttrib2fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib3fv(PRInt32 dummy) { return _to VertexAttrib3fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib4fv(PRInt32 dummy) { return _to VertexAttrib4fv(dummy); } \
  NS_IMETHOD VertexAttrib1fv_array(WebGLuint indx, js::TypedArray *values) { return _to VertexAttrib1fv_array(indx, values); } \
  NS_IMETHOD VertexAttrib2fv_array(WebGLuint indx, js::TypedArray *values) { return _to VertexAttrib2fv_array(indx, values); } \
  NS_IMETHOD VertexAttrib3fv_array(WebGLuint indx, js::TypedArray *values) { return _to VertexAttrib3fv_array(indx, values); } \
  NS_IMETHOD VertexAttrib4fv_array(WebGLuint indx, js::TypedArray *values) { return _to VertexAttrib4fv_array(indx, values); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttribPointer(WebGLuint idx, WebGLint size, WebGLenum type, WebGLboolean normalized, WebGLsizei stride, WebGLsizeiptr offset) { return _to VertexAttribPointer(idx, size, type, normalized, stride, offset); } \
  NS_SCRIPTABLE NS_IMETHOD Viewport(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) { return _to Viewport(x, y, width, height); } \
  NS_IMETHOD MozGetUnderlyingParamString(WebGLenum pname, nsAString & _retval NS_OUTPARAM) { return _to MozGetUnderlyingParamString(pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetExtension(const nsAString & name, nsISupports **_retval NS_OUTPARAM) { return _to GetExtension(name, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWEBGLRENDERINGCONTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCanvas(nsIDOMHTMLCanvasElement **aCanvas) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanvas(aCanvas); } \
  NS_SCRIPTABLE NS_IMETHOD GetContextAttributes(jsval *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextAttributes(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ActiveTexture(WebGLenum texture) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActiveTexture(texture); } \
  NS_SCRIPTABLE NS_IMETHOD AttachShader(nsIWebGLProgram *program, nsIWebGLShader *shader) { return !_to ? NS_ERROR_NULL_POINTER : _to->AttachShader(program, shader); } \
  NS_SCRIPTABLE NS_IMETHOD BindAttribLocation(nsIWebGLProgram *program, WebGLuint index, const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindAttribLocation(program, index, name); } \
  NS_SCRIPTABLE NS_IMETHOD BindBuffer(WebGLenum target, nsIWebGLBuffer *buffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindBuffer(target, buffer); } \
  NS_SCRIPTABLE NS_IMETHOD BindFramebuffer(WebGLenum target, nsIWebGLFramebuffer *framebuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindFramebuffer(target, framebuffer); } \
  NS_SCRIPTABLE NS_IMETHOD BindRenderbuffer(WebGLenum target, nsIWebGLRenderbuffer *renderbuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindRenderbuffer(target, renderbuffer); } \
  NS_SCRIPTABLE NS_IMETHOD BindTexture(WebGLenum target, nsIWebGLTexture *texture) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindTexture(target, texture); } \
  NS_SCRIPTABLE NS_IMETHOD BlendColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->BlendColor(red, green, blue, alpha); } \
  NS_SCRIPTABLE NS_IMETHOD BlendEquation(WebGLenum mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->BlendEquation(mode); } \
  NS_SCRIPTABLE NS_IMETHOD BlendEquationSeparate(WebGLenum modeRGB, WebGLenum modeAlpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->BlendEquationSeparate(modeRGB, modeAlpha); } \
  NS_SCRIPTABLE NS_IMETHOD BlendFunc(WebGLenum sfactor, WebGLenum dfactor) { return !_to ? NS_ERROR_NULL_POINTER : _to->BlendFunc(sfactor, dfactor); } \
  NS_SCRIPTABLE NS_IMETHOD BlendFuncSeparate(WebGLenum srcRGB, WebGLenum dstRGB, WebGLenum srcAlpha, WebGLenum dstAlpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->BlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha); } \
  NS_SCRIPTABLE NS_IMETHOD BufferData(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferData(dummy); } \
  NS_IMETHOD BufferData_size(WebGLenum target, WebGLsizei size, WebGLenum usage) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferData_size(target, size, usage); } \
  NS_IMETHOD BufferData_buf(WebGLenum target, js::ArrayBuffer *data, WebGLenum usage) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferData_buf(target, data, usage); } \
  NS_IMETHOD BufferData_array(WebGLenum target, js::TypedArray *data, WebGLenum usage) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferData_array(target, data, usage); } \
  NS_IMETHOD BufferData_null(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferData_null(); } \
  NS_SCRIPTABLE NS_IMETHOD BufferSubData(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferSubData(dummy); } \
  NS_IMETHOD BufferSubData_buf(WebGLenum target, PRInt32 offset, js::ArrayBuffer *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferSubData_buf(target, offset, data); } \
  NS_IMETHOD BufferSubData_array(WebGLenum target, PRInt32 offset, js::TypedArray *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferSubData_array(target, offset, data); } \
  NS_IMETHOD BufferSubData_null(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BufferSubData_null(); } \
  NS_SCRIPTABLE NS_IMETHOD CheckFramebufferStatus(WebGLenum target, WebGLenum *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckFramebufferStatus(target, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(WebGLbitfield mask) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(mask); } \
  NS_SCRIPTABLE NS_IMETHOD ClearColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearColor(red, green, blue, alpha); } \
  NS_SCRIPTABLE NS_IMETHOD ClearDepth(WebGLclampf depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearDepth(depth); } \
  NS_SCRIPTABLE NS_IMETHOD ClearStencil(WebGLint s) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearStencil(s); } \
  NS_SCRIPTABLE NS_IMETHOD ColorMask(WebGLboolean red, WebGLboolean green, WebGLboolean blue, WebGLboolean alpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->ColorMask(red, green, blue, alpha); } \
  NS_SCRIPTABLE NS_IMETHOD CompileShader(nsIWebGLShader *shader) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompileShader(shader); } \
  NS_SCRIPTABLE NS_IMETHOD CopyTexImage2D(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLint border) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyTexImage2D(target, level, internalformat, x, y, width, height, border); } \
  NS_SCRIPTABLE NS_IMETHOD CopyTexSubImage2D(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD CreateBuffer(nsIWebGLBuffer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateBuffer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateProgram(nsIWebGLProgram **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateProgram(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateFramebuffer(nsIWebGLFramebuffer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFramebuffer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateRenderbuffer(nsIWebGLRenderbuffer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateRenderbuffer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateShader(WebGLenum type, nsIWebGLShader **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateShader(type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTexture(nsIWebGLTexture **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTexture(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CullFace(WebGLenum mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->CullFace(mode); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteBuffer(nsIWebGLBuffer *buffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteBuffer(buffer); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteProgram(nsIWebGLProgram *program) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteProgram(program); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteFramebuffer(nsIWebGLFramebuffer *framebuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteFramebuffer(framebuffer); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteRenderbuffer(nsIWebGLRenderbuffer *renderbuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteRenderbuffer(renderbuffer); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteShader(nsIWebGLShader *shader) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteShader(shader); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTexture(nsIWebGLTexture *texture) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTexture(texture); } \
  NS_SCRIPTABLE NS_IMETHOD DepthFunc(WebGLenum func) { return !_to ? NS_ERROR_NULL_POINTER : _to->DepthFunc(func); } \
  NS_SCRIPTABLE NS_IMETHOD DepthMask(WebGLboolean flag) { return !_to ? NS_ERROR_NULL_POINTER : _to->DepthMask(flag); } \
  NS_SCRIPTABLE NS_IMETHOD DepthRange(WebGLclampf zNear, WebGLclampf zFar) { return !_to ? NS_ERROR_NULL_POINTER : _to->DepthRange(zNear, zFar); } \
  NS_SCRIPTABLE NS_IMETHOD DetachShader(nsIWebGLProgram *program, nsIWebGLShader *shader) { return !_to ? NS_ERROR_NULL_POINTER : _to->DetachShader(program, shader); } \
  NS_SCRIPTABLE NS_IMETHOD Disable(WebGLenum cap) { return !_to ? NS_ERROR_NULL_POINTER : _to->Disable(cap); } \
  NS_SCRIPTABLE NS_IMETHOD DisableVertexAttribArray(WebGLuint index) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableVertexAttribArray(index); } \
  NS_SCRIPTABLE NS_IMETHOD DrawArrays(WebGLenum mode, WebGLint first, WebGLsizei count) { return !_to ? NS_ERROR_NULL_POINTER : _to->DrawArrays(mode, first, count); } \
  NS_SCRIPTABLE NS_IMETHOD DrawElements(WebGLenum mode, WebGLsizei count, WebGLenum type, WebGLint offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->DrawElements(mode, count, type, offset); } \
  NS_SCRIPTABLE NS_IMETHOD Enable(WebGLenum cap) { return !_to ? NS_ERROR_NULL_POINTER : _to->Enable(cap); } \
  NS_SCRIPTABLE NS_IMETHOD EnableVertexAttribArray(WebGLuint index) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableVertexAttribArray(index); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(); } \
  NS_SCRIPTABLE NS_IMETHOD FramebufferRenderbuffer(WebGLenum target, WebGLenum attachment, WebGLenum renderbuffertarget, nsIWebGLRenderbuffer *renderbuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->FramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); } \
  NS_SCRIPTABLE NS_IMETHOD FramebufferTexture2D(WebGLenum target, WebGLenum attachment, WebGLenum textarget, nsIWebGLTexture *texture, WebGLint level) { return !_to ? NS_ERROR_NULL_POINTER : _to->FramebufferTexture2D(target, attachment, textarget, texture, level); } \
  NS_SCRIPTABLE NS_IMETHOD FrontFace(WebGLenum mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->FrontFace(mode); } \
  NS_SCRIPTABLE NS_IMETHOD GenerateMipmap(WebGLenum target) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateMipmap(target); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveAttrib(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveAttrib(program, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveUniform(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveUniform(program, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttachedShaders(nsIWebGLProgram *program, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttachedShaders(program, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttribLocation(nsIWebGLProgram *program, const nsAString & name, WebGLint *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttribLocation(program, name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameter(pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBufferParameter(target, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetError(WebGLenum *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFramebufferAttachmentParameter(WebGLenum target, WebGLenum attachment, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFramebufferAttachmentParameter(target, attachment, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProgramParameter(nsIWebGLProgram *program, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProgramParameter(program, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetProgramInfoLog(nsIWebGLProgram *program, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProgramInfoLog(program, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRenderbufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRenderbufferParameter(target, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetShaderParameter(nsIWebGLShader *shader, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShaderParameter(shader, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetShaderInfoLog(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShaderInfoLog(shader, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetShaderSource(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShaderSource(shader, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTexParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTexParameter(target, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUniform(nsIWebGLProgram *program, nsIWebGLUniformLocation *location, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUniform(program, location, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUniformLocation(nsIWebGLProgram *program, const nsAString & name, nsIWebGLUniformLocation **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUniformLocation(program, name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetVertexAttrib(WebGLuint index, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVertexAttrib(index, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetVertexAttribOffset(WebGLuint index, WebGLenum pname, WebGLuint *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVertexAttribOffset(index, pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Hint(WebGLenum target, WebGLenum mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Hint(target, mode); } \
  NS_SCRIPTABLE NS_IMETHOD IsBuffer(nsIWebGLBuffer *buffer, WebGLboolean *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBuffer(buffer, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsFramebuffer(nsIWebGLFramebuffer *framebuffer, WebGLboolean *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFramebuffer(framebuffer, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsProgram(nsIWebGLProgram *program, WebGLboolean *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsProgram(program, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsRenderbuffer(nsIWebGLRenderbuffer *renderbuffer, WebGLboolean *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsRenderbuffer(renderbuffer, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsShader(nsIWebGLShader *shader, WebGLboolean *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsShader(shader, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsTexture(nsIWebGLTexture *texture, WebGLboolean *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsTexture(texture, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEnabled(WebGLenum cap, WebGLboolean *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEnabled(cap, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LineWidth(WebGLfloat width) { return !_to ? NS_ERROR_NULL_POINTER : _to->LineWidth(width); } \
  NS_SCRIPTABLE NS_IMETHOD LinkProgram(nsIWebGLProgram *program) { return !_to ? NS_ERROR_NULL_POINTER : _to->LinkProgram(program); } \
  NS_SCRIPTABLE NS_IMETHOD PixelStorei(WebGLenum pname, WebGLint param) { return !_to ? NS_ERROR_NULL_POINTER : _to->PixelStorei(pname, param); } \
  NS_SCRIPTABLE NS_IMETHOD PolygonOffset(WebGLfloat factor, WebGLfloat units) { return !_to ? NS_ERROR_NULL_POINTER : _to->PolygonOffset(factor, units); } \
  NS_SCRIPTABLE NS_IMETHOD ReadPixels(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadPixels(dummy); } \
  NS_IMETHOD ReadPixels_array(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadPixels_array(x, y, width, height, format, type, pixels); } \
  NS_IMETHOD ReadPixels_buf(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadPixels_buf(x, y, width, height, format, type, pixels); } \
  NS_SCRIPTABLE NS_IMETHOD RenderbufferStorage(WebGLenum target, WebGLenum internalformat, WebGLsizei width, WebGLsizei height) { return !_to ? NS_ERROR_NULL_POINTER : _to->RenderbufferStorage(target, internalformat, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD SampleCoverage(WebGLclampf value, WebGLboolean invert) { return !_to ? NS_ERROR_NULL_POINTER : _to->SampleCoverage(value, invert); } \
  NS_SCRIPTABLE NS_IMETHOD Scissor(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) { return !_to ? NS_ERROR_NULL_POINTER : _to->Scissor(x, y, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD ShaderSource(nsIWebGLShader *shader, const nsAString & source) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShaderSource(shader, source); } \
  NS_SCRIPTABLE NS_IMETHOD StencilFunc(WebGLenum func, WebGLint ref, WebGLuint mask) { return !_to ? NS_ERROR_NULL_POINTER : _to->StencilFunc(func, ref, mask); } \
  NS_SCRIPTABLE NS_IMETHOD StencilFuncSeparate(WebGLenum face, WebGLenum func, WebGLint ref, WebGLuint mask) { return !_to ? NS_ERROR_NULL_POINTER : _to->StencilFuncSeparate(face, func, ref, mask); } \
  NS_SCRIPTABLE NS_IMETHOD StencilMask(WebGLuint mask) { return !_to ? NS_ERROR_NULL_POINTER : _to->StencilMask(mask); } \
  NS_SCRIPTABLE NS_IMETHOD StencilMaskSeparate(WebGLenum face, WebGLuint mask) { return !_to ? NS_ERROR_NULL_POINTER : _to->StencilMaskSeparate(face, mask); } \
  NS_SCRIPTABLE NS_IMETHOD StencilOp(WebGLenum fail, WebGLenum zfail, WebGLenum zpass) { return !_to ? NS_ERROR_NULL_POINTER : _to->StencilOp(fail, zfail, zpass); } \
  NS_SCRIPTABLE NS_IMETHOD StencilOpSeparate(WebGLenum face, WebGLenum fail, WebGLenum zfail, WebGLenum zpass) { return !_to ? NS_ERROR_NULL_POINTER : _to->StencilOpSeparate(face, fail, zfail, zpass); } \
  NS_SCRIPTABLE NS_IMETHOD TexImage2D(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexImage2D(dummy); } \
  NS_IMETHOD TexImage2D_buf(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexImage2D_buf(target, level, internalformat, width, height, border, format, type, pixels); } \
  NS_IMETHOD TexImage2D_array(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexImage2D_array(target, level, internalformat, width, height, border, format, type, pixels); } \
  NS_IMETHOD TexImage2D_imageData(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexImage2D_imageData(target, level, internalformat, width, height, border, format, type, pixels); } \
  NS_IMETHOD TexImage2D_dom(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLenum format, WebGLenum type, nsIDOMElement *element) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexImage2D_dom(target, level, internalformat, format, type, element); } \
  NS_SCRIPTABLE NS_IMETHOD TexSubImage2D(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexSubImage2D(dummy); } \
  NS_IMETHOD TexSubImage2D_buf(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexSubImage2D_buf(target, level, xoffset, yoffset, width, height, format, type, pixels); } \
  NS_IMETHOD TexSubImage2D_array(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexSubImage2D_array(target, level, xoffset, yoffset, width, height, format, type, pixels); } \
  NS_IMETHOD TexSubImage2D_imageData(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexSubImage2D_imageData(target, level, xoffset, yoffset, width, height, format, type, pixels); } \
  NS_IMETHOD TexSubImage2D_dom(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLenum format, WebGLenum type, nsIDOMElement *element) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexSubImage2D_dom(target, level, xoffset, yoffset, format, type, element); } \
  NS_SCRIPTABLE NS_IMETHOD TexParameterf(WebGLenum target, WebGLenum pname, WebGLfloat param) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexParameterf(target, pname, param); } \
  NS_SCRIPTABLE NS_IMETHOD TexParameteri(WebGLenum target, WebGLenum pname, WebGLint param) { return !_to ? NS_ERROR_NULL_POINTER : _to->TexParameteri(target, pname, param); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform1f(nsIWebGLUniformLocation *location, WebGLfloat x) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform1f(location, x); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform1i(nsIWebGLUniformLocation *location, WebGLint x) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform1i(location, x); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform2f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform2f(location, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform2i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform2i(location, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform3f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform3f(location, x, y, z); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform3i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform3i(location, x, y, z); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform4f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform4f(location, x, y, z, w); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform4i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z, WebGLint w) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform4i(location, x, y, z, w); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform1fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform1fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform1iv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform1iv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform2fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform2fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform2iv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform2iv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform3fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform3fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform3iv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform3iv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform4fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform4fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD Uniform4iv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform4iv(dummy); } \
  NS_IMETHOD Uniform1fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform1fv_array(location, v); } \
  NS_IMETHOD Uniform1iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform1iv_array(location, v); } \
  NS_IMETHOD Uniform2fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform2fv_array(location, v); } \
  NS_IMETHOD Uniform2iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform2iv_array(location, v); } \
  NS_IMETHOD Uniform3fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform3fv_array(location, v); } \
  NS_IMETHOD Uniform3iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform3iv_array(location, v); } \
  NS_IMETHOD Uniform4fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform4fv_array(location, v); } \
  NS_IMETHOD Uniform4iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uniform4iv_array(location, v); } \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix2fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->UniformMatrix2fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix3fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->UniformMatrix3fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD UniformMatrix4fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->UniformMatrix4fv(dummy); } \
  NS_IMETHOD UniformMatrix2fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->UniformMatrix2fv_array(location, transpose, value); } \
  NS_IMETHOD UniformMatrix3fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->UniformMatrix3fv_array(location, transpose, value); } \
  NS_IMETHOD UniformMatrix4fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->UniformMatrix4fv_array(location, transpose, value); } \
  NS_SCRIPTABLE NS_IMETHOD UseProgram(nsIWebGLProgram *program) { return !_to ? NS_ERROR_NULL_POINTER : _to->UseProgram(program); } \
  NS_SCRIPTABLE NS_IMETHOD ValidateProgram(nsIWebGLProgram *program) { return !_to ? NS_ERROR_NULL_POINTER : _to->ValidateProgram(program); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib1f(WebGLuint indx, WebGLfloat x) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib1f(indx, x); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib2f(WebGLuint indx, WebGLfloat x, WebGLfloat y) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib2f(indx, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib3f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib3f(indx, x, y, z); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib4f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib4f(indx, x, y, z, w); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib1fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib1fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib2fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib2fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib3fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib3fv(dummy); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttrib4fv(PRInt32 dummy) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib4fv(dummy); } \
  NS_IMETHOD VertexAttrib1fv_array(WebGLuint indx, js::TypedArray *values) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib1fv_array(indx, values); } \
  NS_IMETHOD VertexAttrib2fv_array(WebGLuint indx, js::TypedArray *values) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib2fv_array(indx, values); } \
  NS_IMETHOD VertexAttrib3fv_array(WebGLuint indx, js::TypedArray *values) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib3fv_array(indx, values); } \
  NS_IMETHOD VertexAttrib4fv_array(WebGLuint indx, js::TypedArray *values) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttrib4fv_array(indx, values); } \
  NS_SCRIPTABLE NS_IMETHOD VertexAttribPointer(WebGLuint idx, WebGLint size, WebGLenum type, WebGLboolean normalized, WebGLsizei stride, WebGLsizeiptr offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->VertexAttribPointer(idx, size, type, normalized, stride, offset); } \
  NS_SCRIPTABLE NS_IMETHOD Viewport(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height) { return !_to ? NS_ERROR_NULL_POINTER : _to->Viewport(x, y, width, height); } \
  NS_IMETHOD MozGetUnderlyingParamString(WebGLenum pname, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetUnderlyingParamString(pname, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetExtension(const nsAString & name, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtension(name, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWebGLRenderingContext : public nsIDOMWebGLRenderingContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWEBGLRENDERINGCONTEXT

  nsDOMWebGLRenderingContext();

private:
  ~nsDOMWebGLRenderingContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWebGLRenderingContext, nsIDOMWebGLRenderingContext)

nsDOMWebGLRenderingContext::nsDOMWebGLRenderingContext()
{
  /* member initializers and constructor code */
}

nsDOMWebGLRenderingContext::~nsDOMWebGLRenderingContext()
{
  /* destructor code */
}

/* readonly attribute nsIDOMHTMLCanvasElement canvas; */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetCanvas(nsIDOMHTMLCanvasElement **aCanvas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getContextAttributes (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetContextAttributes(jsval *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activeTexture (in WebGLenum texture); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ActiveTexture(WebGLenum texture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void attachShader ([optional] in nsIWebGLProgram program, [optional] in nsIWebGLShader shader); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::AttachShader(nsIWebGLProgram *program, nsIWebGLShader *shader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindAttribLocation (in nsIWebGLProgram program, in WebGLuint index, in DOMString name); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BindAttribLocation(nsIWebGLProgram *program, WebGLuint index, const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindBuffer (in WebGLenum target, in nsIWebGLBuffer buffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BindBuffer(WebGLenum target, nsIWebGLBuffer *buffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindFramebuffer (in WebGLenum target, in nsIWebGLFramebuffer framebuffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BindFramebuffer(WebGLenum target, nsIWebGLFramebuffer *framebuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindRenderbuffer (in WebGLenum target, in nsIWebGLRenderbuffer renderbuffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BindRenderbuffer(WebGLenum target, nsIWebGLRenderbuffer *renderbuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindTexture (in WebGLenum target, in nsIWebGLTexture texture); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BindTexture(WebGLenum target, nsIWebGLTexture *texture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blendColor (in WebGLclampf red, in WebGLclampf green, in WebGLclampf blue, in WebGLclampf alpha); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BlendColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blendEquation (in WebGLenum mode); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BlendEquation(WebGLenum mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blendEquationSeparate (in WebGLenum modeRGB, in WebGLenum modeAlpha); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BlendEquationSeparate(WebGLenum modeRGB, WebGLenum modeAlpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blendFunc (in WebGLenum sfactor, in WebGLenum dfactor); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BlendFunc(WebGLenum sfactor, WebGLenum dfactor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blendFuncSeparate (in WebGLenum srcRGB, in WebGLenum dstRGB, in WebGLenum srcAlpha, in WebGLenum dstAlpha); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BlendFuncSeparate(WebGLenum srcRGB, WebGLenum dstRGB, WebGLenum srcAlpha, WebGLenum dstAlpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bufferData ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferData(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void bufferData_size (in WebGLenum target, in WebGLsizei size, in WebGLenum usage); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferData_size(WebGLenum target, WebGLsizei size, WebGLenum usage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void bufferData_buf (in WebGLenum target, in WebGLArrayBufferPtr data, in WebGLenum usage); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferData_buf(WebGLenum target, js::ArrayBuffer *data, WebGLenum usage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void bufferData_array (in WebGLenum target, in WebGLArrayPtr data, in WebGLenum usage); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferData_array(WebGLenum target, js::TypedArray *data, WebGLenum usage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void bufferData_null (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferData_null()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bufferSubData ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferSubData(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void bufferSubData_buf (in WebGLenum target, in long offset, in WebGLArrayBufferPtr data); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferSubData_buf(WebGLenum target, PRInt32 offset, js::ArrayBuffer *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void bufferSubData_array (in WebGLenum target, in long offset, in WebGLArrayPtr data); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferSubData_array(WebGLenum target, PRInt32 offset, js::TypedArray *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void bufferSubData_null (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::BufferSubData_null()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLenum checkFramebufferStatus (in WebGLenum target); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CheckFramebufferStatus(WebGLenum target, WebGLenum *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (in WebGLbitfield mask); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Clear(WebGLbitfield mask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearColor (in WebGLclampf red, in WebGLclampf green, in WebGLclampf blue, in WebGLclampf alpha); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ClearColor(WebGLclampf red, WebGLclampf green, WebGLclampf blue, WebGLclampf alpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearDepth (in WebGLclampf depth); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ClearDepth(WebGLclampf depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearStencil (in WebGLint s); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ClearStencil(WebGLint s)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void colorMask (in WebGLboolean red, in WebGLboolean green, in WebGLboolean blue, in WebGLboolean alpha); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ColorMask(WebGLboolean red, WebGLboolean green, WebGLboolean blue, WebGLboolean alpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void compileShader ([optional] in nsIWebGLShader shader); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CompileShader(nsIWebGLShader *shader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyTexImage2D (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height, in WebGLint border); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CopyTexImage2D(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLint border)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyTexSubImage2D (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CopyTexSubImage2D(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLBuffer createBuffer (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CreateBuffer(nsIWebGLBuffer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLProgram createProgram (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CreateProgram(nsIWebGLProgram **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLFramebuffer createFramebuffer (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CreateFramebuffer(nsIWebGLFramebuffer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLRenderbuffer createRenderbuffer (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CreateRenderbuffer(nsIWebGLRenderbuffer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLShader createShader (in WebGLenum type); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CreateShader(WebGLenum type, nsIWebGLShader **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLTexture createTexture (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CreateTexture(nsIWebGLTexture **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cullFace (in WebGLenum mode); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::CullFace(WebGLenum mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteBuffer (in nsIWebGLBuffer buffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DeleteBuffer(nsIWebGLBuffer *buffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteProgram (in nsIWebGLProgram program); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DeleteProgram(nsIWebGLProgram *program)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteFramebuffer (in nsIWebGLFramebuffer framebuffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DeleteFramebuffer(nsIWebGLFramebuffer *framebuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteRenderbuffer (in nsIWebGLRenderbuffer renderbuffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DeleteRenderbuffer(nsIWebGLRenderbuffer *renderbuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteShader (in nsIWebGLShader shader); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DeleteShader(nsIWebGLShader *shader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTexture (in nsIWebGLTexture texture); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DeleteTexture(nsIWebGLTexture *texture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void depthFunc (in WebGLenum func); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DepthFunc(WebGLenum func)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void depthMask (in WebGLboolean flag); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DepthMask(WebGLboolean flag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void depthRange (in WebGLclampf zNear, in WebGLclampf zFar); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DepthRange(WebGLclampf zNear, WebGLclampf zFar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void detachShader (in nsIWebGLProgram program, in nsIWebGLShader shader); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DetachShader(nsIWebGLProgram *program, nsIWebGLShader *shader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disable (in WebGLenum cap); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Disable(WebGLenum cap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableVertexAttribArray (in WebGLuint index); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DisableVertexAttribArray(WebGLuint index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void drawArrays (in WebGLenum mode, in WebGLint first, in WebGLsizei count); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DrawArrays(WebGLenum mode, WebGLint first, WebGLsizei count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void drawElements (in WebGLenum mode, in WebGLsizei count, in WebGLenum type, in WebGLint offset); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::DrawElements(WebGLenum mode, WebGLsizei count, WebGLenum type, WebGLint offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enable (in WebGLenum cap); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Enable(WebGLenum cap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableVertexAttribArray (in WebGLuint index); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::EnableVertexAttribArray(WebGLuint index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finish (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Finish()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flush (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Flush()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void framebufferRenderbuffer (in WebGLenum target, in WebGLenum attachment, in WebGLenum renderbuffertarget, in nsIWebGLRenderbuffer renderbuffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::FramebufferRenderbuffer(WebGLenum target, WebGLenum attachment, WebGLenum renderbuffertarget, nsIWebGLRenderbuffer *renderbuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void framebufferTexture2D (in WebGLenum target, in WebGLenum attachment, in WebGLenum textarget, in nsIWebGLTexture texture, in WebGLint level); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::FramebufferTexture2D(WebGLenum target, WebGLenum attachment, WebGLenum textarget, nsIWebGLTexture *texture, WebGLint level)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void frontFace (in WebGLenum mode); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::FrontFace(WebGLenum mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void generateMipmap (in WebGLenum target); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GenerateMipmap(WebGLenum target)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLActiveInfo getActiveAttrib (in nsIWebGLProgram program, in PRUint32 index); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetActiveAttrib(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLActiveInfo getActiveUniform (in nsIWebGLProgram program, in PRUint32 index); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetActiveUniform(nsIWebGLProgram *program, PRUint32 index, nsIWebGLActiveInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getAttachedShaders (in nsIWebGLProgram program); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetAttachedShaders(nsIWebGLProgram *program, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLint getAttribLocation (in nsIWebGLProgram program, in DOMString name); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetAttribLocation(nsIWebGLProgram *program, const nsAString & name, WebGLint *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getParameter (in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetParameter(WebGLenum pname, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getBufferParameter (in WebGLenum target, in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetBufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLenum getError (); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetError(WebGLenum *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getFramebufferAttachmentParameter (in WebGLenum target, in WebGLenum attachment, in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetFramebufferAttachmentParameter(WebGLenum target, WebGLenum attachment, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getProgramParameter (in nsIWebGLProgram program, in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetProgramParameter(nsIWebGLProgram *program, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getProgramInfoLog (in nsIWebGLProgram program); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetProgramInfoLog(nsIWebGLProgram *program, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getRenderbufferParameter (in WebGLenum target, in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetRenderbufferParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getShaderParameter (in nsIWebGLShader shader, in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetShaderParameter(nsIWebGLShader *shader, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getShaderInfoLog (in nsIWebGLShader shader); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetShaderInfoLog(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getShaderSource (in nsIWebGLShader shader); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetShaderSource(nsIWebGLShader *shader, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getTexParameter (in WebGLenum target, in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetTexParameter(WebGLenum target, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getUniform (in nsIWebGLProgram program, in nsIWebGLUniformLocation location); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetUniform(nsIWebGLProgram *program, nsIWebGLUniformLocation *location, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebGLUniformLocation getUniformLocation (in nsIWebGLProgram program, in DOMString name); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetUniformLocation(nsIWebGLProgram *program, const nsAString & name, nsIWebGLUniformLocation **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getVertexAttrib (in WebGLuint index, in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetVertexAttrib(WebGLuint index, WebGLenum pname, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLuint getVertexAttribOffset (in WebGLuint index, in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetVertexAttribOffset(WebGLuint index, WebGLenum pname, WebGLuint *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hint (in WebGLenum target, in WebGLenum mode); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Hint(WebGLenum target, WebGLenum mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLboolean isBuffer (in nsIWebGLBuffer buffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::IsBuffer(nsIWebGLBuffer *buffer, WebGLboolean *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLboolean isFramebuffer (in nsIWebGLFramebuffer framebuffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::IsFramebuffer(nsIWebGLFramebuffer *framebuffer, WebGLboolean *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLboolean isProgram (in nsIWebGLProgram program); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::IsProgram(nsIWebGLProgram *program, WebGLboolean *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLboolean isRenderbuffer (in nsIWebGLRenderbuffer renderbuffer); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::IsRenderbuffer(nsIWebGLRenderbuffer *renderbuffer, WebGLboolean *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLboolean isShader (in nsIWebGLShader shader); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::IsShader(nsIWebGLShader *shader, WebGLboolean *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLboolean isTexture (in nsIWebGLTexture texture); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::IsTexture(nsIWebGLTexture *texture, WebGLboolean *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* WebGLboolean isEnabled (in WebGLenum cap); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::IsEnabled(WebGLenum cap, WebGLboolean *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lineWidth (in WebGLfloat width); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::LineWidth(WebGLfloat width)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void linkProgram ([optional] in nsIWebGLProgram program); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::LinkProgram(nsIWebGLProgram *program)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pixelStorei (in WebGLenum pname, in WebGLint param); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::PixelStorei(WebGLenum pname, WebGLint param)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void polygonOffset (in WebGLfloat factor, in WebGLfloat units); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::PolygonOffset(WebGLfloat factor, WebGLfloat units)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void readPixels ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ReadPixels(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void readPixels_array (in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ReadPixels_array(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void readPixels_buf (in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayBufferPtr pixels); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ReadPixels_buf(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void renderbufferStorage (in WebGLenum target, in WebGLenum internalformat, in WebGLsizei width, in WebGLsizei height); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::RenderbufferStorage(WebGLenum target, WebGLenum internalformat, WebGLsizei width, WebGLsizei height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sampleCoverage (in WebGLclampf value, in WebGLboolean invert); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::SampleCoverage(WebGLclampf value, WebGLboolean invert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scissor (in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Scissor(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shaderSource ([optional] in nsIWebGLShader shader, [optional] in DOMString source); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ShaderSource(nsIWebGLShader *shader, const nsAString & source)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stencilFunc (in WebGLenum func, in WebGLint ref, in WebGLuint mask); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::StencilFunc(WebGLenum func, WebGLint ref, WebGLuint mask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stencilFuncSeparate (in WebGLenum face, in WebGLenum func, in WebGLint ref, in WebGLuint mask); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::StencilFuncSeparate(WebGLenum face, WebGLenum func, WebGLint ref, WebGLuint mask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stencilMask (in WebGLuint mask); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::StencilMask(WebGLuint mask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stencilMaskSeparate (in WebGLenum face, in WebGLuint mask); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::StencilMaskSeparate(WebGLenum face, WebGLuint mask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stencilOp (in WebGLenum fail, in WebGLenum zfail, in WebGLenum zpass); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::StencilOp(WebGLenum fail, WebGLenum zfail, WebGLenum zpass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stencilOpSeparate (in WebGLenum face, in WebGLenum fail, in WebGLenum zfail, in WebGLenum zpass); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::StencilOpSeparate(WebGLenum face, WebGLenum fail, WebGLenum zfail, WebGLenum zpass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void texImage2D ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexImage2D(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void texImage2D_buf (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLsizei width, in WebGLsizei height, in WebGLint border, in WebGLenum format, in WebGLenum type, in WebGLArrayBufferPtr pixels); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexImage2D_buf(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void texImage2D_array (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLsizei width, in WebGLsizei height, in WebGLint border, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexImage2D_array(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void texImage2D_imageData (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLsizei width, in WebGLsizei height, in WebGLint border, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexImage2D_imageData(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLsizei width, WebGLsizei height, WebGLint border, WebGLenum format, WebGLenum type, js::TypedArray *pixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void texImage2D_dom (in WebGLenum target, in WebGLint level, in WebGLenum internalformat, in WebGLenum format, in WebGLenum type, in nsIDOMElement element); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexImage2D_dom(WebGLenum target, WebGLint level, WebGLenum internalformat, WebGLenum format, WebGLenum type, nsIDOMElement *element)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void texSubImage2D ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexSubImage2D(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void texSubImage2D_buf (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayBufferPtr pixels); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexSubImage2D_buf(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::ArrayBuffer *pixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void texSubImage2D_array (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexSubImage2D_array(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void texSubImage2D_imageData (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLsizei width, in WebGLsizei height, in WebGLenum format, in WebGLenum type, in WebGLArrayPtr pixels); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexSubImage2D_imageData(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLsizei width, WebGLsizei height, WebGLenum format, WebGLenum type, js::TypedArray *pixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void texSubImage2D_dom (in WebGLenum target, in WebGLint level, in WebGLint xoffset, in WebGLint yoffset, in WebGLenum format, in WebGLenum type, in nsIDOMElement element); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexSubImage2D_dom(WebGLenum target, WebGLint level, WebGLint xoffset, WebGLint yoffset, WebGLenum format, WebGLenum type, nsIDOMElement *element)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void texParameterf (in WebGLenum target, in WebGLenum pname, in WebGLfloat param); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexParameterf(WebGLenum target, WebGLenum pname, WebGLfloat param)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void texParameteri (in WebGLenum target, in WebGLenum pname, in WebGLint param); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::TexParameteri(WebGLenum target, WebGLenum pname, WebGLint param)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform1f (in nsIWebGLUniformLocation location, in WebGLfloat x); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform1f(nsIWebGLUniformLocation *location, WebGLfloat x)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform1i (in nsIWebGLUniformLocation location, in WebGLint x); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform1i(nsIWebGLUniformLocation *location, WebGLint x)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform2f (in nsIWebGLUniformLocation location, in WebGLfloat x, in WebGLfloat y); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform2f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform2i (in nsIWebGLUniformLocation location, in WebGLint x, in WebGLint y); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform2i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform3f (in nsIWebGLUniformLocation location, in WebGLfloat x, in WebGLfloat y, in WebGLfloat z); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform3f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform3i (in nsIWebGLUniformLocation location, in WebGLint x, in WebGLint y, in WebGLint z); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform3i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform4f (in nsIWebGLUniformLocation location, in WebGLfloat x, in WebGLfloat y, in WebGLfloat z, in WebGLfloat w); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform4f(nsIWebGLUniformLocation *location, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform4i (in nsIWebGLUniformLocation location, in WebGLint x, in WebGLint y, in WebGLint z, in WebGLint w); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform4i(nsIWebGLUniformLocation *location, WebGLint x, WebGLint y, WebGLint z, WebGLint w)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform1fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform1fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform1iv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform1iv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform2fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform2fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform2iv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform2iv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform3fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform3fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform3iv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform3iv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform4fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform4fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniform4iv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform4iv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniform1fv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform1fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniform1iv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform1iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniform2fv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform2fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniform2iv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform2iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniform3fv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform3fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniform3iv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform3iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniform4fv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform4fv_array(nsIWebGLUniformLocation *location, js::TypedArray *v)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniform4iv_array (in nsIWebGLUniformLocation location, in WebGLArrayPtr v); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Uniform4iv_array(nsIWebGLUniformLocation *location, js::TypedArray *v)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniformMatrix2fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::UniformMatrix2fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniformMatrix3fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::UniformMatrix3fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uniformMatrix4fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::UniformMatrix4fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniformMatrix2fv_array (in nsIWebGLUniformLocation location, in WebGLboolean transpose, in WebGLArrayPtr value); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::UniformMatrix2fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniformMatrix3fv_array (in nsIWebGLUniformLocation location, in WebGLboolean transpose, in WebGLArrayPtr value); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::UniformMatrix3fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void uniformMatrix4fv_array (in nsIWebGLUniformLocation location, in WebGLboolean transpose, in WebGLArrayPtr value); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::UniformMatrix4fv_array(nsIWebGLUniformLocation *location, WebGLboolean transpose, js::TypedArray *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void useProgram (in nsIWebGLProgram program); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::UseProgram(nsIWebGLProgram *program)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void validateProgram (in nsIWebGLProgram program); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::ValidateProgram(nsIWebGLProgram *program)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttrib1f (in WebGLuint indx, in WebGLfloat x); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib1f(WebGLuint indx, WebGLfloat x)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttrib2f (in WebGLuint indx, in WebGLfloat x, in WebGLfloat y); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib2f(WebGLuint indx, WebGLfloat x, WebGLfloat y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttrib3f (in WebGLuint indx, in WebGLfloat x, in WebGLfloat y, in WebGLfloat z); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib3f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttrib4f (in WebGLuint indx, in WebGLfloat x, in WebGLfloat y, in WebGLfloat z, in WebGLfloat w); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib4f(WebGLuint indx, WebGLfloat x, WebGLfloat y, WebGLfloat z, WebGLfloat w)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttrib1fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib1fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttrib2fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib2fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttrib3fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib3fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttrib4fv ([optional] in long dummy); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib4fv(PRInt32 dummy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void vertexAttrib1fv_array (in WebGLuint indx, in WebGLArrayPtr values); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib1fv_array(WebGLuint indx, js::TypedArray *values)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void vertexAttrib2fv_array (in WebGLuint indx, in WebGLArrayPtr values); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib2fv_array(WebGLuint indx, js::TypedArray *values)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void vertexAttrib3fv_array (in WebGLuint indx, in WebGLArrayPtr values); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib3fv_array(WebGLuint indx, js::TypedArray *values)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void vertexAttrib4fv_array (in WebGLuint indx, in WebGLArrayPtr values); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttrib4fv_array(WebGLuint indx, js::TypedArray *values)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void vertexAttribPointer (in WebGLuint idx, in WebGLint size, in WebGLenum type, in WebGLboolean normalized, in WebGLsizei stride, in WebGLsizeiptr offset); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::VertexAttribPointer(WebGLuint idx, WebGLint size, WebGLenum type, WebGLboolean normalized, WebGLsizei stride, WebGLsizeiptr offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void viewport (in WebGLint x, in WebGLint y, in WebGLsizei width, in WebGLsizei height); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::Viewport(WebGLint x, WebGLint y, WebGLsizei width, WebGLsizei height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] DOMString mozGetUnderlyingParamString (in WebGLenum pname); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::MozGetUnderlyingParamString(WebGLenum pname, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getExtension (in DOMString name); */
NS_IMETHODIMP nsDOMWebGLRenderingContext::GetExtension(const nsAString & name, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWebGLRenderingContext_h__ */
