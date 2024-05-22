#include "Employee.h"

Employee::Employee(const string& name, const string& address)
    : name(name), address(address) {}

string Employee::getName() const {
    return name;
}

string Employee::getAddress() const {
    return address;
}

void Employee::setName(const string& name) {
    this->name = name;
}

void Employee::setAddress(const string& address) {
    this->address = address;
}
