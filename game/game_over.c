/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The game_over.c
*/

#include "game.h"

static void init_sprite_2(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sfVector2f scale = {1.3, 1.3};
    sfIntRect rect = {2464, 0, 315, 50};
    sprite_t button_settings_image = {.file = TILESET, .scale = &scale};
    sfVector2f button_settings_position = {window_width / 4 * 1 -
        315 * 1.3 / 2, window_height / 8 * 6.5};
    sfSprite *button_settings = create_sf_sprite(&button_settings_image,
        button_settings_position);
    sprite_t button_exit_image = {.file = TILESET, .scale = &scale};
    sfVector2f button_exit_position = {window_width / 4 * 3 - 315 * 1.3 / 2,
        window_height / 8 * 6.5};
    sfSprite *button_exit = create_sf_sprite(&button_exit_image,
        button_exit_position);

    sfSprite_setTextureRect(button_settings, rect);
    sfSprite_setTextureRect(button_exit, rect);
    add_sprite(game, button_settings);
    add_sprite(game, button_exit);
}

static void init_sprite(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sprite_t button_restart_image = {.file = TILESET,
        .scale = &(sfVector2f){1.3, 1.3}};
    sfVector2f button_restart_position = {window_width / 2 - 315 * 1.3 / 2,
        window_height / 8 * 5};
    sfSprite *button_restart = create_sf_sprite(&button_restart_image,
        button_restart_position);

    sfSprite_setTextureRect(button_restart, (sfIntRect){2464, 0, 315, 50});
    add_sprite(game, button_restart);
    init_sprite_2(game);
}

static void init_text_3(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    float button_height = window_height / 8 * 6.425;
    text_t settings_text = {.text = "Settings", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f settings_position = {(window_width / 4 * 1 -
        315 * 1.3 / 2) + ((315 * 1.3) / 2) - (8 / 2) * 20, button_height};
    sfText *settings = create_sf_text(&settings_text, settings_position);
    text_t exit_text = {.text = "Exit", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f exit_position = {(window_width / 4 * 3 -
        315 * 1.3 / 2) + ((315 * 1.3) / 2) - (4 / 2) * 20, button_height};
    sfText *exit = create_sf_text(&exit_text, exit_position);

    add_text(game, settings);
    add_text(game, exit);
}

static void init_text_2(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    text_t restart_text = {.text = "Restart", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f restart_position = {window_width / 2 - 70,
        window_height / 8 * 4.95};
    sfText *restart = create_sf_text(&restart_text, restart_position);

    add_text(game, restart);
    init_text_3(game);
}

static void init_text(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    text_t game_over_text = {.text = "Game over !", .font = GAME_FONT, .size =
        60, .color = sfRed, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f game_over_position = {window_width / 2 - 145,
        window_height / 8 * 3};
    sfText *game_over = create_sf_text(&game_over_text, game_over_position);
    text_t score_text = {.text = get_score_str(game), .font = GAME_FONT,
        .size = 50, .color = sfWhite,
        .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f score_position = {window_width / 2 -
        my_strlen(get_score_str(game)) * 10, window_height / 8 * 3.75};
    sfText *score = create_sf_text(&score_text, score_position);

    add_text(game, game_over);
    add_text(game, score);
    init_text_2(game);
}

void display_game_over(game_t *game)
{
    if (game->settings->music_charged != GAME_OVER) {
        game->settings->music_charged = GAME_OVER;
        play_music(game, GAME_OVER_MUSIC);
    }
    init_game_logo(game);
    init_sprite(game);
    init_text(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    reset_game(game);
}

void check_game_over(game_t *game)
{
    if (game->settings->lives < 1) {
        game->state = GAME_OVER;
        game->state_changed = 1;
    }
    if (game->settings->arrows < 1) {
        game->state = GAME_OVER;
        game->state_changed = 1;
    }
}

static void reset_button_texture(game_t *game)
{
    sprite_list_t *temp = game->sprite_list;

    for (int button = 0; temp->next != NULL && button < 3; button++) {
        temp = temp->next;
        sfSprite_setTextureRect(temp->sprite, (sfIntRect){2464, 0, 315, 50});
    }
}

void on_a_game_over_button(game_t *game)
{
    sprite_list_t *temp = game->sprite_list->next;

    if (game->on_button == 1) {
        for (int text = 0; text < game->button_id; text++)
            temp = temp->next;
        play_sound(game, TICK);
        sfSprite_setTextureRect(temp->sprite, (sfIntRect){2464, 50, 315, 50});
        game->on_button = 2;
        return;
    }
    if (game->on_button == 2) {
        for (int text = 0; text < game->button_id; text++)
            temp = temp->next;
        sfSprite_setTextureRect(temp->sprite, (sfIntRect){2464, 50, 315, 50});
        return;
    }
    reset_button_texture(game);
}
