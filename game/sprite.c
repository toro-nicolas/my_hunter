/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The sprite.c
*/

#include "game.h"

void create_sprite_list(game_t *game, sfSprite *sprite)
{
    sprite_list_t *sprite_list = malloc(sizeof(sprite_list_t));

    sprite_list->sprite = sprite;
    sprite_list->next = NULL;
    game->sprite_list = sprite_list;
}

void add_sprite(game_t *game, sfSprite *sprite)
{
    sprite_list_t *new_list;

    if (game->sprite_list == NULL) {
        create_sprite_list(game, sprite);
    } else {
        new_list = malloc(sizeof(sprite_list_t));
        new_list->sprite = sprite;
        new_list->next = game->sprite_list;
        game->sprite_list = new_list;
    }
}

void destroy_all_sprites(game_t *game, sprite_list_t *sprite_list)
{
    if (game->sprite_list != NULL) {
        if (sprite_list->sprite != NULL) {
            sfTexture_destroy((sfTexture *)sfSprite_getTexture
                (sprite_list->sprite));
            sfSprite_destroy(sprite_list->sprite);
            sprite_list->sprite = NULL;
        }
        if (sprite_list->next != NULL) {
            destroy_all_sprites(game, sprite_list->next);
            free(sprite_list->next);
        }
        game->sprite_list = NULL;
    }
}

void display_sprites(game_t *game)
{
    sprite_list_t *temp = game->sprite_list;

    if (temp != NULL) {
        sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        while (temp->next != NULL) {
            temp = temp->next;
            sfRenderWindow_drawSprite(game->window, temp->sprite, NULL);
        }
    }
}
