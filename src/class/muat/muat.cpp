#include "muat.hpp"


Muat::Muat(string filename) : FileReader(filename) {}

bool Muat::isValidName(){

    // check dua char pertama "./" bukan
    if ((filename.length() <= 2) || filename.substr(0, 2) != "./"){
        return false;
    } 

    // menghilangkan "./" dari filename
    this->filename = this->filename.erase(0, 2);

    bool haveSlash = false;
    bool haveFolderName = false;
    bool haveFileName = false;

    // cek apakah ada folder name dan file name
    for (int i = 0; i < filename.length(); i++) {
        if (filename[i] != '/' && !haveSlash && !haveFileName) {
            haveFolderName = true;
        } else if (filename[i] == '/' && haveFolderName && !haveSlash && !haveFileName) {
            haveSlash = true;
        } else if (filename[i] != '/' && haveFolderName && haveSlash && !haveFileName) {
            haveFileName = true;
        }
    }

    if (!haveFileName) {
        return false;
    }

    ifstream file;
    file.open(filename);

    // cek folder valid dengan cara membuka file
    if (!file.is_open()) {
        return false;
    } else {
        file.close();
    }

    return true;
}

void Muat::loadSaveFile()
{   
    string filename;

    cout << "Masukkan lokasi berkas state : ";
    cin >> filename;

    Muat muat(filename);

    if (!muat.isValidName()) {
       throw FailReadFileException();
    }

    muat.data = muat.readFile();
    muat.spawnObject();
    

    // for (int i = 0; i < data.size(); i++) {
    //     for (int j = 0; j < data[i].size(); j++) {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "\nState berhasil dimuat\n" << endl;
}

void Muat::spawnObject(){
    cout << "Spawning object" << endl;
}