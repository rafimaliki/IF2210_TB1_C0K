// File: main.cpp

#include "std.hpp"
#include "class/muat/config_reader.hpp"
#include "class/gameobject/pemain/pemain.hpp"

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



    ConfigReader animal_config("config/animal.txt");
    ConfigReader misc_config("config/misc.txt");
    ConfigReader plant_config("config/plant.txt");
    ConfigReader product_config("config/product.txt");
    ConfigReader recipe_config("config/recipe.txt");

    vector<string> animal_data = animal_config.readLines();
    vector<string> misc_data = misc_config.readLines();
    vector<string> plant_data = plant_config.readLines();
    vector<string> product_data = product_config.readLines();
    vector<string> recipe_data = recipe_config.readLines();

    // cout << "\nAnimal data:" << endl;
    // for (const auto& line : animal_data) {
    //     cout << line << endl;
    // }

    cout << "\nMisc data:" << endl;
    for (const auto& line : misc_data) {
        cout << line << endl;
    }

    // cout << "\nPlant data:" << endl;
    // for (const auto& line : plant_data) {
    //     cout << line << endl;
    // }

    // cout << "\nProduct data:" << endl;
    // for (const auto& line : product_data) {
    //     cout << line << endl;
    // }

    // cout << "\nRecipe data:" << endl;
    // for (const auto& line : recipe_data) {
    //     cout << line << endl;
    // }

    Pemain player1("Rafi", 0);
    Pemain player2("Nicho", 1);
    Pemain player3("Hugo", 2);
    Pemain player4("Zaki", 3);
    Pemain player5("Onta", 4);

    while (true){
        Pemain current_player = Pemain::getCurrentPlayer();
        cout << "\n\033[0mGiliran player " << current_player.getName() << endl;

        string command;

        cout << "> \033[1;1m";
        cin >> command;

        if (command == "EXIT") {
            break;
        } else if (command == "NEXT"){
            Pemain::nextPlayer();
        } else {
            cout << "\033[0mCommand not found!" << endl;
        }

        // player1.cetak_penyimpanan();
    };

    return 0;
}