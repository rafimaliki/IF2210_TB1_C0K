#include "game.hpp"

Game::Game(){
    this->is_running = false;
    this->command = "";
}

void Game::start(){   
    try {
        GameConfig::loadGameConfig();
        Command::initCommand();
        Util::printTitle();
        Game::loadGameData();

        this->is_running = true;

    } catch (FailReadFileException &e) { 
        Util::printColor(e.what(), RED);
    }
     catch (InvalidDataException &e) {
        Util::printColor(e.what(), RED);
    }
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
    }
    catch (NoPermissionException &e){   
        Util::printColor(e.what() + this->command + "\n", RED); cout << endl;
    }
    catch (InvalidCommandException &e){   
        Util::printColor(e.what(), RED); cout << endl;
    }
    catch (const exception &e){
        cout << e.what() << endl;
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

        if (choice == "Y" or choice == "y")
        {   
            try {
                Muat::loadSaveFile();
                valid = true;
                cout << "Giliran player " << Player::players[0]->getName() << endl << endl;

            } catch (const exception &e){
                Util::printColor(e.what(), RED);
            }
        }
        else if (choice == "N" or choice == "n") {
            Game::startNewGame();
            valid = true;
        }

    } while ((!(choice == "Y" or choice == "y") && !(choice == "N" or choice == "n")) || !valid);
}