#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "../../../../std.hpp"
#include "../item.hpp"
#include "../../item_config/item_config.hpp"

class Animal : public Item
{
private:
    /* data */
public:
    ItemConfig* config;
    int weight;

    static vector<Animal*> animals;
    static int animalCount;

    Animal(int ID);
    // ~Animal();
    void print();
    ItemConfig* getConfig();

    // void Feed(ProductConfig product);
};


#endif