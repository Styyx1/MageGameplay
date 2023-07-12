#pragma once

#include "Utility.h"
#include "Settings.h"


namespace FormLookup {

    static void LoadPerk() {
        
        const auto settings = Settings::GetSingleton();
        logger::info("PerkID with FormLookup = {}", settings->activation_perk);
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();
        utility->AbsorbPerk = handler->LookupForm(Settings::ActivationPerkFormID, Settings::perk_mod_name)->As<RE::BGSPerk>();        
        logger::info("Loaded AbsorbPerk: {}", utility->AbsorbPerk->GetName());
    }

    static void LoadFormList() { 
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();
        utility->spell_formlist = handler->LookupForm(0x801, "MageGameplayOverhaul.esp")->As<RE::BGSListForm>();
        logger::info("Loaded Formlist");
    }

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
        ;
        logger::info("Loaded Spell");    
    }

}   // namespace FormLookup 
    //code from: https://github.com/ThirdEyeSqueegee/ReadingIsBad/blob/main/include/FormLookup.h