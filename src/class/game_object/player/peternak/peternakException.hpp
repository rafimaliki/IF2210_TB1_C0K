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

class InventoryNoFoodException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Inventory tidak memiliki makanan";
    }
};

class InventoryNoAnimalException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Inventory tidak memiliki hewan";
    }
};


// peternakan cuma punya hewan herbivora sedangkan makanan yang ada adalah makanan karnivora
class JustHaveHerbivoreAnimalDontHaveFood : public std::exception {
public:
    const char* what() const noexcept override {
        return "Inventory hanya memiliki hewan herbivora sedangkan makanan yang ada adalah makanan karnivora";
    }
};

// peternakan cuma punya hewan karnivora sedangkan makanan yang ada adalah makanan herbivora
class JustHaveCarnivoreAnimalDontHaveFood : public std::exception {
public:
    const char* what() const noexcept override {
        return "Inventory hanya memiliki hewan karnivora sedangkan makanan yang ada adalah makanan herbivora";
    }
};