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

    inline static float trigger_value = 50.0;
    inline static float attack_regeneration_value = 0.5;
    inline static float block_regeneration_value = 2.0;
    inline static float cast_regeneration_value = 1.0;
    inline static std::uint32_t activation_perk = 0x800;
    inline static std::string_view perk_mod_name = "MageGamplayOverhaul.esp";
};