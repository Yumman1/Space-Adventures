#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "spaceship.hpp"
#include "Obstacle.hpp"
#include "Asteroid.hpp" 
#include "Coin.hpp"
#include "Powerup.hpp"
#include "Powerup2.hpp"
#include "CollisionDetection.hpp"
#include "startscreen.hpp"
#include <vector>
#include <algorithm>
#include "scoretracker.hpp"
#include "Asteroid2.hpp"
#include "Asteroid3.hpp"
#include "Asteroid4.hpp"
#include "gamesettings.hpp"
#include "CollisionCheck.hpp"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <fstream>
//all the header files to be included

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;
const int SCROLL_SPEED = 1; 
SDL_Texture* backgroundTexture = nullptr;
SDL_Texture* currentTexture = nullptr;
bool pauseGame = false;


// function to update highscore 
void updateHighScore(int& highScore, const ScoreTracker& scoreTracker) {
    if (scoreTracker.getScore() > highScore) {
        highScore = scoreTracker.getScore();
    }
}


//function to create textures
SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& path) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface != nullptr) {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
    }
    return texture;
}





SDL_Texture* loadBackgroundTexture(SDL_Renderer* renderer, int level);

void restart(Spaceship&, Asteroid&, Asteroid2&, Asteroid3&, Coin&, PowerUp&, PowerUp2&, ScoreTracker&, bool&);

SDL_Texture* loadBackgroundTexture(SDL_Renderer* renderer, int level) {
    std::string backgroundPath;
    if (level == 1) {
        backgroundPath = "Background 1.png";
    } else if (level == 2) {
        backgroundPath = "Background 2.jpg";
    } else {
        backgroundPath = "Background 3.jpg";
    }

    SDL_Texture* texture = loadTexture(renderer, backgroundPath);
    return texture;
}


//function to call when the user wants to restart
void restart(Spaceship& spaceship, Asteroid& asteroid, Asteroid2& asteroid2, Asteroid3& asteroid3, Asteroid4& asteroid4,Coin& coin, PowerUp& powerup, PowerUp2& powerup2, ScoreTracker& scoreTracker, bool& gameOver) {
    spaceship.reset();
    asteroid.reset(rand() % 550, 0);
    asteroid2.reset(rand() % 550, 0);
    asteroid3.reset(rand() % 550, 0);
    asteroid4.reset(rand() % 550, -300);
    coin.reset(rand() % 550, 0);
    powerup.reset(rand() % 550, -500);
    powerup2.reset(rand() % 550, -500);
    scoreTracker.reset();
    pauseGame = false;
    gameOver = false;


}

// to save highscore in a seperate file
void saveHighScore(int highScore) {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highScore;
        file.close();
    } else {
        std::cerr << "Unable to save high score to file." << std::endl;
    }
}

