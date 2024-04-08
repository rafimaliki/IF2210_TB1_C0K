#include "../item/item.hpp"
#include "../item_config/item_config.hpp"
#include "vector"
using namespace std;

class TokoEntry{
private:
    int amount;
    Item* item;
public:
    TokoEntry();
    TokoEntry(Item* item);
    Item* getItem();
    int getAmount() const;
    void tambahAmount(int i);
};

class Toko {
private:
    static int neff; 
    
public:
    static vector<TokoEntry> list_item; 

    static void displayToko(); 
    static void addItem(Item *i); 
    static bool checkValidItem(Item *i);
};

