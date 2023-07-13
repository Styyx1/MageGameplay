#pragma once

class Settings {
protected:
    Settings() = default;
    ~Settings() = default;

public:
    Settings(const Settings&) = delete;
    Settings(Settings&&) = delete;
    Settings& operator=(const Settings&) = delete;
    Settings& operator=(Settings&&) = delete;

    static Settings* GetSingleton();
    static void LoadSettings();

    inline static float trigger_value = 50.0;                                   //  fTriggerValue
    inline static float attack_regeneration_value = 0.5;                        //  fAttackRegenerationValue
    inline static float block_regeneration_value = 2.0;                         //  fBlockRegenerationValue
    inline static float cast_regeneration_value = 1.0;                          //  fCastRegenerationValue
    inline static std::string activation_perk;                                  //  uActivationPerk
    inline static RE::BGSPerk* ActivationPerk;                                  //  
    inline static RE::FormID ActivationPerkFormID;                              //  
    inline static std::string_view perk_mod_name = "MageGamplayOverhaul.esp";   //  sPerkModName
    inline static bool extra_logging = false;                                   //  bExtraLogging

    static RE::FormID ParseFormID(const std::string& str);


    

};