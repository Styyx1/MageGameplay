#pragma once

#include "Utility.h"


namespace FormLookup {

    static void LoadPerk() {

        const auto handler = RE::TESDataHandler::GetSingleton();
        const auto utility = Utility::GetSingleton();
        utility->AbsorbPerk = handler->LookupForm(0x800, "MageGamplayOverhaul.esp")->As<RE::BGSPerk>();        
        logger::info("Loaded AbsorbPerk: {}", utility->AbsorbPerk->GetName());
    }
}   // namespace FormLookup 
    //code from: https://github.com/ThirdEyeSqueegee/ReadingIsBad/blob/main/include/FormLookup.h