//CollisionDetection.cpp

// Include the header file for the CollisionDetection class
#include "CollisionDetection.hpp"


    

        // Check collision between spaceship and asteroids
         bool CollisionDetection::checkSpaceshipAsteroidCollision(Spaceship& spaceship, Asteroid& asteroid) {
           
               
                SDL_Rect spaceshipRect = { spaceship.getXPosition(), spaceship.getYPosition(), 70,70 }; 
                SDL_Rect asteroidRect = { asteroid.getXPosition(), asteroid.getYPosition(), 60,65 }; 

                
                if (SDL_HasIntersection(&spaceshipRect, &asteroidRect)) {
                    
                    return true;
                }

                return false;
            
        }


         bool CollisionDetection::checkSpaceshipAsteroid2Collision(Spaceship& spaceship, Asteroid2& asteroid2) {
           
               
                SDL_Rect spaceshipRect = { spaceship.getXPosition(), spaceship.getYPosition(), 70,70 }; 
                SDL_Rect asteroidRect = { asteroid2.getXPosition(), asteroid2.getYPosition(), 50,55 }; 

                
                if (SDL_HasIntersection(&spaceshipRect, &asteroidRect)) {
                    
                    return true;
                }

                return false;
            
        }


         bool CollisionDetection::checkSpaceshipAsteroid3Collision(Spaceship& spaceship, Asteroid3& asteroid3) {
           
               
                SDL_Rect spaceshipRect = { spaceship.getXPosition(), spaceship.getYPosition(), 70,70 }; 
                SDL_Rect asteroidRect = { asteroid3.getXPosition(), asteroid3.getYPosition(), 35,40 }; 

                
                if (SDL_HasIntersection(&spaceshipRect, &asteroidRect)) {
                    
                    return true;
                }

                return false;
            
        }

        bool CollisionDetection::checkSpaceshipAsteroid4Collision(Spaceship& spaceship, Asteroid4& asteroid4) {
           
               
                SDL_Rect spaceshipRect = { spaceship.getXPosition(), spaceship.getYPosition(), 70,70 }; 
                SDL_Rect asteroidRect = { asteroid4.getXPosition(), asteroid4.getYPosition(), 60,65 }; 

                
                if (SDL_HasIntersection(&spaceshipRect, &asteroidRect)) {
                    
                    return true;
                }

                return false;
            
        }
        
        // Check collision between spaceship and coin
         bool CollisionDetection::checkSpaceshipCoinCollision(Spaceship& spaceship, Coin& coin) {
                SDL_Rect spaceshipRect = { spaceship.getXPosition(), spaceship.getYPosition(), 70, 70};
                SDL_Rect coinRect = { coin.getXPosition(), coin.getYPosition(), 75, 75 };

                if (SDL_HasIntersection(&spaceshipRect, &coinRect)) {
                        return true; // Collision detected
                }

                return false; // No collision
        }

   
        // Check collision between spaceship bullets and asteroids
         int CollisionDetection::checkFireAsteroidCollision(Spaceship& spaceship, Asteroid& asteroid) {
                for (size_t i = 0; i < spaceship.getProjectiles().size(); ++i) {
                        SDL_Rect projectileRect = { spaceship.getProjectiles()[i].x, spaceship.getProjectiles()[i].y, 10, 20 };
                        SDL_Rect asteroidRect = { asteroid.getXPosition(), asteroid.getYPosition(), 60,65 };

                        if (SDL_HasIntersection(&projectileRect, &asteroidRect)) {
                                return static_cast<int>(i); // Collision detected, return the index
                        }
                }

                return -1; // No collision detected
        }
      

         int CollisionDetection::checkFireAsteroid2Collision(Spaceship& spaceship, Asteroid2& asteroid2) {
                for (size_t i = 0; i < spaceship.getProjectiles().size(); ++i) {
                        SDL_Rect projectileRect = { spaceship.getProjectiles()[i].x, spaceship.getProjectiles()[i].y, 10, 20 };
                        SDL_Rect asteroidRect = { asteroid2.getXPosition(), asteroid2.getYPosition(), 50,55 };

                        if (SDL_HasIntersection(&projectileRect, &asteroidRect)) {
                                return static_cast<int>(i); // Collision detected, return the index
                        }
                }

                return -1; // No collision detected
        }


         int CollisionDetection::checkFireAsteroid3Collision(Spaceship& spaceship, Asteroid3& asteroid3) {
                for (size_t i = 0; i < spaceship.getProjectiles().size(); ++i) {
                        SDL_Rect projectileRect = { spaceship.getProjectiles()[i].x, spaceship.getProjectiles()[i].y, 10, 20 };
                        SDL_Rect asteroidRect = { asteroid3.getXPosition(), asteroid3.getYPosition(), 35, 40 };

                        if (SDL_HasIntersection(&projectileRect, &asteroidRect)) {
                                return static_cast<int>(i); // Collision detected, return the index
                        }
                }

                return -1; // No collision detected
        }

         int CollisionDetection::checkFireAsteroid4Collision(Spaceship& spaceship, Asteroid4& asteroid4) {
                for (size_t i = 0; i < spaceship.getProjectiles().size(); ++i) {
                        SDL_Rect projectileRect = { spaceship.getProjectiles()[i].x, spaceship.getProjectiles()[i].y, 10, 20 };
                        SDL_Rect asteroidRect = { asteroid4.getXPosition(), asteroid4.getYPosition(), 60,65 };

                        if (SDL_HasIntersection(&projectileRect, &asteroidRect)) {
                                return static_cast<int>(i); // Collision detected, return the index
                        }
                }

                return -1; // No collision detected
        }
        // Check collision between spaceship and power-ups
         bool CollisionDetection::checkPowerUpCollision(Spaceship& spaceship, PowerUp& PowerUp) {
                SDL_Rect spaceshipRect = { spaceship.getXPosition(), spaceship.getYPosition(), 70, 70 };
                SDL_Rect PowerUpRect = { PowerUp.getXPosition(), PowerUp.getYPosition(), 75, 75 };

                if (SDL_HasIntersection(&spaceshipRect, &PowerUpRect)) {
                        return true; // Collision detected
                }

                return false; // No collision
        }


         bool CollisionDetection::checkPowerUp2Collision(Spaceship& spaceship, PowerUp2& PowerUp2) {
                SDL_Rect spaceshipRect = { spaceship.getXPosition(), spaceship.getYPosition(), 70, 70 };
                SDL_Rect PowerUpRect = { PowerUp2.getXPosition(), PowerUp2.getYPosition(), 75, 75 };

                if (SDL_HasIntersection(&spaceshipRect, &PowerUpRect)) {
                        return true; // Collision detected
                }

                return false; // No collision
        }




        



    

