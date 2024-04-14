#include "inventory.hpp"

template <class T>
InventoryEntry<T>::InventoryEntry(T *item) : amount(1), item(item) {}

template <class T>
InventoryEntry<T>::InventoryEntry() : amount(0), item(nullptr) {}

template <class T>
T *InventoryEntry<T>::getItem()
{
    return this->item;
}

template <class T>
int InventoryEntry<T>::getAmount()
{
    return this->amount;
}

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
int Inventory<T>::getWidth()
{
    return this->width;
}

template <class T>
int Inventory<T>::getHeight()
{
    return this->height;
}

template <class T>
string Inventory<T>::getTitle()
{
    return this->title;
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
void Inventory<T>::add(T *item, int i, int j)
{
    if (i >= this->height || j >= this->width || i < 0 || j < 0)
    {
        throw InvalidIndexException();
    }
    else if (!this->isEmpty(i, j))
    {
        throw SlotIsNotEmptyException();
    }
    else
    {
        this->grid[i][j] = InventoryEntry<T>(item);
    }
}

template <class T>
void Inventory<T>::add(T *item, string idx)
{   
    vector<int> index = Util::idxToInt(idx);
    add(item, index[0], index[1]);
}

template <class T>
void Inventory<T>::remove(int i, int j)
{
    if (i >= this->height || j >= this->width || i < 0 || j < 0){
        throw InvalidIndexException();
    } else if (this->isEmpty(i, j)){
        throw IsEmptySlotException();
    }
   
    this->grid[i][j] = InventoryEntry<T>();
}

template <class T>
void Inventory<T>::remove(string idx)
{
    vector<int> index = Util::idxToInt(idx);
    remove(index[0], index[1]);
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
void Inventory<T>::printItem(int i, int j)
{   
    if (i >= this->height || j >= this->width || i < 0 || j < 0)
    {
        throw InvalidIndexException();
    }
    else if (this->isEmpty(i, j))
    {
        throw IsEmptySlotException();
    }
    this->getItem(i, j)->print();
}

template <class T>
bool Inventory<T>::isEmpty(int i, int j)
{   
    if (i >= this->height || j >= this->width || i < 0 || j < 0)
    {
        throw InvalidIndexException();
    }

    return this->grid[i][j].getAmount() == 0;
}

template <class T>
bool Inventory<T>::isEmpty(string idx)
{   
    vector<int> index = Util::idxToInt(idx);
    return isEmpty(index[0], index[1]);
}

template <class T>
bool Inventory<T>::isFull()
{
    return this->calcEmptySpace() == 0;
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
int Inventory<T>::count()
{
    int count = 0;

    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            if (!this->isEmpty(i, j))
            {
                count++;
            }
        }
    }
    return count;
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
    vector<int> index = Util::idxToInt(idx);
    return getItem(index[0], index[1]);
}

template class Inventory<Item>;
template class InventoryEntry<Item>;

template class Inventory<Plant>;
template class InventoryEntry<Plant>;

template class Inventory<Animal>;
template class InventoryEntry<Animal>;


