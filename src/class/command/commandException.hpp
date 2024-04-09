#include "../../std.hpp"

class InvalidCommandException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Command tidak valid!\n";
    }
};