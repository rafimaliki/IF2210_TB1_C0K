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

void Player::printStats(){
    cout << "\nPlayer stats: " << endl;
    cout << "  Id: " << this->id << endl;
    cout << "  Name: " << this->name << endl;
    cout << "  Money: " << this->money << endl;
    cout << "  Body Weight: " << this->body_weight << endl << endl;
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
    cout << "Player " << getCurrentPlayer()->name << "'s turn ended" <<endl; 
    current_player_idx++;
    if (current_player_idx >= player_count){
        current_player_idx = 0;
    }
    cout << "Player " << getCurrentPlayer()->name << "'s turn" << endl << endl; 
}

void Player::printLahan(){}
Inventory<Plant>* Player::getLadang(){
    return nullptr;
}
void Player::printPeternakan(){}
void Player::addPlant(Plant* item){}
void Player::addAnimal(Item* item){}
void Player::addItem(Item* item){
    this->inventory.add(item);
}


/* Game command related methods */

void Player::NEXT(){

    cout << "\033[1;33m\nAnother day has passed...\n\033[0m";
    Plant::AgeAllPlants();

    cout << "Player " << getCurrentPlayer()->name << "'s turn ended" << endl;

    current_player_idx++;
    if (current_player_idx >= player_count){
        current_player_idx = 0;
    }

    cout << "Player " << getCurrentPlayer()->name << "'s turn" << endl << endl;
}
void Player::CETAK_PENYIMPANAN(){
    this->inventory.print();
}
void Player::PUNGUT_PAJAK(){
    cout << RED << "\nTidak memiliki akses ke command PUNGUT_PAJAK!\n" << RESETstring << endl;
}
void Player::CETAK_LADANG(){
    cout << RED << "\nTidak memiliki akses ke command CETAK_LADANG!\n" << RESETstring << endl;
}
void Player::CETAK_PETERNAKAN(){
    cout << RED << "\nTidak memiliki akses ke command CETAK_PETERNAKAN!\n" << RESETstring << endl;
}
void Player::TANAM(){
    cout << RED << "\nTidak memiliki akses ke command TANAM!\n" << RESETstring << endl;
}
void Player::TERNAK(){
    cout << RED << "\nTidak memiliki akses ke command TERNAK!\n" << RESETstring << endl;
}
void Player::BANGUN(){
    cout << RED << "\nTidak memiliki akses ke command BANGUN!\n" << RESETstring << endl;
}
void Player::MAKAN(){  /* BELUM IMPLEMENTASI */

    Inventory<Item>* inv = this->getInventory();

    cout << "Pilih makanan dari penyimpanan" << endl;
    inv->print();

    string slot;
    bool valid = false;

    while (!valid){
        try {

            cout << "Slot: ";
            cin >> slot;

            while (inv->isEmpty(slot) || !inv->getItem(slot)->isFood()){
                if (inv->isEmpty(slot)){
                    cout << "\nKamu mengambil harapan kosong dari penyimpanan." << endl;
                } else {
                    cout << "\nApa yang kamu lakukan?!! Kamu mencoba untuk memakan itu?!!" << endl;
                }
                cout << "Silahkan masukan slot yang berisi makanan." << endl;

                cout << "\nSlot: ";
                cin >> slot;
            }
            valid = true;
        } catch (...){
            cout << RED << "Invalid slot!\n" << RESETstring << endl;
        }
    }

    this->body_weight += inv->getItem(slot)->getADDED_WEIGHT();

    cout << "\nDengan lahapnya, kamu memakanan hidangan itu" << endl;
    cout << "Alhasil, berat badan kamu naik menjadi " << this->body_weight << endl << endl;

    inv->remove(slot);
}

void Player::KASIH_MAKAN(){
    cout << RED << "\nTidak memiliki akses ke command KASIH_MAKAN!\n" << RESETstring << endl;
}
void Player::BELI(){  /* BELUM IMPLEMENTASI (butuh class Toko) */
    cout << YELLOW << "\nCommand BELI belum diimplementasikan!\n" << RESETstring << endl;
}
void Player::JUAL(){  /* BELUM IMPLEMENTASI (butuh class Toko) */
    cout << YELLOW << "\nCommand JUAL belum diimplementasikan!\n" << RESETstring << endl;
}
void Player::PANEN(){
    cout << RED << "\nTidak memiliki akses ke command PANEN!\n" << RESETstring << endl;
}

void Player::SIMPAN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand SIMPAN belum diimplementasikan!\n" << RESETstring << endl;
}
void Player::TAMBAH_PEMAIN(){
    cout << RED << "\nTidak memiliki akses ke command TAMBAH_PEMAIN!\n" << RESETstring << endl;
}