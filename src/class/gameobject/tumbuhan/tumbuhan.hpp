#ifndef TUMBUHAN_HPP
#define TUMBUHAN_HPP

#include "../item/item.hpp"

class Tumbuhan : public Item
{
public:
    Tumbuhan(string nama) : Item("Tumbuhan"), nama(nama)
    {
        tambahTumbuhan();
    }
    void printJenis() override
    {
        cout << "halo, saya item jenis Tumbuhan dengan nama " << nama << endl;
    }

private:
    int id;
    string kode_huruf;
    string nama;
    int waktu_panen;
    int umur_sekarang;
    int harga;
};

#endif