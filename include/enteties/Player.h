#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "InventorySlot.h"

#include "ConsumableItem.h"
#include "EquipmentItem.h"
#include "ThrowingWeaponItem.h"
#include "QuestItem.h"

#include <vector>
#include <array>
#include <algorithm>

enum class EquipSlot {
    Head,
    Body,
    Hands,
    Feet,
    Accessory,
    Count
};

class Player : public Character {
public:
    Player(int strength,
        int agility,
        int endurance,
        int accuracy,
        int armor,
        int speed);

    // ==== Инвентарь ====

    bool AddItem(Item* item);

    bool RemoveItem(Item* item);

    bool UseConsumable(ConsumableItem* item);

    bool EquipItem(EquipmentItem* item, EquipSlot slot);
    EquipmentItem* UnequipItem(EquipSlot slot);

    bool EquipWeapon(EquipmentItem* weapon);
    EquipmentItem* UnequipWeapon();

    bool ThrowWeapon(ThrowingWeaponItem* item);

    bool AddQuestItem(QuestItem* item);
    bool RemoveQuestItem(QuestItem* item);

    void AddNote(const Note& note);      
    void ShowNotes()              const; // выводит все записи в том порядке, как добавлены

    // ==== Пересчёт итоговых характеристик ====
    // (базовые из Character + бонусы экипировки + пассивки QuestItem)
    int GetStrength()    const override;
    int GetAgility()     const override;
    int GetEndurance()   const override;
    int GetAccuracy()    const override;
    int GetArmor()       const override;
    int GetSpeed()       const override;
    int GetEnergyRegenRate() const override {
        int regen = 2;  // базово

        for (auto* eq : _equippedItems) {
            if (!eq) continue;
            regen += eq->getModifiers().energyRegenMod;
        }
        if (_equippedWeapon) {
            regen += _equippedWeapon->getModifiers().energyRegenMod;
        }

        for (auto& slot : _questInventory) {
            auto* qi = static_cast<QuestItem*>(slot.item);
            regen += qi->getModifiers().energyRegenMod;
        }
        return regen;
        // после реализация будет перенесена в .cpp файл
    }
    int GetResistance(DamageType type) const override;

    // Доступ к спискам для UI
    const std::vector<InventorySlot>& GetEquipmentInventory()     const;
    const std::vector<InventorySlot>& GetSyringeInventory()  const;
    const std::vector<InventorySlot>& GetThrowingInventory() const;
    const std::vector<InventorySlot>& GetQuestInventory()    const;
    const std::array<EquipmentItem*, static_cast<size_t>(EquipSlot::Count)>& GetEquippedItems() const;
    EquipmentItem* GetEquippedWeapon() const;

private:
    // Лимиты
    static constexpr size_t MAX_GEAR_SLOTS = 2;
    static constexpr size_t MAX_SYRINGE_SLOTS = 10;
    static constexpr size_t MAX_THROW_SLOTS = 5;

    // Контейнеры по категориям
    std::vector<InventorySlot> gearInventory_;     // хранит EquipmentItem*
    std::vector<InventorySlot> syringeInventory_;  // хранит ConsumableItem*
    std::vector<InventorySlot> throwingInventory_;// хранит ThrowingWeaponItem*
    std::vector<InventorySlot> _questInventory;    // хранит QuestItem*

    std::vector<Note> _notes;

    // Экипировка
    std::array<EquipmentItem*, static_cast<size_t>(EquipSlot::Count)> _equippedItems{};
    EquipmentItem* _equippedWeapon = nullptr;

    // Пересчитать stats: базовые + всё, что в equippedItems_ и в questInventory_
    void RecalcStats();
};

#endif
