#include "petani.hpp"

Petani::Petani(string name, int money, int body_weight) : Player(name, money, body_weight)
, lahan(GameConfig::miscConfig.getLAHAN_SIZE()[0], GameConfig::miscConfig.getLAHAN_SIZE()[1], "LAHAN"){}

void Petani::printLahan(){
    this->lahan.print();
}

void Petani::addPlant(Item* item){
    this->lahan.add(item);
}