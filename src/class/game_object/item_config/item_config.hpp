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



class GameConfig {
    public:
        vector<PlantConfig> plantConfig;
        vector<AnimalConfig> animalConfig;
        vector<ProductConfig> productConfig;
        vector<RecipeConfig> recipeConfig;

        GameConfig();
        void loadGameConfig();
        void setPlantConfig(vector<PlantConfig> plantConfig);
        void setAnimalConfig(vector<AnimalConfig> animalConfig);
        void setProductConfig(vector<ProductConfig> productConfig);
        void setRecipeConfig(vector<RecipeConfig> recipeConfig);
};

#endif

// class Game {
//     private:
    
//     public:

//         vector<PlantConfig> plantConfig;
//         vector<AnimalConfig> animalConfig;
//         vector<ProductConfig> productConfig;
//         vector<RecipeConfig> recipeConfig;

//         Game(){
//             cout << "A GAME IS CREATED" << endl << endl;
//         }



//         void loadConfig(){

//             // Harus ditambah try catch, buat readernya

//             ConfigReader animal_config("config/animal.txt");

//             vector<vector<string>> animal_Config = animal_config.readConfig();
//             this->setAnimalConfig(AnimalConfig::ReadAnimalConfig(animal_Config));
            
//             cout << "\n\x1b[32mANIMAL Config: \x1b[0m\n" << endl;
//             for (int i = 0; i < int(this->animalConfig.size()) ; i++){
//                 this->animalConfig[i].print();
//             }
//             cout << "\x1b[32mANIMAL Config IS LOADED \x1b[0m" << endl;

//             ConfigReader plant_config("config/plant.txt");

//             vector<vector<string>> plant_Config = plant_config.readConfig();
//             this->setPlantConfig(PlantConfig::ReadPlantConfig(plant_Config));

//             // cout << "\n\x1b[32mPLANT Config: \x1b[0m\n" << endl;
//             // for (int i = 0; i < int(this->plantConfig.size()) ; i++){
//             //     this->plantConfig[i].print();
//             // }
//             cout << "\x1b[32mPLANT Config IS LOADED \x1b[0m" << endl;

//             ConfigReader product_config("config/product.txt");

//             vector<vector<string>> product_Config = product_config.readConfig();
//             this->setProductConfig(ProductConfig::ReadProductConfig(product_Config));

//             // cout << "\n\x1b[32mPRODUCT Config: \x1b[0m\n" << endl;
//             // for (int i = 0; i < int(this->productConfig.size()) ; i++){
//             //     this->productConfig[i].print();
//             // }
//             cout << "\x1b[32mPRODUCT Config IS LOADED \x1b[0m" << endl;

//             ConfigReader recipe_config("config/recipe.txt");

//             vector<vector<string>> recipe_Config = recipe_config.readConfig();
//             this->setRecipeConfig(RecipeConfig::ReadRecipeConfig(recipe_Config));

//             // cout << "\n\x1b[32mRECIPE Config: \x1b[0m\n" << endl;
//             // for (int i = 0; i < int(this->recipeConfig.size()) ; i++){
//             //     this->recipeConfig[i].print();
//             // }
//             cout << "\x1b[32mRECIPE Config IS LOADED \x1b[0m" << endl;
//         }

//         void setPlantConfig(vector<PlantConfig> plantConfig){
//             this->plantConfig = plantConfig;
//         }
//         void setAnimalConfig(vector<AnimalConfig> animalConfig){
//             this->animalConfig = animalConfig;
//         }

//         void setProductConfig(vector<ProductConfig> productConfig){
//             this->productConfig = productConfig;
//         }

//         void setRecipeConfig(vector<RecipeConfig> recipeConfig){
//             this->recipeConfig = recipeConfig;
//         }
// };