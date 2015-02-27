/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIFilePicker.idl
 */

#ifndef __gen_nsIFilePicker_h__
#define __gen_nsIFilePicker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMFile; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIFilePickerShownCallback */
#define NS_IFILEPICKERSHOWNCALLBACK_IID_STR "0d79adad-b244-49a5-9997-2a8cad93fc44"

#define NS_IFILEPICKERSHOWNCALLBACK_IID \
  {0x0d79adad, 0xb244, 0x49a5, \
    { 0x99, 0x97, 0x2a, 0x8c, 0xad, 0x93, 0xfc, 0x44 }}

class NS_NO_VTABLE nsIFilePickerShownCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILEPICKERSHOWNCALLBACK_IID)

  /* void done (in short aResult); */
  NS_IMETHOD Done(int16_t aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFilePickerShownCallback, NS_IFILEPICKERSHOWNCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILEPICKERSHOWNCALLBACK \
  NS_IMETHOD Done(int16_t aResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILEPICKERSHOWNCALLBACK(_to) \
  NS_IMETHOD Done(int16_t aResult) { return _to Done(aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILEPICKERSHOWNCALLBACK(_to) \
  NS_IMETHOD Done(int16_t aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFilePickerShownCallback : public nsIFilePickerShownCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEPICKERSHOWNCALLBACK

  nsFilePickerShownCallback();

private:
  ~nsFilePickerShownCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFilePickerShownCallback, nsIFilePickerShownCallback)

nsFilePickerShownCallback::nsFilePickerShownCallback()
{
  /* member initializers and constructor code */
}

nsFilePickerShownCallback::~nsFilePickerShownCallback()
{
  /* destructor code */
}

/* void done (in short aResult); */
NS_IMETHODIMP nsFilePickerShownCallback::Done(int16_t aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFilePicker */
#define NS_IFILEPICKER_IID_STR "a6a24df3-d20a-4b6a-96d4-4736b10a51b7"

#define NS_IFILEPICKER_IID \
  {0xa6a24df3, 0xd20a, 0x4b6a, \
    { 0x96, 0xd4, 0x47, 0x36, 0xb1, 0x0a, 0x51, 0xb7 }}

class NS_NO_VTABLE nsIFilePicker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILEPICKER_IID)

  enum {
    modeOpen = 0,
    modeSave = 1,
    modeGetFolder = 2,
    modeOpenMultiple = 3,
    returnOK = 0,
    returnCancel = 1,
    returnReplace = 2,
    filterAll = 1,
    filterHTML = 2,
    filterText = 4,
    filterImages = 8,
    filterXML = 16,
    filterXUL = 32,
    filterApps = 64,
    filterAllowURLs = 128,
    filterAudio = 256,
    filterVideo = 512
  };

  /* void init (in nsIDOMWindow parent, in AString title, in short mode); */
  NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, int16_t mode) = 0;

  /* void appendFilters (in long filterMask); */
  NS_IMETHOD AppendFilters(int32_t filterMask) = 0;

  /* void appendFilter (in AString title, in AString filter); */
  NS_IMETHOD AppendFilter(const nsAString & title, const nsAString & filter) = 0;

  /* attribute AString defaultString; */
  NS_IMETHOD GetDefaultString(nsAString & aDefaultString) = 0;
  NS_IMETHOD SetDefaultString(const nsAString & aDefaultString) = 0;

  /* attribute AString defaultExtension; */
  NS_IMETHOD GetDefaultExtension(nsAString & aDefaultExtension) = 0;
  NS_IMETHOD SetDefaultExtension(const nsAString & aDefaultExtension) = 0;

  /* attribute long filterIndex; */
  NS_IMETHOD GetFilterIndex(int32_t *aFilterIndex) = 0;
  NS_IMETHOD SetFilterIndex(int32_t aFilterIndex) = 0;

  /* attribute nsIFile displayDirectory; */
  NS_IMETHOD GetDisplayDirectory(nsIFile * *aDisplayDirectory) = 0;
  NS_IMETHOD SetDisplayDirectory(nsIFile *aDisplayDirectory) = 0;

  /* readonly attribute nsIFile file; */
  NS_IMETHOD GetFile(nsIFile * *aFile) = 0;

  /* readonly attribute nsIURI fileURL; */
  NS_IMETHOD GetFileURL(nsIURI * *aFileURL) = 0;

  /* readonly attribute nsISimpleEnumerator files; */
  NS_IMETHOD GetFiles(nsISimpleEnumerator * *aFiles) = 0;

  /* readonly attribute nsIDOMFile domfile; */
  NS_IMETHOD GetDomfile(nsIDOMFile * *aDomfile) = 0;

  /* readonly attribute nsISimpleEnumerator domfiles; */
  NS_IMETHOD GetDomfiles(nsISimpleEnumerator * *aDomfiles) = 0;

  /* attribute boolean addToRecentDocs; */
  NS_IMETHOD GetAddToRecentDocs(bool *aAddToRecentDocs) = 0;
  NS_IMETHOD SetAddToRecentDocs(bool aAddToRecentDocs) = 0;

  /* [deprecated] short show (); */
  NS_IMETHOD Show(int16_t *_retval) = 0;

  /* void open (in nsIFilePickerShownCallback aFilePickerShownCallback); */
  NS_IMETHOD Open(nsIFilePickerShownCallback *aFilePickerShownCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFilePicker, NS_IFILEPICKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILEPICKER \
  NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, int16_t mode); \
  NS_IMETHOD AppendFilters(int32_t filterMask); \
  NS_IMETHOD AppendFilter(const nsAString & title, const nsAString & filter); \
  NS_IMETHOD GetDefaultString(nsAString & aDefaultString); \
  NS_IMETHOD SetDefaultString(const nsAString & aDefaultString); \
  NS_IMETHOD GetDefaultExtension(nsAString & aDefaultExtension); \
  NS_IMETHOD SetDefaultExtension(const nsAString & aDefaultExtension); \
  NS_IMETHOD GetFilterIndex(int32_t *aFilterIndex); \
  NS_IMETHOD SetFilterIndex(int32_t aFilterIndex); \
  NS_IMETHOD GetDisplayDirectory(nsIFile * *aDisplayDirectory); \
  NS_IMETHOD SetDisplayDirectory(nsIFile *aDisplayDirectory); \
  NS_IMETHOD GetFile(nsIFile * *aFile); \
  NS_IMETHOD GetFileURL(nsIURI * *aFileURL); \
  NS_IMETHOD GetFiles(nsISimpleEnumerator * *aFiles); \
  NS_IMETHOD GetDomfile(nsIDOMFile * *aDomfile); \
  NS_IMETHOD GetDomfiles(nsISimpleEnumerator * *aDomfiles); \
  NS_IMETHOD GetAddToRecentDocs(bool *aAddToRecentDocs); \
  NS_IMETHOD SetAddToRecentDocs(bool aAddToRecentDocs); \
  NS_IMETHOD Show(int16_t *_retval); \
  NS_IMETHOD Open(nsIFilePickerShownCallback *aFilePickerShownCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILEPICKER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, int16_t mode) { return _to Init(parent, title, mode); } \
  NS_IMETHOD AppendFilters(int32_t filterMask) { return _to AppendFilters(filterMask); } \
  NS_IMETHOD AppendFilter(const nsAString & title, const nsAString & filter) { return _to AppendFilter(title, filter); } \
  NS_IMETHOD GetDefaultString(nsAString & aDefaultString) { return _to GetDefaultString(aDefaultString); } \
  NS_IMETHOD SetDefaultString(const nsAString & aDefaultString) { return _to SetDefaultString(aDefaultString); } \
  NS_IMETHOD GetDefaultExtension(nsAString & aDefaultExtension) { return _to GetDefaultExtension(aDefaultExtension); } \
  NS_IMETHOD SetDefaultExtension(const nsAString & aDefaultExtension) { return _to SetDefaultExtension(aDefaultExtension); } \
  NS_IMETHOD GetFilterIndex(int32_t *aFilterIndex) { return _to GetFilterIndex(aFilterIndex); } \
  NS_IMETHOD SetFilterIndex(int32_t aFilterIndex) { return _to SetFilterIndex(aFilterIndex); } \
  NS_IMETHOD GetDisplayDirectory(nsIFile * *aDisplayDirectory) { return _to GetDisplayDirectory(aDisplayDirectory); } \
  NS_IMETHOD SetDisplayDirectory(nsIFile *aDisplayDirectory) { return _to SetDisplayDirectory(aDisplayDirectory); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) { return _to GetFile(aFile); } \
  NS_IMETHOD GetFileURL(nsIURI * *aFileURL) { return _to GetFileURL(aFileURL); } \
  NS_IMETHOD GetFiles(nsISimpleEnumerator * *aFiles) { return _to GetFiles(aFiles); } \
  NS_IMETHOD GetDomfile(nsIDOMFile * *aDomfile) { return _to GetDomfile(aDomfile); } \
  NS_IMETHOD GetDomfiles(nsISimpleEnumerator * *aDomfiles) { return _to GetDomfiles(aDomfiles); } \
  NS_IMETHOD GetAddToRecentDocs(bool *aAddToRecentDocs) { return _to GetAddToRecentDocs(aAddToRecentDocs); } \
  NS_IMETHOD SetAddToRecentDocs(bool aAddToRecentDocs) { return _to SetAddToRecentDocs(aAddToRecentDocs); } \
  NS_IMETHOD Show(int16_t *_retval) { return _to Show(_retval); } \
  NS_IMETHOD Open(nsIFilePickerShownCallback *aFilePickerShownCallback) { return _to Open(aFilePickerShownCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILEPICKER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *parent, const nsAString & title, int16_t mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(parent, title, mode); } \
  NS_IMETHOD AppendFilters(int32_t filterMask) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendFilters(filterMask); } \
  NS_IMETHOD AppendFilter(const nsAString & title, const nsAString & filter) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendFilter(title, filter); } \
  NS_IMETHOD GetDefaultString(nsAString & aDefaultString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultString(aDefaultString); } \
  NS_IMETHOD SetDefaultString(const nsAString & aDefaultString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultString(aDefaultString); } \
  NS_IMETHOD GetDefaultExtension(nsAString & aDefaultExtension) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultExtension(aDefaultExtension); } \
  NS_IMETHOD SetDefaultExtension(const nsAString & aDefaultExtension) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultExtension(aDefaultExtension); } \
  NS_IMETHOD GetFilterIndex(int32_t *aFilterIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterIndex(aFilterIndex); } \
  NS_IMETHOD SetFilterIndex(int32_t aFilterIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterIndex(aFilterIndex); } \
  NS_IMETHOD GetDisplayDirectory(nsIFile * *aDisplayDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayDirectory(aDisplayDirectory); } \
  NS_IMETHOD SetDisplayDirectory(nsIFile *aDisplayDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayDirectory(aDisplayDirectory); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_IMETHOD GetFileURL(nsIURI * *aFileURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileURL(aFileURL); } \
  NS_IMETHOD GetFiles(nsISimpleEnumerator * *aFiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFiles(aFiles); } \
  NS_IMETHOD GetDomfile(nsIDOMFile * *aDomfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomfile(aDomfile); } \
  NS_IMETHOD GetDomfiles(nsISimpleEnumerator * *aDomfiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomfiles(aDomfiles); } \
  NS_IMETHOD GetAddToRecentDocs(bool *aAddToRecentDocs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddToRecentDocs(aAddToRecentDocs); } \
  NS_IMETHOD SetAddToRecentDocs(bool aAddToRecentDocs) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAddToRecentDocs(aAddToRecentDocs); } \
  NS_IMETHOD Show(int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(_retval); } \
  NS_IMETHOD Open(nsIFilePickerShownCallback *aFilePickerShownCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aFilePickerShownCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFilePicker : public nsIFilePicker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEPICKER

  nsFilePicker();

private:
  ~nsFilePicker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFilePicker, nsIFilePicker)

