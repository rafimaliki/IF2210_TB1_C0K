#ifndef PLANT_HPP
#define PLANT_HPP

#include "../../../../std.hpp"
#include "../item.hpp"
#include "../../item_config/item_config.hpp"

class Plant : public Item
{
private:
    /* data */
public:
    PlantConfig& config;
    int Age;

    static vector<Plant*> plants;
    static int plantCount;

    Plant(int ID);
    // ~Plant();
    void print();

    static void AgeAllPlants();
};


#endif