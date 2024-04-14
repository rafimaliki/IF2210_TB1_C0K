// File: main.cpp

#include "class/game/game.hpp"

int main()
{   
    Game HarvestMoon; 

    HarvestMoon.start();

    while (HarvestMoon.isRunning())
    {       
        HarvestMoon.inputCommand();
        HarvestMoon.executeCommand();
        HarvestMoon.checkWin();
    }

    return 0;
}