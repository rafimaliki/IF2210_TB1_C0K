#include "player.hpp"

vector<Player*> Player::players;
int Player::current_player_idx = 0;
int Player::player_count = 0;

Player::Player(string name, int money, int body_weight) : 
    id(Player::player_count+1), 
    name(name),
    money(money), 
    body_weight(body_weight), 
    inventory(GameConfig::miscConfig.getINVENTORY_SIZE()[0], GameConfig::miscConfig.getINVENTORY_SIZE()[1], "PENYIMPANAN") {
    players.push_back(this);
    player_count++;
}

Player::~Player(){}

void Player::printStats(){
    cout << "\nPlayer stats: " << endl;
    cout << "  Id    : " << this->id << endl;
    cout << "  Nama  : " << this->name << endl;
    cout << "  Role  : " << this->getType() << endl;
    cout << "  Uang  : " << this->money << " gulden" <<endl;
    cout << "  Berat : " << this->body_weight << " kg" << endl << endl;
}

void Player::printInventory(){
    this->inventory.print();
}

Inventory<Item>* Player::getInventory(){
    return &this->inventory;
}

Player* Player::getCurrentPlayer(){
    return players[current_player_idx];
}

void Player::next(){   
    cout << "Turn player " << getCurrentPlayer()->name << "berakhir" <<endl; 
    current_player_idx++;
    if (current_player_idx >= player_count){
        current_player_idx = 0;
    }
    cout << "Giliran player " << getCurrentPlayer()->name << endl << endl; 
}

void Player::printLahan(){}
Inventory<Plant>* Player::getLadang(){
    return nullptr;
}
void Player::printPeternakan(){}
Inventory<Animal>* Player::getPeternakan(){
    return nullptr;
}
void Player::addPlant(Plant* item){}
void Player::addAnimal(Item* item){}
void Player::addItem(Item* item){
    this->inventory.add(item);
}

bool Player::haveFood(){
    for (int i = 0 ; i < GameConfig::miscConfig.getINVENTORY_SIZE()[0]; i++){
        for (int j = 0 ; j < GameConfig::miscConfig.getINVENTORY_SIZE()[1]; j++){
            if (!this->inventory.isEmpty(i, j) && this->inventory.getItem(i, j)->isFood()){
                return true;
            }
        }
    }
    return false;
}

void Player::eat(Item* food){
    if (!food->isFood()){
        throw NotFoodException();
    }
    this->body_weight += food->getADDED_WEIGHT();
}

string Player::getType(){
    return "";
}

int Player::getMoney(){
    return money;
}

void Player::setMoney(int money){
    this->money = money;
}

string Player::getName(){
    return name;
}

/* Game command related methods */

void Player::NEXT(){

    cout << "\033[1;33m\nHari telah berlalu...\n\n\033[0m";
    Plant::AgeAllPlants();

     cout << "Turn player " << getCurrentPlayer()->name << " berakhir" <<endl; 

    current_player_idx++;
    if (current_player_idx >= player_count){
        current_player_idx = 0;
    }

    cout << "Giliran player " << getCurrentPlayer()->name << endl << endl; 
}
void Player::CETAK_PENYIMPANAN(){
    this->inventory.print();
}
void Player::PUNGUT_PAJAK(){
    throw NoPermissionException();
}
void Player::CETAK_LADANG(){
    throw NoPermissionException();
}
void Player::CETAK_PETERNAKAN(){
    throw NoPermissionException();
}
void Player::TANAM(){
    throw NoPermissionException();
}
void Player::TERNAK(){
    throw NoPermissionException();
}
void Player::BANGUN(){
    throw NoPermissionException();
}
void Player::MAKAN(){ 

    if (!this->haveFood()){
       throw DontHaveFoodException();
    }

    cout << "Pilih makanan dari penyimpanan" << endl;
    this->inventory.print();

    string msg = "Silahkan masukan slot yang berisi makanan.\n";

    string slot;
    bool valid = false;

    vector<int> idx;
    Item* food;

    while (!valid){
        try {
            cout << "Slot: ";
            cin >> slot;

            idx = Util::idxToInt(slot);
            food = this->inventory.getItem(idx[0], idx[1]);

            this->eat(food);

            cout << "\nDengan lahapnya, kamu memakanan hidangan itu" << endl;
            cout << "Alhasil, berat badan kamu naik menjadi " << this->body_weight << endl << endl;

            this->inventory.remove(idx[0], idx[1]);

            valid = true;

        } catch (InvalidIndexException& e){
            cout << RED << e.what() << RESET << endl;
        } catch (IsEmptySlotException& e){
            cout << endl << e.what() << endl << msg << endl;
        } catch (NotFoodException& e){
            cout << endl << e.what() << endl << msg << endl;
        }
    }
}

