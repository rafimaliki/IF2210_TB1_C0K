#ifndef CONFIG_READER_HPP
#define CONFIG_READER_HPP

#include "../../std.hpp"
#include <fstream>

using std::ifstream;
using std::ifstream;
using std::getline;

class ConfigReader {
public:
    ConfigReader(const string& filename) : filename(filename) {}

    vector<string> readLines() {

        vector<string> lines;
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return lines; 
        }

        string line;

        while (getline(file, line)) {
            lines.push_back(line);
        }

        file.close();
        return lines;
    }

private:
    string filename;
};

#endif