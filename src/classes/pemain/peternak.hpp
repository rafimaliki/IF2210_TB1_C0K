#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"

class Peternak : public Pemain {
    private:
        // matriks peternak

    public:
        void cetak_peternakan();

        void ternak();

        void memberi_pangan();

        void memanen();

        void jual();

        void beli();
};

#endif