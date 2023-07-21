#pragma once

#include "Utility.h"
#include "Settings.h"

namespace FormLookup {

    // Perk that triggers the absorption. can be any perk from any mod via ini file
    static void LoadPerk() 
    {        
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();
        utility->AbsorbPerk = handler->LookupForm(Settings::ActivationPerkFormID, Settings::perk_mod_name)->As<RE::BGSPerk>();        
        //logger::info("Loaded AbsorbPerk: {}", utility->AbsorbPerk->GetName());
        
    }
    // unused for now, maybe plans for later. If called in main, it powers up every scroll 1.5 times 
    static void AdjustScrolls() {
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();                
        auto& scrolls = handler->GetFormArray<RE::ScrollItem>();
        for (RE::ScrollItem*& scroll : scrolls) {
            scroll->GetCostliestEffectItem()->effectItem.magnitude *= 1.50;
        }                
    }
    // Spells from a formlist. Is used to check if the player is casting a ward spell to regenerate magicka while
    // casting it when the player gets hit
    static void LoadSpells() 
    {
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();               
        utility->spell_formlist = handler->LookupForm<RE::BGSListForm>(0x801, "MageGameplayOverhaul.esp");
        logger::info("Loaded Ward spells");        
    }
    //Staves from a fromlist. Used to check extra effects for spells when a staff is equipped
    static void LoadStaves() { 
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();
        utility->staff_formlist = handler->LookupForm<RE::BGSListForm>(0x802, "MageGameplayOverhaul.esp");
        logger::info("Loaded Staves");
    }
}   