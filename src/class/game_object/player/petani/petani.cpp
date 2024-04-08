#include "petani.hpp"
#include "petaniException.hpp"

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
    // cout << YELLOW << "\nCommand TANAM belum diimplementasikan!\n" << RESETstring << endl;
    
    //Cek Apakah Lahan sudah Penuh
    try{
        this->isLahanPenuh();
    } catch (LahanPenuhException& e){
        cout << RED << e.what() << RESETstring << endl;
    }
    

    cout << "Pilih tanaman dari penyimpanan " << endl;


    //Print Inventory
    this->inventory.print();

    string slot;
    bool valid = false;

    while (!valid){
        try {

            cout << "Slot: ";
            cin >> slot;

            while (this->inventory.isEmpty(slot) || !this->inventory.getItem(slot)->isPlant()){
                if (this->inventory.isEmpty(slot)){
                    cout << "\nKamu mengambil harapan kosong dari penyimpanan." << endl;
                } else {
                    cout << "\nApa yang kamu lakukan?!! Kamu mencoba untuk menanam itu?!!" << endl;
                }
                cout << "Silahkan masukan slot yang berisi tanaman." << endl;

                cout << "\nSlot: ";
                cin >> slot;
            }
            valid = true;
        } catch (IndexNotValidException& e){
            cout << RED << e.what() << RESETstring << endl << endl; ;
        }
    }


    //get ID from slot
    int ID = this->inventory.getItem(slot)->getConfig()->getID();



    //Pilih lokasi tanam
    string slot_tanah;
    valid = false;

    while (!valid){
        try {

            cout << "Petak tanah: ";
            cin >> slot_tanah;

            while (!this->lahan.isEmpty(slot_tanah)){
                cout << "\n Lahan itu sudah ditanami ! ." << endl;
                
                cout << "Silahkan masukan petak tanah yang masih kosong." << endl;

                cout << "\nPetak tanah: ";
                cin >> slot_tanah;
            }
            valid = true;
        } catch (IndexNotValidException& e){
            cout << RED << e.what() << RESETstring << endl << endl; ;
        }
    }

    //Tanam Tanamannya
    Plant *tanaman = new Plant(ID);
    tanaman->setPlanted(true);

    this->lahan.add(tanaman,slot_tanah);


    //Hilangin tanaman dari inventory
    this->inventory.remove(slot);
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

void Petani::isLahanPenuh(){
    if(this->lahan.calcEmptySpace() == 0){
        throw LahanPenuhException();
    }
}