#pragma once
namespace EquipEvent {
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
}  // namespace EquipEvent