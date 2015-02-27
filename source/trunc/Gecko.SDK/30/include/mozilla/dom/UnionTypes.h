#ifndef mozilla_dom_UnionTypes_h__
#define mozilla_dom_UnionTypes_h__

#include "VTTCueBinding.h"
#include "jsfriendapi.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/OwningNonNull.h"
#include "mozilla/dom/TypedArray.h"
#include "mozilla/dom/UnionMember.h"

namespace mozilla {
namespace dom {
class CanvasGradient;
class CanvasPattern;
class Element;
class Event;
class HTMLCanvasElement;
class HTMLImageElement;
class HTMLOptGroupElement;
class HTMLOptionElement;
class HTMLVideoElement;
class MessagePortBase;
class TelephonyCall;
class TelephonyCallGroup;
namespace indexedDB {
class IDBCursor;
class IDBIndex;
class IDBObjectStore;
} // namespace indexedDB
class mozContact;
} // namespace dom
} // namespace mozilla
class nsFormData;
class nsGenericHTMLElement;
class nsIDOMBlob;
class nsIDOMWindow;
class nsINodeList;

namespace mozilla {
namespace dom {
class ArrayBufferViewOrBlobOrStringOrFormData
{
  friend class ArrayBufferViewOrBlobOrStringOrFormDataArgument;
  enum Type
  {
    eUninitialized,
    eArrayBufferView,
    eBlob,
    eString,
    eFormData
  };
  union Value
  {
    UnionMember<RootedTypedArray<ArrayBufferView > > mArrayBufferView;
    UnionMember<nsIDOMBlob* > mBlob;
    UnionMember<binding_detail::FakeDependentString > mString;
    UnionMember<NonNull<nsFormData> > mFormData;
  };
  Type mType;
  Value mValue;

  ArrayBufferViewOrBlobOrStringOrFormData(const ArrayBufferViewOrBlobOrStringOrFormData&) MOZ_DELETE;
  void operator=(const ArrayBufferViewOrBlobOrStringOrFormData) MOZ_DELETE;

public:
  explicit inline ArrayBufferViewOrBlobOrStringOrFormData()
    : mType(eUninitialized)
  {
  }

  inline ~ArrayBufferViewOrBlobOrStringOrFormData()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eArrayBufferView: {
        DestroyArrayBufferView();
        break;
      }
      case eBlob: {
        DestroyBlob();
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
      case eFormData: {
        DestroyFormData();
        break;
      }
    }
  }

  inline RootedTypedArray<ArrayBufferView >&
  SetAsArrayBufferView(JSContext* cx)
  {
    if (mType == eArrayBufferView) {
      return mValue.mArrayBufferView.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eArrayBufferView;
    return mValue.mArrayBufferView.SetValue(cx);
  }

  inline bool
  IsArrayBufferView() const
  {
    return mType == eArrayBufferView;
  }

  inline ArrayBufferView&
  GetAsArrayBufferView() const
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return const_cast<RootedTypedArray<ArrayBufferView >&>(mValue.mArrayBufferView.Value());
  }

