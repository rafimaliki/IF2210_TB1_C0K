#include "player.hpp"

vector<Player*> Player::players;
int Player::current_player_idx = 0;
int Player::player_count = 0;

Player::Player(string name, int money, int body_weight) : 
    id(Player::player_count+1), 
    name(name),
    money(money), 
    body_weight(body_weight), 
    inventory(GameConfig::miscConfig.INVENTORY_SIZE[0], GameConfig::miscConfig.INVENTORY_SIZE[1], "PENYIMPANAN") {
    players.push_back(this);
    player_count++;
}

void Player::printStats(){
    cout << "\nPlayer stats: " << endl;
    cout << "  Id: " << this->id << endl;
    cout << "  Name: " << this->name << endl;
    cout << "  Money: " << this->money << endl;
    cout << "  Body Weight: " << this->body_weight << endl << endl;
}

void Player::printInventory(){
    this->inventory.print();
}

Player* Player::getCurrentPlayer(){
    return players[current_player_idx];
}

void Player::next(){   
    cout << "Player " << getCurrentPlayer()->name << "'s turn ended" <<endl; 
    current_player_idx++;
    if (current_player_idx >= player_count){
        current_player_idx = 0;
    }
    cout << "Player " << getCurrentPlayer()->name << "'s turn" << endl << endl; 
}

void Player::printLahan(){}
void Player::printPeternakan(){}
void Player::addPlant(Item* item){}
void Player::addAnimal(Item* item){}