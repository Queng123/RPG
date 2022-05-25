/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** fill_generator_struct
*/

#include "particles.h"

static clockk_t *restart_generator_clock(clockk_t *clock)
{
    clock->time.microseconds = 0;
    clock->seconds = 0;
    sfClock_restart(clock->clock);
    return (clock);
}

static particles_t *fill_particles(particles_t *particles, sfColor start,
sfColor end, sfVector2f pos)
{
    particles->active = false;
    particles->actual = start;
    particles->start = start;
    particles->end = end;
    particles->rotation = (rand() % 360) * PI/180;
    particles->size_beging = 10;
    particles->size_current = 10;
    particles->size_end = 1;
    particles->current_pos = pos;
    particles->save_pos = pos;
    return (particles);
}

generator_t *fill_generator(generator_t *generator, sfVector2f pos,
sfColor start, sfColor end)
{
    generator->lifetime = 0.5;
    generator->life_remaining = 0.5;
    generator->generator_clock =
    restart_generator_clock(generator->generator_clock);
    generator->display = true;
    generator->pos = pos;
    generator->sprite_pos = (sfVector2f) {0, 0};
    generator->nb_display = 80;
    generator->heal = 0;
    for (int i = 0; i != 100; i++) {
        generator->particles[i] =
        fill_particles(generator->particles[i], start, end, pos);
    }
    return (generator);
}
