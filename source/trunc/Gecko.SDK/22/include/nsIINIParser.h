/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/ds/nsIINIParser.idl
 */

#ifndef __gen_nsIINIParser_h__
#define __gen_nsIINIParser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIINIParser */
#define NS_IINIPARSER_IID_STR "7eb955f6-3e78-4d39-b72f-c1bf12a94bce"

#define NS_IINIPARSER_IID \
  {0x7eb955f6, 0x3e78, 0x4d39, \
    { 0xb7, 0x2f, 0xc1, 0xbf, 0x12, 0xa9, 0x4b, 0xce }}

class NS_NO_VTABLE nsIINIParser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINIPARSER_IID)

  /* nsIUTF8StringEnumerator getSections (); */
  NS_IMETHOD GetSections(nsIUTF8StringEnumerator * *_retval) = 0;

  /* nsIUTF8StringEnumerator getKeys (in AUTF8String aSection); */
  NS_IMETHOD GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator * *_retval) = 0;

  /* AUTF8String getString (in AUTF8String aSection, in AUTF8String aKey); */
  NS_IMETHOD GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIINIParser, NS_IINIPARSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINIPARSER \
  NS_IMETHOD GetSections(nsIUTF8StringEnumerator * *_retval); \
  NS_IMETHOD GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator * *_retval); \
  NS_IMETHOD GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINIPARSER(_to) \
  NS_IMETHOD GetSections(nsIUTF8StringEnumerator * *_retval) { return _to GetSections(_retval); } \
  NS_IMETHOD GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator * *_retval) { return _to GetKeys(aSection, _retval); } \
  NS_IMETHOD GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval) { return _to GetString(aSection, aKey, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINIPARSER(_to) \
  NS_IMETHOD GetSections(nsIUTF8StringEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSections(_retval); } \
  NS_IMETHOD GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeys(aSection, _retval); } \
  NS_IMETHOD GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(aSection, aKey, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsINIParser : public nsIINIParser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINIPARSER

  nsINIParser();

private:
  ~nsINIParser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsINIParser, nsIINIParser)

nsINIParser::nsINIParser()
{
  /* member initializers and constructor code */
}

nsINIParser::~nsINIParser()
{
  /* destructor code */
}

/* nsIUTF8StringEnumerator getSections (); */
NS_IMETHODIMP nsINIParser::GetSections(nsIUTF8StringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator getKeys (in AUTF8String aSection); */
NS_IMETHODIMP nsINIParser::GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getString (in AUTF8String aSection, in AUTF8String aKey); */
NS_IMETHODIMP nsINIParser::GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIINIParserWriter */
#define NS_IINIPARSERWRITER_IID_STR "b67bb24b-31a3-4a6a-a5d9-0485c9af5a04"

#define NS_IINIPARSERWRITER_IID \
  {0xb67bb24b, 0x31a3, 0x4a6a, \
    { 0xa5, 0xd9, 0x04, 0x85, 0xc9, 0xaf, 0x5a, 0x04 }}

class NS_NO_VTABLE nsIINIParserWriter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINIPARSERWRITER_IID)

  enum {
    WRITE_UTF16 = 1U
  };

  /* void setString (in AUTF8String aSection, in AUTF8String aKey, in AUTF8String aValue); */
  NS_IMETHOD SetString(const nsACString & aSection, const nsACString & aKey, const nsACString & aValue) = 0;

  /* void writeFile ([optional] in nsIFile aINIFile, [optional] in unsigned long aFlags); */
  NS_IMETHOD WriteFile(nsIFile *aINIFile, uint32_t aFlags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIINIParserWriter, NS_IINIPARSERWRITER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINIPARSERWRITER \
  NS_IMETHOD SetString(const nsACString & aSection, const nsACString & aKey, const nsACString & aValue); \
  NS_IMETHOD WriteFile(nsIFile *aINIFile, uint32_t aFlags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINIPARSERWRITER(_to) \
  NS_IMETHOD SetString(const nsACString & aSection, const nsACString & aKey, const nsACString & aValue) { return _to SetString(aSection, aKey, aValue); } \
  NS_IMETHOD WriteFile(nsIFile *aINIFile, uint32_t aFlags) { return _to WriteFile(aINIFile, aFlags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINIPARSERWRITER(_to) \
  NS_IMETHOD SetString(const nsACString & aSection, const nsACString & aKey, const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetString(aSection, aKey, aValue); } \
  NS_IMETHOD WriteFile(nsIFile *aINIFile, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteFile(aINIFile, aFlags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsINIParserWriter : public nsIINIParserWriter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINIPARSERWRITER

  nsINIParserWriter();

private:
  ~nsINIParserWriter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsINIParserWriter, nsIINIParserWriter)

nsINIParserWriter::nsINIParserWriter()
{
  /* member initializers and constructor code */
}

nsINIParserWriter::~nsINIParserWriter()
{
  /* destructor code */
}

/* void setString (in AUTF8String aSection, in AUTF8String aKey, in AUTF8String aValue); */
NS_IMETHODIMP nsINIParserWriter::SetString(const nsACString & aSection, const nsACString & aKey, const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeFile ([optional] in nsIFile aINIFile, [optional] in unsigned long aFlags); */
NS_IMETHODIMP nsINIParserWriter::WriteFile(nsIFile *aINIFile, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIINIParserFactory */
#define NS_IINIPARSERFACTORY_IID_STR "ccae7ea5-1218-4b51-aecb-c2d8ecd46af9"

#define NS_IINIPARSERFACTORY_IID \
  {0xccae7ea5, 0x1218, 0x4b51, \
    { 0xae, 0xcb, 0xc2, 0xd8, 0xec, 0xd4, 0x6a, 0xf9 }}

class NS_NO_VTABLE nsIINIParserFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINIPARSERFACTORY_IID)

  /* nsIINIParser createINIParser (in nsIFile aINIFile); */
  NS_IMETHOD CreateINIParser(nsIFile *aINIFile, nsIINIParser * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIINIParserFactory, NS_IINIPARSERFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINIPARSERFACTORY \
  NS_IMETHOD CreateINIParser(nsIFile *aINIFile, nsIINIParser * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINIPARSERFACTORY(_to) \
  NS_IMETHOD CreateINIParser(nsIFile *aINIFile, nsIINIParser * *_retval) { return _to CreateINIParser(aINIFile, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINIPARSERFACTORY(_to) \
  NS_IMETHOD CreateINIParser(nsIFile *aINIFile, nsIINIParser * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateINIParser(aINIFile, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsINIParserFactory : public nsIINIParserFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINIPARSERFACTORY

  nsINIParserFactory();

private:
  ~nsINIParserFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsINIParserFactory, nsIINIParserFactory)

nsINIParserFactory::nsINIParserFactory()
{
  /* member initializers and constructor code */
}

nsINIParserFactory::~nsINIParserFactory()
{
  /* destructor code */
}

/* nsIINIParser createINIParser (in nsIFile aINIFile); */
NS_IMETHODIMP nsINIParserFactory::CreateINIParser(nsIFile *aINIFile, nsIINIParser * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIINIParser_h__ */
