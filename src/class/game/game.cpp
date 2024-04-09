#include "game.hpp"

Game::Game() {
    this->is_running = false;
}

void Game::start() {
    this->is_running = true;

    cout << "Game started!\n" << endl;

    loadConfig();
    loadSaveFile();
    Command::initCommand();

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
    cout << RESET;
    return command;
}

void Game::executeCommand(string command) {

    if (command == "EXIT") {
        this->is_running = false;
        return;
    }
    
    try {
        Command::execute(command);
    } catch (NoPermissionException& e) {
        cout << RED << e.what() << command << "\n" << RESET << endl;
    } catch (InvalidCommandException& e) {
        cout << RED << e.what() << RESET << endl;
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