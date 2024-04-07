#include "game.hpp"

Game::Game() {
    this->is_running = false;
}

void Game::start() {
    this->is_running = true;

    cout << "Game started!\n" << endl;

    loadConfig();
    loadSaveFile();

    Player* walikota = new Walikota("Walikota", 1000, 70);
    Player* petani1 = new Petani("Petani1", 50, 45);
    Player* peternak1 = new Peternak("Peternak1", 100, 55);
}

void Game::loadConfig() {

    cout << "Loading config...\n" << endl;
    GameConfig::loadGameConfig();
}

void Game::loadSaveFile() {
    cout << "\nLoading save file..." << endl;
    cout << "No save file found" << endl;
}

string Game::inputCommand() {
    string command;
    cout << "\nEnter command: ";
    cin >> command;
    return command;
}

void Game::executeCommand(string command) {
    cout << "Executing command: " << command << endl;
    if (command == "EXIT" || command == "exit") {
        is_running = false;
    } else if (command == "NEXT" || command == "next") {
        cout << "\033[1;33m\nAnother day has passed...\n\033[0m";
        Plant::AgeAllPlants();
        Player::next();
    } else if (command == "PRINT_INVENTORY" || command == "print_inventory") {
        Player::getCurrentPlayer()->printInventory();
    } else if (command == "PRINT_STATS" || command == "print_stats") {
        Player::getCurrentPlayer()->printStats();
    } else if (command == "PRINT_LAHAN" || command == "print_lahan") {
        Player::getCurrentPlayer()->printLahan();
    } else if (command == "PRINT_PETERNAKAN" || command == "print_peternakan") {
        Player::getCurrentPlayer()->printPeternakan();
    }
    else {
        cout << "Invalid command" << endl;
    }
}

void Game::checkWin() {
    // cout << "\nChecking win...\n" << endl;
}

void Game::printWinner() {
    cout << "Printing winner..." << endl;
}

bool Game::isRunning() {
    return is_running;
}