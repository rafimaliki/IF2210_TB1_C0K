#include "config_reader.hpp"

ConfigReader::ConfigReader(const string& filename) : filename(filename) {}

vector<string> ConfigReader::split(const string &s) {
        vector<string> tokens;
        istringstream iss(s);
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        return tokens;
}
vector<vector<string>> ConfigReader::readConfig() {
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

        // for (auto line : lines) {
        //     for (auto word : line) {
        //         cout << word << " ";
        //     }
        //     cout << endl;
        // }

        return lines;
    }

