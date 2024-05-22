#ifndef IDATABASE_H
#define IDATABASE_H

#include "Employee.h"

using namespace std;

class IDatabase {
public:
    virtual void save(const Employee& employee) = 0;
    virtual ~IDatabase() = default;
};

#endif // IDATABASE_H
