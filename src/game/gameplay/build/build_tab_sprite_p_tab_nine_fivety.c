/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_map
*/

#include "build.h"

void build_tab_sprite_p_tab_nine_fivety(sprite_t *tab[19], sfVector2f pos,
sfVector2f scale)
{
    tab[9] = build_sprit((sfIntRect){1, 0, 48, 81},
    "assets/game/wheat_crop.png", (sfVector2f){2, 2}, pos);
    tab[10] = build_sprit((sfIntRect){0, 0, 93, 93},
    "assets/game/betterave.png", (sfVector2f){2, 2}, pos);
    tab[11] = build_sprit((sfIntRect){1, 0, 109, 159},
    "assets/game/darkoakgreenhouse.png", scale, pos);
    tab[12] = build_sprit((sfIntRect){0, 0, 158, 170},
    "assets/game/bighouse.png", scale, pos);
    tab[13] = build_sprit((sfIntRect){0, 0, 240, 153},
    "assets/game/hospital.png", (sfVector2f){3.5, 3.5}, pos);
    tab[14] = build_sprit((sfIntRect){1, 0, 581, 899},
    "assets/game/house3.png", (sfVector2f){0.5, 0.5}, pos);
}
