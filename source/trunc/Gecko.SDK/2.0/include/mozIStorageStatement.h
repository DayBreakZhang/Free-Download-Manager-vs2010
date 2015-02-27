/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/storage/public/mozIStorageStatement.idl
 */

#ifndef __gen_mozIStorageStatement_h__
#define __gen_mozIStorageStatement_h__


#ifndef __gen_mozIStorageBaseStatement_h__
#include "mozIStorageBaseStatement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStorageStatement */
#define MOZISTORAGESTATEMENT_IID_STR "57ec7be1-36cf-4510-b938-7d1c9ee8cec5"

#define MOZISTORAGESTATEMENT_IID \
  {0x57ec7be1, 0x36cf, 0x4510, \
    { 0xb9, 0x38, 0x7d, 0x1c, 0x9e, 0xe8, 0xce, 0xc5 }}

/**
 * A SQL statement that can be used for both synchronous and asynchronous
 * purposes.
 */
class NS_SCRIPTABLE mozIStorageStatement : public mozIStorageBaseStatement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENT_IID)

  /**
   * Create a clone of this statement, by initializing a new statement
   * with the same connection and same SQL statement as this one.  It
   * does not preserve statement state; that is, if a statement is
   * being executed when it is cloned, the new statement will not be
   * executing.
   */
  /* mozIStorageStatement clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(mozIStorageStatement **_retval NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long parameterCount; */
  NS_SCRIPTABLE NS_IMETHOD GetParameterCount(PRUint32 *aParameterCount) = 0;

  /**
   * Name of nth parameter, if given
   */
  /* AUTF8String getParameterName (in unsigned long aParamIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Returns the index of the named parameter.
   *
   * @param aName
   *        The name of the parameter you want the index for.  This does not
   *        include the leading ':'.
   * @return the index of the named parameter.
   */
  /* unsigned long getParameterIndex (in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Number of columns returned
   */
  /* readonly attribute unsigned long columnCount; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRUint32 *aColumnCount) = 0;

  /**
   * Name of nth column
   */
  /* AUTF8String getColumnName (in unsigned long aColumnIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Obtains the index of the column with the specified name.
   *
   * @param aName
   *        The name of the column.
   * @return The index of the column with the specified name.
   */
  /* unsigned long getColumnIndex (in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Obtains the declared column type of a prepared statement.
   *
   * @param aParamIndex
   *        The zero-based index of the column who's declared type we are
   *        interested in.
   * @return the declared index type.
   */
  /* AUTF8String getColumnDecltype (in unsigned long aParamIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Reset parameters/statement execution
   */
  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

  /**
   * Execute the query, ignoring any results.  This is accomplished by
   * calling executeStep() once, and then calling reset().
   *
   * Error and last insert info, etc. are available from
   * the mozStorageConnection.
   */
  /* void execute (); */
  NS_SCRIPTABLE NS_IMETHOD Execute(void) = 0;

  /**
   * Execute a query, using any currently-bound parameters.  Reset
   * must be called on the statement after the last call of
   * executeStep.
   *
   * @return a boolean indicating whether there are more rows or not;
   *         row data may be accessed using mozIStorageValueArray methods on
   *         the statement.
   */
  /* boolean executeStep (); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteStep(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Execute a query, using any currently-bound parameters.  Reset is called
   * when no more data is returned.  This method is only available to JavaScript
   * consumers.
   *
   * @deprecated As of Mozilla 1.9.2 in favor of executeStep().
   *
   * @return a boolean indicating whether there are more rows or not.
   *
   * [deprecated] boolean step();
   */
/**
   * Obtains the current list of named parameters, which are settable.  This
   * property is only available to JavaScript consumers.
   *
   * readonly attribute mozIStorageStatementParams params;
   */
/**
   * Obtains the current row, with access to all the data members by name.  This
   * property is only available to JavaScript consumers.
   *
   * readonly attribute mozIStorageStatementRow row;
   */
/**
   * These type values are returned by getTypeOfIndex
   * to indicate what type of value is present at
   * a given column.
   */
  enum { VALUE_TYPE_NULL = 0 };

  enum { VALUE_TYPE_INTEGER = 1 };

  enum { VALUE_TYPE_FLOAT = 2 };

  enum { VALUE_TYPE_TEXT = 3 };

  enum { VALUE_TYPE_BLOB = 4 };

  /**
   * The number of entries in the array (each corresponding to a column in the
   * database row)
   */
  /* readonly attribute unsigned long numEntries; */
  NS_SCRIPTABLE NS_IMETHOD GetNumEntries(PRUint32 *aNumEntries) = 0;

  /**
   * Indicate the data type of the current result row for the the given column.
   * SQLite will perform type conversion if you ask for a value as a different
   * type than it is stored as.
   *
   * @param aIndex
   *        0-based column index.
   * @return The type of the value at the given column index; one of
   *         VALUE_TYPE_NULL, VALUE_TYPE_INTEGER, VALUE_TYPE_FLOAT,
   *         VALUE_TYPE_TEXT, VALUE_TYPE_BLOB.
   */
  /* long getTypeOfIndex (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Retrieve the contents of a column from the current result row as an
   * integer.
   *
   * @param aIndex
   *        0-based colummn index.
   * @return Column value interpreted as an integer per type conversion rules.
   * @{
   */
  /* long getInt32 (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long long getInt64 (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM) = 0;

  /** @} */
