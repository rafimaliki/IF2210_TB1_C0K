#include "item_config.hpp"

/* ItemConfig */
ItemConfig::ItemConfig(int ID, string KODE_HURUF, string NAME, int PRICE){
    this->ID = ID;
    this->KODE_HURUF = KODE_HURUF;
    this->NAME = NAME;
    this->PRICE = PRICE;
}

int ItemConfig::getID(){
    return this->ID;
}

string ItemConfig::getKODE_HURUF(){
    return this->KODE_HURUF;
}

string ItemConfig::getNAME(){
    return this->NAME;
}

int ItemConfig::getPRICE(){
    return this->PRICE;
}

string ItemConfig::getTYPE(){
    return "";
}

int ItemConfig::getDURATION_TO_HARVEST(){
    return 0;
}

int ItemConfig::getWEIGHT_TO_HARVEST(){
    return 0;
}

string ItemConfig::getORIGIN(){
    return "";
}

int ItemConfig::getADDED_WEIGHT(){
    return 0;
}

vector<Ingredient> ItemConfig::getINGREDIENTS(){
    return vector<Ingredient>();
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
    cout << "DURATION_TO_HARVEST: " << this->DURATION_TO_HARVEST << endl;
}

string PlantConfig::getTYPE(){
    return this->TYPE;
}

int PlantConfig::getDURATION_TO_HARVEST(){
    return this->DURATION_TO_HARVEST;
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
    cout << "WEIGHT_TO_HARVEST: " << this->WEIGHT_TO_HARVEST << endl;
}

string AnimalConfig::getTYPE(){
    return this->TYPE;
}

int AnimalConfig::getWEIGHT_TO_HARVEST(){
    return this->WEIGHT_TO_HARVEST;
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
    cout << "PRICE: " << this->PRICE << endl;
}

string ProductConfig::getTYPE(){
    return this->TYPE;
}

string ProductConfig::getORIGIN(){
    return this->ORIGIN;
}

int ProductConfig::getADDED_WEIGHT(){
    return this->ADDED_WEIGHT;
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

string Ingredient::getNAME(){
    return this->NAME;
}

int Ingredient::getQUANTITY(){
    return this->QUANTITY;
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

vector<Ingredient> RecipeConfig::getINGREDIENTS(){
    return this->INGREDIENTS;
}





/* Misc Config */

MiscConfig::MiscConfig(){
}

MiscConfig::MiscConfig(int WIN_GOLD_NUMBER, int WIN_WEIGHT_NUMBER, array<int, 2> INVENTORY_SIZE, array<int, 2> LADANG_SIZE, array<int, 2> PETERNAKAN_SIZE){
    this->WIN_GOLD_NUMBER = WIN_GOLD_NUMBER;
    this->WIN_WEIGHT_NUMBER = WIN_WEIGHT_NUMBER;
    this->INVENTORY_SIZE = INVENTORY_SIZE;
    this->LADANG_SIZE = LADANG_SIZE;
    this->PETERNAKAN_SIZE = PETERNAKAN_SIZE;
}

MiscConfig MiscConfig::ReadMiscConfig(vector<vector<string>> Config){
    MiscConfig miscConfig(stoi(Config[0][0]), stoi(Config[1][0]), {stoi(Config[2][0]), stoi(Config[2][1])}, {stoi(Config[3][0]), stoi(Config[3][1])}, {stoi(Config[4][0]), stoi(Config[4][1])});
    return miscConfig;
}

void MiscConfig::print(){
    cout << "WIN_GOLD_NUMBER: " << this->WIN_GOLD_NUMBER << endl;
    cout << "WIN_WEIGHT_NUMBER: " << this->WIN_WEIGHT_NUMBER << endl;
    cout << "INVENTORY_SIZE: " << this->INVENTORY_SIZE[0] << "x" << this->INVENTORY_SIZE[1] << endl;
    cout << "LADANG_SIZE: " << this->LADANG_SIZE[0] << "x" << this->LADANG_SIZE[1] << endl;
    cout << "PETERNAKAN_SIZE: " << this->PETERNAKAN_SIZE[0] << "x" << this->PETERNAKAN_SIZE[1] << endl;
}

int MiscConfig::getWIN_GOLD_NUMBER(){
    return this->WIN_GOLD_NUMBER;
}

int MiscConfig::getWIN_WEIGHT_NUMBER(){
    return this->WIN_WEIGHT_NUMBER;
}

array<int, 2> MiscConfig::getINVENTORY_SIZE(){
    return this->INVENTORY_SIZE;
}

array<int, 2> MiscConfig::getLADANG_SIZE(){
    return this->LADANG_SIZE;
}

array<int, 2> MiscConfig::getPETERNAKAN_SIZE(){
    return this->PETERNAKAN_SIZE;
}


/* GameConfig */

vector<PlantConfig> GameConfig::plantConfig;
vector<AnimalConfig> GameConfig::animalConfig;
vector<ProductConfig> GameConfig::productConfig;
vector<RecipeConfig> GameConfig::recipeConfig;
MiscConfig GameConfig::miscConfig;

GameConfig::GameConfig(){
}

void GameConfig::loadGameConfig(){

    string SUCCESS = GREEN + "SUCCES!\n" + RESET; 

    /* Animal Config */

    cout << "\nReading Animal Config ";
    FileReader animal_config("config/animal.txt");

    vector<vector<string>> animal_Config = animal_config.readFile();
    GameConfig::setAnimalConfig(AnimalConfig::ReadAnimalConfig(animal_Config));
    
    cout << SUCCESS;

    /* Plant Config */
    cout << "Reading Plant Config ";
    FileReader plant_config("config/plant.txt");

    vector<vector<string>> plant_Config = plant_config.readFile();
    GameConfig::setPlantConfig(PlantConfig::ReadPlantConfig(plant_Config));

    cout << SUCCESS;


    /* Product Config */
    cout << "Reading Product Config ";
    FileReader product_config("config/product.txt");

    vector<vector<string>> product_Config = product_config.readFile();

    GameConfig::setProductConfig(ProductConfig::ReadProductConfig(product_Config));

    cout << SUCCESS;

    /* Recipe Config */
    cout << "Reading Recipe Config ";
    FileReader recipe_config("config/recipe.txt");

    vector<vector<string>> recipe_Config = recipe_config.readFile();
    GameConfig::setRecipeConfig(RecipeConfig::ReadRecipeConfig(recipe_Config));

    cout << SUCCESS;

    /* Misc Config */
    cout << "Reading Misc Config ";
    FileReader misc_config("config/misc.txt");

    vector<vector<string>> misc_Config = misc_config.readFile();
    GameConfig::setMiscConfig(MiscConfig::ReadMiscConfig(misc_Config));

    cout << SUCCESS;
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

void GameConfig::setMiscConfig(MiscConfig miscConfig){
    GameConfig::miscConfig = miscConfig;
}
