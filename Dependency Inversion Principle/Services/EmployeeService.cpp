#include "EmployeeService.h"

EmployeeService::EmployeeService(IDatabase* database)
    : database(database) {}

void EmployeeService::saveEmployee(const Employee& employee) {
    database->save(employee);
}
