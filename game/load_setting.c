/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The load_setting.c
*/

#include "game.h"

int load_window_size(void)
{
    FILE *file = fopen("settings/window_size", "r");
    char *number = malloc(sizeof(char *));
    size_t len = 0;

    if (file == NULL) {
        file = fopen("settings/window_size", "w");
        fwrite("0", 1, 1, file);
        fclose(file);
        return 0;
    } else {
        if (fread(number, 1, 1, file) != 0) {
            fclose(file);
            return my_getnbr(number);
        }
        fclose(file);
        return 0;
    }
}

int load_music_volume(void)
{
    FILE *file = fopen("settings/music_volume", "r");
    char *number = malloc(sizeof(char *));
    size_t len = 0;

    if (file == NULL) {
        file = fopen("settings/music_volume", "w");
        fwrite("50", 1, 2, file);
        fclose(file);
        return 50;
    } else {
        if (fread(number, 1, 3, file) != 0) {
            fclose(file);
            return my_getnbr(number);
        }
        fclose(file);
        return 50;
    }
}

int load_sound_volume(void)
{
    FILE *file = fopen("settings/sound_volume", "r");
    char *number = malloc(sizeof(char *));
    size_t len = 0;

    if (file == NULL) {
        file = fopen("settings/sound_volume", "w");
        fwrite("100", 1, 3, file);
        fclose(file);
        return 100;
    } else {
        if (fread(number, 1, 3, file) != 0) {
            fclose(file);
            return my_getnbr(number);
        }
        fclose(file);
        return 100;
    }
}

int load_record(void)
{
    FILE *file = fopen("settings/record", "r");
    char *number = malloc(sizeof(char *));
    size_t len = 0;

    if (file == NULL) {
        file = fopen("settings/record", "w");
        fwrite("0", 1, 1, file);
        fclose(file);
        return 0;
    } else {
        if (fread(number, 1, 11, file) != 0) {
            fclose(file);
            return my_getnbr(number);
        }
        fclose(file);
        return 0;
    }
}
