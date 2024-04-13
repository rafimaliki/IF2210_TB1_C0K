#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "../player.hpp"

class Peternak : public Player {

    private:
        Inventory<Animal> peternakan; 
    public:
        Peternak(string name, int money, int body_weight);

        void printPeternakan();
        void addAnimal(Animal* item);
        Inventory<Animal>* getPeternakan();
        int getWealth();

        /* Game command related methods */
        void CETAK_PETERNAKAN();
        void TERNAK();
        void KASIH_MAKAN();
        void PANEN();
        void isPeternakanPenuh();
        void isPeternakanKosong();
        void isFoodEmpty();
        void isAnimalEmpty();
        void isHarvestReady();
        void isInventoryMemadai(int n);
        void isAnimalFoodEmpty();
        bool isOnlyHerbivoreFood();
        bool isOnlyCarnivoreFood();
        string getType();
        void pilihKandangMakan(string slot_tanah,bool valid);
};

#endif
