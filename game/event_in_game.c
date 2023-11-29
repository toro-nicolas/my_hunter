/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The event_in_game.c
*/

#include "game.h"

void check_click_on_monster(game_t *game)
{
    sfFloatRect eye_pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow
        (game->window);
    int clicked = 0;

    for (monster_list_t *tmp = game->display->monster_list;
        tmp != NULL; tmp = tmp->next) {
        eye_pos = sfSprite_getGlobalBounds(tmp->monster_sprite);
        if ((float)mouse.x > (eye_pos.left) &&
        (float)mouse.x < (eye_pos.left + eye_pos.width) &&
        (float)mouse.y > (eye_pos.top) &&
        (float)mouse.y < (eye_pos.top + eye_pos.height)) {
            tmp->life = tmp->life - 1;
            play_sound(game, MONSTER_DAMAGE);
            clicked = 1;
        }
    }
    if (clicked == 0 && game->settings->arrows != 2147483647)
        game->settings->arrows = game->settings->arrows - 1;
}

void show_monster_life(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfText *monster_life_text = game->display->text_list->
        next->next->next->text;
    int on_eye = 0;

    for (monster_list_t *tmp = game->display->monster_list;
    tmp != NULL; tmp = tmp->next) {
        if (check_mouse_on(mouse,
        sfSprite_getGlobalBounds(tmp->monster_sprite))) {
            sfText_setString(monster_life_text, get_monster_life_str(tmp));
            sfText_setPosition(monster_life_text,
                (sfVector2f){(float)mouse.x + 30, (float)mouse.y - 20});
            on_eye = 1;
        }
    }
    if (on_eye == 0)
        sfText_setPosition(monster_life_text, (sfVector2f){-100, -100});
}

void event_in_game(game_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeyEscape) {
            change_state(game, PAUSE, 1);
        }
    }
    if (event.type == sfEvtMouseButtonPressed ||
    event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter) {
        play_sound(game, BOW);
        check_click_on_monster(game);
    }
    if (game->settings->show_mob_life == 1 && event.type == sfEvtMouseMoved)
        show_monster_life(game);
}
