#pragma once

namespace Events {
    class OnHitEventHandler : public RE::BSTEventSink<RE::TESHitEvent> {
    protected:
        OnHitEventHandler() = default;

    public:
        OnHitEventHandler(const OnHitEventHandler&) = delete;
        OnHitEventHandler(OnHitEventHandler&&) = delete;
        OnHitEventHandler& operator=(const OnHitEventHandler) = delete;
        OnHitEventHandler& operator=(OnHitEventHandler&&) = delete;

        static OnHitEventHandler* GetSingleton();
        RE::BSEventNotifyControl ProcessEvent(const RE::TESHitEvent* a_event, RE::BSTEventSource<RE::TESHitEvent>* a_eventSource) override;
        static void Register();
    };
    class OnEquipHandler : public RE::BSTEventSink<RE::TESEquipEvent> {
    protected:
        OnEquipHandler() = default;

    public: 
        OnEquipHandler(const OnEquipHandler&) = delete;
        OnEquipHandler(OnEquipHandler&&) = delete;
        OnEquipHandler& operator=(const OnEquipHandler) = delete;
        OnEquipHandler& operator=(OnEquipHandler&&) = delete;

        static OnEquipHandler* GetSingleton();
        RE::BSEventNotifyControl ProcessEvent(const RE::TESEquipEvent* a_event,
                                              RE::BSTEventSource<RE::TESEquipEvent>* a_eventSource) override;
        static void Register();

    };
}
