#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include "../../std.hpp"

class Pemain {
    public:

        static vector<Pemain> players;
        static int current_player_id;
        static int num_players;
        
        Pemain(const string& nama, const int id) : nama(nama), id(id) {
            num_players++;
            players.push_back(*this);
        }

        string getName() const {
            return nama;
        }

        int getId() const {
            return id;
        }

        void cetak_penyimpanan();

        void makan();

        void simpan();

        void muat();

        static void nextPlayer() {
            current_player_id = (current_player_id + 1) % num_players;
        }

        static Pemain& getCurrentPlayer() {
            return players[current_player_id];
        }

    protected:
        int id;
        string nama;
        int uang;
        // matriks penyimpanan
        int berat_badan;
};

vector<Pemain> Pemain::players;
int Pemain::current_player_id = 0;
int Pemain::num_players = 0;

#endif