/*
** EPITECH PROJECT, 2022
** create_all_character.c
** File description:
** function that create all class of the game
*/

#include "rpg.h"

static int create_all_cop(game_t *game)
{
    if (create_cop_basic(game) == 84 || create_cop_red(game) == 84
        || create_cop_blue(game) == 84 || create_cop_green(game) == 84
        || create_cop_pink(game) == 84)
        return (84);
    return (0);
}

static int create_all_soldier(game_t *game)
{
    if (create_soldier_basic(game) == 84 || create_soldier_red(game) == 84 ||
        create_soldier_blue(game) == 84 || create_soldier_green(game) == 84 ||
        create_soldier_pink(game) == 84)
        return (84);
    return (0);
}

static int create_all_researcher(game_t *game)
{
    if (create_researcher_basic(game) == 84 || create_researcher_red(game) == 84
        || create_researcher_blue(game) == 84 || create_researcher_green(game)
        == 84 || create_researcher_pink(game) == 84)
        return (84);
    return (0);
}

static int create_all_sporty(game_t *game)
{
    if (create_sporty_basic(game) == 84 || create_sporty_red(game) == 84
        || create_sporty_blue(game) == 84 || create_sporty_green(game) == 84
        || create_sporty_pink(game))
        return (84);
    return (0);
}

int create_all_character(game_t *game)
{
    if (create_all_researcher(game) == 84)
        return (84);
    if (create_all_cop(game) == 84)
        return (84);
    if (create_all_soldier(game) == 84)
        return (84);
    if (create_all_sporty(game) == 84)
        return (84);
    return (0);
}
