#include "peternak.hpp"
#include "peternakException.hpp"
#include <cctype>
#include <limits>

Peternak::Peternak(string name, int money, int body_weight) : Player(name, money, body_weight)
, peternakan(GameConfig::miscConfig.getPETERNAKAN_SIZE()[0], GameConfig::miscConfig.getPETERNAKAN_SIZE()[1], "PETERNAKAN"){}

void Peternak::printPeternakan(){
    this->peternakan.print();
}

void Peternak::addAnimal(Animal* item){
    peternakan.add(item);
}

Inventory<Animal>* Peternak::getPeternakan(){
    return &this->peternakan;
}

int Peternak::getWealth(){
    int totalWealth = Player::getWealth();
    for (int i = 0; i < peternakan.getHeight(); i++){
        for (int j = 0; j < peternakan.getWidth(); j++){
            if (!peternakan.isEmpty(i, j)){
                totalWealth += peternakan.getItem(i, j)->getPRICE();
            }
        }
    }

    return totalWealth;
}

/* Game command related methods */

void Peternak::CETAK_PETERNAKAN(){  
    this->peternakan.print();
    cout << endl;
    int height = this->peternakan.getHeight();
    int width = this->peternakan.getWidth();
    for (int i = 0 ;i < height; i++){
        for (int j = 0; j < width; j++){
            if (!this->peternakan.isEmpty(i, j)){
                char kode = j + 'A';
                cout << "- " << kode;
                if (j < 10){
                    cout << "0" << i + 1 <<": ";
                    cout << this->peternakan.getItem(i, j)->getKODE_HURUF();
                }else{
                    cout << j + 1 <<": ";
                    cout << this->peternakan.getItem(i, j)->getKODE_HURUF();
                }
                cout << endl <<endl;
            }
        }
    }
}

void Peternak::TERNAK(){ 
    this->isPeternakanPenuh();
    this->isAnimalEmpty();   

    // Pilih hewan dari penyimpanan
    string slot = inputSlotTanahTernak();

    //get ID from slot
    int ID = this->inventory.getItem(slot)->getConfig()->getID();

    //Pilih lokasi ternak
    string slot_tanah = inputSlotInventoryTernak();
    
    //Add animal to peternakan
    Animal* animal = new Animal(ID);
    this->peternakan.add(animal, slot_tanah);

    animal->setIsInCage(true);

    this->inventory.remove(slot);

    cout << "Hewan berhasil diternakkan!" << endl;
    CETAK_PETERNAKAN();
}


void Peternak::KASIH_MAKAN(){ 
    // Cek apakah peternakan kosong atau inventory kosong
    isPeternakanKosong();
    isFoodEmpty();
    isAnimalFoodEmpty();

    // Pilih petak tanah
    string slot_tanah = inputSlotTanahKasihMakan();

    // Pilih hewan
    Animal* animal = this->peternakan.getItem(slot_tanah);
    
    cout << "Kamu memilih " << animal->getNAME() << " untuk diberi makan" << endl;
    cout << "Pilih pangan yang mau diberikan:" << endl << endl;

    string animal_type = animal->getTYPE();
    
    // Mencari tipe makanan untuk hewan
    string food_type = checkAnimalFoodType(animal_type);

    // Input slot makanan dari inventory
    string slot = inputSlotInventoryKasihMakan(animal_type,food_type);


    Product* food = new Product(this->inventory.getItem(slot)->getConfig()->getID());
    this->inventory.remove(slot);

    // Kasih makan ternak
    animal->Feed(food);
    cout << animal->getNAME() << " sudah diberi makan dan beratnya menjadi " << animal->getWeight() << endl;
}

