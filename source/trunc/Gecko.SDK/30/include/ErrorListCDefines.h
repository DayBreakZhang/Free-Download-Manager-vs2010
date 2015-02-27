// IWYU pragma: private, include "nsError.h"
/* Helper file for nsError.h, via preprocessor magic */
  /* Standard "it worked" return value */
#define NS_OK   ((nsresult)(0))

  /* ======================================================================= */
  /* Core errors, not part of any modules */
  /* ======================================================================= */
#define NS_ERROR_BASE                           ((nsresult)(0xC1F30000))
  /* Returned when an instance is not initialized */
#define NS_ERROR_NOT_INITIALIZED                ((nsresult)(NS_ERROR_BASE + 1))
  /* Returned when an instance is already initialized */
#define NS_ERROR_ALREADY_INITIALIZED            ((nsresult)(NS_ERROR_BASE + 2))
  /* Returned by a not implemented function */
#define NS_ERROR_NOT_IMPLEMENTED                ((nsresult)(0x80004001))
  /* Returned when a given interface is not supported. */
#define NS_NOINTERFACE                          ((nsresult)(0x80004002))
#define NS_ERROR_NO_INTERFACE                   ((nsresult)(NS_NOINTERFACE))
  /* Returned when a function aborts */
#define NS_ERROR_ABORT                          ((nsresult)(0x80004004))
  /* Returned when a function fails */
#define NS_ERROR_FAILURE                        ((nsresult)(0x80004005))
  /* Returned when an unexpected error occurs */
#define NS_ERROR_UNEXPECTED                     ((nsresult)(0x8000ffff))
  /* Returned when a memory allocation fails */
#define NS_ERROR_OUT_OF_MEMORY                  ((nsresult)(0x8007000e))
  /* Returned when an illegal value is passed */
#define NS_ERROR_ILLEGAL_VALUE                  ((nsresult)(0x80070057))
#define NS_ERROR_INVALID_ARG                    ((nsresult)(NS_ERROR_ILLEGAL_VALUE))
#define NS_ERROR_INVALID_POINTER                ((nsresult)(NS_ERROR_INVALID_ARG))
#define NS_ERROR_NULL_POINTER                   ((nsresult)(NS_ERROR_INVALID_ARG))
  /* Returned when a class doesn't allow aggregation */
#define NS_ERROR_NO_AGGREGATION                 ((nsresult)(0x80040110))
  /* Returned when an operation can't complete due to an unavailable resource */
#define NS_ERROR_NOT_AVAILABLE                  ((nsresult)(0x80040111))
  /* Returned when a class is not registered */
#define NS_ERROR_FACTORY_NOT_REGISTERED         ((nsresult)(0x80040154))
  /* Returned when a class cannot be registered, but may be tried again later */
#define NS_ERROR_FACTORY_REGISTER_AGAIN         ((nsresult)(0x80040155))
  /* Returned when a dynamically loaded factory couldn't be found */
#define NS_ERROR_FACTORY_NOT_LOADED             ((nsresult)(0x800401f8))
  /* Returned when a factory doesn't support signatures */
#define NS_ERROR_FACTORY_NO_SIGNATURE_SUPPORT   ((nsresult)(NS_ERROR_BASE + 0x101))
  /* Returned when a factory already is registered */
#define NS_ERROR_FACTORY_EXISTS                 ((nsresult)(NS_ERROR_BASE + 0x100))


  /* ======================================================================= */
  /* 1: NS_ERROR_MODULE_XPCOM */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_XPCOM
  /* Result codes used by nsIVariant */
#define NS_ERROR_CANNOT_CONVERT_DATA        ((nsresult)(FAILURE(1)))
#define NS_ERROR_OBJECT_IS_IMMUTABLE        ((nsresult)(FAILURE(2)))
#define NS_ERROR_LOSS_OF_SIGNIFICANT_DATA   ((nsresult)(FAILURE(3)))
  /* Result code used by nsIThreadManager */
#define NS_ERROR_NOT_SAME_THREAD            ((nsresult)(FAILURE(4)))
  /* Various operations are not permitted during XPCOM shutdown and will fail
   * with this exception. */
#define NS_ERROR_ILLEGAL_DURING_SHUTDOWN    ((nsresult)(FAILURE(30)))
#define NS_ERROR_SERVICE_NOT_AVAILABLE      ((nsresult)(FAILURE(22)))

#define NS_SUCCESS_LOSS_OF_INSIGNIFICANT_DATA   ((nsresult)(SUCCESS(1)))
  /* Used by nsCycleCollectionParticipant */
#define NS_SUCCESS_INTERRUPTED_TRAVERSE         ((nsresult)(SUCCESS(2)))
  /* DEPRECATED */
#define NS_ERROR_SERVICE_NOT_FOUND              ((nsresult)(SUCCESS(22)))
  /* DEPRECATED */
#define NS_ERROR_SERVICE_IN_USE                 ((nsresult)(SUCCESS(23)))
#undef MODULE


  /* ======================================================================= */
  /* 2: NS_ERROR_MODULE_BASE */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_BASE
  /* I/O Errors */

  /*  Stream closed */
#define NS_BASE_STREAM_CLOSED           ((nsresult)(FAILURE(2)))
  /*  Error from the operating system */
#define NS_BASE_STREAM_OSERROR          ((nsresult)(FAILURE(3)))
  /*  Illegal arguments */
#define NS_BASE_STREAM_ILLEGAL_ARGS     ((nsresult)(FAILURE(4)))
  /*  For unichar streams */
#define NS_BASE_STREAM_NO_CONVERTER     ((nsresult)(FAILURE(5)))
  /*  For unichar streams */
#define NS_BASE_STREAM_BAD_CONVERSION   ((nsresult)(FAILURE(6)))
#define NS_BASE_STREAM_WOULD_BLOCK      ((nsresult)(FAILURE(7)))
#undef MODULE


  /* ======================================================================= */
  /* 3: NS_ERROR_MODULE_GFX */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_GFX
  /* no printer available (e.g. cannot find _any_ printer) */
#define NS_ERROR_GFX_PRINTER_NO_PRINTER_AVAILABLE         ((nsresult)(FAILURE(1)))
  /* _specified_ (by name) printer not found */
#define NS_ERROR_GFX_PRINTER_NAME_NOT_FOUND               ((nsresult)(FAILURE(2)))
  /* print-to-file: could not open output file */
#define NS_ERROR_GFX_PRINTER_COULD_NOT_OPEN_FILE          ((nsresult)(FAILURE(3)))
  /* print: starting document */
#define NS_ERROR_GFX_PRINTER_STARTDOC                     ((nsresult)(FAILURE(4)))
  /* print: ending document */
#define NS_ERROR_GFX_PRINTER_ENDDOC                       ((nsresult)(FAILURE(5)))
  /* print: starting page */
#define NS_ERROR_GFX_PRINTER_STARTPAGE                    ((nsresult)(FAILURE(6)))
  /* The document is still being loaded */
#define NS_ERROR_GFX_PRINTER_DOC_IS_BUSY                  ((nsresult)(FAILURE(7)))

  /* Font cmap is strangely structured - avoid this font! */
#define NS_ERROR_GFX_CMAP_MALFORMED                       ((nsresult)(FAILURE(51)))
#undef MODULE


  /* ======================================================================= */
  /* 6: NS_ERROR_MODULE_NETWORK */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_NETWORK
  /* General async request error codes:
   *
   * These error codes are commonly passed through callback methods to indicate
   * the status of some requested async request.
   *
   * For example, see nsIRequestObserver::onStopRequest.
   */

  /* The async request completed successfully. */
#define NS_BINDING_SUCCEEDED   ((nsresult)(NS_OK))

  /* The async request failed for some unknown reason.  */
