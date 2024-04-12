#include "util.hpp"

void Util::clearScreen()
{
    cout << "\033[2J\033[1;1H";
}

void Util::printTitle()
{

    Util::clearScreen();
    cout << "\n                                                                                                      \n"
            " ██░ ██  ▄▄▄       ██▀███   ██▒   █▓▓█████   ██████ ▄▄▄█████▓    ███▄ ▄███▓ ▒█████   ▒█████   ███▄    █ \n"
            "▓██░ ██▒▒████▄    ▓██ ▒ ██▒▓██░   █▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒   ▓██▒▀█▀ ██▒▒██▒  ██▒▒██▒  ██▒ ██ ▀█   █ \n"
            "▒██▀▀██░▒██  ▀█▄  ▓██ ░▄█ ▒ ▓██  █▒░▒███   ░ ▓██▄   ▒ ▓██░ ▒░   ▓██    ▓██░▒██░  ██▒▒██░  ██▒▓██  ▀█ ██▒\n"
            "░▓█ ░██ ░██▄▄▄▄██ ▒██▀▀█▄    ▒██ █░░▒▓█  ▄   ▒   ██▒░ ▓██▓ ░    ▒██    ▒██ ▒██   ██░▒██   ██░▓██▒  ▐▌██▒\n"
            "░▓█▒░██▓ ▓█   ▓██▒░██▓ ▒██▒   ▒▀█░  ░▒████▒▒██████▒▒  ▒██▒ ░    ▒██▒   ░██▒░ ████▓▒░░ ████▓▒░▒██░   ▓██░\n"
            " ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒▓ ░▒▓░   ░ ▐░  ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░      ░ ▒░   ░  ░░ ▒░▒░▒░ ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ \n"
            " ▒ ░▒░ ░  ▒   ▒▒ ░  ░▒ ░ ▒░   ░ ░░   ░ ░  ░░ ░▒  ░ ░    ░       ░  ░      ░  ░ ▒ ▒░   ░ ▒ ▒░ ░ ░░   ░ ▒░\n"
            " ░  ░░ ░  ░   ▒     ░░   ░      ░░     ░   ░  ░  ░    ░         ░      ░   ░ ░ ░ ▒  ░ ░ ░ ▒     ░   ░ ░ \n"
            " ░  ░  ░      ░  ░   ░           ░     ░  ░      ░                     ░       ░ ░      ░ ░           ░ \n"
            "                                ░                                                                       \n" << endl;
}

vector<string> Util::split(string str, char delimiter)
{

    vector<string> splitted;
    string temp = "";

    int strLen = str.length();

    for (int i = 0; i < strLen; i++)
    {
        if (str[i] == delimiter && temp != "")
        {
            splitted.push_back(temp);
            temp = "";
        }
        else if (str[i] != delimiter)
        {
            temp += str[i];
        }
    }

    if (temp != "")
    {
        splitted.push_back(temp);
    }

    return splitted;
}
vector<string> Util::inputMultiplePetak(const string &str)
{
    std::vector<std::string> results;

    auto parts = split(str, ',');
    for (const auto &part : parts)
    {

        std::string cleanPart;
        for (char ch : part)
        {
            if (ch != ' ')
            {
                cleanPart += ch;
            }
        }
        results.push_back(cleanPart);
    }

    return results;
}
bool Util::isNumber(char c)
{
    return (c >= '0' && c <= '9');
}

bool Util::isLetterLower(char c)
{
    return (c >= 'a' && c <= 'z');
}

bool Util::isLetterUpper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

vector<int> Util::idxToInt(string idx)
{

    int strLen = idx.length();
    if (strLen < 3)
    {
        throw InvalidIndexException();
    }

    if (!isLetterUpper(idx[0]) || !isNumber(idx[1]))
    {
        throw InvalidIndexException();
    }

    char letter = idx[0];
    string number = "";

    for (int i = 1; i < strLen; i++)
    {
        if (isNumber(idx[i]))
        {
            number += idx[i];
        }
        else
        {
            throw InvalidIndexException();
        }
    }

    vector<int> result;

    try
    {
        result.push_back(stoi(number) - 1);
        result.push_back(letter - 'A');
    }
    catch (...)
    {
        throw InvalidIndexException();
    }

    return result;
}

string Util::IntToIdx(vector<int> idx)
{
    string result = "";

    result += (char)(idx[0] + 'A');
    if (idx[1] <= 8){
        result += "0";
    }
    result += to_string(idx[1] + 1);

    return result;
}

int Util::stringToInt(string num)
{
    try
    {
        return stoi(num);
    }
    catch (...)
    {
        throw NotNumberException();
    }
}
