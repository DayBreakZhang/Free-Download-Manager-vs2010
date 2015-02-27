#ifndef mozilla_dom_UnionConversions_h__
#define mozilla_dom_UnionConversions_h__

#include "CanvasRenderingContext2DBinding.h"
#include "ContactsBinding.h"
#include "ElementBinding.h"
#include "EventBinding.h"
#include "FormDataBinding.h"
#include "HTMLCanvasElementBinding.h"
#include "HTMLElementBinding.h"
#include "HTMLImageElementBinding.h"
#include "HTMLOptGroupElementBinding.h"
#include "HTMLOptionElementBinding.h"
#include "HTMLVideoElementBinding.h"
#include "IDBCursorBinding.h"
#include "IDBIndexBinding.h"
#include "IDBObjectStoreBinding.h"
#include "MessagePortBinding.h"
#include "NodeListBinding.h"
#include "TelephonyCallBinding.h"
#include "TelephonyCallGroupBinding.h"
#include "jsfriendapi.h"
#include "mozilla/dom/PrimitiveConversions.h"
#include "mozilla/dom/TypedArray.h"
#include "mozilla/dom/UnionTypes.h"
#include "nsDebug.h"
#include "nsIDOMFile.h"
#include "nsIDOMWindow.h"

namespace mozilla {
namespace dom {
class ArrayBufferViewOrBlobOrStringOrFormDataArgument
{
  ArrayBufferViewOrBlobOrStringOrFormData& mUnion;
  nsRefPtr<nsIDOMBlob> mBlobHolder;

  ArrayBufferViewOrBlobOrStringOrFormDataArgument(const ArrayBufferViewOrBlobOrStringOrFormDataArgument&) MOZ_DELETE;
  void operator=(const ArrayBufferViewOrBlobOrStringOrFormDataArgument) MOZ_DELETE;

public:
  explicit inline ArrayBufferViewOrBlobOrStringOrFormDataArgument(const ArrayBufferViewOrBlobOrStringOrFormData& aUnion)
    : mUnion(const_cast<ArrayBufferViewOrBlobOrStringOrFormData&>(aUnion))
  {
  }

  inline bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBufferView >& memberSlot = SetAsArrayBufferView(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBufferView();
        tryNext = true;
        return true;
      }

    }
    return true;
  }

  inline bool
  TrySetToBlob(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      nsIDOMBlob*& memberSlot = SetAsBlob();
      JS::Rooted<JS::Value> tmpVal(cx, value);
      nsIDOMBlob* tmp;
      if (NS_FAILED(UnwrapArg<nsIDOMBlob>(cx, value, &tmp, static_cast<nsIDOMBlob**>(getter_AddRefs(mBlobHolder)), &tmpVal))) {
        mUnion.DestroyBlob();
        tryNext = true;
        return true;
      }
      MOZ_ASSERT(tmp);
      memberSlot = tmp;
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeDependentString& memberSlot = SetAsString();
      if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    SetAsString().SetData(aData, aLength);
  }

  inline bool
  TrySetToFormData(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsFormData>& memberSlot = SetAsFormData();
      {
        nsresult rv = UnwrapObject<prototypes::id::FormData, nsFormData>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyFormData();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline RootedTypedArray<ArrayBufferView >&
  SetAsArrayBufferView(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBufferView;
    return mUnion.mValue.mArrayBufferView.SetValue(cx);
  }

  inline nsIDOMBlob*&
  SetAsBlob()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eBlob;
    return mUnion.mValue.mBlob.SetValue();
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline NonNull<nsFormData>&
  SetAsFormData()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eFormData;
    return mUnion.mValue.mFormData.SetValue();
  }
};

class BooleanOrObjectArgument
{
  BooleanOrObject& mUnion;

  BooleanOrObjectArgument(const BooleanOrObjectArgument&) MOZ_DELETE;
  void operator=(const BooleanOrObjectArgument) MOZ_DELETE;

public:
  explicit inline BooleanOrObjectArgument(const BooleanOrObject& aUnion)
    : mUnion(const_cast<BooleanOrObject&>(aUnion))
  {
  }

  inline bool
  TrySetToBoolean(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      bool& memberSlot = SetAsBoolean();
      if (!ValueToPrimitive<bool, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetToObject(JSContext* cx, JSObject* obj)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mValue.mObject.SetValue(cx, obj);
    mUnion.mType = mUnion.eObject;
  }

private:
  inline bool&
  SetAsBoolean()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eBoolean;
    return mUnion.mValue.mBoolean.SetValue();
  }
};

class EventOrStringArgument
{
  EventOrString& mUnion;

