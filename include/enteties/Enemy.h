#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <string>

class Enemy : public Character {
public:
    Enemy(const std::string& name,
        int attentiveness,
        int strength,
        int agility,
        int endurance,
        int accuracy,
        int armor,
        int speed,
        int energyRegenRate,
        const std::array<int, static_cast<size_t>(DamageType::Count)>& resistances =
        std::array<int, static_cast<size_t>(DamageType::Count)>());

    const std::string& GetName() const;
    int GetAttentiveness()    const;
    int GetEnergyRegenRate() const override;

private:
    std::string _name;
    int _attentiveness;
    int _energyRegenRate;
};

#endif