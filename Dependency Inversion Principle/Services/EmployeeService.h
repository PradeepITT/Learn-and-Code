#ifndef EMPLOYEESERVICE_H
#define EMPLOYEESERVICE_H

#include "IDatabase.h"

using namespace std;

class EmployeeService {
public:
    EmployeeService(IDatabase* database);
    void saveEmployee(const Employee& employee);

private:
    IDatabase* database;
};

#endif // EMPLOYEESERVICE_H
