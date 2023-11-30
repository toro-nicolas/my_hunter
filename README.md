# my_hunter - TORO Nicolas - PGE 2028
<div align="center"><img src="https://github.com/toro-nicolas/MUL_my_hunter_2028/assets/146118419/51d0092e-8780-475f-83aa-88a3d10bf7b7"></div>

### Table of contents
- [Goal](https://github.com/EpitechPromo2028/B-MUL-100-NCE-1-1-myhunter-nicolas.toro/tree/main#goal)
- [How to compile it ?](https://github.com/EpitechPromo2028/B-MUL-100-NCE-1-1-myhunter-nicolas.toro/tree/main#how-to-compile-it-)
- [How to use it ?](https://github.com/EpitechPromo2028/B-MUL-100-NCE-1-1-myhunter-nicolas.toro/tree/main#how-to-use-it-)
- [How to play ?](https://github.com/EpitechPromo2028/B-MUL-100-NCE-1-1-myhunter-nicolas.toro/tree/main#how-to-play-)
- [Project status](https://github.com/EpitechPromo2028/B-MUL-100-NCE-1-1-myhunter-nicolas.toro/tree/main#project-status)

### Goal
In this project, you are asked to make a **small video game** based on the rules of **Duck Hunt**.    
The basic rules for the my_hunter are as follows:    
• the player is a hunter who shoots ducks.    
• ducks must appear on the screen and move from one side to another.    
• the player can click on them to shoot them.    

In my version of the game, the story takes place in the world of **Terraria**.    
You're no longer a hunter, but a **player** being attacked at night by **demon eyes**.    
_Will you manage to kill them all ?_

### How to compile it ?
Make the game :
```shell
make
```

Re make the game :
```shell
# This command will deleted all the compiled files
make re
```

Remove all compiled files (*.o) :
```shell
make clean
```

Remove all compiled files (*.o) and the libmy.a file :
```shell
make fclean
```

Make the game and launch it :
```shell
# This command will "make re" the game
make run
```

Make a unit_tests file :
```shell
make unit_tests
```

Make and run a unit_tests file with the coverage :
```shell
make tests_run
```

Make the game and valgrind it :
```shell
make valgrind
```

### How to play ?
Launch the game :    
```Shell
./my_hunter
```

Launch the game with the eric mode (infinite lives and arrows) :
```Shell
./my_hunter -e 
./my_hunter --eric
```

Play :    
- Click on play    
- Demons eyes will appear and you'll have to kill them    
- To kill them, move your cursor over them and click on a mouse button or press the enter key of your keyboard    
- After that, the mob will lose 1 life point    
- If a mob have 0 life point, he die    
- If you don't click on a monster, you lose 1 arrow    
- If a monster disappear of the window, you lose 1 life    
- Each small monster killed give you 100 points and each big monster give you 300 points score    
- At each 1000 points score, you level up    
- Each mobs kill will respawn    
- Each mobs respawned, have a velocity depending on the level    
- An untouched monster is not dead, but it reappears somewhere else with the same characteristics    
- From level 5, big monsters can appear    

Pause :    
- When you are in game, you can press Escape for access to pause menu    
- In this menu, the time is stopped and monsters don't move    
- You can resume the game by pressing the escape key or the continue button    

Settings :    
- You can go to the settings for change parameters    
- If you want to change the size, you just have to click on the size and restart the game    
- You can enable infinite lives and infinite arrow which are activated by default only for eric mode    
- You can also change the game volume    
- All settings are saved and loaded when the game is launched    

### Project status
##### Must task :
| Status |                                                     Task description                                                     |                              Comment                              |
|:------:|:------------------------------------------------------------------------------------------------------------------------:|:-----------------------------------------------------------------:|
|   ✅    |                                         The window must be closed using events.                                          |           You can use the cross at the top right corner           |
|   ✅    |                                 The program must manage the input from the mouse click.                                  |           Game button and monsters are mouse-clickable            |
|   ✅    |                       The program must contain animated sprites rendered thanks to sprite sheets.                        | All sprites textures ara stored [here](assets/images/tileset.png) |
|   ✅    |                      The program must contain moving (rotating, translating, or scaling) elements.                       |                       All my monsters move                        |
|   ✅    | The program must accept the “-h” option, then display a short description of the program, and the available user inputs. |                                                                   |

##### Should task :
| Status |                                                     Task description                                                     |                               Comment                               |
|:------:|:------------------------------------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------:|
|   ✅    |                Animations and movements in your program should not depend on the speed of your computer.                 |        They depend on my game_time and animation_time clocks        |
|   ✅    |                      Animations and movements in your program should be timed by sfClock elements.                       |        They depend on my game_time and animation_time clocks        |
|   ✅    |                          Your window should stick between 800x600 pixels and 1920x1080 pixels.                           | There is a choice of size: small (1440 x 810) and big (1920 x 1080) |
|   ✅    |                Your window should have a limited frame rate such that it can be compute without lagging.                 |                    The limited framerate is 120 FPS                 |

##### Could task :
| Status |                                                     Task description                                                     |
|:------:|:------------------------------------------------------------------------------------------------------------------------:|
|   ✅    |                                     The program could have several different levels.                                     |
|   ✅    |                                    The program could display the score of the player.                                    |
|   ✅    |                                     The program could store the highest score made.                                      |
|   ✅    |                             The program could display a small target under the mouse cursor                              |

##### Bonus task :
| Status |                       Task description                        |
|:------:|:-------------------------------------------------------------:|
|   ✅    |               Add different demon eyes textures               |
|   ✅    |                 Add multiple sound and music                  |
|   ✅    |                       Add an Eric Mode                        |
|   ✅    |           Add a settings menu for change parameters           |
|   ✅    |                     Save all the settings                     |
|   ✅    | Add different eyes with different statistics (life, speed...) |

##### Future features (for the 1.1.0) :
Importance :    
- 1 : very important    
- 2 : it will have to be done    
- 3 : not a priority    

| Status | Importance |                                                         Description                                                          |
|:------:|:----------:|:----------------------------------------------------------------------------------------------------------------------------:|
|   ❌    |     1      |                       Print an error message and don't launch the game when the asset aren't detected                        |
|   ❌    |     2      |                                      Update the tileset to make it cleaner and smaller                                       |
|   ❌    |     2      |                                                    Change the game cursor                                                    |
|   ❌    |     1      |                              Replace the max int for the infinite arrow to the infinite symbol                               |
|   ❌    |     3      |                                                    Add the window resize                                                     |
|   ❌    |     2      |                                   Change all sprite origin and position to make it cleaner                                   |
|   ❌    |     2      |                                          Make an animation when an arrow is thrown                                           |
|   ❌    |     2      |                                          Make an animation when a monster is killed                                          |
|   ❌    |     3      |                                                 Add a boss (Eye of Cthulhu)                                                  |
|   ❌    |     3      |                               Add a the Terraria guide for help you to understand how to play                                |
|   ❌    |     3      |                                                     Add multiple weapons                                                     |
|   ❌    |     3      | Add power up (an arrow that lets you regain arrows, a bomb that kills all enemies at once, and a tower that shoots monsters) |
