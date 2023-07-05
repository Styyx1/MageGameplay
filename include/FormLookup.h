#pragma once

#include "Utility.h"


namespace FormLookup {

    static void LoadPerk() {

        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();
        utility->AbsorbPerk = handler->LookupForm(0x800, "MageGamplayOverhaul.esp")->As<RE::BGSPerk>();        
        logger::info("Loaded AbsorbPerk: {}", utility->AbsorbPerk->GetName());
    }

    static void AdjustScrolls() {
        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();
                
            auto& scrolls = handler->GetFormArray<RE::ScrollItem>();
            for (RE::ScrollItem*& scroll : scrolls) {
                scroll->GetCostliestEffectItem()->effectItem.magnitude *= 1.50;                
        }
    }

}   // namespace FormLookup 
    //code from: https://github.com/ThirdEyeSqueegee/ReadingIsBad/blob/main/include/FormLookup.h