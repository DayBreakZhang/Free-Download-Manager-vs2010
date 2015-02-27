/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/storage/public/mozIStorageBaseStatement.idl
 */

#ifndef __gen_mozIStorageBaseStatement_h__
#define __gen_mozIStorageBaseStatement_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_mozIStorageBindingParams_h__
#include "mozIStorageBindingParams.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class mozIStorageStatementCallback; /* forward declaration */

class mozIStoragePendingStatement; /* forward declaration */

class mozIStorageBindingParams; /* forward declaration */

class mozIStorageBindingParamsArray; /* forward declaration */


/* starting interface:    mozIStorageBaseStatement */
#define MOZISTORAGEBASESTATEMENT_IID_STR "da2ec336-fbbb-4ba1-9778-8c9825980d01"

#define MOZISTORAGEBASESTATEMENT_IID \
  {0xda2ec336, 0xfbbb, 0x4ba1, \
    { 0x97, 0x78, 0x8c, 0x98, 0x25, 0x98, 0x0d, 0x01 }}

/**
 * The base interface for both pure asynchronous storage statements 
 * (mozIStorageAsyncStatement) and 'classic' storage statements
 * (mozIStorageStatement) that can be used for both synchronous and asynchronous
 * purposes.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageBaseStatement : public mozIStorageBindingParams {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEBASESTATEMENT_IID)

  /**
   * Finalizes a statement so you can successfully close a database connection.
   * Once a statement has been finalized it can no longer be used for any
   * purpose.
   * 
   * Statements are implicitly finalized when their reference counts hits zero.
   * If you are a native (C++) caller this is accomplished by setting all of
   * your nsCOMPtr instances to be NULL.  If you are operating from JavaScript
   * code then you cannot rely on this behavior because of the involvement of
   * garbage collection.
   *
   * When finalizing an asynchronous statement you do not need to worry about
   * whether the statement has actually been executed by the asynchronous
   * thread; you just need to call finalize after your last call to executeAsync
   * involving the statement.  However, you do need to use asyncClose instead of
   * close on the connection if any statements have been used asynchronously.
   */
  /* void finalize (); */
  NS_SCRIPTABLE NS_IMETHOD Finalize(void) = 0;

  /**
   * Bind the given value at the given numeric index.
   *
   * @param aParamIndex
   *        0-based index, 0 corresponding to the first numbered argument or
   *        "?1".
   * @param aValue
   *        Argument value.
   * @param aValueSize
   *        Length of aValue in bytes.
   * @{
   */
  /* [deprecated] void bindUTF8StringParameter (in unsigned long aParamIndex, in AUTF8String aValue); */
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue) = 0;

  /* [deprecated] void bindStringParameter (in unsigned long aParamIndex, in AString aValue); */
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue) = 0;

  /* [deprecated] void bindDoubleParameter (in unsigned long aParamIndex, in double aValue); */
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindDoubleParameter(PRUint32 aParamIndex, double aValue) = 0;

  /* [deprecated] void bindInt32Parameter (in unsigned long aParamIndex, in long aValue); */
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue) = 0;

  /* [deprecated] void bindInt64Parameter (in unsigned long aParamIndex, in long long aValue); */
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue) = 0;

  /* [deprecated] void bindNullParameter (in unsigned long aParamIndex); */
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindNullParameter(PRUint32 aParamIndex) = 0;

  /* [deprecated] void bindBlobParameter (in unsigned long aParamIndex, [array, size_is (aValueSize), const] in octet aValue, in unsigned long aValueSize); */
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize) = 0;

  /**@}*/
