#include "config_reader.hpp"

ConfigReader::ConfigReader(const string& filename) : filename(filename) {}

vector<vector<string>> ConfigReader::readConfig() {
    
        vector<vector<string>> lines;

        ifstream file(filename);

        if (!file.is_open()) {
            throw FailReadFileException();
        }

        string line;

        while (getline(file, line)) {
            lines.push_back(Util::split(line));
        }

        file.close();

        return lines;
    }

