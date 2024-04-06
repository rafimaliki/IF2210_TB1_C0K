#include "item_config.hpp"

/* ItemConfig */
ItemConfig::ItemConfig(int ID, string KODE_HURUF, string NAME, int PRICE){
    this->ID = ID;
    this->KODE_HURUF = KODE_HURUF;
    this->NAME = NAME;
    this->PRICE = PRICE;
}



/* PlantConfig */
PlantConfig::PlantConfig(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE, int DURATION_TO_HARVEST) : ItemConfig(ID, KODE_HURUF, NAME, PRICE){
    this->TYPE = TYPE;
    this->DURATION_TO_HARVEST = DURATION_TO_HARVEST;
}

vector<PlantConfig> PlantConfig::ReadPlantConfig(vector<vector<string>> Config){
    vector<PlantConfig> plantConfig;
    for (const auto& row : Config) {
        PlantConfig plant(stoi(row[0]), row[1], row[2], row[3], stoi(row[4]), stoi(row[5]));
        plantConfig.push_back(plant);
    }
    return plantConfig;
}

void PlantConfig::print(){
    cout << "ID: " << this->ID << endl;
    cout << "KODE_HURUF: " << this->KODE_HURUF << endl;
    cout << "NAME: " << this->NAME << endl;
    cout << "TYPE: " << this->TYPE << endl;
    cout << "PRICE: " << this->PRICE << endl;
    cout << "DURATION_TO_HARVEST: " << this->DURATION_TO_HARVEST << endl << endl;
}



/* AnimalConfig */
AnimalConfig::AnimalConfig(int ID, string KODE_HURUF, string NAME, string TYPE, int PRICE, int WEIGHT_TO_HARVEST) : ItemConfig(ID, KODE_HURUF, NAME, PRICE){
    this->TYPE = TYPE;
    this->WEIGHT_TO_HARVEST = WEIGHT_TO_HARVEST;
}

vector<AnimalConfig> AnimalConfig::ReadAnimalConfig(vector<vector<string>> Config){
    vector<AnimalConfig> animalConfig;
    for (const auto& row : Config) {
        AnimalConfig animal(stoi(row[0]), row[1], row[2], row[3], stoi(row[4]), stoi(row[5]));
        animalConfig.push_back(animal);
    }
    return animalConfig;
}

void AnimalConfig::print(){
    cout << "ID: " << this->ID << endl;
    cout << "KODE_HURUF: " << this->KODE_HURUF << endl;
    cout << "NAME: " << this->NAME << endl;
    cout << "TYPE: " << this->TYPE << endl;
    cout << "PRICE: " << this->PRICE << endl;
    cout << "WEIGHT_TO_HARVEST: " << this->WEIGHT_TO_HARVEST << endl << endl;
}



/* ProductConfig */
ProductConfig::ProductConfig(int ID, string KODE_HURUF, string NAME, string TYPE, string ORIGIN, int ADDED_WEIGHT, int PRICE) : ItemConfig(ID, KODE_HURUF, NAME, PRICE){
    this->TYPE = TYPE;
    this->ORIGIN = ORIGIN;
    this->ADDED_WEIGHT = ADDED_WEIGHT;
}

vector<ProductConfig> ProductConfig::ReadProductConfig(vector<vector<string>> Config){
    vector<ProductConfig> productConfig;
    for (const auto& row : Config) {
        ProductConfig product(stoi(row[0]), row[1], row[2], row[3], row[4], stoi(row[5]), stoi(row[6]));
        productConfig.push_back(product);
    }
    return productConfig;
}

void ProductConfig::print(){
    cout << "ID: " << this->ID << endl;
    cout << "KODE_HURUF: " << this->KODE_HURUF << endl;
    cout << "NAME: " << this->NAME << endl;
    cout << "TYPE: " << this->TYPE << endl;
    cout << "ORIGIN: " << this->ORIGIN << endl;
    cout << "ADDED_WEIGHT: " << this->ADDED_WEIGHT << endl;
    cout << "PRICE: " << this->PRICE << endl << endl;
}



/* Ingredient */
Ingredient::Ingredient(string NAME, int QUANTITY){
    this->NAME = NAME;
    this->QUANTITY = QUANTITY;
}

void Ingredient::print(){
    cout << "  NAME: " << this->NAME << endl;
    cout << "  QUANTITY: " << this->QUANTITY << endl;
}



