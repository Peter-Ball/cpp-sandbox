#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>

using std::domain_error;    using std::istream;
using std::cin;             using std::cout;
using std::setprecision;    using std::streamsize;
using std::vector;          using std::endl;
using std::string;          using std::max;


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


struct Student_info {
    // this type has four data members
    string name;
    double midterm, final;
    vector<double> homework;
};

// Because we're using a custom type, we're safe to overload read()
istream& read(istream& is, Student_info& s)
{
    // read and store student's name, midterm, and final grades
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);    // read and store all the student's homework grades
    return is;
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records, and find the length of the longest name
    while(read(cin, record)) {
        // note: max() *requires* that both arguments have the same type
        // which is why maxlen *must* have type string::size_type, not just int
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the records
    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i = 0;
        i != students.size(); ++i) {
        
        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name
            << string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }

    return 0;

}