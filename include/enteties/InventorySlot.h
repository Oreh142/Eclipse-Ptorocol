#ifndef INVENTORY_SLOT_H
#define INVENTORY_SLOT_H

#include "Item.h"

// ���� ���� � ���������: ��������� �� ������� + ���������� (��� ���������)
struct InventorySlot {
    Item* item = nullptr;
    int    count = 0;
};

#endif
