#include <iostream>

/*
    A virtual function is a function that can be redefined in a child class
    (remember inheritance), it is a good way to provide a default behavior
    to a function.
*/
using namespace std;


class Person{
    public:
    virtual string greet(){
        return "Hello";
    }
};

class Manager : public Person{
    public:
    string greet(){
        return "Hi";
    }
};

// Seller does not redefine the virtual function greet()
class Seller : public Person{

};


int main()
{
    Person Matt;
    Manager Howard;
    Seller Ron;
    cout << "Matt says " << Matt.greet() << endl;
    cout << "Howard says " << Howard.greet() << endl;
    cout << "Ron says " << Ron.greet() << endl;
    return 0;
}
