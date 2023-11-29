/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The background.c
*/

#include "game.h"

void set_background(game_t *game, int const position[2])
{
    sfIntRect rect = {position[0], position[1], BG_WIDTH, BG_HEIGHT};
    sfSprite *sprite = sfSprite_create();
    float scale = (game->settings->window_size) ? 1.0 : 0.75;

    if (game->display->background != NULL) {
        sfSprite_destroy(game->display->background);
    }
    sfSprite_setTexture(sprite, game->display->game_texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    game->display->background = sprite;
}
