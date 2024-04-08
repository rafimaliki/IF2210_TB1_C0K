#include "../item/item.hpp"
#include "../item_config/item_config.hpp"
#include "../item/animal/animal.hpp"
#include "../item/plant/plant.hpp"
#include "../item/product/product.hpp"
#include "tokoexception.hpp"

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
    void kurangAmount(int i);
};

class Toko {
private:
    static int n_animal;
    static int n_plant;
    static int n_product;

    
public:
    Toko();
    static vector<TokoEntry> list_item; 

    static void displayToko(); 
    static void addItem(Item *i); 
    static Item* beliItemToko(int i,int amount,int gulden);
    static void deleteItem(int idx);
    static bool checkValidItem(Item *i);
    static void checkEmptyItem();

};

