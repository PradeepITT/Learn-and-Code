#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "ProductCatalog.h"

class InventoryManager {
public:
    void displayInventory(const ProductCatalog& catalog) const;
};

#endif // INVENTORYMANAGER_H