/**
   * Retrieve the contents of a column from the current result row as a
   * floating point double.
   *
   * @param aIndex
   *        0-based colummn index.
   * @return Column value interpreted as a double per type conversion rules.
   */
  /* double getDouble (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM) = 0;

  /**
   * Retrieve the contents of a column from the current result row as a
   * string.
   *
   * @param aIndex
   *        0-based colummn index.
   * @return The value for the result column interpreted as a string.  If the
   *         stored value was NULL, you will get an empty string with IsVoid set
   *         to distinguish it from an explicitly set empty string.
   * @{
   */
  /* AUTF8String getUTF8String (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM) = 0;

  /* AString getString (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM) = 0;

  /** @} */
/**
   * Retrieve the contents of a column from the current result row as a
   * blob.
   *
   * @param aIndex
   *        0-based colummn index.
   * @param[out] aDataSize
   *             The number of bytes in the blob.
   * @param[out] aData
   *             The contents of the BLOB.  This will be NULL if aDataSize == 0.
   */
  /* void getBlob (in unsigned long aIndex, out unsigned long aDataSize, [array, size_is (aDataSize)] out octet aData); */
  NS_SCRIPTABLE NS_IMETHOD GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) = 0;

  /**
   * Check whether the given column in the current result row is NULL.
   *
   * @param aIndex
   *        0-based colummn index.
   * @return true if the value for the result column is null.
   */
  /* boolean getIsNull (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Returns a shared string pointer
   */
  /* [noscript] void getSharedUTF8String (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out string aResult); */
  NS_IMETHOD GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM) = 0;

  /* [noscript] void getSharedString (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out wstring aResult); */
  NS_IMETHOD GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM) = 0;

  /* [noscript] void getSharedBlob (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out octetPtr aResult); */
  NS_IMETHOD GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 **aResult NS_OUTPARAM) = 0;

  /**
   * Getters for native code that return their values as
   * the return type, for convenience and sanity.
   *
   * Not virtual; no vtable bloat.
   */
  inline PRInt32 AsInt32(PRUint32 idx) {
    PRInt32 v = 0;
    nsresult rv = GetInt32(idx, &v);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return v;
  }
  inline PRInt64 AsInt64(PRUint32 idx) {
    PRInt64 v = 0;
    nsresult rv = GetInt64(idx, &v);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return v;
  }
  inline double AsDouble(PRUint32 idx) {
    double v = 0.0;
    nsresult rv = GetDouble(idx, &v);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return v;
  }
  inline const char* AsSharedUTF8String(PRUint32 idx, PRUint32 *len) {
    const char *str = nsnull;
    *len = 0;
    nsresult rv = GetSharedUTF8String(idx, len, &str);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return str;
  }
  inline const PRUnichar* AsSharedWString(PRUint32 idx, PRUint32 *len) {
    const PRUnichar *str = nsnull;
    *len = 0;
    nsresult rv = GetSharedString(idx, len, &str);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return str;
  }
  inline const PRUint8* AsSharedBlob(PRUint32 idx, PRUint32 *len) {
    const PRUint8 *blob = nsnull;
    *len = 0;
    nsresult rv = GetSharedBlob(idx, len, &blob);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv) || IsNull(idx),
                      "Getting value failed, wrong column index?");
    return blob;
  }
  inline PRBool IsNull(PRUint32 idx) {
    PRBool b = PR_FALSE;
    nsresult rv = GetIsNull(idx, &b);
    NS_ABORT_IF_FALSE(NS_SUCCEEDED(rv),
                      "Getting value failed, wrong column index?");
    return b;
  }
};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatement, MOZISTORAGESTATEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENT \
  NS_SCRIPTABLE NS_IMETHOD Clone(mozIStorageStatement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetParameterCount(PRUint32 *aParameterCount); \
  NS_SCRIPTABLE NS_IMETHOD GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRUint32 *aColumnCount); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); \
  NS_SCRIPTABLE NS_IMETHOD Execute(void); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteStep(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNumEntries(PRUint32 *aNumEntries); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM); \
  NS_IMETHOD GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM); \
  NS_IMETHOD GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 **aResult NS_OUTPARAM); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Clone(mozIStorageStatement **_retval NS_OUTPARAM) { return _to Clone(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterCount(PRUint32 *aParameterCount) { return _to GetParameterCount(aParameterCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) { return _to GetParameterName(aParamIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) { return _to GetParameterIndex(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRUint32 *aColumnCount) { return _to GetColumnCount(aColumnCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM) { return _to GetColumnName(aColumnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) { return _to GetColumnIndex(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) { return _to GetColumnDecltype(aParamIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } \
  NS_SCRIPTABLE NS_IMETHOD Execute(void) { return _to Execute(); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteStep(PRBool *_retval NS_OUTPARAM) { return _to ExecuteStep(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumEntries(PRUint32 *aNumEntries) { return _to GetNumEntries(aNumEntries); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetTypeOfIndex(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetInt32(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return _to GetInt64(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM) { return _to GetDouble(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM) { return _to GetUTF8String(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM) { return _to GetString(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) { return _to GetBlob(aIndex, aDataSize, aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM) { return _to GetIsNull(aIndex, _retval); } \
  NS_IMETHOD GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM) { return _to GetSharedUTF8String(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM) { return _to GetSharedString(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 **aResult NS_OUTPARAM) { return _to GetSharedBlob(aIndex, aLength, aResult); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Clone(mozIStorageStatement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterCount(PRUint32 *aParameterCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterCount(aParameterCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterName(aParamIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameterIndex(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnCount(PRUint32 *aColumnCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnCount(aColumnCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnName(aColumnIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnIndex(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnDecltype(aParamIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_SCRIPTABLE NS_IMETHOD Execute(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Execute(); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteStep(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteStep(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumEntries(PRUint32 *aNumEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumEntries(aNumEntries); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeOfIndex(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt32(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt64(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDouble(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUTF8String(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlob(aIndex, aDataSize, aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNull(aIndex, _retval); } \
  NS_IMETHOD GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedUTF8String(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedString(aIndex, aLength, aResult); } \
  NS_IMETHOD GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedBlob(aIndex, aLength, aResult); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatement)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* mozIStorageStatement clone (); */
NS_IMETHODIMP _MYCLASS_::Clone(mozIStorageStatement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long parameterCount; */
NS_IMETHODIMP _MYCLASS_::GetParameterCount(PRUint32 *aParameterCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getParameterName (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::GetParameterName(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getParameterIndex (in AUTF8String aName); */
NS_IMETHODIMP _MYCLASS_::GetParameterIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long columnCount; */
NS_IMETHODIMP _MYCLASS_::GetColumnCount(PRUint32 *aColumnCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getColumnName (in unsigned long aColumnIndex); */
NS_IMETHODIMP _MYCLASS_::GetColumnName(PRUint32 aColumnIndex, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getColumnIndex (in AUTF8String aName); */
NS_IMETHODIMP _MYCLASS_::GetColumnIndex(const nsACString & aName, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getColumnDecltype (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::GetColumnDecltype(PRUint32 aParamIndex, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP _MYCLASS_::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void execute (); */
NS_IMETHODIMP _MYCLASS_::Execute()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean executeStep (); */
NS_IMETHODIMP _MYCLASS_::ExecuteStep(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long numEntries; */
NS_IMETHODIMP _MYCLASS_::GetNumEntries(PRUint32 *aNumEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getTypeOfIndex (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetTypeOfIndex(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getInt32 (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetInt32(PRUint32 aIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getInt64 (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetInt64(PRUint32 aIndex, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double getDouble (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetDouble(PRUint32 aIndex, double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getUTF8String (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetUTF8String(PRUint32 aIndex, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getString (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetString(PRUint32 aIndex, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBlob (in unsigned long aIndex, out unsigned long aDataSize, [array, size_is (aDataSize)] out octet aData); */
NS_IMETHODIMP _MYCLASS_::GetBlob(PRUint32 aIndex, PRUint32 *aDataSize NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getIsNull (in unsigned long aIndex); */
NS_IMETHODIMP _MYCLASS_::GetIsNull(PRUint32 aIndex, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedUTF8String (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out string aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedUTF8String(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const char **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedString (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out wstring aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedString(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUnichar **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getSharedBlob (in unsigned long aIndex, out unsigned long aLength, [shared, retval] out octetPtr aResult); */
NS_IMETHODIMP _MYCLASS_::GetSharedBlob(PRUint32 aIndex, PRUint32 *aLength NS_OUTPARAM, const PRUint8 **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageStatement_h__ */
