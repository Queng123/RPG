/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void init_struct_howtwoplay(game_t *game_s)
{
    game_s->howtwoplay_s = malloc(sizeof(howtwoplay_t));
    game_s->howtwoplay_s->error = 0;
}

void build_button_how_to_play(game_t *game)
{
    game->howtwoplay_s->button[0] = malloc(sizeof(button_t));
    game->howtwoplay_s->button[0]->sprite = malloc(sizeof(sprite_t));
    game->howtwoplay_s->button[0]->sprite->sprite = NULL;
    game->howtwoplay_s->button[0]->text = malloc(sizeof(text_t));
    game->howtwoplay_s->button[0]->text->text = NULL;
    game->howtwoplay_s->button[0]->sprite->pos = (sfVector2f) {471, 262};
    game->howtwoplay_s->button[0]->sprite->scale = (sfVector2f) {1, 1};
    game->howtwoplay_s->button[0]->sprite->size = (sfVector2f) {40, 60};
    game->howtwoplay_s->button[1] = malloc(sizeof(button_t));
    game->howtwoplay_s->button[1]->sprite = malloc(sizeof(sprite_t));
    game->howtwoplay_s->button[1]->sprite->sprite = NULL;
    game->howtwoplay_s->button[1]->text = malloc(sizeof(text_t));
    game->howtwoplay_s->button[1]->text->text = NULL;
    game->howtwoplay_s->button[1]->sprite->pos = (sfVector2f) {1421, 263};
    game->howtwoplay_s->button[1]->sprite->scale = (sfVector2f) {1, 1};
    game->howtwoplay_s->button[1]->sprite->size = (sfVector2f) {40, 60};
    game->howtwoplay_s->scene = 0;
}

int init_howtwoplay(game_t *game_s)
{
    init_struct_howtwoplay(game_s);
    if (game_s->howtwoplay_s == NULL)
        return (ERROR);
    build_all_howtwoplay(game_s);
    if (game_s->howtwoplay_s->error == 1)
        return (ERROR);
    build_button_how_to_play(game_s);
    return (SUCCESS);
}
