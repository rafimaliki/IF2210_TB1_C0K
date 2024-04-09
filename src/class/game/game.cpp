#include "game.hpp"

Game::Game()
{
    this->is_running = false;
}

void Game::start()
{

    try
    {

        loadConfig();
        Command::initCommand();

        Util::printTitle();

        string choice;
        do
        {
            cout << "\nApakah Anda ingin memuat state? (Y/N): ";
            cin >> choice;

            if (choice == "Y" or choice == "y")
            {
                Game::loadSaveFile();
            }
            else
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
}

void Game::startNewGame()
{
    Player *walikota = new Walikota("Walikota", 50, 40);
    Player *petani1 = new Petani("Pak Tani", 50, 40);
    Player *peternak1 = new Peternak("Tukang Sapi", 50, 40);

    cout << "Memulai New Game!" << endl;
    cout << "\nGiliran player " << Player::players[0]->getName() << endl;
}

void Game::loadConfig()
{
    // cout << "Loading config...\n" << endl;
    GameConfig::loadGameConfig();
}

void Game::loadSaveFile()
{

    cout << "Masukkan lokasi berkas state : ";

    string lokasi;
    cin >> lokasi;

    cout << "\nFile tidak ditemukan!" << endl;
    Game::startNewGame();
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

    if (command == "EXIT")
    {
        this->is_running = false;
        return;
    }

    try
    {
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
    // cout << "\nChecking win...\n" << endl;
}

void Game::printWinner()
{
    cout << "Printing winner..." << endl;
}

bool Game::isRunning()
{
    return is_running;
}