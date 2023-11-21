// Asteroid.cpp
#include "Asteroid.hpp"


Asteroid::Asteroid(SDL_Renderer* renderer, int x, int y)
    : Obstacle(renderer, "asteroid.png", x, y) {
    // The constructor of the base class (Obstacle) is called with the specified image path and coordinates
}
const int SCREEN_HEIGHT = 800;
void Asteroid::update() {
    // Move the asteroid downward
    yPosition += 5; // Adjust the speed as needed

    // If the asteroid reaches the bottom, reset its position to the top with a new x coordinate
    if (yPosition >= SCREEN_HEIGHT) {
        yPosition = 0;
        xPosition = rand() % 600; // Set a new random x coordinate
    }
}

