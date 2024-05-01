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

void ProductCatalog::updateProduct(int productId, float newPrice, int newQuantity) {
    bool found = false;
    for (Product& product : products) {
        if (product.getId() == productId) {
            product.setPrice(newPrice);
            product.setQuantity(newQuantity);
            found = true;
            break;
        }
    }
    if (!found) {
        throw invalid_argument("Product not found");
    }
}

void ProductCatalog::deleteProduct(int productId) {
    auto productToDelete = remove_if(products.begin(), products.end(), [productId](const Product& product) { return product.getId() == productId; });
    if (productToDelete == products.end()) {
        throw invalid_argument("Product not found");
    }
    products.erase(productToDelete, products.end());
}

void ProductCatalog::sellProduct(int productId, int quantity) {
    // Find product by ID
    auto productIt = std::find_if(products.begin(), products.end(),
                           [productId](const Product& product) { return product.getId() == productId; });
    if (productIt == products.end()) {
        throw ProductNotFoundException();
    }

    if (productIt->getQuantity() < quantity) {
        throw InsufficientQuantityException();
    }

    productIt->setQuantity(productIt->getQuantity() - quantity);
}

const vector<Product>& ProductCatalog::getProducts() const {
    return products;
}
