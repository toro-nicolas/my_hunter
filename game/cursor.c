/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The cursor.c
*/

#include "game.h"

void set_cursor(game_t *game)
{
    sfIntRect cursor_rect = {2780, 0, 100, 100};
    sfVector2f scale = {0.5, 0.5};
    sprite_t cursor_image = {.file = TILESET, .rect = &cursor_rect,
        .scale = &scale};

    game->display->cursor = create_sf_sprite(&cursor_image,
        game->display->game_texture, (sfVector2f){0, 0});
}

void update_cursor(game_t *game)
{
    sfVector2i cursor_position = sfMouse_getPositionRenderWindow
        (game->window);

    sfSprite_setPosition(game->display->cursor, (sfVector2f)
    {((float)cursor_position.x - 25), ((float)cursor_position.y - 25)});
    sfRenderWindow_drawSprite(game->window, game->display->cursor, NULL);
}
