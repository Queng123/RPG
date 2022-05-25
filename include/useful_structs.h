/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** clock
*/

#ifndef CLOCK_H_
    #define CLOCK_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <stdbool.h>

typedef struct clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} clockk_t;

typedef struct pixel_s {
    int sl_color;
    unsigned int width;
    unsigned int height;
    sfSprite *sprite;
    sfTexture *texture;
    sfUint8 *pix;
} pixel_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
} sprite_t;

typedef struct text {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
    const char *str;
} text_t;

typedef struct sound {
    sfSoundBuffer *buff;
    sfSound *sound;
} sound_t;

typedef struct button_s {
    sprite_t *sprite;
    text_t *text;
    int status;
} button_t;

typedef struct music {
    sfMusic *game_music;
    float volume;
} music_t;

#endif/* !CLOCK_H_ */