/**
   * Binds the array of parameters to the statement.  When executeAsync is
   * called, all the parameters in aParameters are bound and then executed.
   *
   * @param aParameters
   *        The array of parameters to bind to the statement upon execution.
   *
   * @note This is only works on statements being used asynchronously.
   */
  /* void bindParameters (in mozIStorageBindingParamsArray aParameters); */
  NS_SCRIPTABLE NS_IMETHOD BindParameters(mozIStorageBindingParamsArray *aParameters) = 0;

  /**
   * Creates a new mozIStorageBindingParamsArray that can be used to bind
   * multiple sets of data to a statement with bindParameters.
   *
   * @return a mozIStorageBindingParamsArray that multiple sets of parameters
   *         can be bound to.
   *
   * @note This is only useful for statements being used asynchronously.
   */
  /* mozIStorageBindingParamsArray newBindingParamsArray (); */
  NS_SCRIPTABLE NS_IMETHOD NewBindingParamsArray(mozIStorageBindingParamsArray **_retval NS_OUTPARAM) = 0;

  /**
   * Execute a query asynchronously using any currently bound parameters.  This
   * statement can be reused immediately, and reset does not need to be called.
   *
   * @note If you have any custom defined functions, they must be re-entrant
   *       since they can be called on multiple threads.
   *
   * @param aCallback [optional]
   *        The callback object that will be notified of progress, errors, and
   *        completion.
   * @return an object that can be used to cancel the statements execution.
   */
  /* mozIStoragePendingStatement executeAsync ([optional] in mozIStorageStatementCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) = 0;

  /**
   * The statement is not usable, either because it failed to initialize or
   * was explicitly finalized.
   */
  enum { MOZ_STORAGE_STATEMENT_INVALID = 0 };

  /**
   * The statement is usable.
   */
  enum { MOZ_STORAGE_STATEMENT_READY = 1 };

  /**
   * Indicates that the statement is executing and the row getters may be used.
   *
   * @note This is only relevant for mozIStorageStatement instances being used
   *       in a synchronous fashion.
   */
  enum { MOZ_STORAGE_STATEMENT_EXECUTING = 2 };

  /**
   * Find out whether the statement is usable (has not been finalized).
   */
  /* readonly attribute long state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt32 *aState) = 0;

  /**
   * Escape a string for SQL LIKE search.
   *
   * @note Consumers will have to use same escape char when doing statements
   *       such as:   ...LIKE '?1' ESCAPE '/'...
   *
   * @param aValue
   *        The string to escape for SQL LIKE.
   * @param aEscapeChar
   *        The escape character.
   * @return an AString of an escaped version of aValue
   *         (%, _ and the escape char are escaped with the escape char)
   *         For example, we will convert "foo/bar_baz%20cheese" 
   *         into "foo//bar/_baz/%20cheese" (if the escape char is '/').
   */
  /* AString escapeStringForLIKE (in AString aValue, in wchar aEscapeChar); */
  NS_SCRIPTABLE NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageBaseStatement, MOZISTORAGEBASESTATEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEBASESTATEMENT \
  NS_SCRIPTABLE NS_IMETHOD Finalize(void); \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue); \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue); \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindDoubleParameter(PRUint32 aParamIndex, double aValue); \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue); \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue); \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindNullParameter(PRUint32 aParamIndex); \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize); \
  NS_SCRIPTABLE NS_IMETHOD BindParameters(mozIStorageBindingParamsArray *aParameters); \
  NS_SCRIPTABLE NS_IMETHOD NewBindingParamsArray(mozIStorageBindingParamsArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt32 *aState); \
  NS_SCRIPTABLE NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEBASESTATEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Finalize(void) { return _to Finalize(); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue) { return _to BindUTF8StringParameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue) { return _to BindStringParameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindDoubleParameter(PRUint32 aParamIndex, double aValue) { return _to BindDoubleParameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue) { return _to BindInt32Parameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue) { return _to BindInt64Parameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindNullParameter(PRUint32 aParamIndex) { return _to BindNullParameter(aParamIndex); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize) { return _to BindBlobParameter(aParamIndex, aValue, aValueSize); } \
  NS_SCRIPTABLE NS_IMETHOD BindParameters(mozIStorageBindingParamsArray *aParameters) { return _to BindParameters(aParameters); } \
  NS_SCRIPTABLE NS_IMETHOD NewBindingParamsArray(mozIStorageBindingParamsArray **_retval NS_OUTPARAM) { return _to NewBindingParamsArray(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) { return _to ExecuteAsync(aCallback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt32 *aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM) { return _to EscapeStringForLIKE(aValue, aEscapeChar, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEBASESTATEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Finalize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finalize(); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindUTF8StringParameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindStringParameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindDoubleParameter(PRUint32 aParamIndex, double aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindDoubleParameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindInt32Parameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindInt64Parameter(aParamIndex, aValue); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindNullParameter(PRUint32 aParamIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindNullParameter(aParamIndex); } \
  NS_DEPRECATED NS_SCRIPTABLE NS_IMETHOD BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindBlobParameter(aParamIndex, aValue, aValueSize); } \
  NS_SCRIPTABLE NS_IMETHOD BindParameters(mozIStorageBindingParamsArray *aParameters) { return !_to ? NS_ERROR_NULL_POINTER : _to->BindParameters(aParameters); } \
  NS_SCRIPTABLE NS_IMETHOD NewBindingParamsArray(mozIStorageBindingParamsArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewBindingParamsArray(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteAsync(aCallback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRInt32 *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EscapeStringForLIKE(aValue, aEscapeChar, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageBaseStatement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEBASESTATEMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageBaseStatement)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void finalize (); */
NS_IMETHODIMP _MYCLASS_::Finalize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindUTF8StringParameter (in unsigned long aParamIndex, in AUTF8String aValue); */
NS_IMETHODIMP _MYCLASS_::BindUTF8StringParameter(PRUint32 aParamIndex, const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindStringParameter (in unsigned long aParamIndex, in AString aValue); */
NS_IMETHODIMP _MYCLASS_::BindStringParameter(PRUint32 aParamIndex, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindDoubleParameter (in unsigned long aParamIndex, in double aValue); */
NS_IMETHODIMP _MYCLASS_::BindDoubleParameter(PRUint32 aParamIndex, double aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindInt32Parameter (in unsigned long aParamIndex, in long aValue); */
NS_IMETHODIMP _MYCLASS_::BindInt32Parameter(PRUint32 aParamIndex, PRInt32 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindInt64Parameter (in unsigned long aParamIndex, in long long aValue); */
NS_IMETHODIMP _MYCLASS_::BindInt64Parameter(PRUint32 aParamIndex, PRInt64 aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindNullParameter (in unsigned long aParamIndex); */
NS_IMETHODIMP _MYCLASS_::BindNullParameter(PRUint32 aParamIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] void bindBlobParameter (in unsigned long aParamIndex, [array, size_is (aValueSize), const] in octet aValue, in unsigned long aValueSize); */
NS_IMETHODIMP _MYCLASS_::BindBlobParameter(PRUint32 aParamIndex, const PRUint8 *aValue, PRUint32 aValueSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bindParameters (in mozIStorageBindingParamsArray aParameters); */
NS_IMETHODIMP _MYCLASS_::BindParameters(mozIStorageBindingParamsArray *aParameters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageBindingParamsArray newBindingParamsArray (); */
NS_IMETHODIMP _MYCLASS_::NewBindingParamsArray(mozIStorageBindingParamsArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement executeAsync ([optional] in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::ExecuteAsync(mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long state; */
NS_IMETHODIMP _MYCLASS_::GetState(PRInt32 *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString escapeStringForLIKE (in AString aValue, in wchar aEscapeChar); */
NS_IMETHODIMP _MYCLASS_::EscapeStringForLIKE(const nsAString & aValue, PRUnichar aEscapeChar, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageBaseStatement_h__ */
