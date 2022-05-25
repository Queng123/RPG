/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** current_item
*/

#include "rpg.h"

void init_clock_boss(game_t *game)
{
    game->boss_s->clock_s = malloc(sizeof(clockk_t));
    game->boss_s->clock_s->clock = sfClock_create();
    game->boss_s->clock_s->seconds = 0;
    game->boss_s->clock_s->time.microseconds = 0;
}

void init_ck_boss(game_t *game)
{
    game->boss_s->ck_boss = malloc(sizeof(clockk_t));
    game->boss_s->ck_boss->clock = sfClock_create();
    game->boss_s->ck_boss->seconds = 0;
    game->boss_s->ck_boss->time.microseconds = 0;
}

void init_value_boss(game_t *game)
{
    game->boss_s = malloc(sizeof(boss_t));
    game->boss_s->error = 0;
    game->boss_s->key_qte = 0;
    game->boss_s->frame_boss = 0;
    game->boss_s->life_player = 3;
    game->boss_s->life_boss = 3;
    game->boss_s->fight = false;
    game->boss_s->display_pop_art = 0;
    game->boss_s->bubulle_legende = 0;
    game->boss_s->menu_boss = 0;
}

void init_build_boss(game_t *game)
{
    build_ring(game->boss_s, 0);
    build_boss(game->boss_s, 1);
    build_tab_letter_key(game->boss_s, 3);
    build_versus(game->boss_s, 4);
    build_button_confirm(game->boss_s, 5);
    build_howtoplay_boss(game->boss_s, 6);
    build_ouch(game->boss_s, 7);
    build_paf(game->boss_s, 8);
    build_heart_player(game->boss_s, 9);
    build_heart_boss(game->boss_s, 10);
    build_button_next_boss(game->boss_s, 11);
    build_msg_boss_zero(game->boss_s, 12);
    build_msg_boss_one(game->boss_s, 13);
    build_msg_boss_two(game->boss_s, 14);
    build_os(game->boss_s, 15);
    build_skelleton(game->boss_s, 16);
}

int init_boss(game_t *game)
{
    init_value_boss(game);
    init_clock_boss(game);
    init_ck_boss(game);
    init_build_boss(game);

    if (game->boss_s->error == 1 || game->boss_s == NULL
    || game->boss_s->clock_s->clock == NULL)
        return (ERROR);
    return (SUCCESS);
}
