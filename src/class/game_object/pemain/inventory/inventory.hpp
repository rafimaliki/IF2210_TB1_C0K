#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "../../../../std.hpp"
#include "../../item/plant/plant.hpp"

const string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string SPACE_1 = " ";
const string SPACE_2 = "  ";
const string SPACE_3 = "   ";
const string SPACE_4 = "    ";
const string DASH = "-----";
const string PLUS = "+";
const string PIPE = "|";
const string EQUAL = "=";
const string TITLE = "[ PENYIMPANAN ]";

/* CLASS DEFINITON */

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
        string title;
        int width;
        int height;
        vector<vector<InventoryEntry<T>>> grid;

        Inventory(int width, int height, string title);
        void add(T* item);
        void remove(int x, int y);
        void print();
        void printItem(int x, int y);
        int calcEmptySpace();
};


/* IMPLEMENTATION */

template <class T>
InventoryEntry<T>::InventoryEntry(T* item) : amount(1), item(item), code(item->config.KODE_HURUF){}

template <class T>
InventoryEntry<T>::InventoryEntry() : amount(0), item(nullptr), code("   "){}

template <class T>
Inventory<T>::Inventory(int width, int height, string title) {
    this->title = title;
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
    cout << "Inventory is full!" << endl;
}

template <class T>
void Inventory<T>::remove(int x, int y) {
    // Implementation of remove function
}

template <class T>
void Inventory<T>::print() {

    int total_lenght = this->width * 6 + 1 - (this->title.length() + 4);
    int left_space = total_lenght / 2;
    int right_space = total_lenght - left_space;

    cout << SPACE_4;
    for (int i = 0; i < left_space; i++) {
        cout << EQUAL;
    } cout << "[ " << this->title << " ]";
    for (int i = 0; i < right_space; i++) {
        cout << EQUAL;
    } cout << endl;


    cout << SPACE_4;
    for (int i = 0; i < this->width; i++) {
        cout << SPACE_3 << LETTERS[i] << SPACE_2;
    } cout << endl;

    for (int i = 0; i < this->height; i++){

        cout << SPACE_4;
        for (int j = 0; j < this->width; j++) {
            cout << PLUS << DASH;
        } cout << PLUS << endl;;

        if(i < 9){
            cout << SPACE_1 << 0 << i+1 << SPACE_1;
        } else {
            cout << SPACE_1 << i+1 << SPACE_1;
        }
        for (int j = 0; j < this->width; j++) {
            cout << PIPE << SPACE_1 << this->grid[i][j].code << SPACE_1;
        } cout << PIPE << endl; 
    }
    cout << SPACE_4;
    for (int j = 0; j < this->width; j++) {
        cout << PLUS << DASH;
    } cout << PLUS << endl << endl;

    cout << "Total slot kosong: " << this->calcEmptySpace() << endl;
}

template <class T>
int Inventory<T>::calcEmptySpace() {\
    int count = 0;

    for(int i = 0; i < this->height; i++) {
        for(int j = 0; j < this->width; j++) {
            if (this->grid[i][j].amount == 0) {
                count++;
            }
        }
    }
    return count;
}

template <class T>
void Inventory<T>::printItem(int x, int y) {
    this->grid[x][y].item->print();
}

#endif