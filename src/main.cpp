// File: main.cpp

#include "std.hpp"
#include "class/muat/config_reader.hpp"
#include "class/game/game.hpp"
// #include "class/gameobject/pemain/pemain.hpp"

int main() {

    cout << "\033[2J\033[1;1H";
    cout << "\n                                                                                                      \n"
            " ██░ ██  ▄▄▄       ██▀███   ██▒   █▓▓█████   ██████ ▄▄▄█████▓    ███▄ ▄███▓ ▒█████   ▒█████   ███▄    █ \n"
            "▓██░ ██▒▒████▄    ▓██ ▒ ██▒▓██░   █▒▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒   ▓██▒▀█▀ ██▒▒██▒  ██▒▒██▒  ██▒ ██ ▀█   █ \n"
            "▒██▀▀██░▒██  ▀█▄  ▓██ ░▄█ ▒ ▓██  █▒░▒███   ░ ▓██▄   ▒ ▓██░ ▒░   ▓██    ▓██░▒██░  ██▒▒██░  ██▒▓██  ▀█ ██▒\n"
            "░▓█ ░██ ░██▄▄▄▄██ ▒██▀▀█▄    ▒██ █░░▒▓█  ▄   ▒   ██▒░ ▓██▓ ░    ▒██    ▒██ ▒██   ██░▒██   ██░▓██▒  ▐▌██▒\n"
            "░▓█▒░██▓ ▓█   ▓██▒░██▓ ▒██▒   ▒▀█░  ░▒████▒▒██████▒▒  ▒██▒ ░    ▒██▒   ░██▒░ ████▓▒░░ ████▓▒░▒██░   ▓██░\n"
            " ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒▓ ░▒▓░   ░ ▐░  ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░      ░ ▒░   ░  ░░ ▒░▒░▒░ ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ \n"
            " ▒ ░▒░ ░  ▒   ▒▒ ░  ░▒ ░ ▒░   ░ ░░   ░ ░  ░░ ░▒  ░ ░    ░       ░  ░      ░  ░ ▒ ▒░   ░ ▒ ▒░ ░ ░░   ░ ▒░\n"
            " ░  ░░ ░  ░   ▒     ░░   ░      ░░     ░   ░  ░  ░    ░         ░      ░   ░ ░ ░ ▒  ░ ░ ░ ▒     ░   ░ ░ \n"
            " ░  ░  ░      ░  ░   ░           ░     ░  ░      ░                     ░       ░ ░      ░ ░           ░ \n"
            "                                ░                                                                       \n";

    Game game;

    ConfigReader animal_config("config/animal.txt");

    vector<vector<string>> animal_data = animal_config.readConfig();
    game.setAnimalData(AnimalData::ReadAnimalData(animal_data));
    
    cout << "\n\x1b[32mANIMAL DATA: \x1b[0m\n" << endl;
    for (int i = 0; i < int(game.animalData.size()) ; i++){
        game.animalData[i].print();
    }

    ConfigReader plant_config("config/plant.txt");

    vector<vector<string>> plant_data = plant_config.readConfig();
    game.setPlantData(PlantData::ReadPlantData(plant_data));

    cout << "\n\x1b[32mPLANT DATA: \x1b[0m\n" << endl;
    for (int i = 0; i < int(game.plantData.size()) ; i++){
        game.plantData[i].print();
    }

    ConfigReader product_config("config/product.txt");

    vector<vector<string>> product_data = product_config.readConfig();
    game.setProductData(ProductData::ReadProductData(product_data));

    cout << "\n\x1b[32mPRODUCT DATA: \x1b[0m\n" << endl;
    for (int i = 0; i < int(game.productData.size()) ; i++){
        game.productData[i].print();
    }

    ConfigReader recipe_config("config/recipe.txt");

    cout << "\n\x1b[32mRECIPE DATA: \x1b[0m\n" << endl;
    vector<vector<string>> recipe_data = recipe_config.readConfig();
    game.setRecipeData(RecipeData::ReadRecipeData(recipe_data));

    for (int i = 0; i < int(game.recipeData.size()) ; i++){
        game.recipeData[i].print();
    }

    

    // Pemain player1("Rafi", 0);
    // Pemain player2("Nicho", 1);
    // Pemain player3("Hugo", 2);
    // Pemain player4("Zaki", 3);
    // Pemain player5("Onta", 4);

    // while (true){
    //     Pemain current_player = Pemain::getCurrentPlayer();
    //     cout << "\n\033[0mGiliran player " << current_player.getName() << endl;

    //     string command;

    //     cout << "> \033[1;1m";
    //     cin >> command;

    //     if (command == "EXIT") {
    //         break;
    //     } else if (command == "NEXT"){
    //         Pemain::nextPlayer();
    //     } else {
    //         cout << "\033[0mCommand not found!" << endl;
    //     }

    //     // player1.cetak_penyimpanan();
    // };

    // Game game;
    // game.start()

    // while(game.isrunning()){

    //     game.getinput();
    //     game.runcommand();

    // }
  
    return 0;
}