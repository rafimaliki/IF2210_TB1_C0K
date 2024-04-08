#include "petani.hpp"

Petani::Petani(string name, int money, int body_weight) : Player(name, money, body_weight)
, lahan(GameConfig::miscConfig.getLadang_SIZE()[0], GameConfig::miscConfig.getLadang_SIZE()[1], "LADANG"){}

void Petani::printLahan(){
    this->lahan.print();
}

void Petani::addPlant(Plant* item){
    this->lahan.add(item);
}

Inventory<Plant>* Petani::getLadang(){
    return &this->lahan;
}

/* Game command related methods */

void Petani::CETAK_LADANG(){ /* BELUM DETAIL SESUAI SPEK */

    //Temp untuk menyimpan tanaman yang unik saja
    map<string,string> temp_tanaman_unik;


    this->lahan.print();

    //Cari ada tanaman apa saja di ladang
    for(int i = 0 ; i < this->lahan.height; i++){
        for(int j = 0 ; j < this->lahan.width; j++){
            if(this->lahan.grid[i][j].getItem() != nullptr){
                string nama_tanaman = this->lahan.grid[i][j].getItem()->getConfig()->getNAME();
                string kode_tanaman = this->lahan.grid[i][j].getItem()->getConfig()->getKODE_HURUF();
                if(temp_tanaman_unik.find(kode_tanaman) == temp_tanaman_unik.end()){
                    temp_tanaman_unik[kode_tanaman] = nama_tanaman;
                }
            }
        }
    }

    //Print tanaman yang unik
    for(auto it = temp_tanaman_unik.begin(); it != temp_tanaman_unik.end();it++){
            cout << it->first << " -> " << it->second << endl;
        }


    
    //Detail Seperti 
    // ALT -> Aloe Tree
    // BNT -> Banana Tree
    // CNT -> Coconut Tree
}
void Petani::TANAM(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand TANAM belum diimplementasikan!\n" << RESETstring << endl;
    
    //Pilih Tanaman Dari Inventory
        //Cek dulu ada tanaman atau engga di inventory
            //Throw Exception
    cout << "Pilih tanaman dari penyimpanan " << endl;

    //print inventory

    
    //Memilih Lokasi Dari Lahan
        //Cek dulu lahannya sudah penuh atau belum
            //Throw exception

    //Hilangin tanaman dari inventory

}
void Petani::PANEN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand PANEN belum diimplementasikan!\n" << RESETstring << endl;

    // Print Ladang
    // Validasi apakah ada tanaman yang sudah dapat di panen
        //Throw Exception
    //Tampilkan Jenis Tanaman Yang siap dipanen
        // Pilih tanaman siap panen yang kamu miliki 
        // 1. BNT (2 petak siap panen) 
        // 2. ALT (3 petak siap panen)
        // Nomor tanaman yang ingin dipanen: 2 // Lakukan validasi
            //Validasi string or something
            //valiasi apakah tanaman itu benar benar siap panen
        // Berapa petak yang ingin dipanen: 3 // Lakukan validasi
            //Validasi string or something
            //Validasi petak tersebut siap panen atau tidak

        //Jika lebih dari satu maka ada pilihan petak mana yang ingin dipanen
            //validasi lagi petak valid atau tidak

        //Validasi Inventory Cukup Atau Tidak


}