/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/places/public/nsPIPlacesDatabase.idl
 */

#ifndef __gen_nsPIPlacesDatabase_h__
#define __gen_nsPIPlacesDatabase_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class nsINavHistoryQuery; /* forward declaration */

class nsINavHistoryQueryOptions; /* forward declaration */

class mozIStorageStatementCallback; /* forward declaration */

class mozIStoragePendingStatement; /* forward declaration */


/* starting interface:    nsPIPlacesDatabase */
#define NS_PIPLACESDATABASE_IID_STR "6eb7ed3d-13ca-450b-b370-15c75e2f3dab"

#define NS_PIPLACESDATABASE_IID \
  {0x6eb7ed3d, 0x13ca, 0x450b, \
    { 0xb3, 0x70, 0x15, 0xc7, 0x5e, 0x2f, 0x3d, 0xab }}

/**
 * This is a private interface used by Places components to get access to the
 * database.  If outside consumers wish to use this, they should only read from
 * the database so they do not break any internal invariants.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsPIPlacesDatabase : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPLACESDATABASE_IID)

  /**
   * The database connection used by Places.
   */
  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection **aDBConnection) = 0;

  /**
   * Asynchronously executes the statement created from queries.
   *
   * @see nsINavHistoryService::executeQueries
   * @note THIS IS A TEMPORARY API.  Don't rely on it, since it will be replaced
   *       in future versions by a real async querying API.
   * @note Results obtained from this method differ from results obtained from
   *       executeQueries, because there is additional filtering and sorting
   *       done by the latter.  Thus you should use executeQueries, unless you
   *       are absolutely sure that the returned results are fine for
   *       your use-case.
   */
  /* mozIStoragePendingStatement asyncExecuteLegacyQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions aOptions, in mozIStorageStatementCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPlacesDatabase, NS_PIPLACESDATABASE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPLACESDATABASE \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection **aDBConnection); \
  NS_SCRIPTABLE NS_IMETHOD AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPLACESDATABASE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection **aDBConnection) { return _to GetDBConnection(aDBConnection); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) { return _to AsyncExecuteLegacyQueries(aQueries, aQueryCount, aOptions, aCallback, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPLACESDATABASE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection **aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncExecuteLegacyQueries(aQueries, aQueryCount, aOptions, aCallback, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPlacesDatabase
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPLACESDATABASE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIPlacesDatabase)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP _MYCLASS_::GetDBConnection(mozIStorageConnection **aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement asyncExecuteLegacyQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions aOptions, in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPlacesDatabase_h__ */
