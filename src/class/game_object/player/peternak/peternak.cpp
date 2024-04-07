#include "peternak.hpp"

Peternak::Peternak(string name, int money, int body_weight) : Player(name, money, body_weight)
, peternakan(GameConfig::miscConfig.getPETERNAKAN_SIZE()[0], GameConfig::miscConfig.getPETERNAKAN_SIZE()[1], "PETERNAKAN"){}

void Peternak::printPeternakan(){
    this->peternakan.print();
}

void Peternak::addAnimal(Item* item){
    peternakan.add(item);
}

/* Game command related methods */

void Peternak::CETAK_PETERNAKAN(){
    this->peternakan.print();
}
void Peternak::TERNAK(){
    cout << YELLOW << "\nCommand TERNAK belum diimplementasikan!\n" << RESETstring << endl;
}
void Peternak::KASIH_MAKAN(){
    cout << YELLOW << "\nCommand KASIH_MAKAN belum diimplementasikan!\n" << RESETstring << endl;
}
void Peternak::PANEN(){
    cout << YELLOW << "\nCommand PANEN belum diimplementasikan!\n" << RESETstring << endl;
}