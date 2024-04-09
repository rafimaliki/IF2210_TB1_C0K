#include "../../std.hpp"

class InvalidIndexException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Index!";
    }
};