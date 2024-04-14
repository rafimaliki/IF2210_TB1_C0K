#ifndef STD_HPP
#define STD_HPP

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <exception>
#include <algorithm>
#include <fstream>
// #include <utility>
#include <cctype>
#include <limits>

using std::ifstream;
using std::ofstream;
using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::to_string;
using std::array;
using std::map;
using std::exception;
// using std::pair;

#include "class/util/util.hpp"

const string BOLD = "\x1b[1m";
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string MAGENTA = "\033[1;35m";
const string CYAN = "\033[1;36m";
const string RESET  = "\033[0m";
const string ERROR = RED + "Terjadi kesalahan lain" + RESET;

#endif
