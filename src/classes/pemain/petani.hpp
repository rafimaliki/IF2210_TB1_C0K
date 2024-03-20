#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"
#include <vector>
using namespace std;

class Petani : public Pemain {
    private:
        vector<vector<string>> ladang;

    public:
        void cetak_ladang(){
            ladang = this->ladang;
            int jumlah_kolom = ladang[0].size();

            cout << "    ";
            int kiri = (jumlah_kolom - 2)/2;
            int kanan = jumlah_kolom - kiri - 2;
            for (int i = 0; i< kiri; i++){
                cout << "======";
            }
            cout << "=[ Ladang ]=";
            for (int i = 0; i< kanan; i++){
                cout << "======";
            }
            cout << endl;
            for (int i = 0; i < ladang.size()*2+2; i++){
                for (int j = 0; j <= ladang[0].size(); j++){
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
                        cout << " " << ladang[(i/2)-1][j-1]<< " |";
                    }
                }
                cout << endl;
            }
        }

        void tanam();

        void memanen();

        void jual();

        void beli();
};
#endif