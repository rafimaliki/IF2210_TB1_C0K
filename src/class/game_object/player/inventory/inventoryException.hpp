#include "../../../../std.hpp"

class IndexNotValidException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Index not valid";
    }
};