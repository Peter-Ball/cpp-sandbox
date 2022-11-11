#ifndef GUARD_median_h
// This  tells the preprocessor,
// process this code IF the GUARD_median_h preprocessor
// variable is not defined. This assures the preprocessor
// only loads the code once, no matter how many times it is
// included.

// It is good practice for ifndef to be the *very first line* of the file,
// Because many implementations check for it and remember not to load the
// file a second time.
#define GUARD_median_h

// median.h
#include <vector>

// We don't use a "using" declaration here
// because that would require our users
// to also use a using declaration.
// Never use a using declaration in a header.
double median(std::vector<double>);

#endif