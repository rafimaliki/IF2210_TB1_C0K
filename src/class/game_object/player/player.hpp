#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../../std.hpp"
#include "playerException.hpp"
#include "inventory/inventory.hpp"

#include "../item/item.hpp"
#include "../item/plant/plant.hpp"
#include "../item/animal/animal.hpp"
#include "../item/product/product.hpp"
#include "../toko/toko.hpp"
// #include "../item/animal/animal.hpp"
// #include "../item/animal/.hpp"

class Player
{
protected:
    int id;
    string name;
    int money;
    Inventory<Item> inventory;
    int body_weight;

public:
    static vector<Player *> players;
    static int current_player_idx;
    static int player_count;

    Player(string name, int money, int body_weight);
    virtual ~Player() = 0;

    void printStats();
    void printInventory();
    static Player *getCurrentPlayer();

    virtual void printLahan();
    virtual void printPeternakan();
    Inventory<Item> *getInventory();
    virtual Inventory<Plant> *getLadang();

    void addItem(Item *item);
    virtual void addPlant(Plant *item);
    virtual void addAnimal(Item *item);

    bool haveFood();
    void eat(Item *food);

    virtual string getType();
    int getMoney();
    void setMoney(int money);
    string getName();

    /* Game command related methods */
    virtual void NEXT();
    virtual void CETAK_PENYIMPANAN();
    virtual void PUNGUT_PAJAK();
    virtual void CETAK_LADANG();
    virtual void CETAK_PETERNAKAN();
    virtual void TANAM();
    virtual void TERNAK();
    virtual void BANGUN();
    virtual void MAKAN();
    virtual void KASIH_MAKAN();
    virtual void BELI();
    virtual void JUAL();
    virtual void PANEN();
    // virtual void MUAT();
    virtual void SIMPAN();
    virtual void TAMBAH_PEMAIN();

    /* Cheat Commands */
    virtual void SET();
    virtual void GIVE();
    virtual void STATS();

    static void next();
};

#endif