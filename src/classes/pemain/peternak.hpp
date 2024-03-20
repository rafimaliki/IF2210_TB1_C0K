#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"
#include <vector>
using namespace std;

class Peternak : public Pemain {
    private:
        vector<vector<string>> peternakan;

    public:
        void cetak_peternakan();

        void ternak();

        void memberi_pangan();

        void memanen();

        void jual();

        void beli();
};

#endif