  EventOrStringArgument(const EventOrStringArgument&) MOZ_DELETE;
  void operator=(const EventOrStringArgument) MOZ_DELETE;

public:
  explicit inline EventOrStringArgument(const EventOrString& aUnion)
    : mUnion(const_cast<EventOrString&>(aUnion))
  {
  }

  inline bool
  TrySetToEvent(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Event>& memberSlot = SetAsEvent();
      {
        nsresult rv = UnwrapObject<prototypes::id::Event, mozilla::dom::Event>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyEvent();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeDependentString& memberSlot = SetAsString();
      if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    SetAsString().SetData(aData, aLength);
  }

private:
  inline NonNull<mozilla::dom::Event>&
  SetAsEvent()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eEvent;
    return mUnion.mValue.mEvent.SetValue();
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
};

class HTMLElementOrLongArgument
{
  HTMLElementOrLong& mUnion;

  HTMLElementOrLongArgument(const HTMLElementOrLongArgument&) MOZ_DELETE;
  void operator=(const HTMLElementOrLongArgument) MOZ_DELETE;

public:
  explicit inline HTMLElementOrLongArgument(const HTMLElementOrLong& aUnion)
    : mUnion(const_cast<HTMLElementOrLong&>(aUnion))
  {
  }

  inline bool
  TrySetToHTMLElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsGenericHTMLElement>& memberSlot = SetAsHTMLElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLElement, nsGenericHTMLElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      int32_t& memberSlot = SetAsLong();
      if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

private:
  inline NonNull<nsGenericHTMLElement>&
  SetAsHTMLElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLElement;
    return mUnion.mValue.mHTMLElement.SetValue();
  }

  inline int32_t&
  SetAsLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }
};

class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument
{
  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& mUnion;

  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument&) MOZ_DELETE;
  void operator=(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument) MOZ_DELETE;

public:
  explicit inline HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& aUnion)
    : mUnion(const_cast<HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement&>(aUnion))
  {
  }

  inline bool
  TrySetToHTMLImageElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLImageElement>& memberSlot = SetAsHTMLImageElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLImageElement, mozilla::dom::HTMLImageElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLImageElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToHTMLCanvasElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLCanvasElement>& memberSlot = SetAsHTMLCanvasElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLCanvasElement, mozilla::dom::HTMLCanvasElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLCanvasElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToHTMLVideoElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLVideoElement>& memberSlot = SetAsHTMLVideoElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLVideoElement, mozilla::dom::HTMLVideoElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLVideoElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::HTMLImageElement>&
  SetAsHTMLImageElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLImageElement;
    return mUnion.mValue.mHTMLImageElement.SetValue();
  }

  inline NonNull<mozilla::dom::HTMLCanvasElement>&
  SetAsHTMLCanvasElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLCanvasElement;
    return mUnion.mValue.mHTMLCanvasElement.SetValue();
  }

  inline NonNull<mozilla::dom::HTMLVideoElement>&
  SetAsHTMLVideoElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLVideoElement;
    return mUnion.mValue.mHTMLVideoElement.SetValue();
  }
};

class HTMLOptionElementOrHTMLOptGroupElementArgument
{
  HTMLOptionElementOrHTMLOptGroupElement& mUnion;

  HTMLOptionElementOrHTMLOptGroupElementArgument(const HTMLOptionElementOrHTMLOptGroupElementArgument&) MOZ_DELETE;
  void operator=(const HTMLOptionElementOrHTMLOptGroupElementArgument) MOZ_DELETE;

public:
  explicit inline HTMLOptionElementOrHTMLOptGroupElementArgument(const HTMLOptionElementOrHTMLOptGroupElement& aUnion)
    : mUnion(const_cast<HTMLOptionElementOrHTMLOptGroupElement&>(aUnion))
  {
  }

  inline bool
  TrySetToHTMLOptionElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLOptionElement>& memberSlot = SetAsHTMLOptionElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLOptionElement, mozilla::dom::HTMLOptionElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLOptionElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToHTMLOptGroupElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLOptGroupElement>& memberSlot = SetAsHTMLOptGroupElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLOptGroupElement, mozilla::dom::HTMLOptGroupElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLOptGroupElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::HTMLOptionElement>&
  SetAsHTMLOptionElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLOptionElement;
    return mUnion.mValue.mHTMLOptionElement.SetValue();
  }

  inline NonNull<mozilla::dom::HTMLOptGroupElement>&
  SetAsHTMLOptGroupElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLOptGroupElement;
    return mUnion.mValue.mHTMLOptGroupElement.SetValue();
  }
};

