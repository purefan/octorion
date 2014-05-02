#include <iostream>

using namespace std;

/*
    To declare a class you need to end it with a semicolon.
*/
class Person{

    // We want each person to have a name
    string name;

    // By default everything in a class is "private", but we want our functions
    // to be "public"
    public:
        // Here we define the prototype for the constructor that sets the name
        Person(string);

        // but we can also have a constructor that doesn't set the name
        Person();

        // We can also have a function that sets the name in case we want to change it.
        void set_name(string);

        // We also want each person to be able to "talk" to someone
        void tell(Person, string);

        // And each person should be able to "listen" when being talked.
        void listen(string);
};

// Now we implement the constructor that sets the name
Person::Person(string full_name){
    name = full_name;
}

// This is the other construction, which doesn't do anything in this case
Person::Person(){}

// Similar to the first constructor this function sets the name of this person
void Person::set_name(string full_name){
    name = full_name;
}

// when someone "tells" something to another, the 2nd one "listens"
void Person::tell(Person who, string what){
    who.listen(what);
}

void Person::listen(string what){
    // here we could store the message in a class property and call it memory
    // but for now lets just output to console
    cout << "My name is " << name << " and I heard: " << what;
}

int main()
{
    // Lets create a person with the first constructor
    Person Joey = Person("Joey Tribbiani");

    // And another with the second constructor
    Person Ross = Person();

    // but we also need to give it a name so:
    Ross.set_name("Ross Geller");

    // And now we tell Joey to tell something to Ross
    Joey.tell(Ross, "Heeyyy duudeee!");

    return 0;
}
