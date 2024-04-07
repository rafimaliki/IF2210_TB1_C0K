#ifndef ITEM_CONFIG_HPP
#define ITEM_CONFIG_HPP

#include "../../../std.hpp"
#include "../../muat/config_reader.hpp"

class ItemConfig {
    public:
        int ID;
        string KODE_HURUF;
        string NAME;
        int PRICE;

        ItemConfig(int ID, string KODE_HURUF, string NAME, int PRICE);
};



class PlantConfig : public ItemConfig{
    public:
        string TYPE;
        int DURATION_TO_HARVEST;

        PlantConfig(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE, int DURATION_TO_HARVEST);
        static vector<PlantConfig> ReadPlantConfig(vector<vector<string>> Config);
        void print();
};



class AnimalConfig : public ItemConfig{
    public:
        string TYPE;
        int WEIGHT_TO_HARVEST;

        AnimalConfig(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE, int WEIGHT_TO_HARVEST);
        static vector<AnimalConfig> ReadAnimalConfig(vector<vector<string>> Config);
        void print();
};



class ProductConfig : public ItemConfig{
    public:
        string TYPE;
        string ORIGIN;
        int ADDED_WEIGHT;

        ProductConfig(int ID, string KODE_HURUF, string NAME, string TYPE, string ORIGIN, int ADDED_WEIGHT, int PRICE);
        static vector<ProductConfig> ReadProductConfig(vector<vector<string>> Config);
        void print();
};



class Ingredient {
    public:
        string NAME;
        int QUANTITY;

        Ingredient(string NAME, int QUANTITY);
        void print();
};



class RecipeConfig : public ItemConfig {
    public:
        vector<Ingredient> INGREDIENTS;

        RecipeConfig(int ID, string KODE_HURUF, string NAME, int PRICE, vector<Ingredient> INGREDIENTS , int PRICE_TO_SELL);
        static vector<RecipeConfig> ReadRecipeConfig(vector<vector<string>> Config);
        void print();
};



class MiscConfig {
    public:
        int WIN_GOLD_NUMBER;
        int WIN_WEIGHT_NUMBER;
        array<int, 2> INVENTORY_sIZE;
        array<int, 2> LAHAN_SIZE;
        array<int, 2> PETERNAKAN_SIZE;

        MiscConfig();
        MiscConfig(int WIN_GOLD_NUMBER, int WIN_WEIGHT_NUMBER, array<int, 2> INVENTORY_sIZE, array<int, 2> LAHAN_SIZE, array<int, 2> PETERNAKAN_SIZE);
        static MiscConfig ReadMiscConfig(vector<vector<string>> Config);
        void print();
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