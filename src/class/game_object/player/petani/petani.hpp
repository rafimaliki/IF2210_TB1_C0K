#ifndef PETANI_HPP
#define PETANI_HPP

#include "../player.hpp"
#include "petaniException.hpp"

class Petani : public Player
{

private:
    Inventory<Plant> lahan;

public:
    Petani(string name, int money, int body_weight);

    /**
     * @brief Method untuk mencetak ladang
     *
     */
    void printLahan();

    /**
     * @brief Method untuk menambahkan tanaman ke ladang
     *
     * @param item (pointer ke tanaman)
     */
    void addPlant(Plant *item);

    /**
     * @brief Method untuk mendapatkan ladang
     *
     * @return Inventory<Plant>* (pointer ke ladang)
     */
    Inventory<Plant> *getLadang();

    /**
     * @brief Method untuk menghitung total kekayaan
     *
     * @return int (total kekayaan)
     */
    int getWealth();

    /* Game command related methods */

    /**
     * @brief Method untuk mencetak ladang
     *
     */
    void CETAK_LADANG();

    /**
     * @brief Method untuk melakukan penanaman
     *
     */
    void TANAM();

    /**
     * @brief Method untuk melakukan panen
     *
     */
    void PANEN();

    /**
     * @brief Cek apakah lahan sudah penuh
     *
     */
    bool isLahanPenuh();

    /**
     * @brief Cek apakah ada tanaman yang bisa dipanen
     *
     */
    void isPanenAvailable();

    /**
     * @brief Ceck apakah inventory memadai untuk ditambah sebanyak n item
     *
     * @param n (banyak item yang akan ditambahkan)
     */
    bool isInventoryMemadai(int n);

    /**
     * @brief Cek apakah inventory penuh
     *
     */
    void isInventoryPenuh();

    /**
     * @brief Mencari tanaman yang siap dipanen
     *
     * @param harvestablePlant (digunakan untuk menyimpan data tanaman yang siap dipanen)
     */
    void findHarvestablePlant(map<string, int> &harvestablePlant);

    /**
     * @brief Mencetak tanaman yang siap dipanen
     *
     * @param harvestablePlant (digunakan untuk menyimpan data tanaman yang siap dipanen)
     */
    void cetakSiapPanen(map<string, int> harvestablePlant);

    /**
     * @brief Mencetak hasil panen
     *
     * @param kode_tanaman  (kode tanaman yang dipanen)
     * @param nPetak        (banyak petak yang dipanen)
     * @param letak_panen   (array yang berisi petak yang dipanen)
     */
    void cetakHasilPanen(string plantName, int nPetak, string letak_panen[]);

    
    bool isTanamanAda();

    int getPlantID(string slot);

    void tanamTanaman(string slot_inventory,int ID, string slot_tanah);

    void isPilihanTanamanValid(int pilihan_tanaman,map<string, int> siap_panen);

    void panenTanaman(string petak_to_harvest,string kode_tanaman);

    void tambahProduk(string petak_to_harvest);

    void isBanyakPetakValid(int nPetak,int banyak_petak);

    void ambilKodeTanaman(map<string, int> siap_panen,string* kode_tanaman,int* nPetak,int pilihan_tanaman);

    string getType();
};

#endif
