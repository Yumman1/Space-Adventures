Welcome to Space Adventures.

In this game you will find yourself in an endless journey of space while avoiding obstacles and collecting coins to boost your spaceship to 
a powerup.

Game Instructions:
- The game is an endless adventure.

- On your journey you will be facing asteroid as obstacles on your course, your job is to avoid them and move forward.

- You will be collecting coins on your journey that will help you unlock powerups depending on the number of coins you have collected, each
coin contributes to 2 points.

- Powerup 1 is for your spaceship that will allow you to shoot 10 bullets towards asteroid, each asteroid destroyed equals to 10 points
in your score. However, the powerup will only last till 10 bullets, after which you will have to collect more coins further to unlock the powerup
again.

- Powerup 2 is for you to collect as many coins as possible as they randomly generate across the screen in a bunch, this power up is known as a 
bonus and will last for 5 seconds at max and then reappear after you have collected more coins again.

- The asteroid speed differs according to the difficulty level chosen. 

- Power up 1 appears after the player has collected 5 coins in Easy difficulty, 8 in Medium difficulty and 12 in Hard difficulty.

- Power up 2 appears after every 25 points collected in Easy difficulty, 30 points in Medium difficulty, and 35 points in Hard difficulty.

- If you collide with any of the asteroids, the game stops and your score is printed on the screen along with the highest score in the game's
history.

- Once the game is over you can press enter to restart the game, or press shift to return to the main menu, where you can change the difficulty.




Compilation Commands:

For Windows: " g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer "

For Mac: " clang++ *.cpp -o odyssey.out -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers -I/Library/Frameworks/SDL2_mixer.framework/Headers -I/Library/Frameworks/SDL2_image.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf -std=c++11 "



Run Commands:

For Windows: " .\a.exe "

For Mac: " ./odyssey.out "

