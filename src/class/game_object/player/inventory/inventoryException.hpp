#ifndef INVENTORYEXCEPTION_HPP
#define INVENTORYEXCEPTION_HPP

#include "../../../../std.hpp"

class IndexNotValidException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Index not valid";
    }
};

class IsEmptySlotException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Kamu mengambil harapan kosong dari penyimpanan.";
    }
};

#endif

class InventorySizeNotValidException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Inventory size not valid";
    }
};

class SlotEmptyException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Slot is empty!";
    }
};