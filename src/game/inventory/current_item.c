/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** current_item
*/

#include "rpg.h"

void display_nb_item(char *nb, game_t *game, sfVector2f pos)
{
    if (nb == NULL)
        return;
    pos.y += 40;
    sfText_setString(game->player->inventory->text->text, nb);
    sfText_setPosition(game->player->inventory->text->text, pos);
    sfRenderWindow_drawText(game->game_info->window,
    game->player->inventory->text->text, NULL);
}

void display_current_item_hud(game_t *game)
{
    sfVector2f pos = {1100, 970};
    enum_item_t item = game->player->item_hand->enum_item_e;
    sfSprite *sprite = game->player->item_hand->sprite_s[item]->sprite;

    sfSprite_setPosition(game->player->inventory->square->sprite, pos);
    pos = (sfVector2f){1109, 979};
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->inventory->square->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window, sprite, NULL);
    display_nb_item(int_to_char(game->player->item_hand->nb_item), game, pos);
}
