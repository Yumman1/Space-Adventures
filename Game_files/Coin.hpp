// Coin.hpp


// Include guard to prevent multiple inclusions of the header
#ifndef COIN_H
#define COIN_H


// Include the base class header
#include "Obstacle.hpp"


// Coin class inheriting from Obstacle class
class Coin : public Obstacle {
public:

    // Constructor for Coin class
    Coin(SDL_Renderer* renderer, int x, int y);
    // Update method for regular coin behavior
    void update();
    void bonusupdate(); // Bonus update method for additional coin behavior
    // Getters for position
    int getXPosition();
    int getYPosition();
    bool isActive()const;// Check if the coin is active
    void destroycoin(); // Deactivate the coin
     void reset(int x, int y); // Implement the reset function

    private:
    bool active; // Member variable indicating if the coin is active or not
};

#endif // COIN_H