class IDBObjectStoreOrIDBIndexArgument
{
  IDBObjectStoreOrIDBIndex& mUnion;

  IDBObjectStoreOrIDBIndexArgument(const IDBObjectStoreOrIDBIndexArgument&) MOZ_DELETE;
  void operator=(const IDBObjectStoreOrIDBIndexArgument) MOZ_DELETE;

public:
  explicit inline IDBObjectStoreOrIDBIndexArgument(const IDBObjectStoreOrIDBIndex& aUnion)
    : mUnion(const_cast<IDBObjectStoreOrIDBIndex&>(aUnion))
  {
  }

  inline bool
  TrySetToIDBObjectStore(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBObjectStore>& memberSlot = SetAsIDBObjectStore();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBObjectStore, mozilla::dom::indexedDB::IDBObjectStore>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBObjectStore();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToIDBIndex(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBIndex>& memberSlot = SetAsIDBIndex();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBIndex, mozilla::dom::indexedDB::IDBIndex>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBIndex();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  SetAsIDBObjectStore()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBObjectStore;
    return mUnion.mValue.mIDBObjectStore.SetValue();
  }

  inline NonNull<mozilla::dom::indexedDB::IDBIndex>&
  SetAsIDBIndex()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBIndex;
    return mUnion.mValue.mIDBIndex.SetValue();
  }
};

class IDBObjectStoreOrIDBIndexOrIDBCursorArgument
{
  IDBObjectStoreOrIDBIndexOrIDBCursor& mUnion;

  IDBObjectStoreOrIDBIndexOrIDBCursorArgument(const IDBObjectStoreOrIDBIndexOrIDBCursorArgument&) MOZ_DELETE;
  void operator=(const IDBObjectStoreOrIDBIndexOrIDBCursorArgument) MOZ_DELETE;

public:
  explicit inline IDBObjectStoreOrIDBIndexOrIDBCursorArgument(const IDBObjectStoreOrIDBIndexOrIDBCursor& aUnion)
    : mUnion(const_cast<IDBObjectStoreOrIDBIndexOrIDBCursor&>(aUnion))
  {
  }

  inline bool
  TrySetToIDBObjectStore(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBObjectStore>& memberSlot = SetAsIDBObjectStore();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBObjectStore, mozilla::dom::indexedDB::IDBObjectStore>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBObjectStore();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToIDBIndex(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBIndex>& memberSlot = SetAsIDBIndex();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBIndex, mozilla::dom::indexedDB::IDBIndex>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBIndex();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToIDBCursor(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBCursor>& memberSlot = SetAsIDBCursor();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBCursor, mozilla::dom::indexedDB::IDBCursor>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBCursor();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  SetAsIDBObjectStore()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBObjectStore;
    return mUnion.mValue.mIDBObjectStore.SetValue();
  }

  inline NonNull<mozilla::dom::indexedDB::IDBIndex>&
  SetAsIDBIndex()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBIndex;
    return mUnion.mValue.mIDBIndex.SetValue();
  }

  inline NonNull<mozilla::dom::indexedDB::IDBCursor>&
  SetAsIDBCursor()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBCursor;
    return mUnion.mValue.mIDBCursor.SetValue();
  }
};

class LongOrAutoKeywordArgument
{
  LongOrAutoKeyword& mUnion;

  LongOrAutoKeywordArgument(const LongOrAutoKeywordArgument&) MOZ_DELETE;
  void operator=(const LongOrAutoKeywordArgument) MOZ_DELETE;

public:
  explicit inline LongOrAutoKeywordArgument(const LongOrAutoKeyword& aUnion)
    : mUnion(const_cast<LongOrAutoKeyword&>(aUnion))
  {
  }

  inline bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      int32_t& memberSlot = SetAsLong();
      if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToAutoKeyword(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      AutoKeyword& memberSlot = SetAsAutoKeyword();
      {
        bool ok;
        int index = FindEnumStringIndex<true>(cx, value, AutoKeywordValues::strings, "AutoKeyword", "Member of LongOrAutoKeyword", &ok);
        if (!ok) {
          return false;
        }
        MOZ_ASSERT(index >= 0);
        memberSlot = static_cast<AutoKeyword>(index);
      }
    }
    return true;
  }

private:
  inline int32_t&
  SetAsLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  inline AutoKeyword&
  SetAsAutoKeyword()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eAutoKeyword;
    return mUnion.mValue.mAutoKeyword.SetValue();
  }
};

