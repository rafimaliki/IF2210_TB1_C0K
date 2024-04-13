#ifndef GAME_HPP
#define GAME_HPP

#include "../../std.hpp"
#include "../command/command.hpp"
#include "../game_object/item_config/item_config.hpp"
#include "../game_object/item/plant/plant.hpp"
#include "../game_object/item/animal/animal.hpp"
#include "../game_object/item/bangunan/bangunan.hpp"
#include "../game_object/item/product/product.hpp"
#include "../game_object/player/player.hpp"
#include "../game_object/player/walikota/walikota.hpp"
#include "../game_object/player/petani/petani.hpp"
#include "../game_object/player/peternak/peternak.hpp"
#include "../file/simpan/simpan.hpp"
#include "../file/muat/muat.hpp"

class Game
{
private:
    bool is_running;
    string command;
    
public:
    Game();

    void start();
    void startNewGame();

    void inputCommand();
    void executeCommand();
    void loadGameData();

    void checkWin();
    void printWinner();

    bool isRunning();

    /* MUAT */ /* BELUM IMPLEMENTASI */
               // void MUAT();
};

#endif