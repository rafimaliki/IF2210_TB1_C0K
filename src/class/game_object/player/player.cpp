<<<<<<< HEAD
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
=======
#include "player.hpp"
#include <limits>    //perlu buat cin sama spasi
#include <algorithm> //perlu buat cin sama spasi
vector<Player *> Player::players;
int Player::current_player_idx = 0;
int Player::player_count = 0;

Player::Player(string name, int money, int body_weight) : id(Player::player_count + 1),
                                                          name(name),
                                                          money(money),
                                                          body_weight(body_weight),
                                                          inventory(GameConfig::miscConfig.getINVENTORY_SIZE()[0], GameConfig::miscConfig.getINVENTORY_SIZE()[1], "PENYIMPANAN")
{
    players.push_back(this);
    player_count++;
}

Player::~Player() {}

void Player::printStats()
{
    cout << "\nPlayer stats: " << endl;
    cout << "  Id    : " << this->id << endl;
    cout << "  Nama  : " << this->name << endl;
    cout << "  Role  : " << this->getType() << endl;
    cout << "  Uang  : " << this->money << " gulden" << endl;
    cout << "  Berat : " << this->body_weight << " kg" << endl
         << endl;
}

void Player::printInventory()
{
    this->inventory.print();
}

Inventory<Item> *Player::getInventory()
{
    return &this->inventory;
}

Player *Player::getCurrentPlayer()
{
    return players[current_player_idx];
}

void Player::next()
{
    cout << "Turn player " << getCurrentPlayer()->name << "berakhir" << endl;
    current_player_idx++;
    if (current_player_idx >= player_count)
    {
        current_player_idx = 0;
    }
    cout << "Giliran player " << getCurrentPlayer()->name << endl
         << endl;
}

void Player::printLahan() {}
Inventory<Plant> *Player::getLadang()
{
    return nullptr;
}
void Player::printPeternakan() {}
Inventory<Animal> *Player::getPeternakan()
{
    return nullptr;
}
void Player::addPlant(Plant *item) {}
void Player::addAnimal(Item *item) {}
void Player::addItem(Item *item)
{
    this->inventory.add(item);
}

bool Player::haveFood()
{
    for (int i = 0; i < GameConfig::miscConfig.getINVENTORY_SIZE()[0]; i++)
    {
        for (int j = 0; j < GameConfig::miscConfig.getINVENTORY_SIZE()[1]; j++)
        {
            if (!this->inventory.isEmpty(i, j) && this->inventory.getItem(i, j)->isFood())
            {
                return true;
            }
        }
    }
    return false;
}

void Player::eat(Item *food)
{
    if (!food->isFood())
    {
        throw NotFoodException();
    }
    this->body_weight += food->getADDED_WEIGHT();
}

string Player::getType()
{
    return "";
}

int Player::getMoney()
{
    return money;
}

void Player::setMoney(int money)
{
    this->money = money;
}

string Player::getName()
{
    return name;
}

/* Game command related methods */

void Player::NEXT()
{

    cout << "\033[1;33m\nHari telah berlalu...\n\n\033[0m";
    Plant::AgeAllPlants();

    cout << "Turn player " << getCurrentPlayer()->name << " berakhir" << endl;

    current_player_idx++;
    if (current_player_idx >= player_count)
    {
        current_player_idx = 0;
    }

    cout << "Giliran player " << getCurrentPlayer()->name << endl
         << endl;
}
void Player::CETAK_PENYIMPANAN()
{
    this->inventory.print();
}
void Player::PUNGUT_PAJAK()
{
    throw NoPermissionException();
}
void Player::CETAK_LADANG()
{
    throw NoPermissionException();
}
void Player::CETAK_PETERNAKAN()
{
    throw NoPermissionException();
}
void Player::TANAM()
{
    throw NoPermissionException();
}
void Player::TERNAK()
{
    throw NoPermissionException();
}
void Player::BANGUN()
{
    throw NoPermissionException();
}
void Player::MAKAN()
{

    if (!this->haveFood())
    {
        throw DontHaveFoodException();
    }

    cout << "Pilih makanan dari penyimpanan" << endl;
    this->inventory.print();

    string msg = "Silahkan masukan slot yang berisi makanan.\n";

    string slot;
    bool valid = false;

    while (!valid)
    {
        try
        {
            cout << "Slot: ";
            cin >> slot;

            vector<int> idx = Util::idxToInt(slot);
            Item *food = this->inventory.getItem(idx[0], idx[1]);

            this->eat(food);

            cout << "\nDengan lahapnya, kamu memakanan hidangan itu" << endl;
            cout << "Alhasil, berat badan kamu naik menjadi " << this->body_weight << endl
                 << endl;

            this->inventory.remove(idx[0], idx[1]);

            valid = true;
        }
        catch (InvalidIndexException &e)
        {
            cout << RED << e.what() << RESET << endl;
        }
        catch (IsEmptySlotException &e)
        {
            cout << endl
                 << e.what() << endl
                 << msg << endl;
        }
        catch (NotFoodException &e)
        {
            cout << endl
                 << e.what() << endl
                 << msg << endl;
        }
    }
}

