#ifndef ITEM_CONFIG_HPP
#define ITEM_CONFIG_HPP

#include "../../../std.hpp"
#include "../../muat/config_reader.hpp"


class ItemConfig {
    protected:
        int ID;
        string KODE_HURUF;
        string NAME;
        int PRICE;

    public:
        ItemConfig(int ID, string KODE_HURUF, string NAME, int PRICE);
        virtual void print() = 0;

        int getID();
        string getKODE_HURUF();
        string getNAME();
        int getPRICE();

        // virtual string getTYPE();
        virtual int getDURATION_TO_HARVEST();
        virtual int getWEIGHT_TO_HARVEST();
        // virtual string getORIGIN();
        // virtual int getADDED_WEIGHT();
        // virtual vector<Ingredient> getINGREDIENTS();
};



class PlantConfig : public ItemConfig{
    private:
        string TYPE;
        int DURATION_TO_HARVEST;
    
    public:
        PlantConfig(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE, int DURATION_TO_HARVEST);
        static vector<PlantConfig> ReadPlantConfig(vector<vector<string>> Config);
        void print();

        string getTYPE();
        int getDURATION_TO_HARVEST();
};



class AnimalConfig : public ItemConfig{
    private:
        string TYPE;
        int WEIGHT_TO_HARVEST;

    public: 
        AnimalConfig(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE, int WEIGHT_TO_HARVEST);
        static vector<AnimalConfig> ReadAnimalConfig(vector<vector<string>> Config);
        void print();

        string getTYPE();
        int getWEIGHT_TO_HARVEST();
};



class ProductConfig : public ItemConfig{
    private:
        string TYPE;
        string ORIGIN;
        int ADDED_WEIGHT;

    public:
        ProductConfig(int ID, string KODE_HURUF, string NAME, string TYPE, string ORIGIN, int ADDED_WEIGHT, int PRICE);
        static vector<ProductConfig> ReadProductConfig(vector<vector<string>> Config);
        void print();

        string getTYPE();
        string getORIGIN();
        int getADDED_WEIGHT();
};



class Ingredient {
    private:
        string NAME;
        int QUANTITY;

    public:
        Ingredient(string NAME, int QUANTITY);
        void print();

        string getNAME();
        int getQUANTITY();
};



class RecipeConfig : public ItemConfig {
    private:
        vector<Ingredient> INGREDIENTS;

    public:
        RecipeConfig(int ID, string KODE_HURUF, string NAME, int PRICE, vector<Ingredient> INGREDIENTS , int PRICE_TO_SELL);
        static vector<RecipeConfig> ReadRecipeConfig(vector<vector<string>> Config);
        void print();

        // vector<Ingredient> getINGREDIENTS();
};



class MiscConfig {
    private:
        int WIN_GOLD_NUMBER;
        int WIN_WEIGHT_NUMBER;
        array<int, 2> INVENTORY_SIZE;
        array<int, 2> LAHAN_SIZE;
        array<int, 2> PETERNAKAN_SIZE;

    public:
        MiscConfig();
        MiscConfig(int WIN_GOLD_NUMBER, int WIN_WEIGHT_NUMBER, array<int, 2> INVENTORY_SIZE, array<int, 2> LAHAN_SIZE, array<int, 2> PETERNAKAN_SIZE);
        static MiscConfig ReadMiscConfig(vector<vector<string>> Config);
        void print();

        int getWIN_GOLD_NUMBER();
        int getWIN_WEIGHT_NUMBER();
        array<int, 2> getINVENTORY_SIZE();
        array<int, 2> getLAHAN_SIZE();
        array<int, 2> getPETERNAKAN_SIZE();
};



class GameConfig {
    private:
        static void setPlantConfig(vector<PlantConfig> plantConfig);
        static void setAnimalConfig(vector<AnimalConfig> animalConfig);
        static void setProductConfig(vector<ProductConfig> productConfig);
        static void setRecipeConfig(vector<RecipeConfig> recipeConfig);
        static void setMiscConfig(MiscConfig miscConfig);
        
    public:
        static vector<PlantConfig> plantConfig;
        static vector<AnimalConfig> animalConfig;
        static vector<ProductConfig> productConfig;
        static vector<RecipeConfig> recipeConfig;
        static MiscConfig miscConfig;

        GameConfig();
        static void loadGameConfig();
};

#endif