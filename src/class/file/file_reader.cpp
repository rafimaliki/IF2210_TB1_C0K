#include "file_reader.hpp"

FileReader::FileReader(string filename) : filename(filename) {}

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

bool FileReader::isValidName(){

    // check dua char pertama "./" bukan
    if ((filename.length() <= 2) || filename.substr(0, 2) != "./"){
        return false;
    } 

    // menghilangkan "./" dari filename
    this->filename = this->filename.erase(0, 2);

    bool haveSlash = false;
    bool haveFolderName = false;
    bool haveFileName = false;

    // cek apakah ada folder name dan file name
    for (int i = 0; i < filename.length(); i++) {
        if (filename[i] != '/' && !haveSlash && !haveFileName) {
            haveFolderName = true;
        } else if (filename[i] == '/' && haveFolderName && !haveSlash && !haveFileName) {
            haveSlash = true;
        } else if (filename[i] != '/' && haveFolderName && haveSlash && !haveFileName) {
            haveFileName = true;
        }
    }

    if (!haveFileName) {
        return false;
    }
    return true;
}