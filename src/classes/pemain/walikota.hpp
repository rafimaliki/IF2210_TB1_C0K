#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "pemain.hpp"

class Walikota : public Pemain {
    public:
        void pungut_pajak();

        void bangun_bangunan();

        void tambah_pemain();

        void jual();
};

#endif