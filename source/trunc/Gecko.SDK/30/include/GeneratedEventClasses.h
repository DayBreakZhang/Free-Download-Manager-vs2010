#ifndef _gen_mozilla_idl_generated_event_declarations_h_
#define _gen_mozilla_idl_generated_event_declarations_h_

#include "mozilla/dom/Event.h"
#include "nsContentUtils.h"
#include "nsIDOMApplicationRegistry.h"
#include "nsIDOMFile.h"
#include "nsIDOMProgressEvent.h"
#include "nsIDOMStorageEvent.h"
#include "nsIDOMMozSettingsEvent.h"
#include "nsIDOMCustomEvent.h"
#include "nsIDOMPageTransitionEvent.h"
#include "nsIDOMDOMTransactionEvent.h"
#include "nsIDOMPopStateEvent.h"
#include "nsIDOMHashChangeEvent.h"
#include "nsIDOMCloseEvent.h"
#include "nsIDOMDeviceOrientationEvent.h"
#include "nsIDOMMozApplicationEvent.h"
#include "nsIDOMSmartCardEvent.h"
#include "nsIDOMStyleRuleChangeEvent.h"
#include "nsIDOMStyleSheetChangeEvent.h"
#include "nsIDOMStyleSheetApplicableStateChangeEvent.h"
#include "nsIDOMElementReplaceEvent.h"
#include "nsIDOMMozSmsEvent.h"
#include "nsIDOMMozMmsEvent.h"
#include "nsIDOMSpeechSynthesisEvent.h"
#include "nsIDOMDeviceStorageChangeEvent.h"
#include "nsIDOMPopupBlockedEvent.h"
#include "nsIDOMRecordErrorEvent.h"
#include "nsIDOMSpeechRecognitionEvent.h"
#include "nsIDOMEventTarget.h"
#include "nsIDOMStorage.h"
#include "nsIVariant.h"
#include "nsIDOMCSSStyleSheet.h"
#include "nsIDOMCSSRule.h"
#include "nsIDOMElement.h"
#include "nsIDOMMozSmsMessage.h"
#include "nsIDOMMozMmsMessage.h"
#include "nsIDOMWindow.h"
#include "nsIURI.h"
#include "nsIDOMDocument.h"
#include "mozilla/dom/ProgressEventBinding.h"
#include "mozilla/dom/StorageEventBinding.h"
#include "mozilla/dom/MozSettingsEventBinding.h"
#include "mozilla/dom/CustomEventBinding.h"
#include "mozilla/dom/PageTransitionEventBinding.h"
#include "mozilla/dom/DOMTransactionEventBinding.h"
#include "mozilla/dom/PopStateEventBinding.h"
#include "mozilla/dom/HashChangeEventBinding.h"
#include "mozilla/dom/CloseEventBinding.h"
#include "mozilla/dom/DeviceOrientationEventBinding.h"
#include "mozilla/dom/MozApplicationEventBinding.h"
#include "mozilla/dom/SmartCardEventBinding.h"
#include "mozilla/dom/StyleRuleChangeEventBinding.h"
#include "mozilla/dom/StyleSheetChangeEventBinding.h"
#include "mozilla/dom/StyleSheetApplicableStateChangeEventBinding.h"
#include "mozilla/dom/ElementReplaceEventBinding.h"
#include "mozilla/dom/MozSmsEventBinding.h"
#include "mozilla/dom/MozMmsEventBinding.h"
#include "mozilla/dom/SpeechSynthesisEventBinding.h"
#include "mozilla/dom/DeviceStorageChangeEventBinding.h"
#include "mozilla/dom/PopupBlockedEventBinding.h"
#include "mozilla/dom/RecordErrorEventBinding.h"
#include "mozilla/dom/SpeechRecognitionEventBinding.h"
namespace mozilla {
namespace dom {

class ProgressEvent : public Event, public nsIDOMProgressEvent
{
public:
  ProgressEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~ProgressEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(ProgressEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMPROGRESSEVENT
  static already_AddRefed<ProgressEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const ProgressEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::ProgressEventBinding::Wrap(aCx, aScope, this);
  }

  bool LengthComputable()
  {
    return mLengthComputable;
  }

  uint64_t Loaded()
  {
    return mLoaded;
  }

  uint64_t Total()
  {
    return mTotal;
  }

