# my_hunter - TORO Nicolas - PGE 2028
![Terraria Hunter]()

### Table of contents
- [Goal](https://github.com/EpitechPromo2028/B-MUL-100-NCE-1-1-myhunter-nicolas.toro/tree/main#goal-)
- [How to compile it ?](https://github.com/EpitechPromo2028/B-MUL-100-NCE-1-1-myhunter-nicolas.toro/tree/main#how-to-compile-it-)- [How to use it ?](https://github.com/EpitechPromo2028/B-CPE-101-NCE-1-1-myprintf-nicolas.toro/tree/main#how-to-use-it-)
- [Project status](https://github.com/EpitechPromo2028/B-MUL-100-NCE-1-1-myhunter-nicolas.toro/tree/main#project-status-)

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

### Project status
| Status |                                                Mandatory task description                                                | 
|:------:|:------------------------------------------------------------------------------------------------------------------------:|
|   ✅    |                                         The window must be closed using events.                                          |
|  🟰    |                                 The program must manage the input from the mouse click.                                  |
|   ❌    |                       The program must contain animated sprites rendered thanks to sprite sheets.                        |
|   ❌    |                      The program must contain moving (rotating, translating, or scaling) elements.                       |
|   🟰   | The program must accept the “-h” option, then display a short description of the program, and the available user inputs. |
|   ✅    |                Animations and movements in your program should not depend on the speed of your computer.                 |
|   ❌    |                      Animations and movements in your program should be timed by sfClock elements.                       |
|   ✅    |                          Your window should stick between 800x600 pixels and 1920x1080 pixels.                           |
|   ✅    |                Your window should have a limited frame rate such that it can be compute without lagging.                 |
|   ❌    |                                     The program could have several different levels.                                     |
|   ❌    |                                    The program could display the score of the player.                                    |
|   ❌    |                                     The program could store the highest score made.                                      |
|   ❌    |                             The program could display a small target under the mouse cursor                              |

| Status |                     Bonus task description                     | 
|:------:|:--------------------------------------------------------------:|
|   ❌    |                  Add a boss (Eye of Cthulhu)                   |
|   ❌    | Add different eyes with different statistique (life, speed...) |
