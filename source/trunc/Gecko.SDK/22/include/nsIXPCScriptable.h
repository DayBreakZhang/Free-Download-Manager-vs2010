/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/js/xpconnect/idl/nsIXPCScriptable.idl
 */

#ifndef __gen_nsIXPCScriptable_h__
#define __gen_nsIXPCScriptable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIXPConnect_h__
#include "nsIXPConnect.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef XP_WIN
#undef GetClassName
#endif

/* starting interface:    nsIXPCScriptable */
#define NS_IXPCSCRIPTABLE_IID_STR "1236e34a-21e0-423c-a8c8-9b3f1e6d7060"

#define NS_IXPCSCRIPTABLE_IID \
  {0x1236e34a, 0x21e0, 0x423c, \
    { 0xa8, 0xc8, 0x9b, 0x3f, 0x1e, 0x6d, 0x70, 0x60 }}

class NS_NO_VTABLE nsIXPCScriptable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCSCRIPTABLE_IID)

  enum {
    WANT_PRECREATE = 1U,
    WANT_CREATE = 2U,
    WANT_POSTCREATE = 4U,
    WANT_ADDPROPERTY = 8U,
    WANT_DELPROPERTY = 16U,
    WANT_GETPROPERTY = 32U,
    WANT_SETPROPERTY = 64U,
    WANT_ENUMERATE = 128U,
    WANT_NEWENUMERATE = 256U,
    WANT_NEWRESOLVE = 512U,
    WANT_CONVERT = 1024U,
    WANT_FINALIZE = 2048U,
    WANT_CHECKACCESS = 4096U,
    WANT_CALL = 8192U,
    WANT_CONSTRUCT = 16384U,
    WANT_HASINSTANCE = 32768U,
    USE_JSSTUB_FOR_ADDPROPERTY = 131072U,
    USE_JSSTUB_FOR_DELPROPERTY = 262144U,
    USE_JSSTUB_FOR_SETPROPERTY = 524288U,
    DONT_ENUM_STATIC_PROPS = 1048576U,
    DONT_ENUM_QUERY_INTERFACE = 2097152U,
    DONT_ASK_INSTANCE_FOR_SCRIPTABLE = 4194304U,
    CLASSINFO_INTERFACES_ONLY = 8388608U,
    ALLOW_PROP_MODS_DURING_RESOLVE = 16777216U,
    ALLOW_PROP_MODS_TO_PROTOTYPE = 33554432U,
    IS_GLOBAL_OBJECT = 67108864U,
    DONT_REFLECT_INTERFACE_NAMES = 134217728U,
    WANT_OUTER_OBJECT = 536870912U,
    RESERVED = 2147483648U
  };

  /* readonly attribute string className; */
  NS_IMETHOD GetClassName(char * *aClassName) = 0;

  /* [nostdcall,notxpcom] uint32_t getScriptableFlags (); */
  virtual uint32_t GetScriptableFlags(void) = 0;

  /* void preCreate (in nsISupports nativeObj, in JSContextPtr cx, in JSObjectPtr globalObj, out JSObjectPtr parentObj); */
  NS_IMETHOD PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj) = 0;

  /* void create (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
  NS_IMETHOD Create(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) = 0;

  /* void postCreate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
  NS_IMETHOD PostCreate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) = 0;

  /* void postTransplant (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
  NS_IMETHOD PostTransplant(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) = 0;

  /* boolean addProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
  NS_IMETHOD AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) = 0;

  /* boolean delProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
  NS_IMETHOD DelProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) = 0;

  /* boolean getProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
  NS_IMETHOD GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) = 0;

  /* boolean setProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
  NS_IMETHOD SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) = 0;

  /* boolean enumerate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
  NS_IMETHOD Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval) = 0;

  /* boolean newEnumerate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in uint32_t enum_op, in JSValPtr statep, out jsid idp); */
  NS_IMETHOD NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t enum_op, jsval *statep, jsid *idp, bool *_retval) = 0;

  /* boolean newResolve (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in uint32_t flags, out JSObjectPtr objp); */
  NS_IMETHOD NewResolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t flags, JSObject **objp, bool *_retval) = 0;

  /* boolean convert (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in uint32_t type, in JSValPtr vp); */
  NS_IMETHOD Convert(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t type, jsval *vp, bool *_retval) = 0;

  /* void finalize (in nsIXPConnectWrappedNative wrapper, in JSFreeOpPtr fop, in JSObjectPtr obj); */
  NS_IMETHOD Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj) = 0;

  /* boolean checkAccess (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in uint32_t mode, in JSValPtr vp); */
  NS_IMETHOD CheckAccess(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t mode, jsval *vp, bool *_retval) = 0;

  /* boolean call (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in uint32_t argc, in JSValPtr argv, in JSValPtr vp); */
  NS_IMETHOD Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval) = 0;

  /* boolean construct (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in uint32_t argc, in JSValPtr argv, in JSValPtr vp); */
  NS_IMETHOD Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval) = 0;

  /* boolean hasInstance (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsval val, out boolean bp); */
  NS_IMETHOD HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::Value & val, bool *bp, bool *_retval) = 0;

  /* JSObjectPtr outerObject (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
  NS_IMETHOD OuterObject(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JSObject **_retval) = 0;

  /* void postCreatePrototype (in JSContextPtr cx, in JSObjectPtr proto); */
  NS_IMETHOD PostCreatePrototype(JSContext *cx, JSObject *proto) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCScriptable, NS_IXPCSCRIPTABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCSCRIPTABLE \
  NS_IMETHOD GetClassName(char * *aClassName); \
  virtual uint32_t GetScriptableFlags(void); \
  NS_IMETHOD PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj); \
  NS_IMETHOD Create(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj); \
  NS_IMETHOD PostCreate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj); \
  NS_IMETHOD PostTransplant(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj); \
  NS_IMETHOD AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval); \
  NS_IMETHOD DelProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval); \
  NS_IMETHOD GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval); \
  NS_IMETHOD SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval); \
  NS_IMETHOD Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval); \
  NS_IMETHOD NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t enum_op, jsval *statep, jsid *idp, bool *_retval); \
  NS_IMETHOD NewResolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t flags, JSObject **objp, bool *_retval); \
  NS_IMETHOD Convert(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t type, jsval *vp, bool *_retval); \
  NS_IMETHOD Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj); \
  NS_IMETHOD CheckAccess(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t mode, jsval *vp, bool *_retval); \
  NS_IMETHOD Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval); \
  NS_IMETHOD Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval); \
  NS_IMETHOD HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::Value & val, bool *bp, bool *_retval); \
  NS_IMETHOD OuterObject(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JSObject **_retval); \
  NS_IMETHOD PostCreatePrototype(JSContext *cx, JSObject *proto); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCSCRIPTABLE(_to) \
  NS_IMETHOD GetClassName(char * *aClassName) { return _to GetClassName(aClassName); } \
  virtual uint32_t GetScriptableFlags(void) { return _to GetScriptableFlags(); } \
  NS_IMETHOD PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj) { return _to PreCreate(nativeObj, cx, globalObj, parentObj); } \
  NS_IMETHOD Create(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) { return _to Create(wrapper, cx, obj); } \
  NS_IMETHOD PostCreate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) { return _to PostCreate(wrapper, cx, obj); } \
  NS_IMETHOD PostTransplant(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) { return _to PostTransplant(wrapper, cx, obj); } \
  NS_IMETHOD AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) { return _to AddProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD DelProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) { return _to DelProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) { return _to GetProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) { return _to SetProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval) { return _to Enumerate(wrapper, cx, obj, _retval); } \
  NS_IMETHOD NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t enum_op, jsval *statep, jsid *idp, bool *_retval) { return _to NewEnumerate(wrapper, cx, obj, enum_op, statep, idp, _retval); } \
  NS_IMETHOD NewResolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t flags, JSObject **objp, bool *_retval) { return _to NewResolve(wrapper, cx, obj, id, flags, objp, _retval); } \
  NS_IMETHOD Convert(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t type, jsval *vp, bool *_retval) { return _to Convert(wrapper, cx, obj, type, vp, _retval); } \
  NS_IMETHOD Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj) { return _to Finalize(wrapper, fop, obj); } \
  NS_IMETHOD CheckAccess(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t mode, jsval *vp, bool *_retval) { return _to CheckAccess(wrapper, cx, obj, id, mode, vp, _retval); } \
  NS_IMETHOD Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval) { return _to Call(wrapper, cx, obj, argc, argv, vp, _retval); } \
  NS_IMETHOD Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval) { return _to Construct(wrapper, cx, obj, argc, argv, vp, _retval); } \
  NS_IMETHOD HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::Value & val, bool *bp, bool *_retval) { return _to HasInstance(wrapper, cx, obj, val, bp, _retval); } \
  NS_IMETHOD OuterObject(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JSObject **_retval) { return _to OuterObject(wrapper, cx, obj, _retval); } \
  NS_IMETHOD PostCreatePrototype(JSContext *cx, JSObject *proto) { return _to PostCreatePrototype(cx, proto); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCSCRIPTABLE(_to) \
  NS_IMETHOD GetClassName(char * *aClassName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassName(aClassName); } \
  virtual uint32_t GetScriptableFlags(void); \
  NS_IMETHOD PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreCreate(nativeObj, cx, globalObj, parentObj); } \
  NS_IMETHOD Create(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) { return !_to ? NS_ERROR_NULL_POINTER : _to->Create(wrapper, cx, obj); } \
  NS_IMETHOD PostCreate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostCreate(wrapper, cx, obj); } \
  NS_IMETHOD PostTransplant(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostTransplant(wrapper, cx, obj); } \
  NS_IMETHOD AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD DelProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DelProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Enumerate(wrapper, cx, obj, _retval); } \
  NS_IMETHOD NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t enum_op, jsval *statep, jsid *idp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewEnumerate(wrapper, cx, obj, enum_op, statep, idp, _retval); } \
  NS_IMETHOD NewResolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t flags, JSObject **objp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewResolve(wrapper, cx, obj, id, flags, objp, _retval); } \
  NS_IMETHOD Convert(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t type, jsval *vp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Convert(wrapper, cx, obj, type, vp, _retval); } \
  NS_IMETHOD Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finalize(wrapper, fop, obj); } \
  NS_IMETHOD CheckAccess(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t mode, jsval *vp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckAccess(wrapper, cx, obj, id, mode, vp, _retval); } \
  NS_IMETHOD Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Call(wrapper, cx, obj, argc, argv, vp, _retval); } \
  NS_IMETHOD Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Construct(wrapper, cx, obj, argc, argv, vp, _retval); } \
  NS_IMETHOD HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::Value & val, bool *bp, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasInstance(wrapper, cx, obj, val, bp, _retval); } \
  NS_IMETHOD OuterObject(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JSObject **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OuterObject(wrapper, cx, obj, _retval); } \
  NS_IMETHOD PostCreatePrototype(JSContext *cx, JSObject *proto) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostCreatePrototype(cx, proto); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCScriptable : public nsIXPCScriptable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCSCRIPTABLE

  nsXPCScriptable();