class NodeListOrElementArgument
{
  NodeListOrElement& mUnion;

  NodeListOrElementArgument(const NodeListOrElementArgument&) MOZ_DELETE;
  void operator=(const NodeListOrElementArgument) MOZ_DELETE;

public:
  explicit inline NodeListOrElementArgument(const NodeListOrElement& aUnion)
    : mUnion(const_cast<NodeListOrElement&>(aUnion))
  {
  }

  inline bool
  TrySetToNodeList(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsINodeList>& memberSlot = SetAsNodeList();
      {
        nsresult rv = UnwrapObject<prototypes::id::NodeList, nsINodeList>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyNodeList();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Element>& memberSlot = SetAsElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::Element, mozilla::dom::Element>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<nsINodeList>&
  SetAsNodeList()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eNodeList;
    return mUnion.mValue.mNodeList.SetValue();
  }

  inline NonNull<mozilla::dom::Element>&
  SetAsElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eElement;
    return mUnion.mValue.mElement.SetValue();
  }
};

class StringOrCanvasGradientOrCanvasPatternArgument
{
  StringOrCanvasGradientOrCanvasPattern& mUnion;

  StringOrCanvasGradientOrCanvasPatternArgument(const StringOrCanvasGradientOrCanvasPatternArgument&) MOZ_DELETE;
  void operator=(const StringOrCanvasGradientOrCanvasPatternArgument) MOZ_DELETE;

public:
  explicit inline StringOrCanvasGradientOrCanvasPatternArgument(const StringOrCanvasGradientOrCanvasPattern& aUnion)
    : mUnion(const_cast<StringOrCanvasGradientOrCanvasPattern&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeDependentString& memberSlot = SetAsString();
      if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    SetAsString().SetData(aData, aLength);
  }

