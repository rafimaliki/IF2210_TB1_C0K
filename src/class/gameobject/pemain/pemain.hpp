#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include "../../../std.hpp"
#include <vector>
using namespace std;

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

        void cetak_penyimpanan(){
            int jumlah_kolom = this->penyimpanan[0].size();

            cout << "    ";
            int kiri = (jumlah_kolom - 3)/2;
            int kanan = jumlah_kolom - kiri - 3;
            for (int i = 0; i< kiri; i++){
                cout << "======";
            }
            cout << "==[ Penyimpanan ]=";
            for (int i = 0; i< kanan; i++){
                cout << "======";
            }
            cout << endl;
            for (int i = 0; i < int(this->penyimpanan.size())*2+2; i++){
                for (int j = 0; j <= this->penyimpanan[0].size(); j++){
                    if(i==0 && j==0){
                        cout << "     ";
                    }else if(i==0){
                        cout << "  " << char('A' + j-1) << "   ";
                    }
                    else if(i%2 ==1 && j == 0){
                        cout << "    +";
                    }else if(i%2 == 1){
                        cout << "-----+";
                    }else if(i%2 == 0 && j == 0){
                        if(i/2 < 10){
                            cout<< " 0" << i / 2 << " |";
                        }else{
                            cout<< " " << i / 2 << " |";
                        }
                    }else{
                        cout << " " << this->penyimpanan[(i/2)-1][j-1]<< " |";
                    }
                }
                cout << endl;
            }
            cout << endl;
            int cnt= 0;
            for (int i = 0; i < this->penyimpanan.size(); i++){
                for (int j = 0; j < this->penyimpanan[0].size(); j++){
                    if (this->penyimpanan[i][j] == "   "){
                        cnt++;
                    }
                }
            }
            cout << "Total slot kosong: "<< cnt << endl;
        }

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
        string nama;
        int id;
        int uang;
        vector<vector<string>> penyimpanan;
        int berat_badan;
};

vector<Pemain> Pemain::players;
int Pemain::current_player_id = 0;
int Pemain::num_players = 0;

#endif