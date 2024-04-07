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

void Animal::printKODE_HURUF(){
    if (this->isReadyToHarvest()){
        cout << "\x1b[32m";
        cout << this->config->getKODE_HURUF();
        cout << "\x1b[0m";
    } else {
        cout << this->config->getKODE_HURUF();
    }
}

bool Animal::isReadyToHarvest(){
    return this->weight >= this->config->getWEIGHT_TO_HARVEST();
}   