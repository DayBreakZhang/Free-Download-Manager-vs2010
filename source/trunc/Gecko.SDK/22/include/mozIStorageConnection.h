/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageConnection.idl
 */

#ifndef __gen_mozIStorageConnection_h__
#define __gen_mozIStorageConnection_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageAggregateFunction; /* forward declaration */

class mozIStorageCompletionCallback; /* forward declaration */

class mozIStorageFunction; /* forward declaration */

class mozIStorageProgressHandler; /* forward declaration */

class mozIStorageBaseStatement; /* forward declaration */

class mozIStorageStatement; /* forward declaration */

class mozIStorageAsyncStatement; /* forward declaration */

class mozIStorageStatementCallback; /* forward declaration */

class mozIStoragePendingStatement; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    mozIStorageConnection */
#define MOZISTORAGECONNECTION_IID_STR "b2a4b534-f92e-4387-9bd9-d10408173925"

#define MOZISTORAGECONNECTION_IID \
  {0xb2a4b534, 0xf92e, 0x4387, \
    { 0x9b, 0xd9, 0xd1, 0x04, 0x08, 0x17, 0x39, 0x25 }}

class NS_NO_VTABLE mozIStorageConnection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGECONNECTION_IID)

  enum {
    DEFAULT_PAGE_SIZE = 32768
  };

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void asyncClose ([optional] in mozIStorageCompletionCallback aCallback); */
  NS_IMETHOD AsyncClose(mozIStorageCompletionCallback *aCallback) = 0;

  /* mozIStorageConnection clone ([optional] in boolean aReadOnly); */
  NS_IMETHOD Clone(bool aReadOnly, mozIStorageConnection * *_retval) = 0;

  /* readonly attribute boolean connectionReady; */
  NS_IMETHOD GetConnectionReady(bool *aConnectionReady) = 0;

  /* readonly attribute nsIFile databaseFile; */
  NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) = 0;

  /* readonly attribute long long lastInsertRowID; */
  NS_IMETHOD GetLastInsertRowID(int64_t *aLastInsertRowID) = 0;

  /* readonly attribute long affectedRows; */
  NS_IMETHOD GetAffectedRows(int32_t *aAffectedRows) = 0;

  /* readonly attribute long lastError; */
  NS_IMETHOD GetLastError(int32_t *aLastError) = 0;

  /* readonly attribute AUTF8String lastErrorString; */
  NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) = 0;

  /* attribute long schemaVersion; */
  NS_IMETHOD GetSchemaVersion(int32_t *aSchemaVersion) = 0;
  NS_IMETHOD SetSchemaVersion(int32_t aSchemaVersion) = 0;

  /* mozIStorageStatement createStatement (in AUTF8String aSQLStatement); */
  NS_IMETHOD CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement * *_retval) = 0;

  /* mozIStorageAsyncStatement createAsyncStatement (in AUTF8String aSQLStatement); */
  NS_IMETHOD CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval) = 0;

  /* void executeSimpleSQL (in AUTF8String aSQLStatement); */
  NS_IMETHOD ExecuteSimpleSQL(const nsACString & aSQLStatement) = 0;

  /* mozIStoragePendingStatement executeAsync ([array, size_is (aNumStatements)] in mozIStorageBaseStatement aStatements, in unsigned long aNumStatements, [optional] in mozIStorageStatementCallback aCallback); */
  NS_IMETHOD ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) = 0;

  /* boolean tableExists (in AUTF8String aTableName); */
  NS_IMETHOD TableExists(const nsACString & aTableName, bool *_retval) = 0;

  /* boolean indexExists (in AUTF8String aIndexName); */
  NS_IMETHOD IndexExists(const nsACString & aIndexName, bool *_retval) = 0;

  /* readonly attribute boolean transactionInProgress; */
  NS_IMETHOD GetTransactionInProgress(bool *aTransactionInProgress) = 0;

  /* void beginTransaction (); */
  NS_IMETHOD BeginTransaction(void) = 0;

  enum {
    TRANSACTION_DEFERRED = 0,
    TRANSACTION_IMMEDIATE = 1,
    TRANSACTION_EXCLUSIVE = 2
  };

  /* void beginTransactionAs (in int32_t transactionType); */
  NS_IMETHOD BeginTransactionAs(int32_t transactionType) = 0;

  /* void commitTransaction (); */
  NS_IMETHOD CommitTransaction(void) = 0;

  /* void rollbackTransaction (); */
  NS_IMETHOD RollbackTransaction(void) = 0;

  /* void createTable (in string aTableName, in string aTableSchema); */
  NS_IMETHOD CreateTable(const char * aTableName, const char * aTableSchema) = 0;

  /* void createFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageFunction aFunction); */
  NS_IMETHOD CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction) = 0;

  /* void createAggregateFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageAggregateFunction aFunction); */
  NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction) = 0;

  /* void removeFunction (in AUTF8String aFunctionName); */
  NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) = 0;

  /* mozIStorageProgressHandler setProgressHandler (in int32_t aGranularity, in mozIStorageProgressHandler aHandler); */
  NS_IMETHOD SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval) = 0;

  /* mozIStorageProgressHandler removeProgressHandler (); */
  NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler * *_retval) = 0;

  /* void setGrowthIncrement (in int32_t aIncrement, in AUTF8String aDatabaseName); */
  NS_IMETHOD SetGrowthIncrement(int32_t aIncrement, const nsACString & aDatabaseName) = 0;

  /* [noscript] void enableModule (in ACString aModuleName); */
  NS_IMETHOD EnableModule(const nsACString & aModuleName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageConnection, MOZISTORAGECONNECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGECONNECTION \
  NS_IMETHOD Close(void); \
  NS_IMETHOD AsyncClose(mozIStorageCompletionCallback *aCallback); \
  NS_IMETHOD Clone(bool aReadOnly, mozIStorageConnection * *_retval); \
  NS_IMETHOD GetConnectionReady(bool *aConnectionReady); \
  NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile); \
  NS_IMETHOD GetLastInsertRowID(int64_t *aLastInsertRowID); \
  NS_IMETHOD GetAffectedRows(int32_t *aAffectedRows); \
  NS_IMETHOD GetLastError(int32_t *aLastError); \
  NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString); \
  NS_IMETHOD GetSchemaVersion(int32_t *aSchemaVersion); \
  NS_IMETHOD SetSchemaVersion(int32_t aSchemaVersion); \
  NS_IMETHOD CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement * *_retval); \
  NS_IMETHOD CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval); \
  NS_IMETHOD ExecuteSimpleSQL(const nsACString & aSQLStatement); \
  NS_IMETHOD ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval); \
  NS_IMETHOD TableExists(const nsACString & aTableName, bool *_retval); \
  NS_IMETHOD IndexExists(const nsACString & aIndexName, bool *_retval); \
  NS_IMETHOD GetTransactionInProgress(bool *aTransactionInProgress); \
  NS_IMETHOD BeginTransaction(void); \
  NS_IMETHOD BeginTransactionAs(int32_t transactionType); \
  NS_IMETHOD CommitTransaction(void); \
  NS_IMETHOD RollbackTransaction(void); \
  NS_IMETHOD CreateTable(const char * aTableName, const char * aTableSchema); \
  NS_IMETHOD CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction); \
  NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction); \
  NS_IMETHOD RemoveFunction(const nsACString & aFunctionName); \
  NS_IMETHOD SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval); \
  NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler * *_retval); \
  NS_IMETHOD SetGrowthIncrement(int32_t aIncrement, const nsACString & aDatabaseName); \
  NS_IMETHOD EnableModule(const nsACString & aModuleName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGECONNECTION(_to) \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD AsyncClose(mozIStorageCompletionCallback *aCallback) { return _to AsyncClose(aCallback); } \
  NS_IMETHOD Clone(bool aReadOnly, mozIStorageConnection * *_retval) { return _to Clone(aReadOnly, _retval); } \
  NS_IMETHOD GetConnectionReady(bool *aConnectionReady) { return _to GetConnectionReady(aConnectionReady); } \
  NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) { return _to GetDatabaseFile(aDatabaseFile); } \
  NS_IMETHOD GetLastInsertRowID(int64_t *aLastInsertRowID) { return _to GetLastInsertRowID(aLastInsertRowID); } \
  NS_IMETHOD GetAffectedRows(int32_t *aAffectedRows) { return _to GetAffectedRows(aAffectedRows); } \
  NS_IMETHOD GetLastError(int32_t *aLastError) { return _to GetLastError(aLastError); } \
  NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) { return _to GetLastErrorString(aLastErrorString); } \
  NS_IMETHOD GetSchemaVersion(int32_t *aSchemaVersion) { return _to GetSchemaVersion(aSchemaVersion); } \
  NS_IMETHOD SetSchemaVersion(int32_t aSchemaVersion) { return _to SetSchemaVersion(aSchemaVersion); } \
  NS_IMETHOD CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement * *_retval) { return _to CreateStatement(aSQLStatement, _retval); } \
  NS_IMETHOD CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval) { return _to CreateAsyncStatement(aSQLStatement, _retval); } \
  NS_IMETHOD ExecuteSimpleSQL(const nsACString & aSQLStatement) { return _to ExecuteSimpleSQL(aSQLStatement); } \
  NS_IMETHOD ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) { return _to ExecuteAsync(aStatements, aNumStatements, aCallback, _retval); } \
  NS_IMETHOD TableExists(const nsACString & aTableName, bool *_retval) { return _to TableExists(aTableName, _retval); } \
  NS_IMETHOD IndexExists(const nsACString & aIndexName, bool *_retval) { return _to IndexExists(aIndexName, _retval); } \
  NS_IMETHOD GetTransactionInProgress(bool *aTransactionInProgress) { return _to GetTransactionInProgress(aTransactionInProgress); } \
  NS_IMETHOD BeginTransaction(void) { return _to BeginTransaction(); } \
  NS_IMETHOD BeginTransactionAs(int32_t transactionType) { return _to BeginTransactionAs(transactionType); } \
  NS_IMETHOD CommitTransaction(void) { return _to CommitTransaction(); } \
  NS_IMETHOD RollbackTransaction(void) { return _to RollbackTransaction(); } \
  NS_IMETHOD CreateTable(const char * aTableName, const char * aTableSchema) { return _to CreateTable(aTableName, aTableSchema); } \
  NS_IMETHOD CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction) { return _to CreateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction) { return _to CreateAggregateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) { return _to RemoveFunction(aFunctionName); } \
  NS_IMETHOD SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval) { return _to SetProgressHandler(aGranularity, aHandler, _retval); } \
  NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler * *_retval) { return _to RemoveProgressHandler(_retval); } \
  NS_IMETHOD SetGrowthIncrement(int32_t aIncrement, const nsACString & aDatabaseName) { return _to SetGrowthIncrement(aIncrement, aDatabaseName); } \
  NS_IMETHOD EnableModule(const nsACString & aModuleName) { return _to EnableModule(aModuleName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGECONNECTION(_to) \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD AsyncClose(mozIStorageCompletionCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncClose(aCallback); } \
  NS_IMETHOD Clone(bool aReadOnly, mozIStorageConnection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(aReadOnly, _retval); } \
  NS_IMETHOD GetConnectionReady(bool *aConnectionReady) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectionReady(aConnectionReady); } \
  NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabaseFile(aDatabaseFile); } \
  NS_IMETHOD GetLastInsertRowID(int64_t *aLastInsertRowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastInsertRowID(aLastInsertRowID); } \
  NS_IMETHOD GetAffectedRows(int32_t *aAffectedRows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAffectedRows(aAffectedRows); } \
  NS_IMETHOD GetLastError(int32_t *aLastError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastError(aLastError); } \
  NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastErrorString(aLastErrorString); } \
  NS_IMETHOD GetSchemaVersion(int32_t *aSchemaVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSchemaVersion(aSchemaVersion); } \
  NS_IMETHOD SetSchemaVersion(int32_t aSchemaVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSchemaVersion(aSchemaVersion); } \
  NS_IMETHOD CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateStatement(aSQLStatement, _retval); } \
  NS_IMETHOD CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAsyncStatement(aSQLStatement, _retval); } \
  NS_IMETHOD ExecuteSimpleSQL(const nsACString & aSQLStatement) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteSimpleSQL(aSQLStatement); } \
  NS_IMETHOD ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteAsync(aStatements, aNumStatements, aCallback, _retval); } \
  NS_IMETHOD TableExists(const nsACString & aTableName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TableExists(aTableName, _retval); } \
  NS_IMETHOD IndexExists(const nsACString & aIndexName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexExists(aIndexName, _retval); } \
  NS_IMETHOD GetTransactionInProgress(bool *aTransactionInProgress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransactionInProgress(aTransactionInProgress); } \
  NS_IMETHOD BeginTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTransaction(); } \
  NS_IMETHOD BeginTransactionAs(int32_t transactionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTransactionAs(transactionType); } \
  NS_IMETHOD CommitTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CommitTransaction(); } \
  NS_IMETHOD RollbackTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RollbackTransaction(); } \
  NS_IMETHOD CreateTable(const char * aTableName, const char * aTableSchema) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTable(aTableName, aTableSchema); } \
  NS_IMETHOD CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAggregateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFunction(aFunctionName); } \
  NS_IMETHOD SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProgressHandler(aGranularity, aHandler, _retval); } \
  NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveProgressHandler(_retval); } \
  NS_IMETHOD SetGrowthIncrement(int32_t aIncrement, const nsACString & aDatabaseName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGrowthIncrement(aIncrement, aDatabaseName); } \
  NS_IMETHOD EnableModule(const nsACString & aModuleName) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableModule(aModuleName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageConnection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGECONNECTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageConnection)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void close (); */
