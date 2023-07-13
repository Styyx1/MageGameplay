#include "Settings.h"
#include "Utility.h"
#include <SimpleIni.h>

Settings* Settings::GetSingleton() 
{
    static Settings singleton;
    return std::addressof(singleton);
}
void Settings::LoadSettings() 
{
    logger::info("Loading settings");

    CSimpleIniA ini;

    ini.SetUnicode();
    ini.LoadFile(R"(.\Data\SKSE\Plugins\MageGameplay.ini)");

    trigger_value = ini.GetDoubleValue("General", "fTriggerValue");
    attack_regeneration_value = ini.GetDoubleValue("General", "fAttackRegenerationValue");
    block_regeneration_value = ini.GetDoubleValue("General", "fBlockRegenerationValue");
    cast_regeneration_value = ini.GetDoubleValue("General", "fCastRegenerationValue");
    std::string activation_perk = ini.GetValue("Perk", "uActivationPerk");
    extra_logging = ini.GetBoolValue("Logging", "bExtraLogging");
    
    if (!activation_perk.empty()) {
        ActivationPerkFormID = ParseFormID(activation_perk);
    }
    //logger::info("PerkID = {}", Settings::ActivationPerkFormID);    
    perk_mod_name = ini.GetValue("Perk", "sPerkModName");    
}
RE::FormID Settings::ParseFormID(const std::string& str) {
    RE::FormID result;
    std::istringstream ss{str};
    ss >> std::hex >> result;
    return result;
}
