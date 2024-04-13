#ifndef CONFIG_READER_HPP
#define CONFIG_READER_HPP

#include "../../std.hpp"
#include "file_readerException.hpp"

class FileReader {
protected:
    string filename;
public:
    // constructor
    FileReader(string filename);

    // method
    vector<vector<string>> readFile();
    bool isValidName();
};

#endif