#ifndef PRODUK_HPP
#define PRODUK_HPP


#include "../item/item.hpp"
// Subclass Produk
class Produk : public Item {
public:
    Produk( string nama) : Item("Produk"), nama(nama)
    {
        tambahProduk();
    }
    ~Produk(){}
    void printJenis() override
    {
        cout << "halo, saya item jenis Produk dengan nama " << nama << endl;
    }

private:
    int id;
    string kode_huruf;
    string nama;
    string tipe;
    string tipe_asal;
    int beban_tambah;
    int harga;
};


#endif