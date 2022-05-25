/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** current_item
*/

#include "rpg.h"
#include "player.h"

void check_if_player_hit(game_t *game)
{
    game->boss_s->life_player -= 1;
    game->boss_s->clock_s->seconds = 0;
    game->boss_s->fight = false;
    game->boss_s->display_pop_art = 1;
}

void check_if_boss_hit(game_t *game)
{
    game->boss_s->life_boss -= 1;
    game->boss_s->clock_s->seconds = 0;
    game->boss_s->fight = false;
    game->boss_s->display_pop_art = 2;
}

void reset_info_for_fight(game_t *game)
{
    game->boss_s->key_rand = rand() % 26;
    game->boss_s->clock_s->seconds = 0;
    game->boss_s->fight = true;
    game->boss_s->display_pop_art = 0;
}

void respawn_player_hopital_boss(game_t *game)
{
    int x = game->map->x_player;
    int y = game->map->y_player;

    game->boss_s->fight = false;
    game->boss_s->life_player = 3;
    game->boss_s->frame_boss = 1;
    game->boss_s->bubulle_legende = 0;
    game->map->x_player = 472;
    game->map->y_player = 210;
    game->map->pos_x = 450;
    game->map->pos_y = 197;
    game->player->obj->hp = game->player->health->max_score;
    update_health_bar(game->player->obj, game->player->health);
    game->map->map_p[y][x] = ' ';
    x = game->map->x_player;
    y = game->map->y_player;
    game->map->map_p[y][x] = 'P';
    game->game_info->scene->actual_game_scene = GAMEPLAY;
}

void systeme_fight(game_t *game)
{
    display_key_rand(game);
    if (game->boss_s->clock_s->seconds >= 1 && game->boss_s->fight == true) {
        check_if_player_hit(game);
        return;
    }
    if (game->boss_s->key_qte == game->boss_s->key_rand
    && game->boss_s->fight == true) {
        check_if_boss_hit(game);
        return;
    }
    display_pop_art(game);
    if (game->boss_s->clock_s->seconds >= 1) {
        reset_info_for_fight(game);
        if (game->boss_s->life_boss == 0)
            game->boss_s->frame_boss = 3;
        if (game->boss_s->life_player == 0)
            respawn_player_hopital_boss(game);
        return;
    }
}
