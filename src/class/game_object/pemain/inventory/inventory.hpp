#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "../../../../std.hpp"
#include "../../item/plant/plant.hpp"

template <class T>
class InventoryEntry
{
    private:
        /* data */
    public:
        int amount; /* hanya 0 dan 1, ada dan tidak, gbs multiple*/
        T* item;
        string code;

        InventoryEntry();
        InventoryEntry(T* item);
};

template <class T>
class Inventory
{
    private:
        /* data */
    public:
        int width;
        int height;
        vector<vector<InventoryEntry<T>>> grid;

        Inventory(int width, int height);
        void add(T* item);
        void remove(int x, int y);
        void print();
};

template <class T>
InventoryEntry<T>::InventoryEntry(T* item) : amount(1), item(item), code(item->config.KODE_HURUF){}

template <class T>
InventoryEntry<T>::InventoryEntry() : amount(0), item(nullptr), code("   "){}

template <class T>
Inventory<T>::Inventory(int width, int height) {
    this->width = width;
    this->height = height;
    this->grid = vector<vector<InventoryEntry<T>>>(height, vector<InventoryEntry<T>>(width, InventoryEntry<T>()));
}

template <class T>
void Inventory<T>::add(T* item) {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            if (this->grid[i][j].amount == 0) {
                this->grid[i][j] = InventoryEntry<T>(item);
                return;
            }
        }
    }
}

template <class T>
void Inventory<T>::remove(int x, int y) {
    // Implementation of remove function
}

template <class T>
void Inventory<T>::print() {

    cout << "Penyimpanan: " << endl;
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            cout << this->grid[i][j].code << "|";
        }
        cout << endl;
    }
}


#endif