//to load the saved file with the highscore
int loadHighScore() {
    std::ifstream file("highscore.txt");
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

//main function and the loop
int main(int argc, char* argv[]) {



    
    //calling all the textures and fonts to be loaded for the game
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (TTF_Init() == -1) {
        // Handle TTF initialization error
        std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << std::endl;
        return 1;
    }

    SDL_Color textColor = {255, 255, 0};

    TTF_Font* fonts = TTF_OpenFont("font.ttf", 40);  // Declare font here
    TTF_Font* fontG = TTF_OpenFont("font.ttf", 100);  // Declare font here
    TTF_Font* fonta = TTF_OpenFont("font.ttf", 20);  // Declare font here

    

    if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG)) {
        std::cerr << "SDL_image initialization failed: " << IMG_GetError() << std::endl;
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer initialization failed: " << Mix_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SpaceExplorer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    

    SDL_Texture* asteroidTexture = loadTexture(renderer, "asteroid1.png");
    if (asteroidTexture == nullptr) {
        std::cerr << "Failed to load asteroid image." << std::endl;
        return 1;
    }
    SDL_Texture* asteroidTexture1 = loadTexture(renderer, "asteroid2.png");
    if (asteroidTexture == nullptr) {
        std::cerr << "Failed to load asteroid image." << std::endl;
        return 1;
    }
    SDL_Texture* asteroidTexture2 = loadTexture(renderer, "asteroid3.png");
    if (asteroidTexture == nullptr) {
        std::cerr << "Failed to load asteroid image." << std::endl;
        return 1;
    }
    SDL_Texture* asteroidTexture3 = loadTexture(renderer, "asteroid1.png");
    if (asteroidTexture == nullptr) {
        std::cerr << "Failed to load asteroid image." << std::endl;
        return 1;
    }



    SDL_Texture* coinTexture = loadTexture(renderer, "Coins.png");
    if (coinTexture == nullptr) {
        std::cerr << "Failed to load coin image." << std::endl;
        return 1;
    }

    SDL_Texture* powerupTexture = loadTexture(renderer, "ss.png");
    if (powerupTexture == nullptr) {
        std::cerr << "Failed to load power-up image." << std::endl;
        return 1;
    }

    Mix_Chunk* gunshotSound = Mix_LoadWAV("laser.wav");
    if (!gunshotSound) {
        std::cerr << "Failed to load sound effect: " << Mix_GetError() << std::endl;
        return 1;
    }

    Mix_Chunk* collisionSound = Mix_LoadWAV("collision.wav");
    if (!collisionSound) {
        std::cerr << "Failed to load collision sound effect: " << Mix_GetError() << std::endl;
        return 1;
    }

    Mix_Chunk* lostsound = Mix_LoadWAV("lost1.wav");
    if (!lostsound) {
        std::cerr << "Failed to load game lost sound effect: " << Mix_GetError() << std::endl;
        return 1;
    }

    Mix_Chunk* coinsound = Mix_LoadWAV("coinc.wav");
    if (!coinsound) {
        std::cerr << "Failed to load game lost sound effect: " << Mix_GetError() << std::endl;
        return 1;
    }

    Mix_Music* backgroundMusic = Mix_LoadMUS("backgroundmusic.wav");
    if (!backgroundMusic) {
        std::cerr << "Failed to load background music: " << Mix_GetError() << std::endl;
        return 1;
    }   

    Mix_VolumeMusic(10);
    
    // to create the startscreen
    StartScreen startScreen(renderer);

    
    bool showStartScreen = true;
    while (showStartScreen) {
        SDL_Event e;
        showStartScreen = startScreen.show(e);

        
        
        SDL_Delay(30);
    }

    int bgY = 0;
    int highScore = loadHighScore();

    bool quit = false;
    SDL_Event e;
    SDL_Texture* currentTexture = nullptr;
     SDL_Texture* backgroundTexture = nullptr;
    backgroundTexture = loadBackgroundTexture(renderer, GameSettings::level);
    if (backgroundTexture == nullptr) {
        std::cerr << "Failed to load background image." << std::endl;
        return 1;
    }
    currentTexture = backgroundTexture;


    

    // initializing the position of every object that will appear in the game
    Spaceship spaceship(renderer, "ss.png", SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50);
    Asteroid asteroid(renderer, rand()%550, 0);
    Asteroid2 asteroid2(renderer, rand()%550, 0);
    Asteroid3 asteroid3(renderer, rand()%550, 0);
    Asteroid4 asteroid4(renderer, rand()%550, -300);
    Coin coin(renderer, rand() % 550, 0);
    Coin coin2(renderer, rand() % 550, rand()%400);
    Coin coin3(renderer, rand() % 550, rand()%400);
    Coin coin4(renderer, rand() % 550, rand()%400);
    Coin coin5(renderer, rand() % 550, rand()%400);
    Coin coin6(renderer, rand() % 550, rand()%400);
    Coin coin7(renderer, rand() % 550, rand()%400);
    Coin coin8(renderer, rand() % 550, rand()%400);
    Coin coin9(renderer, rand() % 550, rand()%400);
    Coin coin10(renderer, rand() % 550, rand()%400);
    Coin coin11(renderer, rand() % 550, rand()%400);
    Coin coin12(renderer, rand() % 550, rand()%400);
    Coin coin13(renderer, rand() % 550, rand()%400);
    Coin coin14(renderer, rand() % 550, rand()%400);
    Coin coin15(renderer, rand() % 550, rand()%400);
    Coin coin16(renderer, rand() % 550, rand()%400);
    Coin coin17(renderer, rand() % 550, rand()%400);
    Coin coin18(renderer, rand() % 550, rand()%400);
    Coin coin19(renderer, rand() % 550, rand()%400);
    PowerUp powerup(renderer, rand() % 550, 0);
    PowerUp2 powerup2(renderer, rand()%550,0);
    ScoreTracker scoreTracker(renderer);

    bool pauseGame = false;

// initializing the flags used for the game's logic
bool leftKeyPressed = false;
bool rightKeyPressed = false;
bool haspowerup = false;
bool haspowerup2 = false;
int bulletcounter = 0;
int coincounter = 0;
bool allowasteroid = false;
bool allowasteroid2 = false;
int scorecounter = 0;
bool powercoin = false;
CollisionDetection collisiondetection;
Mix_PlayMusic(backgroundMusic, -1);
bool gameOver = false;
bool spaceKeyPressed = false;

//main loop starts
while (!quit) {

    //event handling and the detection of the key pressed along with the right functions to call based on the input
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT ) {
            quit = true;
        
        } else if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
            else if (!pauseGame && !gameOver) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        leftKeyPressed = true;
                        break;
                    case SDLK_RIGHT:
                        rightKeyPressed = true;
                        break;
                    case SDLK_SPACE:
                        if (haspowerup == true && bulletcounter < 10) {
                            spaceship.fireProjectile();
                            Mix_PlayChannel(-1, gunshotSound, 0);
                            bulletcounter += 1;
                            if (bulletcounter == 10) {
                                coincounter = 0;
                                haspowerup = false;
                            }
                        }
                        break;
                }
            } else if (gameOver && e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_RETURN:
                        pauseGame = false;
                        leftKeyPressed = false;
                        rightKeyPressed = false;
                        bulletcounter = 0;
                        coincounter = 0;
                        haspowerup = false;
                        powercoin = false;
                        haspowerup2 = false;
                        allowasteroid = false;
                        allowasteroid2 = false;
                        scorecounter=0;

                        restart(spaceship, asteroid, asteroid2, asteroid3, asteroid4,coin, powerup, powerup2, scoreTracker, gameOver);
                        
                        if (scoreTracker.getScore() > highScore) {
                            highScore = scoreTracker.getScore();
                        }
                        gameOver = false;
                        break;
                    case SDLK_LSHIFT:
                    case SDLK_RSHIFT:
                        
                        showStartScreen = true;
                        GameSettings::level = 0;
                        while (showStartScreen ) {
                            SDL_Event spaceEvent;
                            showStartScreen = startScreen.show(spaceEvent);
                            
                            SDL_Delay(30);
                        }
                        pauseGame = false;
                        leftKeyPressed = false;
                        rightKeyPressed = false;
                        bulletcounter = 0;
                        coincounter = 0;
                        haspowerup = false;
                        powercoin = false;
                        haspowerup2 = false;
                        allowasteroid = false;
                        allowasteroid2 = false;
                        scorecounter=0;

                        
                        
                        restart(spaceship, asteroid, asteroid2, asteroid3, asteroid4,coin, powerup, powerup2, scoreTracker, gameOver);
                            // Load the correct background texture based on the level
                        currentTexture = loadBackgroundTexture(renderer, GameSettings::level);
                        
                        break;
                }
            }
        } else if (e.type == SDL_KEYUP) {
            if (!pauseGame) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        leftKeyPressed = false;
                        break;
                    case SDLK_RIGHT:
                        rightKeyPressed = false;
                        break;
                }
            }
        }
    }


    //game logic by using the flags 
    
    if (coincounter >=2){
        allowasteroid = true;
    }


    if (coincounter == 5){
        allowasteroid2 = true;
    }

    if(GameSettings::level == 1 and scorecounter > 25 ){
        haspowerup2=true;
    }
    else if (GameSettings::level == 2 and scorecounter > 30){
        haspowerup2 = true;
    }
    else if (GameSettings::level == 3 and scorecounter >35){
        haspowerup2 = true;
    }

    // mocving th spaceship using the using the flags chnaged with key detection
    if (leftKeyPressed) {
        spaceship.moveLeft();
    }
    if (rightKeyPressed) {
        spaceship.moveRight();
    }
        // while the game is running, updating the game logic for the objects to appear and re-appear
        if (!pauseGame) {
        spaceship.update();
        if(GameSettings::level == 1 and coincounter == 5 and haspowerup==false){
           
            powerup.update();
        }
        else if (GameSettings::level == 2 and coincounter == 8 and haspowerup == false){
            powerup.update();
        }
        else if (GameSettings::level == 3 and coincounter == 12 and haspowerup == false){
            powerup.update();
        }

        if (haspowerup2 == true){
            powerup2.update();
        }

        asteroid.update();
        if (GameSettings::level == 3){
        asteroid4.update();
        }
        
        if (allowasteroid == true){
           asteroid2.update();
        }

        if (allowasteroid2 == true){
           asteroid3.update();
        }
        //bonus coin powerup 
        if (powercoin == true){
            coin2.bonusupdate();
            coin3.bonusupdate();
            coin4.bonusupdate();
            coin5.bonusupdate();
            coin6.bonusupdate();
            coin7.bonusupdate();
            coin8.bonusupdate();
            coin9.bonusupdate();
            coin10.bonusupdate();
            coin11.bonusupdate();
            coin12.bonusupdate();
            coin13.bonusupdate();
            coin14.bonusupdate();
            coin15.bonusupdate();
            coin16.bonusupdate();
            coin17.bonusupdate();
            coin18.bonusupdate();
            coin19.bonusupdate();

        }
        
        
        if (GameSettings::level == 1 and coincounter<5 and haspowerup2 == false){
            coin.update();
        }

        if (GameSettings::level == 2 and coincounter<8 and haspowerup2 == false){
            coin.update();
        }

        if (GameSettings::level == 3 and coincounter<12 and haspowerup2 == false){
            coin.update();
        }
        spaceship.updateProjectiles(); // Update projectiles


        // checking the collision of spaceship with all the objects.
        int check = checkcollision2(collisiondetection, spaceship,  asteroid,  asteroid2,  asteroid3,  asteroid4,  coin,  powerup, powerup2,  pauseGame,  leftKeyPressed,  rightKeyPressed,  scorecounter , coincounter, bulletcounter ,haspowerup, haspowerup2, powercoin, coinsound, collisionSound,lostsound );
        scoreTracker.updateScore(check);
        
        //checking the collision with all the bonus coins
        if(powercoin == true){
        int counter = checkcollision(spaceship, coin2, coin3,  coin4, coin5,  coin6,  coin7,  coin8,  coin9,  coin10,  coin11,  coin12,  coin13, coin14,  coin15,  coin16,  coin17,  coin18, coin19, coinsound );
        scoreTracker.updateScore(counter);
        }
        
        //resetting the bonus coins for re-appearing 
        if (coin2.getYPosition()>800 and coin3.getYPosition()>800 and coin4.getYPosition()>800 and coin5.getYPosition()>800 and coin6.getYPosition()>800 and coin7.getYPosition()>800 and coin8.getYPosition()>800 and coin9.getYPosition()>800 and coin10.getYPosition()>800 and coin11.getYPosition()>800 and coin12.getYPosition()>800 and coin13.getYPosition()>800 and coin14.getYPosition()>800 and coin15.getYPosition()>800 and coin16.getYPosition()>800 and coin17.getYPosition()>800 and coin18.getYPosition()>800 and coin19.getYPosition()>800  ){
            powercoin = false;
            coin2.reset(rand() % 550, rand()%400);
            coin3.reset(rand() % 550, rand()%400);
            coin4.reset(rand() % 550, rand()%400);
            coin5.reset(rand() % 550, rand()%400);
            coin6.reset(rand() % 550, rand()%400);
            coin7.reset(rand() % 550, rand()%400);
            coin8.reset(rand() % 550, rand()%400);
            coin9.reset(rand() % 550, rand()%400);
            coin10.reset(rand() % 550, rand()%400);
            coin11.reset(rand() % 550, rand()%400);
            coin12.reset(rand() % 550, rand()%400);
            coin13.reset(rand() % 550, rand()%400);
            coin14.reset(rand() % 550, rand()%400);
            coin15.reset(rand() % 550, rand()%400);
            coin16.reset(rand() % 550, rand()%400);
            coin17.reset(rand() % 550, rand()%400);
            coin18.reset(rand() % 550, rand()%400);
            coin19.reset(rand() % 550, rand()%400);

        }
       
    }
    spaceship.renderProjectiles(renderer); // Render projectiles

    // logic for when the spaceship collides with the asteroid adn the game stops
    if (pauseGame) {

        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render "GAME OVER" text
        SDL_Surface* gameOverSurface = TTF_RenderText_Solid(fontG, "GAME OVER", textColor);
        SDL_Texture* gameOverTexture = SDL_CreateTextureFromSurface(renderer, gameOverSurface);
        int gameOverWidth, gameOverHeight;
        SDL_QueryTexture(gameOverTexture, nullptr, nullptr, &gameOverWidth, &gameOverHeight);
        SDL_Rect gameOverRect = {(SCREEN_WIDTH - gameOverWidth) / 2, ((SCREEN_HEIGHT / 2)-150) - gameOverHeight, gameOverWidth, gameOverHeight};
        SDL_RenderCopy(renderer, gameOverTexture, nullptr, &gameOverRect);
        SDL_FreeSurface(gameOverSurface);
        SDL_DestroyTexture(gameOverTexture);

        // Render high score
        std::string highScoreText = "High Score: " + std::to_string(highScore);
        SDL_Surface* highScoreSurface = TTF_RenderText_Solid(fonts, highScoreText.c_str(), textColor);
        SDL_Texture* highScoreTexture = SDL_CreateTextureFromSurface(renderer, highScoreSurface);
        int highScoreWidth, highScoreHeight;
        SDL_QueryTexture(highScoreTexture, nullptr, nullptr, &highScoreWidth, &highScoreHeight);
        SDL_Rect highScoreRect = {(SCREEN_WIDTH - highScoreWidth) / 2, (SCREEN_HEIGHT / 2)-60, highScoreWidth, highScoreHeight};
        SDL_RenderCopy(renderer, highScoreTexture, nullptr, &highScoreRect);
        SDL_FreeSurface(highScoreSurface);
        SDL_DestroyTexture(highScoreTexture);

        std::string currentScoreText = "Score: " + std::to_string(scoreTracker.getScore());
        SDL_Surface* currentScoreSurface = TTF_RenderText_Solid(fonts, currentScoreText.c_str(), textColor);
        SDL_Texture* currentScoreTexture = SDL_CreateTextureFromSurface(renderer, currentScoreSurface);
        int currentScoreWidth, currentScoreHeight;
        SDL_QueryTexture(currentScoreTexture, nullptr, nullptr, &currentScoreWidth, &currentScoreHeight);
        SDL_Rect currentScoreRect = {(SCREEN_WIDTH - currentScoreWidth) / 2, (SCREEN_HEIGHT / 2), currentScoreWidth, currentScoreHeight};
        SDL_RenderCopy(renderer, currentScoreTexture, nullptr, &currentScoreRect);
        SDL_FreeSurface(currentScoreSurface);
        SDL_DestroyTexture(currentScoreTexture);

        SDL_Surface* restartTextSurface = TTF_RenderText_Solid(fonta, "Press Return to Restart", textColor);
        SDL_Texture* restartTextTexture = SDL_CreateTextureFromSurface(renderer, restartTextSurface);
        int restartTextWidth, restartTextHeight;
        SDL_QueryTexture(restartTextTexture, nullptr, nullptr, &restartTextWidth, &restartTextHeight);
        SDL_Rect restartTextRect = {(SCREEN_WIDTH - restartTextWidth) / 2, SCREEN_HEIGHT / 2 + 120, restartTextWidth, restartTextHeight};
        SDL_RenderCopy(renderer, restartTextTexture, nullptr, &restartTextRect);
        SDL_FreeSurface(restartTextSurface);
        SDL_DestroyTexture(restartTextTexture);

        // Render "Press Shift to Return to Start Screen" text
        SDL_Surface* returnToStartTextSurface = TTF_RenderText_Solid(fonta, "Press Shift to Return to Start Screen", textColor);
        SDL_Texture* returnToStartTextTexture = SDL_CreateTextureFromSurface(renderer, returnToStartTextSurface);
        int returnToStartTextWidth, returnToStartTextHeight;
        SDL_QueryTexture(returnToStartTextTexture, nullptr, nullptr, &returnToStartTextWidth, &returnToStartTextHeight);
        SDL_Rect returnToStartTextRect = {(SCREEN_WIDTH - returnToStartTextWidth) / 2, SCREEN_HEIGHT / 2 + 150, returnToStartTextWidth, returnToStartTextHeight};
        SDL_RenderCopy(renderer, returnToStartTextTexture, nullptr, &returnToStartTextRect);
        SDL_FreeSurface(returnToStartTextSurface);
        SDL_DestroyTexture(returnToStartTextTexture);
        

        SDL_RenderPresent(renderer);


        updateHighScore(highScore, scoreTracker);
        saveHighScore(highScore);
        SDL_Delay(1000);
        gameOver = true;

    }

    //rendering all the objects until the game is over
    if (!gameOver) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect dstRect1 = {0, bgY, SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_Rect dstRect2 = {0, bgY - SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT};
        SDL_RenderCopy(renderer, currentTexture, nullptr, &dstRect1);
        SDL_RenderCopy(renderer, currentTexture, nullptr, &dstRect2);

        bgY += SCROLL_SPEED; 
        spaceship.render(renderer);

        scoreTracker.render(renderer);
        if (GameSettings::level == 1 and coincounter == 5){
            powerup.render(renderer);
        }

        if (haspowerup2 == true){
            powerup2.render(renderer);
        }

        if (powercoin == true){
            coin2.render(renderer);
            coin3.render(renderer);
            coin4.render(renderer);
            coin5.render(renderer);
            coin6.render(renderer);
            coin7.render(renderer);
            coin8.render(renderer);
            coin9.render(renderer);
            coin10.render(renderer);
            coin11.render(renderer);
            coin12.render(renderer);
            coin13.render(renderer);
            coin14.render(renderer);
            coin15.render(renderer);
            coin16.render(renderer);
            coin17.render(renderer);
            coin18.render(renderer);
            coin19.render(renderer);
            
        }

        if (GameSettings::level == 2 and coincounter == 8){
            powerup.render(renderer);
        }

        if (GameSettings::level == 3 and coincounter == 12){
            powerup.render(renderer);
        }
        asteroid.render1(renderer,80,80);
        if (GameSettings::level == 3){
        asteroid4.render1(renderer,80,80);
        }

        if (allowasteroid == true){
            asteroid2.render1(renderer,65,65);
        }


        if (allowasteroid2 == true){
            asteroid3.render1(renderer,50,50);
        }
       
        spaceship.render(renderer);
        spaceship.renderFire(renderer);
       
        coin.render(renderer);
        
        
        
        
        spaceship.renderProjectiles(renderer); // Render projectiles

        if (bgY >= SCREEN_HEIGHT) {
            bgY = 0;
        }

        SDL_RenderPresent(renderer);
        updateHighScore(highScore, scoreTracker);
    }

        
        SDL_Delay(30); 
    }
    //destorying all the textures when the game pauses and the loop ends
    Mix_FreeMusic(backgroundMusic);
    Mix_CloseAudio();
    
    Mix_FreeChunk(lostsound);
    Mix_FreeChunk(coinsound);
    Mix_FreeChunk(collisionSound);
    
    Mix_FreeChunk(gunshotSound);
    SDL_DestroyTexture(coinTexture);
    SDL_DestroyTexture(powerupTexture);
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(asteroidTexture);
    SDL_DestroyTexture(asteroidTexture1);
    SDL_DestroyTexture(asteroidTexture2);
    SDL_DestroyTexture(asteroidTexture3);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}