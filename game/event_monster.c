/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The event_monster.c
*/

#include "game.h"

static void check_alive(game_t *game, monster_list_t *tmp,
    sfVector2f *sprite_pos, float new_pos_y)
{
    float scale = sfSprite_getScale(tmp->monster_sprite).y;
    int new_life = (game->settings->lives != 2147483647) ? -1 : 0;

    if (sprite_pos->x > (float)sfRenderWindow_getSize(game->window).x +
    sfSprite_getGlobalBounds(tmp->monster_sprite).width) {
        sfSprite_setPosition(tmp->monster_sprite, (sfVector2f)
            {sfRenderWindow_getSize(game->window).x, new_pos_y});
        sfSprite_setScale(tmp->monster_sprite,
            (sfVector2f){ABS(scale), scale});
        tmp->velocity = -tmp->velocity;
        play_sound(game, PLAYER_DAMAGE);
        game->settings->lives = game->settings->lives + new_life;
    }
    if (sprite_pos->x < -sfSprite_getGlobalBounds(tmp->monster_sprite).width) {
        sfSprite_setPosition(tmp->monster_sprite, (sfVector2f) {0, new_pos_y});
        sfSprite_setScale(tmp->monster_sprite, (sfVector2f){-scale, scale});
        tmp->velocity = -tmp->velocity;
        play_sound(game, PLAYER_DAMAGE);
        game->settings->lives = game->settings->lives + new_life;
    }
}

static void check_dead(game_t *game, monster_list_t *tmp)
{
    int sign = (rand() % 2) ? -1 : 1;
    int size = (rand() % 11 > 9) ? 3 : 1;

    if (tmp->next != NULL && tmp->next->life <= 0) {
        play_sound(game, KILL);
        game->settings->score += tmp->score;
        sfSprite_destroy(tmp->next->monster_sprite);
        tmp->next = tmp->next->next;
        add_monster(game, get_random_eye(game, sign, size), sign, size * 100);
    }
    if (tmp->life <= 0) {
        play_sound(game, KILL);
        game->settings->score += tmp->score;
        sfSprite_destroy(tmp->monster_sprite);
        game->display->monster_list = tmp->next;
        add_monster(game, get_random_eye(game, sign, size), sign, size * 100);
    }
}

void update_animation(game_t *game)
{
    sfIntRect rect;

    for (monster_list_t *tmp = game->display->monster_list;
    tmp != NULL; tmp = tmp->next) {
        rect = sfSprite_getTextureRect(tmp->monster_sprite);
        move_rect_from_start(&rect, 0, tmp->size, 4);
        sfSprite_setTextureRect(tmp->monster_sprite, rect);
    }
    sfClock_restart(game->animation_time);
}

void update_monster(game_t *game)
{
    sfVector2f sprite_pos;
    float new_pos_y;
    int sign;

    for (monster_list_t *tmp = game->display->monster_list;
    tmp != NULL; tmp = tmp->next) {
        sprite_pos = sfSprite_getPosition(tmp->monster_sprite);
        new_pos_y = rand() % (int)(sfRenderWindow_getSize(game->window).y -
            sfSprite_getGlobalBounds(tmp->monster_sprite).width *
            sfSprite_getScale(tmp->monster_sprite).y);
        sign = (tmp->velocity > 0) ? 1 : -1;
        sfSprite_move(tmp->monster_sprite, (sfVector2f){(float)tmp->velocity
            * 0.01 * (tmp->score / 100) + sign, 0});
        check_alive(game, tmp, &sprite_pos, new_pos_y);
        check_dead(game, tmp);
        sfClock_restart(game->game_time);
    }
}

void check_add_monster(game_t *game)
{
    monster_list_t *temp = game->display->monster_list;
    int monster_number = 0;
    int sign = (rand() % 2) ? -1 : 1;
    int size = (rand() % 11 > 9) ? 3 : 1;

    for (; temp != NULL; temp = temp->next)
        monster_number = monster_number + 1;
    if (monster_number < game->settings->level)
        add_monster(game, get_random_eye(game, sign, size), sign, size * 100);
}
