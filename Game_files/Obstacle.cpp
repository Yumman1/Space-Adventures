// Obstacle.cpp

// Include the header file for Obstacle
#include "Obstacle.hpp"

// Include necessary headers
#include <SDL_image.h>
#include <iostream>


// Constructor for Obstacle
Obstacle::Obstacle(SDL_Renderer* renderer, const std::string& imagePath, int x, int y) {
    // Load the image surface
    SDL_Surface* loadedSurface = IMG_Load(imagePath.c_str());

    // Check if the surface is loaded successfully
    if (loadedSurface != nullptr) {
        // Create a texture from the surface
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        // Free the loaded surface
        SDL_FreeSurface(loadedSurface);
        // Check if the texture creation is successful
        if (texture == nullptr) {
            std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        }
    } else {
        std::cerr << "Failed to load obstacle image: " << IMG_GetError() << std::endl;
    }

    // Set initial position
    xPosition = x;
    yPosition = y;
}

// Destructor for Obstacle
Obstacle::~Obstacle() {
    // Destroy the texture to release resources
    SDL_DestroyTexture(texture);
}

// Function to render the obstacle on the screen with a default size
void Obstacle::render(SDL_Renderer* renderer) {
    SDL_Rect dstRect = {xPosition, yPosition, 75, 75}; // Default size
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
}

// Function to render the obstacle on the screen with a custom size
void Obstacle::render1(SDL_Renderer* renderer, int a, int b) {
    SDL_Rect dstRect = {xPosition, yPosition, a, b}; // Custom size
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
}

void Obstacle::update() {}


// Function to destroy the rendered image and set the texture to nullptr
void Obstacle::destroy() {
    SDL_DestroyTexture(texture);
    texture = nullptr; // Set to nullptr to avoid using the destroyed texture
}
