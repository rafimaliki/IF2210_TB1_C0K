// File: main.cpp

#include "std.hpp"
#include "classes/config_reader/config_reader.hpp"
#include "classes/player/player.hpp"

int main() {

    cout << "\033[2J\033[1;1H";
    cout << " ██░ ██  ▄▄▄       ██▀███   ██▒   █▓▓█████   ██████ ▄▄▄█████▓    ███▄ ▄███▓ ▒█████   ▒█████   ███▄    █ \n"
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

    // cout << "\nMisc data:" << endl;
    // for (const auto& line : misc_data) {
    //     cout << line << endl;
    // }

    // cout << "\nPlant data:" << endl;
    // for (const auto& line : plant_data) {
    //     cout << line << endl;
    // }

    // cout << "\nProduct data:" << endl;
    // for (const auto& line : product_data) {
    //     cout << line << endl;
    // }

    cout << "\nRecipe data:" << endl;
    for (const auto& line : recipe_data) {
        cout << line << endl;
    }

    Player player1("Rafi", 0);
    Player player2("Nicho", 1);
    Player player3("Hugo", 2);
    Player player4("Zaki", 3);
    Player player5("Onta", 4);

    while (true){

        Player current_player = Player::getCurrentPlayer();
        cout << "\nGiliran player " << current_player.getName() << endl;

        string command;

        cout << "> ";
        cin >> command;

        if (command == "EXIT") {
            break;
        }

        Player::nextPlayer();
    };

    return 0;
}