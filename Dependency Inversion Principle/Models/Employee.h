#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
public:
    Employee(const string& name, const string& address);

    // Getters and setters
    string getName() const;
    string getAddress() const;
    void setName(const string& name);
    void setAddress(const string& address);

private:
    string name;
    string address;
};

#endif // EMPLOYEE_H
