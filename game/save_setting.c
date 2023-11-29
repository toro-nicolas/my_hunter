/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The save_setting.c
*/

#include "game.h"

void update_window_size(int size)
{
    FILE *file = fopen("settings/window_size", "w");

    fwrite(my_str_nbr(size), 1, 1, file);
    fclose(file);
    my_printf("Please, restart the game for see changes !\n");
    exit(0);
}

void update_music_volume(game_t *game, int volume)
{
    FILE *file = fopen("settings/music_volume", "w");

    game->settings->music_volume = volume;
    sfMusic_setVolume(game->settings->music, game->settings->music_volume);
    fwrite(my_str_nbr(volume), 1, my_strlen(my_str_nbr(volume)), file);
    fclose(file);
}

void update_sound_volume(game_t *game, int volume)
{
    FILE *file = fopen("settings/sound_volume", "w");

    game->settings->sound_volume = volume;
    sfMusic_setVolume(game->settings->sound, game->settings->sound_volume);
    fwrite(my_str_nbr(volume), 1, my_strlen(my_str_nbr(volume)), file);
    fclose(file);
}

void update_record(game_t *game)
{
    FILE *file = fopen("settings/record", "w");

    game->settings->record = game->settings->score;
    fwrite(my_str_nbr(game->settings->record), 1,
        my_strlen(my_str_nbr(game->settings->record)), file);
    fclose(file);
}
