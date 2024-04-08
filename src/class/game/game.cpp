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
    cout << BOLD << "> ";
    cin >> command;
    cout << RESETstring;
    return command;
}

void Game::executeCommand(string command) {
    // cout << "Executing command: " << command << endl;
    if (command == "EXIT" || command == "exit") {
        is_running = false;
    } else if (command == "NEXT") {
        Player::getCurrentPlayer()->NEXT();
    } else if (command == "CETAK_PENYIMPANAN"){
        Player::getCurrentPlayer()->CETAK_PENYIMPANAN();
    } else if (command == "PUNGUT_PAJAK"){
        Player::getCurrentPlayer()->PUNGUT_PAJAK();
    } else if (command == "CETAK_LADANG"){
        Player::getCurrentPlayer()->CETAK_LADANG();
    } else if (command == "CETAK_PETERNAKAN"){
        Player::getCurrentPlayer()->CETAK_PETERNAKAN();
    } else if (command == "TANAM"){
        Player::getCurrentPlayer()->TANAM();
    } else if (command == "TERNAK"){
        Player::getCurrentPlayer()->TERNAK();
    } else if (command == "BANGUN"){
        Player::getCurrentPlayer()->BANGUN();
    } else if (command == "MAKAN"){
        Player::getCurrentPlayer()->MAKAN();
    } else if (command == "KASIH_MAKAN"){
        Player::getCurrentPlayer()->KASIH_MAKAN();
    } else if (command == "BELI"){
        Player::getCurrentPlayer()->BELI();
    } else if (command == "JUAL"){
        Player::getCurrentPlayer()->JUAL();
    } else if (command == "PANEN"){
        Player::getCurrentPlayer()->PANEN();
    } else if (command == "SIMPAN"){
        Player::getCurrentPlayer()->SIMPAN();
    } else if (command == "TAMBAH_PEMAIN"){
        Player::getCurrentPlayer()->TAMBAH_PEMAIN();
    } else if (command == "SET"){
        Player::getCurrentPlayer()->SET();
    } else if (command == "GIVE"){
        Player::getCurrentPlayer()->GIVE();
    } else if (command == "STATS"){
        Player::getCurrentPlayer()->STATS();
    }
    else {
        cout << RED << "\nCommand not found\n" << RESETstring << endl;
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