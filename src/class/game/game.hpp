#include "../../std.hpp"
#include "../game_object/item_config/item_config.hpp"
#include "../game_object/item/plant/plant.hpp"
#include "../game_object/item/animal/animal.hpp"
#include "../game_object/player/player.hpp"


class Game {
    private:
        bool is_running;
        // vector<Player> players;
        // Player& current_player;
        
        // GameConfig config; // GameConfig gw ubah jadi static member class GameConfig aja biar gak circular include
    public:
        Game();

        void start();
        void loadConfig();
        void loadSaveFile();

        string inputCommand();
        void executeCommand(string command);

        void checkWin();
        void printWinner();

        bool isRunning();
};