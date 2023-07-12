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

    trigger_value = ini.GetDoubleValue("General", "bTriggerValue");
    attack_regeneration_value = ini.GetDoubleValue("General", "bAttackRegenerationValue");
    block_regeneration_value = ini.GetDoubleValue("General", "bBlockRegenerationValue");
    cast_regeneration_value = ini.GetDoubleValue("General", "bCastRegenerationValue");
    activation_perk = ini.GetDoubleValue("Perk", "bActivationPerk");
    perk_mod_name = ini.GetValue("Perk", "bPerkModName");

}