  inline nsIDOMBlob*&
  SetAsBlob()
  {
    if (mType == eBlob) {
      return mValue.mBlob.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eBlob;
    return mValue.mBlob.SetValue();
  }

  inline bool
  IsBlob() const
  {
    return mType == eBlob;
  }

  inline nsIDOMBlob*
  GetAsBlob() const
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return const_cast<nsIDOMBlob*&>(mValue.mBlob.Value());
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    if (mType == eString) {
      return mValue.mString.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eString;
    return mValue.mString.SetValue();
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline const nsAString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<binding_detail::FakeDependentString&>(mValue.mString.Value());
  }

  inline NonNull<nsFormData>&
  SetAsFormData()
  {
    if (mType == eFormData) {
      return mValue.mFormData.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eFormData;
    return mValue.mFormData.SetValue();
  }

  inline bool
  IsFormData() const
  {
    return mType == eFormData;
  }

  inline nsFormData&
  GetAsFormData() const
  {
    MOZ_ASSERT(IsFormData(), "Wrong type!");
    return const_cast<NonNull<nsFormData>&>(mValue.mFormData.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    mValue.mArrayBufferView.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyBlob()
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    mValue.mBlob.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyFormData()
  {
    MOZ_ASSERT(IsFormData(), "Wrong type!");
    mValue.mFormData.Destroy();
    mType = eUninitialized;
  }
};

class BooleanOrObject
{
  friend class BooleanOrObjectArgument;
  enum Type
  {
    eUninitialized,
    eBoolean,
    eObject
  };
  union Value
  {
    UnionMember<bool > mBoolean;
    UnionMember<JS::Rooted<JSObject*> > mObject;
  };
  Type mType;
  Value mValue;

  BooleanOrObject(const BooleanOrObject&) MOZ_DELETE;
  void operator=(const BooleanOrObject) MOZ_DELETE;

public:
  explicit inline BooleanOrObject()
    : mType(eUninitialized)
  {
  }

  inline ~BooleanOrObject()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eBoolean: {
        DestroyBoolean();
        break;
      }
      case eObject: {
        DestroyObject();
        break;
      }
    }
  }

  inline bool&
  SetAsBoolean()
  {
    if (mType == eBoolean) {
      return mValue.mBoolean.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eBoolean;
    return mValue.mBoolean.SetValue();
  }

  inline bool
  IsBoolean() const
  {
    return mType == eBoolean;
  }

  inline bool
  GetAsBoolean() const
  {
    MOZ_ASSERT(IsBoolean(), "Wrong type!");
    return const_cast<bool&>(mValue.mBoolean.Value());
  }

  inline bool
  IsObject() const
  {
    return mType == eObject;
  }

  inline JSObject*
  GetAsObject() const
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    return const_cast<JS::Rooted<JSObject*>&>(mValue.mObject.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyBoolean()
  {
    MOZ_ASSERT(IsBoolean(), "Wrong type!");
    mValue.mBoolean.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyObject()
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    mValue.mObject.Destroy();
    mType = eUninitialized;
  }
};

class EventOrString
{
  friend class EventOrStringArgument;
  enum Type
  {
    eUninitialized,
    eEvent,
    eString
  };
  union Value
  {
    UnionMember<NonNull<mozilla::dom::Event> > mEvent;
    UnionMember<binding_detail::FakeDependentString > mString;
  };
  Type mType;
  Value mValue;

  EventOrString(const EventOrString&) MOZ_DELETE;
  void operator=(const EventOrString) MOZ_DELETE;

public:
  explicit inline EventOrString()
    : mType(eUninitialized)
  {
  }

  inline ~EventOrString()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eEvent: {
        DestroyEvent();
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
    }
  }

  inline NonNull<mozilla::dom::Event>&
  SetAsEvent()
  {
    if (mType == eEvent) {
      return mValue.mEvent.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eEvent;
    return mValue.mEvent.SetValue();
  }

  inline bool
  IsEvent() const
  {
    return mType == eEvent;
  }

  inline mozilla::dom::Event&
  GetAsEvent() const
  {
    MOZ_ASSERT(IsEvent(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::Event>&>(mValue.mEvent.Value());
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    if (mType == eString) {
      return mValue.mString.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eString;
    return mValue.mString.SetValue();
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline const nsAString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<binding_detail::FakeDependentString&>(mValue.mString.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyEvent()
  {
    MOZ_ASSERT(IsEvent(), "Wrong type!");
    mValue.mEvent.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }
};

class HTMLElementOrLong
{
  friend class HTMLElementOrLongArgument;
  enum Type
  {
    eUninitialized,
    eHTMLElement,
    eLong
  };
  union Value
  {
    UnionMember<NonNull<nsGenericHTMLElement> > mHTMLElement;
    UnionMember<int32_t > mLong;
  };
  Type mType;
  Value mValue;

  HTMLElementOrLong(const HTMLElementOrLong&) MOZ_DELETE;
  void operator=(const HTMLElementOrLong) MOZ_DELETE;

public:
  explicit inline HTMLElementOrLong()
    : mType(eUninitialized)
  {
  }

  inline ~HTMLElementOrLong()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eHTMLElement: {
        DestroyHTMLElement();
        break;
      }
      case eLong: {
        DestroyLong();
        break;
      }
    }
  }

  inline NonNull<nsGenericHTMLElement>&
  SetAsHTMLElement()
  {
    if (mType == eHTMLElement) {
      return mValue.mHTMLElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLElement;
    return mValue.mHTMLElement.SetValue();
  }

  inline bool
  IsHTMLElement() const
  {
    return mType == eHTMLElement;
  }

  inline nsGenericHTMLElement&
  GetAsHTMLElement() const
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    return const_cast<NonNull<nsGenericHTMLElement>&>(mValue.mHTMLElement.Value());
  }

  inline int32_t&
  SetAsLong()
  {
    if (mType == eLong) {
      return mValue.mLong.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  inline bool
  IsLong() const
  {
    return mType == eLong;
  }

  inline int32_t
  GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyHTMLElement()
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    mValue.mHTMLElement.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    mValue.mLong.Destroy();
    mType = eUninitialized;
  }
};

class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement
{
  friend class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument;
  enum Type
  {
    eUninitialized,
    eHTMLImageElement,
    eHTMLCanvasElement,
    eHTMLVideoElement
  };
  union Value
  {
    UnionMember<NonNull<mozilla::dom::HTMLImageElement> > mHTMLImageElement;
    UnionMember<NonNull<mozilla::dom::HTMLCanvasElement> > mHTMLCanvasElement;
    UnionMember<NonNull<mozilla::dom::HTMLVideoElement> > mHTMLVideoElement;
  };
  Type mType;
  Value mValue;

  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement&) MOZ_DELETE;
  void operator=(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement) MOZ_DELETE;

public:
  explicit inline HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement()
    : mType(eUninitialized)
  {
  }

  inline ~HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eHTMLImageElement: {
        DestroyHTMLImageElement();
        break;
      }
      case eHTMLCanvasElement: {
        DestroyHTMLCanvasElement();
        break;
      }
      case eHTMLVideoElement: {
        DestroyHTMLVideoElement();
        break;
      }
    }
  }

  inline NonNull<mozilla::dom::HTMLImageElement>&
  SetAsHTMLImageElement()
  {
    if (mType == eHTMLImageElement) {
      return mValue.mHTMLImageElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLImageElement;
    return mValue.mHTMLImageElement.SetValue();
  }

  inline bool
  IsHTMLImageElement() const
  {
    return mType == eHTMLImageElement;
  }

  inline mozilla::dom::HTMLImageElement&
  GetAsHTMLImageElement() const
  {
    MOZ_ASSERT(IsHTMLImageElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLImageElement>&>(mValue.mHTMLImageElement.Value());
  }

  inline NonNull<mozilla::dom::HTMLCanvasElement>&
  SetAsHTMLCanvasElement()
  {
    if (mType == eHTMLCanvasElement) {
      return mValue.mHTMLCanvasElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLCanvasElement;
    return mValue.mHTMLCanvasElement.SetValue();
  }

  inline bool
  IsHTMLCanvasElement() const
  {
    return mType == eHTMLCanvasElement;
  }

  inline mozilla::dom::HTMLCanvasElement&
  GetAsHTMLCanvasElement() const
  {
    MOZ_ASSERT(IsHTMLCanvasElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLCanvasElement>&>(mValue.mHTMLCanvasElement.Value());
  }

  inline NonNull<mozilla::dom::HTMLVideoElement>&
  SetAsHTMLVideoElement()
  {
    if (mType == eHTMLVideoElement) {
      return mValue.mHTMLVideoElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLVideoElement;
    return mValue.mHTMLVideoElement.SetValue();
  }

  inline bool
  IsHTMLVideoElement() const
  {
    return mType == eHTMLVideoElement;
  }

  inline mozilla::dom::HTMLVideoElement&
  GetAsHTMLVideoElement() const
  {
    MOZ_ASSERT(IsHTMLVideoElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLVideoElement>&>(mValue.mHTMLVideoElement.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyHTMLImageElement()
  {
    MOZ_ASSERT(IsHTMLImageElement(), "Wrong type!");
    mValue.mHTMLImageElement.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyHTMLCanvasElement()
  {
    MOZ_ASSERT(IsHTMLCanvasElement(), "Wrong type!");
    mValue.mHTMLCanvasElement.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyHTMLVideoElement()
  {
    MOZ_ASSERT(IsHTMLVideoElement(), "Wrong type!");
    mValue.mHTMLVideoElement.Destroy();
    mType = eUninitialized;
  }
};

class HTMLOptionElementOrHTMLOptGroupElement
{
  friend class HTMLOptionElementOrHTMLOptGroupElementArgument;
  enum Type
  {
    eUninitialized,
    eHTMLOptionElement,
    eHTMLOptGroupElement
  };
  union Value
  {
    UnionMember<NonNull<mozilla::dom::HTMLOptionElement> > mHTMLOptionElement;
    UnionMember<NonNull<mozilla::dom::HTMLOptGroupElement> > mHTMLOptGroupElement;
  };
  Type mType;
  Value mValue;

  HTMLOptionElementOrHTMLOptGroupElement(const HTMLOptionElementOrHTMLOptGroupElement&) MOZ_DELETE;
  void operator=(const HTMLOptionElementOrHTMLOptGroupElement) MOZ_DELETE;

public:
  explicit inline HTMLOptionElementOrHTMLOptGroupElement()
    : mType(eUninitialized)
  {
  }

  inline ~HTMLOptionElementOrHTMLOptGroupElement()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eHTMLOptionElement: {
        DestroyHTMLOptionElement();
        break;
      }
      case eHTMLOptGroupElement: {
        DestroyHTMLOptGroupElement();
        break;
      }
    }
  }

  inline NonNull<mozilla::dom::HTMLOptionElement>&
  SetAsHTMLOptionElement()
  {
    if (mType == eHTMLOptionElement) {
      return mValue.mHTMLOptionElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLOptionElement;
    return mValue.mHTMLOptionElement.SetValue();
  }

  inline bool
  IsHTMLOptionElement() const
  {
    return mType == eHTMLOptionElement;
  }

  inline mozilla::dom::HTMLOptionElement&
  GetAsHTMLOptionElement() const
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLOptionElement>&>(mValue.mHTMLOptionElement.Value());
  }

  inline NonNull<mozilla::dom::HTMLOptGroupElement>&
  SetAsHTMLOptGroupElement()
  {
    if (mType == eHTMLOptGroupElement) {
      return mValue.mHTMLOptGroupElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLOptGroupElement;
    return mValue.mHTMLOptGroupElement.SetValue();
  }

  inline bool
  IsHTMLOptGroupElement() const
  {
    return mType == eHTMLOptGroupElement;
  }

  inline mozilla::dom::HTMLOptGroupElement&
  GetAsHTMLOptGroupElement() const
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLOptGroupElement>&>(mValue.mHTMLOptGroupElement.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyHTMLOptionElement()
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    mValue.mHTMLOptionElement.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyHTMLOptGroupElement()
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    mValue.mHTMLOptGroupElement.Destroy();
    mType = eUninitialized;
  }
};

class IDBObjectStoreOrIDBIndex
{
  friend class IDBObjectStoreOrIDBIndexArgument;
  enum Type
  {
    eUninitialized,
    eIDBObjectStore,
    eIDBIndex
  };
  union Value
  {
    UnionMember<NonNull<mozilla::dom::indexedDB::IDBObjectStore> > mIDBObjectStore;
    UnionMember<NonNull<mozilla::dom::indexedDB::IDBIndex> > mIDBIndex;
  };
  Type mType;
  Value mValue;

  IDBObjectStoreOrIDBIndex(const IDBObjectStoreOrIDBIndex&) MOZ_DELETE;
  void operator=(const IDBObjectStoreOrIDBIndex) MOZ_DELETE;

public:
  explicit inline IDBObjectStoreOrIDBIndex()
    : mType(eUninitialized)
  {
  }

  inline ~IDBObjectStoreOrIDBIndex()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eIDBObjectStore: {
        DestroyIDBObjectStore();
        break;
      }
      case eIDBIndex: {
        DestroyIDBIndex();
        break;
      }
    }
  }

  inline NonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  SetAsIDBObjectStore()
  {
    if (mType == eIDBObjectStore) {
      return mValue.mIDBObjectStore.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eIDBObjectStore;
    return mValue.mIDBObjectStore.SetValue();
  }

  inline bool
  IsIDBObjectStore() const
  {
    return mType == eIDBObjectStore;
  }

  inline mozilla::dom::indexedDB::IDBObjectStore&
  GetAsIDBObjectStore() const
  {
    MOZ_ASSERT(IsIDBObjectStore(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::indexedDB::IDBObjectStore>&>(mValue.mIDBObjectStore.Value());
  }

  inline NonNull<mozilla::dom::indexedDB::IDBIndex>&
  SetAsIDBIndex()
  {
    if (mType == eIDBIndex) {
      return mValue.mIDBIndex.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eIDBIndex;
    return mValue.mIDBIndex.SetValue();
  }

  inline bool
  IsIDBIndex() const
  {
    return mType == eIDBIndex;
  }

  inline mozilla::dom::indexedDB::IDBIndex&
  GetAsIDBIndex() const
  {
    MOZ_ASSERT(IsIDBIndex(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::indexedDB::IDBIndex>&>(mValue.mIDBIndex.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyIDBObjectStore()
  {
    MOZ_ASSERT(IsIDBObjectStore(), "Wrong type!");
    mValue.mIDBObjectStore.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyIDBIndex()
  {
    MOZ_ASSERT(IsIDBIndex(), "Wrong type!");
    mValue.mIDBIndex.Destroy();
    mType = eUninitialized;
  }
};

class IDBObjectStoreOrIDBIndexOrIDBCursor
{
  friend class IDBObjectStoreOrIDBIndexOrIDBCursorArgument;
  enum Type
  {
    eUninitialized,
    eIDBObjectStore,
    eIDBIndex,
    eIDBCursor
  };
  union Value
  {
    UnionMember<NonNull<mozilla::dom::indexedDB::IDBObjectStore> > mIDBObjectStore;
    UnionMember<NonNull<mozilla::dom::indexedDB::IDBIndex> > mIDBIndex;
    UnionMember<NonNull<mozilla::dom::indexedDB::IDBCursor> > mIDBCursor;
  };
  Type mType;
  Value mValue;

  IDBObjectStoreOrIDBIndexOrIDBCursor(const IDBObjectStoreOrIDBIndexOrIDBCursor&) MOZ_DELETE;
  void operator=(const IDBObjectStoreOrIDBIndexOrIDBCursor) MOZ_DELETE;

public:
  explicit inline IDBObjectStoreOrIDBIndexOrIDBCursor()
    : mType(eUninitialized)
  {
  }

  inline ~IDBObjectStoreOrIDBIndexOrIDBCursor()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eIDBObjectStore: {
        DestroyIDBObjectStore();
        break;
      }
      case eIDBIndex: {
        DestroyIDBIndex();
        break;
      }
      case eIDBCursor: {
        DestroyIDBCursor();
        break;
      }
    }
  }

  inline NonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  SetAsIDBObjectStore()
  {
    if (mType == eIDBObjectStore) {
      return mValue.mIDBObjectStore.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eIDBObjectStore;
    return mValue.mIDBObjectStore.SetValue();
  }

  inline bool
  IsIDBObjectStore() const
  {
    return mType == eIDBObjectStore;
  }

  inline mozilla::dom::indexedDB::IDBObjectStore&
  GetAsIDBObjectStore() const
  {
    MOZ_ASSERT(IsIDBObjectStore(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::indexedDB::IDBObjectStore>&>(mValue.mIDBObjectStore.Value());
  }

  inline NonNull<mozilla::dom::indexedDB::IDBIndex>&
  SetAsIDBIndex()
  {
    if (mType == eIDBIndex) {
      return mValue.mIDBIndex.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eIDBIndex;
    return mValue.mIDBIndex.SetValue();
  }

  inline bool
  IsIDBIndex() const
  {
    return mType == eIDBIndex;
  }

  inline mozilla::dom::indexedDB::IDBIndex&
  GetAsIDBIndex() const
  {
    MOZ_ASSERT(IsIDBIndex(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::indexedDB::IDBIndex>&>(mValue.mIDBIndex.Value());
  }

  inline NonNull<mozilla::dom::indexedDB::IDBCursor>&
  SetAsIDBCursor()
  {
    if (mType == eIDBCursor) {
      return mValue.mIDBCursor.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eIDBCursor;
    return mValue.mIDBCursor.SetValue();
  }

  inline bool
  IsIDBCursor() const
  {
    return mType == eIDBCursor;
  }

  inline mozilla::dom::indexedDB::IDBCursor&
  GetAsIDBCursor() const
  {
    MOZ_ASSERT(IsIDBCursor(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::indexedDB::IDBCursor>&>(mValue.mIDBCursor.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyIDBObjectStore()
  {
    MOZ_ASSERT(IsIDBObjectStore(), "Wrong type!");
    mValue.mIDBObjectStore.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyIDBIndex()
  {
    MOZ_ASSERT(IsIDBIndex(), "Wrong type!");
    mValue.mIDBIndex.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyIDBCursor()
  {
    MOZ_ASSERT(IsIDBCursor(), "Wrong type!");
    mValue.mIDBCursor.Destroy();
    mType = eUninitialized;
  }
};

class LongOrAutoKeyword
{
  friend class LongOrAutoKeywordArgument;
  enum Type
  {
    eUninitialized,
    eLong,
    eAutoKeyword
  };
  union Value
  {
    UnionMember<int32_t > mLong;
    UnionMember<AutoKeyword > mAutoKeyword;
  };
  Type mType;
  Value mValue;

  LongOrAutoKeyword(const LongOrAutoKeyword&) MOZ_DELETE;
  void operator=(const LongOrAutoKeyword) MOZ_DELETE;

public:
  explicit inline LongOrAutoKeyword()
    : mType(eUninitialized)
  {
  }

  inline ~LongOrAutoKeyword()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eLong: {
        DestroyLong();
        break;
      }
      case eAutoKeyword: {
        DestroyAutoKeyword();
        break;
      }
    }
  }

  inline int32_t&
  SetAsLong()
  {
    if (mType == eLong) {
      return mValue.mLong.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  inline bool
  IsLong() const
  {
    return mType == eLong;
  }

  inline int32_t
  GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }

  inline AutoKeyword&
  SetAsAutoKeyword()
  {
    if (mType == eAutoKeyword) {
      return mValue.mAutoKeyword.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eAutoKeyword;
    return mValue.mAutoKeyword.SetValue();
  }

  inline bool
  IsAutoKeyword() const
  {
    return mType == eAutoKeyword;
  }

  inline AutoKeyword
  GetAsAutoKeyword() const
  {
    MOZ_ASSERT(IsAutoKeyword(), "Wrong type!");
    return const_cast<AutoKeyword&>(mValue.mAutoKeyword.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    mValue.mLong.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyAutoKeyword()
  {
    MOZ_ASSERT(IsAutoKeyword(), "Wrong type!");
    mValue.mAutoKeyword.Destroy();
    mType = eUninitialized;
  }
};

class NodeListOrElement
{
  friend class NodeListOrElementArgument;
  enum Type
  {
    eUninitialized,
    eNodeList,
    eElement
  };
  union Value
  {
    UnionMember<NonNull<nsINodeList> > mNodeList;
    UnionMember<NonNull<mozilla::dom::Element> > mElement;
  };
  Type mType;
  Value mValue;

  NodeListOrElement(const NodeListOrElement&) MOZ_DELETE;
  void operator=(const NodeListOrElement) MOZ_DELETE;

public:
  explicit inline NodeListOrElement()
    : mType(eUninitialized)
  {
  }

  inline ~NodeListOrElement()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eNodeList: {
        DestroyNodeList();
        break;
      }
      case eElement: {
        DestroyElement();
        break;
      }
    }
  }

  inline NonNull<nsINodeList>&
  SetAsNodeList()
  {
    if (mType == eNodeList) {
      return mValue.mNodeList.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eNodeList;
    return mValue.mNodeList.SetValue();
  }

  inline bool
  IsNodeList() const
  {
    return mType == eNodeList;
  }

  inline nsINodeList&
  GetAsNodeList() const
  {
    MOZ_ASSERT(IsNodeList(), "Wrong type!");
    return const_cast<NonNull<nsINodeList>&>(mValue.mNodeList.Value());
  }

  inline NonNull<mozilla::dom::Element>&
  SetAsElement()
  {
    if (mType == eElement) {
      return mValue.mElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eElement;
    return mValue.mElement.SetValue();
  }

  inline bool
  IsElement() const
  {
    return mType == eElement;
  }

  inline mozilla::dom::Element&
  GetAsElement() const
  {
    MOZ_ASSERT(IsElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::Element>&>(mValue.mElement.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyNodeList()
  {
    MOZ_ASSERT(IsNodeList(), "Wrong type!");
    mValue.mNodeList.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyElement()
  {
    MOZ_ASSERT(IsElement(), "Wrong type!");
    mValue.mElement.Destroy();
    mType = eUninitialized;
  }
};

class StringOrCanvasGradientOrCanvasPattern
{
  friend class StringOrCanvasGradientOrCanvasPatternArgument;
  enum Type
  {
    eUninitialized,
    eString,
    eCanvasGradient,
    eCanvasPattern
  };
  union Value
  {
    UnionMember<binding_detail::FakeDependentString > mString;
    UnionMember<NonNull<mozilla::dom::CanvasGradient> > mCanvasGradient;
    UnionMember<NonNull<mozilla::dom::CanvasPattern> > mCanvasPattern;
  };
  Type mType;
  Value mValue;

  StringOrCanvasGradientOrCanvasPattern(const StringOrCanvasGradientOrCanvasPattern&) MOZ_DELETE;
  void operator=(const StringOrCanvasGradientOrCanvasPattern) MOZ_DELETE;

public:
  explicit inline StringOrCanvasGradientOrCanvasPattern()
    : mType(eUninitialized)
  {
  }

  inline ~StringOrCanvasGradientOrCanvasPattern()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
      case eCanvasGradient: {
        DestroyCanvasGradient();
        break;
      }
      case eCanvasPattern: {
        DestroyCanvasPattern();
        break;
      }
    }
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    if (mType == eString) {
      return mValue.mString.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eString;
    return mValue.mString.SetValue();
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline const nsAString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<binding_detail::FakeDependentString&>(mValue.mString.Value());
  }

  inline NonNull<mozilla::dom::CanvasGradient>&
  SetAsCanvasGradient()
  {
    if (mType == eCanvasGradient) {
      return mValue.mCanvasGradient.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eCanvasGradient;
    return mValue.mCanvasGradient.SetValue();
  }

  inline bool
  IsCanvasGradient() const
  {
    return mType == eCanvasGradient;
  }

  inline mozilla::dom::CanvasGradient&
  GetAsCanvasGradient() const
  {
    MOZ_ASSERT(IsCanvasGradient(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::CanvasGradient>&>(mValue.mCanvasGradient.Value());
  }

  inline NonNull<mozilla::dom::CanvasPattern>&
  SetAsCanvasPattern()
  {
    if (mType == eCanvasPattern) {
      return mValue.mCanvasPattern.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eCanvasPattern;
    return mValue.mCanvasPattern.SetValue();
  }

  inline bool
  IsCanvasPattern() const
  {
    return mType == eCanvasPattern;
  }

  inline mozilla::dom::CanvasPattern&
  GetAsCanvasPattern() const
  {
    MOZ_ASSERT(IsCanvasPattern(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::CanvasPattern>&>(mValue.mCanvasPattern.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyCanvasGradient()
  {
    MOZ_ASSERT(IsCanvasGradient(), "Wrong type!");
    mValue.mCanvasGradient.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyCanvasPattern()
  {
    MOZ_ASSERT(IsCanvasPattern(), "Wrong type!");
    mValue.mCanvasPattern.Destroy();
    mType = eUninitialized;
  }
};

class StringOrUnsignedLong
{
  friend class StringOrUnsignedLongArgument;
  enum Type
  {
    eUninitialized,
    eString,
    eUnsignedLong
  };
  union Value
  {
    UnionMember<binding_detail::FakeDependentString > mString;
    UnionMember<uint32_t > mUnsignedLong;
  };
  Type mType;
  Value mValue;

  StringOrUnsignedLong(const StringOrUnsignedLong&) MOZ_DELETE;
  void operator=(const StringOrUnsignedLong) MOZ_DELETE;

public:
  explicit inline StringOrUnsignedLong()
    : mType(eUninitialized)
  {
  }

  inline ~StringOrUnsignedLong()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
      case eUnsignedLong: {
        DestroyUnsignedLong();
        break;
      }
    }
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    if (mType == eString) {
      return mValue.mString.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eString;
    return mValue.mString.SetValue();
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline const nsAString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<binding_detail::FakeDependentString&>(mValue.mString.Value());
  }

  inline uint32_t&
  SetAsUnsignedLong()
  {
    if (mType == eUnsignedLong) {
      return mValue.mUnsignedLong.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eUnsignedLong;
    return mValue.mUnsignedLong.SetValue();
  }

  inline bool
  IsUnsignedLong() const
  {
    return mType == eUnsignedLong;
  }

  inline uint32_t
  GetAsUnsignedLong() const
  {
    MOZ_ASSERT(IsUnsignedLong(), "Wrong type!");
    return const_cast<uint32_t&>(mValue.mUnsignedLong.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyUnsignedLong()
  {
    MOZ_ASSERT(IsUnsignedLong(), "Wrong type!");
    mValue.mUnsignedLong.Destroy();
    mType = eUninitialized;
  }
};

class TelephonyCallOrTelephonyCallGroup
{
  friend class TelephonyCallOrTelephonyCallGroupArgument;
  enum Type
  {
    eUninitialized,
    eTelephonyCall,
    eTelephonyCallGroup
  };
  union Value
  {
    UnionMember<NonNull<mozilla::dom::TelephonyCall> > mTelephonyCall;
    UnionMember<NonNull<mozilla::dom::TelephonyCallGroup> > mTelephonyCallGroup;
  };
  Type mType;
  Value mValue;

  TelephonyCallOrTelephonyCallGroup(const TelephonyCallOrTelephonyCallGroup&) MOZ_DELETE;
  void operator=(const TelephonyCallOrTelephonyCallGroup) MOZ_DELETE;

public:
  explicit inline TelephonyCallOrTelephonyCallGroup()
    : mType(eUninitialized)
  {
  }

  inline ~TelephonyCallOrTelephonyCallGroup()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eTelephonyCall: {
        DestroyTelephonyCall();
        break;
      }
      case eTelephonyCallGroup: {
        DestroyTelephonyCallGroup();
        break;
      }
    }
  }

  inline NonNull<mozilla::dom::TelephonyCall>&
  SetAsTelephonyCall()
  {
    if (mType == eTelephonyCall) {
      return mValue.mTelephonyCall.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eTelephonyCall;
    return mValue.mTelephonyCall.SetValue();
  }

  inline bool
  IsTelephonyCall() const
  {
    return mType == eTelephonyCall;
  }

  inline mozilla::dom::TelephonyCall&
  GetAsTelephonyCall() const
  {
    MOZ_ASSERT(IsTelephonyCall(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::TelephonyCall>&>(mValue.mTelephonyCall.Value());
  }

  inline NonNull<mozilla::dom::TelephonyCallGroup>&
  SetAsTelephonyCallGroup()
  {
    if (mType == eTelephonyCallGroup) {
      return mValue.mTelephonyCallGroup.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eTelephonyCallGroup;
    return mValue.mTelephonyCallGroup.SetValue();
  }

  inline bool
  IsTelephonyCallGroup() const
  {
    return mType == eTelephonyCallGroup;
  }

  inline mozilla::dom::TelephonyCallGroup&
  GetAsTelephonyCallGroup() const
  {
    MOZ_ASSERT(IsTelephonyCallGroup(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::TelephonyCallGroup>&>(mValue.mTelephonyCallGroup.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyTelephonyCall()
  {
    MOZ_ASSERT(IsTelephonyCall(), "Wrong type!");
    mValue.mTelephonyCall.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyTelephonyCallGroup()
  {
    MOZ_ASSERT(IsTelephonyCallGroup(), "Wrong type!");
    mValue.mTelephonyCallGroup.Destroy();
    mType = eUninitialized;
  }
};

class UnsignedLongOrString
{
  friend class UnsignedLongOrStringArgument;
  enum Type
  {
    eUninitialized,
    eUnsignedLong,
    eString
  };
  union Value
  {
    UnionMember<uint32_t > mUnsignedLong;
    UnionMember<binding_detail::FakeDependentString > mString;
  };
  Type mType;
  Value mValue;

  UnsignedLongOrString(const UnsignedLongOrString&) MOZ_DELETE;
  void operator=(const UnsignedLongOrString) MOZ_DELETE;

public:
  explicit inline UnsignedLongOrString()
    : mType(eUninitialized)
  {
  }

  inline ~UnsignedLongOrString()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eUnsignedLong: {
        DestroyUnsignedLong();
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
    }
  }

  inline uint32_t&
  SetAsUnsignedLong()
  {
    if (mType == eUnsignedLong) {
      return mValue.mUnsignedLong.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eUnsignedLong;
    return mValue.mUnsignedLong.SetValue();
  }

  inline bool
  IsUnsignedLong() const
  {
    return mType == eUnsignedLong;
  }

  inline uint32_t
  GetAsUnsignedLong() const
  {
    MOZ_ASSERT(IsUnsignedLong(), "Wrong type!");
    return const_cast<uint32_t&>(mValue.mUnsignedLong.Value());
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    if (mType == eString) {
      return mValue.mString.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eString;
    return mValue.mString.SetValue();
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline const nsAString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<binding_detail::FakeDependentString&>(mValue.mString.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyUnsignedLong()
  {
    MOZ_ASSERT(IsUnsignedLong(), "Wrong type!");
    mValue.mUnsignedLong.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }
};

class WindowProxyOrMessagePort
{
  friend class WindowProxyOrMessagePortArgument;
  enum Type
  {
    eUninitialized,
    eWindowProxy,
    eMessagePort
  };
  union Value
  {
    UnionMember<nsIDOMWindow* > mWindowProxy;
    UnionMember<NonNull<mozilla::dom::MessagePortBase> > mMessagePort;
  };
  Type mType;
  Value mValue;

  WindowProxyOrMessagePort(const WindowProxyOrMessagePort&) MOZ_DELETE;
  void operator=(const WindowProxyOrMessagePort) MOZ_DELETE;

public:
  explicit inline WindowProxyOrMessagePort()
    : mType(eUninitialized)
  {
  }

  inline ~WindowProxyOrMessagePort()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eWindowProxy: {
        DestroyWindowProxy();
        break;
      }
      case eMessagePort: {
        DestroyMessagePort();
        break;
      }
    }
  }

  inline nsIDOMWindow*&
  SetAsWindowProxy()
  {
    if (mType == eWindowProxy) {
      return mValue.mWindowProxy.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eWindowProxy;
    return mValue.mWindowProxy.SetValue();
  }

  inline bool
  IsWindowProxy() const
  {
    return mType == eWindowProxy;
  }

  inline nsIDOMWindow*
  GetAsWindowProxy() const
  {
    MOZ_ASSERT(IsWindowProxy(), "Wrong type!");
    return const_cast<nsIDOMWindow*&>(mValue.mWindowProxy.Value());
  }

  inline NonNull<mozilla::dom::MessagePortBase>&
  SetAsMessagePort()
  {
    if (mType == eMessagePort) {
      return mValue.mMessagePort.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eMessagePort;
    return mValue.mMessagePort.SetValue();
  }

  inline bool
  IsMessagePort() const
  {
    return mType == eMessagePort;
  }

  inline mozilla::dom::MessagePortBase&
  GetAsMessagePort() const
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::MessagePortBase>&>(mValue.mMessagePort.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyWindowProxy()
  {
    MOZ_ASSERT(IsWindowProxy(), "Wrong type!");
    mValue.mWindowProxy.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyMessagePort()
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    mValue.mMessagePort.Destroy();
    mType = eUninitialized;
  }
};

class mozContactOrString
{
  friend class mozContactOrStringArgument;
  enum Type
  {
    eUninitialized,
    emozContact,
    eString
  };
  union Value
  {
    UnionMember<NonNull<mozilla::dom::mozContact> > mmozContact;
    UnionMember<binding_detail::FakeDependentString > mString;
  };
  Type mType;
  Value mValue;

  mozContactOrString(const mozContactOrString&) MOZ_DELETE;
  void operator=(const mozContactOrString) MOZ_DELETE;

public:
  explicit inline mozContactOrString()
    : mType(eUninitialized)
  {
  }

  inline ~mozContactOrString()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case emozContact: {
        DestroymozContact();
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
    }
  }

  inline NonNull<mozilla::dom::mozContact>&
  SetAsmozContact()
  {
    if (mType == emozContact) {
      return mValue.mmozContact.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = emozContact;
    return mValue.mmozContact.SetValue();
  }

  inline bool
  IsmozContact() const
  {
    return mType == emozContact;
  }

  inline mozilla::dom::mozContact&
  GetAsmozContact() const
  {
    MOZ_ASSERT(IsmozContact(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::mozContact>&>(mValue.mmozContact.Value());
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    if (mType == eString) {
      return mValue.mString.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eString;
    return mValue.mString.SetValue();
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline const nsAString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<binding_detail::FakeDependentString&>(mValue.mString.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroymozContact()
  {
    MOZ_ASSERT(IsmozContact(), "Wrong type!");
    mValue.mmozContact.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }
};

class OwningArrayBufferViewOrBlobOrStringOrFormData : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eArrayBufferView,
    eBlob,
    eString,
    eFormData
  };
  union Value
  {
    UnionMember<ArrayBufferView > mArrayBufferView;
    UnionMember<nsRefPtr<nsIDOMBlob> > mBlob;
    UnionMember<nsString > mString;
    UnionMember<OwningNonNull<nsFormData> > mFormData;
  };
  Type mType;
  Value mValue;

  OwningArrayBufferViewOrBlobOrStringOrFormData(const OwningArrayBufferViewOrBlobOrStringOrFormData&) MOZ_DELETE;
  void operator=(const OwningArrayBufferViewOrBlobOrStringOrFormData) MOZ_DELETE;

public:
  explicit inline OwningArrayBufferViewOrBlobOrStringOrFormData()
    : mType(eUninitialized)
  {
  }

  ~OwningArrayBufferViewOrBlobOrStringOrFormData();

  ArrayBufferView&
  SetAsArrayBufferView();

  bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsArrayBufferView() const
  {
    return mType == eArrayBufferView;
  }

  inline ArrayBufferView&
  GetAsArrayBufferView() const
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return const_cast<ArrayBufferView&>(mValue.mArrayBufferView.Value());
  }

  nsRefPtr<nsIDOMBlob>&
  SetAsBlob();

  bool
  TrySetToBlob(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsBlob() const
  {
    return mType == eBlob;
  }

  inline nsRefPtr<nsIDOMBlob>&
  GetAsBlob() const
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return const_cast<nsRefPtr<nsIDOMBlob>&>(mValue.mBlob.Value());
  }

  nsString&
  SetAsString();

  bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline void
  SetStringData(const nsString::char_type* aData, nsString::size_type aLength)
  {
    SetAsString().Assign(aData, aLength);
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline nsString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<nsString&>(mValue.mString.Value());
  }

  OwningNonNull<nsFormData>&
  SetAsFormData();

  bool
  TrySetToFormData(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsFormData() const
  {
    return mType == eFormData;
  }

  inline OwningNonNull<nsFormData>&
  GetAsFormData() const
  {
    MOZ_ASSERT(IsFormData(), "Wrong type!");
    return const_cast<OwningNonNull<nsFormData>&>(mValue.mFormData.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyArrayBufferView();

  void
  DestroyBlob();

  void
  DestroyString();

  void
  DestroyFormData();
};

class OwningBooleanOrObject : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eBoolean,
    eObject
  };
  union Value
  {
    UnionMember<bool > mBoolean;
    UnionMember<JSObject* > mObject;
  };
  Type mType;
  Value mValue;

  OwningBooleanOrObject(const OwningBooleanOrObject&) MOZ_DELETE;
  void operator=(const OwningBooleanOrObject) MOZ_DELETE;

public:
  explicit inline OwningBooleanOrObject()
    : mType(eUninitialized)
  {
  }

  ~OwningBooleanOrObject();

  bool&
  SetAsBoolean();

  bool
  TrySetToBoolean(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsBoolean() const
  {
    return mType == eBoolean;
  }

  inline bool&
  GetAsBoolean() const
  {
    MOZ_ASSERT(IsBoolean(), "Wrong type!");
    return const_cast<bool&>(mValue.mBoolean.Value());
  }

  JSObject*&
  SetAsObject();

  inline void
  SetToObject(JSContext* cx, JSObject* obj)
  {
    MOZ_ASSERT(mType == eUninitialized);
    mValue.mObject.SetValue(obj);
    mType = eObject;
  }

  inline bool
  IsObject() const
  {
    return mType == eObject;
  }

  inline JSObject*&
  GetAsObject() const
  {
    MOZ_ASSERT(IsObject(), "Wrong type!");
    return const_cast<JSObject*&>(mValue.mObject.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyBoolean();

  void
  DestroyObject();
};

class OwningEventOrString : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eEvent,
    eString
  };
  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::Event> > mEvent;
    UnionMember<nsString > mString;
  };
  Type mType;
  Value mValue;

  OwningEventOrString(const OwningEventOrString&) MOZ_DELETE;
  void operator=(const OwningEventOrString) MOZ_DELETE;

public:
  explicit inline OwningEventOrString()
    : mType(eUninitialized)
  {
  }

  ~OwningEventOrString();

  OwningNonNull<mozilla::dom::Event>&
  SetAsEvent();

  bool
  TrySetToEvent(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsEvent() const
  {
    return mType == eEvent;
  }

  inline OwningNonNull<mozilla::dom::Event>&
  GetAsEvent() const
  {
    MOZ_ASSERT(IsEvent(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::Event>&>(mValue.mEvent.Value());
  }

  nsString&
  SetAsString();

  bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline void
  SetStringData(const nsString::char_type* aData, nsString::size_type aLength)
  {
    SetAsString().Assign(aData, aLength);
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline nsString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<nsString&>(mValue.mString.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyEvent();

  void
  DestroyString();
};

class OwningHTMLElementOrLong : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eHTMLElement,
    eLong
  };
  union Value
  {
    UnionMember<OwningNonNull<nsGenericHTMLElement> > mHTMLElement;
    UnionMember<int32_t > mLong;
  };
  Type mType;
  Value mValue;

  OwningHTMLElementOrLong(const OwningHTMLElementOrLong&) MOZ_DELETE;
  void operator=(const OwningHTMLElementOrLong) MOZ_DELETE;

public:
  explicit inline OwningHTMLElementOrLong()
    : mType(eUninitialized)
  {
  }

  ~OwningHTMLElementOrLong();

  OwningNonNull<nsGenericHTMLElement>&
  SetAsHTMLElement();

  bool
  TrySetToHTMLElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsHTMLElement() const
  {
    return mType == eHTMLElement;
  }

  inline OwningNonNull<nsGenericHTMLElement>&
  GetAsHTMLElement() const
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    return const_cast<OwningNonNull<nsGenericHTMLElement>&>(mValue.mHTMLElement.Value());
  }

  int32_t&
  SetAsLong();

  bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsLong() const
  {
    return mType == eLong;
  }

  inline int32_t&
  GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyHTMLElement();

  void
  DestroyLong();
};

class OwningHTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eHTMLImageElement,
    eHTMLCanvasElement,
    eHTMLVideoElement
  };
  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::HTMLImageElement> > mHTMLImageElement;
    UnionMember<OwningNonNull<mozilla::dom::HTMLCanvasElement> > mHTMLCanvasElement;
    UnionMember<OwningNonNull<mozilla::dom::HTMLVideoElement> > mHTMLVideoElement;
  };
  Type mType;
  Value mValue;

  OwningHTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement(const OwningHTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement&) MOZ_DELETE;
  void operator=(const OwningHTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement) MOZ_DELETE;

public:
  explicit inline OwningHTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement()
    : mType(eUninitialized)
  {
  }

  ~OwningHTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement();

  OwningNonNull<mozilla::dom::HTMLImageElement>&
  SetAsHTMLImageElement();

  bool
  TrySetToHTMLImageElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsHTMLImageElement() const
  {
    return mType == eHTMLImageElement;
  }

  inline OwningNonNull<mozilla::dom::HTMLImageElement>&
  GetAsHTMLImageElement() const
  {
    MOZ_ASSERT(IsHTMLImageElement(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::HTMLImageElement>&>(mValue.mHTMLImageElement.Value());
  }

  OwningNonNull<mozilla::dom::HTMLCanvasElement>&
  SetAsHTMLCanvasElement();

  bool
  TrySetToHTMLCanvasElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsHTMLCanvasElement() const
  {
    return mType == eHTMLCanvasElement;
  }

  inline OwningNonNull<mozilla::dom::HTMLCanvasElement>&
  GetAsHTMLCanvasElement() const
  {
    MOZ_ASSERT(IsHTMLCanvasElement(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::HTMLCanvasElement>&>(mValue.mHTMLCanvasElement.Value());
  }

  OwningNonNull<mozilla::dom::HTMLVideoElement>&
  SetAsHTMLVideoElement();

  bool
  TrySetToHTMLVideoElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsHTMLVideoElement() const
  {
    return mType == eHTMLVideoElement;
  }

  inline OwningNonNull<mozilla::dom::HTMLVideoElement>&
  GetAsHTMLVideoElement() const
  {
    MOZ_ASSERT(IsHTMLVideoElement(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::HTMLVideoElement>&>(mValue.mHTMLVideoElement.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyHTMLImageElement();

  void
  DestroyHTMLCanvasElement();

  void
  DestroyHTMLVideoElement();
};

class OwningHTMLOptionElementOrHTMLOptGroupElement : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eHTMLOptionElement,
    eHTMLOptGroupElement
  };
  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::HTMLOptionElement> > mHTMLOptionElement;
    UnionMember<OwningNonNull<mozilla::dom::HTMLOptGroupElement> > mHTMLOptGroupElement;
  };
  Type mType;
  Value mValue;

  OwningHTMLOptionElementOrHTMLOptGroupElement(const OwningHTMLOptionElementOrHTMLOptGroupElement&) MOZ_DELETE;
  void operator=(const OwningHTMLOptionElementOrHTMLOptGroupElement) MOZ_DELETE;

public:
  explicit inline OwningHTMLOptionElementOrHTMLOptGroupElement()
    : mType(eUninitialized)
  {
  }

  ~OwningHTMLOptionElementOrHTMLOptGroupElement();

  OwningNonNull<mozilla::dom::HTMLOptionElement>&
  SetAsHTMLOptionElement();

  bool
  TrySetToHTMLOptionElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsHTMLOptionElement() const
  {
    return mType == eHTMLOptionElement;
  }

  inline OwningNonNull<mozilla::dom::HTMLOptionElement>&
  GetAsHTMLOptionElement() const
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::HTMLOptionElement>&>(mValue.mHTMLOptionElement.Value());
  }

  OwningNonNull<mozilla::dom::HTMLOptGroupElement>&
  SetAsHTMLOptGroupElement();

  bool
  TrySetToHTMLOptGroupElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsHTMLOptGroupElement() const
  {
    return mType == eHTMLOptGroupElement;
  }

  inline OwningNonNull<mozilla::dom::HTMLOptGroupElement>&
  GetAsHTMLOptGroupElement() const
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::HTMLOptGroupElement>&>(mValue.mHTMLOptGroupElement.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyHTMLOptionElement();

  void
  DestroyHTMLOptGroupElement();
};

class OwningIDBObjectStoreOrIDBIndex : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eIDBObjectStore,
    eIDBIndex
  };
  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::indexedDB::IDBObjectStore> > mIDBObjectStore;
    UnionMember<OwningNonNull<mozilla::dom::indexedDB::IDBIndex> > mIDBIndex;
  };
  Type mType;
  Value mValue;

  OwningIDBObjectStoreOrIDBIndex(const OwningIDBObjectStoreOrIDBIndex&) MOZ_DELETE;
  void operator=(const OwningIDBObjectStoreOrIDBIndex) MOZ_DELETE;

public:
  explicit inline OwningIDBObjectStoreOrIDBIndex()
    : mType(eUninitialized)
  {
  }

  ~OwningIDBObjectStoreOrIDBIndex();

  OwningNonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  SetAsIDBObjectStore();

  bool
  TrySetToIDBObjectStore(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsIDBObjectStore() const
  {
    return mType == eIDBObjectStore;
  }

  inline OwningNonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  GetAsIDBObjectStore() const
  {
    MOZ_ASSERT(IsIDBObjectStore(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::indexedDB::IDBObjectStore>&>(mValue.mIDBObjectStore.Value());
  }

  OwningNonNull<mozilla::dom::indexedDB::IDBIndex>&
  SetAsIDBIndex();

  bool
  TrySetToIDBIndex(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsIDBIndex() const
  {
    return mType == eIDBIndex;
  }

  inline OwningNonNull<mozilla::dom::indexedDB::IDBIndex>&
  GetAsIDBIndex() const
  {
    MOZ_ASSERT(IsIDBIndex(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::indexedDB::IDBIndex>&>(mValue.mIDBIndex.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyIDBObjectStore();

  void
  DestroyIDBIndex();
};

class OwningIDBObjectStoreOrIDBIndexOrIDBCursor : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eIDBObjectStore,
    eIDBIndex,
    eIDBCursor
  };
  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::indexedDB::IDBObjectStore> > mIDBObjectStore;
    UnionMember<OwningNonNull<mozilla::dom::indexedDB::IDBIndex> > mIDBIndex;
    UnionMember<OwningNonNull<mozilla::dom::indexedDB::IDBCursor> > mIDBCursor;
  };
  Type mType;
  Value mValue;

  OwningIDBObjectStoreOrIDBIndexOrIDBCursor(const OwningIDBObjectStoreOrIDBIndexOrIDBCursor&) MOZ_DELETE;
  void operator=(const OwningIDBObjectStoreOrIDBIndexOrIDBCursor) MOZ_DELETE;

public:
  explicit inline OwningIDBObjectStoreOrIDBIndexOrIDBCursor()
    : mType(eUninitialized)
  {
  }

  ~OwningIDBObjectStoreOrIDBIndexOrIDBCursor();

  OwningNonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  SetAsIDBObjectStore();

  bool
  TrySetToIDBObjectStore(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsIDBObjectStore() const
  {
    return mType == eIDBObjectStore;
  }

  inline OwningNonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  GetAsIDBObjectStore() const
  {
    MOZ_ASSERT(IsIDBObjectStore(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::indexedDB::IDBObjectStore>&>(mValue.mIDBObjectStore.Value());
  }

  OwningNonNull<mozilla::dom::indexedDB::IDBIndex>&
  SetAsIDBIndex();

  bool
  TrySetToIDBIndex(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsIDBIndex() const
  {
    return mType == eIDBIndex;
  }

  inline OwningNonNull<mozilla::dom::indexedDB::IDBIndex>&
  GetAsIDBIndex() const
  {
    MOZ_ASSERT(IsIDBIndex(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::indexedDB::IDBIndex>&>(mValue.mIDBIndex.Value());
  }

  OwningNonNull<mozilla::dom::indexedDB::IDBCursor>&
  SetAsIDBCursor();

  bool
  TrySetToIDBCursor(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsIDBCursor() const
  {
    return mType == eIDBCursor;
  }

  inline OwningNonNull<mozilla::dom::indexedDB::IDBCursor>&
  GetAsIDBCursor() const
  {
    MOZ_ASSERT(IsIDBCursor(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::indexedDB::IDBCursor>&>(mValue.mIDBCursor.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyIDBObjectStore();

  void
  DestroyIDBIndex();

  void
  DestroyIDBCursor();
};

class OwningLongOrAutoKeyword : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eLong,
    eAutoKeyword
  };
  union Value
  {
    UnionMember<int32_t > mLong;
    UnionMember<AutoKeyword > mAutoKeyword;
  };
  Type mType;
  Value mValue;

public:
  explicit inline OwningLongOrAutoKeyword()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningLongOrAutoKeyword(const OwningLongOrAutoKeyword& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  ~OwningLongOrAutoKeyword();

  int32_t&
  SetAsLong();

  bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsLong() const
  {
    return mType == eLong;
  }

  inline int32_t&
  GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }

  AutoKeyword&
  SetAsAutoKeyword();

  bool
  TrySetToAutoKeyword(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsAutoKeyword() const
  {
    return mType == eAutoKeyword;
  }

  inline AutoKeyword&
  GetAsAutoKeyword() const
  {
    MOZ_ASSERT(IsAutoKeyword(), "Wrong type!");
    return const_cast<AutoKeyword&>(mValue.mAutoKeyword.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningLongOrAutoKeyword& aOther);

private:
  void
  DestroyLong();

  void
  DestroyAutoKeyword();
};

class OwningNodeListOrElement : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eNodeList,
    eElement
  };
  union Value
  {
    UnionMember<OwningNonNull<nsINodeList> > mNodeList;
    UnionMember<OwningNonNull<mozilla::dom::Element> > mElement;
  };
  Type mType;
  Value mValue;

  OwningNodeListOrElement(const OwningNodeListOrElement&) MOZ_DELETE;
  void operator=(const OwningNodeListOrElement) MOZ_DELETE;

public:
  explicit inline OwningNodeListOrElement()
    : mType(eUninitialized)
  {
  }

  ~OwningNodeListOrElement();

  OwningNonNull<nsINodeList>&
  SetAsNodeList();

  bool
  TrySetToNodeList(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsNodeList() const
  {
    return mType == eNodeList;
  }

  inline OwningNonNull<nsINodeList>&
  GetAsNodeList() const
  {
    MOZ_ASSERT(IsNodeList(), "Wrong type!");
    return const_cast<OwningNonNull<nsINodeList>&>(mValue.mNodeList.Value());
  }

  OwningNonNull<mozilla::dom::Element>&
  SetAsElement();

  bool
  TrySetToElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsElement() const
  {
    return mType == eElement;
  }

  inline OwningNonNull<mozilla::dom::Element>&
  GetAsElement() const
  {
    MOZ_ASSERT(IsElement(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::Element>&>(mValue.mElement.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyNodeList();

  void
  DestroyElement();
};

class OwningStringOrCanvasGradientOrCanvasPattern : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eString,
    eCanvasGradient,
    eCanvasPattern
  };
  union Value
  {
    UnionMember<nsString > mString;
    UnionMember<OwningNonNull<mozilla::dom::CanvasGradient> > mCanvasGradient;
    UnionMember<OwningNonNull<mozilla::dom::CanvasPattern> > mCanvasPattern;
  };
  Type mType;
  Value mValue;

  OwningStringOrCanvasGradientOrCanvasPattern(const OwningStringOrCanvasGradientOrCanvasPattern&) MOZ_DELETE;
  void operator=(const OwningStringOrCanvasGradientOrCanvasPattern) MOZ_DELETE;

public:
  explicit inline OwningStringOrCanvasGradientOrCanvasPattern()
    : mType(eUninitialized)
  {
  }

  ~OwningStringOrCanvasGradientOrCanvasPattern();

  nsString&
  SetAsString();

  bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline void
  SetStringData(const nsString::char_type* aData, nsString::size_type aLength)
  {
    SetAsString().Assign(aData, aLength);
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline nsString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<nsString&>(mValue.mString.Value());
  }

  OwningNonNull<mozilla::dom::CanvasGradient>&
  SetAsCanvasGradient();

  bool
  TrySetToCanvasGradient(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsCanvasGradient() const
  {
    return mType == eCanvasGradient;
  }

  inline OwningNonNull<mozilla::dom::CanvasGradient>&
  GetAsCanvasGradient() const
  {
    MOZ_ASSERT(IsCanvasGradient(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::CanvasGradient>&>(mValue.mCanvasGradient.Value());
  }

  OwningNonNull<mozilla::dom::CanvasPattern>&
  SetAsCanvasPattern();

  bool
  TrySetToCanvasPattern(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsCanvasPattern() const
  {
    return mType == eCanvasPattern;
  }

  inline OwningNonNull<mozilla::dom::CanvasPattern>&
  GetAsCanvasPattern() const
  {
    MOZ_ASSERT(IsCanvasPattern(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::CanvasPattern>&>(mValue.mCanvasPattern.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyString();

  void
  DestroyCanvasGradient();

  void
  DestroyCanvasPattern();
};

class OwningStringOrUnsignedLong : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eString,
    eUnsignedLong
  };
  union Value
  {
    UnionMember<nsString > mString;
    UnionMember<uint32_t > mUnsignedLong;
  };
  Type mType;
  Value mValue;

public:
  explicit inline OwningStringOrUnsignedLong()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningStringOrUnsignedLong(const OwningStringOrUnsignedLong& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  ~OwningStringOrUnsignedLong();

  nsString&
  SetAsString();

  bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline void
  SetStringData(const nsString::char_type* aData, nsString::size_type aLength)
  {
    SetAsString().Assign(aData, aLength);
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline nsString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<nsString&>(mValue.mString.Value());
  }

  uint32_t&
  SetAsUnsignedLong();

  bool
  TrySetToUnsignedLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsUnsignedLong() const
  {
    return mType == eUnsignedLong;
  }

  inline uint32_t&
  GetAsUnsignedLong() const
  {
    MOZ_ASSERT(IsUnsignedLong(), "Wrong type!");
    return const_cast<uint32_t&>(mValue.mUnsignedLong.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningStringOrUnsignedLong& aOther);

private:
  void
  DestroyString();

  void
  DestroyUnsignedLong();
};

class OwningTelephonyCallOrTelephonyCallGroup : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eTelephonyCall,
    eTelephonyCallGroup
  };
  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::TelephonyCall> > mTelephonyCall;
    UnionMember<OwningNonNull<mozilla::dom::TelephonyCallGroup> > mTelephonyCallGroup;
  };
  Type mType;
  Value mValue;

  OwningTelephonyCallOrTelephonyCallGroup(const OwningTelephonyCallOrTelephonyCallGroup&) MOZ_DELETE;
  void operator=(const OwningTelephonyCallOrTelephonyCallGroup) MOZ_DELETE;

public:
  explicit inline OwningTelephonyCallOrTelephonyCallGroup()
    : mType(eUninitialized)
  {
  }

  ~OwningTelephonyCallOrTelephonyCallGroup();

  OwningNonNull<mozilla::dom::TelephonyCall>&
  SetAsTelephonyCall();

  bool
  TrySetToTelephonyCall(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsTelephonyCall() const
  {
    return mType == eTelephonyCall;
  }

  inline OwningNonNull<mozilla::dom::TelephonyCall>&
  GetAsTelephonyCall() const
  {
    MOZ_ASSERT(IsTelephonyCall(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::TelephonyCall>&>(mValue.mTelephonyCall.Value());
  }

  OwningNonNull<mozilla::dom::TelephonyCallGroup>&
  SetAsTelephonyCallGroup();

  bool
  TrySetToTelephonyCallGroup(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsTelephonyCallGroup() const
  {
    return mType == eTelephonyCallGroup;
  }

  inline OwningNonNull<mozilla::dom::TelephonyCallGroup>&
  GetAsTelephonyCallGroup() const
  {
    MOZ_ASSERT(IsTelephonyCallGroup(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::TelephonyCallGroup>&>(mValue.mTelephonyCallGroup.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyTelephonyCall();

  void
  DestroyTelephonyCallGroup();
};

class OwningUnsignedLongOrString : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eUnsignedLong,
    eString
  };
  union Value
  {
    UnionMember<uint32_t > mUnsignedLong;
    UnionMember<nsString > mString;
  };
  Type mType;
  Value mValue;

public:
  explicit inline OwningUnsignedLongOrString()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningUnsignedLongOrString(const OwningUnsignedLongOrString& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  ~OwningUnsignedLongOrString();

  uint32_t&
  SetAsUnsignedLong();

  bool
  TrySetToUnsignedLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsUnsignedLong() const
  {
    return mType == eUnsignedLong;
  }

  inline uint32_t&
  GetAsUnsignedLong() const
  {
    MOZ_ASSERT(IsUnsignedLong(), "Wrong type!");
    return const_cast<uint32_t&>(mValue.mUnsignedLong.Value());
  }

  nsString&
  SetAsString();

  bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline void
  SetStringData(const nsString::char_type* aData, nsString::size_type aLength)
  {
    SetAsString().Assign(aData, aLength);
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline nsString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<nsString&>(mValue.mString.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningUnsignedLongOrString& aOther);

private:
  void
  DestroyUnsignedLong();

  void
  DestroyString();
};

class OwningWindowProxyOrMessagePort : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    eWindowProxy,
    eMessagePort
  };
  union Value
  {
    UnionMember<nsRefPtr<nsIDOMWindow> > mWindowProxy;
    UnionMember<OwningNonNull<mozilla::dom::MessagePortBase> > mMessagePort;
  };
  Type mType;
  Value mValue;

  OwningWindowProxyOrMessagePort(const OwningWindowProxyOrMessagePort&) MOZ_DELETE;
  void operator=(const OwningWindowProxyOrMessagePort) MOZ_DELETE;

public:
  explicit inline OwningWindowProxyOrMessagePort()
    : mType(eUninitialized)
  {
  }

  ~OwningWindowProxyOrMessagePort();

  nsRefPtr<nsIDOMWindow>&
  SetAsWindowProxy();

  bool
  TrySetToWindowProxy(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsWindowProxy() const
  {
    return mType == eWindowProxy;
  }

  inline nsRefPtr<nsIDOMWindow>&
  GetAsWindowProxy() const
  {
    MOZ_ASSERT(IsWindowProxy(), "Wrong type!");
    return const_cast<nsRefPtr<nsIDOMWindow>&>(mValue.mWindowProxy.Value());
  }

  OwningNonNull<mozilla::dom::MessagePortBase>&
  SetAsMessagePort();

  bool
  TrySetToMessagePort(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsMessagePort() const
  {
    return mType == eMessagePort;
  }

  inline OwningNonNull<mozilla::dom::MessagePortBase>&
  GetAsMessagePort() const
  {
    MOZ_ASSERT(IsMessagePort(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::MessagePortBase>&>(mValue.mMessagePort.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyWindowProxy();

  void
  DestroyMessagePort();
};

class OwningmozContactOrString : public AllOwningUnionBase
{
  enum Type
  {
    eUninitialized,
    emozContact,
    eString
  };
  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::mozContact> > mmozContact;
    UnionMember<nsString > mString;
  };
  Type mType;
  Value mValue;

  OwningmozContactOrString(const OwningmozContactOrString&) MOZ_DELETE;
  void operator=(const OwningmozContactOrString) MOZ_DELETE;

public:
  explicit inline OwningmozContactOrString()
    : mType(eUninitialized)
  {
  }

  ~OwningmozContactOrString();

  OwningNonNull<mozilla::dom::mozContact>&
  SetAsmozContact();

  bool
  TrySetTomozContact(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline bool
  IsmozContact() const
  {
    return mType == emozContact;
  }

  inline OwningNonNull<mozilla::dom::mozContact>&
  GetAsmozContact() const
  {
    MOZ_ASSERT(IsmozContact(), "Wrong type!");
    return const_cast<OwningNonNull<mozilla::dom::mozContact>&>(mValue.mmozContact.Value());
  }

  nsString&
  SetAsString();

  bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext);

  inline void
  SetStringData(const nsString::char_type* aData, nsString::size_type aLength)
  {
    SetAsString().Assign(aData, aLength);
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline nsString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<nsString&>(mValue.mString.Value());
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroymozContact();

  void
  DestroyString();
};
} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionTypes_h__
