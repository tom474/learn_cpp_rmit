// BASIC INHERITANCE
#if 0

#include <iostream>

using std::cout;

// Parent base class
class Animal {
    public:
        int age;

        void eat() {
            cout << "I can eat!\n";
        }
};

// Child derived class
class Dog : public Animal {
    public:
        void bark() {
            cout << "I can bark! Woof woof!!\n";
        }
};

int main() {
    Dog dog1;
    dog1.eat();     // dog1 has method from the parent class
    dog1.bark();    // dog1 has method from its own class
    dog1.age = 10;

    return 0;
}

#endif


// MULTILEVEL & MULTIPLE INHERITANCE
#if 0

#include <iostream>

using std::cout;
using std::string;

// Base class (grandfather)
class Animal {
    public:
        int age;

        Animal(int ageVal = 0)
        : age(ageVal) { 
            cout << "ANIMAL constructor \n";
        }
};

// Derived class (father)
class Cat : public Animal {
    public:
        string featherColor;
        Cat(int ageVal = 0, string featherColorVal = "") 
        : Animal(ageVal), featherColor(featherColorVal) {  
            cout << "CAT constructor\n";
        }
};

// Another base class (mother)
class Pet {
    public:
        string name;

        Pet(string nameVal = "")
        : name(nameVal) {  
            cout << "PET constructor\n";
        }
};

// Derived class (child)
class Kitten : public Pet, public Cat {
    public:
        Kitten(string nameVal = "", string featherColorVal = "", int ageVal = 0) 
        : Pet(nameVal), Cat(ageVal, featherColorVal)  {  
            cout << "KITTEN constructor\n";
        }
};

int main() {
    // Create objects through constructor
    Kitten kitten1("Hello Kitty", "White", 10);

    // Access all inherited members (attributes/methods)
    cout << "\nAge: " << kitten1.age << "\n";
    cout << "Feather color: " << kitten1.featherColor << "\n";
    cout << "Name: " << kitten1.name << "\n";
}

#endif


// FUNCTION OVERRIDING & VIRTUAL FUNCTIONS
#if 0

#include <iostream>

using std::cout;

class Animal {  // Parent base class
    public:
    // IMPORTANCE: remove virtual keyword will not call the child class eat() version in activity() function
    virtual void eat() {    // Virtual function
        cout << "I can eat!\n";
    }
};

class Dog : public Animal { // Child derived class
    public:
        void eat() {    // Override
            cout << "The dog eat in his own way\n";
        }

        void bark() {
            cout << "I can bark! Woof woof!!\n";
        }
};

// A function that takes a pointer/reference of Animal class
void animalEat(Animal &anm) {
    anm.eat();
}

int main() {
    Dog dog1;
    dog1.Animal::eat(); // Call method of the base class
    dog1.eat(); // Call the method of the derived class

    animalEat(dog1);    // Call the function with Dog object

    return 0;
}

#endif


// VECTOR
#if 0

#include <iostream>
#include <vector>

using std::cout;

int main() {
    std::vector<int> numVector {1, 2, 3, 4, 5};
    numVector.push_back(60);   // Add value 60 at the end
    numVector.push_back(70);   // Add value 70 at the end

    cout << "First element: " << numVector[0] << "\n";
    cout << "Last element: " << numVector[numVector.size() - 1] << "\n";

    numVector.pop_back();  // Remove last element
    numVector.erase(numVector.begin() + 2);   // Remove element at index 2

    // Print out all elements with range based for loop
    cout << "All elements after changes: ";
    for (int &num : numVector) {
        cout << num << " ";
    }

    return 0;
}

#endif 