#include "../../../../std.hpp"

// class IndexNotValidException : public exception {
// public:
//     const char* what() const noexcept override {
//         return "Index not valid";
//     }
// };

class PeternakanPenuhException : public exception {
public:
    const char* what() const noexcept override {
        return "Peternakan penuh";
    }
};

class PeternakanKosongException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Peternakan kosong";
    }
};