void Player::KASIH_MAKAN()
{
    throw NoPermissionException();
}

void Player::BELI()
{
    if (this->inventory.isFull())
    {
        cout << "Inventory penuh bang! mau taro dimana bjir" << endl;
    }
    else
    {
        string input, slotstring;
        int nomor, amount;
        bool valid = false;

        Toko::displayToko();
        cout << "Uang anda : " << this->money << endl;
        cout << "Slot penyimpanan tersedia: " << inventory.calcEmptySpace() << endl;
        cout << GREEN << "Ketik 'C' untuk keluar dari toko" << RESET << endl;
        cout << endl;
        while (!valid && !inventory.isFull())
        {
            try
            {
                cout << "Masukkan no. barang yang ingin dibeli : ";
                cin >> input;
                if (input == "C")
                    break;
                nomor = Util::stringToInt(input);
                cout << "Kuantitas : ";
                cin >> input;
                if (input == "C")
                    break;
                amount = Util::stringToInt(input);

                /*Gk muat invent*/
                if (amount > this->inventory.calcEmptySpace())
                    throw InventorySizeNotValidException();
                /*Walikota beli buiding*/

                if (Toko::getItemToko(nomor)->getTYPE() == "" && this->id == 1)
                    throw RoleNotValid();
                Item *beli = Toko::beliItemToko(nomor, amount, this->money);
                this->money -= (amount * beli->getPRICE());
                cout << "Selamat Anda berhasil membeli " << amount << " " << beli->getNAME() << ". Uang Anda tersisa " << this->money << " gulden. " << endl;
                cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
                this->inventory.print();

                /*Sesi Pemilihan Petak*/
                bool petak_valid = false;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                while (!petak_valid)
                {

                    try
                    {
                        cout << "Petak: ";
                        getline(cin, slotstring);
                        vector<string> result_petak = Util::inputMultiplePetak(slotstring);
                        bool valid_slot = true; // Atur menjadi true agar masuk ke loop pertama
                        while (result_petak.size() != amount || valid_slot)
                        {
                            valid_slot = false;
                            for (const string &petak : result_petak)
                            {
                                if (!this->inventory.isEmpty(petak))
                                {
                                    valid_slot = true;
                                    break;
                                }
                            }
                            if (result_petak.size() != amount || valid_slot)
                            {
                                cout << RED << "Slot tidak tersedia / amount tidak sesuai, input ulang" << RESET << endl;
                                cout << "Petak: ";
                                getline(cin, slotstring);
                                result_petak = Util::inputMultiplePetak(slotstring);
                            }
                        }

                        for (int i = 0; i < amount; i++)
                        {
                            inventory.add(beli, result_petak[i]);
                        }

                        valid = true;
                        petak_valid = true;
                        cout << GREEN << "Sukses!" << RESET << endl;
                    }
                    catch (IndexNotValidException &e)
                    {
                        cout << e.what() << endl;
                    }
                }
            }
            catch (RoleNotValid &e)
            {
                cout << e.what() << endl;
            }
            catch (GuldenInvalid &e)
            {
                cout << e.what() << endl;
            }
            catch (...)
            {
                cout << "Invalid input!" << endl;
            }
        }
    }
}

