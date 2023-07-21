#pragma once

#include "Utility.h"
#include "Settings.h"


namespace FormLookup {

    static void LoadPerk() 
    {        
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();
        utility->AbsorbPerk = handler->LookupForm(Settings::ActivationPerkFormID, Settings::perk_mod_name)->As<RE::BGSPerk>();        
        logger::info("Loaded AbsorbPerk: {}", utility->AbsorbPerk->GetName());
        // Perk that triggers the absorption. can be any perk from any mod
    }
    // unused for now, maybe plans for later
    static void AdjustScrolls() {
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();                
        auto& scrolls = handler->GetFormArray<RE::ScrollItem>();
        for (RE::ScrollItem*& scroll : scrolls) {
            scroll->GetCostliestEffectItem()->effectItem.magnitude *= 1.50;
        }                
    }
    static void LoadSpells() 
    {
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();               
        utility->spell_formlist = handler->LookupForm<RE::BGSListForm>(0x801, "MageGameplayOverhaul.esp");
        logger::info("Loaded Ward spells");
        // Spells from a formlist. Is used to check if the player is casting a ward spell to regenerate magicka while
        // casting it when the player gets hit
    } 
}   