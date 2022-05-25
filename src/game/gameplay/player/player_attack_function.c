/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_attack_function
*/

#include "player.h"

int get_damage_mele_weapon(player_t *player)
{
    if (player->item_hand->enum_item_e == BAT) {
        return (5);
    }
    return (0);
}
