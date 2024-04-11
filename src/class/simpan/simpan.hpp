#ifndef SIMPAN_HPP
#define SIMPAN_HPP

#include "../../std.hpp"
#include "../game_object/item_config/item_config.hpp"
#include "../game_object/item/plant/plant.hpp"
#include "../game_object/item/animal/animal.hpp"
#include "../game_object/item/bangunan/bangunan.hpp"
#include "../game_object/item/product/product.hpp"
#include "../game_object/player/player.hpp"
#include "../game_object/player/walikota/walikota.hpp"
#include "../game_object/player/petani/petani.hpp"
#include "../game_object/player/peternak/peternak.hpp"

#include "simpanException.hpp"


class Simpan
{
    private: 
        string filename;
        static string convertLadangToString(Inventory<Plant>* ladang);
        static string convertPeterknakanToString(Inventory<Animal>* peternakan);
        static string convertPlayerToString(Player* player);
        static string convertTokoToString();
        static string convertGameDataToString();
        
    public:
        Simpan(string filename);
        static void saveGame();
        bool isValidName();
        void writeToFile(string data);
};

#endif