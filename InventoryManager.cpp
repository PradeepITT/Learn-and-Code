#include "InventoryManager.h"
#include <iostream>

using namespace std;

void InventoryManager::displayInventory(const ProductCatalog& catalog) const {
    const vector<Product>& products = catalog.getProducts();

    if (products.empty()) {
        cout << "Inventory is empty." << endl;
    } else {
        cout << "Inventory:\n";
        cout << "ID\tName\tPrice \tQuantity\n";
        for (const Product& product : products) {
            cout << product.getId() << "\t" << product.getName() << "\tRs " << product.getPrice() << "\t" << product.getQuantity() << endl;
        }
    }
}
