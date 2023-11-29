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
    game->display->sprite_list = sprite_list;
}

void add_sprite(game_t *game, sfSprite *sprite)
{
    sprite_list_t *new_list;

    if (game->display->sprite_list == NULL) {
        create_sprite_list(game, sprite);
    } else {
        new_list = malloc(sizeof(sprite_list_t));
        new_list->sprite = sprite;
        new_list->next = game->display->sprite_list;
        game->display->sprite_list = new_list;
    }
}

void destroy_all_sprites(game_t *game, sprite_list_t *sprite_list)
{
    if (game->display->sprite_list != NULL) {
        if (sprite_list->sprite != NULL) {
            sfSprite_destroy(sprite_list->sprite);
            sprite_list->sprite = NULL;
        }
        if (sprite_list->next != NULL) {
            destroy_all_sprites(game, sprite_list->next);
            free(sprite_list->next);
        }
        game->display->sprite_list = NULL;
    }
}

void display_sprites(game_t *game)
{
    for (sprite_list_t *tmp = game->display->sprite_list;
    tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
    }
}
