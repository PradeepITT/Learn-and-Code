#ifndef DATABASE_H
#define DATABASE_H

#include "IDatabase.h"

using namespace std;

class Database : public IDatabase {
public:
    void save(const Employee& employee) override;
};

#endif // DATABASE_H
