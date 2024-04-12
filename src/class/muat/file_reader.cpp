#include "file_reader.hpp"

FileReader::FileReader(const string& filename) : filename(filename) {}

vector<vector<string>> FileReader::readFile() {
    
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

