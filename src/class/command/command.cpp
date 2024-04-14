// command.cpp

#include "command.hpp"

map<string, void (Player::*)()> Command::commands;

void Command::addCommand(const string& command, void (Player::*function)()) {
    commands[command] = function;
}

void Command::initCommand(){
    addCommand("NEXT", &Player::NEXT);
    addCommand("CETAK_PENYIMPANAN", &Player::CETAK_PENYIMPANAN);
    addCommand("PUNGUT_PAJAK", &Player::PUNGUT_PAJAK);
    addCommand("CETAK_LADANG", &Player::CETAK_LADANG);
    addCommand("CETAK_PETERNAKAN", &Player::CETAK_PETERNAKAN);
    addCommand("TANAM", &Player::TANAM);
    addCommand("TERNAK", &Player::TERNAK);
    addCommand("BANGUN", &Player::BANGUN);
    addCommand("MAKAN", &Player::MAKAN);
    addCommand("KASIH_MAKAN", &Player::KASIH_MAKAN);
    addCommand("BELI", &Player::BELI);
    addCommand("JUAL", &Player::JUAL);
    addCommand("PANEN", &Player::PANEN);
    addCommand("SIMPAN", &Player::SIMPAN);
    addCommand("TAMBAH_PEMAIN", &Player::TAMBAH_PEMAIN);
}

void Command::initCheat(){
    addCommand("SET", &Player::SET);
    addCommand("GIVE", &Player::GIVE);
    addCommand("STATS", &Player::STATS);
    addCommand("DELETE", &Player::DELETE);
}

void Command::execute(const string& command) {
    auto it = commands.find(command);

    if (it != commands.end()) {
        (Player::getCurrentPlayer()->*(it->second))();
    } else {
        throw InvalidCommandException();
    }
}


