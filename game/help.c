/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The help.c
*/

#include "game.h"

static void print_play(void)
{
    my_printf("    Play :\n"
        "        - Click on play\n"
        "        - Demons eyes will appear and you'll have to kill them\n"
        "        - To kill them, move your cursor over them and click on a "
        "mouse button or press the enter key of your keyboard\n"
        "        - After that, the mob will lose 1 life point\n"
        "        - If a mob have 0 life point, he die\n"
        "        - If you don't click on a monster, you lose 1 arrow\n"
        "        - If a monster disappear of the window, you lose 1 life\n"
        "        - Each small monster killed give you 100 points and "
        "each big monster give you 300 points score\n"
        "        - At each 1000 points score, you level up\n"
        "        - Each mobs kill will respawn\n"
        "        - Each mobs respawned, have a velocity depending "
        "on the level\n"
        "        - An untouched monster is not dead, but it reappears "
        "somewhere else with the same characteristics\n"
        "        - From level 5, big monsters can appear\n");
}

static void print_pause(void)
{
    my_printf("    Pause :\n"
        "        - When you are in game, you can press Escape for "
        "access to pause menu\n"
        "        - In this menu, the time is stopped and "
        "monsters don't move\n"
        "        - You can resume the game by pressing the escape key "
        "or the continue button\n");
}

static void print_settings(void)
{
    my_printf("    Settings :\n"
        "        - You can go to the settings for change parameters\n"
        "        - If you want to change the size, you just have to "
        "click on the size and restart the game\n"
        "        - You can enable infinite lives and infinite arrow "
        "which are activated by default only for eric mode\n"
        "        - You can also change the game volume\n"
        "        - All settings are saved and loaded when the "
        "game is launched\n");
}

int show_help(void)
{
    my_printf("USAGE:\n"
        "    ./my_hunter\n"
        "    -e or --eric -> Enable Eric mode -> Infinite lives and arrows, "
        "you can't lose in this mode\n"
        "HOW TO PLAY:\n");
    print_play();
    print_pause();
    print_settings();
    my_printf("For more informations you can read the README.md of this "
        "project :\n"
        "https://github.com/toro-nicolas/MUL_my_hunter_2028#readme\n");
    return 0;
}
