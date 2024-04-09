#include "peternak.hpp"
#include "peternakException.hpp"

Peternak::Peternak(string name, int money, int body_weight) : Player(name, money, body_weight)
, peternakan(GameConfig::miscConfig.getPETERNAKAN_SIZE()[0], GameConfig::miscConfig.getPETERNAKAN_SIZE()[1], "PETERNAKAN"){}

void Peternak::printPeternakan(){
    this->peternakan.print();
}

void Peternak::addAnimal(Animal* item){
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
                char kode = 1 + i + 'A';
                cout << "- " << kode;
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
void Peternak::TERNAK(){ 
    try{
        this->isPeternakanPenuh();
    } catch (PeternakanPenuhException& e){
        cout << RED << e.what() << RESET <<endl;
        return;
    }

    cout << "Pilih hewan dari penyimpanan" << endl << endl;

    this->inventory.print();
    string slot;
    bool valid = false;

    while (!valid){
        try {

            cout << "Slot: ";
            cin >> slot;

            while (this->inventory.isEmpty(slot) || !this->inventory.getItem(slot)->isAnimal()){
                if (this->inventory.isEmpty(slot)){
                    cout << "\nKamu mengambil harapan kosong dari penyimpanan." << endl;
                } else {
                    cout << "\nApa yang kamu lakukan?!! Kamu mencoba untuk beternak itu?!!" << endl;
                }
                cout << "Silahkan masukan slot yang berisi hewan." << endl;

                cout << "\nSlot: ";
                cin >> slot;
            }
            valid = true;
        } catch (IndexNotValidException& e){
            cout << RED << e.what() << RESET << endl << endl; ;
        }
    }

    //get ID from slot
    int ID = this->inventory.getItem(slot)->getConfig()->getID();

    //Pilih lokasi ternak
    string slot_tanah;
    valid = false;


    cout << endl;

    CETAK_PETERNAKAN();
    while (!valid){
        try {

            cout << "Petak tanah: ";
            cin >> slot_tanah;

            while (!this->peternakan.isEmpty(slot_tanah)){
                cout << "\n Petak itu sudah ada hewannya" << endl;
                
                cout << "Silahkan masukan petak tanah yang masih kosong." << endl;

                cout << "\nPetak tanah: ";
                cin >> slot_tanah;
            }
            valid = true;
        } catch (IndexNotValidException& e){
            cout << RED << e.what() << RESET << endl << endl; ;
        }
    }

    //Add animal to peternakan
    Animal* animal = new Animal(ID);
    this->peternakan.add(animal, slot_tanah);

    // hilangin animal dari inventory
    this->inventory.remove(slot);


    cout << "Hewan berhasil diternakkan!" << endl;
    CETAK_PETERNAKAN();
}
void Peternak::KASIH_MAKAN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand KASIH_MAKAN belum diimplementasikan!\n" << RESET << endl;
}
void Peternak::PANEN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand PANEN belum diimplementasikan!\n" << RESET << endl;
}

string Peternak::getType(){
    return "Peternak";
}

void Peternak::isPeternakanPenuh(){
    if (this->peternakan.isFull()){
        throw PeternakanPenuhException();
    }
}