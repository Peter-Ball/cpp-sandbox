#include <iostream>
#include <string>

int main()
{
    // Get the name
    std::cout << "Please enter your first name: ";
    
    // name can't be const because it is not initialized immediately
    std::string name;
    std::cin >> name;

    // Build the message
    // Use = to initialize a variable value
    // use + to concatenate strings
    // The + operator is overloaded -- it's function depends on inputs
    // But an operator's associativity can never change
    // const means the value is immutable
    const std::string greeting = "Hello, " + name + "!";

    // Middle lines
    // Earlier variables initialized by [var] = [value]
    // Spaces is initialized by [var](expression, expression)
    // We ask the implementation to construct the variable
    // from the expressions in a way that depends on its *type*
    const std::string spaces(greeting.size(), ' ');
    // size() is a member function of the object greeting that returns int
    // greeting has type std::string, and the size() function of strings
    // returns the number of characters
    // ' ' is a character literal representing the space

    // It is defined that when we construct a string from an int n and a char c,
    // we get a string with n copies of c.

    const std::string second = "* " + spaces + " *";

    //top and bottom
    const std::string first(second.size(), '*');

    //write
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    return 0;
}