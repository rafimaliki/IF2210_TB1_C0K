// File: main.cpp

#include "std.hpp"

#include "class/game/game.hpp"
// #include "class/gameobject/pemain/pemain.hpp"
// #include "class/gameobject/item/item.hpp"

// #include "class/game_object/item/plant/plant.hpp"
// #include "class/game_object/item/animal/animal.hpp"
// #include "class/game_object/player/inventory/inventory.hpp"
// #include "class/game_object/player/player.hpp"
// #include "class/game_object/player/walikota/walikota.hpp"
// #include "class/game_object/player/petani/petani.hpp"
// #include "class/game_object/player/peternak/peternak.hpp"

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
    Item* p1 = new Plant(1);
    Item* p2 = new Plant(2);
    Item* p3 = new Plant(3);
    Item* p4 = new Plant(4);
    Item* a1 = new Animal(1);
    Item* a2 = new Animal(2);
    Item* a3 = new Animal(3);
    Item* a4 = new Animal(4);
 
    // Inventory<Item> inv(GameConfig::miscConfig.INVENTORY_sIZE[0], GameConfig::miscConfig.INVENTORY_sIZE[1], "PENYIMPANAN");
    // Inventory<Item> inv(5, 5, "PENYIMPANAN");
    // inv.add(p1);
    // inv.add(a1);

    p1->setPlanted(true);
    p2->setPlanted(true);
    p3->setPlanted(true);
    a1->setIsInCage(true);
    
    Player::players[1]->addPlant(p1);
    Player::players[1]->addPlant(p2);
    Player::players[1]->addPlant(p3);
    Player::players[1]->addItem(p4);
    Player::players[2]->addAnimal(a1);
    Player::players[2]->addItem(a2);
    Player::players[2]->addItem(a3);
    Player::players[2]->addItem(a4);

    Player::players[1]->getLahan()->remove(0,1);
        

    while (game.isRunning()) {
        
        // Player::players[1]->getLahan().printItem(0, 0);
        // Player::players[1]->getLahan().print();

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