/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The event_menu.c
*/

#include "game.h"

static void mouse_on_text(game_t *game, sfEvent event)
{
    text_list_t *temp = game->text_list;
    int button_id = 0;

    if (check_mouse_move_on(event.mouseMove,
        sfText_getGlobalBounds(temp->text))) {
        set_button_id(game, button_id);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
        button_id++;
        if (check_mouse_move_on(event.mouseMove,
            sfText_getGlobalBounds(temp->text))) {
            set_button_id(game, button_id);
            return;
        }
    }
    game->on_button = 0;
}

static void check_click_on_button(game_t *game, sfEvent event)
{
    text_list_t *temp = game->text_list;

    if (check_mouse_click_on(event.mouseButton,
        sfText_getGlobalBounds(temp->text))) {
        play_sound(game, CLICK);
        change_state(game, IN_GAME, 0);
        return;
    }
    temp = temp->next;
    if (check_mouse_click_on(event.mouseButton,
        sfText_getGlobalBounds(temp->text))) {
        play_sound(game, CLICK);
        change_state(game, SETTING, 1);
        return;
    }
    temp = temp->next;
    if (check_mouse_click_on(event.mouseButton,
        sfText_getGlobalBounds(temp->text))) {
        sfRenderWindow_close(game->window);
    }
}

void event_menu(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseMoved) {
        if (game->text_list != NULL)
            mouse_on_text(game, event);
    }
    if (event.type == sfEvtMouseButtonPressed) {
        check_click_on_button(game, event);
    }
}
