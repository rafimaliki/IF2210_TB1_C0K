#include "product.hpp"

vector<Product*> Product::products;
int Product::productCount = 0;

Product::Product(int ID) : Item(), config(&GameConfig::productConfig[ID-1]) {
    Product::products.push_back(this);
    Product::productCount++;
}

void Product::print(){
    this->config->print();
}

void Product::printKODE_HURUF(){
    cout << this->config->getKODE_HURUF();
}

ItemConfig* Product::getConfig(){
    return this->config;
}

string Product::getTYPE(){
    return this->config->getTYPE();
}

int Product::getADDED_WEIGHT(){
    return this->config->getADDED_WEIGHT();
}
