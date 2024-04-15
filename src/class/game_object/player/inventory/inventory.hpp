#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "../../../../std.hpp"
#include "../../item/plant/plant.hpp"
#include "../../item/animal/animal.hpp"
#include "../../item/item.hpp"
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

template <class T>
class InventoryEntry
{
private:
    int amount; /* hanya 0 dan 1, ada dan tidak, gbs multiple*/
    T *item;

public:
    InventoryEntry();
    InventoryEntry(T *item);

    int getAmount();
    T *getItem();
};

template <class T>
class Inventory
{
private:
    /* data */
    string title;
    int width;
    int height;
    vector<vector<InventoryEntry<T>>> grid;
public:

    Inventory();
    Inventory(int width, int height, string title);

    int getWidth();
    int getHeight();
    string getTitle();

    void add(T *item);
    void add (T *item, int i, int j);
    void add(T *item, string idx);
    void operator+=(T *item);

    void remove(int i, int j);
    void remove(string idx);

    void print();
    void printItem(int i, int j);

    bool isEmpty(int j, int i);
    bool isEmpty(string idx);
    bool isFull();

    int calcEmptySpace();
    int count();

    T *getItem(int i, int j);
    T *getItem(string idx);

};

#endif