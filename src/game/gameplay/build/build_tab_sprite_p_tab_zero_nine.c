/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_map
*/

#include "build.h"

void build_tab_sprite_p_tab_zero_nine(sprite_t *tab[19], sfVector2f pos,
sfVector2f scale)
{
    tab[0] = build_sprit((sfIntRect){0, 0, 126, 142},
    "assets/game/house_hero.png", scale, pos);
    tab[1] = build_sprit((sfIntRect){0, 0, 143, 158},
    "assets/game/house1.png", scale, pos);
    tab[2] = build_sprit((sfIntRect){0, 0, 128, 164},
    "assets/game/house2.png", scale, pos);
    tab[3] = build_sprit((sfIntRect){0, 0, 112, 104},
    "assets/game/barn.png", scale, pos);
    tab[4] = build_sprit((sfIntRect){0, 0, 77, 126},
    "assets/game/forge.png", scale, pos);
    tab[5] = build_sprit((sfIntRect){0, 0, 160, 157},
    "assets/game/fisherman.png", scale, pos);
    tab[6] = build_sprit((sfIntRect){0, 0, 48, 80},
    "assets/game/tree.png", scale, pos);
    tab[7] = build_sprit((sfIntRect){1, 0, 48, 81},
    "assets/game/camp.png", (sfVector2f){2, 2}, pos);
    tab[8] = build_sprit((sfIntRect){0, 0, 123, 63},
    "assets/game/gypsi.png", scale, pos);
}
