#include "toko.hpp"

// Define the static members
int Toko::n_plant = 0;
int Toko::n_animal = 0;
int Toko::n_product = 0;
int Toko::n_bangunan = 0;
vector<TokoEntry> Toko::list_item;

TokoEntry::TokoEntry()
{
    amount = 0;
    item = nullptr;
}
TokoEntry::TokoEntry(Item *i)
{
    amount = 1;
    item = i;
}
Item *TokoEntry::getItem()
{
    return this->item;
}

int TokoEntry::getAmount() const
{
    return this->amount;
}
void TokoEntry::tambahAmount(int i)
{
    this->amount += i;
}
void TokoEntry::setAmount(int i)
{
    this->amount = i;
}

void Toko::displayToko()
{
    Toko::n_plant = GameConfig::plantConfig.size();
    Toko::n_animal = GameConfig::animalConfig.size();

    cout << "[=======SECTION TUMBUHAN======]" << endl;
    for (int i = 0; i < n_plant; i++)
    {
        cout << i + 1 << ". " << GameConfig::plantConfig[i].getNAME() << " - " << GameConfig::plantConfig[i].getPRICE() << endl;
    }
    cout << "[========SECTION HEWAN======]" << endl;
    for (int i = 0; i < n_animal; i++)
    {
        cout << n_plant + i + 1 << ". " << GameConfig::animalConfig[i].getNAME() << " - " << GameConfig::animalConfig[i].getPRICE() << endl;
    }
    cout << "[========SECTION PRODUK&BANGUNAN ======]" << endl;
    for (int i = 0; i < n_product + n_bangunan; i++)
    {
        cout << n_animal + n_plant + 1 + i << ". " << list_item[i].getItem()->getNAME() << " - " << list_item[i].getItem()->getPRICE() << "(" << list_item[i].getAmount() << ")" << endl;
    }
}
bool Toko::checkValidItem(Item *item)
{
    for (int i = 0; i < list_item.size(); i++)
    {
        if (list_item[i].getItem()->getKODE_HURUF() == item->getKODE_HURUF())
        {
            return true;
        }
    }
    return false;
}
bool Toko::isInfiniteItem(Item *item)
{
    return (item->isAnimal() || item->isPlant());
}
int Toko::getAmountEntry(int id)
{
    return list_item[id - n_plant - n_animal - 1].getAmount();
}
void Toko::addItem(Item *item)
{
    if (!isInfiniteItem(item))
    {
        if (Toko::checkValidItem(item))
        {
            for (int i = 0; i < list_item.size(); i++)
            {
                if (list_item[i].getItem()->getKODE_HURUF() == item->getKODE_HURUF())
                {
                    list_item[i].tambahAmount(1);
                }
            }
        }
        else
        {
            list_item.push_back(TokoEntry(item));
            if (item->getTYPE() == "")
            {
                n_bangunan++;
            }
            else
            {
                n_product++;
            }
        }
    }
}
void Toko::deleteItem(int idx)
{
    list_item.erase(list_item.begin() + idx);
    if (list_item[idx].getItem()->getTYPE() == "")
    {
        n_bangunan--;
    }
    else
    {
        n_product--;
    }
}

Item *Toko::getItemToko(int id)
{
    int offset_id = id - n_plant - n_animal - 1;
    if (id > n_animal + n_plant + n_product + n_bangunan || id <= 0)
        throw InvalidIndexException();
    if (id <= n_plant) // tumbuhan (infinite)
    {
        Item *plant = new Plant(id);
        return plant;
    }
    else if (n_plant < id && id <= n_animal + n_plant) // hewan (infinite)
    {
        Item *animal = new Animal(id - n_plant);
        return animal;
    }
    else
    {
        return (list_item[offset_id].getItem());
    }
}
TokoEntry Toko::getItemEntry(int id)
{
    return list_item[id - n_plant - n_animal - 1];
}
Item *Toko::beliItemToko(int i, int amount, int gulden)
{
    // if (i <= n_plant)
    // { // tumbuhan (infinite)
    //     Item *plant = getItemToko(i);
    //     if (gulden - (amount * plant->getPRICE()) < 0)
    //         throw GuldenInvalid();
    //     return plant;
    // }
    // else if (n_plant < i && i <= n_animal + n_plant) // hewan (infinite)
    // {
    //     Item *animal = getItemToko(i);
    //     if (gulden - (amount * animal->getPRICE()) < 0)
    //         throw GuldenInvalid();
    //     return animal;
    // }
    // else
    // {
    Item *bought_item = getItemToko(i);
    int total_price = getItemToko(i)->getPRICE() * amount;
    if (!isInfiniteItem(bought_item))
    {
        if (getAmountEntry(i) - amount < 0 || amount <= 0)
            throw AmountNotValid();
    }
    if (gulden - total_price < 0)
        throw GuldenInvalid();
    if (!isInfiniteItem(bought_item))
    {
        setItemEntryAmount(i, getItemEntry(i).getAmount() - amount);
    }
    checkEmptyItem();
    return bought_item;
}

void Toko::setItemEntryAmount(int id, int amount)
{
    list_item[id - n_plant - n_animal - 1].setAmount(amount);
}
void Toko::checkEmptyItem()
{
    for (int i = 0; i < n_product + n_bangunan; i++)
    {
        if (list_item[i].getAmount() == 0)
        {
            list_item.erase(list_item.begin() + i);
            n_product--;
        }
    }
}