void Player::KASIH_MAKAN(){
    throw NoPermissionException();
}
void Player::BELI(){  /* BELUM IMPLEMENTASI (butuh class Toko) */
    cout << YELLOW << "\nCommand BELI belum diimplementasikan!\n" << RESET << endl;
}
void Player::JUAL(){  /* BELUM IMPLEMENTASI (butuh class Toko) */
    cout << YELLOW << "\nCommand JUAL belum diimplementasikan!\n" << RESET << endl;
}
void Player::PANEN(){
    throw NoPermissionException();
}

void Player::SIMPAN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand SIMPAN belum diimplementasikan!\n" << RESET << endl;
}
void Player::TAMBAH_PEMAIN(){
    throw NoPermissionException();
}

/* Cheat Commands */

void Player::SET(){

    cout << "\nAtribut:" << endl;
    cout << "1. Money" << endl;
    cout << "2. Body Weight" << endl;

    string input;
    cout << "\nPilih (1-2): ";
    cin >> input;

    int choice = Util::stringToInt(input);

    if (choice == 1){
        cout << "Masukan jumlah uang: ";
        cin >> input;
        this->money = Util::stringToInt(input);
    } else if (choice == 2){
        cout << "Masukan berat badan: ";
        cin >> input;
        this->body_weight = Util::stringToInt(input);
    } else {
        cout << "Gagal!\n" << endl;
        return;
    }

    cout << "Sukses!\n" << endl;
}

void Player::GIVE(){

    if (this->inventory.isFull()){
        cout << "\nInventory penuh\n" << endl;
        return;
    }

    cout << "\nTipe item:" << endl;
    cout << "1. Plant" << endl;
    cout << "2. Animal" << endl;
    cout << "3. Product" << endl;

    int choice;
    string input;
    cout << "\nPilih (1-3): ";
    cin >> input;
    choice = Util::stringToInt(input);

    if (choice < 1 || choice > 3){
        cout << "Gagal!\n" << endl;
        return;
    }
    Item* item;

    if (choice == 1){
        cout << "\nDaftar tanaman:" << endl;
        for (int i = 0; i < int(GameConfig::plantConfig.size()); i++){
            cout << i+1 << ". " << GameConfig::plantConfig[i].getNAME() << endl;
        }
        cout << "\nPilih (1-" << GameConfig::plantConfig.size() << "): ";
        cin >> input;
        choice = Util::stringToInt(input);

        if (choice < 0 || choice > int(GameConfig::plantConfig.size())){
            cout << "Gagal!\n" << endl;
            return;
        }

        item = new Plant(choice);

    } else if (choice == 2){
        cout << "\nDaftar hewan:" << endl;
        for (int i = 0; i < int(GameConfig::animalConfig.size()); i++){
            cout << i+1 << ". " << GameConfig::animalConfig[i].getNAME() << endl;
        }
        cout << "\nPilih (1-" << GameConfig::animalConfig.size() << "): ";
        cin >> input;
        choice = Util::stringToInt(input);

        if (choice < 0 || choice > int(GameConfig::animalConfig.size())){
            cout << "Gagal!\n" << endl;
            return;
        }

        item = new Animal(choice);

    } else if (choice == 3){
        cout << "\nDaftar produk:" << endl;
        for (int i = 0; i < int(GameConfig::productConfig.size()); i++){
            cout << i+1 << ". " << GameConfig::productConfig[i].getNAME() << endl;
        }
        cout << "\nPilih (1-" << GameConfig::productConfig.size() << "): ";
        cin >> input;
        choice = Util::stringToInt(input);

        if (choice < 0 || choice > int(GameConfig::productConfig.size())){
            cout << "Gagal!\n" << endl;
            return;
        }

        item = new Product(choice);
    }

    Player::getCurrentPlayer()->addItem(item);

    cout << "Sukses!\n" << endl;
}

void Player::STATS(){
    this->printStats();
}