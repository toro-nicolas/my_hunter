/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The setting.c
*/

#include "game.h"

static void init_background(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sfVector2f scale = {1, 1};
    sprite_t background_image = {.file = TILESET, .scale = &scale,
        .rect = &(sfIntRect){1920, 216, 960, 270}};
    sfVector2f background_position = {window_width / 2 - 480,
        window_height / 8 * 3};
    sfSprite *background = create_sf_sprite(&background_image,
        background_position);

    add_sprite(game, background);
}

static void init_button(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sfVector2f scale = {1.3, 1.3};
    sfIntRect rect = {2464, 0, 315, 50};
    sprite_t button_continue_image = {.file = TILESET, .scale = &scale};
    sfVector2f button_continue_position = {window_width / 2 - 480,
        window_height / 8 * 6};
    sfSprite *button_continue = create_sf_sprite(&button_continue_image,
        button_continue_position);
    sprite_t button_menu_image = {.file = TILESET, .scale = &scale};
    sfVector2f button_menu_position = {window_width / 2 + 480 - 315 * 1.3,
        window_height / 8 * 6};
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
    text_t reset_text = {.text = "Reset", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f reset_position = {window_width / 2 - 480 + 315 * 1.3 / 2
        - 5 * 11, window_height / 8 * 6};
    sfText *reset = create_sf_text(&reset_text, reset_position);
    text_t back_text = {.text = "Back", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f back_position = {window_width / 2 + 480 - 315 * 1.3 / 2
        - 4 * 11, window_height / 8 * 6};
    sfText *back = create_sf_text(&back_text, back_position);

    add_text(game, reset);
    add_text(game, back);
}

static void init_window_size(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    float pos = (game->settings->window_size) ? 125 : 250;
    sfVector2f scale = {1.3, 1.3};
    sfIntRect rect = {2666, 150, 100, 50};
    sprite_t size_image = {.file = TILESET, .scale = &scale, .rect = &rect};
    sfVector2f size_position = {window_width / 2 - pos,
        window_height / 8 * 3 + 70};
    sfSprite *size = create_sf_sprite(&size_image, size_position);

    add_sprite(game, size);
}

static void init_on_off(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    char *lives = (game->settings->lives == 2147483647) ? "On" : "Off";
    char *arrows = (game->settings->arrows == 2147483647) ? "On" : "Off";
    text_t on_off_1_text = {.text = lives, .font = GAME_FONT, .size = 40,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f on_off_1_position = {window_width / 2 - 140,
        window_height / 8 * 3 + 135};
    sfText *on_off_1 = create_sf_text(&on_off_1_text, on_off_1_position);
    text_t on_off_2_text = {.text = arrows, .font = GAME_FONT, .size = 40,
        .color = sfWhite, .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f on_off_2_position = {window_width / 2 - 140,
        window_height / 8 * 3 + 200};
    sfText *on_off_2 = create_sf_text(&on_off_2_text, on_off_2_position);

    add_text(game, on_off_1);
    add_text(game, on_off_2);
}

static void init_trackbar_music(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sfVector2f scale = {1.3, 1.3};
    sfIntRect rect = {2464, 182, 202, 10};
    sprite_t empty_image = {.file = TILESET, .scale = &scale, .rect = &rect};
    sfVector2f empty_position = {window_width / 2 + 110,
        window_height / 8 * 3 + 135};
    sfSprite *empty = create_sf_sprite(&empty_image, empty_position);
    sprite_t full_image = {.file = TILESET, .scale = &scale};
    sfVector2f full_position = {window_width / 2 + 110,
        window_height / 8 * 3 + 135};
    sfSprite *full = create_sf_sprite(&full_image, full_position);

    sfSprite_setTextureRect(full, (sfIntRect){2464, 192,
        (int)(game->settings->music_volume / 100 * 202), 10});
    add_sprite(game, empty);
    add_sprite(game, full);
}

static void init_trackbar_sound(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sfVector2f scale = {1.3, 1.3};
    sfIntRect rect = {2464, 182, 202, 10};
    sprite_t empty_image = {.file = TILESET, .scale = &scale, .rect = &rect};
    sfVector2f empty_position = {window_width / 2 + 110,
        window_height / 8 * 3 + 225};
    sfSprite *empty = create_sf_sprite(&empty_image, empty_position);
    sprite_t full_image = {.file = TILESET, .scale = &scale};
    sfVector2f full_position = {window_width / 2 + 110,
        window_height / 8 * 3 + 225};
    sfSprite *full = create_sf_sprite(&full_image, full_position);

    sfSprite_setTextureRect(full, (sfIntRect){2464, 192,
        (int)(game->settings->sound_volume / 100 * 202), 10});
    add_sprite(game, empty);
    add_sprite(game, full);
}

static void reset_button_texture(game_t *game)
{
    sprite_list_t *temp = game->sprite_list->next;

    for (int button = 0; temp->next != NULL && button < 2; button++) {
        temp = temp->next;
        sfSprite_setTextureRect(temp->sprite, (sfIntRect){2464, 0, 315, 50});
    }
}

void on_a_setting_button(game_t *game)
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

void display_setting(game_t *game)
{
    init_game_logo(game);
    init_background(game);
    init_button(game);
    init_text(game);
    init_window_size(game);
    init_on_off(game);
    init_trackbar_music(game);
    init_trackbar_sound(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
}
