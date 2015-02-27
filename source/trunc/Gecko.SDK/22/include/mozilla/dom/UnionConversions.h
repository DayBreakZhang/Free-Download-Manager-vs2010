#ifndef mozilla_dom_UnionConversions_h__
#define mozilla_dom_UnionConversions_h__

#include "EventBinding.h"
#include "HTMLElementBinding.h"
#include "HTMLImageElementBinding.h"
#include "HTMLOptGroupElementBinding.h"
#include "HTMLOptionElementBinding.h"
#include "HTMLVideoElementBinding.h"
#include "XPCWrapper.h"
#include "mozilla/dom/UnionTypes.h"
#include "nsDOMQS.h"
#include "nsDebug.h"

namespace mozilla {
namespace dom {

class EventOrStringArgument {
public:
  EventOrStringArgument(const EventOrString& aUnion) : mUnion(const_cast<EventOrString&>(aUnion))
  {
  }

  bool TrySetToEvent(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::Event, nsDOMEvent>(cx, &value.toObject(), SetAsEvent());
      if (NS_FAILED(rv)) {
        nsDOMEvent *objPtr;
        xpc_qsSelfRef objRef;
        JS::Value val = JS::ObjectValue(*&value.toObject());
        nsresult rv = xpc_qsUnwrapArg<nsDOMEvent>(cx, val, &objPtr, &objRef.ptr, &val);
        if (NS_FAILED(rv)) {
            if (mUnion.mType != mUnion.eUninitialized) {
              mUnion.DestroyEvent();
            }tryNext = true;
            return true;
        }
        // We should be castable!
        MOZ_ASSERT(!objRef.ptr);
        // We should have an object, too!
        MOZ_ASSERT(objPtr);
        SetAsEvent() = objPtr;
      }
    }
    return true;
  }

  bool TrySetToString(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, mStringHolder)) {
      return false;
    }
    const_cast<NonNull<nsAString>&>(SetAsString()) = &mStringHolder;
    return true;
  }

private:
  NonNull<nsDOMEvent>& SetAsEvent()
  {
    mUnion.mType = mUnion.eEvent;
    return mUnion.mValue.mEvent.SetValue();
  }
  NonNull<nsAString>& SetAsString()
  {
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  FakeDependentString mStringHolder;

  EventOrString& mUnion;
};


class HTMLElementOrLongArgument {
public:
  HTMLElementOrLongArgument(const HTMLElementOrLong& aUnion) : mUnion(const_cast<HTMLElementOrLong&>(aUnion))
  {
  }

  bool TrySetToHTMLElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLElement, nsGenericHTMLElement>(cx, &value.toObject(), SetAsHTMLElement());
      if (NS_FAILED(rv)) {
        nsGenericHTMLElement *objPtr;
        xpc_qsSelfRef objRef;
        JS::Value val = JS::ObjectValue(*&value.toObject());
        nsresult rv = xpc_qsUnwrapArg<nsGenericHTMLElement>(cx, val, &objPtr, &objRef.ptr, &val);
        if (NS_FAILED(rv)) {
            if (mUnion.mType != mUnion.eUninitialized) {
              mUnion.DestroyHTMLElement();
            }tryNext = true;
            return true;
        }
        // We should be castable!
        MOZ_ASSERT(!objRef.ptr);
        // We should have an object, too!
        MOZ_ASSERT(objPtr);
        SetAsHTMLElement() = objPtr;
      }
    }
    return true;
  }

  bool TrySetToLong(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &SetAsLong())) {
      return false;
    }
    return true;
  }

private:
  NonNull<nsGenericHTMLElement>& SetAsHTMLElement()
  {
    mUnion.mType = mUnion.eHTMLElement;
    return mUnion.mValue.mHTMLElement.SetValue();
  }
  int32_t& SetAsLong()
  {
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  HTMLElementOrLong& mUnion;
};


class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument {
public:
  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& aUnion) : mUnion(const_cast<HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement&>(aUnion))
  {
  }

  bool TrySetToHTMLImageElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLImageElement, mozilla::dom::HTMLImageElement>(cx, &value.toObject(), SetAsHTMLImageElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLImageElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToHTMLCanvasElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    jsval tmpVal = value;
    mozilla::dom::HTMLCanvasElement* tmp;
    if (NS_FAILED(xpc_qsUnwrapArg<mozilla::dom::HTMLCanvasElement>(cx, value, &tmp, static_cast<mozilla::dom::HTMLCanvasElement**>(getter_AddRefs(mHTMLCanvasElementHolder)), &tmpVal))) {
      if (mUnion.mType != mUnion.eUninitialized) {
        mUnion.DestroyHTMLCanvasElement();
      }tryNext = true;
      return true;
    }
    MOZ_ASSERT(tmp);
    SetAsHTMLCanvasElement() = tmp;
    return true;
  }

  bool TrySetToHTMLVideoElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLVideoElement, mozilla::dom::HTMLVideoElement>(cx, &value.toObject(), SetAsHTMLVideoElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLVideoElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

private:
  NonNull<mozilla::dom::HTMLImageElement>& SetAsHTMLImageElement()
  {
    mUnion.mType = mUnion.eHTMLImageElement;
    return mUnion.mValue.mHTMLImageElement.SetValue();
  }
  mozilla::dom::HTMLCanvasElement*& SetAsHTMLCanvasElement()
  {
    mUnion.mType = mUnion.eHTMLCanvasElement;
    return mUnion.mValue.mHTMLCanvasElement.SetValue();
  }
  NonNull<mozilla::dom::HTMLVideoElement>& SetAsHTMLVideoElement()
  {
    mUnion.mType = mUnion.eHTMLVideoElement;
    return mUnion.mValue.mHTMLVideoElement.SetValue();
  }

  nsRefPtr<mozilla::dom::HTMLCanvasElement> mHTMLCanvasElementHolder;

  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& mUnion;
};


class HTMLOptionElementOrHTMLOptGroupElementArgument {
public:
  HTMLOptionElementOrHTMLOptGroupElementArgument(const HTMLOptionElementOrHTMLOptGroupElement& aUnion) : mUnion(const_cast<HTMLOptionElementOrHTMLOptGroupElement&>(aUnion))
  {
  }

  bool TrySetToHTMLOptionElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLOptionElement, mozilla::dom::HTMLOptionElement>(cx, &value.toObject(), SetAsHTMLOptionElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLOptionElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToHTMLOptGroupElement(JSContext* cx, JSObject* scopeObj, const JS::Value& value, JS::Value* pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLOptGroupElement, mozilla::dom::HTMLOptGroupElement>(cx, &value.toObject(), SetAsHTMLOptGroupElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLOptGroupElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

private:
  NonNull<mozilla::dom::HTMLOptionElement>& SetAsHTMLOptionElement()
  {
    mUnion.mType = mUnion.eHTMLOptionElement;
    return mUnion.mValue.mHTMLOptionElement.SetValue();
  }
  NonNull<mozilla::dom::HTMLOptGroupElement>& SetAsHTMLOptGroupElement()
  {
    mUnion.mType = mUnion.eHTMLOptGroupElement;
    return mUnion.mValue.mHTMLOptGroupElement.SetValue();
  }

  HTMLOptionElementOrHTMLOptGroupElement& mUnion;
};


} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionConversions_h__
