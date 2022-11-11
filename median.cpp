// source file for the median function
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;    using std::sort;    using std::vector;

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
