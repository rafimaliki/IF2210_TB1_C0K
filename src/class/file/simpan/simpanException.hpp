#include "../../../std.hpp"

class InvalidFileException : public exception {
    public:
        const char* what() const noexcept override {
            return "Invalid File Name\n";
        }
};