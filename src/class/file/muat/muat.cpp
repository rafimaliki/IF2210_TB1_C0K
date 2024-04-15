#include "muat.hpp"

Muat::Muat(string filename) : FileReader(filename) {}

bool Muat::tryReadFile(){

    ifstream file(filename);

    if (!file.is_open()) {
        return false;
    } else {
        file.close();
        return true;
    }
}

void Muat::loadSaveFile()
{   
    string filename;

    cout << "Masukkan lokasi berkas state : ";
    cin >> filename;

    Muat muat(filename);

    if (!muat.isValidName() || !muat.tryReadFile()) {
       throw FailReadFileException();
    }

    muat.data = muat.readFile();
    muat.spawnObject();
    
    cout << GREEN << "State berhasil dimuat\n" << RESET << endl;
}

void Muat::spawnObject(){

    int row = 0, num_player = stoi(this->data[0][0]); row++;

    // Spawning new Player
    for (int i = 0; i < num_player; i++){

        Player* new_player = Muat::spawnPlayer(this->data[row]); 
        string job = this->data[row][this->data[row].size()-3]; row++;

        int num_inventory = stoi(this->data[row][0]); row++;
        Inventory<Item>* inventory = new_player->getInventory();

        // Spawning player inventory
        for (int j = 0; j < num_inventory; j++){
            Item* item = Muat::spawnItem(this->data[row][0]); row++;
            (*inventory) += item;
        }

        // Spawning ladang
        if (job == "Petani"){

            int num_special_inventory = stoi(this->data[row][0]); row++;

            for (int j = 0; j < num_special_inventory; j++){

                Plant* plant = Muat::spawnPlant(this->data[row][1], stoi(this->data[row][2]));
                new_player->getLadang()->add(plant, this->data[row][0]); row++;
            }

        // Spawning peternakan
        } else if (job == "Peternak"){

            int num_special_inventory = stoi(this->data[row][0]); row++;

            for (int j = 0; j < num_special_inventory; j++){

                Animal* animal = Muat::spawnAnimal(this->data[row][1], stoi(this->data[row][2]));
                new_player->getPeternakan()->add(animal, this->data[row][0]); row++;
            }
        }
    }

    // Spawning Toko
    int num_toko_unique_item = stoi(this->data[row][0]); row++;

    for (int i = 0; i < num_toko_unique_item; i++){
       
        int count_toko_entry = stoi(this->data[row][1]);
        Item* item = Muat::spawnItem(this->data[row][0]); row++;

        for (int j = 0; j < count_toko_entry; j++){
            Toko::addItem(item);
        }
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

Player* Muat::spawnPlayer(vector<string> vec){

    Player* new_player;

    int len = vec.size();

    string name = composeName(vec);
    string job = vec[len-3];
    int weight = stoi(vec[len-2]);
    int money = stoi(vec[len-1]);
    
    if (job == "Walikota"){
        new_player = new Walikota(name, money, weight);
    } else if (job == "Petani"){
        new_player = new Petani(name, money, weight);
    } else if (job == "Peternak"){
        new_player = new Peternak(name, money, weight);
    } else {
        throw InvalidDataException();
    }

    return new_player;
}

Item* Muat::spawnItem(string name){
    vector<string> type_id = Item::getTYPE_IDbyNAME(name);
    string type = type_id[0];
    int id = stoi(type_id[1]);

    Item* item;

    if (type == "Plant"){
        item = new Plant(id);
    } else if (type == "Animal") {
        item = new Animal(id);
    } else if (type == "Product") {
        item = new Product(id);
    } else if (type == "Bangunan") {
        item = new Bangunan(id);
    } else {
        throw InvalidDataException();
    } 
    return item;
}

Plant* Muat::spawnPlant(string name, int age){
    vector<string> type_id = Item::getTYPE_IDbyNAME(name);
    int id = stoi(type_id[1]);

    Plant* plant = new Plant(id, age);
    plant->setPlanted(true);
    return plant;
}

Animal* Muat::spawnAnimal(string name, int weight){
    vector<string> type_id = Item::getTYPE_IDbyNAME(name);
    int id = stoi(type_id[1]);

    Animal* animal = new Animal(id, weight);
    animal->setIsInCage(true);
    return animal;
}