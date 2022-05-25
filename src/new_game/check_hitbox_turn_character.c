/*
** EPITECH PROJECT, 2022
** check_hitbox_turn_character.c
** File description:
** function that handle the hitbox turn character
*/

#include "rpg.h"

int check_character_right_rotation_second(game_t *game)
{
    if (game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top == 0) {
        game->new_game->character[game->new_game->class * 5
        + game->new_game->color]
        .rect.top = 64;
        return (1);
    }
    if (game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top == 64) {
        game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top = 96;
        return (1);
    }
    return (0);
}

int check_character_right_rotation(game_t *game)
{
    if (check_character_right_rotation_second(game) == 1)
        return (0);
    if (game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top == 96) {
        game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top = 32;
        return (0);
    }
    if (game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top == 32) {
        game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top = 0;
        return (0);
    }
    return (0);
}

int check_character_left_rotation_second(game_t *game)
{
    if (game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top == 0) {
        game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top = 32;
        return (1);
    }
    if (game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top == 32) {
        game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top = 96;
        return (1);
    }
    return (0);
}

int check_character_left_rotation(game_t *game)
{
    if (check_character_left_rotation_second(game) == 1)
        return (0);
    if (game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top == 96) {
        game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top = 64;
        return (0);
    }
    if (game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top == 64) {
        game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect.top = 0;
        return (0);
    }
    return (0);
}

int check_hitbox_turn_character(game_t *game)
{
    if ((game->new_game->cursor.x > 555 && game->new_game->cursor.x < 608) &&
        (game->new_game->cursor.y > 557 && game->new_game->cursor.y < 607)) {
        check_character_right_rotation(game);
        sfSprite_setTextureRect(game->new_game->character
        [game->new_game->class * 5 + game->new_game->color]
        .spr, game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect);
    }
    if ((game->new_game->cursor.x > 796 && game->new_game->cursor.x < 850) &&
        (game->new_game->cursor.y > 560 && game->new_game->cursor.y < 610)) {
        check_character_left_rotation(game);
        sfSprite_setTextureRect(game->new_game->character
        [game->new_game->class * 5 + game->new_game->color]
        .spr, game->new_game->character[game->new_game->class * 5
        + game->new_game->color].rect);
    }
    return (0);
}
