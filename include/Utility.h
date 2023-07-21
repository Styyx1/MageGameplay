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
    inline static RE::TESConditionItem cond_item;
    inline static RE::TESCondition is_in_list;
    inline static RE::BGSPerk* AbsorbPerk{nullptr};
    inline static RE::SpellItem* Spells{nullptr};
    inline static RE::BGSListForm* spell_formlist{nullptr};
    
    static void InitUtility() {
        cond_item.data.comparisonValue.f = 1.0f;        
        cond_item.data.functionData.function = RE::FUNCTION_DATA::FunctionID::kIsInList;
        
        
        is_in_list.head = &cond_item;
        logger::info("Utility initialised");
    }
};
