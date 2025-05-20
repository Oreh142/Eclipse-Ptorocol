#ifndef QUEST_ITEM_H
#define QUEST_ITEM_H

#include "Item.h"
#include "EquipmentItem.h"

class QuestItem : public Item {
public:
    QuestItem(const std::string& name,
        const std::string& description,
        const StatModifiers& passiveMods)
        : Item(name, description)
        , _modifiers(passiveMods)
    {}

    ItemCategory GetCategory() const override {
        return ItemCategory::Quest;
    }

    const StatModifiers& GetModifiers() const { return _modifiers; }

private:
    StatModifiers _modifiers;
};

#endif
