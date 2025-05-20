#ifndef EQUIPMENT_ITEM_H
#define EQUIPMENT_ITEM_H

#include "Item.h"
#include "Character.h"
#include <array>

struct StatModifiers {
    int strengthMod = 0;
    int agilityMod = 0;
    int enduranceMod = 0;
    int accuracyMod = 0;
    int armorMod = 0;
    int speedMod = 0;
    int energyRegenMod = 0;
    std::array<int, static_cast<size_t>(DamageType::Count)> resistanceMod{};
};

class EquipmentItem : public Item {
public:
    EquipmentItem(const std::string& name,
        const std::string& description,
        const StatModifiers& mods)
        : Item(name, description)
        , _modifiers(mods)
    {}

    ItemCategory GetCategory() const override {
        return ItemCategory::Equipment;
    }

    const StatModifiers& GetModifiers() const { return _modifiers; }

private:
    StatModifiers _modifiers;
};

#endif
