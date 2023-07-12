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
        auto spell = player->GetActorRuntimeData().selectedSpells[RE::Actor::SlotTypes::kLeftHand];
        const auto keyword_wards = spell->HasKeyword(ward_keyword);
        if (keyword_wards)
        {
            return true;
        }
    }

    RE::SpellItem* IsInSpellList(RE::BGSListForm* formlist) 
    { 
        const auto spell_list = Utility::spell_formlist;
        if (formlist->ContainsOnlyType(RE::FormType::Spell)) {
            spell_list->GetAllForms();
            return spell_list->GetAllForms()->As<RE::SpellItem>();           
        }
    
    }

    inline static RE::TESConditionItem cond_item;
    inline static RE::TESCondition is_power_attacking;
    inline static RE::BGSPerk* AbsorbPerk;
    inline static RE::SpellItem* Spells;
    inline static RE::BGSKeyword* ward_keyword;
    inline static RE::BGSListForm* spell_formlist;
    

    static void InitUtility() {
        cond_item.data.comparisonValue.f = 1.0f;
        cond_item.data.functionData.function = RE::FUNCTION_DATA::FunctionID::kIsPowerAttacking;
        
        
        is_power_attacking.head = &cond_item;
        logger::info("Utility initialised");
    }
};
