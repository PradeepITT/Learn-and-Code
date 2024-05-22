#include "Database.h"
#include <iostream>

using namespace std;

void Database::save(const Employee& employee) {
    cout << "Saving employee " << employee.getName() << " to the database." << endl;
}
