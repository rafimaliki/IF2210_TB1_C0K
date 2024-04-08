#include "petani.hpp"

Petani::Petani(string name, int money, int body_weight) : Player(name, money, body_weight)
, lahan(GameConfig::miscConfig.getLAHAN_SIZE()[0], GameConfig::miscConfig.getLAHAN_SIZE()[1], "LADANG"){}

void Petani::printLahan(){
    this->lahan.print();
}

void Petani::addPlant(Plant* item){
    this->lahan.add(item);
}

Inventory<Plant>* Petani::getLahan(){
    return &this->lahan;
}

/* Game command related methods */

void Petani::CETAK_LADANG(){ /* BELUM DETAIL SESUAI SPEK */
    this->lahan.print();
}
void Petani::TANAM(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand TANAM belum diimplementasikan!\n" << RESETstring << endl;
}
void Petani::PANEN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand PANEN belum diimplementasikan!\n" << RESETstring << endl;
}