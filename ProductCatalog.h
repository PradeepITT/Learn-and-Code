#ifndef PRODUCTCATALOG_H
#define PRODUCTCATALOG_H

#include "Product.h"
#include <vector>
using namespace std;

class ProductCatalog {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product);
    void updateProduct(int id, float price, int quantity);
    void deleteProduct(int id);
    void sellProduct(int id, int quantity);
    const vector<Product>& getProducts() const;
};

#endif // PRODUCTCATALOG_H
