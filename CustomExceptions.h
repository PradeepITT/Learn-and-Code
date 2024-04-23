#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <exception>
#include <string>

class InvalidInputException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid input data";
    }
};

class ProductNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Product not found";
    }
};

class InsufficientQuantityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Insufficient quantity";
    }
};

class DuplicateProductException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Duplicate product";
    }
};

#endif // CUSTOM_EXCEPTIONS_H
