#ifndef CONFIG_READER_HPP
#define CONFIG_READER_HPP

#include "../../std.hpp"
#include "config_readerException.hpp"

#include <fstream>

using std::ifstream;
using std::getline;

class ConfigReader {
private:
    string filename;
public:
    ConfigReader(const string& filename);
    vector<vector<string>> readConfig();
};

#endif