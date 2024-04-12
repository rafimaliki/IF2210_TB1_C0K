#ifndef MUAT_HPP
#define MUAT_HPP

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
#include "file_reader.hpp"

class Muat : public FileReader {

    private:
        vector<vector<string>> data;
            
    public:
        Muat(string filename);
        bool isValidName();
        string getFilename();
        static void loadSaveFile();
        void spawnObject();

        static string composeName(vector<string>);
};


#endif