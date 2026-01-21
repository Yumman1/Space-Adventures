
// Spaceship.cpp
#include "spaceship.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <algorithm>



const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;

//constuctor for the spaceship class
Spaceship::Spaceship(SDL_Renderer* renderer, const std::string& imagePath, int x, int y){

    SDL_Surface* loadedSurface = IMG_Load(imagePath.c_str());
    if (loadedSurface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);

        if (texture == nullptr) {
            std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        }
    } else {
        std::cerr << "Failed to load spaceship image: " << IMG_GetError() << std::endl;
    }

    
    xPosition = 250;
    yPosition = 675;
}
// destructor
Spaceship::~Spaceship() {
    SDL_DestroyTexture(texture);
    
}
//renderer function for the spaceship
void Spaceship::render(SDL_Renderer* renderer) {
    
    
    SDL_Rect dstRect = {xPosition, yPosition, 80, 80};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
}
//update method for the spaceship
void Spaceship::update() {


 
    if (xPosition < 0) {
        xPosition = 0; 
    } else if (xPosition > (SCREEN_WIDTH - 100)) {
        xPosition = SCREEN_WIDTH - 100; 
    }
    if (isFiring) {
        fireY -= 10; // Adjust the speed of the fire
        if (fireY < -20) {
            isFiring = false; // Reset fire when it goes off the screen
        }
    }
}

// functions for the movement based on input
void Spaceship::moveLeft() {
    xPosition -= 10; 
}

void Spaceship::moveRight() {
    xPosition += 10; 
}
//getter functions for coordinates
int Spaceship::getXPosition()  {
    return xPosition; 
}


int Spaceship::getYPosition()  {
    return yPosition; 
}


// renderer function for the bullet
void Spaceship::renderFire(SDL_Renderer* renderer) {
    if (isFiring) {
        SDL_Rect fireRect = { fireX, fireY, 10, 20 }; // Adjust the size of the fire
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set fire color (assuming red)
        SDL_RenderFillRect(renderer, &fireRect);
    }
}
// coordinate of the fired bullet
void Spaceship::firecord(int projectileIndex) {
    if (projectileIndex >= 0 && projectileIndex < projectiles.size()) {
        projectiles.erase(projectiles.begin() + projectileIndex);
    }
}
//getter functions for the x and y coordinate of the bullet
int Spaceship::getFireX()  {
    return fireX; 
}


int Spaceship::getFireY()  {
    return fireY; 
}
//update method for the bullet's movement
void Spaceship::updateProjectiles() {
    for (auto& projectile : projectiles) {
        projectile.y -= 10; // Adjust the speed of the projectile
    }

    projectiles.erase(
        std::remove_if(
            projectiles.begin(),
            projectiles.end(),
            [](const SDL_Rect& projectile) { return projectile.y < -20; }
        ),
        projectiles.end()
    );
}

//render new bullets into the vector
void Spaceship::renderProjectiles(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set projectile color 
    for (const auto& projectile : projectiles) {
        SDL_RenderFillRect(renderer, &projectile);
    }
}

//function to fire bullets
void Spaceship::fireProjectile() {
    fireX = xPosition + (SPACESHIP_WIDTH / 2) - 5; // Adjust the position of the fire
    fireY = yPosition - 20; // Place the fire above the spaceship
    SDL_Rect newProjectile = {fireX, fireY, 10, 20};
    projectiles.push_back(newProjectile);
}

//reset function
void Spaceship::reset() {
    xPosition = 250;
    yPosition = 675;
    isFiring = false;
    fireX = 0;
    fireY = 0;
    projectiles.clear(); // Clear any existing projectiles
}