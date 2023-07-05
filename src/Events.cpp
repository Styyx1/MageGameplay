#include "Events.h"
#include "Utility.h"
#include "Settings.h"
#include "Hooks.h"
#include "FormLookup.h"

namespace Events {
    OnHitEventHandler* OnHitEventHandler::GetSingleton() {
        static OnHitEventHandler singleton;
        return std::addressof(singleton);
    }

    RE::BSEventNotifyControl OnHitEventHandler::ProcessEvent(const RE::TESHitEvent* a_event,
                                                             RE::BSTEventSource<RE::TESHitEvent>* a_eventSource) {
        if (!a_event) return RE::BSEventNotifyControl::kContinue;
        
        auto av_to_heal = RE::ActorValue::kMagicka;        
        auto modifier = Settings::regeneration_value * 0.01;  
        const auto player = RE::PlayerCharacter::GetSingleton(); 

       

        if (a_event->cause) {
            if (a_event->cause->IsPlayerRef()) {                              
                if (auto targ = a_event->target.get(); targ->As<RE::Actor>()) {
                      
                    if (!player->GetActorRuntimeData().selectedSpells[RE::Actor::SlotTypes::kRightHand] &&
                        player->GetActorRuntimeData().selectedSpells[RE::Actor::SlotTypes::kLeftHand] && player->HasPerk(Utility::AbsorbPerk)) {
                        if (const auto equipped_right = player->GetEquippedObject(false)) {
                            if (const auto weapon = equipped_right->As<RE::TESObjectWEAP>();
                                weapon->IsOneHandedSword() || weapon->IsOneHandedAxe() || weapon->IsOneHandedMace()) {                                
                                if (auto magicka_pct =
                                        Hooks::GetActorValuePercent(player->As<RE::Actor>(), RE::ActorValue::kMagicka) *
                                        100;
                                    const auto magicka_av =
                                        player->AsActorValueOwner()->GetActorValue(RE::ActorValue::kMagicka)) {
                                    if (a_event->source == player->GetActorRuntimeData()
                                                               .selectedSpells[RE::Actor::SlotTypes::kLeftHand]
                                                               ->GetFormID()) {
                                        logger::info("noticed projectile");
                                        if (const auto equipped_left = player->GetEquippedObject(true)) {
                                            if (!equipped_left->IsWeapon() &&
                                                player->GetActorRuntimeData()
                                                    .selectedSpells[RE::Actor::SlotTypes::kLeftHand]) {
                                                logger::info("event ready for spell");
                                                if (auto stam_pct =
                                                        Hooks::GetActorValuePercent(player->As<RE::Actor>(),
                                                                                    RE::ActorValue::kStamina) *
                                                        100;
                                                    const auto stamina_av = player->AsActorValueOwner()->GetActorValue(
                                                        RE::ActorValue::kStamina)) {
                                                    if (stam_pct <= Settings::trigger_value && player->IsInCombat()) {
                                                        player->AsActorValueOwner()->RestoreActorValue(
                                                            RE::ACTOR_VALUE_MODIFIER::kDamage, RE::ActorValue::kStamina,
                                                            player->AsActorValueOwner()->GetBaseActorValue(
                                                                RE::ActorValue::kStamina) *
                                                                modifier);
                                                        logger::info("healed stamina");
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (magicka_pct <= Settings::trigger_value && player->IsInCombat() && a_event->source == weapon->GetFormID()) {
                                        //logger::info("Magicka Percentage is {}", magicka_pct);
                                        player->AsActorValueOwner()->RestoreActorValue(
                                            RE::ACTOR_VALUE_MODIFIER::kDamage, av_to_heal,
                                            player->AsActorValueOwner()->GetBaseActorValue(RE::ActorValue::kMagicka) *
                                                modifier);
                                    }
                                }
                            }
                        }
                       
                    }                     
                }                
            }             
        }
        
        
        return RE::BSEventNotifyControl::kContinue;
    }

    void OnHitEventHandler::Register() {
        const auto holder = RE::ScriptEventSourceHolder::GetSingleton();
        holder->AddEventSink(GetSingleton());
        logger::info("Registered hit event handler");
    }
}



/*



 if (const auto equipped_left = player->GetEquippedObject(true)) {
                            if (!equipped_left->IsWeapon() &&
                                player->GetActorRuntimeData().selectedSpells[RE::Actor::SlotTypes::kLeftHand]) {
                                if (auto stam_pct = Hooks::GetActorValuePercent(player->As<RE::Actor>(),
 RE::ActorValue::kStamina) * 100; const auto stamina_av =
                                        player->AsActorValueOwner()->GetActorValue(RE::ActorValue::kStamina)) {
                                    if (stam_pct <= Settings::trigger_value && player->IsInCombat()) {
                                        player->AsActorValueOwner()->RestoreActorValue(
                                            RE::ACTOR_VALUE_MODIFIER::kDamage, RE::ActorValue::kStamina,
                                            player->AsActorValueOwner()->GetBaseActorValue(RE::ActorValue::kStamina) *
                                                modifier);
                                    }
                                }
                            }
                        }





*/