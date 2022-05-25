/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_settings_bg
*/

#include "rpg.h"

int init_settings_bg(game_t *game)
{
    if (init_audio(game) == 84 || init_video(game) == 84 ||
        init_controls(game) == 84)
        return (84);
    return (0);
}
