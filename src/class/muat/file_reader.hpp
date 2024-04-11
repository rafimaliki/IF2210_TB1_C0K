#ifndef CONFIG_READER_HPP
#define CONFIG_READER_HPP

#include "../../std.hpp"
#include "file_readerException.hpp"

class FileReader {
private:
    string filename;
public:
    FileReader(const string& filename);
    vector<vector<string>> readConfig();
};

#endif