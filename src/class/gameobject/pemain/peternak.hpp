#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"
#include <vector>
using namespace std;

class Peternak : public Pemain {
    private:
        vector<vector<string>> peternakan;

    public:
        void cetak_peternakan(){
            int jumlah_kolom = this->peternakan[0].size();
            cout << "    ";
            int kiri = (jumlah_kolom - 3)/2;
            int kanan = jumlah_kolom - kiri - 3;
            for (int i = 0; i< kiri; i++){
                cout << "======";
            }
            cout << "==[ Peternakan ]==";
            for (int i = 0; i< kanan; i++){
                cout << "======";
            }
            cout << endl;
            for (int i = 0; i < int(this->peternakan.size())*2+2; i++){
                for (int j = 0; j <= this->peternakan[0].size(); j++){
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
                        cout << " " << this->peternakan[(i/2)-1][j-1]<< " |";
                    }
                }
                cout << endl;
            }
        
        }

        void ternak();

        void memberi_pangan();

        void memanen();

        void jual();

        void beli();
};

#endif