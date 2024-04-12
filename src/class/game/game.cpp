#include "game.hpp"

Game::Game()
{
    this->is_running = false;
}

void Game::start()
{

    try
    {

        GameConfig::loadGameConfig();
        Command::initCommand();

        Util::printTitle();

        string choice;
        do
        {
            cout << "Apakah Anda ingin memuat state? (Y/N): ";
            cin >> choice;

            if (choice == "Y" or choice == "y")
            {   
                try {
                    Muat::loadSaveFile();
                    
                } catch (FailReadFileException &e) {
                    cout << RED << e.what() << RESET << endl;
                }
                Game::startNewGame();
            }
            else if (choice == "N" or choice == "n")
            {
                Game::startNewGame();
            }

        } while (!(choice == "Y" or choice == "y") && !(choice == "N" or choice == "n"));

        this->is_running = true;
    }
    catch (FailReadFileException &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
    catch (...)
    {
        cout << RED << "FAIL!" << RESET << endl;
    }
}

void Game::startNewGame()
{
    Player *walikota = new Walikota("Walikota", 50, 40);
    Player *petani1 = new Petani("Petani1", 50, 40);
    Player *peternak1 = new Peternak("Peternak1", 50, 40);

    cout << "Memulai New Game!" << endl;
    cout << "\nGiliran player " << Player::players[0]->getName() << endl << endl;
}


string Game::inputCommand()
{
    string command;
    cout << BOLD << "> ";
    cin >> command;
    cout << RESET;
    return command;
}

void Game::executeCommand(string command)
{   
    try
    {
        if (command == "EXIT") {
            this->is_running = false;
            return;
        } else if (command == "SIMPAN") {
            Simpan::saveGame();
            this->is_running = false;
            return;
        }
        Command::execute(command);
    }
    catch (NoPermissionException &e)
    {
        cout << RED << e.what() << command << "\n"
             << RESET << endl;
    }
    catch (InvalidCommandException &e)
    {
        cout << RED << e.what() << RESET << endl;
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}

void Game::checkWin()
{
    int win_gold = GameConfig::miscConfig.getWIN_GOLD_NUMBER();
    int win_weight = GameConfig::miscConfig.getWIN_WEIGHT_NUMBER();

    if (Player::getCurrentPlayer()->getMoney() >= win_gold && Player::getCurrentPlayer()->getWeight() >= win_weight)
    {
        printWinner();
        this->is_running = false;
    }
}

void Game::printWinner()
{
    cout << "Player " << Player::getCurrentPlayer()->getName() << " menang!" << endl;
    cout << "Mengakhiri permainan" << endl;
}

bool Game::isRunning()
{
    return is_running;
}