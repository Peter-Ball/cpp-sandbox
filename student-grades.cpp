#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include "grade.h"
#include "Student_info.h"

using std::domain_error;    using std::sort;
using std::cin;             using std::cout;
using std::setprecision;    using std::streamsize;
using std::vector;          using std::endl;
using std::string;          using std::max;

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