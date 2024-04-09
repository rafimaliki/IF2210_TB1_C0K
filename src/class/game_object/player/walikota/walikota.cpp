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
    cout << "Resep bangunan yang ada adalah sebagai berikut." << endl;
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

string Walikota::getType(){
    return "Walikota";
}