#define NS_BINDING_FAILED       ((nsresult)(FAILURE(1)))
  /* The async request failed because it was aborted by some user action. */
#define NS_BINDING_ABORTED      ((nsresult)(FAILURE(2)))
  /* The async request has been "redirected" to a different async request.
   * (e.g., an HTTP redirect occurred).
   *
   * This error code is used with load groups to notify the load group observer
   * when a request in the load group is redirected to another request. */
#define NS_BINDING_REDIRECTED   ((nsresult)(FAILURE(3)))
  /* The async request has been "retargeted" to a different "handler."
   *
   * This error code is used with load groups to notify the load group observer
   * when a request in the load group is removed from the load group and added
   * to a different load group. */
#define NS_BINDING_RETARGETED   ((nsresult)(FAILURE(4)))

  /* Miscellaneous error codes: These errors are not typically passed via
   * onStopRequest. */

  /* The URI is malformed. */
#define NS_ERROR_MALFORMED_URI                        ((nsresult)(FAILURE(10)))
  /* The requested action could not be completed while the object is busy.
   * Implementations of nsIChannel::asyncOpen will commonly return this error
   * if the channel has already been opened (and has not yet been closed). */
#define NS_ERROR_IN_PROGRESS                          ((nsresult)(FAILURE(15)))
  /* Returned from nsIChannel::asyncOpen to indicate that OnDataAvailable will
   * not be called because there is no content available.  This is used by
   * helper app style protocols (e.g., mailto).  XXX perhaps this should be a
   * success code. */
#define NS_ERROR_NO_CONTENT                           ((nsresult)(FAILURE(17)))
  /* The URI scheme corresponds to an unknown protocol handler. */
#define NS_ERROR_UNKNOWN_PROTOCOL                     ((nsresult)(FAILURE(18)))
  /* The content encoding of the source document was incorrect, for example
   * returning a plain HTML document advertised as Content-Encoding: gzip */
#define NS_ERROR_INVALID_CONTENT_ENCODING             ((nsresult)(FAILURE(27)))
  /* A transport level corruption was found in the source document. for example
   * a document with a calculated checksum that does not match the Content-MD5
   * http header. */
#define NS_ERROR_CORRUPTED_CONTENT                    ((nsresult)(FAILURE(29)))
  /* While parsing for the first component of a header field using syntax as in
   * Content-Disposition or Content-Type, the first component was found to be
   * empty, such as in: Content-Disposition: ; filename=foo */
#define NS_ERROR_FIRST_HEADER_FIELD_COMPONENT_EMPTY   ((nsresult)(FAILURE(34)))
  /* Returned from nsIChannel::asyncOpen when trying to open the channel again
   * (reopening is not supported). */
#define NS_ERROR_ALREADY_OPENED                       ((nsresult)(FAILURE(73)))

  /* Connectivity error codes: */

  /* The connection is already established.  XXX unused - consider removing. */
#define NS_ERROR_ALREADY_CONNECTED          ((nsresult)(FAILURE(11)))
  /* The connection does not exist.  XXX unused - consider removing. */
#define NS_ERROR_NOT_CONNECTED              ((nsresult)(FAILURE(12)))
  /* The connection attempt failed, for example, because no server was
   * listening at specified host:port. */
#define NS_ERROR_CONNECTION_REFUSED         ((nsresult)(FAILURE(13)))
  /* The connection was lost due to a timeout error.  */
#define NS_ERROR_NET_TIMEOUT                ((nsresult)(FAILURE(14)))
  /* The requested action could not be completed while the networking library
   * is in the offline state. */
#define NS_ERROR_OFFLINE                    ((nsresult)(FAILURE(16)))
  /* The requested action was prohibited because it would have caused the
   * networking library to establish a connection to an unsafe or otherwise
   * banned port. */
#define NS_ERROR_PORT_ACCESS_NOT_ALLOWED    ((nsresult)(FAILURE(19)))
  /* The connection was established, but no data was ever received. */
#define NS_ERROR_NET_RESET                  ((nsresult)(FAILURE(20)))
  /* The connection was established, but the data transfer was interrupted. */
#define NS_ERROR_NET_INTERRUPT              ((nsresult)(FAILURE(71)))
  /* The connection attempt to a proxy failed. */
#define NS_ERROR_PROXY_CONNECTION_REFUSED   ((nsresult)(FAILURE(72)))

  /* XXX really need to better rationalize these error codes.  are consumers of
   * necko really expected to know how to discern the meaning of these?? */
  /* This request is not resumable, but it was tried to resume it, or to
   * request resume-specific data. */
#define NS_ERROR_NOT_RESUMABLE         ((nsresult)(FAILURE(25)))
  /* The request failed as a result of a detected redirection loop.  */
#define NS_ERROR_REDIRECT_LOOP         ((nsresult)(FAILURE(31)))
  /* It was attempted to resume the request, but the entity has changed in the
   * meantime. */
#define NS_ERROR_ENTITY_CHANGED        ((nsresult)(FAILURE(32)))
  /* The request failed because the content type returned by the server was not
   * a type expected by the channel (for nested channels such as the JAR
   * channel). */
#define NS_ERROR_UNSAFE_CONTENT_TYPE   ((nsresult)(FAILURE(74)))
  /* The request failed because the user tried to access to a remote XUL
   * document from a website that is not in its white-list. */
#define NS_ERROR_REMOTE_XUL            ((nsresult)(FAILURE(75)))


  /* FTP specific error codes: */

#define NS_ERROR_FTP_LOGIN   ((nsresult)(FAILURE(21)))
#define NS_ERROR_FTP_CWD     ((nsresult)(FAILURE(22)))
#define NS_ERROR_FTP_PASV    ((nsresult)(FAILURE(23)))
#define NS_ERROR_FTP_PWD     ((nsresult)(FAILURE(24)))
#define NS_ERROR_FTP_LIST    ((nsresult)(FAILURE(28)))

  /* DNS specific error codes: */

  /* The lookup of a hostname failed.  This generally refers to the hostname
   * from the URL being loaded. */
#define NS_ERROR_UNKNOWN_HOST            ((nsresult)(FAILURE(30)))
  /* A low or medium priority DNS lookup failed because the pending queue was
   * already full. High priorty (the default) always makes room */
#define NS_ERROR_DNS_LOOKUP_QUEUE_FULL   ((nsresult)(FAILURE(33)))
  /* The lookup of a proxy hostname failed.  If a channel is configured to
   * speak to a proxy server, then it will generate this error if the proxy
   * hostname cannot be resolved. */
#define NS_ERROR_UNKNOWN_PROXY_HOST      ((nsresult)(FAILURE(42)))


  /* Socket specific error codes: */

  /* The specified socket type does not exist. */
#define NS_ERROR_UNKNOWN_SOCKET_TYPE    ((nsresult)(FAILURE(51)))
  /* The specified socket type could not be created. */
#define NS_ERROR_SOCKET_CREATE_FAILED   ((nsresult)(FAILURE(52)))
  /* The operating system doesn't support the given type of address. */
#define NS_ERROR_SOCKET_ADDRESS_NOT_SUPPORTED  ((nsresult)(FAILURE(53)))
  /* The address to which we tried to bind the socket was busy. */
#define NS_ERROR_SOCKET_ADDRESS_IN_USE  ((nsresult)(FAILURE(54)))

  /* Cache specific error codes: */
#define NS_ERROR_CACHE_KEY_NOT_FOUND         ((nsresult)(FAILURE(61)))
#define NS_ERROR_CACHE_DATA_IS_STREAM        ((nsresult)(FAILURE(62)))
#define NS_ERROR_CACHE_DATA_IS_NOT_STREAM    ((nsresult)(FAILURE(63)))
#define NS_ERROR_CACHE_WAIT_FOR_VALIDATION   ((nsresult)(FAILURE(64)))
#define NS_ERROR_CACHE_ENTRY_DOOMED          ((nsresult)(FAILURE(65)))
#define NS_ERROR_CACHE_READ_ACCESS_DENIED    ((nsresult)(FAILURE(66)))
#define NS_ERROR_CACHE_WRITE_ACCESS_DENIED   ((nsresult)(FAILURE(67)))
#define NS_ERROR_CACHE_IN_USE                ((nsresult)(FAILURE(68)))
  /* Error passed through onStopRequest if the document could not be fetched
   * from the cache. */
