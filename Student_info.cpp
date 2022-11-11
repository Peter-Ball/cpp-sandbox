// source file for Student_info related functions

// It's a good idea to include the declarations in the 
// file where we store the definitions, because it
// allows the compiler to check for consistency between the two
#include "Student_info.h"

// Using declarations are fine in the source code
using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

// Because we're using a custom type, we're safe to overload read()
istream& read(istream& is, Student_info& s)
{
    // read and store student's name, midterm, and final grades
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);    // read and store all the student's homework grades
    return is;
}

// read homework grades from an input stream into a vector<double>
// These pointers are *not* const -- means we intend to change the values.
// if pointers are not const, then they must point to Ivalues: non-temporary
// values. So couldn't feed the return from a function. Would have to stored in variable.
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}