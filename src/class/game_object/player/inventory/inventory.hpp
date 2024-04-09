#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "../../../../std.hpp"
#include "../../item/plant/plant.hpp"
#include "inventoryException.hpp"

const string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string SPACE_1 = " ";
const string SPACE_2 = "  ";
const string SPACE_3 = "   ";
const string SPACE_4 = "    ";
const string DASH = "-----";
const string PLUS = "+";
const string PIPE = "|";
const string EQUAL = "=";

/* CLASS DEFINITON */

template <class T>
class InventoryEntry
{
private:
    int amount; /* hanya 0 dan 1, ada dan tidak, gbs multiple*/
    T *item;

public:
    InventoryEntry();
    InventoryEntry(T *item);

    int getAmount() { return this->amount; }
    T *getItem() { return this->item; }
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

    Inventory();
    Inventory(int width, int height, string title);

    void add(T *item);
    void add(T *item, string idx);

    void remove(int i, int j);
    void remove(string idx);

    void print();
    void printItem(int i, int j);

    bool isEmpty(int j, int i);
    bool isEmpty(string idx);

    T *getItem(int i, int j);
    T *getItem(string idx);

    int calcEmptySpace();
    bool isFull();
};

/* IMPLEMENTATION */

template <class T>
InventoryEntry<T>::InventoryEntry(T *item) : amount(1), item(item) {}

template <class T>
InventoryEntry<T>::InventoryEntry() : amount(0), item(nullptr) {}

template <class T>
Inventory<T>::Inventory()
{
    this->title = "";
    this->width = 0;
    this->height = 0;
    this->grid = vector<vector<InventoryEntry<T>>>(0, vector<InventoryEntry<T>>(0, InventoryEntry<T>()));
}

template <class T>
Inventory<T>::Inventory(int width, int height, string title)
{
    this->title = title;
    this->width = width;
    this->height = height;
    this->grid = vector<vector<InventoryEntry<T>>>(height, vector<InventoryEntry<T>>(width, InventoryEntry<T>()));
}

template <class T>
void Inventory<T>::add(T *item)
{
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            if (this->grid[i][j].getAmount() == 0)
            {
                this->grid[i][j] = InventoryEntry<T>(item);
                return;
            }
        }
    }
    cout << "Inventory is full!" << endl;
}

template <class T>
void Inventory<T>::add(T *item, string idx)
{
    try
    {
        int j = idx[0] - 'A';
        int i = stoi(idx.substr(1)) - 1;

        if (i >= this->height || j >= this->width || i < 0 || j < 0)
        {
            throw IndexNotValidException();
        }

        if (this->grid[i][j].getAmount() == 0)
        {
            this->grid[i][j] = InventoryEntry<T>(item);
        }
        else
        {
            cout << "Slot sudah terisi!" << endl;
        }
    }
    catch (...)
    {
        throw IndexNotValidException();
    }
}

template <class T>
void Inventory<T>::remove(int i, int j)
{
    if (this->isEmpty(i, j))
    {
        cout << "Slot kosong!" << endl;
    }
    else
    {
        this->grid[i][j] = InventoryEntry<T>();
    }
}

template <class T>
void Inventory<T>::remove(string idx)
{

    try
    {
        int j = idx[0] - 'A';
        int i = stoi(idx.substr(1)) - 1;

        if (i >= this->height || j >= this->width || i < 0 || j < 0)
        {
            throw IndexNotValidException();
        }

        this->remove(i, j);
    }
    catch (...)
    {
        throw IndexNotValidException();
    }
}

template <class T>
void Inventory<T>::print()
{

    int total_length = this->width * 6 + 1 - (this->title.length() + 4);
    int left_space = total_length / 2;
    int right_space = total_length - left_space;

    cout << endl
         << SPACE_4;
    for (int i = 0; i < left_space; i++)
    {
        cout << EQUAL;
    }
    cout << "[ " << this->title << " ]";
    for (int i = 0; i < right_space; i++)
    {
        cout << EQUAL;
    }
    cout << endl;

    cout << SPACE_4;
    for (int i = 0; i < this->width; i++)
    {
        cout << SPACE_3 << LETTERS[i] << SPACE_2;
    }
    cout << endl;

    for (int i = 0; i < this->height; i++)
    {

        cout << SPACE_4;
        for (int j = 0; j < this->width; j++)
        {
            cout << PLUS << DASH;
        }
        cout << PLUS << endl;
        ;

        if (i < 9)
        {
            cout << SPACE_1 << 0 << i + 1 << SPACE_1;
        }
        else
        {
            cout << SPACE_1 << i + 1 << SPACE_1;
        }
        for (int j = 0; j < this->width; j++)
        {
            cout << PIPE << SPACE_1;
            if (!this->isEmpty(i, j))
            {
                this->grid[i][j].getItem()->printKODE_HURUF();
            }
            else
            {
                cout << SPACE_3;
            };
            cout << SPACE_1;
        }
        cout << PIPE << endl;
    }
    cout << SPACE_4;
    for (int j = 0; j < this->width; j++)
    {
        cout << PLUS << DASH;
    }
    cout << PLUS << endl
         << endl;

    cout << "Total slot kosong: " << this->calcEmptySpace() << endl
         << endl;
}

template <class T>
int Inventory<T>::calcEmptySpace()
{
    int count = 0;

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            if (this->isEmpty(i, j))
            {
                count++;
            }
        }
    }
    return count;
}

template <class T>
bool Inventory<T>::isEmpty(int i, int j)
{
    return this->grid[i][j].getAmount() == 0;
}

template <class T>
bool Inventory<T>::isEmpty(string idx)
{
    try
    {
        int j = idx[0] - 'A';
        int i = stoi(idx.substr(1)) - 1;

        if (i >= this->height || j >= this->width || i < 0 || j < 0)
        {
            throw IndexNotValidException();
        }

        return this->grid[i][j].getAmount() == 0;
    }
    catch (...)
    {
        throw IndexNotValidException();
    }
}

template <class T>
bool Inventory<T>::isFull()
{
    return this->calcEmptySpace() == 0;
}

template <class T>
void Inventory<T>::printItem(int i, int j)
{
    this->grid[i][j].getItem()->print();
}

template <class T>
T *Inventory<T>::getItem(int i, int j)
{
    if (i >= this->height || j >= this->width || i < 0 || j < 0)
    {
        throw InvalidIndexException();
    }
    else if (this->isEmpty(i, j))
    {
        throw IsEmptySlotException();
    }
    return this->grid[i][j].getItem();
}

template <class T>
T *Inventory<T>::getItem(string idx)
{
    try
    {
        int j = idx[0] - 'A';
        int i = stoi(idx.substr(1)) - 1;

        if (i >= this->height || j >= this->width || i < 0 || j < 0)
        {
            throw IndexNotValidException();
        }

        return this->grid[i][j].getItem();
    }
    catch (...)
    {
        throw IndexNotValidException();
    }
}

#endif