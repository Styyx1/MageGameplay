#include "Events.h"
#include "FormLookup.h"

namespace Events {
    OnEquipHandler* OnEquipHandler::GetSingleton() {
        static OnEquipHandler singleton;
        return std::addressof(singleton);
    }
    RE::BSEventNotifyControl OnEquipHandler::ProcessEvent(const RE::TESEquipEvent* a_event,
                                                          RE::BSTEventSource<RE::TESEquipEvent>* a_eventSource) {
        if (!a_event) return RE::BSEventNotifyControl::kContinue;

        const auto player = RE::PlayerCharacter::GetSingleton();
        float new_cost = 10.0f;

        if (a_event->baseObject == Utility::staff_weapon->GetFormID()) {
            if (auto staff_weap = Utility::staff_weapon->AsReference();
                staff_weap->HasKeyword(Utility::weapTypeStaff)) {
                auto equipped_spell = player->GetActorRuntimeData().selectedSpells[RE::Actor::SlotTypes::kRightHand];
                equipped_spell->GetCostliestEffectItem()->effectItem.magnitude *= 1.50;
                equipped_spell->AdjustCost(new_cost, player->As<RE::Actor>());
            }
        }
        return RE::BSEventNotifyControl::kContinue;
        
    }


}  // namespace Events