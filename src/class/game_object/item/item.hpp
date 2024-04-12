#ifndef ITEM_HPP
#define ITEM_HPP

#include "../../../std.hpp"
#include "../item_config/item_config.hpp"

class Item
{
    private:
    public:
        Item();
        virtual ~Item() = 0; 

        virtual void print();

        virtual ItemConfig* getConfig() = 0;
        virtual void setPlanted(bool isPlanted);
        virtual void setIsInCage(bool isInCage);
        virtual void printKODE_HURUF();
        virtual bool isReadyToHarvest();

        /* GETTER */
        virtual int getID();
        virtual string getKODE_HURUF();
        virtual string getNAME();
        virtual int getPRICE();
        virtual string getTYPE();
        virtual int getDURATION_TO_HARVEST();
        virtual int getWEIGHT_TO_HARVEST();
        virtual string getORIGIN();
        virtual int getADDED_WEIGHT();

        bool isFood();
        bool isPlant();
        bool isAnimal();

        static vector<string> getTYPE_IDbyNAME(string name);


};
#endif
