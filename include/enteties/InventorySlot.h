#ifndef INVENTORY_SLOT_H
#define INVENTORY_SLOT_H

#include "Item.h"

// Один слот в инвентаре: указатель на предмет + количество (для стакаемых)
struct InventorySlot {
    Item* item = nullptr;
    int    count = 0;
};

#endif
