#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP


#include "../item/item.hpp"
class Bangunan : public Item
{
public:
    Bangunan() : Item("Bangunan")
    {
        tambahBangunan();
    }
    ~Bangunan();
    void printJenis() override
    {
        cout << "halo, saya item jenis Bangunan dengan nama " << endl;
    }

private:
    int id;
    string kode_huruf;
    int harga;
};


#endif