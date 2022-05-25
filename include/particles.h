/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** particles
*/

#ifndef PARTICLES_H_
    #define PARTICLES_H_
    #define PI 3.141592653589793238462643383279502884

    #include <math.h>
    #include <unistd.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <stdbool.h>
    #include "useful_structs.h"
    #include <stdlib.h>

typedef struct particles {
    sfColor actual;
    sfColor start;
    sfColor end;
    sfVector2f current_pos;
    sfVector2f save_pos;
    float size_beging;
    float size_current;
    float size_end;
    float rotation;
    bool active;
} particles_t;

typedef struct generator {
    float lifetime;
    float life_remaining;
    clockk_t *generator_clock;
    particles_t *particles[100];
    sfVector2f pos;
    bool display;
    int nb_display;
    int heal;
    pixel_t *pixel;
    sfVector2f sprite_pos;
} generator_t;

pixel_t *pixel_s_create(unsigned int width, unsigned int height);
void my_put_pixel(pixel_t *pixel_s, unsigned int x, unsigned int y,
sfColor *color);
generator_t *build_generator(void);
void use_generator(generator_t *generator, float animation_framerate,
sfRenderWindow *win);
generator_t *fill_generator(generator_t *generator, sfVector2f pos,
sfColor start, sfColor end);
pixel_t *clear_framebuffer(pixel_t *framebuffer, int x, int y, sfColor *color);
sfColor change_color_and_fade(sfColor actual, sfColor start, sfColor end,
float ratio);
void create_bounce(pixel_t *pixel_s, sfVector2f center, int radius,
sfColor color);

#endif/* !PARTICLES_H_ */