#define NS_ERROR_DOCUMENT_NOT_CACHED         ((nsresult)(FAILURE(70)))

  /* Effective TLD Service specific error codes: */

  /* The requested number of domain levels exceeds those present in the host
   * string. */
#define NS_ERROR_INSUFFICIENT_DOMAIN_LEVELS   ((nsresult)(FAILURE(80)))
  /* The host string is an IP address. */
#define NS_ERROR_HOST_IS_IP_ADDRESS           ((nsresult)(FAILURE(81)))


  /* StreamLoader specific result codes: */

  /* Result code returned by nsIStreamLoaderObserver to indicate that the
   * observer is taking over responsibility for the data buffer, and the loader
   * should NOT free it. */
#define NS_SUCCESS_ADOPTED_DATA   ((nsresult)(SUCCESS(90)))

  /* FTP */
#define NS_NET_STATUS_BEGIN_FTP_TRANSACTION   ((nsresult)(SUCCESS(27)))
#define NS_NET_STATUS_END_FTP_TRANSACTION     ((nsresult)(SUCCESS(28)))

  /* This success code may be returned by nsIAuthModule::getNextToken to
   * indicate that the authentication is finished and thus there's no need
   * to call getNextToken again. */
#define NS_SUCCESS_AUTH_FINISHED   ((nsresult)(SUCCESS(40)))

  /* These are really not "results", they're statuses, used by nsITransport and
   * friends.  This is abuse of nsresult, but we'll put up with it for now. */
  /* nsITransport */
#define NS_NET_STATUS_READING   ((nsresult)(FAILURE(8)))
#define NS_NET_STATUS_WRITING   ((nsresult)(FAILURE(9)))

  /* nsISocketTransport */
#define NS_NET_STATUS_RESOLVING_HOST   ((nsresult)(FAILURE(3)))
#define NS_NET_STATUS_RESOLVED_HOST    ((nsresult)(FAILURE(11)))
#define NS_NET_STATUS_CONNECTING_TO    ((nsresult)(FAILURE(7)))
#define NS_NET_STATUS_CONNECTED_TO     ((nsresult)(FAILURE(4)))
#define NS_NET_STATUS_SENDING_TO       ((nsresult)(FAILURE(5)))
#define NS_NET_STATUS_WAITING_FOR      ((nsresult)(FAILURE(10)))
#define NS_NET_STATUS_RECEIVING_FROM   ((nsresult)(FAILURE(6)))
#undef MODULE


  /* ======================================================================= */
  /* 7: NS_ERROR_MODULE_PLUGINS */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_PLUGINS
#define NS_ERROR_PLUGINS_PLUGINSNOTCHANGED         ((nsresult)(FAILURE(1000)))
#define NS_ERROR_PLUGIN_DISABLED                   ((nsresult)(FAILURE(1001)))
#define NS_ERROR_PLUGIN_BLOCKLISTED                ((nsresult)(FAILURE(1002)))
#define NS_ERROR_PLUGIN_TIME_RANGE_NOT_SUPPORTED   ((nsresult)(FAILURE(1003)))
#define NS_ERROR_PLUGIN_CLICKTOPLAY                ((nsresult)(FAILURE(1004)))
#undef MODULE


  /* ======================================================================= */
  /* 8: NS_ERROR_MODULE_LAYOUT */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_LAYOUT
  /* Return code for nsITableLayout */
#define NS_TABLELAYOUT_CELL_NOT_FOUND   ((nsresult)(SUCCESS(0)))
  /* Return code for nsFrame::GetNextPrevLineFromeBlockFrame */
#define NS_POSITION_BEFORE_TABLE        ((nsresult)(SUCCESS(3)))
  /** Return codes for nsPresState::GetProperty() */
  /* Returned if the property exists */
#define NS_STATE_PROPERTY_EXISTS        ((nsresult)(NS_OK))
  /* Returned if the property does not exist */
#define NS_STATE_PROPERTY_NOT_THERE     ((nsresult)(SUCCESS(5)))
#undef MODULE


  /* ======================================================================= */
  /* 9: NS_ERROR_MODULE_HTMLPARSER */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_HTMLPARSER
#define NS_ERROR_HTMLPARSER_CONTINUE   ((nsresult)(NS_OK))

#define NS_ERROR_HTMLPARSER_EOF                         ((nsresult)(FAILURE(1000)))
#define NS_ERROR_HTMLPARSER_UNKNOWN                     ((nsresult)(FAILURE(1001)))
#define NS_ERROR_HTMLPARSER_CANTPROPAGATE               ((nsresult)(FAILURE(1002)))
#define NS_ERROR_HTMLPARSER_CONTEXTMISMATCH             ((nsresult)(FAILURE(1003)))
#define NS_ERROR_HTMLPARSER_BADFILENAME                 ((nsresult)(FAILURE(1004)))
#define NS_ERROR_HTMLPARSER_BADURL                      ((nsresult)(FAILURE(1005)))
#define NS_ERROR_HTMLPARSER_INVALIDPARSERCONTEXT        ((nsresult)(FAILURE(1006)))
#define NS_ERROR_HTMLPARSER_INTERRUPTED                 ((nsresult)(FAILURE(1007)))
#define NS_ERROR_HTMLPARSER_BLOCK                       ((nsresult)(FAILURE(1008)))
#define NS_ERROR_HTMLPARSER_BADTOKENIZER                ((nsresult)(FAILURE(1009)))
#define NS_ERROR_HTMLPARSER_BADATTRIBUTE                ((nsresult)(FAILURE(1010)))
#define NS_ERROR_HTMLPARSER_UNRESOLVEDDTD               ((nsresult)(FAILURE(1011)))
#define NS_ERROR_HTMLPARSER_MISPLACEDTABLECONTENT       ((nsresult)(FAILURE(1012)))
#define NS_ERROR_HTMLPARSER_BADDTD                      ((nsresult)(FAILURE(1013)))
#define NS_ERROR_HTMLPARSER_BADCONTEXT                  ((nsresult)(FAILURE(1014)))
#define NS_ERROR_HTMLPARSER_STOPPARSING                 ((nsresult)(FAILURE(1015)))
#define NS_ERROR_HTMLPARSER_UNTERMINATEDSTRINGLITERAL   ((nsresult)(FAILURE(1016)))
#define NS_ERROR_HTMLPARSER_HIERARCHYTOODEEP            ((nsresult)(FAILURE(1017)))
#define NS_ERROR_HTMLPARSER_FAKE_ENDTAG                 ((nsresult)(FAILURE(1018)))
#define NS_ERROR_HTMLPARSER_INVALID_COMMENT             ((nsresult)(FAILURE(1019)))

#define NS_HTMLTOKENS_NOT_AN_ENTITY        ((nsresult)(SUCCESS(2000)))
#define NS_HTMLPARSER_VALID_META_CHARSET   ((nsresult)(SUCCESS(3000)))
#undef MODULE


  /* ======================================================================= */
  /* 10: NS_ERROR_MODULE_RDF */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_RDF
  /* Returned from nsIRDFDataSource::Assert() and Unassert() if the assertion
   * (or unassertion was accepted by the datasource */
#define NS_RDF_ASSERTION_ACCEPTED   ((nsresult)(NS_OK))
  /* Returned from nsIRDFCursor::Advance() if the cursor has no more
   * elements to enumerate */
