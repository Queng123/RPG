/*
** EPITECH PROJECT, 2022
** physique_engine
** File description:
** build_struct
*/

#include "gameplay.h"
#include "build.h"

clockk_t *build_clock(void)
{
    clockk_t *res = malloc(sizeof(clockk_t));

    if (res == NULL)
        return (NULL);
    res->clock = sfClock_create();
    res->seconds = 0;

    return (res);
}

sfSprite *build_sprite(char *filepath)
{
    sfVector2f scale = {3, 3};
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

void build_date(game_t *game)
{
    game->gameplay->date = malloc(sizeof(button_t));
    game->gameplay->date->sprite = build_bg("assets/game/date.png");
    game->gameplay->date->text = build_text("assets/font/pixel.ttf");
    game->gameplay->date->sprite->pos = (sfVector2f) {0, 0};
    game->gameplay->date->sprite->scale = (sfVector2f) {1, 1};
    game->gameplay->date->sprite->size = (sfVector2f) {156, 192};
    game->gameplay->date->text->str = " ";
    game->gameplay->date->text->pos = (sfVector2f) {0, 0};
    game->gameplay->date->text->scale = (sfVector2f) {1, 1};
}

void build_game(game_t *game_s)
{
    char *ground = "assets/game/1.jpg";

    game_s->clock_s = build_clock();
    game_s->gameplay = malloc(sizeof(gameplay_t));
    game_s->gameplay->timer = build_clock();
    game_s->gameplay->time = 720;
    game_s->gameplay->pause = malloc(sizeof(pause_t));
    game_s->gameplay->pause->display = false;
    game_s->audio = load_audio();
    game_s->generator = build_generator();
    build_date(game_s);
    init_pause(game_s);
    init_game_bar(game_s);
    game_s->gameplay->tablet = build_tablet();
    build_all_obj(game_s->entitie);
    game_s->ground = build_sprite(ground);
    game_s->map = build_map("data/map.uwu");
    game_s->quest = build_quest();
}
