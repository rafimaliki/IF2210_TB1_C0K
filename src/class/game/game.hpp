#include "../../std.hpp"
#include "../game_object/item_config/item_config.hpp"

class Game {
    private:
        bool is_running;
        GameConfig config;
        // vector<Player> players;
        // Player& current_player;
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