/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** stamina
*/

#include "gameplay.h"

void update_stamina_bar_and_draw(game_t *game)
{
    sfVector2f size = {game->player->stamina * 2.9, 50};
    sfVector2f pos = {205, 100};
    sfColor yellow = {255, 200, 0, 255};

    sfRectangleShape_setSize(game->player->bar, size);
    sfRectangleShape_setPosition(game->player->bar, pos);
    sfRectangleShape_setFillColor(game->player->bar, yellow);
    sfRenderWindow_drawRectangleShape(game->game_info->window,
    game->player->bar, NULL);
}

void decrease_movement(game_t *game)
{
    if (game->player->is_running == 1 && game->player->stamina > 0) {
        game->player->stamina -= 5;
    }
}

void update_stamina(game_t *game)
{
    if (game->player->stamina < game->player->stamina_max) {
        game->player->stamina++;
    }
    if (game->player->stamina <= 0) {
        game->player->is_running = -1;
    }
    update_stamina_bar_and_draw(game);
}
