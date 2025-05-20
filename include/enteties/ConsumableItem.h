#ifndef CONSUMABLE_ITEM_H
#define CONSUMABLE_ITEM_H

#include "Item.h"

class ConsumableItem : public Item {
public:
    ConsumableItem(const std::string& name,
        const std::string& description,
        int hpRestore,
        int energyRestore)
        : Item(name, description)
        , _hpRestore(hpRestore)
        , _energyRestore(energyRestore)
    {}

    ItemCategory GetCategory() const override {
        return ItemCategory::Consumable;
    }

    int GetHpRestore()    const { return _hpRestore; }
    int GetEnergyRestore() const { return _energyRestore; }

private:
    int _hpRestore;
    int _energyRestore;
};

#endif
