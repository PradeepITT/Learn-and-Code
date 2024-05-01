#include "ProductCatalog.h"
#include "Product.h"
#include "CustomExceptions.h"
#include <algorithm>
#include <stdexcept>
using namespace std;

void ProductCatalog::addProduct(const Product& product) {
    for (const Product& existingProduct : products) {
        if (existingProduct.getId() == product.getId()) {
            throw DuplicateProductException();
        }
    }
    products.push_back(product);
}

void ProductCatalog::updateProduct(int id, float price, int quantity) {
    auto productToUpdate = find_if(products.begin(), products.end(), [id](const Product& p) { return p.getId() == id; });
    if (productToUpdate == products.end()) {
        throw ProductNotFoundException();
    }

    productToUpdate->setPrice(price);
    productToUpdate->setQuantity(quantity);
}

void ProductCatalog::deleteProduct(int id) {
    auto productToDelete = remove_if(products.begin(), products.end(), [id](const Product& p) { return p.getId() == id; });
    if (productToDelete == products.end()) {
        throw ProductNotFoundException();
    }
    products.erase(productToDelete, products.end());
}

void ProductCatalog::sellProduct(int id, int quantity) {
    auto productToSell = find_if(products.begin(), products.end(), [id](const Product& p) { return p.getId() == id; });
    if (productToSell == products.end()) {
        throw ProductNotFoundException();
    }

    if (productToSell->getQuantity() < quantity) {
        throw InsufficientQuantityException();
    }

    productToSell->setQuantity(productToSell->getQuantity() - quantity);
}

const vector<Product>& ProductCatalog::getProducts() const {
    return products;
}
