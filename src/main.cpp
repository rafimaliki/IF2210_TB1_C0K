// File: main.cpp

#include "class/game/game.hpp"

int main()
{
    Game game;
    game.start();
 
    while (game.isRunning())
    {   
        string command = game.inputCommand();
        game.executeCommand(command);

        game.checkWin();
    }

    return 0;
}