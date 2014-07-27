#include <iostream>

using namespace std;

/*
    In this project we will look at polymorphism.
    Polymorphism is basically to take advantage that a pointer
    to a child class (remember inheritance) is compatible with
    a pointer to the parent class.
*/

// A basic class
class Person{
public:
    int age;
    void setAge(int i);
};
void Person::setAge(int age){ this->age = age;}

// and a simple inheritance case
class Diver : public Person{
public:
    int getAge();
};
int Diver::getAge(){ return this->age; }

int main()
{
    // Normal instantiation
    Diver Marco;

    // This is the magic line:
    Person * Donald = &Marco;
    // what is happening is that we create a pointer of type Person,
    // but we assign it the address to the Marco object

    // This allows us to do things like:
    Donald->setAge(21);

    cout << "Marco is " << Marco.age << " years old";

    // So basically, we went around Marco (through Donald) to set
    // his (Marco's) age, all thanks to polymorphism

    return 0;
}
