/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The header of the csfml functions
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

#ifndef CSFML_H_
    #define CSFML_H_

/* Pixels functions */
typedef struct framebuffer_s {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width,
    unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void framebuffer_draw(sfRenderWindow *window,
    framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer,
    unsigned int x, unsigned int y, sfColor color);
void draw_square(framebuffer_t *framebuffer, sfVector2u position,
    unsigned int size, sfColor color);

/* Images functions */
typedef struct sprite_s {
    char *file;
    sfIntRect *rect;
    sfVector2f *scale;
    sfColor *color;
    float rotation;
} sprite_t;

void image_draw(sfRenderWindow* window, char *file,
    unsigned int width, unsigned  int height);
void image_draw_from_rect(sfRenderWindow* window, char *file, sfIntRect *rect);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_rect_from_start(sfIntRect *rect, int start, int offset,
    int sprite_numbers);
sfSprite *create_sf_sprite(sprite_t *sprite_box, sfTexture *texture,
    sfVector2f position);

/* Text functions */
typedef struct text_s {
    char *text;
    char *font;
    int size;
    float lineSpacing;
    float letterSpacing;
    sfColor color;
    float outlineColor_size;
    sfColor outlineColor;
    float rotation;
    sfUint32 style;
} text_t;

void draw_text(sfRenderWindow* window, text_t *text_box, sfVector2f position);
sfText *create_sf_text(text_t *text_box, sfVector2f position);

/* Music and sound functions */
void play_sound_with_sleep(char *file, float volume);

#endif /* CSFML_H_ */
