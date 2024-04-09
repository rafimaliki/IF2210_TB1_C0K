#include "bangunan.hpp"

vector<Bangunan*> Bangunan::daftar_bangunan;
int Bangunan::bangunanCount = 0;

Bangunan::Bangunan(int ID) : Item(), config(&GameConfig::recipeConfig[ID - 1]){
    Bangunan::daftar_bangunan.push_back(this);
    Bangunan::bangunanCount++;
}

void Bangunan::print(){
    this->config->print();
}

ItemConfig* Bangunan::getConfig(){
    return this->config;
}

void Bangunan::printKODE_HURUF(){
    cout << this->config->getKODE_HURUF();
}

string Bangunan::getType(){
    return this->config->getTYPE();
}