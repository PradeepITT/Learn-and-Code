//Using Struct
#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    Person person = {"John Doe", 30};

    cout << "Name: " << person.name << endl;
    cout << "Age: " << person.age << endl;

    return 0;
}
