#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "../../../../std.hpp"
#include "../item.hpp"
#include "../../item_config/item_config.hpp"

class Animal : public Item
{
private:
    /* data */
    ItemConfig* config;
    int weight;
    bool isInCage;
public:

    static vector<Animal*> animals;
    static int animalCount;

    Animal(int ID);
    Animal(int ID, int weight);
    // ~Animal();
    void print();
    ItemConfig* getConfig();
    void printKODE_HURUF();
    bool isReadyToHarvest();
    void setIsInCage(bool isInCage);

    void Feed(Item* product);
    int getWeight();
    void setWeight(int weight);
};


#endif