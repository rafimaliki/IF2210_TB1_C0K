#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "../../../../std.hpp"
#include "../item.hpp"
#include "../../item_config/item_config.hpp"

class Bangunan : public Item
{
private:
    ItemConfig* config;

public:
    static vector<Bangunan*> daftar_bangunan;
    static int bangunanCount;

    Bangunan(int ID);
    void print();
    ItemConfig* getConfig();
    void printKodeHuruf();
    string getType();

};


#endif