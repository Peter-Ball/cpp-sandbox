// An updated name-frame that uses loops to be more flexible

#include <iostream>
#include <string>

// Using declaration to simply code
using std::cout;    using std::endl;
using std::cin;    using std::string;

int main()
{
    // Get the name
    cout << "Please enter your first name: ";
    
    // name can't be const because it is not initialized immediately
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    // Rewritten from here

    cout << endl;
    cout << "How much padding should the frame have?";

    // The number of blanks surrounding the greeting
    int pad;
    cin >> pad;

    if(pad < 0) {
        cout << "The number must be 0 or larger." << endl;
        return 1;
    }

    const string spaces(greeting.size() + pad * 2, ' ');

    // total number of rows to write
    const int rows = pad * 2 + 3;

    // separate output from input
    cout << endl;

    // write r rows of output
    int r = 0;

    // invariant: we have written r rows so far
    // Note to self: explicitly naming invariant improves readability
    // Invariant is true here
    while (r != rows) {
        // We can assume invariant is true here
        
        // write a row of output (makes invariant false)
        // :: is the scope operator. We want the type size_type from the class string
        // which is from the namespace std. This is the appropriate type
        // for holding the number of characters in a string.
        const string::size_type cols = greeting.size() + pad * 2 + 2;
        // Note: we don't use int because we don't know how big greeting.size() is -- it
        // could be too big for the int type! Its good practice to use the most
        // correct type for the job.

        string::size_type c = 0;

        // invariant: we have written c characters so far in the current row
        while (c != cols) {
            // Relational operators (==) have lower precedence
            // than arithmetic operators (||)
            if (r == 0 || r == rows-1 || 
                    c == 0 || c == cols-1) {
                    cout << "*";
                    ++c;
                }
            else {
                if (r == pad + 1) {
                    if (c == pad + 1) {
                        cout << greeting;
                        c += greeting.size();
                    }
                    else {
                        cout << " ";
                        ++c;
                    }
                }
                else {
                    cout << spaces;
                    c += cols -2;
                }
            }
        }

        cout << endl;

        // incrementing r makes invariant true again
        ++r;
    }
    // we can conclude that invariant is true here


    return 0;
}