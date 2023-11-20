/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The background.c
*/

#include "game.h"

void set_background(sfRenderWindow* window, char *file, int position[2])
{
    sfIntRect rect = {position[0], position[1], BG_WIDTH, BG_HEIGHT};
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.6666, 0.6666};

    if (open(file, O_RDONLY) != -1) {
        texture = sfTexture_createFromFile(file, &rect);
        if (texture != NULL) {
            sfSprite_setTexture(sprite, texture, sfFalse);
            sfSprite_setScale(sprite, scale);
            sfRenderWindow_drawSprite(window, sprite, NULL);
        }
        sfTexture_destroy(texture);
    }
    sfSprite_destroy(sprite);
}
