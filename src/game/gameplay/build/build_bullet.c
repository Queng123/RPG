/*
** EPITECH PROJECT, 2022
** PHYSIQUE_ENGINE
** File description:
** build_bullet
*/

#include "gameplay.h"
#include "build.h"

static const char *src[7] = {"assets/game/zombie1.png",
"assets/game/zombie2.png", "assets/game/zombie3.png",
"assets/game/zombie4.png", "assets/game/zombie5.png",
"assets/game/zombie6.png", "assets/game/zombie7.png"};

void build_barbarian(obj_t *res[NB_ENT])
{
    sfIntRect rect_en = {0, 0, 224, 192};
    sfIntRect rect_hit = {0, 0, 224, 170};
    int nb_en = 500;
    int i = 250;

    for (; i < NB_ENT && i < nb_en; i++) {
        res[i] = build_obj("assets/game/unknown.png", rect_en, ALIVE, IMMU);
        res[i]->abs = 0;
        res[i]->scale = (sfVector2f) {1.5, 1.5};
        res[i]->damage = 10;
        res[i]->hp = 50;
        res[i]->time = 15;
        res[i]->speed_max = 7;
        res[i]->hitbox = rect_hit;
        res[i]->pos.x = 100;
        res[i]->pos.y = 100;
    }
}

void build_enemy(obj_t *res[NB_ENT])
{

    int nb_tank = NB_ENT;
    int i = 0;
    char *filepath = NULL;
    sfIntRect rect_en = {0, 0, 21, 46};
    sfIntRect rect_hit = {4, 16, 17, 25};

    nb_tank += i;
    for (;i < NB_ENT && i < nb_tank; i++) {
        filepath = src[(rand() % 7)];
        res[i] = build_obj(filepath, rect_en, DEAD, ENEMY);
        res[i]->abs = 0.5;
        res[i]->scale = (sfVector2f) {2, 2};
        res[i]->damage = 10;
        res[i]->hp = 20;
        res[i]->time = 12;
        res[i]->speed_max = 5;
        res[i]->hitbox = rect_hit;
    }
}
