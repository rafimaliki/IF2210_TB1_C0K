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




int Item::jumlahTumbuhan = 0;
int Item::jumlahHewan = 0;
int Item::jumlahBangunan = 0;
int Item::jumlahProduk = 0;



#endif