  void InitProgressEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, bool  aLengthComputable, uint64_t  aLoaded, uint64_t  aTotal, ErrorResult& aRv);

protected:
  bool mLengthComputable;
  uint64_t mLoaded;
  uint64_t mTotal;
};

class StorageEvent : public Event, public nsIDOMStorageEvent
{
public:
  StorageEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~StorageEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(StorageEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMSTORAGEEVENT
  static already_AddRefed<StorageEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const StorageEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::StorageEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<nsIDOMStorage> GetStorageArea()
  {
    nsCOMPtr<nsIDOMStorage> storageArea = do_QueryInterface(mStorageArea);
    return storageArea.forget().downcast<nsIDOMStorage>();
  }

  void InitStorageEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, const nsAString& aKey, const nsAString& aOldValue, const nsAString& aNewValue, const nsAString& aUrl, nsIDOMStorage* aStorageArea, ErrorResult& aRv);

protected:
  nsString mKey;
  nsString mOldValue;
  nsString mNewValue;
  nsString mUrl;
  nsCOMPtr<nsIDOMStorage> mStorageArea;
};

class MozSettingsEvent : public Event, public nsIDOMMozSettingsEvent
{
public:
  MozSettingsEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~MozSettingsEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(MozSettingsEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMMOZSETTINGSEVENT
  static already_AddRefed<MozSettingsEvent> Constructor(const GlobalObject& aGlobal, JSContext* aCx, const nsAString& aType, const MozSettingsEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::MozSettingsEventBinding::Wrap(aCx, aScope, this);
  }

  JS::Value GetSettingValue(JSContext* aCx, ErrorResult& aRv);

  void InitMozSettingsEvent(JSContext* aCx, const nsAString& aType, bool aCanBubble, bool aCancelable, const nsAString& aSettingName, JS::Value aSettingValue, ErrorResult& aRv);

protected:
  nsString mSettingName;
  nsCOMPtr<nsIVariant> mSettingValue;
};

class CustomEvent : public Event, public nsIDOMCustomEvent
{
public:
  CustomEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~CustomEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(CustomEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMCUSTOMEVENT
  static already_AddRefed<CustomEvent> Constructor(const GlobalObject& aGlobal, JSContext* aCx, const nsAString& aType, const CustomEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::CustomEventBinding::Wrap(aCx, aScope, this);
  }

  JS::Value GetDetail(JSContext* aCx, ErrorResult& aRv);

  void InitCustomEvent(JSContext* aCx, const nsAString& aType, bool aCanBubble, bool aCancelable, JS::Value aDetail, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIVariant> mDetail;
};

class PageTransitionEvent : public Event, public nsIDOMPageTransitionEvent
{
public:
  PageTransitionEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~PageTransitionEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(PageTransitionEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMPAGETRANSITIONEVENT
  static already_AddRefed<PageTransitionEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const PageTransitionEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::PageTransitionEventBinding::Wrap(aCx, aScope, this);
  }

  bool Persisted()
  {
    return mPersisted;
  }

  void InitPageTransitionEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, bool  aPersisted, ErrorResult& aRv);

protected:
  bool mPersisted;
};

class DOMTransactionEvent : public Event, public nsIDOMDOMTransactionEvent
{
public:
  DOMTransactionEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~DOMTransactionEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(DOMTransactionEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMDOMTRANSACTIONEVENT
  static already_AddRefed<DOMTransactionEvent> Constructor(const GlobalObject& aGlobal, JSContext* aCx, const nsAString& aType, const DOMTransactionEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::DOMTransactionEventBinding::Wrap(aCx, aScope, this);
  }

  JS::Value GetTransactions(JSContext* aCx, ErrorResult& aRv);

  void InitDOMTransactionEvent(JSContext* aCx, const nsAString& aType, bool aCanBubble, bool aCancelable, JS::Value aTransactions, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIVariant> mTransactions;
};

class PopStateEvent : public Event, public nsIDOMPopStateEvent
{
public:
  PopStateEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~PopStateEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(PopStateEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMPOPSTATEEVENT
  static already_AddRefed<PopStateEvent> Constructor(const GlobalObject& aGlobal, JSContext* aCx, const nsAString& aType, const PopStateEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::PopStateEventBinding::Wrap(aCx, aScope, this);
  }

  JS::Value GetState(JSContext* aCx, ErrorResult& aRv);

  void InitPopStateEvent(JSContext* aCx, const nsAString& aType, bool aCanBubble, bool aCancelable, JS::Value aState, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIVariant> mState;
};

class HashChangeEvent : public Event, public nsIDOMHashChangeEvent
{
public:
  HashChangeEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~HashChangeEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(HashChangeEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMHASHCHANGEEVENT
  static already_AddRefed<HashChangeEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const HashChangeEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::HashChangeEventBinding::Wrap(aCx, aScope, this);
  }

  void InitHashChangeEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, const nsAString& aOldURL, const nsAString& aNewURL, ErrorResult& aRv);

protected:
  nsString mOldURL;
  nsString mNewURL;
};

class CloseEvent : public Event, public nsIDOMCloseEvent
{
public:
  CloseEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~CloseEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(CloseEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMCLOSEEVENT
  static already_AddRefed<CloseEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const CloseEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::CloseEventBinding::Wrap(aCx, aScope, this);
  }

  bool WasClean()
  {
    return mWasClean;
  }

  uint16_t Code()
  {
    return mCode;
  }

  void InitCloseEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, bool  aWasClean, uint16_t  aCode, const nsAString& aReason, ErrorResult& aRv);

protected:
  bool mWasClean;
  uint16_t mCode;
  nsString mReason;
};

class DeviceOrientationEvent : public Event, public nsIDOMDeviceOrientationEvent
{
public:
  DeviceOrientationEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~DeviceOrientationEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(DeviceOrientationEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMDEVICEORIENTATIONEVENT
  static already_AddRefed<DeviceOrientationEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const DeviceOrientationEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::DeviceOrientationEventBinding::Wrap(aCx, aScope, this);
  }

  double Alpha()
  {
    return mAlpha;
  }

  double Beta()
  {
    return mBeta;
  }

  double Gamma()
  {
    return mGamma;
  }

  bool Absolute()
  {
    return mAbsolute;
  }

  void InitDeviceOrientationEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, double  aAlpha, double  aBeta, double  aGamma, bool  aAbsolute, ErrorResult& aRv);

protected:
  double mAlpha;
  double mBeta;
  double mGamma;
  bool mAbsolute;
};

class MozApplicationEvent : public Event, public nsIDOMMozApplicationEvent
{
public:
  MozApplicationEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~MozApplicationEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(MozApplicationEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMMOZAPPLICATIONEVENT
  static already_AddRefed<MozApplicationEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const MozApplicationEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::MozApplicationEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<mozIDOMApplication> GetApplication()
  {
    nsCOMPtr<mozIDOMApplication> application = do_QueryInterface(mApplication);
    return application.forget().downcast<mozIDOMApplication>();
  }

  void InitMozApplicationEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, mozIDOMApplication* aApplication, ErrorResult& aRv);

protected:
  nsCOMPtr<mozIDOMApplication> mApplication;
};

class SmartCardEvent : public Event, public nsIDOMSmartCardEvent
{
public:
  SmartCardEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~SmartCardEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(SmartCardEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMSMARTCARDEVENT
  static already_AddRefed<SmartCardEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const SmartCardEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::SmartCardEventBinding::Wrap(aCx, aScope, this);
  }

