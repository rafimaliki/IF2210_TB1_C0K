#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"
#include <vector>
using namespace std;

class Petani : public Pemain {
    private:
        vector<vector<string>> ladang;

    public:
        void cetak_ladang();

        void tanam();

        void memanen();

        void jual();

        void beli();
};

#endif