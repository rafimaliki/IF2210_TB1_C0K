#include "peternak.hpp"

Peternak::Peternak(string name, int money, int body_weight) : Player(name, money, body_weight)
, peternakan(GameConfig::miscConfig.getPETERNAKAN_SIZE()[0], GameConfig::miscConfig.getPETERNAKAN_SIZE()[1], "PETERNAKAN"){}

void Peternak::printPeternakan(){
    this->peternakan.print();
}

void Peternak::addAnimal(Item* item){
    peternakan.add(item);
}