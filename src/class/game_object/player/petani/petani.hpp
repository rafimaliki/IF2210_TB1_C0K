#ifndef PETANI_HPP
#define PETANI_HPP

#include "../player.hpp"
#include "petaniException.hpp"



class Petani : public Player {

    private:
        Inventory<Plant> lahan;
    public:
        Petani(string name, int money, int body_weight);
        void printLahan();
        void addPlant(Plant* item);
        Inventory<Plant>* getLadang();
        int getWealth();

        // void pungut_pajak();
        // void bangun_bangunan();
        // void tambah_pemain();
        // void jual();
        /* Game command related methods */
        void CETAK_LADANG();
        void TANAM();
        void PANEN();
        void isLahanPenuh();
        void isPanenAvailable();
        void isInventoryMemadai(int n);
        

        string getType();
        // void MUAT();
};

#endif
