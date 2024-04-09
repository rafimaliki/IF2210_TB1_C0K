#include "../../../std.hpp"

class NoPermissionException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Tidak memiliki akses ke command ";
    }
};