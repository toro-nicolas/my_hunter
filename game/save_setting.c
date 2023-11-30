/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The save_setting.c
*/

#include "game.h"

void update_window_size(game_t *game, int size)
{
    FILE *file = fopen("settings/window_size", "w");
    int width = (size) ? 1920 : 1440;
    int height = (size) ? 1080 : 810;

    fwrite(my_str_nbr(size), 1, 1, file);
    fclose(file);
    sfRenderWindow_close(game->window);
    sfRenderWindow_destroy(game->window);
    game->window = sfRenderWindow_create((sfVideoMode){
        width, height, 32}, "my_hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 120);
    game->settings->window_size = size;
    destroy_all_texts(game, game->display->text_list);
    destroy_all_sprites(game, game->display->sprite_list);
    if (game->old_state == MENU)
        set_background(game, (int [2]){0, 1080});
    if (game->old_state == GAME_OVER)
        set_background(game, (int [2]){0, 0});
    display_setting(game);
    sort_state_element(game);
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
