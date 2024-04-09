
using namespace std;

class AmountNotValid : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Amount tidak valid!";
    }
};

class GuldenInvalid : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Gulden gak valid!";
    }
};