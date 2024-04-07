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

};

#endif