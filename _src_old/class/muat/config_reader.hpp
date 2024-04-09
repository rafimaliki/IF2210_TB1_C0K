#ifndef CONFIG_READER_HPP
#define CONFIG_READER_HPP

#include "../../std.hpp"
#include <fstream>
#include <bits/stdc++.h>

using std::ifstream;
using std::ifstream;
using std::getline;
using std::istringstream;

class ConfigReader {
private:
    string filename;
public:
    ConfigReader(const string& filename) : filename(filename) {}

    vector<vector<string>> readConfig() {
        vector<vector<string>> lines;

        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return lines;
        }

        string line;

        while (getline(file, line)) {
            lines.push_back(split(line));
        }

        file.close();
        return lines;
    }

    vector<string> split(const string &s) {
        vector<string> tokens;
        istringstream iss(s);
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

// class ParsePlantData {
//     public:
//         static vector<PlantData> parse(vector<string> lines) {
//             vector<PlantData> plantData;
//             for (const auto& line : lines) {
//                 vector<string> data = split(line, ',');
//                 PlantData plant(stoi(data[0]), data[1], data[2], data[3], data[4], stoi(data[5]));
//                 plantData.push_back(plant);
//             }
//             return plantData;
//         }
// }

#endif