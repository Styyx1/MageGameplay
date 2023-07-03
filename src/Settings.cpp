#include "Settings.h"

#include "SimpleIni.h"

Settings* Settings::GetSingleton() {
    static Settings singleton;
    return std::addressof(singleton);
}

void Settings::LoadSettings() {
    logger::info("Loading settings");

    CSimpleIniA ini;

    ini.SetUnicode();
    ini.LoadFile(R"(.\Data\SKSE\Plugins\MageGameplay.ini)");

    trigger_value = ini.GetDoubleValue("General", "bTriggerValue");
    regeneration_value = ini.GetDoubleValue("General", "bRegenerationValue");

    

    logger::info("Loaded settings");
}
