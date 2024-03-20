// File: main.cpp

#include <iostream>
#include <vector>
#include <string>

#include "classes/config_reader/config_reader.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {

    cout << "Welcome to FARM CITY!" << endl;

    ConfigReader animal_config("../config/animals.txt");
    vector<string> animal_data = animal_config.readLines();

    for (const auto& line : animal_data) {
        cout << line << endl;
    }



    return 0;
}