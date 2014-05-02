== Classes I ==
Classes are a way to group code together, that way we can easily reuse it.

In this example, we will use a class to make people, and help them talk to each other.
You should know that "classes" are data abstractions, so the first thing we do is
create a class "Person", and from this class we will make more "person"s.

Each person that we create should have a name, should be able to tell something to
another Person, and should also be able to listen.

There are several ways to set the name of our Persons, one is to have a normal function
that updates a class property, another is to update that class property with the
constructor function. In this example we implement both ways.

=== Things to Remember ===
* Functions must include the type that they return: ```int function get_age()```