nsFilePicker::nsFilePicker()
{
  /* member initializers and constructor code */
}

nsFilePicker::~nsFilePicker()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow parent, in AString title, in short mode); */
NS_IMETHODIMP nsFilePicker::Init(nsIDOMWindow *parent, const nsAString & title, int16_t mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendFilters (in long filterMask); */
NS_IMETHODIMP nsFilePicker::AppendFilters(int32_t filterMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendFilter (in AString title, in AString filter); */
NS_IMETHODIMP nsFilePicker::AppendFilter(const nsAString & title, const nsAString & filter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString defaultString; */
NS_IMETHODIMP nsFilePicker::GetDefaultString(nsAString & aDefaultString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFilePicker::SetDefaultString(const nsAString & aDefaultString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString defaultExtension; */
NS_IMETHODIMP nsFilePicker::GetDefaultExtension(nsAString & aDefaultExtension)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFilePicker::SetDefaultExtension(const nsAString & aDefaultExtension)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long filterIndex; */
NS_IMETHODIMP nsFilePicker::GetFilterIndex(int32_t *aFilterIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFilePicker::SetFilterIndex(int32_t aFilterIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFile displayDirectory; */
NS_IMETHODIMP nsFilePicker::GetDisplayDirectory(nsIFile * *aDisplayDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFilePicker::SetDisplayDirectory(nsIFile *aDisplayDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile file; */
NS_IMETHODIMP nsFilePicker::GetFile(nsIFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI fileURL; */
NS_IMETHODIMP nsFilePicker::GetFileURL(nsIURI * *aFileURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator files; */
NS_IMETHODIMP nsFilePicker::GetFiles(nsISimpleEnumerator * *aFiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMFile domfile; */
NS_IMETHODIMP nsFilePicker::GetDomfile(nsIDOMFile * *aDomfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator domfiles; */
NS_IMETHODIMP nsFilePicker::GetDomfiles(nsISimpleEnumerator * *aDomfiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean addToRecentDocs; */
NS_IMETHODIMP nsFilePicker::GetAddToRecentDocs(bool *aAddToRecentDocs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFilePicker::SetAddToRecentDocs(bool aAddToRecentDocs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] short show (); */
NS_IMETHODIMP nsFilePicker::Show(int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (in nsIFilePickerShownCallback aFilePickerShownCallback); */
NS_IMETHODIMP nsFilePicker::Open(nsIFilePickerShownCallback *aFilePickerShownCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFilePicker_h__ */
