/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The music_sound.c
*/

#include "game.h"

void play_sound(game_t *game, char *file)
{
    if (game->settings->sound != NULL)
        sfMusic_destroy(game->settings->sound);
    game->settings->sound = sfMusic_createFromFile(file);
    sfMusic_setVolume(game->settings->sound, game->settings->sound_volume);
    sfMusic_play(game->settings->sound);
}

void play_music(game_t *game, char *file)
{
    if (game->settings->music != NULL)
        sfMusic_destroy(game->settings->music);
    game->settings->music = sfMusic_createFromFile(file);
    sfMusic_setVolume(game->settings->music, game->settings->music_volume);
    sfMusic_setLoop(game->settings->music, sfTrue);
    sfMusic_play(game->settings->music);
}
