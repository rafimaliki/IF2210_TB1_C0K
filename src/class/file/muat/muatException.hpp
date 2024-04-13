#include "../../../std.hpp"

class InvalidDataException : public exception {
    public:
        const char* what() const noexcept override {
            return "Data muat tidak valid!\n";
        }
};