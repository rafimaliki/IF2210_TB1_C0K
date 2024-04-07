#include "plant.hpp"

vector<Plant*> Plant::plants;
int Plant::plantCount = 0;

Plant::Plant(int ID) : Item(), config(&GameConfig::plantConfig[ID-1]) {
    this->Age = 0;
    Plant::plants.push_back(this);
    Plant::plantCount++;
}

void Plant::print(){
    this->config->print();
    cout << "AGE: " << this->Age << endl;
}

void Plant::AgeAllPlants(){
    for (int i = 0; i < Plant::plantCount; i++){
        Plant::plants[i]->Age++;
    }
}

ItemConfig* Plant::getConfig(){
    return this->config;
}