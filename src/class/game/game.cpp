#include "game.hpp"

Game::Game(){
    this->is_running = false;
    this->command = "";
}

void Game::start(){   
    try {
        GameConfig::loadGameConfig();
        Command::initCommand();
        Command::initCheat();
        Util::printTitle();
        Game::loadGameData();

        this->is_running = true; 
    } catch (FailReadFileException &e) { 
        Util::printColor(e.what(), RED);
    } catch (InvalidDataException &e) {
        Util::printColor(e.what(), RED);
    }
}

Game::~Game(){
    destroyObject();
}

void Game::destroyObject(){
    // destroy player 
    for (int i = 0; i < Player::players.size(); i++){
        delete Player::players[i];
    }
    Player::players.clear();

    // destroy plant
    for (int i = 0; i < Plant::plants.size(); i++){
        delete Plant::plants[i];
    }
    Plant::plants.clear();

    // destroy animal
    for (int i = 0; i < Animal::animals.size(); i++){
        delete Animal::animals[i];
    }
    Animal::animals.clear();

    // destroy bangunan
    for (int i = 0; i < Bangunan::daftar_bangunan.size(); i++){
        delete Bangunan::daftar_bangunan[i];
    }
    Bangunan::daftar_bangunan.clear();

    // destroy product 
    for (int i = 0; i < Product::products.size(); i++){
        delete Product::products[i];
    }
    Product::products.clear();
}

void Game::startNewGame(){
    Player *walikota = new Walikota("Walikota", 50, 40);
    Player *petani1 = new Petani("Petani1", 50, 40);
    Player *peternak1 = new Peternak("Peternak1", 50, 40);

    cout << "Memulai New Game!" << endl;
    cout << "\nGiliran player " << Player::players[0]->getName() << endl << endl;
}


void Game::inputCommand(){
    cout << BOLD << "> ";
    cin >> this->command;
    cout << RESET;
}

void Game::executeCommand(){   

    try{
        if (this->command == "EXIT") {
            this->is_running = false;
        } else if (this->command == "SIMPAN") {
            Simpan::saveGame();
            this->is_running = false;
        } else {
            Command::execute(this->command);
        }
    } catch (NoPermissionException &e){   
        Util::printColor(e.what() + this->command + "\n", RED); cout << endl;
    } catch (InvalidCommandException &e){   
        Util::printColor(e.what(), RED); cout << endl;
    } catch (const exception &e){
        Util::printColor(e.what(), RED); cout << endl;
    }
}

void Game::checkWin(){

    int win_gold = GameConfig::miscConfig.getWIN_GOLD_NUMBER();
    int win_weight = GameConfig::miscConfig.getWIN_WEIGHT_NUMBER();

    if (Player::getCurrentPlayer()->getMoney() >= win_gold && Player::getCurrentPlayer()->getWeight() >= win_weight){
        printWinner();
        this->is_running = false;
    }
}

void Game::printWinner(){
    cout << "Player " << Player::getCurrentPlayer()->getName() << " menang!" << endl;
    cout << "Mengakhiri permainan" << endl;
}

bool Game::isRunning(){
    return is_running;
}

void Game::loadGameData(){
    string choice;
    bool valid = false;
    
    do {
        cout << "Apakah Anda ingin memuat state? (Y/N): ";
        cin >> choice;

        if (choice == "Y") {   
            try {
                Muat::loadSaveFile();
                valid = true;
                cout << "Giliran player " << Player::players[0]->getName() << endl << endl;

            } catch (const exception &e){
                Util::printColor(e.what(), RED);
            }
        } else if (choice == "N") {
            Game::startNewGame();
            valid = true;
        } 
        // else if (choice == "ENABLE_CHEAT"){ // Enable cheat easter egg <GIVE, SET, DELETE, STATS> method
        //     Command::initCheat();
        //     Util::printColor("Cheat enabled!\n", GREEN);
        // }
    } while ((!(choice == "Y") && !(choice == "N")) || !valid);
}