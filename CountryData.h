#ifndef COUNTRYDATA_H
#define COUNTRYDATA_H

#include <string>
using namespace std;

struct CountryData {
    string country;
    double literacyRate;
    double gdpPerCapita;

    bool operator<(const CountryData& other) const {
        return country < other.country;
    }
};

#endif
