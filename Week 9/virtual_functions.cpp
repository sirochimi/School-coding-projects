// Week 9 Activity 2: compare static and dynamic binding in one file.
#include <iostream>
using namespace std;
class Animal {
public:
    void speak() { cout << "Animal makes a generic sound." << endl; }
};
class Dog : public Animal {
public:
    void speak() { cout << "Dog barks: Woof! Woof!" << endl; }
};
class VirtualAnimal {
public:
    virtual ~VirtualAnimal() = default;
    virtual void speak() { cout << "Animal makes a generic sound." << endl; }
};
class VirtualDog : public VirtualAnimal {
public:
    void speak() override { cout << "Dog barks: Woof! Woof!" << endl; }
};
int main() {
    cout << "--- Without Virtual Keyword ---" << endl;
    Dog dog; Animal *pet = &dog; pet->speak();
    cout << "--- With Virtual Keyword ---" << endl;
    VirtualDog virtualDog; VirtualAnimal *virtualPet = &virtualDog; virtualPet->speak();
    return 0;
}