#define NS_RDF_CURSOR_EMPTY         ((nsresult)(SUCCESS(1)))
  /* Returned from nsIRDFDataSource::GetSource() and GetTarget() if the
   * source/target has no value */
#define NS_RDF_NO_VALUE             ((nsresult)(SUCCESS(2)))
  /* Returned from nsIRDFDataSource::Assert() and Unassert() if the assertion
   * (or unassertion) was rejected by the datasource; i.e., the datasource was
   * not willing to record the statement. */
#define NS_RDF_ASSERTION_REJECTED   ((nsresult)(SUCCESS(3)))
  /* Return this from rdfITripleVisitor to stop cycling */
#define NS_RDF_STOP_VISIT           ((nsresult)(SUCCESS(4)))
#undef MODULE


  /* ======================================================================= */
  /* 11: NS_ERROR_MODULE_UCONV */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_UCONV
#define NS_ERROR_UCONV_NOCONV        ((nsresult)(FAILURE(1)))
#define NS_ERROR_UDEC_ILLEGALINPUT   ((nsresult)(FAILURE(14)))

#define NS_SUCCESS_USING_FALLBACK_LOCALE   ((nsresult)(SUCCESS(2)))
#define NS_OK_UDEC_EXACTLENGTH             ((nsresult)(SUCCESS(11)))
#define NS_OK_UDEC_MOREINPUT               ((nsresult)(SUCCESS(12)))
#define NS_OK_UDEC_MOREOUTPUT              ((nsresult)(SUCCESS(13)))
#define NS_OK_UDEC_NOBOMFOUND              ((nsresult)(SUCCESS(14)))
#define NS_OK_UENC_EXACTLENGTH             ((nsresult)(SUCCESS(33)))
#define NS_OK_UENC_MOREOUTPUT              ((nsresult)(SUCCESS(34)))
#define NS_ERROR_UENC_NOMAPPING            ((nsresult)(SUCCESS(35)))
#define NS_OK_UENC_MOREINPUT               ((nsresult)(SUCCESS(36)))

  /* BEGIN DEPRECATED */
#define NS_EXACT_LENGTH          ((nsresult)(NS_OK_UDEC_EXACTLENGTH))
#define NS_PARTIAL_MORE_INPUT    ((nsresult)(NS_OK_UDEC_MOREINPUT))
#define NS_PARTIAL_MORE_OUTPUT   ((nsresult)(NS_OK_UDEC_MOREOUTPUT))
#define NS_ERROR_ILLEGAL_INPUT   ((nsresult)(NS_ERROR_UDEC_ILLEGALINPUT))
  /* END DEPRECATED */
#undef MODULE


  /* ======================================================================= */
  /* 13: NS_ERROR_MODULE_FILES */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_FILES
#define NS_ERROR_FILE_UNRECOGNIZED_PATH       ((nsresult)(FAILURE(1)))
#define NS_ERROR_FILE_UNRESOLVABLE_SYMLINK    ((nsresult)(FAILURE(2)))
#define NS_ERROR_FILE_EXECUTION_FAILED        ((nsresult)(FAILURE(3)))
#define NS_ERROR_FILE_UNKNOWN_TYPE            ((nsresult)(FAILURE(4)))
#define NS_ERROR_FILE_DESTINATION_NOT_DIR     ((nsresult)(FAILURE(5)))
#define NS_ERROR_FILE_TARGET_DOES_NOT_EXIST   ((nsresult)(FAILURE(6)))
#define NS_ERROR_FILE_COPY_OR_MOVE_FAILED     ((nsresult)(FAILURE(7)))
#define NS_ERROR_FILE_ALREADY_EXISTS          ((nsresult)(FAILURE(8)))
#define NS_ERROR_FILE_INVALID_PATH            ((nsresult)(FAILURE(9)))
#define NS_ERROR_FILE_DISK_FULL               ((nsresult)(FAILURE(10)))
#define NS_ERROR_FILE_CORRUPTED               ((nsresult)(FAILURE(11)))
#define NS_ERROR_FILE_NOT_DIRECTORY           ((nsresult)(FAILURE(12)))
#define NS_ERROR_FILE_IS_DIRECTORY            ((nsresult)(FAILURE(13)))
#define NS_ERROR_FILE_IS_LOCKED               ((nsresult)(FAILURE(14)))
#define NS_ERROR_FILE_TOO_BIG                 ((nsresult)(FAILURE(15)))
#define NS_ERROR_FILE_NO_DEVICE_SPACE         ((nsresult)(FAILURE(16)))
#define NS_ERROR_FILE_NAME_TOO_LONG           ((nsresult)(FAILURE(17)))
#define NS_ERROR_FILE_NOT_FOUND               ((nsresult)(FAILURE(18)))
#define NS_ERROR_FILE_READ_ONLY               ((nsresult)(FAILURE(19)))
#define NS_ERROR_FILE_DIR_NOT_EMPTY           ((nsresult)(FAILURE(20)))
#define NS_ERROR_FILE_ACCESS_DENIED           ((nsresult)(FAILURE(21)))

#define NS_SUCCESS_FILE_DIRECTORY_EMPTY   ((nsresult)(SUCCESS(1)))
  /* Result codes used by nsIDirectoryServiceProvider2 */
#define NS_SUCCESS_AGGREGATE_RESULT       ((nsresult)(SUCCESS(2)))
#undef MODULE


  /* ======================================================================= */
  /* 14: NS_ERROR_MODULE_DOM */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_DOM
  /* XXX If you add a new DOM error code, also add an error string to
   * dom/base/domerr.msg */

  /* Standard DOM error codes: http://dvcs.w3.org/hg/domcore/raw-file/tip/Overview.html */
#define NS_ERROR_DOM_INDEX_SIZE_ERR                ((nsresult)(FAILURE(1)))
#define NS_ERROR_DOM_HIERARCHY_REQUEST_ERR         ((nsresult)(FAILURE(3)))
#define NS_ERROR_DOM_WRONG_DOCUMENT_ERR            ((nsresult)(FAILURE(4)))
#define NS_ERROR_DOM_INVALID_CHARACTER_ERR         ((nsresult)(FAILURE(5)))
#define NS_ERROR_DOM_NO_MODIFICATION_ALLOWED_ERR   ((nsresult)(FAILURE(7)))
#define NS_ERROR_DOM_NOT_FOUND_ERR                 ((nsresult)(FAILURE(8)))
#define NS_ERROR_DOM_NOT_SUPPORTED_ERR             ((nsresult)(FAILURE(9)))
#define NS_ERROR_DOM_INUSE_ATTRIBUTE_ERR           ((nsresult)(FAILURE(10)))
#define NS_ERROR_DOM_INVALID_STATE_ERR             ((nsresult)(FAILURE(11)))
#define NS_ERROR_DOM_SYNTAX_ERR                    ((nsresult)(FAILURE(12)))
#define NS_ERROR_DOM_INVALID_MODIFICATION_ERR      ((nsresult)(FAILURE(13)))
#define NS_ERROR_DOM_NAMESPACE_ERR                 ((nsresult)(FAILURE(14)))
#define NS_ERROR_DOM_INVALID_ACCESS_ERR            ((nsresult)(FAILURE(15)))
#define NS_ERROR_DOM_TYPE_MISMATCH_ERR             ((nsresult)(FAILURE(17)))
#define NS_ERROR_DOM_SECURITY_ERR                  ((nsresult)(FAILURE(18)))
#define NS_ERROR_DOM_NETWORK_ERR                   ((nsresult)(FAILURE(19)))
#define NS_ERROR_DOM_ABORT_ERR                     ((nsresult)(FAILURE(20)))
#define NS_ERROR_DOM_URL_MISMATCH_ERR              ((nsresult)(FAILURE(21)))
#define NS_ERROR_DOM_QUOTA_EXCEEDED_ERR            ((nsresult)(FAILURE(22)))
#define NS_ERROR_DOM_TIMEOUT_ERR                   ((nsresult)(FAILURE(23)))
#define NS_ERROR_DOM_INVALID_NODE_TYPE_ERR         ((nsresult)(FAILURE(24)))
#define NS_ERROR_DOM_DATA_CLONE_ERR                ((nsresult)(FAILURE(25)))
  /* XXX Should be JavaScript native errors */
