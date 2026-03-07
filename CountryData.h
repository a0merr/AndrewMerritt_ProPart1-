#ifndef COUNTRYDATA_H
#define COUNTRYDATA_H

#include <string>
#include <iostream>

struct CountryData {
    std::string countryName;
    double literacyRate;
    double gdpPerCapita;

    CountryData() : countryName(""), literacyRate(0.0), gdpPerCapita(0.0) {}

    CountryData(const std::string& name, double literacy, double gdp)
        : countryName(name), literacyRate(literacy), gdpPerCapita(gdp) {}

    bool operator<(const CountryData& other) const {
        return countryName < other.countryName;
    }
    bool operator==(const CountryData& other) const {
        return countryName == other.countryName;
    }
    bool operator>(const CountryData& other) const {
        return countryName > other.countryName;
    }
    friend std::ostream& operator<<(std::ostream& os, const CountryData& c) {
        os << "Country: " << c.countryName
           << " | Literacy Rate: " << c.literacyRate << "%"
           << " | GDP per Capita: $" << c.gdpPerCapita;
        return os;
    }
};

#endif