void Peternak::PANEN(){ 
    // Temp map untuk menyimpan hewan yang siap dipanen
    map<string, int> temp_siap_panen;

    //CEK INVENTORY
    isInventoryPeternakPenuh();
    CETAK_PETERNAKAN();
    isHarvestReady();

    //Cari hewan yang siap di panen
    findAnimaltoHarvest(temp_siap_panen);

    // Cetak hewan yang siap dipanen
    printAnimaltoHarvest(temp_siap_panen);

    // pilih hewan
    int hewan_pilihan;
    int banyak_petak;
    string input;

    // OPSIONAL SELAIN LANGSUNG RETURN
    chooseAnimalToHarvest(hewan_pilihan,banyak_petak,temp_siap_panen,peternakan,input);

    //Pilih Petak
    int count = 0;
    int nPetak;
    string kode_hewan;

    // get kode hewan
    getKodeHewan(hewan_pilihan,kode_hewan,temp_siap_panen,nPetak,count);

    //get id dari hewan untuk mapping dari hewan ke produk hewan
    int ID = 0;

    inputPetakPanen(input,banyak_petak,nPetak,kode_hewan);

    //hitung inventory apakah cukup atau tidak
    // jika yang dipilih adalah ayam atau bebek maka tambahkan 1 telur
    if(kode_hewan == "CHK" || kode_hewan == "DCK"){
        this->isInventoryMemadai(banyak_petak*2);
    }else{
        this->isInventoryMemadai(banyak_petak);
    }

    string petak_to_harvest;
    string letak_panen[nPetak];

    // Panen hewan
    panenHewan(nPetak,banyak_petak,petak_to_harvest,ID,letak_panen,kode_hewan);
}

string Peternak::getType(){
    return "Peternak";
}

void Peternak::isPeternakanPenuh(){
    if (this->peternakan.isFull()){
        throw PeternakanPenuhException();
    }
    
}

void Peternak::isPeternakanKosong(){
    if(this->peternakan.calcEmptySpace() == this->peternakan.getHeight() * this->peternakan.getWidth()){
        throw PeternakanKosongException();
    }
}

void Peternak::isFoodEmpty(){
    for (int i = 0 ; i < this->inventory.getHeight();i++){
        for (int j = 0; j < this->inventory.getWidth(); j++){
            if (!this->inventory.isEmpty(i, j) && this->inventory.getItem(i, j)->isFood()){
                return;
            }
        }
    }
    throw InventoryNoFoodException();
}

void Peternak::isAnimalEmpty(){
    for (int i = 0 ; i < this->inventory.getHeight();i++){
        for (int j = 0; j < this->inventory.getWidth(); j++){
            if (!this->inventory.isEmpty(i, j) && this->inventory.getItem(i, j)->isAnimal()){
                return;
            }
        }
    }
    throw InventoryNoAnimalException();
}

void Peternak::isHarvestReady(){
    //Cek apakah ada tanaman yang bisa dipanen
    bool flag = false;
    for(int i = 0 ; i < this->peternakan.getHeight(); i++){
        for(int j = 0 ; j < this->peternakan.getWidth(); j++){
            if(!this->peternakan.isEmpty(i,j)){
                if(this->peternakan.getItem(i, j)->isReadyToHarvest()){
                    flag = true;
                    break;
                }
            }
        }
    }

    if(!flag){
        throw PanenHewanTidakTersediaException();
    }
}


void Peternak::isInventoryMemadai(int n){
    if(this->inventory.calcEmptySpace() < n){
        throw InventoryTidakMemadaiException();
    }
}

void Peternak::isAnimalFoodEmpty(){
    bool herbivore_food = isHerbivoreFoodReady();
    bool carnivore_food = isCarnivoreFoodReady();

    bool herbivore = false;
    bool carnivore = false;
    bool omnivore = false;

    for(int i = 0; i < this->peternakan.getHeight(); i++){
        for(int j = 0; j < this->peternakan.getWidth(); j++){
            if (!this->peternakan.isEmpty(i, j)){
                if (this->peternakan.getItem(i, j)->getTYPE() == "HERBIVORE"){
                    herbivore = true;
                } else if (this->peternakan.getItem(i, j)->getTYPE() == "CARNIVORE"){
                    carnivore = true;
                }else if (this->peternakan.getItem(i, j)->getTYPE() == "OMNIVORE"){
                    omnivore = true;
                }
            }
        }
    }

    if (herbivore_food && !herbivore && !omnivore && !carnivore_food && carnivore){
        throw CarnivoreAnimalDontHaveFood();
    } else if (carnivore_food && !herbivore_food && !carnivore && !omnivore && herbivore){
        throw HerbivoreAnimalDontHaveFood();
    }
}

