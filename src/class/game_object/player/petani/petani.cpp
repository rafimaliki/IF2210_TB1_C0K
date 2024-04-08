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

void Petani::CETAK_LADANG(){

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
void Petani::TANAM(){  
   
    
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




    //PRINT LADANG
    cout << endl;
    this->lahan.print();


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

    cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << tanaman->getConfig()->getNAME() << " berhasil ditanam!" << endl;

    //Hilangin tanaman dari inventory
    this->inventory.remove(slot);
}
void Petani::PANEN(){ 
    

    //TEMP MAP untuk menyimpan tanaman yang siap dipanen
    map<string,int> temp_siap_panen;

    //CEK INVENTORY
    if(this->inventory.isFull()){
        cout << RED << "Inventory Penuh ! Silahkan kosongkan terlebih dahulu" << RESETstring << endl;
        return;
    }


    this->CETAK_LADANG();



    try{
        this->isPanenAvailable();
    } catch (PanenTidakTersediaException& e){
        cout << RED << e.what() << RESETstring << endl;
        return;
    }

    //Cari tanaman yang siap dipanen
    for(int i = 0 ; i < this->lahan.height; i++){
        for(int j = 0 ; j < this->lahan.width; j++){
            if(this->lahan.grid[i][j].getItem() != nullptr){
                if(this->lahan.grid[i][j].getItem()->isReadyToHarvest()){
                    string kode_tanaman = this->lahan.grid[i][j].getItem()->getConfig()->getKODE_HURUF();
                    if(temp_siap_panen.find(kode_tanaman) == temp_siap_panen.end()){
                    temp_siap_panen[kode_tanaman] = 1;
                    }else{
                        temp_siap_panen[kode_tanaman]++;
                    }
                }
            }
        }
    }

    //Print tanaman yang siap dipanen
    cout << " Pilih tanaman siap panen yang kamu miliki " << endl;

    int i = 1;
    for(auto it = temp_siap_panen.begin(); it != temp_siap_panen.end();it++){
            cout << i << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            i++;
        }


    //Pilih Tanaman
    int pilihan_tanaman;
    int banyak_petak;

    bool valid = false;

    while(!valid){
        try{
            cout << "\nNomor tanaman yang ingin dipanen: ";
            cin >> pilihan_tanaman;
            
            while(pilihan_tanaman < 1 || pilihan_tanaman > temp_siap_panen.size()){
                cout << RED << "Pilihan tidak valid" << RESETstring << endl;
                cout << "Nomor tanaman yang ingin dipanen: ";
                cin >> pilihan_tanaman;
            }

            valid = true;
        }
        catch (...){
            cout << RED << "Input tidak valid" << RESETstring << endl;
        }
    }


    //Pilih Petak
    int count = 0;
    int nPetak;
    string kode_tanaman;

    for(auto it = temp_siap_panen.begin(); it != temp_siap_panen.end();it++){
        if(count == pilihan_tanaman - 1){
            nPetak = it->second;
            kode_tanaman = it->first;
            break;
        }
        count++;
    }


     //get id dari tanaman untuk mapping dari tanaman ke produk tanaman
    int ID = 0;

    valid = false;
    while(!valid){
        try{
            cout << "Berapa petak yang ingin dipanen: ";
            cin >> banyak_petak;

            while(banyak_petak < 1 || banyak_petak > nPetak){
                cout << RED << "Pilihan tidak valid" << RESETstring << endl;
                cout << "Berapa petak yang ingin dipanen: ";
                cin >> banyak_petak;
            }

            valid = true;
        }
        catch (...){
            cout << RED << "Input tidak valid" << RESETstring << endl;
        }
    }

    //hitung inventory apakah cukup atau tidak
    try{
        this->isInventoryMemadai(banyak_petak);
    } catch (InventoryTidakMemadaiException& e){
        cout << RED << e.what() << RESETstring << endl;
    }


    string petak_to_harvest;
    string letak_panen[nPetak];


    cout << "\nPilih petak yang ingin dipanen" << endl;
    for(int i  = 0 ; i < banyak_petak ; i++){
        valid = false;
        while(!valid){
            try{
                cout << "Petak ke-"  << i+1 << " : ";
                cin >> petak_to_harvest;

                while((this->lahan.isEmpty(petak_to_harvest)) || this->lahan.getItem(petak_to_harvest)->getConfig()->getKODE_HURUF() != kode_tanaman ||!this->lahan.getItem(petak_to_harvest)->isReadyToHarvest()){
                    cout << RED << "Petak tidak valid" << RESETstring << endl;
                    cout << "Petak ke-"  << i+1 << " : ";
                    cin >> petak_to_harvest;
                }


                //add item ke inventory
                ID = this->lahan.getItem(petak_to_harvest)->getConfig()->getID();
                Item *item = new Product(ID);

                this->addItem(item);

                this->getLadang()->remove(petak_to_harvest);


                //Simpan kordinat panen
                letak_panen[i] = petak_to_harvest;
                

                valid = true;
            }
            catch (...){
                cout << RED << "Input tidak valid" << RESETstring << endl;
            }
        }
    }
    

    cout << nPetak << " petak tanaman " << kode_tanaman << " pada petak ";
    for (int i = 0; i < nPetak-1; i++)
    {
        cout << letak_panen[i] << ", ";
    }
    cout << letak_panen[nPetak-1] << " telah dipanen!" << endl;
    
}

void Petani::isLahanPenuh(){
    if(this->lahan.calcEmptySpace() == 0){
        throw LahanPenuhException();
    }
}

void Petani::isPanenAvailable(){
    //Cek apakah ada tanaman yang bisa dipanen
    bool flag = false;
    for(int i = 0 ; i < this->lahan.height; i++){
        for(int j = 0 ; j < this->lahan.width; j++){
            if(this->lahan.grid[i][j].getItem() != nullptr){
                if(this->lahan.grid[i][j].getItem()->isReadyToHarvest()){
                    flag = true;
                    break;
                }
            }
        }
    }

    if(!flag){
        throw PanenTidakTersediaException();
    }
}


void Petani::isInventoryMemadai(int n){
    if(this->inventory.calcEmptySpace() < n){
        throw InventoryTidakMemadaiException();
    }
}

//Mapping tanaman ke produk tanaman
