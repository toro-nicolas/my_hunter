/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The event_menu.c
*/

#include "game.h"

static void set_button_id(game_t *game, int button_id)
{
    if (game->on_menu_button != 2 && game->button_menu_id == button_id)
        game->on_menu_button = 1;
    game->button_menu_id = button_id;
}

static int check_mouse_on_text(sfMouseMoveEvent mouse, sfFloatRect text_pos)
{
    if (mouse.x > (int)text_pos.left &&
        mouse.x < (int)text_pos.left + (int)text_pos.width &&
        mouse.y > (int)text_pos.top &&
        mouse.y < (int)text_pos.top + (int)text_pos.height)
        return 1;
    return 0;
}

void mouse_on_text(game_t *game, sfEvent event)
{
    text_list_t *temp = game->text_list;
    int button_id = 0;

    if (check_mouse_on_text(event.mouseMove,
        sfText_getGlobalBounds(temp->text))) {
        set_button_id(game, button_id);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
        button_id++;
        if (check_mouse_on_text(event.mouseMove,
            sfText_getGlobalBounds(temp->text))) {
            set_button_id(game, button_id);
            return;
        }
    }
    game->on_menu_button = 0;
}

static int check_mouse_on_button(sfMouseButtonEvent mouse,
    sfFloatRect text_pos)
{
    if (mouse.x > (int)text_pos.left &&
        mouse.x < (int)text_pos.left + (int)text_pos.width &&
        mouse.y > (int)text_pos.top &&
        mouse.y < (int)text_pos.top + (int)text_pos.height)
        return 1;
    return 0;
}

void check_click_on_button(game_t *game, sfEvent event)
{
    text_list_t *temp = game->text_list;

    if (check_mouse_on_button(event.mouseButton,
        sfText_getGlobalBounds(temp->text))) {
        game->state = IN_GAME;
        return;
    }
    temp = temp->next;
    if (check_mouse_on_button(event.mouseButton,
        sfText_getGlobalBounds(temp->text))) {
        game->state = SETTING;
        return;
    }
    temp = temp->next;
    if (check_mouse_on_button(event.mouseButton,
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
        play_sound(game, CLICK);
        check_click_on_button(game, event);
    }
}
