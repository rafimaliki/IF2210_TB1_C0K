#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../../std.hpp"
#include "inventory/inventory.hpp"
#include "../item/item.hpp"
// #include "../item/animal/animal.hpp"
// #include "../item/animal/.hpp"

class Player {
protected:
    int id;
    string name;
    int money;
    Inventory<Item> inventory;
    int body_weight;
public:
    static vector<Player*> players;
    static int current_player_idx;
    static int player_count;

    Player(string name, int money, int body_weight);

    void printStats();
    void printInventory();
    static Player* getCurrentPlayer();
    static void next();

    virtual void printLahan();
    virtual Inventory<Item> getLahan();
    virtual void printPeternakan();

    virtual void addPlant(Item* item);
    virtual void addAnimal(Item* item);

};

#endif