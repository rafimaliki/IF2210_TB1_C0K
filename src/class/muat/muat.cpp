#include "muat.hpp"


Muat::Muat(string filename) : FileReader(filename) {}

bool Muat::isValidName(){

    // check dua char pertama "./" bukan
    if ((filename.length() <= 2) || filename.substr(0, 2) != "./"){
        return false;
    } 

    // menghilangkan "./" dari filename
    this->filename = this->filename.erase(0, 2);

    bool haveSlash = false;
    bool haveFolderName = false;
    bool haveFileName = false;

    // cek apakah ada folder name dan file name
    for (int i = 0; i < filename.length(); i++) {
        if (filename[i] != '/' && !haveSlash && !haveFileName) {
            haveFolderName = true;
        } else if (filename[i] == '/' && haveFolderName && !haveSlash && !haveFileName) {
            haveSlash = true;
        } else if (filename[i] != '/' && haveFolderName && haveSlash && !haveFileName) {
            haveFileName = true;
        }
    }

    if (!haveFileName) {
        return false;
    }

    ifstream file;
    file.open(filename);

    // cek folder valid dengan cara membuka file
    if (!file.is_open()) {
        return false;
    } else {
        file.close();
    }

    return true;
}

void Muat::loadSaveFile()
{   
    string filename;

    cout << "Masukkan lokasi berkas state : ";
    cin >> filename;

    Muat muat(filename);

    if (!muat.isValidName()) {
       throw FailReadFileException();
    }

    muat.data = muat.readFile();
    muat.spawnObject();
    

    // for (int i = 0; i < muat.data.size(); i++) {
    //     for (int j = 0; j < muat.data[i].size(); j++) {
    //         cout << muat.data[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "\nState berhasil dimuat\n" << endl;
}

void Muat::spawnObject(){

    
    int row = 0;
    int num_player = stoi(this->data[0][0]); row++;

    int num_inventory, num_special_inventory, num_toko, row_len, weight, money, id, count_toko_entry;
    string name, job, type;
    vector<string> type_id;

    Player* new_player;
    Item* item;
    Plant* plant;
    Animal* animal;

    Inventory<Plant>* ladang;
    Inventory<Animal>* peternakan;

    for (int i = 0; i < num_player; i++){

        row_len = this->data[row].size();

        name = composeName(this->data[row]);
        job = this->data[row][row_len-3];
        weight = stoi(this->data[row][row_len-2]);
        money = stoi(this->data[row][row_len-1]);
        
        if (job == "Walikota"){
            new_player = new Walikota(name, money, weight);
        } else if (job == "Petani"){
            new_player = new Petani(name, money, weight);
        } else if (job == "Peternak"){
            new_player = new Peternak(name, money, weight);
        } else {
            // throw InvalidJobException();
        }

        row++;

        num_inventory = stoi(this->data[row][0]);

        row++;

        for (int j = 0; j < num_inventory; j++){

            type_id = Item::getTYPE_IDbyNAME(this->data[row][0]);
            type = type_id[0];
            id = stoi(type_id[1]);

            if (type == "Plant"){
                item = new Plant(id);
            } else if (type == "Animal") {
                item = new Animal(id);
            } else if (type == "Product") {
                item = new Product(id);
            } else if (type == "Bangunan") {
                item = new Bangunan(id);
            }

            new_player->addItem(item);
            row++;
        }

        if (job == "Petani"){

            ladang = new_player->getLadang();
            num_special_inventory = stoi(this->data[row][0]); row++;

            for (int j = 0; j < num_special_inventory; j++){
                id = stoi(Item::getTYPE_IDbyNAME(this->data[row][1])[1]);
                plant = new Plant(id, stoi(this->data[row][2]));
                plant->setPlanted(true);
                ladang->add(plant, this->data[row][0]);
                row++;
            }

        } else if (job == "Peternak"){

            peternakan = new_player->getPeternakan();
            num_special_inventory = stoi(this->data[row][0]); row++;

            for (int j = 0; j < num_special_inventory; j++){
                id = stoi(Item::getTYPE_IDbyNAME(this->data[row][1])[1]);
                animal = new Animal(id, stoi(this->data[row][2]));
                animal->setIsInCage(true);
                peternakan->add(animal, this->data[row][0]);
                row++;
            }
        }
    }
    num_toko = stoi(this->data[row][0]); row++;
    for (int i = 0; i < num_toko; i++){
        type_id = Item::getTYPE_IDbyNAME(this->data[row][0]);
        type = type_id[0];
        id = stoi(type_id[1]);
        count_toko_entry = stoi(this->data[row][1]);

        if (type == "Product"){
            item = new Product(id);

        } else if (type == "Bangunan"){
            item = new Bangunan(id);
        }

        for (int j = 0; j < count_toko_entry; j++){
            Toko::addItem(item);
        }
        row++;
    }
}

string Muat::composeName(vector<string> vec){

    string name = "";

    int len_vec = vec.size();
    int len_name = len_vec - 3;

    for (int i = 0; i < len_name; i++){
        name += vec[i];

        if (i != len_name-1){
            name += " ";
        }
    }

    return name;
}
