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
    activation_perk = std::uint32_t(ini.GetValue("Perk", "uActivationPerk"));
    
    logger::info("PerkID = {}", Settings::activation_perk);
    
    perk_mod_name = ini.GetValue("Perk", "sPerkModName");

}