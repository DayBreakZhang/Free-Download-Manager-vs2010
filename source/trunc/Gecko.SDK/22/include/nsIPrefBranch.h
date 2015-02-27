/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/modules/libpref/public/nsIPrefBranch.idl
 */

#ifndef __gen_nsIPrefBranch_h__
#define __gen_nsIPrefBranch_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObserver; /* forward declaration */


/* starting interface:    nsIPrefBranch */
#define NS_IPREFBRANCH_IID_STR "55d25e49-793f-4727-a69f-de8b15f4b985"

#define NS_IPREFBRANCH_IID \
  {0x55d25e49, 0x793f, 0x4727, \
    { 0xa6, 0x9f, 0xde, 0x8b, 0x15, 0xf4, 0xb9, 0x85 }}

class NS_NO_VTABLE nsIPrefBranch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFBRANCH_IID)

  enum {
    PREF_INVALID = 0,
    PREF_STRING = 32,
    PREF_INT = 64,
    PREF_BOOL = 128
  };

  /* readonly attribute string root; */
  NS_IMETHOD GetRoot(char * *aRoot) = 0;

  /* long getPrefType (in string aPrefName); */
  NS_IMETHOD GetPrefType(const char * aPrefName, int32_t *_retval) = 0;

  /* boolean getBoolPref (in string aPrefName); */
  NS_IMETHOD GetBoolPref(const char * aPrefName, bool *_retval) = 0;

  /* void setBoolPref (in string aPrefName, in boolean aValue); */
  NS_IMETHOD SetBoolPref(const char * aPrefName, bool aValue) = 0;

  /* float getFloatPref (in string aPrefName); */
  NS_IMETHOD GetFloatPref(const char * aPrefName, float *_retval) = 0;

  /* string getCharPref (in string aPrefName); */
  NS_IMETHOD GetCharPref(const char * aPrefName, char * *_retval) = 0;

  /* void setCharPref (in string aPrefName, in string aValue); */
  NS_IMETHOD SetCharPref(const char * aPrefName, const char * aValue) = 0;

  /* long getIntPref (in string aPrefName); */
  NS_IMETHOD GetIntPref(const char * aPrefName, int32_t *_retval) = 0;

  /* void setIntPref (in string aPrefName, in long aValue); */
  NS_IMETHOD SetIntPref(const char * aPrefName, int32_t aValue) = 0;

  /* void getComplexValue (in string aPrefName, in nsIIDRef aType, [iid_is (aType), retval] out nsQIResult aValue); */
  NS_IMETHOD GetComplexValue(const char * aPrefName, const nsIID & aType, void **aValue) = 0;

  /* void setComplexValue (in string aPrefName, in nsIIDRef aType, in nsISupports aValue); */
  NS_IMETHOD SetComplexValue(const char * aPrefName, const nsIID & aType, nsISupports *aValue) = 0;

  /* void clearUserPref (in string aPrefName); */
  NS_IMETHOD ClearUserPref(const char * aPrefName) = 0;

  /* void lockPref (in string aPrefName); */
  NS_IMETHOD LockPref(const char * aPrefName) = 0;

  /* boolean prefHasUserValue (in string aPrefName); */
  NS_IMETHOD PrefHasUserValue(const char * aPrefName, bool *_retval) = 0;

  /* boolean prefIsLocked (in string aPrefName); */
  NS_IMETHOD PrefIsLocked(const char * aPrefName, bool *_retval) = 0;

  /* void unlockPref (in string aPrefName); */
  NS_IMETHOD UnlockPref(const char * aPrefName) = 0;

  /* void deleteBranch (in string aStartingAt); */
  NS_IMETHOD DeleteBranch(const char * aStartingAt) = 0;

  /* void getChildList (in string aStartingAt, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out string aChildArray); */
  NS_IMETHOD GetChildList(const char * aStartingAt, uint32_t *aCount, char * **aChildArray) = 0;

  /* void resetBranch (in string aStartingAt); */
  NS_IMETHOD ResetBranch(const char * aStartingAt) = 0;

  /* void addObserver (in string aDomain, in nsIObserver aObserver, in boolean aHoldWeak); */
  NS_IMETHOD AddObserver(const char * aDomain, nsIObserver *aObserver, bool aHoldWeak) = 0;

  /* void removeObserver (in string aDomain, in nsIObserver aObserver); */
  NS_IMETHOD RemoveObserver(const char * aDomain, nsIObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefBranch, NS_IPREFBRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFBRANCH \
  NS_IMETHOD GetRoot(char * *aRoot); \
  NS_IMETHOD GetPrefType(const char * aPrefName, int32_t *_retval); \
  NS_IMETHOD GetBoolPref(const char * aPrefName, bool *_retval); \
  NS_IMETHOD SetBoolPref(const char * aPrefName, bool aValue); \
  NS_IMETHOD GetFloatPref(const char * aPrefName, float *_retval); \
  NS_IMETHOD GetCharPref(const char * aPrefName, char * *_retval); \
  NS_IMETHOD SetCharPref(const char * aPrefName, const char * aValue); \
  NS_IMETHOD GetIntPref(const char * aPrefName, int32_t *_retval); \
  NS_IMETHOD SetIntPref(const char * aPrefName, int32_t aValue); \
  NS_IMETHOD GetComplexValue(const char * aPrefName, const nsIID & aType, void **aValue); \
  NS_IMETHOD SetComplexValue(const char * aPrefName, const nsIID & aType, nsISupports *aValue); \
  NS_IMETHOD ClearUserPref(const char * aPrefName); \
  NS_IMETHOD LockPref(const char * aPrefName); \
  NS_IMETHOD PrefHasUserValue(const char * aPrefName, bool *_retval); \
  NS_IMETHOD PrefIsLocked(const char * aPrefName, bool *_retval); \
  NS_IMETHOD UnlockPref(const char * aPrefName); \
  NS_IMETHOD DeleteBranch(const char * aStartingAt); \
  NS_IMETHOD GetChildList(const char * aStartingAt, uint32_t *aCount, char * **aChildArray); \
  NS_IMETHOD ResetBranch(const char * aStartingAt); \
  NS_IMETHOD AddObserver(const char * aDomain, nsIObserver *aObserver, bool aHoldWeak); \
  NS_IMETHOD RemoveObserver(const char * aDomain, nsIObserver *aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFBRANCH(_to) \
  NS_IMETHOD GetRoot(char * *aRoot) { return _to GetRoot(aRoot); } \
  NS_IMETHOD GetPrefType(const char * aPrefName, int32_t *_retval) { return _to GetPrefType(aPrefName, _retval); } \
  NS_IMETHOD GetBoolPref(const char * aPrefName, bool *_retval) { return _to GetBoolPref(aPrefName, _retval); } \
  NS_IMETHOD SetBoolPref(const char * aPrefName, bool aValue) { return _to SetBoolPref(aPrefName, aValue); } \
  NS_IMETHOD GetFloatPref(const char * aPrefName, float *_retval) { return _to GetFloatPref(aPrefName, _retval); } \
  NS_IMETHOD GetCharPref(const char * aPrefName, char * *_retval) { return _to GetCharPref(aPrefName, _retval); } \
  NS_IMETHOD SetCharPref(const char * aPrefName, const char * aValue) { return _to SetCharPref(aPrefName, aValue); } \
  NS_IMETHOD GetIntPref(const char * aPrefName, int32_t *_retval) { return _to GetIntPref(aPrefName, _retval); } \
  NS_IMETHOD SetIntPref(const char * aPrefName, int32_t aValue) { return _to SetIntPref(aPrefName, aValue); } \
  NS_IMETHOD GetComplexValue(const char * aPrefName, const nsIID & aType, void **aValue) { return _to GetComplexValue(aPrefName, aType, aValue); } \
  NS_IMETHOD SetComplexValue(const char * aPrefName, const nsIID & aType, nsISupports *aValue) { return _to SetComplexValue(aPrefName, aType, aValue); } \
  NS_IMETHOD ClearUserPref(const char * aPrefName) { return _to ClearUserPref(aPrefName); } \
  NS_IMETHOD LockPref(const char * aPrefName) { return _to LockPref(aPrefName); } \
  NS_IMETHOD PrefHasUserValue(const char * aPrefName, bool *_retval) { return _to PrefHasUserValue(aPrefName, _retval); } \
  NS_IMETHOD PrefIsLocked(const char * aPrefName, bool *_retval) { return _to PrefIsLocked(aPrefName, _retval); } \
  NS_IMETHOD UnlockPref(const char * aPrefName) { return _to UnlockPref(aPrefName); } \
  NS_IMETHOD DeleteBranch(const char * aStartingAt) { return _to DeleteBranch(aStartingAt); } \
  NS_IMETHOD GetChildList(const char * aStartingAt, uint32_t *aCount, char * **aChildArray) { return _to GetChildList(aStartingAt, aCount, aChildArray); } \
  NS_IMETHOD ResetBranch(const char * aStartingAt) { return _to ResetBranch(aStartingAt); } \
  NS_IMETHOD AddObserver(const char * aDomain, nsIObserver *aObserver, bool aHoldWeak) { return _to AddObserver(aDomain, aObserver, aHoldWeak); } \
  NS_IMETHOD RemoveObserver(const char * aDomain, nsIObserver *aObserver) { return _to RemoveObserver(aDomain, aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFBRANCH(_to) \
  NS_IMETHOD GetRoot(char * *aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_IMETHOD GetPrefType(const char * aPrefName, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefType(aPrefName, _retval); } \
  NS_IMETHOD GetBoolPref(const char * aPrefName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoolPref(aPrefName, _retval); } \
  NS_IMETHOD SetBoolPref(const char * aPrefName, bool aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBoolPref(aPrefName, aValue); } \
  NS_IMETHOD GetFloatPref(const char * aPrefName, float *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFloatPref(aPrefName, _retval); } \
  NS_IMETHOD GetCharPref(const char * aPrefName, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharPref(aPrefName, _retval); } \
  NS_IMETHOD SetCharPref(const char * aPrefName, const char * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharPref(aPrefName, aValue); } \
  NS_IMETHOD GetIntPref(const char * aPrefName, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntPref(aPrefName, _retval); } \
  NS_IMETHOD SetIntPref(const char * aPrefName, int32_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIntPref(aPrefName, aValue); } \
  NS_IMETHOD GetComplexValue(const char * aPrefName, const nsIID & aType, void **aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComplexValue(aPrefName, aType, aValue); } \
  NS_IMETHOD SetComplexValue(const char * aPrefName, const nsIID & aType, nsISupports *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetComplexValue(aPrefName, aType, aValue); } \
  NS_IMETHOD ClearUserPref(const char * aPrefName) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearUserPref(aPrefName); } \
  NS_IMETHOD LockPref(const char * aPrefName) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockPref(aPrefName); } \
  NS_IMETHOD PrefHasUserValue(const char * aPrefName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrefHasUserValue(aPrefName, _retval); } \
  NS_IMETHOD PrefIsLocked(const char * aPrefName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrefIsLocked(aPrefName, _retval); } \
  NS_IMETHOD UnlockPref(const char * aPrefName) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockPref(aPrefName); } \
  NS_IMETHOD DeleteBranch(const char * aStartingAt) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteBranch(aStartingAt); } \
  NS_IMETHOD GetChildList(const char * aStartingAt, uint32_t *aCount, char * **aChildArray) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildList(aStartingAt, aCount, aChildArray); } \
  NS_IMETHOD ResetBranch(const char * aStartingAt) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetBranch(aStartingAt); } \
  NS_IMETHOD AddObserver(const char * aDomain, nsIObserver *aObserver, bool aHoldWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aDomain, aObserver, aHoldWeak); } \
  NS_IMETHOD RemoveObserver(const char * aDomain, nsIObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aDomain, aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefBranch : public nsIPrefBranch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFBRANCH

  nsPrefBranch();

private:
  ~nsPrefBranch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrefBranch, nsIPrefBranch)

