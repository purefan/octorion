#include <iostream>

using namespace std;
/*
    In this project we will look at inheritance.
    One way to define inheritance is to say that it is like
    having a class that copies everything from another class
*/

// Here we have a basic Person class, doesnt do much...
class Person{
private:
    string name;
public:
    string getName();
    Person(string a);
};

Person::Person(string who){ this->name = who;}
string Person::getName(){ return this->name; }

// but then we can say that there are more specific ways to
// define a person
class Carpenter : public Person{
private:
    string specialty;
public:
    string getSpecialty();
    void setSpecialty(string a);
    // We have to be careful with the constructor of a "child" class:
    Carpenter(string a) : Person(a) {
        // You can leave this constructor empty and "a" will be the
        // string parameter in the constructor for Person
    };

    Carpenter(string name, string specialty) : Person(name){
        // In this constructor we define both things: the name and the
        // specialty
        this->specialty = specialty;
    }
};

string Carpenter::getSpecialty(){ return this->specialty; }
void Carpenter::setSpecialty(string a){ this->specialty = a; }



/*
    In the Carpenter class we defined another attribute ("specialty"),
    a setter and a getter, but this class also has the "name" attribute
    from the "parent" class Person
*/
int main()
{
    Carpenter Paul("Paul");
    // Notice how we created a Carpenter but it still has a name:
    cout << "Hello " << Paul.getName() << endl;
    // that's because from the Carpenter constructor we call the Person constructor

    // Now lets create another Carpenter and set its specialty:
    Carpenter Mark("Mark", "floors");
    cout << "Hello " << Mark.getName() << " I hear you're good with " << Mark.getSpecialty() << endl;
    return 0;
}