NS_IMETHODIMP _MYCLASS_::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncClose ([optional] in mozIStorageCompletionCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::AsyncClose(mozIStorageCompletionCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageConnection clone ([optional] in boolean aReadOnly); */
NS_IMETHODIMP _MYCLASS_::Clone(bool aReadOnly, mozIStorageConnection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean connectionReady; */
NS_IMETHODIMP _MYCLASS_::GetConnectionReady(bool *aConnectionReady)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile databaseFile; */
NS_IMETHODIMP _MYCLASS_::GetDatabaseFile(nsIFile * *aDatabaseFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long lastInsertRowID; */
NS_IMETHODIMP _MYCLASS_::GetLastInsertRowID(int64_t *aLastInsertRowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long affectedRows; */
NS_IMETHODIMP _MYCLASS_::GetAffectedRows(int32_t *aAffectedRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long lastError; */
NS_IMETHODIMP _MYCLASS_::GetLastError(int32_t *aLastError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String lastErrorString; */
NS_IMETHODIMP _MYCLASS_::GetLastErrorString(nsACString & aLastErrorString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long schemaVersion; */
NS_IMETHODIMP _MYCLASS_::GetSchemaVersion(int32_t *aSchemaVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetSchemaVersion(int32_t aSchemaVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageStatement createStatement (in AUTF8String aSQLStatement); */
NS_IMETHODIMP _MYCLASS_::CreateStatement(const nsACString & aSQLStatement, mozIStorageStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageAsyncStatement createAsyncStatement (in AUTF8String aSQLStatement); */
NS_IMETHODIMP _MYCLASS_::CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void executeSimpleSQL (in AUTF8String aSQLStatement); */
NS_IMETHODIMP _MYCLASS_::ExecuteSimpleSQL(const nsACString & aSQLStatement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement executeAsync ([array, size_is (aNumStatements)] in mozIStorageBaseStatement aStatements, in unsigned long aNumStatements, [optional] in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean tableExists (in AUTF8String aTableName); */
NS_IMETHODIMP _MYCLASS_::TableExists(const nsACString & aTableName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean indexExists (in AUTF8String aIndexName); */
NS_IMETHODIMP _MYCLASS_::IndexExists(const nsACString & aIndexName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean transactionInProgress; */
NS_IMETHODIMP _MYCLASS_::GetTransactionInProgress(bool *aTransactionInProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTransaction (); */
NS_IMETHODIMP _MYCLASS_::BeginTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTransactionAs (in int32_t transactionType); */
NS_IMETHODIMP _MYCLASS_::BeginTransactionAs(int32_t transactionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void commitTransaction (); */
NS_IMETHODIMP _MYCLASS_::CommitTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rollbackTransaction (); */
NS_IMETHODIMP _MYCLASS_::RollbackTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createTable (in string aTableName, in string aTableSchema); */
NS_IMETHODIMP _MYCLASS_::CreateTable(const char * aTableName, const char * aTableSchema)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageFunction aFunction); */
NS_IMETHODIMP _MYCLASS_::CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createAggregateFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageAggregateFunction aFunction); */
NS_IMETHODIMP _MYCLASS_::CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFunction (in AUTF8String aFunctionName); */
NS_IMETHODIMP _MYCLASS_::RemoveFunction(const nsACString & aFunctionName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageProgressHandler setProgressHandler (in int32_t aGranularity, in mozIStorageProgressHandler aHandler); */
NS_IMETHODIMP _MYCLASS_::SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageProgressHandler removeProgressHandler (); */
NS_IMETHODIMP _MYCLASS_::RemoveProgressHandler(mozIStorageProgressHandler * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setGrowthIncrement (in int32_t aIncrement, in AUTF8String aDatabaseName); */
NS_IMETHODIMP _MYCLASS_::SetGrowthIncrement(int32_t aIncrement, const nsACString & aDatabaseName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void enableModule (in ACString aModuleName); */
NS_IMETHODIMP _MYCLASS_::EnableModule(const nsACString & aModuleName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageConnection_h__ */
