#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include <limits>
#include <algorithm>
#include "../player.hpp"
#include "../petani/petani.hpp"
#include "../peternak/peternak.hpp"
#include "../../item/bangunan/bangunan.hpp"
#include "walikotaexception.hpp"

class Walikota : public Player {
    public:
        Walikota(string name, int money, int body_weight);

        // void pungut_pajak();
        // void bangun_bangunan();
        // void tambah_pemain();
        // void jual();

        /* Game command related methods */
        void PUNGUT_PAJAK();
        void BANGUN();
        // void MUAT();
        void TAMBAH_PEMAIN();
        int HITUNG_PAJAK(int idx);
        vector<RecipeConfig> getDaftarRecipe();
        void showRecipe(vector<RecipeConfig> daftar_bangunan);
        string inputNama(vector<RecipeConfig> daftar_bangunan);
        int getBangunanPrice(string nama, vector<RecipeConfig> daftar_bangunan);
        void useMoney(int amount);
        void cancelUseMoney(int amount);
        void useIngredients(string nama, vector<RecipeConfig> daftar_bangunan);
        void bangunBangunan(string nama, vector<RecipeConfig> daftar_bangunan);
        string inputJenisPemain();
        string inputPemainBaru();
        void addNewPlayer(string namaPemainBaru, string jenisPemainBaru);

        string getType();
};

#endif