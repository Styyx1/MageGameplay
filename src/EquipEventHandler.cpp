#include "EquipEventHandler.h"
#include "Utility.h"



namespace EquipEvent {
    OnEquipHandler* OnEquipHandler::GetSingleton() {
        static OnEquipHandler singleton;
        return std::addressof(singleton);
    }
    RE::BSEventNotifyControl OnEquipHandler::ProcessEvent(const RE::TESEquipEvent* a_event,
                                                          RE::BSTEventSource<RE::TESEquipEvent>* a_eventSource) {
        if (!a_event) return RE::BSEventNotifyControl::kContinue;

        const auto utility = Utility::GetSingleton();

        if (a_event->equipped) {
            if (a_event->actor->IsPlayerRef()) {
                logger::info("Player equip event started");
                const auto player = RE::PlayerCharacter::GetSingleton();
                if (auto right_weap = player->GetEquippedObject(false)->As<RE::TESObjectWEAP>(); right_weap->IsStaff()) {
                    logger::info("player has staff: {}", right_weap->GetName());
                    auto spell_equipped = player->GetActorRuntimeData().selectedSpells[RE::Actor::SlotTypes::kLeftHand]; spell_equipped->GetCostliestEffectItem()->effectItem.magnitude *= 50.0f;
                    logger::info("spell goes brrrrr with {} magnitude", spell_equipped->GetCostliestEffectItem()->effectItem.magnitude);
                    }
                }
            }
        
        return RE::BSEventNotifyControl::kContinue;

        
    }
    


    void OnEquipHandler::Register() {
        const auto holder = RE::ScriptEventSourceHolder::GetSingleton();
        holder->AddEventSink(GetSingleton());
        logger::info("Registered equip event handler");
    }


}  // namespace Events