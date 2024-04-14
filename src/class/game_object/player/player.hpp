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
    virtual Inventory<Animal> *getPeternakan();

    void addItem(Item *item);
    virtual void addPlant(Plant *item);
    virtual void addAnimal(Animal *item);
    void addPlayer(Player *player);
    virtual int getWealth();

    bool haveFood();
    void eat(Item *food);

    virtual string getType();
    int getMoney();
    int getWeight();
    void setMoney(int money);
    string getName();
    string convertLowercase(string str);

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

    /* Operator overloading */
    bool operator<(Player* other);
    bool operator>(Player* other);

    /* Cheat Commands */
    void SET();
    void GIVE();
    void STATS();
    void DELETE();
    void DELETE_INVENTORY();
    void DELETE_LADANG();
    void DELETE_PETERNAKAN();

};

#endif