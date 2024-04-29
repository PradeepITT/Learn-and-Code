#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H
using namespace std;
#include <exception>
#include <string>

class InvalidInputException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid input data";
    }
};

class ProductNotFoundException : public exception {
public:
    const char* what() const noexcept override {
        return "Product not found";
    }
};

class InsufficientQuantityException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient quantity";
    }
};

class DuplicateProductException : public exception {
public:
    const char* what() const noexcept override {
        return "Duplicate product";
    }
};

#endif // CUSTOM_EXCEPTIONS_H
