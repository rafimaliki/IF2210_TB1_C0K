// File: main.cpp

#include "class/game/game.hpp"

int main() {

    cout << "\033[2J\033[1;1H";
    cout << "\n                                                                                                      \n"
            " ██░ ██  ▄▄▄       ██▀███   ██▒   █▓▓█████   ██████ ▄▄▄█████▓    ███▄ ▄███▓ ▒█████   ▒█████   ███▄    █ \n"
            "▓██░ ██▒▒████▄    ▓██ ▒ ██▒▓██░   █▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒   ▓██▒▀█▀ ██▒▒██▒  ██▒▒██▒  ██▒ ██ ▀█   █ \n"
            "▒██▀▀██░▒██  ▀█▄  ▓██ ░▄█ ▒ ▓██  █▒░▒███   ░ ▓██▄   ▒ ▓██░ ▒░   ▓██    ▓██░▒██░  ██▒▒██░  ██▒▓██  ▀█ ██▒\n"
            "░▓█ ░██ ░██▄▄▄▄██ ▒██▀▀█▄    ▒██ █░░▒▓█  ▄   ▒   ██▒░ ▓██▓ ░    ▒██    ▒██ ▒██   ██░▒██   ██░▓██▒  ▐▌██▒\n"
            "░▓█▒░██▓ ▓█   ▓██▒░██▓ ▒██▒   ▒▀█░  ░▒████▒▒██████▒▒  ▒██▒ ░    ▒██▒   ░██▒░ ████▓▒░░ ████▓▒░▒██░   ▓██░\n"
            " ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒▓ ░▒▓░   ░ ▐░  ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░      ░ ▒░   ░  ░░ ▒░▒░▒░ ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ \n"
            " ▒ ░▒░ ░  ▒   ▒▒ ░  ░▒ ░ ▒░   ░ ░░   ░ ░  ░░ ░▒  ░ ░    ░       ░  ░      ░  ░ ▒ ▒░   ░ ▒ ▒░ ░ ░░   ░ ▒░\n"
            " ░  ░░ ░  ░   ▒     ░░   ░      ░░     ░   ░  ░  ░    ░         ░      ░   ░ ░ ░ ▒  ░ ░ ░ ▒     ░   ░ ░ \n"
            " ░  ░  ░      ░  ░   ░           ░     ░  ░      ░                     ░       ░ ░      ░ ░           ░ \n"
            "                                ░                                                                       \n";

    Game game;
    game.start();

    /* 
    di dalam game.start() manggil 
        game.loadConfig();
        game.loadSaveFile();
        dan ngubah state Running ke true
    */

    cout << endl;
    Plant* p1 = new Plant(1);
    Item* p4 = new Plant(4);
    
    Plant* p2 = new Plant(2);
    Plant* p3 = new Plant(3);
    Item* a1 = new Animal(1);
    Item* a2 = new Animal(2);
    Item* a3 = new Animal(3);
    Item* a4 = new Animal(4);

    Item* pr1 = new Product(1);
    Item* pr2 = new Product(3);
    Item* pr3 = new Product(6);
    Item* pr4 = new Product(7);
    Item* pr5 = new Product(17);

    Item* bg1 = new Bangunan(1);
    Item* bg2 = new Bangunan(2);
    Item* bg3 = new Bangunan(3);
    Item* bg4 = new Bangunan(4);

    // cout << "Id: " << p1->getID() << endl;
    // cout << "Kode Huruf: " << p1->getKODE_HURUF() << endl;
    // cout << "Nama: " << p1->getNAME() << endl;
    // cout << "Harga: " << p1->getPRICE() << endl;
    // cout << "Tipe: " << p1->getTYPE() << endl;
    // cout << "Durasi Panen: " << p1->getDURATION_TO_HARVEST() << endl;
    // cout << endl;
    // cout << "Id: " << a1->getID() << endl;
    // cout << "Kode Huruf: " << a1->getKODE_HURUF() << endl;
    // cout << "Nama: " << a1->getNAME() << endl;
    // cout << "Harga: " << a1->getPRICE() << endl;
    // cout << "Tipe: " << a1->getTYPE() << endl;
    // cout << "Berat harvest: " << a1->getWEIGHT_TO_HARVEST() << endl;
    // cout << endl;
    // cout << "Id: " << pr1->getID() << endl;
    // cout << "Kode Huruf: " << pr1->getKODE_HURUF() << endl;
    // cout << "Nama: " << pr1->getNAME() << endl;
    // cout << "Harga: " << pr1->getPRICE() << endl;
    // cout << "Tipe: " << pr1->getTYPE() << endl;
    // cout << "Origin: " << pr1->getORIGIN() << endl;
    // cout << "Added Weight: " << pr1->getADDED_WEIGHT() << endl;

    // TOKO

    // PETANI BELI TUMBUHAN ID 1

    // item* p = new Plant(1); -> masukin ke Inventory Petani

    // saat petani mau TANAM 

    // get id = 1
    // plant* p = new Plant(1); -> masukin ke ladang 
 
    // Inventory<Item> inv(GameConfig::miscConfig.INVENTORY_sIZE[0], GameConfig::miscConfig.INVENTORY_sIZE[1], "PENYIMPANAN");
    // Inventory<Item> inv(5, 5, "PENYIMPANAN");
    // inv.add(p1);
    // inv.add(a1);

    p1->setPlanted(true);
    p2->setPlanted(true);
    p3->setPlanted(true);
    a1->setIsInCage(true);

    Player::players[0]->addItem(pr1);
    Player::players[0]->addItem(pr2);
    Player::players[0]->addItem(pr3);
    Player::players[0]->addItem(pr4);
    Player::players[0]->addItem(pr5);
    
    Player::players[1]->addPlant(p1);
    Player::players[1]->addPlant(p2);
    Player::players[1]->addPlant(p3);
    Player::players[1]->addItem(p4);

    Player::players[2]->addAnimal(a1);
    Player::players[2]->addItem(a2);
    Player::players[2]->addItem(a3);
    Player::players[2]->addItem(a4);

    Player::players[1]->getLadang()->remove(0,1);

    while (game.isRunning()) {

        // cout << "is food: " << pr1->isFood() << endl;
        // cout << "is food: " << pr2->isFood() << endl;
        // cout << "is food: " << pr3->isFood() << endl;

        // pr1->print();
        // pr2->print();
        // pr3->print();
        
        // Player::players[1]->getLadang()->printItem(0, 0);
        // Player::players[1]->getLadang()->getItem("A01")->print();
        // Player::players[1]->getLadang()->getItem("B01")->print();
        // Player::players[1]->getLadang()->print();

        /* 
                            NOTES
            Khusus plant dan animal perlu atribut tambahan yang membedakan apakah
            dia udah di tanam/peternakan atau di inventory doang

            Kalo di tanam/peternakan, dia bakal nge-age/bisa dikasi makan setiap turn
            Kalo di inventory, dia gbs nge-age/dikasi makan
        */

        
        // Plant::plants[0]->print();
        // cout << endl;
        // Plant::plants[1]->print();

        // inv.print();
        // cout << "\nInventory[0,0]: " << endl;
        // inv.printItem(0, 0);
        // cout << "\nInventory[0,1]: " << endl;
        // inv.printItem(0, 1);

        game.executeCommand(game.inputCommand());
        game.checkWin();

        /* Kalo win bakal ngubah state Running ke false dan set variabel winner : player& */


        /* 
           Tes print config dari main 
           Semua file yang include item_config.hpp harusnya bisa akses ini 
        */

        // cout << "\n\x1b[32mRECIPE Config: \x1b[0m\n" << endl;
        // for (int i = 0; i < int(GameConfig::recipeConfig.size()) ; i++){
        //     GameConfig::recipeConfig[i].print();
        // }
   }

   game.printWinner();
  
    return 0;
}