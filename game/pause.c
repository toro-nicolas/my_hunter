/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The pause.c
*/

#include "game.h"

static void init_sprite(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sfVector2f scale = {1.3, 1.3};
    sfIntRect rect = {2464, 0, 315, 50};
    sprite_t button_continue_image = {.file = TILESET, .scale = &scale};
    sfVector2f button_continue_position = {window_width / 2 -
        315 * 1.3 / 2, window_height / 8 * 3.8};
    sfSprite *button_continue = create_sf_sprite(&button_continue_image,
        button_continue_position);
    sprite_t button_menu_image = {.file = TILESET, .scale = &scale};
    sfVector2f button_menu_position = {window_width / 2 - 315 * 1.3 / 2,
        window_height / 8 * 5.8};
    sfSprite *button_menu = create_sf_sprite(&button_menu_image,
        button_menu_position);

    sfSprite_setTextureRect(button_continue, rect);
    sfSprite_setTextureRect(button_menu, rect);
    add_sprite(game, button_continue);
    add_sprite(game, button_menu);
}

static void init_text(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    text_t continue_text = {.text = "Continue", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f continue_position = {window_width / 2 - 8 * 10,
        window_height / 8 * 3.75};
    sfText *continu = create_sf_text(&continue_text, continue_position);
    text_t menu_text = {.text = "Menu", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f menu_position = {window_width / 2 - 4 * 13,
        window_height / 8 * 5.75};
    sfText *menu = create_sf_text(&menu_text, menu_position);

    add_text(game, continu);
    add_text(game, menu);
}

static void reset_button_texture(game_t *game)
{
    sprite_list_t *temp = game->sprite_list;

    for (int button = 0; temp->next != NULL && button < 3; button++) {
        temp = temp->next;
        sfSprite_setTextureRect(temp->sprite, (sfIntRect){2464, 0, 315, 50});
    }
}

void on_a_pause_button(game_t *game)
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

void display_pause(game_t *game)
{
    init_game_logo(game);
    init_sprite(game);
    init_text(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfClock_restart(game->game_time);
}
