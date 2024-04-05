#include "Game.h"

// Initialize static members outside the class definition
std::vector<PlantData> Game::plantData;
std::vector<AnimalData> Game::animalData;
std::vector<ProductData> Game::productData;
std::vector<RecipeData> Game::recipeData;

Game::Game() {
    std::cout << "A game is Created" << std::endl;
}