// Asteroid2.cpp
#include "Asteroid2.hpp"
#include "gamesettings.hpp"
#include <random>

// Constructor for Asteroid2 class, inheriting from Obstacle class
Asteroid2::Asteroid2(SDL_Renderer* renderer, int x, int y)
    : Obstacle(renderer, "asteroid2.png", x, y) {
    // The constructor of the base class (Obstacle) is called with the specified image path and coordinates
}
const int SCREEN_HEIGHT = 800;


void Asteroid2::update() {
    int speed = GameSettings::asteroidSpeed2;

    // Move the asteroid downward
        yPosition += speed; // Adjust the speed as needed

        // If the asteroid reaches the bottom, reset its position to the top with a new x coordinate
        if (yPosition >= SCREEN_HEIGHT) {
            yPosition = 0;
            xPosition = rand()%550; // Set a new random x coordinate
        }
}

// Get the x-coordinate of the asteroid
int Asteroid2::getXPosition()  {
    return xPosition; 
}



// Get the y-coordinate of the asteroid
int Asteroid2::getYPosition() {
    return yPosition; 
}


// Reset the asteroid's position
void Asteroid2::reset(int x, int y) {
    active = true;
    xPosition = x;
    yPosition = y;
   
}

// Check if the asteroid is active
bool Asteroid2::isActive() const{
    return active;
}


// Set the asteroid as inactive
void Asteroid2::destroyasteroid() {
    active = false;
}

