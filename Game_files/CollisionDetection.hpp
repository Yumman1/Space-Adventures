// CollisionDetection.hpp


// Include guard to prevent multiple inclusions of the header
#ifndef COLLISION_DETECTION_HPP
#define COLLISION_DETECTION_HPP


// Include necessary headers for forward declarations
#include "spaceship.hpp"
#include "Asteroid.hpp"
#include "Asteroid2.hpp"
#include "Asteroid3.hpp"
#include "Asteroid4.hpp"
#include "Coin.hpp"
#include "Powerup.hpp"
#include "Powerup2.hpp"


// Class declaration for CollisionDetection
class CollisionDetection {
public:

     // Function declarations for checking collisions between different game elements
     bool checkSpaceshipAsteroidCollision(Spaceship& spaceship, Asteroid& asteroid);
     bool checkSpaceshipAsteroid2Collision(Spaceship& spaceship, Asteroid2& asteroid2);
     bool checkSpaceshipAsteroid3Collision(Spaceship& spaceship, Asteroid3& asteroid3);
     bool checkSpaceshipAsteroid4Collision(Spaceship& spaceship, Asteroid4& asteroid4);
     bool checkSpaceshipCoinCollision(Spaceship& spaceship, Coin& coin);
     int checkFireAsteroidCollision(Spaceship& spaceship, Asteroid& asteroid);
     int checkFireAsteroid2Collision(Spaceship& spaceship, Asteroid2& asteroid2);
     int checkFireAsteroid3Collision(Spaceship& spaceship, Asteroid3& asteroid3);
     int checkFireAsteroid4Collision(Spaceship& spaceship, Asteroid4& asteroid4);
     bool checkPowerUpCollision(Spaceship& spaceship, PowerUp& PowerUp);
     bool checkPowerUp2Collision(Spaceship& spaceship, PowerUp2& PowerUp2);

};
// End of include guard
#endif // COLLISION_DETECTION_HPP
