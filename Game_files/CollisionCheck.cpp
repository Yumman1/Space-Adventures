//CollisionCheck.cpp


#include<iostream>
#include "Coin.hpp"
#include "CollisionDetection.hpp"
#include "spaceship.hpp"
#include "scoretracker.hpp"
#include <SDL_mixer.h>


// Function to check collision between spaceship and coins
int checkcollision(Spaceship& spaceship, Coin& coin2, Coin& coin3, Coin& coin4, Coin& coin5, Coin& coin6, Coin& coin7, Coin& coin8, Coin& coin9, Coin& coin10, Coin& coin11, Coin& coin12, Coin& coin13, Coin& coin14, Coin& coin15, Coin& coin16, Coin& coin17, Coin& coin18, Coin& coin19, Mix_Chunk* coinsound ){
        
        CollisionDetection collisionDetection;
        
        int count = 0;

        // Check collision for each coin
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin2)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin2.destroycoin();
            coin2.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin3)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin3.destroycoin();
            coin3.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin4)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin4.destroycoin();
            coin4.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin5)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin5.destroycoin();
            coin5.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin6)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin6.destroycoin();
            coin6.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin7)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin7.destroycoin();
            coin7.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin8)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin8.destroycoin();
            coin8.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin9)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin9.destroycoin();
            coin9.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin10)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin10.destroycoin();
            coin10.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin11)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin11.destroycoin();
            coin11.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin12)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin12.destroycoin();
            coin12.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin13)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin13.destroycoin();
            coin13.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin14)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin14.destroycoin();
            coin14.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin15)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin15.destroycoin();
            coin15.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin16)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin16.destroycoin();
            coin16.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin17)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin17.destroycoin();
            coin17.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin18)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin18.destroycoin();
            coin18.reset(rand() % 550, 850);
    
        }
        if (collisionDetection.checkSpaceshipCoinCollision(spaceship, coin19)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            count++;
            coin19.destroycoin();
            coin19.reset(rand() % 550, 850);
    
        }
        return count;
}

// Function to check collision between spaceship and various game elements

int checkcollision2(CollisionDetection collisiondetection, Spaceship& spaceship, Asteroid& asteroid, Asteroid2& asteroid2, Asteroid3& asteroid3, Asteroid4& asteroid4, Coin& coin, PowerUp& powerup, PowerUp2& powerup2, bool& pauseGame, bool& leftKeyPressed, bool& rightKeyPressed, int& scorecounter , int& coincounter, int& bulletcounter ,bool& haspowerup, bool& haspowerup2, bool& powercoin, Mix_Chunk* coinsound, Mix_Chunk* collisionSound, Mix_Chunk* lostsound ){
    int updatescore = 0;

        if (collisiondetection.checkSpaceshipAsteroidCollision(spaceship, asteroid) ) {
            Mix_PlayChannel(-1, lostsound, 0);
            pauseGame = true;
            leftKeyPressed = false;
            rightKeyPressed = false;
        }
        if (collisiondetection.checkSpaceshipAsteroid2Collision(spaceship, asteroid2) ) {
            Mix_PlayChannel(-1, lostsound, 0);
            pauseGame = true;
            leftKeyPressed = false;
            rightKeyPressed = false;
        }
        if (collisiondetection.checkSpaceshipAsteroid3Collision(spaceship, asteroid3) ) {
            Mix_PlayChannel(-1, lostsound, 0);
            pauseGame = true;
            leftKeyPressed = false;
            rightKeyPressed = false;
        }
        if (collisiondetection.checkSpaceshipAsteroid4Collision(spaceship, asteroid4) ) {
            Mix_PlayChannel(-1, lostsound, 0);
            pauseGame = true;
            leftKeyPressed = false;
            rightKeyPressed = false;
        }
        if (collisiondetection.checkSpaceshipCoinCollision(spaceship, coin)) {
            // Collision detected between spaceship and coin
            Mix_PlayChannel(-1, coinsound, 0);
            
            updatescore+=2;
            scorecounter +=2;
            coin.destroycoin();
            coin.reset(rand() % 550, -500);
            coincounter+=1;
            
        }
        if (collisiondetection.checkPowerUpCollision(spaceship, powerup)) {
                    // Collision detected between spaceship and coin
                    
                    Mix_PlayChannel(-1, coinsound, 0);
                    powerup.destroypowerup();
                    powerup.reset(rand() % 550, -500);
                    haspowerup = true;
                    bulletcounter = 0;
        }

        if (collisiondetection.checkPowerUp2Collision(spaceship, powerup2)) {
                    // Collision detected between spaceship and coin
                    
                    Mix_PlayChannel(-1, coinsound, 0);
                    powerup2.destroypowerup();
                    powerup2.reset(rand() % 550, -500);
                    haspowerup2 = false;
                    scorecounter = 0;
                    asteroid.reset(rand() % 550, -1500);
                    asteroid2.reset(rand() % 550, -1500);
                    asteroid3.reset(rand() % 550, -1500);
                    asteroid4.reset(rand() % 550, -1800);
                    powercoin = true;
        }

        int collisionIndex = collisiondetection.checkFireAsteroidCollision(spaceship, asteroid);
        if (collisionIndex != -1) {
            Mix_PlayChannel(-1, collisionSound, 0);
            spaceship.firecord(collisionIndex); // Remove the projectile at the collision index
            asteroid.destroyasteroid();
            asteroid.reset(rand() % 550, -500);
            updatescore+=5;
           
            scorecounter+=5;
        }

        int collisionIndex2 = collisiondetection.checkFireAsteroid2Collision(spaceship, asteroid2);
        if (collisionIndex2 != -1) {
            Mix_PlayChannel(-1, collisionSound, 0);
            spaceship.firecord(collisionIndex2); // Remove the projectile at the collision index
            asteroid2.destroyasteroid();
            asteroid2.reset(rand() % 550, -500);
            updatescore+=5;
            scorecounter+=5;
        }

        int collisionIndex3 = collisiondetection.checkFireAsteroid3Collision(spaceship, asteroid3);
        if (collisionIndex3 != -1) {
            Mix_PlayChannel(-1, collisionSound, 0);
            spaceship.firecord(collisionIndex3); // Remove the projectile at the collision index
            asteroid3.destroyasteroid();
            asteroid3.reset(rand() % 550, -500);
            updatescore+=5;
            scorecounter+=5;
        }

        int collisionIndex4 = collisiondetection.checkFireAsteroid4Collision(spaceship, asteroid4);
        if (collisionIndex4 != -1) {
            Mix_PlayChannel(-1, collisionSound, 0);
            spaceship.firecord(collisionIndex4); // Remove the projectile at the collision index
            asteroid4.destroyasteroid();
            asteroid4.reset(rand() % 550, -500);
            updatescore+=5;
           
            scorecounter+=5;
        }
    return updatescore;
}