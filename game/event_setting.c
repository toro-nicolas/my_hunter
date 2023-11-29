/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The event_setting.c
*/

#include "game.h"

static void mouse_on_button(game_t *game, sfEvent event)
{
    sprite_list_t *temp = game->display->sprite_list->next->next;

    if (check_mouse_move_on(event.mouseMove,
    sfSprite_getGlobalBounds(temp->sprite))) {
        set_button_id(game, 1);
        return;
    }
    temp = temp->next;
    if (check_mouse_move_on(event.mouseMove,
    sfSprite_getGlobalBounds(temp->sprite))) {
        set_button_id(game, 2);
        return;
    }
    game->on_button = 0;
}

static void reset_settings(game_t *game)
{
    sfText_setString(game->display->text_list->next->next->text, "Off");
    game->settings->lives = 3;
    sfText_setString(game->display->text_list->next->next->next->text, "Off");
    game->settings->arrows = 30;
    sfSprite_setTextureRect(game->display->sprite_list->next->next->next->next
    ->next->next->sprite, (sfIntRect){2464, 192, 101, 10});
    update_music_volume(game, 50);
    sfSprite_setTextureRect(game->display->sprite_list->next->next->next->next
    ->next->next->next->next->sprite, (sfIntRect){2464, 192, 202, 10});
    update_sound_volume(game, 100);
}

static int check_click_on_button(game_t *game,
    sprite_list_t *temp, sfMouseButtonEvent mouse)
{
    if (check_mouse_click_on(mouse, sfSprite_getGlobalBounds(temp->sprite))) {
        reset_settings(game);
        return 1;
    }
    temp = temp->next;
    if (check_mouse_click_on(mouse, sfSprite_getGlobalBounds(temp->sprite))) {
        change_state(game, game->old_state, 2);
        return 1;
    }
    return 0;
}

static void check_click_on_size(game_t *game, sfMouseButtonEvent mouse)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;

    if (game->settings->window_size == 1 &&
    mouse.y > window_height / 8 * 3 + 70 &&
    mouse.y < window_height / 8 * 3 + 70 + 50 &&
    mouse.x > window_width / 2 - 250 &&
    mouse.x < window_width / 2 - 250 + 100) {
        update_window_size(0);
        sfRenderWindow_close(game->window);
    }
    if (game->settings->window_size == 0 &&
    mouse.y > window_height / 8 * 3 + 70 &&
    mouse.y < window_height / 8 * 3 + 70 + 50 &&
    mouse.x > window_width / 2 - 125 &&
    mouse.x < window_width / 2 - 125 + 100) {
        update_window_size(1);
        sfRenderWindow_close(game->window);
    }
}

static int check_click_on_infinite_lives(game_t *game,
    text_list_t *temp, sfMouseButtonEvent mouse)
{
    if (check_mouse_click_on(mouse, sfText_getGlobalBounds(temp->text))) {
        if (my_strcmp(sfText_getString(temp->text), "On") == 0) {
            sfText_setString(temp->text, "Off");
            game->settings->lives = 3;
        } else {
            sfText_setString(temp->text, "On");
            game->settings->lives = 2147483647;
        }
        return 1;
    }
    return 0;
}

static int check_click_on_infinite_arrows(game_t *game,
    text_list_t *temp, sfMouseButtonEvent mouse)
{
    temp = temp->next;
    if (check_mouse_click_on(mouse, sfText_getGlobalBounds(temp->text))) {
        if (my_strcmp(sfText_getString(temp->text), "On") == 0) {
            sfText_setString(temp->text, "Off");
            game->settings->arrows = 30;
        } else {
            sfText_setString(temp->text, "On");
            game->settings->arrows = 2147483647;
        }
        return 1;
    }
    return 0;
}

static int check_click_on_music_volume(game_t *game,
    sprite_list_t *temp, sfMouseButtonEvent mouse)
{
    int window_width = (int)sfRenderWindow_getSize(game->window).x;

    temp = temp->next->next->next;
    if (check_mouse_click_on(mouse, sfSprite_getGlobalBounds(temp->sprite))) {
        temp = temp->next;
        sfSprite_setTextureRect(temp->sprite, (sfIntRect){2464, 192,
        (mouse.x - (window_width / 2 + 110)) / 262.6 * 202, 10});
        update_music_volume(game,
            (mouse.x - (window_width / 2 + 110)) / 262.6 * 100);
        return 1;
    }
    return 0;
}

static int check_click_on_sound_volume(game_t *game,
    sprite_list_t *temp, sfMouseButtonEvent mouse)
{
    int window_width = (int)sfRenderWindow_getSize(game->window).x;

    temp = temp->next->next->next->next->next;
    if (check_mouse_click_on(mouse, sfSprite_getGlobalBounds(temp->sprite))) {
        temp = temp->next;
        sfSprite_setTextureRect(temp->sprite, (sfIntRect){2464, 192,
        (mouse.x - (window_width / 2 + 110)) / 262.6 * 202, 10});
        update_sound_volume(game,
            (mouse.x - (window_width / 2 + 110)) / 262.6 * 100);
        return 1;
    }
    return 0;
}

static void check_click(game_t *game, sfEvent event)
{
    sprite_list_t *temp_sprite = game->display->sprite_list->next->next;
    text_list_t *temp_text = game->display->text_list->next->next;

    if (check_click_on_button(game, temp_sprite, event.mouseButton))
        return;
    check_click_on_size(game, event.mouseButton);
    if (check_click_on_infinite_lives(game, temp_text, event.mouseButton))
        return;
    if (check_click_on_infinite_arrows(game, temp_text, event.mouseButton))
        return;
    if (check_click_on_music_volume(game, temp_sprite, event.mouseButton))
        return;
    if (check_click_on_sound_volume(game, temp_sprite, event.mouseButton))
        return;
}

void event_setting(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseMoved) {
        if (game->display->sprite_list != NULL)
            mouse_on_button(game, event);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        check_click(game, event);
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape) {
        change_state(game, game->old_state, 2);
    }
}
