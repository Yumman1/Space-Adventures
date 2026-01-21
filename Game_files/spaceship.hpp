
// Spaceship.hpp
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SDL.h>
#include <string>
#include <vector>



class Spaceship {
public:
    Spaceship(SDL_Renderer* renderer, const std::string& imagePath, int x, int y);
    ~Spaceship();
    
    void render(SDL_Renderer* renderer); //render spaceship
    void update(); //update method for the ship
    int getXPosition() ; //getters for x and y coordinates
    int getYPosition();
    int getFireX(); // getters for x and y coordinate of the bullet
    int getFireY();

    // Constants for width and height
    static constexpr int SPACESHIP_WIDTH = 100; // Assuming width
    static constexpr int SPACESHIP_HEIGHT = 100; // Assuming height
    
    // New methods for movement
    void moveLeft(); //functions to move the spaceship left and right
    void moveRight();

    void fireProjectile(); //function to fire bullets
    void renderFire(SDL_Renderer* renderer); //render bullets
    void firecord(int projectileIndex); //function to return cordinate of the fired bullet
    void updateProjectiles(); // Function to update projectiles
    void renderProjectiles(SDL_Renderer* renderer); // Function to render projectiles
    const std::vector<SDL_Rect>& getProjectiles() const { return projectiles; }
    void reset(); //reseting the spaceship when the game finishes and user presses enter or shift

    
private:
    SDL_Texture* texture;
    int xPosition;
    int yPosition;
    SDL_Texture* fireTexture; // Texture for the fire
    int fireX, fireY; // Position of the fire
    bool isFiring; // Flag to indicate if firing
    std::vector<SDL_Rect> projectiles; // Collection of projectiles
    int projectileToRemoveIndex = -1;
    
};

#endif // SPACESHIP_H