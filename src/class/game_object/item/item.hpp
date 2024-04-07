#ifndef ITEM_HPP
#define ITEM_HPP

#include "../../../std.hpp"
#include "../item_config/item_config.hpp"

#include <map> 

class Item
{
    private:
    public:
        Item();
        virtual void print();
        virtual ItemConfig* getConfig() = 0;
        virtual ~Item(); 
};
#endif
