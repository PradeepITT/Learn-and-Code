#include <iostream>
#include <stdexcept>
using namespace std;

class PersonInjuredException : public exception {
public:
    PersonInjuredException(const char* message) : exception(message) {}
};