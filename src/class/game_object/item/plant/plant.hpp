#ifndef PLANT_HPP
#define PLANT_HPP

#include "../../../../std.hpp"
#include "../item.hpp"
#include "../../item_config/item_config.hpp"

class Plant : public Item
{
private:
    /* data */
    ItemConfig* config;
    int Age;
    bool isPlanted;
public:

    static vector<Plant*> plants;
    static int plantCount;

    Plant(int ID);
    // ~Plant();
    void print();
    ItemConfig* getConfig();
    void setPlanted(bool isPlanted);
    void printKODE_HURUF();
    bool isReadyToHarvest();
    string getTYPE();

    static void AgeAllPlants();

};


#endif