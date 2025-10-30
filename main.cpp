#include <iostream>
#include <fstream>
#include <sstream>
#include "ASList.h"
#include "CountryData.h"
using namespace std;

int main() {
    ASList<CountryData> list;
    ifstream file("education-economy-data.csv");

    if (!file.is_open()) {
        cerr << "Error: Could not open CSV file.\n";
        return 1;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string country, literacyStr, physician, gdpStr, gdpGrowth, gdpPerCapitaStr, category, unemployment, continent;

        getline(ss, country, ',');
        getline(ss, literacyStr, ',');
        getline(ss, physician, ',');
        getline(ss, gdpStr, ',');
        getline(ss, gdpGrowth, ',');
        getline(ss, gdpPerCapitaStr, ',');
        getline(ss, category, ',');
        getline(ss, unemployment, ',');
        getline(ss, continent, ',');

        CountryData data;
        data.country = country;
        data.literacyRate = stod(literacyStr);
        data.gdpPerCapita = stod(gdpPerCapitaStr);

        list.insert(data);
    }

    cout << "Data sorted alphabetically by Country (A–Z):\n";
    cout << "---------------------------------------------\n";
    list.print();

    file.close();
    return 0;
}
