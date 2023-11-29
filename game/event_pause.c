/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The event_pause.c
*/

#include "game.h"

static void mouse_on_button(game_t *game, sfEvent event)
{
    sprite_list_t *temp = game->display->sprite_list->next;
    int button_id = 0;

    if (check_mouse_move_on(event.mouseMove,
    sfSprite_getGlobalBounds(temp->sprite))) {
        set_button_id(game, button_id);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
        button_id++;
        if (check_mouse_move_on(event.mouseMove,
        sfSprite_getGlobalBounds(temp->sprite))) {
            set_button_id(game, button_id);
            return;
        }
    }
    game->on_button = 0;
}

static void check_click_on_button(game_t *game, sfEvent event)
{
    sprite_list_t *temp = game->display->sprite_list->next;

    if (check_mouse_click_on(event.mouseButton,
    sfSprite_getGlobalBounds(temp->sprite))) {
        play_sound(game, CLICK);
        change_state(game, IN_GAME, 2);
        return;
    }
    temp = temp->next;
    if (check_mouse_click_on(event.mouseButton,
    sfSprite_getGlobalBounds(temp->sprite))) {
        play_sound(game, CLICK);
        change_state(game, MENU, 0);
    }
}

void event_pause(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseMoved) {
        if (game->display->sprite_list != NULL)
            mouse_on_button(game, event);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        check_click_on_button(game, event);
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape) {
        change_state(game, IN_GAME, 2);
    }
}
