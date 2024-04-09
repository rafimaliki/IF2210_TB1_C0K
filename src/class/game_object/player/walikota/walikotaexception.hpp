#ifndef WALIKOTA_EXCEPTION_HPP
#define WALIKOTA_EXCEPTION_HPP

#include "../../../../std.hpp"

class InvalidBuildingNameException : public exception {
    public:
        const char* what() const throw(){
            return "Kamu tidak punya resep bangunan tersebut!";
        }
};

class NotEnoughMoneyException : public exception {
    public:
        const char* what() const throw(){
            return "Kamu tidak punya uang yang cukup!";
        }
};

class NotEnoughItemException : public exception {
    public:
        const char* what() const throw(){
            return "Silakan pilih bangunan lain!";
        }
};


#endif