bool Peternak::isHerbivoreFoodReady(){
    for(int i = 0; i < this->inventory.getHeight(); i++){
        for(int j = 0; j < this->inventory.getWidth(); j++){
            if (!this->inventory.isEmpty(i, j)){
                if (this->inventory.getItem(i, j)->getTYPE() == "PRODUCT_FRUIT_PLANT"){
                    return true;
                }
            }
        }
    }

    return false;
}

bool Peternak::isCarnivoreFoodReady(){
    for(int i = 0; i < this->inventory.getHeight(); i++){
        for(int j = 0; j < this->inventory.getWidth(); j++){
            if (!this->inventory.isEmpty(i, j)){
                if (this->inventory.getItem(i, j)->getTYPE() == "PRODUCT_ANIMAL"){
                    return true;
                }
            }
        }
    }

    return false;
}

bool Peternak::cekKondisiHewanSebelumLoop(string slot_tanah,bool herbivore_food,bool carnivore_food){
    bool flag = false;
    if(!this->peternakan.isEmpty(slot_tanah)){
        string tipe = this->peternakan.getItem(slot_tanah)->getTYPE();
        if(tipe == "HERBIVORE" && herbivore_food){
            flag = true;
        }else if(tipe == "CARNIVORE" && carnivore_food){
            flag = true;
        }else if(tipe == "OMNIVORE" && (herbivore_food || carnivore_food)){
            flag = true;
        }
    }

    return flag;
}

bool Peternak::cekKondisiHewan(string tipe,bool herbivore_food,bool carnivore_food){
    bool flag = false;
    if (tipe == "HERBIVORE" && !herbivore_food){
        cout << "\nHewan ini herbivora dan hanya ada makanan karnivora di inventory" << endl;
        cout << "Silahkan masukan petak tanah yang benar" << endl;
    } else if (tipe == "CARNIVORE" && !carnivore_food){
        cout << "\nHewan ini karnivora dan hanya ada makanan herbivora di inventory" << endl;
        cout << "Silahkan masukan petak tanah yang benar" << endl;
    }else{
        flag = true;
    }

    return flag;
}

string Peternak::checkAnimalFoodType(string animalType){
    string food_type;
    if(animalType == "HERBIVORE"){
        food_type = "PRODUCT_FRUIT_PLANT";
    }else{
        food_type = "PRODUCT_ANIMAL";
    }
    return food_type;
}

bool Peternak::checkFoodforAnimalBeforeLoop(string slot, string animal_type,string food_type){
    bool flag = false;
    if(!this->inventory.isEmpty(slot) && animal_type == "OMNIVORE" && this->inventory.getItem(slot)->isFood()){
        flag = true;
    }else if(!this->inventory.isEmpty(slot) && this->inventory.getItem(slot)->getTYPE() == food_type){
        flag = true;
    }

    return flag;

}

string Peternak::inputSlotTanahKasihMakan(){
    string slot_tanah;
    bool valid = false;
    
    CETAK_PETERNAKAN();
    
    bool herbivore_food = isHerbivoreFoodReady();
    bool carnivore_food = isCarnivoreFoodReady();

    while (!valid){
        try {
            cout << "Petak kandang: ";
            cin >> slot_tanah;
            bool flag = false;
            // cek flag sebelum mulai loop
            if(!this->peternakan.isEmpty(slot_tanah)){
                string tipe = this->peternakan.getItem(slot_tanah)->getTYPE();
                if(tipe == "HERBIVORE" && herbivore_food){
                    flag = true;
                }else if(tipe == "CARNIVORE" && carnivore_food){
                    flag = true;
                }else if(tipe == "OMNIVORE" && (herbivore_food || carnivore_food)){
                    flag = true;
                }
            }

            while (this->peternakan.isEmpty(slot_tanah) || !flag){
                if(!this->peternakan.isEmpty(slot_tanah)){
                    string tipe = this->peternakan.getItem(slot_tanah)->getTYPE();
                    flag = cekKondisiHewan(tipe,herbivore_food,carnivore_food);

                    if (!flag){
                        cout << "\nPetak tanah: ";
                        cin >> slot_tanah;
                    }
                }else{
                    cout << "\nPetak itu tidak ada hewannya" << endl;
                    cout << "Silahkan masukan petak tanah yang ada hewannya" << endl;
                    cout << "\nPetak tanah: ";
                    cin >> slot_tanah;
                }
            }
            valid = true;
        } catch (InvalidIndexException& e){
            cout << RED << e.what() << RESET << endl << endl; ;
        }
    }

    return slot_tanah;
}