nsPrefBranch::nsPrefBranch()
{
  /* member initializers and constructor code */
}

nsPrefBranch::~nsPrefBranch()
{
  /* destructor code */
}

/* readonly attribute string root; */
NS_IMETHODIMP nsPrefBranch::GetRoot(char * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getPrefType (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::GetPrefType(const char * aPrefName, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getBoolPref (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::GetBoolPref(const char * aPrefName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBoolPref (in string aPrefName, in boolean aValue); */
NS_IMETHODIMP nsPrefBranch::SetBoolPref(const char * aPrefName, bool aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getFloatPref (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::GetFloatPref(const char * aPrefName, float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getCharPref (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::GetCharPref(const char * aPrefName, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCharPref (in string aPrefName, in string aValue); */
NS_IMETHODIMP nsPrefBranch::SetCharPref(const char * aPrefName, const char * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIntPref (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::GetIntPref(const char * aPrefName, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIntPref (in string aPrefName, in long aValue); */
NS_IMETHODIMP nsPrefBranch::SetIntPref(const char * aPrefName, int32_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getComplexValue (in string aPrefName, in nsIIDRef aType, [iid_is (aType), retval] out nsQIResult aValue); */
NS_IMETHODIMP nsPrefBranch::GetComplexValue(const char * aPrefName, const nsIID & aType, void **aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setComplexValue (in string aPrefName, in nsIIDRef aType, in nsISupports aValue); */
NS_IMETHODIMP nsPrefBranch::SetComplexValue(const char * aPrefName, const nsIID & aType, nsISupports *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearUserPref (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::ClearUserPref(const char * aPrefName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lockPref (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::LockPref(const char * aPrefName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean prefHasUserValue (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::PrefHasUserValue(const char * aPrefName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean prefIsLocked (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::PrefIsLocked(const char * aPrefName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlockPref (in string aPrefName); */
NS_IMETHODIMP nsPrefBranch::UnlockPref(const char * aPrefName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteBranch (in string aStartingAt); */
NS_IMETHODIMP nsPrefBranch::DeleteBranch(const char * aStartingAt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getChildList (in string aStartingAt, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out string aChildArray); */
NS_IMETHODIMP nsPrefBranch::GetChildList(const char * aStartingAt, uint32_t *aCount, char * **aChildArray)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetBranch (in string aStartingAt); */
NS_IMETHODIMP nsPrefBranch::ResetBranch(const char * aStartingAt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in string aDomain, in nsIObserver aObserver, in boolean aHoldWeak); */
NS_IMETHODIMP nsPrefBranch::AddObserver(const char * aDomain, nsIObserver *aObserver, bool aHoldWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in string aDomain, in nsIObserver aObserver); */
NS_IMETHODIMP nsPrefBranch::RemoveObserver(const char * aDomain, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_PREFBRANCH_CONTRACTID "@mozilla.org/preferencesbranch;1"
/**
 * Notification sent when a preference changes.
 */
#define NS_PREFBRANCH_PREFCHANGE_TOPIC_ID "nsPref:changed"

#endif /* __gen_nsIPrefBranch_h__ */
