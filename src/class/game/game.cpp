#include "game.hpp"

Game::Game() {
    this->is_running = false;
}

void Game::start() {
    this->is_running = true;

    cout << "Game started!\n" << endl;

    loadConfig();
    loadSaveFile();
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
        cout << "\033[1;33mAnother day has passed...\033[0m\n";
        Plant::AgeAllPlants();
    } 
}

void Game::checkWin() {
    cout << "\nChecking win...\n" << endl;
}

void Game::printWinner() {
    cout << "Printing winner..." << endl;
}

bool Game::isRunning() {
    return is_running;
}