#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;    using std::vector;

// compute a grade from midterm, final, and homework grades
// storing as a function makes it easier to change grading scheme
// it also gives this computation a *name*
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// This function does *not* make a copy of the hw vector; we are passing a pointer
// const pointers are good whenever we are not going to change the parameter's value,
// and the parameter's type is time consuming to copy (e.g. vector, string)
// We have *overloaded* grade.
double grade(double midterm, double final, const vector<double>& hw)
{
    // more useful error message (eventually catch would be better)
    if (hw.size() == 0)
        throw domain_error("student has done no homework");

    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}