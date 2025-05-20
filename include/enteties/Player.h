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

    // ==== ��������� ====

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
    void ShowNotes()              const; // ������� ��� ������ � ��� �������, ��� ���������

    // ==== �������� �������� ������������� ====
    // (������� �� Character + ������ ���������� + �������� QuestItem)
    int GetStrength()    const override;
    int GetAgility()     const override;
    int GetEndurance()   const override;
    int GetAccuracy()    const override;
    int GetArmor()       const override;
    int GetSpeed()       const override;
    int GetEnergyRegenRate() const override {
        int regen = 2;  // ������

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
        // ����� ���������� ����� ���������� � .cpp ����
    }
    int GetResistance(DamageType type) const override;

    // ������ � ������� ��� UI
    const std::vector<InventorySlot>& GetEquipmentInventory()     const;
    const std::vector<InventorySlot>& GetSyringeInventory()  const;
    const std::vector<InventorySlot>& GetThrowingInventory() const;
    const std::vector<InventorySlot>& GetQuestInventory()    const;
    const std::array<EquipmentItem*, static_cast<size_t>(EquipSlot::Count)>& GetEquippedItems() const;
    EquipmentItem* GetEquippedWeapon() const;

private:
    // ������
    static constexpr size_t MAX_GEAR_SLOTS = 2;
    static constexpr size_t MAX_SYRINGE_SLOTS = 10;
    static constexpr size_t MAX_THROW_SLOTS = 5;

    // ���������� �� ����������
    std::vector<InventorySlot> gearInventory_;     // ������ EquipmentItem*
    std::vector<InventorySlot> syringeInventory_;  // ������ ConsumableItem*
    std::vector<InventorySlot> throwingInventory_;// ������ ThrowingWeaponItem*
    std::vector<InventorySlot> _questInventory;    // ������ QuestItem*

    std::vector<Note> _notes;

    // ����������
    std::array<EquipmentItem*, static_cast<size_t>(EquipSlot::Count)> _equippedItems{};
    EquipmentItem* _equippedWeapon = nullptr;

    // ����������� stats: ������� + ��, ��� � equippedItems_ � � questInventory_
    void RecalcStats();
};

#endif
