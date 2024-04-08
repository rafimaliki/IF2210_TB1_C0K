#include "../../../../std.hpp"

class IndexNotValidException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Index not valid";
    }
};

class InventorySizeNotValidException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Inventory size not valid";
    }
};