#define NS_ERROR_TYPE_ERR                          ((nsresult)(FAILURE(26)))
#define NS_ERROR_RANGE_ERR                         ((nsresult)(FAILURE(27)))
  /* StringEncoding API errors from http://wiki.whatwg.org/wiki/StringEncoding */
#define NS_ERROR_DOM_ENCODING_NOT_SUPPORTED_ERR    ((nsresult)(FAILURE(28)))
#define NS_ERROR_DOM_ENCODING_NOT_UTF_ERR          ((nsresult)(FAILURE(29)))
#define NS_ERROR_DOM_ENCODING_DECODE_ERR           ((nsresult)(FAILURE(30)))
  /* DOM error codes defined by us */
#define NS_ERROR_DOM_SECMAN_ERR                    ((nsresult)(FAILURE(1001)))
#define NS_ERROR_DOM_WRONG_TYPE_ERR                ((nsresult)(FAILURE(1002)))
#define NS_ERROR_DOM_NOT_OBJECT_ERR                ((nsresult)(FAILURE(1003)))
#define NS_ERROR_DOM_NOT_XPC_OBJECT_ERR            ((nsresult)(FAILURE(1004)))
#define NS_ERROR_DOM_NOT_NUMBER_ERR                ((nsresult)(FAILURE(1005)))
#define NS_ERROR_DOM_NOT_BOOLEAN_ERR               ((nsresult)(FAILURE(1006)))
#define NS_ERROR_DOM_NOT_FUNCTION_ERR              ((nsresult)(FAILURE(1007)))
#define NS_ERROR_DOM_TOO_FEW_PARAMETERS_ERR        ((nsresult)(FAILURE(1008)))
#define NS_ERROR_DOM_BAD_DOCUMENT_DOMAIN           ((nsresult)(FAILURE(1009)))
#define NS_ERROR_DOM_PROP_ACCESS_DENIED            ((nsresult)(FAILURE(1010)))
#define NS_ERROR_DOM_XPCONNECT_ACCESS_DENIED       ((nsresult)(FAILURE(1011)))
#define NS_ERROR_DOM_BAD_URI                       ((nsresult)(FAILURE(1012)))
#define NS_ERROR_DOM_RETVAL_UNDEFINED              ((nsresult)(FAILURE(1013)))
#define NS_ERROR_DOM_QUOTA_REACHED                 ((nsresult)(FAILURE(1014)))
#define NS_ERROR_DOM_JS_EXCEPTION                  ((nsresult)(FAILURE(1015)))

  /* May be used to indicate when e.g. setting a property value didn't
   * actually change the value, like for obj.foo = "bar"; obj.foo = "bar";
   * the second assignment throws NS_SUCCESS_DOM_NO_OPERATION.
   */
#define NS_SUCCESS_DOM_NO_OPERATION                ((nsresult)(SUCCESS(1)))
#undef MODULE


  /* ======================================================================= */
  /* 15: NS_ERROR_MODULE_IMGLIB */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_IMGLIB
#define NS_IMAGELIB_SUCCESS_LOAD_FINISHED   ((nsresult)(SUCCESS(0)))
#define NS_IMAGELIB_CHANGING_OWNER          ((nsresult)(SUCCESS(1)))

#define NS_IMAGELIB_ERROR_FAILURE        ((nsresult)(FAILURE(5)))
#define NS_IMAGELIB_ERROR_NO_DECODER     ((nsresult)(FAILURE(6)))
#define NS_IMAGELIB_ERROR_NOT_FINISHED   ((nsresult)(FAILURE(7)))
#define NS_IMAGELIB_ERROR_NO_ENCODER     ((nsresult)(FAILURE(9)))
#undef MODULE


  /* ======================================================================= */
  /* 17: NS_ERROR_MODULE_EDITOR */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_EDITOR
#define NS_ERROR_EDITOR_NO_SELECTION   ((nsresult)(FAILURE(1)))
#define NS_ERROR_EDITOR_NO_TEXTNODE    ((nsresult)(FAILURE(2)))
#define NS_FOUND_TARGET                ((nsresult)(FAILURE(3)))

#define NS_EDITOR_ELEMENT_NOT_FOUND    ((nsresult)(SUCCESS(1)))
#undef MODULE


  /* ======================================================================= */
  /* 18: NS_ERROR_MODULE_XPCONNECT */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_XPCONNECT
