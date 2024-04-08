#include "item.hpp"

Item::Item(){
    // cout << "\x1b[32mAn Object IS CREATED!\x1b[0m" << endl;
}

void Item::print(){}

Item::~Item(){}

void Item::setPlanted(bool isPlanted){}
void Item::setIsInCage(bool isInCage){}
void Item::printKODE_HURUF(){}
bool Item::isReadyToHarvest(){
    return false;
}

bool Item::isFood(){
    return (this->getTYPE() == "PRODUCT_FRUIT_PLANT" || this->getTYPE() == "PRODUCT_ANIMAL");
}

bool Item::isPlant(){
    cout << "TYPE: " << this->getTYPE() << endl;
    return (this->getTYPE() == "MATERIAL_PLANT" || this->getTYPE() == "FRUIT_PLANT");
}

bool Item::isAnimal(){
    return (this->getTYPE() == "CARNIVORE" || this->getTYPE() == "HERBIVORE");
}

/* GETTER */
int Item::getID(){
    return this->getConfig()->getID();
}
string Item::getKODE_HURUF(){
    return this->getConfig()->getKODE_HURUF();
}
string Item::getNAME(){
    return this->getConfig()->getNAME();
}
int Item::getPRICE(){
    return this->getConfig()->getPRICE();
}
string Item::getTYPE(){
    return this->getConfig()->getTYPE();
}
int Item::getDURATION_TO_HARVEST(){
    return this->getConfig()->getDURATION_TO_HARVEST();
}
int Item::getWEIGHT_TO_HARVEST(){
    return this->getConfig()->getWEIGHT_TO_HARVEST();
}
string Item::getORIGIN(){
    return this->getConfig()->getORIGIN();
}
int Item::getADDED_WEIGHT(){
    return this->getConfig()->getADDED_WEIGHT();
}