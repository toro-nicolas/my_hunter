/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The monster.c
*/

#include "game.h"

void destroy_all_monsters(game_t *game, monster_list_t *monster_list)
{
    if (game->display->monster_list != NULL) {
        if (monster_list->monster_sprite != NULL) {
            sfSprite_destroy(monster_list->monster_sprite);
            monster_list->monster_sprite = NULL;
        }
        if (monster_list->next != NULL) {
            destroy_all_monsters(game, monster_list->next);
            free(monster_list->next);
        }
        game->display->monster_list = NULL;
    }
}

void add_monster(game_t *game, sfSprite *sprite,
    int velocity, int score)
{
    monster_list_t *monster_list = malloc(sizeof(monster_list_t));

    monster_list->monster_sprite = sprite;
    monster_list->size = sfSprite_getGlobalBounds(sprite).width /
        sfSprite_getScale(sprite).y;
    monster_list->velocity = velocity * game->settings->level;
    monster_list->life = rand() % 3 + 1;
    monster_list->score = score;
    if (game->display->monster_list == NULL)
        monster_list->next = NULL;
    else
        monster_list->next = game->display->monster_list;
    game->display->monster_list = monster_list;
}

static sfSprite *create_small_eye(game_t *game, int velocity)
{
    int selected_eye = rand() % 6;
    sfVector2f scale = {-2.5, 2.5};
    sfVector2f eye_pos = {0, (float)(rand() %
        (int)(sfRenderWindow_getSize(game->window).y - 21 * 2.5))};
    sfIntRect eye_rec = {0, 2161 + selected_eye + (selected_eye * 22), 36, 22};
    sprite_t eye = {.file = TILESET, .scale = &scale};
    sfSprite *eye_sprite;

    if (velocity < 0) {
        scale.x = 2.5;
        eye_pos.x = (float)(sfRenderWindow_getSize(game->window).x);
    }
    eye_sprite = create_sf_sprite(&eye, game->display->game_texture, eye_pos);
    sfSprite_setTextureRect(eye_sprite, eye_rec);
    return eye_sprite;
}

static sfSprite *create_big_eye(game_t *game, int velocity)
{
    int selected_eye = rand() % 2;
    sfVector2f scale = {-2.5, 2.5};
    sfVector2f eye_pos = {0, (float)(rand() %
        (int)(sfRenderWindow_getSize(game->window).y - 31 * 2.5))};
    sfIntRect eye_rec = {0, 2299 + selected_eye + (selected_eye * 32), 46, 32};
    sprite_t eye = {.file = TILESET, .scale = &scale};
    sfSprite *eye_sprite;

    if (velocity < 0) {
        scale.x = 2.5;
        eye_pos.x = (float)(sfRenderWindow_getSize(game->window).x);
    }
    eye_sprite = create_sf_sprite(&eye, game->display->game_texture, eye_pos);
    sfSprite_setTextureRect(eye_sprite, eye_rec);
    return eye_sprite;
}

sfSprite *get_random_eye(game_t *game, int sign, int size)
{
    if (game->settings->level >= 5 && size == 3) {
        return create_big_eye(game, sign);
    }
    return create_small_eye(game, sign);
}

void display_monsters(game_t *game)
{
    for (monster_list_t *tmp = game->display->monster_list;
    tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(game->window, tmp->monster_sprite, NULL);
    }
}
