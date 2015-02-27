/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXPConnect.idl
 */

#ifndef __gen_nsIXPConnect_h__
#define __gen_nsIXPConnect_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"
#include "js/TypeDecls.h"
struct JSFreeOp;
class nsWrapperCache;
class nsAXPCNativeCallContext;
class nsIXPCScriptable; /* forward declaration */

class nsIXPConnect; /* forward declaration */

class nsIXPConnectWrappedNative; /* forward declaration */

class nsIInterfaceInfo; /* forward declaration */

class nsIXPCSecurityManager; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIClassInfo; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIStackFrame; /* forward declaration */

class nsIObjectInputStream; /* forward declaration */

class nsIObjectOutputStream; /* forward declaration */


/* starting interface:    nsIXPConnectJSObjectHolder */
#define NS_IXPCONNECTJSOBJECTHOLDER_IID_STR "909e8641-7c54-4dff-9b94-ba631f057b33"

#define NS_IXPCONNECTJSOBJECTHOLDER_IID \
  {0x909e8641, 0x7c54, 0x4dff, \
    { 0x9b, 0x94, 0xba, 0x63, 0x1f, 0x05, 0x7b, 0x33 }}

class NS_NO_VTABLE nsIXPConnectJSObjectHolder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTJSOBJECTHOLDER_IID)

  /* [nostdcall,notxpcom] JSObjectPtr GetJSObject (); */
  virtual JSObject * GetJSObject(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectJSObjectHolder, NS_IXPCONNECTJSOBJECTHOLDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTJSOBJECTHOLDER \
  virtual JSObject * GetJSObject(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTJSOBJECTHOLDER(_to) \
  virtual JSObject * GetJSObject(void) { return _to GetJSObject(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTJSOBJECTHOLDER(_to) \
  virtual JSObject * GetJSObject(void); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectJSObjectHolder : public nsIXPConnectJSObjectHolder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTJSOBJECTHOLDER

  nsXPConnectJSObjectHolder();

private:
  ~nsXPConnectJSObjectHolder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPConnectJSObjectHolder, nsIXPConnectJSObjectHolder)

nsXPConnectJSObjectHolder::nsXPConnectJSObjectHolder()
{
  /* member initializers and constructor code */
}

nsXPConnectJSObjectHolder::~nsXPConnectJSObjectHolder()
{
  /* destructor code */
}

/* [nostdcall,notxpcom] JSObjectPtr GetJSObject (); */
JSObject * nsXPConnectJSObjectHolder::GetJSObject()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPConnectWrappedNative */
#define NS_IXPCONNECTWRAPPEDNATIVE_IID_STR "675b01ba-397b-472a-9b80-5716376a2ec6"

#define NS_IXPCONNECTWRAPPEDNATIVE_IID \
  {0x675b01ba, 0x397b, 0x472a, \
    { 0x9b, 0x80, 0x57, 0x16, 0x37, 0x6a, 0x2e, 0xc6 }}

class nsIXPConnectWrappedNative : public nsIXPConnectJSObjectHolder {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTWRAPPEDNATIVE_IID)

  /* readonly attribute nsISupports Native; */
  NS_IMETHOD GetNative(nsISupports * *aNative) = 0;

  /* readonly attribute JSObjectPtr JSObjectPrototype; */
  NS_IMETHOD GetJSObjectPrototype(JSObject **aJSObjectPrototype) = 0;

  /* nsIInterfaceInfo FindInterfaceWithMember (in JSHandleId nameID); */
  NS_IMETHOD FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) = 0;

  /* nsIInterfaceInfo FindInterfaceWithName (in JSHandleId nameID); */
  NS_IMETHOD FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) = 0;

  /* [notxpcom] bool HasNativeMember (in JSHandleId name); */
  NS_IMETHOD_(bool) HasNativeMember(JS::Handle<jsid> name) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(int16_t depth) = 0;

  /* void finishInitForWrappedGlobal (); */
  NS_IMETHOD FinishInitForWrappedGlobal(void) = 0;

     /**
     * Faster access to the native object from C++.  Will never return null.
     */
    nsISupports* Native() const { return mIdentity; }
protected:
    nsISupports *mIdentity;
public:
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectWrappedNative, NS_IXPCONNECTWRAPPEDNATIVE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTWRAPPEDNATIVE \
  NS_IMETHOD GetNative(nsISupports * *aNative); \
  NS_IMETHOD GetJSObjectPrototype(JSObject **aJSObjectPrototype); \
  NS_IMETHOD FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval); \
  NS_IMETHOD FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval); \
  NS_IMETHOD_(bool) HasNativeMember(JS::Handle<jsid> name); \
  NS_IMETHOD DebugDump(int16_t depth); \
  NS_IMETHOD FinishInitForWrappedGlobal(void); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTWRAPPEDNATIVE(_to) \
  NS_IMETHOD GetNative(nsISupports * *aNative) { return _to GetNative(aNative); } \
  NS_IMETHOD GetJSObjectPrototype(JSObject **aJSObjectPrototype) { return _to GetJSObjectPrototype(aJSObjectPrototype); } \
  NS_IMETHOD FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) { return _to FindInterfaceWithMember(nameID, _retval); } \
  NS_IMETHOD FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) { return _to FindInterfaceWithName(nameID, _retval); } \
  NS_IMETHOD_(bool) HasNativeMember(JS::Handle<jsid> name) { return _to HasNativeMember(name); } \
  NS_IMETHOD DebugDump(int16_t depth) { return _to DebugDump(depth); } \
  NS_IMETHOD FinishInitForWrappedGlobal(void) { return _to FinishInitForWrappedGlobal(); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTWRAPPEDNATIVE(_to) \
  NS_IMETHOD GetNative(nsISupports * *aNative) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNative(aNative); } \
  NS_IMETHOD GetJSObjectPrototype(JSObject **aJSObjectPrototype) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSObjectPrototype(aJSObjectPrototype); } \
  NS_IMETHOD FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindInterfaceWithMember(nameID, _retval); } \
  NS_IMETHOD FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindInterfaceWithName(nameID, _retval); } \
  NS_IMETHOD_(bool) HasNativeMember(JS::Handle<jsid> name); \
  NS_IMETHOD DebugDump(int16_t depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \
  NS_IMETHOD FinishInitForWrappedGlobal(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FinishInitForWrappedGlobal(); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectWrappedNative : public nsIXPConnectWrappedNative
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTWRAPPEDNATIVE

  nsXPConnectWrappedNative();

private:
  ~nsXPConnectWrappedNative();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPConnectWrappedNative, nsIXPConnectWrappedNative)

nsXPConnectWrappedNative::nsXPConnectWrappedNative()
{
  /* member initializers and constructor code */
}

nsXPConnectWrappedNative::~nsXPConnectWrappedNative()
{
  /* destructor code */
}

/* readonly attribute nsISupports Native; */
NS_IMETHODIMP nsXPConnectWrappedNative::GetNative(nsISupports * *aNative)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute JSObjectPtr JSObjectPrototype; */
NS_IMETHODIMP nsXPConnectWrappedNative::GetJSObjectPrototype(JSObject **aJSObjectPrototype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo FindInterfaceWithMember (in JSHandleId nameID); */
NS_IMETHODIMP nsXPConnectWrappedNative::FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo FindInterfaceWithName (in JSHandleId nameID); */
NS_IMETHODIMP nsXPConnectWrappedNative::FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] bool HasNativeMember (in JSHandleId name); */
NS_IMETHODIMP_(bool) nsXPConnectWrappedNative::HasNativeMember(JS::Handle<jsid> name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnectWrappedNative::DebugDump(int16_t depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finishInitForWrappedGlobal (); */
NS_IMETHODIMP nsXPConnectWrappedNative::FinishInitForWrappedGlobal()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#include "nsCOMPtr.h"
inline
const nsQueryInterface
do_QueryWrappedNative(nsIXPConnectWrappedNative *aWrappedNative)
{
    return nsQueryInterface(aWrappedNative->Native());
}
inline
const nsQueryInterfaceWithError
do_QueryWrappedNative(nsIXPConnectWrappedNative *aWrappedNative,
                      nsresult *aError)
{
    return nsQueryInterfaceWithError(aWrappedNative->Native(), aError);
}

/* starting interface:    nsIXPConnectWrappedJS */
#define NS_IXPCONNECTWRAPPEDJS_IID_STR "bed52030-bca6-11d2-ba79-00805f8a5dd7"

#define NS_IXPCONNECTWRAPPEDJS_IID \
  {0xbed52030, 0xbca6, 0x11d2, \
    { 0xba, 0x79, 0x00, 0x80, 0x5f, 0x8a, 0x5d, 0xd7 }}

class NS_NO_VTABLE nsIXPConnectWrappedJS : public nsIXPConnectJSObjectHolder {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTWRAPPEDJS_IID)

  /* readonly attribute nsIInterfaceInfo InterfaceInfo; */
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) = 0;

  /* readonly attribute nsIIDPtr InterfaceIID; */
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(int16_t depth) = 0;

  /* void aggregatedQueryInterface (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void **result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectWrappedJS, NS_IXPCONNECTWRAPPEDJS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTWRAPPEDJS \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo); \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID); \
  NS_IMETHOD DebugDump(int16_t depth); \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void **result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTWRAPPEDJS(_to) \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) { return _to GetInterfaceInfo(aInterfaceInfo); } \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) { return _to GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD DebugDump(int16_t depth) { return _to DebugDump(depth); } \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void **result) { return _to AggregatedQueryInterface(uuid, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTWRAPPEDJS(_to) \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceInfo(aInterfaceInfo); } \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD DebugDump(int16_t depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void **result) { return !_to ? NS_ERROR_NULL_POINTER : _to->AggregatedQueryInterface(uuid, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectWrappedJS : public nsIXPConnectWrappedJS
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTWRAPPEDJS

  nsXPConnectWrappedJS();

private:
  ~nsXPConnectWrappedJS();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPConnectWrappedJS, nsIXPConnectWrappedJS)

nsXPConnectWrappedJS::nsXPConnectWrappedJS()
{
  /* member initializers and constructor code */
}

nsXPConnectWrappedJS::~nsXPConnectWrappedJS()
{
  /* destructor code */
}

/* readonly attribute nsIInterfaceInfo InterfaceInfo; */
NS_IMETHODIMP nsXPConnectWrappedJS::GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDPtr InterfaceIID; */
NS_IMETHODIMP nsXPConnectWrappedJS::GetInterfaceIID(nsIID **aInterfaceIID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnectWrappedJS::DebugDump(int16_t depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void aggregatedQueryInterface (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnectWrappedJS::AggregatedQueryInterface(const nsIID & uuid, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCWrappedJSObjectGetter */
#define NS_IXPCWRAPPEDJSOBJECTGETTER_IID_STR "254bb2e0-6439-11d4-8fe0-0010a4e73d9a"

#define NS_IXPCWRAPPEDJSOBJECTGETTER_IID \
  {0x254bb2e0, 0x6439, 0x11d4, \
    { 0x8f, 0xe0, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIXPCWrappedJSObjectGetter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCWRAPPEDJSOBJECTGETTER_IID)

  /* readonly attribute nsISupports neverCalled; */
  NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCWrappedJSObjectGetter, NS_IXPCWRAPPEDJSOBJECTGETTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCWRAPPEDJSOBJECTGETTER \
  NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCWRAPPEDJSOBJECTGETTER(_to) \
  NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) { return _to GetNeverCalled(aNeverCalled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCWRAPPEDJSOBJECTGETTER(_to) \
  NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeverCalled(aNeverCalled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCWrappedJSObjectGetter : public nsIXPCWrappedJSObjectGetter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCWRAPPEDJSOBJECTGETTER

  nsXPCWrappedJSObjectGetter();

private:
  ~nsXPCWrappedJSObjectGetter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCWrappedJSObjectGetter, nsIXPCWrappedJSObjectGetter)

nsXPCWrappedJSObjectGetter::nsXPCWrappedJSObjectGetter()
{
  /* member initializers and constructor code */
}

nsXPCWrappedJSObjectGetter::~nsXPCWrappedJSObjectGetter()
{
  /* destructor code */
}

/* readonly attribute nsISupports neverCalled; */
NS_IMETHODIMP nsXPCWrappedJSObjectGetter::GetNeverCalled(nsISupports * *aNeverCalled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCFunctionThisTranslator */
#define NS_IXPCFUNCTIONTHISTRANSLATOR_IID_STR "f5f84b70-92eb-41f1-a1dd-2eaac0ed564c"

#define NS_IXPCFUNCTIONTHISTRANSLATOR_IID \
  {0xf5f84b70, 0x92eb, 0x41f1, \
    { 0xa1, 0xdd, 0x2e, 0xaa, 0xc0, 0xed, 0x56, 0x4c }}

class NS_NO_VTABLE nsIXPCFunctionThisTranslator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCFUNCTIONTHISTRANSLATOR_IID)

  /* nsISupports TranslateThis (in nsISupports aInitialThis); */
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCFunctionThisTranslator, NS_IXPCFUNCTIONTHISTRANSLATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCFUNCTIONTHISTRANSLATOR \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCFUNCTIONTHISTRANSLATOR(_to) \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval) { return _to TranslateThis(aInitialThis, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCFUNCTIONTHISTRANSLATOR(_to) \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TranslateThis(aInitialThis, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCFunctionThisTranslator : public nsIXPCFunctionThisTranslator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCFUNCTIONTHISTRANSLATOR

  nsXPCFunctionThisTranslator();

private:
  ~nsXPCFunctionThisTranslator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCFunctionThisTranslator, nsIXPCFunctionThisTranslator)

nsXPCFunctionThisTranslator::nsXPCFunctionThisTranslator()
{
  /* member initializers and constructor code */
}

nsXPCFunctionThisTranslator::~nsXPCFunctionThisTranslator()
{
  /* destructor code */
}

/* nsISupports TranslateThis (in nsISupports aInitialThis); */
NS_IMETHODIMP nsXPCFunctionThisTranslator::TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// For use with the service manager
// {CB6593E0-F9B2-11d2-BDD6-000064657374}
#define NS_XPCONNECT_CID \
{ 0xcb6593e0, 0xf9b2, 0x11d2, \
    { 0xbd, 0xd6, 0x0, 0x0, 0x64, 0x65, 0x73, 0x74 } }

/* starting interface:    nsIXPConnect */
#define NS_IXPCONNECT_IID_STR "3d5a6320-8764-11e3-baa7-0800200c9a66"

#define NS_IXPCONNECT_IID \
  {0x3d5a6320, 0x8764, 0x11e3, \
    { 0xba, 0xa7, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class nsIXPConnect : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECT_IID)

   NS_DEFINE_STATIC_CID_ACCESSOR(NS_XPCONNECT_CID)
  /* void initClasses (in JSContextPtr aJSContext, in JSObjectPtr aGlobalJSObj); */
  NS_IMETHOD InitClasses(JSContext *aJSContext, JSObject *aGlobalJSObj) = 0;

  /* nsIXPConnectJSObjectHolder initClassesWithNewWrappedGlobal (in JSContextPtr aJSContext, in nsISupports aCOMObj, in nsIPrincipal aPrincipal, in uint32_t aFlags, in JSCompartmentOptions aOptions); */
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval) = 0;

  enum {
    INIT_JS_STANDARD_CLASSES = 1U,
    DONT_FIRE_ONNEWGLOBALHOOK = 2U,
    OMIT_COMPONENTS_OBJECT = 4U
  };

  /* nsIXPConnectJSObjectHolder wrapNative (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
  NS_IMETHOD WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval) = 0;

  /* void wrapNativeToJSVal (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsWrapperCachePtr aCache, in nsIIDPtr aIID, in boolean aAllowWrapper, out jsval aVal); */
  NS_IMETHOD WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal) = 0;

  /* void wrapJS (in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
  NS_IMETHOD WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) = 0;

  /* nsIVariant jSValToVariant (in JSContextPtr cx, in jsval aJSVal); */
  NS_IMETHOD JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval) = 0;

  /* nsIXPConnectWrappedNative getWrappedNativeOfJSObject (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval) = 0;

  /* [noscript,notxpcom] nsISupports getNativeOfWrapper (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
  NS_IMETHOD_(nsISupports *) GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj) = 0;

  /* void setDefaultSecurityManager (in nsIXPCSecurityManager aManager); */
  NS_IMETHOD SetDefaultSecurityManager(nsIXPCSecurityManager *aManager) = 0;

  /* nsIStackFrame createStackFrameLocation (in uint32_t aLanguage, in string aFilename, in string aFunctionName, in int32_t aLineNumber, in nsIStackFrame aCaller); */
  NS_IMETHOD CreateStackFrameLocation(uint32_t aLanguage, const char * aFilename, const char * aFunctionName, int32_t aLineNumber, nsIStackFrame *aCaller, nsIStackFrame * *_retval) = 0;

  /* [noscript,nostdcall,notxpcom] JSContextPtr getCurrentJSContext (); */
  virtual JSContext * GetCurrentJSContext(void) = 0;

  /* [noscript,nostdcall,notxpcom] JSContextPtr initSafeJSContext (); */
  virtual JSContext * InitSafeJSContext(void) = 0;

  /* [noscript,nostdcall,notxpcom] JSContextPtr getSafeJSContext (); */
  virtual JSContext * GetSafeJSContext(void) = 0;

  /* readonly attribute nsIStackFrame CurrentJSStack; */
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) = 0;

  /* readonly attribute nsAXPCNativeCallContextPtr CurrentNativeCallContext; */
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(int16_t depth) = 0;

  /* void debugDumpObject (in nsISupports aCOMObj, in short depth); */
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, int16_t depth) = 0;

  /* void debugDumpJSStack (in boolean showArgs, in boolean showLocals, in boolean showThisProps); */
  NS_IMETHOD DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps) = 0;

  /* void debugDumpEvalInJSStackFrame (in uint32_t aFrameNumber, in string aSourceText); */
  NS_IMETHOD DebugDumpEvalInJSStackFrame(uint32_t aFrameNumber, const char * aSourceText) = 0;

  /* void wrapJSAggregatedToNative (in nsISupports aOuter, in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) = 0;

  /* nsIXPConnectWrappedNative getWrappedNativeOfNativeObject (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval) = 0;

  /* void setFunctionThisTranslator (in nsIIDRef aIID, in nsIXPCFunctionThisTranslator aTranslator); */
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator) = 0;

  /* void reparentWrappedNativeIfFound (in JSContextPtr aJSContext, in JSObjectPtr aScope, in JSObjectPtr aNewParent, in nsISupports aCOMObj); */
  NS_IMETHOD ReparentWrappedNativeIfFound(JSContext *aJSContext, JSObject *aScope, JSObject *aNewParent, nsISupports *aCOMObj) = 0;

  /* void rescueOrphansInScope (in JSContextPtr aJSContext, in JSObjectPtr aScope); */
  NS_IMETHOD RescueOrphansInScope(JSContext *aJSContext, JSObject *aScope) = 0;

  /* nsIXPConnectJSObjectHolder getWrappedNativePrototype (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsIClassInfo aClassInfo); */
  NS_IMETHOD GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval) = 0;

  /* jsval variantToJS (in JSContextPtr ctx, in JSObjectPtr scope, in nsIVariant value); */
  NS_IMETHOD VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval) = 0;

  /* nsIVariant JSToVariant (in JSContextPtr ctx, in jsval value); */
  NS_IMETHOD JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval) = 0;

  /* [noscript] nsIXPConnectJSObjectHolder createSandbox (in JSContextPtr cx, in nsIPrincipal principal); */
  NS_IMETHOD CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval) = 0;

  /* [noscript] jsval evalInSandboxObject (in AString source, in string filename, in JSContextPtr cx, in JSObjectPtr sandbox, in boolean returnStringOnly); */
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, bool returnStringOnly, JS::MutableHandleValue _retval) = 0;

  /* void setReportAllJSExceptions (in boolean reportAllJSExceptions); */
  NS_IMETHOD SetReportAllJSExceptions(bool reportAllJSExceptions) = 0;

  /* void GarbageCollect (in uint32_t reason); */
  NS_IMETHOD GarbageCollect(uint32_t reason) = 0;

  /* void NotifyDidPaint (); */
  NS_IMETHOD NotifyDidPaint(void) = 0;

     /**
     * Get the object principal for this wrapper.  Note that this may well end
     * up being null; in that case one should seek principals elsewhere.  Null
     * here does NOT indicate system principal or no principals at all, just
     * that this wrapper doesn't have an intrinsic one.
     */
    virtual nsIPrincipal* GetPrincipal(JSObject* obj,
                                       bool allowShortCircuit) const = 0;
    virtual char* DebugPrintJSStack(bool showArgs,
                                    bool showLocals,
                                    bool showThisProps) = 0;
  /* nsIXPConnectJSObjectHolder holdObject (in JSContextPtr aJSContext, in JSObjectPtr aObject); */
  NS_IMETHOD HoldObject(JSContext *aJSContext, JSObject *aObject, nsIXPConnectJSObjectHolder * *_retval) = 0;

  /* [noscript] void setDebugModeWhenPossible (in boolean mode, in boolean allowSyncDisable); */
  NS_IMETHOD SetDebugModeWhenPossible(bool mode, bool allowSyncDisable) = 0;

  /* [noscript] void writeScript (in nsIObjectOutputStream aStream, in JSContextPtr aJSContext, in JSScriptPtr aJSScript); */
  NS_IMETHOD WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript) = 0;

  /* [noscript] JSScriptPtr readScript (in nsIObjectInputStream aStream, in JSContextPtr aJSContext); */
  NS_IMETHOD ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval) = 0;

  /* [noscript] void writeFunction (in nsIObjectOutputStream aStream, in JSContextPtr aJSContext, in JSObjectPtr aJSObject); */
  NS_IMETHOD WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject) = 0;

  /* [noscript] JSObjectPtr readFunction (in nsIObjectInputStream aStream, in JSContextPtr aJSContext); */
  NS_IMETHOD ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval) = 0;

  /* [noscript] void markErrorUnreported (in JSContextPtr aJSContext); */
  NS_IMETHOD MarkErrorUnreported(JSContext *aJSContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnect, NS_IXPCONNECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECT \
  NS_IMETHOD InitClasses(JSContext *aJSContext, JSObject *aGlobalJSObj); \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval); \
  NS_IMETHOD WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval); \
  NS_IMETHOD WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal); \
  NS_IMETHOD WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result); \
  NS_IMETHOD JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval); \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval); \
  NS_IMETHOD_(nsISupports *) GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj); \
  NS_IMETHOD SetDefaultSecurityManager(nsIXPCSecurityManager *aManager); \
  NS_IMETHOD CreateStackFrameLocation(uint32_t aLanguage, const char * aFilename, const char * aFunctionName, int32_t aLineNumber, nsIStackFrame *aCaller, nsIStackFrame * *_retval); \
  virtual JSContext * GetCurrentJSContext(void); \
  virtual JSContext * InitSafeJSContext(void); \
  virtual JSContext * GetSafeJSContext(void); \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack); \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext); \
  NS_IMETHOD DebugDump(int16_t depth); \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, int16_t depth); \
  NS_IMETHOD DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps); \
  NS_IMETHOD DebugDumpEvalInJSStackFrame(uint32_t aFrameNumber, const char * aSourceText); \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result); \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval); \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator); \
  NS_IMETHOD ReparentWrappedNativeIfFound(JSContext *aJSContext, JSObject *aScope, JSObject *aNewParent, nsISupports *aCOMObj); \
  NS_IMETHOD RescueOrphansInScope(JSContext *aJSContext, JSObject *aScope); \
  NS_IMETHOD GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval); \
  NS_IMETHOD VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval); \
  NS_IMETHOD JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval); \
  NS_IMETHOD CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval); \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, bool returnStringOnly, JS::MutableHandleValue _retval); \
  NS_IMETHOD SetReportAllJSExceptions(bool reportAllJSExceptions); \
  NS_IMETHOD GarbageCollect(uint32_t reason); \
  NS_IMETHOD NotifyDidPaint(void); \
  NS_IMETHOD HoldObject(JSContext *aJSContext, JSObject *aObject, nsIXPConnectJSObjectHolder * *_retval); \
  NS_IMETHOD SetDebugModeWhenPossible(bool mode, bool allowSyncDisable); \
  NS_IMETHOD WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript); \
  NS_IMETHOD ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval); \
  NS_IMETHOD WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject); \
  NS_IMETHOD ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval); \
  NS_IMETHOD MarkErrorUnreported(JSContext *aJSContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECT(_to) \
  NS_IMETHOD InitClasses(JSContext *aJSContext, JSObject *aGlobalJSObj) { return _to InitClasses(aJSContext, aGlobalJSObj); } \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval) { return _to InitClassesWithNewWrappedGlobal(aJSContext, aCOMObj, aPrincipal, aFlags, aOptions, _retval); } \
  NS_IMETHOD WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval) { return _to WrapNative(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal) { return _to WrapNativeToJSVal(aJSContext, aScope, aCOMObj, aCache, aIID, aAllowWrapper, aVal); } \
  NS_IMETHOD WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) { return _to WrapJS(aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval) { return _to JSValToVariant(cx, aJSVal, _retval); } \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval) { return _to GetWrappedNativeOfJSObject(aJSContext, aJSObj, _retval); } \
  NS_IMETHOD_(nsISupports *) GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj) { return _to GetNativeOfWrapper(aJSContext, aJSObj); } \
  NS_IMETHOD SetDefaultSecurityManager(nsIXPCSecurityManager *aManager) { return _to SetDefaultSecurityManager(aManager); } \
  NS_IMETHOD CreateStackFrameLocation(uint32_t aLanguage, const char * aFilename, const char * aFunctionName, int32_t aLineNumber, nsIStackFrame *aCaller, nsIStackFrame * *_retval) { return _to CreateStackFrameLocation(aLanguage, aFilename, aFunctionName, aLineNumber, aCaller, _retval); } \
  virtual JSContext * GetCurrentJSContext(void) { return _to GetCurrentJSContext(); } \
  virtual JSContext * InitSafeJSContext(void) { return _to InitSafeJSContext(); } \
  virtual JSContext * GetSafeJSContext(void) { return _to GetSafeJSContext(); } \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) { return _to GetCurrentJSStack(aCurrentJSStack); } \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext) { return _to GetCurrentNativeCallContext(aCurrentNativeCallContext); } \
  NS_IMETHOD DebugDump(int16_t depth) { return _to DebugDump(depth); } \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, int16_t depth) { return _to DebugDumpObject(aCOMObj, depth); } \
  NS_IMETHOD DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps) { return _to DebugDumpJSStack(showArgs, showLocals, showThisProps); } \
  NS_IMETHOD DebugDumpEvalInJSStackFrame(uint32_t aFrameNumber, const char * aSourceText) { return _to DebugDumpEvalInJSStackFrame(aFrameNumber, aSourceText); } \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) { return _to WrapJSAggregatedToNative(aOuter, aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval) { return _to GetWrappedNativeOfNativeObject(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator) { return _to SetFunctionThisTranslator(aIID, aTranslator); } \
  NS_IMETHOD ReparentWrappedNativeIfFound(JSContext *aJSContext, JSObject *aScope, JSObject *aNewParent, nsISupports *aCOMObj) { return _to ReparentWrappedNativeIfFound(aJSContext, aScope, aNewParent, aCOMObj); } \
  NS_IMETHOD RescueOrphansInScope(JSContext *aJSContext, JSObject *aScope) { return _to RescueOrphansInScope(aJSContext, aScope); } \
  NS_IMETHOD GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval) { return _to GetWrappedNativePrototype(aJSContext, aScope, aClassInfo, _retval); } \
  NS_IMETHOD VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval) { return _to VariantToJS(ctx, scope, value, _retval); } \
  NS_IMETHOD JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval) { return _to JSToVariant(ctx, value, _retval); } \
  NS_IMETHOD CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval) { return _to CreateSandbox(cx, principal, _retval); } \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, bool returnStringOnly, JS::MutableHandleValue _retval) { return _to EvalInSandboxObject(source, filename, cx, sandbox, returnStringOnly, _retval); } \
  NS_IMETHOD SetReportAllJSExceptions(bool reportAllJSExceptions) { return _to SetReportAllJSExceptions(reportAllJSExceptions); } \
  NS_IMETHOD GarbageCollect(uint32_t reason) { return _to GarbageCollect(reason); } \
  NS_IMETHOD NotifyDidPaint(void) { return _to NotifyDidPaint(); } \
  NS_IMETHOD HoldObject(JSContext *aJSContext, JSObject *aObject, nsIXPConnectJSObjectHolder * *_retval) { return _to HoldObject(aJSContext, aObject, _retval); } \
  NS_IMETHOD SetDebugModeWhenPossible(bool mode, bool allowSyncDisable) { return _to SetDebugModeWhenPossible(mode, allowSyncDisable); } \
  NS_IMETHOD WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript) { return _to WriteScript(aStream, aJSContext, aJSScript); } \
  NS_IMETHOD ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval) { return _to ReadScript(aStream, aJSContext, _retval); } \
  NS_IMETHOD WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject) { return _to WriteFunction(aStream, aJSContext, aJSObject); } \
  NS_IMETHOD ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval) { return _to ReadFunction(aStream, aJSContext, _retval); } \
  NS_IMETHOD MarkErrorUnreported(JSContext *aJSContext) { return _to MarkErrorUnreported(aJSContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECT(_to) \
  NS_IMETHOD InitClasses(JSContext *aJSContext, JSObject *aGlobalJSObj) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitClasses(aJSContext, aGlobalJSObj); } \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitClassesWithNewWrappedGlobal(aJSContext, aCOMObj, aPrincipal, aFlags, aOptions, _retval); } \
  NS_IMETHOD WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapNative(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapNativeToJSVal(aJSContext, aScope, aCOMObj, aCache, aIID, aAllowWrapper, aVal); } \
  NS_IMETHOD WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapJS(aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->JSValToVariant(cx, aJSVal, _retval); } \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativeOfJSObject(aJSContext, aJSObj, _retval); } \
  NS_IMETHOD_(nsISupports *) GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj); \
  NS_IMETHOD SetDefaultSecurityManager(nsIXPCSecurityManager *aManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultSecurityManager(aManager); } \
  NS_IMETHOD CreateStackFrameLocation(uint32_t aLanguage, const char * aFilename, const char * aFunctionName, int32_t aLineNumber, nsIStackFrame *aCaller, nsIStackFrame * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateStackFrameLocation(aLanguage, aFilename, aFunctionName, aLineNumber, aCaller, _retval); } \
  virtual JSContext * GetCurrentJSContext(void); \
  virtual JSContext * InitSafeJSContext(void); \
  virtual JSContext * GetSafeJSContext(void); \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentJSStack(aCurrentJSStack); } \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentNativeCallContext(aCurrentNativeCallContext); } \
  NS_IMETHOD DebugDump(int16_t depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, int16_t depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpObject(aCOMObj, depth); } \
  NS_IMETHOD DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpJSStack(showArgs, showLocals, showThisProps); } \
  NS_IMETHOD DebugDumpEvalInJSStackFrame(uint32_t aFrameNumber, const char * aSourceText) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpEvalInJSStackFrame(aFrameNumber, aSourceText); } \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapJSAggregatedToNative(aOuter, aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativeOfNativeObject(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFunctionThisTranslator(aIID, aTranslator); } \
  NS_IMETHOD ReparentWrappedNativeIfFound(JSContext *aJSContext, JSObject *aScope, JSObject *aNewParent, nsISupports *aCOMObj) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReparentWrappedNativeIfFound(aJSContext, aScope, aNewParent, aCOMObj); } \
  NS_IMETHOD RescueOrphansInScope(JSContext *aJSContext, JSObject *aScope) { return !_to ? NS_ERROR_NULL_POINTER : _to->RescueOrphansInScope(aJSContext, aScope); } \
  NS_IMETHOD GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativePrototype(aJSContext, aScope, aClassInfo, _retval); } \
  NS_IMETHOD VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->VariantToJS(ctx, scope, value, _retval); } \
  NS_IMETHOD JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->JSToVariant(ctx, value, _retval); } \
  NS_IMETHOD CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSandbox(cx, principal, _retval); } \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, bool returnStringOnly, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvalInSandboxObject(source, filename, cx, sandbox, returnStringOnly, _retval); } \
  NS_IMETHOD SetReportAllJSExceptions(bool reportAllJSExceptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReportAllJSExceptions(reportAllJSExceptions); } \
  NS_IMETHOD GarbageCollect(uint32_t reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->GarbageCollect(reason); } \
  NS_IMETHOD NotifyDidPaint(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDidPaint(); } \
  NS_IMETHOD HoldObject(JSContext *aJSContext, JSObject *aObject, nsIXPConnectJSObjectHolder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HoldObject(aJSContext, aObject, _retval); } \
  NS_IMETHOD SetDebugModeWhenPossible(bool mode, bool allowSyncDisable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDebugModeWhenPossible(mode, allowSyncDisable); } \
  NS_IMETHOD WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteScript(aStream, aJSContext, aJSScript); } \
  NS_IMETHOD ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadScript(aStream, aJSContext, _retval); } \
  NS_IMETHOD WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteFunction(aStream, aJSContext, aJSObject); } \
  NS_IMETHOD ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadFunction(aStream, aJSContext, _retval); } \
  NS_IMETHOD MarkErrorUnreported(JSContext *aJSContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkErrorUnreported(aJSContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnect : public nsIXPConnect
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECT

  nsXPConnect();

private:
  ~nsXPConnect();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPConnect, nsIXPConnect)

nsXPConnect::nsXPConnect()
{
  /* member initializers and constructor code */
}

nsXPConnect::~nsXPConnect()
{
  /* destructor code */
}

/* void initClasses (in JSContextPtr aJSContext, in JSObjectPtr aGlobalJSObj); */
NS_IMETHODIMP nsXPConnect::InitClasses(JSContext *aJSContext, JSObject *aGlobalJSObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder initClassesWithNewWrappedGlobal (in JSContextPtr aJSContext, in nsISupports aCOMObj, in nsIPrincipal aPrincipal, in uint32_t aFlags, in JSCompartmentOptions aOptions); */
NS_IMETHODIMP nsXPConnect::InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder wrapNative (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
NS_IMETHODIMP nsXPConnect::WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapNativeToJSVal (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsWrapperCachePtr aCache, in nsIIDPtr aIID, in boolean aAllowWrapper, out jsval aVal); */
NS_IMETHODIMP nsXPConnect::WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapJS (in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnect::WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant jSValToVariant (in JSContextPtr cx, in jsval aJSVal); */
NS_IMETHODIMP nsXPConnect::JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectWrappedNative getWrappedNativeOfJSObject (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsISupports getNativeOfWrapper (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
NS_IMETHODIMP_(nsISupports *) nsXPConnect::GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDefaultSecurityManager (in nsIXPCSecurityManager aManager); */
NS_IMETHODIMP nsXPConnect::SetDefaultSecurityManager(nsIXPCSecurityManager *aManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStackFrame createStackFrameLocation (in uint32_t aLanguage, in string aFilename, in string aFunctionName, in int32_t aLineNumber, in nsIStackFrame aCaller); */
NS_IMETHODIMP nsXPConnect::CreateStackFrameLocation(uint32_t aLanguage, const char * aFilename, const char * aFunctionName, int32_t aLineNumber, nsIStackFrame *aCaller, nsIStackFrame * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] JSContextPtr getCurrentJSContext (); */
JSContext * nsXPConnect::GetCurrentJSContext()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] JSContextPtr initSafeJSContext (); */
JSContext * nsXPConnect::InitSafeJSContext()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] JSContextPtr getSafeJSContext (); */
JSContext * nsXPConnect::GetSafeJSContext()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame CurrentJSStack; */
NS_IMETHODIMP nsXPConnect::GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsAXPCNativeCallContextPtr CurrentNativeCallContext; */
NS_IMETHODIMP nsXPConnect::GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnect::DebugDump(int16_t depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpObject (in nsISupports aCOMObj, in short depth); */
NS_IMETHODIMP nsXPConnect::DebugDumpObject(nsISupports *aCOMObj, int16_t depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpJSStack (in boolean showArgs, in boolean showLocals, in boolean showThisProps); */
NS_IMETHODIMP nsXPConnect::DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpEvalInJSStackFrame (in uint32_t aFrameNumber, in string aSourceText); */
NS_IMETHODIMP nsXPConnect::DebugDumpEvalInJSStackFrame(uint32_t aFrameNumber, const char * aSourceText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapJSAggregatedToNative (in nsISupports aOuter, in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnect::WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectWrappedNative getWrappedNativeOfNativeObject (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFunctionThisTranslator (in nsIIDRef aIID, in nsIXPCFunctionThisTranslator aTranslator); */
NS_IMETHODIMP nsXPConnect::SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reparentWrappedNativeIfFound (in JSContextPtr aJSContext, in JSObjectPtr aScope, in JSObjectPtr aNewParent, in nsISupports aCOMObj); */
NS_IMETHODIMP nsXPConnect::ReparentWrappedNativeIfFound(JSContext *aJSContext, JSObject *aScope, JSObject *aNewParent, nsISupports *aCOMObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rescueOrphansInScope (in JSContextPtr aJSContext, in JSObjectPtr aScope); */
NS_IMETHODIMP nsXPConnect::RescueOrphansInScope(JSContext *aJSContext, JSObject *aScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder getWrappedNativePrototype (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsIClassInfo aClassInfo); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval variantToJS (in JSContextPtr ctx, in JSObjectPtr scope, in nsIVariant value); */
NS_IMETHODIMP nsXPConnect::VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant JSToVariant (in JSContextPtr ctx, in jsval value); */
NS_IMETHODIMP nsXPConnect::JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIXPConnectJSObjectHolder createSandbox (in JSContextPtr cx, in nsIPrincipal principal); */
NS_IMETHODIMP nsXPConnect::CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] jsval evalInSandboxObject (in AString source, in string filename, in JSContextPtr cx, in JSObjectPtr sandbox, in boolean returnStringOnly); */
NS_IMETHODIMP nsXPConnect::EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, bool returnStringOnly, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setReportAllJSExceptions (in boolean reportAllJSExceptions); */
NS_IMETHODIMP nsXPConnect::SetReportAllJSExceptions(bool reportAllJSExceptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GarbageCollect (in uint32_t reason); */
NS_IMETHODIMP nsXPConnect::GarbageCollect(uint32_t reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void NotifyDidPaint (); */
NS_IMETHODIMP nsXPConnect::NotifyDidPaint()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder holdObject (in JSContextPtr aJSContext, in JSObjectPtr aObject); */
NS_IMETHODIMP nsXPConnect::HoldObject(JSContext *aJSContext, JSObject *aObject, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setDebugModeWhenPossible (in boolean mode, in boolean allowSyncDisable); */
NS_IMETHODIMP nsXPConnect::SetDebugModeWhenPossible(bool mode, bool allowSyncDisable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void writeScript (in nsIObjectOutputStream aStream, in JSContextPtr aJSContext, in JSScriptPtr aJSScript); */
NS_IMETHODIMP nsXPConnect::WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSScriptPtr readScript (in nsIObjectInputStream aStream, in JSContextPtr aJSContext); */
NS_IMETHODIMP nsXPConnect::ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void writeFunction (in nsIObjectOutputStream aStream, in JSContextPtr aJSContext, in JSObjectPtr aJSObject); */
NS_IMETHODIMP nsXPConnect::WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSObjectPtr readFunction (in nsIObjectInputStream aStream, in JSContextPtr aJSContext); */
NS_IMETHODIMP nsXPConnect::ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void markErrorUnreported (in JSContextPtr aJSContext); */
NS_IMETHODIMP nsXPConnect::MarkErrorUnreported(JSContext *aJSContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPConnect_h__ */
