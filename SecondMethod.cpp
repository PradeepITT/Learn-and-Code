//Using a Constructor to Initialize Values
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    // Constructor
    Person(string n, int a) : name(n), age(a) {}
};

int main() {
    Person person("John Doe", 30);

    cout << "Name: " << person.name << endl;
    cout << "Age: " << person.age << endl;

    return 0;
}
