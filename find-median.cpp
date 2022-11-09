#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <iomanip>
#include <algorithm>

using std::cout;    using std::cin;
using std::vector;  using std::endl;
using std::setprecision;

int main()
{
    cout << "Enter a list of space-separated"
            " numbers, then the end-of-file.";

    double x;
    // Vector is a template class
    vector<double> numbers;

    // invariant:
    // numbers contains all the numbers read so far
    while (cin>>x)
        numbers.push_back(x);
    
    // typedef defines a synonym for another type.
    // Here, vec_sz becomes a synonym for 
    // vector<double>::size_type
    typedef vector<double>::size_type vec_sz;
    vec_sz size = numbers.size();

    if (size == 0){
        cout << endl << "You must enter at least one number." << endl;
        return 1;
    }

    sort(numbers.begin(), numbers.end());

    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (numbers[mid] + numbers[mid-1])/2
                    : numbers[mid];
    
    cout << "The median is " << setprecision(3) << median << endl;
}