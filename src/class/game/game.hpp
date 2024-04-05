#include "../../std.hpp"
#include "../gameobject/bangunan/bangunan.hpp"
#include "../gameobject/hewan/hewan.hpp"
#include "../gameobject/pemain/pemain.hpp"
#include "../gameobject/pemain/walikota.hpp"
#include "../gameobject/pemain/petani.hpp"
#include "../gameobject/pemain/peternak.hpp"
#include "../gameobject/produk/produk.hpp"
#include "../gameobject/tumbuhan/tumbuhan.hpp"
#include "../muat/config_reader.hpp"


class ItemData {
    public:
        int ID;
        string KODE_HURUF;
        string NAME;
        string TYPE;
        int PRICE;

        ItemData(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE){
            this->ID = ID;
            this->KODE_HURUF = KODE_HURUF;
            this->NAME = NAME;
            this->TYPE = TYPE;
            this->PRICE = PRICE;
        }
};

class PlantData : public ItemData{
    public:
        int DURATION_TO_HARVEST;

        PlantData(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE, int DURATION_TO_HARVEST) : ItemData(ID, KODE_HURUF, NAME, TYPE, PRICE){
            this->DURATION_TO_HARVEST = DURATION_TO_HARVEST;
        }

        static vector<PlantData> ReadPlantData(vector<vector<string>> data){
            vector<PlantData> plantData;
            for (const auto& row : data) {
                PlantData plant(stoi(row[0]), row[1], row[2], row[3], stoi(row[4]), stoi(row[5]));
                plantData.push_back(plant);
            }
            return plantData;
        }

        void print(){
            cout << "ID: " << this->ID << endl;
            cout << "KODE_HURUF: " << this->KODE_HURUF << endl;
            cout << "NAME: " << this->NAME << endl;
            cout << "TYPE: " << this->TYPE << endl;
            cout << "PRICE: " << this->PRICE << endl;
            cout << "DURATION_TO_HARVEST: " << this->DURATION_TO_HARVEST << endl << endl;
        }
};

class AnimalData : public ItemData{
    public:
        int WEIGHT_TO_HARVEST;

        AnimalData(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE, int WEIGHT_TO_HARVEST) : ItemData(ID, KODE_HURUF, NAME, TYPE, PRICE){
            this->WEIGHT_TO_HARVEST = WEIGHT_TO_HARVEST;
        }

        static vector<AnimalData> ReadAnimalData(vector<vector<string>> data){

            vector<AnimalData> animalData;
            for (const auto& row : data) {
                AnimalData animal(stoi(row[0]), row[1], row[2], row[3], stoi(row[4]), stoi(row[5]));
                animalData.push_back(animal);
            }
            return animalData;
        }

        void print(){
            cout << "ID: " << this->ID << endl;
            cout << "KODE_HURUF: " << this->KODE_HURUF << endl;
            cout << "NAME: " << this->NAME << endl;
            cout << "TYPE: " << this->TYPE << endl;
            cout << "PRICE: " << this->PRICE << endl;
            cout << "WEIGHT_TO_HARVEST: " << this->WEIGHT_TO_HARVEST << endl << endl;
        }
};

class ProductData : public ItemData{
    public:
        string ORIGIN;
        int ADDED_WEIGHT;

        ProductData(int ID, string KODE_HURUF, string NAME, string TYPE, string ORIGIN, int ADDED_WEIGHT, int PRICE) : ItemData(ID, KODE_HURUF, NAME, TYPE, PRICE){
            this->ORIGIN = ORIGIN;
            this->ADDED_WEIGHT = ADDED_WEIGHT;
        }

        static vector<ProductData> ReadProductData(vector<vector<string>> data){
            vector<ProductData> productData;
            for (const auto& row : data) {
                ProductData product(stoi(row[0]), row[1], row[2], row[3], row[4], stoi(row[5]), stoi(row[6]));
                productData.push_back(product);
            }
            return productData;
        }

        void print(){
            cout << "ID: " << this->ID << endl;
            cout << "KODE_HURUF: " << this->KODE_HURUF << endl;
            cout << "NAME: " << this->NAME << endl;
            cout << "TYPE: " << this->TYPE << endl;
            cout << "ORIGIN: " << this->ORIGIN << endl;
            cout << "ADDED_WEIGHT: " << this->ADDED_WEIGHT << endl;
            cout << "PRICE: " << this->PRICE << endl << endl;
        }
};

class Ingredient {
    public:
        string NAME;
        int QUANTITY;

