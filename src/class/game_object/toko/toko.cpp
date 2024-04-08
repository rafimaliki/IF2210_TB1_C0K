#include "toko.hpp"

// Define the static members
int Toko::n_plant  = 0;
int Toko::n_animal = 0;
int Toko::n_product = 0;
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
void TokoEntry::kurangAmount(int i)
{
    this->amount -= i;
}


void Toko::displayToko()
{
    Toko::n_plant  = GameConfig::plantConfig.size();
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
    cout << "[========SECTION PRODUK======]" << endl;
    for (int i = 0; i < n_product; i++)
    {
        cout << n_animal+ n_plant + 1 + i << ". " << list_item[i].getItem()->getNAME() << " - " << list_item[i].getItem()->getPRICE() << "(" << list_item[i].getAmount() << ")" << endl;
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
        n_product++;
    }
    

}
void Toko::deleteItem(int idx){
    list_item.erase(list_item.begin() + idx);
    n_product --;
}
Item* Toko::beliItemToko(int i,int amount,int gulden){
    if(i > n_animal+n_plant+n_product || i <= 0) throw NumberNotValid();

    if(i <= n_plant){ // tumbuhan (infinite)
        Item* plant = new Plant(i);
        if(gulden - (amount * plant->getPRICE()) < 0) throw GuldenInvalid();
        return plant;
    }else if (n_plant  < i && i <= n_animal + n_plant ) // hewan (infinite)
    {
         
        Item* animal = new Animal(i - n_plant);
        if(gulden - (amount * animal->getPRICE()) < 0) throw GuldenInvalid();
        return animal;
    }else{
        int total_price = list_item[i- n_plant - n_animal - 1].getItem()->getPRICE() * amount;
        if(list_item[i - n_plant - n_animal - 1].getAmount()  - amount < 0||amount <= 0 ) throw AmountNotValid();
        if(gulden - total_price < 0) throw GuldenInvalid();
        Item* temp =  list_item[i -n_plant - n_animal -1 ].getItem();
        list_item[i - n_plant - n_animal - 1].kurangAmount(amount);
        checkEmptyItem();
        return temp;
    }
}
void Toko::checkEmptyItem(){
    for (int i = 0; i < n_product; i++)
    {
        if(list_item[i].getAmount() == 0){
            list_item.erase(list_item.begin() + i -1);
            n_product --;
        }
    }
}