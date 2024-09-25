#include <iostream>

using std::cout;
using std::string;

class Cat {
    public:
        string name;
        int age;

        // Default constructor with default arguments
        Cat(string nameVal = "", int ageVal = 0)
        : name(nameVal), age(ageVal){}
};

class Person {
    public:
        Cat cat;    // Attribute is an object
        string name;

        // Default constructor with default arguments
        Person(Cat catVal = Cat(), string nameVal = "")
        : cat(catVal), name(nameVal) {}
};

int main() {
    Person personArr[3] = {
        Person(Cat("Cat1", 3), "Cuong"),
        Person(Cat("Cat2", 4), "Tom"),
        Person(Cat("Cat3", 5), "Tommy")
    };

    Person maxPerson = personArr[0];    // Assume person 0 is the one that has the oldest cat
    for (int i = 1; i <= 2; i++) {       // Compare the cat's age with that of other people's cats
        if (maxPerson.cat.age < personArr[i].cat.age) {
            maxPerson = personArr[i];
        }
    }

    cout << "Person with the oldest cat:\n";
    cout << "Person Name = " << maxPerson.name << "\n";
    cout << "Cat Name = " << maxPerson.cat.name << "\n";
    cout << "Cat Age = " << maxPerson.cat.age << "\n";

    return 0;
}