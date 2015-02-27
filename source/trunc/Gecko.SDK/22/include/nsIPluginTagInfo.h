/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/plugins/base/nsIPluginTagInfo.idl
 */

#ifndef __gen_nsIPluginTagInfo_h__
#define __gen_nsIPluginTagInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
enum nsPluginTagType {
  nsPluginTagType_Unknown,
  nsPluginTagType_Embed,
  nsPluginTagType_Object,
  nsPluginTagType_Applet
};
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIPluginTagInfo */
#define NS_IPLUGINTAGINFO_IID_STR "759a955e-c590-419a-b5f3-e54bb67e24b8"

#define NS_IPLUGINTAGINFO_IID \
  {0x759a955e, 0xc590, 0x419a, \
    { 0xb5, 0xf3, 0xe5, 0x4b, 0xb6, 0x7e, 0x24, 0xb8 }}

class NS_NO_VTABLE nsIPluginTagInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINTAGINFO_IID)

  /* void getAttributes (in PRUint16Ref aCount, in constCharStarConstStar aNames, in constCharStarConstStar aValues); */
  NS_IMETHOD GetAttributes(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues) = 0;

  /* void getAttribute (in string aName, out constCharPtr aResult); */
  NS_IMETHOD GetAttribute(const char * aName, const char **aResult) = 0;

  /* readonly attribute nsPluginTagType tagType; */
  NS_IMETHOD GetTagType(nsPluginTagType *aTagType) = 0;

  /* void getParameters (in PRUint16Ref aCount, in constCharStarConstStar aNames, in constCharStarConstStar aValues); */
  NS_IMETHOD GetParameters(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues) = 0;

  /* void getParameter (in string aName, out constCharPtr aResult); */
  NS_IMETHOD GetParameter(const char * aName, const char **aResult) = 0;

  /* void getDocumentBase (out constCharPtr aDocumentBase); */
  NS_IMETHOD GetDocumentBase(const char **aDocumentBase) = 0;

  /* void getDocumentEncoding (out constCharPtr aDocumentEncoding); */
  NS_IMETHOD GetDocumentEncoding(const char **aDocumentEncoding) = 0;

  /* void getAlignment (out constCharPtr aElignment); */
  NS_IMETHOD GetAlignment(const char **aElignment) = 0;

  /* readonly attribute unsigned long width; */
  NS_IMETHOD GetWidth(uint32_t *aWidth) = 0;

  /* readonly attribute unsigned long height; */
  NS_IMETHOD GetHeight(uint32_t *aHeight) = 0;

  /* readonly attribute unsigned long borderVertSpace; */
  NS_IMETHOD GetBorderVertSpace(uint32_t *aBorderVertSpace) = 0;

  /* readonly attribute unsigned long borderHorizSpace; */
  NS_IMETHOD GetBorderHorizSpace(uint32_t *aBorderHorizSpace) = 0;

  /* readonly attribute nsIDOMElement DOMElement; */
  NS_IMETHOD GetDOMElement(nsIDOMElement * *aDOMElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginTagInfo, NS_IPLUGINTAGINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINTAGINFO \
  NS_IMETHOD GetAttributes(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues); \
  NS_IMETHOD GetAttribute(const char * aName, const char **aResult); \
  NS_IMETHOD GetTagType(nsPluginTagType *aTagType); \
  NS_IMETHOD GetParameters(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues); \
  NS_IMETHOD GetParameter(const char * aName, const char **aResult); \
  NS_IMETHOD GetDocumentBase(const char **aDocumentBase); \
  NS_IMETHOD GetDocumentEncoding(const char **aDocumentEncoding); \
  NS_IMETHOD GetAlignment(const char **aElignment); \
  NS_IMETHOD GetWidth(uint32_t *aWidth); \
  NS_IMETHOD GetHeight(uint32_t *aHeight); \
  NS_IMETHOD GetBorderVertSpace(uint32_t *aBorderVertSpace); \
  NS_IMETHOD GetBorderHorizSpace(uint32_t *aBorderHorizSpace); \
  NS_IMETHOD GetDOMElement(nsIDOMElement * *aDOMElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINTAGINFO(_to) \
  NS_IMETHOD GetAttributes(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues) { return _to GetAttributes(aCount, aNames, aValues); } \
  NS_IMETHOD GetAttribute(const char * aName, const char **aResult) { return _to GetAttribute(aName, aResult); } \
  NS_IMETHOD GetTagType(nsPluginTagType *aTagType) { return _to GetTagType(aTagType); } \
  NS_IMETHOD GetParameters(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues) { return _to GetParameters(aCount, aNames, aValues); } \
  NS_IMETHOD GetParameter(const char * aName, const char **aResult) { return _to GetParameter(aName, aResult); } \
  NS_IMETHOD GetDocumentBase(const char **aDocumentBase) { return _to GetDocumentBase(aDocumentBase); } \
  NS_IMETHOD GetDocumentEncoding(const char **aDocumentEncoding) { return _to GetDocumentEncoding(aDocumentEncoding); } \
  NS_IMETHOD GetAlignment(const char **aElignment) { return _to GetAlignment(aElignment); } \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetBorderVertSpace(uint32_t *aBorderVertSpace) { return _to GetBorderVertSpace(aBorderVertSpace); } \
  NS_IMETHOD GetBorderHorizSpace(uint32_t *aBorderHorizSpace) { return _to GetBorderHorizSpace(aBorderHorizSpace); } \
  NS_IMETHOD GetDOMElement(nsIDOMElement * *aDOMElement) { return _to GetDOMElement(aDOMElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINTAGINFO(_to) \
  NS_IMETHOD GetAttributes(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributes(aCount, aNames, aValues); } \
  NS_IMETHOD GetAttribute(const char * aName, const char **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttribute(aName, aResult); } \
  NS_IMETHOD GetTagType(nsPluginTagType *aTagType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagType(aTagType); } \
  NS_IMETHOD GetParameters(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameters(aCount, aNames, aValues); } \
  NS_IMETHOD GetParameter(const char * aName, const char **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameter(aName, aResult); } \
  NS_IMETHOD GetDocumentBase(const char **aDocumentBase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentBase(aDocumentBase); } \
  NS_IMETHOD GetDocumentEncoding(const char **aDocumentEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentEncoding(aDocumentEncoding); } \
  NS_IMETHOD GetAlignment(const char **aElignment) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlignment(aElignment); } \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetBorderVertSpace(uint32_t *aBorderVertSpace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBorderVertSpace(aBorderVertSpace); } \
  NS_IMETHOD GetBorderHorizSpace(uint32_t *aBorderHorizSpace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBorderHorizSpace(aBorderHorizSpace); } \
  NS_IMETHOD GetDOMElement(nsIDOMElement * *aDOMElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMElement(aDOMElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginTagInfo : public nsIPluginTagInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINTAGINFO

  nsPluginTagInfo();

private:
  ~nsPluginTagInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginTagInfo, nsIPluginTagInfo)

nsPluginTagInfo::nsPluginTagInfo()
{
  /* member initializers and constructor code */
}

nsPluginTagInfo::~nsPluginTagInfo()
{
  /* destructor code */
}

/* void getAttributes (in PRUint16Ref aCount, in constCharStarConstStar aNames, in constCharStarConstStar aValues); */
NS_IMETHODIMP nsPluginTagInfo::GetAttributes(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttribute (in string aName, out constCharPtr aResult); */
NS_IMETHODIMP nsPluginTagInfo::GetAttribute(const char * aName, const char **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsPluginTagType tagType; */
NS_IMETHODIMP nsPluginTagInfo::GetTagType(nsPluginTagType *aTagType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getParameters (in PRUint16Ref aCount, in constCharStarConstStar aNames, in constCharStarConstStar aValues); */
NS_IMETHODIMP nsPluginTagInfo::GetParameters(uint16_t & aCount, const char* const* & aNames, const char* const* & aValues)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getParameter (in string aName, out constCharPtr aResult); */
NS_IMETHODIMP nsPluginTagInfo::GetParameter(const char * aName, const char **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDocumentBase (out constCharPtr aDocumentBase); */
NS_IMETHODIMP nsPluginTagInfo::GetDocumentBase(const char **aDocumentBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDocumentEncoding (out constCharPtr aDocumentEncoding); */
NS_IMETHODIMP nsPluginTagInfo::GetDocumentEncoding(const char **aDocumentEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAlignment (out constCharPtr aElignment); */
NS_IMETHODIMP nsPluginTagInfo::GetAlignment(const char **aElignment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long width; */
NS_IMETHODIMP nsPluginTagInfo::GetWidth(uint32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long height; */
NS_IMETHODIMP nsPluginTagInfo::GetHeight(uint32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long borderVertSpace; */
NS_IMETHODIMP nsPluginTagInfo::GetBorderVertSpace(uint32_t *aBorderVertSpace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long borderHorizSpace; */
NS_IMETHODIMP nsPluginTagInfo::GetBorderHorizSpace(uint32_t *aBorderHorizSpace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement DOMElement; */
NS_IMETHODIMP nsPluginTagInfo::GetDOMElement(nsIDOMElement * *aDOMElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginTagInfo_h__ */
