/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_health
*/

#include "player.h"

void update_health_bar(obj_t *player, bar_t *health)
{
    health->info->rect.width = player->hp * 4;

    sfSprite_setTextureRect(health->info->sprite, health->info->rect);
}

void add_health(game_t *game)
{
    int current_health = game->player->health->current_score;
    int max_health = game->player->health->max_score;

    if (current_health > max_health) {
        game->player->health->current_score = max_health;
        return;
    }
    game->player->health->current_score += 1;
    update_health_bar(game->player->obj, game->player->health);
}

void display_player_health_stamina(game_t *game)
{
    sfVector2f pos_h = game->player->health->info->pos;
    sfVector2f scale_h = game->player->health->info->scale;

    sfSprite_setPosition(game->player->health->info->sprite, pos_h);
    sfSprite_setScale(game->player->health->info->sprite, scale_h);
    display_sprite(game, game->player->health->info->sprite);
    update_stamina(game);
}
