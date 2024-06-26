#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../../std.hpp"
#include "commandException.hpp"
#include "../game_object/player/player.hpp"
#include "../game/game.hpp"
#include "../file/simpan/simpan.hpp"

class Command {
    private:
        static map<string, void (Player::*)()> commands;
    
    public:
        static void addCommand(const string& command, void (Player::*function)());
        static void initCommand();
        static void initCheat();
        static void execute(const string& command);
};

#endif

