#include "../../std.hpp"

class FailReadFileException : public exception {
    public:
        const char* what() const noexcept override {
            return "Lokasi berkas tidak valid\n";
        }
};