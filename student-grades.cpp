#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ios>

using std::domain_error;    using std::istream;
using std::cin;             using std::cout;
using std::setprecision;    using std::streamsize;
using std::vector;          using std::endl;


// compute a grade from midterm, final, and homework grades
// storing as a function makes it easier to change grading scheme
// it also gives this computation a *name*
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute the median of a vector<double>
// impt: a copy of vector is made, not a pointer to the original
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    // A convenience is that size and mid are protected to this scope now
    vec_sz size = vec.size();
    if (size==0){
        // Throwing an error is more general
        throw domain_error("median of an empty vector");
    }
    
    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
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

int main()
{
    // ask for midterm and final grades
    cout << "Please enter your midterm and final exam grades:";
    double midterm, final;
    cin >> midterm >> final;

    // ask for homework grades
    cout << "Enter all your grades, "
        "followed by end-of-file: ";

    vector<double> homework;

    // read in the homework grades
    read_hw(cin, homework);

    // compute and generate the final grade, if possible
    // (hurrah error handling!)
    try {
        // Because of the error handling, impt that we compute this separately
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is" << setprecision(3)
            << final_grade << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;
        return 1;
    }

    return 0;

}