#define NS_ERROR_XPC_NOT_ENOUGH_ARGS                   ((nsresult)(FAILURE(1)))
#define NS_ERROR_XPC_NEED_OUT_OBJECT                   ((nsresult)(FAILURE(2)))
#define NS_ERROR_XPC_CANT_SET_OUT_VAL                  ((nsresult)(FAILURE(3)))
#define NS_ERROR_XPC_NATIVE_RETURNED_FAILURE           ((nsresult)(FAILURE(4)))
#define NS_ERROR_XPC_CANT_GET_INTERFACE_INFO           ((nsresult)(FAILURE(5)))
#define NS_ERROR_XPC_CANT_GET_PARAM_IFACE_INFO         ((nsresult)(FAILURE(6)))
#define NS_ERROR_XPC_CANT_GET_METHOD_INFO              ((nsresult)(FAILURE(7)))
#define NS_ERROR_XPC_UNEXPECTED                        ((nsresult)(FAILURE(8)))
#define NS_ERROR_XPC_BAD_CONVERT_JS                    ((nsresult)(FAILURE(9)))
#define NS_ERROR_XPC_BAD_CONVERT_NATIVE                ((nsresult)(FAILURE(10)))
#define NS_ERROR_XPC_BAD_CONVERT_JS_NULL_REF           ((nsresult)(FAILURE(11)))
#define NS_ERROR_XPC_BAD_OP_ON_WN_PROTO                ((nsresult)(FAILURE(12)))
#define NS_ERROR_XPC_CANT_CONVERT_WN_TO_FUN            ((nsresult)(FAILURE(13)))
#define NS_ERROR_XPC_CANT_DEFINE_PROP_ON_WN            ((nsresult)(FAILURE(14)))
#define NS_ERROR_XPC_CANT_WATCH_WN_STATIC              ((nsresult)(FAILURE(15)))
#define NS_ERROR_XPC_CANT_EXPORT_WN_STATIC             ((nsresult)(FAILURE(16)))
#define NS_ERROR_XPC_SCRIPTABLE_CALL_FAILED            ((nsresult)(FAILURE(17)))
#define NS_ERROR_XPC_SCRIPTABLE_CTOR_FAILED            ((nsresult)(FAILURE(18)))
#define NS_ERROR_XPC_CANT_CALL_WO_SCRIPTABLE           ((nsresult)(FAILURE(19)))
#define NS_ERROR_XPC_CANT_CTOR_WO_SCRIPTABLE           ((nsresult)(FAILURE(20)))
#define NS_ERROR_XPC_CI_RETURNED_FAILURE               ((nsresult)(FAILURE(21)))
#define NS_ERROR_XPC_GS_RETURNED_FAILURE               ((nsresult)(FAILURE(22)))
#define NS_ERROR_XPC_BAD_CID                           ((nsresult)(FAILURE(23)))
#define NS_ERROR_XPC_BAD_IID                           ((nsresult)(FAILURE(24)))
#define NS_ERROR_XPC_CANT_CREATE_WN                    ((nsresult)(FAILURE(25)))
#define NS_ERROR_XPC_JS_THREW_EXCEPTION                ((nsresult)(FAILURE(26)))
#define NS_ERROR_XPC_JS_THREW_NATIVE_OBJECT            ((nsresult)(FAILURE(27)))
#define NS_ERROR_XPC_JS_THREW_JS_OBJECT                ((nsresult)(FAILURE(28)))
#define NS_ERROR_XPC_JS_THREW_NULL                     ((nsresult)(FAILURE(29)))
#define NS_ERROR_XPC_JS_THREW_STRING                   ((nsresult)(FAILURE(30)))
#define NS_ERROR_XPC_JS_THREW_NUMBER                   ((nsresult)(FAILURE(31)))
#define NS_ERROR_XPC_JAVASCRIPT_ERROR                  ((nsresult)(FAILURE(32)))
#define NS_ERROR_XPC_JAVASCRIPT_ERROR_WITH_DETAILS     ((nsresult)(FAILURE(33)))
#define NS_ERROR_XPC_CANT_CONVERT_PRIMITIVE_TO_ARRAY   ((nsresult)(FAILURE(34)))
#define NS_ERROR_XPC_CANT_CONVERT_OBJECT_TO_ARRAY      ((nsresult)(FAILURE(35)))
#define NS_ERROR_XPC_NOT_ENOUGH_ELEMENTS_IN_ARRAY      ((nsresult)(FAILURE(36)))
#define NS_ERROR_XPC_CANT_GET_ARRAY_INFO               ((nsresult)(FAILURE(37)))
#define NS_ERROR_XPC_NOT_ENOUGH_CHARS_IN_STRING        ((nsresult)(FAILURE(38)))
#define NS_ERROR_XPC_SECURITY_MANAGER_VETO             ((nsresult)(FAILURE(39)))
#define NS_ERROR_XPC_INTERFACE_NOT_SCRIPTABLE          ((nsresult)(FAILURE(40)))
#define NS_ERROR_XPC_INTERFACE_NOT_FROM_NSISUPPORTS    ((nsresult)(FAILURE(41)))
#define NS_ERROR_XPC_CANT_GET_JSOBJECT_OF_DOM_OBJECT   ((nsresult)(FAILURE(42)))
#define NS_ERROR_XPC_CANT_SET_READ_ONLY_CONSTANT       ((nsresult)(FAILURE(43)))
#define NS_ERROR_XPC_CANT_SET_READ_ONLY_ATTRIBUTE      ((nsresult)(FAILURE(44)))
#define NS_ERROR_XPC_CANT_SET_READ_ONLY_METHOD         ((nsresult)(FAILURE(45)))
#define NS_ERROR_XPC_CANT_ADD_PROP_TO_WRAPPED_NATIVE   ((nsresult)(FAILURE(46)))
#define NS_ERROR_XPC_CALL_TO_SCRIPTABLE_FAILED         ((nsresult)(FAILURE(47)))
#define NS_ERROR_XPC_JSOBJECT_HAS_NO_FUNCTION_NAMED    ((nsresult)(FAILURE(48)))
#define NS_ERROR_XPC_BAD_ID_STRING                     ((nsresult)(FAILURE(49)))
#define NS_ERROR_XPC_BAD_INITIALIZER_NAME              ((nsresult)(FAILURE(50)))
#define NS_ERROR_XPC_HAS_BEEN_SHUTDOWN                 ((nsresult)(FAILURE(51)))
#define NS_ERROR_XPC_CANT_MODIFY_PROP_ON_WN            ((nsresult)(FAILURE(52)))
#define NS_ERROR_XPC_BAD_CONVERT_JS_ZERO_ISNOT_NULL    ((nsresult)(FAILURE(53)))
#define NS_ERROR_XPC_CANT_PASS_CPOW_TO_NATIVE          ((nsresult)(FAILURE(54)))
  /* any new errors here should have an associated entry added in xpc.msg */

#define NS_SUCCESS_I_DID_SOMETHING       ((nsresult)(SUCCESS(1)))
#undef MODULE


  /* ======================================================================= */
  /* 19: NS_ERROR_MODULE_PROFILE */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_PROFILE
#define NS_ERROR_LAUNCHED_CHILD_PROCESS   ((nsresult)(FAILURE(200)))
#undef MODULE


  /* ======================================================================= */
  /* 21: NS_ERROR_MODULE_SECURITY */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_SECURITY
  /* Error code for CSP */
#define NS_ERROR_CSP_FRAME_ANCESTOR_VIOLATION      ((nsresult)(FAILURE(99)))

  /* CMS specific nsresult error codes.  Note: the numbers used here correspond
   * to the values in nsICMSMessageErrors.idl. */
#define NS_ERROR_CMS_VERIFY_NOT_SIGNED             ((nsresult)(FAILURE(1024)))
#define NS_ERROR_CMS_VERIFY_NO_CONTENT_INFO        ((nsresult)(FAILURE(1025)))
#define NS_ERROR_CMS_VERIFY_BAD_DIGEST             ((nsresult)(FAILURE(1026)))
#define NS_ERROR_CMS_VERIFY_NOCERT                 ((nsresult)(FAILURE(1028)))
#define NS_ERROR_CMS_VERIFY_UNTRUSTED              ((nsresult)(FAILURE(1029)))
#define NS_ERROR_CMS_VERIFY_ERROR_UNVERIFIED       ((nsresult)(FAILURE(1031)))
#define NS_ERROR_CMS_VERIFY_ERROR_PROCESSING       ((nsresult)(FAILURE(1032)))
#define NS_ERROR_CMS_VERIFY_BAD_SIGNATURE          ((nsresult)(FAILURE(1033)))
#define NS_ERROR_CMS_VERIFY_DIGEST_MISMATCH        ((nsresult)(FAILURE(1034)))
#define NS_ERROR_CMS_VERIFY_UNKNOWN_ALGO           ((nsresult)(FAILURE(1035)))
#define NS_ERROR_CMS_VERIFY_UNSUPPORTED_ALGO       ((nsresult)(FAILURE(1036)))
#define NS_ERROR_CMS_VERIFY_MALFORMED_SIGNATURE    ((nsresult)(FAILURE(1037)))
#define NS_ERROR_CMS_VERIFY_HEADER_MISMATCH        ((nsresult)(FAILURE(1038)))
#define NS_ERROR_CMS_VERIFY_NOT_YET_ATTEMPTED      ((nsresult)(FAILURE(1039)))
#define NS_ERROR_CMS_VERIFY_CERT_WITHOUT_ADDRESS   ((nsresult)(FAILURE(1040)))
#define NS_ERROR_CMS_ENCRYPT_NO_BULK_ALG           ((nsresult)(FAILURE(1056)))
#define NS_ERROR_CMS_ENCRYPT_INCOMPLETE            ((nsresult)(FAILURE(1057)))
#undef MODULE


  /* ======================================================================= */
  /* 22: NS_ERROR_MODULE_DOM_XPATH */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_DOM_XPATH
  /* DOM error codes from http://www.w3.org/TR/DOM-Level-3-XPath/ */
#define NS_ERROR_DOM_INVALID_EXPRESSION_ERR   ((nsresult)(FAILURE(51)))
#define NS_ERROR_DOM_TYPE_ERR                 ((nsresult)(FAILURE(52)))
#undef MODULE


  /* ======================================================================= */
  /* 24: NS_ERROR_MODULE_URILOADER */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_URILOADER
#define NS_ERROR_WONT_HANDLE_CONTENT    ((nsresult)(FAILURE(1)))
  /* The load has been cancelled because it was found on a malware or phishing
   * blacklist. */
