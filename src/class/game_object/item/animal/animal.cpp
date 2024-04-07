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
        cout << GREEN << this->config->getKODE_HURUF() << RESETstring;
    } else {
         cout << RED << this->config->getKODE_HURUF() << RESETstring;
    }
}

bool Animal::isReadyToHarvest(){
    return this->weight >= this->config->getWEIGHT_TO_HARVEST();
}   