/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_tablet_text
*/

#include "rpg.h"

tablet_t *build_text_tablet(tablet_t *tablet)
{
    for (int i = 0; i != 12; i++) {
        tablet->text[i] = build_text("assets/font/verdana.ttf");
        tablet->text[i]->scale = (sfVector2f) {1.2, 1.2};
    }
    tablet->text[11]->scale = (sfVector2f) {1.5, 1.5};
    return (tablet);
}

tablet_t *build_tablet_player_info(tablet_t *tablet)
{
    tablet->background[8] = build_bg("assets/game/tablet/player_info.jpg");
    tablet->background[8]->scale = (sfVector2f) {0.8, 0.8};
    return (tablet);
}