#define NS_ERROR_MALWARE_URI            ((nsresult)(FAILURE(30)))
#define NS_ERROR_PHISHING_URI           ((nsresult)(FAILURE(31)))
  /* Used when "Save Link As..." doesn't see the headers quickly enough to
   * choose a filename.  See nsContextMenu.js. */
#define NS_ERROR_SAVE_LINK_AS_TIMEOUT   ((nsresult)(FAILURE(32)))
  /* Used when the data from a channel has already been parsed and cached so it
   * doesn't need to be reparsed from the original source. */
#define NS_ERROR_PARSED_DATA_CACHED     ((nsresult)(FAILURE(33)))

  /* This success code indicates that a refresh header was found and
   * successfully setup.  */
#define NS_REFRESHURI_HEADER_FOUND   ((nsresult)(SUCCESS(2)))
#undef MODULE


  /* ======================================================================= */
  /* 25: NS_ERROR_MODULE_CONTENT */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_CONTENT
  /* Error codes for image loading */
#define NS_ERROR_IMAGE_SRC_CHANGED              ((nsresult)(FAILURE(4)))
#define NS_ERROR_IMAGE_BLOCKED                  ((nsresult)(FAILURE(5)))
  /* Error codes for content policy blocking */
#define NS_ERROR_CONTENT_BLOCKED                ((nsresult)(FAILURE(6)))
#define NS_ERROR_CONTENT_BLOCKED_SHOW_ALT       ((nsresult)(FAILURE(7)))
  /* Success variations of content policy blocking */
#define NS_PROPTABLE_PROP_NOT_THERE             ((nsresult)(FAILURE(10)))
  /* Error code for XBL */
#define NS_ERROR_XBL_BLOCKED                    ((nsresult)(FAILURE(15)))
  /* Error code for when the content process crashed */
#define NS_ERROR_CONTENT_CRASHED                ((nsresult)(FAILURE(16)))

  /* XXX this is not really used */
#define NS_HTML_STYLE_PROPERTY_NOT_THERE    ((nsresult)(SUCCESS(2)))
#define NS_CONTENT_BLOCKED                  ((nsresult)(SUCCESS(8)))
#define NS_CONTENT_BLOCKED_SHOW_ALT         ((nsresult)(SUCCESS(9)))
#define NS_PROPTABLE_PROP_OVERWRITTEN       ((nsresult)(SUCCESS(11)))
  /* Error codes for FindBroadcaster in XULDocument.cpp */
#define NS_FINDBROADCASTER_NOT_FOUND        ((nsresult)(SUCCESS(12)))
#define NS_FINDBROADCASTER_FOUND            ((nsresult)(SUCCESS(13)))
#define NS_FINDBROADCASTER_AWAIT_OVERLAYS   ((nsresult)(SUCCESS(14)))
#undef MODULE


  /* ======================================================================= */
  /* 27: NS_ERROR_MODULE_XSLT */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_XSLT
#define NS_ERROR_XPATH_INVALID_ARG   ((nsresult)(NS_ERROR_INVALID_ARG))

#define NS_ERROR_XSLT_PARSE_FAILURE                   ((nsresult)(FAILURE(1)))
#define NS_ERROR_XPATH_PARSE_FAILURE                  ((nsresult)(FAILURE(2)))
#define NS_ERROR_XSLT_ALREADY_SET                     ((nsresult)(FAILURE(3)))
#define NS_ERROR_XSLT_EXECUTION_FAILURE               ((nsresult)(FAILURE(4)))
#define NS_ERROR_XPATH_UNKNOWN_FUNCTION               ((nsresult)(FAILURE(5)))
#define NS_ERROR_XSLT_BAD_RECURSION                   ((nsresult)(FAILURE(6)))
#define NS_ERROR_XSLT_BAD_VALUE                       ((nsresult)(FAILURE(7)))
#define NS_ERROR_XSLT_NODESET_EXPECTED                ((nsresult)(FAILURE(8)))
#define NS_ERROR_XSLT_ABORTED                         ((nsresult)(FAILURE(9)))
#define NS_ERROR_XSLT_NETWORK_ERROR                   ((nsresult)(FAILURE(10)))
#define NS_ERROR_XSLT_WRONG_MIME_TYPE                 ((nsresult)(FAILURE(11)))
#define NS_ERROR_XSLT_LOAD_RECURSION                  ((nsresult)(FAILURE(12)))
#define NS_ERROR_XPATH_BAD_ARGUMENT_COUNT             ((nsresult)(FAILURE(13)))
#define NS_ERROR_XPATH_BAD_EXTENSION_FUNCTION         ((nsresult)(FAILURE(14)))
#define NS_ERROR_XPATH_PAREN_EXPECTED                 ((nsresult)(FAILURE(15)))
#define NS_ERROR_XPATH_INVALID_AXIS                   ((nsresult)(FAILURE(16)))
#define NS_ERROR_XPATH_NO_NODE_TYPE_TEST              ((nsresult)(FAILURE(17)))
#define NS_ERROR_XPATH_BRACKET_EXPECTED               ((nsresult)(FAILURE(18)))
#define NS_ERROR_XPATH_INVALID_VAR_NAME               ((nsresult)(FAILURE(19)))
#define NS_ERROR_XPATH_UNEXPECTED_END                 ((nsresult)(FAILURE(20)))
#define NS_ERROR_XPATH_OPERATOR_EXPECTED              ((nsresult)(FAILURE(21)))
#define NS_ERROR_XPATH_UNCLOSED_LITERAL               ((nsresult)(FAILURE(22)))
#define NS_ERROR_XPATH_BAD_COLON                      ((nsresult)(FAILURE(23)))
#define NS_ERROR_XPATH_BAD_BANG                       ((nsresult)(FAILURE(24)))
#define NS_ERROR_XPATH_ILLEGAL_CHAR                   ((nsresult)(FAILURE(25)))
#define NS_ERROR_XPATH_BINARY_EXPECTED                ((nsresult)(FAILURE(26)))
#define NS_ERROR_XSLT_LOAD_BLOCKED_ERROR              ((nsresult)(FAILURE(27)))
#define NS_ERROR_XPATH_INVALID_EXPRESSION_EVALUATED   ((nsresult)(FAILURE(28)))
#define NS_ERROR_XPATH_UNBALANCED_CURLY_BRACE         ((nsresult)(FAILURE(29)))
#define NS_ERROR_XSLT_BAD_NODE_NAME                   ((nsresult)(FAILURE(30)))
#define NS_ERROR_XSLT_VAR_ALREADY_SET                 ((nsresult)(FAILURE(31)))

#define NS_XSLT_GET_NEW_HANDLER   ((nsresult)(SUCCESS(1)))
#undef MODULE


  /* ======================================================================= */
  /* 29: NS_ERROR_MODULE_SVG */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_SVG
  /* SVG DOM error codes from http://www.w3.org/TR/SVG11/svgdom.html */
#define NS_ERROR_DOM_SVG_WRONG_TYPE_ERR          ((nsresult)(FAILURE(0)))
  /* Yes, the spec says "INVERTABLE", not "INVERTIBLE" */
#define NS_ERROR_DOM_SVG_MATRIX_NOT_INVERTABLE   ((nsresult)(FAILURE(2)))
#undef MODULE


  /* ======================================================================= */
  /* 30: NS_ERROR_MODULE_STORAGE */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_STORAGE
  /* To add additional errors to Storage, please append entries to the bottom
   * of the list in the following format:
   *   NS_ERROR_STORAGE_YOUR_ERR,  FAILURE(n)
   * where n is the next unique positive integer.  You must also add an entry
   * to js/xpconnect/src/xpc.msg under the code block beginning with the
   * comment 'storage related codes (from mozStorage.h)', in the following
   * format: 'XPC_MSG_DEF(NS_ERROR_STORAGE_YOUR_ERR, "brief description of your
   * error")' */
