#ifndef HEWAN_HPP
#define HEWAN_HPP


#include "../item/item.hpp"
class Hewan : public Item
{
public:
    Hewan( string nama) : Item("Hewan"), nama(nama)
    {
        tambahHewan();
    }
    void printJenis() override
    {
        cout << "halo, saya item jenis Hewan dengan nama " << nama << endl;
    }

private:
    int id;
    string kode_huruf;
    string nama;
    string tipe;
    int berat_panen;
    int harga;
};


#endif