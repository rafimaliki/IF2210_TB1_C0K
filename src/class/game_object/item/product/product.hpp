#ifndef PRODUK_HPP
#define PRODUK_HPP

#include "../item.hpp"

class Product : public Item
{
private:
    /* data */
    ItemConfig* config;
public:

    static vector<Product*> products;
    static int productCount;

    Product(int ID);
    void print();

    void printKODE_HURUF();
    ItemConfig* getConfig();
    string getTYPE();
    int getADDED_WEIGHT();
};


#endif