private:
  ~nsXPCScriptable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCScriptable, nsIXPCScriptable)

nsXPCScriptable::nsXPCScriptable()
{
  /* member initializers and constructor code */
}

nsXPCScriptable::~nsXPCScriptable()
{
  /* destructor code */
}

/* readonly attribute string className; */
NS_IMETHODIMP nsXPCScriptable::GetClassName(char * *aClassName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [nostdcall,notxpcom] uint32_t getScriptableFlags (); */
uint32_t nsXPCScriptable::GetScriptableFlags()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preCreate (in nsISupports nativeObj, in JSContextPtr cx, in JSObjectPtr globalObj, out JSObjectPtr parentObj); */
NS_IMETHODIMP nsXPCScriptable::PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void create (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
NS_IMETHODIMP nsXPCScriptable::Create(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postCreate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
NS_IMETHODIMP nsXPCScriptable::PostCreate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postTransplant (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
NS_IMETHODIMP nsXPCScriptable::PostTransplant(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean addProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean delProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::DelProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean setProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, jsval *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean enumerate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
NS_IMETHODIMP nsXPCScriptable::Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean newEnumerate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in uint32_t enum_op, in JSValPtr statep, out jsid idp); */
NS_IMETHODIMP nsXPCScriptable::NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t enum_op, jsval *statep, jsid *idp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean newResolve (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in uint32_t flags, out JSObjectPtr objp); */
NS_IMETHODIMP nsXPCScriptable::NewResolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t flags, JSObject **objp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean convert (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in uint32_t type, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::Convert(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t type, jsval *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finalize (in nsIXPConnectWrappedNative wrapper, in JSFreeOpPtr fop, in JSObjectPtr obj); */
NS_IMETHODIMP nsXPCScriptable::Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkAccess (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in uint32_t mode, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::CheckAccess(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, uint32_t mode, jsval *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean call (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in uint32_t argc, in JSValPtr argv, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean construct (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in uint32_t argc, in JSValPtr argv, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, uint32_t argc, jsval *argv, jsval *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasInstance (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsval val, out boolean bp); */
NS_IMETHODIMP nsXPCScriptable::HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::Value & val, bool *bp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* JSObjectPtr outerObject (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
NS_IMETHODIMP nsXPCScriptable::OuterObject(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JSObject **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postCreatePrototype (in JSContextPtr cx, in JSObjectPtr proto); */
NS_IMETHODIMP nsXPCScriptable::PostCreatePrototype(JSContext *cx, JSObject *proto)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#include "nsAutoPtr.h"
#define NS_XPCCLASSINFO_IID \
{ 0x9a5b0342, 0x0f70, 0x4d31, \
 { 0xb7, 0xd7, 0x29, 0x68, 0xa5, 0x70, 0x4b, 0xd8 } }
class NS_NO_VTABLE nsXPCClassInfo : public nsIClassInfo,
                                    public nsIXPCScriptable
{
public:
  NS_DECLARE_STATIC_IID_ACCESSOR(NS_XPCCLASSINFO_IID)
  NS_IMETHOD_(nsrefcnt) AddRef() = 0;
  NS_IMETHOD_(nsrefcnt) Release() = 0;
  virtual void PreserveWrapper(nsISupports *aNative) = 0;
  virtual uint32_t GetInterfacesBitmap() = 0;
};
NS_DEFINE_STATIC_IID_ACCESSOR(nsXPCClassInfo, NS_XPCCLASSINFO_IID)
inline
nsresult
CallQueryInterface(nsISupports* aSourcePtr,
                   nsRefPtrGetterAddRefs<nsXPCClassInfo> aDestPtr)
{
  return CallQueryInterface(aSourcePtr,
                            static_cast<nsXPCClassInfo**>(aDestPtr));
}

#endif /* __gen_nsIXPCScriptable_h__ */
