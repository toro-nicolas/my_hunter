/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The in_game.c
*/

#include "game.h"

/*static void get_mouse_position(game_t *game)
{
    sfVector2f mouse_position;
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        my_putchar('b');
        if (event.type == sfEvtMouseMoved) {
            my_printf("Mouse x=%d y=%d|\n", event.mouseMove.x,
                      event.mouseMove.y);
            mouse_position.x = (float) event.mouseMove.x;
            mouse_position.y = (float) event.mouseMove.y;
        }
    }
    //my_printf("Mouse x=%f y=%f|\n", mouse_position.x, mouse_position.y);
    game->mouse_position = &mouse_position;
}*/

static void set_cursor(game_t *game)
{
    //get_mouse_position(game);
    //my_printf("Mouse x=%f y=%f\n", game->mouse_position->x,
    //          game->mouse_position->y);
    //sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    //sfRenderWindow_pollEvent(game->window, &game->event);
    sfIntRect logo_rect = {2773, 0, 100, 100};
    sfVector2f scale = {0.5, 0.5};
    sprite_t logo_image = {.file = TILESET, .rect = &logo_rect,
        .scale = &scale};
    sfVector2i logo_position_i = sfMouse_getPositionRenderWindow
        (game->window);
    sfVector2f logo_position_f = {(float)logo_position_i.x,
                                  (float)logo_position_i.y};
        //*game->mouse_position;
    sfSprite *logo = create_sf_sprite(&logo_image, logo_position_f);
    my_putchar('q');

    add_sprite(game, logo);
}

void display_in_game(game_t *game)
{
    game->background_pos[1] = 0;
    if (game->settings->music_charged == MENU) {
        game->settings->music_charged = IN_GAME;
        play_music(game, GAME);
    }
    //my_putchar('c');
    //my_printf("Mouse x=%f y=%f|\n", game->mouse_position->x,
    //          game->mouse_position->y);
    //set_cursor(game);
    //init_sprite(game);
    //init_text(game);
}
