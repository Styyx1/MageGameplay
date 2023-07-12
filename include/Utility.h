#pragma once

#include "Settings.h"

class Utility {
protected:
    Utility() = default;
    ~Utility() = default;

public:
    Utility(const Utility&) = delete;            // Prevent copy construction
    Utility(Utility&&) = delete;                 // Prevent move construction
    Utility& operator=(const Utility&) = delete; // Prevent copy assignment
    Utility& operator=(Utility&&) = delete;      // Prevent move assignment

    static Utility* GetSingleton() {
        static Utility singleton;
        return std::addressof(singleton);
    }

    static bool WardSpell() {
        const auto player = RE::PlayerCharacter::GetSingleton();
        const auto util = Utility::GetSingleton();
        const auto spell_form_list = util->spell_formlist;
        auto spell = player->GetActorRuntimeData().selectedSpells[RE::Actor::SlotTypes::kLeftHand];
        
        if (Utility::is_in_list(spell_form_list->AsReference(), spell->AsReference())) {
            return true;
        } 
        else
            return false;
    }
    inline static RE::MagicItem* WardCast() 
    { 
        const auto player = RE::PlayerCharacter::GetSingleton();
        auto spell = player->GetActorRuntimeData().selectedSpells[RE::Actor::SlotTypes::kLeftHand];
        if (Utility::WardSpell()) {
            logger::info("Ward spell = {}", spell->GetName());
            return spell;
        } else
            return nullptr;
    
    }

    

    inline static RE::TESConditionItem cond_item;
    inline static RE::TESCondition is_in_list;
    inline static RE::BGSPerk* AbsorbPerk;
    inline static RE::SpellItem* Spells;
    inline static RE::BGSKeyword* ward_keyword;
    inline static RE::BGSListForm* spell_formlist;
    

    static void InitUtility() {
        cond_item.data.comparisonValue.f = 1.0f;        
        cond_item.data.functionData.function = RE::FUNCTION_DATA::FunctionID::kIsInList;
        
        
        is_in_list.head = &cond_item;
        logger::info("Utility initialised");
    }
};
