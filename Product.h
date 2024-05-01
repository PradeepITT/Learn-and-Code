#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;
    int quantity;

public:
    Product(int _id, string _name, float _price, int _quantity);
    int getId() const;
    string getName() const;
    float getPrice() const;
    int getQuantity() const;
    void setPrice(float _price);
    void setQuantity(int _quantity);
};

#endif // PRODUCT_H
