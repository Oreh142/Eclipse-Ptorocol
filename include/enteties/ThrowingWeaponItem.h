#ifndef THROWING_WEAPON_ITEM_H
#define THROWING_WEAPON_ITEM_H

#include "Item.h"
#include "Character.h"

class ThrowingWeaponItem : public Item {
public:
    ThrowingWeaponItem(const std::string& name,
        const std::string& description,
        int damage,
        DamageType type,
        int range)
        : Item(name, description)
        , _damage(damage)
        , _type(type)
        , _range(range)
    {}

    ItemCategory GetCategory() const override {
        return ItemCategory::Throwing;
    }

    DamageType GetDamageType() const { return _type; }
    int GetDamage()    const { return _damage; }
    int GetRange()     const { return _range; }

private:
    DamageType _type;
    int _damage;
    int _range;
};

#endif
