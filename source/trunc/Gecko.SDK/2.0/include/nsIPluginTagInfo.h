/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/plugin/base/public/nsIPluginTagInfo.idl
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
#define NS_IPLUGINTAGINFO_IID_STR "6d827df5-b5cd-416c-85cb-3cdd05c7aed1"

#define NS_IPLUGINTAGINFO_IID \
  {0x6d827df5, 0xb5cd, 0x416c, \
    { 0x85, 0xcb, 0x3c, 0xdd, 0x05, 0xc7, 0xae, 0xd1 }}

/**
 * Plugin Tag Info Interface
 * This interface provides information about the HTML tag on the page.
 * Some day this might get superseded by a DOM API.
 */
class NS_NO_VTABLE nsIPluginTagInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINTAGINFO_IID)

  /**
   * QueryInterface on nsIPluginInstancePeer to get this.
   *
   * (Corresponds to NPP_New's argc, argn, and argv arguments.)
   * Get a ptr to the paired list of attribute names and values,
   * returns the length of the array.
   *
   * Each name or value is a null-terminated string.
   */
  /* void getAttributes (in PRUint16Ref aCount, in constCharStarConstStar aNames, in constCharStarConstStar aValues); */
  NS_IMETHOD GetAttributes(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues) = 0;

  /**
   * Gets the value for the named attribute.
   *
   * @param aName   - the name of the attribute to find
   * @param aResult - the resulting attribute
   * @result - NS_OK if this operation was successful, NS_ERROR_FAILURE if
   * this operation failed. result is set to NULL if the attribute is not found
   * else to the found value.
   */
  /* void getAttribute (in string aName, out constCharPtr aResult); */
  NS_IMETHOD GetAttribute(const char *aName, const char **aResult NS_OUTPARAM) = 0;

  /**
   * Get the type of the HTML tag that was used ot instantiate this
   * plugin.  Currently supported tags are EMBED, OBJECT and APPLET.
   */
  /* readonly attribute nsPluginTagType tagType; */
  NS_IMETHOD GetTagType(nsPluginTagType *aTagType) = 0;

  /**
   * Get the complete text of the HTML tag that was used to instantiate this plugin.
   */
  /* void getTagText (out constCharPtr aTagText); */
  NS_IMETHOD GetTagText(const char **aTagText NS_OUTPARAM) = 0;

  /**
   * Get a ptr to the paired list of parameter names and values,
   * returns the length of the array.
   *
   * Each name or value is a null-terminated string.
   */
  /* void getParameters (in PRUint16Ref aCount, in constCharStarConstStar aNames, in constCharStarConstStar aValues); */
  NS_IMETHOD GetParameters(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues) = 0;

  /**
   * Get the value for the named parameter.  Returns null
   * if the parameter was not set.
   *
   * @param aName   - name of the parameter
   * @param aResult - parameter value
   * @result        - NS_OK if this operation was successful
   */
  /* void getParameter (in string aName, out constCharPtr aResult); */
  NS_IMETHOD GetParameter(const char *aName, const char **aResult NS_OUTPARAM) = 0;

  /**
   * Get the document base
   */
  /* void getDocumentBase (out constCharPtr aDocumentBase); */
  NS_IMETHOD GetDocumentBase(const char **aDocumentBase NS_OUTPARAM) = 0;

  /**
   * Return an encoding whose name is specified in:
   * http://java.sun.com/products/jdk/1.1/docs/guide/intl/intl.doc.html#25303
   */
  /* void getDocumentEncoding (out constCharPtr aDocumentEncoding); */
  NS_IMETHOD GetDocumentEncoding(const char **aDocumentEncoding NS_OUTPARAM) = 0;

  /**
   * Get object alignment
   */
  /* void getAlignment (out constCharPtr aElignment); */
  NS_IMETHOD GetAlignment(const char **aElignment NS_OUTPARAM) = 0;

  /**
   * Get object width
   */
  /* readonly attribute unsigned long width; */
  NS_IMETHOD GetWidth(PRUint32 *aWidth) = 0;

  /**
   * Get object height
   */
  /* readonly attribute unsigned long height; */
  NS_IMETHOD GetHeight(PRUint32 *aHeight) = 0;

  /**
   * Get border vertical space
   */
  /* readonly attribute unsigned long borderVertSpace; */
  NS_IMETHOD GetBorderVertSpace(PRUint32 *aBorderVertSpace) = 0;

  /**
   * Get border horizontal space
   */
  /* readonly attribute unsigned long borderHorizSpace; */
  NS_IMETHOD GetBorderHorizSpace(PRUint32 *aBorderHorizSpace) = 0;

  /**
   * Returns a unique id for the current document containing plugin
   */
  /* readonly attribute unsigned long uniqueID; */
  NS_IMETHOD GetUniqueID(PRUint32 *aUniqueID) = 0;

  /**
   * Returns the DOM element corresponding to the tag which references
   * this plugin in the document.
   *
   * @param aDOMElement - resulting DOM element
   * @result - NS_OK if this operation was successful
   */
  /* readonly attribute nsIDOMElement DOMElement; */
  NS_IMETHOD GetDOMElement(nsIDOMElement **aDOMElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginTagInfo, NS_IPLUGINTAGINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINTAGINFO \
  NS_IMETHOD GetAttributes(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues); \
  NS_IMETHOD GetAttribute(const char *aName, const char **aResult NS_OUTPARAM); \
  NS_IMETHOD GetTagType(nsPluginTagType *aTagType); \
  NS_IMETHOD GetTagText(const char **aTagText NS_OUTPARAM); \
  NS_IMETHOD GetParameters(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues); \
  NS_IMETHOD GetParameter(const char *aName, const char **aResult NS_OUTPARAM); \
  NS_IMETHOD GetDocumentBase(const char **aDocumentBase NS_OUTPARAM); \
  NS_IMETHOD GetDocumentEncoding(const char **aDocumentEncoding NS_OUTPARAM); \
  NS_IMETHOD GetAlignment(const char **aElignment NS_OUTPARAM); \
  NS_IMETHOD GetWidth(PRUint32 *aWidth); \
  NS_IMETHOD GetHeight(PRUint32 *aHeight); \
  NS_IMETHOD GetBorderVertSpace(PRUint32 *aBorderVertSpace); \
  NS_IMETHOD GetBorderHorizSpace(PRUint32 *aBorderHorizSpace); \
  NS_IMETHOD GetUniqueID(PRUint32 *aUniqueID); \
  NS_IMETHOD GetDOMElement(nsIDOMElement **aDOMElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINTAGINFO(_to) \
  NS_IMETHOD GetAttributes(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues) { return _to GetAttributes(aCount, aNames, aValues); } \
  NS_IMETHOD GetAttribute(const char *aName, const char **aResult NS_OUTPARAM) { return _to GetAttribute(aName, aResult); } \
  NS_IMETHOD GetTagType(nsPluginTagType *aTagType) { return _to GetTagType(aTagType); } \
  NS_IMETHOD GetTagText(const char **aTagText NS_OUTPARAM) { return _to GetTagText(aTagText); } \
  NS_IMETHOD GetParameters(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues) { return _to GetParameters(aCount, aNames, aValues); } \
  NS_IMETHOD GetParameter(const char *aName, const char **aResult NS_OUTPARAM) { return _to GetParameter(aName, aResult); } \
  NS_IMETHOD GetDocumentBase(const char **aDocumentBase NS_OUTPARAM) { return _to GetDocumentBase(aDocumentBase); } \
  NS_IMETHOD GetDocumentEncoding(const char **aDocumentEncoding NS_OUTPARAM) { return _to GetDocumentEncoding(aDocumentEncoding); } \
  NS_IMETHOD GetAlignment(const char **aElignment NS_OUTPARAM) { return _to GetAlignment(aElignment); } \
  NS_IMETHOD GetWidth(PRUint32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(PRUint32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetBorderVertSpace(PRUint32 *aBorderVertSpace) { return _to GetBorderVertSpace(aBorderVertSpace); } \
  NS_IMETHOD GetBorderHorizSpace(PRUint32 *aBorderHorizSpace) { return _to GetBorderHorizSpace(aBorderHorizSpace); } \
  NS_IMETHOD GetUniqueID(PRUint32 *aUniqueID) { return _to GetUniqueID(aUniqueID); } \
  NS_IMETHOD GetDOMElement(nsIDOMElement **aDOMElement) { return _to GetDOMElement(aDOMElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINTAGINFO(_to) \
  NS_IMETHOD GetAttributes(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributes(aCount, aNames, aValues); } \
  NS_IMETHOD GetAttribute(const char *aName, const char **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttribute(aName, aResult); } \
  NS_IMETHOD GetTagType(nsPluginTagType *aTagType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagType(aTagType); } \
  NS_IMETHOD GetTagText(const char **aTagText NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagText(aTagText); } \
  NS_IMETHOD GetParameters(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameters(aCount, aNames, aValues); } \
  NS_IMETHOD GetParameter(const char *aName, const char **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameter(aName, aResult); } \
  NS_IMETHOD GetDocumentBase(const char **aDocumentBase NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentBase(aDocumentBase); } \
  NS_IMETHOD GetDocumentEncoding(const char **aDocumentEncoding NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentEncoding(aDocumentEncoding); } \
  NS_IMETHOD GetAlignment(const char **aElignment NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlignment(aElignment); } \
  NS_IMETHOD GetWidth(PRUint32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(PRUint32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetBorderVertSpace(PRUint32 *aBorderVertSpace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBorderVertSpace(aBorderVertSpace); } \
  NS_IMETHOD GetBorderHorizSpace(PRUint32 *aBorderHorizSpace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBorderHorizSpace(aBorderHorizSpace); } \
  NS_IMETHOD GetUniqueID(PRUint32 *aUniqueID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUniqueID(aUniqueID); } \
  NS_IMETHOD GetDOMElement(nsIDOMElement **aDOMElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMElement(aDOMElement); } 

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
NS_IMETHODIMP nsPluginTagInfo::GetAttributes(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttribute (in string aName, out constCharPtr aResult); */
NS_IMETHODIMP nsPluginTagInfo::GetAttribute(const char *aName, const char **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsPluginTagType tagType; */
NS_IMETHODIMP nsPluginTagInfo::GetTagType(nsPluginTagType *aTagType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTagText (out constCharPtr aTagText); */
NS_IMETHODIMP nsPluginTagInfo::GetTagText(const char **aTagText NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getParameters (in PRUint16Ref aCount, in constCharStarConstStar aNames, in constCharStarConstStar aValues); */
NS_IMETHODIMP nsPluginTagInfo::GetParameters(PRUint16 & aCount, const char* const* & aNames, const char* const* & aValues)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getParameter (in string aName, out constCharPtr aResult); */
NS_IMETHODIMP nsPluginTagInfo::GetParameter(const char *aName, const char **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDocumentBase (out constCharPtr aDocumentBase); */
NS_IMETHODIMP nsPluginTagInfo::GetDocumentBase(const char **aDocumentBase NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDocumentEncoding (out constCharPtr aDocumentEncoding); */
NS_IMETHODIMP nsPluginTagInfo::GetDocumentEncoding(const char **aDocumentEncoding NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAlignment (out constCharPtr aElignment); */
NS_IMETHODIMP nsPluginTagInfo::GetAlignment(const char **aElignment NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long width; */
NS_IMETHODIMP nsPluginTagInfo::GetWidth(PRUint32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long height; */
NS_IMETHODIMP nsPluginTagInfo::GetHeight(PRUint32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long borderVertSpace; */
NS_IMETHODIMP nsPluginTagInfo::GetBorderVertSpace(PRUint32 *aBorderVertSpace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long borderHorizSpace; */
NS_IMETHODIMP nsPluginTagInfo::GetBorderHorizSpace(PRUint32 *aBorderHorizSpace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long uniqueID; */
NS_IMETHODIMP nsPluginTagInfo::GetUniqueID(PRUint32 *aUniqueID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement DOMElement; */
NS_IMETHODIMP nsPluginTagInfo::GetDOMElement(nsIDOMElement **aDOMElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginTagInfo_h__ */
