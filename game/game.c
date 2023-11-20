/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The game.c
*/

#include "game.h"

settings_t *create_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->music = sfMusic_createFromFile(TITLE_SCREEN);
    settings->music_volume = 50.0;
    sfMusic_setVolume(settings->music, settings->music_volume);
    settings->music_charged = 0;
    settings->sound = NULL;
    settings->sound_volume = 100.0;
    return settings;
}

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode mode = {1276, 686, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "my_hunter",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfClock *game_time = sfClock_create();
    sfVector2f mouse_pos = {0, 0};

    game->window = window;
    game->game_time = game_time;
    game->mouse_position = &mouse_pos;
    game->state = 0;
    game->background_pos[0] = 0;
    game->background_pos[1] = 1029;
    game->settings = create_settings();
    game->sprite_list = NULL;
    game->text_list = NULL;
    game->on_menu_button = 0;
    game->button_menu_id = 0;
    sfMusic_play(game->settings->music);
    return game;
}

void destroy_game(game_t *game)
{
    if (game->settings->music != NULL)
        sfMusic_destroy(game->settings->music);
    if (game->settings->sound != NULL)
        sfMusic_destroy(game->settings->sound);
    free(game->settings);
    sfClock_destroy(game->game_time);
    sfRenderWindow_destroy(game->window);
    free(game);
}
