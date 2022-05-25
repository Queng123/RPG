/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_pause
*/

#include "rpg.h"

void set_pause_text(game_t *game)
{
    game->gameplay->pause->button[0]->text->pos = (sfVector2f) {855, 430};
    game->gameplay->pause->button[1]->text->pos = (sfVector2f) {900, 515};
    game->gameplay->pause->button[2]->text->pos = (sfVector2f) {855, 600};
    game->gameplay->pause->button[0]->text->str = "Back to menu";
    game->gameplay->pause->button[1]->text->str = "Options";
    game->gameplay->pause->button[2]->text->str = "Back to game";
    game->gameplay->pause->button[0]->sprite->pos = (sfVector2f) {775, 420};
    game->gameplay->pause->button[1]->sprite->pos = (sfVector2f) {775, 510};
    game->gameplay->pause->button[2]->sprite->pos = (sfVector2f) {775, 580};
    game->gameplay->pause->button[0]->sprite->size = (sfVector2f) {360, 67};
    game->gameplay->pause->button[1]->sprite->size = (sfVector2f) {360, 67};
    game->gameplay->pause->button[2]->sprite->size = (sfVector2f) {360, 67};
}

int init_pause(game_t *game)
{
    for (int i = 0; i != 3; i++) {
        game->gameplay->pause->button[i] = malloc(sizeof(button_t));
        game->gameplay->pause->button[i]->text =
        build_text("assets/font/verdana.ttf");
        if (game->gameplay->pause->button[i]->text == NULL)
            return (84);
        game->gameplay->pause->button[i]->sprite = malloc(sizeof(sprite_t));
        game->gameplay->pause->button[i]->sprite->sprite = NULL;
        game->gameplay->pause->button[i]->text->scale = (sfVector2f) {1, 1};
    }
    set_pause_text(game);
    game->gameplay->pause->background = build_bg("assets/game/Pause.png");
    game->gameplay->pause->background->pos = (sfVector2f) {750, 300};
    game->gameplay->pause->background->scale = (sfVector2f) {1, 1};
    if (game->gameplay->pause->background == NULL)
        return (84);
    return (0);
}
