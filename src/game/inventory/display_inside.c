/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_inside
*/

#include "rpg.h"

static const sfVector2f pos[16] = {{1368, 840}, {1446, 840},
{1525, 840}, {1602, 840}, {1680, 840}, {1760, 840}, {1368, 918}, {1446, 918},
{1525, 918}, {1602, 918}, {1680, 918}, {1760, 918}};

void display_text(char *nb, game_t *game, int i)
{
    sfVector2f position = pos[i];

    if (nb == NULL)
        return;
    position.y += 40;
    sfText_setString(game->player->inventory->text->text, nb);
    sfText_setPosition(game->player->inventory->text->text, position);
    sfRenderWindow_drawText(game->game_info->window,
    game->player->inventory->text->text, NULL);
}

void display_inventory_item(game_t *game)
{
    sfSprite *temp;
    enum_item_t item;
    item_t **tab = game->player->inventory->items;

    for (int i = 0; i < 12; i++) {
        item = tab[i]->enum_item_e;
        if (item != NONE && HAND) {
            display_text(int_to_char(tab[i]->nb_item), game, i);
            temp = tab[i]->sprite_s[item]->sprite;
            sfSprite_setPosition(temp, pos[i]);
            sfSprite_setScale(temp, tab[i]->sprite_s[item]->scale);
            sfRenderWindow_drawSprite(game->game_info->window, temp, NULL);
        }
    }
}
