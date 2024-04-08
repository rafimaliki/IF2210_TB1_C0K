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

string Item::getTYPE(){
    return "";
}

int Item::getADDED_WEIGHT(){
    return 0;
}

bool Item::isFood(){
    return (this->getTYPE() == "PRODUCT_FRUIT_PLANT" || this->getTYPE() == "PRODUCT_ANIMAL");
}

bool Item::isPlant(){
    cout << "TYPE: " << this->getTYPE() << endl;
    return (this->getTYPE() == "MATERIAL_PLANT" || this->getTYPE() == "FRUIT_PLANT");
}