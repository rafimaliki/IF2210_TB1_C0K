#ifndef WALIKOTA_EXCEPTION_HPP
#define WALIKOTA_EXCEPTION_HPP

#include "../../../../std.hpp"

class WalikotaException : public Exception {
    const char* what() const throw(){
        return "Empty";
    }
};


#endif