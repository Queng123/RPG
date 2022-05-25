/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** feed_struct_pixel_info
*/

#include "particles.h"

static particles_t *build_particles(void)
{
    particles_t *particles = malloc(sizeof(particles_t));

    if (particles == NULL)
        return (NULL);
    particles->rotation = (rand() % 360) * PI/180;
    particles->size_beging = 100;
    particles->size_current = 100;
    particles->size_end = 1;
    particles->active = false;
    return (particles);
}

clockk_t *clock_generator(void)
{
    clockk_t *generator_clock = malloc(sizeof(clockk_t));

    if (generator_clock == NULL)
        return (NULL);
    generator_clock->clock = sfClock_create();
    if (generator_clock->clock == NULL)
        return (NULL);
    generator_clock->seconds = 0;
    generator_clock->time.microseconds = 0;
    return (generator_clock);
}

generator_t *build_generator(void)
{
    generator_t *generator = malloc(sizeof(generator_t));

    if (generator == NULL)
        return (NULL);
    generator->life_remaining = 1;
    generator->lifetime = 1;
    generator->generator_clock = clock_generator();
    if (generator->generator_clock == NULL)
        return (NULL);
    generator->display = false;
    generator->sprite_pos = (sfVector2f) {0, 0};
    generator->pixel = pixel_s_create(1920, 1080);
    generator->heal = 0;
    for (int i = 0; i != 100; i++) {
        generator->particles[i] = build_particles();
        if (generator->particles[i] == NULL)
            return (NULL);
    }
    return (generator);
}
