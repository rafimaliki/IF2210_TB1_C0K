#include "walikota.hpp"

Walikota::Walikota(string name, int money, int body_weight) : Player(name, money, body_weight){}

/* Game command related methods */

void Walikota::PUNGUT_PAJAK(){
    int tax, total_taxes = 0, playerCurrMoney, counter = 1;
    cout << "Cring cring cring..." << endl;
    cout << "Pajak sudah dipungut!" << endl << endl;

    cout << "Berikut adalah detil dari pemungutan pajak:" << endl;
    for (int i = 0; i < player_count; i++){
        if (players[i]->getType() != "Walikota"){
            playerCurrMoney = players[i]->getMoney();
            tax = HITUNG_PAJAK(i);
            if (playerCurrMoney - tax <= 0){
                tax = playerCurrMoney;
            }
            total_taxes += tax;
            cout << "   " << counter << ". " << players[i]->getName() << " - " << players[i]->getType() << ": " << tax << " gulden" << endl;
            players[i]->setMoney(playerCurrMoney - tax);
            counter++;
        }
    }
    cout << "Negara mendapatkan pemasukan sebesar " << total_taxes << " gulden." << endl;
    cout << "Gunakan dengan baik dan jangan dikorupsi ya!" << endl << endl;

    setMoney(money + total_taxes);
}

void Walikota::BANGUN(){  /* BELUM IMPLEMENTASI */
    string namaBangunan, cekLanjut;
    vector<Bangunan*> daftar_bangunan = getDaftarBangunan();
    bool valid = false, lanjut = false;
    int price = 0;

    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
    showRecipe(daftar_bangunan);

    while (!valid){
        try {
            cout << "Apakah ingin melanjutkan membangun bangunan? (YA/TIDAK)" << endl;
            cin >> cekLanjut;
            if (cekLanjut == "YA"){
                namaBangunan = inputNama(daftar_bangunan);
                price = getBangunanPrice(namaBangunan, daftar_bangunan);
                useMoney(price);
                useIngredients(namaBangunan, daftar_bangunan);
                bangunBangunan(namaBangunan, daftar_bangunan);
                cout << namaBangunan << " berhasil dibangun dan telah menjadi hak milik walikota!" << endl << endl;
            } else {
                cout << "Batal membangun bangunan..." << endl << endl;
            }
            valid = true;
        } catch (InvalidBuildingNameException& e){
            cout << e.what() << endl << endl;
        } catch (NotEnoughMoneyException& e){
            cout << e.what() << endl << endl;
        } catch (NotEnoughItemException& e){
            cout << e.what() << endl << endl;
            cancelUseMoney(price);
        }
    }
}

void Walikota::TAMBAH_PEMAIN(){  /* BELUM IMPLEMENTASI */
    cout << YELLOW << "\nCommand TAMBAH_PEMAIN belum diimplementasikan!\n" << RESET << endl;
}

int Walikota::HITUNG_PAJAK(int idx){
    int tax;
    int wealth = players[idx]->getMoney();
    Inventory<Item>* playerInventory = players[idx]->getInventory();
    // Loop setiap inventory pemain
    for (int i = 0; i < playerInventory->height; i++){
        for (int j = 0; j < playerInventory->width; j++){
            if (!playerInventory->isEmpty(i, j)){
                wealth += playerInventory->getItem(i, j)->getPRICE();
            }
        }
    }

    int KKP = wealth;
    if (players[idx]->getType() == "Petani"){
        KKP -= 13;
    } else {
        KKP -= 11;
    }
    if (KKP <= 6){
        tax = KKP * 0.05;
    } else if ((KKP > 6) && (KKP <= 25)){
        tax = KKP * 0.15;
    } else if ((KKP > 25) && (KKP <= 50)){
        tax = KKP * 0.25;
    } else if ((KKP > 50) && (KKP <= 500)){
        tax = KKP * 0.3;
    } else {
        tax = KKP * 0.35;
    }
    return tax;
}

vector<Bangunan*> Walikota::getDaftarBangunan(){
    return Bangunan::daftar_bangunan;
}

void Walikota::showRecipe(vector<Bangunan*> daftar_bangunan){
    for (int i = 0; i < daftar_bangunan.size(); i++){
        cout << (i + 1) << ". " << daftar_bangunan[i]->getConfig()->getNAME() << " ";
        cout << "(";
        cout << daftar_bangunan[i]->getConfig()->getPRICE() << " gulden";
        for (int j = 0; j < daftar_bangunan[i]->getConfig()->getINGREDIENTS().size(); j++){
            cout << ", " << daftar_bangunan[i]->getConfig()->getINGREDIENTS()[j].getNAME() << " " << daftar_bangunan[i]->getConfig()->getINGREDIENTS()[j].getQUANTITY();
        }
        cout << ")" << endl;
    }
    cout << endl;
}

