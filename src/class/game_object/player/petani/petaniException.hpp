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

class InventoryPenuhException : public exception {
public:
    const char* what() const noexcept override {
        return "Inventory Penuh ! Silahkan kosongkan terlebih dahulu";
    }
};

class InventoryTidakAdaTanamanException : public exception {
public:
    const char* what() const noexcept override {
        return "Inventory tidak ada tanaman";
    }
};

class bukanTanamanException : public exception {
public:
    const char* what() const noexcept override {
        return "Apa yang kamu lakukan?!! Kamu mencoba untuk menanam itu?!!";
    }
};

class ambilSlotKosongException : public exception {
public:
    const char* what() const noexcept override {
        return "Kamu mengambil harapan kosong dari penyimpanan.";
    }
};

class lahanSudahDitanamiException : public exception {
public:
    const char* what() const noexcept override {
        return "Lahan itu sudah ditanami";
    }
};
#endif