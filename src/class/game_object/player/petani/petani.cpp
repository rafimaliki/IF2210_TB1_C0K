#include "petani.hpp"

Petani::Petani(string name, int money, int body_weight) : Player(name, money, body_weight)
, lahan(GameConfig::miscConfig.getLADANG_SIZE()[0], GameConfig::miscConfig.getLADANG_SIZE()[1], "LADANG"){}

void Petani::printLahan(){
    this->lahan.print();
}

void Petani::addPlant(Plant* item){
    this->lahan.add(item);
}

Inventory<Plant>* Petani::getLadang(){
    return &this->lahan;
}

int Petani::getWealth(){
    int totalWealth = Player::getWealth();
    for (int i = 0; i < lahan.getHeight(); i++){
        for (int j = 0; j < lahan.getWidth(); j++){
            if (!lahan.isEmpty(i, j)){
                totalWealth += lahan.getItem(i, j)->getPRICE();
            }
        }
    }

    return totalWealth;
}

/* Game command related methods */

void Petani::CETAK_LADANG(){

    //Temp untuk menyimpan tanaman yang unik saja
    map<string,string> temp_tanaman_unik;


    this->lahan.print();

    //Cari ada tanaman apa saja di ladang
    for(int i = 0 ; i < this->lahan.getHeight(); i++){
        for(int j = 0 ; j < this->lahan.getWidth(); j++){
            if(!this->lahan.isEmpty(i,j)){
                string nama_tanaman = this->lahan.getItem(i, j)->getNAME();
                string kode_tanaman = this->lahan.getItem(i, j)->getKODE_HURUF();
                if(temp_tanaman_unik.find(kode_tanaman) == temp_tanaman_unik.end()){
                    temp_tanaman_unik[kode_tanaman] = nama_tanaman;
                }
            }
        }
    }

    //Print tanaman yang unik
    for(auto it = temp_tanaman_unik.begin(); it != temp_tanaman_unik.end();it++){
            cout << "- " << it->first << ": " << it->second << endl;
        }
}
void Petani::TANAM(){  
   
    
    //Cek Apakah Lahan sudah Penuh
    try{
        this->isLahanPenuh();
    } catch (LahanPenuhException& e){
        cout << RED << e.what() << RESET << endl;
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
        } catch (InvalidIndexException& e){
            cout << RED << e.what() << RESET << endl << endl; ;
        }
    }


    //get ID from slot
    int ID = this->inventory.getItem(slot)->getConfig()->getID();

    cout << "\nKamu memilih " << this->inventory.getItem(slot)->getConfig()->getNAME() << endl;




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
        } catch (InvalidIndexException& e){
            cout << RED << e.what() << RESET << endl << endl; ;
        }
    }

    //Tanam Tanamannya
    Plant *tanaman = new Plant(ID);
    tanaman->setPlanted(true);

    this->lahan.add(tanaman,slot_tanah);

    cout << "\nCangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << tanaman->getConfig()->getNAME() << " berhasil ditanam!" << endl;

    //Hilangin tanaman dari inventory
    this->inventory.remove(slot);
}
void Petani::PANEN(){ 
    

    //TEMP MAP untuk menyimpan tanaman yang siap dipanen
    map<string,int> temp_siap_panen;

 
    try{
        this->isiInventoryPenuh();
        this->CETAK_LADANG();
        this->isPanenAvailable();
    } catch (InventoryPenuhException& e){
        cout << RED << e.what() << RESET << endl;
        return;
    } catch (PanenTidakTersediaException& e){
        cout << RED << e.what() << RESET << endl;
        return;
    }



    //Cari tanaman yang siap dipanen
    this->findHarvestablePlant(temp_siap_panen);

    //Print tanaman yang siap dipanen
    cout << " Pilih tanaman siap panen yang kamu miliki " << endl;

    cetakSiapPanen(temp_siap_panen);


    //Pilih Tanaman
    int pilihan_tanaman;
    int banyak_petak;
    string input;
    bool valid = false;


    


    while(!valid){
     
        cout << "\nNomor tanaman yang ingin dipanen: ";
        cin >> input;

        // Mengonversi input menjadi integer
        pilihan_tanaman = Util::stringToInt(input);

        if (pilihan_tanaman < 1 || pilihan_tanaman > temp_siap_panen.size()) {
            cout << RED << "Pilihan tidak valid" << RESET << endl;
            valid = false;
        } else {
            valid = true;
        }

        
        //Membersihkan input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        cout << "\nBerapa petak yang ingin dipanen: ";
        cin >> input;

        // Mengonversi input menjadi integer
        banyak_petak = Util::stringToInt(input);

        

        if (banyak_petak < 1 || banyak_petak > nPetak) {
            cout << RED << "Pilihan tidak valid" << RESET << endl;
            valid = false;
        } else {
            valid = true;
        }

     

        //Membersihkan input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

  

    //hitung inventory apakah cukup atau tidak
    try{
        this->isInventoryMemadai(banyak_petak);
    } catch (InventoryTidakMemadaiException& e){
        cout << RED << e.what() << RESET << endl;
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
                    cout << RED << "Petak tidak valid" << RESET << endl;
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
                cout << RED << "Input tidak valid" << RESET << endl;
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

string Petani::getType(){
    return "Petani";
}

void Petani::isLahanPenuh(){
    if(this->lahan.calcEmptySpace() == 0){
        throw LahanPenuhException();
    }
}

void Petani::isPanenAvailable(){
    //Cek apakah ada tanaman yang bisa dipanen
    bool flag = false;
    for(int i = 0 ; i < this->lahan.getHeight(); i++){
        for(int j = 0 ; j < this->lahan.getWidth(); j++){
            if(!this->lahan.isEmpty(i,j)){
                if(this->lahan.getItem(i, j)->isReadyToHarvest()){
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

void Petani::isiInventoryPenuh(){
    if(this->inventory.isFull()){
        throw InventoryPenuhException();
    }
}

void Petani::findHarvestablePlant(map<string,int>& harvestablePlant){
    //Cari tanaman yang siap dipanen
    for(int i = 0 ; i < this->lahan.getHeight(); i++){
        for(int j = 0 ; j < this->lahan.getWidth(); j++){
            if(!this->lahan.isEmpty(i,j)){
                if(this->lahan.getItem(i, j)->isReadyToHarvest()){
                    string kode_tanaman = this->lahan.getItem(i, j)->getKODE_HURUF();
                    if(harvestablePlant.find(kode_tanaman) == harvestablePlant.end()){
                        harvestablePlant[kode_tanaman] = 1;
                    }else{
                        harvestablePlant[kode_tanaman]++;
                    }
                }
            }
        }
    }
}

void Petani::cetakSiapPanen(map<string,int>& harvestablePlant){
    int i = 1;
    for(auto it = harvestablePlant.begin(); it != harvestablePlant.end();it++){
            cout << i << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
            i++;
        }
}