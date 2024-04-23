#include "ProductCatalog.h"
#include "Product.h"
#include "CustomExceptions.h"
#include <algorithm>
#include <stdexcept>
using namespace std;

void ProductCatalog::addProduct(const Product& product) {
    for (const Product& p : products) {
        if (p.getId() == product.getId()) {
            throw DuplicateProductException();
        }
    }
    products.push_back(product);
}

void ProductCatalog::updateProduct(int id, float price, int quantity) {
    bool found = false;
    for (Product& p : products) {
        if (p.getId() == id) {
            p.setPrice(price);
            p.setQuantity(quantity);
            found = true;
            break;
        }
    }
    if (!found) {
        throw invalid_argument("Product not found");
    }
}

void ProductCatalog::deleteProduct(int id) {
    auto it = remove_if(products.begin(), products.end(), [id](const Product& p) { return p.getId() == id; });
    if (it == products.end()) {
        throw invalid_argument("Product not found");
    }
    products.erase(it, products.end());
}
void ProductCatalog::sellProduct(int id, int quantity) {
    // Find product by ID
    auto it = std::find_if(products.begin(), products.end(),
                           [id](const Product& p) { return p.getId() == id; });
    if (it == products.end()) {
        throw ProductNotFoundException();
    }

    if (it->getQuantity() < quantity) {
        throw InsufficientQuantityException();
    }

    it->setQuantity(it->getQuantity() - quantity);
}

const vector<Product>& ProductCatalog::getProducts() const {
    return products;
}
