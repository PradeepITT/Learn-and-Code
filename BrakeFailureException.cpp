#include <iostream>
#include <stdexcept>
using namespace std;

class BrakeFailureException : public exception {
public:
    BrakeFailureException(const char* message) : exception(message) {}
};

