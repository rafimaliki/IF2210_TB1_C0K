#include "../../std.hpp"

class InvalidIndexException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid Index!\n";
    }
};

class NotNumberException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Input is not a number!\n";
    }
};

class RoleNotValid : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Role tidak sesuai!\n";
    }
};
