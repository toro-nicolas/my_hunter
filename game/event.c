/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The event.c
*/

#include "game.h"

static void manage_mouse_click(sfMouseButtonEvent event)
{
    my_printf("Mouse x=%d y=%d\n", event.x, event.y);
}

static void check_size(sfRenderWindow *window)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2u max_size = {1920, 1080};
    sfVector2u min_size = {800, 600};
    sfVector2u new_size = {size.x, size.y};

    if (size.x > max_size.x)
        new_size.x = max_size.x;
    if (size.y > max_size.y)
        new_size.y = max_size.y;
    if (size.x < min_size.x)
        new_size.x = min_size.x;
    if (size.y < min_size.y)
        new_size.y = min_size.y;
    if (size.x != new_size.x || size.y != new_size.y) {
        my_printf("%u, %u --> %u, %u\n",
            size.x, size.y, new_size.x, new_size.y);
        sfRenderWindow_setSize(window, new_size);
    }
}

static void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

/*static void get_mouse_postion(game_t *game, sfMouseMoveEvent mouse)
{
    if (game->state == IN_GAME) {
        game->mouse_position->x = (float)mouse.x;
        game->mouse_position->y = (float)mouse.y;
    }
}*/

void analyse_events(game_t *game, sfEvent event)
{
    void (*event_functions[])(game_t *, sfEvent) = {&event_menu,
        &event_in_game, &event_pause, &event_setting, &event_game_over};

    if (event.type == sfEvtClosed)
        close_window(game->window);
    if (event.type == sfEvtMouseButtonPressed) {
        check_size(game->window);
        manage_mouse_click(event.mouseButton);
        if (game->state == 0)
            game->on_menu_button = 0;
    }
    event_functions[game->state](game, event);
}
