// File: main.cpp

#include "class/game/game.hpp"

int main()
{

    Game game;
    game.start();


    /* players[0] = Petani1 */

    Item* P0_a1 = new Plant(1); Player::players[0]->addItem(P0_a1);
    Item* P0_a2 = new Plant(2); Player::players[0]->addItem(P0_a2);
    Item* P0_a3 = new Plant(2); Player::players[0]->addItem(P0_a3);
    Item* P0_a4 = new Plant(4); Player::players[0]->addItem(P0_a3);

    Plant* P0_a5 = new Plant(5, 7); P0_a5->setPlanted(true); Player::players[0]->addPlant(P0_a5);
    Plant* P0_a6 = new Plant(5); P0_a6->setPlanted(true); Player::players[0]->addPlant(P0_a6);
    Plant* P0_a7 = new Plant(7, 7); P0_a7->setPlanted(true); Player::players[0]->addPlant(P0_a7);

    Item* P0_pr1 = new Product(1); Player::players[0]->addItem(P0_pr1);
    Item* P0_pr2 = new Product(2); Player::players[0]->addItem(P0_pr2);
    Item* P0_pr3 = new Product(3); Player::players[0]->addItem(P0_pr3);
    Item* P0_b1 = new Bangunan(2); Player::players[0]->addItem(P0_b1);


    /* Players[1] = Peternak1 */

    Item* p1_a1 = new Animal(1); Player::players[1]->addItem(p1_a1);
    Item* p1_a2 = new Animal(2); Player::players[1]->addItem(p1_a2);
    Item* p1_a3 = new Animal(2); Player::players[1]->addItem(p1_a3);
    Item* p1_a4 = new Animal(4); Player::players[1]->addItem(p1_a3);

    Animal* p1_a5 = new Animal(5); p1_a5->setIsInCage(true); Player::players[1]->addAnimal(p1_a5);
    Animal* p1_a6 = new Animal(5, 15); p1_a6->setIsInCage(true); Player::players[1]->addAnimal(p1_a6);
    Animal* p1_a7 = new Animal(7, 15); p1_a7->setIsInCage(true); Player::players[1]->addAnimal(p1_a7);

    Item* p1_pr1 = new Product(6); Player::players[1]->addItem(p1_pr1);
    Item* p1_pr2 = new Product(7); Player::players[1]->addItem(p1_pr2);
    Item* p1_pr3 = new Product(16); Player::players[1]->addItem(p1_pr3);
    Item* p1_b1 = new Bangunan(1); Player::players[1]->addItem(p1_b1);


    /* Players[2] = Walikota */

    Item* p2_pr1 = new Product(4); Player::players[2]->addItem(p2_pr1);
    Item* p2_pr2 = new Product(5); Player::players[2]->addItem(p2_pr2);
    Item* p2_pr3 = new Product(8); Player::players[2]->addItem(p2_pr3);
    Item* p2_b1 = new Bangunan(3); Player::players[2]->addItem(p2_b1);
    Item* p2_b2 = new Bangunan(4); Player::players[2]->addItem(p2_b2);


    /* Toko */

    Item* t_p1 = new Product(1); Toko::addItem(t_p1);
    Item* t_p2 = new Product(1); Toko::addItem(t_p2);
    Item* t_p3 = new Product(2); Toko::addItem(t_p3);
    Item* t_p4 = new Bangunan(4); Toko::addItem(t_p4);

    while (game.isRunning())
    {   
        string command = game.inputCommand();
        game.executeCommand(command);

        game.checkWin();
    }

    return 0;
}