void Player::JUAL()
{
    if (this->inventory.calcEmptySpace() == this->inventory.height * this->inventory.width)
    {
        cout << "Lu miskin gk punya apa apa di inventory, mau jual apa" << endl;
    }
    else
    {
        bool valid = false;
        string slotstring;
        vector<string> slotstemp;
        char opsi;
        vector<string> finalslots;
        cout << "Berikut penyimpanan anda" << endl;
        this->inventory.print();
        while (!valid)
        {
            cout << "Silakan pilih petak yang ingin anda jual!" << endl;
            cout << "Petak  : ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, slotstring);
            cout << "Yakin mau jual? (Y/N) : ";
            cin >> opsi;
            if (opsi == 'N')
            {
                cout << "Jual batal!" << endl;
                break;
            }
            finalslots.clear();
            finalslots = Util::inputMultiplePetak(slotstring);
            try
            {
                for (int i = 0; i < finalslots.size(); i++)
                {
                    if (this->inventory.isEmpty(finalslots[i]))
                        throw SlotEmptyException();
                    if (this->inventory.getItem(finalslots[i])->getTYPE() == "" && this->id != 1)
                        throw RoleNotValid();
                }
                int total_money = 0;
                for (int i = 0; i < finalslots.size(); i++)
                {
                    Item *newitem = this->inventory.getItem(finalslots[i]);
                    total_money += newitem->getPRICE();
                    Toko::addItem(newitem);
                    this->inventory.remove(finalslots[i]);
                }
                valid = true;
                setMoney(this->money += total_money);
                cout << GREEN << "Barang anda berhasil terjual! Uang anda bertambah " << total_money << " gulden! gacor!!!" << RESET << endl;
            }
            catch (InvalidIndexException &e)
            {
                cout << e.what() << endl;
            }
            catch (RoleNotValid &e)
            {
                cout << e.what() << endl;
            }
            catch (...)
            {
                cout << "Invalid input!" << '\n';
            }
        }
    }
}

void Player::PANEN()
{
    cout << RED << "\nTidak memiliki akses ke command PANEN!\n"
         << RESET << endl;
}

void Player::SIMPAN()
{ /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand SIMPAN belum diimplementasikan!\n"
         << RESET << endl;
}
void Player::TAMBAH_PEMAIN()
{
    throw NoPermissionException();
}

/* Cheat Commands */

void Player::SET()
{

    cout << "\nAtribut:" << endl;
    cout << "1. Money" << endl;
    cout << "2. Body Weight" << endl;

    string input;
    cout << "\nPilih (1-2): ";
    cin >> input;

    int choice = Util::stringToInt(input);

    if (choice == 1)
    {
        cout << "Masukan jumlah uang: ";
        cin >> input;
        this->money = Util::stringToInt(input);
    }
    else if (choice == 2)
    {
        cout << "Masukan berat badan: ";
        cin >> input;
        this->body_weight = Util::stringToInt(input);
    }
    else
    {
        cout << "Gagal!\n"
             << endl;
        return;
    }

    cout << "Sukses!\n"
         << endl;
}

void Player::GIVE()
{

    if (this->inventory.isFull())
    {
        cout << "\nInventory penuh\n"
             << endl;
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

    if (choice < 1 || choice > 3)
    {
        cout << "Gagal!\n"
             << endl;
        return;
    }
    Item *item;

    if (choice == 1)
    {
        cout << "\nDaftar tanaman:" << endl;
        for (int i = 0; i < int(GameConfig::plantConfig.size()); i++)
        {
            cout << i + 1 << ". " << GameConfig::plantConfig[i].getNAME() << endl;
        }
        cout << "\nPilih (1-" << GameConfig::plantConfig.size() << "): ";
        cin >> input;
        choice = Util::stringToInt(input);

        if (choice < 0 || choice > int(GameConfig::plantConfig.size()))
        {
            cout << "Gagal!\n"
                 << endl;
            return;
        }

        item = new Plant(choice);
    }
    else if (choice == 2)
    {
        cout << "\nDaftar hewan:" << endl;
        for (int i = 0; i < int(GameConfig::animalConfig.size()); i++)
        {
            cout << i + 1 << ". " << GameConfig::animalConfig[i].getNAME() << endl;
        }
        cout << "\nPilih (1-" << GameConfig::animalConfig.size() << "): ";
        cin >> input;
        choice = Util::stringToInt(input);

        if (choice < 0 || choice > int(GameConfig::animalConfig.size()))
        {
            cout << "Gagal!\n"
                 << endl;
            return;
        }

        item = new Animal(choice);
    }
    else if (choice == 3)
    {
        cout << "\nDaftar produk:" << endl;
        for (int i = 0; i < int(GameConfig::productConfig.size()); i++)
        {
            cout << i + 1 << ". " << GameConfig::productConfig[i].getNAME() << endl;
        }
        cout << "\nPilih (1-" << GameConfig::productConfig.size() << "): ";
        cin >> input;
        choice = Util::stringToInt(input);

        if (choice < 0 || choice > int(GameConfig::productConfig.size()))
        {
            cout << "Gagal!\n"
                 << endl;
            return;
        }

        item = new Product(choice);
    }

    Player::getCurrentPlayer()->addItem(item);

    cout << "Sukses!\n"
         << endl;
}

void Player::STATS()
{
    this->printStats();
>>>>>>> 5aa2df29836d6847071ac9dac3307fde554d3810
}