#include "toko.hpp"

// Define the static members
int Toko::neff = 0;
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

void Toko::displayToko()
{
    int total_plant = GameConfig::plantConfig.size();
    int total_animal = GameConfig::animalConfig.size();
    cout << "[=======SECTION TUMBUHAN======]" << endl;
    for (int i = 0; i < total_plant; i++)
    {
        cout << i + 1 << ". " << GameConfig::plantConfig[i].getNAME() << " - " << GameConfig::plantConfig[i].getPRICE() << endl;
    }
    cout << "[========SECTION HEWAN======]" << endl;
    for (int i = 0; i < total_animal; i++)
    {
        cout << total_plant + i + 1 << ". " << GameConfig::animalConfig[i].getNAME() << " - " << GameConfig::animalConfig[i].getPRICE() << endl;
    }
    cout << "[========SECTION PRODUK======]" << endl;
    for (int i = 0; i < list_item.size(); i++)
    {
        cout << total_animal + total_plant + 1 + i << ". " << list_item[i].getItem()->getNAME() << " - " << list_item[i].getItem()->getPRICE() << "(" << list_item[i].getAmount() << ")" << endl;
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
void Toko::addItem(Item *item)
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
    }else{
        list_item.push_back(TokoEntry(item));
    }

}