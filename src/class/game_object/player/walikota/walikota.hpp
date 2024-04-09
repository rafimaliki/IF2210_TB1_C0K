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

        /* Game command related methods */
        void PUNGUT_PAJAK();
        void BANGUN();
        // void MUAT();
        void TAMBAH_PEMAIN();
        int HITUNG_PAJAK(int idx);

        string getType();
};

#endif