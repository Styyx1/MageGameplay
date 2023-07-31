#include "SKSE/Interfaces.h"
#include "Logging.h"
#include "Events.h"
#include "Settings.h"
#include "Utility.h"
#include "FormLookup.h"
#include "EquipEventHandler.h"

void Listener(SKSE::MessagingInterface::Message* message) {
    if (message->type == SKSE::MessagingInterface::kDataLoaded) {
        Events::OnHitEventHandler::Register();
<<<<<<< Updated upstream
        Utility::InitUtility();
=======
        logger::info("Hit Event Registered");
        EquipEvent::OnEquipHandler::Register(); 
        logger::info("Equip Event Started");
>>>>>>> Stashed changes
        Settings::LoadSettings();
        logger::info("Settings initialised");
        FormLookup::LoadPerk();
        logger::info("Perk initialised");
        FormLookup::LoadSpells();
<<<<<<< Updated upstream
        //FormLookup::AdjustScrolls();
=======
        logger::info("Spells initialised");
        FormLookup::LoadStaves();
        logger::info("Staves initialised");
        //FormLookup::LoadFormListID();
        //logger::info("Formlist Formdetection initialised");
        //FormLookup::AdjustScrolls();        
>>>>>>> Stashed changes
    }
}

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    InitializeLogging();
    const auto* plugin = SKSE::PluginDeclaration::GetSingleton();
    auto version = plugin->GetVersion();
    logger::info("{} {} is loading...", plugin->GetName(), version);
    Init(skse);

    if (const auto messaging = SKSE::GetMessagingInterface();
        !messaging->RegisterListener(Listener)) return false;

    logger::info("{} has finished loading.", plugin->GetName());
    return true;
}
