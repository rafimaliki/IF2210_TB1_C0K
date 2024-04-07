#include "item.hpp"

Item::Item(){
    cout << "\x1b[32mAn Object IS CREATED!\x1b[0m" << endl;
}

void Item::print(){
    cout << "This is an Item" << endl;
}

Item::~Item(){
    cout << "\x1b[31mAn Object IS DESTROYED!\x1b[0m" << endl;
}