string Peternak::inputSlotInventoryKasihMakan(string animal_type,string food_type){
    this->inventory.print();
    string slot;
    bool valid = false;

    while (!valid){
        try {

            cout << "Slot: ";
            cin >> slot;
            bool flag = false;
            // cek flag sebelum mulai loop
            flag = checkFoodforAnimalBeforeLoop(slot,animal_type,food_type);
            
            while (this->inventory.isEmpty(slot) || !this->inventory.getItem(slot)->isFood() || !flag){
                if (this->inventory.isEmpty(slot)){
                    cout << "\nKamu mengambil harapan kosong dari penyimpanan." << endl;
                    cout << "Silahkan masukan slot berisi makanan dari penyimpanan." << endl;

                    cout << "\nSlot: ";
                    cin >> slot;
                } else if(!this->inventory.getItem(slot)->isFood()){
                    cout << "\nBerbahaya jika kamu memberi makan ternak kamu dengan itu" << endl;
                    cout << "Silahkan masukan slot berisi makanan yang benar." << endl;

                    cout << "\nSlot: ";
                    cin >> slot;
                }else if(animal_type != "OMNIVORE"){
                    if (this->inventory.getItem(slot)->getTYPE() != food_type){
                        cout << "\nHewan ini tidak bisa makan itu" << endl;
                        cout << "Silahkan masukan slot berisi makanan yang benar." << endl;

                        cout << "\nSlot: ";
                        cin >> slot;
                    }else{
                        flag = true;
                    }
                }else{
                    flag = true;
                }
            }
            valid = true;
        } catch (InvalidIndexException& e){
            cout << RED << e.what() << RESET << endl << endl; ;
        }
    }

    return slot;
}

string Peternak::inputSlotTanahTernak(){
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
        } catch (InvalidIndexException& e){
            cout << RED << e.what() << RESET << endl << endl; ;
        }
    }

    return slot;
}

string Peternak::inputSlotInventoryTernak(){
    string slot_tanah;
    bool valid = false;


    cout << endl;

    CETAK_PETERNAKAN();
    while (!valid){
        try {

            cout << "Petak kandang: ";
            cin >> slot_tanah;

            while (!this->peternakan.isEmpty(slot_tanah)){
                cout << "\n Petak itu sudah ada hewannya" << endl;
                
                cout << "Silahkan masukan petak tanah yang masih kosong." << endl;

                cout << "\nPetak tanah: ";
                cin >> slot_tanah;
            }
            valid = true;
        } catch (InvalidIndexException& e){
            cout << RED << e.what() << RESET << endl << endl; ;
        }
    }
    return slot_tanah;
}

void Peternak::isInventoryPeternakPenuh(){
    if (this->inventory.isFull()){
        throw InventoryPeternakPenuhException();
    }
}

void Peternak::findAnimaltoHarvest(map<string, int> &temp_siap_panen){
    for(int i = 0 ; i < this->peternakan.getHeight(); i++){
        for(int j = 0 ; j < this->peternakan.getWidth(); j++){
            if(!this->peternakan.isEmpty(i,j)){
                if(this->peternakan.getItem(i, j)->isReadyToHarvest()){
                    string kode_tanaman = this->peternakan.getItem(i, j)->getKODE_HURUF();
                    if(temp_siap_panen.find(kode_tanaman) == temp_siap_panen.end()){
                        temp_siap_panen[kode_tanaman] = 1;
                    }else{
                        temp_siap_panen[kode_tanaman]++;
                    }
                }
            }
        }
    }
}

