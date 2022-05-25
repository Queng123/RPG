/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_heal
*/

#include "player.h"

void update_player_hand(player_t *player)
{
    if (player->item_hand->nb_item <= 0) {
        player->item_hand->enum_item_e = HAND;
    }
}

int item_is_heal(item_t *items)
{
    enum_item_t tab_food[5] = {CARROT, BREAD, CHOCO, SERRINGUE, BANDAGES};

    for (int i = 0; i < 5; i++) {
        if (items->enum_item_e == tab_food[i]) {
            return (0);
        }
    }
    return (1);
}

int can_player_heal(player_t *player)
{
    if (player->item_hand->nb_item >= 1
    && item_is_heal(player->item_hand) == 0) {
        return (0);
    }
    return (1);
}

void heal_player(game_t *game, player_t *player)
{
    enum_item_t tab_food[5] = {CARROT, BREAD, CHOCO, SERRINGUE, BANDAGES};
    int tab_heal[5] = {10, 10, 10, 75, 25};

    for (int i = 0; i < 6; i++) {
        if (tab_food[i] == player->item_hand->enum_item_e) {
            sfSound_play(game->audio->eat_sound);
            player->obj->hp += tab_heal[i];
            player->item_hand->nb_item--;
            sfClock_restart(player->obj->clock_attack->clock);
            player->obj->clock_attack->seconds = 0;
        }
    }
    if (player->obj->hp > player->health->max_score) {
        player->obj->hp = player->health->max_score;
    }
    update_health_bar(player->obj, player->health);
    update_player_hand(player);
}

void try_heal_player(game_t *game, sfMouseButtonEvent mouse)
{
    sfVector2f pos = (sfVector2f) {(game->map->y_player - game->map->pos_y) *
    48, (game->map->x_player - game->map->pos_x) * 48};

    if (mouse.button != sfMouseRight || can_player_heal(game->player) != 0) {
        return;
    }
    heal_player(game, game->player);
    game->generator = fill_generator(game->generator, pos, sfGreen, sfBlack);
    game->generator->heal = 1;
}
