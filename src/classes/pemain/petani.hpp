#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"

class Petani : public Pemain {
    private:
        // matriks ladang

    public:
        void cetak_ladang();

        void tanam();

        void memanen();

        void jual();

        void beli();
};

#endif