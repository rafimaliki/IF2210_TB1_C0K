#ifndef TUMBUHAN_HPP
#define TUMBUHAN_HPP

#include "../../../std.hpp"

class Tumbuhan {
    private:
        int id;
        string kode_huruf;
        string nama;
        string tipe;
        int waktu_panen;
        int harga;

    public:
        void kurangi_waktu_panen();
};

#endif