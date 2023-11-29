/*
** EPITECH PROJECT, 2023
** bsmyhunter
** File description:
** main.c
*/

#include "./include/csfml.h"
#include "./include/game.h"

static void sort_text_list(game_t *game)
{
    text_list_t *previous_text_list = NULL;
    text_list_t *current_text_list = game->display->text_list;
    text_list_t *next_text_list = NULL;

    while (current_text_list != NULL) {
        next_text_list = current_text_list->next;
        current_text_list->next = previous_text_list;
        previous_text_list = current_text_list;
        current_text_list = next_text_list;
    }
    game->display->text_list = previous_text_list;
}

static void sort_sprite_list(game_t *game)
{
    sprite_list_t *previous_sprite_list = NULL;
    sprite_list_t *current_sprite_list = game->display->sprite_list;
    sprite_list_t *next_sprite_list = NULL;

    while (current_sprite_list != NULL) {
        next_sprite_list = current_sprite_list->next;
        current_sprite_list->next = previous_sprite_list;
        previous_sprite_list = current_sprite_list;
        current_sprite_list = next_sprite_list;
    }
    game->display->sprite_list = previous_sprite_list;
}

static void sort_state_element(game_t *game)
{
    sort_sprite_list(game);
    sort_text_list(game);
}

static void on_a_button(game_t *game)
{
    if (game->state == MENU && game->state_changed == 0)
        on_a_menu_button(game);
    if (game->state == PAUSE && game->state_changed == 0)
        on_a_pause_button(game);
    if (game->state == SETTING && game->state_changed == 0)
        on_a_setting_button(game);
    if (game->state == GAME_OVER && game->state_changed == 0)
        on_a_game_over_button(game);
}

static void update_window(game_t *game)
{
    void (*display_state[])(game_t *) = {&display_menu, &display_in_game,
        &display_pause, &display_setting, &display_game_over};

    if (game->state_changed == 1) {
        game->on_button = 0;
        game->button_id = 0;
        destroy_all_texts(game, game->display->text_list);
        destroy_all_sprites(game, game->display->sprite_list);
        display_state[game->state](game);
        sort_state_element(game);
        game->state_changed = 0;
    }
}

static void display_window(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    update_window(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        analyse_events(game, game->event);
    }
    on_a_button(game);
    sfRenderWindow_drawSprite(game->window, game->display->background, NULL);
    if (game->state == IN_GAME && game->state_changed == 0)
        update_game(game);
    display_sprites(game);
    display_texts(game);
    sfRenderWindow_display(game->window);
}

int init_game(int eric_mode)
{
    game_t *game = create_game(eric_mode);

    if (!game->window) {
        return EXIT_FAILURE;
    }
    while (sfRenderWindow_isOpen(game->window)) {
        display_window(game);
    }
    destroy_game(game);
    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    int eric_mode = 0;

    if (argc != 1) {
        if (my_strcmp(argv[1], "-h") == 0 || my_strcmp(argv[1], "--help") == 0)
            return show_help();
        if (my_strcmp(argv[1], "-e") == 0 || my_strcmp(argv[1], "--eric") == 0)
            eric_mode = 1;
        else {
            my_putstr_error("my_hunter: invalid option\n"
                "Try './my_hunter --help' for more information.\n");
            return 84;
        }
    }
    return init_game(eric_mode);
}
