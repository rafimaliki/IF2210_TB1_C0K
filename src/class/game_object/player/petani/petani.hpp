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

        /* Game command related methods */
        void CETAK_LADANG();
        void TANAM();
        void PANEN();
        void isLahanPenuh();
        void isPanenAvailable();
        void isInventoryMemadai(int n);
        void isiInventoryPenuh();
        void findHarvestablePlant(map<string,int>& harvestablePlant);
        void cetakSiapPanen(map<string,int>& harvestablePlant);

        string getType();

};

#endif
