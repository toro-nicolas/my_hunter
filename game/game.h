/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The game.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../include/csfml.h"

#ifndef GAME_H_
    #define GAME_H_

    /* Files path */
    #define GAME_FONT "assets/fonts/font.ttf"
    #define TILESET "assets/images/tileset.png"
    #define GAME "assets/musics/game.ogg"
    #define TITLE_SCREEN "assets/musics/title_screen.ogg"
    #define BOW "assets/sounds/bow.ogg"
    #define CLICK "assets/sounds/click.ogg"
    #define CLOSE_MENU "assets/sounds/close_menu.ogg"
    #define KILL "assets/sounds/kill.ogg"
    #define OPEN_MENU "assets/sounds/open_menu.ogg"
    #define TICK "assets/sounds/tick.ogg"

    /* Background size */
    #define BG_WIDTH 1914
    #define BG_HEIGHT 1029

    /* State */
    #define MENU 0
    #define IN_GAME 1
    #define PAUSE 2
    #define SETTING 3
    #define GAME_OVER 4

/* Game */
typedef struct sprite_list_s {
    sfSprite *sprite;
    struct sprite_list_s *next;
} sprite_list_t;

typedef struct text_list_s {
    sfText *text;
    struct text_list_s *next;
} text_list_t;

typedef struct settings_s {
    sfMusic *music;
    float music_volume;
    int music_charged;
    sfMusic *sound;
    float sound_volume;
} settings_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfClock *game_time;
    sfEvent event;
    sfVector2f *mouse_position;
    int state;
    int background_pos[2];
    settings_t *settings;
    sprite_list_t *sprite_list;
    text_list_t *text_list;
    int on_menu_button;
    int button_menu_id;
} game_t;

/* Game */
settings_t *create_settings(void);
game_t *create_game(void);
void destroy_game(game_t *game);

/* Events */
void event_menu(game_t *game, sfEvent event);
void event_in_game(game_t *game, sfEvent event);
void event_pause(game_t *game, sfEvent event);
void event_setting(game_t *game, sfEvent event);
void event_game_over(game_t *game, sfEvent event);
void analyse_events(game_t *game, sfEvent event);

/* Display */
void display_menu(game_t *game);
void display_in_game(game_t *game);
void display_pause(game_t *game);
void display_setting(game_t *game);
void display_game_over(game_t *game);

/* Background */
void set_background(sfRenderWindow* window, char *file, int position[2]);

/* Sprites */
void create_sprite_list(game_t *game, sfSprite *sprite);
void add_sprite(game_t *game, sfSprite *sprite);
void destroy_all_sprites(game_t *game, sprite_list_t *sprite_list);
void display_sprites(game_t *game);

/* Texts */
void create_text_list(game_t *game, sfText *text);
void add_text(game_t *game, sfText *text);
void destroy_all_texts(game_t *game, text_list_t *text_list);
void display_texts(game_t *game);

/* Musics and sounds */
void play_sound(game_t *game, char *file);
void play_music(game_t *game, char *file);

void on_a_menu_button(game_t *game);

#endif /* GAME_H_ */
