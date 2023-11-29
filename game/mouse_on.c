/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The mouse_on.c
*/

#include "game.h"

int check_mouse_move_on(sfMouseMoveEvent mouse,
    sfFloatRect text_pos)
{
    if ((float)mouse.x > (text_pos.left) &&
    (float)mouse.x < (text_pos.left + text_pos.width) &&
    (float)mouse.y > (text_pos.top) &&
    (float)mouse.y < (text_pos.top + text_pos.height))
        return 1;
    return 0;
}

int check_mouse_click_on(sfMouseButtonEvent mouse,
    sfFloatRect text_pos)
{
    if ((float)mouse.x > (text_pos.left) &&
    (float)mouse.x < (text_pos.left + text_pos.width) &&
    (float)mouse.y > (text_pos.top) &&
    (float)mouse.y < (text_pos.top + text_pos.height))
        return 1;
    return 0;
}

int check_mouse_on(sfVector2i mouse,
    sfFloatRect text_pos)
{
    if ((float)mouse.x > (text_pos.left) &&
    (float)mouse.x < (text_pos.left + text_pos.width) &&
    (float)mouse.y > (text_pos.top) &&
    (float)mouse.y < (text_pos.top + text_pos.height))
        return 1;
    return 0;
}