  void InitSmartCardEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, const nsAString& aTokenName, ErrorResult& aRv);

protected:
  nsString mTokenName;
};

class StyleRuleChangeEvent : public Event, public nsIDOMStyleRuleChangeEvent
{
public:
  StyleRuleChangeEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~StyleRuleChangeEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(StyleRuleChangeEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMSTYLERULECHANGEEVENT
  static already_AddRefed<StyleRuleChangeEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const StyleRuleChangeEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::StyleRuleChangeEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<nsCSSStyleSheet> GetStylesheet()
  {
    nsCOMPtr<nsIStyleSheet> stylesheet = do_QueryInterface(mStylesheet);
    return stylesheet.forget().downcast<nsCSSStyleSheet>();
  }

  already_AddRefed<nsIDOMCSSRule> GetRule()
  {
    nsCOMPtr<nsIDOMCSSRule> rule = do_QueryInterface(mRule);
    return rule.forget().downcast<nsIDOMCSSRule>();
  }

  void InitStyleRuleChangeEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, nsCSSStyleSheet* aStylesheet, nsIDOMCSSRule* aRule, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIDOMCSSStyleSheet> mStylesheet;
  nsCOMPtr<nsIDOMCSSRule> mRule;
};

class StyleSheetChangeEvent : public Event, public nsIDOMStyleSheetChangeEvent
{
public:
  StyleSheetChangeEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~StyleSheetChangeEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(StyleSheetChangeEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMSTYLESHEETCHANGEEVENT
  static already_AddRefed<StyleSheetChangeEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const StyleSheetChangeEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::StyleSheetChangeEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<nsCSSStyleSheet> GetStylesheet()
  {
    nsCOMPtr<nsIStyleSheet> stylesheet = do_QueryInterface(mStylesheet);
    return stylesheet.forget().downcast<nsCSSStyleSheet>();
  }

  bool DocumentSheet()
  {
    return mDocumentSheet;
  }

  void InitStyleSheetChangeEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, nsCSSStyleSheet* aStylesheet, bool  aDocumentSheet, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIDOMCSSStyleSheet> mStylesheet;
  bool mDocumentSheet;
};

class StyleSheetApplicableStateChangeEvent : public Event, public nsIDOMStyleSheetApplicableStateChangeEvent
{
public:
  StyleSheetApplicableStateChangeEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~StyleSheetApplicableStateChangeEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(StyleSheetApplicableStateChangeEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMSTYLESHEETAPPLICABLESTATECHANGEEVENT
  static already_AddRefed<StyleSheetApplicableStateChangeEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const StyleSheetApplicableStateChangeEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::StyleSheetApplicableStateChangeEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<nsCSSStyleSheet> GetStylesheet()
  {
    nsCOMPtr<nsIStyleSheet> stylesheet = do_QueryInterface(mStylesheet);
    return stylesheet.forget().downcast<nsCSSStyleSheet>();
  }

  bool Applicable()
  {
    return mApplicable;
  }

  void InitStyleSheetApplicableStateChangeEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, nsCSSStyleSheet* aStylesheet, bool  aApplicable, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIDOMCSSStyleSheet> mStylesheet;
  bool mApplicable;
};

class ElementReplaceEvent : public Event, public nsIDOMElementReplaceEvent
{
public:
  ElementReplaceEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~ElementReplaceEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(ElementReplaceEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMELEMENTREPLACEEVENT
  static already_AddRefed<ElementReplaceEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const ElementReplaceEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::ElementReplaceEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<mozilla::dom::Element> GetUpgrade()
  {
    nsCOMPtr<mozilla::dom::Element> upgrade = do_QueryInterface(mUpgrade);
    return upgrade.forget().downcast<mozilla::dom::Element>();
  }

  void InitElementReplaceEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, mozilla::dom::Element* aUpgrade, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIDOMElement> mUpgrade;
};

class MozSmsEvent : public Event, public nsIDOMMozSmsEvent
{
public:
  MozSmsEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~MozSmsEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(MozSmsEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMMOZSMSEVENT
  static already_AddRefed<MozSmsEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const MozSmsEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::MozSmsEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<nsIDOMMozSmsMessage> GetMessage()
  {
    nsCOMPtr<nsIDOMMozSmsMessage> message = do_QueryInterface(mMessage);
    return message.forget().downcast<nsIDOMMozSmsMessage>();
  }

  void InitMozSmsEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, nsIDOMMozSmsMessage* aMessage, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIDOMMozSmsMessage> mMessage;
};

class MozMmsEvent : public Event, public nsIDOMMozMmsEvent
{
public:
  MozMmsEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~MozMmsEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(MozMmsEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMMOZMMSEVENT
  static already_AddRefed<MozMmsEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const MozMmsEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::MozMmsEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<nsIDOMMozMmsMessage> GetMessage()
  {
    nsCOMPtr<nsIDOMMozMmsMessage> message = do_QueryInterface(mMessage);
    return message.forget().downcast<nsIDOMMozMmsMessage>();
  }

  void InitMozMmsEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, nsIDOMMozMmsMessage* aMessage, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIDOMMozMmsMessage> mMessage;
};

class SpeechSynthesisEvent : public Event, public nsIDOMSpeechSynthesisEvent
{
public:
  SpeechSynthesisEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~SpeechSynthesisEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(SpeechSynthesisEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMSPEECHSYNTHESISEVENT
  static already_AddRefed<SpeechSynthesisEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const SpeechSynthesisEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::SpeechSynthesisEventBinding::Wrap(aCx, aScope, this);
  }

