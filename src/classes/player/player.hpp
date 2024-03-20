#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../std.hpp"

class Player {
public:

    static vector<Player> players;
    static int current_player_id;
    static int num_players;
     
    Player(const string& name, const int id) : name(name), id(id) {
        num_players++;
        players.push_back(*this);
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    static void nextPlayer() {
        current_player_id = (current_player_id + 1) % num_players;
    }

    static Player& getCurrentPlayer() {
        return players[current_player_id];
    }

private:
    string name;
    int id;
};

vector<Player> Player::players;
int Player::current_player_id = 0;
int Player::num_players = 0;

#endif