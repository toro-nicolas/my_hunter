/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The menu.c
*/

#include "game.h"

static void init_text(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    float middle = window_width / 2;
    text_t play_text = {.text = "Play", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f play_position = {middle - 2 * 20, window_height / 8 * 3.5};
    sfText *play = create_sf_text(&play_text, play_position);
    text_t setting_text = {.text = "Settings", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f setting_position = {middle - 4 * 20, window_height / 8 * 5};
    sfText *setting = create_sf_text(&setting_text, setting_position);
    text_t exit_text = {.text = "Exit", .font = GAME_FONT, .size = 50,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f exit_position = {middle - 2 * 20, window_height / 8 * 6.5};
    sfText *exit = create_sf_text(&exit_text, exit_position);

    add_text(game, play);
    add_text(game, setting);
    add_text(game, exit);
}

void display_menu(game_t *game)
{
    reset_game(game);
    set_background(game, TILESET, (int [2]){0, 1080});
    if (game->settings->music_charged != MENU) {
        game->settings->music_charged = MENU;
        play_music(game, TITLE_SCREEN);
    }
    init_game_logo(game);
    init_text(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
}

static void reset_text_color(game_t *game)
{
    text_list_t *temp = game->text_list;

    if (game->text_list != NULL) {
        sfText_setColor(temp->text, sfWhite);
        for (int text = 0; temp->next != NULL; text++) {
            temp = temp->next;
            sfText_setColor(temp->text, sfWhite);
        }
    }
}

void on_a_menu_button(game_t *game)
{
    text_list_t *temp = game->text_list;

    if (game->on_button == 1) {
        for (int text = 0; text < game->button_id; text++)
            temp = temp->next;
        play_sound(game, TICK);
        sfText_setColor(temp->text, sfYellow);
        game->on_button = 2;
        return;
    }
    if (game->on_button == 2) {
        for (int text = 0; text < game->button_id; text++)
            temp = temp->next;
        sfText_setColor(temp->text, sfYellow);
        return;
    }
    reset_text_color(game);
}
