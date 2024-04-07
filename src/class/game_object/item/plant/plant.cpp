#include "plant.hpp"

vector<Plant*> Plant::plants;
int Plant::plantCount = 0;

Plant::Plant(int ID) : Item(), config(&GameConfig::plantConfig[ID-1]) {
    this->Age = 0;
    this->isPlanted = false;
    Plant::plants.push_back(this);
    Plant::plantCount++;
}

void Plant::print(){
    this->config->print();
    cout << "AGE: " << this->Age << endl;
    cout << "IS PLANTED: " << this->isPlanted << endl;
}

void Plant::AgeAllPlants(){
    cout << "\033[1;33mAll plants have aged by one day\n\033[0m\n";
    for (int i = 0; i < Plant::plantCount; i++){
        if (Plant::plants[i]->isPlanted){
            Plant::plants[i]->Age++;
        }
    }
}

void Plant::setPlanted(bool isPlanted){
    // cout << "Plant is planted: " << isPlanted << endl;
    this->isPlanted = isPlanted;
}

ItemConfig* Plant::getConfig(){
    return this->config;
}

void Plant::printKODE_HURUF(){
    if (this->isPlanted)
    {
        if (this->isReadyToHarvest()){
            cout << GREEN << this->config->getKODE_HURUF() << RESETstring;
        } else {
            cout << RED << this->config->getKODE_HURUF() << RESETstring;
        }
    } else {
        cout << this->config->getKODE_HURUF();
    }
}

bool Plant::isReadyToHarvest(){
    return this->Age >= this->config->getDURATION_TO_HARVEST();
}