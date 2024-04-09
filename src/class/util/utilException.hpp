#include "../../std.hpp"

class InvalidIndexException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid Index!\n";
    }
};