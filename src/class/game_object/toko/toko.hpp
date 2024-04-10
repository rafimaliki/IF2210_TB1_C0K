#include "../item/item.hpp"
#include "../item_config/item_config.hpp"
#include "../item/animal/animal.hpp"
#include "../item/plant/plant.hpp"
#include "../item/product/product.hpp"
#include "../item/bangunan/bangunan.hpp"
#include "tokoexception.hpp"

#include "vector"
using namespace std;

class TokoEntry
{
private:
    int amount;
    Item *item;

public:
    TokoEntry();
    TokoEntry(Item *item);
    Item *getItem();

    int getAmount() const;
    void tambahAmount(int i);
    void setAmount(int i);
};

class Toko
{
private:
    static int n_animal;
    static int n_plant;
    static int n_product;
    static int n_bangunan;

public:
    Toko();
    static vector<TokoEntry> list_item;

    static void displayToko();
    static void addItem(Item *i);
    static Item *beliItemToko(int i, int amount, int gulden);
    static Item *getItemToko(int id);
    static int getAmountEntry(int id);
    static void deleteItem(int idx);
    static bool checkValidItem(Item *i);
    static bool isInfiniteItem(Item *i);
    static void setItemEntryAmount(int id, int amount);
    static TokoEntry getItemEntry(int id);
    static void checkEmptyItem();
};
