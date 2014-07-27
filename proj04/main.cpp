#include <iostream>
#include <vector>

using namespace std;
/* In this case we will look at inheritance and why it is important */

/* 1. Lets say we have a class Person: */

class Person {

private:
    int age;
    string name;
public:
    string getName();
    int getAge();
    Person(string);

    // 2. Ignore this line until you read 4.
    friend void introduce(Person);
};

Person::Person(string who){
    this->name = who;
    this->age = 14;
}

string Person::getName(){ return this->name; }


/* 3. And we have a random function that introduces a person */
void introduce(Person a){
    // 4. This next line will not work because 'age' is private
    // cout << "This is " << a.getName() << " and he is " << a.age << " y.o.";

    // 5. The only way to get the age property is by declaring this function as friend
    cout << "This is " << a.getName() << " and he is " << a.age << " y.o.";
    // 6. Which is what we did in 2.
}

int main(){

    Person Paul("Paul");
    introduce(Paul);
    return 0;
}
