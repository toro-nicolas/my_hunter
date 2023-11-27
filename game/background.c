/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The background.c
*/

#include "game.h"

void set_background(game_t *game, char *file, int const position[2])
{
    sfIntRect rect = {position[0], position[1], BG_WIDTH, BG_HEIGHT};
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    float scale = (game->settings->window_size) ? 1.0 : 0.75;

    if (game->background != NULL) {
        sfTexture_destroy((sfTexture *) sfSprite_getTexture(game->background));
        sfSprite_destroy(game->background);
    }
    if (open(file, O_RDONLY) != -1) {
        texture = sfTexture_createFromFile(file, &rect);
        if (texture != NULL) {
            sfSprite_setTexture(sprite, texture, sfFalse);
            sfSprite_setScale(sprite, (sfVector2f){scale, scale});
            sfRenderWindow_drawSprite(game->window, sprite, NULL);
            game->background = sprite;
        }
    }
}
