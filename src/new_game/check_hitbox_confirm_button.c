/*
** EPITECH PROJECT, 2022
** check_hitbox_confirm_button.c
** File description:
** function that check the hitbox of the confirm button
*/

#include "rpg.h"
#include "build.h"

static const char *filepath[] = {"assets/new_game/Soldier_basic.png",
"assets/new_game/Soldier_red.png", "assets/new_game/Soldier_blue.png",
"assets/new_game/Soldier_green.png", "assets/new_game/Soldier_pink.png",
"assets/new_game/Sporty_basic.png", "assets/new_game/Sporty_red.png",
"assets/new_game/Sporty_blue.png", "assets/new_game/Sporty_green.png",
"assets/new_game/Sporty_pink.png", "assets/new_game/Cop_basic.png",
"assets/new_game/Cop_red.png", "assets/new_game/Cop_blue.png",
"assets/new_game/Cop_green.png", "assets/new_game/Cop_pink.png",
"assets/new_game/Researcher_basic.png", "assets/new_game/Researcher_red.png",
"assets/new_game/Researcher_blue.png", "assets/new_game/Researcher_green.png",
"assets/new_game/Researcher_pink.png"};

int check_hitbox_confirm_button(game_t *game)
{
    if ((game->new_game->cursor.x > 1325 && game->new_game->cursor.x < 1525)
        && (game->new_game->cursor.y > 795 && game->new_game->cursor.y < 865)) {
        game->player =
        build_player((char *)filepath[game->new_game->class
        * 5 + game->new_game->color]);
        send_stat_character(game);
        clean_all_character(game);
        init_intro(game);
        game->game_info->scene->actual_scene = GAME;
        game->game_info->scene->actual_game_scene = INTRO;
        game->chests = build_tab_chest("assets/game/chest.png",
        game->player->inventory->items[0]->sprite_s);
        set_map(game->map, game->chests->chest);
        set_npc_map(game->map, game->quest);
        game->player->filepath_character =
        my_strdup(filepath[game->new_game->class * 5 + game->new_game->color]);
    }
    return (0);
}