void Peternak::printAnimaltoHarvest(map<string, int> temp_siap_panen){
    cout << "Pilih hewan yang siap panen yang kamu miliki" << endl;
    int i = 1;
    for(auto it = temp_siap_panen.begin(); it != temp_siap_panen.end();it++){
        cout << i << ". " << it->first << " (" << it->second << " petak siap panen)" << endl;
        i++;
    }
}

 void Peternak::chooseAnimalToHarvest(int &hewan_pilihan, int &banyak_petak, map<string, int> temp_siap_panen, Inventory<Animal> peternakan, string &input){
    bool valid = false;
    
    while(!valid){
        try{
            cout << "\nNomor hewan yang ingin dipanen: ";
            cin >> input;

            // Mengonversi input menjadi integer
            hewan_pilihan = stoi(input);

            

            if (hewan_pilihan < 1 || hewan_pilihan > temp_siap_panen.size()) {
                cout << RED << "Pilihan tidak valid" << RESET << endl;
                valid = false;
            } else {
                valid = true;
            }

        }
        catch (const exception &e){
            cout << RED << "Error: Input harus berupa integer" << RESET << endl;
        }

        //Membersihkan input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
 }

void Peternak::getKodeHewan(int hewan_pilihan, string &kode_hewan, map<string, int> temp_siap_panen,int &nPetak,int &count){
    for(auto it = temp_siap_panen.begin(); it != temp_siap_panen.end();it++){
        if(count == hewan_pilihan - 1){
            nPetak = it->second;
            kode_hewan = it->first;
            break;
        }
        count++;
    }
}

void Peternak::inputPetakPanen(string &input, int &banyak_petak, int nPetak, string kode_hewan){
    bool valid = false;
    //OPSIONAL TANPA RETURN LANGSUNG 
    while(!valid){
        try{
            cout << "\nBerapa petak yang ingin dipanen: ";
            cin >> input;

            // Mengonversi input menjadi integer
            banyak_petak = stoi(input);

            if (banyak_petak < 1 || banyak_petak > nPetak) {
                cout << RED << "Pilihan tidak valid" << RESET << endl;
                valid = false;
            } else {
                valid = true;
            }
        }
        catch (const exception &e){
            cout << RED << "Error: Input harus berupa integer" << RESET << endl;
        }

        //Membersihkan input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Peternak::panenHewan(int nPetak, int banyak_petak,string &petak_to_harvest,int ID,string *letak_panen,string kode_hewan){
    for(int i  = 0 ; i < banyak_petak ; i++){
        bool valid = false;
        while(!valid){
            try{
                cout << "Petak ke-"  << i+1 << " : ";
                cin >> petak_to_harvest;

                while((this->peternakan.isEmpty(petak_to_harvest)) || this->peternakan.getItem(petak_to_harvest)->getConfig()->getKODE_HURUF() != kode_hewan ||!this->peternakan.getItem(petak_to_harvest)->isReadyToHarvest()){
                    cout << RED << "Petak tidak valid" << RESET << endl;
                    cout << "Petak ke-"  << i+1 << " : ";
                    cin >> petak_to_harvest;
                }


                //add item ke inventory
                ID = this->peternakan.getItem(petak_to_harvest)->getConfig()->getID();
                int offset = GameConfig::plantConfig.size();
                Item *item = new Product(ID + offset);
                this->addItem(item);

                if(this->peternakan.getItem(petak_to_harvest)->getNAME() == "CHICKEN"){
                    Item *egg = new Product(16);
                    this->addItem(egg);
                }else if(this->peternakan.getItem(petak_to_harvest)->getNAME() == "DUCK"){
                    Item *egg = new Product(17);
                    this->addItem(egg);
                }
                this->getPeternakan()->remove(petak_to_harvest);


                //Simpan kordinat panen
                letak_panen[i] = petak_to_harvest;
                

                valid = true;
            }
            catch (...){
                cout << RED << "Input tidak valid" << RESET << endl;
            }
        }
    }
    

    cout << nPetak << " petak Hewan " << kode_hewan << " pada petak ";
    for (int i = 0; i < nPetak-1; i++)
    {
        cout << letak_panen[i] << ", ";
    }
    cout << letak_panen[nPetak-1] << " telah dipanen!" << endl << endl;
}