/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The in_game.c
*/

#include "game.h"

static void init_text_3(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    text_t arrow_text = {.text = "2147483647", .font = GAME_FONT, .size = 30,
        .color = sfWhite, .outlineColor_size = 1.0, .outlineColor = sfBlack};
    sfVector2f arrow_position = {window_width / 16 * 3.3,
        window_height / 8 * 7.25};
    sfText *arrow = create_sf_text(&arrow_text, arrow_position);

    add_text(game, arrow);
}

static void init_text_2(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    text_t score_text = {.text = "Score: ", .font = GAME_FONT, .size = 40,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f score_position = {window_width / 8 * 4,
        window_height / 8 * 7.125};
    sfText *score = create_sf_text(&score_text, score_position);
    text_t monster_life_text = {.text = "Life: ", .font = GAME_FONT,
        .size = 30, .color = sfWhite,
        .outlineColor_size = 2.0, .outlineColor = sfBlack};
    sfVector2f monster_life_position = {-100, -100};
    sfText *monster_life = create_sf_text(&monster_life_text,
        monster_life_position);

    add_text(game, score);
    add_text(game, monster_life);
    init_text_3(game);
}

static void init_text(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    text_t level_text = {.text = "Level", .font = GAME_FONT, .size = 60,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f level_position = {window_width / 8 * 2.5,
        window_height / 8 * 7};
    sfText *level = create_sf_text(&level_text, level_position);
    text_t record_text = {.text = "Record: ", .font = GAME_FONT, .size = 40,
        .color = sfWhite, .outlineColor_size = 5.0, .outlineColor = sfBlack};
    sfVector2f record_position = {window_width / 8 * 6,
        window_height / 8 * 7.125};
    sfText *record = create_sf_text(&record_text, record_position);

    add_text(game, level);
    add_text(game, record);
    init_text_2(game);
}

static void init_arrows(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sfIntRect arrow_rect = {2532, 150, 14, 32};
    float scale = (game->settings->window_size) ? 2.5 : 2;
    sprite_t arrow_image = {.file = TILESET, .rect = &arrow_rect,
        .scale = &(sfVector2f){scale, scale}};
    sfSprite *arrow = create_sf_sprite(&arrow_image,
        game->display->game_texture,
        (sfVector2f){window_width / 16 * 3, window_height / 8 * 7.125});

    add_sprite(game, arrow);
}

static void init_hearts(game_t *game)
{
    float window_width = (float)sfRenderWindow_getSize(game->window).x;
    float window_height = (float)sfRenderWindow_getSize(game->window).y;
    sfIntRect heart_rect = {2466, 150, 22, 22};
    float scale = (game->settings->window_size) ? 2.5 : 2;
    sprite_t heart_image = {.file = TILESET, .rect = &heart_rect,
        .scale = &(sfVector2f){scale, scale}};
    sfSprite *heart_1 = create_sf_sprite(&heart_image,
        game->display->game_texture,
        (sfVector2f){window_width / 16 * 1, window_height / 8 * 7.2});
    sfSprite *heart_2 = create_sf_sprite(&heart_image,
        game->display->game_texture,
        (sfVector2f){window_width / 16 * 1.5, window_height / 8 * 7.2});
    sfSprite *heart_3 = create_sf_sprite(&heart_image,
        game->display->game_texture,
        (sfVector2f){window_width / 16 * 2, window_height / 8 * 7.2});

    add_sprite(game, heart_3);
    add_sprite(game, heart_2);
    add_sprite(game, heart_1);
}

void display_in_game(game_t *game)
{
    int sign = (rand() % 2) ? -1 : 1;

    set_background(game, (int [2]){0, 0});
    if (game->settings->music_charged != IN_GAME) {
        game->settings->music_charged = IN_GAME;
        play_music(game, GAME);
    }
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    init_text(game);
    init_hearts(game);
    init_arrows(game);
}

static void update_text(game_t *game)
{
    sfText_setString(game->display->text_list->text,
        get_level_str(game));
    sfText_setString(game->display->text_list->next->text,
        get_record_str(game));
    sfText_setString(game->display->text_list->next->next->text,
        get_score_str(game));
    sfText_setString(game->display->text_list->next->next->next->next->text,
        my_str_nbr(game->settings->arrows));
}

static void update_life(game_t *game)
{
    int life_number = 0;
    sprite_list_t *list_to_free;

    for (sprite_list_t *tmp = game->display->sprite_list;
    tmp != NULL; tmp = tmp->next) {
        life_number = life_number + 1;
    }
    if (game->settings->lives < 3 && game->settings->lives > -1 &&
    life_number - 1 != game->settings->lives) {
        sfSprite_destroy(game->display->sprite_list->sprite);
        game->display->sprite_list->sprite = NULL;
        list_to_free = game->display->sprite_list;
        game->display->sprite_list = game->display->sprite_list->next;
        free(list_to_free);
    }
}

void update_game(game_t *game)
{
    if (sfClock_getElapsedTime(game->animation_time).microseconds
    / 1000000.0 > 0.2)
        update_animation(game);
    if (sfClock_getElapsedTime(game->game_time).microseconds
    / 1000000.0 > 0.005)
        update_monster(game);
    game->settings->level = (game->settings->score + 1000) / 1000;
    if (game->settings->score > game->settings->record)
        update_record(game);
    check_add_monster(game);
    update_text(game);
    update_life(game);
    check_game_over(game);
    display_monsters(game);
    update_cursor(game);
}

void reset_game(game_t *game)
{
    game->settings->lives =
        (game->settings->lives == 2147483647) ? 2147483647 : 3;
    game->settings->arrows =
        (game->settings->arrows == 2147483647) ? 2147483647 : 30;
    game->settings->score = 0;
    game->settings->level = 1;
    destroy_all_monsters(game, game->display->monster_list);
}