#define NS_ERROR_STORAGE_BUSY         ((nsresult)(FAILURE(1)))
#define NS_ERROR_STORAGE_IOERR        ((nsresult)(FAILURE(2)))
#define NS_ERROR_STORAGE_CONSTRAINT   ((nsresult)(FAILURE(3)))
#undef MODULE


  /* ======================================================================= */
  /* 32: NS_ERROR_MODULE_DOM_FILE */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_DOM_FILE
#define NS_ERROR_DOM_FILE_NOT_FOUND_ERR      ((nsresult)(FAILURE(0)))
#define NS_ERROR_DOM_FILE_NOT_READABLE_ERR   ((nsresult)(FAILURE(1)))
#define NS_ERROR_DOM_FILE_ABORT_ERR          ((nsresult)(FAILURE(2)))
#undef MODULE


  /* ======================================================================= */
  /* 33: NS_ERROR_MODULE_DOM_INDEXEDDB */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_DOM_INDEXEDDB
  /* IndexedDB error codes http://dvcs.w3.org/hg/IndexedDB/raw-file/tip/Overview.html */
#define NS_ERROR_DOM_INDEXEDDB_UNKNOWN_ERR                ((nsresult)(FAILURE(1)))
#define NS_ERROR_DOM_INDEXEDDB_NOT_FOUND_ERR              ((nsresult)(FAILURE(3)))
#define NS_ERROR_DOM_INDEXEDDB_CONSTRAINT_ERR             ((nsresult)(FAILURE(4)))
#define NS_ERROR_DOM_INDEXEDDB_DATA_ERR                   ((nsresult)(FAILURE(5)))
#define NS_ERROR_DOM_INDEXEDDB_NOT_ALLOWED_ERR            ((nsresult)(FAILURE(6)))
#define NS_ERROR_DOM_INDEXEDDB_TRANSACTION_INACTIVE_ERR   ((nsresult)(FAILURE(7)))
#define NS_ERROR_DOM_INDEXEDDB_ABORT_ERR                  ((nsresult)(FAILURE(8)))
#define NS_ERROR_DOM_INDEXEDDB_READ_ONLY_ERR              ((nsresult)(FAILURE(9)))
#define NS_ERROR_DOM_INDEXEDDB_TIMEOUT_ERR                ((nsresult)(FAILURE(10)))
#define NS_ERROR_DOM_INDEXEDDB_QUOTA_ERR                  ((nsresult)(FAILURE(11)))
#define NS_ERROR_DOM_INDEXEDDB_VERSION_ERR                ((nsresult)(FAILURE(12)))
#define NS_ERROR_DOM_INDEXEDDB_RECOVERABLE_ERR            ((nsresult)(FAILURE(1001)))
#undef MODULE


  /* ======================================================================= */
  /* 34: NS_ERROR_MODULE_DOM_FILEHANDLE */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_DOM_FILEHANDLE
#define NS_ERROR_DOM_FILEHANDLE_UNKNOWN_ERR               ((nsresult)(FAILURE(1)))
#define NS_ERROR_DOM_FILEHANDLE_NOT_ALLOWED_ERR           ((nsresult)(FAILURE(2)))
#define NS_ERROR_DOM_FILEHANDLE_LOCKEDFILE_INACTIVE_ERR   ((nsresult)(FAILURE(3)))
#define NS_ERROR_DOM_FILEHANDLE_ABORT_ERR                 ((nsresult)(FAILURE(4)))
#define NS_ERROR_DOM_FILEHANDLE_READ_ONLY_ERR             ((nsresult)(FAILURE(5)))
#undef MODULE

  /* ======================================================================= */
  /* 35: NS_ERROR_MODULE_SIGNED_JAR */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_SIGNED_JAR
#define NS_ERROR_SIGNED_JAR_NOT_SIGNED                    ((nsresult)(FAILURE(1)))
#define NS_ERROR_SIGNED_JAR_MODIFIED_ENTRY                ((nsresult)(FAILURE(2)))
#define NS_ERROR_SIGNED_JAR_UNSIGNED_ENTRY                ((nsresult)(FAILURE(3)))
#define NS_ERROR_SIGNED_JAR_ENTRY_MISSING                 ((nsresult)(FAILURE(4)))
#define NS_ERROR_SIGNED_JAR_WRONG_SIGNATURE               ((nsresult)(FAILURE(5)))
#define NS_ERROR_SIGNED_JAR_ENTRY_TOO_LARGE               ((nsresult)(FAILURE(6)))
#define NS_ERROR_SIGNED_JAR_ENTRY_INVALID                 ((nsresult)(FAILURE(7)))
#define NS_ERROR_SIGNED_JAR_MANIFEST_INVALID              ((nsresult)(FAILURE(8)))
#undef MODULE

  /* ======================================================================= */
  /* 36: NS_ERROR_MODULE_DOM_FILESYSTEM */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_DOM_FILESYSTEM
#define NS_ERROR_DOM_FILESYSTEM_INVALID_PATH_ERR           ((nsresult)(FAILURE(1)))
#define NS_ERROR_DOM_FILESYSTEM_INVALID_MODIFICATION_ERR   ((nsresult)(FAILURE(2)))
#define NS_ERROR_DOM_FILESYSTEM_NO_MODIFICATION_ALLOWED_ERR  ((nsresult)(FAILURE(3)))
#define NS_ERROR_DOM_FILESYSTEM_PATH_EXISTS_ERR            ((nsresult)(FAILURE(4)))
#define NS_ERROR_DOM_FILESYSTEM_TYPE_MISMATCH_ERR          ((nsresult)(FAILURE(5)))
#define NS_ERROR_DOM_FILESYSTEM_UNKNOWN_ERR                ((nsresult)(FAILURE(6)))
#undef MODULE

  /* ======================================================================= */
  /* 51: NS_ERROR_MODULE_GENERAL */
  /* ======================================================================= */
#define MODULE NS_ERROR_MODULE_GENERAL
  /* Error code used internally by the incremental downloader to cancel the
   * network channel when the download is already complete. */
#define NS_ERROR_DOWNLOAD_COMPLETE       ((nsresult)(FAILURE(1)))
  /* Error code used internally by the incremental downloader to cancel the
   * network channel when the response to a range request is 200 instead of
   * 206. */
#define NS_ERROR_DOWNLOAD_NOT_PARTIAL    ((nsresult)(FAILURE(2)))
#define NS_ERROR_UNORM_MOREOUTPUT        ((nsresult)(FAILURE(33)))

#define NS_ERROR_DOCSHELL_REQUEST_REJECTED   ((nsresult)(FAILURE(1001)))
  /* This is needed for displaying an error message when navigation is
   * attempted on a document when printing The value arbitrary as long as it
   * doesn't conflict with any of the other values in the errors in
   * DisplayLoadError */
#define NS_ERROR_DOCUMENT_IS_PRINTMODE   ((nsresult)(FAILURE(2001)))

#define NS_SUCCESS_DONT_FIXUP            ((nsresult)(SUCCESS(1)))
  /* This success code may be returned by nsIAppStartup::Run to indicate that
   * the application should be restarted.  This condition corresponds to the
   * case in which nsIAppStartup::Quit was called with the eRestart flag. */
#define NS_SUCCESS_RESTART_APP           ((nsresult)(SUCCESS(1)))
#define NS_SUCCESS_RESTART_METRO_APP     ((nsresult)(SUCCESS(2)))
#define NS_SUCCESS_UNORM_NOTFOUND   ((nsresult)(SUCCESS(17)))


  /* a11y */
  /* raised when current pivot's position is needed but it's not in the tree */
#define NS_ERROR_NOT_IN_TREE   ((nsresult)(FAILURE(38)))

  /* see nsTextEquivUtils */
#define NS_OK_NO_NAME_CLAUSE_HANDLED   ((nsresult)(SUCCESS(34)))
#undef MODULE
