#include "../../../std.hpp"

class NoPermissionException : public exception {
public:
    const char* what() const noexcept override {
        return "Tidak memiliki akses ke command ";
    }
};

class NotFoodException : public exception {
public:
    const char* what() const noexcept override {
        return "Apa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!!";
    }
};

class DontHaveFoodException : public exception {
public:
    const char* what() const noexcept override {
        return "Tidak ada makanan di penyimpanan\n";
    }
};
