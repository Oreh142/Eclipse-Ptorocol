#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>

// Все реальные типы урона перечисляются до Count
enum class DamageType {
    Physical,
    Electric,
    Fire,
    Poison,
    Plasma,
    Psychological,
    Count   // не реальный, а для размера массивов
};

class Character {
public:
    Character(int strength,
        int agility,
        int endurance,
        int accuracy,
        int armor,
        int speed,
        const std::array<int, static_cast<size_t>(DamageType::Count)>& resistances =
        std::array<int, static_cast<size_t>(DamageType::Count)>{}); // resistances — массив размером Count

    virtual ~Character() = default;

    virtual int GetStrength()  const;
    virtual int GetAgility()   const;
    virtual int GetEndurance() const;
    virtual int GetAccuracy()  const;
    virtual int GetArmor()     const;
    virtual int GetSpeed()     const;
    virtual int GetEnergyRegenRate() const;

    int  GetMaxHealth()    const;
    int  GetHealth()       const;
    int  GetMaxEnergy()    const;
    int  GetEnergy()       const;
    bool IsAlive()         const;

    int GetResistance(DamageType type) const;

    void TakeDamage(int baseDamage, DamageType type = DamageType::Physical);
    bool AttemptHit(int targetAgility) const;

    bool UseEnergy(int energy);
    void RestoreEnergy(int energy);

protected:
    int _strength;
    int _agility;
    int _endurance;
    int _accuracy;
    int _armor;
    int _speed;

    int _maxHealth;
    int _health;
    int _maxEnergy;
    int _energy;

    std::array<int, static_cast<size_t>(DamageType::Count)> _resistances;
};

#endif