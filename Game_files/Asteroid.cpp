// Asteroid.cpp
#include "Asteroid.hpp"
#include "gamesettings.hpp"
#include <random>

// Constructor for Asteroid class, inheriting from Obstacle class
Asteroid::Asteroid(SDL_Renderer* renderer, int x, int y)
    : Obstacle(renderer, "asteroid1.png", x, y) {
    // The constructor of the base class (Obstacle) is called with the specified image path and coordinates
}


// Constant representing the screen height
const int SCREEN_HEIGHT = 800;

// Update method for Asteroid class
void Asteroid::update() {

    // Get the asteroid speed from GameSettings
    int speed = GameSettings::asteroidSpeed1;

    // Move the asteroid downward
        yPosition += speed; // Adjust the speed as needed

        // If the asteroid reaches the bottom, reset its position to the top with a new x coordinate
        if (yPosition >= SCREEN_HEIGHT) {
            yPosition = 0;
            xPosition = rand()%550; // Set a new random x coordinate
        }
}


// Get the x-coordinate of the asteroid
int Asteroid::getXPosition()  {
    return xPosition; 
}

// Get the y-coordinate of the asteroid
int Asteroid::getYPosition() {
    return yPosition; 
}


// Reset the asteroid's position
void Asteroid::reset(int x, int y) {
    active = true;
    xPosition = x;
    yPosition = y;

}

// Check if the asteroid is active
bool Asteroid::isActive() const{
    return active;
}

// Set the asteroid as inactive
void Asteroid::destroyasteroid() {
    active = false;
}

