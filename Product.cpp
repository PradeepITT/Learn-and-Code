#include "Product.h"
#include <stdexcept>
using namespace std;

Product::Product(int _id, string _name, float _price, int _quantity)
    : id(_id), name(_name), price(_price), quantity(_quantity) {}

int Product::getId() const { return id; }

string Product::getName() const { return name; }

float Product::getPrice() const { return price; }

int Product::getQuantity() const { return quantity; }

void Product::setPrice(float _price) {
    if (_price < 0)
        throw invalid_argument("Price cannot be negative");
    price = _price;
}

void Product::setQuantity(int _quantity) {
    if (_quantity < 0)
        throw invalid_argument("Quantity cannot be negative");
    quantity = _quantity;
}
