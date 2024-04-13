#ifndef INVENTORYEXCEPTION_HPP
#define INVENTORYEXCEPTION_HPP

#include "../../../../std.hpp"

class IsEmptySlotException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Kamu mengambil harapan kosong dari penyimpanan.";
    }
};

#endif

class InventorySizeNotValidException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Inventory size not valid";
    }
};

class SlotIsNotEmptyException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Slot sudah terisi.";
    }
};