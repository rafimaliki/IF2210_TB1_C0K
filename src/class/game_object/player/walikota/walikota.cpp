#include "walikota.hpp"

Walikota::Walikota(string name, int money, int body_weight) : Player(name, money, body_weight){}

/* Game command related methods */

void Walikota::PUNGUT_PAJAK(){
    cout << YELLOW << "\nCommand PUNGUT_PAJAK belum diimplementasikan!!\n" << RESETstring << endl;
}

void Walikota::BANGUN(){
    cout << YELLOW << "\nCommand BANGUN belum diimplementasikan!\n" << RESETstring << endl;
}

void Walikota::TAMBAH_PEMAIN(){
    cout << YELLOW << "\nCommand TAMBAH_PEMAIN belum diimplementasikan!\n" << RESETstring << endl;
}