/* RecipeConfig */
RecipeConfig::RecipeConfig(int ID, string KODE_HURUF, string NAME, int PRICE, vector<Ingredient> INGREDIENTS , int PRICE_TO_SELL) : ItemConfig(ID, KODE_HURUF, NAME, PRICE){
    this->INGREDIENTS = INGREDIENTS;
}

vector<RecipeConfig>  RecipeConfig::ReadRecipeConfig(vector<vector<string>> Config){
    vector<RecipeConfig> recipeConfig;
    for (const auto& row : Config) {
        vector<Ingredient> ingredients;
        for (int i = 4; i < int(row.size()); i = i+2){
            ingredients.push_back(Ingredient(row[i], stoi(row[i+1])));
        }
        RecipeConfig recipe(stoi(row[0]), row[1], row[2], stoi(row[3]), ingredients, stoi(row[5]));
        recipeConfig.push_back(recipe);
    }
    return recipeConfig;
}

void RecipeConfig::print(){
    cout << "ID: " << this->ID << endl;
    cout << "KODE_HURUF: " << this->KODE_HURUF << endl;
    cout << "NAME: " << this->NAME << endl;
    cout << "PRICE: " << this->PRICE << endl;
    cout << "INGREDIENTS: " << endl;
    for (int i = 0 ; i < int(this->INGREDIENTS.size()); i++){
        this->INGREDIENTS[i].print();
    }
    cout << endl;
}



/* GameConfig */

vector<PlantConfig> GameConfig::plantConfig;
vector<AnimalConfig> GameConfig::animalConfig;
vector<ProductConfig> GameConfig::productConfig;
vector<RecipeConfig> GameConfig::recipeConfig;

GameConfig::GameConfig(){
}

void GameConfig::loadGameConfig(){

    // Tambah try catch disini untuk setiap config file
    ConfigReader animal_config("config/animal.txt");

    vector<vector<string>> animal_Config = animal_config.readConfig();
    GameConfig::setAnimalConfig(AnimalConfig::ReadAnimalConfig(animal_Config));
    
    // cout << "\n\x1b[32mANIMAL Config: \x1b[0m\n" << endl;
    // for (int i = 0; i < int(GameConfig::animalConfig.size()) ; i++){
    //     GameConfig::animalConfig[i].print();
    // }
    cout << "\x1b[32mANIMAL Config IS LOADED \x1b[0m" << endl;

    ConfigReader plant_config("config/plant.txt");

    vector<vector<string>> plant_Config = plant_config.readConfig();
    GameConfig::setPlantConfig(PlantConfig::ReadPlantConfig(plant_Config));

    // cout << "\n\x1b[32mPLANT Config: \x1b[0m\n" << endl;
    // for (int i = 0; i < int(GameConfig::plantConfig.size()) ; i++){
    //     GameConfig::plantConfig[i].print();
    // }
    cout << "\x1b[32mPLANT Config IS LOADED \x1b[0m" << endl;

    ConfigReader product_config("config/product.txt");

    vector<vector<string>> product_Config = product_config.readConfig();
    GameConfig::setProductConfig(ProductConfig::ReadProductConfig(product_Config));

    // cout << "\n\x1b[32mPRODUCT Config: \x1b[0m\n" << endl;
    // for (int i = 0; i < int(GameConfig::productConfig.size()) ; i++){
    //     GameConfig::productConfig[i].print();
    // }
    cout << "\x1b[32mPRODUCT Config IS LOADED \x1b[0m" << endl;

    ConfigReader recipe_config("config/recipe.txt");

    vector<vector<string>> recipe_Config = recipe_config.readConfig();
    GameConfig::setRecipeConfig(RecipeConfig::ReadRecipeConfig(recipe_Config));

    // cout << "\n\x1b[32mRECIPE Config: \x1b[0m\n" << endl;
    // for (int i = 0; i < int(GameConfig::recipeConfig.size()) ; i++){
    //     GameConfig::recipeConfig[i].print();
    // }
    cout << "\x1b[32mRECIPE Config IS LOADED \x1b[0m" << endl;
}
void GameConfig::setPlantConfig(vector<PlantConfig> plantConfig){
    GameConfig::plantConfig = plantConfig;
}
void GameConfig::setAnimalConfig(vector<AnimalConfig> animalConfig){
    GameConfig::animalConfig = animalConfig;
}

void GameConfig::setProductConfig(vector<ProductConfig> productConfig){
    GameConfig::productConfig = productConfig;
}

void GameConfig::setRecipeConfig(vector<RecipeConfig> recipeConfig){
    GameConfig::recipeConfig = recipeConfig;
}
