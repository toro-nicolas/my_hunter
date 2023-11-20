/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The menu.c
*/

#include "game.h"

static void init_sprite(game_t *game)
{
    sfIntRect logo_rect = {1914, 0, 544, 216};
    sfVector2f scale = {0.75, 0.75};
    sprite_t logo_image = {.file = TILESET, .rect = &logo_rect,
        .scale = &scale};
    sfVector2f logo_position = {430, 50};
    sfSprite *logo = create_sf_sprite(&logo_image, logo_position);

    add_sprite(game, logo);
}

static void init_text(game_t *game)
{
    text_t play_text = {.text = "Play", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f play_position = {600, 250};
    sfText *play = create_sf_text(&play_text, play_position);
    text_t setting_text = {.text = "Settings", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f setting_position = {560, 400};
    sfText *setting = create_sf_text(&setting_text, setting_position);
    text_t exit_text = {.text = "Exit", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f exit_position = {600, 550};
    sfText *exit = create_sf_text(&exit_text, exit_position);

    add_text(game, play);
    add_text(game, setting);
    add_text(game, exit);
}

static void set_cursor(game_t *game)
{
    sfIntRect logo_rect = {2773, 0, 100, 100};
    sfVector2f scale = {0.5, 0.5};
    sprite_t logo_image = {.file = TILESET, .rect = &logo_rect,
        .scale = &scale};
    sfVector2i logo_position_i = sfMouse_getPositionRenderWindow
        (game->window);
    sfVector2f logo_position_f = {(float)logo_position_i.x,
                                  (float)logo_position_i.y};
    sfSprite *logo = create_sf_sprite(&logo_image, logo_position_f);

    add_sprite(game, logo);
}

void display_menu(game_t *game)
{
    game->background_pos[1] = 1029;
    if (game->settings->music_charged == IN_GAME) {
        game->settings->music_charged = MENU;
        play_music(game, TITLE_SCREEN);
    }
    init_sprite(game);
    init_text(game);
    set_cursor(game);
}

void on_a_menu_button(game_t *game)
{
    text_list_t *temp = game->text_list;

    if (game->on_menu_button == 1) {
        for (int text = 0; text < game->button_menu_id; text++) {
            temp = temp->next;
        }
        play_sound(game, TICK);
        sfText_setColor(temp->text, sfYellow);
        game->on_menu_button = 2;
        return;
    }
    if (game->on_menu_button == 2) {
        for (int text = 0; text < game->button_menu_id; text++) {
            temp = temp->next;
        }
        sfText_setColor(temp->text, sfYellow);
    }
}
