#include "../../../../std.hpp"

class LahanPenuhException : public exception {
public:
    const char* what() const noexcept override {
        return "Lahan sudah penuh";
    }
};