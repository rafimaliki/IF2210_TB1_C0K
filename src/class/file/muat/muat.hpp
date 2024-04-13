#ifndef MUAT_HPP
#define MUAT_HPP

#include "../../../std.hpp"
#include "../../game_object/item_config/item_config.hpp"
#include "../../game_object/item/plant/plant.hpp"
#include "../../game_object/item/animal/animal.hpp"
#include "../../game_object/item/bangunan/bangunan.hpp"
#include "../../game_object/item/product/product.hpp"
#include "../../game_object/player/player.hpp"
#include "../../game_object/player/walikota/walikota.hpp"
#include "../../game_object/player/petani/petani.hpp"
#include "../../game_object/player/peternak/peternak.hpp"
#include "../file_reader.hpp"
#include "muatException.hpp"

class Muat : public FileReader {

    private:
        // Data attribute
        vector<vector<string>> data;

        // Object spawning method
        void spawnObject();
        static string composeName(vector<string> vec);
        static Player* spawnPlayer(vector<string> vec);
        static Item* spawnItem(string name);
        static Plant* spawnPlant(string name, int age);
        static Animal* spawnAnimal(string name, int weight);
            
    public:
        // Constructor
        Muat(string filename);

        // File reading method
        bool tryReadFile();

        // Controller method
        static void loadSaveFile();

};


#endif