  uint32_t CharIndex()
  {
    return mCharIndex;
  }

  float ElapsedTime()
  {
    return mElapsedTime;
  }

  void InitSpeechSynthesisEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, uint32_t  aCharIndex, float  aElapsedTime, const nsAString& aName, ErrorResult& aRv);

protected:
  uint32_t mCharIndex;
  float mElapsedTime;
  nsString mName;
};

class DeviceStorageChangeEvent : public Event, public nsIDOMDeviceStorageChangeEvent
{
public:
  DeviceStorageChangeEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~DeviceStorageChangeEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(DeviceStorageChangeEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMDEVICESTORAGECHANGEEVENT
  static already_AddRefed<DeviceStorageChangeEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const DeviceStorageChangeEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::DeviceStorageChangeEventBinding::Wrap(aCx, aScope, this);
  }

  void InitDeviceStorageChangeEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, const nsAString& aPath, const nsAString& aReason, ErrorResult& aRv);

protected:
  nsString mPath;
  nsString mReason;
};

class PopupBlockedEvent : public Event, public nsIDOMPopupBlockedEvent
{
public:
  PopupBlockedEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~PopupBlockedEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(PopupBlockedEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMPOPUPBLOCKEDEVENT
  static already_AddRefed<PopupBlockedEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const PopupBlockedEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::PopupBlockedEventBinding::Wrap(aCx, aScope, this);
  }