        Ingredient(string NAME, int QUANTITY){
            this->NAME = NAME;
            this->QUANTITY = QUANTITY;
        }

        void print(){
            cout << "  NAME: " << this->NAME << endl;
            cout << "  QUANTITY: " << this->QUANTITY << endl;
        }
};

class RecipeData : public ItemData{
    public:
        vector<Ingredient> INGREDIENTS;

        RecipeData(int ID, string KODE_HURUF, string NAME, int PRICE, vector<Ingredient> INGREDIENTS , int PRICE_TO_SELL) : ItemData(ID, KODE_HURUF, NAME, "", PRICE){
            this->INGREDIENTS = INGREDIENTS;
        }

        static vector<RecipeData> ReadRecipeData(vector<vector<string>> data){
            vector<RecipeData> recipeData;
            for (const auto& row : data) {
                vector<Ingredient> ingredients;
                for (int i = 4; i < int(row.size()); i = i+2){
                    ingredients.push_back(Ingredient(row[i], stoi(row[i+1])));
                }
                RecipeData recipe(stoi(row[0]), row[1], row[2], stoi(row[3]), ingredients, stoi(row[5]));
                recipeData.push_back(recipe);
            }
            return recipeData;
        }

        void print(){
            cout << "ID: " << this->ID << endl;
            cout << "KODE_HURUF: " << this->KODE_HURUF << endl;
            cout << "NAME: " << this->NAME << endl;
            cout << "TYPE: " << this->TYPE << endl;
            cout << "PRICE: " << this->PRICE << endl;
            cout << "INGREDIENTS: " << endl;
            for (int i = 0 ; i < int(this->INGREDIENTS.size()); i++){
                this->INGREDIENTS[i].print();
            }
            cout << endl;
        }
};

class Game {
    private:
    
    public:

        vector<PlantData> plantData;
        vector<AnimalData> animalData;
        vector<ProductData> productData;
        vector<RecipeData> recipeData;

        Game(){
            cout << "A GAME IS CREATED" << endl << endl;
        }

        void loadData(){

            // Harus ditambah try catch, buat readernya

            ConfigReader animal_config("config/animal.txt");

            vector<vector<string>> animal_data = animal_config.readConfig();
            this->setAnimalData(AnimalData::ReadAnimalData(animal_data));
            
            // cout << "\n\x1b[32mANIMAL DATA: \x1b[0m\n" << endl;
            // for (int i = 0; i < int(this->animalData.size()) ; i++){
            //     this->animalData[i].print();
            // }
            cout << "\x1b[32mANIMAL DATA IS LOADED \x1b[0m" << endl;

            ConfigReader plant_config("config/plant.txt");

            vector<vector<string>> plant_data = plant_config.readConfig();
            this->setPlantData(PlantData::ReadPlantData(plant_data));

            // cout << "\n\x1b[32mPLANT DATA: \x1b[0m\n" << endl;
            // for (int i = 0; i < int(this->plantData.size()) ; i++){
            //     this->plantData[i].print();
            // }
            cout << "\x1b[32mPLANT DATA IS LOADED \x1b[0m" << endl;

            ConfigReader product_config("config/product.txt");

            vector<vector<string>> product_data = product_config.readConfig();
            this->setProductData(ProductData::ReadProductData(product_data));

            // cout << "\n\x1b[32mPRODUCT DATA: \x1b[0m\n" << endl;
            // for (int i = 0; i < int(this->productData.size()) ; i++){
            //     this->productData[i].print();
            // }
            cout << "\x1b[32mPRODUCT DATA IS LOADED \x1b[0m" << endl;

            ConfigReader recipe_config("config/recipe.txt");

            vector<vector<string>> recipe_data = recipe_config.readConfig();
            this->setRecipeData(RecipeData::ReadRecipeData(recipe_data));

            // cout << "\n\x1b[32mRECIPE DATA: \x1b[0m\n" << endl;
            // for (int i = 0; i < int(this->recipeData.size()) ; i++){
            //     this->recipeData[i].print();
            // }
            cout << "\x1b[32mRECIPE DATA IS LOADED \x1b[0m" << endl;
        }

        void setPlantData(vector<PlantData> plantData){
            this->plantData = plantData;
        }
        void setAnimalData(vector<AnimalData> animalData){
            this->animalData = animalData;
        }

        void setProductData(vector<ProductData> productData){
            this->productData = productData;
        }

        void setRecipeData(vector<RecipeData> recipeData){
            this->recipeData = recipeData;
        }
};