#include "simpan.hpp"

Simpan::Simpan(string filename) : filename(filename) {}

bool Simpan::isValidName(){

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

string Simpan::convertLadangToString(Inventory<Plant>* ladang)
{
    string result = "";

    // jumlah item di ladang
    int plant_count = ladang->count();
    result += to_string(plant_count) + "\n";
    vector<int> idx;

    // ladang data
    for (int i = 0; i < GameConfig::miscConfig.getLADANG_SIZE()[1]; i++){
        for (int j = 0; j < GameConfig::miscConfig.getLADANG_SIZE()[0]; j++){
            if (!ladang->isEmpty(i, j)){
                idx = {j, i};   
                result += Util::IntToIdx(idx) + " " + ladang->getItem(i, j)->getNAME() + " " + to_string(ladang->getItem(i, j)->getAge()) + "\n";
            }
        }
    }

    return result;
}

string Simpan::convertPeterknakanToString(Inventory<Animal>* peternakan)
{
    string result = "";

    // jumlah item di peternakan
    int animal_count = peternakan->count();
    result += to_string(animal_count) + "\n";
    vector<int> idx;

    // peternakan data
    for (int i = 0; i < GameConfig::miscConfig.getPETERNAKAN_SIZE()[1]; i++){
        for (int j = 0; j < GameConfig::miscConfig.getPETERNAKAN_SIZE()[0]; j++){
            if (!peternakan->isEmpty(i, j)){
                idx = {j, i};   
                result += Util::IntToIdx(idx) + " " + peternakan->getItem(i, j)->getNAME() + " " + to_string(peternakan->getItem(i, j)->getWeight()) + "\n";
            }
        }
    }

    return result;
}

string Simpan::convertPlayerToString(Player* player)
{
    string result = "";

    // nama role weight money
    result += player->getName() + " ";
    result += player->getType() + " ";
    result += to_string(player->getWeight()) + " ";
    result += to_string(player->getMoney()) + "\n";

    // jumlah item di inventory
    Inventory<Item>* inv = player->getInventory();
    int inv_count = inv->count();
    result += to_string(inv_count) + "\n";

    // inventory data
    for (int i = 0; i < GameConfig::miscConfig.getINVENTORY_SIZE()[1]; i++){
        for (int j = 0; j < GameConfig::miscConfig.getINVENTORY_SIZE()[0]; j++){
            if (!inv->isEmpty(i, j)){
                result += inv->getItem(i, j)->getNAME() + "\n";
            }
        }
    }

    // special inventory data
    if (player->getType() == "Petani") {
        result += Simpan::convertLadangToString(player->getLadang());
    } else if (player->getType() == "Peternak") {
        result += Simpan::convertPeterknakanToString(player->getPeternakan());
    }

    return result;
}

string Simpan::convertTokoToString()
{
    string result = "";
    string temp_result = "";

    int count_toko_entry = Toko::list_item.size();
    int count = 0;

    for (int i = 0; i < count_toko_entry; i++){
        count += Toko::list_item[i].getAmount();
        temp_result += Toko::list_item[i].getItem()->getNAME() + " " + to_string(Toko::list_item[i].getAmount()) + "\n";
    }

    result += to_string(count_toko_entry) + "\n" + temp_result;

    return result;
}

string Simpan::convertGameDataToString()
{   
    string result = "";

    // jumlah player
    int player_count = Player::player_count;
    result += to_string(player_count) + "\n";
    
    // convert data layer ke string
    for (int i = 0; i < Player::player_count; i++) {
        result += Simpan::convertPlayerToString(Player::players[i]);
    }

    // convert data toko ke string
    result += Simpan::convertTokoToString();

    // hapus last newline
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }

    return result;
}

void Simpan::writeToFile(string data)
{
    ofstream file;
    file.open(this->filename);
    file << data;
    file.close();
}

void Simpan::saveGame()
{   
    string filename;

    cout << "\nMasukkan lokasi berkas state : ";
    cin >> filename;

    Simpan simpan(filename);

    if (!simpan.isValidName()) {
       throw InvalidFileException();
    }

    string data = Simpan::convertGameDataToString();

    simpan.writeToFile(data);

    cout << "State berhasil disimpan\n" << endl;
}

