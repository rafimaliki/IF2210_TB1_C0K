#include "item.hpp"

Item::Item(){}
Item::~Item(){}

void Item::print(){}

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

pair<string, int> Item::getTYPE_IDbyNAME(string name){

    pair<string, int> result;

    for (int i = 0; i < GameConfig::plantConfig.size(); i++){
        if (name == GameConfig::plantConfig[i].getNAME()){
            result = {"Plant", GameConfig::plantConfig[i].getID()};
            return result;
        }
    }

    for (int i = 0; i < GameConfig::animalConfig.size(); i++){
        if (name == GameConfig::animalConfig[i].getNAME()){
            result = {"Animal", GameConfig::animalConfig[i].getID()};
            return result;
        }
    }

    for (int i = 0; i < GameConfig::productConfig.size(); i++){
        if (name == GameConfig::productConfig[i].getNAME()){
            result = {"Product", GameConfig::productConfig[i].getID()};
            return result;
        }
    }

    for (int i = 0; i < GameConfig::recipeConfig.size(); i++){
        if (name == GameConfig::recipeConfig[i].getNAME()){
            result = {"Bangunan", GameConfig::recipeConfig[i].getID()};
            return result;
        }
    }

    // throw InvalidTypeException();
    return result;
}