#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "../player.hpp"

class Walikota : public Player {
    public:
        Walikota(string name, int money, int body_weight);

        // void pungut_pajak();
        // void bangun_bangunan();
        // void tambah_pemain();
        // void jual();
};

#endif