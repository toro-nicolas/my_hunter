/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The game.c
*/

#include "game.h"

settings_t *create_settings(int eric_mode)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->window_size = load_window_size();
    settings->music = sfMusic_createFromFile(TITLE_SCREEN);
    settings->music_volume = load_music_volume();
    sfMusic_setVolume(settings->music, settings->music_volume);
    settings->music_charged = 0;
    settings->sound = NULL;
    settings->sound_volume = load_sound_volume();
    settings->show_mob_life = 1;
    settings->level = 1;
    settings->score = 0;
    settings->record = load_record();
    settings->lives = (eric_mode) ? 2147483647 : 3;
    settings->arrows = (eric_mode) ? 2147483647 : 30;
    return settings;
}

static void create_game_display(game_t *game)
{
    game->display = malloc(sizeof(display_t));
    game->display->game_texture = sfTexture_createFromFile(TILESET, NULL);
    game->display->background = NULL;
    set_cursor(game);
    game->display->sprite_list = NULL;
    game->display->text_list = NULL;
    game->display->monster_list = NULL;
}

game_t *create_game(int eric_mode)
{
    game_t *game = malloc(sizeof(game_t));
    int width;
    int height;

    game->settings = create_settings(eric_mode);
    width = (game->settings->window_size) ? 1920 : 1440;
    height = (game->settings->window_size) ? 1080 : 810;
    game->window = sfRenderWindow_create((sfVideoMode){
        width, height, 32}, "my_hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 120);
    game->game_time = sfClock_create();
    game->animation_time = sfClock_create();
    game->old_state = MENU;
    game->state = MENU;
    game->state_changed = 1;
    game->on_button = 0;
    game->button_id = 0;
    create_game_display(game);
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
    sfTexture_destroy(game->display->game_texture);
    sfSprite_destroy(game->display->cursor);
    sfSprite_destroy(game->display->background);
    destroy_all_texts(game, game->display->text_list);
    destroy_all_sprites(game, game->display->sprite_list);
    sfClock_destroy(game->game_time);
    sfRenderWindow_destroy(game->window);
    free(game);
}

void init_game_logo(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    float scale = (game->settings->window_size) ? 1.0 : 0.75;
    sfIntRect logo_rect = {1920, 0, 544, 216};
    sprite_t logo_image = {.file = TILESET, .rect = &logo_rect,
        .scale = &(sfVector2f){scale, scale}};
    sfVector2f logo_position = {window_width / 2.8, window_height / 8};
    sfSprite *logo = create_sf_sprite(&logo_image, game->display->game_texture,
        logo_position);

    add_sprite(game, logo);
}
