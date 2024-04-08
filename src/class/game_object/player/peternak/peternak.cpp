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

void Peternak::CETAK_PETERNAKAN(){  /* BELUM DETAIL SESUAI SPEK */
    this->peternakan.print();
    cout << endl;
    int height = this->peternakan.height;
    int width = this->peternakan.width;
    for (int i = 0 ;i < height; i++){
        for (int j = 0; j < width; j++){
            if (!this->peternakan.isEmpty(i, j)){
                cout << "- " << i + "A";
                if (j < 10){
                    cout << "0" << j <<": ";
                    cout << this->peternakan.getItem(i, j)->getKODE_HURUF();
                }else{
                    cout << j <<": ";
                    cout << this->peternakan.getItem(i, j)->getKODE_HURUF();
                }
                cout << endl <<endl;
            }
        }
    }


}
void Peternak::TERNAK(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand TERNAK belum diimplementasikan!\n" << RESETstring << endl;
}
void Peternak::KASIH_MAKAN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand KASIH_MAKAN belum diimplementasikan!\n" << RESETstring << endl;
}
void Peternak::PANEN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand PANEN belum diimplementasikan!\n" << RESETstring << endl;
}