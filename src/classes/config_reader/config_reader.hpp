#include "../../std.hpp"
#include <fstream>

class ConfigReader {
public:
    ConfigReader(const std::string& filename) : filename(filename) {}

    std::vector<std::string> readLines() {


        // Convert the path to a string and print it
        // std::cout << "Current working directory: " << std::filesystem::current_path().string() << std::endl;

        std::vector<std::string> lines;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return lines; // Return empty vector if file cannot be opened
        }

        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        file.close();
        return lines;
    }

private:
    std::string filename;
};
