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

class pilihanTanamanException : public exception {
public:
    const char* what() const noexcept override {
        return "Pilihan tanaman tidak valid";
    }
};

class tanamanBelumTumbuhException : public exception {
public:
    const char* what() const noexcept override {
        return "Tanaman belum bisa dipanen";
    }
};

class bukanTanamanYangDiambilException : public exception {
public:
    const char* what() const noexcept override {
        return "Itu bukan tanaman yang akan kamu panen!!";
    }
};

class panenDiLahanKosongException : public exception {
public:
    const char* what() const noexcept override {
        return "Kamu mencoba untuk memanen lahan kosong";
    }
};

class terlaluBanyakPetakException : public exception {
public:
    const char* what() const noexcept override {
        return "Terlalu banyak petak";
    }
};

#endif