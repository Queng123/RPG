/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** use_generator
*/

#include "particles.h"

void display_pixel(sfRenderWindow *win, generator_t *generator)
{
    sfSprite_setTexture(generator->pixel->sprite,
    generator->pixel->texture, sfTrue);
    sfTexture_updateFromPixels(generator->pixel->texture, generator->pixel->pix,
    1920, 1080, 0, 0);
    sfSprite_setPosition(generator->pixel->sprite, generator->sprite_pos);
    sfRenderWindow_drawSprite(win, generator->pixel->sprite, NULL);
}

sfVector2f update_explosion(float ratio, float rotation, sfVector2f pos,
sfVector2f current_pos)
{
    current_pos = (sfVector2f) {pos.x - (ratio * 40) * sin(rotation),
    pos.y - (ratio * 40) * cos(rotation)};
    return (current_pos);
}

void display_particles(particles_t *particles, float ratio,
generator_t *generator)
{
    if (ratio < 0.5) {
        particles->actual = change_color_and_fade(particles->actual,
        particles->start, particles->end, ratio);
        particles->size_current =
        (particles->size_beging - particles->size_end) * ratio;
        particles->current_pos = update_explosion(ratio, particles->rotation,
        particles->save_pos, particles->current_pos);
    }
    create_bounce(generator->pixel, particles->current_pos, 3,
    particles->actual);
}

void use_generator(generator_t *generator, float animation_framerate,
sfRenderWindow *win)
{
    float ratio = 0;
    sfColor clear = (sfColor) {0, 0, 0, 0};

    while (generator->generator_clock->seconds >= animation_framerate) {
        generator->generator_clock->seconds -= animation_framerate;
        generator->life_remaining -= animation_framerate;
        ratio = generator->life_remaining / generator->lifetime;
        ratio = 1 - ratio;
        for (int i = 0; i != generator->nb_display; i++) {
            generator->particles[i]->active = true;
            display_particles(generator->particles[i], ratio, generator);
        }
    }
    display_pixel(win, generator);
    if (generator->life_remaining <= 0) {
        generator->display = false;
        generator->heal = 0;
        generator->pixel =
        clear_framebuffer(generator->pixel, 1920, 1080, &clear);
    }
}
