#ifndef PETANI_EXCEPTION_HPP
#define PETANI_EXCEPTION_HPP

#include "../../../../std.hpp"

class LahanPenuhException : public exception {
public:
    const char* what() const noexcept override {
        return "Lahan sudah penuh";
    }
};

class PanenTidakTersediaException : public exception {
public:
    const char* what() const noexcept override {
        return "Tidak ada tanaman yang bisa dipanen";
    }
};

class InventoryTidakMemadaiException : public exception {
public:
    const char* what() const noexcept override {
        return "Inventory tidak memadai";
    }
};


#endif