  already_AddRefed<nsGlobalWindow> GetRequestingWindow()
  {
    nsCOMPtr<nsIDOMEventTarget> requestingWindow = do_QueryInterface(mRequestingWindow);
    return requestingWindow.forget().downcast<nsGlobalWindow>();
  }

  already_AddRefed<nsIURI> GetPopupWindowURI()
  {
    nsCOMPtr<nsIURI> popupWindowURI = do_QueryInterface(mPopupWindowURI);
    return popupWindowURI.forget().downcast<nsIURI>();
  }

  void InitPopupBlockedEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, nsGlobalWindow* aRequestingWindow, nsIURI* aPopupWindowURI, const nsAString& aPopupWindowName, const nsAString& aPopupWindowFeatures, ErrorResult& aRv);

protected:
  nsCOMPtr<nsIDOMWindow> mRequestingWindow;
  nsCOMPtr<nsIURI> mPopupWindowURI;
  nsString mPopupWindowName;
  nsString mPopupWindowFeatures;
};

class RecordErrorEvent : public Event, public nsIDOMRecordErrorEvent
{
public:
  RecordErrorEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~RecordErrorEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(RecordErrorEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMRECORDERROREVENT
  static already_AddRefed<RecordErrorEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const RecordErrorEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::RecordErrorEventBinding::Wrap(aCx, aScope, this);
  }

  void InitRecordErrorEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, const nsAString& aName, ErrorResult& aRv);

protected:
  nsString mName;
};

class SpeechRecognitionEvent : public Event, public nsIDOMSpeechRecognitionEvent
{
public:
  SpeechRecognitionEvent(mozilla::dom::EventTarget* aOwner, nsPresContext* aPresContext = nullptr, mozilla::WidgetEvent* aEvent = nullptr);
  virtual ~SpeechRecognitionEvent();

  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(SpeechRecognitionEvent, Event)
  NS_FORWARD_TO_EVENT
  NS_DECL_NSIDOMSPEECHRECOGNITIONEVENT
  static already_AddRefed<SpeechRecognitionEvent> Constructor(const GlobalObject& aGlobal, const nsAString& aType, const SpeechRecognitionEventInit& aParam, ErrorResult& aRv);

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE
  {
    return mozilla::dom::SpeechRecognitionEventBinding::Wrap(aCx, aScope, this);
  }

  uint32_t ResultIndex()
  {
    return mResultIndex;
  }

  already_AddRefed<nsISupports> GetResults()
  {
    nsCOMPtr<nsISupports> results = do_QueryInterface(mResults);
    return results.forget().downcast<nsISupports>();
  }

  already_AddRefed<nsIDocument> GetEmma()
  {
    nsCOMPtr<nsIDocument> emma = do_QueryInterface(mEmma);
    return emma.forget().downcast<nsIDocument>();
  }

  void InitSpeechRecognitionEvent(const nsAString& aType, bool aCanBubble, bool aCancelable, uint32_t  aResultIndex, nsISupports* aResults, const nsAString& aInterpretation, nsIDocument* aEmma, ErrorResult& aRv);

protected:
  uint32_t mResultIndex;
  nsCOMPtr<nsISupports> mResults;
  nsString mInterpretation;
  nsCOMPtr<nsIDOMDocument> mEmma;
};
} // namespace dom
} // namespace mozilla

#endif
