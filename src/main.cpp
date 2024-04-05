// File: main.cpp

#include "std.hpp"
#include "class/game/game.hpp"
#include "class/gameobject/pemain/pemain.hpp"
#include "class/gameobject/item/item.hpp"

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
    game.loadData();

    

    // Pemain player1("Rafi", 0);
    // Pemain player2("Nicho", 1);
    // Pemain player3("Hugo", 2);
    // Pemain player4("Zaki", 3);
    // Pemain player5("Onta", 4);

    // // debugging
    // player1.addHewan("sapi1");
    // player1.addHewan("sapi2");
    // player1.addHewan("sapi3");
    // player1.addTumbuhan("rumput");
    // player1.addProduk("ganja");
    // player1.cetakItem();

    // player2.addHewan("sapi4");
    // player2.addHewan("sapi5");
    // player2.addHewan("sapi6");
    // player2.addTumbuhan("rumput");
    // player2.addProduk("ganja");
    // player2.cetakItem();



    // while (true){
    //     Pemain current_player = Pemain::getCurrentPlayer();
    //     cout << "\n\033[0mGiliran player " << current_player.getName() << endl;

    //     string command;

    //     cout << "> \033[1;1m";
    //     cin >> command;

    //     if (command == "EXIT") {
    //         break;
    //     } else if (command == "NEXT"){
    //         Pemain::nextPlayer();
    //     } else {
    //         cout << "\033[0mCommand not found!" << endl;
    //     }

    //     // player1.cetak_penyimpanan();
    // };

    // Game game;
    // game.start()

    // while(game.isrunning()){

    //     game.getinput();
    //     game.runcommand();

    // }
  
    return 0;
}