  inline bool
  TrySetToCanvasGradient(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::CanvasGradient>& memberSlot = SetAsCanvasGradient();
      {
        nsresult rv = UnwrapObject<prototypes::id::CanvasGradient, mozilla::dom::CanvasGradient>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyCanvasGradient();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToCanvasPattern(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::CanvasPattern>& memberSlot = SetAsCanvasPattern();
      {
        nsresult rv = UnwrapObject<prototypes::id::CanvasPattern, mozilla::dom::CanvasPattern>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyCanvasPattern();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline NonNull<mozilla::dom::CanvasGradient>&
  SetAsCanvasGradient()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eCanvasGradient;
    return mUnion.mValue.mCanvasGradient.SetValue();
  }

  inline NonNull<mozilla::dom::CanvasPattern>&
  SetAsCanvasPattern()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eCanvasPattern;
    return mUnion.mValue.mCanvasPattern.SetValue();
  }
};

class StringOrUnsignedLongArgument
{
  StringOrUnsignedLong& mUnion;

  StringOrUnsignedLongArgument(const StringOrUnsignedLongArgument&) MOZ_DELETE;
  void operator=(const StringOrUnsignedLongArgument) MOZ_DELETE;

public:
  explicit inline StringOrUnsignedLongArgument(const StringOrUnsignedLong& aUnion)
    : mUnion(const_cast<StringOrUnsignedLong&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeDependentString& memberSlot = SetAsString();
      if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    SetAsString().SetData(aData, aLength);
  }

  inline bool
  TrySetToUnsignedLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      uint32_t& memberSlot = SetAsUnsignedLong();
      if (!ValueToPrimitive<uint32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline uint32_t&
  SetAsUnsignedLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUnsignedLong;
    return mUnion.mValue.mUnsignedLong.SetValue();
  }
};

class TelephonyCallOrTelephonyCallGroupArgument
{
  TelephonyCallOrTelephonyCallGroup& mUnion;

  TelephonyCallOrTelephonyCallGroupArgument(const TelephonyCallOrTelephonyCallGroupArgument&) MOZ_DELETE;
  void operator=(const TelephonyCallOrTelephonyCallGroupArgument) MOZ_DELETE;

public:
  explicit inline TelephonyCallOrTelephonyCallGroupArgument(const TelephonyCallOrTelephonyCallGroup& aUnion)
    : mUnion(const_cast<TelephonyCallOrTelephonyCallGroup&>(aUnion))
  {
  }

  inline bool
  TrySetToTelephonyCall(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::TelephonyCall>& memberSlot = SetAsTelephonyCall();
      {
        nsresult rv = UnwrapObject<prototypes::id::TelephonyCall, mozilla::dom::TelephonyCall>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyTelephonyCall();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToTelephonyCallGroup(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::TelephonyCallGroup>& memberSlot = SetAsTelephonyCallGroup();
      {
        nsresult rv = UnwrapObject<prototypes::id::TelephonyCallGroup, mozilla::dom::TelephonyCallGroup>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyTelephonyCallGroup();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::TelephonyCall>&
  SetAsTelephonyCall()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eTelephonyCall;
    return mUnion.mValue.mTelephonyCall.SetValue();
  }

  inline NonNull<mozilla::dom::TelephonyCallGroup>&
  SetAsTelephonyCallGroup()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eTelephonyCallGroup;
    return mUnion.mValue.mTelephonyCallGroup.SetValue();
  }
};

class UnsignedLongOrStringArgument
{
  UnsignedLongOrString& mUnion;

  UnsignedLongOrStringArgument(const UnsignedLongOrStringArgument&) MOZ_DELETE;
  void operator=(const UnsignedLongOrStringArgument) MOZ_DELETE;

public:
  explicit inline UnsignedLongOrStringArgument(const UnsignedLongOrString& aUnion)
    : mUnion(const_cast<UnsignedLongOrString&>(aUnion))
  {
  }

  inline bool
  TrySetToUnsignedLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      uint32_t& memberSlot = SetAsUnsignedLong();
      if (!ValueToPrimitive<uint32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeDependentString& memberSlot = SetAsString();
      if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    SetAsString().SetData(aData, aLength);
  }

private:
  inline uint32_t&
  SetAsUnsignedLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUnsignedLong;
    return mUnion.mValue.mUnsignedLong.SetValue();
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
};

class WindowProxyOrMessagePortArgument
{
  WindowProxyOrMessagePort& mUnion;
  nsRefPtr<nsIDOMWindow> mWindowProxyHolder;

  WindowProxyOrMessagePortArgument(const WindowProxyOrMessagePortArgument&) MOZ_DELETE;
  void operator=(const WindowProxyOrMessagePortArgument) MOZ_DELETE;

public:
  explicit inline WindowProxyOrMessagePortArgument(const WindowProxyOrMessagePort& aUnion)
    : mUnion(const_cast<WindowProxyOrMessagePort&>(aUnion))
  {
  }

  inline bool
  TrySetToWindowProxy(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      nsIDOMWindow*& memberSlot = SetAsWindowProxy();
      JS::Rooted<JS::Value> tmpVal(cx, value);
      nsIDOMWindow* tmp;
      if (NS_FAILED(UnwrapArg<nsIDOMWindow>(cx, value, &tmp, static_cast<nsIDOMWindow**>(getter_AddRefs(mWindowProxyHolder)), &tmpVal))) {
        mUnion.DestroyWindowProxy();
        tryNext = true;
        return true;
      }
      MOZ_ASSERT(tmp);
      memberSlot = tmp;
    }
    return true;
  }

  inline bool
  TrySetToMessagePort(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::MessagePortBase>& memberSlot = SetAsMessagePort();
      {
        nsresult rv = UnwrapObject<prototypes::id::MessagePort, mozilla::dom::MessagePortBase>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyMessagePort();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline nsIDOMWindow*&
  SetAsWindowProxy()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eWindowProxy;
    return mUnion.mValue.mWindowProxy.SetValue();
  }

  inline NonNull<mozilla::dom::MessagePortBase>&
  SetAsMessagePort()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMessagePort;
    return mUnion.mValue.mMessagePort.SetValue();
  }
};

class mozContactOrStringArgument
{
  mozContactOrString& mUnion;

  mozContactOrStringArgument(const mozContactOrStringArgument&) MOZ_DELETE;
  void operator=(const mozContactOrStringArgument) MOZ_DELETE;

public:
  explicit inline mozContactOrStringArgument(const mozContactOrString& aUnion)
    : mUnion(const_cast<mozContactOrString&>(aUnion))
  {
  }

  inline bool
  TrySetTomozContact(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::mozContact>& memberSlot = SetAsmozContact();
      {
        nsresult rv = UnwrapObject<prototypes::id::mozContact, mozilla::dom::mozContact>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroymozContact();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeDependentString& memberSlot = SetAsString();
      if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    SetAsString().SetData(aData, aLength);
  }

private:
  inline NonNull<mozilla::dom::mozContact>&
  SetAsmozContact()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.emozContact;
    return mUnion.mValue.mmozContact.SetValue();
  }

  inline binding_detail::FakeDependentString&
  SetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
};


} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionConversions_h__
