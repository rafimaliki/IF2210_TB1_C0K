#ifndef ITEM_HPP
#define ITEM_HPP

#include "../../../std.hpp"

#include <map> 

class Item
{
public:
    static int jumlahTumbuhan;
    static int jumlahHewan;
    static int jumlahBangunan;
    static int jumlahProduk;
    Item(const std::string &name) : tipe_objek(name) {}
    virtual ~Item() {} 

    string getJenis() const
    {
        return tipe_objek;
    }
    int getJumlahTumbuhan() const {
        return jumlahTumbuhan;
    }
    int getJumlahHewan() const {
        return jumlahHewan;
    }
    int getJumlahProduk() const {
        return jumlahProduk;
    }
    int getJumlahBangunan() const {
        return jumlahBangunan;
    }


    virtual void printJenis()
    {
        cout << "halo saya item" << endl;
    }

private:
    string tipe_objek;

protected:
    static void tambahTumbuhan()
    {
        jumlahTumbuhan++;
    }

    static void tambahHewan()
    {
        jumlahHewan++;
    }

    static void tambahBangunan()
    {
        jumlahBangunan++;
    }

    static void tambahProduk()
    {
        jumlahProduk++;
    }
};


class ItemMap
{
public:
    ItemMap() : last_key(0) {}
    ~ItemMap(){
        
    }

    void addItem(Item *item)
    {
        itemMap[++last_key] = item;
    }

    // Nanti bisa isi key bolong pake method validator ..

    void removeItem(int key)
    {
        auto it = itemMap.find(key);
        if (it != itemMap.end())
        {
            delete it->second;
            itemMap.erase(it);
        }
    }

    void displayItems() const
    {
        for (const auto &pair : itemMap)
        {
            std::cout << "Key: " << pair.first << ", Jenis: " << pair.second->getJenis() << std::endl;
        }
    }
    vector<int> getTypeId(string type) const
    {
        vector<int> vt;
        for (auto &pair : itemMap)
        {
            int key = pair.first;
            if (pair.second->getJenis() == type)
            {
                vt.push_back(key);
            }
        }
        return vt;
    }
    void printAllTypeId()
    {
        cout << "id Tumbuhan" << endl;
        vector<int> vt = getTypeId("Tumbuhan");
        for (std::vector<int>::size_type i = 0; i < vt.size(); i++)// pake size_type, kalo gk pake nanti warning
        {
            cout << vt[i] << " ";
        }
        cout << endl;
        vt.clear();
        cout << "id Hewan" << endl;
        vt = getTypeId("Hewan");
        for (std::vector<int>::size_type i = 0; i < vt.size(); i++)// pake size_type, kalo gk pake nanti warning
        {
            cout << vt[i] << " ";
        }
        cout << endl;
        vt.clear();
        cout << "id Bangunan" << endl;
        vt = getTypeId("Bangunan");
        for (std::vector<int>::size_type i = 0; i < vt.size(); i++)// pake size_type, kalo gk pake nanti warning
        {
            cout << vt[i] << " ";
        }
        cout << endl;
        vt.clear();
        cout << "id Produk" << endl;
        vt = getTypeId("Produk");
        for (std::vector<int>::size_type i = 0; i < vt.size(); i++) // pake size_type, kalo gk pake nanti warning
        {
            cout << vt[i] << " ";
        }
        cout << endl;
    }

private:
    std::map<int, Item *> itemMap;
    int last_key;
};



//DISCLAIMER : SEMENTARA SUBCLASS ITEM DISINI SEMUA, INCLUDE GW GK JELAS - Hugo
//DISCLAIMER : SEMENTARA SUBCLASS ITEM DISINI SEMUA, INCLUDE GW GK JELAS - Hugo
//DISCLAIMER : SEMENTARA SUBCLASS ITEM DISINI SEMUA, INCLUDE GW GK JELAS - Hugo


int Item::jumlahTumbuhan = 0;
int Item::jumlahHewan = 0;
int Item::jumlahBangunan = 0;
int Item::jumlahProduk = 0;

// class Bangunan : public Item
// {
// public:
//     Bangunan() : Item("Bangunan")
//     {
//         tambahBangunan();
//     }
//     ~Bangunan();
//     void printJenis() override
//     {
//         cout << "halo, saya item jenis Bangunan dengan nama " << endl;
//     }

// private:
//     int id;
//     string kode_huruf;
//     int harga;
// };

// class Produk : public Item {
// public:
//     Produk() : Item("Produk") , nama("Unnamed"){}
//     Produk( string nama) : Item("Produk"), nama(nama) 
//     {
//         tambahProduk();
//     }
//     ~Produk();
//     void printJenis() override
//     {
//         cout << "halo, saya item jenis Produk dengan nama " << nama << endl;
//     }

// private:
//     int id;
//     string kode_huruf;
//     string nama;
//     string tipe;
//     string tipe_asal;
//     int beban_tambah;
//     int harga;
// };
// class Tumbuhan : public Item
// {
// public:
//     Tumbuhan( string nama) : Item("Tumbuhan"), nama(nama)
//     {
//         tambahTumbuhan();
//     }
//     ~Tumbuhan();
//     void printJenis() override
//     {
//         cout << "halo, saya item jenis Tumbuhan dengan nama " << nama << endl;
//     }

// private:
//     int id;
//     string kode_huruf;
//     string nama;
//     int waktu_panen;
//     int umur_sekarang;
//     int harga;
// };
// class Hewan : public Item
// {
// public:
//     Hewan( string nama) : Item("Hewan"), nama(nama)
//     {
//         tambahHewan();
//     }
//     ~Hewan();
//     void printJenis() override
//     {
//         cout << "halo, saya item jenis Hewan dengan nama " << nama << endl;
//     }

// private:
//     int id;
//     string kode_huruf;
//     string nama;
//     string tipe;
//     int berat_panen;
//     int harga;
// };

#endif
