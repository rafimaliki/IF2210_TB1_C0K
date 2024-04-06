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
    vector<string> split(const string &s);
public:
    ConfigReader(const string& filename);
    vector<vector<string>> readConfig();
};

#endif