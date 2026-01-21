// CollisionCheck.hpp

// Include guard to prevent multiple inclusions of the header
#ifndef COLLISION_CHECK_HPP
#define COLLISION_CHECK_HPP


// Include necessary headers
#include "spaceship.hpp"
#include "Coin.hpp"
#include <SDL_mixer.h>


// Function declarations for collision checking
int checkcollision(Spaceship& spaceship, Coin& coin2, Coin& coin3, Coin& coin4, Coin& coin5, Coin& coin6, Coin& coin7, Coin& coin8, Coin& coin9, Coin& coin10, Coin& coin11, Coin& coin12, Coin& coin13, Coin& coin14, Coin& coin15, Coin& coin16, Coin& coin17, Coin& coin18, Coin& coin19, Mix_Chunk* coinsound);
int checkcollision2(CollisionDetection collisiondetection, Spaceship& spaceship, Asteroid& asteroid, Asteroid2& asteroid2, Asteroid3& asteroid3, Asteroid4& asteroid4, Coin& coin, PowerUp& powerup, PowerUp2& powerup2, bool& pauseGame, bool& leftKeyPressed, bool& rightKeyPressed, int& scorecounter , int& coincounter, int& bulletcounter ,bool& haspowerup, bool& haspowerup2, bool& powercoin, Mix_Chunk* coinsound, Mix_Chunk* collisionSound, Mix_Chunk* lostsound);


// End of include guard
#endif // COLLISION_CHECK_HPP
