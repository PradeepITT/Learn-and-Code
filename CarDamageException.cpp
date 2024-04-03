#include <iostream>
#include <stdexcept>

using namespace std;

class CarDamageException : public exception {
public:
    CarDamageException(const char* message) : exception(message) {}
};