#ifndef UTIL_HPP
#define UTIL_HPP

#include "../../std.hpp"
#include "utilException.hpp"

class Util {
    public:
        static void clearScreen();
        static void printTitle();

        static vector<string> split(string str, char delimiter = ' ');

        static bool isNumber(char c);
        static bool isLetterLower(char c);
        static bool isLetterUpper(char c);

        // A01 -> {0, 0}
        static vector<int> idxToInt(string idx);
};

#endif