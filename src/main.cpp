// File: main.cpp

#include "std.hpp"

#include "class/game/game.hpp"
// #include "class/gameobject/pemain/pemain.hpp"
// #include "class/gameobject/item/item.hpp"

#include "class/game_object/item/plant/plant.hpp"

int main() {

    cout << "\033[2J\033[1;1H";

    cout << "Testing Git Ignore!";
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
   Plant p1(1);
   Plant p2(2);
   cout << endl;

   while (game.isRunning()) {

        
        Plant::plants[0]->print();
        cout << endl;
        Plant::plants[1]->print();
        
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