string Walikota::inputNama(vector<Bangunan*> daftar_bangunan){
    bool found = false;
    string nama;
    cout << "Bangunan yang ingin dibangun: ";
    cin >> nama;
    for (int i = 0; i < daftar_bangunan.size(); i++){
        if (daftar_bangunan[i]->getConfig()->getNAME() == nama){
            found = true;
        }
    }
    
    if (found){
        return nama;
    } else {
        throw InvalidBuildingNameException();
    }
}

int Walikota::getBangunanPrice(string nama, vector<Bangunan*> daftar_bangunan){
    for (int i = 0; i < daftar_bangunan.size(); i++){
        if (daftar_bangunan[i]->getConfig()->getNAME() == nama){
            return daftar_bangunan[i]->getConfig()->getPRICE();
        }
    }
    return -1;
}

void Walikota::useMoney(int amount){
    if (money < amount){
        throw NotEnoughMoneyException();
    } else {
        money -= amount;
    }
}

void Walikota::cancelUseMoney(int amount){
    money += amount;
}

void Walikota::useIngredients(string nama, vector<Bangunan*> daftar_bangunan){
    int idx;
    vector<string> ingredient_name;
    vector<int> ingredient_quantity, available_ingredient;
    vector<vector<int>> location_list;;
    bool notEnough = false;

    for (int i = 0; i < daftar_bangunan.size(); i++){
        if (daftar_bangunan[i]->getConfig()->getNAME() == nama){
            idx = i;
        }
    }


    for (int i = 0; i < daftar_bangunan[idx]->getConfig()->getINGREDIENTS().size(); i++){
        ingredient_name.push_back(daftar_bangunan[idx]->getConfig()->getINGREDIENTS()[i].getNAME());
        ingredient_quantity.push_back(daftar_bangunan[idx]->getConfig()->getINGREDIENTS()[i].getQUANTITY());
    }

    for (int i = 0; i < ingredient_quantity.size(); i++){
        available_ingredient.push_back(0);
    }

    for (int i = 0; i < inventory.height; i++){
        for (int j = 0; j < inventory.width; j++){
            if (inventory.grid[i][j].getAmount() != 0){
                for (int k = 0; k < ingredient_name.size(); k++){
                    if (inventory.grid[i][j].getItem()->getNAME() == ingredient_name[k]){
                        available_ingredient[k]++;
                        location_list.push_back({i, j});
                    }
                }
            }
        }
    }

    for (int i = 0; i < ingredient_quantity.size(); i++){
        if (available_ingredient[i] - ingredient_quantity[i] < 0){
            notEnough = true;
        }
    }

    if (notEnough){
        cout << "Kamu tidak punya sumber daya yang cukup! Masih memerlukan ";
        for (int i = 0; i < available_ingredient.size(); i++){
            if (available_ingredient[i] - ingredient_quantity[i] < 0){
                cout << (ingredient_quantity[i] - available_ingredient[i]) << " " << ingredient_name[i];
            } else {
                cout << "0 " << ingredient_name[i];
            }

            if (i != available_ingredient.size() - 1){
                cout << ", ";
            } else {
                cout << "!" << endl;
            }
        }
        throw NotEnoughItemException();
    } else {
        for (int i = 0; i < location_list.size(); i++){
            if ((location_list[i][0] != -1) && (location_list[i][1] != -1)){
                for (int j = 0; j < ingredient_name.size(); j++){
                    if ((inventory.grid[location_list[i][0]][location_list[i][1]].getItem()->getNAME() == ingredient_name[j]) && (ingredient_quantity[j] > 0)){
                        ingredient_quantity[j]--;
                        inventory.remove(location_list[i][0], location_list[i][1]);
                        location_list[i][0] = -1;
                        location_list[j][0] = -1;
                        break;
                    }
                }
            }
        }
    }
}

void Walikota::bangunBangunan(string nama, vector<Bangunan*> daftar_bangunan){
    int idx;
    for (int i = 0; i < daftar_bangunan.size(); i++){
        if (daftar_bangunan[i]->getConfig()->getNAME() == nama){
            idx = i;
        }
    }
    Item* bangunanBaru = new Bangunan(idx + 1);
    addItem(bangunanBaru);
}

string Walikota::getType(){
    return "Walikota";
}