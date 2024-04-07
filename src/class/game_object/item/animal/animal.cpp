#include "animal.hpp"

vector<Animal*> Animal::animals;
int Animal::animalCount = 0;

Animal::Animal(int ID) : Item(), config(&GameConfig::animalConfig[ID-1]) {
    this->weight = 0;
    Animal::animals.push_back(this);
    Animal::animalCount++;
}

void Animal::print(){
    this->config->print();
    cout << "WEIGHT: " << this->weight << endl;
}

ItemConfig* Animal::getConfig(){
    return this->config;
}