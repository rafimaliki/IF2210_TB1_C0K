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
        bool isHerbivoreFoodReady();
        bool isCarnivoreFoodReady();
        string getType();
        void pilihKandangMakan(string slot_tanah,bool valid);
        bool cekKondisiHewan(string tipe,bool herbivore_food,bool carnivore_food);
        string checkAnimalFoodType(string animalType);
        bool checkFoodforAnimalBeforeLoop(string slot, string animal_type,string food_type);
        bool cekKondisiHewanSebelumLoop(string slot_tanah,bool herbivore_food,bool carnivore_food);
        string inputSlotTanahKasihMakan();
        string inputSlotInventoryKasihMakan(string animal_type,string food_type);
        string inputSlotTanahTernak();
        string inputSlotInventoryTernak();
        void isInventoryPeternakPenuh();
        void findAnimaltoHarvest(map<string, int> &temp_siap_panen);
        void printAnimaltoHarvest(map<string, int> temp_siap_panen);
        void chooseAnimalToHarvest(int &hewan_pilihan, int &banyak_petak, map<string, int> temp_siap_panen, Inventory<Animal> peternakan,string &input);
        void getKodeHewan(int hewan_pilihan, string &kode_hewan, map<string, int> temp_siap_panen,int &nPetak,int& count);
        void inputPetakPanen(string &input, int &banyak_petak, int nPetak, string kode_hewan);
        void panenHewan(int nPetak, int banyak_petak,string &petak_to_harvest,int ID,string *letak_panen,string kode_hewan);
        
};

#endif
