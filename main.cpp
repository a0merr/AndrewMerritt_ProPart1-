#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "ASList.h"
#include "CountryData.h"

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end   = str.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

bool loadCSV(const std::string& filename, ASList<CountryData>& list) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'\n";
        return false;
    }
    std::string line;
    int lineNum = 0;
    std::getline(file, line);
    while (std::getline(file, line)) {
        ++lineNum;
        if (trim(line).empty()) continue;
        std::stringstream ss(line);
        std::string col;
        std::vector<std::string> cols;
        while (std::getline(ss, col, ','))
            cols.push_back(trim(col));
        if (cols.size() < 6) {
            std::cerr << "Warning: Skipping malformed line " << lineNum << "\n";
            continue;
        }
        try {
            std::string name = cols[0];
            if (name.empty()) continue;
            double literacy = cols[1].empty() ? 0.0 : std::stod(cols[1]);
            double gdp      = cols[5].empty() ? 0.0 : std::stod(cols[5]);
            if (list.isFull()) { std::cerr << "List full.\n"; break; }
            list.insert(CountryData(name, literacy, gdp));
        } catch (const std::exception& e) {
            std::cerr << "Warning: Skipping line " << lineNum << " (" << e.what() << ")\n";
        }
    }
    file.close();
    return true;
}

int main() {
    std::cout << "=========================================\n";
    std::cout << "   ProPart1 - Alphabetically Sorted      \n";
    std::cout << "          Country Data                   \n";
    std::cout << "       Author: Andrew Merritt            \n";
    std::cout << "=========================================\n\n";

    ASList<CountryData> countryList(200);
    const std::string filename = "education-economy-data modified.csv";

    if (!loadCSV(filename, countryList)) return 1;

    std::cout << "Loaded " << countryList.getSize() << " countries.\n";
    std::cout << "-----------------------------------------\n\n";
    countryList.print();
    std::cout << "\n=========================================\n";
    std::cout << "Total countries displayed: " << countryList.getSize() << "\n";
    std::cout << "=========================================\n";
    return 0;
}
