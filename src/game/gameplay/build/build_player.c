/*
** EPITECH PROJECT, 2022
** lol
** File description:
** build_player
*/

#include "gameplay.h"
#include "build.h"

item_t *build_item(int nb_item, enum_item_t type, sprite_t **sprite)
{
    item_t *item_s = malloc(sizeof(item_t));

    if (item_s == NULL || sprite == NULL)
        return (NULL);
    item_s->enum_item_e = type;
    item_s->nb_item = nb_item;
    item_s->sprite_s = sprite;
    return (item_s);
}

void build_player_info(obj_t *player, sfVector2f scale, player_t *play)
{
    player->scale = scale;
    player->hitbox = (sfIntRect) {39, 17, 11, 17};
    player->damage = 500;
    player->abs = 0;
    player->hp = 100;
    play->obj = player;
}

void init_player(player_t *play, sfIntRect rect_h, sfVector2f pos_h)
{
    play->health = build_bar("assets/game/health.jpg", 100, rect_h, pos_h);
    play->inventory = build_inventory();
    play->is_running = -1;
    play->bar = sfRectangleShape_create();
    play->item_hand = build_item(1, HAND, play->inventory->items[0]->sprite_s);
    play->exp = 0;
    play->level = 1;
    play->step = 10;
    play->point_competences = 0;
    play->stamina = 200;
    play->stamina_max = 200;
}

player_t *build_player(char *filepath)
{
    obj_t *player;
    player_t *play = malloc(sizeof(player_t));
    sfVector2f pos_h = {185, 20};
    sfIntRect rect_h = {0, 0, 400, 33};
    sfIntRect rect = {0, 0, 30, 32};
    sfVector2f scale = {2, 2};

    if (play == NULL)
        return (NULL);
    player = build_obj(filepath, rect, ALIVE, PLAYER);
    player->scale = scale;
    play->obj = player;
    init_player(play, rect_h, pos_h);
    return (play);
}
