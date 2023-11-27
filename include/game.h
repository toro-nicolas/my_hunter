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
#include "csfml.h"

#ifndef GAME_H_
    #define GAME_H_

    /* Files path */
    #define GAME_FONT "assets/fonts/font.ttf"
    #define TILESET "assets/images/tileset.png"
    #define GAME "assets/musics/game.ogg"
    #define TITLE_SCREEN "assets/musics/title_screen.ogg"
    #define GAME_OVER_MUSIC "assets/musics/game_over.ogg"
    #define BOW "assets/sounds/bow.ogg"
    #define CLICK "assets/sounds/click.ogg"
    #define CLOSE_MENU "assets/sounds/close_menu.ogg"
    #define KILL "assets/sounds/kill.ogg"
    #define MONSTER_DAMAGE "assets/sounds/monster_damage.ogg"
    #define OPEN_MENU "assets/sounds/open_menu.ogg"
    #define PLAYER_DAMAGE "assets/sounds/player_damage.ogg"
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
typedef struct monster_list_s {
    sfSprite *monster_sprite;
    int size;
    int velocity;
    int life;
    int score;
    struct monster_list_s *next;
} monster_list_t;

typedef struct sprite_list_s {
    sfSprite *sprite;
    struct sprite_list_s *next;
} sprite_list_t;

typedef struct text_list_s {
    sfText *text;
    struct text_list_s *next;
} text_list_t;

typedef struct settings_s {
    int window_size;
    sfMusic *music;
    float music_volume;
    int music_charged;
    sfMusic *sound;
    float sound_volume;
    int show_mob_life;
    int level;
    int score;
    int record;
    int lives;
    int arrows;
} settings_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfClock *game_time;
    sfClock *animation_time;
    sfEvent event;
    int old_state;
    int state;
    int state_changed;
    sfSprite *background;
    sfSprite *cursor;
    settings_t *settings;
    sprite_list_t *sprite_list;
    text_list_t *text_list;
    int on_button;
    int button_id;
    monster_list_t *monster_list;
} game_t;

/* Settings */
int load_window_size(void);
int load_music_volume(void);
int load_sound_volume(void);
void update_window_size(int size);
void update_music_volume(game_t *game, int volume);
void update_sound_volume(game_t *game, int volume);

/* Game */
settings_t *create_settings(int eric_mode);
game_t *create_game(int eric_mode);
void destroy_game(game_t *game);
void init_game_logo(game_t *game);

/* Cursor */
void set_cursor(game_t *game);
void update_cursor(game_t *game);

/* Events */
void change_state(game_t *game, int state, int sound);
void set_button_id(game_t *game, int button_id);
int check_mouse_move_on(sfMouseMoveEvent mouse,
    sfFloatRect text_pos);
int check_mouse_click_on(sfMouseButtonEvent mouse,
    sfFloatRect text_pos);
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
void set_background(game_t *game, char *file, int const position[2]);

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
void reset_text_color(game_t *game);

/* Musics and sounds */
void play_sound(game_t *game, char *file);
void play_music(game_t *game, char *file);

/* Game over */
void check_game_over(game_t *game);

/* Buttons */
void on_a_menu_button(game_t *game);
void on_a_pause_button(game_t *game);
void on_a_game_over_button(game_t *game);
void on_a_setting_button(game_t *game);

/* Monsters */
void destroy_all_monsters(game_t *game, monster_list_t *monster_list);
void add_monster(game_t *game, sfSprite *sprite,
    int velocity, int score);
sfSprite *create_small_eye(game_t *game, int velocity);
sfSprite *create_big_eye(game_t *game, int velocity);
sfSprite *get_random_eye(game_t *game, int sign, int size);
void update_animation(game_t *game);
void update_monster(game_t *game);
void check_add_monster(game_t *game);
void display_monsters(game_t *game);

/* Game infos */
char *get_level_str(game_t *game);
char *get_record_str(game_t *game);
char *get_score_str(game_t *game);
char *get_monster_life_str(monster_list_t *monster);

/* In game */
void destroy_all_monsters(game_t *game, monster_list_t *monster_list);
void update_game(game_t *game);
void reset_game(game_t *game);

#endif /* GAME_H_ */
